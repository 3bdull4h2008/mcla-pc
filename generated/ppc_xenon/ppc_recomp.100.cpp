#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824F8900"))) PPC_WEAK_FUNC(sub_824F8900);
PPC_FUNC_IMPL(__imp__sub_824F8900) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,140
	ctx.r3.s64 = ctx.r3.s64 + 140;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F8908"))) PPC_WEAK_FUNC(sub_824F8908);
PPC_FUNC_IMPL(__imp__sub_824F8908) {
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
	ctx.lr = 0x824F8910;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r10,150(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// rlwimi r10,r9,5,0,28
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 5) & 0xFFFFFFF8) | (ctx.r10.u64 & 0xFFFFFFFF00000007);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r10,150(r31)
	PPC_STORE_U8(r31.u32 + 150, ctx.r10.u8);
	// bl 0x824e6310
	ctx.lr = 0x824F8944;
	sub_824E6310(ctx, base);
	// lbz r8,150(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// sth r30,148(r31)
	PPC_STORE_U16(r31.u32 + 148, r30.u16);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stb r7,150(r31)
	PPC_STORE_U8(r31.u32 + 150, ctx.r7.u8);
	// rlwinm r3,r7,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F8964"))) PPC_WEAK_FUNC(sub_824F8964);
PPC_FUNC_IMPL(__imp__sub_824F8964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8968"))) PPC_WEAK_FUNC(sub_824F8968);
PPC_FUNC_IMPL(__imp__sub_824F8968) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824f89b8
	if (!cr6.eq) goto loc_824F89B8;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,84(r4)
	PPC_STORE_U32(ctx.r4.u32 + 84, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f89a4
	if (cr6.eq) goto loc_824F89A4;
	// stw r11,88(r10)
	PPC_STORE_U32(ctx.r10.u32 + 88, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824F89A4:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824F89B8:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824f89f4
	if (!cr6.eq) goto loc_824F89F4;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,88(r4)
	PPC_STORE_U32(ctx.r4.u32 + 88, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8a18
	if (cr6.eq) goto loc_824F8A18;
	// stw r11,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824F89F4:
	// lwz r10,88(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,84(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// stw r9,84(r10)
	PPC_STORE_U32(ctx.r10.u32 + 84, ctx.r9.u32);
	// lwz r8,84(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// lwz r7,88(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// stw r7,88(r8)
	PPC_STORE_U32(ctx.r8.u32 + 88, ctx.r7.u32);
	// stw r11,84(r4)
	PPC_STORE_U32(ctx.r4.u32 + 84, r11.u32);
	// stw r11,88(r4)
	PPC_STORE_U32(ctx.r4.u32 + 88, r11.u32);
loc_824F8A18:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F8A28"))) PPC_WEAK_FUNC(sub_824F8A28);
PPC_FUNC_IMPL(__imp__sub_824F8A28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8a50
	if (cr6.eq) goto loc_824F8A50;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_824F8A50:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8a70
	if (cr6.eq) goto loc_824F8A70;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824f8a74
	if (!cr6.eq) goto loc_824F8A74;
loc_824F8A70:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824F8A74:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8a90
	if (cr6.eq) goto loc_824F8A90;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824F8A90:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F8AA4"))) PPC_WEAK_FUNC(sub_824F8AA4);
PPC_FUNC_IMPL(__imp__sub_824F8AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8AA8"))) PPC_WEAK_FUNC(sub_824F8AA8);
PPC_FUNC_IMPL(__imp__sub_824F8AA8) {
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
	// addi r4,r31,108
	ctx.r4.s64 = r31.s64 + 108;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8AD0;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824f8af0
	if (!cr6.eq) goto loc_824F8AF0;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x824eb048
	ctx.lr = 0x824F8AF0;
	sub_824EB048(ctx, base);
loc_824F8AF0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8AF8;
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

__attribute__((alias("__imp__sub_824F8B10"))) PPC_WEAK_FUNC(sub_824F8B10);
PPC_FUNC_IMPL(__imp__sub_824F8B10) {
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
	ctx.lr = 0x824F8B18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r28,r31,64
	r28.s64 = r31.s64 + 64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8B30;
	sub_821C8FE0(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8b88
	if (cr6.eq) goto loc_824F8B88;
	// addi r29,r31,52
	r29.s64 = r31.s64 + 52;
loc_824F8B40:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8B50;
	sub_821C8FE0(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824f8b74
	if (!cr6.eq) goto loc_824F8B74;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82533d00
	ctx.lr = 0x824F8B68;
	sub_82533D00(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f8968
	ctx.lr = 0x824F8B74;
	sub_824F8968(ctx, base);
loc_824F8B74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8B7C;
	sub_821C9030(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f8b40
	if (!cr6.eq) goto loc_824F8B40;
loc_824F8B88:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824F8B90;
	sub_821C9030(ctx, base);
	// addi r28,r31,108
	r28.s64 = r31.s64 + 108;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8BA0;
	sub_821C8FE0(ctx, base);
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8bf4
	if (cr6.eq) goto loc_824F8BF4;
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
loc_824F8BB4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8BC4;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824f8be0
	if (!cr6.eq) goto loc_824F8BE0;
	// stw r27,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r27.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb048
	ctx.lr = 0x824F8BE0;
	sub_824EB048(ctx, base);
loc_824F8BE0:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824F8BE8;
	sub_821C9030(ctx, base);
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f8bb4
	if (!cr6.eq) goto loc_824F8BB4;
loc_824F8BF4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8BFC;
	sub_821C9030(ctx, base);
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8C08;
	sub_821C8FE0(ctx, base);
	// lbz r11,150(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8c48
	if (cr6.eq) goto loc_824F8C48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252fc40
	ctx.lr = 0x824F8C20;
	sub_8252FC40(ctx, base);
	// lbz r9,150(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,-1
	r11.s64 = -1;
	// rlwimi r9,r10,5,0,28
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 5) & 0xFFFFFFF8) | (ctx.r9.u64 & 0xFFFFFFFF00000007);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r9,150(r31)
	PPC_STORE_U8(r31.u32 + 150, ctx.r9.u8);
	// bl 0x824e6310
	ctx.lr = 0x824F8C44;
	sub_824E6310(ctx, base);
	// sth r27,148(r31)
	PPC_STORE_U16(r31.u32 + 148, r27.u16);
loc_824F8C48:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824F8C50;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F8C58"))) PPC_WEAK_FUNC(sub_824F8C58);
PPC_FUNC_IMPL(__imp__sub_824F8C58) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8C7C;
	sub_821C8FE0(ctx, base);
	// bl 0x821c9788
	ctx.lr = 0x824F8C80;
	sub_821C9788(ctx, base);
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8cb4
	if (cr6.eq) goto loc_824F8CB4;
loc_824F8C90:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F8CA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824f8c90
	if (!cr6.eq) goto loc_824F8C90;
loc_824F8CB4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8CBC;
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

__attribute__((alias("__imp__sub_824F8CD4"))) PPC_WEAK_FUNC(sub_824F8CD4);
PPC_FUNC_IMPL(__imp__sub_824F8CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8CD8"))) PPC_WEAK_FUNC(sub_824F8CD8);
PPC_FUNC_IMPL(__imp__sub_824F8CD8) {
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
	ctx.lr = 0x824F8CE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8D00;
	sub_821C8FE0(ctx, base);
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8d38
	if (cr6.eq) goto loc_824F8D38;
loc_824F8D0C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F8D2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824f8d0c
	if (!cr6.eq) goto loc_824F8D0C;
loc_824F8D38:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8D40;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F8D48"))) PPC_WEAK_FUNC(sub_824F8D48);
PPC_FUNC_IMPL(__imp__sub_824F8D48) {
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
	ctx.lr = 0x824F8D50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8D70;
	sub_821C8FE0(ctx, base);
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8da8
	if (cr6.eq) goto loc_824F8DA8;
loc_824F8D7C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F8D9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824f8d7c
	if (!cr6.eq) goto loc_824F8D7C;
loc_824F8DA8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8DB0;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F8DB8"))) PPC_WEAK_FUNC(sub_824F8DB8);
PPC_FUNC_IMPL(__imp__sub_824F8DB8) {
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
	ctx.lr = 0x824F8DC0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8DE4;
	sub_821C8FE0(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r30,1024
	cr6.compare<uint32_t>(r30.u32, 1024, xer);
	// ble cr6,0x824f8e14
	if (!cr6.gt) goto loc_824F8E14;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f8e8c
	if (cr6.eq) goto loc_824F8E8C;
	// li r11,3
	r11.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824F8E08;
	sub_821C9030(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824F8E14:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x824f8e44
	if (!cr6.lt) goto loc_824F8E44;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f8e8c
	if (cr6.eq) goto loc_824F8E8C;
	// li r11,7
	r11.s64 = 7;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x824F8E38;
	sub_821C9030(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824F8E44:
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252ff18
	ctx.lr = 0x824F8E5C;
	sub_8252FF18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8e8c
	if (cr6.eq) goto loc_824F8E8C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824f8e74
	if (cr6.eq) goto loc_824F8E74;
	// stw r26,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r26.u32);
loc_824F8E74:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r26,1
	r26.s64 = 1;
	// bl 0x824f8cd8
	ctx.lr = 0x824F8E8C;
	sub_824F8CD8(ctx, base);
loc_824F8E8C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8E94;
	sub_821C9030(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824F8EA0"))) PPC_WEAK_FUNC(sub_824F8EA0);
PPC_FUNC_IMPL(__imp__sub_824F8EA0) {
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
	ctx.lr = 0x824F8EA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x824e6320
	ctx.lr = 0x824F8ECC;
	sub_824E6320(ctx, base);
	// lbz r11,150(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f8eec
	if (cr6.eq) goto loc_824F8EEC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x824f8ef0
	if (!cr6.lt) goto loc_824F8EF0;
loc_824F8EEC:
	// li r11,0
	r11.s64 = 0;
loc_824F8EF0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f8f24
	if (cr6.eq) goto loc_824F8F24;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f8db8
	ctx.lr = 0x824F8F14;
	sub_824F8DB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f8f28
	if (!cr6.eq) goto loc_824F8F28;
loc_824F8F24:
	// li r11,0
	r11.s64 = 0;
loc_824F8F28:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824F8F34"))) PPC_WEAK_FUNC(sub_824F8F34);
PPC_FUNC_IMPL(__imp__sub_824F8F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F8F38"))) PPC_WEAK_FUNC(sub_824F8F38);
PPC_FUNC_IMPL(__imp__sub_824F8F38) {
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
	ctx.lr = 0x824F8F40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r26,20
	ctx.r4.s64 = r26.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8F64;
	sub_821C8FE0(ctx, base);
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x824f8f8c
	if (!cr6.lt) goto loc_824F8F8C;
	// li r29,-1
	r29.s64 = -1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8fb4
	if (cr6.eq) goto loc_824F8FB4;
	// li r11,7
	r11.s64 = 7;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x824f8fb4
	goto loc_824F8FB4;
loc_824F8F8C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824f8f98
	if (cr6.eq) goto loc_824F8F98;
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_824F8F98:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82530030
	ctx.lr = 0x824F8FB0;
	sub_82530030(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824F8FB4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F8FBC;
	sub_821C9030(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x824f90d4
	if (!cr6.gt) goto loc_824F90D4;
	// addi r4,r26,64
	ctx.r4.s64 = r26.s64 + 64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824F8FD0;
	sub_821C8FE0(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824f8d48
	ctx.lr = 0x824F8FE4;
	sub_824F8D48(ctx, base);
	// lwz r11,60(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f90cc
	if (cr6.eq) goto loc_824F90CC;
	// lbz r10,150(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 150);
	// addi r11,r26,52
	r11.s64 = r26.s64 + 52;
	// mr r25,r24
	r25.u64 = r24.u64;
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stb r9,150(r26)
	PPC_STORE_U8(r26.u32 + 150, ctx.r9.u8);
	// lwz r31,52(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// beq cr6,0x824f90ac
	if (cr6.eq) goto loc_824F90AC;
loc_824F9018:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533c38
	ctx.lr = 0x824F9020;
	sub_82533C38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9094
	if (cr6.eq) goto loc_824F9094;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F904C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x824f9060
	if (cr6.eq) goto loc_824F9060;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x824f9094
	if (!cr6.eq) goto loc_824F9094;
loc_824F9060:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824F9080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subf r9,r24,r30
	ctx.r9.s64 = r30.s64 - r24.s64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r25,r8,27,31,31
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// beq cr6,0x824f90ac
	if (cr6.eq) goto loc_824F90AC;
loc_824F9094:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f8a28
	ctx.lr = 0x824F90A0;
	sub_824F8A28(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824f9018
	if (!cr6.eq) goto loc_824F9018;
loc_824F90AC:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f90bc
	if (cr6.eq) goto loc_824F90BC;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_824F90BC:
	// lbz r11,150(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 150);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,150(r26)
	PPC_STORE_U8(r26.u32 + 150, ctx.r10.u8);
loc_824F90CC:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824F90D4;
	sub_821C9030(ctx, base);
loc_824F90D4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824F90E0"))) PPC_WEAK_FUNC(sub_824F90E0);
PPC_FUNC_IMPL(__imp__sub_824F90E0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,108
	ctx.r4.s64 = r31.s64 + 108;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824F9108;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824f912c
	if (!cr6.eq) goto loc_824F912C;
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eab98
	ctx.lr = 0x824F912C;
	sub_824EAB98(ctx, base);
loc_824F912C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824F9134;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_824F914C"))) PPC_WEAK_FUNC(sub_824F914C);
PPC_FUNC_IMPL(__imp__sub_824F914C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9150"))) PPC_WEAK_FUNC(sub_824F9150);
PPC_FUNC_IMPL(__imp__sub_824F9150) {
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
	ctx.lr = 0x824F9158;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824F9178;
	sub_821C8ED8(ctx, base);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824F918C;
	sub_821C8ED8(ctx, base);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824F91A0;
	sub_821C8ED8(ctx, base);
	// addi r29,r31,140
	r29.s64 = r31.s64 + 140;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6310
	ctx.lr = 0x824F91AC;
	sub_824E6310(ctx, base);
	// lbz r9,150(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 150);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,-1
	r11.s64 = -1;
	// rlwimi r9,r10,5,0,28
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 5) & 0xFFFFFFF8) | (ctx.r9.u64 & 0xFFFFFFFF00000007);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r9,150(r31)
	PPC_STORE_U8(r31.u32 + 150, ctx.r9.u8);
	// bl 0x824e6310
	ctx.lr = 0x824F91D0;
	sub_824E6310(ctx, base);
	// sth r30,148(r31)
	PPC_STORE_U16(r31.u32 + 148, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F91E0"))) PPC_WEAK_FUNC(sub_824F91E0);
PPC_FUNC_IMPL(__imp__sub_824F91E0) {
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
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x82130000
	ctx.lr = 0x824F91FC;
	sub_82130000(ctx, base);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x825307d0
	ctx.lr = 0x824F9204;
	sub_825307D0(ctx, base);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// bl 0x82130000
	ctx.lr = 0x824F920C;
	sub_82130000(ctx, base);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x82483d28
	ctx.lr = 0x824F9214;
	sub_82483D28(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82130000
	ctx.lr = 0x824F921C;
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

__attribute__((alias("__imp__sub_824F9230"))) PPC_WEAK_FUNC(sub_824F9230);
PPC_FUNC_IMPL(__imp__sub_824F9230) {
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
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F9250;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
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

__attribute__((alias("__imp__sub_824F926C"))) PPC_WEAK_FUNC(sub_824F926C);
PPC_FUNC_IMPL(__imp__sub_824F926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9270"))) PPC_WEAK_FUNC(sub_824F9270);
PPC_FUNC_IMPL(__imp__sub_824F9270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// beq cr6,0x824f9294
	if (cr6.eq) goto loc_824F9294;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x824f9294
	if (cr6.lt) goto loc_824F9294;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x824f9298
	if (!cr6.gt) goto loc_824F9298;
loc_824F9294:
	// li r11,0
	r11.s64 = 0;
loc_824F9298:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F92A0"))) PPC_WEAK_FUNC(sub_824F92A0);
PPC_FUNC_IMPL(__imp__sub_824F92A0) {
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
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F92C8;
	sub_8244D150(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// std r30,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r30.u64);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
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

__attribute__((alias("__imp__sub_824F92EC"))) PPC_WEAK_FUNC(sub_824F92EC);
PPC_FUNC_IMPL(__imp__sub_824F92EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F92F0"))) PPC_WEAK_FUNC(sub_824F92F0);
PPC_FUNC_IMPL(__imp__sub_824F92F0) {
	PPC_FUNC_PROLOGUE();
	// ld r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F92F8"))) PPC_WEAK_FUNC(sub_824F92F8);
PPC_FUNC_IMPL(__imp__sub_824F92F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x824f9380
	if (!cr6.eq) goto loc_824F9380;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x824f9328
	if (cr6.eq) goto loc_824F9328;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x824f9328
	if (cr6.lt) goto loc_824F9328;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x824f932c
	if (!cr6.gt) goto loc_824F932C;
loc_824F9328:
	// li r11,0
	r11.s64 = 0;
loc_824F932C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9380
	if (cr6.eq) goto loc_824F9380;
	// ld r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// cmpldi cr6,r10,0
	cr6.compare<uint64_t>(ctx.r10.u64, 0, xer);
	// beq cr6,0x824f9358
	if (cr6.eq) goto loc_824F9358;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// blt cr6,0x824f9358
	if (cr6.lt) goto loc_824F9358;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x824f935c
	if (!cr6.gt) goto loc_824F935C;
loc_824F9358:
	// li r11,0
	r11.s64 = 0;
loc_824F935C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9380
	if (cr6.eq) goto loc_824F9380;
	// cmpld cr6,r8,r10
	cr6.compare<uint64_t>(ctx.r8.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f9378
	if (cr6.eq) goto loc_824F9378;
	// li r11,0
	r11.s64 = 0;
loc_824F9378:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_824F9380:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F9388"))) PPC_WEAK_FUNC(sub_824F9388);
PPC_FUNC_IMPL(__imp__sub_824F9388) {
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
	// bl 0x824f92f8
	ctx.lr = 0x824F9398;
	sub_824F92F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F93B4"))) PPC_WEAK_FUNC(sub_824F93B4);
PPC_FUNC_IMPL(__imp__sub_824F93B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F93B8"))) PPC_WEAK_FUNC(sub_824F93B8);
PPC_FUNC_IMPL(__imp__sub_824F93B8) {
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
	ctx.lr = 0x824F93C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x8275cc98
	ctx.lr = 0x824F93DC;
	sub_8275CC98(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824f9428
	if (!cr6.eq) goto loc_824F9428;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// bne cr6,0x824f9400
	if (!cr6.eq) goto loc_824F9400;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8275cc98
	ctx.lr = 0x824F9400;
	sub_8275CC98(ctx, base);
loc_824F9400:
	// li r5,16
	ctx.r5.s64 = 16;
	// ld r30,80(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F9414;
	sub_8244D150(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r30,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r30.u64);
	// stb r3,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r3.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
loc_824F9428:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9434"))) PPC_WEAK_FUNC(sub_824F9434);
PPC_FUNC_IMPL(__imp__sub_824F9434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9438"))) PPC_WEAK_FUNC(sub_824F9438);
PPC_FUNC_IMPL(__imp__sub_824F9438) {
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
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F9458;
	sub_8244D150(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
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

__attribute__((alias("__imp__sub_824F9478"))) PPC_WEAK_FUNC(sub_824F9478);
PPC_FUNC_IMPL(__imp__sub_824F9478) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// addi r11,r10,-2260
	r11.s64 = ctx.r10.s64 + -2260;
	// ld r7,8(r3)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r9,28896
	ctx.r5.s64 = ctx.r9.s64 + 28896;
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x824F94B8;
	sub_82137A08(ctx, base);
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r3,r5,1
	ctx.r3.u64 = ctx.r5.u64 ^ 1;
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

__attribute__((alias("__imp__sub_824F94E0"))) PPC_WEAK_FUNC(sub_824F94E0);
PPC_FUNC_IMPL(__imp__sub_824F94E0) {
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
	ctx.lr = 0x824F94E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82618750
	ctx.lr = 0x824F9504;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824F9514;
	sub_82618640(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r28,0
	r28.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lbz r30,0(r29)
	r30.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x824F952C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9564
	if (cr6.eq) goto loc_824F9564;
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
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824F9554;
	sub_82618390(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824F9560;
	sub_826188B8(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824F9564:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9590
	if (cr6.eq) goto loc_824F9590;
	// li r5,64
	ctx.r5.s64 = 64;
	// ld r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618d38
	ctx.lr = 0x824F9580;
	sub_82618D38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9590
	if (cr6.eq) goto loc_824F9590;
	// li r28,1
	r28.s64 = 1;
loc_824F9590:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f95c4
	if (cr6.eq) goto loc_824F95C4;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f95bc
	if (cr6.eq) goto loc_824F95BC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824F95AC;
	sub_826186A0(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_824F95BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_824F95C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F95D0"))) PPC_WEAK_FUNC(sub_824F95D0);
PPC_FUNC_IMPL(__imp__sub_824F95D0) {
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
	ctx.lr = 0x824F95D8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82618750
	ctx.lr = 0x824F95F4;
	sub_82618750(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824F9604;
	sub_826185E0(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r28
	r29.u64 = r28.u64;
	// bl 0x8244d150
	ctx.lr = 0x824F961C;
	sub_8244D150(ctx, base);
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x826187f0
	ctx.lr = 0x824F9630;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9674
	if (cr6.eq) goto loc_824F9674;
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
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618318
	ctx.lr = 0x824F9658;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x826188d8
	ctx.lr = 0x824F966C;
	sub_826188D8(ctx, base);
	// li r30,1
	r30.s64 = 1;
	// b 0x824f9678
	goto loc_824F9678;
loc_824F9674:
	// stb r28,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r28.u8);
loc_824F9678:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f96a4
	if (cr6.eq) goto loc_824F96A4;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618c90
	ctx.lr = 0x824F9694;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f96a4
	if (cr6.eq) goto loc_824F96A4;
	// li r29,1
	r29.s64 = 1;
loc_824F96A4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f96d8
	if (cr6.eq) goto loc_824F96D8;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f96d0
	if (cr6.eq) goto loc_824F96D0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824F96C0;
	sub_826186B0(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
loc_824F96D0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
loc_824F96D8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F96E4"))) PPC_WEAK_FUNC(sub_824F96E4);
PPC_FUNC_IMPL(__imp__sub_824F96E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F96E8"))) PPC_WEAK_FUNC(sub_824F96E8);
PPC_FUNC_IMPL(__imp__sub_824F96E8) {
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
	ctx.lr = 0x824F96F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32127
	r31.s64 = -2105475072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// ld r11,-2240(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + -2240);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// bne cr6,0x824f9760
	if (!cr6.eq) goto loc_824F9760;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6148
	ctx.lr = 0x824F9714;
	sub_824E6148(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9770
	if (cr6.eq) goto loc_824F9770;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c98a8
	ctx.lr = 0x824F9730;
	sub_821C98A8(ctx, base);
	// clrldi r11,r3,32
	r11.u64 = ctx.r3.u64 & 0xFFFFFFFF;
loc_824F9734:
	// mftb r10
	ctx.r10.u64 = __rdtsc();
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824f9734
	if (cr6.eq) goto loc_824F9734;
	// rldicr r11,r11,32,31
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF00000000;
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// std r11,-2240(r31)
	PPC_STORE_U64(r31.u32 + -2240, r11.u64);
	// std r11,0(r30)
	PPC_STORE_U64(r30.u32 + 0, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824F9760:
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,0(r30)
	PPC_STORE_U64(r30.u32 + 0, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824F9770:
	// ld r11,-2240(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + -2240);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// std r11,0(r30)
	PPC_STORE_U64(r30.u32 + 0, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9784"))) PPC_WEAK_FUNC(sub_824F9784);
PPC_FUNC_IMPL(__imp__sub_824F9784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9788"))) PPC_WEAK_FUNC(sub_824F9788);
PPC_FUNC_IMPL(__imp__sub_824F9788) {
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
	// bl 0x82501a78
	ctx.lr = 0x824F97A0;
	sub_82501A78(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
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

__attribute__((alias("__imp__sub_824F97BC"))) PPC_WEAK_FUNC(sub_824F97BC);
PPC_FUNC_IMPL(__imp__sub_824F97BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F97C0"))) PPC_WEAK_FUNC(sub_824F97C0);
PPC_FUNC_IMPL(__imp__sub_824F97C0) {
	PPC_FUNC_PROLOGUE();
	// ld r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F97C8"))) PPC_WEAK_FUNC(sub_824F97C8);
PPC_FUNC_IMPL(__imp__sub_824F97C8) {
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
	ctx.lr = 0x824F97D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82501b38
	ctx.lr = 0x824F97F0;
	sub_82501B38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9844
	if (cr6.eq) goto loc_824F9844;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x824f9844
	if (cr6.lt) goto loc_824F9844;
	// ld r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r5,32
	ctx.r5.s64 = 32;
	// rldicl r4,r10,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618390
	ctx.lr = 0x824F9824;
	sub_82618390(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,32
	ctx.r5.s64 = 32;
	// ld r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82618390
	ctx.lr = 0x824F9840;
	sub_82618390(ctx, base);
	// li r28,1
	r28.s64 = 1;
loc_824F9844:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f9878
	if (cr6.eq) goto loc_824F9878;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9870
	if (cr6.eq) goto loc_824F9870;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824F9870:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_824F9878:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F9884"))) PPC_WEAK_FUNC(sub_824F9884);
PPC_FUNC_IMPL(__imp__sub_824F9884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9888"))) PPC_WEAK_FUNC(sub_824F9888);
PPC_FUNC_IMPL(__imp__sub_824F9888) {
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
	ctx.lr = 0x824F9890;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82501c80
	ctx.lr = 0x824F98B0;
	sub_82501C80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9910
	if (cr6.eq) goto loc_824F9910;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// blt cr6,0x824f9910
	if (cr6.lt) goto loc_824F9910;
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618318
	ctx.lr = 0x824F98E0;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82618318
	ctx.lr = 0x824F98FC;
	sub_82618318(ctx, base);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r28,1
	r28.s64 = 1;
	// rldimi r7,r8,32,0
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r7.u64 & 0xFFFFFFFF);
	// std r7,40(r30)
	PPC_STORE_U64(r30.u32 + 40, ctx.r7.u64);
loc_824F9910:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824f9944
	if (cr6.eq) goto loc_824F9944;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f993c
	if (cr6.eq) goto loc_824F993C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824F993C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_824F9944:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824F9950"))) PPC_WEAK_FUNC(sub_824F9950);
PPC_FUNC_IMPL(__imp__sub_824F9950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,40(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// ld r10,40(r4)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r4.u32 + 40);
	// cmpld cr6,r11,r10
	cr6.compare<uint64_t>(r11.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f9968
	if (cr6.eq) goto loc_824F9968;
	// li r11,0
	r11.s64 = 0;
loc_824F9968:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F9970"))) PPC_WEAK_FUNC(sub_824F9970);
PPC_FUNC_IMPL(__imp__sub_824F9970) {
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
	// bl 0x82501a78
	ctx.lr = 0x824F998C;
	sub_82501A78(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// bl 0x82501ac0
	ctx.lr = 0x824F99A0;
	sub_82501AC0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f96e8
	ctx.lr = 0x824F99A8;
	sub_824F96E8(ctx, base);
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

__attribute__((alias("__imp__sub_824F99C0"))) PPC_WEAK_FUNC(sub_824F99C0);
PPC_FUNC_IMPL(__imp__sub_824F99C0) {
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
	// bl 0x82501b00
	ctx.lr = 0x824F99D8;
	sub_82501B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501a78
	ctx.lr = 0x824F99E0;
	sub_82501A78(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,40(r31)
	PPC_STORE_U64(r31.u32 + 40, r11.u64);
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

__attribute__((alias("__imp__sub_824F9A00"))) PPC_WEAK_FUNC(sub_824F9A00);
PPC_FUNC_IMPL(__imp__sub_824F9A00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// ld r11,40(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 40);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9a14
	if (!cr6.eq) goto loc_824F9A14;
	// li r11,0
	r11.s64 = 0;
loc_824F9A14:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824F9A1C"))) PPC_WEAK_FUNC(sub_824F9A1C);
PPC_FUNC_IMPL(__imp__sub_824F9A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9A20"))) PPC_WEAK_FUNC(sub_824F9A20);
PPC_FUNC_IMPL(__imp__sub_824F9A20) {
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
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// cmpdi cr6,r11,-1
	cr6.compare<int64_t>(r11.s64, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9a50
	if (!cr6.eq) goto loc_824F9A50;
	// li r11,0
	r11.s64 = 0;
loc_824F9A50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9a90
	if (cr6.eq) goto loc_824F9A90;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f96e8
	ctx.lr = 0x824F9A64;
	sub_824F96E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9a90
	if (cr6.eq) goto loc_824F9A90;
	// ld r11,40(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// cmpld cr6,r11,r10
	cr6.compare<uint64_t>(r11.u64, ctx.r10.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824f9a88
	if (cr6.eq) goto loc_824F9A88;
	// li r11,0
	r11.s64 = 0;
loc_824F9A88:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// b 0x824f9a94
	goto loc_824F9A94;
loc_824F9A90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824F9A94:
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

__attribute__((alias("__imp__sub_824F9AAC"))) PPC_WEAK_FUNC(sub_824F9AAC);
PPC_FUNC_IMPL(__imp__sub_824F9AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9AB0"))) PPC_WEAK_FUNC(sub_824F9AB0);
PPC_FUNC_IMPL(__imp__sub_824F9AB0) {
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
	ctx.lr = 0x824F9AB8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9AC8;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9AD4;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// ble cr6,0x824f9ae8
	if (!cr6.gt) goto loc_824F9AE8;
	// li r30,16
	r30.s64 = 16;
loc_824F9AE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9AF0;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9B04;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9b6c
	if (cr6.eq) goto loc_824F9B6C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f95d0
	ctx.lr = 0x824F9B24;
	sub_824F95D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9b6c
	if (cr6.eq) goto loc_824F9B6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9B3C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9b6c
	if (cr6.eq) goto loc_824F9B6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9B50;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9B5C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9b70
	if (!cr6.eq) goto loc_824F9B70;
loc_824F9B6C:
	// li r11,0
	r11.s64 = 0;
loc_824F9B70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9B7C"))) PPC_WEAK_FUNC(sub_824F9B7C);
PPC_FUNC_IMPL(__imp__sub_824F9B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9B80"))) PPC_WEAK_FUNC(sub_824F9B80);
PPC_FUNC_IMPL(__imp__sub_824F9B80) {
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
	ctx.lr = 0x824F9B88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9B98;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9BA4;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,8
	cr6.compare<uint32_t>(r30.u32, 8, xer);
	// ble cr6,0x824f9bb8
	if (!cr6.gt) goto loc_824F9BB8;
	// li r30,8
	r30.s64 = 8;
loc_824F9BB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9BC0;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9BD4;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9c3c
	if (cr6.eq) goto loc_824F9C3C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f04c8
	ctx.lr = 0x824F9BF4;
	sub_824F04C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9c3c
	if (cr6.eq) goto loc_824F9C3C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9C0C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9c3c
	if (cr6.eq) goto loc_824F9C3C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9C20;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9C2C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9c40
	if (!cr6.eq) goto loc_824F9C40;
loc_824F9C3C:
	// li r11,0
	r11.s64 = 0;
loc_824F9C40:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9C4C"))) PPC_WEAK_FUNC(sub_824F9C4C);
PPC_FUNC_IMPL(__imp__sub_824F9C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9C50"))) PPC_WEAK_FUNC(sub_824F9C50);
PPC_FUNC_IMPL(__imp__sub_824F9C50) {
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
	ctx.lr = 0x824F9C58;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9C68;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9C74;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,96
	cr6.compare<uint32_t>(r30.u32, 96, xer);
	// ble cr6,0x824f9c88
	if (!cr6.gt) goto loc_824F9C88;
	// li r30,96
	r30.s64 = 96;
loc_824F9C88:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9C90;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9CA4;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9d0c
	if (cr6.eq) goto loc_824F9D0C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e74e0
	ctx.lr = 0x824F9CC4;
	sub_824E74E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9d0c
	if (cr6.eq) goto loc_824F9D0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9CDC;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9d0c
	if (cr6.eq) goto loc_824F9D0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9CF0;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9CFC;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9d10
	if (!cr6.eq) goto loc_824F9D10;
loc_824F9D0C:
	// li r11,0
	r11.s64 = 0;
loc_824F9D10:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9D1C"))) PPC_WEAK_FUNC(sub_824F9D1C);
PPC_FUNC_IMPL(__imp__sub_824F9D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9D20"))) PPC_WEAK_FUNC(sub_824F9D20);
PPC_FUNC_IMPL(__imp__sub_824F9D20) {
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
	ctx.lr = 0x824F9D28;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9D38;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9D44;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,40
	cr6.compare<uint32_t>(r30.u32, 40, xer);
	// ble cr6,0x824f9d58
	if (!cr6.gt) goto loc_824F9D58;
	// li r30,40
	r30.s64 = 40;
loc_824F9D58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9D60;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9D74;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9ddc
	if (cr6.eq) goto loc_824F9DDC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8252ae40
	ctx.lr = 0x824F9D94;
	sub_8252AE40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9ddc
	if (cr6.eq) goto loc_824F9DDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9DAC;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9ddc
	if (cr6.eq) goto loc_824F9DDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9DC0;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9DCC;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9de0
	if (!cr6.eq) goto loc_824F9DE0;
loc_824F9DDC:
	// li r11,0
	r11.s64 = 0;
loc_824F9DE0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9DEC"))) PPC_WEAK_FUNC(sub_824F9DEC);
PPC_FUNC_IMPL(__imp__sub_824F9DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9DF0"))) PPC_WEAK_FUNC(sub_824F9DF0);
PPC_FUNC_IMPL(__imp__sub_824F9DF0) {
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
	ctx.lr = 0x824F9DF8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9E08;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9E14;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,48
	cr6.compare<uint32_t>(r30.u32, 48, xer);
	// ble cr6,0x824f9e28
	if (!cr6.gt) goto loc_824F9E28;
	// li r30,48
	r30.s64 = 48;
loc_824F9E28:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9E30;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9E44;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9eac
	if (cr6.eq) goto loc_824F9EAC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9888
	ctx.lr = 0x824F9E64;
	sub_824F9888(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9eac
	if (cr6.eq) goto loc_824F9EAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9E7C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9eac
	if (cr6.eq) goto loc_824F9EAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9E90;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9E9C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9eb0
	if (!cr6.eq) goto loc_824F9EB0;
loc_824F9EAC:
	// li r11,0
	r11.s64 = 0;
loc_824F9EB0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9EBC"))) PPC_WEAK_FUNC(sub_824F9EBC);
PPC_FUNC_IMPL(__imp__sub_824F9EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9EC0"))) PPC_WEAK_FUNC(sub_824F9EC0);
PPC_FUNC_IMPL(__imp__sub_824F9EC0) {
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
	ctx.lr = 0x824F9EC8;
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9ED8;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9EE4;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,560
	cr6.compare<uint32_t>(r30.u32, 560, xer);
	// ble cr6,0x824f9ef8
	if (!cr6.gt) goto loc_824F9EF8;
	// li r30,560
	r30.s64 = 560;
loc_824F9EF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9F00;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9F14;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9f7c
	if (cr6.eq) goto loc_824F9F7C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e1df0
	ctx.lr = 0x824F9F34;
	sub_824E1DF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9f7c
	if (cr6.eq) goto loc_824F9F7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824F9F4C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824f9f7c
	if (cr6.eq) goto loc_824F9F7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9F60;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824F9F6C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824f9f80
	if (!cr6.eq) goto loc_824F9F80;
loc_824F9F7C:
	// li r11,0
	r11.s64 = 0;
loc_824F9F80:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824F9F8C"))) PPC_WEAK_FUNC(sub_824F9F8C);
PPC_FUNC_IMPL(__imp__sub_824F9F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824F9F90"))) PPC_WEAK_FUNC(sub_824F9F90);
PPC_FUNC_IMPL(__imp__sub_824F9F90) {
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
	ctx.lr = 0x824F9F98;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824F9FA8;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9FB4;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,60
	cr6.compare<uint32_t>(r30.u32, 60, xer);
	// ble cr6,0x824f9fc8
	if (!cr6.gt) goto loc_824F9FC8;
	// li r30,60
	r30.s64 = 60;
loc_824F9FC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824F9FD0;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824F9FE4;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa04c
	if (cr6.eq) goto loc_824FA04C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e66b8
	ctx.lr = 0x824FA004;
	sub_824E66B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa04c
	if (cr6.eq) goto loc_824FA04C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824FA01C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa04c
	if (cr6.eq) goto loc_824FA04C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA030;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824FA03C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa050
	if (!cr6.eq) goto loc_824FA050;
loc_824FA04C:
	// li r11,0
	r11.s64 = 0;
loc_824FA050:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FA05C"))) PPC_WEAK_FUNC(sub_824FA05C);
PPC_FUNC_IMPL(__imp__sub_824FA05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA060"))) PPC_WEAK_FUNC(sub_824FA060);
PPC_FUNC_IMPL(__imp__sub_824FA060) {
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
	ctx.lr = 0x824FA068;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824FA078;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA084;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,620
	cr6.compare<uint32_t>(r30.u32, 620, xer);
	// ble cr6,0x824fa098
	if (!cr6.gt) goto loc_824FA098;
	// li r30,620
	r30.s64 = 620;
loc_824FA098:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA0A0;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824FA0B4;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa11c
	if (cr6.eq) goto loc_824FA11C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fc398
	ctx.lr = 0x824FA0D4;
	sub_824FC398(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa11c
	if (cr6.eq) goto loc_824FA11C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824FA0EC;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa11c
	if (cr6.eq) goto loc_824FA11C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA100;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824FA10C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa120
	if (!cr6.eq) goto loc_824FA120;
loc_824FA11C:
	// li r11,0
	r11.s64 = 0;
loc_824FA120:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FA12C"))) PPC_WEAK_FUNC(sub_824FA12C);
PPC_FUNC_IMPL(__imp__sub_824FA12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA130"))) PPC_WEAK_FUNC(sub_824FA130);
PPC_FUNC_IMPL(__imp__sub_824FA130) {
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
	ctx.lr = 0x824FA138;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824FA148;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA154;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,152
	cr6.compare<uint32_t>(r30.u32, 152, xer);
	// ble cr6,0x824fa168
	if (!cr6.gt) goto loc_824FA168;
	// li r30,152
	r30.s64 = 152;
loc_824FA168:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA170;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824FA184;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa1ec
	if (cr6.eq) goto loc_824FA1EC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f3420
	ctx.lr = 0x824FA1A4;
	sub_824F3420(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa1ec
	if (cr6.eq) goto loc_824FA1EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824FA1BC;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa1ec
	if (cr6.eq) goto loc_824FA1EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FA1D0;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824FA1DC;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa1f0
	if (!cr6.eq) goto loc_824FA1F0;
loc_824FA1EC:
	// li r11,0
	r11.s64 = 0;
loc_824FA1F0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FA1FC"))) PPC_WEAK_FUNC(sub_824FA1FC);
PPC_FUNC_IMPL(__imp__sub_824FA1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA200"))) PPC_WEAK_FUNC(sub_824FA200);
PPC_FUNC_IMPL(__imp__sub_824FA200) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9ab0
	sub_824F9AB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA204"))) PPC_WEAK_FUNC(sub_824FA204);
PPC_FUNC_IMPL(__imp__sub_824FA204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA208"))) PPC_WEAK_FUNC(sub_824FA208);
PPC_FUNC_IMPL(__imp__sub_824FA208) {
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824f94e0
	ctx.lr = 0x824FA230;
	sub_824F94E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa25c
	if (cr6.eq) goto loc_824FA25C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA24C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa260
	if (!cr6.eq) goto loc_824FA260;
loc_824FA25C:
	// li r11,0
	r11.s64 = 0;
loc_824FA260:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824FA278"))) PPC_WEAK_FUNC(sub_824FA278);
PPC_FUNC_IMPL(__imp__sub_824FA278) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9b80
	sub_824F9B80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA27C"))) PPC_WEAK_FUNC(sub_824FA27C);
PPC_FUNC_IMPL(__imp__sub_824FA27C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA280"))) PPC_WEAK_FUNC(sub_824FA280);
PPC_FUNC_IMPL(__imp__sub_824FA280) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9c50
	sub_824F9C50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA284"))) PPC_WEAK_FUNC(sub_824FA284);
PPC_FUNC_IMPL(__imp__sub_824FA284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA288"))) PPC_WEAK_FUNC(sub_824FA288);
PPC_FUNC_IMPL(__imp__sub_824FA288) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824e73b8
	ctx.lr = 0x824FA2B0;
	sub_824E73B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa2dc
	if (cr6.eq) goto loc_824FA2DC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA2CC;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa2e0
	if (!cr6.eq) goto loc_824FA2E0;
loc_824FA2DC:
	// li r11,0
	r11.s64 = 0;
loc_824FA2E0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA2F8"))) PPC_WEAK_FUNC(sub_824FA2F8);
PPC_FUNC_IMPL(__imp__sub_824FA2F8) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9d20
	sub_824F9D20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA2FC"))) PPC_WEAK_FUNC(sub_824FA2FC);
PPC_FUNC_IMPL(__imp__sub_824FA2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA300"))) PPC_WEAK_FUNC(sub_824FA300);
PPC_FUNC_IMPL(__imp__sub_824FA300) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8252ad70
	ctx.lr = 0x824FA328;
	sub_8252AD70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa354
	if (cr6.eq) goto loc_824FA354;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA344;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa358
	if (!cr6.eq) goto loc_824FA358;
loc_824FA354:
	// li r11,0
	r11.s64 = 0;
loc_824FA358:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA370"))) PPC_WEAK_FUNC(sub_824FA370);
PPC_FUNC_IMPL(__imp__sub_824FA370) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// bl 0x8252a660
	ctx.lr = 0x824FA398;
	sub_8252A660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa3c4
	if (cr6.eq) goto loc_824FA3C4;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA3B4;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa3c8
	if (!cr6.eq) goto loc_824FA3C8;
loc_824FA3C4:
	// li r11,0
	r11.s64 = 0;
loc_824FA3C8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824FA3E0"))) PPC_WEAK_FUNC(sub_824FA3E0);
PPC_FUNC_IMPL(__imp__sub_824FA3E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9df0
	sub_824F9DF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA3E4"))) PPC_WEAK_FUNC(sub_824FA3E4);
PPC_FUNC_IMPL(__imp__sub_824FA3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA3E8"))) PPC_WEAK_FUNC(sub_824FA3E8);
PPC_FUNC_IMPL(__imp__sub_824FA3E8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824f97c8
	ctx.lr = 0x824FA410;
	sub_824F97C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa43c
	if (cr6.eq) goto loc_824FA43C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA42C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa440
	if (!cr6.eq) goto loc_824FA440;
loc_824FA43C:
	// li r11,0
	r11.s64 = 0;
loc_824FA440:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA458"))) PPC_WEAK_FUNC(sub_824FA458);
PPC_FUNC_IMPL(__imp__sub_824FA458) {
	PPC_FUNC_PROLOGUE();
	// b 0x824fbf80
	sub_824FBF80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA45C"))) PPC_WEAK_FUNC(sub_824FA45C);
PPC_FUNC_IMPL(__imp__sub_824FA45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA460"))) PPC_WEAK_FUNC(sub_824FA460);
PPC_FUNC_IMPL(__imp__sub_824FA460) {
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
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,513
	ctx.r5.s64 = 513;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9948
	ctx.lr = 0x824FA488;
	sub_824E9948(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa4b4
	if (cr6.eq) goto loc_824FA4B4;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA4A4;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa4b8
	if (!cr6.eq) goto loc_824FA4B8;
loc_824FA4B4:
	// li r11,0
	r11.s64 = 0;
loc_824FA4B8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA4D0"))) PPC_WEAK_FUNC(sub_824FA4D0);
PPC_FUNC_IMPL(__imp__sub_824FA4D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9ec0
	sub_824F9EC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA4D4"))) PPC_WEAK_FUNC(sub_824FA4D4);
PPC_FUNC_IMPL(__imp__sub_824FA4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA4D8"))) PPC_WEAK_FUNC(sub_824FA4D8);
PPC_FUNC_IMPL(__imp__sub_824FA4D8) {
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
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,560
	ctx.r5.s64 = 560;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824e1c80
	ctx.lr = 0x824FA500;
	sub_824E1C80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa52c
	if (cr6.eq) goto loc_824FA52C;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA51C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa530
	if (!cr6.eq) goto loc_824FA530;
loc_824FA52C:
	// li r11,0
	r11.s64 = 0;
loc_824FA530:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA548"))) PPC_WEAK_FUNC(sub_824FA548);
PPC_FUNC_IMPL(__imp__sub_824FA548) {
	PPC_FUNC_PROLOGUE();
	// b 0x824f9f90
	sub_824F9F90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA54C"))) PPC_WEAK_FUNC(sub_824FA54C);
PPC_FUNC_IMPL(__imp__sub_824FA54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA550"))) PPC_WEAK_FUNC(sub_824FA550);
PPC_FUNC_IMPL(__imp__sub_824FA550) {
	PPC_FUNC_PROLOGUE();
	// b 0x824fa060
	sub_824FA060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA554"))) PPC_WEAK_FUNC(sub_824FA554);
PPC_FUNC_IMPL(__imp__sub_824FA554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA558"))) PPC_WEAK_FUNC(sub_824FA558);
PPC_FUNC_IMPL(__imp__sub_824FA558) {
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
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,620
	ctx.r5.s64 = 620;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824fc210
	ctx.lr = 0x824FA580;
	sub_824FC210(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa5ac
	if (cr6.eq) goto loc_824FA5AC;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA59C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa5b0
	if (!cr6.eq) goto loc_824FA5B0;
loc_824FA5AC:
	// li r11,0
	r11.s64 = 0;
loc_824FA5B0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA5C8"))) PPC_WEAK_FUNC(sub_824FA5C8);
PPC_FUNC_IMPL(__imp__sub_824FA5C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x824fa130
	sub_824FA130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA5CC"))) PPC_WEAK_FUNC(sub_824FA5CC);
PPC_FUNC_IMPL(__imp__sub_824FA5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA5D0"))) PPC_WEAK_FUNC(sub_824FA5D0);
PPC_FUNC_IMPL(__imp__sub_824FA5D0) {
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,152
	ctx.r5.s64 = 152;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824f30d8
	ctx.lr = 0x824FA5F8;
	sub_824F30D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fa624
	if (cr6.eq) goto loc_824FA624;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FA614;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fa628
	if (!cr6.eq) goto loc_824FA628;
loc_824FA624:
	// li r11,0
	r11.s64 = 0;
loc_824FA628:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA640"))) PPC_WEAK_FUNC(sub_824FA640);
PPC_FUNC_IMPL(__imp__sub_824FA640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// stw r3,-2224(r11)
	PPC_STORE_U32(r11.u32 + -2224, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA64C"))) PPC_WEAK_FUNC(sub_824FA64C);
PPC_FUNC_IMPL(__imp__sub_824FA64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA650"))) PPC_WEAK_FUNC(sub_824FA650);
PPC_FUNC_IMPL(__imp__sub_824FA650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 28);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r8,r9,-1028
	ctx.r8.s64 = ctx.r9.s64 + -1028;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// clrlwi r7,r10,25
	ctx.r7.u64 = ctx.r10.u32 & 0x7F;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r6,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r6.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stb r7,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA684"))) PPC_WEAK_FUNC(sub_824FA684);
PPC_FUNC_IMPL(__imp__sub_824FA684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA688"))) PPC_WEAK_FUNC(sub_824FA688);
PPC_FUNC_IMPL(__imp__sub_824FA688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,28(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 28);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-1028
	ctx.r8.s64 = ctx.r10.s64 + -1028;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// ori r5,r11,128
	ctx.r5.u64 = r11.u64 | 128;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stb r5,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA6BC"))) PPC_WEAK_FUNC(sub_824FA6BC);
PPC_FUNC_IMPL(__imp__sub_824FA6BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA6C0"))) PPC_WEAK_FUNC(sub_824FA6C0);
PPC_FUNC_IMPL(__imp__sub_824FA6C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// lbz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fa700
	if (cr6.eq) goto loc_824FA700;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x824fa6f4
	if (!cr6.gt) goto loc_824FA6F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
loc_824FA6F4:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_824FA700:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA710"))) PPC_WEAK_FUNC(sub_824FA710);
PPC_FUNC_IMPL(__imp__sub_824FA710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x824fa730
	if (cr6.eq) goto loc_824FA730;
loc_824FA720:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824fa720
	if (!cr6.eq) goto loc_824FA720;
loc_824FA730:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824fa74c
	if (!cr6.eq) goto loc_824FA74C;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x824fa754
	goto loc_824FA754;
loc_824FA74C:
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
loc_824FA754:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// lbz r9,28(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 28);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824fa778
	if (cr6.eq) goto loc_824FA778;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_824FA778:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA788"))) PPC_WEAK_FUNC(sub_824FA788);
PPC_FUNC_IMPL(__imp__sub_824FA788) {
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
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r30,0
	r30.s64 = 0;
	// addi r11,r11,32244
	r11.s64 = r11.s64 + 32244;
	// lwz r10,32252(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32252);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824fa7d8
	if (!cr6.eq) goto loc_824FA7D8;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// mr r31,r30
	r31.u64 = r30.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r10,32252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32252, ctx.r10.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// b 0x824fa7dc
	goto loc_824FA7DC;
loc_824FA7D8:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_824FA7DC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824fa7fc
	if (cr6.eq) goto loc_824FA7FC;
loc_824FA7E4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x824FA7EC;
	sub_82130588(ctx, base);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824fa7e4
	if (!cr6.eq) goto loc_824FA7E4;
loc_824FA7FC:
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

__attribute__((alias("__imp__sub_824FA814"))) PPC_WEAK_FUNC(sub_824FA814);
PPC_FUNC_IMPL(__imp__sub_824FA814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA818"))) PPC_WEAK_FUNC(sub_824FA818);
PPC_FUNC_IMPL(__imp__sub_824FA818) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,32244
	r11.s64 = r11.s64 + 32244;
	// lwz r10,32252(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32252);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824fa848
	if (!cr6.eq) goto loc_824FA848;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,32252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32252, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x824fa84c
	goto loc_824FA84C;
loc_824FA848:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_824FA84C:
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lwz r10,32252(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32252);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824fa86c
	if (!cr6.eq) goto loc_824FA86C;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,32252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32252, ctx.r10.u32);
	// b 0x824fa870
	goto loc_824FA870;
loc_824FA86C:
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_824FA870:
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824fa89c
	if (!cr6.eq) goto loc_824FA89C;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r10,32252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32252, ctx.r10.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// blr 
	return;
loc_824FA89C:
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA8A8"))) PPC_WEAK_FUNC(sub_824FA8A8);
PPC_FUNC_IMPL(__imp__sub_824FA8A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,32240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32240);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32240(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32240, r11.u32);
	// bnelr 
	if (!cr0.eq) return;
	// b 0x824fa788
	sub_824FA788(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FA8C0"))) PPC_WEAK_FUNC(sub_824FA8C0);
PPC_FUNC_IMPL(__imp__sub_824FA8C0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA8C4"))) PPC_WEAK_FUNC(sub_824FA8C4);
PPC_FUNC_IMPL(__imp__sub_824FA8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA8C8"))) PPC_WEAK_FUNC(sub_824FA8C8);
PPC_FUNC_IMPL(__imp__sub_824FA8C8) {
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
	ctx.lr = 0x824FA8D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addic. r11,r29,-1
	xer.ca = r29.u32 > 0;
	r11.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r9,16(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// ble 0x824fa910
	if (!cr0.gt) goto loc_824FA910;
loc_824FA8F0:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824fa910
	if (cr6.eq) goto loc_824FA910;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x824fa8f0
	if (cr0.gt) goto loc_824FA8F0;
loc_824FA910:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r31,20(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824fa960
	if (cr6.eq) goto loc_824FA960;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r11,10116
	r28.s64 = r11.s64 + 10116;
loc_824FA92C:
	// cmplw cr6,r27,r31
	cr6.compare<uint32_t>(r27.u32, r31.u32, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824fa964
	if (cr6.eq) goto loc_824FA964;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x821c3410
	ctx.lr = 0x824FA944;
	sub_821C3410(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c3410
	ctx.lr = 0x824FA954;
	sub_821C3410(ctx, base);
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824fa92c
	if (!cr6.eq) goto loc_824FA92C;
loc_824FA960:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824FA964:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FA96C"))) PPC_WEAK_FUNC(sub_824FA96C);
PPC_FUNC_IMPL(__imp__sub_824FA96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FA970"))) PPC_WEAK_FUNC(sub_824FA970);
PPC_FUNC_IMPL(__imp__sub_824FA970) {
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
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, r11.u32);
	// stw r11,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r11.u32);
	// bl 0x824fa818
	ctx.lr = 0x824FA9A0;
	sub_824FA818(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FA9B0"))) PPC_WEAK_FUNC(sub_824FA9B0);
PPC_FUNC_IMPL(__imp__sub_824FA9B0) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x824FA9CC;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_824FA9E8"))) PPC_WEAK_FUNC(sub_824FA9E8);
PPC_FUNC_IMPL(__imp__sub_824FA9E8) {
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
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lbz r11,28(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 28);
	// rlwinm r11,r11,25,7,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824faa68
	if (cr6.eq) goto loc_824FAA68;
	// lbz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824faa48
	if (cr6.eq) goto loc_824FAA48;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r8,31
	ctx.r3.u64 = ctx.r8.u32 & 0x1;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824FAA48:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824faa68
	if (cr6.eq) goto loc_824FAA68;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824FAA68:
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824faa90
	if (cr6.eq) goto loc_824FAA90;
loc_824FAA78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_824FAA90:
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// beq cr6,0x824faa78
	if (cr6.eq) goto loc_824FAA78;
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// bl 0x824fa8c8
	ctx.lr = 0x824FAAA4;
	sub_824FA8C8(ctx, base);
	// li r5,255
	ctx.r5.s64 = 255;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa8c8
	ctx.lr = 0x824FAAB4;
	sub_824FA8C8(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
loc_824FAABC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x824faae0
	if (cr6.eq) goto loc_824FAAE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824faabc
	if (cr6.eq) goto loc_824FAABC;
loc_824FAAE0:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FAB00"))) PPC_WEAK_FUNC(sub_824FAB00);
PPC_FUNC_IMPL(__imp__sub_824FAB00) {
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
	ctx.lr = 0x824FAB08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stb r6,159(r1)
	PPC_STORE_U8(ctx.r1.u32 + 159, ctx.r6.u8);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAB2C;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fab88
	if (cr6.eq) goto loc_824FAB88;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAB48;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fabbc
	if (!cr6.eq) goto loc_824FABBC;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAB64;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fab7c
	if (cr6.eq) goto loc_824FAB7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FAB7C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FAB88:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAB90;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fab7c
	if (!cr6.eq) goto loc_824FAB7C;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FABAC;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fabc0
	if (!cr6.eq) goto loc_824FABC0;
loc_824FABBC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_824FABC0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FABC8"))) PPC_WEAK_FUNC(sub_824FABC8);
PPC_FUNC_IMPL(__imp__sub_824FABC8) {
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
	ctx.lr = 0x824FABD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stb r5,151(r1)
	PPC_STORE_U8(ctx.r1.u32 + 151, ctx.r5.u8);
	// addi r3,r1,151
	ctx.r3.s64 = ctx.r1.s64 + 151;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r31,r30,-4
	r31.s64 = r30.s64 + -4;
	// lwz r5,-4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// bl 0x824fa9e8
	ctx.lr = 0x824FABF0;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fac28
	if (cr6.eq) goto loc_824FAC28;
loc_824FABFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,151
	ctx.r3.s64 = ctx.r1.s64 + 151;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAC1C;
	sub_824FA9E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824fabfc
	if (!cr6.eq) goto loc_824FABFC;
loc_824FAC28:
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FAC34"))) PPC_WEAK_FUNC(sub_824FAC34);
PPC_FUNC_IMPL(__imp__sub_824FAC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FAC38"))) PPC_WEAK_FUNC(sub_824FAC38);
PPC_FUNC_IMPL(__imp__sub_824FAC38) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x824FAC40;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stb r7,199(r1)
	PPC_STORE_U8(ctx.r1.u32 + 199, ctx.r7.u8);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// addze r29,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r29.s64 = temp.s64;
	// ble cr6,0x824facb0
	if (!cr6.gt) goto loc_824FACB0;
loc_824FAC6C:
	// rlwinm r28,r29,2,0,29
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,199
	ctx.r3.s64 = ctx.r1.s64 + 199;
	// lwzx r4,r28,r30
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r30.u32);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAC80;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824facb0
	if (cr6.eq) goto loc_824FACB0;
	// lwzx r11,r28,r30
	r11.u64 = PPC_LOAD_U32(r28.u32 + r30.u32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r29,-1
	ctx.r9.s64 = r29.s64 + -1;
	// mr r31,r29
	r31.u64 = r29.u64;
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// stwx r11,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, r11.u32);
	// addze r29,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	r29.s64 = temp.s64;
	// bgt cr6,0x824fac6c
	if (cr6.gt) goto loc_824FAC6C;
loc_824FACB0:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r27,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FACC0"))) PPC_WEAK_FUNC(sub_824FACC0);
PPC_FUNC_IMPL(__imp__sub_824FACC0) {
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
	ctx.lr = 0x824FACC8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r31,r11,1,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r29
	r25.u64 = r29.u64;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// bge cr6,0x824fad44
	if (!cr6.lt) goto loc_824FAD44;
loc_824FACF4:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r1,199
	ctx.r3.s64 = ctx.r1.s64 + 199;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAD0C;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fad1c
	if (cr6.eq) goto loc_824FAD1C;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_824FAD1C:
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r31,1
	ctx.r9.s64 = r31.s64 + 1;
	// mr r29,r31
	r29.u64 = r31.u64;
	// rlwinm r31,r9,1,0,30
	r31.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r8,r11,r30
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// stwx r8,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r8.u32);
	// blt cr6,0x824facf4
	if (cr6.lt) goto loc_824FACF4;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
loc_824FAD44:
	// bne cr6,0x824fad60
	if (!cr6.eq) goto loc_824FAD60;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r30
	ctx.r9.u64 = r11.u64 + r30.u64;
	// addi r29,r31,-1
	r29.s64 = r31.s64 + -1;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// stwx r8,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r8.u32);
loc_824FAD60:
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fac38
	ctx.lr = 0x824FAD78;
	sub_824FAC38(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824FAD80"))) PPC_WEAK_FUNC(sub_824FAD80);
PPC_FUNC_IMPL(__imp__sub_824FAD80) {
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
	ctx.lr = 0x824FAD88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r6,159(r1)
	PPC_STORE_U8(ctx.r1.u32 + 159, ctx.r6.u8);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
loc_824FAD9C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// bl 0x824fa9e8
	ctx.lr = 0x824FADAC;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fadd8
	if (cr6.eq) goto loc_824FADD8;
loc_824FADB8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FADCC;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fadb8
	if (!cr6.eq) goto loc_824FADB8;
loc_824FADD8:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FADEC;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fae18
	if (cr6.eq) goto loc_824FAE18;
loc_824FADF8:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,159
	ctx.r3.s64 = ctx.r1.s64 + 159;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FAE0C;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fadf8
	if (!cr6.eq) goto loc_824FADF8;
loc_824FAE18:
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bge cr6,0x824fae38
	if (!cr6.lt) goto loc_824FAE38;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x824fad9c
	goto loc_824FAD9C;
loc_824FAE38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FAE44"))) PPC_WEAK_FUNC(sub_824FAE44);
PPC_FUNC_IMPL(__imp__sub_824FAE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FAE48"))) PPC_WEAK_FUNC(sub_824FAE48);
PPC_FUNC_IMPL(__imp__sub_824FAE48) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824FAE50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// subf r11,r29,r4
	r11.s64 = ctx.r4.s64 - r29.s64;
	// srawi r28,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r28.s64 = r11.s32 >> 2;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// blt cr6,0x824faec4
	if (cr6.lt) goto loc_824FAEC4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lwzx r6,r11,r29
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x824facc0
	ctx.lr = 0x824FAE94;
	sub_824FACC0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824faec4
	if (cr6.eq) goto loc_824FAEC4;
loc_824FAE9C:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824facc0
	ctx.lr = 0x824FAEBC;
	sub_824FACC0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x824fae9c
	if (!cr6.eq) goto loc_824FAE9C;
loc_824FAEC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FAECC"))) PPC_WEAK_FUNC(sub_824FAECC);
PPC_FUNC_IMPL(__imp__sub_824FAECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FAED0"))) PPC_WEAK_FUNC(sub_824FAED0);
PPC_FUNC_IMPL(__imp__sub_824FAED0) {
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
	ctx.lr = 0x824FAED8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// beq cr6,0x824faf64
	if (cr6.eq) goto loc_824FAF64;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// beq cr6,0x824faf64
	if (cr6.eq) goto loc_824FAF64;
	// subf r30,r29,r31
	r30.s64 = r31.s64 - r29.s64;
loc_824FAF00:
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824fa9e8
	ctx.lr = 0x824FAF14;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824faf44
	if (cr6.eq) goto loc_824FAF44;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824faf3c
	if (!cr6.gt) goto loc_824FAF3C;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db5b0
	ctx.lr = 0x824FAF3C;
	sub_823DB5B0(ctx, base);
loc_824FAF3C:
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// b 0x824faf54
	goto loc_824FAF54;
loc_824FAF44:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fabc8
	ctx.lr = 0x824FAF54;
	sub_824FABC8(ctx, base);
loc_824FAF54:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// bne cr6,0x824faf00
	if (!cr6.eq) goto loc_824FAF00;
loc_824FAF64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FAF6C"))) PPC_WEAK_FUNC(sub_824FAF6C);
PPC_FUNC_IMPL(__imp__sub_824FAF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FAF70"))) PPC_WEAK_FUNC(sub_824FAF70);
PPC_FUNC_IMPL(__imp__sub_824FAF70) {
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
	ctx.lr = 0x824FAF78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// ble cr6,0x824fafd4
	if (!cr6.gt) goto loc_824FAFD4;
	// addi r31,r3,64
	r31.s64 = ctx.r3.s64 + 64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824faed0
	ctx.lr = 0x824FAFA8;
	sub_824FAED0(ctx, base);
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x824fafdc
	if (cr6.eq) goto loc_824FAFDC;
loc_824FAFB0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fabc8
	ctx.lr = 0x824FAFC0;
	sub_824FABC8(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x824fafb0
	if (!cr6.eq) goto loc_824FAFB0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FAFD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824faed0
	ctx.lr = 0x824FAFDC;
	sub_824FAED0(ctx, base);
loc_824FAFDC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FAFE4"))) PPC_WEAK_FUNC(sub_824FAFE4);
PPC_FUNC_IMPL(__imp__sub_824FAFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FAFE8"))) PPC_WEAK_FUNC(sub_824FAFE8);
PPC_FUNC_IMPL(__imp__sub_824FAFE8) {
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
	ctx.lr = 0x824FAFF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// subf r11,r30,r4
	r11.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// ble cr6,0x824fb044
	if (!cr6.gt) goto loc_824FB044;
	// addi r29,r30,-4
	r29.s64 = r30.s64 + -4;
loc_824FB010:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r11,-4
	r31.s64 = r11.s64 + -4;
	// lwzx r6,r29,r11
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	ctx.r5.s64 = r31.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, ctx.r10.u32);
	// bl 0x824facc0
	ctx.lr = 0x824FB034;
	sub_824FACC0(ctx, base);
	// rlwinm r9,r31,0,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFC;
	// mr r11,r31
	r11.u64 = r31.u64;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bgt cr6,0x824fb010
	if (cr6.gt) goto loc_824FB010;
loc_824FB044:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824FB04C"))) PPC_WEAK_FUNC(sub_824FB04C);
PPC_FUNC_IMPL(__imp__sub_824FB04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB050"))) PPC_WEAK_FUNC(sub_824FB050);
PPC_FUNC_IMPL(__imp__sub_824FB050) {
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
	ctx.lr = 0x824FB058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824fae48
	ctx.lr = 0x824FB07C;
	sub_824FAE48(ctx, base);
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x824fb0d4
	if (!cr6.lt) goto loc_824FB0D4;
loc_824FB088:
	// addi r3,r1,183
	ctx.r3.s64 = ctx.r1.s64 + 183;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fa9e8
	ctx.lr = 0x824FB098;
	sub_824FA9E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb0c8
	if (cr6.eq) goto loc_824FB0C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r10,r30,r29
	ctx.r10.s64 = r29.s64 - r30.s64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// srawi r5,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x824facc0
	ctx.lr = 0x824FB0C8;
	sub_824FACC0(ctx, base);
loc_824FB0C8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// blt cr6,0x824fb088
	if (cr6.lt) goto loc_824FB088;
loc_824FB0D4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fafe8
	ctx.lr = 0x824FB0E4;
	sub_824FAFE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FB0EC"))) PPC_WEAK_FUNC(sub_824FB0EC);
PPC_FUNC_IMPL(__imp__sub_824FB0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB0F0"))) PPC_WEAK_FUNC(sub_824FB0F0);
PPC_FUNC_IMPL(__imp__sub_824FB0F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824FB0F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// ble cr6,0x824fb1b0
	if (!cr6.gt) goto loc_824FB1B0;
loc_824FB11C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824fb19c
	if (cr6.eq) goto loc_824FB19C;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addi r5,r31,-4
	ctx.r5.s64 = r31.s64 + -4;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824fab00
	ctx.lr = 0x824FB150;
	sub_824FAB00(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// bl 0x824fad80
	ctx.lr = 0x824FB168;
	sub_824FAD80(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x824fb0f0
	ctx.lr = 0x824FB180;
	sub_824FB0F0(ctx, base);
	// subf r6,r30,r29
	ctx.r6.s64 = r29.s64 - r30.s64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// rlwinm r5,r6,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// cmpwi cr6,r5,64
	cr6.compare<int32_t>(ctx.r5.s32, 64, xer);
	// bgt cr6,0x824fb11c
	if (cr6.gt) goto loc_824FB11C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824FB19C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824fb050
	ctx.lr = 0x824FB1B0;
	sub_824FB050(ctx, base);
loc_824FB1B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FB1B8"))) PPC_WEAK_FUNC(sub_824FB1B8);
PPC_FUNC_IMPL(__imp__sub_824FB1B8) {
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
	ctx.lr = 0x824FB1C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x824fb224
	if (cr6.eq) goto loc_824FB224;
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// li r10,0
	ctx.r10.s64 = 0;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824fb1fc
	if (cr6.eq) goto loc_824FB1FC;
loc_824FB1EC:
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x824fb1ec
	if (!cr6.eq) goto loc_824FB1EC;
loc_824FB1FC:
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fb0f0
	ctx.lr = 0x824FB214;
	sub_824FB0F0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824faf70
	ctx.lr = 0x824FB224;
	sub_824FAF70(ctx, base);
loc_824FB224:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FB22C"))) PPC_WEAK_FUNC(sub_824FB22C);
PPC_FUNC_IMPL(__imp__sub_824FB22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB230"))) PPC_WEAK_FUNC(sub_824FB230);
PPC_FUNC_IMPL(__imp__sub_824FB230) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fb31c
	if (!cr6.eq) goto loc_824FB31C;
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x824fb26c
	if (!cr6.gt) goto loc_824FB26C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824FB26C:
	// bl 0x82130528
	ctx.lr = 0x824FB270;
	sub_82130528(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fb31c
	if (cr6.eq) goto loc_824FB31C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb2a4
	if (cr6.eq) goto loc_824FB2A4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824FB28C:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fb28c
	if (!cr6.eq) goto loc_824FB28C;
loc_824FB2A4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r3
	ctx.r4.u64 = r11.u64 + ctx.r3.u64;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// lbz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x824fb1b8
	ctx.lr = 0x824FB2C8;
	sub_824FB1B8(ctx, base);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x824fb31c
	if (!cr6.gt) goto loc_824FB31C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824FB2E0:
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r11,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, r11.u32);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x824fb308
	if (cr6.lt) goto loc_824FB308;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_824FB308:
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824fb2e0
	if (cr6.lt) goto loc_824FB2E0;
loc_824FB31C:
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

__attribute__((alias("__imp__sub_824FB330"))) PPC_WEAK_FUNC(sub_824FB330);
PPC_FUNC_IMPL(__imp__sub_824FB330) {
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
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32244
	ctx.r10.s64 = r11.s64 + 32244;
	// lwz r11,32252(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32252);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824fb378
	if (!cr6.eq) goto loc_824FB378;
	// ori r8,r11,1
	ctx.r8.u64 = r11.u64 | 1;
	// li r11,0
	r11.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,32252(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32252, ctx.r8.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x824fb37c
	goto loc_824FB37C;
loc_824FB378:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_824FB37C:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb39c
	if (cr6.eq) goto loc_824FB39C;
loc_824FB388:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fb230
	ctx.lr = 0x824FB390;
	sub_824FB230(ctx, base);
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824fb388
	if (!cr6.eq) goto loc_824FB388;
loc_824FB39C:
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

__attribute__((alias("__imp__sub_824FB3B0"))) PPC_WEAK_FUNC(sub_824FB3B0);
PPC_FUNC_IMPL(__imp__sub_824FB3B0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,32240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32240);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824fb3d8
	if (!cr6.eq) goto loc_824FB3D8;
	// bl 0x824fb330
	ctx.lr = 0x824FB3D4;
	sub_824FB330(ctx, base);
	// lwz r11,32240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32240);
loc_824FB3D8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,32240(r31)
	PPC_STORE_U32(r31.u32 + 32240, r11.u32);
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

__attribute__((alias("__imp__sub_824FB3F4"))) PPC_WEAK_FUNC(sub_824FB3F4);
PPC_FUNC_IMPL(__imp__sub_824FB3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB3F8"))) PPC_WEAK_FUNC(sub_824FB3F8);
PPC_FUNC_IMPL(__imp__sub_824FB3F8) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB418;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r31,r10,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824FB430;
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

__attribute__((alias("__imp__sub_824FB448"))) PPC_WEAK_FUNC(sub_824FB448);
PPC_FUNC_IMPL(__imp__sub_824FB448) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824fb48c
	if (!cr6.eq) goto loc_824FB48C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb480
	if (cr6.eq) goto loc_824FB480;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824fb4c4
	if (!cr6.eq) goto loc_824FB4C4;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824fb4c4
	goto loc_824FB4C4;
loc_824FB480:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824fb4c4
	goto loc_824FB4C4;
loc_824FB48C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824fb4ac
	if (!cr6.eq) goto loc_824FB4AC;
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824fb4c4
	goto loc_824FB4C4;
loc_824FB4AC:
	// stw r5,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r5.u32);
	// lwz r11,16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// stw r11,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, r11.u32);
	// lwz r10,16(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// stw r6,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r6.u32);
loc_824FB4C4:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FB4DC"))) PPC_WEAK_FUNC(sub_824FB4DC);
PPC_FUNC_IMPL(__imp__sub_824FB4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB4E0"))) PPC_WEAK_FUNC(sub_824FB4E0);
PPC_FUNC_IMPL(__imp__sub_824FB4E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb508
	if (cr6.eq) goto loc_824FB508;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_824FB508:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fb528
	if (cr6.eq) goto loc_824FB528;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824fb52c
	if (!cr6.eq) goto loc_824FB52C;
loc_824FB528:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824FB52C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fb548
	if (cr6.eq) goto loc_824FB548;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824FB548:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FB55C"))) PPC_WEAK_FUNC(sub_824FB55C);
PPC_FUNC_IMPL(__imp__sub_824FB55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB560"))) PPC_WEAK_FUNC(sub_824FB560);
PPC_FUNC_IMPL(__imp__sub_824FB560) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB584;
	sub_821C8FE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82500f98
	ctx.lr = 0x824FB590;
	sub_82500F98(ctx, base);
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// beq cr6,0x824fb5d8
	if (cr6.eq) goto loc_824FB5D8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x824fb5d8
	if (!cr6.eq) goto loc_824FB5D8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// beq cr6,0x824fb61c
	if (cr6.eq) goto loc_824FB61C;
loc_824FB5B8:
	// bl 0x8252fd78
	ctx.lr = 0x824FB5BC;
	sub_8252FD78(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824fb4e0
	ctx.lr = 0x824FB5C8;
	sub_824FB4E0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fb5b8
	if (!cr6.eq) goto loc_824FB5B8;
	// b 0x824fb61c
	goto loc_824FB61C;
loc_824FB5D8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824fb61c
	if (cr6.eq) goto loc_824FB61C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fb61c
	if (!cr6.eq) goto loc_824FB61C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// beq cr6,0x824fb61c
	if (cr6.eq) goto loc_824FB61C;
loc_824FB600:
	// bl 0x8252fc40
	ctx.lr = 0x824FB604;
	sub_8252FC40(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824fb4e0
	ctx.lr = 0x824FB610;
	sub_824FB4E0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fb600
	if (!cr6.eq) goto loc_824FB600;
loc_824FB61C:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824fb67c
	if (cr6.eq) goto loc_824FB67C;
loc_824FB628:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f8c58
	ctx.lr = 0x824FB630;
	sub_824F8C58(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824fb640
	if (cr6.eq) goto loc_824FB640;
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// b 0x824fb674
	goto loc_824FB674;
loc_824FB640:
	// rlwinm r11,r31,0,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb65c
	if (cr6.eq) goto loc_824FB65C;
	// clrlwi r11,r31,31
	r11.u64 = r31.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fb660
	if (!cr6.eq) goto loc_824FB660;
loc_824FB65C:
	// li r11,0
	r11.s64 = 0;
loc_824FB660:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb67c
	if (cr6.eq) goto loc_824FB67C;
	// rlwinm r31,r31,0,0,30
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_824FB674:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824fb628
	if (!cr6.eq) goto loc_824FB628;
loc_824FB67C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824FB684;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_824FB69C"))) PPC_WEAK_FUNC(sub_824FB69C);
PPC_FUNC_IMPL(__imp__sub_824FB69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB6A0"))) PPC_WEAK_FUNC(sub_824FB6A0);
PPC_FUNC_IMPL(__imp__sub_824FB6A0) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB6C8;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb6f8
	if (cr6.eq) goto loc_824FB6F8;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824fb6f8
	if (!cr6.eq) goto loc_824FB6F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f8b10
	ctx.lr = 0x824FB6E4;
	sub_824F8B10(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f3d58
	ctx.lr = 0x824FB6F8;
	sub_824F3D58(ctx, base);
loc_824FB6F8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824FB700;
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

__attribute__((alias("__imp__sub_824FB718"))) PPC_WEAK_FUNC(sub_824FB718);
PPC_FUNC_IMPL(__imp__sub_824FB718) {
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
	ctx.lr = 0x824FB720;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB744;
	sub_821C8FE0(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r28,1
	r28.s64 = 1;
	// bl 0x824fb448
	ctx.lr = 0x824FB75C;
	sub_824FB448(ctx, base);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f8908
	ctx.lr = 0x824FB770;
	sub_824F8908(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB77C;
	sub_821C8FE0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r29,r10,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x821c9030
	ctx.lr = 0x824FB794;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824fb7c0
	if (cr6.eq) goto loc_824FB7C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252fd78
	ctx.lr = 0x824FB7A4;
	sub_8252FD78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fb7c0
	if (!cr6.eq) goto loc_824FB7C0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fb6a0
	ctx.lr = 0x824FB7BC;
	sub_824FB6A0(ctx, base);
	// li r28,0
	r28.s64 = 0;
loc_824FB7C0:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824FB7C8;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FB7D4"))) PPC_WEAK_FUNC(sub_824FB7D4);
PPC_FUNC_IMPL(__imp__sub_824FB7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB7D8"))) PPC_WEAK_FUNC(sub_824FB7D8);
PPC_FUNC_IMPL(__imp__sub_824FB7D8) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824FB808;
	sub_821C8ED8(ctx, base);
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

__attribute__((alias("__imp__sub_824FB820"))) PPC_WEAK_FUNC(sub_824FB820);
PPC_FUNC_IMPL(__imp__sub_824FB820) {
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
	ctx.lr = 0x824FB828;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb894
	if (cr6.eq) goto loc_824FB894;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// li r28,0
	r28.s64 = 0;
loc_824FB844:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824FB854;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb880
	if (cr6.eq) goto loc_824FB880;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x824fb880
	if (!cr6.eq) goto loc_824FB880;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f8b10
	ctx.lr = 0x824FB870;
	sub_824F8B10(ctx, base);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f3d58
	ctx.lr = 0x824FB880;
	sub_824F3D58(ctx, base);
loc_824FB880:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824FB888;
	sub_821C9030(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fb844
	if (!cr6.eq) goto loc_824FB844;
loc_824FB894:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82500ea0
	ctx.lr = 0x824FB89C;
	sub_82500EA0(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x824FB8A4;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f5ba8
	ctx.lr = 0x824FB8AC;
	sub_824F5BA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824FB8B4"))) PPC_WEAK_FUNC(sub_824FB8B4);
PPC_FUNC_IMPL(__imp__sub_824FB8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB8B8"))) PPC_WEAK_FUNC(sub_824FB8B8);
PPC_FUNC_IMPL(__imp__sub_824FB8B8) {
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
	// li r11,0
	r11.s64 = 0;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x824FB8E4;
	sub_8244D150(ctx, base);
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

__attribute__((alias("__imp__sub_824FB8FC"))) PPC_WEAK_FUNC(sub_824FB8FC);
PPC_FUNC_IMPL(__imp__sub_824FB8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB900"))) PPC_WEAK_FUNC(sub_824FB900);
PPC_FUNC_IMPL(__imp__sub_824FB900) {
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
	ctx.lr = 0x824FB908;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8244d150
	ctx.lr = 0x824FB924;
	sub_8244D150(ctx, base);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce080
	ctx.lr = 0x824FB938;
	sub_821CE080(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FB948"))) PPC_WEAK_FUNC(sub_824FB948);
PPC_FUNC_IMPL(__imp__sub_824FB948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r5,28
	ctx.r5.s64 = 28;
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// b 0x8244d150
	sub_8244D150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FB960"))) PPC_WEAK_FUNC(sub_824FB960);
PPC_FUNC_IMPL(__imp__sub_824FB960) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fb97c
	if (cr6.eq) goto loc_824FB97C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fb980
	if (cr6.eq) goto loc_824FB980;
loc_824FB97C:
	// li r11,0
	r11.s64 = 0;
loc_824FB980:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FB988"))) PPC_WEAK_FUNC(sub_824FB988);
PPC_FUNC_IMPL(__imp__sub_824FB988) {
	PPC_FUNC_PROLOGUE();
	// b 0x82450030
	sub_82450030(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FB98C"))) PPC_WEAK_FUNC(sub_824FB98C);
PPC_FUNC_IMPL(__imp__sub_824FB98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FB990"))) PPC_WEAK_FUNC(sub_824FB990);
PPC_FUNC_IMPL(__imp__sub_824FB990) {
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
	ctx.lr = 0x824FB998;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,32256
	r31.s64 = r11.s64 + 32256;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fba14
	if (!cr6.eq) goto loc_824FBA14;
	// bl 0x8244bac8
	ctx.lr = 0x824FB9C4;
	sub_8244BAC8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r26,-32115
	r26.s64 = -2104688640;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r29,32272(r11)
	PPC_STORE_U32(r11.u32 + 32272, r29.u32);
	// stw r30,32268(r26)
	PPC_STORE_U32(r26.u32 + 32268, r30.u32);
	// bl 0x8244d5c0
	ctx.lr = 0x824FB9E4;
	sub_8244D5C0(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r3,32268(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 32268);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r11,32276(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32276, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FBA04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// bl 0x824fb3b0
	ctx.lr = 0x824FBA14;
	sub_824FB3B0(ctx, base);
loc_824FBA14:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FBA1C"))) PPC_WEAK_FUNC(sub_824FBA1C);
PPC_FUNC_IMPL(__imp__sub_824FBA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBA20"))) PPC_WEAK_FUNC(sub_824FBA20);
PPC_FUNC_IMPL(__imp__sub_824FBA20) {
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
	// addi r31,r11,32260
	r31.s64 = r11.s64 + 32260;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbaac
	if (cr6.eq) goto loc_824FBAAC;
	// bl 0x824fa8a8
	ctx.lr = 0x824FBA4C;
	sub_824FA8A8(ctx, base);
	// bl 0x8244bad8
	ctx.lr = 0x824FBA50;
	sub_8244BAD8(ctx, base);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,29256
	ctx.r4.s64 = r11.s64 + 29256;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FBA74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,32272(r8)
	PPC_STORE_U32(ctx.r8.u32 + 32272, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x824FBA90;
	sub_8244D150(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,32268(r30)
	PPC_STORE_U32(r30.u32 + 32268, ctx.r10.u32);
	// stw r11,32276(r7)
	PPC_STORE_U32(ctx.r7.u32 + 32276, r11.u32);
	// stb r9,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r9.u8);
loc_824FBAAC:
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

__attribute__((alias("__imp__sub_824FBAC4"))) PPC_WEAK_FUNC(sub_824FBAC4);
PPC_FUNC_IMPL(__imp__sub_824FBAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBAC8"))) PPC_WEAK_FUNC(sub_824FBAC8);
PPC_FUNC_IMPL(__imp__sub_824FBAC8) {
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
	ctx.lr = 0x824FBAD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbaf8
	if (cr6.eq) goto loc_824FBAF8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fbafc
	if (cr6.eq) goto loc_824FBAFC;
loc_824FBAF8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824FBAFC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbb5c
	if (cr6.eq) goto loc_824FBB5C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,997
	cr6.compare<uint32_t>(r11.u32, 997, xer);
	// beq cr6,0x824fbb5c
	if (cr6.eq) goto loc_824FBB5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82450030
	ctx.lr = 0x824FBB1C;
	sub_82450030(ctx, base);
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x824fbb48
	if (!cr6.eq) goto loc_824FBB48;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824FBB38;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FBB48:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824FBB50;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
loc_824FBB5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FBB64"))) PPC_WEAK_FUNC(sub_824FBB64);
PPC_FUNC_IMPL(__imp__sub_824FBB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBB68"))) PPC_WEAK_FUNC(sub_824FBB68);
PPC_FUNC_IMPL(__imp__sub_824FBB68) {
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
	ctx.lr = 0x824FBB70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbb98
	if (cr6.eq) goto loc_824FBB98;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fbb9c
	if (cr6.eq) goto loc_824FBB9C;
loc_824FBB98:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824FBB9C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbbcc
	if (cr6.eq) goto loc_824FBBCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275cce0
	ctx.lr = 0x824FBBB0;
	sub_8275CCE0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FBBC4;
	sub_821CE0A0(ctx, base);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
loc_824FBBCC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FBBD4"))) PPC_WEAK_FUNC(sub_824FBBD4);
PPC_FUNC_IMPL(__imp__sub_824FBBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBBD8"))) PPC_WEAK_FUNC(sub_824FBBD8);
PPC_FUNC_IMPL(__imp__sub_824FBBD8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// subf r9,r31,r30
	ctx.r9.s64 = r30.s64 - r31.s64;
	// li r10,16
	ctx.r10.s64 = 16;
loc_824FBC00:
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x824fbc00
	if (!cr0.eq) goto loc_824FBC00;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r4,r30,44
	ctx.r4.s64 = r30.s64 + 44;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lwz r9,24(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r7,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r7.u32);
	// lwz r6,36(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// lwz r5,40(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r5,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r5.u32);
	// bl 0x824ea350
	ctx.lr = 0x824FBC58;
	sub_824EA350(ctx, base);
	// addi r4,r30,557
	ctx.r4.s64 = r30.s64 + 557;
	// addi r3,r31,557
	ctx.r3.s64 = r31.s64 + 557;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824FBC68;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_824FBC84"))) PPC_WEAK_FUNC(sub_824FBC84);
PPC_FUNC_IMPL(__imp__sub_824FBC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBC88"))) PPC_WEAK_FUNC(sub_824FBC88);
PPC_FUNC_IMPL(__imp__sub_824FBC88) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824FBC90;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,228(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// li r11,0
	r11.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// bl 0x823da950
	ctx.lr = 0x824FBCD0;
	sub_823DA950(ctx, base);
	// stw r29,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r29.u32);
	// stw r28,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r28.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,116
	ctx.r3.s64 = r31.s64 + 116;
	// bl 0x824ea350
	ctx.lr = 0x824FBCE4;
	sub_824EA350(ctx, base);
	// stw r26,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r26.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r31,636
	ctx.r3.s64 = r31.s64 + 636;
	// bl 0x824ea350
	ctx.lr = 0x824FBCF4;
	sub_824EA350(ctx, base);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824FBD00"))) PPC_WEAK_FUNC(sub_824FBD00);
PPC_FUNC_IMPL(__imp__sub_824FBD00) {
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
	ctx.lr = 0x824FBD08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r11,1456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1456);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824fbd48
	if (!cr6.eq) goto loc_824FBD48;
	// bl 0x824fb3b0
	ctx.lr = 0x824FBD30;
	sub_824FB3B0(ctx, base);
	// lbz r11,1456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1456);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r29,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r29.u32);
	// stb r10,1456(r31)
	PPC_STORE_U8(r31.u32 + 1456, ctx.r10.u8);
loc_824FBD48:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FBD50"))) PPC_WEAK_FUNC(sub_824FBD50);
PPC_FUNC_IMPL(__imp__sub_824FBD50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,1436(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbd6c
	if (cr6.eq) goto loc_824FBD6C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fbd70
	if (cr6.eq) goto loc_824FBD70;
loc_824FBD6C:
	// li r11,0
	r11.s64 = 0;
loc_824FBD70:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FBD78"))) PPC_WEAK_FUNC(sub_824FBD78);
PPC_FUNC_IMPL(__imp__sub_824FBD78) {
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
	ctx.lr = 0x824FBD80;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e30
	ctx.lr = 0x824FBD94;
	sub_824E8E30(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824fbe14
	if (!cr6.gt) goto loc_824FBE14;
	// li r28,0
	r28.s64 = 0;
loc_824FBDA8:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r9,r28,r11
	ctx.r9.u64 = r28.u64 + r11.u64;
	// ldx r8,r28,r11
	ctx.r8.u64 = PPC_LOAD_U64(r28.u32 + r11.u32);
	// std r8,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r8.u64);
	// ld r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// std r7,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, ctx.r7.u64);
	// ld r6,16(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 16);
	// std r6,16(r10)
	PPC_STORE_U64(ctx.r10.u32 + 16, ctx.r6.u64);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x824e9448
	ctx.lr = 0x824FBDD8;
	sub_824E9448(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824fbe00
	if (cr6.lt) goto loc_824FBE00;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x824e8e70
	ctx.lr = 0x824FBDEC;
	sub_824E8E70(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9530
	ctx.lr = 0x824FBE00;
	sub_824E9530(ctx, base);
loc_824FBE00:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,24
	r28.s64 = r28.s64 + 24;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x824fbda8
	if (cr6.lt) goto loc_824FBDA8;
loc_824FBE14:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824fbe6c
	if (!cr6.gt) goto loc_824FBE6C;
	// li r28,0
	r28.s64 = 0;
loc_824FBE28:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// lwzx r4,r11,r28
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// bl 0x824e9448
	ctx.lr = 0x824FBE3C;
	sub_824E9448(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824fbe58
	if (cr6.lt) goto loc_824FBE58;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r30,4
	ctx.r5.s64 = r30.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9530
	ctx.lr = 0x824FBE58;
	sub_824E9530(ctx, base);
loc_824FBE58:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x824fbe28
	if (cr6.lt) goto loc_824FBE28;
loc_824FBE6C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FBE78"))) PPC_WEAK_FUNC(sub_824FBE78);
PPC_FUNC_IMPL(__imp__sub_824FBE78) {
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
	ctx.lr = 0x824FBE80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r4,1384(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1384);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fbeb4
	if (cr6.eq) goto loc_824FBEB4;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FBEB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, r29.u32);
loc_824FBEB4:
	// lwz r4,1388(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fbed8
	if (cr6.eq) goto loc_824FBED8;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FBED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, r29.u32);
loc_824FBED8:
	// lwz r4,1396(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1396);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fbefc
	if (cr6.eq) goto loc_824FBEFC;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FBEF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,1396(r31)
	PPC_STORE_U32(r31.u32 + 1396, r29.u32);
loc_824FBEFC:
	// addi r3,r31,1400
	ctx.r3.s64 = r31.s64 + 1400;
	// bl 0x824fb948
	ctx.lr = 0x824FBF04;
	sub_824FB948(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FBF0C"))) PPC_WEAK_FUNC(sub_824FBF0C);
PPC_FUNC_IMPL(__imp__sub_824FBF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FBF10"))) PPC_WEAK_FUNC(sub_824FBF10);
PPC_FUNC_IMPL(__imp__sub_824FBF10) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,60
	ctx.r5.s64 = 60;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6438
	ctx.lr = 0x824FBF38;
	sub_824E6438(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fbf64
	if (cr6.eq) goto loc_824FBF64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x824FBF54;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fbf68
	if (!cr6.eq) goto loc_824FBF68;
loc_824FBF64:
	// li r11,0
	r11.s64 = 0;
loc_824FBF68:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FBF80"))) PPC_WEAK_FUNC(sub_824FBF80);
PPC_FUNC_IMPL(__imp__sub_824FBF80) {
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
	ctx.lr = 0x824FBF88;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x826187d0
	ctx.lr = 0x824FBF98;
	sub_826187D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FBFA4;
	sub_82656BF8(ctx, base);
	// subf r11,r3,r30
	r11.s64 = r30.s64 - ctx.r3.s64;
	// srawi r30,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r30.s64 = r11.s32 >> 3;
	// cmplwi cr6,r30,513
	cr6.compare<uint32_t>(r30.u32, 513, xer);
	// ble cr6,0x824fbfb8
	if (!cr6.gt) goto loc_824FBFB8;
	// li r30,513
	r30.s64 = 513;
loc_824FBFB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FBFC0;
	sub_82656BF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619320
	ctx.lr = 0x824FBFD4;
	sub_82619320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc03c
	if (cr6.eq) goto loc_824FC03C;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9c48
	ctx.lr = 0x824FBFF4;
	sub_824E9C48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc03c
	if (cr6.eq) goto loc_824FC03C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82618870
	ctx.lr = 0x824FC00C;
	sub_82618870(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc03c
	if (cr6.eq) goto loc_824FC03C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824FC020;
	sub_82656BF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826189e8
	ctx.lr = 0x824FC02C;
	sub_826189E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fc040
	if (!cr6.eq) goto loc_824FC040;
loc_824FC03C:
	// li r11,0
	r11.s64 = 0;
loc_824FC040:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FC04C"))) PPC_WEAK_FUNC(sub_824FC04C);
PPC_FUNC_IMPL(__imp__sub_824FC04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FC050"))) PPC_WEAK_FUNC(sub_824FC050);
PPC_FUNC_IMPL(__imp__sub_824FC050) {
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
	ctx.lr = 0x824FC058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8de8
	ctx.lr = 0x824FC06C;
	sub_824E8DE8(ctx, base);
	// addi r28,r31,557
	r28.s64 = r31.s64 + 557;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6400
	ctx.lr = 0x824FC078;
	sub_824E6400(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r30,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r30.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// bl 0x824e6348
	ctx.lr = 0x824FC08C;
	sub_824E6348(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x824e8e30
	ctx.lr = 0x824FC09C;
	sub_824E8E30(ctx, base);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824FC0B8"))) PPC_WEAK_FUNC(sub_824FC0B8);
PPC_FUNC_IMPL(__imp__sub_824FC0B8) {
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
	ctx.lr = 0x824FC0C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r31,557
	r28.s64 = r31.s64 + 557;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r30,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r30.u8);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
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
	// bl 0x824e6348
	ctx.lr = 0x824FC0FC;
	sub_824E6348(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r27,r31,44
	r27.s64 = r31.s64 + 44;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e8e30
	ctx.lr = 0x824FC110;
	sub_824E8E30(ctx, base);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r8,15
	ctx.r8.s64 = 15;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824FC12C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fc1bc
	if (cr6.eq) goto loc_824FC1BC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fc1a0
	if (cr6.eq) goto loc_824FC1A0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fc1a8
	if (cr6.eq) goto loc_824FC1A8;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fc1b0
	if (cr6.eq) goto loc_824FC1B0;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fc1b8
	if (cr6.eq) goto loc_824FC1B8;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addic. r8,r8,-5
	xer.ca = ctx.r8.u32 > 4;
	ctx.r8.s64 = ctx.r8.s64 + -5;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// bgt 0x824fc12c
	if (cr0.gt) goto loc_824FC12C;
	// b 0x824fc1bc
	goto loc_824FC1BC;
loc_824FC1A0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824fc1bc
	goto loc_824FC1BC;
loc_824FC1A8:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x824fc1bc
	goto loc_824FC1BC;
loc_824FC1B0:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x824fc1bc
	goto loc_824FC1BC;
loc_824FC1B8:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_824FC1BC:
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r26,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r26.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x824FC1D4;
	sub_823DA950(ctx, base);
	// stw r24,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r24.u32);
	// stw r23,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r23.u32);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ea350
	ctx.lr = 0x824FC1E8;
	sub_824EA350(ctx, base);
	// lwz r11,260(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// lwz r10,268(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r9,276(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// stw r21,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r21.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// stw r9,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824FC20C"))) PPC_WEAK_FUNC(sub_824FC20C);
PPC_FUNC_IMPL(__imp__sub_824FC20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FC210"))) PPC_WEAK_FUNC(sub_824FC210);
PPC_FUNC_IMPL(__imp__sub_824FC210) {
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
	ctx.lr = 0x824FC218;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824FC23C;
	sub_82618750(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824FC24C;
	sub_82618640(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82619080
	ctx.lr = 0x824FC25C;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824FC278;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x824FC294;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x824FC2B0;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x824FC2CC;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x824FC2E8;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b338
	ctx.lr = 0x824FC304;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824FC320;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// addi r4,r31,44
	ctx.r4.s64 = r31.s64 + 44;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fa460
	ctx.lr = 0x824FC338;
	sub_824FA460(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// addi r4,r31,557
	ctx.r4.s64 = r31.s64 + 557;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fbf10
	ctx.lr = 0x824FC350;
	sub_824FBF10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc36c
	if (cr6.eq) goto loc_824FC36C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824FC364;
	sub_826186A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,1
	r29.s64 = 1;
loc_824FC36C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824fc38c
	if (cr6.eq) goto loc_824FC38C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x824fc388
	if (!cr6.eq) goto loc_824FC388;
	// li r11,0
	r11.s64 = 0;
loc_824FC388:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824FC38C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FC398"))) PPC_WEAK_FUNC(sub_824FC398);
PPC_FUNC_IMPL(__imp__sub_824FC398) {
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
	ctx.lr = 0x824FC3A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824FC3C4;
	sub_82618750(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826185e0
	ctx.lr = 0x824FC3D4;
	sub_826185E0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618fa0
	ctx.lr = 0x824FC3E4;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82257568
	ctx.lr = 0x824FC400;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,20
	ctx.r4.s64 = r31.s64 + 20;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275750
	ctx.lr = 0x824FC41C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275750
	ctx.lr = 0x824FC438;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275750
	ctx.lr = 0x824FC454;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275750
	ctx.lr = 0x824FC470;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82275750
	ctx.lr = 0x824FC48C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82257568
	ctx.lr = 0x824FC4A8;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// addi r4,r31,44
	ctx.r4.s64 = r31.s64 + 44;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fbf80
	ctx.lr = 0x824FC4C0;
	sub_824FBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// addi r4,r31,557
	ctx.r4.s64 = r31.s64 + 557;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f9f90
	ctx.lr = 0x824FC4D8;
	sub_824F9F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc4f4
	if (cr6.eq) goto loc_824FC4F4;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186b0
	ctx.lr = 0x824FC4EC;
	sub_826186B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,1
	r29.s64 = 1;
loc_824FC4F4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824fc514
	if (cr6.eq) goto loc_824FC514;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x824fc510
	if (!cr6.eq) goto loc_824FC510;
	// li r11,0
	r11.s64 = 0;
loc_824FC510:
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824FC514:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FC520"))) PPC_WEAK_FUNC(sub_824FC520);
PPC_FUNC_IMPL(__imp__sub_824FC520) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824FC528;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e71c8
	ctx.lr = 0x824FC538;
	sub_824E71C8(ctx, base);
	// addi r30,r31,116
	r30.s64 = r31.s64 + 116;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8de8
	ctx.lr = 0x824FC544;
	sub_824E8DE8(ctx, base);
	// addi r29,r31,636
	r29.s64 = r31.s64 + 636;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8de8
	ctx.lr = 0x824FC550;
	sub_824E8DE8(ctx, base);
	// addi r28,r31,1149
	r28.s64 = r31.s64 + 1149;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6400
	ctx.lr = 0x824FC55C;
	sub_824E6400(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// li r27,0
	r27.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r27,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r27.u32);
	// bl 0x824e8e30
	ctx.lr = 0x824FC578;
	sub_824E8E30(ctx, base);
	// stw r27,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e30
	ctx.lr = 0x824FC584;
	sub_824E8E30(ctx, base);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6348
	ctx.lr = 0x824FC590;
	sub_824E6348(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FC59C"))) PPC_WEAK_FUNC(sub_824FC59C);
PPC_FUNC_IMPL(__imp__sub_824FC59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FC5A0"))) PPC_WEAK_FUNC(sub_824FC5A0);
PPC_FUNC_IMPL(__imp__sub_824FC5A0) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// bl 0x824f9150
	ctx.lr = 0x824FC5C8;
	sub_824F9150(ctx, base);
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// bl 0x824fc520
	ctx.lr = 0x824FC5D4;
	sub_824FC520(ctx, base);
	// std r30,1376(r31)
	PPC_STORE_U64(r31.u32 + 1376, r30.u64);
	// stw r30,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, r30.u32);
	// addi r3,r31,1400
	ctx.r3.s64 = r31.s64 + 1400;
	// stw r30,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, r30.u32);
	// stw r30,1396(r31)
	PPC_STORE_U32(r31.u32 + 1396, r30.u32);
	// bl 0x824fb8b8
	ctx.lr = 0x824FC5EC;
	sub_824FB8B8(ctx, base);
	// stw r30,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r30.u32);
	// stw r30,1440(r31)
	PPC_STORE_U32(r31.u32 + 1440, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,1444(r31)
	PPC_STORE_U32(r31.u32 + 1444, r30.u32);
	// stw r30,1448(r31)
	PPC_STORE_U32(r31.u32 + 1448, r30.u32);
	// stw r30,1452(r31)
	PPC_STORE_U32(r31.u32 + 1452, r30.u32);
	// lbz r11,1456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1456);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,1456(r31)
	PPC_STORE_U8(r31.u32 + 1456, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_824FC628"))) PPC_WEAK_FUNC(sub_824FC628);
PPC_FUNC_IMPL(__imp__sub_824FC628) {
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
	// bl 0x824fbe78
	ctx.lr = 0x824FC644;
	sub_824FBE78(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FC650;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fc664
	if (cr6.eq) goto loc_824FC664;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FC664;
	sub_824FB6A0(ctx, base);
loc_824FC664:
	// li r11,0
	r11.s64 = 0;
	// stw r11,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r11.u32);
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

__attribute__((alias("__imp__sub_824FC684"))) PPC_WEAK_FUNC(sub_824FC684);
PPC_FUNC_IMPL(__imp__sub_824FC684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FC688"))) PPC_WEAK_FUNC(sub_824FC688);
PPC_FUNC_IMPL(__imp__sub_824FC688) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824FC690;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x824fc718
	if (!cr6.gt) goto loc_824FC718;
	// lis r7,16384
	ctx.r7.s64 = 1073741824;
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// ori r7,r7,33033
	ctx.r7.u64 = ctx.r7.u64 | 33033;
loc_824FC6BC:
	// ld r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r31,r1,-64
	r31.s64 = ctx.r1.s64 + -64;
	// ld r30,8(r11)
	r30.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// ld r29,16(r11)
	r29.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// std r3,0(r31)
	PPC_STORE_U64(r31.u32 + 0, ctx.r3.u64);
	// std r30,8(r31)
	PPC_STORE_U64(r31.u32 + 8, r30.u64);
	// std r29,16(r31)
	PPC_STORE_U64(r31.u32 + 16, r29.u64);
	// lwz r3,-64(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	// cmplw cr6,r3,r7
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r7.u32, xer);
	// beq cr6,0x824fc6f8
	if (cr6.eq) goto loc_824FC6F8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x824fc6bc
	if (cr6.lt) goto loc_824FC6BC;
	// b 0x824fc718
	goto loc_824FC718;
loc_824FC6F8:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// li r6,1
	ctx.r6.s64 = 1;
	// ld r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U64(r11.u32 + 16);
	// std r9,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r9.u64);
	// std r7,8(r8)
	PPC_STORE_U64(ctx.r8.u32 + 8, ctx.r7.u64);
	// std r3,16(r8)
	PPC_STORE_U64(ctx.r8.u32 + 16, ctx.r3.u64);
loc_824FC718:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc76c
	if (cr6.eq) goto loc_824FC76C;
	// lwz r11,-48(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bgt cr6,0x824fc734
	if (cr6.gt) goto loc_824FC734;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_824FC734:
	// lwz r9,-44(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x824fc760
	if (!cr0.gt) goto loc_824FC760;
loc_824FC740:
	// lhz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824fc760
	if (cr6.eq) goto loc_824FC760;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bgt 0x824fc740
	if (cr0.gt) goto loc_824FC740;
loc_824FC760:
	// stb r4,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d924c
	return;
loc_824FC76C:
	// addic. r9,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r9.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// ble 0x824fc7a0
	if (!cr0.gt) goto loc_824FC7A0;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r7,r8,29544
	ctx.r7.s64 = ctx.r8.s64 + 29544;
	// subf r8,r10,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r10.s64;
loc_824FC784:
	// lbzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fc7a0
	if (cr6.eq) goto loc_824FC7A0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x824fc784
	if (cr0.gt) goto loc_824FC784;
loc_824FC7A0:
	// stb r4,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r4.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FC7AC"))) PPC_WEAK_FUNC(sub_824FC7AC);
PPC_FUNC_IMPL(__imp__sub_824FC7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FC7B0"))) PPC_WEAK_FUNC(sub_824FC7B0);
PPC_FUNC_IMPL(__imp__sub_824FC7B0) {
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
	ctx.lr = 0x824FC7B8;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,1436(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc7e0
	if (cr6.eq) goto loc_824FC7E0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fc7e4
	if (cr6.eq) goto loc_824FC7E4;
loc_824FC7E0:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824FC7E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc7fc
	if (cr6.eq) goto loc_824FC7FC;
	// addi r3,r26,1400
	ctx.r3.s64 = r26.s64 + 1400;
	// bl 0x824fbac8
	ctx.lr = 0x824FC7FC;
	sub_824FBAC8(ctx, base);
loc_824FC7FC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824fc980
	if (cr6.eq) goto loc_824FC980;
	// lwz r11,1436(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc820
	if (cr6.eq) goto loc_824FC820;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fc824
	if (cr6.eq) goto loc_824FC824;
loc_824FC820:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824FC824:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fc980
	if (!cr6.eq) goto loc_824FC980;
	// addi r3,r26,1400
	ctx.r3.s64 = r26.s64 + 1400;
	// bl 0x824fb988
	ctx.lr = 0x824FC838;
	sub_824FB988(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fc950
	if (!cr6.eq) goto loc_824FC950;
	// lwz r28,264(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 264);
	// lwz r23,1396(r26)
	r23.u64 = PPC_LOAD_U32(r26.u32 + 1396);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bgt cr6,0x824fc85c
	if (cr6.gt) goto loc_824FC85C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_824FC85C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r29.u32);
	// beq cr6,0x824fc950
	if (cr6.eq) goto loc_824FC950;
	// mr r25,r29
	r25.u64 = r29.u64;
	// mr r22,r11
	r22.u64 = r11.u64;
	// li r24,-1
	r24.s64 = -1;
loc_824FC874:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mulli r9,r11,620
	ctx.r9.s64 = r11.s64 * 620;
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// stbx r29,r9,r10
	PPC_STORE_U8(ctx.r9.u32 + ctx.r10.u32, r29.u8);
	// add r31,r9,r10
	r31.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r30,r25,r11
	r30.u64 = r25.u64 + r11.u64;
	// addi r3,r31,557
	ctx.r3.s64 = r31.s64 + 557;
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// bl 0x824e6348
	ctx.lr = 0x824FC89C;
	sub_824E6348(ctx, base);
	// stw r24,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r24.u32);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x824e8e30
	ctx.lr = 0x824FC8A8;
	sub_824E8E30(ctx, base);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824FC8C0;
	sub_824E8DE8(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fc688
	ctx.lr = 0x824FC8D0;
	sub_824FC688(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fc944
	if (cr6.eq) goto loc_824FC944;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fbd78
	ctx.lr = 0x824FC8E8;
	sub_824FBD78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fc944
	if (cr6.eq) goto loc_824FC944;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r27,72(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lwz r8,64(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,60(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// add r30,r8,r27
	r30.u64 = ctx.r8.u64 + r27.u64;
	// lwz r8,268(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 268);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r7,164(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 164);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x824fc0b8
	ctx.lr = 0x824FC938;
	sub_824FC0B8(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
loc_824FC944:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r25,r25,92
	r25.s64 = r25.s64 + 92;
	// bne 0x824fc874
	if (!cr0.eq) goto loc_824FC874;
loc_824FC950:
	// stw r29,1436(r26)
	PPC_STORE_U32(r26.u32 + 1436, r29.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824fbe78
	ctx.lr = 0x824FC95C;
	sub_824FBE78(ctx, base);
	// addi r31,r26,4
	r31.s64 = r26.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FC968;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fc97c
	if (cr6.eq) goto loc_824FC97C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FC97C;
	sub_824FB6A0(ctx, base);
loc_824FC97C:
	// stw r29,1436(r26)
	PPC_STORE_U32(r26.u32 + 1436, r29.u32);
loc_824FC980:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824FC988"))) PPC_WEAK_FUNC(sub_824FC988);
PPC_FUNC_IMPL(__imp__sub_824FC988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x824FC990;
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r19,r31,1400
	r19.s64 = r31.s64 + 1400;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// addi r4,r11,29560
	ctx.r4.s64 = r11.s64 + 29560;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r22,0
	r22.s64 = 0;
	// bl 0x824fb900
	ctx.lr = 0x824FC9B8;
	sub_824FB900(ctx, base);
	// addi r21,r31,168
	r21.s64 = r31.s64 + 168;
	// addi r29,r31,276
	r29.s64 = r31.s64 + 276;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821f8730
	ctx.lr = 0x824FC9C8;
	sub_821F8730(ctx, base);
	// lwz r10,792(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 792);
	// lwz r9,264(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r23,r31,1392
	r23.s64 = r31.s64 + 1392;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r28,4(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824FC9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r22,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r22.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r22,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r22.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8274bc18
	ctx.lr = 0x824FCA1C;
	sub_8274BC18(ctx, base);
	// lis r24,-32115
	r24.s64 = -2104688640;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fca30
	if (cr6.eq) goto loc_824FCA30;
	// cmplwi cr6,r3,122
	cr6.compare<uint32_t>(ctx.r3.u32, 122, xer);
	// bne cr6,0x824fcc28
	if (!cr6.eq) goto loc_824FCC28;
loc_824FCA30:
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FCA50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,1396(r31)
	PPC_STORE_U32(r31.u32 + 1396, ctx.r3.u32);
	// beq cr6,0x824fcc28
	if (cr6.eq) goto loc_824FCC28;
	// lwz r11,268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// lis r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// subf r9,r22,r11
	ctx.r9.s64 = r11.s64 - r22.s64;
	// ori r8,r10,32778
	ctx.r8.u64 = ctx.r10.u64 | 32778;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// mr r28,r22
	r28.u64 = r22.u64;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// li r25,1
	r25.s64 = 1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// mr r30,r22
	r30.u64 = r22.u64;
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// bl 0x824e8e58
	ctx.lr = 0x824FCA94;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824fcb68
	if (!cr6.gt) goto loc_824FCB68;
	// addi r27,r1,120
	r27.s64 = ctx.r1.s64 + 120;
	// addi r26,r1,368
	r26.s64 = ctx.r1.s64 + 368;
loc_824FCAA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8f28
	ctx.lr = 0x824FCAB0;
	sub_824E8F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fcb00
	if (!cr6.eq) goto loc_824FCB00;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9eb8
	ctx.lr = 0x824FCAC8;
	sub_824E9EB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// beq cr6,0x824fcaf0
	if (cr6.eq) goto loc_824FCAF0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x824e9f18
	ctx.lr = 0x824FCAE4;
	sub_824E9F18(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r26,r26,24
	r26.s64 = r26.s64 + 24;
	// b 0x824fcb00
	goto loc_824FCB00;
loc_824FCAF0:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x824ea0b8
	ctx.lr = 0x824FCAF8;
	sub_824EA0B8(ctx, base);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
loc_824FCB00:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x824e8e58
	ctx.lr = 0x824FCB0C;
	sub_824E8E58(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x824fcaa4
	if (cr6.lt) goto loc_824FCAA4;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x824fcb60
	if (cr6.eq) goto loc_824FCB60;
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r30,r11,3,0,28
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FCB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fcc28
	if (cr6.eq) goto loc_824FCC28;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// bl 0x8244d5c0
	ctx.lr = 0x824FCB60;
	sub_8244D5C0(ctx, base);
loc_824FCB60:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x824fcba4
	if (cr6.eq) goto loc_824FCBA4;
loc_824FCB68:
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// rlwinm r30,r25,3,0,28
	r30.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 3) & 0xFFFFFFF8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FCB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fcc28
	if (cr6.eq) goto loc_824FCC28;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8244d5c0
	ctx.lr = 0x824FCBA4;
	sub_8244D5C0(ctx, base);
loc_824FCBA4:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r30,792(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 792);
	// bl 0x82130000
	ctx.lr = 0x824FCBB0;
	sub_82130000(ctx, base);
	// lwz r11,264(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r27,1396(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 1396);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r26,1388(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// lwz r21,1384(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 1384);
	// lwz r18,272(r31)
	r18.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r17,4(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821f8730
	ctx.lr = 0x824FCBD4;
	sub_821F8730(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FCBEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// stw r23,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r23.u32);
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// clrlwi r7,r28,16
	ctx.r7.u64 = r28.u32 & 0xFFFF;
	// clrlwi r8,r25,16
	ctx.r8.u64 = r25.u32 & 0xFFFF;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// bl 0x8274bc18
	ctx.lr = 0x824FCC18;
	sub_8274BC18(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fcce8
	if (cr6.eq) goto loc_824FCCE8;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// beq cr6,0x824fcce8
	if (cr6.eq) goto loc_824FCCE8;
loc_824FCC28:
	// lwz r30,1432(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1432);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FCC3C;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lwz r4,1384(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1384);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fcc68
	if (cr6.eq) goto loc_824FCC68;
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FCC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r22,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, r22.u32);
loc_824FCC68:
	// lwz r4,1388(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fcc8c
	if (cr6.eq) goto loc_824FCC8C;
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FCC88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r22,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, r22.u32);
loc_824FCC8C:
	// lwz r4,1396(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1396);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fccb0
	if (cr6.eq) goto loc_824FCCB0;
	// lwz r3,32268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FCCAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r22,1396(r31)
	PPC_STORE_U32(r31.u32 + 1396, r22.u32);
loc_824FCCB0:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x824fb948
	ctx.lr = 0x824FCCB8;
	sub_824FB948(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FCCC4;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fccd8
	if (cr6.eq) goto loc_824FCCD8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FCCD8;
	sub_824FB6A0(ctx, base);
loc_824FCCD8:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r22,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r22.u32);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9218
	return;
loc_824FCCE8:
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r20,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r20.u32);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_824FCCF8"))) PPC_WEAK_FUNC(sub_824FCCF8);
PPC_FUNC_IMPL(__imp__sub_824FCCF8) {
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
	// lwz r11,1436(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fcd2c
	if (cr6.eq) goto loc_824FCD2C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fcd30
	if (cr6.eq) goto loc_824FCD30;
loc_824FCD2C:
	// li r11,0
	r11.s64 = 0;
loc_824FCD30:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fcd74
	if (cr6.eq) goto loc_824FCD74;
	// addi r3,r31,1400
	ctx.r3.s64 = r31.s64 + 1400;
	// bl 0x824fbb68
	ctx.lr = 0x824FCD44;
	sub_824FBB68(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fbe78
	ctx.lr = 0x824FCD4C;
	sub_824FBE78(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FCD58;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fcd6c
	if (cr6.eq) goto loc_824FCD6C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FCD6C;
	sub_824FB6A0(ctx, base);
loc_824FCD6C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r11.u32);
loc_824FCD74:
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

__attribute__((alias("__imp__sub_824FCD8C"))) PPC_WEAK_FUNC(sub_824FCD8C);
PPC_FUNC_IMPL(__imp__sub_824FCD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FCD90"))) PPC_WEAK_FUNC(sub_824FCD90);
PPC_FUNC_IMPL(__imp__sub_824FCD90) {
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
	ctx.lr = 0x824FCD98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r31,1436(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1436);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824fcdc0
	if (cr6.eq) goto loc_824FCDC0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fcdc4
	if (cr6.eq) goto loc_824FCDC4;
loc_824FCDC0:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824FCDC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fce04
	if (cr6.eq) goto loc_824FCE04;
	// lwz r11,164(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824fcdfc
	if (!cr6.eq) goto loc_824FCDFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FCDEC;
	sub_821CE0A0(ctx, base);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r29,1436(r30)
	PPC_STORE_U32(r30.u32 + 1436, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824FCDFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fccf8
	ctx.lr = 0x824FCE04;
	sub_824FCCF8(ctx, base);
loc_824FCE04:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FCE0C"))) PPC_WEAK_FUNC(sub_824FCE0C);
PPC_FUNC_IMPL(__imp__sub_824FCE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FCE10"))) PPC_WEAK_FUNC(sub_824FCE10);
PPC_FUNC_IMPL(__imp__sub_824FCE10) {
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
	// bl 0x824e3e38
	ctx.lr = 0x824FCE30;
	sub_824E3E38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fce88
	if (cr6.eq) goto loc_824FCE88;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// bl 0x82618f70
	ctx.lr = 0x824FCE48;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fce88
	if (cr6.eq) goto loc_824FCE88;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fce70
	if (cr6.eq) goto loc_824FCE70;
	// addi r4,r31,21
	ctx.r4.s64 = r31.s64 + 21;
	// bl 0x824fa460
	ctx.lr = 0x824FCE6C;
	sub_824FA460(ctx, base);
	// b 0x824fce78
	goto loc_824FCE78;
loc_824FCE70:
	// addi r4,r31,534
	ctx.r4.s64 = r31.s64 + 534;
	// bl 0x824fbf10
	ctx.lr = 0x824FCE78;
	sub_824FBF10(ctx, base);
loc_824FCE78:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fce8c
	if (!cr6.eq) goto loc_824FCE8C;
loc_824FCE88:
	// li r11,0
	r11.s64 = 0;
loc_824FCE8C:
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

__attribute__((alias("__imp__sub_824FCEA8"))) PPC_WEAK_FUNC(sub_824FCEA8);
PPC_FUNC_IMPL(__imp__sub_824FCEA8) {
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
	// bl 0x824e3db0
	ctx.lr = 0x824FCEC8;
	sub_824E3DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fcef0
	if (cr6.eq) goto loc_824FCEF0;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa550
	ctx.lr = 0x824FCEE0;
	sub_824FA550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fcef4
	if (!cr6.eq) goto loc_824FCEF4;
loc_824FCEF0:
	// li r11,0
	r11.s64 = 0;
loc_824FCEF4:
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

__attribute__((alias("__imp__sub_824FCF10"))) PPC_WEAK_FUNC(sub_824FCF10);
PPC_FUNC_IMPL(__imp__sub_824FCF10) {
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
	ctx.lr = 0x824FCF18;
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
	ctx.lr = 0x824FCF3C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824FCF48;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824FCF58;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824fcf7c
	if (cr6.eq) goto loc_824FCF7C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824fce10
	ctx.lr = 0x824FCF6C;
	sub_824FCE10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fcf80
	if (!cr6.eq) goto loc_824FCF80;
loc_824FCF7C:
	// li r30,0
	r30.s64 = 0;
loc_824FCF80:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824fcfb8
	if (cr6.eq) goto loc_824FCFB8;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fcfb0
	if (cr6.eq) goto loc_824FCFB0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824FCF9C;
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
loc_824FCFB0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824FCFB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FCFC4"))) PPC_WEAK_FUNC(sub_824FCFC4);
PPC_FUNC_IMPL(__imp__sub_824FCFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FCFC8"))) PPC_WEAK_FUNC(sub_824FCFC8);
PPC_FUNC_IMPL(__imp__sub_824FCFC8) {
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
	ctx.lr = 0x824FCFD0;
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
	ctx.lr = 0x824FD000;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824FD00C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824FD01C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824fd04c
	if (cr6.eq) goto loc_824FD04C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824fd04c
	if (!cr6.eq) goto loc_824FD04C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824fcea8
	ctx.lr = 0x824FD03C;
	sub_824FCEA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd050
	if (!cr6.eq) goto loc_824FD050;
loc_824FD04C:
	// li r31,0
	r31.s64 = 0;
loc_824FD050:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824fd07c
	if (cr6.eq) goto loc_824FD07C;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd074
	if (cr6.eq) goto loc_824FD074;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824FD06C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824fd078
	goto loc_824FD078;
loc_824FD074:
	// li r11,0
	r11.s64 = 0;
loc_824FD078:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824FD07C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd0a0
	if (cr6.eq) goto loc_824FD0A0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824FD090;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fd0a4
	if (cr6.eq) goto loc_824FD0A4;
loc_824FD0A0:
	// li r11,0
	r11.s64 = 0;
loc_824FD0A4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FD0B0"))) PPC_WEAK_FUNC(sub_824FD0B0);
PPC_FUNC_IMPL(__imp__sub_824FD0B0) {
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
	// lbz r11,1456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1456);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fd124
	if (cr6.eq) goto loc_824FD124;
	// bl 0x824fcd90
	ctx.lr = 0x824FD0DC;
	sub_824FCD90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fbe78
	ctx.lr = 0x824FD0E4;
	sub_824FBE78(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FD0F0;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fd104
	if (cr6.eq) goto loc_824FD104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FD104;
	sub_824FB6A0(ctx, base);
loc_824FD104:
	// li r30,0
	r30.s64 = 0;
	// stw r30,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r30.u32);
	// bl 0x824fa8a8
	ctx.lr = 0x824FD110;
	sub_824FA8A8(ctx, base);
	// lbz r11,1456(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1456);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// stb r10,1456(r31)
	PPC_STORE_U8(r31.u32 + 1456, ctx.r10.u8);
loc_824FD124:
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

__attribute__((alias("__imp__sub_824FD13C"))) PPC_WEAK_FUNC(sub_824FD13C);
PPC_FUNC_IMPL(__imp__sub_824FD13C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD140"))) PPC_WEAK_FUNC(sub_824FD140);
PPC_FUNC_IMPL(__imp__sub_824FD140) {
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
	// bl 0x824fd0b0
	ctx.lr = 0x824FD158;
	sub_824FD0B0(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x824f91e0
	ctx.lr = 0x824FD160;
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

__attribute__((alias("__imp__sub_824FD174"))) PPC_WEAK_FUNC(sub_824FD174);
PPC_FUNC_IMPL(__imp__sub_824FD174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD178"))) PPC_WEAK_FUNC(sub_824FD178);
PPC_FUNC_IMPL(__imp__sub_824FD178) {
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
	ctx.lr = 0x824FD180;
	// stwu r1,-2432(r1)
	ea = -2432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x824FD18C;
	sub_821C9788(ctx, base);
	// lwz r11,1444(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1444);
	// li r27,1
	r27.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// ori r10,r3,1
	ctx.r10.u64 = ctx.r3.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd1b0
	if (cr6.eq) goto loc_824FD1B0;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// cmplwi cr6,r11,250
	cr6.compare<uint32_t>(r11.u32, 250, xer);
	// blt cr6,0x824fd2a0
	if (cr6.lt) goto loc_824FD2A0;
loc_824FD1B0:
	// lwz r11,1440(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1440);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x824fd1e4
	if (cr6.lt) goto loc_824FD1E4;
	// lwz r31,1436(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1436);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FD1D0;
	sub_821CE0A0(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r26,1436(r30)
	PPC_STORE_U32(r30.u32 + 1436, r26.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fc628
	ctx.lr = 0x824FD1E0;
	sub_824FC628(ctx, base);
	// b 0x824fd2a0
	goto loc_824FD2A0;
loc_824FD1E4:
	// lis r9,8
	ctx.r9.s64 = 524288;
	// stw r10,1444(r30)
	PPC_STORE_U32(r30.u32 + 1444, ctx.r10.u32);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// std r26,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r26.u64);
	// ori r7,r9,44613
	ctx.r7.u64 = ctx.r9.u64 | 44613;
	// stw r8,1440(r30)
	PPC_STORE_U32(r30.u32 + 1440, ctx.r8.u32);
	// addi r3,r1,117
	ctx.r3.s64 = ctx.r1.s64 + 117;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824FD208;
	sub_824E8DE8(ctx, base);
	// addi r3,r1,630
	ctx.r3.s64 = ctx.r1.s64 + 630;
	// bl 0x824e6400
	ctx.lr = 0x824FD210;
	sub_824E6400(ctx, base);
	// ld r11,1376(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 1376);
	// lwz r6,160(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bne cr6,0x824fd238
	if (!cr6.eq) goto loc_824FD238;
	// stb r27,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r27.u8);
	// addi r4,r30,276
	ctx.r4.s64 = r30.s64 + 276;
	// addi r3,r1,117
	ctx.r3.s64 = ctx.r1.s64 + 117;
	// bl 0x824ea350
	ctx.lr = 0x824FD234;
	sub_824EA350(ctx, base);
	// b 0x824fd24c
	goto loc_824FD24C;
loc_824FD238:
	// addi r4,r30,1309
	ctx.r4.s64 = r30.s64 + 1309;
	// stb r26,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r26.u8);
	// addi r3,r1,630
	ctx.r3.s64 = ctx.r1.s64 + 630;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824FD24C;
	sub_823DA950(ctx, base);
loc_824FD24C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,32332
	ctx.r10.s64 = r11.s64 + 32332;
	// li r6,1022
	ctx.r6.s64 = 1022;
	// addi r5,r1,1346
	ctx.r5.s64 = ctx.r1.s64 + 1346;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824fcf10
	ctx.lr = 0x824FD26C;
	sub_824FCF10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fd2a0
	if (cr6.eq) goto loc_824FD2A0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,156(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// addi r5,r1,1344
	ctx.r5.s64 = ctx.r1.s64 + 1344;
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// clrlwi r4,r10,16
	ctx.r4.u64 = ctx.r10.u32 & 0xFFFF;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// sth r9,1344(r1)
	PPC_STORE_U16(ctx.r1.u32 + 1344, ctx.r9.u16);
	// bl 0x824f8ea0
	ctx.lr = 0x824FD2A0;
	sub_824F8EA0(ctx, base);
loc_824FD2A0:
	// lwz r11,1436(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd2bc
	if (cr6.eq) goto loc_824FD2BC;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x824fd2c0
	if (cr6.eq) goto loc_824FD2C0;
loc_824FD2BC:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_824FD2C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd41c
	if (cr6.eq) goto loc_824FD41C;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824e6310
	ctx.lr = 0x824FD2D4;
	sub_824E6310(ctx, base);
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// bl 0x824e0d78
	ctx.lr = 0x824FD2DC;
	sub_824E0D78(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// addi r5,r1,1344
	ctx.r5.s64 = ctx.r1.s64 + 1344;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x824f8f38
	ctx.lr = 0x824FD2F4;
	sub_824F8F38(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x824fd41c
	if (cr6.lt) goto loc_824FD41C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,32300
	ctx.r10.s64 = r11.s64 + 32300;
	// addi r6,r31,-2
	ctx.r6.s64 = r31.s64 + -2;
	// addi r5,r1,1346
	ctx.r5.s64 = ctx.r1.s64 + 1346;
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824fcfc8
	ctx.lr = 0x824FD320;
	sub_824FCFC8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fd41c
	if (cr6.eq) goto loc_824FD41C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// cmpw cr6,r10,r31
	cr6.compare<int32_t>(ctx.r10.s32, r31.s32, xer);
	// bne cr6,0x824fd41c
	if (!cr6.eq) goto loc_824FD41C;
	// ld r11,1376(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 1376);
	// ld r10,712(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 712);
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// bne cr6,0x824fd41c
	if (!cr6.eq) goto loc_824FD41C;
	// lwz r31,264(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// mr r28,r26
	r28.u64 = r26.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824fd3a0
	if (!cr6.gt) goto loc_824FD3A0;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_824FD364:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,1277
	ctx.r4.s64 = ctx.r1.s64 + 1277;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r3,r11,557
	ctx.r3.s64 = r11.s64 + 557;
	// bl 0x824e6358
	ctx.lr = 0x824FD378;
	sub_824E6358(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd39c
	if (!cr6.eq) goto loc_824FD39C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,620
	r29.s64 = r29.s64 + 620;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x824fd364
	if (cr6.lt) goto loc_824FD364;
	// b 0x824fd3a0
	goto loc_824FD3A0;
loc_824FD39C:
	// mr r27,r26
	r27.u64 = r26.u64;
loc_824FD3A0:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// beq cr6,0x824fd408
	if (cr6.eq) goto loc_824FD408;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r11,r11,620
	r11.s64 = r11.s64 * 620;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// addi r4,r1,720
	ctx.r4.s64 = ctx.r1.s64 + 720;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x824fbbd8
	ctx.lr = 0x824FD3CC;
	sub_824FBBD8(ctx, base);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r8,r7
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, xer);
	// bne cr6,0x824fd41c
	if (!cr6.eq) goto loc_824FD41C;
	// lwz r31,1436(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1436);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FD3F0;
	sub_821CE0A0(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// stw r26,1436(r30)
	PPC_STORE_U32(r30.u32 + 1436, r26.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fc628
	ctx.lr = 0x824FD400;
	sub_824FC628(ctx, base);
	// addi r1,r1,2432
	ctx.r1.s64 = ctx.r1.s64 + 2432;
	// b 0x823d9240
	return;
loc_824FD408:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824fd41c
	if (!cr6.gt) goto loc_824FD41C;
	// lwz r11,1440(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1440);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1440(r30)
	PPC_STORE_U32(r30.u32 + 1440, r11.u32);
loc_824FD41C:
	// addi r1,r1,2432
	ctx.r1.s64 = ctx.r1.s64 + 2432;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FD424"))) PPC_WEAK_FUNC(sub_824FD424);
PPC_FUNC_IMPL(__imp__sub_824FD424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD428"))) PPC_WEAK_FUNC(sub_824FD428);
PPC_FUNC_IMPL(__imp__sub_824FD428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,1436(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd444
	if (cr6.eq) goto loc_824FD444;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824fd448
	if (cr6.eq) goto loc_824FD448;
loc_824FD444:
	// li r11,0
	r11.s64 = 0;
loc_824FD448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,164(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824fd464
	if (!cr6.eq) goto loc_824FD464;
	// b 0x824fd178
	sub_824FD178(ctx, base);
	return;
loc_824FD464:
	// b 0x824fc7b0
	sub_824FC7B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824FD468"))) PPC_WEAK_FUNC(sub_824FD468);
PPC_FUNC_IMPL(__imp__sub_824FD468) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FD46C"))) PPC_WEAK_FUNC(sub_824FD46C);
PPC_FUNC_IMPL(__imp__sub_824FD46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD470"))) PPC_WEAK_FUNC(sub_824FD470);
PPC_FUNC_IMPL(__imp__sub_824FD470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824FD478;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r23,0
	r23.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// mr r24,r10
	r24.u64 = ctx.r10.u64;
	// mr r22,r23
	r22.u64 = r23.u64;
	// bl 0x824fbd50
	ctx.lr = 0x824FD4A8;
	sub_824FBD50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r21,284(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd5cc
	if (!cr6.eq) goto loc_824FD5CC;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824fd4e8
	if (!cr6.eq) goto loc_824FD4E8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fd5cc
	if (cr6.eq) goto loc_824FD5CC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x824fb718
	ctx.lr = 0x824FD4DC;
	sub_824FB718(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd5cc
	if (cr6.eq) goto loc_824FD5CC;
loc_824FD4E8:
	// lwz r11,276(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,160
	ctx.r3.s64 = r31.s64 + 160;
	// bl 0x824fbc88
	ctx.lr = 0x824FD514;
	sub_824FBC88(ctx, base);
	// bl 0x82534e80
	ctx.lr = 0x824FD518;
	sub_82534E80(ctx, base);
	// std r3,1376(r31)
	PPC_STORE_U64(r31.u32 + 1376, ctx.r3.u64);
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824fd5a8
	if (!cr6.eq) goto loc_824FD5A8;
	// lwz r21,284(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// mr r30,r21
	r30.u64 = r21.u64;
	// bne cr6,0x824fd538
	if (!cr6.eq) goto loc_824FD538;
	// addi r30,r31,1448
	r30.s64 = r31.s64 + 1448;
loc_824FD538:
	// stw r30,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r23,1440(r31)
	PPC_STORE_U32(r31.u32 + 1440, r23.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r23,1444(r31)
	PPC_STORE_U32(r31.u32 + 1444, r23.u32);
	// bl 0x821ce080
	ctx.lr = 0x824FD550;
	sub_821CE080(ctx, base);
	// stw r23,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r23.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fd178
	ctx.lr = 0x824FD55C;
	sub_824FD178(ctx, base);
loc_824FD55C:
	// li r22,1
	r22.s64 = 1;
loc_824FD560:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd59c
	if (!cr6.eq) goto loc_824FD59C;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x824fd59c
	if (cr6.eq) goto loc_824FD59C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821ce080
	ctx.lr = 0x824FD580;
	sub_821CE080(ctx, base);
	// stw r23,4(r21)
	PPC_STORE_U32(r21.u32 + 4, r23.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FD594;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r21)
	PPC_STORE_U32(r21.u32 + 4, r11.u32);
loc_824FD59C:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
loc_824FD5A8:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bne cr6,0x824fd5b8
	if (!cr6.eq) goto loc_824FD5B8;
	// addi r4,r31,1448
	ctx.r4.s64 = r31.s64 + 1448;
loc_824FD5B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fc988
	ctx.lr = 0x824FD5C0;
	sub_824FC988(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd55c
	if (!cr6.eq) goto loc_824FD55C;
loc_824FD5CC:
	// lwz r4,1384(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1384);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fd5f4
	if (cr6.eq) goto loc_824FD5F4;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FD5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r23,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, r23.u32);
loc_824FD5F4:
	// lwz r4,1388(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fd618
	if (cr6.eq) goto loc_824FD618;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FD614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r23,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, r23.u32);
loc_824FD618:
	// lwz r4,1396(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1396);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fd63c
	if (cr6.eq) goto loc_824FD63C;
	// lwz r3,32268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32268);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FD638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r23,1396(r31)
	PPC_STORE_U32(r31.u32 + 1396, r23.u32);
loc_824FD63C:
	// addi r3,r31,1400
	ctx.r3.s64 = r31.s64 + 1400;
	// bl 0x824fb948
	ctx.lr = 0x824FD644;
	sub_824FB948(ctx, base);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656bf0
	ctx.lr = 0x824FD650;
	sub_82656BF0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fd664
	if (cr6.eq) goto loc_824FD664;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824fb6a0
	ctx.lr = 0x824FD664;
	sub_824FB6A0(ctx, base);
loc_824FD664:
	// stw r23,1436(r31)
	PPC_STORE_U32(r31.u32 + 1436, r23.u32);
	// b 0x824fd560
	goto loc_824FD560;
}

__attribute__((alias("__imp__sub_824FD66C"))) PPC_WEAK_FUNC(sub_824FD66C);
PPC_FUNC_IMPL(__imp__sub_824FD66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD670"))) PPC_WEAK_FUNC(sub_824FD670);
PPC_FUNC_IMPL(__imp__sub_824FD670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FD688"))) PPC_WEAK_FUNC(sub_824FD688);
PPC_FUNC_IMPL(__imp__sub_824FD688) {
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
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fd6b4
	if (cr6.eq) goto loc_824FD6B4;
	// bl 0x8244a660
	ctx.lr = 0x824FD6AC;
	sub_8244A660(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_824FD6B4:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
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
}

__attribute__((alias("__imp__sub_824FD6D4"))) PPC_WEAK_FUNC(sub_824FD6D4);
PPC_FUNC_IMPL(__imp__sub_824FD6D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD6D8"))) PPC_WEAK_FUNC(sub_824FD6D8);
PPC_FUNC_IMPL(__imp__sub_824FD6D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824FD6E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,9
	ctx.r8.s64 = 9;
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
	// addi r27,r31,104
	r27.s64 = r31.s64 + 104;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824FD700:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824fd700
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824FD700;
	// addi r28,r31,144
	r28.s64 = r31.s64 + 144;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r8,8
	ctx.r8.s64 = 8;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824FD728:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bdnz 0x824fd728
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824FD728;
	// addi r30,r31,156
	r30.s64 = r31.s64 + 156;
	// addi r4,r11,44
	ctx.r4.s64 = r11.s64 + 44;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x824FD750;
	sub_823DA950(ctx, base);
	// li r7,16384
	ctx.r7.s64 = 16384;
	// li r29,0
	r29.s64 = 0;
	// stw r27,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r27.u32);
	// addi r11,r31,100
	r11.s64 = r31.s64 + 100;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r31,140
	ctx.r4.s64 = r31.s64 + 140;
	// stw r28,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r28.u32);
	// addi r5,r31,152
	ctx.r5.s64 = r31.s64 + 152;
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// addi r6,r31,172
	ctx.r6.s64 = r31.s64 + 172;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244a600
	ctx.lr = 0x824FD79C;
	sub_8244A600(ctx, base);
	// subf r6,r29,r3
	ctx.r6.s64 = ctx.r3.s64 - r29.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FD7B0"))) PPC_WEAK_FUNC(sub_824FD7B0);
PPC_FUNC_IMPL(__imp__sub_824FD7B0) {
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
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fd7ec
	if (cr6.eq) goto loc_824FD7EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd7f8
	if (cr6.eq) goto loc_824FD7F8;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x824fd7f8
	goto loc_824FD7F8;
loc_824FD7EC:
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
loc_824FD7F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fd834
	if (!cr6.eq) goto loc_824FD834;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd834
	if (cr6.eq) goto loc_824FD834;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82728348
	ctx.lr = 0x824FD81C;
	sub_82728348(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
loc_824FD834:
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

__attribute__((alias("__imp__sub_824FD848"))) PPC_WEAK_FUNC(sub_824FD848);
PPC_FUNC_IMPL(__imp__sub_824FD848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r9,r11,29916
	ctx.r9.s64 = r11.s64 + 29916;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r8,0
	ctx.r8.s64 = 0;
loc_824FD864:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fd8e4
	if (cr6.eq) goto loc_824FD8E4;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x824fd8a8
	if (!cr6.eq) goto loc_824FD8A8;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824fd8a0
	if (cr6.eq) goto loc_824FD8A0;
	// stw r8,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r8.u32);
	// b 0x824fd8d0
	goto loc_824FD8D0;
loc_824FD8A0:
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x824fd8d0
	goto loc_824FD8D0;
loc_824FD8A8:
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824fd8c8
	if (cr6.eq) goto loc_824FD8C8;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// b 0x824fd8d0
	goto loc_824FD8D0;
loc_824FD8C8:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_824FD8D0:
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_824FD8E4:
	// lbz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stb r9,16(r11)
	PPC_STORE_U8(r11.u32 + 16, ctx.r9.u8);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824fd864
	if (!cr6.eq) goto loc_824FD864;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FD908"))) PPC_WEAK_FUNC(sub_824FD908);
PPC_FUNC_IMPL(__imp__sub_824FD908) {
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
	// bl 0x824fd848
	ctx.lr = 0x824FD928;
	sub_824FD848(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fd940
	if (cr6.eq) goto loc_824FD940;
	// bl 0x82130588
	ctx.lr = 0x824FD93C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FD940:
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

__attribute__((alias("__imp__sub_824FD958"))) PPC_WEAK_FUNC(sub_824FD958);
PPC_FUNC_IMPL(__imp__sub_824FD958) {
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
	// addi r10,r11,29988
	ctx.r10.s64 = r11.s64 + 29988;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824fd848
	ctx.lr = 0x824FD984;
	sub_824FD848(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fd99c
	if (cr6.eq) goto loc_824FD99C;
	// bl 0x82130588
	ctx.lr = 0x824FD998;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FD99C:
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

__attribute__((alias("__imp__sub_824FD9B4"))) PPC_WEAK_FUNC(sub_824FD9B4);
PPC_FUNC_IMPL(__imp__sub_824FD9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FD9B8"))) PPC_WEAK_FUNC(sub_824FD9B8);
PPC_FUNC_IMPL(__imp__sub_824FD9B8) {
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
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fd9e4
	if (cr6.eq) goto loc_824FD9E4;
	// bl 0x8244a660
	ctx.lr = 0x824FD9DC;
	sub_8244A660(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_824FD9E4:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,-1
	r11.s64 = -1;
	// addi r9,r10,29988
	ctx.r9.s64 = ctx.r10.s64 + 29988;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// bl 0x824fd848
	ctx.lr = 0x824FDA04;
	sub_824FD848(ctx, base);
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

__attribute__((alias("__imp__sub_824FDA18"))) PPC_WEAK_FUNC(sub_824FDA18);
PPC_FUNC_IMPL(__imp__sub_824FDA18) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// beq cr6,0x824fda94
	if (cr6.eq) goto loc_824FDA94;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fda94
	if (cr6.eq) goto loc_824FDA94;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fda94
	if (cr6.eq) goto loc_824FDA94;
	// lhz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lhz r8,22(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 22);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lwz r7,24(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// beq cr6,0x824fda94
	if (cr6.eq) goto loc_824FDA94;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x824fda9c
	goto loc_824FDA9C;
loc_824FDA94:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
loc_824FDA9C:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x822990d8
	ctx.lr = 0x824FDAA4;
	sub_822990D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FDAB4"))) PPC_WEAK_FUNC(sub_824FDAB4);
PPC_FUNC_IMPL(__imp__sub_824FDAB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FDAB8"))) PPC_WEAK_FUNC(sub_824FDAB8);
PPC_FUNC_IMPL(__imp__sub_824FDAB8) {
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
	// beq cr6,0x824fdb14
	if (cr6.eq) goto loc_824FDB14;
	// bl 0x824fda18
	ctx.lr = 0x824FDADC;
	sub_824FDA18(ctx, base);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fdaf4
	if (cr6.eq) goto loc_824FDAF4;
	// bl 0x8244a660
	ctx.lr = 0x824FDAEC;
	sub_8244A660(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_824FDAF4:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
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
loc_824FDB14:
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fdb2c
	if (cr6.eq) goto loc_824FDB2C;
	// bl 0x8244a660
	ctx.lr = 0x824FDB24;
	sub_8244A660(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_824FDB2C:
	// li r11,-1
	r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// bl 0x824fda18
	ctx.lr = 0x824FDB40;
	sub_824FDA18(ctx, base);
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

__attribute__((alias("__imp__sub_824FDB54"))) PPC_WEAK_FUNC(sub_824FDB54);
PPC_FUNC_IMPL(__imp__sub_824FDB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FDB58"))) PPC_WEAK_FUNC(sub_824FDB58);
PPC_FUNC_IMPL(__imp__sub_824FDB58) {
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
	ctx.lr = 0x824FDB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r30,0
	r30.s64 = 0;
	// li r29,-1
	r29.s64 = -1;
	// addi r10,r11,29988
	ctx.r10.s64 = r11.s64 + 29988;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// bl 0x824e6400
	ctx.lr = 0x824FDBA4;
	sub_824E6400(ctx, base);
	// stw r29,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r29.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FDBB8"))) PPC_WEAK_FUNC(sub_824FDBB8);
PPC_FUNC_IMPL(__imp__sub_824FDBB8) {
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
	// li r11,-1
	r11.s64 = -1;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// blt cr6,0x824fdc14
	if (cr6.lt) goto loc_824FDC14;
	// bne cr6,0x824fdc1c
	if (!cr6.eq) goto loc_824FDC1C;
	// bl 0x824fd6d8
	ctx.lr = 0x824FDBE8;
	sub_824FD6D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fdc1c
	if (!cr6.eq) goto loc_824FDC1C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fdab8
	ctx.lr = 0x824FDC00;
	sub_824FDAB8(ctx, base);
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
loc_824FDC14:
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_824FDC1C:
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

__attribute__((alias("__imp__sub_824FDC30"))) PPC_WEAK_FUNC(sub_824FDC30);
PPC_FUNC_IMPL(__imp__sub_824FDC30) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824FDC58;
	sub_823DA950(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_824FDC88"))) PPC_WEAK_FUNC(sub_824FDC88);
PPC_FUNC_IMPL(__imp__sub_824FDC88) {
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
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x824fdcac
	if (cr6.eq) goto loc_824FDCAC;
	// bl 0x824fdbb8
	ctx.lr = 0x824FDCAC;
	sub_824FDBB8(ctx, base);
loc_824FDCAC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x824fdce4
	if (cr6.eq) goto loc_824FDCE4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x824fdce4
	if (!cr6.eq) goto loc_824FDCE4;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fdce4
	if (cr6.eq) goto loc_824FDCE4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824fdce4
	if (!cr6.eq) goto loc_824FDCE4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fdab8
	ctx.lr = 0x824FDCE4;
	sub_824FDAB8(ctx, base);
loc_824FDCE4:
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

__attribute__((alias("__imp__sub_824FDCF8"))) PPC_WEAK_FUNC(sub_824FDCF8);
PPC_FUNC_IMPL(__imp__sub_824FDCF8) {
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
	ctx.lr = 0x824FDD00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618670
	ctx.lr = 0x824FDD14;
	sub_82618670(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824FDD28;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fdd60
	if (cr6.eq) goto loc_824FDD60;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x824FDD50;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x824FDD5C;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_824FDD60:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fdd94
	if (cr6.eq) goto loc_824FDD94;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e6270
	ctx.lr = 0x824FDD74;
	sub_824E6270(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x82275660
	ctx.lr = 0x824FDD84;
	sub_82275660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fdd98
	if (!cr6.eq) goto loc_824FDD98;
loc_824FDD94:
	// li r11,0
	r11.s64 = 0;
loc_824FDD98:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824FDDA4"))) PPC_WEAK_FUNC(sub_824FDDA4);
PPC_FUNC_IMPL(__imp__sub_824FDDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FDDA8"))) PPC_WEAK_FUNC(sub_824FDDA8);
PPC_FUNC_IMPL(__imp__sub_824FDDA8) {
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
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82257568
	ctx.lr = 0x824FDDD0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fde18
	if (cr6.eq) goto loc_824FDE18;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822756d0
	ctx.lr = 0x824FDDEC;
	sub_822756D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fde18
	if (cr6.eq) goto loc_824FDE18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824e6330
	ctx.lr = 0x824FDE08;
	sub_824E6330(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824fde1c
	if (!cr6.eq) goto loc_824FDE1C;
loc_824FDE18:
	// li r11,0
	r11.s64 = 0;
loc_824FDE1C:
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

__attribute__((alias("__imp__sub_824FDE38"))) PPC_WEAK_FUNC(sub_824FDE38);
PPC_FUNC_IMPL(__imp__sub_824FDE38) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,30048
	ctx.r10.s64 = r11.s64 + 30048;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fde84
	if (cr6.eq) goto loc_824FDE84;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FDE80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
loc_824FDE84:
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fdea8
	if (cr6.eq) goto loc_824FDEA8;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FDEA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
loc_824FDEA8:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fdebc
	if (cr6.eq) goto loc_824FDEBC;
	// bl 0x8275cc90
	ctx.lr = 0x824FDEB8;
	sub_8275CC90(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
loc_824FDEBC:
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

__attribute__((alias("__imp__sub_824FDED4"))) PPC_WEAK_FUNC(sub_824FDED4);
PPC_FUNC_IMPL(__imp__sub_824FDED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FDED8"))) PPC_WEAK_FUNC(sub_824FDED8);
PPC_FUNC_IMPL(__imp__sub_824FDED8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r11,52(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 52);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r11,r3,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r3.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,52(r10)
	PPC_STORE_U8(ctx.r10.u32 + 52, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FDF00"))) PPC_WEAK_FUNC(sub_824FDF00);
PPC_FUNC_IMPL(__imp__sub_824FDF00) {
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
	ctx.lr = 0x824FDF08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FDF2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,136
	ctx.r4.s64 = 136;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824FDF54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// beq cr6,0x824fe048
	if (cr6.eq) goto loc_824FE048;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FDF74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,65534
	cr6.compare<uint32_t>(r30.u32, 65534, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// beq cr6,0x824fdf98
	if (cr6.eq) goto loc_824FDF98;
	// sth r30,8(r11)
	PPC_STORE_U16(r11.u32 + 8, r30.u16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_824FDF98:
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82457778
	ctx.lr = 0x824FDFBC;
	sub_82457778(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fe048
	if (!cr6.eq) goto loc_824FE048;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FDFE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// beq cr6,0x824fe048
	if (cr6.eq) goto loc_824FE048;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r31,12
	ctx.r5.s64 = r31.s64 + 12;
	// addi r4,r11,30068
	ctx.r4.s64 = r11.s64 + 30068;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824fb900
	ctx.lr = 0x824FE004;
	sub_824FB900(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x824FE00C;
	sub_82130000(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824501c8
	ctx.lr = 0x824FE024;
	sub_824501C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fe038
	if (cr6.eq) goto loc_824FE038;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x824fe03c
	if (!cr6.eq) goto loc_824FE03C;
loc_824FE038:
	// li r11,1
	r11.s64 = 1;
loc_824FE03C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824FE048:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824FE054"))) PPC_WEAK_FUNC(sub_824FE054);
PPC_FUNC_IMPL(__imp__sub_824FE054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FE058"))) PPC_WEAK_FUNC(sub_824FE058);
PPC_FUNC_IMPL(__imp__sub_824FE058) {
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
	ctx.lr = 0x824FE060;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824fe0e4
	if (cr6.eq) goto loc_824FE0E4;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
loc_824FE0A8:
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// blt cr6,0x824fe0a8
	if (cr6.lt) goto loc_824FE0A8;
loc_824FE0E4:
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
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
	ctx.lr = 0x824FE104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r3.u32);
	// beq cr6,0x824fe234
	if (cr6.eq) goto loc_824FE234;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
	// ble cr6,0x824fe180
	if (!cr6.gt) goto loc_824FE180;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
loc_824FE14C:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,65534
	cr6.compare<uint32_t>(ctx.r10.u32, 65534, xer);
	// beq cr6,0x824fe174
	if (cr6.eq) goto loc_824FE174;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r10.u16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
loc_824FE174:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x824fe14c
	if (!cr0.eq) goto loc_824FE14C;
loc_824FE180:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r31,r30,40
	r31.s64 = r30.s64 + 40;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82457778
	ctx.lr = 0x824FE1A8;
	sub_82457778(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fe234
	if (!cr6.eq) goto loc_824FE234;
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// beq cr6,0x824fe234
	if (cr6.eq) goto loc_824FE234;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r30,12
	ctx.r5.s64 = r30.s64 + 12;
	// addi r4,r11,30068
	ctx.r4.s64 = r11.s64 + 30068;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fb900
	ctx.lr = 0x824FE1F0;
	sub_824FB900(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x824FE1F8;
	sub_82130000(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824501c8
	ctx.lr = 0x824FE210;
	sub_824501C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fe224
	if (cr6.eq) goto loc_824FE224;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x824fe228
	if (!cr6.eq) goto loc_824FE228;
loc_824FE224:
	// li r11,1
	r11.s64 = 1;
loc_824FE228:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9240
	return;
loc_824FE234:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FE240"))) PPC_WEAK_FUNC(sub_824FE240);
PPC_FUNC_IMPL(__imp__sub_824FE240) {
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
	ctx.lr = 0x824FE248;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE26C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE27C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824fe2cc
	if (cr6.eq) goto loc_824FE2CC;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
loc_824FE290:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE2A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE2B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// blt cr6,0x824fe290
	if (cr6.lt) goto loc_824FE290;
loc_824FE2CC:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
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
	ctx.lr = 0x824FE2EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// beq cr6,0x824fe49c
	if (cr6.eq) goto loc_824FE49C;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r26,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r26.u32);
	// ble cr6,0x824fe368
	if (!cr6.gt) goto loc_824FE368;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
loc_824FE334:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,65534
	cr6.compare<uint32_t>(ctx.r10.u32, 65534, xer);
	// beq cr6,0x824fe35c
	if (cr6.eq) goto loc_824FE35C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r10.u16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
loc_824FE35C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x824fe334
	if (!cr0.eq) goto loc_824FE334;
loc_824FE368:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FE38C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// beq cr6,0x824fe49c
	if (cr6.eq) goto loc_824FE49C;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r28,r26
	r28.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824fe3dc
	if (!cr6.gt) goto loc_824FE3DC;
	// mr r29,r26
	r29.u64 = r26.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
loc_824FE3B0:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824FE3BC;
	sub_824F92F0(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// stdx r3,r11,r29
	PPC_STORE_U64(r11.u32 + r29.u32, ctx.r3.u64);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x824fe3b0
	if (cr6.lt) goto loc_824FE3B0;
loc_824FE3DC:
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82457698
	ctx.lr = 0x824FE404;
	sub_82457698(ctx, base);
	// cmplwi cr6,r3,122
	cr6.compare<uint32_t>(ctx.r3.u32, 122, xer);
	// bne cr6,0x824fe49c
	if (!cr6.eq) goto loc_824FE49C;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fe49c
	if (cr6.eq) goto loc_824FE49C;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// beq cr6,0x824fe49c
	if (cr6.eq) goto loc_824FE49C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r31,12
	ctx.r5.s64 = r31.s64 + 12;
	// addi r4,r11,30080
	ctx.r4.s64 = r11.s64 + 30080;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824fb900
	ctx.lr = 0x824FE454;
	sub_824FB900(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x824FE45C;
	sub_82130000(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r7,36(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82457698
	ctx.lr = 0x824FE480;
	sub_82457698(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fe494
	if (cr6.eq) goto loc_824FE494;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x824fe498
	if (!cr6.eq) goto loc_824FE498;
loc_824FE494:
	// li r11,1
	r11.s64 = 1;
loc_824FE498:
	// clrlwi r26,r11,24
	r26.u64 = r11.u32 & 0xFF;
loc_824FE49C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824FE4A8"))) PPC_WEAK_FUNC(sub_824FE4A8);
PPC_FUNC_IMPL(__imp__sub_824FE4A8) {
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
	ctx.lr = 0x824FE4B0;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r27,r31,48
	r27.s64 = r31.s64 + 48;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x824f9478
	ctx.lr = 0x824FE4D4;
	sub_824F9478(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824fe548
	if (cr6.eq) goto loc_824FE548;
	// addi r28,r1,160
	r28.s64 = ctx.r1.s64 + 160;
loc_824FE50C:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE520;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x824fe50c
	if (cr6.lt) goto loc_824FE50C;
loc_824FE548:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
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
	ctx.lr = 0x824FE568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// beq cr6,0x824fe6b4
	if (cr6.eq) goto loc_824FE6B4;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r25,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r25.u32);
	// ble cr6,0x824fe5e4
	if (!cr6.gt) goto loc_824FE5E4;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
loc_824FE5B0:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,65534
	cr6.compare<uint32_t>(ctx.r10.u32, 65534, xer);
	// beq cr6,0x824fe5d8
	if (cr6.eq) goto loc_824FE5D8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r7,r11
	PPC_STORE_U16(ctx.r7.u32 + r11.u32, ctx.r10.u16);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
loc_824FE5D8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x824fe5b0
	if (!cr0.eq) goto loc_824FE5B0;
loc_824FE5E4:
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
	// bl 0x824f92f0
	ctx.lr = 0x824FE608;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// bl 0x824577d8
	ctx.lr = 0x824FE628;
	sub_824577D8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824fe6b4
	if (!cr6.eq) goto loc_824FE6B4;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// beq cr6,0x824fe6b4
	if (cr6.eq) goto loc_824FE6B4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r5,r31,12
	ctx.r5.s64 = r31.s64 + 12;
	// addi r4,r11,30068
	ctx.r4.s64 = r11.s64 + 30068;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824fb900
	ctx.lr = 0x824FE670;
	sub_824FB900(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130000
	ctx.lr = 0x824FE678;
	sub_82130000(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824501c8
	ctx.lr = 0x824FE690;
	sub_824501C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824fe6a4
	if (cr6.eq) goto loc_824FE6A4;
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x824fe6a8
	if (!cr6.eq) goto loc_824FE6A8;
loc_824FE6A4:
	// li r11,1
	r11.s64 = 1;
loc_824FE6A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d923c
	return;
loc_824FE6B4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824FE6C0"))) PPC_WEAK_FUNC(sub_824FE6C0);
PPC_FUNC_IMPL(__imp__sub_824FE6C0) {
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
	// bl 0x824fde38
	ctx.lr = 0x824FE6E0;
	sub_824FDE38(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824fe6f8
	if (cr6.eq) goto loc_824FE6F8;
	// bl 0x82130588
	ctx.lr = 0x824FE6F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FE6F8:
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

__attribute__((alias("__imp__sub_824FE710"))) PPC_WEAK_FUNC(sub_824FE710);
PPC_FUNC_IMPL(__imp__sub_824FE710) {
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
	// addi r10,r11,30056
	ctx.r10.s64 = r11.s64 + 30056;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824fde38
	ctx.lr = 0x824FE73C;
	sub_824FDE38(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fe754
	if (cr6.eq) goto loc_824FE754;
	// bl 0x82130588
	ctx.lr = 0x824FE750;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FE754:
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

__attribute__((alias("__imp__sub_824FE76C"))) PPC_WEAK_FUNC(sub_824FE76C);
PPC_FUNC_IMPL(__imp__sub_824FE76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FE770"))) PPC_WEAK_FUNC(sub_824FE770);
PPC_FUNC_IMPL(__imp__sub_824FE770) {
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
	// addi r10,r11,30064
	ctx.r10.s64 = r11.s64 + 30064;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824fde38
	ctx.lr = 0x824FE79C;
	sub_824FDE38(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fe7b4
	if (cr6.eq) goto loc_824FE7B4;
	// bl 0x82130588
	ctx.lr = 0x824FE7B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FE7B4:
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

__attribute__((alias("__imp__sub_824FE7CC"))) PPC_WEAK_FUNC(sub_824FE7CC);
PPC_FUNC_IMPL(__imp__sub_824FE7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FE7D0"))) PPC_WEAK_FUNC(sub_824FE7D0);
PPC_FUNC_IMPL(__imp__sub_824FE7D0) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,30108
	ctx.r10.s64 = r11.s64 + 30108;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fe810
	if (cr6.eq) goto loc_824FE810;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824FE810:
	// lwz r4,56(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fe830
	if (cr6.eq) goto loc_824FE830;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE830;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824FE830:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,30064
	ctx.r10.s64 = r11.s64 + 30064;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824fde38
	ctx.lr = 0x824FE844;
	sub_824FDE38(ctx, base);
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

__attribute__((alias("__imp__sub_824FE858"))) PPC_WEAK_FUNC(sub_824FE858);
PPC_FUNC_IMPL(__imp__sub_824FE858) {
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
	ctx.lr = 0x824FE860;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824fe884
	if (!cr6.eq) goto loc_824FE884;
	// bl 0x824fbb68
	ctx.lr = 0x824FE880;
	sub_824FBB68(ctx, base);
	// stw r29,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r29.u32);
loc_824FE884:
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824fe8a8
	if (cr6.eq) goto loc_824FE8A8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FE8A0;
	sub_821CE0A0(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
loc_824FE8A8:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 32268);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FE8C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824FE8E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824FE8E8"))) PPC_WEAK_FUNC(sub_824FE8E8);
PPC_FUNC_IMPL(__imp__sub_824FE8E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r15{};
	PPCRegister r18{};
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
	ctx.lr = 0x824FE8F0;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE91C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r20,0
	r20.s64 = 0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// mr r31,r20
	r31.u64 = r20.u64;
	// beq cr6,0x824fe970
	if (cr6.eq) goto loc_824FE970;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
loc_824FE934:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824FE95C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// blt cr6,0x824fe934
	if (cr6.lt) goto loc_824FE934;
loc_824FE970:
	// lwz r11,8(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// mr r24,r20
	r24.u64 = r20.u64;
	// mr r22,r20
	r22.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824feb38
	if (!cr6.gt) goto loc_824FEB38;
	// mr r23,r20
	r23.u64 = r20.u64;
loc_824FE988:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// bge cr6,0x824feb38
	if (!cr6.lt) goto loc_824FEB38;
	// lwz r11,12(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 12);
	// add r28,r11,r23
	r28.u64 = r11.u64 + r23.u64;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824feb24
	if (cr6.eq) goto loc_824FEB24;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824FE9C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r10,r28,24
	ctx.r10.s64 = r28.s64 + 24;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r8,15
	ctx.r8.s64 = 15;
loc_824FE9D0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fea60
	if (cr6.eq) goto loc_824FEA60;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fea44
	if (cr6.eq) goto loc_824FEA44;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fea4c
	if (cr6.eq) goto loc_824FEA4C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fea54
	if (cr6.eq) goto loc_824FEA54;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824fea5c
	if (cr6.eq) goto loc_824FEA5C;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addic. r8,r8,-5
	xer.ca = ctx.r8.u32 > 4;
	ctx.r8.s64 = ctx.r8.s64 + -5;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// bgt 0x824fe9d0
	if (cr0.gt) goto loc_824FE9D0;
	// b 0x824fea60
	goto loc_824FEA60;
loc_824FEA44:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824fea60
	goto loc_824FEA60;
loc_824FEA4C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x824fea60
	goto loc_824FEA60;
loc_824FEA54:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x824fea60
	goto loc_824FEA60;
loc_824FEA5C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_824FEA60:
	// stb r20,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r20.u8);
	// addi r3,r27,24
	ctx.r3.s64 = r27.s64 + 24;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// stw r11,16(r27)
	PPC_STORE_U32(r27.u32 + 16, r11.u32);
	// ld r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// bl 0x824f92a0
	ctx.lr = 0x824FEA78;
	sub_824F92A0(ctx, base);
	// mr r31,r20
	r31.u64 = r20.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x824feb20
	if (!cr6.gt) goto loc_824FEB20;
	// mr r30,r20
	r30.u64 = r20.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
loc_824FEA8C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,65534
	cr6.compare<uint32_t>(r11.u32, 65534, xer);
	// bne cr6,0x824feaa0
	if (!cr6.eq) goto loc_824FEAA0;
	// addi r5,r28,16
	ctx.r5.s64 = r28.s64 + 16;
	// b 0x824feaf8
	goto loc_824FEAF8;
loc_824FEAA0:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// lbz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// cmplwi cr6,r10,5
	cr6.compare<uint32_t>(ctx.r10.u32, 5, xer);
	// bgt cr6,0x824feb10
	if (cr6.gt) goto loc_824FEB10;
	// lis r12,-32176
	r12.s64 = -2108686336;
	// addi r12,r12,-5424
	r12.s64 = r12.s64 + -5424;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824FEAE8;
	case 1:
		goto loc_824FEAE8;
	case 2:
		goto loc_824FEAF4;
	case 3:
		goto loc_824FEAF4;
	case 4:
		goto loc_824FEB10;
	case 5:
		goto loc_824FEAE8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-5400(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5400);
	// lwz r18,-5400(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5400);
	// lwz r18,-5388(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5388);
	// lwz r18,-5388(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5388);
	// lwz r18,-5360(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5360);
	// lwz r18,-5400(r15)
	r18.u64 = PPC_LOAD_U32(r15.u32 + -5400);
loc_824FEAE8:
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// b 0x824feafc
	goto loc_824FEAFC;
loc_824FEAF4:
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
loc_824FEAF8:
	// li r6,8
	ctx.r6.s64 = 8;
loc_824FEAFC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824feb10
	if (cr6.eq) goto loc_824FEB10;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,40(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// bl 0x824e9530
	ctx.lr = 0x824FEB10;
	sub_824E9530(ctx, base);
loc_824FEB10:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r31,r25
	cr6.compare<int32_t>(r31.s32, r25.s32, xer);
	// blt cr6,0x824fea8c
	if (cr6.lt) goto loc_824FEA8C;
loc_824FEB20:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_824FEB24:
	// lwz r11,8(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// addi r23,r23,48
	r23.s64 = r23.s64 + 48;
	// cmplw cr6,r22,r11
	cr6.compare<uint32_t>(r22.u32, r11.u32, xer);
	// blt cr6,0x824fe988
	if (cr6.lt) goto loc_824FE988;
loc_824FEB38:
	// stw r24,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r24.u32);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824FEB44"))) PPC_WEAK_FUNC(sub_824FEB44);
PPC_FUNC_IMPL(__imp__sub_824FEB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824FEB48"))) PPC_WEAK_FUNC(sub_824FEB48);
PPC_FUNC_IMPL(__imp__sub_824FEB48) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x824f9478
	ctx.lr = 0x824FEB6C;
	sub_824F9478(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824feb88
	if (!cr6.eq) goto loc_824FEB88;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824fe8e8
	ctx.lr = 0x824FEB88;
	sub_824FE8E8(ctx, base);
loc_824FEB88:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824FEBA0"))) PPC_WEAK_FUNC(sub_824FEBA0);
PPC_FUNC_IMPL(__imp__sub_824FEBA0) {
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
	// bl 0x824fe7d0
	ctx.lr = 0x824FEBC0;
	sub_824FE7D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824febd8
	if (cr6.eq) goto loc_824FEBD8;
	// bl 0x82130588
	ctx.lr = 0x824FEBD4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824FEBD8:
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

__attribute__((alias("__imp__sub_824FEBF0"))) PPC_WEAK_FUNC(sub_824FEBF0);
PPC_FUNC_IMPL(__imp__sub_824FEBF0) {
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
	ctx.lr = 0x824FEBF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,52(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 52);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824fecc4
	if (cr6.eq) goto loc_824FECC4;
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824feca4
	if (cr6.eq) goto loc_824FECA4;
	// li r28,0
	r28.s64 = 0;
	// lis r27,-32115
	r27.s64 = -2104688640;
loc_824FEC24:
	// lwz r31,36(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824fec40
	if (!cr6.eq) goto loc_824FEC40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fbb68
	ctx.lr = 0x824FEC3C;
	sub_824FBB68(ctx, base);
	// stw r28,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r28.u32);
loc_824FEC40:
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824fec64
	if (cr6.eq) goto loc_824FEC64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824FEC5C;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
loc_824FEC64:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,32268(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 32268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824FEC80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824FEC98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,44(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x824fec24
	if (!cr6.eq) goto loc_824FEC24;
loc_824FECA4:
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824fecb8
	if (cr6.eq) goto loc_824FECB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824fe858
	ctx.lr = 0x824FECB8;
	sub_824FE858(ctx, base);
loc_824FECB8:
	// lbz r11,52(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 52);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,52(r30)
	PPC_STORE_U8(r30.u32 + 52, ctx.r10.u8);
loc_824FECC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824FECCC"))) PPC_WEAK_FUNC(sub_824FECCC);
PPC_FUNC_IMPL(__imp__sub_824FECCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

