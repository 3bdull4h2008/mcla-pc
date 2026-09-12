#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826FEE8C"))) PPC_WEAK_FUNC(sub_826FEE8C);
PPC_FUNC_IMPL(__imp__sub_826FEE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FEE90"))) PPC_WEAK_FUNC(sub_826FEE90);
PPC_FUNC_IMPL(__imp__sub_826FEE90) {
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
	// addi r10,r11,20604
	ctx.r10.s64 = r11.s64 + 20604;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,202(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 202);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826feec8
	if (cr6.eq) goto loc_826FEEC8;
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// bl 0x82130588
	ctx.lr = 0x826FEEC8;
	sub_82130588(ctx, base);
loc_826FEEC8:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// bl 0x82130588
	ctx.lr = 0x826FEED4;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82130588
	ctx.lr = 0x826FEEE4;
	sub_82130588(ctx, base);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f49d8
	ctx.lr = 0x826FEEF0;
	sub_821F49D8(ctx, base);
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

__attribute__((alias("__imp__sub_826FEF08"))) PPC_WEAK_FUNC(sub_826FEF08);
PPC_FUNC_IMPL(__imp__sub_826FEF08) {
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
	ctx.lr = 0x826FEF10;
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
	ctx.lr = 0x826FEF24;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r3,160
	ctx.r3.s64 = 160;
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stb r28,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r28.u8);
	// bl 0x82130528
	ctx.lr = 0x826FEF44;
	sub_82130528(ctx, base);
	// li r11,20
	r11.s64 = 20;
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
	ctx.lr = 0x826FEF60;
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
	ctx.lr = 0x826FEF74;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,20960
	ctx.r3.s64 = ctx.r8.s64 + 20960;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FEF90;
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
	ctx.lr = 0x826FEFA4;
	sub_824787B0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,20944
	ctx.r3.s64 = ctx.r6.s64 + 20944;
	// stw r27,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r27.u32);
	// stw r28,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r28.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FEFC0;
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
	ctx.lr = 0x826FEFD4;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,2
	r11.s64 = 2;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,20936
	ctx.r3.s64 = ctx.r10.s64 + 20936;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FEFF4;
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
	ctx.lr = 0x826FF008;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,20916
	ctx.r3.s64 = ctx.r7.s64 + 20916;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF028;
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
	ctx.lr = 0x826FF03C;
	sub_824787B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,20896
	ctx.r3.s64 = ctx.r3.s64 + 20896;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF05C;
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
	ctx.lr = 0x826FF070;
	sub_824787B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,20872
	ctx.r3.s64 = ctx.r9.s64 + 20872;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF090;
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
	ctx.lr = 0x826FF0A4;
	sub_824787B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,6
	ctx.r7.s64 = 6;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,20844
	ctx.r3.s64 = ctx.r6.s64 + 20844;
	// stw r27,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF0C4;
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
	ctx.lr = 0x826FF0D8;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,8
	r11.s64 = 8;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,20820
	ctx.r3.s64 = ctx.r10.s64 + 20820;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF0F8;
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
	ctx.lr = 0x826FF10C;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,7
	ctx.r8.s64 = 7;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,20804
	ctx.r3.s64 = ctx.r7.s64 + 20804;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF12C;
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
	ctx.lr = 0x826FF140;
	sub_824787B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,9
	ctx.r5.s64 = 9;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,20788
	ctx.r3.s64 = ctx.r3.s64 + 20788;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF160;
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
	ctx.lr = 0x826FF174;
	sub_824787B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,10
	ctx.r10.s64 = 10;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,20776
	ctx.r3.s64 = ctx.r9.s64 + 20776;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF194;
	sub_821C9790(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826FF1A8;
	sub_824787B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,11
	ctx.r7.s64 = 11;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,20764
	ctx.r3.s64 = ctx.r6.s64 + 20764;
	// stw r27,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF1C8;
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
	ctx.lr = 0x826FF1DC;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,12
	r11.s64 = 12;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,20744
	ctx.r3.s64 = ctx.r10.s64 + 20744;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF1FC;
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
	ctx.lr = 0x826FF210;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,13
	ctx.r8.s64 = 13;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,20728
	ctx.r3.s64 = ctx.r7.s64 + 20728;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF230;
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
	ctx.lr = 0x826FF244;
	sub_824787B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,14
	ctx.r5.s64 = 14;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,20720
	ctx.r3.s64 = ctx.r3.s64 + 20720;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF264;
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
	ctx.lr = 0x826FF278;
	sub_824787B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,15
	ctx.r10.s64 = 15;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,20708
	ctx.r3.s64 = ctx.r9.s64 + 20708;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF298;
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
	ctx.lr = 0x826FF2AC;
	sub_824787B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,20688
	ctx.r3.s64 = ctx.r6.s64 + 20688;
	// stw r27,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF2CC;
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
	ctx.lr = 0x826FF2E0;
	sub_824787B0(ctx, base);
	// li r5,17
	ctx.r5.s64 = 17;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,20672
	ctx.r3.s64 = r11.s64 + 20672;
	// bl 0x821c9790
	ctx.lr = 0x826FF2FC;
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
	ctx.lr = 0x826FF310;
	sub_824787B0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,18
	ctx.r9.s64 = 18;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,20652
	ctx.r3.s64 = ctx.r8.s64 + 20652;
	// stw r27,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r27.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x826FF330;
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
	ctx.lr = 0x826FF344;
	sub_824787B0(ctx, base);
	// li r7,19
	ctx.r7.s64 = 19;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// lbz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826ff380
	if (!cr6.eq) goto loc_826FF380;
	// lhz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826ff37c
	if (cr6.eq) goto loc_826FF37C;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x826FF37C;
	sub_823DCF08(ctx, base);
loc_826FF37C:
	// stb r28,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r28.u8);
loc_826FF380:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826FF388"))) PPC_WEAK_FUNC(sub_826FF388);
PPC_FUNC_IMPL(__imp__sub_826FF388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r15{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826FF390;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x826FF3B0;
	sub_821C9790(ctx, base);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r27,0
	r27.s64 = 0;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826ff3e8
	if (cr6.eq) goto loc_826FF3E8;
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
	ctx.lr = 0x826FF3DC;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826ff3ec
	if (!cr6.eq) goto loc_826FF3EC;
loc_826FF3E8:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826FF3EC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x826ff544
	if (cr6.gt) goto loc_826FF544;
	// lis r12,-32144
	r12.s64 = -2106589184;
	// addi r12,r12,-3056
	r12.s64 = r12.s64 + -3056;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826FF460;
	case 1:
		goto loc_826FF4A8;
	case 2:
		goto loc_826FF550;
	case 3:
		goto loc_826FF5C0;
	case 4:
		goto loc_826FF630;
	case 5:
		goto loc_826FF644;
	case 6:
		goto loc_826FF660;
	case 7:
		goto loc_826FF67C;
	case 8:
		goto loc_826FF698;
	case 9:
		goto loc_826FF6B4;
	case 10:
		goto loc_826FF6D0;
	case 11:
		goto loc_826FF6EC;
	case 12:
		goto loc_826FF700;
	case 13:
		goto loc_826FF714;
	case 14:
		goto loc_826FF728;
	case 15:
		goto loc_826FF73C;
	case 16:
		goto loc_826FF790;
	case 17:
		goto loc_826FF7E4;
	case 18:
		goto loc_826FF838;
	case 19:
		goto loc_826FF854;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-2976(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2976);
	// lwz r19,-2904(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2904);
	// lwz r19,-2736(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2736);
	// lwz r19,-2624(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2624);
	// lwz r19,-2512(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2512);
	// lwz r19,-2492(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2492);
	// lwz r19,-2464(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2464);
	// lwz r19,-2436(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2436);
	// lwz r19,-2408(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2408);
	// lwz r19,-2380(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2380);
	// lwz r19,-2352(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2352);
	// lwz r19,-2324(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2324);
	// lwz r19,-2304(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2304);
	// lwz r19,-2284(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2284);
	// lwz r19,-2264(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2264);
	// lwz r19,-2244(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2244);
	// lwz r19,-2160(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2160);
	// lwz r19,-2076(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -2076);
	// lwz r19,-1992(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -1992);
	// lwz r19,-1964(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -1964);
loc_826FF460:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-9408
	ctx.r5.s64 = r11.s64 + -9408;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FF474;
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
loc_826FF488:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826ff488
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826FF488;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF4A8:
	// lbz r11,268(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ff540
	if (!cr6.eq) goto loc_826FF540;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FF4C4;
	sub_82137A08(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lwz r9,408(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// addi r10,r11,-6656
	ctx.r10.s64 = r11.s64 + -6656;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
	// lwz r8,236(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x826ff50c
	if (!cr6.eq) goto loc_826FF50C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,21068
	ctx.r3.s64 = r11.s64 + 21068;
	// bl 0x821c9790
	ctx.lr = 0x826FF4F4;
	sub_821C9790(ctx, base);
	// stw r3,436(r30)
	PPC_STORE_U32(r30.u32 + 436, ctx.r3.u32);
	// lwz r10,244(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF50C:
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff540
	if (!cr6.eq) goto loc_826FF540;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,21040
	ctx.r3.s64 = r11.s64 + 21040;
	// bl 0x821c9790
	ctx.lr = 0x826FF528;
	sub_821C9790(ctx, base);
	// stw r3,436(r30)
	PPC_STORE_U32(r30.u32 + 436, ctx.r3.u32);
	// lwz r10,248(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF540:
	// stb r27,268(r31)
	PPC_STORE_U8(r31.u32 + 268, r27.u8);
loc_826FF544:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF550:
	// lbz r11,268(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ff540
	if (!cr6.eq) goto loc_826FF540;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FF56C;
	sub_82137A08(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lwz r9,408(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// addi r10,r11,-9688
	ctx.r10.s64 = r11.s64 + -9688;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
	// lwz r8,236(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x826ff5a0
	if (!cr6.eq) goto loc_826FF5A0;
	// lwz r11,244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,408(r30)
	PPC_STORE_U32(r30.u32 + 408, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF5A0:
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff540
	if (!cr6.eq) goto loc_826FF540;
	// lwz r11,248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,408(r30)
	PPC_STORE_U32(r30.u32 + 408, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF5C0:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff5fc
	if (!cr6.eq) goto loc_826FF5FC;
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r10,21032
	ctx.r5.s64 = ctx.r10.s64 + 21032;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x826FF5F0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF5FC:
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff544
	if (!cr6.eq) goto loc_826FF544;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r6,r11,20572
	ctx.r6.s64 = r11.s64 + 20572;
	// addi r5,r10,21032
	ctx.r5.s64 = ctx.r10.s64 + 21032;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FF624;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF630:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdef8
	ctx.lr = 0x826FF63C;
	sub_826FDEF8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF644:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20896
	ctx.r5.s64 = r11.s64 + 20896;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdc60
	ctx.lr = 0x826FF658;
	sub_826FDC60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF660:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20872
	ctx.r5.s64 = r11.s64 + 20872;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdc60
	ctx.lr = 0x826FF674;
	sub_826FDC60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF67C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20820
	ctx.r5.s64 = r11.s64 + 20820;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdc60
	ctx.lr = 0x826FF690;
	sub_826FDC60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF698:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20844
	ctx.r5.s64 = r11.s64 + 20844;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdc60
	ctx.lr = 0x826FF6AC;
	sub_826FDC60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF6B4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20804
	ctx.r5.s64 = r11.s64 + 20804;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdd78
	ctx.lr = 0x826FF6C8;
	sub_826FDD78(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF6D0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20788
	ctx.r5.s64 = r11.s64 + 20788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdd78
	ctx.lr = 0x826FF6E4;
	sub_826FDD78(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF6EC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fddd8
	ctx.lr = 0x826FF6F8;
	sub_826FDDD8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF700:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fe978
	ctx.lr = 0x826FF70C;
	sub_826FE978(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF714:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdf58
	ctx.lr = 0x826FF720;
	sub_826FDF58(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF728:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fdfb8
	ctx.lr = 0x826FF734;
	sub_826FDFB8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF73C:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff778
	if (!cr6.eq) goto loc_826FF778;
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r5,r10,21020
	ctx.r5.s64 = ctx.r10.s64 + 21020;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x826FF76C;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF778:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20720
	ctx.r5.s64 = r11.s64 + 20720;
	// bl 0x82137a08
	ctx.lr = 0x826FF784;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF790:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff7cc
	if (!cr6.eq) goto loc_826FF7CC;
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r5,r10,21004
	ctx.r5.s64 = ctx.r10.s64 + 21004;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x826FF7C0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF7CC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20708
	ctx.r5.s64 = r11.s64 + 20708;
	// bl 0x82137a08
	ctx.lr = 0x826FF7D8;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF7E4:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826ff820
	if (!cr6.eq) goto loc_826FF820;
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r5,r10,20980
	ctx.r5.s64 = ctx.r10.s64 + 20980;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x826FF814;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF820:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20688
	ctx.r5.s64 = r11.s64 + 20688;
	// bl 0x82137a08
	ctx.lr = 0x826FF82C;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF838:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20972
	ctx.r5.s64 = r11.s64 + 20972;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fe0f8
	ctx.lr = 0x826FF84C;
	sub_826FE0F8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826FF854:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20652
	ctx.r5.s64 = r11.s64 + 20652;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fe0f8
	ctx.lr = 0x826FF868;
	sub_826FE0F8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826FF870"))) PPC_WEAK_FUNC(sub_826FF870);
PPC_FUNC_IMPL(__imp__sub_826FF870) {
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
	// bl 0x826fee90
	ctx.lr = 0x826FF890;
	sub_826FEE90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ff8a8
	if (cr6.eq) goto loc_826FF8A8;
	// bl 0x82130588
	ctx.lr = 0x826FF8A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FF8A8:
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

__attribute__((alias("__imp__sub_826FF8C0"))) PPC_WEAK_FUNC(sub_826FF8C0);
PPC_FUNC_IMPL(__imp__sub_826FF8C0) {
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
	// li r3,272
	ctx.r3.s64 = 272;
	// bl 0x82130528
	ctx.lr = 0x826FF8D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ff8f8
	if (cr6.eq) goto loc_826FF8F8;
	// bl 0x826fed90
	ctx.lr = 0x826FF8E0;
	sub_826FED90(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-24400(r11)
	PPC_STORE_U32(r11.u32 + -24400, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826FF8F8:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-24400(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24400, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FF914"))) PPC_WEAK_FUNC(sub_826FF914);
PPC_FUNC_IMPL(__imp__sub_826FF914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FF918"))) PPC_WEAK_FUNC(sub_826FF918);
PPC_FUNC_IMPL(__imp__sub_826FF918) {
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
	ctx.lr = 0x826FF920;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r4,r10,-25336
	ctx.r4.s64 = ctx.r10.s64 + -25336;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821ca540
	ctx.lr = 0x826FF940;
	sub_821CA540(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ff978
	if (!cr6.eq) goto loc_826FF978;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x826FF958;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ff970
	if (cr6.eq) goto loc_826FF970;
	// bl 0x821c0580
	ctx.lr = 0x826FF968;
	sub_821C0580(ctx, base);
	// stw r30,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r30.u32);
	// b 0x826ff978
	goto loc_826FF978;
loc_826FF970:
	// li r11,0
	r11.s64 = 0;
	// stw r11,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r11.u32);
loc_826FF978:
	// bl 0x821c4210
	ctx.lr = 0x826FF97C;
	sub_821C4210(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// addi r10,r11,30500
	ctx.r10.s64 = r11.s64 + 30500;
	// lwz r11,30500(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 30500);
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x821c05e8
	ctx.lr = 0x826FF9A0;
	sub_821C05E8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r5,r9,5276
	ctx.r5.s64 = ctx.r9.s64 + 5276;
	// addi r4,r8,21100
	ctx.r4.s64 = ctx.r8.s64 + 21100;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x826FF9C0;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x826ffb1c
	if (cr6.eq) goto loc_826FFB1C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821c00e8
	ctx.lr = 0x826FF9D8;
	sub_821C00E8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r29,28(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826ffae0
	if (cr6.eq) goto loc_826FFAE0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r28,95
	r28.s64 = 95;
	// addi r27,r11,-13276
	r27.s64 = r11.s64 + -13276;
loc_826FF9F8:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c75d0
	ctx.lr = 0x826FFA04;
	sub_821C75D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ffad4
	if (cr6.eq) goto loc_826FFAD4;
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x826FFA1C;
	sub_82137A08(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_826FFA28:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826ffa28
	if (!cr6.eq) goto loc_826FFA28;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bge cr6,0x826ffa84
	if (!cr6.lt) goto loc_826FFA84;
loc_826FFA58:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bne cr6,0x826ffa78
	if (!cr6.eq) goto loc_826FFA78;
	// subf r5,r30,r31
	ctx.r5.s64 = r31.s64 - r30.s64;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x826FFA74;
	sub_823DA950(ctx, base);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_826FFA78:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// blt cr6,0x826ffa58
	if (cr6.lt) goto loc_826FFA58;
loc_826FFA84:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ffab4
	if (cr6.eq) goto loc_826FFAB4;
loc_826FFA94:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// bne cr6,0x826ffaa4
	if (!cr6.eq) goto loc_826FFAA4;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
loc_826FFAA4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ffa94
	if (!cr6.eq) goto loc_826FFA94;
loc_826FFAB4:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9790
	ctx.lr = 0x826FFAC0;
	sub_821C9790(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r23,196
	ctx.r3.s64 = r23.s64 + 196;
	// bl 0x8262e420
	ctx.lr = 0x826FFAD0;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
loc_826FFAD4:
	// lwz r29,24(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826ff9f8
	if (!cr6.eq) goto loc_826FF9F8;
loc_826FFAE0:
	// lhz r4,200(r23)
	ctx.r4.u64 = PPC_LOAD_U16(r23.u32 + 200);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x826ffaf0
	if (!cr6.lt) goto loc_826FFAF0;
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
loc_826FFAF0:
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lwz r3,196(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 196);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,-10144
	ctx.r6.s64 = r11.s64 + -10144;
	// bl 0x823dcf08
	ctx.lr = 0x826FFB04;
	sub_823DCF08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x826FFB0C;
	sub_821BE610(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c5c70
	ctx.lr = 0x826FFB14;
	sub_821C5C70(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x826FFB1C;
	sub_82130588(ctx, base);
loc_826FFB1C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826FFB24;
	sub_821C9A90(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826FFB2C"))) PPC_WEAK_FUNC(sub_826FFB2C);
PPC_FUNC_IMPL(__imp__sub_826FFB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FFB30"))) PPC_WEAK_FUNC(sub_826FFB30);
PPC_FUNC_IMPL(__imp__sub_826FFB30) {
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
	ctx.lr = 0x826FFB38;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r10,21184
	ctx.r8.s64 = ctx.r10.s64 + 21184;
	// addi r7,r9,21168
	ctx.r7.s64 = ctx.r9.s64 + 21168;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FFB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FFB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,32(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 32);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826ffd3c
	if (cr6.eq) goto loc_826FFD3C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r4,28(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// addi r31,r11,21152
	r31.s64 = r11.s64 + 21152;
	// addi r3,r10,21132
	ctx.r3.s64 = ctx.r10.s64 + 21132;
	// addi r28,r9,-9660
	r28.s64 = ctx.r9.s64 + -9660;
	// addi r27,r8,20572
	r27.s64 = ctx.r8.s64 + 20572;
	// addi r30,r7,21124
	r30.s64 = ctx.r7.s64 + 21124;
loc_826FFBC8:
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826FFBD4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826ffbf8
	if (cr6.eq) goto loc_826FFBF8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ffbd4
	if (cr6.eq) goto loc_826FFBD4;
loc_826FFBF8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ffc08
	if (!cr6.eq) goto loc_826FFC08;
	// stw r4,232(r29)
	PPC_STORE_U32(r29.u32 + 232, ctx.r4.u32);
	// b 0x826ffd28
	goto loc_826FFD28;
loc_826FFC08:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826FFC10:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826ffc34
	if (cr6.eq) goto loc_826FFC34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ffc10
	if (cr6.eq) goto loc_826FFC10;
loc_826FFC34:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ffc44
	if (!cr6.eq) goto loc_826FFC44;
	// stw r4,236(r29)
	PPC_STORE_U32(r29.u32 + 236, ctx.r4.u32);
	// b 0x826ffd28
	goto loc_826FFD28;
loc_826FFC44:
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826FFC4C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826ffc70
	if (cr6.eq) goto loc_826FFC70;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ffc4c
	if (cr6.eq) goto loc_826FFC4C;
loc_826FFC70:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ffd28
	if (!cr6.eq) goto loc_826FFD28;
	// stw r4,240(r29)
	PPC_STORE_U32(r29.u32 + 240, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r11,12(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ffd28
	if (cr6.eq) goto loc_826FFD28;
	// li r6,0
	ctx.r6.s64 = 0;
loc_826FFC90:
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// add r7,r6,r11
	ctx.r7.u64 = ctx.r6.u64 + r11.u64;
	// lwzx r8,r6,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826FFCA4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r25,0(r10)
	r25.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r25,r9
	ctx.r9.s64 = ctx.r9.s64 - r25.s64;
	// beq cr6,0x826ffcc8
	if (cr6.eq) goto loc_826FFCC8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ffca4
	if (cr6.eq) goto loc_826FFCA4;
loc_826FFCC8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ffcd8
	if (!cr6.eq) goto loc_826FFCD8;
	// stw r7,244(r29)
	PPC_STORE_U32(r29.u32 + 244, ctx.r7.u32);
	// b 0x826ffd10
	goto loc_826FFD10;
loc_826FFCD8:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_826FFCE0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826ffd04
	if (cr6.eq) goto loc_826FFD04;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826ffce0
	if (cr6.eq) goto loc_826FFCE0;
loc_826FFD04:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ffd10
	if (!cr6.eq) goto loc_826FFD10;
	// stw r7,248(r29)
	PPC_STORE_U32(r29.u32 + 248, ctx.r7.u32);
loc_826FFD10:
	// lwz r11,240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 240);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,24
	ctx.r6.s64 = ctx.r6.s64 + 24;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// blt cr6,0x826ffc90
	if (cr6.lt) goto loc_826FFC90;
loc_826FFD28:
	// lhz r11,32(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r4,r4,20
	ctx.r4.s64 = ctx.r4.s64 + 20;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x826ffbc8
	if (cr6.lt) goto loc_826FFBC8;
loc_826FFD3C:
	// lwz r11,232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 232);
	// addi r30,r29,40
	r30.s64 = r29.s64 + 40;
	// lwz r3,40(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lhz r31,12(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x826FFD50;
	sub_82130588(ctx, base);
	// addi r10,r31,31
	ctx.r10.s64 = r31.s64 + 31;
	// mr r28,r31
	r28.u64 = r31.u64;
	// srawi r9,r10,5
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 5;
	// sth r28,46(r29)
	PPC_STORE_U16(r29.u32 + 46, r28.u16);
	// clrlwi r27,r9,16
	r27.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r27,44(r29)
	PPC_STORE_U16(r29.u32 + 44, r27.u16);
	// rlwinm r26,r27,2,14,29
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0x3FFFC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130528
	ctx.lr = 0x826FFD74;
	sub_82130528(ctx, base);
	// stw r3,40(r29)
	PPC_STORE_U32(r29.u32 + 40, ctx.r3.u32);
	// lhz r8,44(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r5,r8,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x826FFD88;
	sub_8244D150(ctx, base);
	// lwz r3,48(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// addi r30,r29,48
	r30.s64 = r29.s64 + 48;
	// bl 0x82130588
	ctx.lr = 0x826FFD94;
	sub_82130588(ctx, base);
	// sth r28,54(r29)
	PPC_STORE_U16(r29.u32 + 54, r28.u16);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// sth r27,52(r29)
	PPC_STORE_U16(r29.u32 + 52, r27.u16);
	// bl 0x82130528
	ctx.lr = 0x826FFDA4;
	sub_82130528(ctx, base);
	// stw r3,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r3.u32);
	// lhz r7,52(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 52);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r5,r7,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x826FFDB8;
	sub_8244D150(ctx, base);
	// addi r4,r31,-1
	ctx.r4.s64 = r31.s64 + -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826FFDC4;
	sub_82145020(ctx, base);
	// stw r3,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ff918
	ctx.lr = 0x826FFDD0;
	sub_826FF918(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826FFDD8"))) PPC_WEAK_FUNC(sub_826FFDD8);
PPC_FUNC_IMPL(__imp__sub_826FFDD8) {
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
	ctx.lr = 0x826FFDF4;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,21200
	ctx.r3.s64 = r11.s64 + 21200;
	// bl 0x821378b8
	ctx.lr = 0x826FFE04;
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
	ctx.lr = 0x826FFE30;
	sub_821F1138(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826ffe64
	if (!cr6.eq) goto loc_826FFE64;
	// bl 0x821d2aa0
	ctx.lr = 0x826FFE44;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826FFE4C;
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
loc_826FFE64:
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
	ctx.lr = 0x826FFE7C;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826FFE84;
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

__attribute__((alias("__imp__sub_826FFE9C"))) PPC_WEAK_FUNC(sub_826FFE9C);
PPC_FUNC_IMPL(__imp__sub_826FFE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FFEA0"))) PPC_WEAK_FUNC(sub_826FFEA0);
PPC_FUNC_IMPL(__imp__sub_826FFEA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826ffee4
	if (cr6.eq) goto loc_826FFEE4;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826ffee4
	if (cr6.eq) goto loc_826FFEE4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826ffed4
	if (cr6.lt) goto loc_826FFED4;
	// li r11,1
	r11.s64 = 1;
loc_826FFED4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826ffee8
	if (!cr6.eq) goto loc_826FFEE8;
loc_826FFEE4:
	// li r11,0
	r11.s64 = 0;
loc_826FFEE8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FFEF0"))) PPC_WEAK_FUNC(sub_826FFEF0);
PPC_FUNC_IMPL(__imp__sub_826FFEF0) {
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
	ctx.lr = 0x826FFEF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826fff94
	if (cr6.eq) goto loc_826FFF94;
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r31,r11,24152
	r31.s64 = r11.s64 + 24152;
	// addi r30,r10,24124
	r30.s64 = ctx.r10.s64 + 24124;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826FFF34;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fff94
	if (cr6.eq) goto loc_826FFF94;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x823dedd8
	ctx.lr = 0x826FFF58;
	sub_823DEDD8(ctx, base);
	// lhz r10,18(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 18);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bne cr6,0x826fff88
	if (!cr6.eq) goto loc_826FFF88;
	// li r11,0
	r11.s64 = 0;
loc_826FFF88:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826FFF94:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FFFA0"))) PPC_WEAK_FUNC(sub_826FFFA0);
PPC_FUNC_IMPL(__imp__sub_826FFFA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fffdc
	if (cr6.eq) goto loc_826FFFDC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fffdc
	if (cr6.eq) goto loc_826FFFDC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 580);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x826fffd4
	if (cr6.gt) goto loc_826FFFD4;
	// li r11,0
	r11.s64 = 0;
loc_826FFFD4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_826FFFDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FFFE4"))) PPC_WEAK_FUNC(sub_826FFFE4);
PPC_FUNC_IMPL(__imp__sub_826FFFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FFFE8"))) PPC_WEAK_FUNC(sub_826FFFE8);
PPC_FUNC_IMPL(__imp__sub_826FFFE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700054
	if (cr6.eq) goto loc_82700054;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82700054
	if (cr6.eq) goto loc_82700054;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// lwz r8,52(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// lfs f31,268(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	f31.f64 = double(temp.f32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8270002C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8270003c
	if (cr6.gt) goto loc_8270003C;
	// li r11,0
	r11.s64 = 0;
loc_8270003C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82700054:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270006C"))) PPC_WEAK_FUNC(sub_8270006C);
PPC_FUNC_IMPL(__imp__sub_8270006C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700070"))) PPC_WEAK_FUNC(sub_82700070);
PPC_FUNC_IMPL(__imp__sub_82700070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r4,1072(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1072, ctx.r4.u8);
	// stb r4,1073(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1073, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82700084"))) PPC_WEAK_FUNC(sub_82700084);
PPC_FUNC_IMPL(__imp__sub_82700084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700088"))) PPC_WEAK_FUNC(sub_82700088);
PPC_FUNC_IMPL(__imp__sub_82700088) {
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
	// bl 0x82387a18
	ctx.lr = 0x8270009C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827000f0
	if (!cr6.eq) goto loc_827000F0;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6732(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6732);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827000f0
	if (!cr6.eq) goto loc_827000F0;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827000f0
	if (cr6.eq) goto loc_827000F0;
	// bl 0x822a39c0
	ctx.lr = 0x827000CC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827000f0
	if (cr6.eq) goto loc_827000F0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x827000E0;
	sub_822A39C8(ctx, base);
	// bl 0x822a8628
	ctx.lr = 0x827000E4;
	sub_822A8628(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x827000f4
	if (!cr6.eq) goto loc_827000F4;
loc_827000F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827000F4:
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

__attribute__((alias("__imp__sub_82700108"))) PPC_WEAK_FUNC(sub_82700108);
PPC_FUNC_IMPL(__imp__sub_82700108) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,-12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700214
	if (cr6.eq) goto loc_82700214;
	// bl 0x826bca58
	ctx.lr = 0x82700130;
	sub_826BCA58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82700214
	if (!cr6.eq) goto loc_82700214;
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,21572
	r30.s64 = r11.s64 + 21572;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82700160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// bne cr6,0x82700194
	if (!cr6.eq) goto loc_82700194;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270018C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,103
	ctx.r4.s64 = 103;
	// b 0x827001e4
	goto loc_827001E4;
loc_82700194:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,21564
	r30.s64 = r11.s64 + 21564;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827001B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82700214
	if (!cr6.eq) goto loc_82700214;
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827001E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,104
	ctx.r4.s64 = 104;
loc_827001E4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r31,r9,16256
	r31.u64 = ctx.r9.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x827001FC;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82700214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82700214:
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

__attribute__((alias("__imp__sub_8270022C"))) PPC_WEAK_FUNC(sub_8270022C);
PPC_FUNC_IMPL(__imp__sub_8270022C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700230"))) PPC_WEAK_FUNC(sub_82700230);
PPC_FUNC_IMPL(__imp__sub_82700230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8270024c
	if (cr6.lt) goto loc_8270024C;
	// li r11,0
	r11.s64 = 0;
loc_8270024C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700280
	if (cr6.eq) goto loc_82700280;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82700280
	if (cr6.lt) goto loc_82700280;
	// lhz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82700280
	if (!cr6.lt) goto loc_82700280;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_82700280:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270028C"))) PPC_WEAK_FUNC(sub_8270028C);
PPC_FUNC_IMPL(__imp__sub_8270028C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700290"))) PPC_WEAK_FUNC(sub_82700290);
PPC_FUNC_IMPL(__imp__sub_82700290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f0,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x827002bc
	if (cr6.lt) goto loc_827002BC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,-5856(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x827002c0
	if (cr6.lt) goto loc_827002C0;
loc_827002BC:
	// li r11,0
	r11.s64 = 0;
loc_827002C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827002f4
	if (cr6.eq) goto loc_827002F4;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x827002f4
	if (cr6.lt) goto loc_827002F4;
	// lhz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x827002f4
	if (!cr6.lt) goto loc_827002F4;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_827002F4:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82700300"))) PPC_WEAK_FUNC(sub_82700300);
PPC_FUNC_IMPL(__imp__sub_82700300) {
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
	ctx.lr = 0x82700308;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270035c
	if (cr6.eq) goto loc_8270035C;
	// li r31,0
	r31.s64 = 0;
loc_82700324:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82700348
	if (cr6.eq) goto loc_82700348;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82700348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82700348:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82700324
	if (cr6.lt) goto loc_82700324;
loc_8270035C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82700364"))) PPC_WEAK_FUNC(sub_82700364);
PPC_FUNC_IMPL(__imp__sub_82700364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700368"))) PPC_WEAK_FUNC(sub_82700368);
PPC_FUNC_IMPL(__imp__sub_82700368) {
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
	ctx.lr = 0x82700370;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r29,r25,2,0,29
	r29.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82700390:
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827003c0
	if (cr6.eq) goto loc_827003C0;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82710598
	ctx.lr = 0x827003B0;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x827003e0
	if (cr6.eq) goto loc_827003E0;
loc_827003C0:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82700390
	if (cr6.lt) goto loc_82700390;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_827003E0:
	// add r11,r28,r25
	r11.u64 = r28.u64 + r25.u64;
	// lwz r10,44(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_827003F8"))) PPC_WEAK_FUNC(sub_827003F8);
PPC_FUNC_IMPL(__imp__sub_827003F8) {
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
	ctx.lr = 0x82700400;
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
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827004a0
	if (cr6.eq) goto loc_827004A0;
	// li r29,0
	r29.s64 = 0;
loc_82700420:
	// li r31,0
	r31.s64 = 0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_82700428:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270047c
	if (cr6.eq) goto loc_8270047C;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82710598
	ctx.lr = 0x82700448;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8270047c
	if (!cr6.eq) goto loc_8270047C;
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82700470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827004ac
	if (!cr6.eq) goto loc_827004AC;
loc_8270047C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82700428
	if (cr6.lt) goto loc_82700428;
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x82700420
	if (cr6.lt) goto loc_82700420;
loc_827004A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827004AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827004B8"))) PPC_WEAK_FUNC(sub_827004B8);
PPC_FUNC_IMPL(__imp__sub_827004B8) {
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
	ctx.lr = 0x827004C0;
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
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700560
	if (cr6.eq) goto loc_82700560;
	// li r29,0
	r29.s64 = 0;
loc_827004E0:
	// li r31,0
	r31.s64 = 0;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_827004E8:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lbz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270053c
	if (cr6.eq) goto loc_8270053C;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82710598
	ctx.lr = 0x82700508;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8270053c
	if (!cr6.eq) goto loc_8270053C;
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82700530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8270056c
	if (!cr6.eq) goto loc_8270056C;
loc_8270053C:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x827004e8
	if (cr6.lt) goto loc_827004E8;
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x827004e0
	if (cr6.lt) goto loc_827004E0;
loc_82700560:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8270056C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82700578"))) PPC_WEAK_FUNC(sub_82700578);
PPC_FUNC_IMPL(__imp__sub_82700578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r30,r1,112
	r30.s64 = ctx.r1.s64 + 112;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-23452(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23452);
	// sth r4,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r4.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v1,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,2048
	ctx.r7.s64 = 2048;
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stvx128 v2,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82574418
	ctx.lr = 0x8270061C;
	sub_82574418(ctx, base);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_82700640"))) PPC_WEAK_FUNC(sub_82700640);
PPC_FUNC_IMPL(__imp__sub_82700640) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82700648;
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700790
	if (cr6.eq) goto loc_82700790;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a8108
	ctx.lr = 0x82700678;
	sub_822A8108(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f31,48(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	f31.f64 = double(temp.f32);
	// ori r31,r8,16704
	r31.u64 = ctx.r8.u64 | 16704;
	// lfs f30,56(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 56);
	f30.f64 = double(temp.f32);
	// lfs f0,30712(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	f0.f64 = double(temp.f32);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lfs f29,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// stfs f29,100(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8224a2b8
	ctx.lr = 0x827006BC;
	sub_8224A2B8(ctx, base);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82700790
	if (cr6.eq) goto loc_82700790;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82244840
	ctx.lr = 0x827006E8;
	sub_82244840(ctx, base);
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700728
	if (cr6.eq) goto loc_82700728;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700728
	if (cr6.eq) goto loc_82700728;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,23960(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 23960);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82700728
	if (!cr6.lt) goto loc_82700728;
	// lfs f0,32(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// b 0x82700738
	goto loc_82700738;
loc_82700728:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a8148
	ctx.lr = 0x82700730;
	sub_822A8148(ctx, base);
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
loc_82700738:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82700764
	if (cr6.eq) goto loc_82700764;
	// lfs f12,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 - f30.f64));
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmadds f7,f9,f13,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f29
	cr6.compare(ctx.f7.f64, f29.f64);
	// bgt cr6,0x82700794
	if (cr6.gt) goto loc_82700794;
loc_82700764:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82700790
	if (cr6.eq) goto loc_82700790;
	// lfs f12,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 - f30.f64));
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmadds f7,f9,f13,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f29
	cr6.compare(ctx.f7.f64, f29.f64);
	// bgt cr6,0x82700794
	if (cr6.gt) goto loc_82700794;
loc_82700790:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82700794:
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

__attribute__((alias("__imp__sub_827007A8"))) PPC_WEAK_FUNC(sub_827007A8);
PPC_FUNC_IMPL(__imp__sub_827007A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x82700800
	if (cr6.eq) goto loc_82700800;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82700838
	if (!cr6.gt) goto loc_82700838;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_827007C4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827007e0
	if (cr6.eq) goto loc_827007E0;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r7,1076(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1076);
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// beq cr6,0x827007f8
	if (cr6.eq) goto loc_827007F8;
loc_827007E0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x827007c4
	if (cr6.lt) goto loc_827007C4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827007F8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_82700800:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82700838
	if (!cr6.gt) goto loc_82700838;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_8270080C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82700828
	if (cr6.eq) goto loc_82700828;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r7,1076(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 1076);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x827007f8
	if (!cr6.eq) goto loc_827007F8;
loc_82700828:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8270080c
	if (cr6.lt) goto loc_8270080C;
loc_82700838:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82700840"))) PPC_WEAK_FUNC(sub_82700840);
PPC_FUNC_IMPL(__imp__sub_82700840) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8270084C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 20);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82700874
	if (!cr6.eq) goto loc_82700874;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x8270084c
	if (cr6.lt) goto loc_8270084C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82700874:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r9
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// b 0x82714f68
	sub_82714F68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82700880"))) PPC_WEAK_FUNC(sub_82700880);
PPC_FUNC_IMPL(__imp__sub_82700880) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x827008d0
	if (!cr6.gt) goto loc_827008D0;
	// lwz r6,44(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
loc_82700898:
	// li r11,0
	r11.s64 = 0;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_827008A0:
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r4,20(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x827008d8
	if (!cr6.eq) goto loc_827008D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x827008a0
	if (cr6.lt) goto loc_827008A0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// blt cr6,0x82700898
	if (cr6.lt) goto loc_82700898;
loc_827008D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827008D8:
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lwz r3,32(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827008EC"))) PPC_WEAK_FUNC(sub_827008EC);
PPC_FUNC_IMPL(__imp__sub_827008EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827008F0"))) PPC_WEAK_FUNC(sub_827008F0);
PPC_FUNC_IMPL(__imp__sub_827008F0) {
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
	ctx.lr = 0x827008F8;
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
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700948
	if (cr6.eq) goto loc_82700948;
	// li r31,0
	r31.s64 = 0;
loc_82700918:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82700934
	if (cr6.eq) goto loc_82700934;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x8270c7e8
	ctx.lr = 0x82700934;
	sub_8270C7E8(ctx, base);
loc_82700934:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82700918
	if (cr6.lt) goto loc_82700918;
loc_82700948:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82700950"))) PPC_WEAK_FUNC(sub_82700950);
PPC_FUNC_IMPL(__imp__sub_82700950) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82700958;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700b7c
	if (cr6.eq) goto loc_82700B7C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700b7c
	if (cr6.eq) goto loc_82700B7C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700b7c
	if (cr6.eq) goto loc_82700B7C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x827009B0;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8224a2b8
	ctx.lr = 0x827009F8;
	sub_8224A2B8(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,-13624
	r31.s64 = r11.s64 + -13624;
	// lfs f30,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f31,-13028(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13028);
	f31.f64 = double(temp.f32);
	// stfs f30,0(r30)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// beq cr6,0x82700a30
	if (cr6.eq) goto loc_82700A30;
	// bl 0x822447b8
	ctx.lr = 0x82700A20;
	sub_822447B8(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x82700a4c
	if (!cr6.eq) goto loc_82700A4C;
loc_82700A30:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r11,21584
	ctx.r5.s64 = r11.s64 + 21584;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82130000
	ctx.lr = 0x82700A44;
	sub_82130000(ctx, base);
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 236);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_82700A4C:
	// lwz r11,244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	f0.f64 = double(temp.f32);
	// addi r9,r11,100
	ctx.r9.s64 = r11.s64 + 100;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lwz r8,48(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lwz r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fsel f5,f6,f12,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : ctx.f7.f64;
	// stfs f5,0(r25)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// lwz r11,252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// addi r5,r11,100
	ctx.r5.s64 = r11.s64 + 100;
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// lfs f4,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f13,248(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// fadds f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f2,80(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// fmuls f12,f13,f4
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fsubs f10,f3,f11
	ctx.f10.f64 = double(float(ctx.f3.f64 - ctx.f11.f64));
	// fsel f9,f10,f3,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f3.f64 : ctx.f11.f64;
	// stfs f9,0(r27)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// addi r3,r11,100
	ctx.r3.s64 = r11.s64 + 100;
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// lfs f8,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fadds f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f8
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f8.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fsubs f1,f7,f2
	ctx.f1.f64 = double(float(ctx.f7.f64 - ctx.f2.f64));
	// fsel f0,f1,f7,f2
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f7.f64 : ctx.f2.f64;
	// stfs f0,0(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lfs f13,224(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f31
	f0.f64 = double(float(ctx.f13.f64 * f31.f64));
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lfs f12,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82700b30
	if (!cr6.gt) goto loc_82700B30;
	// li r11,3
	r11.s64 = 3;
	// b 0x82700b58
	goto loc_82700B58;
loc_82700B30:
	// lfs f13,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82700b44
	if (!cr6.gt) goto loc_82700B44;
	// li r11,2
	r11.s64 = 2;
	// b 0x82700b58
	goto loc_82700B58;
loc_82700B44:
	// lfs f13,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82700b58
	if (cr6.gt) goto loc_82700B58;
	// li r11,0
	r11.s64 = 0;
loc_82700B58:
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82700B7C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82700B90"))) PPC_WEAK_FUNC(sub_82700B90);
PPC_FUNC_IMPL(__imp__sub_82700B90) {
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
	ctx.lr = 0x82700B98;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,484(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 484);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r9,r10,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82700c68
	if (cr6.eq) goto loc_82700C68;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82700c50
	if (cr6.eq) goto loc_82700C50;
	// li r31,0
	r31.s64 = 0;
loc_82700BDC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82700c28
	if (cr6.eq) goto loc_82700C28;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700c28
	if (cr6.eq) goto loc_82700C28;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822aafc8
	ctx.lr = 0x82700C0C;
	sub_822AAFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700c28
	if (cr6.eq) goto loc_82700C28;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82700c28
	if (!cr6.gt) goto loc_82700C28;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82700C28:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82700bdc
	if (cr6.lt) goto loc_82700BDC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,18080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18080);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x82700c54
	if (cr6.gt) goto loc_82700C54;
loc_82700C50:
	// li r11,0
	r11.s64 = 0;
loc_82700C54:
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82700C68:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82700C78"))) PPC_WEAK_FUNC(sub_82700C78);
PPC_FUNC_IMPL(__imp__sub_82700C78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82700C80;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82700CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82700f04
	if (cr6.eq) goto loc_82700F04;
	// lwz r31,640(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 640);
	// mr r28,r26
	r28.u64 = r26.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82700cf8
	if (cr6.eq) goto loc_82700CF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82245218
	ctx.lr = 0x82700CE0;
	sub_82245218(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700cf8
	if (cr6.eq) goto loc_82700CF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x82700CF4;
	sub_822452F8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_82700CF8:
	// mulli r11,r29,68
	r11.s64 = r29.s64 * 68;
	// add r30,r11,r30
	r30.u64 = r11.u64 + r30.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r11,152(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700d20
	if (cr6.eq) goto loc_82700D20;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// beq cr6,0x82700d2c
	if (cr6.eq) goto loc_82700D2C;
	// li r10,1
	ctx.r10.s64 = 1;
loc_82700D20:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82700d2c
	if (cr6.eq) goto loc_82700D2C;
	// li r31,1
	r31.s64 = 1;
loc_82700D2C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82700d68
	if (cr6.eq) goto loc_82700D68;
	// lfs f2,56(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f1,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// addi r5,r10,21720
	ctx.r5.s64 = ctx.r10.s64 + 21720;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82130000
	ctx.lr = 0x82700D64;
	sub_82130000(ctx, base);
	// stw r26,152(r30)
	PPC_STORE_U32(r30.u32 + 152, r26.u32);
loc_82700D68:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82700f04
	if (cr6.eq) goto loc_82700F04;
	// lfs f2,56(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f1,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// addi r5,r11,21676
	ctx.r5.s64 = r11.s64 + 21676;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82130000
	ctx.lr = 0x82700DA0;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82700230
	ctx.lr = 0x82700DC0;
	sub_82700230(ctx, base);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r9,2384
	ctx.r8.s64 = ctx.r9.s64 + 2384;
	// lvx128 v126,r0,r8
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v62,v63,v126
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v126.u8)));
	// vcmpeqfp128. v61,v62,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v61.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82700e00
	if (!cr6.eq) goto loc_82700E00;
	// bl 0x82700230
	ctx.lr = 0x82700DF0;
	sub_82700230(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82700e34
	goto loc_82700E34;
loc_82700E00:
	// bl 0x82700290
	ctx.lr = 0x82700E04;
	sub_82700290(ctx, base);
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v59,v126
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v126.u8)));
	// vcmpeqfp128. v57,v58,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v57.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82700e34
	if (!cr6.eq) goto loc_82700E34;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82700290
	ctx.lr = 0x82700E28;
	sub_82700290(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82700E34:
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82700e50
	if (cr6.eq) goto loc_82700E50;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82700e50
	if (cr6.eq) goto loc_82700E50;
	// lfs f31,224(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f31.f64 = double(temp.f32);
loc_82700E50:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// lfs f13,-7912(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82700ec0
	if (!cr6.gt) goto loc_82700EC0;
	// fneg f0,f31
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// li r7,272
	ctx.r7.s64 = 272;
	// addi r6,r9,-31664
	ctx.r6.s64 = ctx.r9.s64 + -31664;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r4,128(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r4,r7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vrefp128 v0,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v54.f32)));
	// vor128 v12,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v52,v53,v9
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v52,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82700ec8
	goto loc_82700EC8;
loc_82700EC0:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82700EC8:
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,32680(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bge cr6,0x82700f00
	if (!cr6.lt) goto loc_82700F00;
	// li r26,1
	r26.s64 = 1;
loc_82700F00:
	// stw r28,152(r30)
	PPC_STORE_U32(r30.u32 + 152, r28.u32);
loc_82700F04:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82700F24"))) PPC_WEAK_FUNC(sub_82700F24);
PPC_FUNC_IMPL(__imp__sub_82700F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82700F28"))) PPC_WEAK_FUNC(sub_82700F28);
PPC_FUNC_IMPL(__imp__sub_82700F28) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82700F44;
	sub_822A8108(ctx, base);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// bl 0x826fd0e8
	ctx.lr = 0x82700F4C;
	sub_826FD0E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82701060
	if (!cr6.eq) goto loc_82701060;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82700F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270105c
	if (cr6.eq) goto loc_8270105C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270105c
	if (cr6.eq) goto loc_8270105C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270105c
	if (cr6.eq) goto loc_8270105C;
	// lwz r10,640(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270105c
	if (cr6.eq) goto loc_8270105C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x8270101c
	if (!cr6.lt) goto loc_8270101C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82700FC8;
	sub_822A8108(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// lfs f0,628(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 628);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,632(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,624(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 624);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f12,f8,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x82701054
	if (cr6.gt) goto loc_82701054;
loc_82701000:
	// li r11,0
	r11.s64 = 0;
loc_82701004:
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
loc_8270101C:
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lfs f0,628(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 628);
	f0.f64 = double(temp.f32);
	// lfs f13,632(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 632);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,624(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 624);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,276(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bge cr6,0x82701000
	if (!cr6.lt) goto loc_82701000;
loc_82701054:
	// li r11,1
	r11.s64 = 1;
	// b 0x82701004
	goto loc_82701004;
loc_8270105C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82701060:
	// bl 0x822a8108
	ctx.lr = 0x82701064;
	sub_822A8108(ctx, base);
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

__attribute__((alias("__imp__sub_8270107C"))) PPC_WEAK_FUNC(sub_8270107C);
PPC_FUNC_IMPL(__imp__sub_8270107C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701080"))) PPC_WEAK_FUNC(sub_82701080);
PPC_FUNC_IMPL(__imp__sub_82701080) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827010a4
	if (cr6.eq) goto loc_827010A4;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x827010a8
	goto loc_827010A8;
loc_827010A4:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_827010A8:
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_827010B8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827010d8
	if (cr6.eq) goto loc_827010D8;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,1152(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1152);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x827010d8
	if (!cr6.eq) goto loc_827010D8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_827010D8:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x827010b8
	if (!cr0.eq) goto loc_827010B8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827010E8"))) PPC_WEAK_FUNC(sub_827010E8);
PPC_FUNC_IMPL(__imp__sub_827010E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82701164
	if (cr6.lt) goto loc_82701164;
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82701164
	if (!cr6.lt) goto loc_82701164;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82701118
	if (!cr6.eq) goto loc_82701118;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
loc_82701118:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82701164
	if (!cr6.gt) goto loc_82701164;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82701130:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82701154
	if (cr6.eq) goto loc_82701154;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r6,1152(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1152);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82701154
	if (!cr6.eq) goto loc_82701154;
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt 0x8270116c
	if (cr0.lt) goto loc_8270116C;
loc_82701154:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82701130
	if (cr6.lt) goto loc_82701130;
loc_82701164:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8270116C:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82701178"))) PPC_WEAK_FUNC(sub_82701178);
PPC_FUNC_IMPL(__imp__sub_82701178) {
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
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82701180;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701474
	if (cr6.eq) goto loc_82701474;
	// bl 0x82387a18
	ctx.lr = 0x827011B4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82701474
	if (!cr6.eq) goto loc_82701474;
	// bl 0x82388070
	ctx.lr = 0x827011C4;
	sub_82388070(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827011e0
	if (!cr6.eq) goto loc_827011E0;
	// bl 0x826bdb78
	ctx.lr = 0x827011D4;
	sub_826BDB78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701474
	if (cr6.eq) goto loc_82701474;
loc_827011E0:
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// li r29,0
	r29.s64 = 0;
	// li r23,1
	r23.s64 = 1;
	// lhz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8270125c
	if (!cr6.gt) goto loc_8270125C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_827011FC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270121c
	if (cr6.eq) goto loc_8270121C;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x827011fc
	if (cr6.lt) goto loc_827011FC;
	// b 0x8270125c
	goto loc_8270125C;
loc_8270121C:
	// li r3,1168
	ctx.r3.s64 = 1168;
	// bl 0x82130528
	ctx.lr = 0x82701224;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701234
	if (cr6.eq) goto loc_82701234;
	// bl 0x8270bee0
	ctx.lr = 0x82701230;
	sub_8270BEE0(ctx, base);
	// b 0x82701238
	goto loc_82701238;
loc_82701234:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82701238:
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stb r23,465(r7)
	PPC_STORE_U8(ctx.r7.u32 + 465, r23.u8);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_8270125C:
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// beq cr6,0x82701474
	if (cr6.eq) goto loc_82701474;
	// lwz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827012d8
	if (cr6.eq) goto loc_827012D8;
	// addi r3,r10,8109
	ctx.r3.s64 = ctx.r10.s64 + 8109;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x82701280;
	sub_823DB730(ctx, base);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x827012d8
	if (!cr6.eq) goto loc_827012D8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f11,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lwzx r3,r9,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f10,f31,f0
	ctx.f10.f64 = double(float(f31.f64 * f0.f64));
	// stfs f10,92(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,224(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x82701320
	goto loc_82701320;
loc_827012D8:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f12,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f0,27644(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 * f0.f64));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,188(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82701320:
	// bctrl 
	ctx.lr = 0x82701324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// beq cr6,0x827013a8
	if (cr6.eq) goto loc_827013A8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,896
	ctx.r10.s64 = 896;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwzx r28,r9,r31
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stb r26,872(r28)
	PPC_STORE_U8(r28.u32 + 872, r26.u8);
	// stw r29,868(r28)
	PPC_STORE_U32(r28.u32 + 868, r29.u32);
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r28,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x82683820
	ctx.lr = 0x82701364;
	sub_82683820(ctx, base);
	// clrlwi r7,r26,24
	ctx.r7.u64 = r26.u32 & 0xFF;
	// stb r23,964(r28)
	PPC_STORE_U8(r28.u32 + 964, r23.u8);
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r5,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r4,r11,9
	ctx.r4.s64 = r11.s64 + 9;
	// stb r4,966(r28)
	PPC_STORE_U8(r28.u32 + 966, ctx.r4.u8);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r11,r3,r31
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + r31.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,1048(r28)
	PPC_STORE_U32(r28.u32 + 1048, r11.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827013A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827013dc
	goto loc_827013DC;
loc_827013A8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827013d0
	if (cr6.eq) goto loc_827013D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827013CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_827013D0:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
loc_827013DC:
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82701460
	if (cr6.eq) goto loc_82701460;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rotlwi r4,r9,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b5ff0
	ctx.lr = 0x82701400;
	sub_822B5FF0(ctx, base);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8270c408
	ctx.lr = 0x82701414;
	sub_8270C408(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lbz r8,-6144(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + -6144);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82701448
	if (!cr6.eq) goto loc_82701448;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701440
	if (cr6.eq) goto loc_82701440;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82701448
	if (!cr6.eq) goto loc_82701448;
loc_82701440:
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// b 0x8270144c
	goto loc_8270144C;
loc_82701448:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8270144C:
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stb r10,1073(r9)
	PPC_STORE_U8(ctx.r9.u32 + 1073, ctx.r10.u8);
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_82701460:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_82701474:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82701484"))) PPC_WEAK_FUNC(sub_82701484);
PPC_FUNC_IMPL(__imp__sub_82701484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701488"))) PPC_WEAK_FUNC(sub_82701488);
PPC_FUNC_IMPL(__imp__sub_82701488) {
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
	ctx.lr = 0x82701490;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r7,-10016(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x827014ec
	if (cr6.eq) goto loc_827014EC;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82701080
	ctx.lr = 0x827014AC;
	sub_82701080(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x827014ec
	if (!cr6.gt) goto loc_827014EC;
	// b 0x827014c4
	goto loc_827014C4;
loc_827014C0:
	// lwz r7,-10016(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_827014C4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x827010e8
	ctx.lr = 0x827014D0;
	sub_827010E8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827014E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x827014c0
	if (cr6.lt) goto loc_827014C0;
loc_827014EC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827014F4"))) PPC_WEAK_FUNC(sub_827014F4);
PPC_FUNC_IMPL(__imp__sub_827014F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827014F8"))) PPC_WEAK_FUNC(sub_827014F8);
PPC_FUNC_IMPL(__imp__sub_827014F8) {
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
	ctx.lr = 0x82701500;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,-10016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82701554
	if (cr6.eq) goto loc_82701554;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82701080
	ctx.lr = 0x82701520;
	sub_82701080(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82701554
	if (!cr6.gt) goto loc_82701554;
loc_82701530:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827010e8
	ctx.lr = 0x8270153C;
	sub_827010E8(ctx, base);
	// lwz r11,140(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x82701558
	if (cr6.eq) goto loc_82701558;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// blt cr6,0x82701530
	if (cr6.lt) goto loc_82701530;
loc_82701554:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82701558:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82701560"))) PPC_WEAK_FUNC(sub_82701560);
PPC_FUNC_IMPL(__imp__sub_82701560) {
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
	// lwz r30,-10016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8270158c
	if (!cr6.eq) goto loc_8270158C;
loc_82701584:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827015cc
	goto loc_827015CC;
loc_8270158C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82701080
	ctx.lr = 0x82701594;
	sub_82701080(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827015c8
	if (!cr6.gt) goto loc_827015C8;
loc_827015A4:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827010e8
	ctx.lr = 0x827015B0;
	sub_827010E8(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82701584
	if (!cr6.eq) goto loc_82701584;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// blt cr6,0x827015a4
	if (cr6.lt) goto loc_827015A4;
loc_827015C8:
	// li r3,1
	ctx.r3.s64 = 1;
loc_827015CC:
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

__attribute__((alias("__imp__sub_827015E4"))) PPC_WEAK_FUNC(sub_827015E4);
PPC_FUNC_IMPL(__imp__sub_827015E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827015E8"))) PPC_WEAK_FUNC(sub_827015E8);
PPC_FUNC_IMPL(__imp__sub_827015E8) {
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
	// lwz r30,-10016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82701614
	if (!cr6.eq) goto loc_82701614;
loc_8270160C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82701654
	goto loc_82701654;
loc_82701614:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82701080
	ctx.lr = 0x8270161C;
	sub_82701080(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82701650
	if (!cr6.gt) goto loc_82701650;
loc_8270162C:
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827010e8
	ctx.lr = 0x82701638;
	sub_827010E8(ctx, base);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8270160c
	if (!cr6.eq) goto loc_8270160C;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r31
	cr6.compare<int32_t>(ctx.r5.s32, r31.s32, xer);
	// blt cr6,0x8270162c
	if (cr6.lt) goto loc_8270162C;
loc_82701650:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82701654:
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

__attribute__((alias("__imp__sub_8270166C"))) PPC_WEAK_FUNC(sub_8270166C);
PPC_FUNC_IMPL(__imp__sub_8270166C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701670"))) PPC_WEAK_FUNC(sub_82701670);
PPC_FUNC_IMPL(__imp__sub_82701670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82701678;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827016cc
	if (cr6.eq) goto loc_827016CC;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82701694;
	sub_82701080(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x827016cc
	if (!cr6.gt) goto loc_827016CC;
loc_827016A4:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x827016B0;
	sub_827010E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827016c0
	if (cr6.eq) goto loc_827016C0;
	// bl 0x822a8e20
	ctx.lr = 0x827016BC;
	sub_822A8E20(ctx, base);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_827016C0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x827016a4
	if (cr6.lt) goto loc_827016A4;
loc_827016CC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827016D4"))) PPC_WEAK_FUNC(sub_827016D4);
PPC_FUNC_IMPL(__imp__sub_827016D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827016D8"))) PPC_WEAK_FUNC(sub_827016D8);
PPC_FUNC_IMPL(__imp__sub_827016D8) {
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
	ctx.lr = 0x827016E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82701740
	if (cr6.eq) goto loc_82701740;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82701700;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82701740
	if (!cr6.gt) goto loc_82701740;
loc_82701710:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x8270171C;
	sub_827010E8(ctx, base);
	// lbz r11,872(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701734
	if (cr6.eq) goto loc_82701734;
	// stb r30,1072(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1072, r30.u8);
	// stb r30,1073(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1073, r30.u8);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_82701734:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x82701710
	if (cr6.lt) goto loc_82701710;
loc_82701740:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82701748"))) PPC_WEAK_FUNC(sub_82701748);
PPC_FUNC_IMPL(__imp__sub_82701748) {
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
	ctx.lr = 0x82701750;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r5,-10016(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x827017ac
	if (cr6.eq) goto loc_827017AC;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82701770;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x827017ac
	if (!cr6.gt) goto loc_827017AC;
loc_82701780:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x8270178C;
	sub_827010E8(ctx, base);
	// lbz r11,872(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827017a0
	if (cr6.eq) goto loc_827017A0;
	// stb r29,1072(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1072, r29.u8);
	// lwz r5,-10016(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_827017A0:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x82701780
	if (cr6.lt) goto loc_82701780;
loc_827017AC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827017B4"))) PPC_WEAK_FUNC(sub_827017B4);
PPC_FUNC_IMPL(__imp__sub_827017B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827017B8"))) PPC_WEAK_FUNC(sub_827017B8);
PPC_FUNC_IMPL(__imp__sub_827017B8) {
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
	ctx.lr = 0x827017C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r5,-10016(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8270181c
	if (cr6.eq) goto loc_8270181C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x827017E0;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8270181c
	if (!cr6.gt) goto loc_8270181C;
loc_827017F0:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x827017FC;
	sub_827010E8(ctx, base);
	// lbz r11,872(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701810
	if (cr6.eq) goto loc_82701810;
	// stb r29,1073(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1073, r29.u8);
	// lwz r5,-10016(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_82701810:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x827017f0
	if (cr6.lt) goto loc_827017F0;
loc_8270181C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82701824"))) PPC_WEAK_FUNC(sub_82701824);
PPC_FUNC_IMPL(__imp__sub_82701824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701828"))) PPC_WEAK_FUNC(sub_82701828);
PPC_FUNC_IMPL(__imp__sub_82701828) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82701830;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701914
	if (cr6.eq) goto loc_82701914;
	// lhz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82701900
	if (cr6.eq) goto loc_82701900;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lfs f29,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f29.f64 = double(temp.f32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82701888:
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lbz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827018ec
	if (cr6.eq) goto loc_827018EC;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// stb r26,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, r26.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827018c0
	if (cr6.eq) goto loc_827018C0;
	// lfs f1,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x827018c4
	if (cr6.gt) goto loc_827018C4;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// b 0x827018c4
	goto loc_827018C4;
loc_827018C0:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
loc_827018C4:
	// bl 0x82710f28
	ctx.lr = 0x827018C8;
	sub_82710F28(ctx, base);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// stb r29,30(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30, r29.u8);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwzx r8,r9,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// stb r28,31(r8)
	PPC_STORE_U8(ctx.r8.u32 + 31, r28.u8);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
loc_827018EC:
	// lhz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// blt cr6,0x82701888
	if (cr6.lt) goto loc_82701888;
loc_82701900:
	// stb r26,220(r11)
	PPC_STORE_U8(r11.u32 + 220, r26.u8);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// stb r29,221(r11)
	PPC_STORE_U8(r11.u32 + 221, r29.u8);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// stb r28,222(r11)
	PPC_STORE_U8(r11.u32 + 222, r28.u8);
loc_82701914:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_82701928"))) PPC_WEAK_FUNC(sub_82701928);
PPC_FUNC_IMPL(__imp__sub_82701928) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82701944"))) PPC_WEAK_FUNC(sub_82701944);
PPC_FUNC_IMPL(__imp__sub_82701944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701948"))) PPC_WEAK_FUNC(sub_82701948);
PPC_FUNC_IMPL(__imp__sub_82701948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82701950;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827019f8
	if (cr6.eq) goto loc_827019F8;
	// lfs f3,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lfs f2,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// stfd f4,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f4.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// stfd f3,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f3.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f2,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f2.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f1,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f1.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// addi r5,r11,21832
	ctx.r5.s64 = r11.s64 + 21832;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x827019BC;
	sub_82130000(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x827019f8
	if (cr6.lt) goto loc_827019F8;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lhz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 184);
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bge cr6,0x827019f8
	if (!cr6.lt) goto loc_827019F8;
	// lwz r11,180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// lwz r8,180(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stfs f31,16(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 16, temp.u32);
loc_827019F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82701A04"))) PPC_WEAK_FUNC(sub_82701A04);
PPC_FUNC_IMPL(__imp__sub_82701A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701A08"))) PPC_WEAK_FUNC(sub_82701A08);
PPC_FUNC_IMPL(__imp__sub_82701A08) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701a6c
	if (cr6.eq) goto loc_82701A6C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82701a68
	if (cr6.eq) goto loc_82701A68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82701A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r8,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r31,208(r11)
	PPC_STORE_U32(r11.u32 + 208, r31.u32);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_82701A68:
	// stw r3,204(r11)
	PPC_STORE_U32(r11.u32 + 204, ctx.r3.u32);
loc_82701A6C:
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

__attribute__((alias("__imp__sub_82701A84"))) PPC_WEAK_FUNC(sub_82701A84);
PPC_FUNC_IMPL(__imp__sub_82701A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701A88"))) PPC_WEAK_FUNC(sub_82701A88);
PPC_FUNC_IMPL(__imp__sub_82701A88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701ab0
	if (cr6.eq) goto loc_82701AB0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// blr 
	return;
loc_82701AB0:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82701ABC"))) PPC_WEAK_FUNC(sub_82701ABC);
PPC_FUNC_IMPL(__imp__sub_82701ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82701AC0"))) PPC_WEAK_FUNC(sub_82701AC0);
PPC_FUNC_IMPL(__imp__sub_82701AC0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82701AC8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,-10016(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701bb8
	if (cr6.eq) goto loc_82701BB8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82701bb8
	if (cr6.eq) goto loc_82701BB8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82701B00;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701bb8
	if (cr6.eq) goto loc_82701BB8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x82701B18;
	sub_822A3998(ctx, base);
	// lwz r5,-10016(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82701B28;
	sub_82701080(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82701bb8
	if (!cr6.gt) goto loc_82701BB8;
loc_82701B38:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x82701B44;
	sub_827010E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,880(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82701bac
	if (!cr6.eq) goto loc_82701BAC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a8108
	ctx.lr = 0x82701B5C;
	sub_822A8108(ctx, base);
	// addi r26,r3,48
	r26.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82701B68;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f31,f31
	ctx.f13.f64 = double(float(f31.f64 * f31.f64));
	// lfs f12,8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f8,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f13
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// blt cr6,0x82701bc8
	if (cr6.lt) goto loc_82701BC8;
	// lwz r5,-10016(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -10016);
loc_82701BAC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82701b38
	if (cr6.lt) goto loc_82701B38;
loc_82701BB8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_82701BC8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82701BD8"))) PPC_WEAK_FUNC(sub_82701BD8);
PPC_FUNC_IMPL(__imp__sub_82701BD8) {
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
	ctx.lr = 0x82701BE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701dc8
	if (cr6.eq) goto loc_82701DC8;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82700368
	ctx.lr = 0x82701C04;
	sub_82700368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701c3c
	if (cr6.eq) goto loc_82701C3C;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82701c24
	if (cr6.gt) goto loc_82701C24;
	// li r11,0
	r11.s64 = 0;
loc_82701C24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701c3c
	if (cr6.eq) goto loc_82701C3C;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701C3C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// bl 0x827004b8
	ctx.lr = 0x82701C48;
	sub_827004B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701c60
	if (cr6.eq) goto loc_82701C60;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701C60:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// bl 0x827003f8
	ctx.lr = 0x82701C6C;
	sub_827003F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701c84
	if (cr6.eq) goto loc_82701C84;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701C84:
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// lbz r11,56(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701ca0
	if (cr6.eq) goto loc_82701CA0;
	// li r3,100
	ctx.r3.s64 = 100;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701CA0:
	// clrlwi r27,r31,24
	r27.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82701cd4
	if (cr6.eq) goto loc_82701CD4;
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82701cc4
	if (cr6.eq) goto loc_82701CC4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82701cc8
	if (!cr6.eq) goto loc_82701CC8;
loc_82701CC4:
	// li r11,1
	r11.s64 = 1;
loc_82701CC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82701ce8
	if (!cr6.eq) goto loc_82701CE8;
loc_82701CD4:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82700368
	ctx.lr = 0x82701CE0;
	sub_82700368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701cf4
	if (cr6.eq) goto loc_82701CF4;
loc_82701CE8:
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701CF4:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82700368
	ctx.lr = 0x82701D04;
	sub_82700368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701d18
	if (cr6.eq) goto loc_82701D18;
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701D18:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82700368
	ctx.lr = 0x82701D28;
	sub_82700368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701d3c
	if (cr6.eq) goto loc_82701D3C;
	// li r3,5
	ctx.r3.s64 = 5;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701D3C:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82700368
	ctx.lr = 0x82701D4C;
	sub_82700368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82701d60
	if (cr6.eq) goto loc_82701D60;
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701D60:
	// lwz r5,-10016(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82701D6C;
	sub_82701080(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82701dc8
	if (!cr6.gt) goto loc_82701DC8;
loc_82701D7C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x82701D88;
	sub_827010E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x82701dbc
	if (!cr6.eq) goto loc_82701DBC;
	// bl 0x8270c388
	ctx.lr = 0x82701D9C;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701db8
	if (cr6.eq) goto loc_82701DB8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c360
	ctx.lr = 0x82701DB0;
	sub_8270C360(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82701dd4
	if (cr6.eq) goto loc_82701DD4;
loc_82701DB8:
	// lwz r5,-10016(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -10016);
loc_82701DBC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82701d7c
	if (cr6.lt) goto loc_82701D7C;
loc_82701DC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82701DD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82701DE0"))) PPC_WEAK_FUNC(sub_82701DE0);
PPC_FUNC_IMPL(__imp__sub_82701DE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82701DE8;
	// lhz r30,48(r3)
	r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82701e88
	if (!cr6.gt) goto loc_82701E88;
	// lwz r29,44(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82701E00:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_82701E08:
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lbz r11,20(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82701e68
	if (cr6.eq) goto loc_82701E68;
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82701e68
	if (!cr6.gt) goto loc_82701E68;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82701E2C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82701e4c
	if (cr6.lt) goto loc_82701E4C;
	// lwz r11,72(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82701e4c
	if (!cr6.lt) goto loc_82701E4C;
	// lwz r11,76(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// b 0x82701e50
	goto loc_82701E50;
loc_82701E4C:
	// li r11,0
	r11.s64 = 0;
loc_82701E50:
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x82701e90
	if (cr6.eq) goto loc_82701E90;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x82701e2c
	if (cr6.lt) goto loc_82701E2C;
loc_82701E68:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// blt cr6,0x82701e08
	if (cr6.lt) goto loc_82701E08;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x82701e00
	if (cr6.lt) goto loc_82701E00;
loc_82701E88:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d924c
	return;
loc_82701E90:
	// add r11,r5,r31
	r11.u64 = ctx.r5.u64 + r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r29
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r29.u32);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82701EA0"))) PPC_WEAK_FUNC(sub_82701EA0);
PPC_FUNC_IMPL(__imp__sub_82701EA0) {
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
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c598
	ctx.lr = 0x82701ECC;
	sub_8270C598(ctx, base);
	// lhz r11,176(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 176);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// beq cr6,0x82701f10
	if (cr6.eq) goto loc_82701F10;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_82701EE4:
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r7,r30
	cr6.compare<uint32_t>(ctx.r7.u32, r30.u32, xer);
	// bne cr6,0x82701efc
	if (!cr6.eq) goto loc_82701EFC;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_82701EFC:
	// lhz r11,176(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 176);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x82701ee4
	if (cr6.lt) goto loc_82701EE4;
loc_82701F10:
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

__attribute__((alias("__imp__sub_82701F28"))) PPC_WEAK_FUNC(sub_82701F28);
PPC_FUNC_IMPL(__imp__sub_82701F28) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82701F30;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// lwz r10,172(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// rlwinm r11,r25,2,0,29
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r24,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r27,68(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 68);
	// lwzx r30,r7,r9
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82701f98
	if (!cr6.eq) goto loc_82701F98;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r11,21992
	ctx.r5.s64 = r11.s64 + 21992;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82130000
	ctx.lr = 0x82701F90;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_82701F98:
	// lbz r9,880(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 880);
	// rlwinm r11,r31,4,0,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// beq cr6,0x82701fc8
	if (cr6.eq) goto loc_82701FC8;
	// li r11,912
	r11.s64 = 912;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stvx128 v63,r26,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270c408
	ctx.lr = 0x82701FC8;
	sub_8270C408(ctx, base);
loc_82701FC8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82744d40
	ctx.lr = 0x82701FD4;
	sub_82744D40(ctx, base);
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82702054
	if (!cr6.gt) goto loc_82702054;
	// addi r28,r11,-1
	r28.s64 = r11.s64 + -1;
	// addi r29,r11,-1
	r29.s64 = r11.s64 + -1;
loc_82701FE8:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x82701ffc
	if (!cr6.eq) goto loc_82701FFC;
	// li r31,0
	r31.s64 = 0;
	// b 0x82702038
	goto loc_82702038;
loc_82701FFC:
	// blt cr6,0x82702038
	if (cr6.lt) goto loc_82702038;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// blt cr6,0x82702010
	if (cr6.lt) goto loc_82702010;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82702010:
	// addi r9,r28,1
	ctx.r9.s64 = r28.s64 + 1;
	// rotlwi r11,r31,1
	r11.u64 = __builtin_rotateleft32(r31.u32, 1);
	// divw r8,r31,r9
	ctx.r8.s32 = r31.s32 / ctx.r9.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// andc r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 & ~ctx.r7.u64;
	// subf r11,r6,r31
	r11.s64 = r31.s64 - ctx.r6.s64;
	// twllei r9,0
	// twlgei r5,-1
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
loc_82702038:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r11,r31,4,0,27
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82744d60
	ctx.lr = 0x8270204C;
	sub_82744D60(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x82701fe8
	if (!cr0.eq) goto loc_82701FE8;
loc_82702054:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82744aa8
	ctx.lr = 0x82702060;
	sub_82744AA8(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8270c598
	ctx.lr = 0x82702070;
	sub_8270C598(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r11,21928
	ctx.r5.s64 = r11.s64 + 21928;
	// lwz r6,868(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 868);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x82702090;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82702098"))) PPC_WEAK_FUNC(sub_82702098);
PPC_FUNC_IMPL(__imp__sub_82702098) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827020A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827021bc
	if (cr6.eq) goto loc_827021BC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,-5460(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827020D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827021bc
	if (cr6.eq) goto loc_827021BC;
	// lwz r11,1120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1120);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827021bc
	if (cr6.eq) goto loc_827021BC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lhz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 12);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// beq cr6,0x827021bc
	if (cr6.eq) goto loc_827021BC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,1128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x827021bc
	if (cr6.gt) goto loc_827021BC;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lwz r11,2192(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// addi r7,r4,-13624
	ctx.r7.s64 = ctx.r4.s64 + -13624;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lis r27,-32256
	r27.s64 = -2113929216;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mulld r9,r4,r5
	ctx.r9.s64 = ctx.r4.s64 * ctx.r5.s64;
	// lwz r10,320(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 320);
	// lfs f0,14348(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lfs f13,11360(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// stw r10,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f5,f7,f13
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fcmpu cr6,f6,f5
	cr6.compare(ctx.f6.f64, ctx.f5.f64);
	// ble cr6,0x827021c8
	if (!cr6.gt) goto loc_827021C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,1128(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 1128, temp.u32);
loc_827021BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_827021C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x827021D0;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// li r11,-1
	r11.s64 = -1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r9,172(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,1120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1120);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// lfs f13,22044(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 22044);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lhz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827022bc
	if (cr6.eq) goto loc_827022BC;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
loc_8270222C:
	// lwz r11,1124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1124);
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// beq cr6,0x827022a8
	if (cr6.eq) goto loc_827022A8;
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwzx r8,r11,r5
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// lhz r9,8(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827022a8
	if (cr6.eq) goto loc_827022A8;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82702254:
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f8,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f0,f5,f5,f3
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82702294
	if (!cr6.lt) goto loc_82702294;
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82702294:
	// lhz r11,8(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82702254
	if (cr6.lt) goto loc_82702254;
loc_827022A8:
	// lhz r11,12(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8270222c
	if (cr6.lt) goto loc_8270222C;
loc_827022BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827022C8"))) PPC_WEAK_FUNC(sub_827022C8);
PPC_FUNC_IMPL(__imp__sub_827022C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r6,48(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82702324
	if (!cr6.gt) goto loc_82702324;
	// lwz r5,44(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_827022E0:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_827022E8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82702304
	if (cr6.eq) goto loc_82702304;
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x8270232c
	if (cr6.eq) goto loc_8270232C;
loc_82702304:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// blt cr6,0x827022e8
	if (cr6.lt) goto loc_827022E8;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// blt cr6,0x827022e0
	if (cr6.lt) goto loc_827022E0;
loc_82702324:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8270232C:
	// add r11,r9,r7
	r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r5
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270233C"))) PPC_WEAK_FUNC(sub_8270233C);
PPC_FUNC_IMPL(__imp__sub_8270233C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82702340"))) PPC_WEAK_FUNC(sub_82702340);
PPC_FUNC_IMPL(__imp__sub_82702340) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// bge cr6,0x82702384
	if (!cr6.lt) goto loc_82702384;
	// fsubs f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x82702394
	goto loc_82702394;
loc_82702384:
	// fadds f0,f1,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82702394:
	// li r10,3600
	ctx.r10.s64 = 3600;
	// divw r6,r11,r10
	ctx.r6.s32 = r11.s32 / ctx.r10.s32;
	// cmpwi cr6,r6,99
	cr6.compare<int32_t>(ctx.r6.s32, 99, xer);
	// blt cr6,0x827023a8
	if (cr6.lt) goto loc_827023A8;
	// li r6,99
	ctx.r6.s64 = 99;
loc_827023A8:
	// mr r31,r11
	r31.u64 = r11.u64;
	// lis r9,-30584
	ctx.r9.s64 = -2004353024;
	// lis r8,-28254
	ctx.r8.s64 = -1851654144;
	// ori r7,r9,34953
	ctx.r7.u64 = ctx.r9.u64 | 34953;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// ori r5,r8,46021
	ctx.r5.u64 = ctx.r8.u64 | 46021;
	// mulhw r9,r10,r7
	ctx.r9.s64 = (int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32)) >> 32;
	// mulhw r8,r11,r5
	ctx.r8.s64 = (int64_t(r11.s32) * int64_t(ctx.r5.s32)) >> 32;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + r11.u64;
	// srawi r10,r10,5
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 5;
	// srawi r9,r9,11
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 11;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// li r10,60
	ctx.r10.s64 = 60;
	// mulli r9,r7,3600
	ctx.r9.s64 = ctx.r7.s64 * 3600;
	// subf r7,r9,r11
	ctx.r7.s64 = r11.s64 - ctx.r9.s64;
	// mulli r11,r8,60
	r11.s64 = ctx.r8.s64 * 60;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// subf r8,r11,r31
	ctx.r8.s64 = r31.s64 - r11.s64;
	// addi r5,r5,22048
	ctx.r5.s64 = ctx.r5.s64 + 22048;
	// divw r7,r7,r10
	ctx.r7.s32 = ctx.r7.s32 / ctx.r10.s32;
	// bl 0x82137a08
	ctx.lr = 0x8270240C;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_82702420"))) PPC_WEAK_FUNC(sub_82702420);
PPC_FUNC_IMPL(__imp__sub_82702420) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82702428;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r10,-6730(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6730);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82702454
	if (cr6.eq) goto loc_82702454;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82702454:
	// lwz r29,36(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r30,r11,-13624
	r30.s64 = r11.s64 + -13624;
	// beq cr6,0x82702568
	if (cr6.eq) goto loc_82702568;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r11,2
	r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
loc_82702478:
	// slw r9,r10,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82702494
	if (!cr6.eq) goto loc_82702494;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x82702478
	if (!cr0.lt) goto loc_82702478;
	// b 0x827024a0
	goto loc_827024A0;
loc_82702494:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r30,128
	ctx.r10.s64 = r30.s64 + 128;
	// lwzx r31,r11,r10
	r31.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_827024A0:
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r11,r30,144
	r11.s64 = r30.s64 + 144;
loc_827024A8:
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827024bc
	if (cr6.eq) goto loc_827024BC;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_827024BC:
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827024d4
	if (cr6.eq) goto loc_827024D4;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_827024D4:
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827024ec
	if (cr6.eq) goto loc_827024EC;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_827024EC:
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82702504
	if (cr6.eq) goto loc_82702504;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_82702504:
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270251c
	if (cr6.eq) goto loc_8270251C;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_8270251C:
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// and r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82702534
	if (cr6.eq) goto loc_82702534;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// add r31,r9,r31
	r31.u64 = ctx.r9.u64 + r31.u64;
loc_82702534:
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// addi r9,r30,192
	ctx.r9.s64 = r30.s64 + 192;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x827024a8
	if (cr6.lt) goto loc_827024A8;
	// rlwinm r11,r8,0,26,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702568
	if (cr6.eq) goto loc_82702568;
	// rlwinm r11,r8,0,25,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702568
	if (cr6.eq) goto loc_82702568;
	// lwz r11,152(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// subf r31,r11,r31
	r31.s64 = r31.s64 - r11.s64;
loc_82702568:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270257C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// lfs f31,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f31.f64 = double(temp.f32);
	// blt cr6,0x82702600
	if (cr6.lt) goto loc_82702600;
	// lwz r11,120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// lfs f0,104(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 104);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x827025d0
	if (!cr6.lt) goto loc_827025D0;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x827025e0
	goto loc_827025E0;
loc_827025D0:
	// fadds f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_827025E0:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82702600
	if (cr6.eq) goto loc_82702600;
	// lbz r11,12(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702600
	if (cr6.eq) goto loc_82702600;
	// lwz r11,124(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 124);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82702600:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x82702610;
	sub_826B95B0(ctx, base);
	// bl 0x826bbcf0
	ctx.lr = 0x82702614;
	sub_826BBCF0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8270262c
	if (!cr6.lt) goto loc_8270262C;
	// srawi r11,r31,2
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3) != 0);
	r11.s64 = r31.s32 >> 2;
	// b 0x82702654
	goto loc_82702654;
loc_8270262C:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82702640
	if (!cr6.lt) goto loc_82702640;
	// li r11,3
	r11.s64 = 3;
	// divw r31,r31,r11
	r31.s32 = r31.s32 / r11.s32;
	// b 0x82702658
	goto loc_82702658;
loc_82702640:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x82702658
	if (!cr6.lt) goto loc_82702658;
	// srawi r11,r31,1
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1) != 0);
	r11.s64 = r31.s32 >> 1;
loc_82702654:
	// addze r31,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r31.s64 = temp.s64;
loc_82702658:
	// cmpwi cr6,r31,100
	cr6.compare<int32_t>(r31.s32, 100, xer);
	// bge cr6,0x82702674
	if (!cr6.lt) goto loc_82702674;
	// li r11,100
	r11.s64 = 100;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82702674:
	// lwz r11,116(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bgt cr6,0x82702684
	if (cr6.gt) goto loc_82702684;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82702684:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82702694"))) PPC_WEAK_FUNC(sub_82702694);
PPC_FUNC_IMPL(__imp__sub_82702694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82702698"))) PPC_WEAK_FUNC(sub_82702698);
PPC_FUNC_IMPL(__imp__sub_82702698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827026d0
	if (cr6.eq) goto loc_827026D0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
loc_827026B0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827026d8
	if (cr6.eq) goto loc_827026D8;
	// lhz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x827026b0
	if (cr6.lt) goto loc_827026B0;
loc_827026D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827026D8:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stb r8,4(r7)
	PPC_STORE_U8(ctx.r7.u32 + 4, ctx.r8.u8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82702700"))) PPC_WEAK_FUNC(sub_82702700);
PPC_FUNC_IMPL(__imp__sub_82702700) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82702770
	if (cr6.eq) goto loc_82702770;
	// clrlwi r7,r5,24
	ctx.r7.u64 = ctx.r5.u32 & 0xFF;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8270271C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8270273c
	if (cr6.eq) goto loc_8270273C;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r4,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r4.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r5,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// b 0x82702750
	goto loc_82702750;
loc_8270273C:
	// lwzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// subf r3,r6,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r6.s64;
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_82702750:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82702778
	if (!cr6.eq) goto loc_82702778;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// blt cr6,0x8270271c
	if (cr6.lt) goto loc_8270271C;
loc_82702770:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82702778:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82702770
	if (cr6.eq) goto loc_82702770;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r9,4(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4, ctx.r9.u8);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827027AC"))) PPC_WEAK_FUNC(sub_827027AC);
PPC_FUNC_IMPL(__imp__sub_827027AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827027B0"))) PPC_WEAK_FUNC(sub_827027B0);
PPC_FUNC_IMPL(__imp__sub_827027B0) {
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
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x827027CC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x827027f4
	if (!cr6.gt) goto loc_827027F4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_827027DC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827027e8
	if (cr6.eq) goto loc_827027E8;
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
loc_827027E8:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x827027dc
	if (!cr0.eq) goto loc_827027DC;
loc_827027F4:
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

__attribute__((alias("__imp__sub_82702808"))) PPC_WEAK_FUNC(sub_82702808);
PPC_FUNC_IMPL(__imp__sub_82702808) {
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
	ctx.lr = 0x82702810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,164
	ctx.r3.s64 = r31.s64 + 164;
	// bl 0x8270da30
	ctx.lr = 0x82702820;
	sub_8270DA30(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r29,r28
	r29.u64 = r28.u64;
	// beq cr6,0x8270288c
	if (cr6.eq) goto loc_8270288C;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82702838:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82702878
	if (cr6.eq) goto loc_82702878;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270285C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r9,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,136(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 136);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82702878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82702878:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82702838
	if (cr6.lt) goto loc_82702838;
loc_8270288C:
	// lhz r11,48(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827028cc
	if (cr6.eq) goto loc_827028CC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_827028A0:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827028B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 48);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x827028a0
	if (cr6.lt) goto loc_827028A0;
loc_827028CC:
	// stw r28,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r28.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stb r28,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r28.u8);
	// stw r28,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r28.u32);
	// stb r28,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r28.u8);
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
	// stw r28,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r28.u32);
	// stw r28,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r28.u32);
	// stb r28,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r28.u8);
	// stw r28,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r28.u32);
	// bl 0x82714f10
	ctx.lr = 0x82702900;
	sub_82714F10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82702914"))) PPC_WEAK_FUNC(sub_82702914);
PPC_FUNC_IMPL(__imp__sub_82702914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82702918"))) PPC_WEAK_FUNC(sub_82702918);
PPC_FUNC_IMPL(__imp__sub_82702918) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82702a10
	if (cr6.eq) goto loc_82702A10;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,-12744(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -12744);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82702958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82702990
	if (cr6.eq) goto loc_82702990;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82702978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,20
	ctx.r3.s64 = r30.s64 + 20;
	// bl 0x82702700
	ctx.lr = 0x8270298C;
	sub_82702700(ctx, base);
	// b 0x82702a10
	goto loc_82702A10;
loc_82702990:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,-5460(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827029A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827029e8
	if (cr6.eq) goto loc_827029E8;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// bl 0x82744d08
	ctx.lr = 0x827029C0;
	sub_82744D08(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827029D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// bl 0x82702700
	ctx.lr = 0x827029E4;
	sub_82702700(ctx, base);
	// b 0x82702a10
	goto loc_82702A10;
loc_827029E8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827029F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82702A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82702A10:
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

__attribute__((alias("__imp__sub_82702A28"))) PPC_WEAK_FUNC(sub_82702A28);
PPC_FUNC_IMPL(__imp__sub_82702A28) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82702A30;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702b10
	if (cr6.eq) goto loc_82702B10;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r31,0
	r31.s64 = 0;
	// addi r27,r11,-13624
	r27.s64 = r11.s64 + -13624;
loc_82702A64:
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702afc
	if (cr6.eq) goto loc_82702AFC;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702a8c
	if (cr6.eq) goto loc_82702A8C;
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lbz r11,1072(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1072);
	// b 0x82702a90
	goto loc_82702A90;
loc_82702A8C:
	// li r11,1
	r11.s64 = 1;
loc_82702A90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702afc
	if (cr6.eq) goto loc_82702AFC;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702ac4
	if (cr6.eq) goto loc_82702AC4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// bl 0x82701de0
	ctx.lr = 0x82702AB4;
	sub_82701DE0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82702afc
	if (cr6.eq) goto loc_82702AFC;
loc_82702AC4:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// lbz r9,872(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82702afc
	if (!cr6.eq) goto loc_82702AFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f2,220(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 220);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfs f1,188(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 188);
	ctx.f1.f64 = double(temp.f32);
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x8270cfc8
	ctx.lr = 0x82702AF0;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82702b1c
	if (!cr6.eq) goto loc_82702B1C;
loc_82702AFC:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82702a64
	if (cr6.lt) goto loc_82702A64;
loc_82702B10:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_82702B1C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82702B30"))) PPC_WEAK_FUNC(sub_82702B30);
PPC_FUNC_IMPL(__imp__sub_82702B30) {
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
	// li r31,0
	r31.s64 = 0;
	// bl 0x82701de0
	ctx.lr = 0x82702B48;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82702b80
	if (cr6.eq) goto loc_82702B80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82702B60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
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
loc_82702B80:
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

__attribute__((alias("__imp__sub_82702B98"))) PPC_WEAK_FUNC(sub_82702B98);
PPC_FUNC_IMPL(__imp__sub_82702B98) {
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
	// li r31,0
	r31.s64 = 0;
	// bl 0x82701de0
	ctx.lr = 0x82702BB0;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82702bf0
	if (cr6.eq) goto loc_82702BF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82702BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82702bd8
	if (!cr6.lt) goto loc_82702BD8;
	// li r11,0
	r11.s64 = 0;
loc_82702BD8:
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
loc_82702BF0:
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

__attribute__((alias("__imp__sub_82702C08"))) PPC_WEAK_FUNC(sub_82702C08);
PPC_FUNC_IMPL(__imp__sub_82702C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82702C10;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// bl 0x827022c8
	ctx.lr = 0x82702C4C;
	sub_827022C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82702c6c
	if (cr6.eq) goto loc_82702C6C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82702C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
loc_82702C6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x82702C74;
	sub_822A8108(ctx, base);
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// addi r26,r27,48
	r26.s64 = r27.s64 + 48;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826fd0a8
	ctx.lr = 0x82702C9C;
	sub_826FD0A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826fd0e8
	ctx.lr = 0x82702CB0;
	sub_826FD0E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270306c
	if (!cr6.eq) goto loc_8270306C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826fd088
	ctx.lr = 0x82702CC4;
	sub_826FD088(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270306c
	if (!cr6.eq) goto loc_8270306C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826fd0c8
	ctx.lr = 0x82702CD8;
	sub_826FD0C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270306c
	if (!cr6.eq) goto loc_8270306C;
	// li r31,0
	r31.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82700640
	ctx.lr = 0x82702CFC;
	sub_82700640(ctx, base);
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r30,96(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f30,224(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f30.f64 = double(temp.f32);
	// bne cr6,0x82702d30
	if (!cr6.eq) goto loc_82702D30;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,23960(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 23960);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bge cr6,0x8270306c
	if (!cr6.lt) goto loc_8270306C;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82703070
	goto loc_82703070;
loc_82702D30:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82702D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82702d5c
	if (cr6.eq) goto loc_82702D5C;
	// lwz r11,640(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 640);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
loc_82702D5C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822447b8
	ctx.lr = 0x82702D64;
	sub_822447B8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-13624
	r11.s64 = r11.s64 + -13624;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x82702d8c
	if (!cr6.eq) goto loc_82702D8C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,236(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 236);
	f0.f64 = double(temp.f32);
	// lfs f13,-7912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_82702D8C:
	// lwz r11,280(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 280);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fcmpu cr6,f30,f10
	cr6.compare(f30.f64, ctx.f10.f64);
	// bge cr6,0x8270306c
	if (!cr6.lt) goto loc_8270306C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f30,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82702f2c
	if (cr6.eq) goto loc_82702F2C;
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82702f2c
	if (cr6.eq) goto loc_82702F2C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x82702DE0;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 84);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f12,88(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f10,64(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r28,80
	r30.s64 = r28.s64 + 80;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fmuls f6,f13,f13
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f0,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fsubs f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// lfd f2,-32664(r9)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r9.u32 + -32664);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmadds f1,f10,f30,f0
	ctx.f1.f64 = double(float(ctx.f10.f64 * f30.f64 + f0.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f29,f5,f5,f4
	f29.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// bl 0x823dc480
	ctx.lr = 0x82702E40;
	sub_823DC480(ctx, base);
	// frsp f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f29,f3
	cr6.compare(f29.f64, ctx.f3.f64);
	// bge cr6,0x82702f2c
	if (!cr6.lt) goto loc_82702F2C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82700230
	ctx.lr = 0x82702E64;
	sub_82700230(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v62,v126
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v126.u8)));
	// vcmpeqfp128. v60,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v60.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82702ea4
	if (!cr6.eq) goto loc_82702EA4;
	// bl 0x82700230
	ctx.lr = 0x82702E94;
	sub_82700230(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82702ed8
	goto loc_82702ED8;
loc_82702EA4:
	// bl 0x82700290
	ctx.lr = 0x82702EA8;
	sub_82700290(ctx, base);
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v58,v126
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v126.u8)));
	// vcmpeqfp128. v56,v57,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v56.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82702ed8
	if (!cr6.eq) goto loc_82702ED8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82700290
	ctx.lr = 0x82702ECC;
	sub_82700290(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82702ED8:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v54,v126
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v126.u8)));
	// vcmpeqfp128. v52,v53,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v52.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8270306c
	if (!cr6.eq) goto loc_8270306C;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v49,v51,v50
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x82702F1C;
	sub_8216C900(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f0,22064(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 22064);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8270306c
	if (cr6.lt) goto loc_8270306C;
loc_82702F2C:
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270306c
	if (cr6.eq) goto loc_8270306C;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v13,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lis r30,-32250
	r30.s64 = -2113536000;
	// lvx128 v48,r11,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v47,r11,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,2256
	r11.s64 = ctx.r3.s64 + 2256;
	// vsubfp128 v46,v47,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v0,r27,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7156(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7156);
	f0.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r29,r1,240
	r29.s64 = ctx.r1.s64 + 240;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,31492(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31492);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v12,r27,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,192(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r28,r1,256
	r28.s64 = ctx.r1.s64 + 256;
	// lvlx128 v45,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// stvx128 v46,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f12,f30
	ctx.f10.f64 = double(float(ctx.f12.f64 * f30.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lvlx128 v44,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v44,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lvlx128 v43,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v43,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// vmaddfp v9,v0,v10,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,196(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r10,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r10.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,-23452(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -23452);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// sth r31,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r31.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r31,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r31.u8);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// sth r31,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r31.u16);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// stw r31,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r31.u32);
	// vmaddfp v13,v12,v8,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v7,v0,v11,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v13,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x8270305C;
	sub_82574418(ctx, base);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703070
	if (cr6.eq) goto loc_82703070;
loc_8270306C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82703070:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82703094"))) PPC_WEAK_FUNC(sub_82703094);
PPC_FUNC_IMPL(__imp__sub_82703094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703098"))) PPC_WEAK_FUNC(sub_82703098);
PPC_FUNC_IMPL(__imp__sub_82703098) {
	PPC_FUNC_PROLOGUE();
	// b 0x82701488
	sub_82701488(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270309C"))) PPC_WEAK_FUNC(sub_8270309C);
PPC_FUNC_IMPL(__imp__sub_8270309C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827030A0"))) PPC_WEAK_FUNC(sub_827030A0);
PPC_FUNC_IMPL(__imp__sub_827030A0) {
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
	// bl 0x827014f8
	ctx.lr = 0x827030C0;
	sub_827014F8(ctx, base);
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

__attribute__((alias("__imp__sub_827030DC"))) PPC_WEAK_FUNC(sub_827030DC);
PPC_FUNC_IMPL(__imp__sub_827030DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827030E0"))) PPC_WEAK_FUNC(sub_827030E0);
PPC_FUNC_IMPL(__imp__sub_827030E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82703100
	if (!cr6.eq) goto loc_82703100;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_82703100:
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270310C"))) PPC_WEAK_FUNC(sub_8270310C);
PPC_FUNC_IMPL(__imp__sub_8270310C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703110"))) PPC_WEAK_FUNC(sub_82703110);
PPC_FUNC_IMPL(__imp__sub_82703110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703140
	if (cr6.eq) goto loc_82703140;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82703140:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703154"))) PPC_WEAK_FUNC(sub_82703154);
PPC_FUNC_IMPL(__imp__sub_82703154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703158"))) PPC_WEAK_FUNC(sub_82703158);
PPC_FUNC_IMPL(__imp__sub_82703158) {
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
	// bl 0x82701560
	ctx.lr = 0x82703170;
	sub_82701560(ctx, base);
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

__attribute__((alias("__imp__sub_82703190"))) PPC_WEAK_FUNC(sub_82703190);
PPC_FUNC_IMPL(__imp__sub_82703190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827031bc
	if (cr6.eq) goto loc_827031BC;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_827031BC:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827031D0"))) PPC_WEAK_FUNC(sub_827031D0);
PPC_FUNC_IMPL(__imp__sub_827031D0) {
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
	// bl 0x827015e8
	ctx.lr = 0x827031E8;
	sub_827015E8(ctx, base);
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

__attribute__((alias("__imp__sub_82703208"))) PPC_WEAK_FUNC(sub_82703208);
PPC_FUNC_IMPL(__imp__sub_82703208) {
	PPC_FUNC_PROLOGUE();
	// b 0x82701670
	sub_82701670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270320C"))) PPC_WEAK_FUNC(sub_8270320C);
PPC_FUNC_IMPL(__imp__sub_8270320C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703210"))) PPC_WEAK_FUNC(sub_82703210);
PPC_FUNC_IMPL(__imp__sub_82703210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,1072(r11)
	PPC_STORE_U8(r11.u32 + 1072, ctx.r10.u8);
	// stb r10,1073(r11)
	PPC_STORE_U8(r11.u32 + 1073, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703240"))) PPC_WEAK_FUNC(sub_82703240);
PPC_FUNC_IMPL(__imp__sub_82703240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x827016d8
	sub_827016D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270325C"))) PPC_WEAK_FUNC(sub_8270325C);
PPC_FUNC_IMPL(__imp__sub_8270325C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703260"))) PPC_WEAK_FUNC(sub_82703260);
PPC_FUNC_IMPL(__imp__sub_82703260) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r9,872(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,1072(r11)
	PPC_STORE_U8(r11.u32 + 1072, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703294"))) PPC_WEAK_FUNC(sub_82703294);
PPC_FUNC_IMPL(__imp__sub_82703294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703298"))) PPC_WEAK_FUNC(sub_82703298);
PPC_FUNC_IMPL(__imp__sub_82703298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x82701748
	sub_82701748(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827032B4"))) PPC_WEAK_FUNC(sub_827032B4);
PPC_FUNC_IMPL(__imp__sub_827032B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827032B8"))) PPC_WEAK_FUNC(sub_827032B8);
PPC_FUNC_IMPL(__imp__sub_827032B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r9,872(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,1073(r11)
	PPC_STORE_U8(r11.u32 + 1073, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827032EC"))) PPC_WEAK_FUNC(sub_827032EC);
PPC_FUNC_IMPL(__imp__sub_827032EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827032F0"))) PPC_WEAK_FUNC(sub_827032F0);
PPC_FUNC_IMPL(__imp__sub_827032F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x827017b8
	sub_827017B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270330C"))) PPC_WEAK_FUNC(sub_8270330C);
PPC_FUNC_IMPL(__imp__sub_8270330C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703310"))) PPC_WEAK_FUNC(sub_82703310);
PPC_FUNC_IMPL(__imp__sub_82703310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r6,r9
	ctx.r6.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// xori r9,r3,1
	ctx.r9.u64 = ctx.r3.u64 ^ 1;
	// xori r8,r11,1
	ctx.r8.u64 = r11.u64 ^ 1;
	// clrlwi r3,r10,24
	ctx.r3.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r4,r9,24
	ctx.r4.u64 = ctx.r9.u32 & 0xFF;
	// clrlwi r5,r8,24
	ctx.r5.u64 = ctx.r8.u32 & 0xFF;
	// b 0x82701828
	sub_82701828(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82703354"))) PPC_WEAK_FUNC(sub_82703354);
PPC_FUNC_IMPL(__imp__sub_82703354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703358"))) PPC_WEAK_FUNC(sub_82703358);
PPC_FUNC_IMPL(__imp__sub_82703358) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82703378
	if (!cr6.eq) goto loc_82703378;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_82703378:
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703384"))) PPC_WEAK_FUNC(sub_82703384);
PPC_FUNC_IMPL(__imp__sub_82703384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703388"))) PPC_WEAK_FUNC(sub_82703388);
PPC_FUNC_IMPL(__imp__sub_82703388) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827033a8
	if (!cr6.eq) goto loc_827033A8;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_827033A8:
	// lwz r11,80(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827033B4"))) PPC_WEAK_FUNC(sub_827033B4);
PPC_FUNC_IMPL(__imp__sub_827033B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827033B8"))) PPC_WEAK_FUNC(sub_827033B8);
PPC_FUNC_IMPL(__imp__sub_827033B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lhz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 184);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r10,196(r11)
	PPC_STORE_U32(r11.u32 + 196, ctx.r10.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r9,21888
	ctx.r5.s64 = ctx.r9.s64 + 21888;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82703410"))) PPC_WEAK_FUNC(sub_82703410);
PPC_FUNC_IMPL(__imp__sub_82703410) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703414"))) PPC_WEAK_FUNC(sub_82703414);
PPC_FUNC_IMPL(__imp__sub_82703414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703418"))) PPC_WEAK_FUNC(sub_82703418);
PPC_FUNC_IMPL(__imp__sub_82703418) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82701a08
	sub_82701A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82703428"))) PPC_WEAK_FUNC(sub_82703428);
PPC_FUNC_IMPL(__imp__sub_82703428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703444"))) PPC_WEAK_FUNC(sub_82703444);
PPC_FUNC_IMPL(__imp__sub_82703444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703448"))) PPC_WEAK_FUNC(sub_82703448);
PPC_FUNC_IMPL(__imp__sub_82703448) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703478
	if (cr6.eq) goto loc_82703478;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82703478:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270348C"))) PPC_WEAK_FUNC(sub_8270348C);
PPC_FUNC_IMPL(__imp__sub_8270348C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703490"))) PPC_WEAK_FUNC(sub_82703490);
PPC_FUNC_IMPL(__imp__sub_82703490) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10016(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r8,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r8.u32);
	// lwz r3,18508(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 18508);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,-10016(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10016);
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// b 0x826b94a8
	sub_826B94A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827034C4"))) PPC_WEAK_FUNC(sub_827034C4);
PPC_FUNC_IMPL(__imp__sub_827034C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827034C8"))) PPC_WEAK_FUNC(sub_827034C8);
PPC_FUNC_IMPL(__imp__sub_827034C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827034f8
	if (cr6.eq) goto loc_827034F8;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_827034F8:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270350C"))) PPC_WEAK_FUNC(sub_8270350C);
PPC_FUNC_IMPL(__imp__sub_8270350C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703510"))) PPC_WEAK_FUNC(sub_82703510);
PPC_FUNC_IMPL(__imp__sub_82703510) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270352C"))) PPC_WEAK_FUNC(sub_8270352C);
PPC_FUNC_IMPL(__imp__sub_8270352C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703530"))) PPC_WEAK_FUNC(sub_82703530);
PPC_FUNC_IMPL(__imp__sub_82703530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703560
	if (cr6.eq) goto loc_82703560;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82703560:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703574"))) PPC_WEAK_FUNC(sub_82703574);
PPC_FUNC_IMPL(__imp__sub_82703574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703578"))) PPC_WEAK_FUNC(sub_82703578);
PPC_FUNC_IMPL(__imp__sub_82703578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270359c
	if (cr6.eq) goto loc_8270359C;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_8270359C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827035B0"))) PPC_WEAK_FUNC(sub_827035B0);
PPC_FUNC_IMPL(__imp__sub_827035B0) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82701ac0
	ctx.lr = 0x827035D0;
	sub_82701AC0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
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
}

__attribute__((alias("__imp__sub_827035F0"))) PPC_WEAK_FUNC(sub_827035F0);
PPC_FUNC_IMPL(__imp__sub_827035F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,216(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 216, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82703610"))) PPC_WEAK_FUNC(sub_82703610);
PPC_FUNC_IMPL(__imp__sub_82703610) {
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
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x82701bd8
	ctx.lr = 0x82703640;
	sub_82701BD8(ctx, base);
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

__attribute__((alias("__imp__sub_8270365C"))) PPC_WEAK_FUNC(sub_8270365C);
PPC_FUNC_IMPL(__imp__sub_8270365C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703660"))) PPC_WEAK_FUNC(sub_82703660);
PPC_FUNC_IMPL(__imp__sub_82703660) {
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
	ctx.lr = 0x82703668;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703720
	if (cr6.eq) goto loc_82703720;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// bl 0x82714f10
	ctx.lr = 0x82703684;
	sub_82714F10(ctx, base);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82703690;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82703720
	if (!cr6.gt) goto loc_82703720;
loc_827036A0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x827036AC;
	sub_827010E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703714
	if (cr6.eq) goto loc_82703714;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701de0
	ctx.lr = 0x827036C4;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827036e4
	if (cr6.eq) goto loc_827036E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827036E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82703708
	goto loc_82703708;
loc_827036E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c388
	ctx.lr = 0x827036EC;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703708
	if (cr6.eq) goto loc_82703708;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270cc90
	ctx.lr = 0x82703708;
	sub_8270CC90(ctx, base);
loc_82703708:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e38
	ctx.lr = 0x82703710;
	sub_822A8E38(ctx, base);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_82703714:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x827036a0
	if (cr6.lt) goto loc_827036A0;
loc_82703720:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82703728"))) PPC_WEAK_FUNC(sub_82703728);
PPC_FUNC_IMPL(__imp__sub_82703728) {
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
	ctx.lr = 0x82703730;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827037e8
	if (cr6.eq) goto loc_827037E8;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// bl 0x82714f10
	ctx.lr = 0x8270374C;
	sub_82714F10(ctx, base);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701080
	ctx.lr = 0x82703758;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x827037e8
	if (!cr6.gt) goto loc_827037E8;
loc_82703768:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x827010e8
	ctx.lr = 0x82703774;
	sub_827010E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827037dc
	if (cr6.eq) goto loc_827037DC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82701de0
	ctx.lr = 0x8270378C;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827037ac
	if (cr6.eq) goto loc_827037AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827037A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827037d0
	goto loc_827037D0;
loc_827037AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c388
	ctx.lr = 0x827037B4;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827037d0
	if (cr6.eq) goto loc_827037D0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270cc90
	ctx.lr = 0x827037D0;
	sub_8270CC90(ctx, base);
loc_827037D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e50
	ctx.lr = 0x827037D8;
	sub_822A8E50(ctx, base);
	// lwz r5,-10016(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_827037DC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x82703768
	if (cr6.lt) goto loc_82703768;
loc_827037E8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827037F0"))) PPC_WEAK_FUNC(sub_827037F0);
PPC_FUNC_IMPL(__imp__sub_827037F0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x827037F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r31,-10016(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827038b8
	if (cr6.eq) goto loc_827038B8;
	// lhz r11,184(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 184);
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703848
	if (cr6.eq) goto loc_82703848;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82703824:
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82130588
	ctx.lr = 0x82703830;
	sub_82130588(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r31,-10016(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + -10016);
	// lhz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 184);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82703824
	if (cr6.lt) goto loc_82703824;
loc_82703848:
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// addi r11,r31,180
	r11.s64 = r31.s64 + 180;
	// bl 0x82130588
	ctx.lr = 0x82703854;
	sub_82130588(ctx, base);
	// stw r28,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r28.u32);
	// sth r28,184(r31)
	PPC_STORE_U16(r31.u32 + 184, r28.u16);
	// sth r28,186(r31)
	PPC_STORE_U16(r31.u32 + 186, r28.u16);
	// lwz r11,-10016(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10016);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82703898
	if (!cr6.eq) goto loc_82703898;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,212(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 212, temp.u32);
	// stw r10,192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 192, ctx.r10.u32);
	// stw r28,200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 200, r28.u32);
	// stw r28,196(r8)
	PPC_STORE_U32(ctx.r8.u32 + 196, r28.u32);
	// lwz r11,-10016(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10016);
loc_82703898:
	// stw r28,204(r11)
	PPC_STORE_U32(r11.u32 + 204, r28.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r11,-10016(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10016);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r28,208(r11)
	PPC_STORE_U32(r11.u32 + 208, r28.u32);
	// addi r5,r10,22068
	ctx.r5.s64 = ctx.r10.s64 + 22068;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x827038B8;
	sub_82130000(ctx, base);
loc_827038B8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_827038C0"))) PPC_WEAK_FUNC(sub_827038C0);
PPC_FUNC_IMPL(__imp__sub_827038C0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,47
	ctx.r4.s64 = 47;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x827038F4;
	sub_82641CB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x82703908;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,800(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270391C;
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

__attribute__((alias("__imp__sub_82703934"))) PPC_WEAK_FUNC(sub_82703934);
PPC_FUNC_IMPL(__imp__sub_82703934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703938"))) PPC_WEAK_FUNC(sub_82703938);
PPC_FUNC_IMPL(__imp__sub_82703938) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,46
	ctx.r4.s64 = 46;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8270396C;
	sub_82641CB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x82703980;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,800(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82703994;
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

__attribute__((alias("__imp__sub_827039AC"))) PPC_WEAK_FUNC(sub_827039AC);
PPC_FUNC_IMPL(__imp__sub_827039AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827039B0"))) PPC_WEAK_FUNC(sub_827039B0);
PPC_FUNC_IMPL(__imp__sub_827039B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x827039B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703b98
	if (cr6.eq) goto loc_82703B98;
	// bl 0x82256058
	ctx.lr = 0x827039D0;
	sub_82256058(ctx, base);
	// bl 0x82256168
	ctx.lr = 0x827039D4;
	sub_82256168(ctx, base);
	// li r26,1
	r26.s64 = 1;
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x827039f0
	if (!cr6.eq) goto loc_827039F0;
	// bl 0x82256058
	ctx.lr = 0x827039E4;
	sub_82256058(ctx, base);
	// stb r26,3775(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3775, r26.u8);
	// bl 0x82256058
	ctx.lr = 0x827039EC;
	sub_82256058(ctx, base);
	// stb r26,3773(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3773, r26.u8);
loc_827039F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10016(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// bl 0x827008f0
	ctx.lr = 0x827039FC;
	sub_827008F0(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82703A00;
	sub_82256058(ctx, base);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82703a68
	if (!cr6.eq) goto loc_82703A68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82701080
	ctx.lr = 0x82703A18;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82703a68
	if (!cr6.gt) goto loc_82703A68;
loc_82703A28:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827010e8
	ctx.lr = 0x82703A34;
	sub_827010E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82703a5c
	if (cr6.eq) goto loc_82703A5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82701de0
	ctx.lr = 0x82703A48;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82703a5c
	if (!cr6.eq) goto loc_82703A5C;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x822a8e50
	ctx.lr = 0x82703A58;
	sub_822A8E50(ctx, base);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_82703A5C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x82703a28
	if (cr6.lt) goto loc_82703A28;
loc_82703A68:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82703aa4
	if (cr6.eq) goto loc_82703AA4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82703aa4
	if (cr6.eq) goto loc_82703AA4;
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82703aa4
	if (cr6.eq) goto loc_82703AA4;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_82703AA4:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82703aec
	if (cr6.eq) goto loc_82703AEC;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82703aec
	if (cr6.eq) goto loc_82703AEC;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// lfs f13,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82703adc
	if (cr6.lt) goto loc_82703ADC;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82703ADC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bne cr6,0x82703af0
	if (!cr6.eq) goto loc_82703AF0;
loc_82703AEC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82703AF0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32692(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32692);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,40(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// stfs f12,36(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,40(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82703B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82703b7c
	if (cr6.eq) goto loc_82703B7C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f1,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x82703B78;
	sub_822B0F10(ctx, base);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_82703B7C:
	// stw r27,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r27.u32);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// stb r27,64(r11)
	PPC_STORE_U8(r11.u32 + 64, r27.u8);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// stb r27,56(r11)
	PPC_STORE_U8(r11.u32 + 56, r27.u8);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// stw r27,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r27.u32);
loc_82703B98:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82703BA0"))) PPC_WEAK_FUNC(sub_82703BA0);
PPC_FUNC_IMPL(__imp__sub_82703BA0) {
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
	ctx.lr = 0x82703BA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,-10016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703c64
	if (cr6.eq) goto loc_82703C64;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// bl 0x82714f10
	ctx.lr = 0x82703BC8;
	sub_82714F10(ctx, base);
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// bl 0x82701080
	ctx.lr = 0x82703BD0;
	sub_82701080(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82703c64
	if (!cr6.gt) goto loc_82703C64;
loc_82703BE0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x82703BEC;
	sub_827010E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703c58
	if (cr6.eq) goto loc_82703C58;
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82703c58
	if (!cr6.eq) goto loc_82703C58;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// bl 0x82701de0
	ctx.lr = 0x82703C14;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82703c34
	if (cr6.eq) goto loc_82703C34;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703C30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82703c58
	goto loc_82703C58;
loc_82703C34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c388
	ctx.lr = 0x82703C3C;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703c58
	if (cr6.eq) goto loc_82703C58;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270cc90
	ctx.lr = 0x82703C58;
	sub_8270CC90(ctx, base);
loc_82703C58:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x82703be0
	if (cr6.lt) goto loc_82703BE0;
loc_82703C64:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82703C6C"))) PPC_WEAK_FUNC(sub_82703C6C);
PPC_FUNC_IMPL(__imp__sub_82703C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703C70"))) PPC_WEAK_FUNC(sub_82703C70);
PPC_FUNC_IMPL(__imp__sub_82703C70) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82703cf0
	if (cr6.eq) goto loc_82703CF0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82703cf0
	if (cr6.eq) goto loc_82703CF0;
	// bl 0x827022c8
	ctx.lr = 0x82703CA0;
	sub_827022C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703cf0
	if (cr6.eq) goto loc_82703CF0;
	// bl 0x82710598
	ctx.lr = 0x82703CB0;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703cf0
	if (cr6.eq) goto loc_82703CF0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
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
loc_82703CF0:
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

__attribute__((alias("__imp__sub_82703D08"))) PPC_WEAK_FUNC(sub_82703D08);
PPC_FUNC_IMPL(__imp__sub_82703D08) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,-10016(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82703de0
	if (cr6.eq) goto loc_82703DE0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82703de0
	if (cr6.eq) goto loc_82703DE0;
	// lwz r11,196(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82703d4c
	if (cr6.eq) goto loc_82703D4C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82703d50
	if (!cr6.eq) goto loc_82703D50;
loc_82703D4C:
	// li r11,1
	r11.s64 = 1;
loc_82703D50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703d80
	if (cr6.eq) goto loc_82703D80;
	// lwz r11,200(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 200);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x82703d80
	if (!cr6.eq) goto loc_82703D80;
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
loc_82703D80:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x827022c8
	ctx.lr = 0x82703D88;
	sub_827022C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703de0
	if (cr6.eq) goto loc_82703DE0;
	// bl 0x82710598
	ctx.lr = 0x82703D98;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82703de0
	if (cr6.eq) goto loc_82703DE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82703dc8
	if (!cr6.lt) goto loc_82703DC8;
	// li r11,0
	r11.s64 = 0;
loc_82703DC8:
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
loc_82703DE0:
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

__attribute__((alias("__imp__sub_82703DF8"))) PPC_WEAK_FUNC(sub_82703DF8);
PPC_FUNC_IMPL(__imp__sub_82703DF8) {
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
	ctx.lr = 0x82703E00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703e90
	if (cr6.eq) goto loc_82703E90;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r29,-32130
	r29.s64 = -2105671680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,984(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 984);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82703e90
	if (cr6.eq) goto loc_82703E90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18180
	ctx.r10.s64 = r11.s64 + 18180;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82703e90
	if (!cr6.eq) goto loc_82703E90;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82703e84
	if (cr6.eq) goto loc_82703E84;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,984(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 984);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82703e90
	if (!cr6.eq) goto loc_82703E90;
loc_82703E84:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82703E90:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82701ea0
	ctx.lr = 0x82703E9C;
	sub_82701EA0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703EB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82703f30
	if (cr6.eq) goto loc_82703F30;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703ED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82703f20
	if (cr6.eq) goto loc_82703F20;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82703f30
	if (cr6.eq) goto loc_82703F30;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82703F20:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r5,1
	ctx.r5.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82703F30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82703F30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82703F3C"))) PPC_WEAK_FUNC(sub_82703F3C);
PPC_FUNC_IMPL(__imp__sub_82703F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82703F40"))) PPC_WEAK_FUNC(sub_82703F40);
PPC_FUNC_IMPL(__imp__sub_82703F40) {
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
	ctx.lr = 0x82703F48;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82703f90
	if (!cr6.gt) goto loc_82703F90;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_82703F64:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82703f84
	if (cr6.eq) goto loc_82703F84;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r8,656(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 656);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82703f84
	if (!cr6.eq) goto loc_82703F84;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82703F84:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82703f64
	if (!cr0.eq) goto loc_82703F64;
loc_82703F90:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82703fcc
	if (!cr6.eq) goto loc_82703FCC;
	// bl 0x82256058
	ctx.lr = 0x82703FA4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82703fcc
	if (cr6.eq) goto loc_82703FCC;
	// bl 0x82256058
	ctx.lr = 0x82703FB0;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82703fcc
	if (cr0.eq) goto loc_82703FCC;
	// bl 0x82256058
	ctx.lr = 0x82703FBC;
	sub_82256058(ctx, base);
	// lwz r11,3148(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82703fd0
	if (cr6.eq) goto loc_82703FD0;
loc_82703FCC:
	// li r11,0
	r11.s64 = 0;
loc_82703FD0:
	// lbz r10,56(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 56);
	// clrlwi r25,r11,24
	r25.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82704018
	if (!cr6.eq) goto loc_82704018;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704010
	if (cr6.eq) goto loc_82704010;
	// bl 0x823bbf70
	ctx.lr = 0x82703FF4;
	sub_823BBF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82704018
	if (!cr6.eq) goto loc_82704018;
	// bl 0x823bbf80
	ctx.lr = 0x82704004;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82704018
	if (!cr6.eq) goto loc_82704018;
loc_82704010:
	// li r11,0
	r11.s64 = 0;
	// b 0x8270401c
	goto loc_8270401C;
loc_82704018:
	// li r11,1
	r11.s64 = 1;
loc_8270401C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// clrlwi r26,r11,24
	r26.u64 = r11.u32 & 0xFF;
	// addi r9,r10,18180
	ctx.r9.s64 = ctx.r10.s64 + 18180;
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x8270403c
	if (!cr6.lt) goto loc_8270403C;
	// li r11,0
	r11.s64 = 0;
loc_8270403C:
	// lhz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82704128
	if (cr6.eq) goto loc_82704128;
	// li r31,0
	r31.s64 = 0;
loc_82704054:
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704114
	if (cr6.eq) goto loc_82704114;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lbz r11,872(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827040e4
	if (cr6.eq) goto loc_827040E4;
	// lwz r11,1152(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827040e4
	if (!cr6.eq) goto loc_827040E4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82701de0
	ctx.lr = 0x82704088;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827040e4
	if (!cr6.eq) goto loc_827040E4;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827040bc
	if (cr6.eq) goto loc_827040BC;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x822a8e68
	ctx.lr = 0x827040A4;
	sub_822A8E68(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x827040e4
	if (cr6.eq) goto loc_827040E4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x822a8e20
	ctx.lr = 0x827040B8;
	sub_822A8E20(ctx, base);
	// b 0x827040e4
	goto loc_827040E4;
loc_827040BC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827040e4
	if (!cr6.eq) goto loc_827040E4;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x822a8e68
	ctx.lr = 0x827040D0;
	sub_822A8E68(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827040e4
	if (cr6.eq) goto loc_827040E4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x822a8e50
	ctx.lr = 0x827040E4;
	sub_822A8E50(ctx, base);
loc_827040E4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,656(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82704104
	if (!cr6.eq) goto loc_82704104;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704114
	if (cr6.eq) goto loc_82704114;
loc_82704104:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82704114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82704114:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82704054
	if (cr6.lt) goto loc_82704054;
loc_82704128:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82704130"))) PPC_WEAK_FUNC(sub_82704130);
PPC_FUNC_IMPL(__imp__sub_82704130) {
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
	ctx.lr = 0x82704138;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82703f40
	ctx.lr = 0x82704144;
	sub_82703F40(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827041e8
	if (cr6.eq) goto loc_827041E8;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_82704160:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827041d4
	if (cr6.eq) goto loc_827041D4;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,1152(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1152);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x827041c4
	if (!cr6.eq) goto loc_827041C4;
	// lwz r11,656(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827041c4
	if (!cr6.eq) goto loc_827041C4;
	// lwz r3,17892(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17892);
	// bl 0x822b61b0
	ctx.lr = 0x82704194;
	sub_822B61B0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827041b8
	if (cr6.eq) goto loc_827041B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827041B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827041B8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r27,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r27.u32);
	// b 0x827041d4
	goto loc_827041D4;
loc_827041C4:
	// lwz r3,48(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827041d4
	if (cr6.eq) goto loc_827041D4;
	// bl 0x82331648
	ctx.lr = 0x827041D4;
	sub_82331648(ctx, base);
loc_827041D4:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82704160
	if (cr6.lt) goto loc_82704160;
loc_827041E8:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704220
	if (cr6.eq) goto loc_82704220;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_827041FC:
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x827041fc
	if (cr6.lt) goto loc_827041FC;
loc_82704220:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82704228"))) PPC_WEAK_FUNC(sub_82704228);
PPC_FUNC_IMPL(__imp__sub_82704228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82704230;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270428c
	if (cr6.eq) goto loc_8270428C;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270427c
	if (cr6.eq) goto loc_8270427C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82704280
	if (cr6.eq) goto loc_82704280;
loc_8270427C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82704280:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827042f0
	if (!cr6.eq) goto loc_827042F0;
loc_8270428C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827042bc
	if (cr6.eq) goto loc_827042BC;
	// bl 0x823bbf70
	ctx.lr = 0x827042A0;
	sub_823BBF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827042f0
	if (!cr6.eq) goto loc_827042F0;
	// bl 0x823bbf80
	ctx.lr = 0x827042B0;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827042f0
	if (!cr6.eq) goto loc_827042F0;
loc_827042BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827042e0
	if (cr6.eq) goto loc_827042E0;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4994
	ctx.r9.u64 = ctx.r10.u64 | 4994;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827042f0
	if (!cr6.eq) goto loc_827042F0;
loc_827042E0:
	// bl 0x82207e88
	ctx.lr = 0x827042E4;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704300
	if (cr6.eq) goto loc_82704300;
loc_827042F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82704300:
	// clrlwi r20,r28,24
	r20.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8270431c
	if (cr6.eq) goto loc_8270431C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6732(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6732);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827042f0
	if (!cr6.eq) goto loc_827042F0;
loc_8270431C:
	// lis r25,-32121
	r25.s64 = -2105081856;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82704334
	if (cr6.eq) goto loc_82704334;
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x822043c8
	ctx.lr = 0x82704334;
	sub_822043C8(ctx, base);
loc_82704334:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,4(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// li r29,-1
	r29.s64 = -1;
	// mr r21,r22
	r21.u64 = r22.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82704400
	if (cr6.eq) goto loc_82704400;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827022c8
	ctx.lr = 0x82704358;
	sub_827022C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827043c0
	if (cr6.eq) goto loc_827043C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82704374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bne cr6,0x82704390
	if (!cr6.eq) goto loc_82704390;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82704390:
	// bge cr6,0x827043a0
	if (!cr6.lt) goto loc_827043A0;
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827042f0
	if (cr6.eq) goto loc_827042F0;
loc_827043A0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f31,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	f31.f64 = double(temp.f32);
	// li r21,1
	r21.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827043C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827043C0:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82704400
	if (cr6.eq) goto loc_82704400;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827043d8
	if (cr6.eq) goto loc_827043D8;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x82704400
	if (!cr6.eq) goto loc_82704400;
loc_827043D8:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,22120
	ctx.r4.s64 = ctx.r10.s64 + 22120;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82704400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82704400:
	// lwz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82704458
	if (cr6.eq) goto loc_82704458;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82701de0
	ctx.lr = 0x82704414;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82704434
	if (cr6.eq) goto loc_82704434;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82704430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82704458
	goto loc_82704458;
loc_82704434:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8270c388
	ctx.lr = 0x8270443C;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704458
	if (cr6.eq) goto loc_82704458;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8270cc90
	ctx.lr = 0x82704458;
	sub_8270CC90(ctx, base);
loc_82704458:
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r30,r22
	r30.u64 = r22.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
loc_82704470:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 20);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82704494
	if (cr6.eq) goto loc_82704494;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// blt cr6,0x82704470
	if (cr6.lt) goto loc_82704470;
	// b 0x827044d8
	goto loc_827044D8;
loc_82704494:
	// add r10,r31,r27
	ctx.r10.u64 = r31.u64 + r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// rlwinm r30,r10,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x827044B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,44(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// lwzx r30,r11,r30
	r30.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bne cr6,0x827044d8
	if (!cr6.eq) goto loc_827044D8;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// stw r22,92(r8)
	PPC_STORE_U32(ctx.r8.u32 + 92, r22.u32);
loc_827044D8:
	// clrlwi r28,r3,24
	r28.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82704758
	if (cr6.eq) goto loc_82704758;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82704604
	if (cr6.eq) goto loc_82704604;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// blt cr6,0x82704504
	if (cr6.lt) goto loc_82704504;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,22104
	ctx.r3.s64 = r11.s64 + 22104;
	// bl 0x8268b898
	ctx.lr = 0x82704504;
	sub_8268B898(ctx, base);
loc_82704504:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// ble cr6,0x8270452c
	if (!cr6.gt) goto loc_8270452C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82704520;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// ble cr6,0x8270452c
	if (!cr6.gt) goto loc_8270452C;
	// stfs f31,104(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
loc_8270452C:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// stw r22,52(r26)
	PPC_STORE_U32(r26.u32 + 52, r22.u32);
	// beq cr6,0x82704604
	if (cr6.eq) goto loc_82704604;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x827045a4
	if (cr6.eq) goto loc_827045A4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,-24400(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24400);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x8270456c
	if (!cr6.eq) goto loc_8270456C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x8270456C;
	sub_821F1498(ctx, base);
loc_8270456C:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82704584
	if (!cr6.gt) goto loc_82704584;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82704588
	goto loc_82704588;
loc_82704584:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_82704588:
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// bl 0x8270c2d8
	ctx.lr = 0x82704590;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x827045A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827045A4:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82704604
	if (cr6.eq) goto loc_82704604;
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x827045C4;
	sub_82641CB0(ctx, base);
	// addi r31,r3,2624
	r31.s64 = ctx.r3.s64 + 2624;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// blt cr6,0x827045f8
	if (cr6.lt) goto loc_827045F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x827045e8
	if (cr6.eq) goto loc_827045E8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82650ff0
	ctx.lr = 0x827045E0;
	sub_82650FF0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x827045fc
	goto loc_827045FC;
loc_827045E8:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82650ff0
	ctx.lr = 0x827045F0;
	sub_82650FF0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x827045fc
	goto loc_827045FC;
loc_827045F8:
	// li r4,2
	ctx.r4.s64 = 2;
loc_827045FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82650ff0
	ctx.lr = 0x82704604;
	sub_82650FF0(ctx, base);
loc_82704604:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8270474c
	if (cr6.eq) goto loc_8270474C;
	// stb r22,64(r26)
	PPC_STORE_U8(r26.u32 + 64, r22.u8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r22,68(r26)
	PPC_STORE_U32(r26.u32 + 68, r22.u32);
	// stw r22,72(r26)
	PPC_STORE_U32(r26.u32 + 72, r22.u32);
	// stw r22,76(r26)
	PPC_STORE_U32(r26.u32 + 76, r22.u32);
	// beq cr6,0x8270462c
	if (cr6.eq) goto loc_8270462C;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// b 0x82704630
	goto loc_82704630;
loc_8270462C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82704630:
	// stw r11,80(r26)
	PPC_STORE_U32(r26.u32 + 80, r11.u32);
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// bne cr6,0x82704664
	if (!cr6.eq) goto loc_82704664;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82704664
	if (cr6.eq) goto loc_82704664;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8270465c
	if (!cr6.gt) goto loc_8270465C;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82704660
	goto loc_82704660;
loc_8270465C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82704660:
	// stw r11,84(r26)
	PPC_STORE_U32(r26.u32 + 84, r11.u32);
loc_82704664:
	// lwz r11,8(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827046dc
	if (cr6.eq) goto loc_827046DC;
	// addi r10,r27,-1
	ctx.r10.s64 = r27.s64 + -1;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bgt cr6,0x827046dc
	if (cr6.gt) goto loc_827046DC;
	// lis r12,-32144
	r12.s64 = -2106589184;
	// addi r12,r12,18068
	r12.s64 = r12.s64 + 18068;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_827046A4;
	case 1:
		goto loc_827046B4;
	case 2:
		goto loc_827046B4;
	case 3:
		goto loc_827046C4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,18084(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + 18084);
	// lwz r19,18100(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + 18100);
	// lwz r19,18100(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + 18100);
	// lwz r19,18116(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + 18116);
loc_827046A4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// b 0x827046cc
	goto loc_827046CC;
loc_827046B4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// b 0x827046cc
	goto loc_827046CC;
loc_827046C4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r10,-13624(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13624);
loc_827046CC:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bge cr6,0x827046dc
	if (!cr6.lt) goto loc_827046DC;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_827046DC:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8270474c
	if (cr6.eq) goto loc_8270474C;
	// lwz r11,4(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270474c
	if (cr6.eq) goto loc_8270474C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82704704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270474c
	if (cr6.eq) goto loc_8270474C;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// beq cr6,0x8270472c
	if (cr6.eq) goto loc_8270472C;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270474c
	if (!cr6.eq) goto loc_8270474C;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// ble cr6,0x8270474c
	if (!cr6.gt) goto loc_8270474C;
loc_8270472C:
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
	// bne cr6,0x8270474c
	if (!cr6.eq) goto loc_8270474C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82700108
	ctx.lr = 0x8270474C;
	sub_82700108(ctx, base);
loc_8270474C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8270475c
	if (!cr6.eq) goto loc_8270475C;
loc_82704758:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_8270475C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82704768"))) PPC_WEAK_FUNC(sub_82704768);
PPC_FUNC_IMPL(__imp__sub_82704768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91d8
	ctx.lr = 0x82704770;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d0
	ctx.lr = 0x82704778;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82704f68
	if (cr6.eq) goto loc_82704F68;
	// bl 0x822a39c0
	ctx.lr = 0x827047A8;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704f68
	if (cr6.eq) goto loc_82704F68;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82704f68
	if (cr6.eq) goto loc_82704F68;
	// bl 0x822a8108
	ctx.lr = 0x827047C8;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lhz r9,176(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 176);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r22,-1
	r22.s64 = -1;
	// li r21,-1
	r21.s64 = -1;
	// lvx128 v127,r3,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,0
	r28.s64 = 0;
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f27,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f27.f64 = double(temp.f32);
	// beq cr6,0x82704a10
	if (cr6.eq) goto loc_82704A10;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f31.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f30,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f30.f64 = double(temp.f32);
	// lfs f29,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// clrlwi r25,r30,24
	r25.u64 = r30.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// addi r26,r11,22128
	r26.s64 = r11.s64 + 22128;
	// lfs f26,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f26.f64 = double(temp.f32);
loc_8270481C:
	// lwz r11,172(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// add r30,r11,r27
	r30.u64 = r11.u64 + r27.u64;
	// beq cr6,0x82704838
	if (cr6.eq) goto loc_82704838;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827049f4
	if (!cr6.eq) goto loc_827049F4;
loc_82704838:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827049f4
	if (cr6.eq) goto loc_827049F4;
	// li r31,0
	r31.s64 = 0;
loc_8270484C:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// fmr f0,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = f26.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwzx r6,r11,r31
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lhz r7,8(r6)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r6.u32 + 8);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// blt cr6,0x82704934
	if (cr6.lt) goto loc_82704934;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_82704884:
	// lfs f13,-4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// lfs f10,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f4,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f8,f30,f10
	ctx.f8.f64 = double(float(f30.f64 - ctx.f10.f64));
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f2,f30,f4
	ctx.f2.f64 = double(float(f30.f64 - ctx.f4.f64));
	// fsubs f9,f31,f11
	ctx.f9.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f7,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f7.f64 = double(temp.f32);
	// lfs f1,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f5,f29,f7
	ctx.f5.f64 = double(float(f29.f64 - ctx.f7.f64));
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f29,f1
	ctx.f11.f64 = double(float(f29.f64 - ctx.f1.f64));
	// lfs f4,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f7,f31,f13
	ctx.f7.f64 = double(float(f31.f64 - ctx.f13.f64));
	// lfs f1,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f13,f29,f4
	ctx.f13.f64 = double(float(f29.f64 - ctx.f4.f64));
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f4,f31,f1
	ctx.f4.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lfs f10,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f3,f31,f6
	ctx.f3.f64 = double(float(f31.f64 - ctx.f6.f64));
	// fmuls f12,f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// fmuls f1,f8,f8
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmuls f8,f2,f2
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// fsubs f6,f30,f10
	ctx.f6.f64 = double(float(f30.f64 - ctx.f10.f64));
	// lfs f10,40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f29,f10
	ctx.f10.f64 = double(float(f29.f64 - ctx.f10.f64));
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// fmadds f2,f9,f9,f12
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f12.f64));
	// fmadds f1,f3,f3,f1
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f1.f64));
	// fmadds f12,f7,f7,f8
	ctx.f12.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fmuls f6,f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmadds f8,f5,f5,f2
	ctx.f8.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fmadds f7,f11,f11,f1
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f1.f64));
	// fmadds f9,f4,f4,f6
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f6.f64));
	// fmadds f6,f13,f13,f12
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fadds f4,f8,f0
	ctx.f4.f64 = double(float(ctx.f8.f64 + f0.f64));
	// fmadds f5,f10,f10,f9
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fadds f3,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 + ctx.f4.f64));
	// fadds f2,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f3.f64));
	// fadds f0,f5,f2
	f0.f64 = double(float(ctx.f5.f64 + ctx.f2.f64));
	// bne 0x82704884
	if (!cr0.eq) goto loc_82704884;
loc_82704934:
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// bge cr6,0x82704980
	if (!cr6.lt) goto loc_82704980;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// rlwinm r9,r8,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r10,r8,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_8270494C:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f29,f9
	ctx.f8.f64 = double(float(f29.f64 - ctx.f9.f64));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fadds f0,f5,f0
	f0.f64 = double(float(ctx.f5.f64 + f0.f64));
	// bne 0x8270494c
	if (!cr0.eq) goto loc_8270494C;
loc_82704980:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x827049e0
	if (!cr6.gt) goto loc_827049E0;
	// extsw r11,r7
	r11.s64 = ctx.r7.s32;
	// lwz r6,0(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,3
	ctx.r3.s64 = 3;
	// fdivs f28,f0,f11
	f28.f64 = double(float(f0.f64 / ctx.f11.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// stfd f1,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f1.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// bl 0x82130000
	ctx.lr = 0x827049C4;
	sub_82130000(ctx, base);
	// fcmpu cr6,f27,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f26.f64);
	// blt cr6,0x827049d4
	if (cr6.lt) goto loc_827049D4;
	// fcmpu cr6,f27,f28
	cr6.compare(f27.f64, f28.f64);
	// ble cr6,0x827049e0
	if (!cr6.gt) goto loc_827049E0;
loc_827049D4:
	// fmr f27,f28
	ctx.fpscr.disableFlushMode();
	f27.f64 = f28.f64;
	// mr r22,r28
	r22.u64 = r28.u64;
	// mr r21,r29
	r21.u64 = r29.u64;
loc_827049E0:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8270484c
	if (cr6.lt) goto loc_8270484C;
loc_827049F4:
	// lhz r11,176(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 176);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,20
	r27.s64 = r27.s64 + 20;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8270481c
	if (cr6.lt) goto loc_8270481C;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// bge cr6,0x82704a18
	if (!cr6.lt) goto loc_82704A18;
loc_82704A10:
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x82704f6c
	goto loc_82704F6C;
loc_82704A18:
	// rlwinm r11,r22,2,0,29
	r11.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,172(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// add r11,r22,r11
	r11.u64 = r22.u64 + r11.u64;
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r26,r10
	r11.u64 = r26.u64 + ctx.r10.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82704f60
	if (!cr6.eq) goto loc_82704F60;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r21,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r10
	r27.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lhz r31,8(r27)
	r31.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82704f60
	if (!cr6.gt) goto loc_82704F60;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x822a8108
	ctx.lr = 0x82704A58;
	sub_822A8108(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// clrlwi r7,r23,24
	ctx.r7.u64 = r23.u32 & 0xFF;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,0
	r29.s64 = 0;
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f27.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 + f27.f64));
	// fadds f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 + f27.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// beq cr6,0x82704c50
	if (cr6.eq) goto loc_82704C50;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lvx128 v2,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82700578
	ctx.lr = 0x82704ABC;
	sub_82700578(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82704acc
	if (cr6.eq) goto loc_82704ACC;
	// li r23,0
	r23.s64 = 0;
loc_82704ACC:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82704c50
	if (cr6.eq) goto loc_82704C50;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// li r30,0
	r30.s64 = 0;
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// twllei r31,0
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r3,r11,1
	ctx.r3.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r3,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// divw r7,r3,r31
	ctx.r7.s32 = ctx.r3.s32 / r31.s32;
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// mullw r4,r7,r31
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(r31.s32);
	// andc r10,r31,r5
	ctx.r10.u64 = r31.u64 & ~ctx.r5.u64;
	// subf r29,r4,r3
	r29.s64 = ctx.r3.s64 - ctx.r4.s64;
	// twlgei r10,-1
	// ble cr6,0x82704bd0
	if (!cr6.gt) goto loc_82704BD0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r11,-13624
	r28.s64 = r11.s64 + -13624;
	// lfs f28,396(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 396);
	f28.f64 = double(temp.f32);
loc_82704B40:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f13,f28,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f28.f64 * f28.f64));
	// lvx128 v62,r10,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f8,f12,f31
	ctx.f8.f64 = double(float(ctx.f12.f64 - f31.f64));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f7,f11,f29
	ctx.f7.f64 = double(float(ctx.f11.f64 - f29.f64));
	// fadds f0,f10,f27
	f0.f64 = double(float(ctx.f10.f64 + f27.f64));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fsubs f9,f0,f30
	ctx.f9.f64 = double(float(f0.f64 - f30.f64));
	// fmuls f6,f9,f9
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// fcmpu cr6,f4,f13
	cr6.compare(ctx.f4.f64, ctx.f13.f64);
	// bgt cr6,0x82704bb0
	if (cr6.gt) goto loc_82704BB0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lvx128 v2,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82700578
	ctx.lr = 0x82704BA0;
	sub_82700578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82704bd0
	if (cr6.eq) goto loc_82704BD0;
	// lfs f28,396(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 396);
	f28.f64 = double(temp.f32);
loc_82704BB0:
	// addi r5,r31,-1
	ctx.r5.s64 = r31.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// bl 0x82250268
	ctx.lr = 0x82704BC0;
	sub_82250268(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// blt cr6,0x82704b40
	if (cr6.lt) goto loc_82704B40;
loc_82704BD0:
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// bne cr6,0x82704c50
	if (!cr6.eq) goto loc_82704C50;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82704c44
	if (!cr6.gt) goto loc_82704C44;
loc_82704BE4:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// rlwinm r10,r29,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lvx128 v61,r10,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 + f27.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v2,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82700578
	ctx.lr = 0x82704C18;
	sub_82700578(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82704c44
	if (cr6.eq) goto loc_82704C44;
	// addi r5,r31,-1
	ctx.r5.s64 = r31.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// bl 0x82250268
	ctx.lr = 0x82704C34;
	sub_82250268(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// blt cr6,0x82704be4
	if (cr6.lt) goto loc_82704BE4;
loc_82704C44:
	// cmpw cr6,r30,r31
	cr6.compare<int32_t>(r30.s32, r31.s32, xer);
	// bne cr6,0x82704c50
	if (!cr6.eq) goto loc_82704C50;
	// li r23,0
	r23.s64 = 0;
loc_82704C50:
	// clrlwi r28,r23,24
	r28.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82704de0
	if (!cr6.eq) goto loc_82704DE0;
	// lwz r7,4(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r10,r31,-1
	ctx.r10.s64 = r31.s64 + -1;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f29,f0
	ctx.f13.f64 = double(float(f29.f64 - f0.f64));
	// lfs f12,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 - ctx.f12.f64));
	// lfs f10,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f30,f10
	ctx.f9.f64 = double(float(f30.f64 - ctx.f10.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f0,f9,f9,f7
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// blt cr6,0x82704d8c
	if (cr6.lt) goto loc_82704D8C;
	// addi r6,r31,-3
	ctx.r6.s64 = r31.s64 + -3;
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r9,r7,24
	ctx.r9.s64 = ctx.r7.s64 + 24;
	// addi r10,r7,40
	ctx.r10.s64 = ctx.r7.s64 + 40;
loc_82704CA4:
	// lfs f13,-8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f13,f8,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82704cd8
	if (!cr6.lt) goto loc_82704CD8;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82704CD8:
	// lfs f13,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f13,f8,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82704d0c
	if (!cr6.lt) goto loc_82704D0C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// addi r29,r8,-1
	r29.s64 = ctx.r8.s64 + -1;
loc_82704D0C:
	// lfs f13,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f13,f8,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82704d40
	if (!cr6.lt) goto loc_82704D40;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
loc_82704D40:
	// lfs f13,40(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f13,f8,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82704d74
	if (!cr6.lt) goto loc_82704D74;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// addi r29,r8,1
	r29.s64 = ctx.r8.s64 + 1;
loc_82704D74:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x82704ca4
	if (cr6.lt) goto loc_82704CA4;
loc_82704D8C:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bge cr6,0x82704de0
	if (!cr6.lt) goto loc_82704DE0;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_82704D9C:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f31,f11
	ctx.f10.f64 = double(float(f31.f64 - ctx.f11.f64));
	// lfs f9,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f30,f9
	ctx.f8.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fmuls f7,f12,f12
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f6,f10,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f13,f8,f8,f6
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82704dd0
	if (!cr6.lt) goto loc_82704DD0;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82704DD0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// blt cr6,0x82704d9c
	if (cr6.lt) goto loc_82704D9C;
loc_82704DE0:
	// lwz r3,68(r20)
	ctx.r3.u64 = PPC_LOAD_U32(r20.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82704e1c
	if (cr6.eq) goto loc_82704E1C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,-5460(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82704E04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82704e1c
	if (cr6.eq) goto loc_82704E1C;
	// lwz r31,68(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 68);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82704e80
	if (!cr6.eq) goto loc_82704E80;
loc_82704E1C:
	// lwz r11,40(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82704e70
	if (cr6.eq) goto loc_82704E70;
	// addi r30,r24,32
	r30.s64 = r24.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702698
	ctx.lr = 0x82704E34;
	sub_82702698(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// bl 0x82703df8
	ctx.lr = 0x82704E54;
	sub_82703DF8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82704e78
	if (!cr6.eq) goto loc_82704E78;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702700
	ctx.lr = 0x82704E70;
	sub_82702700(ctx, base);
loc_82704E70:
	// li r3,3
	ctx.r3.s64 = 3;
	// b 0x82704f6c
	goto loc_82704F6C;
loc_82704E78:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82704e70
	if (cr6.eq) goto loc_82704E70;
loc_82704E80:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82701ea0
	ctx.lr = 0x82704E8C;
	sub_82701EA0(ctx, base);
	// lwz r11,172(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// li r8,1
	ctx.r8.s64 = 1;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// stw r20,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r20.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82701f28
	ctx.lr = 0x82704EB4;
	sub_82701F28(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82704f50
	if (cr6.eq) goto loc_82704F50;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x822a8108
	ctx.lr = 0x82704EC4;
	sub_822A8108(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// li r6,48
	ctx.r6.s64 = 48;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v58,r3,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v57,r3,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r10,2272
	ctx.r5.s64 = ctx.r10.s64 + 2272;
	// lfs f1,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f2,30712(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x822a9930
	ctx.lr = 0x82704F40;
	sub_822A9930(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82746230
	ctx.lr = 0x82704F48;
	sub_82746230(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82704f6c
	goto loc_82704F6C;
loc_82704F50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82746108
	ctx.lr = 0x82704F58;
	sub_82746108(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82704f6c
	goto loc_82704F6C;
loc_82704F60:
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x82704f6c
	goto loc_82704F6C;
loc_82704F68:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82704F6C:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba1c
	ctx.lr = 0x82704F80;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82704F84"))) PPC_WEAK_FUNC(sub_82704F84);
PPC_FUNC_IMPL(__imp__sub_82704F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82704F88"))) PPC_WEAK_FUNC(sub_82704F88);
PPC_FUNC_IMPL(__imp__sub_82704F88) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82704F90;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mulli r11,r28,68
	r11.s64 = r28.s64 * 68;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,244(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82700950
	ctx.lr = 0x82704FDC;
	sub_82700950(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82705048
	if (cr6.eq) goto loc_82705048;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8270501c
	if (!cr6.eq) goto loc_8270501C;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r6.u32);
	// b 0x82705048
	goto loc_82705048;
loc_8270501C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bne cr6,0x82705040
	if (!cr6.eq) goto loc_82705040;
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// b 0x82705048
	goto loc_82705048;
loc_82705040:
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82705048:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a8108
	ctx.lr = 0x82705050;
	sub_822A8108(ctx, base);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// bl 0x826fd0a8
	ctx.lr = 0x82705058;
	sub_826FD0A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82705070
	if (!cr6.eq) goto loc_82705070;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82705070:
	// lwz r11,484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 484);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82705090
	if (cr6.eq) goto loc_82705090;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82705090:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82700b90
	ctx.lr = 0x827050A0;
	sub_82700B90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827050dc
	if (cr6.eq) goto loc_827050DC;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827050d4
	if (cr6.eq) goto loc_827050D4;
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// b 0x827050dc
	goto loc_827050DC;
loc_827050D4:
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_827050DC:
	// lwz r11,484(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 484);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r9,r10,29,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827050fc
	if (cr6.eq) goto loc_827050FC;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_827050FC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705134
	if (cr6.eq) goto loc_82705134;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82700c78
	ctx.lr = 0x8270511C;
	sub_82700C78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705134
	if (cr6.eq) goto loc_82705134;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82705134:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826ffef0
	ctx.lr = 0x82705140;
	sub_826FFEF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705158
	if (cr6.eq) goto loc_82705158;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,1024
	ctx.r10.u64 = r11.u64 | 1024;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_82705158:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82705194
	if (cr6.eq) goto loc_82705194;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82705194
	if (cr6.eq) goto loc_82705194;
	// lfs f0,580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 580);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8270518c
	if (cr6.gt) goto loc_8270518C;
	// li r11,0
	r11.s64 = 0;
loc_8270518C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x82705198
	goto loc_82705198;
loc_82705194:
	// li r11,0
	r11.s64 = 0;
loc_82705198:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,-13624
	r29.s64 = r11.s64 + -13624;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// beq cr6,0x827051f4
	if (cr6.eq) goto loc_827051F4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827051cc
	if (cr6.eq) goto loc_827051CC;
loc_827051BC:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,2048
	ctx.r10.u64 = r11.u64 | 2048;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// b 0x82705208
	goto loc_82705208;
loc_827051CC:
	// addi r11,r28,2
	r11.s64 = r28.s64 + 2;
	// lfs f0,264(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 264);
	f0.f64 = double(temp.f32);
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// lfsx f13,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827051bc
	if (!cr6.lt) goto loc_827051BC;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfsx f13,r11,r30
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + r30.u32, temp.u32);
	// b 0x82705208
	goto loc_82705208;
loc_827051F4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82705208
	if (!cr6.eq) goto loc_82705208;
	// addi r11,r28,2
	r11.s64 = r28.s64 + 2;
	// mulli r10,r11,68
	ctx.r10.s64 = r11.s64 * 68;
	// stfsx f31,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, temp.u32);
loc_82705208:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fffe8
	ctx.lr = 0x82705214;
	sub_826FFFE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270522c
	if (cr6.eq) goto loc_8270522C;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,4096
	ctx.r10.u64 = r11.u64 | 4096;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
loc_8270522C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82700f28
	ctx.lr = 0x82705238;
	sub_82700F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// beq cr6,0x82705284
	if (cr6.eq) goto loc_82705284;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82705264
	if (cr6.eq) goto loc_82705264;
loc_82705254:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,8192
	ctx.r10.u64 = r11.u64 | 8192;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// b 0x82705290
	goto loc_82705290;
loc_82705264:
	// lfs f0,272(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 272);
	f0.f64 = double(temp.f32);
	// lfs f13,144(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82705254
	if (!cr6.lt) goto loc_82705254;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// b 0x82705290
	goto loc_82705290;
loc_82705284:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82705290
	if (!cr6.eq) goto loc_82705290;
	// stfs f31,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
loc_82705290:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702c08
	ctx.lr = 0x8270529C;
	sub_82702C08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// beq cr6,0x82705300
	if (cr6.eq) goto loc_82705300;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827052e4
	if (!cr6.eq) goto loc_827052E4;
	// lfs f0,276(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 276);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x827052e4
	if (!cr6.lt) goto loc_827052E4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,148(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_827052E4:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// ori r10,r11,16384
	ctx.r10.u64 = r11.u64 | 16384;
	// stw r10,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82705300:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270530c
	if (!cr6.eq) goto loc_8270530C;
	// stfs f31,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
loc_8270530C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8270531C"))) PPC_WEAK_FUNC(sub_8270531C);
PPC_FUNC_IMPL(__imp__sub_8270531C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705320"))) PPC_WEAK_FUNC(sub_82705320);
PPC_FUNC_IMPL(__imp__sub_82705320) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cntlzw r4,r6
	ctx.r4.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f1,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r4,r8,24
	ctx.r4.u64 = ctx.r8.u32 & 0xFF;
	// lfs f11,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827053A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_827053C4"))) PPC_WEAK_FUNC(sub_827053C4);
PPC_FUNC_IMPL(__imp__sub_827053C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827053C8"))) PPC_WEAK_FUNC(sub_827053C8);
PPC_FUNC_IMPL(__imp__sub_827053C8) {
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
	ctx.lr = 0x827053D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,876(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 876);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82705444
	if (!cr6.eq) goto loc_82705444;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82705444
	if (!cr6.gt) goto loc_82705444;
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702698
	ctx.lr = 0x82705400;
	sub_82702698(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// bl 0x82703df8
	ctx.lr = 0x8270541C;
	sub_82703DF8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82705434
	if (cr6.eq) goto loc_82705434;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82705434:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702700
	ctx.lr = 0x82705444;
	sub_82702700(ctx, base);
loc_82705444:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82705450"))) PPC_WEAK_FUNC(sub_82705450);
PPC_FUNC_IMPL(__imp__sub_82705450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32144
	r11.s64 = -2106589184;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,4472
	ctx.r3.s64 = r11.s64 + 4472;
	// b 0x82705320
	sub_82705320(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82705460"))) PPC_WEAK_FUNC(sub_82705460);
PPC_FUNC_IMPL(__imp__sub_82705460) {
	PPC_FUNC_PROLOGUE();
	// b 0x82703660
	sub_82703660(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82705464"))) PPC_WEAK_FUNC(sub_82705464);
PPC_FUNC_IMPL(__imp__sub_82705464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705468"))) PPC_WEAK_FUNC(sub_82705468);
PPC_FUNC_IMPL(__imp__sub_82705468) {
	PPC_FUNC_PROLOGUE();
	// b 0x82703728
	sub_82703728(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270546C"))) PPC_WEAK_FUNC(sub_8270546C);
PPC_FUNC_IMPL(__imp__sub_8270546C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705470"))) PPC_WEAK_FUNC(sub_82705470);
PPC_FUNC_IMPL(__imp__sub_82705470) {
	PPC_FUNC_PROLOGUE();
	// b 0x827037f0
	sub_827037F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82705474"))) PPC_WEAK_FUNC(sub_82705474);
PPC_FUNC_IMPL(__imp__sub_82705474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705478"))) PPC_WEAK_FUNC(sub_82705478);
PPC_FUNC_IMPL(__imp__sub_82705478) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f1,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82701948
	ctx.lr = 0x827054B4;
	sub_82701948(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827054C4"))) PPC_WEAK_FUNC(sub_827054C4);
PPC_FUNC_IMPL(__imp__sub_827054C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827054C8"))) PPC_WEAK_FUNC(sub_827054C8);
PPC_FUNC_IMPL(__imp__sub_827054C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x827039b0
	sub_827039B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827054CC"))) PPC_WEAK_FUNC(sub_827054CC);
PPC_FUNC_IMPL(__imp__sub_827054CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827054D0"))) PPC_WEAK_FUNC(sub_827054D0);
PPC_FUNC_IMPL(__imp__sub_827054D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x827038c0
	sub_827038C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827054DC"))) PPC_WEAK_FUNC(sub_827054DC);
PPC_FUNC_IMPL(__imp__sub_827054DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827054E0"))) PPC_WEAK_FUNC(sub_827054E0);
PPC_FUNC_IMPL(__imp__sub_827054E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82703938
	sub_82703938(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827054EC"))) PPC_WEAK_FUNC(sub_827054EC);
PPC_FUNC_IMPL(__imp__sub_827054EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827054F0"))) PPC_WEAK_FUNC(sub_827054F0);
PPC_FUNC_IMPL(__imp__sub_827054F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x82703ba0
	sub_82703BA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270550C"))) PPC_WEAK_FUNC(sub_8270550C);
PPC_FUNC_IMPL(__imp__sub_8270550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705510"))) PPC_WEAK_FUNC(sub_82705510);
PPC_FUNC_IMPL(__imp__sub_82705510) {
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
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x82705564
	if (cr6.eq) goto loc_82705564;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82705564
	if (cr6.eq) goto loc_82705564;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82702a28
	ctx.lr = 0x82705554;
	sub_82702A28(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// b 0x82705568
	goto loc_82705568;
loc_82705564:
	// li r11,0
	r11.s64 = 0;
loc_82705568:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
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
}

__attribute__((alias("__imp__sub_82705588"))) PPC_WEAK_FUNC(sub_82705588);
PPC_FUNC_IMPL(__imp__sub_82705588) {
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
	// bl 0x82703c70
	ctx.lr = 0x827055A8;
	sub_82703C70(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
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
}

__attribute__((alias("__imp__sub_827055C8"))) PPC_WEAK_FUNC(sub_827055C8);
PPC_FUNC_IMPL(__imp__sub_827055C8) {
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
	// bl 0x82703d08
	ctx.lr = 0x827055E8;
	sub_82703D08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
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
}

__attribute__((alias("__imp__sub_82705608"))) PPC_WEAK_FUNC(sub_82705608);
PPC_FUNC_IMPL(__imp__sub_82705608) {
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
	ctx.lr = 0x82705610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827056ec
	if (cr6.eq) goto loc_827056EC;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827056f8
	if (cr6.eq) goto loc_827056F8;
	// lwz r29,868(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 868);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x827056f8
	if (cr6.lt) goto loc_827056F8;
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x827056f8
	if (!cr6.lt) goto loc_827056F8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82701de0
	ctx.lr = 0x82705650;
	sub_82701DE0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82705688
	if (cr6.eq) goto loc_82705688;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270566c
	if (cr6.eq) goto loc_8270566C;
	// bl 0x82714f10
	ctx.lr = 0x8270566C;
	sub_82714F10(ctx, base);
loc_8270566C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82705684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827056ac
	goto loc_827056AC;
loc_82705688:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c388
	ctx.lr = 0x82705690;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827056ac
	if (cr6.eq) goto loc_827056AC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cc90
	ctx.lr = 0x827056AC;
	sub_8270CC90(ctx, base);
loc_827056AC:
	// lwz r3,-10016(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwzx r30,r11,r31
	r30.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82701ea0
	ctx.lr = 0x827056C4;
	sub_82701EA0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827056DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10016(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x8270c958
	ctx.lr = 0x827056EC;
	sub_8270C958(ctx, base);
loc_827056EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_827056F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82705704"))) PPC_WEAK_FUNC(sub_82705704);
PPC_FUNC_IMPL(__imp__sub_82705704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705708"))) PPC_WEAK_FUNC(sub_82705708);
PPC_FUNC_IMPL(__imp__sub_82705708) {
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
	ctx.lr = 0x82705710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82705730
	if (!cr6.eq) goto loc_82705730;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82705730:
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// bl 0x82714f10
	ctx.lr = 0x82705738;
	sub_82714F10(ctx, base);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// li r30,1
	r30.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827057a8
	if (cr6.eq) goto loc_827057A8;
	// li r31,0
	r31.s64 = 0;
loc_82705754:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82705794
	if (cr6.eq) goto loc_82705794;
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270578c
	if (cr6.eq) goto loc_8270578C;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82705608
	ctx.lr = 0x82705778;
	sub_82705608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// bne cr6,0x82705790
	if (!cr6.eq) goto loc_82705790;
loc_8270578C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82705790:
	// clrlwi r30,r10,24
	r30.u64 = ctx.r10.u32 & 0xFF;
loc_82705794:
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x82705754
	if (cr6.lt) goto loc_82705754;
loc_827057A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,-24400(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24400);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x827057d4
	if (!cr6.eq) goto loc_827057D4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x827057D4;
	sub_821F1498(ctx, base);
loc_827057D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827057E0"))) PPC_WEAK_FUNC(sub_827057E0);
PPC_FUNC_IMPL(__imp__sub_827057E0) {
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
	ctx.lr = 0x827057E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r7,-10016(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82705870
	if (cr6.eq) goto loc_82705870;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270581c
	if (cr6.eq) goto loc_8270581C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82703ba0
	ctx.lr = 0x82705818;
	sub_82703BA0(ctx, base);
	// lwz r7,-10016(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_8270581C:
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x82701080
	ctx.lr = 0x82705824;
	sub_82701080(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82705870
	if (!cr6.gt) goto loc_82705870;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82705834:
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82705864
	if (cr6.eq) goto loc_82705864;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lbz r10,872(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82705864
	if (!cr6.eq) goto loc_82705864;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8270c408
	ctx.lr = 0x82705860;
	sub_8270C408(ctx, base);
	// lwz r7,-10016(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + -10016);
loc_82705864:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82705834
	if (!cr0.eq) goto loc_82705834;
loc_82705870:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82705878"))) PPC_WEAK_FUNC(sub_82705878);
PPC_FUNC_IMPL(__imp__sub_82705878) {
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
	ctx.lr = 0x82705880;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705910
	if (cr6.eq) goto loc_82705910;
	// lhz r11,184(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827058a8
	if (cr6.eq) goto loc_827058A8;
	// bl 0x827037f0
	ctx.lr = 0x827058A8;
	sub_827037F0(ctx, base);
loc_827058A8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,22216
	ctx.r5.s64 = r11.s64 + 22216;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x827058C0;
	sub_82130000(ctx, base);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,180
	ctx.r3.s64 = r11.s64 + 180;
	// bl 0x8247bb70
	ctx.lr = 0x827058D0;
	sub_8247BB70(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82705910
	if (!cr6.gt) goto loc_82705910;
	// li r30,0
	r30.s64 = 0;
loc_827058DC:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x827058E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827058f4
	if (cr6.eq) goto loc_827058F4;
	// bl 0x82715fc0
	ctx.lr = 0x827058F0;
	sub_82715FC0(ctx, base);
	// b 0x827058f8
	goto loc_827058F8;
loc_827058F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827058F8:
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lwz r11,180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// stwx r3,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x827058dc
	if (!cr0.eq) goto loc_827058DC;
loc_82705910:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82705918"))) PPC_WEAK_FUNC(sub_82705918);
PPC_FUNC_IMPL(__imp__sub_82705918) {
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
	ctx.lr = 0x82705920;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,-10016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82705b0c
	if (cr6.eq) goto loc_82705B0C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r27,0
	r27.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// stw r27,196(r30)
	PPC_STORE_U32(r30.u32 + 196, r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r11,188(r30)
	PPC_STORE_U32(r30.u32 + 188, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,192(r30)
	PPC_STORE_U32(r30.u32 + 192, r11.u32);
	// stfs f0,212(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 212, temp.u32);
	// stw r27,200(r30)
	PPC_STORE_U32(r30.u32 + 200, r27.u32);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// lhz r28,184(r30)
	r28.u64 = PPC_LOAD_U16(r30.u32 + 184);
	// bl 0x82388090
	ctx.lr = 0x82705968;
	sub_82388090(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82705980
	if (cr6.eq) goto loc_82705980;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82705af8
	if (!cr6.gt) goto loc_82705AF8;
loc_82705980:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82701080
	ctx.lr = 0x82705988;
	sub_82701080(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82705af8
	if (!cr6.gt) goto loc_82705AF8;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82705af8
	if (!cr6.gt) goto loc_82705AF8;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addi r31,r11,2192
	r31.s64 = r11.s64 + 2192;
	// ori r29,r10,64167
	r29.u64 = ctx.r10.u64 | 64167;
	// twllei r28,0
	// lwz r9,2192(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2192);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r9,r29
	ctx.r10.s64 = ctx.r9.s64 * r29.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// divw r7,r8,r28
	ctx.r7.s32 = ctx.r8.s32 / r28.s32;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mullw r6,r7,r28
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r28.s32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r27,192(r30)
	PPC_STORE_U32(r30.u32 + 192, r27.u32);
	// subf r5,r6,r8
	ctx.r5.s64 = ctx.r8.s64 - ctx.r6.s64;
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// stw r5,188(r30)
	PPC_STORE_U32(r30.u32 + 188, ctx.r5.u32);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// andc r3,r28,r4
	ctx.r3.u64 = r28.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// bl 0x82256058
	ctx.lr = 0x827059F8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705a74
	if (cr6.eq) goto loc_82705A74;
	// bl 0x82256058
	ctx.lr = 0x82705A04;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82705a74
	if (cr0.eq) goto loc_82705A74;
	// bl 0x82256058
	ctx.lr = 0x82705A10;
	sub_82256058(ctx, base);
	// lwz r11,3124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3124);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82705a74
	if (!cr6.gt) goto loc_82705A74;
	// bl 0x82256058
	ctx.lr = 0x82705A20;
	sub_82256058(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r8,r29
	ctx.r10.s64 = ctx.r8.s64 * r29.s64;
	// lwz r9,3124(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3124);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r5,r7,r6
	ctx.r5.s32 = ctx.r7.s32 / ctx.r6.s32;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// mullw r3,r5,r6
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// andc r9,r6,r4
	ctx.r9.u64 = ctx.r6.u64 & ~ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// subf r8,r3,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r3.s64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// twllei r6,0
	// twlgei r9,-1
	// stw r8,192(r30)
	PPC_STORE_U32(r30.u32 + 192, ctx.r8.u32);
loc_82705A74:
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82705a88
	if (!cr6.eq) goto loc_82705A88;
	// li r11,1
	r11.s64 = 1;
	// stw r11,196(r30)
	PPC_STORE_U32(r30.u32 + 196, r11.u32);
loc_82705A88:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x82705A94;
	sub_827057E0(ctx, base);
	// lwz r6,188(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// lwz r10,180(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,192(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r11,22288
	ctx.r5.s64 = r11.s64 + 22288;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lfs f4,16(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// stfd f4,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f4.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// stfd f2,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f2.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f1,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f1.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f3,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f3.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// bl 0x82130000
	ctx.lr = 0x82705AF0;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82705AF8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r11,22252
	ctx.r5.s64 = r11.s64 + 22252;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x82705B0C;
	sub_82130000(ctx, base);
loc_82705B0C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82705B14"))) PPC_WEAK_FUNC(sub_82705B14);
PPC_FUNC_IMPL(__imp__sub_82705B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705B18"))) PPC_WEAK_FUNC(sub_82705B18);
PPC_FUNC_IMPL(__imp__sub_82705B18) {
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
	ctx.lr = 0x82705B20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705c0c
	if (cr6.eq) goto loc_82705C0C;
	// bl 0x822a39c0
	ctx.lr = 0x82705B3C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705c0c
	if (cr6.eq) goto loc_82705C0C;
	// lwz r11,1120(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82705c00
	if (cr6.lt) goto loc_82705C00;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,1128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82705c0c
	if (cr6.gt) goto loc_82705C0C;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwz r11,264(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x82705c00
	if (cr6.eq) goto loc_82705C00;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,-13624
	r31.s64 = ctx.r10.s64 + -13624;
loc_82705B8C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r29,r11
	r29.u64 = r11.u64;
	// bl 0x82215e10
	ctx.lr = 0x82705B9C;
	sub_82215E10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x82705BA4;
	sub_822A8108(ctx, base);
	// addi r29,r3,48
	r29.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82705BB0;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	f0.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// fsubs f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f11
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// blt cr6,0x82705c0c
	if (cr6.lt) goto loc_82705C0C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82705b8c
	if (!cr6.eq) goto loc_82705B8C;
loc_82705C00:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82705C0C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82705C18"))) PPC_WEAK_FUNC(sub_82705C18);
PPC_FUNC_IMPL(__imp__sub_82705C18) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705cc0
	if (cr6.eq) goto loc_82705CC0;
	// bl 0x822a39c0
	ctx.lr = 0x82705C44;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705cc0
	if (cr6.eq) goto loc_82705CC0;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// lwz r11,264(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705cc0
	if (cr6.eq) goto loc_82705CC0;
loc_82705C68:
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x82705cc4
	if (cr6.eq) goto loc_82705CC4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705c84
	if (cr6.eq) goto loc_82705C84;
	// lwz r11,864(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 864);
	// b 0x82705cb8
	goto loc_82705CB8;
loc_82705C84:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705ca0
	if (cr6.eq) goto loc_82705CA0;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82705ca4
	if (!cr6.eq) goto loc_82705CA4;
loc_82705CA0:
	// li r11,0
	r11.s64 = 0;
loc_82705CA4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705cc0
	if (cr6.eq) goto loc_82705CC0;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_82705CB8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82705c68
	if (!cr6.eq) goto loc_82705C68;
loc_82705CC0:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82705CC4:
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

__attribute__((alias("__imp__sub_82705CDC"))) PPC_WEAK_FUNC(sub_82705CDC);
PPC_FUNC_IMPL(__imp__sub_82705CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705CE0"))) PPC_WEAK_FUNC(sub_82705CE0);
PPC_FUNC_IMPL(__imp__sub_82705CE0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705d80
	if (cr6.eq) goto loc_82705D80;
	// bl 0x822a39c0
	ctx.lr = 0x82705D0C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705d80
	if (cr6.eq) goto loc_82705D80;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// lwz r3,264(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705d80
	if (cr6.eq) goto loc_82705D80;
loc_82705D2C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82705d84
	if (cr0.lt) goto loc_82705D84;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82705d44
	if (cr6.eq) goto loc_82705D44;
	// lwz r3,864(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 864);
	// b 0x82705d78
	goto loc_82705D78;
loc_82705D44:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705d60
	if (cr6.eq) goto loc_82705D60;
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82705d64
	if (!cr6.eq) goto loc_82705D64;
loc_82705D60:
	// li r11,0
	r11.s64 = 0;
loc_82705D64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705d80
	if (cr6.eq) goto loc_82705D80;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
loc_82705D78:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82705d2c
	if (!cr6.eq) goto loc_82705D2C;
loc_82705D80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82705D84:
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

__attribute__((alias("__imp__sub_82705D9C"))) PPC_WEAK_FUNC(sub_82705D9C);
PPC_FUNC_IMPL(__imp__sub_82705D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705DA0"))) PPC_WEAK_FUNC(sub_82705DA0);
PPC_FUNC_IMPL(__imp__sub_82705DA0) {
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
	ctx.lr = 0x82705DA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r29,68
	r11.s64 = r29.s64 * 68;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// add r28,r11,r31
	r28.u64 = r11.u64 + r31.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// addi r30,r10,-13624
	r30.s64 = ctx.r10.s64 + -13624;
	// lwz r27,-13624(r10)
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + -13624);
	// lwz r24,104(r28)
	r24.u64 = PPC_LOAD_U32(r28.u32 + 104);
	// bl 0x82705ce0
	ctx.lr = 0x82705DD8;
	sub_82705CE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827022c8
	ctx.lr = 0x82705DE4;
	sub_827022C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82705e7c
	if (cr6.eq) goto loc_82705E7C;
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82705ec4
	if (cr6.eq) goto loc_82705EC4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82705E0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x82705e48
	if (cr6.eq) goto loc_82705E48;
	// ble cr6,0x82705e7c
	if (!cr6.gt) goto loc_82705E7C;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bgt cr6,0x82705e7c
	if (cr6.gt) goto loc_82705E7C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82705E34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82705e7c
	if (!cr6.eq) goto loc_82705E7C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x82705e78
	goto loc_82705E78;
loc_82705E48:
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82705e74
	if (!cr6.eq) goto loc_82705E74;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82705E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82705e7c
	if (!cr6.eq) goto loc_82705E7C;
loc_82705E74:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
loc_82705E78:
	// addi r27,r11,-1
	r27.s64 = r11.s64 + -1;
loc_82705E7C:
	// lwz r11,104(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 104);
	// add. r10,r11,r26
	ctx.r10.u64 = r11.u64 + r26.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x82705e90
	if (!cr0.lt) goto loc_82705E90;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82705e9c
	goto loc_82705E9C;
loc_82705E90:
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// ble cr6,0x82705e9c
	if (!cr6.gt) goto loc_82705E9C;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82705E9C:
	// stw r10,104(r28)
	PPC_STORE_U32(r28.u32 + 104, ctx.r10.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// addi r5,r11,22360
	ctx.r5.s64 = r11.s64 + 22360;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82130000
	ctx.lr = 0x82705EC4;
	sub_82130000(ctx, base);
loc_82705EC4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82705ECC"))) PPC_WEAK_FUNC(sub_82705ECC);
PPC_FUNC_IMPL(__imp__sub_82705ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82705ED0"))) PPC_WEAK_FUNC(sub_82705ED0);
PPC_FUNC_IMPL(__imp__sub_82705ED0) {
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
	// bl 0x82705c18
	ctx.lr = 0x82705EE8;
	sub_82705C18(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82705f1c
	if (cr6.lt) goto loc_82705F1C;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// bge cr6,0x82705f1c
	if (!cr6.lt) goto loc_82705F1C;
	// mulli r11,r6,68
	r11.s64 = ctx.r6.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
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
loc_82705F1C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r11,21768
	ctx.r5.s64 = r11.s64 + 21768;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82130000
	ctx.lr = 0x82705F30;
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
}

__attribute__((alias("__imp__sub_82705F48"))) PPC_WEAK_FUNC(sub_82705F48);
PPC_FUNC_IMPL(__imp__sub_82705F48) {
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
	// bl 0x82705608
	ctx.lr = 0x82705F68;
	sub_82705608(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
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
}

__attribute__((alias("__imp__sub_82705F88"))) PPC_WEAK_FUNC(sub_82705F88);
PPC_FUNC_IMPL(__imp__sub_82705F88) {
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
	// bl 0x82705708
	ctx.lr = 0x82705FA0;
	sub_82705708(ctx, base);
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

__attribute__((alias("__imp__sub_82705FC0"))) PPC_WEAK_FUNC(sub_82705FC0);
PPC_FUNC_IMPL(__imp__sub_82705FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x827057e0
	sub_827057E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82705FF0"))) PPC_WEAK_FUNC(sub_82705FF0);
PPC_FUNC_IMPL(__imp__sub_82705FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82705878
	sub_82705878(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82705FFC"))) PPC_WEAK_FUNC(sub_82705FFC);
PPC_FUNC_IMPL(__imp__sub_82705FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82706000"))) PPC_WEAK_FUNC(sub_82706000);
PPC_FUNC_IMPL(__imp__sub_82706000) {
	PPC_FUNC_PROLOGUE();
	// b 0x82705918
	sub_82705918(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82706004"))) PPC_WEAK_FUNC(sub_82706004);
PPC_FUNC_IMPL(__imp__sub_82706004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82706008"))) PPC_WEAK_FUNC(sub_82706008);
PPC_FUNC_IMPL(__imp__sub_82706008) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82706010;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// beq cr6,0x8270604c
	if (cr6.eq) goto loc_8270604C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82705ed0
	ctx.lr = 0x82706048;
	sub_82705ED0(ctx, base);
	// b 0x82706050
	goto loc_82706050;
loc_8270604C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82706050:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stfs f31,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r29,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r29.u8);
	// stb r28,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r28.u8);
	// stb r27,15(r31)
	PPC_STORE_U8(r31.u32 + 15, r27.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82706078"))) PPC_WEAK_FUNC(sub_82706078);
PPC_FUNC_IMPL(__imp__sub_82706078) {
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
	ctx.lr = 0x82706080;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x827060c0
	if (!cr6.gt) goto loc_827060C0;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_82706098:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827060ac
	if (cr6.eq) goto loc_827060AC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x827060AC;
	sub_82130588(ctx, base);
loc_827060AC:
	// addi r3,r31,-4
	ctx.r3.s64 = r31.s64 + -4;
	// bl 0x821d2aa0
	ctx.lr = 0x827060B4;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// bne 0x82706098
	if (!cr0.eq) goto loc_82706098;
loc_827060C0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x827060C8;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827060D0"))) PPC_WEAK_FUNC(sub_827060D0);
PPC_FUNC_IMPL(__imp__sub_827060D0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x827060D8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827060FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8270660c
	if (!cr6.gt) goto loc_8270660C;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247bb70
	ctx.lr = 0x82706114;
	sub_8247BB70(ctx, base);
	// addi r30,r28,12
	r30.s64 = r28.s64 + 12;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247bb70
	ctx.lr = 0x82706124;
	sub_8247BB70(ctx, base);
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// beq cr6,0x82706160
	if (cr6.eq) goto loc_82706160;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8270613C:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r29,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r29.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r29.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,8(r28)
	ctx.r7.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8270613c
	if (cr6.lt) goto loc_8270613C;
loc_82706160:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x8270660c
	if (!cr6.gt) goto loc_8270660C;
	// lwz r3,20(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// bl 0x82130588
	ctx.lr = 0x82706174;
	sub_82130588(ctx, base);
	// clrlwi r27,r26,16
	r27.u64 = r26.u32 & 0xFFFF;
	// stw r29,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r29.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r29,24(r28)
	PPC_STORE_U16(r28.u32 + 24, r29.u16);
	// sth r27,26(r28)
	PPC_STORE_U16(r28.u32 + 26, r27.u16);
	// beq cr6,0x8270619c
	if (cr6.eq) goto loc_8270619C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827027b0
	ctx.lr = 0x82706198;
	sub_827027B0(ctx, base);
	// b 0x827061a0
	goto loc_827061A0;
loc_8270619C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827061A0:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r24,1
	r24.s64 = 1;
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// lwz r11,28(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82706224
	if (cr6.eq) goto loc_82706224;
loc_827061BC:
	// li r3,784
	ctx.r3.s64 = 784;
	// bl 0x82130528
	ctx.lr = 0x827061C4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827061d4
	if (cr6.eq) goto loc_827061D4;
	// bl 0x8270e2a8
	ctx.lr = 0x827061D0;
	sub_8270E2A8(ctx, base);
	// b 0x827061d8
	goto loc_827061D8;
loc_827061D4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827061D8:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706210
	if (cr6.eq) goto loc_82706210;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
loc_827061F0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82706290
	if (cr6.eq) goto loc_82706290;
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x827061f0
	if (cr6.lt) goto loc_827061F0;
loc_82706210:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82706214:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,28(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827061bc
	if (!cr6.eq) goto loc_827061BC;
loc_82706224:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706258
	if (cr6.eq) goto loc_82706258;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82706238:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stb r29,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r29.u8);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x82706238
	if (cr6.lt) goto loc_82706238;
loc_82706258:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r30,r28,32
	r30.s64 = r28.s64 + 32;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x8270626C;
	sub_82130588(ctx, base);
	// sth r27,38(r28)
	PPC_STORE_U16(r28.u32 + 38, r27.u16);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r29,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r29.u32);
	// sth r29,36(r28)
	PPC_STORE_U16(r28.u32 + 36, r29.u16);
	// beq cr6,0x827062b4
	if (cr6.eq) goto loc_827062B4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827027b0
	ctx.lr = 0x8270628C;
	sub_827027B0(ctx, base);
	// b 0x827062b8
	goto loc_827062B8;
loc_82706290:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stb r24,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r24.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82706214
	goto loc_82706214;
loc_827062B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827062B8:
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// stw r26,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r26.u32);
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82706338
	if (cr6.eq) goto loc_82706338;
loc_827062D0:
	// li r3,1712
	ctx.r3.s64 = 1712;
	// bl 0x82130528
	ctx.lr = 0x827062D8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827062e8
	if (cr6.eq) goto loc_827062E8;
	// bl 0x82744ae0
	ctx.lr = 0x827062E4;
	sub_82744AE0(ctx, base);
	// b 0x827062ec
	goto loc_827062EC;
loc_827062E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827062EC:
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706324
	if (cr6.eq) goto loc_82706324;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
loc_82706304:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827063b8
	if (cr6.eq) goto loc_827063B8;
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82706304
	if (cr6.lt) goto loc_82706304;
loc_82706324:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82706328:
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827062d0
	if (!cr6.eq) goto loc_827062D0;
loc_82706338:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270636c
	if (cr6.eq) goto loc_8270636C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8270634C:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// stb r29,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r29.u8);
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8270634c
	if (cr6.lt) goto loc_8270634C;
loc_8270636C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r31,r28,44
	r31.s64 = r28.s64 + 44;
	// li r27,5
	r27.s64 = 5;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// lhz r10,50(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 50);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82706398
	if (!cr6.eq) goto loc_82706398;
	// sth r27,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r27.u16);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82706394;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82706398:
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
	// li r3,464
	ctx.r3.s64 = 464;
	// bl 0x82130528
	ctx.lr = 0x827063A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827063dc
	if (cr6.eq) goto loc_827063DC;
	// bl 0x82715c98
	ctx.lr = 0x827063B0;
	sub_82715C98(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x827063e0
	goto loc_827063E0;
loc_827063B8:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// stb r24,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r24.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82706328
	goto loc_82706328;
loc_827063DC:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_827063E0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,176
	ctx.r3.s64 = 176;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r29,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x827063FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706410
	if (cr6.eq) goto loc_82706410;
	// bl 0x8271b460
	ctx.lr = 0x82706408;
	sub_8271B460(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82706414
	goto loc_82706414;
loc_82706410:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82706414:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,176
	ctx.r3.s64 = 176;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r29,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82706430;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706444
	if (cr6.eq) goto loc_82706444;
	// bl 0x8271a580
	ctx.lr = 0x8270643C;
	sub_8271A580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82706448
	goto loc_82706448;
loc_82706444:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82706448:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,176
	ctx.r3.s64 = 176;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r29,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82706464;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706478
	if (cr6.eq) goto loc_82706478;
	// bl 0x82718a70
	ctx.lr = 0x82706470;
	sub_82718A70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8270647c
	goto loc_8270647C;
loc_82706478:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8270647C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,176
	ctx.r3.s64 = 176;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// stw r29,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82706498;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827064a8
	if (cr6.eq) goto loc_827064A8;
	// bl 0x82716e58
	ctx.lr = 0x827064A4;
	sub_82716E58(ctx, base);
	// b 0x827064ac
	goto loc_827064AC;
loc_827064A8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827064AC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r25,r11,30576
	r25.s64 = r11.s64 + 30576;
	// addi r4,r9,22444
	ctx.r4.s64 = ctx.r9.s64 + 22444;
	// stw r3,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// stw r29,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, r29.u32);
	// stw r29,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r29.u32);
	// stb r29,56(r28)
	PPC_STORE_U8(r28.u32 + 56, r29.u8);
	// stw r29,60(r28)
	PPC_STORE_U32(r28.u32 + 60, r29.u32);
	// stb r29,64(r28)
	PPC_STORE_U8(r28.u32 + 64, r29.u8);
	// stw r29,68(r28)
	PPC_STORE_U32(r28.u32 + 68, r29.u32);
	// stw r29,72(r28)
	PPC_STORE_U32(r28.u32 + 72, r29.u32);
	// stw r29,76(r28)
	PPC_STORE_U32(r28.u32 + 76, r29.u32);
	// stw r29,80(r28)
	PPC_STORE_U32(r28.u32 + 80, r29.u32);
	// stw r29,84(r28)
	PPC_STORE_U32(r28.u32 + 84, r29.u32);
	// stb r29,88(r28)
	PPC_STORE_U8(r28.u32 + 88, r29.u8);
	// stw r29,92(r28)
	PPC_STORE_U32(r28.u32 + 92, r29.u32);
	// bl 0x821ca540
	ctx.lr = 0x82706504;
	sub_821CA540(ctx, base);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r5,r5,22428
	ctx.r5.s64 = ctx.r5.s64 + 22428;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,-27856(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + -27856);
	// bl 0x82137a08
	ctx.lr = 0x82706520;
	sub_82137A08(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r26,-32111
	r26.s64 = -2104426496;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// addi r30,r11,5276
	r30.s64 = r11.s64 + 5276;
	// addi r31,r28,164
	r31.s64 = r28.s64 + 164;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r6,-24208(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + -24208);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,2828(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2828);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821c04b0
	ctx.lr = 0x82706550;
	sub_821C04B0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8270657c
	if (!cr6.eq) goto loc_8270657C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,-24208(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + -24208);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,2828(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 2828);
	// addi r4,r11,22416
	ctx.r4.s64 = r11.s64 + 22416;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x821c04b0
	ctx.lr = 0x8270657C;
	sub_821C04B0(ctx, base);
loc_8270657C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82706584;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270da70
	ctx.lr = 0x8270658C;
	sub_8270DA70(ctx, base);
	// addi r3,r28,96
	ctx.r3.s64 = r28.s64 + 96;
	// bl 0x82714f10
	ctx.lr = 0x82706594;
	sub_82714F10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r24,222(r28)
	PPC_STORE_U8(r28.u32 + 222, r24.u8);
	// li r3,8176
	ctx.r3.s64 = 8176;
	// stb r24,221(r28)
	PPC_STORE_U8(r28.u32 + 221, r24.u8);
	// stb r24,220(r28)
	PPC_STORE_U8(r28.u32 + 220, r24.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,216(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 216, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x827065B4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827065c4
	if (cr6.eq) goto loc_827065C4;
	// bl 0x8238f550
	ctx.lr = 0x827065C0;
	sub_8238F550(ctx, base);
	// b 0x827065c8
	goto loc_827065C8;
loc_827065C4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_827065C8:
	// stw r3,224(r28)
	PPC_STORE_U32(r28.u32 + 224, ctx.r3.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24808
	ctx.r4.s64 = r11.s64 + 24808;
	// bl 0x82390b18
	ctx.lr = 0x827065DC;
	sub_82390B18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270660c
	if (!cr6.eq) goto loc_8270660C;
	// lwz r3,224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 224);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706608
	if (cr6.eq) goto loc_82706608;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82706608:
	// stw r29,224(r28)
	PPC_STORE_U32(r28.u32 + 224, r29.u32);
loc_8270660C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82706614"))) PPC_WEAK_FUNC(sub_82706614);
PPC_FUNC_IMPL(__imp__sub_82706614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82706618"))) PPC_WEAK_FUNC(sub_82706618);
PPC_FUNC_IMPL(__imp__sub_82706618) {
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
	ctx.lr = 0x82706620;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827066bc
	if (cr6.eq) goto loc_827066BC;
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827066a8
	if (!cr6.gt) goto loc_827066A8;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_82706648:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lbz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706670
	if (cr6.eq) goto loc_82706670;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82706670:
	// lwz r11,44(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706694
	if (cr6.eq) goto loc_82706694;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82706694:
	// lhz r11,48(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 48);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82706648
	if (cr6.lt) goto loc_82706648;
loc_827066A8:
	// lwz r3,44(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// bl 0x82130588
	ctx.lr = 0x827066B0;
	sub_82130588(ctx, base);
	// stw r27,44(r28)
	PPC_STORE_U32(r28.u32 + 44, r27.u32);
	// sth r27,48(r28)
	PPC_STORE_U16(r28.u32 + 48, r27.u16);
	// sth r27,50(r28)
	PPC_STORE_U16(r28.u32 + 50, r27.u16);
loc_827066BC:
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706754
	if (cr6.eq) goto loc_82706754;
	// mr r31,r27
	r31.u64 = r27.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
loc_827066D4:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706740
	if (cr6.eq) goto loc_82706740;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r3,17892(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17892);
	// bl 0x822b61b0
	ctx.lr = 0x827066F0;
	sub_822B61B0(ctx, base);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r26,r11,r31
	r26.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82701ea0
	ctx.lr = 0x82706704;
	sub_82701EA0(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270671C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706740
	if (cr6.eq) goto loc_82706740;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82706740:
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827066d4
	if (cr6.lt) goto loc_827066D4;
loc_82706754:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8270675C;
	sub_82130588(ctx, base);
	// stw r27,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r27.u32);
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// sth r27,8(r28)
	PPC_STORE_U16(r28.u32 + 8, r27.u16);
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r27,10(r28)
	PPC_STORE_U16(r28.u32 + 10, r27.u16);
	// lhz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827067a0
	if (cr6.eq) goto loc_827067A0;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82706780:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stb r27,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r27.u8);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82706780
	if (cr6.lt) goto loc_82706780;
loc_827067A0:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r29,1
	r29.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,28(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82706830
	if (cr6.eq) goto loc_82706830;
loc_827067B8:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827067f0
	if (cr6.eq) goto loc_827067F0;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
loc_827067D0:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82706950
	if (cr6.eq) goto loc_82706950;
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x827067d0
	if (cr6.lt) goto loc_827067D0;
loc_827067F0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_827067F4:
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270680C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82706824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,28(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x827067b8
	if (!cr6.eq) goto loc_827067B8;
loc_82706830:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82706838;
	sub_82130588(ctx, base);
	// sth r27,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r27.u16);
	// addi r30,r28,32
	r30.s64 = r28.s64 + 32;
	// sth r27,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r27.u16);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stw r27,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r27.u32);
	// lhz r10,36(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706880
	if (cr6.eq) goto loc_82706880;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82706860:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stb r27,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r27.u8);
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82706860
	if (cr6.lt) goto loc_82706860;
loc_82706880:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// lwz r10,40(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270690c
	if (cr6.eq) goto loc_8270690C;
loc_82706894:
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827068cc
	if (cr6.eq) goto loc_827068CC;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
loc_827068AC:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82706974
	if (cr6.eq) goto loc_82706974;
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x827068ac
	if (cr6.lt) goto loc_827068AC;
loc_827068CC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_827068D0:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827068E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82706900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,40(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x82706894
	if (!cr6.eq) goto loc_82706894;
loc_8270690C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82706914;
	sub_82130588(ctx, base);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// stw r27,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r27.u32);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// lwz r3,224(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 224);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706944
	if (cr6.eq) goto loc_82706944;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82706944:
	// stw r27,224(r28)
	PPC_STORE_U32(r28.u32 + 224, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82706950:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stb r29,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r29.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x827067f4
	goto loc_827067F4;
loc_82706974:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// stb r29,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r29.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x827068d0
	goto loc_827068D0;
}

__attribute__((alias("__imp__sub_82706998"))) PPC_WEAK_FUNC(sub_82706998);
PPC_FUNC_IMPL(__imp__sub_82706998) {
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
	ctx.lr = 0x827069A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r26,r5,24
	r26.u64 = ctx.r5.u32 & 0xFF;
	// li r25,0
	r25.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r29,r25
	r29.u64 = r25.u64;
	// beq cr6,0x827069fc
	if (cr6.eq) goto loc_827069FC;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x827069d8
	if (cr6.eq) goto loc_827069D8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x827069dc
	if (!cr6.eq) goto loc_827069DC;
loc_827069D8:
	// li r11,1
	r11.s64 = 1;
loc_827069DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827069fc
	if (cr6.eq) goto loc_827069FC;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// bne cr6,0x827069fc
	if (!cr6.eq) goto loc_827069FC;
	// li r29,1
	r29.s64 = 1;
	// stw r25,196(r30)
	PPC_STORE_U32(r30.u32 + 196, r25.u32);
loc_827069FC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827022c8
	ctx.lr = 0x82706A08;
	sub_827022C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r28,-32111
	r28.s64 = -2104426496;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82706ab8
	if (cr6.eq) goto loc_82706AB8;
	// bl 0x82710598
	ctx.lr = 0x82706A1C;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// bne cr6,0x82706ab8
	if (!cr6.eq) goto loc_82706AB8;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82706a40
	if (!cr6.eq) goto loc_82706A40;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82705ed0
	ctx.lr = 0x82706A40;
	sub_82705ED0(ctx, base);
loc_82706A40:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706a4c
	if (cr6.eq) goto loc_82706A4C;
	// bl 0x82714f10
	ctx.lr = 0x82706A4C;
	sub_82714F10(ctx, base);
loc_82706A4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82706A64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82706a84
	if (cr6.eq) goto loc_82706A84;
	// bl 0x82256058
	ctx.lr = 0x82706A70;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706a84
	if (cr6.eq) goto loc_82706A84;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x82706A84;
	sub_827057E0(ctx, base);
loc_82706A84:
	// lwz r11,-24400(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24400);
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rotlwi r5,r10,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82706A9C;
	sub_8244D150(ctx, base);
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706ab4
	if (cr6.eq) goto loc_82706AB4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x82706ab4
	if (!cr6.eq) goto loc_82706AB4;
	// stw r25,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r25.u32);
loc_82706AB4:
	// li r29,1
	r29.s64 = 1;
loc_82706AB8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-24400(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24400);
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82706ae0
	if (!cr6.eq) goto loc_82706AE0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x82706AE0;
	sub_821F1498(ctx, base);
loc_82706AE0:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701828
	ctx.lr = 0x82706AF0;
	sub_82701828(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82706AFC"))) PPC_WEAK_FUNC(sub_82706AFC);
PPC_FUNC_IMPL(__imp__sub_82706AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82706B00"))) PPC_WEAK_FUNC(sub_82706B00);
PPC_FUNC_IMPL(__imp__sub_82706B00) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82706B08;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706cf0
	if (cr6.eq) goto loc_82706CF0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82706cf0
	if (cr6.eq) goto loc_82706CF0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82706cf0
	if (!cr6.gt) goto loc_82706CF0;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// bgt cr6,0x82706cf0
	if (cr6.gt) goto loc_82706CF0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82705ed0
	ctx.lr = 0x82706B50;
	sub_82705ED0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82714378
	ctx.lr = 0x82706B5C;
	sub_82714378(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82706b74
	if (cr6.eq) goto loc_82706B74;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
loc_82706B74:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bne cr6,0x82706bf0
	if (!cr6.eq) goto loc_82706BF0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82713fe8
	ctx.lr = 0x82706B84;
	sub_82713FE8(ctx, base);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82706b98
	if (!cr6.eq) goto loc_82706B98;
	// li r29,0
	r29.s64 = 0;
loc_82706B98:
	// lwz r31,-10016(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82706BC8;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x82704228
	ctx.lr = 0x82706BE0;
	sub_82704228(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82714070
	ctx.lr = 0x82706BE8;
	sub_82714070(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d923c
	return;
loc_82706BF0:
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// bne cr6,0x82706c6c
	if (!cr6.eq) goto loc_82706C6C;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82713fb0
	ctx.lr = 0x82706C00;
	sub_82713FB0(ctx, base);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82706c14
	if (!cr6.eq) goto loc_82706C14;
	// li r29,0
	r29.s64 = 0;
loc_82706C14:
	// lwz r31,-10016(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82706C44;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x82704228
	ctx.lr = 0x82706C5C;
	sub_82704228(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82714070
	ctx.lr = 0x82706C64;
	sub_82714070(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d923c
	return;
loc_82706C6C:
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// bne cr6,0x82706ce8
	if (!cr6.eq) goto loc_82706CE8;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82713fb0
	ctx.lr = 0x82706C7C;
	sub_82713FB0(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82714428
	ctx.lr = 0x82706C84;
	sub_82714428(ctx, base);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// addi r29,r1,240
	r29.s64 = ctx.r1.s64 + 240;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82706c98
	if (!cr6.eq) goto loc_82706C98;
	// li r29,0
	r29.s64 = 0;
loc_82706C98:
	// lwz r31,-10016(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82706CC8;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x82704228
	ctx.lr = 0x82706CE0;
	sub_82704228(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82714070
	ctx.lr = 0x82706CE8;
	sub_82714070(ctx, base);
loc_82706CE8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82714070
	ctx.lr = 0x82706CF0;
	sub_82714070(ctx, base);
loc_82706CF0:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82706CF8"))) PPC_WEAK_FUNC(sub_82706CF8);
PPC_FUNC_IMPL(__imp__sub_82706CF8) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82706D00;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706f38
	if (cr6.eq) goto loc_82706F38;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82706f38
	if (cr6.eq) goto loc_82706F38;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,22488
	ctx.r4.s64 = ctx.r10.s64 + 22488;
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
	// bctrl 
	ctx.lr = 0x82706D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// bl 0x82705ed0
	ctx.lr = 0x82706D54;
	sub_82705ED0(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82706d64
	if (cr6.eq) goto loc_82706D64;
	// stb r28,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r28.u8);
loc_82706D64:
	// lwz r10,-10016(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lwz r11,68(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706da0
	if (cr6.eq) goto loc_82706DA0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82706da0
	if (cr6.eq) goto loc_82706DA0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82706da0
	if (cr6.eq) goto loc_82706DA0;
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82706da0
	if (cr6.eq) goto loc_82706DA0;
	// lwz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// sth r10,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r10.u16);
loc_82706DA0:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82713fe8
	ctx.lr = 0x82706DA8;
	sub_82713FE8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,436(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 436);
	f0.f64 = double(temp.f32);
	// lwz r31,-10016(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,216(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82706DF0;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82704228
	ctx.lr = 0x82706E08;
	sub_82704228(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82706e54
	if (cr6.eq) goto loc_82706E54;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82706e54
	if (!cr6.gt) goto loc_82706E54;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82706e54
	if (cr6.eq) goto loc_82706E54;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82706E38;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// li r10,912
	ctx.r10.s64 = 912;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270c408
	ctx.lr = 0x82706E54;
	sub_8270C408(ctx, base);
loc_82706E54:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82224ac8
	ctx.lr = 0x82706E5C;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82706f38
	if (cr6.eq) goto loc_82706F38;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706e8c
	if (cr6.eq) goto loc_82706E8C;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x82706e90
	if (!cr6.eq) goto loc_82706E90;
loc_82706E8C:
	// li r11,0
	r11.s64 = 0;
loc_82706E90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82706f38
	if (!cr6.eq) goto loc_82706F38;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82706f38
	if (cr6.eq) goto loc_82706F38;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82706f38
	if (!cr6.gt) goto loc_82706F38;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82706f38
	if (cr6.eq) goto loc_82706F38;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r6,r10,3998
	ctx.r6.s64 = ctx.r10.s64 + 3998;
	// addi r5,r9,-10052
	ctx.r5.s64 = ctx.r9.s64 + -10052;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// addi r4,r8,22460
	ctx.r4.s64 = ctx.r8.s64 + 22460;
	// bl 0x821f3628
	ctx.lr = 0x82706EE4;
	sub_821F3628(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x827143d0
	ctx.lr = 0x82706EEC;
	sub_827143D0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82224ac8
	ctx.lr = 0x82706EF4;
	sub_82224AC8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82706f04
	if (cr6.eq) goto loc_82706F04;
	// stb r28,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r28.u8);
loc_82706F04:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82706f1c
	if (!cr6.gt) goto loc_82706F1C;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82706f20
	goto loc_82706F20;
loc_82706F1C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82706F20:
	// bl 0x8270c2d8
	ctx.lr = 0x82706F24;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82714080
	ctx.lr = 0x82706F30;
	sub_82714080(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82714070
	ctx.lr = 0x82706F38;
	sub_82714070(ctx, base);
loc_82706F38:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82706F40"))) PPC_WEAK_FUNC(sub_82706F40);
PPC_FUNC_IMPL(__imp__sub_82706F40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82706F48;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d8
	ctx.lr = 0x82706F50;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82707140
	if (cr6.eq) goto loc_82707140;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82706f94
	if (cr6.eq) goto loc_82706F94;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827022c8
	ctx.lr = 0x82706F8C;
	sub_827022C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82707140
	if (!cr6.eq) goto loc_82707140;
loc_82706F94:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82701080
	ctx.lr = 0x82706F9C;
	sub_82701080(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82706fbc
	if (cr6.eq) goto loc_82706FBC;
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x82706fcc
	goto loc_82706FCC;
loc_82706FBC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822a8108
	ctx.lr = 0x82706FC4;
	sub_822A8108(ctx, base);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
loc_82706FCC:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82707140
	if (!cr6.gt) goto loc_82707140;
	// lfs f30,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// lfs f29,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f29.f64 = double(temp.f32);
	// lfs f28,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f28.f64 = double(temp.f32);
loc_82706FF0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827010e8
	ctx.lr = 0x82706FFC;
	sub_827010E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,880(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827070a0
	if (!cr6.eq) goto loc_827070A0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82701de0
	ctx.lr = 0x82707018;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827070a0
	if (!cr6.eq) goto loc_827070A0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x82707060
	if (!cr6.eq) goto loc_82707060;
	// mr r27,r30
	r27.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82707034;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 - f29.f64));
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 - f28.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f31,f9,f9,f7
	f31.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// b 0x8270709c
	goto loc_8270709C;
loc_82707060:
	// bl 0x822a8108
	ctx.lr = 0x82707064;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 - f29.f64));
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f28
	ctx.f9.f64 = double(float(ctx.f10.f64 - f28.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f0,f9,f9,f7
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8270709c
	if (!cr6.lt) goto loc_8270709C;
	// mr r27,r30
	r27.u64 = r30.u64;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_8270709C:
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
loc_827070A0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// blt cr6,0x82706ff0
	if (cr6.lt) goto loc_82706FF0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82707140
	if (cr6.eq) goto loc_82707140;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82714020
	ctx.lr = 0x827070BC;
	sub_82714020(ctx, base);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lbz r31,222(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 222);
	// lbz r30,221(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 221);
	// lbz r28,220(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// beq cr6,0x827070f4
	if (cr6.eq) goto loc_827070F4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82705ed0
	ctx.lr = 0x827070E8;
	sub_82705ED0(ctx, base);
	// lwz r11,-10016(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// b 0x827070fc
	goto loc_827070FC;
loc_827070F4:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_827070FC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r28,109(r1)
	PPC_STORE_U8(ctx.r1.u32 + 109, r28.u8);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r8,108(r1)
	PPC_STORE_U8(ctx.r1.u32 + 108, ctx.r8.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,110(r1)
	PPC_STORE_U8(ctx.r1.u32 + 110, r30.u8);
	// stb r31,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r31.u8);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r24,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r24.u32);
	// bl 0x82704228
	ctx.lr = 0x82707140;
	sub_82704228(ctx, base);
loc_82707140:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba24
	ctx.lr = 0x82707154;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82707158"))) PPC_WEAK_FUNC(sub_82707158);
PPC_FUNC_IMPL(__imp__sub_82707158) {
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
	ctx.lr = 0x82707160;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82707200
	if (cr6.eq) goto loc_82707200;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827071c8
	if (cr6.eq) goto loc_827071C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82707198;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827071c8
	if (cr6.eq) goto loc_827071C8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x827071B0;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82706998
	ctx.lr = 0x827071C0;
	sub_82706998(ctx, base);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_827071C8:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707200
	if (cr6.eq) goto loc_82707200;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707200
	if (cr6.eq) goto loc_82707200;
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x82707200
	if (!cr6.gt) goto loc_82707200;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82707200
	if (cr6.eq) goto loc_82707200;
	// bl 0x826b94a8
	ctx.lr = 0x82707200;
	sub_826B94A8(ctx, base);
loc_82707200:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82707208"))) PPC_WEAK_FUNC(sub_82707208);
PPC_FUNC_IMPL(__imp__sub_82707208) {
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
	// bl 0x823d91c0
	ctx.lr = 0x82707210;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d0
	ctx.lr = 0x82707218;
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lbz r10,-6732(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6732);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82707330
	if (!cr6.eq) goto loc_82707330;
	// lwz r11,196(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 196);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82707448
	if (cr6.eq) goto loc_82707448;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82707340
	if (cr6.eq) goto loc_82707340;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82707330
	if (!cr6.eq) goto loc_82707330;
	// lfs f0,212(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 212);
	f0.f64 = double(temp.f32);
	// lwz r30,200(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 200);
	// fsubs f0,f0,f1
	f0.f64 = double(float(f0.f64 - ctx.f1.f64));
	// stfs f0,212(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 212, temp.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x82707288
	if (cr6.lt) goto loc_82707288;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826ffea0
	ctx.lr = 0x8270727C;
	sub_826FFEA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
loc_82707288:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,196(r25)
	PPC_STORE_U32(r25.u32 + 196, r11.u32);
	// lwz r3,-10016(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82705ed0
	ctx.lr = 0x827072A8;
	sub_82705ED0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82714378
	ctx.lr = 0x827072B4;
	sub_82714378(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827072cc
	if (cr6.eq) goto loc_827072CC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
loc_827072CC:
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82713fb0
	ctx.lr = 0x827072D4;
	sub_82713FB0(ctx, base);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82714428
	ctx.lr = 0x827072DC;
	sub_82714428(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82707308;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82704228
	ctx.lr = 0x82707320;
	sub_82704228(ctx, base);
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
loc_82707324:
	// bl 0x82714070
	ctx.lr = 0x82707328;
	sub_82714070(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
loc_8270732C:
	// bl 0x82714070
	ctx.lr = 0x82707330;
	sub_82714070(ctx, base);
loc_82707330:
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba1c
	ctx.lr = 0x8270733C;
	// b 0x823d9210
	return;
loc_82707340:
	// lwz r30,200(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 200);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82707404
	if (cr6.eq) goto loc_82707404;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826ffea0
	ctx.lr = 0x82707358;
	sub_826FFEA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707404
	if (cr6.eq) goto loc_82707404;
	// li r11,0
	r11.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r11,196(r25)
	PPC_STORE_U32(r25.u32 + 196, r11.u32);
	// lwz r3,-10016(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// bl 0x82705ed0
	ctx.lr = 0x82707380;
	sub_82705ED0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82714378
	ctx.lr = 0x8270738C;
	sub_82714378(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827073a4
	if (cr6.eq) goto loc_827073A4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// stw r9,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r9.u32);
loc_827073A4:
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82713fb0
	ctx.lr = 0x827073AC;
	sub_82713FB0(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82714428
	ctx.lr = 0x827073B4;
	sub_82714428(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r31,-10016(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10016);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,222(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 222);
	// lbz r9,221(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 221);
	// lbz r8,220(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x827073E4;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82704228
	ctx.lr = 0x827073FC;
	sub_82704228(ctx, base);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// b 0x82707324
	goto loc_82707324;
loc_82707404:
	// lfs f0,212(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 212);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 - ctx.f1.f64));
	// stfs f13,212(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r25.u32 + 212, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82707330
	if (!cr6.lt) goto loc_82707330;
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r10,196(r25)
	PPC_STORE_U32(r25.u32 + 196, ctx.r10.u32);
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// lfs f0,392(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 392);
	f0.f64 = double(temp.f32);
	// stfs f0,212(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 212, temp.u32);
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba1c
	ctx.lr = 0x82707444;
	// b 0x823d9210
	return;
loc_82707448:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// bl 0x822a39c0
	ctx.lr = 0x8270745C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// lwz r11,188(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82707330
	if (cr6.lt) goto loc_82707330;
	// lhz r10,184(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 184);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82707330
	if (!cr6.lt) goto loc_82707330;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82707488;
	sub_822A39C8(ctx, base);
	// bl 0x822a8628
	ctx.lr = 0x8270748C;
	sub_822A8628(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r6,264(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// beq cr6,0x82707330
	if (cr6.eq) goto loc_82707330;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// lfs f27,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f27.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f28,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f28.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f26,23092(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 23092);
	f26.f64 = double(temp.f32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f29,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r16,0
	r16.s64 = 0;
	// ori r20,r5,64167
	r20.u64 = ctx.r5.u64 | 64167;
	// lis r21,-32121
	r21.s64 = -2105081856;
	// lis r17,-32121
	r17.s64 = -2105081856;
	// addi r22,r11,-13624
	r22.s64 = r11.s64 + -13624;
	// addi r24,r10,2192
	r24.s64 = ctx.r10.s64 + 2192;
	// addi r15,r9,22584
	r15.s64 = ctx.r9.s64 + 22584;
	// addi r18,r8,22556
	r18.s64 = ctx.r8.s64 + 22556;
	// addi r19,r7,22496
	r19.s64 = ctx.r7.s64 + 22496;
loc_8270750C:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// bl 0x82215e10
	ctx.lr = 0x8270751C;
	sub_82215E10(ctx, base);
	// lwz r11,188(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 188);
	// lwz r10,180(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 180);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x822a8108
	ctx.lr = 0x82707534;
	sub_822A8108(ctx, base);
	// addi r8,r3,48
	ctx.r8.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,188(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 188);
	// lwz r11,180(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 180);
	// lfs f12,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f11,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lfs f5,16(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f5,f5
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fmuls f3,f10,f10
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f2,f8,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fmadds f1,f6,f6,f2
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f4
	cr6.compare(ctx.f1.f64, ctx.f4.f64);
	// bge cr6,0x827078c8
	if (!cr6.lt) goto loc_827078C8;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f4,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfd f4,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f4.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// stfd f3,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f3.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f2,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f2.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f1,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f1.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// bl 0x82130000
	ctx.lr = 0x827075CC;
	sub_82130000(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82714ba8
	ctx.lr = 0x827075D4;
	sub_82714BA8(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x827075D8;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82707628
	if (!cr6.eq) goto loc_82707628;
	// bl 0x82256058
	ctx.lr = 0x827075E8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82707628
	if (cr6.eq) goto loc_82707628;
	// bl 0x82256058
	ctx.lr = 0x827075F4;
	sub_82256058(ctx, base);
	// lwz r11,3088(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3088);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82707628
	if (!cr6.gt) goto loc_82707628;
	// bl 0x82256058
	ctx.lr = 0x82707604;
	sub_82256058(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707628
	if (cr6.eq) goto loc_82707628;
	// bl 0x82256058
	ctx.lr = 0x82707614;
	sub_82256058(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// stw r18,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r18.u32);
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// stw r11,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r11.u32);
	// b 0x8270762c
	goto loc_8270762C;
loc_82707628:
	// stw r15,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r15.u32);
loc_8270762C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827010e8
	ctx.lr = 0x82707638;
	sub_827010E8(ctx, base);
	// bl 0x8270c2d8
	ctx.lr = 0x8270763C;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82714080
	ctx.lr = 0x82707648;
	sub_82714080(ctx, base);
	// lwz r7,208(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 208);
	// li r11,2
	r11.s64 = 2;
	// stfs f26,212(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r25.u32 + 212, temp.u32);
	// stw r16,200(r25)
	PPC_STORE_U32(r25.u32 + 200, r16.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,196(r25)
	PPC_STORE_U32(r25.u32 + 196, r11.u32);
	// beq cr6,0x827076d0
	if (cr6.eq) goto loc_827076D0;
	// lwz r11,17892(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 17892);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827076d0
	if (cr6.eq) goto loc_827076D0;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// mr r9,r16
	ctx.r9.u64 = r16.u64;
	// lbzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82707690
	if (cr6.eq) goto loc_82707690;
	// lwz r8,804(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x82707694
	goto loc_82707694;
loc_82707690:
	// lwz r8,400(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_82707694:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x827076d0
	if (!cr6.gt) goto loc_827076D0;
loc_8270769C:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x827076ac
	if (cr6.eq) goto loc_827076AC;
	// lwz r10,404(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// b 0x827076b0
	goto loc_827076B0;
loc_827076AC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_827076B0:
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// beq cr6,0x827076cc
	if (cr6.eq) goto loc_827076CC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8270769c
	if (cr6.lt) goto loc_8270769C;
	// b 0x827076d0
	goto loc_827076D0;
loc_827076CC:
	// stw r7,200(r25)
	PPC_STORE_U32(r25.u32 + 200, ctx.r7.u32);
loc_827076D0:
	// lwz r11,200(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827078b4
	if (!cr6.eq) goto loc_827078B4;
	// lwz r11,204(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 204);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x827076f4
	if (cr6.lt) goto loc_827076F4;
	// beq cr6,0x827078b0
	if (cr6.eq) goto loc_827078B0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x827078b4
	if (!cr6.lt) goto loc_827078B4;
loc_827076F4:
	// lwz r8,-5148(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + -5148);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x827078b0
	if (cr6.eq) goto loc_827078B0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82707764
	if (cr6.eq) goto loc_82707764;
	// lwz r7,0(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// mulld r10,r7,r20
	ctx.r10.s64 = ctx.r7.s64 * r20.s64;
	// lwz r9,420(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 420);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// extsw r6,r9
	ctx.r6.s64 = ctx.r9.s32;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r4,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r11,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r11.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmuls f8,f10,f27
	ctx.f8.f64 = double(float(ctx.f10.f64 * f27.f64));
	// fmuls f7,f9,f28
	ctx.f7.f64 = double(float(ctx.f9.f64 * f28.f64));
	// fcmpu cr6,f7,f8
	cr6.compare(ctx.f7.f64, ctx.f8.f64);
	// bge cr6,0x827078b0
	if (!cr6.lt) goto loc_827078B0;
loc_82707764:
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707780
	if (cr6.eq) goto loc_82707780;
	// lhz r31,20(r8)
	r31.u64 = PPC_LOAD_U16(ctx.r8.u32 + 20);
	// b 0x82707784
	goto loc_82707784;
loc_82707780:
	// lhz r31,12(r8)
	r31.u64 = PPC_LOAD_U16(ctx.r8.u32 + 12);
loc_82707784:
	// lfs f0,424(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 424);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// fmuls f30,f0,f0
	f30.f64 = double(float(f0.f64 * f0.f64));
	// ble cr6,0x827078b0
	if (!cr6.gt) goto loc_827078B0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827077a4
	if (cr6.eq) goto loc_827077A4;
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// b 0x827077a8
	goto loc_827077A8;
loc_827077A4:
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
loc_827077A8:
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x827078b0
	if (cr6.eq) goto loc_827078B0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a8108
	ctx.lr = 0x827077BC;
	sub_822A8108(ctx, base);
	// addi r30,r3,48
	r30.s64 = ctx.r3.s64 + 48;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822a8108
	ctx.lr = 0x827077C8;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f31,f6,f6,f4
	f31.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// ble cr6,0x82707898
	if (!cr6.gt) goto loc_82707898;
	// li r30,4
	r30.s64 = 4;
	// addi r29,r31,-1
	r29.s64 = r31.s64 + -1;
loc_8270780C:
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-5148(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -5148);
	// beq cr6,0x82707824
	if (cr6.eq) goto loc_82707824;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x82707828
	goto loc_82707828;
loc_82707824:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82707828:
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270788c
	if (cr6.eq) goto loc_8270788C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270783C;
	sub_822A8108(ctx, base);
	// addi r14,r3,48
	r14.s64 = ctx.r3.s64 + 48;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x822a8108
	ctx.lr = 0x82707848;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f0,f6,f6,f4
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8270788c
	if (!cr6.lt) goto loc_8270788C;
	// mr r28,r31
	r28.u64 = r31.u64;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_8270788C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8270780c
	if (!cr0.eq) goto loc_8270780C;
loc_82707898:
	// lfs f0,424(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 424);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// blt cr6,0x827078ac
	if (cr6.lt) goto loc_827078AC;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bge cr6,0x827078b0
	if (!cr6.lt) goto loc_827078B0;
loc_827078AC:
	// mr r23,r28
	r23.u64 = r28.u64;
loc_827078B0:
	// stw r23,200(r25)
	PPC_STORE_U32(r25.u32 + 200, r23.u32);
loc_827078B4:
	// lwz r11,200(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 200);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270732c
	if (!cr6.eq) goto loc_8270732C;
	// bl 0x82714070
	ctx.lr = 0x827078C8;
	sub_82714070(ctx, base);
loc_827078C8:
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8270750c
	if (!cr6.eq) goto loc_8270750C;
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba1c
	ctx.lr = 0x827078E0;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827078E4"))) PPC_WEAK_FUNC(sub_827078E4);
PPC_FUNC_IMPL(__imp__sub_827078E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827078E8"))) PPC_WEAK_FUNC(sub_827078E8);
PPC_FUNC_IMPL(__imp__sub_827078E8) {
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
	// bl 0x823d91c0
	ctx.lr = 0x827078F0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9c8
	ctx.lr = 0x827078F8;
	// stwu r1,-1056(r1)
	ea = -1056 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82708c54
	if (cr6.eq) goto loc_82708C54;
	// bl 0x822a39c0
	ctx.lr = 0x82707918;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708c54
	if (cr6.eq) goto loc_82708C54;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// lwz r11,264(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// beq cr6,0x82708c54
	if (cr6.eq) goto loc_82708C54;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r18,-32244
	r18.s64 = -2113142784;
	// lis r21,-32244
	r21.s64 = -2113142784;
	// lis r25,-32244
	r25.s64 = -2113142784;
	// addi r11,r11,23028
	r11.s64 = r11.s64 + 23028;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r10,r18,23012
	ctx.r10.s64 = r18.s64 + 23012;
	// lis r26,-32244
	r26.s64 = -2113142784;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// addi r10,r21,-9756
	ctx.r10.s64 = r21.s64 + -9756;
	// lis r22,-32244
	r22.s64 = -2113142784;
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// addi r10,r9,23044
	ctx.r10.s64 = ctx.r9.s64 + 23044;
	// addi r9,r25,22996
	ctx.r9.s64 = r25.s64 + 22996;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lis r28,-32244
	r28.s64 = -2113142784;
	// stw r9,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// addi r11,r26,22980
	r11.s64 = r26.s64 + 22980;
	// addi r6,r22,22584
	ctx.r6.s64 = r22.s64 + 22584;
	// addi r9,r28,22964
	ctx.r9.s64 = r28.s64 + 22964;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// lis r27,-32244
	r27.s64 = -2113142784;
	// lfs f24,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f24.f64 = double(temp.f32);
	// lis r29,-32244
	r29.s64 = -2113142784;
	// stw r9,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r9.u32);
	// lis r17,-32244
	r17.s64 = -2113142784;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// lis r15,-32244
	r15.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r10,r27,22952
	ctx.r10.s64 = r27.s64 + 22952;
	// addi r11,r29,22936
	r11.s64 = r29.s64 + 22936;
	// addi r8,r17,22916
	ctx.r8.s64 = r17.s64 + 22916;
	// stw r10,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r10.u32);
	// addi r6,r15,22900
	ctx.r6.s64 = r15.s64 + 22900;
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r11.u32);
	// addi r9,r3,22884
	ctx.r9.s64 = ctx.r3.s64 + 22884;
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// lis r20,-32244
	r20.s64 = -2113142784;
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// lis r31,-32244
	r31.s64 = -2113142784;
	// stw r9,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r16,-32244
	r16.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// addi r22,r20,-9724
	r22.s64 = r20.s64 + -9724;
	// addi r10,r31,22872
	ctx.r10.s64 = r31.s64 + 22872;
	// addi r11,r7,22856
	r11.s64 = ctx.r7.s64 + 22856;
	// stw r22,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r22.u32);
	// lis r23,-32125
	r23.s64 = -2105344000;
	// stw r10,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r10.u32);
	// lis r19,-32244
	r19.s64 = -2113142784;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// lis r14,-32244
	r14.s64 = -2113142784;
	// lis r24,-32244
	r24.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r21,r16,22836
	r21.s64 = r16.s64 + 22836;
	// addi r4,r4,22820
	ctx.r4.s64 = ctx.r4.s64 + 22820;
	// addi r3,r5,22804
	ctx.r3.s64 = ctx.r5.s64 + 22804;
	// stw r21,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r21.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r4,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r4.u32);
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r23,r23,-13624
	r23.s64 = r23.s64 + -13624;
	// addi r22,r19,22788
	r22.s64 = r19.s64 + 22788;
	// addi r14,r14,22772
	r14.s64 = r14.s64 + 22772;
	// addi r15,r24,22756
	r15.s64 = r24.s64 + 22756;
	// addi r18,r6,22740
	r18.s64 = ctx.r6.s64 + 22740;
	// addi r17,r8,22724
	r17.s64 = ctx.r8.s64 + 22724;
	// addi r9,r9,22708
	ctx.r9.s64 = ctx.r9.s64 + 22708;
	// addi r16,r11,22612
	r16.s64 = r11.s64 + 22612;
	// lwz r26,96(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r20,r10,22632
	r20.s64 = ctx.r10.s64 + 22632;
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
loc_82707AA0:
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// bge cr6,0x82708c54
	if (!cr6.lt) goto loc_82708C54;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,264
	ctx.r3.s64 = ctx.r1.s64 + 264;
	// mr r24,r11
	r24.u64 = r11.u64;
	// bl 0x82215e10
	ctx.lr = 0x82707AB8;
	sub_82215E10(ctx, base);
	// mulli r11,r26,68
	r11.s64 = r26.s64 * 68;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// ble cr6,0x82707ae4
	if (!cr6.gt) goto loc_82707AE4;
	// lhz r11,488(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,484(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 484);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82707AE0;
	sub_8244D150(ctx, base);
	// b 0x82708c48
	goto loc_82708C48;
loc_82707AE4:
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704f88
	ctx.lr = 0x82707B10;
	sub_82704F88(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827022c8
	ctx.lr = 0x82707B1C;
	sub_827022C8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82707b58
	if (cr6.eq) goto loc_82707B58;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82707B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82707b58
	if (cr6.eq) goto loc_82707B58;
	// lwz r11,72(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82707b58
	if (!cr6.gt) goto loc_82707B58;
	// lwz r11,76(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 76);
	// lwz r21,0(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82707b5c
	goto loc_82707B5C;
loc_82707B58:
	// li r21,0
	r21.s64 = 0;
loc_82707B5C:
	// li r19,0
	r19.s64 = 0;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x82707c30
	if (!cr6.eq) goto loc_82707C30;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82702a28
	ctx.lr = 0x82707B80;
	sub_82702A28(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x82707c30
	if (!cr6.eq) goto loc_82707C30;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707c28
	if (cr6.eq) goto loc_82707C28;
	// li r29,0
	r29.s64 = 0;
loc_82707BA0:
	// lwz r28,4(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r11,r29,r28
	r11.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707c04
	if (cr6.eq) goto loc_82707C04;
	// rotlwi r4,r11,0
	ctx.r4.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lbz r11,872(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707c04
	if (cr6.eq) goto loc_82707C04;
	// lbz r11,1072(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707c04
	if (cr6.eq) goto loc_82707C04;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82701de0
	ctx.lr = 0x82707BD4;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82707c04
	if (!cr6.eq) goto loc_82707C04;
	// lwz r11,48(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82707c04
	if (cr6.eq) goto loc_82707C04;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwzx r3,r29,r28
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x822aafc8
	ctx.lr = 0x82707BF8;
	sub_822AAFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82707c1c
	if (!cr6.eq) goto loc_82707C1C;
loc_82707C04:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82707ba0
	if (cr6.lt) goto loc_82707BA0;
	// b 0x827083f4
	goto loc_827083F4;
loc_82707C1C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r19,r10,r11
	r19.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_82707C28:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x827083f4
	if (cr6.eq) goto loc_827083F4;
loc_82707C30:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82707d80
	if (cr6.eq) goto loc_82707D80;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82707cf8
	if (cr6.eq) goto loc_82707CF8;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x82707ff0
	if (!cr6.gt) goto loc_82707FF0;
	// lfs f30,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f30.f64 = double(temp.f32);
	// lfs f29,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f29.f64 = double(temp.f32);
	// lfs f28,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f28.f64 = double(temp.f32);
	// lfs f27,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f27.f64 = double(temp.f32);
	// lfs f26,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f26.f64 = double(temp.f32);
loc_82707C7C:
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,32(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82705da0
	ctx.lr = 0x82707C9C;
	sub_82705DA0(ctx, base);
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f30.f64;
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// li r4,2
	ctx.r4.s64 = 2;
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// li r3,2
	ctx.r3.s64 = 2;
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x82707CE8;
	sub_82130000(ctx, base);
	// lfs f12,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82707c7c
	if (cr6.gt) goto loc_82707C7C;
	// b 0x82707ff0
	goto loc_82707FF0;
loc_82707CF8:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,160(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// ori r8,r9,2
	ctx.r8.u64 = ctx.r9.u64 | 2;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// ori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 | 1;
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// lwz r5,28(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 28);
	// bl 0x82705da0
	ctx.lr = 0x82707D30;
	sub_82705DA0(ctx, base);
	// lfs f5,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f4.f64 = double(temp.f32);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// li r3,2
	ctx.r3.s64 = 2;
	// lfs f2,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// bl 0x82130000
	ctx.lr = 0x82707D7C;
	sub_82130000(ctx, base);
	// b 0x82707ff0
	goto loc_82707FF0;
loc_82707D80:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82707ec0
	if (cr6.eq) goto loc_82707EC0;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82707e44
	if (cr6.eq) goto loc_82707E44;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x82707ff0
	if (!cr6.gt) goto loc_82707FF0;
	// lfs f30,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f30.f64 = double(temp.f32);
	// lfs f29,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f29.f64 = double(temp.f32);
	// lfs f28,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f28.f64 = double(temp.f32);
	// lfs f27,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f27.f64 = double(temp.f32);
	// lfs f26,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f26.f64 = double(temp.f32);
loc_82707DC8:
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,40(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 40);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82705da0
	ctx.lr = 0x82707DE8;
	sub_82705DA0(ctx, base);
	// fmr f4,f29
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f29.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// bl 0x82130000
	ctx.lr = 0x82707E34;
	sub_82130000(ctx, base);
	// lfs f12,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82707dc8
	if (cr6.gt) goto loc_82707DC8;
	// b 0x82707ff0
	goto loc_82707FF0;
loc_82707E44:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,140(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// lwz r5,36(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 36);
	// bl 0x82705da0
	ctx.lr = 0x82707E70;
	sub_82705DA0(ctx, base);
	// lfs f5,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// lfs f4,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f4.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// li r3,2
	ctx.r3.s64 = 2;
	// lfs f2,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// bl 0x82130000
	ctx.lr = 0x82707EBC;
	sub_82130000(ctx, base);
	// b 0x82707ff0
	goto loc_82707FF0;
loc_82707EC0:
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82707ff0
	if (cr6.eq) goto loc_82707FF0;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82707f84
	if (cr6.eq) goto loc_82707F84;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x82707ff0
	if (!cr6.gt) goto loc_82707FF0;
	// lfs f30,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f30.f64 = double(temp.f32);
	// lfs f29,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f29.f64 = double(temp.f32);
	// lfs f28,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f28.f64 = double(temp.f32);
	// lfs f27,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f27.f64 = double(temp.f32);
	// lfs f26,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f26.f64 = double(temp.f32);
loc_82707F08:
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,48(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82705da0
	ctx.lr = 0x82707F28;
	sub_82705DA0(ctx, base);
	// fmr f3,f28
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f28.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,2
	ctx.r3.s64 = 2;
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// bl 0x82130000
	ctx.lr = 0x82707F74;
	sub_82130000(ctx, base);
	// lfs f12,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82707f08
	if (cr6.gt) goto loc_82707F08;
	// b 0x82707ff0
	goto loc_82707FF0;
loc_82707F84:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,200(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r5,44(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 44);
	// bl 0x82705da0
	ctx.lr = 0x82707FA4;
	sub_82705DA0(ctx, base);
	// lfs f4,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f4.f64 = double(temp.f32);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f5,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stfd f4,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f4.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f5,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.f5.u64);
	// ld r10,72(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 72);
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// bl 0x82130000
	ctx.lr = 0x82707FF0;
	sub_82130000(ctx, base);
loc_82707FF0:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708078
	if (cr6.eq) goto loc_82708078;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708058
	if (cr6.eq) goto loc_82708058;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x82708078
	if (!cr6.gt) goto loc_82708078;
loc_82708028:
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,188(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r5,56(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 56);
	// bl 0x82705da0
	ctx.lr = 0x82708048;
	sub_82705DA0(ctx, base);
	// lfs f12,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82708028
	if (cr6.gt) goto loc_82708028;
	// b 0x82708078
	goto loc_82708078;
loc_82708058:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,152(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r5,52(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 52);
	// bl 0x82705da0
	ctx.lr = 0x82708078;
	sub_82705DA0(ctx, base);
loc_82708078:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827080a8
	if (cr6.eq) goto loc_827080A8;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r5,60(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 60);
	// bl 0x82705da0
	ctx.lr = 0x827080A8;
	sub_82705DA0(ctx, base);
loc_827080A8:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827080cc
	if (!cr6.eq) goto loc_827080CC;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708108
	if (cr6.eq) goto loc_82708108;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827080e8
	if (cr6.eq) goto loc_827080E8;
loc_827080CC:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// b 0x827080f4
	goto loc_827080F4;
loc_827080E8:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
loc_827080F4:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r5,64(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,180(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x82705da0
	ctx.lr = 0x82708108;
	sub_82705DA0(ctx, base);
loc_82708108:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708138
	if (cr6.eq) goto loc_82708138;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,164(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r5,68(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 68);
	// bl 0x82705da0
	ctx.lr = 0x82708138;
	sub_82705DA0(ctx, base);
loc_82708138:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708168
	if (cr6.eq) goto loc_82708168;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,196(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// lwz r5,76(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 76);
	// bl 0x82705da0
	ctx.lr = 0x82708168;
	sub_82705DA0(ctx, base);
loc_82708168:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827081f4
	if (cr6.eq) goto loc_827081F4;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827081d0
	if (cr6.eq) goto loc_827081D0;
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x827081f4
	if (!cr6.gt) goto loc_827081F4;
loc_827081A0:
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f0.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,172(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// lwz r5,84(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 84);
	// bl 0x82705da0
	ctx.lr = 0x827081C0;
	sub_82705DA0(ctx, base);
	// lfs f12,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x827081a0
	if (cr6.gt) goto loc_827081A0;
	// b 0x827081f4
	goto loc_827081F4;
loc_827081D0:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,148(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// ori r10,r11,1024
	ctx.r10.u64 = r11.u64 | 1024;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// stfs f24,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// lwz r5,80(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 80);
	// bl 0x82705da0
	ctx.lr = 0x827081F4;
	sub_82705DA0(ctx, base);
loc_827081F4:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270828c
	if (cr6.eq) goto loc_8270828C;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	// addi r11,r26,2
	r11.s64 = r26.s64 + 2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708264
	if (cr6.eq) goto loc_82708264;
	// mulli r29,r11,68
	r29.s64 = r11.s64 * 68;
	// lfsx f0,r29,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfsx f13,r29,r30
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + r30.u32, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8270828c
	if (!cr6.gt) goto loc_8270828C;
loc_82708234:
	// lfsx f0,r29,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + r30.u32);
	f0.f64 = double(temp.f32);
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfsx f13,r29,r30
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + r30.u32, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,92(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 92);
	// bl 0x82705da0
	ctx.lr = 0x82708254;
	sub_82705DA0(ctx, base);
	// lfsx f12,r29,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + r30.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82708234
	if (cr6.gt) goto loc_82708234;
	// b 0x8270828c
	goto loc_8270828C;
loc_82708264:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mulli r9,r11,68
	ctx.r9.s64 = r11.s64 * 68;
	// lwz r6,144(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// ori r8,r10,2048
	ctx.r8.u64 = ctx.r10.u64 | 2048;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
	// stfsx f24,r9,r30
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,88(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 88);
	// bl 0x82705da0
	ctx.lr = 0x8270828C;
	sub_82705DA0(ctx, base);
loc_8270828C:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827082d4
	if (cr6.eq) goto loc_827082D4;
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827082dc
	if (!cr6.eq) goto loc_827082DC;
	// li r11,1
	r11.s64 = 1;
	// lwz r6,136(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// ori r9,r10,4096
	ctx.r9.u64 = ctx.r10.u64 | 4096;
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// lwz r5,96(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 96);
	// bl 0x82705da0
	ctx.lr = 0x827082D0;
	sub_82705DA0(ctx, base);
	// b 0x827082dc
	goto loc_827082DC;
loc_827082D4:
	// li r11,0
	r11.s64 = 0;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
loc_827082DC:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708368
	if (cr6.eq) goto loc_82708368;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82708344
	if (cr6.eq) goto loc_82708344;
	// lfs f0,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x82708368
	if (!cr6.gt) goto loc_82708368;
loc_82708314:
	// lfs f0,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,104(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 104);
	// bl 0x82705da0
	ctx.lr = 0x82708334;
	sub_82705DA0(ctx, base);
	// lfs f12,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82708314
	if (cr6.gt) goto loc_82708314;
	// b 0x82708368
	goto loc_82708368;
loc_82708344:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,168(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// ori r10,r11,8192
	ctx.r10.u64 = r11.u64 | 8192;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// stfs f24,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// lwz r5,100(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 100);
	// bl 0x82705da0
	ctx.lr = 0x82708368;
	sub_82705DA0(ctx, base);
loc_82708368:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827083f4
	if (cr6.eq) goto loc_827083F4;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827083d0
	if (cr6.eq) goto loc_827083D0;
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,148(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x827083f4
	if (!cr6.gt) goto loc_827083F4;
loc_827083A0:
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	f0.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,148(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,176(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r5,112(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 112);
	// bl 0x82705da0
	ctx.lr = 0x827083C0;
	sub_82705DA0(ctx, base);
	// lfs f12,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x827083a0
	if (cr6.gt) goto loc_827083A0;
	// b 0x827083f4
	goto loc_827083F4;
loc_827083D0:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,184(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// ori r10,r11,16384
	ctx.r10.u64 = r11.u64 | 16384;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// stfs f24,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// lwz r5,108(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 108);
	// bl 0x82705da0
	ctx.lr = 0x827083F4;
	sub_82705DA0(ctx, base);
loc_827083F4:
	// bl 0x82256058
	ctx.lr = 0x827083F8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270855c
	if (cr6.eq) goto loc_8270855C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8270855c
	if (!cr6.eq) goto loc_8270855C;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82708424
	if (!cr6.eq) goto loc_82708424;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270855c
	if (cr6.eq) goto loc_8270855C;
loc_82708424:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270855c
	if (cr6.eq) goto loc_8270855C;
	// li r28,0
	r28.s64 = 0;
loc_82708438:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827084b8
	if (cr6.eq) goto loc_827084B8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x82701de0
	ctx.lr = 0x82708454;
	sub_82701DE0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827084b8
	if (cr6.eq) goto loc_827084B8;
	// lbz r11,30(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827084b8
	if (cr6.eq) goto loc_827084B8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270847C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x827084b8
	if (!cr6.eq) goto loc_827084B8;
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827084b8
	if (cr6.eq) goto loc_827084B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827084A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827084b8
	if (cr6.eq) goto loc_827084B8;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplw cr6,r11,r24
	cr6.compare<uint32_t>(r11.u32, r24.u32, xer);
	// bne cr6,0x827084d0
	if (!cr6.eq) goto loc_827084D0;
loc_827084B8:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82708438
	if (cr6.lt) goto loc_82708438;
	// b 0x8270855c
	goto loc_8270855C;
loc_827084D0:
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827084e0
	if (cr6.eq) goto loc_827084E0;
	// bl 0x82714f10
	ctx.lr = 0x827084E0;
	sub_82714F10(ctx, base);
loc_827084E0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827084F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82713fb0
	ctx.lr = 0x82708500;
	sub_82713FB0(ctx, base);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x827144d8
	ctx.lr = 0x82708508;
	sub_827144D8(ctx, base);
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// li r7,1
	ctx.r7.s64 = 1;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r29,r1,640
	r29.s64 = ctx.r1.s64 + 640;
	// lwzx r5,r11,r5
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	// bl 0x82706008
	ctx.lr = 0x8270853C;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x82704228
	ctx.lr = 0x82708554;
	sub_82704228(ctx, base);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x82714070
	ctx.lr = 0x8270855C;
	sub_82714070(ctx, base);
loc_8270855C:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82708c30
	if (!cr6.gt) goto loc_82708C30;
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x827085dc
	if (!cr6.lt) goto loc_827085DC;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708590
	if (cr6.eq) goto loc_82708590;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x82708634
	if (!cr6.eq) goto loc_82708634;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// bne cr6,0x82708894
	if (!cr6.eq) goto loc_82708894;
loc_82708590:
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,112(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8270862c
	if (!cr6.gt) goto loc_8270862C;
loc_827085A8:
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,112(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lwz r11,16(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// neg r5,r11
	ctx.r5.s64 = -r11.s64;
	// lwz r6,192(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// bl 0x82705da0
	ctx.lr = 0x827085CC;
	sub_82705DA0(ctx, base);
	// lfs f12,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x827085a8
	if (cr6.gt) goto loc_827085A8;
	// b 0x8270862c
	goto loc_8270862C;
loc_827085DC:
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8270862c
	if (!cr6.lt) goto loc_8270862C;
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 + f25.f64));
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8270862c
	if (!cr6.gt) goto loc_8270862C;
loc_82708600:
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,24(r23)
	ctx.r5.u64 = PPC_LOAD_U32(r23.u32 + 24);
	// bl 0x82705da0
	ctx.lr = 0x82708620;
	sub_82705DA0(ctx, base);
	// lfs f12,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x82708600
	if (cr6.gt) goto loc_82708600;
loc_8270862C:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8270888c
	if (cr6.eq) goto loc_8270888C;
loc_82708634:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82701de0
	ctx.lr = 0x82708640;
	sub_82701DE0(ctx, base);
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82708740
	if (!cr6.eq) goto loc_82708740;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82713fb0
	ctx.lr = 0x8270865C;
	sub_82713FB0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// bl 0x82706008
	ctx.lr = 0x82708684;
	sub_82706008(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x827086c4
	if (!cr6.eq) goto loc_827086C4;
	// addi r3,r1,496
	ctx.r3.s64 = ctx.r1.s64 + 496;
	// bl 0x82714428
	ctx.lr = 0x82708694;
	sub_82714428(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r7,r1,496
	ctx.r7.s64 = ctx.r1.s64 + 496;
	// li r6,1
	ctx.r6.s64 = 1;
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// stw r9,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r9.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704228
	ctx.lr = 0x827086BC;
	sub_82704228(ctx, base);
	// addi r3,r1,496
	ctx.r3.s64 = ctx.r1.s64 + 496;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_827086C4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827086D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82708708
	if (!cr6.eq) goto loc_82708708;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// bl 0x82714480
	ctx.lr = 0x827086E8;
	sub_82714480(ctx, base);
	// addi r7,r1,736
	ctx.r7.s64 = ctx.r1.s64 + 736;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704228
	ctx.lr = 0x82708700;
	sub_82704228(ctx, base);
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_82708708:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270871C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bge cr6,0x82708c30
	if (!cr6.lt) goto loc_82708C30;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704228
	ctx.lr = 0x8270873C;
	sub_82704228(ctx, base);
	// b 0x82708c30
	goto loc_82708C30;
loc_82708740:
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82708800
	if (cr6.lt) goto loc_82708800;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82713fe8
	ctx.lr = 0x82708754;
	sub_82713FE8(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// bl 0x82706008
	ctx.lr = 0x8270877C;
	sub_82706008(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x827087bc
	if (!cr6.eq) goto loc_827087BC;
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// bl 0x82714428
	ctx.lr = 0x8270878C;
	sub_82714428(ctx, base);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r10,96(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r7,r1,544
	ctx.r7.s64 = ctx.r1.s64 + 544;
	// li r6,1
	ctx.r6.s64 = 1;
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stw r9,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r9.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704228
	ctx.lr = 0x827087B4;
	sub_82704228(ctx, base);
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_827087BC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827087D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82708c30
	if (!cr6.eq) goto loc_82708C30;
	// addi r3,r1,688
	ctx.r3.s64 = ctx.r1.s64 + 688;
	// bl 0x82714480
	ctx.lr = 0x827087E0;
	sub_82714480(ctx, base);
	// addi r7,r1,688
	ctx.r7.s64 = ctx.r1.s64 + 688;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82704228
	ctx.lr = 0x827087F8;
	sub_82704228(ctx, base);
	// addi r3,r1,688
	ctx.r3.s64 = ctx.r1.s64 + 688;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_82708800:
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82708c30
	if (cr6.lt) goto loc_82708C30;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82708830
	if (cr6.eq) goto loc_82708830;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82708828;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bge cr6,0x82708c30
	if (!cr6.lt) goto loc_82708C30;
loc_82708830:
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x82713fb0
	ctx.lr = 0x82708838;
	sub_82713FB0(ctx, base);
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// bl 0x82714530
	ctx.lr = 0x82708840;
	sub_82714530(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// addi r31,r1,784
	r31.s64 = ctx.r1.s64 + 784;
	// bl 0x82706008
	ctx.lr = 0x8270886C;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x82708884;
	sub_82704228(ctx, base);
	// addi r3,r1,784
	ctx.r3.s64 = ctx.r1.s64 + 784;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_8270888C:
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82708c30
	if (cr6.eq) goto loc_82708C30;
loc_82708894:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x827089d0
	if (!cr6.eq) goto loc_827089D0;
	// lwz r11,876(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 876);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x827088c8
	if (!cr6.eq) goto loc_827088C8;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827088c8
	if (cr6.eq) goto loc_827088C8;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827053c8
	ctx.lr = 0x827088C8;
	sub_827053C8(ctx, base);
loc_827088C8:
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82713fb0
	ctx.lr = 0x827088D0;
	sub_82713FB0(ctx, base);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82714428
	ctx.lr = 0x827088D8;
	sub_82714428(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x827088DC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82708948
	if (!cr6.eq) goto loc_82708948;
	// bl 0x82256058
	ctx.lr = 0x827088EC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82708948
	if (cr6.eq) goto loc_82708948;
	// bl 0x82256058
	ctx.lr = 0x827088F8;
	sub_82256058(ctx, base);
	// lwz r11,3088(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3088);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82708948
	if (!cr6.gt) goto loc_82708948;
	// bl 0x82256058
	ctx.lr = 0x82708908;
	sub_82256058(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708948
	if (cr6.eq) goto loc_82708948;
	// bl 0x82256058
	ctx.lr = 0x82708918;
	sub_82256058(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r29,208(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// bl 0x82224ac8
	ctx.lr = 0x82708928;
	sub_82224AC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270893c
	if (!cr6.eq) goto loc_8270893C;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_8270893C:
	// addi r6,r24,144
	ctx.r6.s64 = r24.s64 + 144;
	// addi r5,r29,144
	ctx.r5.s64 = r29.s64 + 144;
	// b 0x82708954
	goto loc_82708954;
loc_82708948:
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82708954:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f32d0
	ctx.lr = 0x8270896C;
	sub_821F32D0(ctx, base);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r10,360(r1)
	PPC_STORE_U8(ctx.r1.u32 + 360, ctx.r10.u8);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// and r8,r11,r9
	ctx.r8.u64 = r11.u64 & ctx.r9.u64;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// stw r8,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r8.u32);
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r1,320
	r31.s64 = ctx.r1.s64 + 320;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x827089B0;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x827089C8;
	sub_82704228(ctx, base);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_827089D0:
	// lwz r10,12(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82708b08
	if (cr6.lt) goto loc_82708B08;
	// lwz r11,876(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 876);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82708a00
	if (!cr6.eq) goto loc_82708A00;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82708a00
	if (cr6.eq) goto loc_82708A00;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827053c8
	ctx.lr = 0x82708A00;
	sub_827053C8(ctx, base);
loc_82708A00:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82713fe8
	ctx.lr = 0x82708A08;
	sub_82713FE8(ctx, base);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82714428
	ctx.lr = 0x82708A10;
	sub_82714428(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x82708A14;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82708a80
	if (!cr6.eq) goto loc_82708A80;
	// bl 0x82256058
	ctx.lr = 0x82708A24;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82708a80
	if (cr6.eq) goto loc_82708A80;
	// bl 0x82256058
	ctx.lr = 0x82708A30;
	sub_82256058(ctx, base);
	// lwz r11,3088(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3088);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82708a80
	if (!cr6.gt) goto loc_82708A80;
	// bl 0x82256058
	ctx.lr = 0x82708A40;
	sub_82256058(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708a80
	if (cr6.eq) goto loc_82708A80;
	// bl 0x82256058
	ctx.lr = 0x82708A50;
	sub_82256058(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r29,208(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// bl 0x82224ac8
	ctx.lr = 0x82708A60;
	sub_82224AC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82708a74
	if (!cr6.eq) goto loc_82708A74;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_82708A74:
	// addi r6,r24,144
	ctx.r6.s64 = r24.s64 + 144;
	// addi r5,r29,144
	ctx.r5.s64 = r29.s64 + 144;
	// b 0x82708a8c
	goto loc_82708A8C;
loc_82708A80:
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82708A8C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f32d0
	ctx.lr = 0x82708AA4;
	sub_821F32D0(ctx, base);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r10,312(r1)
	PPC_STORE_U8(ctx.r1.u32 + 312, ctx.r10.u8);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// and r8,r11,r9
	ctx.r8.u64 = r11.u64 & ctx.r9.u64;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// stw r8,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r8.u32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r1,272
	r31.s64 = ctx.r1.s64 + 272;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// bl 0x82706008
	ctx.lr = 0x82708AE8;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x82708B00;
	sub_82704228(ctx, base);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// b 0x82708c2c
	goto loc_82708C2C;
loc_82708B08:
	// lwz r10,4(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82708c30
	if (cr6.lt) goto loc_82708C30;
	// lwz r11,876(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 876);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82708b38
	if (!cr6.eq) goto loc_82708B38;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82708b38
	if (cr6.eq) goto loc_82708B38;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827053c8
	ctx.lr = 0x82708B38;
	sub_827053C8(ctx, base);
loc_82708B38:
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x82713fb0
	ctx.lr = 0x82708B40;
	sub_82713FB0(ctx, base);
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x82714530
	ctx.lr = 0x82708B48;
	sub_82714530(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x82708B4C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82708bb8
	if (!cr6.eq) goto loc_82708BB8;
	// bl 0x82256058
	ctx.lr = 0x82708B5C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82708bb8
	if (cr6.eq) goto loc_82708BB8;
	// bl 0x82256058
	ctx.lr = 0x82708B68;
	sub_82256058(ctx, base);
	// lwz r11,3088(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3088);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82708bb8
	if (!cr6.gt) goto loc_82708BB8;
	// bl 0x82256058
	ctx.lr = 0x82708B78;
	sub_82256058(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708bb8
	if (cr6.eq) goto loc_82708BB8;
	// bl 0x82256058
	ctx.lr = 0x82708B88;
	sub_82256058(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r31,208(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// bl 0x82224ac8
	ctx.lr = 0x82708B98;
	sub_82224AC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82708bac
	if (!cr6.eq) goto loc_82708BAC;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
loc_82708BAC:
	// addi r6,r24,144
	ctx.r6.s64 = r24.s64 + 144;
	// addi r5,r31,144
	ctx.r5.s64 = r31.s64 + 144;
	// b 0x82708bc4
	goto loc_82708BC4;
loc_82708BB8:
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
loc_82708BC4:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f32d0
	ctx.lr = 0x82708BDC;
	sub_821F32D0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// li r7,1
	ctx.r7.s64 = 1;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// stb r11,632(r1)
	PPC_STORE_U8(ctx.r1.u32 + 632, r11.u8);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// fmr f1,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f24.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r1,592
	r31.s64 = ctx.r1.s64 + 592;
	// bl 0x82706008
	ctx.lr = 0x82708C10;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x82708C28;
	sub_82704228(ctx, base);
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
loc_82708C2C:
	// bl 0x82714070
	ctx.lr = 0x82708C30;
	sub_82714070(ctx, base);
loc_82708C30:
	// lhz r11,488(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,484(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 484);
	// rotlwi r5,r11,2
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82708C44;
	sub_8244D150(ctx, base);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_82708C48:
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82707aa0
	if (!cr6.eq) goto loc_82707AA0;
loc_82708C54:
	// addi r1,r1,1056
	ctx.r1.s64 = ctx.r1.s64 + 1056;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba14
	ctx.lr = 0x82708C60;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82708C64"))) PPC_WEAK_FUNC(sub_82708C64);
PPC_FUNC_IMPL(__imp__sub_82708C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82708C68"))) PPC_WEAK_FUNC(sub_82708C68);
PPC_FUNC_IMPL(__imp__sub_82708C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
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
	ctx.lr = 0x82708C70;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708cf4
	if (cr6.eq) goto loc_82708CF4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82710598
	ctx.lr = 0x82708C98;
	sub_82710598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708cf4
	if (cr6.eq) goto loc_82708CF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f31,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	f31.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82708CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bgt cr6,0x82708e10
	if (cr6.gt) goto loc_82708E10;
	// lis r12,-32143
	r12.s64 = -2106523648;
	// addi r12,r12,-29472
	r12.s64 = r12.s64 + -29472;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_82708CF4;
	case 1:
		goto loc_82708CF4;
	case 2:
		goto loc_82708D04;
	case 3:
		goto loc_82708D84;
	case 4:
		goto loc_82708CF4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-29452(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -29452);
	// lwz r19,-29452(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -29452);
	// lwz r19,-29436(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -29436);
	// lwz r19,-29308(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -29308);
	// lwz r19,-29452(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -29452);
loc_82708CF4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82708D04:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82708D20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82713fb0
	ctx.lr = 0x82708D28;
	sub_82713FB0(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82714588
	ctx.lr = 0x82708D30;
	sub_82714588(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f1,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r1,160
	r31.s64 = ctx.r1.s64 + 160;
	// bl 0x82706008
	ctx.lr = 0x82708D60;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x82708D78;
	sub_82704228(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// b 0x82708e00
	goto loc_82708E00;
loc_82708D84:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,32(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82708DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82713fb0
	ctx.lr = 0x82708DA8;
	sub_82713FB0(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82714588
	ctx.lr = 0x82708DB0;
	sub_82714588(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// lbz r10,222(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 222);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lbz r9,221(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 221);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lbz r8,220(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 220);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f1,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r1,208
	r31.s64 = ctx.r1.s64 + 208;
	// bl 0x82706008
	ctx.lr = 0x82708DE0;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x82708DF8;
	sub_82704228(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
loc_82708E00:
	// bl 0x82714070
	ctx.lr = 0x82708E04;
	sub_82714070(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82708e10
	if (cr6.eq) goto loc_82708E10;
	// stfs f31,104(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 104, temp.u32);
loc_82708E10:
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82708E28"))) PPC_WEAK_FUNC(sub_82708E28);
PPC_FUNC_IMPL(__imp__sub_82708E28) {
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
	ctx.lr = 0x82708E30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82708ea0
	if (!cr6.gt) goto loc_82708EA0;
	// addi r29,r26,6
	r29.s64 = r26.s64 + 6;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_82708E48:
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82708e5c
	if (cr6.eq) goto loc_82708E5C;
	// lwz r3,2(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2);
	// bl 0x82130588
	ctx.lr = 0x82708E5C;
	sub_82130588(ctx, base);
loc_82708E5C:
	// lhz r31,0(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82708e94
	if (cr6.eq) goto loc_82708E94;
	// lwz r28,-6(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -6);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82708e8c
	if (!cr6.gt) goto loc_82708E8C;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82708E78:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82708E80;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82708e78
	if (!cr0.eq) goto loc_82708E78;
loc_82708E8C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82708E94;
	sub_82130588(ctx, base);
loc_82708E94:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// bne 0x82708e48
	if (!cr0.eq) goto loc_82708E48;
loc_82708EA0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82708EA8;
	sub_82130588(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82708EB0"))) PPC_WEAK_FUNC(sub_82708EB0);
PPC_FUNC_IMPL(__imp__sub_82708EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cntlzw r6,r9
	ctx.r6.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r10,r7
	ctx.r10.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r9,r6,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r8,r5,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r6,r9,1
	ctx.r6.u64 = ctx.r9.u64 ^ 1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// xori r10,r7,1
	ctx.r10.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// b 0x82706b00
	sub_82706B00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82708F00"))) PPC_WEAK_FUNC(sub_82708F00);
PPC_FUNC_IMPL(__imp__sub_82708F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82706cf8
	sub_82706CF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82708F0C"))) PPC_WEAK_FUNC(sub_82708F0C);
PPC_FUNC_IMPL(__imp__sub_82708F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82708F10"))) PPC_WEAK_FUNC(sub_82708F10);
PPC_FUNC_IMPL(__imp__sub_82708F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r3,r7,24
	ctx.r3.u64 = ctx.r7.u32 & 0xFF;
	// b 0x82707158
	sub_82707158(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82708F2C"))) PPC_WEAK_FUNC(sub_82708F2C);
PPC_FUNC_IMPL(__imp__sub_82708F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82708F30"))) PPC_WEAK_FUNC(sub_82708F30);
PPC_FUNC_IMPL(__imp__sub_82708F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f26{};
	PPCRegister f27{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82708F38;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d0
	ctx.lr = 0x82708F40;
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r16,0
	r16.s64 = 0;
	// lbz r11,-6144(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82708f88
	if (!cr6.eq) goto loc_82708F88;
	// bl 0x82256058
	ctx.lr = 0x82708F60;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82708f88
	if (cr6.eq) goto loc_82708F88;
	// bl 0x82256058
	ctx.lr = 0x82708F6C;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82708f88
	if (cr0.eq) goto loc_82708F88;
	// bl 0x82256058
	ctx.lr = 0x82708F78;
	sub_82256058(ctx, base);
	// lwz r11,3148(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82708f8c
	if (cr6.eq) goto loc_82708F8C;
loc_82708F88:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_82708F8C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// lwz r11,17268(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827096b0
	if (cr6.eq) goto loc_827096B0;
	// lhz r11,8(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// stw r16,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r16.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709668
	if (cr6.eq) goto loc_82709668;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f27,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f27.f64 = double(temp.f32);
	// lfs f29,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f29.f64 = double(temp.f32);
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// lfs f30,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f30.f64 = double(temp.f32);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f28,-29932(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29932);
	f28.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f26,27640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27640);
	f26.f64 = double(temp.f32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// li r20,48
	r20.s64 = 48;
	// li r17,32
	r17.s64 = 32;
	// ori r22,r5,64167
	r22.u64 = ctx.r5.u64 | 64167;
	// lis r14,-32121
	r14.s64 = -2105081856;
	// addi r21,r11,-24312
	r21.s64 = r11.s64 + -24312;
	// addi r23,r10,-13624
	r23.s64 = ctx.r10.s64 + -13624;
	// addi r15,r9,23096
	r15.s64 = ctx.r9.s64 + 23096;
	// addi r19,r8,23060
	r19.s64 = ctx.r8.s64 + 23060;
	// addi r24,r7,2192
	r24.s64 = ctx.r7.s64 + 2192;
	// addi r18,r6,2272
	r18.s64 = ctx.r6.s64 + 2272;
loc_82709028:
	// lwz r11,92(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 92);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lhz r10,8(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r8,4(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// twllei r10,0
	// divw r6,r7,r10
	ctx.r6.s32 = ctx.r7.s32 / ctx.r10.s32;
	// rotlwi r11,r7,1
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// mullw r5,r6,r10
	ctx.r5.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r3.u64;
	// twlgei r10,-1
	// lwzx r30,r11,r8
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82709650
	if (cr6.eq) goto loc_82709650;
	// lbz r11,872(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709628
	if (cr6.eq) goto loc_82709628;
	// lwz r11,1152(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82701de0
	ctx.lr = 0x82709090;
	sub_82701DE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6732(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6732);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827090c4
	if (cr6.eq) goto loc_827090C4;
	// lbz r11,880(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709650
	if (!cr6.eq) goto loc_82709650;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c408
	ctx.lr = 0x827090C0;
	sub_8270C408(ctx, base);
	// b 0x82709650
	goto loc_82709650;
loc_827090C4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c388
	ctx.lr = 0x827090CC;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709560
	if (!cr6.eq) goto loc_82709560;
	// lbz r11,88(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827090f8
	if (cr6.eq) goto loc_827090F8;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827090f8
	if (!cr6.eq) goto loc_827090F8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,1073(r30)
	PPC_STORE_U8(r30.u32 + 1073, r11.u8);
loc_827090F8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r11,-6144(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270910c
	if (cr6.eq) goto loc_8270910C;
	// stb r16,1073(r30)
	PPC_STORE_U8(r30.u32 + 1073, r16.u8);
loc_8270910C:
	// lbz r11,1073(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1073);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270914c
	if (!cr6.eq) goto loc_8270914C;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82709628
	if (cr6.eq) goto loc_82709628;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82701ea0
	ctx.lr = 0x82709130;
	sub_82701EA0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82709148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82709628
	goto loc_82709628;
loc_8270914C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c510
	ctx.lr = 0x82709154;
	sub_8270C510(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827091b8
	if (!cr6.eq) goto loc_827091B8;
	// lwz r11,-10012(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709628
	if (cr6.eq) goto loc_82709628;
	// li r5,1
	ctx.r5.s64 = 1;
	// lbz r6,1156(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 1156);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82704768
	ctx.lr = 0x82709180;
	sub_82704768(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82709190
	if (!cr6.eq) goto loc_82709190;
	// stb r16,1156(r30)
	PPC_STORE_U8(r30.u32 + 1156, r16.u8);
	// b 0x82709628
	goto loc_82709628;
loc_82709190:
	// lbz r11,880(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// stb r16,1156(r30)
	PPC_STORE_U8(r30.u32 + 1156, r16.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c408
	ctx.lr = 0x827091AC;
	sub_8270C408(ctx, base);
	// stb r16,1072(r30)
	PPC_STORE_U8(r30.u32 + 1072, r16.u8);
	// stb r16,1073(r30)
	PPC_STORE_U8(r30.u32 + 1073, r16.u8);
	// b 0x82709628
	goto loc_82709628;
loc_827091B8:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82705b18
	ctx.lr = 0x827091C4;
	sub_82705B18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827091f0
	if (cr6.eq) goto loc_827091F0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82704768
	ctx.lr = 0x827091E4;
	sub_82704768(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x827091f0
	if (!cr6.eq) goto loc_827091F0;
	// stfs f26,1128(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r30.u32 + 1128, temp.u32);
loc_827091F0:
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82702098
	ctx.lr = 0x82709204;
	sub_82702098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270922c
	if (cr6.eq) goto loc_8270922C;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,1120(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 1120);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82701f28
	ctx.lr = 0x8270922C;
	sub_82701F28(ctx, base);
loc_8270922C:
	// lbz r11,1072(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709628
	if (cr6.eq) goto loc_82709628;
	// bl 0x82387a18
	ctx.lr = 0x8270923C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lhz r11,48(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 48);
	// mr r26,r16
	r26.u64 = r16.u64;
	// mr r27,r16
	r27.u64 = r16.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709300
	if (cr6.eq) goto loc_82709300;
	// mr r29,r16
	r29.u64 = r16.u64;
loc_82709260:
	// mr r31,r16
	r31.u64 = r16.u64;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_82709268:
	// lwz r11,44(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 44);
	// lwzx r11,r11,r28
	r11.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lbz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827092c4
	if (cr6.eq) goto loc_827092C4;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f2,220(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 220);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,188(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 188);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// bl 0x8270cfc8
	ctx.lr = 0x82709294;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827092c4
	if (cr6.eq) goto loc_827092C4;
	// lwz r11,44(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 44);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwzx r5,r31,r11
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82708c68
	ctx.lr = 0x827092B8;
	sub_82708C68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827092d8
	if (!cr6.eq) goto loc_827092D8;
loc_827092C4:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x82709268
	if (cr6.lt) goto loc_82709268;
	// b 0x827092dc
	goto loc_827092DC;
loc_827092D8:
	// li r26,1
	r26.s64 = 1;
loc_827092DC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827092fc
	if (!cr6.eq) goto loc_827092FC;
	// lhz r11,48(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 48);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82709260
	if (cr6.lt) goto loc_82709260;
loc_827092FC:
	// lbz r28,80(r1)
	r28.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
loc_82709300:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lfs f0,1104(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r11,264(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// beq cr6,0x82709628
	if (cr6.eq) goto loc_82709628;
loc_82709338:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// mr r31,r11
	r31.u64 = r11.u64;
	// bl 0x82215e10
	ctx.lr = 0x82709348;
	sub_82215E10(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827007a8
	ctx.lr = 0x82709354;
	sub_827007A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709550
	if (!cr6.eq) goto loc_82709550;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82709368;
	sub_822A8108(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82709374;
	sub_822A8108(ctx, base);
	// lvx128 v63,r29,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lvx128 v60,r3,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x827093b8
	if (cr6.eq) goto loc_827093B8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827093b8
	if (cr6.eq) goto loc_827093B8;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x827093bc
	goto loc_827093BC;
loc_827093B8:
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
loc_827093BC:
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x827093ec
	if (cr6.eq) goto loc_827093EC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827093ec
	if (cr6.eq) goto loc_827093EC;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x827093f0
	goto loc_827093F0;
loc_827093EC:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_827093F0:
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x827022c8
	ctx.lr = 0x82709408;
	sub_827022C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82709550
	if (!cr6.eq) goto loc_82709550;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,188(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 188);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// bl 0x8270cfc8
	ctx.lr = 0x82709424;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709550
	if (cr6.eq) goto loc_82709550;
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// lfs f13,40(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,32(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f10,f11,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bge cr6,0x82709550
	if (!cr6.lt) goto loc_82709550;
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,280(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// ble cr6,0x82709550
	if (!cr6.gt) goto loc_82709550;
	// lfs f0,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// lfs f13,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// ble cr6,0x82709550
	if (!cr6.gt) goto loc_82709550;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// mulld r11,r11,r22
	r11.s64 = r11.s64 * r22.s64;
	// lwz r9,292(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 292);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// std r10,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// lfd f0,192(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// lfd f12,128(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r11,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r11.u32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f7,f9,f29
	ctx.f7.f64 = double(float(ctx.f9.f64 * f29.f64));
	// fmuls f8,f10,f30
	ctx.f8.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fcmpu cr6,f8,f7
	cr6.compare(ctx.f8.f64, ctx.f7.f64);
	// bge cr6,0x8270954c
	if (!cr6.lt) goto loc_8270954C;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// lwz r7,8(r21)
	ctx.r7.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r6,868(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 868);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x8270952C;
	sub_82130000(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82714e10
	ctx.lr = 0x82709534;
	sub_82714E10(ctx, base);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r31.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cc90
	ctx.lr = 0x82709548;
	sub_8270CC90(ctx, base);
	// b 0x82709550
	goto loc_82709550;
loc_8270954C:
	// stfs f27,1104(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 1104, temp.u32);
loc_82709550:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709338
	if (!cr6.eq) goto loc_82709338;
	// b 0x82709628
	goto loc_82709628;
loc_82709560:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c360
	ctx.lr = 0x82709568;
	sub_8270C360(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lbz r11,1072(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1072);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709618
	if (cr6.eq) goto loc_82709618;
	// lbz r11,1073(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1073);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709618
	if (cr6.eq) goto loc_82709618;
	// bl 0x82387a18
	ctx.lr = 0x8270958C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709618
	if (!cr6.eq) goto loc_82709618;
	// lfs f0,1104(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x82709628
	if (!cr6.eq) goto loc_82709628;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// mulld r11,r11,r22
	r11.s64 = r11.s64 * r22.s64;
	// lwz r9,296(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 296);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// extsw r10,r9
	ctx.r10.s64 = ctx.r9.s32;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r8,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r8.u64);
	// lfd f10,160(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stw r10,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r10.u32);
	// stw r11,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r11.u32);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64));
	// fcmpu cr6,f7,f11
	cr6.compare(ctx.f7.f64, ctx.f11.f64);
	// bge cr6,0x827096a0
	if (!cr6.lt) goto loc_827096A0;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// lwz r7,8(r21)
	ctx.r7.u64 = PPC_LOAD_U32(r21.u32 + 8);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r6,868(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 868);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x82709618;
	sub_82130000(ctx, base);
loc_82709618:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cc90
	ctx.lr = 0x82709628;
	sub_8270CC90(ctx, base);
loc_82709628:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270963C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,488(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 488);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,484(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 484);
	// rotlwi r5,r9,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x82709650;
	sub_8244D150(ctx, base);
loc_82709650:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lhz r10,8(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82709028
	if (cr6.lt) goto loc_82709028;
loc_82709668:
	// lhz r11,8(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827096a8
	if (cr6.eq) goto loc_827096A8;
	// lwz r10,92(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 92);
	// twllei r11,0
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r11
	ctx.r8.s32 = ctx.r9.s32 / r11.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// andc r5,r11,r7
	ctx.r5.u64 = r11.u64 & ~ctx.r7.u64;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// b 0x827096ac
	goto loc_827096AC;
loc_827096A0:
	// stfs f27,1104(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r30.u32 + 1104, temp.u32);
	// b 0x82709628
	goto loc_82709628;
loc_827096A8:
	// mr r11,r16
	r11.u64 = r16.u64;
loc_827096AC:
	// stw r11,92(r25)
	PPC_STORE_U32(r25.u32 + 92, r11.u32);
loc_827096B0:
	// stb r28,88(r25)
	PPC_STORE_U8(r25.u32 + 88, r28.u8);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba1c
	ctx.lr = 0x827096C0;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_827096C4"))) PPC_WEAK_FUNC(sub_827096C4);
PPC_FUNC_IMPL(__imp__sub_827096C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827096C8"))) PPC_WEAK_FUNC(sub_827096C8);
PPC_FUNC_IMPL(__imp__sub_827096C8) {
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
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,21584
	ctx.r4.s64 = r11.s64 + 21584;
	// addi r3,r10,24908
	ctx.r3.s64 = ctx.r10.s64 + 24908;
	// bl 0x82554798
	ctx.lr = 0x827096E8;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,24392
	ctx.r4.s64 = ctx.r9.s64 + 24392;
	// addi r3,r8,24880
	ctx.r3.s64 = ctx.r8.s64 + 24880;
	// bl 0x82554798
	ctx.lr = 0x827096FC;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,24456
	ctx.r4.s64 = ctx.r7.s64 + 24456;
	// addi r3,r6,24848
	ctx.r3.s64 = ctx.r6.s64 + 24848;
	// bl 0x82554798
	ctx.lr = 0x82709710;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,12440
	ctx.r4.s64 = ctx.r5.s64 + 12440;
	// addi r3,r3,24816
	ctx.r3.s64 = ctx.r3.s64 + 24816;
	// bl 0x82554798
	ctx.lr = 0x82709724;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,12448
	ctx.r4.s64 = r11.s64 + 12448;
	// addi r3,r10,24788
	ctx.r3.s64 = ctx.r10.s64 + 24788;
	// bl 0x82554798
	ctx.lr = 0x82709738;
	sub_82554798(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,-12200
	ctx.r4.s64 = ctx.r9.s64 + -12200;
	// addi r3,r8,24764
	ctx.r3.s64 = ctx.r8.s64 + 24764;
	// bl 0x82554798
	ctx.lr = 0x8270974C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,12512
	ctx.r4.s64 = ctx.r7.s64 + 12512;
	// addi r3,r6,24728
	ctx.r3.s64 = ctx.r6.s64 + 24728;
	// bl 0x82554798
	ctx.lr = 0x82709760;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,12560
	ctx.r4.s64 = ctx.r5.s64 + 12560;
	// addi r3,r3,24700
	ctx.r3.s64 = ctx.r3.s64 + 24700;
	// bl 0x82554798
	ctx.lr = 0x82709774;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,12632
	ctx.r4.s64 = r11.s64 + 12632;
	// addi r3,r10,24668
	ctx.r3.s64 = ctx.r10.s64 + 24668;
	// bl 0x82554798
	ctx.lr = 0x82709788;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,12688
	ctx.r4.s64 = ctx.r9.s64 + 12688;
	// addi r3,r8,24640
	ctx.r3.s64 = ctx.r8.s64 + 24640;
	// bl 0x82554798
	ctx.lr = 0x8270979C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,12752
	ctx.r4.s64 = ctx.r7.s64 + 12752;
	// addi r3,r6,24608
	ctx.r3.s64 = ctx.r6.s64 + 24608;
	// bl 0x82554798
	ctx.lr = 0x827097B0;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,12808
	ctx.r4.s64 = ctx.r5.s64 + 12808;
	// addi r3,r3,24564
	ctx.r3.s64 = ctx.r3.s64 + 24564;
	// bl 0x82554798
	ctx.lr = 0x827097C4;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,21600
	ctx.r4.s64 = r11.s64 + 21600;
	// addi r3,r10,24520
	ctx.r3.s64 = ctx.r10.s64 + 24520;
	// bl 0x82554798
	ctx.lr = 0x827097D8;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,21608
	ctx.r4.s64 = ctx.r9.s64 + 21608;
	// addi r3,r8,24476
	ctx.r3.s64 = ctx.r8.s64 + 24476;
	// bl 0x82554798
	ctx.lr = 0x827097EC;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,24512
	ctx.r4.s64 = ctx.r7.s64 + 24512;
	// addi r3,r6,24436
	ctx.r3.s64 = ctx.r6.s64 + 24436;
	// bl 0x82554798
	ctx.lr = 0x82709800;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,12816
	ctx.r4.s64 = ctx.r5.s64 + 12816;
	// addi r3,r3,24404
	ctx.r3.s64 = ctx.r3.s64 + 24404;
	// bl 0x82554798
	ctx.lr = 0x82709814;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,12864
	ctx.r4.s64 = r11.s64 + 12864;
	// addi r3,r10,24368
	ctx.r3.s64 = ctx.r10.s64 + 24368;
	// bl 0x82554798
	ctx.lr = 0x82709828;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,12896
	ctx.r4.s64 = ctx.r9.s64 + 12896;
	// addi r3,r8,24320
	ctx.r3.s64 = ctx.r8.s64 + 24320;
	// bl 0x82554798
	ctx.lr = 0x8270983C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,12952
	ctx.r4.s64 = ctx.r7.s64 + 12952;
	// addi r3,r6,24268
	ctx.r3.s64 = ctx.r6.s64 + 24268;
	// bl 0x82554798
	ctx.lr = 0x82709850;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,12984
	ctx.r4.s64 = ctx.r5.s64 + 12984;
	// addi r3,r3,24228
	ctx.r3.s64 = ctx.r3.s64 + 24228;
	// bl 0x82554798
	ctx.lr = 0x82709864;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13040
	ctx.r4.s64 = r11.s64 + 13040;
	// addi r3,r10,24188
	ctx.r3.s64 = ctx.r10.s64 + 24188;
	// bl 0x82554798
	ctx.lr = 0x82709878;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13072
	ctx.r4.s64 = ctx.r9.s64 + 13072;
	// addi r3,r8,24152
	ctx.r3.s64 = ctx.r8.s64 + 24152;
	// bl 0x82554798
	ctx.lr = 0x8270988C;
	sub_82554798(ctx, base);
	// lis r7,-32143
	ctx.r7.s64 = -2106523648;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-29008
	ctx.r4.s64 = ctx.r7.s64 + -29008;
	// addi r3,r6,24124
	ctx.r3.s64 = ctx.r6.s64 + 24124;
	// bl 0x82554798
	ctx.lr = 0x827098A0;
	sub_82554798(ctx, base);
	// lis r5,-32143
	ctx.r5.s64 = -2106523648;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-28928
	ctx.r4.s64 = ctx.r5.s64 + -28928;
	// addi r3,r3,24092
	ctx.r3.s64 = ctx.r3.s64 + 24092;
	// bl 0x82554798
	ctx.lr = 0x827098B4;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13144
	ctx.r4.s64 = r11.s64 + 13144;
	// addi r3,r10,24060
	ctx.r3.s64 = ctx.r10.s64 + 24060;
	// bl 0x82554798
	ctx.lr = 0x827098C8;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13192
	ctx.r4.s64 = ctx.r9.s64 + 13192;
	// addi r3,r8,24020
	ctx.r3.s64 = ctx.r8.s64 + 24020;
	// bl 0x82554798
	ctx.lr = 0x827098DC;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,24560
	ctx.r4.s64 = ctx.r7.s64 + 24560;
	// addi r3,r6,23988
	ctx.r3.s64 = ctx.r6.s64 + 23988;
	// bl 0x82554798
	ctx.lr = 0x827098F0;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,21616
	ctx.r4.s64 = ctx.r5.s64 + 21616;
	// addi r3,r3,23956
	ctx.r3.s64 = ctx.r3.s64 + 23956;
	// bl 0x82554798
	ctx.lr = 0x82709904;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,21624
	ctx.r4.s64 = r11.s64 + 21624;
	// addi r3,r10,23928
	ctx.r3.s64 = ctx.r10.s64 + 23928;
	// bl 0x82554798
	ctx.lr = 0x82709918;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,24576
	ctx.r4.s64 = ctx.r9.s64 + 24576;
	// addi r3,r8,23896
	ctx.r3.s64 = ctx.r8.s64 + 23896;
	// bl 0x82554798
	ctx.lr = 0x8270992C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,13240
	ctx.r4.s64 = ctx.r7.s64 + 13240;
	// addi r3,r6,23860
	ctx.r3.s64 = ctx.r6.s64 + 23860;
	// bl 0x82554798
	ctx.lr = 0x82709940;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13336
	ctx.r4.s64 = ctx.r5.s64 + 13336;
	// addi r3,r3,23824
	ctx.r3.s64 = ctx.r3.s64 + 23824;
	// bl 0x82554798
	ctx.lr = 0x82709954;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// addi r4,r11,13352
	ctx.r4.s64 = r11.s64 + 13352;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,23784
	ctx.r3.s64 = ctx.r10.s64 + 23784;
	// bl 0x82554798
	ctx.lr = 0x82709968;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13384
	ctx.r4.s64 = ctx.r9.s64 + 13384;
	// addi r3,r8,23744
	ctx.r3.s64 = ctx.r8.s64 + 23744;
	// bl 0x82554798
	ctx.lr = 0x8270997C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,13456
	ctx.r4.s64 = ctx.r7.s64 + 13456;
	// addi r3,r6,23704
	ctx.r3.s64 = ctx.r6.s64 + 23704;
	// bl 0x82554798
	ctx.lr = 0x82709990;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13512
	ctx.r4.s64 = ctx.r5.s64 + 13512;
	// addi r3,r3,23664
	ctx.r3.s64 = ctx.r3.s64 + 23664;
	// bl 0x82554798
	ctx.lr = 0x827099A4;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13584
	ctx.r4.s64 = r11.s64 + 13584;
	// addi r3,r10,23624
	ctx.r3.s64 = ctx.r10.s64 + 23624;
	// bl 0x82554798
	ctx.lr = 0x827099B8;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13616
	ctx.r4.s64 = ctx.r9.s64 + 13616;
	// addi r3,r8,23584
	ctx.r3.s64 = ctx.r8.s64 + 23584;
	// bl 0x82554798
	ctx.lr = 0x827099CC;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,13688
	ctx.r4.s64 = ctx.r7.s64 + 13688;
	// addi r3,r6,23544
	ctx.r3.s64 = ctx.r6.s64 + 23544;
	// bl 0x82554798
	ctx.lr = 0x827099E0;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,21704
	ctx.r4.s64 = ctx.r5.s64 + 21704;
	// addi r3,r3,23516
	ctx.r3.s64 = ctx.r3.s64 + 23516;
	// bl 0x82554798
	ctx.lr = 0x827099F4;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,21712
	ctx.r4.s64 = r11.s64 + 21712;
	// addi r3,r10,23468
	ctx.r3.s64 = ctx.r10.s64 + 23468;
	// bl 0x82554798
	ctx.lr = 0x82709A08;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,21728
	ctx.r4.s64 = ctx.r9.s64 + 21728;
	// addi r3,r8,23420
	ctx.r3.s64 = ctx.r8.s64 + 23420;
	// bl 0x82554798
	ctx.lr = 0x82709A1C;
	sub_82554798(ctx, base);
	// lis r7,-32143
	ctx.r7.s64 = -2106523648;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,-28912
	ctx.r4.s64 = ctx.r7.s64 + -28912;
	// addi r3,r6,23388
	ctx.r3.s64 = ctx.r6.s64 + 23388;
	// bl 0x82554798
	ctx.lr = 0x82709A30;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,21744
	ctx.r4.s64 = ctx.r5.s64 + 21744;
	// addi r3,r3,23360
	ctx.r3.s64 = ctx.r3.s64 + 23360;
	// bl 0x82554798
	ctx.lr = 0x82709A44;
	sub_82554798(ctx, base);
	// lis r11,-32144
	r11.s64 = -2106589184;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13744
	ctx.r4.s64 = r11.s64 + 13744;
	// addi r3,r10,23320
	ctx.r3.s64 = ctx.r10.s64 + 23320;
	// bl 0x82554798
	ctx.lr = 0x82709A58;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,21776
	ctx.r4.s64 = ctx.r9.s64 + 21776;
	// addi r3,r8,23280
	ctx.r3.s64 = ctx.r8.s64 + 23280;
	// bl 0x82554798
	ctx.lr = 0x82709A6C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,21896
	ctx.r4.s64 = ctx.r7.s64 + 21896;
	// addi r3,r6,23244
	ctx.r3.s64 = ctx.r6.s64 + 23244;
	// bl 0x82554798
	ctx.lr = 0x82709A80;
	sub_82554798(ctx, base);
	// lis r5,-32144
	ctx.r5.s64 = -2106589184;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,21960
	ctx.r4.s64 = ctx.r5.s64 + 21960;
	// addi r3,r3,23212
	ctx.r3.s64 = ctx.r3.s64 + 23212;
	// bl 0x82554798
	ctx.lr = 0x82709A94;
	sub_82554798(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32144
	ctx.r10.s64 = -2106589184;
	// addi r3,r11,23172
	ctx.r3.s64 = r11.s64 + 23172;
	// addi r4,r10,13808
	ctx.r4.s64 = ctx.r10.s64 + 13808;
	// bl 0x82554798
	ctx.lr = 0x82709AA8;
	sub_82554798(ctx, base);
	// lis r9,-32144
	ctx.r9.s64 = -2106589184;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13840
	ctx.r4.s64 = ctx.r9.s64 + 13840;
	// addi r3,r8,23136
	ctx.r3.s64 = ctx.r8.s64 + 23136;
	// bl 0x82554798
	ctx.lr = 0x82709ABC;
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

__attribute__((alias("__imp__sub_82709ACC"))) PPC_WEAK_FUNC(sub_82709ACC);
PPC_FUNC_IMPL(__imp__sub_82709ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82709AD0"))) PPC_WEAK_FUNC(sub_82709AD0);
PPC_FUNC_IMPL(__imp__sub_82709AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82709AD8;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9cc
	ctx.lr = 0x82709AE0;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// li r18,0
	r18.s64 = 0;
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// lhz r11,48(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ad14
	if (cr6.eq) goto loc_8270AD14;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f27,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f27.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f29,-1540(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1540);
	f29.f64 = double(temp.f32);
	// lfs f28,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f28.f64 = double(temp.f32);
	// addi r11,r11,-24332
	r11.s64 = r11.s64 + -24332;
	// lfs f30,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r10,r10,-13624
	ctx.r10.s64 = ctx.r10.s64 + -13624;
	// addi r9,r9,25040
	ctx.r9.s64 = ctx.r9.s64 + 25040;
	// stw r11,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r11.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r31,-32252
	r31.s64 = -2113667072;
	// lis r30,-32246
	r30.s64 = -2113273856;
	// lis r29,-32244
	r29.s64 = -2113142784;
	// addi r8,r8,-16868
	ctx.r8.s64 = ctx.r8.s64 + -16868;
	// addi r7,r7,-18232
	ctx.r7.s64 = ctx.r7.s64 + -18232;
	// addi r6,r6,25032
	ctx.r6.s64 = ctx.r6.s64 + 25032;
	// stw r8,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// addi r5,r5,25016
	ctx.r5.s64 = ctx.r5.s64 + 25016;
	// stw r7,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r7.u32);
	// addi r4,r4,-2640
	ctx.r4.s64 = ctx.r4.s64 + -2640;
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// addi r3,r3,25004
	ctx.r3.s64 = ctx.r3.s64 + 25004;
	// stw r5,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r5.u32);
	// addi r11,r31,-18224
	r11.s64 = r31.s64 + -18224;
	// stw r4,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r10,r30,25244
	ctx.r10.s64 = r30.s64 + 25244;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// addi r9,r29,24976
	ctx.r9.s64 = r29.s64 + 24976;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// lis r28,-32246
	r28.s64 = -2113273856;
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// lis r27,-32252
	r27.s64 = -2113667072;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lis r26,-32253
	r26.s64 = -2113732608;
	// lis r25,-32246
	r25.s64 = -2113273856;
	// lis r24,-32246
	r24.s64 = -2113273856;
	// lis r23,-32244
	r23.s64 = -2113142784;
	// lis r22,-32255
	r22.s64 = -2113863680;
	// lis r21,-32244
	r21.s64 = -2113142784;
	// lis r20,-32250
	r20.s64 = -2113536000;
	// lis r17,-32256
	r17.s64 = -2113929216;
	// addi r8,r28,25216
	ctx.r8.s64 = r28.s64 + 25216;
	// addi r7,r27,-25488
	ctx.r7.s64 = r27.s64 + -25488;
	// addi r6,r26,-9136
	ctx.r6.s64 = r26.s64 + -9136;
	// stw r8,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// addi r5,r25,2516
	ctx.r5.s64 = r25.s64 + 2516;
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// addi r4,r24,2532
	ctx.r4.s64 = r24.s64 + 2532;
	// lfs f26,7444(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 7444);
	f26.f64 = double(temp.f32);
	// addi r3,r23,24948
	ctx.r3.s64 = r23.s64 + 24948;
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// addi r11,r22,4496
	r11.s64 = r22.s64 + 4496;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// addi r10,r21,24936
	ctx.r10.s64 = r21.s64 + 24936;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// addi r9,r20,-12796
	ctx.r9.s64 = r20.s64 + -12796;
	// stw r3,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r3.u32);
	// li r14,1
	r14.s64 = 1;
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
loc_82709C28:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// b 0x82709c38
	goto loc_82709C38;
loc_82709C34:
	// lwz r18,96(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_82709C38:
	// add r9,r10,r18
	ctx.r9.u64 = ctx.r10.u64 + r18.u64;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// rlwinm r17,r9,2,0,29
	r17.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r17
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// lbz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 20);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8270ace8
	if (cr6.eq) goto loc_8270ACE8;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rlwinm r20,r18,2,0,29
	r20.u64 = __builtin_rotateleft64(r18.u32 | (r18.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r16,r10,2,0,29
	r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r20,r11
	r11.u64 = r20.u64 + r11.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// lwz r18,32(r9)
	r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// lwzx r3,r16,r11
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + r11.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bl 0x82710598
	ctx.lr = 0x82709C78;
	sub_82710598(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x82709ca0
	if (cr6.eq) goto loc_82709CA0;
	// lwz r11,656(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82709ca0
	if (cr6.eq) goto loc_82709CA0;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82706998
	ctx.lr = 0x82709C9C;
	sub_82706998(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_82709CA0:
	// clrlwi r15,r5,24
	r15.u64 = ctx.r5.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// stw r28,76(r19)
	PPC_STORE_U32(r19.u32 + 76, r28.u32);
	// beq cr6,0x8270a420
	if (cr6.eq) goto loc_8270A420;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r11,-6732(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -6732);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82709cd8
	if (cr6.eq) goto loc_82709CD8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82706998
	ctx.lr = 0x82709CD4;
	sub_82706998(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_82709CD8:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82709eac
	if (!cr6.eq) goto loc_82709EAC;
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82709dc0
	if (cr6.eq) goto loc_82709DC0;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82709dc0
	if (cr6.eq) goto loc_82709DC0;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,72(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82709d2c
	if (!cr6.gt) goto loc_82709D2C;
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82709d30
	goto loc_82709D30;
loc_82709D2C:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82709D30:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82709D44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82713fe8
	ctx.lr = 0x82709D4C;
	sub_82713FE8(ctx, base);
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x827144d8
	ctx.lr = 0x82709D54;
	sub_827144D8(ctx, base);
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r31.u32);
	// stw r18,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, r18.u32);
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// lbz r31,222(r19)
	r31.u64 = PPC_LOAD_U8(r19.u32 + 222);
	// lbz r30,221(r19)
	r30.u64 = PPC_LOAD_U8(r19.u32 + 221);
	// lbz r29,220(r19)
	r29.u64 = PPC_LOAD_U8(r19.u32 + 220);
	// beq cr6,0x82709d84
	if (cr6.eq) goto loc_82709D84;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82705ed0
	ctx.lr = 0x82709D7C;
	sub_82705ED0(ctx, base);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// b 0x82709d88
	goto loc_82709D88;
loc_82709D84:
	// stw r28,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r28.u32);
loc_82709D88:
	// stfs f30,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stb r29,221(r1)
	PPC_STORE_U8(ctx.r1.u32 + 221, r29.u8);
	// stb r14,220(r1)
	PPC_STORE_U8(ctx.r1.u32 + 220, r14.u8);
	// addi r7,r1,576
	ctx.r7.s64 = ctx.r1.s64 + 576;
	// stb r30,222(r1)
	PPC_STORE_U8(ctx.r1.u32 + 222, r30.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r31,223(r1)
	PPC_STORE_U8(ctx.r1.u32 + 223, r31.u8);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82704228
	ctx.lr = 0x82709DB4;
	sub_82704228(ctx, base);
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x82714070
	ctx.lr = 0x82709DBC;
	sub_82714070(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_82709DC0:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r31,r8,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r31,r10
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r11,92(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82709e4c
	if (cr6.lt) goto loc_82709E4C;
	// bne cr6,0x82709eac
	if (!cr6.eq) goto loc_82709EAC;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82709eac
	if (cr6.eq) goto loc_82709EAC;
	// lwz r30,136(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x82709eac
	if (cr6.lt) goto loc_82709EAC;
	// lwz r11,72(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82709e18
	if (!cr6.gt) goto loc_82709E18;
	// lwz r11,76(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82709e1c
	goto loc_82709E1C;
loc_82709E18:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
loc_82709E1C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// bl 0x826fda48
	ctx.lr = 0x82709E28;
	sub_826FDA48(ctx, base);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r11,2
	r11.s64 = 2;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// stw r11,92(r9)
	PPC_STORE_U32(ctx.r9.u32 + 92, r11.u32);
	// lfs f0,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 232);
	f0.f64 = double(temp.f32);
	// lwz r8,44(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r7,r31,r8
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// stfs f0,112(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 112, temp.u32);
	// b 0x82709eac
	goto loc_82709EAC;
loc_82709E4C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2256(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82709e70
	if (cr6.eq) goto loc_82709E70;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r14
	r11.u64 = r14.u64;
	// bne cr6,0x82709e74
	if (!cr6.eq) goto loc_82709E74;
loc_82709E70:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82709E74:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82709eac
	if (!cr6.eq) goto loc_82709EAC;
	// lwz r11,72(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82709e98
	if (!cr6.gt) goto loc_82709E98;
	// lwz r11,76(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82709e9c
	goto loc_82709E9C;
loc_82709E98:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82709E9C:
	// bl 0x8270c5c0
	ctx.lr = 0x82709EA0;
	sub_8270C5C0(ctx, base);
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r14,92(r10)
	PPC_STORE_U32(ctx.r10.u32 + 92, r14.u32);
loc_82709EAC:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270a408
	if (cr6.eq) goto loc_8270A408;
	// bl 0x82256058
	ctx.lr = 0x82709EB8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270a26c
	if (cr6.eq) goto loc_8270A26C;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lbz r10,30(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 30);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270a26c
	if (cr6.eq) goto loc_8270A26C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82709EE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270a26c
	if (cr6.eq) goto loc_8270A26C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r22,0
	r22.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270a05c
	if (cr6.eq) goto loc_8270A05C;
	// bl 0x822a39c0
	ctx.lr = 0x82709F0C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a05c
	if (cr6.eq) goto loc_8270A05C;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
	// li r29,0
	r29.s64 = 0;
	// lwzx r10,r17,r11
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8270a05c
	if (!cr6.gt) goto loc_8270A05C;
	// lwz r10,17268(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r28,0
	r28.s64 = 0;
loc_82709F3C:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lwzx r11,r17,r11
	r11.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// blt cr6,0x8270a038
	if (cr6.lt) goto loc_8270A038;
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// bge cr6,0x8270a038
	if (!cr6.lt) goto loc_8270A038;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwzx r30,r11,r28
	r30.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8270a038
	if (cr6.eq) goto loc_8270A038;
	// lwz r31,264(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 264);
	// addi r11,r10,264
	r11.s64 = ctx.r10.s64 + 264;
	// stw r11,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r31,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r31.u32);
	// beq cr6,0x8270a038
	if (cr6.eq) goto loc_8270A038;
loc_82709F80:
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x82215e10
	ctx.lr = 0x82709F8C;
	sub_82215E10(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270a024
	if (cr6.eq) goto loc_8270A024;
	// cmplw cr6,r31,r18
	cr6.compare<uint32_t>(r31.u32, r18.u32, xer);
	// beq cr6,0x8270a024
	if (cr6.eq) goto loc_8270A024;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cfc8
	ctx.lr = 0x82709FB4;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a024
	if (cr6.eq) goto loc_8270A024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82709FC8;
	sub_822A8108(ctx, base);
	// addi r27,r3,48
	r27.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x82709FD4;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f0,f6,f6,f4
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// blt cr6,0x8270a018
	if (cr6.lt) goto loc_8270A018;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8270a024
	if (!cr6.gt) goto loc_8270A024;
loc_8270A018:
	// mr r22,r31
	r22.u64 = r31.u64;
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// mr r21,r30
	r21.u64 = r30.u64;
loc_8270A024:
	// lwz r31,200(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82709f80
	if (!cr6.eq) goto loc_82709F80;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,17268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17268);
loc_8270A038:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwzx r9,r17,r11
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x82709f3c
	if (cr6.lt) goto loc_82709F3C;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x8270a1d8
	if (!cr6.eq) goto loc_8270A1D8;
loc_8270A05C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-5148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270a26c
	if (cr6.eq) goto loc_8270A26C;
	// lwz r24,0(r13)
	r24.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r23,72
	r23.s64 = 72;
	// lbzx r11,r23,r24
	r11.u64 = PPC_LOAD_U8(r23.u32 + r24.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a088
	if (cr6.eq) goto loc_8270A088;
	// lhz r25,20(r10)
	r25.u64 = PPC_LOAD_U16(ctx.r10.u32 + 20);
	// b 0x8270a08c
	goto loc_8270A08C;
loc_8270A088:
	// lhz r25,12(r10)
	r25.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
loc_8270A08C:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
	// li r27,0
	r27.s64 = 0;
	// lwzx r9,r17,r11
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8270a26c
	if (!cr6.gt) goto loc_8270A26C;
	// li r26,0
	r26.s64 = 0;
loc_8270A0AC:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// lwzx r11,r17,r11
	r11.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// blt cr6,0x8270a1b4
	if (cr6.lt) goto loc_8270A1B4;
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpw cr6,r27,r9
	cr6.compare<int32_t>(r27.s32, ctx.r9.s32, xer);
	// bge cr6,0x8270a1b4
	if (!cr6.lt) goto loc_8270A1B4;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwzx r30,r11,r26
	r30.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8270a1b4
	if (cr6.eq) goto loc_8270A1B4;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x8270a1b4
	if (!cr6.gt) goto loc_8270A1B4;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r25
	r28.u64 = r25.u64;
loc_8270A0E8:
	// lbzx r11,r23,r24
	r11.u64 = PPC_LOAD_U8(r23.u32 + r24.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a0fc
	if (cr6.eq) goto loc_8270A0FC;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// b 0x8270a100
	goto loc_8270A100;
loc_8270A0FC:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_8270A100:
	// lwzx r31,r11,r29
	r31.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270a1a8
	if (cr6.eq) goto loc_8270A1A8;
	// cmplw cr6,r31,r18
	cr6.compare<uint32_t>(r31.u32, r18.u32, xer);
	// beq cr6,0x8270a1a8
	if (cr6.eq) goto loc_8270A1A8;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cfc8
	ctx.lr = 0x8270A12C;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a1a0
	if (cr6.eq) goto loc_8270A1A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270A140;
	sub_822A8108(ctx, base);
	// addi r14,r3,48
	r14.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270A14C;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r14)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r14.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// lfs f13,8(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f0,f6,f6,f4
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// blt cr6,0x8270a190
	if (cr6.lt) goto loc_8270A190;
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8270a19c
	if (!cr6.gt) goto loc_8270A19C;
loc_8270A190:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// mr r22,r31
	r22.u64 = r31.u64;
	// mr r21,r30
	r21.u64 = r30.u64;
loc_8270A19C:
	// li r14,1
	r14.s64 = 1;
loc_8270A1A0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-5148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -5148);
loc_8270A1A8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8270a0e8
	if (!cr0.eq) goto loc_8270A0E8;
loc_8270A1B4:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// lwzx r9,r17,r11
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// cmpw cr6,r27,r8
	cr6.compare<int32_t>(r27.s32, ctx.r8.s32, xer);
	// blt cr6,0x8270a0ac
	if (cr6.lt) goto loc_8270A0AC;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8270a26c
	if (cr6.eq) goto loc_8270A26C;
loc_8270A1D8:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r10,r17,r11
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270a1f0
	if (cr6.eq) goto loc_8270A1F0;
	// bl 0x82714f10
	ctx.lr = 0x8270A1F0;
	sub_82714F10(ctx, base);
loc_8270A1F0:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A20C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// bl 0x82713fb0
	ctx.lr = 0x8270A214;
	sub_82713FB0(ctx, base);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82714428
	ctx.lr = 0x8270A21C;
	sub_82714428(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lbz r10,222(r19)
	ctx.r10.u64 = PPC_LOAD_U8(r19.u32 + 222);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// lbz r9,221(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 221);
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lbz r8,220(r19)
	ctx.r8.u64 = PPC_LOAD_U8(r19.u32 + 220);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r31,r1,480
	r31.s64 = ctx.r1.s64 + 480;
	// bl 0x82706008
	ctx.lr = 0x8270A248;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x8270A260;
	sub_82704228(ctx, base);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82714070
	ctx.lr = 0x8270A268;
	sub_82714070(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_8270A26C:
	// lwz r11,0(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A280;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8270a380
	if (!cr6.eq) goto loc_8270A380;
	// bl 0x82256058
	ctx.lr = 0x8270A290;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8270a380
	if (!cr6.eq) goto loc_8270A380;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270a380
	if (cr6.eq) goto loc_8270A380;
	// bl 0x822a39c0
	ctx.lr = 0x8270A2AC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a380
	if (cr6.eq) goto loc_8270A380;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8270A2C0;
	sub_822A39C8(ctx, base);
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,136(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// add r11,r20,r11
	r11.u64 = r20.u64 + r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f1,204(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r16,r11
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + r11.u32);
	// bl 0x827105c8
	ctx.lr = 0x8270A2E0;
	sub_827105C8(ctx, base);
	// lwz r9,44(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwzx r8,r17,r9
	ctx.r8.u64 = PPC_LOAD_U32(r17.u32 + ctx.r9.u32);
	// lwz r3,36(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270a2fc
	if (cr6.eq) goto loc_8270A2FC;
	// bl 0x82714f10
	ctx.lr = 0x8270A2FC;
	sub_82714F10(ctx, base);
loc_8270A2FC:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8270a380
	if (cr6.eq) goto loc_8270A380;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x82713fb0
	ctx.lr = 0x8270A328;
	sub_82713FB0(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82714428
	ctx.lr = 0x8270A330;
	sub_82714428(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lbz r10,222(r19)
	ctx.r10.u64 = PPC_LOAD_U8(r19.u32 + 222);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lbz r9,221(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 221);
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// lbz r8,220(r19)
	ctx.r8.u64 = PPC_LOAD_U8(r19.u32 + 220);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// addi r31,r1,528
	r31.s64 = ctx.r1.s64 + 528;
	// bl 0x82706008
	ctx.lr = 0x8270A35C;
	sub_82706008(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82704228
	ctx.lr = 0x8270A374;
	sub_82704228(ctx, base);
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82714070
	ctx.lr = 0x8270A37C;
	sub_82714070(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_8270A380:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270a408
	if (cr6.eq) goto loc_8270A408;
	// lwz r11,48(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270a3e8
	if (cr6.eq) goto loc_8270A3E8;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270a3e8
	if (cr6.eq) goto loc_8270A3E8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8270a3d8
	if (cr6.lt) goto loc_8270A3D8;
	// mr r11,r14
	r11.u64 = r14.u64;
loc_8270A3D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r14
	r11.u64 = r14.u64;
	// bne cr6,0x8270a3ec
	if (!cr6.eq) goto loc_8270A3EC;
loc_8270A3E8:
	// li r11,0
	r11.s64 = 0;
loc_8270A3EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a408
	if (cr6.eq) goto loc_8270A408;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82706998
	ctx.lr = 0x8270A408;
	sub_82706998(ctx, base);
loc_8270A408:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// add r11,r20,r11
	r11.u64 = r20.u64 + r11.u64;
	// lwzx r4,r16,r11
	ctx.r4.u64 = PPC_LOAD_U32(r16.u32 + r11.u32);
	// bl 0x82702420
	ctx.lr = 0x8270A41C;
	sub_82702420(ctx, base);
	// stw r3,76(r19)
	PPC_STORE_U32(r19.u32 + 76, ctx.r3.u32);
loc_8270A420:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A43C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,68(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 68);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8270a594
	if (!cr6.eq) goto loc_8270A594;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270a594
	if (cr6.eq) goto loc_8270A594;
	// stw r18,68(r19)
	PPC_STORE_U32(r19.u32 + 68, r18.u32);
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270a4dc
	if (cr6.eq) goto loc_8270A4DC;
	// lwz r11,48(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270a4dc
	if (cr6.eq) goto loc_8270A4DC;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8270a4dc
	if (cr6.eq) goto loc_8270A4DC;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x822a7d90
	ctx.lr = 0x8270A498;
	sub_822A7D90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a4b8
	if (cr6.eq) goto loc_8270A4B8;
	// lwz r11,592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8270a4b8
	if (!cr6.gt) goto loc_8270A4B8;
	// stb r14,64(r19)
	PPC_STORE_U8(r19.u32 + 64, r14.u8);
loc_8270A4B8:
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270a4dc
	if (cr6.eq) goto loc_8270A4DC;
	// lwz r11,48(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,664(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lhz r8,18(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 18);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// stw r7,72(r19)
	PPC_STORE_U32(r19.u32 + 72, ctx.r7.u32);
loc_8270A4DC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270a594
	if (cr6.eq) goto loc_8270A594;
	// addis r30,r11,1
	r30.s64 = r11.s64 + 65536;
	// li r31,76
	r31.s64 = 76;
	// addi r30,r30,16256
	r30.s64 = r30.s64 + 16256;
loc_8270A4F8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8270A504;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,105
	cr6.compare<int32_t>(r31.s32, 105, xer);
	// blt cr6,0x8270a4f8
	if (cr6.lt) goto loc_8270A4F8;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270a594
	if (cr6.eq) goto loc_8270A594;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8270a594
	if (cr6.eq) goto loc_8270A594;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270a594
	if (cr6.eq) goto loc_8270A594;
	// li r4,45
	ctx.r4.s64 = 45;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8270A564;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,176(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8270A594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270A594:
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r11,r17,r10
	r11.u64 = PPC_LOAD_U32(r17.u32 + ctx.r10.u32);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,52(r19)
	PPC_STORE_U32(r19.u32 + 52, r11.u32);
	// beq cr6,0x8270ace8
	if (cr6.eq) goto loc_8270ACE8;
	// lwz r31,168(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8270a5bc
	if (cr6.eq) goto loc_8270A5BC;
	// lwz r31,172(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
loc_8270A5BC:
	// lwzx r3,r17,r10
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A5D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,164(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// rlwinm r6,r3,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,184(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwzx r6,r6,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x8270A5F8;
	sub_82130000(ctx, base);
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270a614
	if (cr6.eq) goto loc_8270A614;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82705c18
	ctx.lr = 0x8270A60C;
	sub_82705C18(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8270a618
	goto loc_8270A618;
loc_8270A614:
	// li r30,-1
	r30.s64 = -1;
loc_8270A618:
	// lwz r11,52(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 52);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8270a7a4
	if (cr6.eq) goto loc_8270A7A4;
	// ble cr6,0x8270ac50
	if (!cr6.gt) goto loc_8270AC50;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bgt cr6,0x8270ac50
	if (cr6.gt) goto loc_8270AC50;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270ac50
	if (cr6.eq) goto loc_8270AC50;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270a6d4
	if (cr6.eq) goto loc_8270A6D4;
	// lwz r11,0(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270a6d4
	if (cr6.eq) goto loc_8270A6D4;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270a6d4
	if (cr6.eq) goto loc_8270A6D4;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r4,192(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8270A6B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,44(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,160(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// lwzx r6,r17,r7
	ctx.r6.u64 = PPC_LOAD_U32(r17.u32 + ctx.r7.u32);
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// lfs f0,104(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x8268b770
	ctx.lr = 0x8270A6D4;
	sub_8268B770(ctx, base);
loc_8270A6D4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lwz r10,2252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8270a700
	if (!cr6.eq) goto loc_8270A700;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x8270A700;
	sub_821F1498(ctx, base);
loc_8270A700:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8270a754
	if (!cr6.eq) goto loc_8270A754;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714740
	ctx.lr = 0x8270A714;
	sub_82714740(ctx, base);
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r11,r16,r11
	r11.u64 = PPC_LOAD_U32(r16.u32 + r11.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8270a734
	if (!cr6.gt) goto loc_8270A734;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8270a738
	goto loc_8270A738;
loc_8270A734:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270A738:
	// bl 0x8270c2d8
	ctx.lr = 0x8270A73C;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714080
	ctx.lr = 0x8270A748;
	sub_82714080(ctx, base);
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714070
	ctx.lr = 0x8270A750;
	sub_82714070(ctx, base);
	// b 0x8270ac50
	goto loc_8270AC50;
loc_8270A754:
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x827146e8
	ctx.lr = 0x8270A75C;
	sub_827146E8(ctx, base);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// stw r11,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, r11.u32);
	// lwzx r11,r17,r10
	r11.u64 = PPC_LOAD_U32(r17.u32 + ctx.r10.u32);
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8270a784
	if (!cr6.gt) goto loc_8270A784;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x8270a788
	goto loc_8270A788;
loc_8270A784:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270A788:
	// bl 0x8270c2d8
	ctx.lr = 0x8270A78C;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82714080
	ctx.lr = 0x8270A798;
	sub_82714080(ctx, base);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82714070
	ctx.lr = 0x8270A7A0;
	sub_82714070(ctx, base);
	// b 0x8270ac50
	goto loc_8270AC50;
loc_8270A7A4:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8270a858
	if (!cr6.eq) goto loc_8270A858;
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r16,r11
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270A7CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82713fe8
	ctx.lr = 0x8270A7D4;
	sub_82713FE8(ctx, base);
	// lwz r8,44(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lwzx r11,r16,r8
	r11.u64 = PPC_LOAD_U32(r16.u32 + ctx.r8.u32);
	// lwz r7,72(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8270a7f8
	if (!cr6.gt) goto loc_8270A7F8;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r10.u32);
	// b 0x8270a800
	goto loc_8270A800;
loc_8270A7F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r11.u32);
loc_8270A800:
	// lbz r11,220(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 220);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lbz r10,221(r19)
	ctx.r10.u64 = PPC_LOAD_U8(r19.u32 + 221);
	// lbz r9,222(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 222);
	// lwz r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r18,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r18.u32);
	// stb r11,253(r1)
	PPC_STORE_U8(ctx.r1.u32 + 253, r11.u8);
	// stb r10,254(r1)
	PPC_STORE_U8(ctx.r1.u32 + 254, ctx.r10.u8);
	// stb r9,255(r1)
	PPC_STORE_U8(ctx.r1.u32 + 255, ctx.r9.u8);
	// stw r8,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r8.u32);
	// stb r14,252(r1)
	PPC_STORE_U8(ctx.r1.u32 + 252, r14.u8);
	// bl 0x82714428
	ctx.lr = 0x8270A830;
	sub_82714428(ctx, base);
	// stfs f26,396(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82704228
	ctx.lr = 0x8270A84C;
	sub_82704228(ctx, base);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x82714070
	ctx.lr = 0x8270A854;
	sub_82714070(ctx, base);
	// b 0x8270ace8
	goto loc_8270ACE8;
loc_8270A858:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8270aa84
	if (!cr6.eq) goto loc_8270AA84;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270ac50
	if (cr6.eq) goto loc_8270AC50;
	// lwz r11,0(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A87C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270ac50
	if (cr6.eq) goto loc_8270AC50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lwz r10,2252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8270a8b4
	if (!cr6.eq) goto loc_8270A8B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x8270A8B4;
	sub_821F1498(ctx, base);
loc_8270A8B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827016d8
	ctx.lr = 0x8270A8BC;
	sub_827016D8(ctx, base);
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270a968
	if (cr6.eq) goto loc_8270A968;
	// bl 0x82256058
	ctx.lr = 0x8270A8C8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270a938
	if (cr6.eq) goto loc_8270A938;
	// bl 0x82261078
	ctx.lr = 0x8270A8D4;
	sub_82261078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82261058
	ctx.lr = 0x8270A8DC;
	sub_82261058(ctx, base);
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r28,120(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x8270A8F4;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8270A908;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x8270A920;
	sub_821FDE78(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x8270A924;
	sub_82256058(ctx, base);
	// stb r14,3775(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3775, r14.u8);
	// bl 0x82256058
	ctx.lr = 0x8270A92C;
	sub_82256058(ctx, base);
	// stb r14,3773(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3773, r14.u8);
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// bl 0x822c68d8
	ctx.lr = 0x8270A938;
	sub_822C68D8(ctx, base);
loc_8270A938:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r6,76(r19)
	ctx.r6.u64 = PPC_LOAD_U32(r19.u32 + 76);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217820
	ctx.lr = 0x8270A958;
	sub_82217820(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x822183b0
	ctx.lr = 0x8270A968;
	sub_822183B0(ctx, base);
loc_8270A968:
	// stb r14,56(r19)
	PPC_STORE_U8(r19.u32 + 56, r14.u8);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x826ffea0
	ctx.lr = 0x8270A978;
	sub_826FFEA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270aa4c
	if (cr6.eq) goto loc_8270AA4C;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270ac3c
	if (cr6.eq) goto loc_8270AC3C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,46
	ctx.r4.s64 = 46;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8270A9A8;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x8270A9BC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270A9D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,44(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwzx r11,r7,r4
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// lfs f1,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82702340
	ctx.lr = 0x8270A9F8;
	sub_82702340(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8270AA0C;
	sub_822183B0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270AA30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ac3c
	if (cr6.eq) goto loc_8270AC3C;
	// lwz r4,76(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 76);
	// bl 0x826b94a8
	ctx.lr = 0x8270AA48;
	sub_826B94A8(ctx, base);
	// b 0x8270ac3c
	goto loc_8270AC3C;
loc_8270AA4C:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270aa7c
	if (cr6.eq) goto loc_8270AA7C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,47
	ctx.r4.s64 = 47;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8270AA70;
	sub_82641CB0(ctx, base);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82674568
	ctx.lr = 0x8270AA7C;
	sub_82674568(ctx, base);
loc_8270AA7C:
	// lwz r5,188(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// b 0x8270ac40
	goto loc_8270AC40;
loc_8270AA84:
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x8270ac50
	if (cr6.eq) goto loc_8270AC50;
	// lwz r11,0(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270AAA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270ac50
	if (cr6.eq) goto loc_8270AC50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lwz r10,2252(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8270aad8
	if (!cr6.eq) goto loc_8270AAD8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x8270AAD8;
	sub_821F1498(ctx, base);
loc_8270AAD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827016d8
	ctx.lr = 0x8270AAE0;
	sub_827016D8(ctx, base);
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x8270ac38
	if (cr6.eq) goto loc_8270AC38;
	// bl 0x82256058
	ctx.lr = 0x8270AAEC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ab5c
	if (cr6.eq) goto loc_8270AB5C;
	// bl 0x82261078
	ctx.lr = 0x8270AAF8;
	sub_82261078(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82261058
	ctx.lr = 0x8270AB00;
	sub_82261058(ctx, base);
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lwz r28,120(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x8270AB18;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8270AB2C;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x8270AB44;
	sub_821FDE78(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x8270AB48;
	sub_82256058(ctx, base);
	// stb r14,3775(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3775, r14.u8);
	// bl 0x82256058
	ctx.lr = 0x8270AB50;
	sub_82256058(ctx, base);
	// stb r14,3773(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3773, r14.u8);
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// bl 0x822c68d8
	ctx.lr = 0x8270AB5C;
	sub_822C68D8(ctx, base);
loc_8270AB5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,46
	ctx.r4.s64 = 46;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8270AB78;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9790
	ctx.lr = 0x8270AB8C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,800(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 800);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270ABA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,44(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwzx r8,r17,r9
	ctx.r8.u64 = PPC_LOAD_U32(r17.u32 + ctx.r9.u32);
	// lfs f1,104(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82702340
	ctx.lr = 0x8270ABBC;
	sub_82702340(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8270ABD0;
	sub_822183B0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,76(r19)
	ctx.r6.u64 = PPC_LOAD_U32(r19.u32 + 76);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lwz r31,-10244(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217820
	ctx.lr = 0x8270ABEC;
	sub_82217820(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x822183b0
	ctx.lr = 0x8270ABFC;
	sub_822183B0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8270AC20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ac38
	if (cr6.eq) goto loc_8270AC38;
	// lwz r4,76(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 76);
	// bl 0x826b94a8
	ctx.lr = 0x8270AC38;
	sub_826B94A8(ctx, base);
loc_8270AC38:
	// stb r14,56(r19)
	PPC_STORE_U8(r19.u32 + 56, r14.u8);
loc_8270AC3C:
	// lwz r5,148(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
loc_8270AC40:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,108(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8270AC50;
	sub_8268B770(ctx, base);
loc_8270AC50:
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ac74
	if (cr6.eq) goto loc_8270AC74;
	// bl 0x82714f10
	ctx.lr = 0x8270AC60;
	sub_82714F10(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8270ac74
	if (cr6.lt) goto loc_8270AC74;
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// add r11,r11,r19
	r11.u64 = r11.u64 + r19.u64;
	// stfs f27,116(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
loc_8270AC74:
	// lwz r11,44(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r17,r11
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270AC90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701828
	ctx.lr = 0x8270ACA0;
	sub_82701828(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lhz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rotlwi r5,r8,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// bl 0x8244d150
	ctx.lr = 0x8270ACBC;
	sub_8244D150(ctx, base);
	// lwz r11,52(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 52);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x8270acd0
	if (cr6.eq) goto loc_8270ACD0;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8270ace8
	if (!cr6.eq) goto loc_8270ACE8;
loc_8270ACD0:
	// bl 0x82256058
	ctx.lr = 0x8270ACD4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ace8
	if (cr6.eq) goto loc_8270ACE8;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x8270ACE8;
	sub_827057E0(ctx, base);
loc_8270ACE8:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// blt cr6,0x82709c34
	if (cr6.lt) goto loc_82709C34;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lhz r10,48(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 48);
	// addi r18,r11,1
	r18.s64 = r11.s64 + 1;
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// cmpw cr6,r18,r10
	cr6.compare<int32_t>(r18.s32, ctx.r10.s32, xer);
	// blt cr6,0x82709c28
	if (cr6.lt) goto loc_82709C28;
loc_8270AD14:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270AD2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba18
	ctx.lr = 0x8270AD38;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8270AD3C"))) PPC_WEAK_FUNC(sub_8270AD3C);
PPC_FUNC_IMPL(__imp__sub_8270AD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270AD40"))) PPC_WEAK_FUNC(sub_8270AD40);
PPC_FUNC_IMPL(__imp__sub_8270AD40) {
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
	// addi r10,r11,25064
	ctx.r10.s64 = r11.s64 + 25064;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82706618
	ctx.lr = 0x8270AD68;
	sub_82706618(ctx, base);
	// lhz r9,186(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 186);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270ad7c
	if (cr6.eq) goto loc_8270AD7C;
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// bl 0x82130588
	ctx.lr = 0x8270AD7C;
	sub_82130588(ctx, base);
loc_8270AD7C:
	// lhz r5,178(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 178);
	// addi r30,r31,164
	r30.s64 = r31.s64 + 164;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8270ad98
	if (cr6.eq) goto loc_8270AD98;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82708e28
	ctx.lr = 0x8270AD98;
	sub_82708E28(ctx, base);
loc_8270AD98:
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8270adb0
	if (cr6.eq) goto loc_8270ADB0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82706078
	ctx.lr = 0x8270ADB0;
	sub_82706078(ctx, base);
loc_8270ADB0:
	// lhz r11,50(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 50);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270adc4
	if (cr6.eq) goto loc_8270ADC4;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82130588
	ctx.lr = 0x8270ADC4;
	sub_82130588(ctx, base);
loc_8270ADC4:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x8270ADCC;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// sth r30,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r30.u16);
	// sth r30,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8270ADE4;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ae04
	if (cr6.eq) goto loc_8270AE04;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8270AE04;
	sub_82130588(ctx, base);
loc_8270AE04:
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ae18
	if (cr6.eq) goto loc_8270AE18;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8270AE18;
	sub_82130588(ctx, base);
loc_8270AE18:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8270AE20;
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

__attribute__((alias("__imp__sub_8270AE38"))) PPC_WEAK_FUNC(sub_8270AE38);
PPC_FUNC_IMPL(__imp__sub_8270AE38) {
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
	ctx.lr = 0x8270AE40;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b0e0
	if (cr6.eq) goto loc_8270B0E0;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270ae78
	if (cr6.eq) goto loc_8270AE78;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8270ae7c
	if (cr6.eq) goto loc_8270AE7C;
loc_8270AE78:
	// li r11,0
	r11.s64 = 0;
loc_8270AE7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270b0e0
	if (!cr6.eq) goto loc_8270B0E0;
	// lbz r11,56(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270aea4
	if (cr6.eq) goto loc_8270AEA4;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827008f0
	ctx.lr = 0x8270AEA0;
	sub_827008F0(ctx, base);
	// b 0x8270b094
	goto loc_8270B094;
loc_8270AEA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270af2c
	if (cr6.eq) goto loc_8270AF2C;
	// bl 0x823bbf70
	ctx.lr = 0x8270AEB8;
	sub_823BBF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270aed4
	if (!cr6.eq) goto loc_8270AED4;
	// bl 0x823bbf80
	ctx.lr = 0x8270AEC8;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270af2c
	if (cr6.eq) goto loc_8270AF2C;
loc_8270AED4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8270AEF0;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8270AF08;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827022c8
	ctx.lr = 0x8270AF14;
	sub_827022C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82706998
	ctx.lr = 0x8270AF28;
	sub_82706998(ctx, base);
	// b 0x8270b094
	goto loc_8270B094;
loc_8270AF2C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f31,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82707208
	ctx.lr = 0x8270AF44;
	sub_82707208(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82700088
	ctx.lr = 0x8270AF4C;
	sub_82700088(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270af64
	if (cr6.eq) goto loc_8270AF64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x827078e8
	ctx.lr = 0x8270AF64;
	sub_827078E8(ctx, base);
loc_8270AF64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82709ad0
	ctx.lr = 0x8270AF70;
	sub_82709AD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82708f30
	ctx.lr = 0x8270AF78;
	sub_82708F30(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,17268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,116(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270b094
	if (!cr6.gt) goto loc_8270B094;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// stfs f12,116(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 116, temp.u32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x8270b094
	if (cr6.gt) goto loc_8270B094;
	// stfs f0,116(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 116, temp.u32);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r10,r11,264
	ctx.r10.s64 = r11.s64 + 264;
	// lwz r11,264(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// li r31,0
	r31.s64 = 0;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
loc_8270AFD4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r28,r11
	r28.u64 = r11.u64;
	// bl 0x82215e10
	ctx.lr = 0x8270AFE4;
	sub_82215E10(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// beq cr6,0x8270b000
	if (cr6.eq) goto loc_8270B000;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270afd4
	if (!cr6.eq) goto loc_8270AFD4;
	// b 0x8270b008
	goto loc_8270B008;
loc_8270B000:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822aaf98
	ctx.lr = 0x8270B008;
	sub_822AAF98(ctx, base);
loc_8270B008:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b094
	if (cr6.eq) goto loc_8270B094;
	// li r31,0
	r31.s64 = 0;
loc_8270B024:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270b080
	if (cr6.eq) goto loc_8270B080;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,484(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 484);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r7,r8,30,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8270b080
	if (cr6.eq) goto loc_8270B080;
	// lwz r10,48(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270b080
	if (cr6.eq) goto loc_8270B080;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,28(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x822aafc8
	ctx.lr = 0x8270B068;
	sub_822AAFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b080
	if (cr6.eq) goto loc_8270B080;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x822aaf98
	ctx.lr = 0x8270B080;
	sub_822AAF98(ctx, base);
loc_8270B080:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8270b024
	if (cr6.lt) goto loc_8270B024;
loc_8270B094:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b0e0
	if (cr6.eq) goto loc_8270B0E0;
	// li r31,0
	r31.s64 = 0;
loc_8270B0A8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270b0cc
	if (cr6.eq) goto loc_8270B0CC;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270B0CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270B0CC:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8270b0a8
	if (cr6.lt) goto loc_8270B0A8;
loc_8270B0E0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8270B0EC"))) PPC_WEAK_FUNC(sub_8270B0EC);
PPC_FUNC_IMPL(__imp__sub_8270B0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B0F0"))) PPC_WEAK_FUNC(sub_8270B0F0);
PPC_FUNC_IMPL(__imp__sub_8270B0F0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,25064
	ctx.r10.s64 = r11.s64 + 25064;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// sth r30,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r30.u16);
	// sth r30,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r30.u16);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// sth r30,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r30.u16);
	// sth r30,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r30.u16);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// sth r30,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r30.u16);
	// sth r30,50(r31)
	PPC_STORE_U16(r31.u32 + 50, r30.u16);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stb r30,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r30.u8);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stb r30,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r30.u8);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// bl 0x82714f10
	ctx.lr = 0x8270B190;
	sub_82714F10(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r31,164
	r11.s64 = r31.s64 + 164;
	// stw r30,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r30.u32);
	// sth r30,168(r31)
	PPC_STORE_U16(r31.u32 + 168, r30.u16);
	// li r11,1
	r11.s64 = 1;
	// sth r30,170(r31)
	PPC_STORE_U16(r31.u32 + 170, r30.u16);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,176(r31)
	PPC_STORE_U16(r31.u32 + 176, r30.u16);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r30,178(r31)
	PPC_STORE_U16(r31.u32 + 178, r30.u16);
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// sth r30,184(r31)
	PPC_STORE_U16(r31.u32 + 184, r30.u16);
	// sth r30,186(r31)
	PPC_STORE_U16(r31.u32 + 186, r30.u16);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// stw r30,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r30.u32);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// stb r11,220(r31)
	PPC_STORE_U8(r31.u32 + 220, r11.u8);
	// stb r11,221(r31)
	PPC_STORE_U8(r31.u32 + 221, r11.u8);
	// stb r11,222(r31)
	PPC_STORE_U8(r31.u32 + 222, r11.u8);
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
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

__attribute__((alias("__imp__sub_8270B214"))) PPC_WEAK_FUNC(sub_8270B214);
PPC_FUNC_IMPL(__imp__sub_8270B214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B218"))) PPC_WEAK_FUNC(sub_8270B218);
PPC_FUNC_IMPL(__imp__sub_8270B218) {
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
	// bl 0x8270ad40
	ctx.lr = 0x8270B238;
	sub_8270AD40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270b250
	if (cr6.eq) goto loc_8270B250;
	// bl 0x82130588
	ctx.lr = 0x8270B24C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8270B250:
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

__attribute__((alias("__imp__sub_8270B268"))) PPC_WEAK_FUNC(sub_8270B268);
PPC_FUNC_IMPL(__imp__sub_8270B268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8270B270;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r31,-32253
	r31.s64 = -2113732608;
	// lfs f11,32668(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 32668);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f10,31304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	ctx.f10.f64 = double(temp.f32);
	// lis r30,-32255
	r30.s64 = -2113863680;
	// lfs f6,-12988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12988);
	ctx.f6.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f5,-29924(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29924);
	ctx.f5.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f10,188(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 188, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f10,192(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f6,204(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f5,220(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// lis r29,-32254
	r29.s64 = -2113798144;
	// stfs f10,256(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lfs f6,12880(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12880);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-30580(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -30580);
	ctx.f5.f64 = double(temp.f32);
	// li r7,600
	ctx.r7.s64 = 600;
	// lfs f10,-26872(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26872);
	ctx.f10.f64 = double(temp.f32);
	// li r31,2
	r31.s64 = 2;
	// lfs f0,27640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27640);
	f0.f64 = double(temp.f32);
	// li r30,100
	r30.s64 = 100;
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r8,500
	ctx.r8.s64 = 500;
	// lfs f7,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f7.f64 = double(temp.f32);
	// li r9,250
	ctx.r9.s64 = 250;
	// lfs f9,27632(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27632);
	ctx.f9.f64 = double(temp.f32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lfs f8,27636(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27636);
	ctx.f8.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f12,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// li r10,10
	ctx.r10.s64 = 10;
	// lfs f4,-1540(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -1540);
	ctx.f4.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,50
	ctx.r6.s64 = 50;
	// stfs f7,208(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// li r27,1000
	r27.s64 = 1000;
	// stfs f7,272(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// li r29,30
	r29.s64 = 30;
	// stw r31,-176(r1)
	PPC_STORE_U32(ctx.r1.u32 + -176, r31.u32);
	// stw r30,-156(r1)
	PPC_STORE_U32(ctx.r1.u32 + -156, r30.u32);
	// lfs f7,30712(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 30712);
	ctx.f7.f64 = double(temp.f32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// stfs f11,196(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f0,200(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stw r5,-172(r1)
	PPC_STORE_U32(ctx.r1.u32 + -172, ctx.r5.u32);
	// stfs f13,212(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// stw r6,-168(r1)
	PPC_STORE_U32(ctx.r1.u32 + -168, ctx.r6.u32);
	// stfs f13,216(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// stw r10,-164(r1)
	PPC_STORE_U32(ctx.r1.u32 + -164, ctx.r10.u32);
	// stfs f9,224(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// stfs f9,228(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 228, temp.u32);
	// stw r8,-160(r1)
	PPC_STORE_U32(ctx.r1.u32 + -160, ctx.r8.u32);
	// stfs f0,232(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stfs f8,236(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 236, temp.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// stfs f0,240(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 240, temp.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stfs f12,248(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 248, temp.u32);
	// stw r29,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r29.u32);
	// stfs f0,264(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// stw r4,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// stfs f13,268(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stfs f13,276(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// li r31,25
	r31.s64 = 25;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// li r30,5000
	r30.s64 = 5000;
	// lwz r29,-176(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + -176);
	// lis r28,-32252
	r28.s64 = -2113667072;
	// lwz r20,-156(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// lis r26,-32256
	r26.s64 = -2113929216;
	// lis r24,-32256
	r24.s64 = -2113929216;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// lis r22,-32252
	r22.s64 = -2113667072;
	// stw r8,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r8.u32);
	// rotlwi r21,r8,0
	r21.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stfs f12,284(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 284, temp.u32);
	// li r11,100
	r11.s64 = 100;
	// stfs f12,308(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// li r9,15
	ctx.r9.s64 = 15;
	// stfs f12,344(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 344, temp.u32);
	// li r8,30
	ctx.r8.s64 = 30;
	// stfs f12,356(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 356, temp.u32);
	// rotlwi r27,r5,0
	r27.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lfs f12,-28428(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -28428);
	ctx.f12.f64 = double(temp.f32);
	// rotlwi r25,r6,0
	r25.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// stfs f13,312(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 312, temp.u32);
	// rotlwi r23,r10,0
	r23.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stfs f10,316(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 316, temp.u32);
	// li r19,300
	r19.s64 = 300;
	// stfs f11,328(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 328, temp.u32);
	// li r18,40
	r18.s64 = 40;
	// stfs f10,336(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 336, temp.u32);
	// li r17,5
	r17.s64 = 5;
	// stfs f11,348(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 348, temp.u32);
	// li r16,70
	r16.s64 = 70;
	// stfs f11,376(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 376, temp.u32);
	// li r15,100
	r15.s64 = 100;
	// stfs f10,404(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 404, temp.u32);
	// addi r14,r3,128
	r14.s64 = ctx.r3.s64 + 128;
	// stw r29,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r29.u32);
	// stw r31,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r31.u32);
	// lfs f11,11368(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 11368);
	ctx.f11.f64 = double(temp.f32);
	// stw r30,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r30.u32);
	// lfs f10,31016(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 31016);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,3732(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stw r27,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r27.u32);
	// stfs f6,288(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 288, temp.u32);
	// stw r25,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r25.u32);
	// stfs f0,300(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 300, temp.u32);
	// stw r23,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r23.u32);
	// stfs f5,304(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// stw r15,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r15.u32);
	// stfs f4,324(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 324, temp.u32);
	// stw r14,-156(r1)
	PPC_STORE_U32(ctx.r1.u32 + -156, r14.u32);
	// stfs f7,340(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 340, temp.u32);
	// stw r21,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r21.u32);
	// stfs f7,360(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 360, temp.u32);
	// stw r20,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r20.u32);
	// stfs f8,372(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 372, temp.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stfs f9,380(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 380, temp.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stfs f6,396(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 396, temp.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stw r9,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r9.u32);
	// lis r31,-32244
	r31.s64 = -2113142784;
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// lis r30,-32253
	r30.s64 = -2113732608;
	// stw r9,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r9.u32);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lis r28,-32254
	r28.s64 = -2113798144;
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stw r9,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r9.u32);
	// stw r10,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r10.u32);
	// stw r19,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r19.u32);
	// stw r7,244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 244, ctx.r7.u32);
	// stw r8,252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 252, ctx.r8.u32);
	// stw r18,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, r18.u32);
	// stw r10,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r10.u32);
	// stw r17,292(r3)
	PPC_STORE_U32(ctx.r3.u32 + 292, r17.u32);
	// stw r4,296(r3)
	PPC_STORE_U32(ctx.r3.u32 + 296, ctx.r4.u32);
	// stw r5,320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 320, ctx.r5.u32);
	// stw r6,332(r3)
	PPC_STORE_U32(ctx.r3.u32 + 332, ctx.r6.u32);
	// stw r7,352(r3)
	PPC_STORE_U32(ctx.r3.u32 + 352, ctx.r7.u32);
	// stw r16,388(r3)
	PPC_STORE_U32(ctx.r3.u32 + 388, r16.u32);
	// stw r8,420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 420, ctx.r8.u32);
	// lfs f9,27296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 27296);
	ctx.f9.f64 = double(temp.f32);
	// rotlwi r10,r14,0
	ctx.r10.u64 = __builtin_rotateleft32(r14.u32, 0);
	// lfs f6,21588(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 21588);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,31020(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31020);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-11624(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -11624);
	ctx.f4.f64 = double(temp.f32);
	// stfs f12,364(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 364, temp.u32);
	// stfs f11,368(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// stfs f10,384(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 384, temp.u32);
	// stfs f13,392(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 392, temp.u32);
	// stfs f9,400(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 400, temp.u32);
	// stfs f6,408(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 408, temp.u32);
	// stfs f7,412(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 412, temp.u32);
	// stfs f0,416(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 416, temp.u32);
	// stfs f8,424(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 424, temp.u32);
	// stfs f5,428(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 428, temp.u32);
	// stfs f4,432(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 432, temp.u32);
	// stfs f13,436(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 436, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8270B540:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8270b540
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8270B540;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8270B550"))) PPC_WEAK_FUNC(sub_8270B550);
PPC_FUNC_IMPL(__imp__sub_8270B550) {
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
	// li r3,440
	ctx.r3.s64 = 440;
	// bl 0x82130528
	ctx.lr = 0x8270B564;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270b580
	if (cr6.eq) goto loc_8270B580;
	// bl 0x8270b268
	ctx.lr = 0x8270B570;
	sub_8270B268(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8270B580:
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

__attribute__((alias("__imp__sub_8270B594"))) PPC_WEAK_FUNC(sub_8270B594);
PPC_FUNC_IMPL(__imp__sub_8270B594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B598"))) PPC_WEAK_FUNC(sub_8270B598);
PPC_FUNC_IMPL(__imp__sub_8270B598) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24340);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270B5A4"))) PPC_WEAK_FUNC(sub_8270B5A4);
PPC_FUNC_IMPL(__imp__sub_8270B5A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B5A8"))) PPC_WEAK_FUNC(sub_8270B5A8);
PPC_FUNC_IMPL(__imp__sub_8270B5A8) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,22444
	ctx.r4.s64 = ctx.r10.s64 + 22444;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8270B5D4;
	sub_821CA540(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r4,-14076(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -14076);
	// addi r7,r11,-13624
	ctx.r7.s64 = r11.s64 + -13624;
	// addi r5,r10,5276
	ctx.r5.s64 = ctx.r10.s64 + 5276;
	// lwz r6,-24340(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24340);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// bl 0x821c04b0
	ctx.lr = 0x8270B604;
	sub_821C04B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8270B610;
	sub_821C9A90(ctx, base);
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

__attribute__((alias("__imp__sub_8270B62C"))) PPC_WEAK_FUNC(sub_8270B62C);
PPC_FUNC_IMPL(__imp__sub_8270B62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B630"))) PPC_WEAK_FUNC(sub_8270B630);
PPC_FUNC_IMPL(__imp__sub_8270B630) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8270B638;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r24,r10,-24276
	r24.s64 = ctx.r10.s64 + -24276;
	// addi r11,r11,27628
	r11.s64 = r11.s64 + 27628;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r11,-24276(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24276, r11.u32);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// addi r11,r8,27616
	r11.s64 = ctx.r8.s64 + 27616;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r11,12(r24)
	PPC_STORE_U32(r24.u32 + 12, r11.u32);
	// addi r10,r10,27584
	ctx.r10.s64 = ctx.r10.s64 + 27584;
	// addi r9,r9,27572
	ctx.r9.s64 = ctx.r9.s64 + 27572;
	// addi r11,r5,27596
	r11.s64 = ctx.r5.s64 + 27596;
	// stw r10,4(r24)
	PPC_STORE_U32(r24.u32 + 4, ctx.r10.u32);
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// stw r9,8(r24)
	PPC_STORE_U32(r24.u32 + 8, ctx.r9.u32);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// stw r11,24(r24)
	PPC_STORE_U32(r24.u32 + 24, r11.u32);
	// lis r31,-32244
	r31.s64 = -2113142784;
	// addi r10,r7,27560
	ctx.r10.s64 = ctx.r7.s64 + 27560;
	// addi r9,r6,27540
	ctx.r9.s64 = ctx.r6.s64 + 27540;
	// addi r11,r31,27528
	r11.s64 = r31.s64 + 27528;
	// stw r10,16(r24)
	PPC_STORE_U32(r24.u32 + 16, ctx.r10.u32);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// stw r9,20(r24)
	PPC_STORE_U32(r24.u32 + 20, ctx.r9.u32);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// stw r11,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r11.u32);
	// lis r28,-32244
	r28.s64 = -2113142784;
	// addi r10,r4,27512
	ctx.r10.s64 = ctx.r4.s64 + 27512;
	// addi r9,r3,27500
	ctx.r9.s64 = ctx.r3.s64 + 27500;
	// addi r11,r28,27484
	r11.s64 = r28.s64 + 27484;
	// stw r10,28(r24)
	PPC_STORE_U32(r24.u32 + 28, ctx.r10.u32);
	// lis r30,-32244
	r30.s64 = -2113142784;
	// stw r9,32(r24)
	PPC_STORE_U32(r24.u32 + 32, ctx.r9.u32);
	// lis r29,-32244
	r29.s64 = -2113142784;
	// stw r11,48(r24)
	PPC_STORE_U32(r24.u32 + 48, r11.u32);
	// lis r23,-32111
	r23.s64 = -2104426496;
	// lis r25,-32255
	r25.s64 = -2113863680;
	// addi r10,r30,27472
	ctx.r10.s64 = r30.s64 + 27472;
	// addi r9,r29,27460
	ctx.r9.s64 = r29.s64 + 27460;
	// addi r11,r25,-8396
	r11.s64 = r25.s64 + -8396;
	// stw r10,40(r24)
	PPC_STORE_U32(r24.u32 + 40, ctx.r10.u32);
	// lis r27,-32244
	r27.s64 = -2113142784;
	// stw r9,44(r24)
	PPC_STORE_U32(r24.u32 + 44, ctx.r9.u32);
	// lis r26,-32244
	r26.s64 = -2113142784;
	// stw r11,-24312(r23)
	PPC_STORE_U32(r23.u32 + -24312, r11.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r10,r27,27448
	ctx.r10.s64 = r27.s64 + 27448;
	// addi r9,r26,27432
	ctx.r9.s64 = r26.s64 + 27432;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// stw r10,52(r24)
	PPC_STORE_U32(r24.u32 + 52, ctx.r10.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r9,56(r24)
	PPC_STORE_U32(r24.u32 + 56, ctx.r9.u32);
	// addi r31,r7,27420
	r31.s64 = ctx.r7.s64 + 27420;
	// stb r11,-24336(r8)
	PPC_STORE_U8(ctx.r8.u32 + -24336, r11.u8);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r30,-32244
	r30.s64 = -2113142784;
	// lis r29,-32244
	r29.s64 = -2113142784;
	// lis r28,-32244
	r28.s64 = -2113142784;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r10,r10,-19084
	ctx.r10.s64 = ctx.r10.s64 + -19084;
	// addi r9,r9,27412
	ctx.r9.s64 = ctx.r9.s64 + 27412;
	// addi r8,r8,27404
	ctx.r8.s64 = ctx.r8.s64 + 27404;
	// addi r7,r7,27392
	ctx.r7.s64 = ctx.r7.s64 + 27392;
	// addi r6,r6,27384
	ctx.r6.s64 = ctx.r6.s64 + 27384;
	// addi r5,r5,27376
	ctx.r5.s64 = ctx.r5.s64 + 27376;
	// addi r4,r4,27360
	ctx.r4.s64 = ctx.r4.s64 + 27360;
	// addi r3,r3,27336
	ctx.r3.s64 = ctx.r3.s64 + 27336;
	// addi r30,r30,27328
	r30.s64 = r30.s64 + 27328;
	// addi r29,r29,27312
	r29.s64 = r29.s64 + 27312;
	// addi r28,r28,27300
	r28.s64 = r28.s64 + 27300;
	// addi r27,r23,-24312
	r27.s64 = r23.s64 + -24312;
	// lis r26,-32111
	r26.s64 = -2104426496;
	// stw r10,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r10.u32);
	// addi r10,r26,-24332
	ctx.r10.s64 = r26.s64 + -24332;
	// stw r9,8(r27)
	PPC_STORE_U32(r27.u32 + 8, ctx.r9.u32);
	// stw r11,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r11.u32);
	// stw r8,16(r27)
	PPC_STORE_U32(r27.u32 + 16, ctx.r8.u32);
	// stw r7,20(r27)
	PPC_STORE_U32(r27.u32 + 20, ctx.r7.u32);
	// stw r6,24(r27)
	PPC_STORE_U32(r27.u32 + 24, ctx.r6.u32);
	// stw r5,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r5.u32);
	// stw r4,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r4.u32);
	// stw r3,-24332(r26)
	PPC_STORE_U32(r26.u32 + -24332, ctx.r3.u32);
	// stw r31,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r31.u32);
	// stw r30,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r30.u32);
	// stw r29,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r29.u32);
	// stw r28,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r28.u32);
	// bl 0x8270b5a8
	ctx.lr = 0x8270B7BC;
	sub_8270B5A8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8270B7C4"))) PPC_WEAK_FUNC(sub_8270B7C4);
PPC_FUNC_IMPL(__imp__sub_8270B7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270B7C8"))) PPC_WEAK_FUNC(sub_8270B7C8);
PPC_FUNC_IMPL(__imp__sub_8270B7C8) {
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
	// addi r31,r11,-24340
	r31.s64 = r11.s64 + -24340;
	// lwz r11,-24340(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24340);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270bec8
	if (!cr6.eq) goto loc_8270BEC8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8270B7F8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270b80c
	if (cr6.eq) goto loc_8270B80C;
	// bl 0x821d5408
	ctx.lr = 0x8270B808;
	sub_821D5408(ctx, base);
	// b 0x8270b810
	goto loc_8270B810;
loc_8270B80C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8270B810:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32143
	r11.s64 = -2106523648;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,27640
	ctx.r7.s64 = ctx.r10.s64 + 27640;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19048
	ctx.r9.s64 = r11.s64 + -19048;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,440
	ctx.r5.s64 = 440;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32143
	ctx.r8.s64 = -2106523648;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,-19120
	ctx.r4.s64 = ctx.r8.s64 + -19120;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r5,r10,-16356
	ctx.r5.s64 = ctx.r10.s64 + -16356;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-16380
	ctx.r9.s64 = ctx.r3.s64 + -16380;
	// addi r4,r8,-16308
	ctx.r4.s64 = ctx.r8.s64 + -16308;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r6,r3,-16332
	ctx.r6.s64 = ctx.r3.s64 + -16332;
	// addi r5,r8,-16284
	ctx.r5.s64 = ctx.r8.s64 + -16284;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r11,12
	r11.s64 = 12;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-16236
	ctx.r4.s64 = ctx.r7.s64 + -16236;
	// addi r6,r3,-16260
	ctx.r6.s64 = ctx.r3.s64 + -16260;
	// addi r5,r8,-16212
	ctx.r5.s64 = ctx.r8.s64 + -16212;
	// li r11,24
	r11.s64 = 24;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,28
	ctx.r10.s64 = 28;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-16164
	ctx.r4.s64 = ctx.r7.s64 + -16164;
	// addi r6,r3,-16188
	ctx.r6.s64 = ctx.r3.s64 + -16188;
	// addi r5,r8,-16140
	ctx.r5.s64 = ctx.r8.s64 + -16140;
	// li r11,36
	r11.s64 = 36;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,40
	ctx.r10.s64 = 40;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-16092
	ctx.r4.s64 = ctx.r7.s64 + -16092;
	// addi r6,r3,-16116
	ctx.r6.s64 = ctx.r3.s64 + -16116;
	// addi r5,r8,-16068
	ctx.r5.s64 = ctx.r8.s64 + -16068;
	// li r11,48
	r11.s64 = 48;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,44
	ctx.r9.s64 = 44;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,52
	ctx.r10.s64 = 52;
	// addi r4,r7,-16044
	ctx.r4.s64 = ctx.r7.s64 + -16044;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r11,56
	r11.s64 = 56;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r9,r3,-16020
	ctx.r9.s64 = ctx.r3.s64 + -16020;
	// addi r8,r11,-15996
	ctx.r8.s64 = r11.s64 + -15996;
	// li r10,64
	ctx.r10.s64 = 64;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r11,60
	r11.s64 = 60;
	// addi r4,r7,-15972
	ctx.r4.s64 = ctx.r7.s64 + -15972;
	// addi r3,r6,-15948
	ctx.r3.s64 = ctx.r6.s64 + -15948;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r8,r5,-15924
	ctx.r8.s64 = ctx.r5.s64 + -15924;
	// li r9,68
	ctx.r9.s64 = 68;
	// li r11,72
	r11.s64 = 72;
	// li r10,76
	ctx.r10.s64 = 76;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-15900
	ctx.r4.s64 = ctx.r7.s64 + -15900;
	// addi r3,r6,-15876
	ctx.r3.s64 = ctx.r6.s64 + -15876;
	// addi r8,r5,-15852
	ctx.r8.s64 = ctx.r5.s64 + -15852;
	// li r9,80
	ctx.r9.s64 = 80;
	// li r11,84
	r11.s64 = 84;
	// li r10,88
	ctx.r10.s64 = 88;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-15828
	ctx.r4.s64 = ctx.r7.s64 + -15828;
	// addi r3,r6,-15804
	ctx.r3.s64 = ctx.r6.s64 + -15804;
	// addi r8,r5,-15780
	ctx.r8.s64 = ctx.r5.s64 + -15780;
	// li r9,92
	ctx.r9.s64 = 92;
	// li r11,96
	r11.s64 = 96;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-15756
	ctx.r4.s64 = ctx.r7.s64 + -15756;
	// addi r3,r6,-15732
	ctx.r3.s64 = ctx.r6.s64 + -15732;
	// addi r8,r5,-15708
	ctx.r8.s64 = ctx.r5.s64 + -15708;
	// li r9,104
	ctx.r9.s64 = 104;
	// li r11,108
	r11.s64 = 108;
	// li r10,112
	ctx.r10.s64 = 112;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-15684
	ctx.r4.s64 = ctx.r7.s64 + -15684;
	// addi r3,r6,-15660
	ctx.r3.s64 = ctx.r6.s64 + -15660;
	// addi r8,r5,-15636
	ctx.r8.s64 = ctx.r5.s64 + -15636;
	// li r9,116
	ctx.r9.s64 = 116;
	// li r11,120
	r11.s64 = 120;
	// li r10,124
	ctx.r10.s64 = 124;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-13684
	ctx.r4.s64 = ctx.r7.s64 + -13684;
	// addi r3,r6,-15588
	ctx.r3.s64 = ctx.r6.s64 + -15588;
	// addi r8,r5,-15564
	ctx.r8.s64 = ctx.r5.s64 + -15564;
	// li r9,128
	ctx.r9.s64 = 128;
	// li r11,188
	r11.s64 = 188;
	// li r10,192
	ctx.r10.s64 = 192;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-15540
	ctx.r5.s64 = ctx.r7.s64 + -15540;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// li r11,196
	r11.s64 = 196;
	// addi r4,r6,-15516
	ctx.r4.s64 = ctx.r6.s64 + -15516;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// li r10,200
	ctx.r10.s64 = 200;
	// addi r7,r3,-15492
	ctx.r7.s64 = ctx.r3.s64 + -15492;
	// addi r6,r9,-15468
	ctx.r6.s64 = ctx.r9.s64 + -15468;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r8,-15444
	ctx.r5.s64 = ctx.r8.s64 + -15444;
	// li r9,204
	ctx.r9.s64 = 204;
	// li r11,208
	r11.s64 = 208;
	// li r10,212
	ctx.r10.s64 = 212;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r4,-15420
	ctx.r7.s64 = ctx.r4.s64 + -15420;
	// addi r6,r3,-15396
	ctx.r6.s64 = ctx.r3.s64 + -15396;
	// addi r5,r8,-15372
	ctx.r5.s64 = ctx.r8.s64 + -15372;
	// li r9,216
	ctx.r9.s64 = 216;
	// li r11,220
	r11.s64 = 220;
	// li r10,224
	ctx.r10.s64 = 224;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r4,-15348
	ctx.r7.s64 = ctx.r4.s64 + -15348;
	// addi r6,r3,-15324
	ctx.r6.s64 = ctx.r3.s64 + -15324;
	// addi r5,r8,-15300
	ctx.r5.s64 = ctx.r8.s64 + -15300;
	// li r9,228
	ctx.r9.s64 = 228;
	// li r11,232
	r11.s64 = 232;
	// li r10,236
	ctx.r10.s64 = 236;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r4,-15276
	ctx.r7.s64 = ctx.r4.s64 + -15276;
	// addi r6,r3,-15252
	ctx.r6.s64 = ctx.r3.s64 + -15252;
	// addi r5,r8,-15228
	ctx.r5.s64 = ctx.r8.s64 + -15228;
	// li r9,240
	ctx.r9.s64 = 240;
	// li r11,244
	r11.s64 = 244;
	// li r10,248
	ctx.r10.s64 = 248;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r4,-15204
	ctx.r7.s64 = ctx.r4.s64 + -15204;
	// addi r6,r3,-15180
	ctx.r6.s64 = ctx.r3.s64 + -15180;
	// addi r5,r8,-15156
	ctx.r5.s64 = ctx.r8.s64 + -15156;
	// li r9,252
	ctx.r9.s64 = 252;
	// li r11,256
	r11.s64 = 256;
	// li r10,260
	ctx.r10.s64 = 260;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r4,-15132
	ctx.r7.s64 = ctx.r4.s64 + -15132;
	// addi r6,r3,-15108
	ctx.r6.s64 = ctx.r3.s64 + -15108;
	// addi r5,r8,-15084
	ctx.r5.s64 = ctx.r8.s64 + -15084;
	// li r9,264
	ctx.r9.s64 = 264;
	// li r11,268
	r11.s64 = 268;
	// li r10,272
	ctx.r10.s64 = 272;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r8,r4,-15060
	ctx.r8.s64 = ctx.r4.s64 + -15060;
	// addi r7,r3,-15036
	ctx.r7.s64 = ctx.r3.s64 + -15036;
	// li r11,276
	r11.s64 = 276;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r10,280
	ctx.r10.s64 = 280;
	// addi r4,r9,-15012
	ctx.r4.s64 = ctx.r9.s64 + -15012;
	// addi r3,r6,-14988
	ctx.r3.s64 = ctx.r6.s64 + -14988;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// addi r8,r5,-14964
	ctx.r8.s64 = ctx.r5.s64 + -14964;
	// li r9,284
	ctx.r9.s64 = 284;
	// li r11,288
	r11.s64 = 288;
	// li r10,292
	ctx.r10.s64 = 292;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-14940
	ctx.r4.s64 = ctx.r7.s64 + -14940;
	// addi r3,r6,-14916
	ctx.r3.s64 = ctx.r6.s64 + -14916;
	// addi r8,r5,-14892
	ctx.r8.s64 = ctx.r5.s64 + -14892;
	// li r9,296
	ctx.r9.s64 = 296;
	// li r11,300
	r11.s64 = 300;
	// li r10,304
	ctx.r10.s64 = 304;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-14868
	ctx.r4.s64 = ctx.r7.s64 + -14868;
	// addi r3,r6,-14844
	ctx.r3.s64 = ctx.r6.s64 + -14844;
	// addi r8,r5,-14820
	ctx.r8.s64 = ctx.r5.s64 + -14820;
	// li r9,308
	ctx.r9.s64 = 308;
	// li r11,312
	r11.s64 = 312;
	// li r10,316
	ctx.r10.s64 = 316;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-14796
	ctx.r4.s64 = ctx.r7.s64 + -14796;
	// addi r3,r6,-14772
	ctx.r3.s64 = ctx.r6.s64 + -14772;
	// addi r8,r5,-14748
	ctx.r8.s64 = ctx.r5.s64 + -14748;
	// li r9,320
	ctx.r9.s64 = 320;
	// li r11,324
	r11.s64 = 324;
	// li r10,328
	ctx.r10.s64 = 328;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-14724
	ctx.r4.s64 = ctx.r7.s64 + -14724;
	// addi r3,r6,-14700
	ctx.r3.s64 = ctx.r6.s64 + -14700;
	// addi r8,r5,-14676
	ctx.r8.s64 = ctx.r5.s64 + -14676;
	// li r9,332
	ctx.r9.s64 = 332;
	// li r11,336
	r11.s64 = 336;
	// li r10,340
	ctx.r10.s64 = 340;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// addi r4,r7,-14652
	ctx.r4.s64 = ctx.r7.s64 + -14652;
	// addi r3,r6,-14628
	ctx.r3.s64 = ctx.r6.s64 + -14628;
	// addi r8,r5,-14604
	ctx.r8.s64 = ctx.r5.s64 + -14604;
	// li r9,344
	ctx.r9.s64 = 344;
	// li r11,348
	r11.s64 = 348;
	// li r10,352
	ctx.r10.s64 = 352;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// addi r5,r7,-14580
	ctx.r5.s64 = ctx.r7.s64 + -14580;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r9,r6,-14556
	ctx.r9.s64 = ctx.r6.s64 + -14556;
	// li r11,356
	r11.s64 = 356;
	// addi r8,r3,-14508
	ctx.r8.s64 = ctx.r3.s64 + -14508;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r10,360
	ctx.r10.s64 = 360;
	// addi r5,r4,-14532
	ctx.r5.s64 = ctx.r4.s64 + -14532;
	// li r11,368
	r11.s64 = 368;
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-14484
	ctx.r4.s64 = ctx.r7.s64 + -14484;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r9,364
	ctx.r9.s64 = 364;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r10,372
	ctx.r10.s64 = 372;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r3,r6,-14436
	ctx.r3.s64 = ctx.r6.s64 + -14436;
	// addi r5,r8,-14460
	ctx.r5.s64 = ctx.r8.s64 + -14460;
	// addi r4,r7,-14412
	ctx.r4.s64 = ctx.r7.s64 + -14412;
	// li r11,380
	r11.s64 = 380;
	// li r9,376
	ctx.r9.s64 = 376;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r10,384
	ctx.r10.s64 = 384;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r3,r6,-14364
	ctx.r3.s64 = ctx.r6.s64 + -14364;
	// addi r5,r8,-14388
	ctx.r5.s64 = ctx.r8.s64 + -14388;
	// addi r4,r7,-14340
	ctx.r4.s64 = ctx.r7.s64 + -14340;
	// li r11,392
	r11.s64 = 392;
	// li r9,388
	ctx.r9.s64 = 388;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r10,396
	ctx.r10.s64 = 396;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r3,r6,-14292
	ctx.r3.s64 = ctx.r6.s64 + -14292;
	// addi r5,r8,-14316
	ctx.r5.s64 = ctx.r8.s64 + -14316;
	// addi r4,r7,-14268
	ctx.r4.s64 = ctx.r7.s64 + -14268;
	// li r11,404
	r11.s64 = 404;
	// li r9,400
	ctx.r9.s64 = 400;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r10,408
	ctx.r10.s64 = 408;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// addi r3,r6,-14220
	ctx.r3.s64 = ctx.r6.s64 + -14220;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r8,-14244
	ctx.r5.s64 = ctx.r8.s64 + -14244;
	// addi r4,r7,-14196
	ctx.r4.s64 = ctx.r7.s64 + -14196;
	// li r11,416
	r11.s64 = 416;
	// li r9,412
	ctx.r9.s64 = 412;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// li r10,420
	ctx.r10.s64 = 420;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r3,r6,-14148
	ctx.r3.s64 = ctx.r6.s64 + -14148;
	// addi r5,r8,-14172
	ctx.r5.s64 = ctx.r8.s64 + -14172;
	// addi r4,r7,-14124
	ctx.r4.s64 = ctx.r7.s64 + -14124;
	// li r11,428
	r11.s64 = 428;
	// li r9,424
	ctx.r9.s64 = 424;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// li r10,432
	ctx.r10.s64 = 432;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// addi r3,r6,-14100
	ctx.r3.s64 = ctx.r6.s64 + -14100;
	// li r11,436
	r11.s64 = 436;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8270BE74;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8270BE84;
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
	ctx.lr = 0x8270BEA0;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-14072
	ctx.r4.s64 = ctx.r8.s64 + -14072;
	// bl 0x821d4b00
	ctx.lr = 0x8270BEB0;
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
	ctx.lr = 0x8270BEC8;
	sub_821C0548(ctx, base);
loc_8270BEC8:
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

__attribute__((alias("__imp__sub_8270BEE0"))) PPC_WEAK_FUNC(sub_8270BEE0);
PPC_FUNC_IMPL(__imp__sub_8270BEE0) {
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
	ctx.lr = 0x8270BEE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826fc678
	ctx.lr = 0x8270BEF4;
	sub_826FC678(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,2272
	ctx.r9.s64 = r11.s64 + 2272;
	// li r8,896
	ctx.r8.s64 = 896;
	// li r28,-1
	r28.s64 = -1;
	// li r30,0
	r30.s64 = 0;
	// addi r7,r10,27988
	ctx.r7.s64 = ctx.r10.s64 + 27988;
	// stw r28,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r28.u32);
	// li r29,1
	r29.s64 = 1;
	// stw r28,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r28.u32);
	// li r6,912
	ctx.r6.s64 = 912;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stb r29,872(r31)
	PPC_STORE_U8(r31.u32 + 872, r29.u8);
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// stb r30,880(r31)
	PPC_STORE_U8(r31.u32 + 880, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822381c0
	ctx.lr = 0x8270BF48;
	sub_822381C0(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stb r29,1072(r31)
	PPC_STORE_U8(r31.u32 + 1072, r29.u8);
	// stb r29,1073(r31)
	PPC_STORE_U8(r31.u32 + 1073, r29.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, r30.u8);
	// stw r30,1076(r31)
	PPC_STORE_U32(r31.u32 + 1076, r30.u32);
	// lfs f0,11412(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11412);
	f0.f64 = double(temp.f32);
	// stfs f0,1088(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1088, temp.u32);
	// stfs f0,1092(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1092, temp.u32);
	// stfs f0,1096(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1096, temp.u32);
	// stw r28,1120(r31)
	PPC_STORE_U32(r31.u32 + 1120, r28.u32);
	// lfs f0,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r28,1124(r31)
	PPC_STORE_U32(r31.u32 + 1124, r28.u32);
	// stfs f0,1104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1104, temp.u32);
	// stb r29,1148(r31)
	PPC_STORE_U8(r31.u32 + 1148, r29.u8);
	// stfs f0,1108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1108, temp.u32);
	// stw r30,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r30.u32);
	// stfs f0,1112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1112, temp.u32);
	// stb r30,1156(r31)
	PPC_STORE_U8(r31.u32 + 1156, r30.u8);
	// stfs f0,1116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1116, temp.u32);
	// stb r30,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r30.u8);
	// stfs f0,1128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
	// stfs f0,1132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
	// stfs f0,1136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1136, temp.u32);
	// stfs f0,1140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
	// stfs f0,1144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1144, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

