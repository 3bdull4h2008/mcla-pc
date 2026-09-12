#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826505B4"))) PPC_WEAK_FUNC(sub_826505B4);
PPC_FUNC_IMPL(__imp__sub_826505B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826505B8"))) PPC_WEAK_FUNC(sub_826505B8);
PPC_FUNC_IMPL(__imp__sub_826505B8) {
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
	// bl 0x82630980
	ctx.lr = 0x826505D0;
	sub_82630980(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826505E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82650604
	if (cr6.eq) goto loc_82650604;
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// li r31,1
	r31.s64 = 1;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82650608
	if (cr6.eq) goto loc_82650608;
loc_82650604:
	// li r31,0
	r31.s64 = 0;
loc_82650608:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// lwz r7,116(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r6,-24900
	ctx.r4.s64 = ctx.r6.s64 + -24900;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r3,1
	ctx.r5.u64 = ctx.r3.u64 ^ 1;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x8265064C;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_82650660"))) PPC_WEAK_FUNC(sub_82650660);
PPC_FUNC_IMPL(__imp__sub_82650660) {
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
	// bl 0x82630980
	ctx.lr = 0x82650678;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,96(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826506B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24932
	ctx.r4.s64 = ctx.r4.s64 + -24932;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826506D8;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_826506EC"))) PPC_WEAK_FUNC(sub_826506EC);
PPC_FUNC_IMPL(__imp__sub_826506EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826506F0"))) PPC_WEAK_FUNC(sub_826506F0);
PPC_FUNC_IMPL(__imp__sub_826506F0) {
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
	// bl 0x82630980
	ctx.lr = 0x82650708;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,796(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 796);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82650748
	if (cr6.eq) goto loc_82650748;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265074c
	if (!cr6.eq) goto loc_8265074C;
loc_82650748:
	// li r31,0
	r31.s64 = 0;
loc_8265074C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650760;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-12724
	ctx.r4.s64 = ctx.r9.s64 + -12724;
	// bl 0x825ee0e0
	ctx.lr = 0x82650774;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_82650788"))) PPC_WEAK_FUNC(sub_82650788);
PPC_FUNC_IMPL(__imp__sub_82650788) {
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
	ctx.lr = 0x82650790;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8265079C;
	sub_82630980(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826507B0;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// lwz r26,56(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x821f9fb8
	ctx.lr = 0x826507C8;
	sub_821F9FB8(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r29,-5052(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + -5052);
	// bl 0x82256058
	ctx.lr = 0x826507D8;
	sub_82256058(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r7,5996
	r31.s64 = ctx.r7.s64 + 5996;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826507F0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650800;
	sub_825ED480(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82650ba4
	if (cr6.eq) goto loc_82650BA4;
	// bl 0x825ef9f0
	ctx.lr = 0x8265080C;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,676(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82650b2c
	if (!cr6.eq) goto loc_82650B2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e0b0
	ctx.lr = 0x8265087C;
	sub_8227E0B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82257160
	ctx.lr = 0x8265088C;
	sub_82257160(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82257160
	ctx.lr = 0x8265089C;
	sub_82257160(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r29,0
	r29.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x826508b4
	if (!cr6.lt) goto loc_826508B4;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
loc_826508B4:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x826508c0
	if (!cr6.lt) goto loc_826508C0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
loc_826508C0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826509e4
	if (cr6.eq) goto loc_826509E4;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r25,1
	r25.s64 = 1;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r29,r11,2520
	r29.s64 = r11.s64 + 2520;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82202fb8
	ctx.lr = 0x826508F0;
	sub_82202FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265090C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82650ba4
	if (cr6.eq) goto loc_82650BA4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef808
	ctx.lr = 0x82650920;
	sub_825EF808(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// addi r27,r11,2544
	r27.s64 = r11.s64 + 2544;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x825ee0e0
	ctx.lr = 0x82650944;
	sub_825EE0E0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef808
	ctx.lr = 0x8265094C;
	sub_825EF808(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265095C;
	sub_825EE0E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// bne cr6,0x8265096c
	if (!cr6.eq) goto loc_8265096C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
loc_8265096C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-12608
	ctx.r4.s64 = ctx.r10.s64 + -12608;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x82650998
	if (!cr6.eq) goto loc_82650998;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
loc_82650998:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-12624
	ctx.r4.s64 = ctx.r10.s64 + -12624;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826509B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826509D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-24900
	ctx.r4.s64 = ctx.r6.s64 + -24900;
	// b 0x82650b88
	goto loc_82650B88;
loc_826509E4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,2544
	r30.s64 = r11.s64 + 2544;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826509FC;
	sub_825EE0E0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2520
	ctx.r4.s64 = r11.s64 + 2520;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650A10;
	sub_825EE0E0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82650A1C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5df8
	ctx.lr = 0x82650A20;
	sub_822A5DF8(ctx, base);
	// lwz r9,3100(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r9,13
	cr6.compare<int32_t>(ctx.r9.s32, 13, xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// bne cr6,0x82650a64
	if (!cr6.eq) goto loc_82650A64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r27,r11,27816
	r27.s64 = r11.s64 + 27816;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8223de50
	ctx.lr = 0x82650A44;
	sub_8223DE50(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r10,-12632
	ctx.r4.s64 = ctx.r10.s64 + -12632;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82650A58;
	sub_825EE2D8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-12652
	ctx.r4.s64 = ctx.r9.s64 + -12652;
	// b 0x82650ae8
	goto loc_82650AE8;
loc_82650A64:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r10,-12660
	ctx.r4.s64 = ctx.r10.s64 + -12660;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82650A7C;
	sub_82218310(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r25,r9,27816
	r25.s64 = ctx.r9.s64 + 27816;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r5,r8,2460
	ctx.r5.s64 = ctx.r8.s64 + 2460;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x82650AA0;
	sub_82137A08(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r7,-12672
	ctx.r4.s64 = ctx.r7.s64 + -12672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,52(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82650AC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r10,-12608
	ctx.r4.s64 = ctx.r10.s64 + -12608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82650AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r4,r7,-12688
	ctx.r4.s64 = ctx.r7.s64 + -12688;
loc_82650AE8:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650AF4;
	sub_825EE0E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B24;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_82650B2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r30,r10,2544
	r30.s64 = ctx.r10.s64 + 2544;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82650B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B68;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-12652
	ctx.r4.s64 = ctx.r7.s64 + -12652;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B7C;
	sub_825EE0E0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-12712
	ctx.r4.s64 = ctx.r6.s64 + -12712;
loc_82650B88:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B90;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r4,-12688
	ctx.r4.s64 = ctx.r4.s64 + -12688;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82650BA4;
	sub_825EE0E0(ctx, base);
loc_82650BA4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82650BAC"))) PPC_WEAK_FUNC(sub_82650BAC);
PPC_FUNC_IMPL(__imp__sub_82650BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82650BB0"))) PPC_WEAK_FUNC(sub_82650BB0);
PPC_FUNC_IMPL(__imp__sub_82650BB0) {
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
	ctx.lr = 0x82650BB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82650BC4;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11876
	ctx.r4.s64 = ctx.r10.s64 + -11876;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650BD8;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,-13532
	r31.s64 = ctx.r9.s64 + -13532;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r28,56(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82650BF4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650C04;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x82650C08;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82650d44
	if (cr6.eq) goto loc_82650D44;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82720e28
	ctx.lr = 0x82650C38;
	sub_82720E28(ctx, base);
	// lbz r10,100(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 100);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// addi r4,r11,-12556
	ctx.r4.s64 = r11.s64 + -12556;
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x825ee230
	ctx.lr = 0x82650C54;
	sub_825EE230(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r5,r30,772
	ctx.r5.s64 = r30.s64 + 772;
	// addi r4,r8,-12564
	ctx.r4.s64 = ctx.r8.s64 + -12564;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82650C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x82650C78;
	sub_82387A18(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82650c90
	if (cr6.eq) goto loc_82650C90;
	// addi r5,r30,448
	ctx.r5.s64 = r30.s64 + 448;
	// b 0x82650ca0
	goto loc_82650CA0;
loc_82650C90:
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,780(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 780);
	// bl 0x82218310
	ctx.lr = 0x82650C9C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82650CA0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-2948
	ctx.r4.s64 = ctx.r10.s64 + -2948;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,776(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x82650CCC;
	sub_82218310(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r7,52(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 52);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-12576
	ctx.r4.s64 = ctx.r8.s64 + -12576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650CE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,784(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x82650CF8;
	sub_82218310(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-10292
	ctx.r4.s64 = ctx.r6.s64 + -10292;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82650D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,784(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r10,-12592
	ctx.r4.s64 = ctx.r10.s64 + -12592;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x825ee230
	ctx.lr = 0x82650D3C;
	sub_825EE230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82650D44:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// addi r4,r10,-2948
	ctx.r4.s64 = ctx.r10.s64 + -2948;
	// stw r9,780(r30)
	PPC_STORE_U32(r30.u32 + 780, ctx.r9.u32);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r9,776(r30)
	PPC_STORE_U32(r30.u32 + 776, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,784(r30)
	PPC_STORE_U32(r30.u32 + 784, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650D78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r5,776(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-12576
	ctx.r4.s64 = ctx.r6.s64 + -12576;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r5,784(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-10292
	ctx.r4.s64 = ctx.r9.s64 + -10292;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-12556
	ctx.r4.s64 = ctx.r6.s64 + -12556;
	// bl 0x825ee230
	ctx.lr = 0x82650DCC;
	sub_825EE230(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82720560
	ctx.lr = 0x82650DD4;
	sub_82720560(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82650DDC"))) PPC_WEAK_FUNC(sub_82650DDC);
PPC_FUNC_IMPL(__imp__sub_82650DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82650DE0"))) PPC_WEAK_FUNC(sub_82650DE0);
PPC_FUNC_IMPL(__imp__sub_82650DE0) {
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
	ctx.lr = 0x82650DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826337a8
	ctx.lr = 0x82650DF4;
	sub_826337A8(ctx, base);
	// lbz r9,176(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-12516
	ctx.r10.s64 = r11.s64 + -12516;
	// clrlwi r8,r9,26
	ctx.r8.u64 = ctx.r9.u32 & 0x3F;
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r4,64
	ctx.r4.s64 = 64;
	// stb r8,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r8.u8);
	// addi r3,r31,468
	ctx.r3.s64 = r31.s64 + 468;
	// bl 0x827264f8
	ctx.lr = 0x82650E20;
	sub_827264F8(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stb r30,768(r31)
	PPC_STORE_U8(r31.u32 + 768, r30.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r30,772(r31)
	PPC_STORE_U32(r31.u32 + 772, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r30.u32);
	// addi r3,r5,3998
	ctx.r3.s64 = ctx.r5.s64 + 3998;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r4,788(r31)
	PPC_STORE_U8(r31.u32 + 788, ctx.r4.u8);
	// lfs f13,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stw r3,776(r31)
	PPC_STORE_U32(r31.u32 + 776, ctx.r3.u32);
	// stfs f0,792(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// stw r3,780(r31)
	PPC_STORE_U32(r31.u32 + 780, ctx.r3.u32);
	// stfs f13,800(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 800, temp.u32);
	// stw r3,784(r31)
	PPC_STORE_U32(r31.u32 + 784, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11876
	ctx.r4.s64 = ctx.r10.s64 + -11876;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650E74;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650e8c
	if (cr6.eq) goto loc_82650E8C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82630c38
	ctx.lr = 0x82650E8C;
	sub_82630C38(ctx, base);
loc_82650E8C:
	// stb r30,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r30.u8);
	// li r3,32
	ctx.r3.s64 = 32;
	// stb r30,448(r31)
	PPC_STORE_U8(r31.u32 + 448, r30.u8);
	// bl 0x82130528
	ctx.lr = 0x82650E9C;
	sub_82130528(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r29,r11,-12536
	r29.s64 = r11.s64 + -12536;
	// beq cr6,0x82650ec0
	if (cr6.eq) goto loc_82650EC0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,472(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 472);
	// bl 0x8218fad0
	ctx.lr = 0x82650EB8;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82650ec4
	goto loc_82650EC4;
loc_82650EC0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_82650EC4:
	// stw r5,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r5.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x82650ED8;
	sub_82182150(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fd60
	ctx.lr = 0x82650EE4;
	sub_8262FD60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82650EF0"))) PPC_WEAK_FUNC(sub_82650EF0);
PPC_FUNC_IMPL(__imp__sub_82650EF0) {
	PPC_FUNC_PROLOGUE();
	// stw r5,772(r3)
	PPC_STORE_U32(ctx.r3.u32 + 772, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82650EF8"))) PPC_WEAK_FUNC(sub_82650EF8);
PPC_FUNC_IMPL(__imp__sub_82650EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,772(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 772);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82650F04"))) PPC_WEAK_FUNC(sub_82650F04);
PPC_FUNC_IMPL(__imp__sub_82650F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82650F08"))) PPC_WEAK_FUNC(sub_82650F08);
PPC_FUNC_IMPL(__imp__sub_82650F08) {
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
	// addi r3,r31,468
	ctx.r3.s64 = r31.s64 + 468;
	// bl 0x82726128
	ctx.lr = 0x82650F2C;
	sub_82726128(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82650F34;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650f4c
	if (cr6.eq) goto loc_82650F4C;
	// bl 0x82130588
	ctx.lr = 0x82650F48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82650F4C:
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

__attribute__((alias("__imp__sub_82650F64"))) PPC_WEAK_FUNC(sub_82650F64);
PPC_FUNC_IMPL(__imp__sub_82650F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82650F68"))) PPC_WEAK_FUNC(sub_82650F68);
PPC_FUNC_IMPL(__imp__sub_82650F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82650F70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r9,-11876
	ctx.r4.s64 = ctx.r9.s64 + -11876;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,792(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 792, temp.u32);
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650F98;
	sub_821F9FB8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r30,r8,-13532
	r30.s64 = ctx.r8.s64 + -13532;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82650FB4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650FC4;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x82650FC8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,-11112
	ctx.r4.s64 = ctx.r6.s64 + -11112;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650FE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82650FEC"))) PPC_WEAK_FUNC(sub_82650FEC);
PPC_FUNC_IMPL(__imp__sub_82650FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82650FF0"))) PPC_WEAK_FUNC(sub_82650FF0);
PPC_FUNC_IMPL(__imp__sub_82650FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// lwz r11,-10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826510d4
	if (cr6.eq) goto loc_826510D4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8265102C;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bgt cr6,0x826510d4
	if (cr6.gt) goto loc_826510D4;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,4176
	r12.s64 = r12.s64 + 4176;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_82651060;
	case 1:
		goto loc_82651080;
	case 2:
		goto loc_826510A0;
	case 3:
		goto loc_826510AC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,4192(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4192);
	// lwz r19,4224(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4224);
	// lwz r19,4256(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4256);
	// lwz r19,4268(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4268);
loc_82651060:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r4,r10,-11800
	ctx.r4.s64 = ctx.r10.s64 + -11800;
	// bl 0x82218310
	ctx.lr = 0x82651074;
	sub_82218310(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-11820
	ctx.r4.s64 = ctx.r9.s64 + -11820;
	// b 0x826510c8
	goto loc_826510C8;
loc_82651080:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r4,r10,-11840
	ctx.r4.s64 = ctx.r10.s64 + -11840;
	// bl 0x82218310
	ctx.lr = 0x82651094;
	sub_82218310(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-11820
	ctx.r4.s64 = ctx.r9.s64 + -11820;
	// b 0x826510c8
	goto loc_826510C8;
loc_826510A0:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,-11868
	ctx.r4.s64 = ctx.r10.s64 + -11868;
	// b 0x826510b4
	goto loc_826510B4;
loc_826510AC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11900
	ctx.r4.s64 = ctx.r10.s64 + -11900;
loc_826510B4:
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82218310
	ctx.lr = 0x826510C0;
	sub_82218310(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-11916
	ctx.r4.s64 = ctx.r9.s64 + -11916;
loc_826510C8:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x826510D4;
	sub_825EE2D8(ctx, base);
loc_826510D4:
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

__attribute__((alias("__imp__sub_826510EC"))) PPC_WEAK_FUNC(sub_826510EC);
PPC_FUNC_IMPL(__imp__sub_826510EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826510F0"))) PPC_WEAK_FUNC(sub_826510F0);
PPC_FUNC_IMPL(__imp__sub_826510F0) {
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
	ctx.lr = 0x826510F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82651104;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18780
	ctx.r4.s64 = ctx.r10.s64 + -18780;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82651118;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82651230
	if (cr6.eq) goto loc_82651230;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82651230
	if (!cr6.eq) goto loc_82651230;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651168;
	sub_82720E28(ctx, base);
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826511e8
	if (cr6.eq) goto loc_826511E8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r4,r11,-11728
	ctx.r4.s64 = r11.s64 + -11728;
	// bl 0x825ee0e0
	ctx.lr = 0x8265118C;
	sub_825EE0E0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r10,-11744
	ctx.r4.s64 = ctx.r10.s64 + -11744;
	// bl 0x825ee0e0
	ctx.lr = 0x826511A0;
	sub_825EE0E0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,332(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 332);
	// lwz r29,56(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826511B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11760
	ctx.r4.s64 = ctx.r7.s64 + -11760;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x826511CC;
	sub_825EE2D8(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r4,r6,-11776
	ctx.r4.s64 = ctx.r6.s64 + -11776;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x825ee2d8
	ctx.lr = 0x826511E0;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826511E8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-11744
	ctx.r4.s64 = r11.s64 + -11744;
	// bl 0x825ee0e0
	ctx.lr = 0x826511F8;
	sub_825EE0E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r31,r10,3998
	r31.s64 = ctx.r10.s64 + 3998;
	// addi r4,r9,-11760
	ctx.r4.s64 = ctx.r9.s64 + -11760;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82651214;
	sub_825EE2D8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r8,-11776
	ctx.r4.s64 = ctx.r8.s64 + -11776;
	// bl 0x825ee2d8
	ctx.lr = 0x82651228;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82651230:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720560
	ctx.lr = 0x82651238;
	sub_82720560(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82651240"))) PPC_WEAK_FUNC(sub_82651240);
PPC_FUNC_IMPL(__imp__sub_82651240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8265125C;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265127C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r30,56(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r4,r4,-11640
	ctx.r4.s64 = ctx.r4.s64 + -11640;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826512B8;
	sub_825EE0E0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,192(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r9,-11656
	ctx.r4.s64 = ctx.r9.s64 + -11656;
	// bl 0x825ee188
	ctx.lr = 0x826512CC;
	sub_825EE188(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r8,-11676
	ctx.r4.s64 = ctx.r8.s64 + -11676;
	// bl 0x825ee188
	ctx.lr = 0x826512E0;
	sub_825EE188(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,-11700
	ctx.r4.s64 = ctx.r6.s64 + -11700;
	// lwz r3,-10244(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826512F4;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-11712
	ctx.r4.s64 = ctx.r4.s64 + -11712;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82651308;
	sub_825EE2D8(ctx, base);
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

__attribute__((alias("__imp__sub_82651320"))) PPC_WEAK_FUNC(sub_82651320);
PPC_FUNC_IMPL(__imp__sub_82651320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8265133C;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265135C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r5,208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-11552
	ctx.r4.s64 = ctx.r8.s64 + -11552;
	// bl 0x825ee0e0
	ctx.lr = 0x82651374;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,192(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r7,-11568
	ctx.r4.s64 = ctx.r7.s64 + -11568;
	// bl 0x825ee188
	ctx.lr = 0x82651388;
	sub_825EE188(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r4,r6,-11584
	ctx.r4.s64 = ctx.r6.s64 + -11584;
	// bl 0x825ee0e0
	ctx.lr = 0x8265139C;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r4,r4,-11600
	ctx.r4.s64 = ctx.r4.s64 + -11600;
	// bl 0x825ee0e0
	ctx.lr = 0x826513B0;
	sub_825EE0E0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r11,-11620
	ctx.r4.s64 = r11.s64 + -11620;
	// bl 0x825ee188
	ctx.lr = 0x826513C4;
	sub_825EE188(ctx, base);
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

__attribute__((alias("__imp__sub_826513DC"))) PPC_WEAK_FUNC(sub_826513DC);
PPC_FUNC_IMPL(__imp__sub_826513DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826513E0"))) PPC_WEAK_FUNC(sub_826513E0);
PPC_FUNC_IMPL(__imp__sub_826513E0) {
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
	// bl 0x82630980
	ctx.lr = 0x826513F8;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,92(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24916
	ctx.r4.s64 = ctx.r4.s64 + -24916;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82651458;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_8265146C"))) PPC_WEAK_FUNC(sub_8265146C);
PPC_FUNC_IMPL(__imp__sub_8265146C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651470"))) PPC_WEAK_FUNC(sub_82651470);
PPC_FUNC_IMPL(__imp__sub_82651470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82651478;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265149C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826514B4;
	sub_821F9FB8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-24916
	ctx.r4.s64 = ctx.r8.s64 + -24916;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x826514CC;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r27,r7,-24900
	r27.s64 = ctx.r7.s64 + -24900;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826514E4;
	sub_825EE0E0(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-27060
	ctx.r4.s64 = ctx.r6.s64 + -27060;
	// bl 0x825ee0e0
	ctx.lr = 0x826514F8;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r4,-11532
	ctx.r4.s64 = ctx.r4.s64 + -11532;
	// bl 0x825ee0e0
	ctx.lr = 0x8265150C;
	sub_825EE0E0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r11,-11552
	ctx.r4.s64 = r11.s64 + -11552;
	// bl 0x825ee230
	ctx.lr = 0x82651520;
	sub_825EE230(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r4,r10,-25148
	ctx.r4.s64 = ctx.r10.s64 + -25148;
	// bl 0x825ee0e0
	ctx.lr = 0x82651534;
	sub_825EE0E0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r26,r9,2544
	r26.s64 = ctx.r9.s64 + 2544;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265154C;
	sub_825EE0E0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r4,r8,2520
	ctx.r4.s64 = ctx.r8.s64 + 2520;
	// bl 0x825ee0e0
	ctx.lr = 0x82651560;
	sub_825EE0E0(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r25,r7,5996
	r25.s64 = ctx.r7.s64 + 5996;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r31,56(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82651578;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82651588;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8265158C;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,44(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826515AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r10,-12652
	ctx.r4.s64 = ctx.r10.s64 + -12652;
	// bl 0x825ee0e0
	ctx.lr = 0x826515C0;
	sub_825EE0E0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-12712
	ctx.r4.s64 = ctx.r9.s64 + -12712;
	// bl 0x825ee0e0
	ctx.lr = 0x826515D4;
	sub_825EE0E0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r8,-12688
	ctx.r4.s64 = ctx.r8.s64 + -12688;
	// bl 0x825ee0e0
	ctx.lr = 0x826515E8;
	sub_825EE0E0(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r7,-21684
	ctx.r4.s64 = ctx.r7.s64 + -21684;
	// bl 0x825ee0e0
	ctx.lr = 0x826515FC;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82651618;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-24980
	ctx.r4.s64 = r11.s64 + -24980;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x825ee0e0
	ctx.lr = 0x82651630;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265164C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,116(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x82651660;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265167C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// bl 0x8223dfb0
	ctx.lr = 0x82651688;
	sub_8223DFB0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r5,1
	ctx.r3.s64 = ctx.r5.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826516A0;
	sub_82641CB0(ctx, base);
	// addi r3,r3,1024
	ctx.r3.s64 = ctx.r3.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826516B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,56(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826516C8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x826516D8;
	sub_825ED480(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r27,r9,-13284
	r27.s64 = ctx.r9.s64 + -13284;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x826516F4;
	sub_82722678(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x82651708;
	sub_82722678(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r31,r7,20304
	r31.s64 = ctx.r7.s64 + 20304;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82651728;
	sub_82722678(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x82651738;
	sub_825EE0E0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-11640
	ctx.r4.s64 = ctx.r6.s64 + -11640;
	// bl 0x825ee0e0
	ctx.lr = 0x8265174C;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82720560
	ctx.lr = 0x82651754;
	sub_82720560(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8265175C"))) PPC_WEAK_FUNC(sub_8265175C);
PPC_FUNC_IMPL(__imp__sub_8265175C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651760"))) PPC_WEAK_FUNC(sub_82651760);
PPC_FUNC_IMPL(__imp__sub_82651760) {
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
	ctx.lr = 0x82651768;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-20092
	ctx.r3.s64 = r11.s64 + -20092;
	// bl 0x821fa210
	ctx.lr = 0x8265177C;
	sub_821FA210(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10028(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x8265178C;
	sub_822040F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947e0
	ctx.lr = 0x82651798;
	sub_826947E0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// xori r28,r7,1
	r28.u64 = ctx.r7.u64 ^ 1;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826517B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826517f8
	if (!cr6.eq) goto loc_826517F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826517D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826517f8
	if (!cr6.eq) goto loc_826517F8;
	// bl 0x8265eb48
	ctx.lr = 0x826517E8;
	sub_8265EB48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x826517fc
	if (cr6.eq) goto loc_826517FC;
loc_826517F8:
	// li r11,1
	r11.s64 = 1;
loc_826517FC:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x82651808;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82651838
	if (cr6.eq) goto loc_82651838;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651838
	if (!cr6.eq) goto loc_82651838;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651838
	if (!cr6.eq) goto loc_82651838;
	// bl 0x82387b90
	ctx.lr = 0x8265182C;
	sub_82387B90(ctx, base);
	// lwz r11,1204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1204);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8265184c
	if (!cr6.eq) goto loc_8265184C;
loc_82651838:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lbz r10,628(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 628);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82651850
	if (cr6.eq) goto loc_82651850;
loc_8265184C:
	// li r31,1
	r31.s64 = 1;
loc_82651850:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651874
	if (!cr6.eq) goto loc_82651874;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651874
	if (!cr6.eq) goto loc_82651874;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651880
	if (cr6.eq) goto loc_82651880;
loc_82651874:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82651880:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8265188C"))) PPC_WEAK_FUNC(sub_8265188C);
PPC_FUNC_IMPL(__imp__sub_8265188C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651890"))) PPC_WEAK_FUNC(sub_82651890);
PPC_FUNC_IMPL(__imp__sub_82651890) {
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
	ctx.lr = 0x82651898;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r11,-18780
	ctx.r4.s64 = r11.s64 + -18780;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826518B4;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826518D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addis r29,r11,1
	r29.s64 = r11.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826518F4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82651904;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8264ec10
	ctx.lr = 0x82651910;
	sub_8264EC10(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651920;
	sub_82720E28(ctx, base);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8265194C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r10,-20132
	ctx.r4.s64 = ctx.r10.s64 + -20132;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82651968;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,2816(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r6,r7,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265199c
	if (cr6.eq) goto loc_8265199C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651998;
	sub_82720E28(ctx, base);
	// b 0x826519d8
	goto loc_826519D8;
loc_8265199C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x826519CC;
	sub_82720E28(ctx, base);
	// b 0x826519d8
	goto loc_826519D8;
loc_826519D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720560
	ctx.lr = 0x826519D8;
	sub_82720560(ctx, base);
loc_826519D8:
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826519f4
	if (!cr6.eq) goto loc_826519F4;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826519f8
	if (cr6.eq) goto loc_826519F8;
loc_826519F4:
	// li r30,1
	r30.s64 = 1;
loc_826519F8:
	// lbz r11,896(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 896);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82651a1c
	if (cr6.eq) goto loc_82651A1C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651A1C:
	// stb r30,896(r28)
	PPC_STORE_U8(r28.u32 + 896, r30.u8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82651a38
	if (!cr6.eq) goto loc_82651A38;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82651a3c
	if (cr6.eq) goto loc_82651A3C;
loc_82651A38:
	// li r11,0
	r11.s64 = 0;
loc_82651A3C:
	// lbz r10,5708(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5708);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// rlwimi r10,r11,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,5708(r31)
	PPC_STORE_U8(r31.u32 + 5708, ctx.r10.u8);
	// bne cr6,0x82651a6c
	if (!cr6.eq) goto loc_82651A6C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651a6c
	if (!cr6.eq) goto loc_82651A6C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651a70
	if (cr6.eq) goto loc_82651A70;
loc_82651A6C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651A70:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651A84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82651a9c
	if (!cr6.eq) goto loc_82651A9C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651aa0
	if (cr6.eq) goto loc_82651AA0;
loc_82651A9C:
	// li r4,1
	ctx.r4.s64 = 1;
loc_82651AA0:
	// lwz r11,2832(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,640(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651AE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,2000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,448(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,1408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1408);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1216(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651B44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82651b60
	if (cr6.eq) goto loc_82651B60;
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82651b64
	if (!cr6.eq) goto loc_82651B64;
loc_82651B60:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651B64:
	// lwz r11,3648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3648);
	// addi r3,r31,3648
	ctx.r3.s64 = r31.s64 + 3648;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1024(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651B90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 692);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651BA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lwz r11,-3624(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -3624);
	// lwz r4,700(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r11,796(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 796);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,5472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5472);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x82651bd4
	if (!cr6.eq) goto loc_82651BD4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651BD4:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82651BE4"))) PPC_WEAK_FUNC(sub_82651BE4);
PPC_FUNC_IMPL(__imp__sub_82651BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651BE8"))) PPC_WEAK_FUNC(sub_82651BE8);
PPC_FUNC_IMPL(__imp__sub_82651BE8) {
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
	ctx.lr = 0x82651BF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82651890
	ctx.lr = 0x82651BFC;
	sub_82651890(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651C14;
	sub_82641CB0(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82203f98
	ctx.lr = 0x82651C24;
	sub_82203F98(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82204018
	ctx.lr = 0x82651C34;
	sub_82204018(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82203fd8
	ctx.lr = 0x82651C44;
	sub_82203FD8(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82651c64
	if (cr6.eq) goto loc_82651C64;
	// lwz r11,1808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651C64:
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651C94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1600(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651CAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,2000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// beq cr6,0x82651cd8
	if (cr6.eq) goto loc_82651CD8;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x82651cdc
	if (!cr6.eq) goto loc_82651CDC;
loc_82651CD8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651CDC:
	// addi r31,r31,832
	r31.s64 = r31.s64 + 832;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82651CFC;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651d1c
	if (cr6.eq) goto loc_82651D1C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651D1C:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82651D24;
	sub_822040F8(ctx, base);
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82651D3C"))) PPC_WEAK_FUNC(sub_82651D3C);
PPC_FUNC_IMPL(__imp__sub_82651D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651D40"))) PPC_WEAK_FUNC(sub_82651D40);
PPC_FUNC_IMPL(__imp__sub_82651D40) {
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
	// bl 0x82651890
	ctx.lr = 0x82651D54;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651D6C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,5280(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 5280);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1808(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82651DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651DD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1600(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651E00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1024(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651E18;
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

__attribute__((alias("__imp__sub_82651E2C"))) PPC_WEAK_FUNC(sub_82651E2C);
PPC_FUNC_IMPL(__imp__sub_82651E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651E30"))) PPC_WEAK_FUNC(sub_82651E30);
PPC_FUNC_IMPL(__imp__sub_82651E30) {
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
	// bl 0x82651be8
	ctx.lr = 0x82651E44;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651E5C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1024(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651E90;
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

__attribute__((alias("__imp__sub_82651EA4"))) PPC_WEAK_FUNC(sub_82651EA4);
PPC_FUNC_IMPL(__imp__sub_82651EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651EA8"))) PPC_WEAK_FUNC(sub_82651EA8);
PPC_FUNC_IMPL(__imp__sub_82651EA8) {
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
	// bl 0x82651be8
	ctx.lr = 0x82651EBC;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651ED4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// lwz r10,1600(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,832(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651F08;
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

__attribute__((alias("__imp__sub_82651F1C"))) PPC_WEAK_FUNC(sub_82651F1C);
PPC_FUNC_IMPL(__imp__sub_82651F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651F20"))) PPC_WEAK_FUNC(sub_82651F20);
PPC_FUNC_IMPL(__imp__sub_82651F20) {
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
	ctx.lr = 0x82651F28;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82651be8
	ctx.lr = 0x82651F30;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651F48;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,1600
	r30.s64 = r31.s64 + 1600;
	// lwz r29,1600(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// bl 0x8264e598
	ctx.lr = 0x82651F58;
	sub_8264E598(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651F74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,832(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1808(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651FA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,2192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82651FC4"))) PPC_WEAK_FUNC(sub_82651FC4);
PPC_FUNC_IMPL(__imp__sub_82651FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82651FC8"))) PPC_WEAK_FUNC(sub_82651FC8);
PPC_FUNC_IMPL(__imp__sub_82651FC8) {
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
	// bl 0x82651890
	ctx.lr = 0x82651FD8;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651FF0;
	sub_82641CB0(ctx, base);
	// addi r3,r3,832
	ctx.r3.s64 = ctx.r3.s64 + 832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652008;
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

__attribute__((alias("__imp__sub_82652018"))) PPC_WEAK_FUNC(sub_82652018);
PPC_FUNC_IMPL(__imp__sub_82652018) {
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
	// bl 0x82651be8
	ctx.lr = 0x8265202C;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82652044;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1600(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652078;
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

__attribute__((alias("__imp__sub_8265208C"))) PPC_WEAK_FUNC(sub_8265208C);
PPC_FUNC_IMPL(__imp__sub_8265208C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82652090"))) PPC_WEAK_FUNC(sub_82652090);
PPC_FUNC_IMPL(__imp__sub_82652090) {
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
	// bl 0x82651be8
	ctx.lr = 0x826520A0;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826520B8;
	sub_82641CB0(ctx, base);
	// addi r3,r3,832
	ctx.r3.s64 = ctx.r3.s64 + 832;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826520D0;
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

__attribute__((alias("__imp__sub_826520E0"))) PPC_WEAK_FUNC(sub_826520E0);
PPC_FUNC_IMPL(__imp__sub_826520E0) {
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
	// bl 0x82651890
	ctx.lr = 0x826520F4;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265210C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1808(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,2000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82652158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82652188;
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

__attribute__((alias("__imp__sub_8265219C"))) PPC_WEAK_FUNC(sub_8265219C);
PPC_FUNC_IMPL(__imp__sub_8265219C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826521A0"))) PPC_WEAK_FUNC(sub_826521A0);
PPC_FUNC_IMPL(__imp__sub_826521A0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x826521A8;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r11,-10740
	ctx.r4.s64 = r11.s64 + -10740;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633e80
	ctx.lr = 0x826521C4;
	sub_82633E80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r27,r31,256
	r27.s64 = r31.s64 + 256;
	// addi r9,r10,-11508
	ctx.r9.s64 = ctx.r10.s64 + -11508;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x826337a8
	ctx.lr = 0x826521DC;
	sub_826337A8(ctx, base);
	// lbz r6,432(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 432);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-21564
	ctx.r7.s64 = ctx.r8.s64 + -21564;
	// stb r5,432(r31)
	PPC_STORE_U8(r31.u32 + 432, ctx.r5.u8);
	// addi r26,r31,448
	r26.s64 = r31.s64 + 448;
	// stw r7,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r7.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652200;
	sub_826337A8(ctx, base);
	// lbz r10,624(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 624);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-20908
	r11.s64 = ctx.r4.s64 + -20908;
	// stb r9,624(r31)
	PPC_STORE_U8(r31.u32 + 624, ctx.r9.u8);
	// addi r25,r31,640
	r25.s64 = r31.s64 + 640;
	// stw r11,448(r31)
	PPC_STORE_U32(r31.u32 + 448, r11.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652224;
	sub_826337A8(ctx, base);
	// lbz r6,816(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 816);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-20252
	ctx.r7.s64 = ctx.r8.s64 + -20252;
	// stb r5,816(r31)
	PPC_STORE_U8(r31.u32 + 816, ctx.r5.u8);
	// addi r24,r31,832
	r24.s64 = r31.s64 + 832;
	// stw r7,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r7.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652248;
	sub_826337A8(ctx, base);
	// lbz r10,1008(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1008);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-19596
	r11.s64 = ctx.r4.s64 + -19596;
	// stb r9,1008(r31)
	PPC_STORE_U8(r31.u32 + 1008, ctx.r9.u8);
	// addi r23,r31,1024
	r23.s64 = r31.s64 + 1024;
	// stw r11,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r11.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265226C;
	sub_826337A8(ctx, base);
	// lbz r6,1200(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1200);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-18940
	ctx.r7.s64 = ctx.r8.s64 + -18940;
	// stb r5,1200(r31)
	PPC_STORE_U8(r31.u32 + 1200, ctx.r5.u8);
	// addi r22,r31,1216
	r22.s64 = r31.s64 + 1216;
	// stw r7,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, ctx.r7.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652290;
	sub_826337A8(ctx, base);
	// lbz r10,1392(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1392);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-18284
	r11.s64 = ctx.r4.s64 + -18284;
	// stb r9,1392(r31)
	PPC_STORE_U8(r31.u32 + 1392, ctx.r9.u8);
	// addi r21,r31,1408
	r21.s64 = r31.s64 + 1408;
	// stw r11,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r11.u32);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x826337a8
	ctx.lr = 0x826522B4;
	sub_826337A8(ctx, base);
	// lbz r6,1584(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1584);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-17628
	ctx.r7.s64 = ctx.r8.s64 + -17628;
	// stb r5,1584(r31)
	PPC_STORE_U8(r31.u32 + 1584, ctx.r5.u8);
	// addi r20,r31,1600
	r20.s64 = r31.s64 + 1600;
	// stw r7,1408(r31)
	PPC_STORE_U32(r31.u32 + 1408, ctx.r7.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x826337a8
	ctx.lr = 0x826522D8;
	sub_826337A8(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r19,r31,1808
	r19.s64 = r31.s64 + 1808;
	// lbz r10,1776(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1776);
	// addi r11,r4,-22908
	r11.s64 = ctx.r4.s64 + -22908;
	// lbz r9,1804(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1804);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r11,1600(r31)
	PPC_STORE_U32(r31.u32 + 1600, r11.u32);
	// clrlwi r8,r10,26
	ctx.r8.u64 = ctx.r10.u32 & 0x3F;
	// clrlwi r7,r9,27
	ctx.r7.u64 = ctx.r9.u32 & 0x1F;
	// stb r8,1776(r31)
	PPC_STORE_U8(r31.u32 + 1776, ctx.r8.u8);
	// stb r7,1804(r31)
	PPC_STORE_U8(r31.u32 + 1804, ctx.r7.u8);
	// bl 0x826337a8
	ctx.lr = 0x82652308;
	sub_826337A8(ctx, base);
	// lbz r4,1984(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1984);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-16972
	ctx.r5.s64 = ctx.r6.s64 + -16972;
	// stb r11,1984(r31)
	PPC_STORE_U8(r31.u32 + 1984, r11.u8);
	// addi r18,r31,2000
	r18.s64 = r31.s64 + 2000;
	// stw r5,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, ctx.r5.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265232C;
	sub_826337A8(ctx, base);
	// lbz r8,2176(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2176);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// addi r9,r10,-16316
	ctx.r9.s64 = ctx.r10.s64 + -16316;
	// stb r7,2176(r31)
	PPC_STORE_U8(r31.u32 + 2176, ctx.r7.u8);
	// addi r17,r31,2192
	r17.s64 = r31.s64 + 2192;
	// stw r9,2000(r31)
	PPC_STORE_U32(r31.u32 + 2000, ctx.r9.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652350;
	sub_826337A8(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lbz r11,2368(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2368);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r5,-24876
	ctx.r3.s64 = ctx.r5.s64 + -24876;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r4,2396(r31)
	PPC_STORE_U8(r31.u32 + 2396, ctx.r4.u8);
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r3,2192(r31)
	PPC_STORE_U32(r31.u32 + 2192, ctx.r3.u32);
	// stfs f31,2384(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2384, temp.u32);
	// stb r10,2368(r31)
	PPC_STORE_U8(r31.u32 + 2368, ctx.r10.u8);
	// stfs f31,2388(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2388, temp.u32);
	// addi r30,r31,2400
	r30.s64 = r31.s64 + 2400;
	// stfs f31,2392(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2392, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652390;
	sub_826337A8(ctx, base);
	// lbz r7,2576(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 2576);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stfs f31,2592(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2592, temp.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r8,r9,-22252
	ctx.r8.s64 = ctx.r9.s64 + -22252;
	// clrlwi r6,r7,26
	ctx.r6.u64 = ctx.r7.u32 & 0x3F;
	// stw r28,2596(r31)
	PPC_STORE_U32(r31.u32 + 2596, r28.u32);
	// stw r8,2400(r31)
	PPC_STORE_U32(r31.u32 + 2400, ctx.r8.u32);
	// addi r16,r31,2624
	r16.s64 = r31.s64 + 2624;
	// stw r28,2600(r31)
	PPC_STORE_U32(r31.u32 + 2600, r28.u32);
	// stb r6,2576(r31)
	PPC_STORE_U8(r31.u32 + 2576, ctx.r6.u8);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x826337a8
	ctx.lr = 0x826523C4;
	sub_826337A8(ctx, base);
	// lbz r9,2816(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// lbz r10,2800(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2800);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// clrlwi r7,r9,25
	ctx.r7.u64 = ctx.r9.u32 & 0x7F;
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r11,r5,-24220
	r11.s64 = ctx.r5.s64 + -24220;
	// clrlwi r8,r10,26
	ctx.r8.u64 = ctx.r10.u32 & 0x3F;
	// stw r4,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r4.u32);
	// rlwinm r7,r7,0,27,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,2624(r31)
	PPC_STORE_U32(r31.u32 + 2624, r11.u32);
	// stb r8,2800(r31)
	PPC_STORE_U8(r31.u32 + 2800, ctx.r8.u8);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// stb r7,2816(r31)
	PPC_STORE_U8(r31.u32 + 2816, ctx.r7.u8);
	// bl 0x82650de0
	ctx.lr = 0x826523FC;
	sub_82650DE0(ctx, base);
	// addi r29,r31,3648
	r29.s64 = r31.s64 + 3648;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652408;
	sub_826337A8(ctx, base);
	// lbz r4,3824(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 3824);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-15660
	ctx.r5.s64 = ctx.r6.s64 + -15660;
	// stb r11,3824(r31)
	PPC_STORE_U8(r31.u32 + 3824, r11.u8);
	// addi r15,r31,3840
	r15.s64 = r31.s64 + 3840;
	// stw r5,3648(r31)
	PPC_STORE_U32(r31.u32 + 3648, ctx.r5.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265242C;
	sub_826337A8(ctx, base);
	// stfs f31,4032(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4032, temp.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// lbz r8,4016(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4016);
	// addi r9,r10,-23564
	ctx.r9.s64 = ctx.r10.s64 + -23564;
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// stw r9,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, ctx.r9.u32);
	// stb r7,4016(r31)
	PPC_STORE_U8(r31.u32 + 4016, ctx.r7.u8);
	// bl 0x82233a60
	ctx.lr = 0x82652450;
	sub_82233A60(ctx, base);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// bl 0x826337a8
	ctx.lr = 0x82652458;
	sub_826337A8(ctx, base);
	// lbz r4,5456(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 5456);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-15004
	ctx.r5.s64 = ctx.r6.s64 + -15004;
	// stb r11,5456(r31)
	PPC_STORE_U8(r31.u32 + 5456, r11.u8);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// stw r5,5280(r31)
	PPC_STORE_U32(r31.u32 + 5280, ctx.r5.u32);
	// bl 0x826337a8
	ctx.lr = 0x82652478;
	sub_826337A8(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r7,r10,-14348
	ctx.r7.s64 = ctx.r10.s64 + -14348;
	// addi r10,r6,-13516
	ctx.r10.s64 = ctx.r6.s64 + -13516;
	// addi r6,r11,-12752
	ctx.r6.s64 = r11.s64 + -12752;
	// stw r7,5472(r31)
	PPC_STORE_U32(r31.u32 + 5472, ctx.r7.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r14,r11,-13640
	r14.s64 = r11.s64 + -13640;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r5,r9,-13696
	ctx.r5.s64 = ctx.r9.s64 + -13696;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r8,-13592
	ctx.r3.s64 = ctx.r8.s64 + -13592;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r8,r4,-13484
	ctx.r8.s64 = ctx.r4.s64 + -13484;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r9,r9,-13668
	ctx.r9.s64 = ctx.r9.s64 + -13668;
	// addi r7,r7,-13452
	ctx.r7.s64 = ctx.r7.s64 + -13452;
	// addi r4,r4,-13420
	ctx.r4.s64 = ctx.r4.s64 + -13420;
	// lbz r11,5648(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5648);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stb r11,5648(r31)
	PPC_STORE_U8(r31.u32 + 5648, r11.u8);
	// stw r5,5664(r31)
	PPC_STORE_U32(r31.u32 + 5664, ctx.r5.u32);
	// stw r3,5668(r31)
	PPC_STORE_U32(r31.u32 + 5668, ctx.r3.u32);
	// stw r10,5672(r31)
	PPC_STORE_U32(r31.u32 + 5672, ctx.r10.u32);
	// stw r8,5676(r31)
	PPC_STORE_U32(r31.u32 + 5676, ctx.r8.u32);
	// stw r6,5680(r31)
	PPC_STORE_U32(r31.u32 + 5680, ctx.r6.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stb r28,5684(r31)
	PPC_STORE_U8(r31.u32 + 5684, r28.u8);
	// stw r9,5688(r31)
	PPC_STORE_U32(r31.u32 + 5688, ctx.r9.u32);
	// stw r7,5692(r31)
	PPC_STORE_U32(r31.u32 + 5692, ctx.r7.u32);
	// stw r4,5696(r31)
	PPC_STORE_U32(r31.u32 + 5696, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r14,5700(r31)
	PPC_STORE_U32(r31.u32 + 5700, r14.u32);
	// lbz r10,5708(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5708);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,5708(r31)
	PPC_STORE_U8(r31.u32 + 5708, ctx.r9.u8);
	// stw r28,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r28.u32);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r22,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r22.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r21,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r21.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r20,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r20.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r19,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r19.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r18,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r18.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r17,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r17.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r16,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r16.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,2832
	r11.s64 = r31.s64 + 2832;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r15,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r15.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r11,r31,4048
	r11.s64 = r31.s64 + 4048;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r31,5280
	r11.s64 = r31.s64 + 5280;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r23,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r23.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// addi r11,r31,5472
	r11.s64 = r31.s64 + 5472;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,-10236(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,3648(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3648);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,2400(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265274C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,5704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 5704, temp.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82652768"))) PPC_WEAK_FUNC(sub_82652768);
PPC_FUNC_IMPL(__imp__sub_82652768) {
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
	// bl 0x826438b8
	ctx.lr = 0x82652788;
	sub_826438B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826527a0
	if (cr6.eq) goto loc_826527A0;
	// bl 0x82130588
	ctx.lr = 0x8265279C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826527A0:
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

__attribute__((alias("__imp__sub_826527B8"))) PPC_WEAK_FUNC(sub_826527B8);
PPC_FUNC_IMPL(__imp__sub_826527B8) {
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
	ctx.lr = 0x826527C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r31,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r31.u32);
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826527E4;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r29,56(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// bl 0x821f9fb8
	ctx.lr = 0x826527FC;
	sub_821F9FB8(ctx, base);
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
loc_82652800:
	// cmpwi cr6,r31,11
	cr6.compare<int32_t>(r31.s32, 11, xer);
	// beq cr6,0x82652830
	if (cr6.eq) goto loc_82652830;
	// cmpwi cr6,r31,12
	cr6.compare<int32_t>(r31.s32, 12, xer);
	// beq cr6,0x8265284c
	if (cr6.eq) goto loc_8265284C;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,196(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82652848
	goto loc_82652848;
loc_82652830:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82652848:
	// bctrl 
	ctx.lr = 0x8265284C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265284C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,19
	cr6.compare<int32_t>(r31.s32, 19, xer);
	// blt cr6,0x82652800
	if (cr6.lt) goto loc_82652800;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82652860"))) PPC_WEAK_FUNC(sub_82652860);
PPC_FUNC_IMPL(__imp__sub_82652860) {
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
	// bl 0x82630980
	ctx.lr = 0x82652878;
	sub_82630980(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265288C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4048);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x826528bc
	if (!cr6.eq) goto loc_826528BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826528B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// bl 0x82651470
	ctx.lr = 0x826528B8;
	sub_82651470(ctx, base);
	// b 0x826528c8
	goto loc_826528C8;
loc_826528BC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826528C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826528C8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826528E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826528F8;
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

__attribute__((alias("__imp__sub_8265290C"))) PPC_WEAK_FUNC(sub_8265290C);
PPC_FUNC_IMPL(__imp__sub_8265290C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82652910"))) PPC_WEAK_FUNC(sub_82652910);
PPC_FUNC_IMPL(__imp__sub_82652910) {
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
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82652948
	if (!cr6.eq) goto loc_82652948;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82652944;
	sub_821F9FB8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
loc_82652948:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
	// bl 0x821e6828
	ctx.lr = 0x82652960;
	sub_821E6828(ctx, base);
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

__attribute__((alias("__imp__sub_82652974"))) PPC_WEAK_FUNC(sub_82652974);
PPC_FUNC_IMPL(__imp__sub_82652974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82652978"))) PPC_WEAK_FUNC(sub_82652978);
PPC_FUNC_IMPL(__imp__sub_82652978) {
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
	ctx.lr = 0x82652980;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x8264e598
	ctx.lr = 0x8265298C;
	sub_8264E598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826529f8
	if (!cr6.eq) goto loc_826529F8;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826529c8
	if (cr6.eq) goto loc_826529C8;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826529e4
	if (!cr6.gt) goto loc_826529E4;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826529d8
	goto loc_826529D8;
loc_826529C8:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826529e4
	if (!cr6.gt) goto loc_826529E4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826529D8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826529e8
	if (!cr6.eq) goto loc_826529E8;
loc_826529E4:
	// li r11,0
	r11.s64 = 0;
loc_826529E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826529fc
	if (!cr6.eq) goto loc_826529FC;
loc_826529F8:
	// li r11,1
	r11.s64 = 1;
loc_826529FC:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-10116
	ctx.r3.s64 = ctx.r10.s64 + -10116;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r29,r11,1
	r29.s64 = r11.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// bl 0x821fa230
	ctx.lr = 0x82652A1C;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82652A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10132
	ctx.r3.s64 = r11.s64 + -10132;
	// bl 0x821fa230
	ctx.lr = 0x82652A44;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13240
	ctx.r3.s64 = r11.s64 + -13240;
	// bl 0x821fa230
	ctx.lr = 0x82652A6C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652AA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82652AB4;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652acc
	if (cr6.eq) goto loc_82652ACC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82652ACC:
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// ori r9,r10,4944
	ctx.r9.u64 = ctx.r10.u64 | 4944;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4994
	ctx.r9.u64 = ctx.r10.u64 | 4994;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r31,1
	r31.s64 = 1;
	// addi r4,r10,-10144
	ctx.r4.s64 = ctx.r10.s64 + -10144;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82652B30;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652b48
	if (cr6.eq) goto loc_82652B48;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r31,r9,1
	r31.u64 = ctx.r9.u64 ^ 1;
loc_82652B48:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21664
	ctx.r4.s64 = ctx.r10.s64 + -21664;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82652B68;
	sub_821F9FB8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r9,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// beq cr6,0x82652b8c
	if (cr6.eq) goto loc_82652B8C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// bl 0x825ee270
	ctx.lr = 0x82652B8C;
	sub_825EE270(ctx, base);
loc_82652B8C:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8264ec10
	ctx.lr = 0x82652BA0;
	sub_8264EC10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82652bd8
	if (cr6.eq) goto loc_82652BD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82652bd8
	if (cr6.eq) goto loc_82652BD8;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652BD8:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207068
	ctx.lr = 0x82652BE0;
	sub_82207068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652bf8
	if (cr6.eq) goto loc_82652BF8;
	// bl 0x82256058
	ctx.lr = 0x82652BF0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652BF8:
	// bl 0x8264e598
	ctx.lr = 0x82652BFC;
	sub_8264E598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82652c34
	if (cr6.eq) goto loc_82652C34;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652c50
	if (!cr6.gt) goto loc_82652C50;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x82652c44
	goto loc_82652C44;
loc_82652C34:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652c50
	if (!cr6.gt) goto loc_82652C50;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82652C44:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82652c54
	if (!cr6.eq) goto loc_82652C54;
loc_82652C50:
	// li r11,0
	r11.s64 = 0;
loc_82652C54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652C88;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82652ca4
	if (!cr6.eq) goto loc_82652CA4;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822090b8
	ctx.lr = 0x82652C98;
	sub_822090B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652CA4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10732
	ctx.r3.s64 = r11.s64 + -10732;
	// bl 0x821fa210
	ctx.lr = 0x82652CB0;
	sub_821FA210(ctx, base);
	// bl 0x826947e0
	ctx.lr = 0x82652CB4;
	sub_826947E0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
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
loc_82652CD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82652CE0"))) PPC_WEAK_FUNC(sub_82652CE0);
PPC_FUNC_IMPL(__imp__sub_82652CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cf4
	if (cr6.eq) goto loc_82652CF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82652CF4:
	// b 0x82652978
	sub_82652978(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82652CF8"))) PPC_WEAK_FUNC(sub_82652CF8);
PPC_FUNC_IMPL(__imp__sub_82652CF8) {
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
	ctx.lr = 0x82652D00;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lbz r10,900(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 900);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,108
	ctx.r4.s64 = 108;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82652D38;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,17268(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652db8
	if (cr6.eq) goto loc_82652DB8;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82652d8c
	if (cr6.eq) goto loc_82652D8C;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652da8
	if (!cr6.gt) goto loc_82652DA8;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x82652d9c
	goto loc_82652D9C;
loc_82652D8C:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652da8
	if (!cr6.gt) goto loc_82652DA8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82652D9C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82652dac
	if (!cr6.eq) goto loc_82652DAC;
loc_82652DA8:
	// li r11,0
	r11.s64 = 0;
loc_82652DAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652DB8:
	// lwz r3,-10028(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82652DC0;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x82256058
	ctx.lr = 0x82652DE0;
	sub_82256058(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82652e30
	if (cr6.eq) goto loc_82652E30;
	// bl 0x82256138
	ctx.lr = 0x82652DF4;
	sub_82256138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652e10
	if (cr6.eq) goto loc_82652E10;
	// bl 0x82387a18
	ctx.lr = 0x82652E04;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E10:
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f1,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82256090
	ctx.lr = 0x82652E24;
	sub_82256090(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E30:
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652E3C;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652e6c
	if (cr6.eq) goto loc_82652E6C;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652E50;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,672(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E6C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,22440
	ctx.r4.s64 = ctx.r10.s64 + 22440;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82652E80;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652e94
	if (cr6.eq) goto loc_82652E94;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
loc_82652E94:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10116
	ctx.r3.s64 = r11.s64 + -10116;
	// bl 0x821fa230
	ctx.lr = 0x82652EA0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652EB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10132
	ctx.r3.s64 = r11.s64 + -10132;
	// bl 0x821fa230
	ctx.lr = 0x82652EC8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// bl 0x822a39c0
	ctx.lr = 0x82652EF8;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82652F1C;
	sub_822A39C8(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_82652F2C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x82652F34;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// beq cr6,0x82652f50
	if (cr6.eq) goto loc_82652F50;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82701bd8
	ctx.lr = 0x82652F44;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82652f54
	if (!cr6.eq) goto loc_82652F54;
loc_82652F50:
	// li r11,1
	r11.s64 = 1;
loc_82652F54:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x823bb3f0
	ctx.lr = 0x82652F6C;
	sub_823BB3F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x823bbf80
	ctx.lr = 0x82652F7C;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652fb0
	if (cr6.eq) goto loc_82652FB0;
	// bl 0x823bc1c0
	ctx.lr = 0x82652F8C;
	sub_823BC1C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82653044
	if (!cr6.gt) goto loc_82653044;
	// bl 0x823bc1c0
	ctx.lr = 0x82652FA0;
	sub_823BC1C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82653044
	if (cr6.gt) goto loc_82653044;
loc_82652FB0:
	// lwz r3,-10028(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// bl 0x82204160
	ctx.lr = 0x82652FB8;
	sub_82204160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// ori r9,r10,4944
	ctx.r9.u64 = ctx.r10.u64 | 4944;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x82387a18
	ctx.lr = 0x82652FE0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653034
	if (cr6.eq) goto loc_82653034;
	// lwz r31,-3624(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82653034
	if (!cr6.eq) goto loc_82653034;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x8265300C;
	sub_82293F60(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x8265301C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82653020;
	sub_82293F60(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,-12736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12736);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82653044
	if (cr6.lt) goto loc_82653044;
loc_82653034:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82653044:
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

__attribute__((alias("__imp__sub_82653054"))) PPC_WEAK_FUNC(sub_82653054);
PPC_FUNC_IMPL(__imp__sub_82653054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653058"))) PPC_WEAK_FUNC(sub_82653058);
PPC_FUNC_IMPL(__imp__sub_82653058) {
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
	ctx.lr = 0x82653060;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bne cr6,0x82653218
	if (!cr6.eq) goto loc_82653218;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,76
	cr6.compare<int32_t>(r11.s32, 76, xer);
	// beq cr6,0x8265310c
	if (cr6.eq) goto loc_8265310C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-12896
	ctx.r4.s64 = r11.s64 + -12896;
	// bl 0x82691650
	ctx.lr = 0x826530B4;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826530C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r8,-2016
	ctx.r4.s64 = ctx.r8.s64 + -2016;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82691650
	ctx.lr = 0x826530D8;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,312(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 312);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826530E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r30,24
	ctx.r5.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82653100
	if (!cr6.eq) goto loc_82653100;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265310c
	if (cr6.eq) goto loc_8265310C;
loc_82653100:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8265310C:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8265313c
	if (cr6.eq) goto loc_8265313C;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82653158
	if (!cr6.gt) goto loc_82653158;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8265314c
	goto loc_8265314C;
loc_8265313C:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82653158
	if (!cr6.gt) goto loc_82653158;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8265314C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8265315c
	if (!cr6.eq) goto loc_8265315C;
loc_82653158:
	// li r11,0
	r11.s64 = 0;
loc_8265315C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826532f0
	if (cr6.eq) goto loc_826532F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82653174;
	sub_822040F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826532f0
	if (!cr6.eq) goto loc_826532F0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,54
	cr6.compare<int32_t>(r11.s32, 54, xer);
	// beq cr6,0x826532c0
	if (cr6.eq) goto loc_826532C0;
	// cmpwi cr6,r11,55
	cr6.compare<int32_t>(r11.s32, 55, xer);
	// beq cr6,0x8265319c
	if (cr6.eq) goto loc_8265319C;
	// cmpwi cr6,r11,76
	cr6.compare<int32_t>(r11.s32, 76, xer);
	// bne cr6,0x82653218
	if (!cr6.eq) goto loc_82653218;
loc_8265319C:
	// bl 0x82652cf8
	ctx.lr = 0x826531A0;
	sub_82652CF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lwz r3,24588(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24588);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x821e6800
	ctx.lr = 0x826531C0;
	sub_821E6800(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r4,r9,-12796
	ctx.r4.s64 = ctx.r9.s64 + -12796;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x826531D4;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,312(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826531E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265323c
	if (cr6.eq) goto loc_8265323C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-10648
	ctx.r4.s64 = r11.s64 + -10648;
loc_82653200:
	// bl 0x82691650
	ctx.lr = 0x82653204;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82653218:
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ea68
	ctx.lr = 0x82653234;
	sub_8268EA68(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8265323C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-3752
	ctx.r4.s64 = r11.s64 + -3752;
	// bl 0x82691650
	ctx.lr = 0x82653248;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653278
	if (cr6.eq) goto loc_82653278;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-10672
	ctx.r4.s64 = r11.s64 + -10672;
	// b 0x82653200
	goto loc_82653200;
loc_82653278:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10684
	ctx.r4.s64 = r11.s64 + -10684;
	// bl 0x82691650
	ctx.lr = 0x82653284;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826532b4
	if (cr6.eq) goto loc_826532B4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10708
	ctx.r4.s64 = r11.s64 + -10708;
	// b 0x82653200
	goto loc_82653200;
loc_826532B4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10720
	ctx.r4.s64 = r11.s64 + -10720;
	// b 0x82653200
	goto loc_82653200;
loc_826532C0:
	// bl 0x82652cf8
	ctx.lr = 0x826532C4;
	sub_82652CF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8264f2a8
	ctx.lr = 0x826532D8;
	sub_8264F2A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// bl 0x82650038
	ctx.lr = 0x826532E8;
	sub_82650038(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_826532F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826532FC"))) PPC_WEAK_FUNC(sub_826532FC);
PPC_FUNC_IMPL(__imp__sub_826532FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653300"))) PPC_WEAK_FUNC(sub_82653300);
PPC_FUNC_IMPL(__imp__sub_82653300) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265332C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82653370
	if (!cr6.eq) goto loc_82653370;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653370
	if (cr6.eq) goto loc_82653370;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10604
	ctx.r3.s64 = r11.s64 + -10604;
	// bl 0x821e6800
	ctx.lr = 0x82653350;
	sub_821E6800(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r9,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r9.u8);
	// stb r8,790(r31)
	PPC_STORE_U8(r31.u32 + 790, ctx.r8.u8);
	// lfs f0,-28872(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28872);
	f0.f64 = double(temp.f32);
	// stfs f0,796(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 796, temp.u32);
	// b 0x826533c0
	goto loc_826533C0;
loc_82653370:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826533c0
	if (cr6.eq) goto loc_826533C0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826533c0
	if (!cr6.eq) goto loc_826533C0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10624
	ctx.r3.s64 = r11.s64 + -10624;
	// bl 0x821e6800
	ctx.lr = 0x826533A8;
	sub_821E6800(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-11460
	ctx.r3.s64 = ctx.r10.s64 + -11460;
	// bl 0x82255cf8
	ctx.lr = 0x826533B8;
	sub_82255CF8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,790(r31)
	PPC_STORE_U8(r31.u32 + 790, ctx.r9.u8);
loc_826533C0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fd60
	ctx.lr = 0x826533CC;
	sub_8262FD60(ctx, base);
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

__attribute__((alias("__imp__sub_826533E4"))) PPC_WEAK_FUNC(sub_826533E4);
PPC_FUNC_IMPL(__imp__sub_826533E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826533E8"))) PPC_WEAK_FUNC(sub_826533E8);
PPC_FUNC_IMPL(__imp__sub_826533E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,960(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 960, temp.u32);
	// stfs f2,964(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 964, temp.u32);
	// stb r6,968(r3)
	PPC_STORE_U8(ctx.r3.u32 + 968, ctx.r6.u8);
	// stfs f3,972(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 972, temp.u32);
	// stb r7,969(r3)
	PPC_STORE_U8(ctx.r3.u32 + 969, ctx.r7.u8);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f0,976(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 976, temp.u32);
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bne cr6,0x82653418
	if (!cr6.eq) goto loc_82653418;
	// stfs f1,980(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 980, temp.u32);
loc_82653418:
	// lfs f0,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7220);
	f0.f64 = double(temp.f32);
	// stfs f0,984(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 984, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653424"))) PPC_WEAK_FUNC(sub_82653424);
PPC_FUNC_IMPL(__imp__sub_82653424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653428"))) PPC_WEAK_FUNC(sub_82653428);
PPC_FUNC_IMPL(__imp__sub_82653428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r3,944
	ctx.r5.s64 = ctx.r3.s64 + 944;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12548(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12548);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,-12560(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x821f51a0
	sub_821F51A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82653450"))) PPC_WEAK_FUNC(sub_82653450);
PPC_FUNC_IMPL(__imp__sub_82653450) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82653458;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,-12264
	r30.s64 = r11.s64 + -12264;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lbz r28,68(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 68);
	// bl 0x821c9790
	ctx.lr = 0x8265348C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8265349C;
	sub_825ED480(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826535e4
	if (cr6.eq) goto loc_826535E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,21416
	ctx.r4.s64 = r11.s64 + 21416;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee120
	ctx.lr = 0x826534C0;
	sub_825EE120(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x826534d0
	if (!cr6.lt) goto loc_826534D0;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
loc_826534D0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535e4
	if (cr6.eq) goto loc_826535E4;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826535e4
	if (!cr6.eq) goto loc_826535E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x826534F0;
	sub_825EF9F0(ctx, base);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// beq cr6,0x826535c4
	if (cr6.eq) goto loc_826535C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82653518;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82653538;
	sub_825EF9F0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,6
	r31.s64 = 6;
	// lfs f31,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f31.f64 = double(temp.f32);
loc_82653548:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef8c8
	ctx.lr = 0x82653564;
	sub_825EF8C8(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef8c8
	ctx.lr = 0x82653584;
	sub_825EF8C8(ctx, base);
	// fsubs f0,f30,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - ctx.f1.f64));
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x826535a4
	if (cr6.gt) goto loc_826535A4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// ble cr6,0x82653548
	if (!cr6.gt) goto loc_82653548;
	// b 0x826535a8
	goto loc_826535A8;
loc_826535A4:
	// li r28,1
	r28.s64 = 1;
loc_826535A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12448);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535c4
	if (cr6.eq) goto loc_826535C4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10248
	ctx.r3.s64 = r11.s64 + -10248;
	// bl 0x821e6800
	ctx.lr = 0x826535C4;
	sub_821E6800(ctx, base);
loc_826535C4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826535e4
	if (!cr6.eq) goto loc_826535E4;
	// bl 0x82387a18
	ctx.lr = 0x826535D4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,2
	ctx.r3.s64 = 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535e8
	if (cr6.eq) goto loc_826535E8;
loc_826535E4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_826535E8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826535F8"))) PPC_WEAK_FUNC(sub_826535F8);
PPC_FUNC_IMPL(__imp__sub_826535F8) {
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
	ctx.lr = 0x82653600;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8265360C;
	sub_82632F78(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,-12592
	r30.s64 = r11.s64 + -12592;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r29,208(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265362C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653638;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r8,21416
	r30.s64 = ctx.r8.s64 + 21416;
	// lwz r6,468(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// lwz r29,956(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82653658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653664;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265366C"))) PPC_WEAK_FUNC(sub_8265366C);
PPC_FUNC_IMPL(__imp__sub_8265366C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653670"))) PPC_WEAK_FUNC(sub_82653670);
PPC_FUNC_IMPL(__imp__sub_82653670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,948(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 948);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821ec060
	sub_821EC060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82653684"))) PPC_WEAK_FUNC(sub_82653684);
PPC_FUNC_IMPL(__imp__sub_82653684) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653688"))) PPC_WEAK_FUNC(sub_82653688);
PPC_FUNC_IMPL(__imp__sub_82653688) {
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
	ctx.lr = 0x82653690;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826536B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826536e8
	if (cr6.eq) goto loc_826536E8;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// beq cr6,0x826536dc
	if (cr6.eq) goto loc_826536DC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630aa8
	ctx.lr = 0x826536D4;
	sub_82630AA8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826536DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826536E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826536F4"))) PPC_WEAK_FUNC(sub_826536F4);
PPC_FUNC_IMPL(__imp__sub_826536F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826536F8"))) PPC_WEAK_FUNC(sub_826536F8);
PPC_FUNC_IMPL(__imp__sub_826536F8) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r30,864(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// bl 0x82631f88
	ctx.lr = 0x8265371C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265372c
	if (cr6.lt) goto loc_8265372C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265372C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653748;
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

__attribute__((alias("__imp__sub_82653760"))) PPC_WEAK_FUNC(sub_82653760);
PPC_FUNC_IMPL(__imp__sub_82653760) {
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
	// bl 0x82630748
	ctx.lr = 0x82653780;
	sub_82630748(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,8044
	ctx.r5.s64 = r11.s64 + 8044;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,860
	ctx.r6.s64 = r31.s64 + 860;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826537A0;
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

__attribute__((alias("__imp__sub_826537B8"))) PPC_WEAK_FUNC(sub_826537B8);
PPC_FUNC_IMPL(__imp__sub_826537B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,672(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// addi r3,r3,672
	ctx.r3.s64 = ctx.r3.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826537D0"))) PPC_WEAK_FUNC(sub_826537D0);
PPC_FUNC_IMPL(__imp__sub_826537D0) {
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
	ctx.lr = 0x826537D8;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826537F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265389c
	if (cr6.eq) goto loc_8265389C;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x82653864
	if (cr6.eq) goto loc_82653864;
	// cmpwi cr6,r30,56
	cr6.compare<int32_t>(r30.s32, 56, xer);
	// beq cr6,0x8265382c
	if (cr6.eq) goto loc_8265382C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x82653824;
	sub_826309E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265382C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,772(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653858
	if (cr6.eq) goto loc_82653858;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x82653858;
	sub_821E6800(ctx, base);
loc_82653858:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653864:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,768(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653890
	if (cr6.eq) goto loc_82653890;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82653890;
	sub_821E6800(ctx, base);
loc_82653890:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265389C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826538A8"))) PPC_WEAK_FUNC(sub_826538A8);
PPC_FUNC_IMPL(__imp__sub_826538A8) {
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
	// bl 0x82630748
	ctx.lr = 0x826538C8;
	sub_82630748(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,8044
	ctx.r5.s64 = r11.s64 + 8044;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,860
	ctx.r6.s64 = r31.s64 + 860;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x826538E8;
	sub_824DF200(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-10260
	ctx.r5.s64 = ctx.r10.s64 + -10260;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,952
	ctx.r6.s64 = r31.s64 + 952;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82653908;
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

__attribute__((alias("__imp__sub_82653920"))) PPC_WEAK_FUNC(sub_82653920);
PPC_FUNC_IMPL(__imp__sub_82653920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// bne cr6,0x82653968
	if (!cr6.eq) goto loc_82653968;
	// lfs f0,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82653a68
	if (!cr6.lt) goto loc_82653A68;
loc_82653968:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,980(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 980);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,960(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 960);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f10,f9
	cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// lfs f11,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// bne cr6,0x82653988
	if (!cr6.eq) goto loc_82653988;
	// stfs f31,976(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// b 0x826539b4
	goto loc_826539B4;
loc_82653988:
	// lfs f12,964(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 964);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// beq cr6,0x826539b4
	if (cr6.eq) goto loc_826539B4;
	// lfs f0,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x826539b4
	if (!cr6.lt) goto loc_826539B4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f13,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
loc_826539B4:
	// lfs f0,964(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 964);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// beq cr6,0x82653a60
	if (cr6.eq) goto loc_82653A60;
	// lfs f1,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82653a50
	if (!cr6.lt) goto loc_82653A50;
	// lbz r11,968(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a0c
	if (cr6.eq) goto loc_82653A0C;
	// lbz r10,969(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 969);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826539fc
	if (cr6.eq) goto loc_826539FC;
	// bl 0x82227ce8
	ctx.lr = 0x826539E8;
	sub_82227CE8(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x82653a1c
	goto loc_82653A1C;
loc_826539FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a0c
	if (cr6.eq) goto loc_82653A0C;
	// bl 0x82227c70
	ctx.lr = 0x82653A08;
	sub_82227C70(ctx, base);
	// b 0x82653a1c
	goto loc_82653A1C;
loc_82653A0C:
	// lbz r11,969(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 969);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a1c
	if (cr6.eq) goto loc_82653A1C;
	// bl 0x82227c18
	ctx.lr = 0x82653A1C;
	sub_82227C18(ctx, base);
loc_82653A1C:
	// lfs f2,972(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 972);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// beq cr6,0x82653a30
	if (cr6.eq) goto loc_82653A30;
	// bl 0x823dc480
	ctx.lr = 0x82653A2C;
	sub_823DC480(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
loc_82653A30:
	// lfs f0,984(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 984);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,960(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 960);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f0,f12,f1,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f0,7220(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
	// b 0x82653a68
	goto loc_82653A68;
loc_82653A50:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f9,980(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f9,7220(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
	// b 0x82653a68
	goto loc_82653A68;
loc_82653A60:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f10,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
loc_82653A68:
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

__attribute__((alias("__imp__sub_82653A80"))) PPC_WEAK_FUNC(sub_82653A80);
PPC_FUNC_IMPL(__imp__sub_82653A80) {
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
	ctx.lr = 0x82653A88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x82653aa4
	if (!cr6.eq) goto loc_82653AA4;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82653b20
	if (cr6.eq) goto loc_82653B20;
loc_82653AA4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,-10224
	r29.s64 = ctx.r10.s64 + -10224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee270
	ctx.lr = 0x82653AD0;
	sub_825EE270(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82653AE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82653b20
	if (cr6.eq) goto loc_82653B20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,956(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lbz r30,80(r1)
	r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82653450
	ctx.lr = 0x82653B18;
	sub_82653450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82653B20:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82653B2C"))) PPC_WEAK_FUNC(sub_82653B2C);
PPC_FUNC_IMPL(__imp__sub_82653B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653B30"))) PPC_WEAK_FUNC(sub_82653B30);
PPC_FUNC_IMPL(__imp__sub_82653B30) {
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
	// bl 0x8228fbf8
	ctx.lr = 0x82653B48;
	sub_8228FBF8(ctx, base);
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82653ba8
	if (cr6.eq) goto loc_82653BA8;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82653ba4
	if (!cr6.eq) goto loc_82653BA4;
	// bl 0x821f4b28
	ctx.lr = 0x82653B64;
	sub_821F4B28(ctx, base);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// addi r5,r31,948
	ctx.r5.s64 = r31.s64 + 948;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653ba8
	if (!cr6.eq) goto loc_82653BA8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-10212
	ctx.r4.s64 = ctx.r9.s64 + -10212;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x82653B90;
	sub_821EE720(ctx, base);
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
loc_82653BA4:
	// bl 0x821f4c98
	ctx.lr = 0x82653BA8;
	sub_821F4C98(ctx, base);
loc_82653BA8:
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

__attribute__((alias("__imp__sub_82653BBC"))) PPC_WEAK_FUNC(sub_82653BBC);
PPC_FUNC_IMPL(__imp__sub_82653BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653BC0"))) PPC_WEAK_FUNC(sub_82653BC0);
PPC_FUNC_IMPL(__imp__sub_82653BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82653bdc
	if (cr6.eq) goto loc_82653BDC;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// ble cr6,0x82653bd8
	if (!cr6.gt) goto loc_82653BD8;
	// cmpwi cr6,r4,58
	cr6.compare<int32_t>(ctx.r4.s32, 58, xer);
	// ble cr6,0x82653bdc
	if (!cr6.gt) goto loc_82653BDC;
loc_82653BD8:
	// b 0x826537d0
	sub_826537D0(ctx, base);
	return;
loc_82653BDC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653BE4"))) PPC_WEAK_FUNC(sub_82653BE4);
PPC_FUNC_IMPL(__imp__sub_82653BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653BE8"))) PPC_WEAK_FUNC(sub_82653BE8);
PPC_FUNC_IMPL(__imp__sub_82653BE8) {
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
	ctx.lr = 0x82653BF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82633e80
	ctx.lr = 0x82653C08;
	sub_82633E80(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r10,r11,-10180
	ctx.r10.s64 = r11.s64 + -10180;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826337a8
	ctx.lr = 0x82653C20;
	sub_826337A8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r9,-14100
	ctx.r8.s64 = ctx.r9.s64 + -14100;
	// stw r29,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r29.u32);
	// addi r3,r30,184
	ctx.r3.s64 = r30.s64 + 184;
	// stw r8,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r8.u32);
	// stw r29,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r29.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82653C40;
	sub_821C2F70(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r29,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r29.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stb r7,460(r31)
	PPC_STORE_U8(r31.u32 + 460, ctx.r7.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r29,480(r31)
	PPC_STORE_U8(r31.u32 + 480, r29.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82653C60;
	sub_8262FFE0(ctx, base);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82653C88"))) PPC_WEAK_FUNC(sub_82653C88);
PPC_FUNC_IMPL(__imp__sub_82653C88) {
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
	ctx.lr = 0x82653C90;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653d38
	if (cr6.eq) goto loc_82653D38;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x82653d20
	if (!cr6.eq) goto loc_82653D20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,780(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 780);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653CD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653d20
	if (cr6.eq) goto loc_82653D20;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82653D00;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653D20:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630aa8
	ctx.lr = 0x82653D30;
	sub_82630AA8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653D38:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82653D44"))) PPC_WEAK_FUNC(sub_82653D44);
PPC_FUNC_IMPL(__imp__sub_82653D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653D48"))) PPC_WEAK_FUNC(sub_82653D48);
PPC_FUNC_IMPL(__imp__sub_82653D48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,6132
	ctx.r9.s64 = ctx.r9.s64 + 6132;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653d98
	if (cr6.eq) goto loc_82653D98;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653d84
	if (cr6.eq) goto loc_82653D84;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
loc_82653D84:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r8,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r8.u8);
	// blr 
	return;
loc_82653D98:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653DAC"))) PPC_WEAK_FUNC(sub_82653DAC);
PPC_FUNC_IMPL(__imp__sub_82653DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653DB0"))) PPC_WEAK_FUNC(sub_82653DB0);
PPC_FUNC_IMPL(__imp__sub_82653DB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,6132
	ctx.r9.s64 = ctx.r9.s64 + 6132;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e00
	if (cr6.eq) goto loc_82653E00;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653dec
	if (cr6.eq) goto loc_82653DEC;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
loc_82653DEC:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stb r8,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r8.u8);
	// blr 
	return;
loc_82653E00:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653E14"))) PPC_WEAK_FUNC(sub_82653E14);
PPC_FUNC_IMPL(__imp__sub_82653E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653E18"))) PPC_WEAK_FUNC(sub_82653E18);
PPC_FUNC_IMPL(__imp__sub_82653E18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// addi r10,r10,6132
	ctx.r10.s64 = ctx.r10.s64 + 6132;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82653e4c
	if (!cr6.eq) goto loc_82653E4C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_82653E4C:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82653e60
	if (!cr6.eq) goto loc_82653E60;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_82653E60:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e74
	if (cr6.eq) goto loc_82653E74;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_82653E74:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e88
	if (cr6.eq) goto loc_82653E88;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_82653E88:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82653E9C"))) PPC_WEAK_FUNC(sub_82653E9C);
PPC_FUNC_IMPL(__imp__sub_82653E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82653EA0"))) PPC_WEAK_FUNC(sub_82653EA0);
PPC_FUNC_IMPL(__imp__sub_82653EA0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,27904
	ctx.r5.s64 = r11.s64 + 27904;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653be8
	ctx.lr = 0x82653ECC;
	sub_82653BE8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r9,-8716
	ctx.r7.s64 = ctx.r9.s64 + -8716;
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
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

__attribute__((alias("__imp__sub_82653EF8"))) PPC_WEAK_FUNC(sub_82653EF8);
PPC_FUNC_IMPL(__imp__sub_82653EF8) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82653F28"))) PPC_WEAK_FUNC(sub_82653F28);
PPC_FUNC_IMPL(__imp__sub_82653F28) {
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
	ctx.lr = 0x82653F30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826540a8
	if (cr6.eq) goto loc_826540A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r5,956(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r11,21416
	ctx.r4.s64 = r11.s64 + 21416;
	// bl 0x825ee0e0
	ctx.lr = 0x82653F68;
	sub_825EE0E0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,992(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82653F80;
	sub_82691650(ctx, base);
	// lwz r30,56(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,304(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 304);
	// bl 0x82720e28
	ctx.lr = 0x82653F94;
	sub_82720E28(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r9,2612
	r28.s64 = ctx.r9.s64 + 2612;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r27,56(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82653FAC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x82653FBC;
	sub_825ED480(ctx, base);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13268
	ctx.r4.s64 = ctx.r7.s64 + -13268;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x82653FD8;
	sub_82722678(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-11044
	ctx.r4.s64 = ctx.r6.s64 + -11044;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653FEC;
	sub_825EE0E0(ctx, base);
	// lis r5,-32138
	ctx.r5.s64 = -2106195968;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r9,r5,9352
	ctx.r9.s64 = ctx.r5.s64 + 9352;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82220308
	ctx.lr = 0x82654014;
	sub_82220308(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,-10224
	ctx.r4.s64 = ctx.r8.s64 + -10224;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82654028;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,332(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 332);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265403C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-13276
	ctx.r4.s64 = ctx.r4.s64 + -13276;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827227b8
	ctx.lr = 0x82654050;
	sub_827227B8(ctx, base);
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r8,176(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 176);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82654078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82635840
	ctx.lr = 0x82654084;
	sub_82635840(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r7,620
	ctx.r4.s64 = ctx.r7.s64 + 620;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826540A0;
	sub_82722678(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826540A8:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 304);
	// bl 0x82720560
	ctx.lr = 0x826540B4;
	sub_82720560(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826540BC"))) PPC_WEAK_FUNC(sub_826540BC);
PPC_FUNC_IMPL(__imp__sub_826540BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826540C0"))) PPC_WEAK_FUNC(sub_826540C0);
PPC_FUNC_IMPL(__imp__sub_826540C0) {
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
	ctx.lr = 0x826540C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82653be8
	ctx.lr = 0x826540E8;
	sub_82653BE8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,496
	r30.s64 = r31.s64 + 496;
	// addi r10,r11,-7924
	ctx.r10.s64 = r11.s64 + -7924;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633a10
	ctx.lr = 0x82654108;
	sub_82633A10(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// addi r8,r9,4916
	ctx.r8.s64 = ctx.r9.s64 + 4916;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r8,496(r31)
	PPC_STORE_U32(r31.u32 + 496, ctx.r8.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82634738
	ctx.lr = 0x82654128;
	sub_82634738(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// addi r6,r7,-9388
	ctx.r6.s64 = ctx.r7.s64 + -9388;
	// stw r6,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r6.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82654174"))) PPC_WEAK_FUNC(sub_82654174);
PPC_FUNC_IMPL(__imp__sub_82654174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654178"))) PPC_WEAK_FUNC(sub_82654178);
PPC_FUNC_IMPL(__imp__sub_82654178) {
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
	// lhz r11,214(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 214);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541a8
	if (cr6.eq) goto loc_826541A8;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x826541A8;
	sub_82130588(ctx, base);
loc_826541A8:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541bc
	if (cr6.eq) goto loc_826541BC;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826541BC;
	sub_82130588(ctx, base);
loc_826541BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826541C4;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541dc
	if (cr6.eq) goto loc_826541DC;
	// bl 0x82130588
	ctx.lr = 0x826541D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826541DC:
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

__attribute__((alias("__imp__sub_826541F4"))) PPC_WEAK_FUNC(sub_826541F4);
PPC_FUNC_IMPL(__imp__sub_826541F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826541F8"))) PPC_WEAK_FUNC(sub_826541F8);
PPC_FUNC_IMPL(__imp__sub_826541F8) {
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
	ctx.lr = 0x82654200;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x82653be8
	ctx.lr = 0x82654220;
	sub_82653BE8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r31,496
	r29.s64 = r31.s64 + 496;
	// addi r10,r11,7236
	ctx.r10.s64 = r11.s64 + 7236;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633a10
	ctx.lr = 0x82654240;
	sub_82633A10(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// addi r8,r9,4916
	ctx.r8.s64 = ctx.r9.s64 + 4916;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r8,496(r31)
	PPC_STORE_U32(r31.u32 + 496, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82634738
	ctx.lr = 0x82654260;
	sub_82634738(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,6524
	ctx.r6.s64 = ctx.r7.s64 + 6524;
	// stw r11,928(r31)
	PPC_STORE_U32(r31.u32 + 928, r11.u32);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// stw r6,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r6.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r11.u32);
	// addi r4,r5,-26040
	ctx.r4.s64 = ctx.r5.s64 + -26040;
	// stw r28,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r28.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821c2f90
	ctx.lr = 0x82654290;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826542A0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826542a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826542A0;
	// addi r10,r31,908
	ctx.r10.s64 = r31.s64 + 908;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826542C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826542c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826542C4;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82654318"))) PPC_WEAK_FUNC(sub_82654318);
PPC_FUNC_IMPL(__imp__sub_82654318) {
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
	// bl 0x8228f920
	ctx.lr = 0x82654330;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// addi r6,r7,-7124
	ctx.r6.s64 = ctx.r7.s64 + -7124;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,960(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f13,964(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,972(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stw r10,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r10.u32);
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stw r10,948(r31)
	PPC_STORE_U32(r31.u32 + 948, ctx.r10.u32);
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stw r5,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r5.u32);
	// stw r4,956(r31)
	PPC_STORE_U32(r31.u32 + 956, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r11.u8);
	// stb r11,969(r31)
	PPC_STORE_U8(r31.u32 + 969, r11.u8);
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

__attribute__((alias("__imp__sub_826543A0"))) PPC_WEAK_FUNC(sub_826543A0);
PPC_FUNC_IMPL(__imp__sub_826543A0) {
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
	// bl 0x826541f8
	ctx.lr = 0x826543B8;
	sub_826541F8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// addi r6,r7,-7124
	ctx.r6.s64 = ctx.r7.s64 + -7124;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,960(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f13,964(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,972(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stw r10,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r10.u32);
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stw r10,948(r31)
	PPC_STORE_U32(r31.u32 + 948, ctx.r10.u32);
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stw r5,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r5.u32);
	// stw r4,956(r31)
	PPC_STORE_U32(r31.u32 + 956, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r11.u8);
	// stb r11,969(r31)
	PPC_STORE_U8(r31.u32 + 969, r11.u8);
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

__attribute__((alias("__imp__sub_82654428"))) PPC_WEAK_FUNC(sub_82654428);
PPC_FUNC_IMPL(__imp__sub_82654428) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82654318
	ctx.lr = 0x82654460;
	sub_82654318(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-6316
	ctx.r9.s64 = ctx.r10.s64 + -6316;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8265448C"))) PPC_WEAK_FUNC(sub_8265448C);
PPC_FUNC_IMPL(__imp__sub_8265448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654490"))) PPC_WEAK_FUNC(sub_82654490);
PPC_FUNC_IMPL(__imp__sub_82654490) {
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
	// bl 0x8221fcc8
	ctx.lr = 0x826544B0;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826544c8
	if (cr6.eq) goto loc_826544C8;
	// bl 0x82130588
	ctx.lr = 0x826544C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826544C8:
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

__attribute__((alias("__imp__sub_826544E0"))) PPC_WEAK_FUNC(sub_826544E0);
PPC_FUNC_IMPL(__imp__sub_826544E0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82654318
	ctx.lr = 0x82654518;
	sub_82654318(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-6316
	ctx.r9.s64 = ctx.r10.s64 + -6316;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82654544"))) PPC_WEAK_FUNC(sub_82654544);
PPC_FUNC_IMPL(__imp__sub_82654544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654548"))) PPC_WEAK_FUNC(sub_82654548);
PPC_FUNC_IMPL(__imp__sub_82654548) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-2800(r1)
	ea = -2800 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r4,14
	ctx.r4.s64 = 14;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9248
	ctx.lr = 0x8265457C;
	sub_821F9248(ctx, base);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r11,r5,2352
	r11.s64 = ctx.r5.s64 + 2352;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v126,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v58,r3,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r10,r4,2256
	ctx.r10.s64 = ctx.r4.s64 + 2256;
	// vmrglw128 v55,v62,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vmrglw128 v54,v58,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v53,v63,v59
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// li r11,0
	r11.s64 = 0;
	// vmrghw128 v50,v55,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vmsum4fp128 v49,v53,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// vmsum4fp128 v48,v53,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// vmsum4fp128 v47,v53,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r10,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r10.u16);
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, r11.u16);
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// vmrghw128 v46,v49,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v48,v47
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v45,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// stvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8220edb0
	ctx.lr = 0x82654658;
	sub_8220EDB0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lfs f1,12424(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8257df18
	ctx.lr = 0x82654674;
	sub_8257DF18(ctx, base);
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r6,r7,-20564
	ctx.r6.s64 = ctx.r7.s64 + -20564;
	// addi r5,r5,-20524
	ctx.r5.s64 = ctx.r5.s64 + -20524;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-23464(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -23464);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82654698;
	sub_823DEDD8(ctx, base);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,512
	ctx.r3.s64 = 512;
	// slw r11,r3,r4
	r11.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r4.u8 & 0x3F));
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,6174
	ctx.r5.s64 = 6174;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8220dbd8
	ctx.lr = 0x826546CC;
	sub_8220DBD8(ctx, base);
	// lbz r10,666(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 666);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826546f8
	if (!cr6.gt) goto loc_826546F8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826546e8
	if (cr6.eq) goto loc_826546E8;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x826546E8;
	sub_82130588(ctx, base);
loc_826546E8:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x826546F0;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82654714
	goto loc_82654714;
loc_826546F8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654708
	if (cr6.eq) goto loc_82654708;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654708;
	sub_82130588(ctx, base);
loc_82654708:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x82654710;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82654714:
	// addi r1,r1,2800
	ctx.r1.s64 = ctx.r1.s64 + 2800;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82654734"))) PPC_WEAK_FUNC(sub_82654734);
PPC_FUNC_IMPL(__imp__sub_82654734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654738"))) PPC_WEAK_FUNC(sub_82654738);
PPC_FUNC_IMPL(__imp__sub_82654738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd524
	ctx.lr = 0x8265474C;
	// stwu r1,-2864(r1)
	ea = -2864 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r4,14
	ctx.r4.s64 = 14;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9248
	ctx.lr = 0x82654768;
	sub_821F9248(ctx, base);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r5,2352
	ctx.r10.s64 = ctx.r5.s64 + 2352;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v127,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v58,r3,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v126,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v56,v62,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// li r4,0
	ctx.r4.s64 = 0;
	// vmrglw128 v55,v58,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v127,v62,v61
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vor128 v126,v63,v59
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmrghw128 v124,v58,v60
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vor128 v125,v63,v57
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vmrghw128 v54,v56,v55
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v123,v126,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v123.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// vmsum4fp128 v122,v125,v54
	simde_mm_store_ps(v122.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// bl 0x822a3998
	ctx.lr = 0x826547D8;
	sub_822A3998(ctx, base);
	// vmrglw128 v53,v127,v124
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vmrghw128 v52,v127,v124
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// vmrglw128 v51,v127,v124
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// vmrghw128 v50,v127,v124
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// vmsum4fp128 v49,v126,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// vmsum4fp128 v48,v126,v52
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vmsum4fp128 v47,v125,v51
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// li r11,0
	r11.s64 = 0;
	// vmsum4fp128 v46,v125,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// lwz r31,28(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r7,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r7.u16);
	// sth r11,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, r11.u16);
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// vmrghw128 v45,v49,v126
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v44,v48,v123
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v47,v125
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v42,v46,v122
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v122.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v41,v44,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v40,v42,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v41,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8220edb0
	ctx.lr = 0x82654884;
	sub_8220EDB0(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,-29232(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8257df18
	ctx.lr = 0x826548A0;
	sub_8257DF18(ctx, base);
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r6,r3,-20564
	ctx.r6.s64 = ctx.r3.s64 + -20564;
	// addi r5,r11,-20524
	ctx.r5.s64 = r11.s64 + -20524;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-23464(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -23464);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826548C4;
	sub_823DEDD8(ctx, base);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r8,512
	ctx.r8.s64 = 512;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// stw r7,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r7.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,6166
	ctx.r5.s64 = 6166;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8220dbd8
	ctx.lr = 0x826548F8;
	sub_8220DBD8(ctx, base);
	// lbz r10,666(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 666);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82654924
	if (!cr6.gt) goto loc_82654924;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654914
	if (cr6.eq) goto loc_82654914;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654914;
	sub_82130588(ctx, base);
loc_82654914:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x8265491C;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82654940
	goto loc_82654940;
loc_82654924:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654934
	if (cr6.eq) goto loc_82654934;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654934;
	sub_82130588(ctx, base);
loc_82654934:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x8265493C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82654940:
	// addi r1,r1,2864
	ctx.r1.s64 = ctx.r1.s64 + 2864;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd7bc
	ctx.lr = 0x8265494C;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265495C"))) PPC_WEAK_FUNC(sub_8265495C);
PPC_FUNC_IMPL(__imp__sub_8265495C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654960"))) PPC_WEAK_FUNC(sub_82654960);
PPC_FUNC_IMPL(__imp__sub_82654960) {
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
	ctx.lr = 0x82654968;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82654980;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a5680
	ctx.lr = 0x82654988;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x826549bc
	if (cr6.eq) goto loc_826549BC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x826549B0;
	sub_82562740(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82654a9c
	if (!cr6.eq) goto loc_82654A9C;
loc_826549BC:
	// bl 0x82387a18
	ctx.lr = 0x826549C0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654a9c
	if (!cr6.eq) goto loc_82654A9C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r10,r11,4897
	ctx.r10.s64 = r11.s64 + 4897;
	// addi r9,r11,4947
	ctx.r9.s64 = r11.s64 + 4947;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v2,r8,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82654738
	ctx.lr = 0x826549F4;
	sub_82654738(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82654a0c
	if (!cr6.eq) goto loc_82654A0C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654aa4
	if (!cr6.eq) goto loc_82654AA4;
loc_82654A0C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822082b0
	ctx.lr = 0x82654A14;
	sub_822082B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82654aa4
	if (!cr6.eq) goto loc_82654AA4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-10028(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r11,r11,10
	r11.s64 = r11.s64 + 10;
	// addi r9,r11,4897
	ctx.r9.s64 = r11.s64 + 4897;
	// addi r8,r11,4947
	ctx.r8.s64 = r11.s64 + 4947;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v2,r7,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r6,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82654738
	ctx.lr = 0x82654A50;
	sub_82654738(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82654a68
	if (!cr6.eq) goto loc_82654A68;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654a88
	if (!cr6.eq) goto loc_82654A88;
loc_82654A68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,10
	ctx.r3.s64 = r11.s64 + 10;
	// bl 0x822082b0
	ctx.lr = 0x82654A74;
	sub_822082B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82654a9c
	if (cr6.eq) goto loc_82654A9C;
loc_82654A88:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,10
	r11.s64 = r11.s64 + 10;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82654A9C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82654AA4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82654AAC"))) PPC_WEAK_FUNC(sub_82654AAC);
PPC_FUNC_IMPL(__imp__sub_82654AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654AB0"))) PPC_WEAK_FUNC(sub_82654AB0);
PPC_FUNC_IMPL(__imp__sub_82654AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r11,956
	ctx.r3.s64 = r11.s64 + 956;
	// lwz r10,952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 952);
	// stw r10,956(r11)
	PPC_STORE_U32(r11.u32 + 956, ctx.r10.u32);
	// b 0x82654960
	sub_82654960(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82654AC4"))) PPC_WEAK_FUNC(sub_82654AC4);
PPC_FUNC_IMPL(__imp__sub_82654AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654AC8"))) PPC_WEAK_FUNC(sub_82654AC8);
PPC_FUNC_IMPL(__imp__sub_82654AC8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654AEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82654b40
	if (cr6.eq) goto loc_82654B40;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r11,6512
	r31.s64 = r11.s64 + 6512;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82654B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82654B10:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x82654b34
	if (cr6.eq) goto loc_82654B34;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82654b10
	if (cr6.eq) goto loc_82654B10;
loc_82654B34:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654b44
	if (cr6.eq) goto loc_82654B44;
loc_82654B40:
	// li r11,0
	r11.s64 = 0;
loc_82654B44:
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

__attribute__((alias("__imp__sub_82654B5C"))) PPC_WEAK_FUNC(sub_82654B5C);
PPC_FUNC_IMPL(__imp__sub_82654B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654B60"))) PPC_WEAK_FUNC(sub_82654B60);
PPC_FUNC_IMPL(__imp__sub_82654B60) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82654bd8
	if (cr6.eq) goto loc_82654BD8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r11,8860
	r31.s64 = r11.s64 + 8860;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82654BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82654BA8:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x82654bcc
	if (cr6.eq) goto loc_82654BCC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82654ba8
	if (cr6.eq) goto loc_82654BA8;
loc_82654BCC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654bdc
	if (cr6.eq) goto loc_82654BDC;
loc_82654BD8:
	// li r11,0
	r11.s64 = 0;
loc_82654BDC:
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

__attribute__((alias("__imp__sub_82654BF4"))) PPC_WEAK_FUNC(sub_82654BF4);
PPC_FUNC_IMPL(__imp__sub_82654BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654BF8"))) PPC_WEAK_FUNC(sub_82654BF8);
PPC_FUNC_IMPL(__imp__sub_82654BF8) {
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
	// bl 0x82654ac8
	ctx.lr = 0x82654C10;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654c40
	if (!cr6.eq) goto loc_82654C40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654b60
	ctx.lr = 0x82654C24;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654c40
	if (!cr6.eq) goto loc_82654C40;
	// lbz r11,960(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654c44
	if (cr6.eq) goto loc_82654C44;
loc_82654C40:
	// li r11,0
	r11.s64 = 0;
loc_82654C44:
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

__attribute__((alias("__imp__sub_82654C5C"))) PPC_WEAK_FUNC(sub_82654C5C);
PPC_FUNC_IMPL(__imp__sub_82654C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654C60"))) PPC_WEAK_FUNC(sub_82654C60);
PPC_FUNC_IMPL(__imp__sub_82654C60) {
	PPC_FUNC_PROLOGUE();
	// li r3,36
	ctx.r3.s64 = 36;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82654C68"))) PPC_WEAK_FUNC(sub_82654C68);
PPC_FUNC_IMPL(__imp__sub_82654C68) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,28572
	ctx.r4.s64 = ctx.r10.s64 + 28572;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82654C98;
	sub_8262FFE0(ctx, base);
	// addi r9,r31,1376
	ctx.r9.s64 = r31.s64 + 1376;
	// stw r9,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82654CB4"))) PPC_WEAK_FUNC(sub_82654CB4);
PPC_FUNC_IMPL(__imp__sub_82654CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654CB8"))) PPC_WEAK_FUNC(sub_82654CB8);
PPC_FUNC_IMPL(__imp__sub_82654CB8) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r11,r31,952
	r11.s64 = r31.s64 + 952;
	// addi r3,r10,-5016
	ctx.r3.s64 = ctx.r10.s64 + -5016;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// bl 0x821fa230
	ctx.lr = 0x82654CE0;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82654CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82654d10
	if (cr6.eq) goto loc_82654D10;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28860
	ctx.r4.s64 = r11.s64 + 28860;
	// b 0x82654d1c
	goto loc_82654D1C;
loc_82654D10:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,28500
	ctx.r4.s64 = r11.s64 + 28500;
loc_82654D1C:
	// bl 0x8262ffe0
	ctx.lr = 0x82654D20;
	sub_8262FFE0(ctx, base);
	// addi r10,r31,1376
	ctx.r10.s64 = r31.s64 + 1376;
	// stw r10,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82654D3C"))) PPC_WEAK_FUNC(sub_82654D3C);
PPC_FUNC_IMPL(__imp__sub_82654D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654D40"))) PPC_WEAK_FUNC(sub_82654D40);
PPC_FUNC_IMPL(__imp__sub_82654D40) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r31,976
	r11.s64 = r31.s64 + 976;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r10,28500
	ctx.r4.s64 = ctx.r10.s64 + 28500;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82654D70;
	sub_8262FFE0(ctx, base);
	// addi r9,r31,1360
	ctx.r9.s64 = r31.s64 + 1360;
	// stw r9,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82654D8C"))) PPC_WEAK_FUNC(sub_82654D8C);
PPC_FUNC_IMPL(__imp__sub_82654D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654D90"))) PPC_WEAK_FUNC(sub_82654D90);
PPC_FUNC_IMPL(__imp__sub_82654D90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,864(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 864);
	// addi r10,r3,976
	ctx.r10.s64 = ctx.r3.s64 + 976;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82654DA8"))) PPC_WEAK_FUNC(sub_82654DA8);
PPC_FUNC_IMPL(__imp__sub_82654DA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654DD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82654dec
	if (cr6.eq) goto loc_82654DEC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82130000
	ctx.lr = 0x82654DEC;
	sub_82130000(ctx, base);
loc_82654DEC:
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

__attribute__((alias("__imp__sub_82654E04"))) PPC_WEAK_FUNC(sub_82654E04);
PPC_FUNC_IMPL(__imp__sub_82654E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654E08"))) PPC_WEAK_FUNC(sub_82654E08);
PPC_FUNC_IMPL(__imp__sub_82654E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,1056(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1056);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82654E1C"))) PPC_WEAK_FUNC(sub_82654E1C);
PPC_FUNC_IMPL(__imp__sub_82654E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82654E20"))) PPC_WEAK_FUNC(sub_82654E20);
PPC_FUNC_IMPL(__imp__sub_82654E20) {
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
	// lwz r3,1056(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654E48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1060(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// lwz r9,1056(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// twllei r3,0
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// divw r7,r8,r3
	ctx.r7.s32 = ctx.r8.s32 / ctx.r3.s32;
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r6,r7,r3
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32);
	// subf r4,r6,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r6.s64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// stw r4,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, ctx.r4.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// andc r11,r3,r5
	r11.u64 = ctx.r3.u64 & ~ctx.r5.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// twlgei r11,-1
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82654E8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,1060(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// bge cr6,0x82654ec4
	if (!cr6.lt) goto loc_82654EC4;
	// lwz r3,1056(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654EB0;
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
loc_82654EC4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
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

__attribute__((alias("__imp__sub_82654EE0"))) PPC_WEAK_FUNC(sub_82654EE0);
PPC_FUNC_IMPL(__imp__sub_82654EE0) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,944(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654F10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82654F24;
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

__attribute__((alias("__imp__sub_82654F38"))) PPC_WEAK_FUNC(sub_82654F38);
PPC_FUNC_IMPL(__imp__sub_82654F38) {
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
	ctx.lr = 0x82654F40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x82655078
	if (cr6.eq) goto loc_82655078;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x82654f64
	if (cr6.eq) goto loc_82654F64;
	// bl 0x826537d0
	ctx.lr = 0x82654F5C;
	sub_826537D0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82654F64:
	// bl 0x82654b60
	ctx.lr = 0x82654F68;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82655060
	if (!cr6.eq) goto loc_82655060;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82654F80;
	sub_821E6800(ctx, base);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,672(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 672);
	// bl 0x82203240
	ctx.lr = 0x82654F90;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,656(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654FA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r9,6328
	r11.s64 = ctx.r9.s64 + 6328;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82654FC0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82654fc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82654FC0;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,106
	ctx.r3.s64 = ctx.r1.s64 + 106;
	// bl 0x823d9890
	ctx.lr = 0x82654FE4;
	sub_823D9890(ctx, base);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_82654FEC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82654fec
	if (!cr6.eq) goto loc_82654FEC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82655000:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x82655000
	if (!cr6.eq) goto loc_82655000;
	// lis r11,-32123
	r11.s64 = -2105212928;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,23088
	ctx.r9.s64 = r11.s64 + 23088;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r6,r10,-4992
	ctx.r6.s64 = ctx.r10.s64 + -4992;
	// ld r8,23088(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 23088);
	// li r7,5
	ctx.r7.s64 = 5;
	// stb r4,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, ctx.r4.u8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r29,1200
	ctx.r3.s64 = r29.s64 + 1200;
	// ld r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82655054;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82655060:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8265506C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82655078:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,56
	ctx.r4.s64 = 56;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r11)
	PPC_STORE_U8(r11.u32 + 797, ctx.r10.u8);
	// bl 0x826537d0
	ctx.lr = 0x826550A8;
	sub_826537D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826550B4"))) PPC_WEAK_FUNC(sub_826550B4);
PPC_FUNC_IMPL(__imp__sub_826550B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826550B8"))) PPC_WEAK_FUNC(sub_826550B8);
PPC_FUNC_IMPL(__imp__sub_826550B8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x826550D4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826550E4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826550e4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826550E4;
	// addi r10,r31,6068
	ctx.r10.s64 = r31.s64 + 6068;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655108:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655108
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655108;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655124;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655134:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655134
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655134;
	// addi r10,r31,6308
	ctx.r10.s64 = r31.s64 + 6308;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655158:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655158
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655158;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655174;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655184:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655184
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655184;
	// addi r10,r31,6548
	ctx.r10.s64 = r31.s64 + 6548;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826551A8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826551a8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826551A8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x826551C4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826551D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826551d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826551D4;
	// addi r10,r31,6788
	ctx.r10.s64 = r31.s64 + 6788;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826551F8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826551f8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826551F8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655214;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655224:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655224
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655224;
	// addi r10,r31,7028
	ctx.r10.s64 = r31.s64 + 7028;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655248:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655248
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655248;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655264;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655274:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655274
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655274;
	// addi r10,r31,7268
	ctx.r10.s64 = r31.s64 + 7268;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655298:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655298
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655298;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x826552B4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826552C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826552c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826552C4;
	// addi r10,r31,7508
	ctx.r10.s64 = r31.s64 + 7508;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826552E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826552e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826552E8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655304;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655314:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655314
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655314;
	// addi r10,r31,7748
	ctx.r10.s64 = r31.s64 + 7748;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655338:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655338
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655338;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x82655354;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655364:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655364
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655364;
	// addi r10,r31,7988
	ctx.r10.s64 = r31.s64 + 7988;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655388:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655388
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655388;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x826553A4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826553B4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826553b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826553B4;
	// addi r10,r31,8228
	ctx.r10.s64 = r31.s64 + 8228;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826553D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826553d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826553D8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x826553F4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655404:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655404
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655404;
	// addi r10,r31,8468
	ctx.r10.s64 = r31.s64 + 8468;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82655428:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82655428
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82655428;
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

__attribute__((alias("__imp__sub_82655450"))) PPC_WEAK_FUNC(sub_82655450);
PPC_FUNC_IMPL(__imp__sub_82655450) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,400(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265547C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82655488;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_826554A0"))) PPC_WEAK_FUNC(sub_826554A0);
PPC_FUNC_IMPL(__imp__sub_826554A0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x8262fff0
	ctx.lr = 0x826554C0;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6096
	ctx.r3.s64 = r31.s64 + 6096;
	// bl 0x8262fff0
	ctx.lr = 0x826554CC;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6336
	ctx.r3.s64 = r31.s64 + 6336;
	// bl 0x8262fff0
	ctx.lr = 0x826554D8;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6576
	ctx.r3.s64 = r31.s64 + 6576;
	// bl 0x8262fff0
	ctx.lr = 0x826554E4;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6816
	ctx.r3.s64 = r31.s64 + 6816;
	// bl 0x8262fff0
	ctx.lr = 0x826554F0;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7056
	ctx.r3.s64 = r31.s64 + 7056;
	// bl 0x8262fff0
	ctx.lr = 0x826554FC;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7296
	ctx.r3.s64 = r31.s64 + 7296;
	// bl 0x8262fff0
	ctx.lr = 0x82655508;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7536
	ctx.r3.s64 = r31.s64 + 7536;
	// bl 0x8262fff0
	ctx.lr = 0x82655514;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7776
	ctx.r3.s64 = r31.s64 + 7776;
	// bl 0x8262fff0
	ctx.lr = 0x82655520;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,8016
	ctx.r3.s64 = r31.s64 + 8016;
	// bl 0x8262fff0
	ctx.lr = 0x8265552C;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,8256
	ctx.r3.s64 = r31.s64 + 8256;
	// bl 0x8262fff0
	ctx.lr = 0x82655538;
	sub_8262FFF0(ctx, base);
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

__attribute__((alias("__imp__sub_8265554C"))) PPC_WEAK_FUNC(sub_8265554C);
PPC_FUNC_IMPL(__imp__sub_8265554C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82655550"))) PPC_WEAK_FUNC(sub_82655550);
PPC_FUNC_IMPL(__imp__sub_82655550) {
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
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826555a4
	if (cr6.eq) goto loc_826555A4;
	// lwz r11,1136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1136);
	// addi r3,r31,1136
	ctx.r3.s64 = r31.s64 + 1136;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82655584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1608(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1608);
	// addi r11,r31,1392
	r11.s64 = r31.s64 + 1392;
	// stw r3,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, ctx.r3.u32);
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// beq cr6,0x826555a4
	if (cr6.eq) goto loc_826555A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x826555A4;
	sub_821C3048(ctx, base);
loc_826555A4:
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

__attribute__((alias("__imp__sub_826555B8"))) PPC_WEAK_FUNC(sub_826555B8);
PPC_FUNC_IMPL(__imp__sub_826555B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826555C8"))) PPC_WEAK_FUNC(sub_826555C8);
PPC_FUNC_IMPL(__imp__sub_826555C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4496);
	// stw r11,8520(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8520, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826555D4"))) PPC_WEAK_FUNC(sub_826555D4);
PPC_FUNC_IMPL(__imp__sub_826555D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826555D8"))) PPC_WEAK_FUNC(sub_826555D8);
PPC_FUNC_IMPL(__imp__sub_826555D8) {
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
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82655630
	if (cr6.eq) goto loc_82655630;
	// lwz r11,1136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1136);
	// addi r3,r31,1136
	ctx.r3.s64 = r31.s64 + 1136;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82655610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1608(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1608);
	// addi r11,r31,1392
	r11.s64 = r31.s64 + 1392;
	// stw r3,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, ctx.r3.u32);
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// beq cr6,0x82655630
	if (cr6.eq) goto loc_82655630;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82655630;
	sub_821C3048(ctx, base);
loc_82655630:
	// lwz r11,3056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82655768
	if (!cr6.eq) goto loc_82655768;
	// lwz r10,6064(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6064);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82655650
	if (cr6.eq) goto loc_82655650;
	// li r11,1
	r11.s64 = 1;
loc_82655650:
	// lwz r10,6304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6304);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82655660
	if (cr6.eq) goto loc_82655660;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82655660:
	// lwz r10,6544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6544);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82655670
	if (cr6.eq) goto loc_82655670;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82655670:
	// lwz r10,6784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6784);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82655680
	if (cr6.eq) goto loc_82655680;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82655680:
	// lwz r10,7024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7024);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82655690
	if (cr6.eq) goto loc_82655690;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82655690:
	// lwz r10,7264(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7264);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826556a0
	if (cr6.eq) goto loc_826556A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_826556A0:
	// lwz r10,7504(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7504);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826556b0
	if (cr6.eq) goto loc_826556B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_826556B0:
	// lwz r10,7744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7744);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826556c0
	if (cr6.eq) goto loc_826556C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_826556C0:
	// lwz r10,7984(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7984);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826556d0
	if (cr6.eq) goto loc_826556D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_826556D0:
	// lwz r10,8224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826556e0
	if (cr6.eq) goto loc_826556E0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_826556E0:
	// addi r30,r31,8256
	r30.s64 = r31.s64 + 8256;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bge cr6,0x82655724
	if (!cr6.lt) goto loc_82655724;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8262fff0
	ctx.lr = 0x826556F8;
	sub_8262FFF0(ctx, base);
	// lwz r11,8256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8256);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265570C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82655768
	if (cr6.eq) goto loc_82655768;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// b 0x82655748
	goto loc_82655748;
loc_82655724:
	// lwz r11,8256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8256);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82655734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82655768
	if (!cr6.eq) goto loc_82655768;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
loc_82655748:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82655754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82655768;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82655768:
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

__attribute__((alias("__imp__sub_82655780"))) PPC_WEAK_FUNC(sub_82655780);
PPC_FUNC_IMPL(__imp__sub_82655780) {
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
	// bl 0x8263a5f8
	ctx.lr = 0x82655798;
	sub_8263A5F8(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r8,r10,-4964
	ctx.r8.s64 = ctx.r10.s64 + -4964;
	// li r11,0
	r11.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,27964(r9)
	PPC_STORE_U8(ctx.r9.u32 + 27964, r11.u8);
	// stb r11,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r11.u8);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
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

__attribute__((alias("__imp__sub_826557D0"))) PPC_WEAK_FUNC(sub_826557D0);
PPC_FUNC_IMPL(__imp__sub_826557D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-4408
	ctx.r10.s64 = ctx.r10.s64 + -4408;
loc_826557DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82655800
	if (cr6.eq) goto loc_82655800;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826557dc
	if (cr6.eq) goto loc_826557DC;
loc_82655800:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8265581c
	if (!cr6.eq) goto loc_8265581C;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8265581c
	if (cr6.eq) goto loc_8265581C;
	// lbz r11,4(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// stb r11,164(r3)
	PPC_STORE_U8(ctx.r3.u32 + 164, r11.u8);
	// blr 
	return;
loc_8265581C:
	// b 0x8268e578
	sub_8268E578(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82655820"))) PPC_WEAK_FUNC(sub_82655820);
PPC_FUNC_IMPL(__imp__sub_82655820) {
	PPC_FUNC_PROLOGUE();
	// b 0x82630530
	sub_82630530(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82655824"))) PPC_WEAK_FUNC(sub_82655824);
PPC_FUNC_IMPL(__imp__sub_82655824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82655828"))) PPC_WEAK_FUNC(sub_82655828);
PPC_FUNC_IMPL(__imp__sub_82655828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,800(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 800);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82655838"))) PPC_WEAK_FUNC(sub_82655838);
PPC_FUNC_IMPL(__imp__sub_82655838) {
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
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82655884
	if (cr6.eq) goto loc_82655884;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// ble cr6,0x82655860
	if (!cr6.gt) goto loc_82655860;
	// cmpwi cr6,r5,5
	cr6.compare<int32_t>(ctx.r5.s32, 5, xer);
	// ble cr6,0x82655884
	if (!cr6.gt) goto loc_82655884;
loc_82655860:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82655870;
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
loc_82655884:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265589C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x826558A8;
	sub_82218310(ctx, base);
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

__attribute__((alias("__imp__sub_826558BC"))) PPC_WEAK_FUNC(sub_826558BC);
PPC_FUNC_IMPL(__imp__sub_826558BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826558C0"))) PPC_WEAK_FUNC(sub_826558C0);
PPC_FUNC_IMPL(__imp__sub_826558C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826558C8;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// stw r3,20(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20, ctx.r3.u32);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826558E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826558e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826558E8;
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// li r29,32
	r29.s64 = 32;
	// stw r11,-108(r1)
	PPC_STORE_U32(ctx.r1.u32 + -108, r11.u32);
	// li r30,64
	r30.s64 = 64;
	// stw r10,-112(r1)
	PPC_STORE_U32(ctx.r1.u32 + -112, ctx.r10.u32);
	// li r31,96
	r31.s64 = 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,128
	ctx.r5.s64 = 128;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,64(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 64);
	// stb r9,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r9.u8);
	// li r6,160
	ctx.r6.s64 = 160;
	// lbz r8,65(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 65);
	// li r7,192
	ctx.r7.s64 = 192;
	// stb r8,65(r3)
	PPC_STORE_U8(ctx.r3.u32 + 65, ctx.r8.u8);
	// lvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,96(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 96);
	// stb r9,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r9.u8);
	// li r8,224
	ctx.r8.s64 = 224;
	// lbz r29,97(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 97);
	// li r9,256
	ctx.r9.s64 = 256;
	// stb r29,97(r3)
	PPC_STORE_U8(ctx.r3.u32 + 97, r29.u8);
	// lvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r30,128(r4)
	r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 128);
	// stb r30,128(r3)
	PPC_STORE_U8(ctx.r3.u32 + 128, r30.u8);
	// li r28,288
	r28.s64 = 288;
	// lbz r30,129(r4)
	r30.u64 = PPC_LOAD_U8(ctx.r4.u32 + 129);
	// li r29,320
	r29.s64 = 320;
	// stb r30,129(r3)
	PPC_STORE_U8(ctx.r3.u32 + 129, r30.u8);
	// lvx128 v60,r11,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r31,160(r4)
	r31.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// stb r31,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, r31.u8);
	// li r30,352
	r30.s64 = 352;
	// lbz r27,161(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 161);
	// li r31,384
	r31.s64 = 384;
	// stb r27,161(r3)
	PPC_STORE_U8(ctx.r3.u32 + 161, r27.u8);
	// lvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,192(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 192);
	// stb r5,192(r3)
	PPC_STORE_U8(ctx.r3.u32 + 192, ctx.r5.u8);
	// li r5,416
	ctx.r5.s64 = 416;
	// lbz r27,193(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 193);
	// li r25,576
	r25.s64 = 576;
	// stb r27,193(r3)
	PPC_STORE_U8(ctx.r3.u32 + 193, r27.u8);
	// lvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,224(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 224);
	// stb r6,224(r3)
	PPC_STORE_U8(ctx.r3.u32 + 224, ctx.r6.u8);
	// li r6,448
	ctx.r6.s64 = 448;
	// lbz r27,225(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 225);
	// li r26,608
	r26.s64 = 608;
	// stb r27,225(r3)
	PPC_STORE_U8(ctx.r3.u32 + 225, r27.u8);
	// lvx128 v57,r11,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,256(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 256);
	// stb r7,256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 256, ctx.r7.u8);
	// li r7,480
	ctx.r7.s64 = 480;
	// lbz r27,257(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 257);
	// stb r27,257(r3)
	PPC_STORE_U8(ctx.r3.u32 + 257, r27.u8);
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,288(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 288);
	// stb r8,288(r3)
	PPC_STORE_U8(ctx.r3.u32 + 288, ctx.r8.u8);
	// li r8,512
	ctx.r8.s64 = 512;
	// lbz r27,289(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 289);
	// stb r27,289(r3)
	PPC_STORE_U8(ctx.r3.u32 + 289, r27.u8);
	// lvx128 v55,r11,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,320(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 320);
	// stb r9,320(r3)
	PPC_STORE_U8(ctx.r3.u32 + 320, ctx.r9.u8);
	// li r9,544
	ctx.r9.s64 = 544;
	// lbz r27,321(r4)
	r27.u64 = PPC_LOAD_U8(ctx.r4.u32 + 321);
	// stb r27,321(r3)
	PPC_STORE_U8(ctx.r3.u32 + 321, r27.u8);
	// lvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r24,352(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 352);
	// li r27,640
	r27.s64 = 640;
	// stb r24,352(r3)
	PPC_STORE_U8(ctx.r3.u32 + 352, r24.u8);
	// rotlwi r23,r10,0
	r23.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r24,353(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 353);
	// li r28,672
	r28.s64 = 672;
	// stb r24,353(r3)
	PPC_STORE_U8(ctx.r3.u32 + 353, r24.u8);
	// lvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r22,28(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	// stvx128 v53,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r29,384(r4)
	r29.u64 = PPC_LOAD_U8(ctx.r4.u32 + 384);
	// mr r21,r22
	r21.u64 = r22.u64;
	// stb r29,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, r29.u8);
	// li r29,704
	r29.s64 = 704;
	// lbz r24,385(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 385);
	// stb r24,385(r3)
	PPC_STORE_U8(ctx.r3.u32 + 385, r24.u8);
	// lvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r24,416(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 416);
	// stb r24,416(r3)
	PPC_STORE_U8(ctx.r3.u32 + 416, r24.u8);
	// li r30,736
	r30.s64 = 736;
	// lbz r24,417(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 417);
	// stb r24,417(r3)
	PPC_STORE_U8(ctx.r3.u32 + 417, r24.u8);
	// lvx128 v51,r11,r31
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,768
	r31.s64 = 768;
	// lbz r24,448(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 448);
	// stb r24,448(r3)
	PPC_STORE_U8(ctx.r3.u32 + 448, r24.u8);
	// lbz r24,449(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 449);
	// stb r24,449(r3)
	PPC_STORE_U8(ctx.r3.u32 + 449, r24.u8);
	// lvx128 v50,r11,r5
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,832
	ctx.r5.s64 = 832;
	// lbz r24,480(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 480);
	// stb r24,480(r3)
	PPC_STORE_U8(ctx.r3.u32 + 480, r24.u8);
	// lbz r24,481(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 481);
	// stb r24,481(r3)
	PPC_STORE_U8(ctx.r3.u32 + 481, r24.u8);
	// lvx128 v49,r11,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,512(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 512);
	// stb r6,512(r3)
	PPC_STORE_U8(ctx.r3.u32 + 512, ctx.r6.u8);
	// li r6,864
	ctx.r6.s64 = 864;
	// lbz r24,513(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 513);
	// stb r24,513(r3)
	PPC_STORE_U8(ctx.r3.u32 + 513, r24.u8);
	// lvx128 v48,r11,r7
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,896
	ctx.r7.s64 = 896;
	// lbz r24,544(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 544);
	// stb r24,544(r3)
	PPC_STORE_U8(ctx.r3.u32 + 544, r24.u8);
	// lbz r24,545(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 545);
	// stb r24,545(r3)
	PPC_STORE_U8(ctx.r3.u32 + 545, r24.u8);
	// lvx128 v47,r11,r8
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lbz r24,576(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 576);
	// li r8,928
	ctx.r8.s64 = 928;
	// stb r24,576(r3)
	PPC_STORE_U8(ctx.r3.u32 + 576, r24.u8);
	// lbz r24,577(r4)
	r24.u64 = PPC_LOAD_U8(ctx.r4.u32 + 577);
	// li r4,800
	ctx.r4.s64 = 800;
	// stb r24,577(r3)
	PPC_STORE_U8(ctx.r3.u32 + 577, r24.u8);
	// lwz r3,20(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lvx128 v46,r11,r9
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r23,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,608(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 608);
	// stb r11,608(r3)
	PPC_STORE_U8(ctx.r3.u32 + 608, r11.u8);
	// mr r11,r22
	r11.u64 = r22.u64;
	// lbz r9,609(r21)
	ctx.r9.u64 = PPC_LOAD_U8(r21.u32 + 609);
	// stb r9,609(r3)
	PPC_STORE_U8(ctx.r3.u32 + 609, ctx.r9.u8);
	// lvx128 v45,r10,r25
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -112);
	// stvx128 v45,r9,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r25,640(r11)
	r25.u64 = PPC_LOAD_U8(r11.u32 + 640);
	// stb r25,640(r3)
	PPC_STORE_U8(ctx.r3.u32 + 640, r25.u8);
	// lbz r25,641(r11)
	r25.u64 = PPC_LOAD_U8(r11.u32 + 641);
	// stb r25,641(r3)
	PPC_STORE_U8(ctx.r3.u32 + 641, r25.u8);
	// lvx128 v44,r10,r26
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r9,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r26,672(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 672);
	// stb r26,672(r3)
	PPC_STORE_U8(ctx.r3.u32 + 672, r26.u8);
	// lbz r26,673(r11)
	r26.u64 = PPC_LOAD_U8(r11.u32 + 673);
	// stb r26,673(r3)
	PPC_STORE_U8(ctx.r3.u32 + 673, r26.u8);
	// lvx128 v43,r10,r27
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r27,704(r11)
	r27.u64 = PPC_LOAD_U8(r11.u32 + 704);
	// stb r27,704(r3)
	PPC_STORE_U8(ctx.r3.u32 + 704, r27.u8);
	// lbz r27,705(r11)
	r27.u64 = PPC_LOAD_U8(r11.u32 + 705);
	// stb r27,705(r3)
	PPC_STORE_U8(ctx.r3.u32 + 705, r27.u8);
	// lvx128 v42,r10,r28
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r9,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r28,736(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 736);
	// stb r28,736(r3)
	PPC_STORE_U8(ctx.r3.u32 + 736, r28.u8);
	// lbz r28,737(r11)
	r28.u64 = PPC_LOAD_U8(r11.u32 + 737);
	// stb r28,737(r3)
	PPC_STORE_U8(ctx.r3.u32 + 737, r28.u8);
	// lvx128 v41,r10,r29
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r9,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r29,768(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 768);
	// stb r29,768(r3)
	PPC_STORE_U8(ctx.r3.u32 + 768, r29.u8);
	// lbz r29,769(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 769);
	// stb r29,769(r3)
	PPC_STORE_U8(ctx.r3.u32 + 769, r29.u8);
	// lvx128 v40,r10,r30
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r30,800(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 800);
	// stb r30,800(r3)
	PPC_STORE_U8(ctx.r3.u32 + 800, r30.u8);
	// lbz r30,801(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 801);
	// stb r30,801(r3)
	PPC_STORE_U8(ctx.r3.u32 + 801, r30.u8);
	// lvx128 v39,r10,r31
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r9,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r31,832(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 832);
	// stb r31,832(r3)
	PPC_STORE_U8(ctx.r3.u32 + 832, r31.u8);
	// lbz r31,833(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 833);
	// stb r31,833(r3)
	PPC_STORE_U8(ctx.r3.u32 + 833, r31.u8);
	// lvx128 v38,r10,r4
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r9,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,864(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 864);
	// stb r4,864(r3)
	PPC_STORE_U8(ctx.r3.u32 + 864, ctx.r4.u8);
	// lbz r4,865(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 865);
	// stb r4,865(r3)
	PPC_STORE_U8(ctx.r3.u32 + 865, ctx.r4.u8);
	// lvx128 v37,r10,r5
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,896(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 896);
	// stb r5,896(r3)
	PPC_STORE_U8(ctx.r3.u32 + 896, ctx.r5.u8);
	// lbz r4,897(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 897);
	// stb r4,897(r3)
	PPC_STORE_U8(ctx.r3.u32 + 897, ctx.r4.u8);
	// lvx128 v36,r10,r6
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,928(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 928);
	// stb r6,928(r3)
	PPC_STORE_U8(ctx.r3.u32 + 928, ctx.r6.u8);
	// lbz r5,929(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 929);
	// stb r5,929(r3)
	PPC_STORE_U8(ctx.r3.u32 + 929, ctx.r5.u8);
	// lvx128 v35,r10,r7
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,960(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 960);
	// stb r4,960(r3)
	PPC_STORE_U8(ctx.r3.u32 + 960, ctx.r4.u8);
	// lbz r7,961(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 961);
	// stb r7,961(r3)
	PPC_STORE_U8(ctx.r3.u32 + 961, ctx.r7.u8);
	// lvx128 v34,r10,r8
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,960
	ctx.r8.s64 = 960;
	// lbz r6,992(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 992);
	// stb r6,992(r3)
	PPC_STORE_U8(ctx.r3.u32 + 992, ctx.r6.u8);
	// lbz r5,993(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 993);
	// stb r5,993(r3)
	PPC_STORE_U8(ctx.r3.u32 + 993, ctx.r5.u8);
	// lvx128 v33,r10,r8
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,1024(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 1024);
	// stb r4,1024(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1024, ctx.r4.u8);
	// lbz r10,1025(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1025);
	// stb r10,1025(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1025, ctx.r10.u8);
	// lbz r9,1040(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 1040);
	// stb r9,1040(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1040, ctx.r9.u8);
	// lbz r8,1041(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 1041);
	// stb r8,1041(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1041, ctx.r8.u8);
	// lbz r7,1042(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1042);
	// stb r7,1042(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1042, ctx.r7.u8);
	// lbz r6,1043(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1043);
	// stb r6,1043(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1043, ctx.r6.u8);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82655CAC"))) PPC_WEAK_FUNC(sub_82655CAC);
PPC_FUNC_IMPL(__imp__sub_82655CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82655CB0"))) PPC_WEAK_FUNC(sub_82655CB0);
PPC_FUNC_IMPL(__imp__sub_82655CB0) {
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
	// rlwinm r30,r4,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// bne cr6,0x82655d04
	if (!cr6.eq) goto loc_82655D04;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r4,18(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204310
	ctx.lr = 0x82655CF0;
	sub_82204310(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82655d04
	if (cr6.eq) goto loc_82655D04;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4384
	ctx.r3.s64 = r11.s64 + -4384;
	// b 0x82655d58
	goto loc_82655D58;
loc_82655D04:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bne cr6,0x82655d20
	if (!cr6.eq) goto loc_82655D20;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4396
	ctx.r3.s64 = r11.s64 + -4396;
	// b 0x82655d58
	goto loc_82655D58;
loc_82655D20:
	// cmpwi cr6,r11,17
	cr6.compare<int32_t>(r11.s32, 17, xer);
	// bne cr6,0x82655d34
	if (!cr6.eq) goto loc_82655D34;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,6512
	ctx.r3.s64 = r11.s64 + 6512;
	// b 0x82655d58
	goto loc_82655D58;
loc_82655D34:
	// cmpwi cr6,r11,18
	cr6.compare<int32_t>(r11.s32, 18, xer);
	// bne cr6,0x82655d48
	if (!cr6.eq) goto loc_82655D48;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,8860
	ctx.r3.s64 = r11.s64 + 8860;
	// b 0x82655d58
	goto loc_82655D58;
loc_82655D48:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-27892
	ctx.r8.s64 = ctx.r10.s64 + -27892;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
loc_82655D58:
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

__attribute__((alias("__imp__sub_82655D70"))) PPC_WEAK_FUNC(sub_82655D70);
PPC_FUNC_IMPL(__imp__sub_82655D70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,-6148(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -6148);
	// mulli r10,r8,1056
	ctx.r10.s64 = ctx.r8.s64 * 1056;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r3,r11,11988
	ctx.r3.s64 = r11.s64 + 11988;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82655D94"))) PPC_WEAK_FUNC(sub_82655D94);
PPC_FUNC_IMPL(__imp__sub_82655D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82655D98"))) PPC_WEAK_FUNC(sub_82655D98);
PPC_FUNC_IMPL(__imp__sub_82655D98) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82655DC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x82655DCC;
	sub_82218310(ctx, base);
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

__attribute__((alias("__imp__sub_82655DE0"))) PPC_WEAK_FUNC(sub_82655DE0);
PPC_FUNC_IMPL(__imp__sub_82655DE0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,44(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,36(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,-10028(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lwzx r4,r6,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r31,r11,30
	r31.s64 = r11.s64 + 30;
	// bl 0x822042b0
	ctx.lr = 0x82655E34;
	sub_822042B0(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// addi r3,r31,10
	ctx.r3.s64 = r31.s64 + 10;
	// bne cr6,0x82655e44
	if (!cr6.eq) goto loc_82655E44;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82655E44:
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

__attribute__((alias("__imp__sub_82655E58"))) PPC_WEAK_FUNC(sub_82655E58);
PPC_FUNC_IMPL(__imp__sub_82655E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x82655E60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,5
	cr6.compare<uint32_t>(ctx.r5.u32, 5, xer);
	// bgt cr6,0x82655fe8
	if (cr6.gt) goto loc_82655FE8;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,24200
	r12.s64 = r12.s64 + 24200;
	// rlwinm r0,r5,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r5.u64) {
	case 0:
		goto loc_82655EA0;
	case 1:
		goto loc_82655EC4;
	case 2:
		goto loc_82655FA8;
	case 3:
		goto loc_82655FB8;
	case 4:
		goto loc_82655FC8;
	case 5:
		goto loc_82655FD8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,24224(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24224);
	// lwz r19,24260(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24260);
	// lwz r19,24488(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24488);
	// lwz r19,24504(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24504);
	// lwz r19,24520(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24520);
	// lwz r19,24536(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24536);
loc_82655EA0:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r7,36(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655EC4:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rlwinm r31,r4,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r28,0
	r28.s64 = 0;
	// addi r4,r10,-18740
	ctx.r4.s64 = ctx.r10.s64 + -18740;
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82655EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82655f00
	if (cr6.eq) goto loc_82655F00;
	// li r28,8
	r28.s64 = 8;
loc_82655F00:
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r10,-18748
	ctx.r4.s64 = ctx.r10.s64 + -18748;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82655F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82655f30
	if (cr6.eq) goto loc_82655F30;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
loc_82655F30:
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r10,-18732
	ctx.r4.s64 = ctx.r10.s64 + -18732;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82655F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82655f60
	if (cr6.eq) goto loc_82655F60;
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
loc_82655F60:
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r10,-18756
	ctx.r4.s64 = ctx.r10.s64 + -18756;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82655F84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82655f90
	if (cr6.eq) goto loc_82655F90;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82655F90:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,28128
	ctx.r9.s64 = r11.s64 + 28128;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655FA8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4308
	ctx.r3.s64 = r11.s64 + -4308;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655FB8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4328
	ctx.r3.s64 = r11.s64 + -4328;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655FC8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4340
	ctx.r3.s64 = r11.s64 + -4340;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655FD8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4360
	ctx.r3.s64 = r11.s64 + -4360;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82655FE8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4368
	ctx.r3.s64 = r11.s64 + -4368;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82655FF8"))) PPC_WEAK_FUNC(sub_82655FF8);
PPC_FUNC_IMPL(__imp__sub_82655FF8) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x82656014;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82656024
	if (cr6.lt) goto loc_82656024;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82656024:
	// lwz r10,980(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 980);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82656044"))) PPC_WEAK_FUNC(sub_82656044);
PPC_FUNC_IMPL(__imp__sub_82656044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82656048"))) PPC_WEAK_FUNC(sub_82656048);
PPC_FUNC_IMPL(__imp__sub_82656048) {
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
	ctx.lr = 0x82656050;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x82656064;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82656074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826561b4
	if (cr6.eq) goto loc_826561B4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265608C;
	sub_8238EC00(ctx, base);
	// addi r11,r29,672
	r11.s64 = r29.s64 + 672;
	// lwz r30,864(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 864);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82631f88
	ctx.lr = 0x826560A0;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826560b0
	if (cr6.lt) goto loc_826560B0;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826560B0:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826560CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823895f8
	ctx.lr = 0x826560DC;
	sub_823895F8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r4,136(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 136);
	// bl 0x8223de50
	ctx.lr = 0x82656100;
	sub_8223DE50(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r6,-4276
	ctx.r3.s64 = ctx.r6.s64 + -4276;
	// bl 0x82130000
	ctx.lr = 0x82656110;
	sub_82130000(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,-4292
	ctx.r4.s64 = r11.s64 + -4292;
	// lwz r3,-10244(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82656128;
	sub_822183B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82656130;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82656144;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8265614C;
	sub_824E70F0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,864(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 864);
	// addi r10,r29,928
	ctx.r10.s64 = r29.s64 + 928;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// beq cr6,0x8265618c
	if (cr6.eq) goto loc_8265618C;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8265617c
	if (cr6.eq) goto loc_8265617C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28860
	ctx.r4.s64 = r11.s64 + 28860;
	// b 0x826561b0
	goto loc_826561B0;
loc_8265617C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,28900
	ctx.r4.s64 = r11.s64 + 28900;
	// b 0x826561b0
	goto loc_826561B0;
loc_8265618C:
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x826561a4
	if (cr6.eq) goto loc_826561A4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,28500
	ctx.r4.s64 = r11.s64 + 28500;
	// b 0x826561b0
	goto loc_826561B0;
loc_826561A4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,28572
	ctx.r4.s64 = r11.s64 + 28572;
loc_826561B0:
	// bl 0x8262ffe0
	ctx.lr = 0x826561B4;
	sub_8262FFE0(ctx, base);
loc_826561B4:
	// lwz r11,672(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 672);
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826561C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826561D0"))) PPC_WEAK_FUNC(sub_826561D0);
PPC_FUNC_IMPL(__imp__sub_826561D0) {
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
	// bl 0x82630748
	ctx.lr = 0x826561F0;
	sub_82630748(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,8044
	ctx.r5.s64 = r11.s64 + 8044;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,860
	ctx.r6.s64 = r31.s64 + 860;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x82656210;
	sub_824DF200(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-4192
	ctx.r5.s64 = ctx.r10.s64 + -4192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1220
	ctx.r6.s64 = r31.s64 + 1220;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82656230;
	sub_824DF200(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-4208
	ctx.r5.s64 = ctx.r9.s64 + -4208;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1224
	ctx.r6.s64 = r31.s64 + 1224;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82656250;
	sub_824DF200(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-4224
	ctx.r5.s64 = ctx.r8.s64 + -4224;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1228
	ctx.r6.s64 = r31.s64 + 1228;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82656270;
	sub_824DF200(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-4232
	ctx.r5.s64 = ctx.r7.s64 + -4232;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1408
	ctx.r6.s64 = r31.s64 + 1408;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82656290;
	sub_824DF200(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-4248
	ctx.r5.s64 = ctx.r6.s64 + -4248;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1412
	ctx.r6.s64 = r31.s64 + 1412;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826562B0;
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

__attribute__((alias("__imp__sub_826562C8"))) PPC_WEAK_FUNC(sub_826562C8);
PPC_FUNC_IMPL(__imp__sub_826562C8) {
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
	ctx.lr = 0x826562D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826562EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x826563e0
	if (!cr6.eq) goto loc_826563E0;
	// lwz r30,864(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r29,r31,952
	r29.s64 = r31.s64 + 952;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// bne cr6,0x82656350
	if (!cr6.eq) goto loc_82656350;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r28,-10028(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + -10028);
	// bl 0x82203240
	ctx.lr = 0x82656318;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82656330;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822042b0
	ctx.lr = 0x8265633C;
	sub_822042B0(ctx, base);
	// lwz r11,-10028(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10028);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82211138
	ctx.lr = 0x8265634C;
	sub_82211138(ctx, base);
	// b 0x82656380
	goto loc_82656380;
loc_82656350:
	// addi r29,r31,976
	r29.s64 = r31.s64 + 976;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// bne cr6,0x8265639c
	if (!cr6.eq) goto loc_8265639C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82655ff8
	ctx.lr = 0x82656364;
	sub_82655FF8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mulli r10,r3,1056
	ctx.r10.s64 = ctx.r3.s64 * 1056;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,11984
	ctx.r3.s64 = r11.s64 + 11984;
	// bl 0x82250f20
	ctx.lr = 0x82656380;
	sub_82250F20(ctx, base);
loc_82656380:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265639C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265639C:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826563B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,864(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826563C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x826563e0
	if (!cr6.eq) goto loc_826563E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826563E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826563E0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826563E8"))) PPC_WEAK_FUNC(sub_826563E8);
PPC_FUNC_IMPL(__imp__sub_826563E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x826563F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82656408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r4,r8,-12776
	ctx.r4.s64 = ctx.r8.s64 + -12776;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// addi r30,r7,-7660
	r30.s64 = ctx.r7.s64 + -7660;
	// addi r29,r6,-22108
	r29.s64 = ctx.r6.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82656434;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82656448;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265646c
	if (cr6.eq) goto loc_8265646C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,27964(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27964);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265646c
	if (cr6.eq) goto loc_8265646C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265646C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lfs f2,27640(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f2.f64 = double(temp.f32);
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// lfs f1,1184(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1184);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-7572(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7572);
	// bl 0x822f1518
	ctx.lr = 0x82656494;
	sub_822F1518(ctx, base);
	// lwz r11,1188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1188);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r11,-7884(r7)
	PPC_STORE_U32(ctx.r7.u32 + -7884, r11.u32);
	// bl 0x822e8a78
	ctx.lr = 0x826564A4;
	sub_822E8A78(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x826564AC;
	sub_82216138(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826564B8"))) PPC_WEAK_FUNC(sub_826564B8);
PPC_FUNC_IMPL(__imp__sub_826564B8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826564E0;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826564F0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826564f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826564F0;
	// addi r10,r31,6068
	ctx.r10.s64 = r31.s64 + 6068;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656514:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656514
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656514;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265653C;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265654C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265654c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265654C;
	// addi r10,r31,6308
	ctx.r10.s64 = r31.s64 + 6308;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656570:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656570
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656570;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x82656598;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826565A8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826565a8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826565A8;
	// addi r10,r31,6548
	ctx.r10.s64 = r31.s64 + 6548;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826565CC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826565cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826565CC;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826565F4;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656604:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656604
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656604;
	// addi r10,r31,6788
	ctx.r10.s64 = r31.s64 + 6788;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656628:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656628
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656628;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x82656650;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656660:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656660
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656660;
	// addi r10,r31,7028
	ctx.r10.s64 = r31.s64 + 7028;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656684:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656684
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656684;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826566AC;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826566BC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826566bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826566BC;
	// addi r10,r31,7268
	ctx.r10.s64 = r31.s64 + 7268;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826566E0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826566e0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826566E0;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x82656708;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656718:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656718
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656718;
	// addi r10,r31,7508
	ctx.r10.s64 = r31.s64 + 7508;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265673C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265673c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265673C;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x82656764;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656774:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656774
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656774;
	// addi r10,r31,7748
	ctx.r10.s64 = r31.s64 + 7748;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656798:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656798
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656798;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826567C0;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826567D0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826567d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826567D0;
	// addi r10,r31,7988
	ctx.r10.s64 = r31.s64 + 7988;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826567F4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826567f4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826567F4;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265681C;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265682C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265682c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265682C;
	// addi r10,r31,8228
	ctx.r10.s64 = r31.s64 + 8228;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656850:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656850
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656850;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21976
	ctx.r4.s64 = r11.s64 + 21976;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x82656878;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82656888:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82656888
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82656888;
	// addi r10,r31,8468
	ctx.r10.s64 = r31.s64 + 8468;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826568AC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826568ac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826568AC;
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

__attribute__((alias("__imp__sub_826568D4"))) PPC_WEAK_FUNC(sub_826568D4);
PPC_FUNC_IMPL(__imp__sub_826568D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826568D8"))) PPC_WEAK_FUNC(sub_826568D8);
PPC_FUNC_IMPL(__imp__sub_826568D8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r9,r10,55136
	ctx.r9.u64 = ctx.r10.u64 | 55136;
	// lwz r3,200(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r4,208(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lbzx r30,r7,r9
	r30.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r9.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82656924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,-5396
	ctx.r10.s64 = ctx.r10.s64 + -5396;
loc_82656930:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82656954
	if (cr6.eq) goto loc_82656954;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82656930
	if (cr6.eq) goto loc_82656930;
loc_82656954:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82656964
	if (!cr6.eq) goto loc_82656964;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x82656980
	goto loc_82656980;
loc_82656964:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265697c
	if (cr6.eq) goto loc_8265697C;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// b 0x82656980
	goto loc_82656980;
loc_8265697C:
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
loc_82656980:
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

__attribute__((alias("__imp__sub_82656998"))) PPC_WEAK_FUNC(sub_82656998);
PPC_FUNC_IMPL(__imp__sub_82656998) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// lwz r11,928(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 928);
	// lwz r4,2096(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 2096);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826569C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,-5396
	ctx.r10.s64 = ctx.r10.s64 + -5396;
loc_826569D4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826569f8
	if (cr6.eq) goto loc_826569F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826569d4
	if (cr6.eq) goto loc_826569D4;
loc_826569F8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82656a4c
	if (cr6.eq) goto loc_82656A4C;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r10,-4372
	ctx.r10.s64 = ctx.r10.s64 + -4372;
loc_82656A0C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82656a30
	if (cr6.eq) goto loc_82656A30;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82656a0c
	if (cr6.eq) goto loc_82656A0C;
loc_82656A30:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82656a4c
	if (cr6.eq) goto loc_82656A4C;
	// lwz r11,2096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2096);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r9,r10,28200
	ctx.r9.s64 = ctx.r10.s64 + 28200;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x82656a60
	goto loc_82656A60;
loc_82656A4C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ori r9,r10,55364
	ctx.r9.u64 = ctx.r10.u64 | 55364;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
loc_82656A60:
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r11,-7884(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7884, r11.u32);
	// bl 0x822e8a78
	ctx.lr = 0x82656A70;
	sub_822E8A78(ctx, base);
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

__attribute__((alias("__imp__sub_82656A84"))) PPC_WEAK_FUNC(sub_82656A84);
PPC_FUNC_IMPL(__imp__sub_82656A84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82656A88"))) PPC_WEAK_FUNC(sub_82656A88);
PPC_FUNC_IMPL(__imp__sub_82656A88) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r31,1
	r31.s64 = 1;
	// addi r4,r11,27920
	ctx.r4.s64 = r11.s64 + 27920;
	// lwz r10,3776(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3776);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// blt cr6,0x82656ae4
	if (cr6.lt) goto loc_82656AE4;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,28076
	ctx.r10.s64 = ctx.r10.s64 + 28076;
loc_82656AC4:
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r8,r4,4
	ctx.r8.s64 = ctx.r4.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r7,3776(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3776);
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// ble cr6,0x82656ac4
	if (!cr6.gt) goto loc_82656AC4;
loc_82656AE4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r11,r11,-4164
	r11.s64 = r11.s64 + -4164;
	// addi r8,r9,-4180
	ctx.r8.s64 = ctx.r9.s64 + -4180;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// addi r3,r30,1072
	ctx.r3.s64 = r30.s64 + 1072;
	// stwx r8,r10,r4
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, ctx.r8.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r7,1072(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 1072);
	// addi r5,r31,1
	ctx.r5.s64 = r31.s64 + 1;
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82656B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x82656B20;
	sub_82387A18(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82656b5c
	if (cr6.eq) goto loc_82656B5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82656b5c
	if (cr6.eq) goto loc_82656B5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,680(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 680);
	// b 0x82656b60
	goto loc_82656B60;
loc_82656B5C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
loc_82656B60:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// lwz r11,2368(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2368);
	// addi r3,r30,2368
	ctx.r3.s64 = r30.s64 + 2368;
	// ble cr6,0x82656b78
	if (!cr6.gt) goto loc_82656B78;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// b 0x82656b7c
	goto loc_82656B7C;
loc_82656B78:
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
loc_82656B7C:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82656B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,3536(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3536);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// ble cr6,0x82656b9c
	if (!cr6.gt) goto loc_82656B9C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,3328
	ctx.r3.s64 = r30.s64 + 3328;
	// bl 0x8262fff0
	ctx.lr = 0x82656B9C;
	sub_8262FFF0(ctx, base);
loc_82656B9C:
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

__attribute__((alias("__imp__sub_82656BB4"))) PPC_WEAK_FUNC(sub_82656BB4);
PPC_FUNC_IMPL(__imp__sub_82656BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82656BB8"))) PPC_WEAK_FUNC(sub_82656BB8);
PPC_FUNC_IMPL(__imp__sub_82656BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r10,1258(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1258, ctx.r10.u8);
	// stb r9,164(r3)
	PPC_STORE_U8(ctx.r3.u32 + 164, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82656BD8"))) PPC_WEAK_FUNC(sub_82656BD8);
PPC_FUNC_IMPL(__imp__sub_82656BD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82656BEC"))) PPC_WEAK_FUNC(sub_82656BEC);
PPC_FUNC_IMPL(__imp__sub_82656BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82656BF0"))) PPC_WEAK_FUNC(sub_82656BF0);
PPC_FUNC_IMPL(__imp__sub_82656BF0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82656BF8"))) PPC_WEAK_FUNC(sub_82656BF8);
PPC_FUNC_IMPL(__imp__sub_82656BF8) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82656C00"))) PPC_WEAK_FUNC(sub_82656C00);
PPC_FUNC_IMPL(__imp__sub_82656C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// add r9,r11,r6
	ctx.r9.u64 = r11.u64 + ctx.r6.u64;
	// rlwinm r8,r9,5,0,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v63,r8,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82656C20"))) PPC_WEAK_FUNC(sub_82656C20);
PPC_FUNC_IMPL(__imp__sub_82656C20) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82656c6c
	if (cr6.eq) goto loc_82656C6C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82656C54:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82656c54
	if (!cr6.eq) goto loc_82656C54;
loc_82656C6C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82656C80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82656cc4
	if (!cr6.gt) goto loc_82656CC4;
	// addi r9,r31,4
	ctx.r9.s64 = r31.s64 + 4;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82656C94:
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwzx r3,r5,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// addi r4,r7,1
	ctx.r4.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// sth r4,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r4.u16);
	// stwx r3,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r3.u32);
	// bne 0x82656c94
	if (!cr0.eq) goto loc_82656C94;
loc_82656CC4:
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

__attribute__((alias("__imp__sub_82656CDC"))) PPC_WEAK_FUNC(sub_82656CDC);
PPC_FUNC_IMPL(__imp__sub_82656CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82656CE0"))) PPC_WEAK_FUNC(sub_82656CE0);
PPC_FUNC_IMPL(__imp__sub_82656CE0) {
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
	ctx.lr = 0x82656CE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82656d20
	if (cr6.eq) goto loc_82656D20;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r29,4
	r11.s64 = r29.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82656D08:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82656d08
	if (!cr6.eq) goto loc_82656D08;
loc_82656D20:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82656D2C;
	sub_8238EC00(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r26,-1
	r26.s64 = -1;
	// ori r31,r11,6256
	r31.u64 = r11.u64 | 6256;
	// lis r25,-32121
	r25.s64 = -2105081856;
loc_82656D48:
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// lbzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r31.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82656db0
	if (cr6.eq) goto loc_82656DB0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x82656D74;
	sub_821C9790(ctx, base);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82389668
	ctx.lr = 0x82656D88;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82656db0
	if (cr6.eq) goto loc_82656DB0;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addi r10,r29,4
	ctx.r10.s64 = r29.s64 + 4;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,8(r29)
	PPC_STORE_U16(r29.u32 + 8, ctx.r8.u16);
	// stwx r28,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r28.u32);
loc_82656DB0:
	// addi r30,r30,64
	r30.s64 = r30.s64 + 64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r30,6400
	cr6.compare<int32_t>(r30.s32, 6400, xer);
	// blt cr6,0x82656d48
	if (cr6.lt) goto loc_82656D48;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82656DC8"))) PPC_WEAK_FUNC(sub_82656DC8);
PPC_FUNC_IMPL(__imp__sub_82656DC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// cmplwi cr6,r5,5
	cr6.compare<uint32_t>(ctx.r5.u32, 5, xer);
	// bgt cr6,0x82656f88
	if (cr6.gt) goto loc_82656F88;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,28164
	r12.s64 = r12.s64 + 28164;
	// rlwinm r0,r5,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r5.u64) {
	case 0:
		goto loc_82656E1C;
	case 1:
		goto loc_82656E48;
	case 2:
		goto loc_82656F58;
	case 3:
		goto loc_82656F64;
	case 4:
		goto loc_82656F70;
	case 5:
		goto loc_82656F7C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,28188(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28188);
	// lwz r19,28232(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28232);
	// lwz r19,28504(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28504);
	// lwz r19,28516(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28516);
	// lwz r19,28528(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28528);
	// lwz r19,28540(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28540);
loc_82656E1C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,6256
	ctx.r3.s64 = ctx.r3.s64 + 6256;
	// b 0x82656f90
	goto loc_82656F90;
loc_82656E48:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82656E5C;
	sub_8238EC00(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// rlwinm r10,r6,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// addis r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 65536;
	// addi r4,r4,6256
	ctx.r4.s64 = ctx.r4.s64 + 6256;
	// bl 0x823895f8
	ctx.lr = 0x82656E8C;
	sub_823895F8(ctx, base);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r30,0
	r30.s64 = 0;
	// addi r4,r3,-18740
	ctx.r4.s64 = ctx.r3.s64 + -18740;
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82656EB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82656ec0
	if (cr6.eq) goto loc_82656EC0;
	// li r30,8
	r30.s64 = 8;
loc_82656EC0:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,-18748
	ctx.r4.s64 = r11.s64 + -18748;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82656EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82656eec
	if (cr6.eq) goto loc_82656EEC;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
loc_82656EEC:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,-18732
	ctx.r4.s64 = r11.s64 + -18732;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82656F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82656f18
	if (cr6.eq) goto loc_82656F18;
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
loc_82656F18:
	// lwz r3,-12440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12440);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r11,-18756
	ctx.r4.s64 = r11.s64 + -18756;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82656F38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82656f44
	if (cr6.eq) goto loc_82656F44;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_82656F44:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,28128
	ctx.r9.s64 = r11.s64 + 28128;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x82656f90
	goto loc_82656F90;
loc_82656F58:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4308
	ctx.r3.s64 = r11.s64 + -4308;
	// b 0x82656f90
	goto loc_82656F90;
loc_82656F64:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4328
	ctx.r3.s64 = r11.s64 + -4328;
	// b 0x82656f90
	goto loc_82656F90;
loc_82656F70:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4340
	ctx.r3.s64 = r11.s64 + -4340;
	// b 0x82656f90
	goto loc_82656F90;
loc_82656F7C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4360
	ctx.r3.s64 = r11.s64 + -4360;
	// b 0x82656f90
	goto loc_82656F90;
loc_82656F88:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-4368
	ctx.r3.s64 = r11.s64 + -4368;
loc_82656F90:
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

__attribute__((alias("__imp__sub_82656FA8"))) PPC_WEAK_FUNC(sub_82656FA8);
PPC_FUNC_IMPL(__imp__sub_82656FA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82656fd8
	if (cr6.eq) goto loc_82656FD8;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82656FC0:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82656fc0
	if (!cr6.eq) goto loc_82656FC0;
loc_82656FD8:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
loc_82656FE4:
	// lwz r11,-6148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -6148);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lbz r10,13027(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 13027);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82657000
	if (!cr6.eq) goto loc_82657000;
	// lwz r11,11984(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11984);
	// b 0x82657004
	goto loc_82657004;
loc_82657000:
	// lbz r11,13026(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13026);
loc_82657004:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82657030
	if (!cr6.gt) goto loc_82657030;
	// lhz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r4,r7,-2
	ctx.r4.s64 = ctx.r7.s64 + -2;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r10.u16);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
loc_82657030:
	// lwz r11,-6148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -6148);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lbz r10,14083(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14083);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x8265704c
	if (!cr6.eq) goto loc_8265704C;
	// lwz r11,13040(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 13040);
	// b 0x82657050
	goto loc_82657050;
loc_8265704C:
	// lbz r11,14082(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 14082);
loc_82657050:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8265707c
	if (!cr6.gt) goto loc_8265707C;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r4,r7,-1
	ctx.r4.s64 = ctx.r7.s64 + -1;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
loc_8265707C:
	// lwz r11,-6148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -6148);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lbz r10,15139(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15139);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82657098
	if (!cr6.eq) goto loc_82657098;
	// lwz r11,14096(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14096);
	// b 0x8265709c
	goto loc_8265709C;
loc_82657098:
	// lbz r11,15138(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 15138);
loc_8265709C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826570c4
	if (!cr6.gt) goto loc_826570C4;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
	// stwx r7,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u32);
loc_826570C4:
	// lwz r11,-6148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -6148);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lbz r10,16195(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 16195);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x826570e0
	if (!cr6.eq) goto loc_826570E0;
	// lwz r11,15152(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 15152);
	// b 0x826570e4
	goto loc_826570E4;
loc_826570E0:
	// lbz r11,16194(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 16194);
loc_826570E4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82657110
	if (!cr6.gt) goto loc_82657110;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r4,r7,1
	ctx.r4.s64 = ctx.r7.s64 + 1;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
loc_82657110:
	// lwz r11,-6148(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -6148);
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// lbz r10,17251(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17251);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x8265712c
	if (!cr6.eq) goto loc_8265712C;
	// lwz r11,16208(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16208);
	// b 0x82657130
	goto loc_82657130;
loc_8265712C:
	// lbz r11,17250(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 17250);
loc_82657130:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8265715c
	if (!cr6.gt) goto loc_8265715C;
	// lhz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r4,r7,2
	ctx.r4.s64 = ctx.r7.s64 + 2;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, ctx.r8.u16);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
loc_8265715C:
	// addi r7,r7,5
	ctx.r7.s64 = ctx.r7.s64 + 5;
	// addi r6,r6,5280
	ctx.r6.s64 = ctx.r6.s64 + 5280;
	// addi r11,r7,-2
	r11.s64 = ctx.r7.s64 + -2;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// blt cr6,0x82656fe4
	if (cr6.lt) goto loc_82656FE4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82657174"))) PPC_WEAK_FUNC(sub_82657174);
PPC_FUNC_IMPL(__imp__sub_82657174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82657178"))) PPC_WEAK_FUNC(sub_82657178);
PPC_FUNC_IMPL(__imp__sub_82657178) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826571b8
	if (cr6.eq) goto loc_826571B8;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826bf4b0
	ctx.lr = 0x826571A8;
	sub_826BF4B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826571b8
	if (!cr6.eq) goto loc_826571B8;
	// li r31,1
	r31.s64 = 1;
loc_826571B8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
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
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826571D8"))) PPC_WEAK_FUNC(sub_826571D8);
PPC_FUNC_IMPL(__imp__sub_826571D8) {
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
	ctx.lr = 0x826571E0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265721c
	if (cr6.eq) goto loc_8265721C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82657204:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82657204
	if (!cr6.eq) goto loc_82657204;
loc_8265721C:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,17232
	ctx.r10.s64 = ctx.r10.s64 + 17232;
	// lwz r19,32(r9)
	r19.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
loc_82657230:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82657254
	if (cr6.eq) goto loc_82657254;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82657230
	if (cr6.eq) goto loc_82657230;
loc_82657254:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82657344
	if (!cr6.eq) goto loc_82657344;
	// bl 0x8238e748
	ctx.lr = 0x82657260;
	sub_8238E748(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x826575b0
	if (!cr6.gt) goto loc_826575B0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r26,0
	r26.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r25,r11,-28304
	r25.s64 = r11.s64 + -28304;
loc_82657284:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,-10020(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -10020);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r4,r9,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// beq cr6,0x826572b8
	if (cr6.eq) goto loc_826572B8;
	// bl 0x826bf4b0
	ctx.lr = 0x826572A8;
	sub_826BF4B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826572b8
	if (!cr6.eq) goto loc_826572B8;
	// li r30,1
	r30.s64 = 1;
loc_826572B8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657328
	if (!cr6.eq) goto loc_82657328;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// lwz r9,144(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82657328
	if (cr6.eq) goto loc_82657328;
	// lbz r11,96(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657300
	if (cr6.eq) goto loc_82657300;
	// bl 0x82387e18
	ctx.lr = 0x826572F4;
	sub_82387E18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657328
	if (cr6.eq) goto loc_82657328;
loc_82657300:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// bne cr6,0x82657328
	if (!cr6.eq) goto loc_82657328;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
loc_82657328:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r26,r26,160
	r26.s64 = r26.s64 + 160;
	// cmpw cr6,r29,r19
	cr6.compare<int32_t>(r29.s32, r19.s32, xer);
	// blt cr6,0x82657284
	if (cr6.lt) goto loc_82657284;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_82657344:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-7972
	ctx.r10.s64 = ctx.r10.s64 + -7972;
loc_82657350:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82657374
	if (cr6.eq) goto loc_82657374;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82657350
	if (cr6.eq) goto loc_82657350;
loc_82657374:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82657464
	if (!cr6.eq) goto loc_82657464;
	// bl 0x8238e6d8
	ctx.lr = 0x82657380;
	sub_8238E6D8(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x826575b0
	if (!cr6.gt) goto loc_826575B0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r26,0
	r26.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r25,r11,-28304
	r25.s64 = r11.s64 + -28304;
loc_826573A4:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,-10020(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -10020);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r4,r9,r28
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r28.u32);
	// beq cr6,0x826573d8
	if (cr6.eq) goto loc_826573D8;
	// bl 0x826bf4b0
	ctx.lr = 0x826573C8;
	sub_826BF4B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826573d8
	if (!cr6.eq) goto loc_826573D8;
	// li r30,1
	r30.s64 = 1;
loc_826573D8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657448
	if (!cr6.eq) goto loc_82657448;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// add r30,r11,r26
	r30.u64 = r11.u64 + r26.u64;
	// lwz r9,144(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82657448
	if (cr6.eq) goto loc_82657448;
	// lbz r11,96(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657420
	if (cr6.eq) goto loc_82657420;
	// bl 0x82387e18
	ctx.lr = 0x82657414;
	sub_82387E18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657448
	if (cr6.eq) goto loc_82657448;
loc_82657420:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// bne cr6,0x82657448
	if (!cr6.eq) goto loc_82657448;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
loc_82657448:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r26,r26,160
	r26.s64 = r26.s64 + 160;
	// cmpw cr6,r29,r19
	cr6.compare<int32_t>(r29.s32, r19.s32, xer);
	// blt cr6,0x826573a4
	if (cr6.lt) goto loc_826573A4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_82657464:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,18072
	ctx.r10.s64 = ctx.r10.s64 + 18072;
loc_82657470:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82657494
	if (cr6.eq) goto loc_82657494;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82657470
	if (cr6.eq) goto loc_82657470;
loc_82657494:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826575b0
	if (!cr6.eq) goto loc_826575B0;
	// bl 0x8238e748
	ctx.lr = 0x826574A0;
	sub_8238E748(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x826575b0
	if (!cr6.gt) goto loc_826575B0;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r26,0
	r26.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// li r22,114
	r22.s64 = 114;
	// lis r23,-32115
	r23.s64 = -2104688640;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r21,r9,-19152
	r21.s64 = ctx.r9.s64 + -19152;
	// addi r25,r10,5392
	r25.s64 = ctx.r10.s64 + 5392;
	// addi r24,r11,-28304
	r24.s64 = r11.s64 + -28304;
loc_826574DC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,-10020(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -10020);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r4,r9,r27
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	// beq cr6,0x82657510
	if (cr6.eq) goto loc_82657510;
	// bl 0x826bf4b0
	ctx.lr = 0x82657500;
	sub_826BF4B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657510
	if (!cr6.eq) goto loc_82657510;
	// li r30,1
	r30.s64 = 1;
loc_82657510:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265759c
	if (!cr6.eq) goto loc_8265759C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265759c
	if (cr6.eq) goto loc_8265759C;
	// lbz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265759c
	if (!cr6.eq) goto loc_8265759C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpw cr6,r10,r20
	cr6.compare<int32_t>(ctx.r10.s32, r20.s32, xer);
	// bne cr6,0x8265759c
	if (!cr6.eq) goto loc_8265759C;
	// lhz r11,16(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// stb r22,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r22.u8);
	// lwz r3,-12440(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -12440);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// bl 0x8238dd80
	ctx.lr = 0x82657570;
	sub_8238DD80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82657598
	if (cr6.eq) goto loc_82657598;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// stwx r28,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r28.u32);
loc_82657598:
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
loc_8265759C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r26,r26,160
	r26.s64 = r26.s64 + 160;
	// cmpw cr6,r28,r19
	cr6.compare<int32_t>(r28.s32, r19.s32, xer);
	// blt cr6,0x826574dc
	if (cr6.lt) goto loc_826574DC;
loc_826575B0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_826575B8"))) PPC_WEAK_FUNC(sub_826575B8);
PPC_FUNC_IMPL(__imp__sub_826575B8) {
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
	ctx.lr = 0x826575C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r29,40
	r29.s64 = 40;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// addis r27,r11,3
	r27.s64 = r11.s64 + 196608;
	// addis r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 65536;
	// addi r27,r27,-11360
	r27.s64 = r27.s64 + -11360;
	// addi r4,r4,6256
	ctx.r4.s64 = ctx.r4.s64 + 6256;
	// bl 0x82389800
	ctx.lr = 0x8265760C;
	sub_82389800(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82657620
	if (cr6.eq) goto loc_82657620;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r29,r11,40
	xer.ca = r11.u32 > 4294967255;
	r29.s64 = r11.s64 + 40;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8265766c
	if (cr0.eq) goto loc_8265766C;
loc_82657620:
	// lbz r11,962(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 962);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265766c
	if (!cr6.eq) goto loc_8265766C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82657650;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x823896c0
	ctx.lr = 0x8265765C;
	sub_823896C0(ctx, base);
	// bl 0x8238eb20
	ctx.lr = 0x82657660;
	sub_8238EB20(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x82657670
	if (cr6.eq) goto loc_82657670;
loc_8265766C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82657670:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82657678"))) PPC_WEAK_FUNC(sub_82657678);
PPC_FUNC_IMPL(__imp__sub_82657678) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82657680;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r31,976
	ctx.r10.s64 = r31.s64 + 976;
	// addi r26,r31,1392
	r26.s64 = r31.s64 + 1392;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r27,0
	r27.s64 = 0;
	// stfs f0,1392(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1392, temp.u32);
	// stfs f0,1396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1396, temp.u32);
	// stfs f0,1400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1400, temp.u32);
	// lwz r9,864(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x82657758
	if (!cr6.eq) goto loc_82657758;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r28,1
	r28.s64 = 1;
	// bl 0x82631f88
	ctx.lr = 0x826576C4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826576d4
	if (cr6.lt) goto loc_826576D4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826576D4:
	// lwz r10,980(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 980);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,-6148(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -6148);
	// mulli r10,r7,1056
	ctx.r10.s64 = ctx.r7.s64 * 1056;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r11,11984
	r30.s64 = r11.s64 + 11984;
	// lbz r6,13027(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 13027);
	// cmplwi cr6,r6,205
	cr6.compare<uint32_t>(ctx.r6.u32, 205, xer);
	// bne cr6,0x82657708
	if (!cr6.eq) goto loc_82657708;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x8265770c
	goto loc_8265770C;
loc_82657708:
	// lbz r5,1042(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 1042);
loc_8265770C:
	// lwz r11,1360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1360);
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265772C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,1043(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1043);
	// cmplwi cr6,r9,205
	cr6.compare<uint32_t>(ctx.r9.u32, 205, xer);
	// bne cr6,0x82657740
	if (!cr6.eq) goto loc_82657740;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x82657744
	goto loc_82657744;
loc_82657740:
	// lbz r11,1042(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1042);
loc_82657744:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826578a0
	if (!cr6.gt) goto loc_826578A0;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826578a0
	goto loc_826578A0;
loc_82657758:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x82657764;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82657774
	if (cr6.lt) goto loc_82657774;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82657774:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826578a0
	if (cr6.lt) goto loc_826578A0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82657788;
	sub_8238EC00(ctx, base);
	// lwz r29,864(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8265779C;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826577B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823895f8
	ctx.lr = 0x826577C4;
	sub_823895F8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,44(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r9
	r30.u64 = r11.u64 + ctx.r9.u64;
	// addi r4,r30,84
	ctx.r4.s64 = r30.s64 + 84;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r7,r11,-3
	ctx.r7.s64 = r11.s64 + -3;
	// addi r6,r11,-2
	ctx.r6.s64 = r11.s64 + -2;
	// cntlzw r5,r7
	ctx.r5.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cntlzw r3,r6
	ctx.r3.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r10,r5,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// rlwinm r27,r3,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r28,r10,1
	r28.u64 = ctx.r10.u64 ^ 1;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82657830
	if (cr6.lt) goto loc_82657830;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x82657830
	if (cr6.gt) goto loc_82657830;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r10,248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 248, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_82657830:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// addi r3,r31,1376
	ctx.r3.s64 = r31.s64 + 1376;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657864
	if (cr6.eq) goto loc_82657864;
	// lhz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,1376(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1376);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r5,r11,-16
	ctx.r5.s64 = r11.s64 + -16;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82657874
	goto loc_82657874;
loc_82657864:
	// lwz r11,1376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1376);
	// addi r5,r30,48
	ctx.r5.s64 = r30.s64 + 48;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82657874:
	// bctrl 
	ctx.lr = 0x82657878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,80(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826578a0
	if (cr6.eq) goto loc_826578A0;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r26)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stfs f13,4(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 4, temp.u32);
	// stfs f0,8(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 8, temp.u32);
loc_826578A0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,1388(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r27,252(r11)
	PPC_STORE_U8(r11.u32 + 252, r27.u8);
	// stb r28,732(r11)
	PPC_STORE_U8(r11.u32 + 732, r28.u8);
	// stw r10,248(r11)
	PPC_STORE_U32(r11.u32 + 248, ctx.r10.u32);
	// bl 0x82387a18
	ctx.lr = 0x826578C0;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82657918
	if (cr6.eq) goto loc_82657918;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x826578D4;
	sub_822A5948(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x826578D8;
	sub_822A8108(ctx, base);
	// addi r4,r31,1232
	ctx.r4.s64 = r31.s64 + 1232;
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// b 0x82657a04
	goto loc_82657A04;
loc_82657918:
	// lwz r3,1388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265792C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// blt cr6,0x826579b4
	if (cr6.lt) goto loc_826579B4;
	// lwz r4,1388(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,1388(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1388);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82657978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// vor128 v57,v58,v58
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r5,r6,-31616
	ctx.r5.s64 = ctx.r6.s64 + -31616;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x826579B0;
	sub_82202EC0(ctx, base);
	// b 0x826579f4
	goto loc_826579F4;
loc_826579B4:
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// vupkd3d128 v53,v54,4
	temp.f32 = 3.0f;
	temp.s32 += v54.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v54.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v53 = vTemp;
	// li r8,1280
	ctx.r8.s64 = 1280;
	// vpermwi128 v52,v53,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x15));
	// vpermwi128 v51,v53,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x45));
	// vpermwi128 v50,v53,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x51));
	// stvx128 v52,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r26
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826579F4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
loc_82657A04:
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r3,3408
	ctx.r3.s64 = ctx.r3.s64 + 3408;
	// bl 0x822249b8
	ctx.lr = 0x82657A14;
	sub_822249B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82657A20"))) PPC_WEAK_FUNC(sub_82657A20);
PPC_FUNC_IMPL(__imp__sub_82657A20) {
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
	ctx.lr = 0x82657A28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-4116
	ctx.r4.s64 = ctx.r9.s64 + -4116;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,340(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// addis r27,r7,3
	r27.s64 = ctx.r7.s64 + 196608;
	// addi r27,r27,-11360
	r27.s64 = r27.s64 + -11360;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82657A5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,648(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82657A78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,-5016
	ctx.r3.s64 = ctx.r4.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x82657A84;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82657c1c
	if (cr6.eq) goto loc_82657C1C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82657AAC;
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
	ctx.lr = 0x82657AC0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82657AC8;
	sub_824E70F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// beq cr6,0x82657af8
	if (cr6.eq) goto loc_82657AF8;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r25,r11,28900
	r25.s64 = r11.s64 + 28900;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82657AF0;
	sub_8262FFE0(ctx, base);
	// stb r28,5008(r31)
	PPC_STORE_U8(r31.u32 + 5008, r28.u8);
	// b 0x82657b10
	goto loc_82657B10;
loc_82657AF8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r25,r11,28572
	r25.s64 = r11.s64 + 28572;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82657B0C;
	sub_8262FFE0(ctx, base);
	// stb r29,5008(r31)
	PPC_STORE_U8(r31.u32 + 5008, r29.u8);
loc_82657B10:
	// stw r25,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r25.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,28004
	ctx.r4.s64 = r11.s64 + 28004;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826347f0
	ctx.lr = 0x82657B28;
	sub_826347F0(ctx, base);
	// stb r28,940(r31)
	PPC_STORE_U8(r31.u32 + 940, r28.u8);
	// stb r28,964(r31)
	PPC_STORE_U8(r31.u32 + 964, r28.u8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x82657B40;
	sub_821F9FB8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r25,r9,2612
	r25.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r24,56(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82657B5C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82657B6C;
	sub_825ED480(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r8,-13268
	ctx.r3.s64 = ctx.r8.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x82657B84;
	sub_821C9790(ctx, base);
	// li r7,7
	ctx.r7.s64 = 7;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82657BA0;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82657BB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82657BD0;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82657BE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r6,1072
	ctx.r4.s64 = ctx.r6.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x82657BFC;
	sub_825EE0E0(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-13284
	ctx.r4.s64 = ctx.r4.s64 + -13284;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82722678
	ctx.lr = 0x82657C18;
	sub_82722678(ctx, base);
	// b 0x82657c3c
	goto loc_82657C3C;
loc_82657C1C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28004
	ctx.r4.s64 = r11.s64 + 28004;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826347f0
	ctx.lr = 0x82657C30;
	sub_826347F0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// stb r29,940(r31)
	PPC_STORE_U8(r31.u32 + 940, r29.u8);
	// stb r29,964(r31)
	PPC_STORE_U8(r31.u32 + 964, r29.u8);
loc_82657C3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656048
	ctx.lr = 0x82657C44;
	sub_82656048(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82654ac8
	ctx.lr = 0x82657C4C;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657c7c
	if (!cr6.eq) goto loc_82657C7C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82654b60
	ctx.lr = 0x82657C60;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657c7c
	if (!cr6.eq) goto loc_82657C7C;
	// lbz r11,960(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657c7c
	if (!cr6.eq) goto loc_82657C7C;
	// mr r29,r28
	r29.u64 = r28.u64;
loc_82657C7C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657cb8
	if (cr6.eq) goto loc_82657CB8;
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x82657C90;
	sub_82631F88(ctx, base);
	// lwz r11,856(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82657ca0
	if (cr6.lt) goto loc_82657CA0;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82657CA0:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x82657ccc
	if (!cr6.gt) goto loc_82657CCC;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r10,r31,976
	ctx.r10.s64 = r31.s64 + 976;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82657ccc
	if (cr6.eq) goto loc_82657CCC;
loc_82657CB8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,27988
	ctx.r4.s64 = r11.s64 + 27988;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82657CCC;
	sub_8262FFE0(ctx, base);
loc_82657CCC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x82657CDC;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82657CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82657D00"))) PPC_WEAK_FUNC(sub_82657D00);
PPC_FUNC_IMPL(__imp__sub_82657D00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,-10236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r11,248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 248, r11.u32);
	// stb r11,1216(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1216, r11.u8);
	// stb r11,5008(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5008, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82657D20"))) PPC_WEAK_FUNC(sub_82657D20);
PPC_FUNC_IMPL(__imp__sub_82657D20) {
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
	ctx.lr = 0x82657D28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657D40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82657e70
	if (cr6.eq) goto loc_82657E70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82632f78
	ctx.lr = 0x82657D54;
	sub_82632F78(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x82657D60;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82657D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82657e70
	if (cr6.eq) goto loc_82657E70;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82657D90;
	sub_821F9FB8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82657DAC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82657DBC;
	sub_825ED480(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r8,-13268
	ctx.r3.s64 = ctx.r8.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x82657DD4;
	sub_821C9790(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82657DF8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657E10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,15
	ctx.r9.s64 = 15;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82657E28;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82657E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r4,1072
	ctx.r4.s64 = ctx.r4.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x82657E54;
	sub_825EE0E0(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x82657E70;
	sub_82722678(ctx, base);
loc_82657E70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82657E78"))) PPC_WEAK_FUNC(sub_82657E78);
PPC_FUNC_IMPL(__imp__sub_82657E78) {
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
	ctx.lr = 0x82657E80;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r11,-12776
	ctx.r4.s64 = r11.s64 + -12776;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r30,r10,-7660
	r30.s64 = ctx.r10.s64 + -7660;
	// addi r29,r9,-22108
	r29.s64 = ctx.r9.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82657EB4;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82657EC8;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r25,r8,1
	r25.s64 = ctx.r8.s64 + 65536;
	// addi r25,r25,16256
	r25.s64 = r25.s64 + 16256;
	// beq cr6,0x82657efc
	if (cr6.eq) goto loc_82657EFC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,27964(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27964);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82657efc
	if (cr6.eq) goto loc_82657EFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82657EFC:
	// lwz r11,944(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 944);
	// addi r30,r27,944
	r30.s64 = r27.s64 + 944;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82657F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8265820c
	if (cr6.eq) goto loc_8265820C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x82657F2C;
	sub_821F9FB8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r24,56(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r28,4304(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82631f88
	ctx.lr = 0x82657F48;
	sub_82631F88(ctx, base);
	// lwz r11,856(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82657f58
	if (cr6.lt) goto loc_82657F58;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82657F58:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82657F74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,961(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 961);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82658040
	if (cr6.eq) goto loc_82658040;
	// lbz r11,17(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657fa0
	if (cr6.eq) goto loc_82657FA0;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82657fa4
	if (cr6.eq) goto loc_82657FA4;
loc_82657FA0:
	// li r11,0
	r11.s64 = 0;
loc_82657FA4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82657fc8
	if (cr6.eq) goto loc_82657FC8;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82654ac8
	ctx.lr = 0x82657FB8;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82657fcc
	if (!cr6.eq) goto loc_82657FCC;
loc_82657FC8:
	// li r29,-1
	r29.s64 = -1;
loc_82657FCC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8238e748
	ctx.lr = 0x82657FD4;
	sub_8238E748(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r30,r29
	r30.u64 = r29.u64;
	// bl 0x82654ac8
	ctx.lr = 0x82657FE4;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// beq cr6,0x82658014
	if (cr6.eq) goto loc_82658014;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x82658010
	if (cr6.lt) goto loc_82658010;
	// cmpwi cr6,r31,13
	cr6.compare<int32_t>(r31.s32, 13, xer);
	// li r30,2
	r30.s64 = 2;
	// ble cr6,0x82658014
	if (!cr6.gt) goto loc_82658014;
loc_82658010:
	// li r30,1
	r30.s64 = 1;
loc_82658014:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// stw r11,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, r11.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r29,984(r9)
	PPC_STORE_U32(ctx.r9.u32 + 984, r29.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r30,528(r8)
	PPC_STORE_U32(ctx.r8.u32 + 528, r30.u32);
	// bne cr6,0x82658038
	if (!cr6.eq) goto loc_82658038;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82658038:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r31,1136(r11)
	PPC_STORE_U32(r11.u32 + 1136, r31.u32);
loc_82658040:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r10,-4384
	ctx.r10.s64 = ctx.r10.s64 + -4384;
loc_8265804C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82658070
	if (cr6.eq) goto loc_82658070;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8265804c
	if (cr6.eq) goto loc_8265804C;
loc_82658070:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826580ac
	if (!cr6.eq) goto loc_826580AC;
	// addis r31,r25,2
	r31.s64 = r25.s64 + 131072;
	// addi r31,r31,-32640
	r31.s64 = r31.s64 + -32640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654cb8
	ctx.lr = 0x82658088;
	sub_82654CB8(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r10,r11,33760
	ctx.r10.u64 = r11.u64 | 33760;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r25,r10
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8265816c
	goto loc_8265816C;
loc_826580AC:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r10,-4396
	ctx.r10.s64 = ctx.r10.s64 + -4396;
loc_826580B8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826580dc
	if (cr6.eq) goto loc_826580DC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826580b8
	if (cr6.eq) goto loc_826580B8;
loc_826580DC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82658118
	if (!cr6.eq) goto loc_82658118;
	// addis r31,r25,2
	r31.s64 = r25.s64 + 131072;
	// addi r31,r31,-32640
	r31.s64 = r31.s64 + -32640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654d40
	ctx.lr = 0x826580F4;
	sub_82654D40(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r10,r11,33760
	ctx.r10.u64 = r11.u64 | 33760;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r25,r10
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8265816c
	goto loc_8265816C;
loc_82658118:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82654ac8
	ctx.lr = 0x82658120;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826581d4
	if (!cr6.eq) goto loc_826581D4;
	// lbz r11,960(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826581d4
	if (!cr6.eq) goto loc_826581D4;
	// addis r31,r25,2
	r31.s64 = r25.s64 + 131072;
	// addi r31,r31,-32640
	r31.s64 = r31.s64 + -32640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654c68
	ctx.lr = 0x82658148;
	sub_82654C68(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// ori r9,r11,33760
	ctx.r9.u64 = r11.u64 | 33760;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r10,17232
	ctx.r4.s64 = ctx.r10.s64 + 17232;
	// lwzx r3,r25,r9
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + ctx.r9.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_8265816C:
	// bctrl 
	ctx.lr = 0x82658170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32155
	ctx.r9.s64 = -2107310080;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r9,20192
	ctx.r4.s64 = ctx.r9.s64 + 20192;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c2f90
	ctx.lr = 0x826581A0;
	sub_821C2F90(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,728(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 728);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ld r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// ld r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// rldicr r7,r10,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826581C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_826581D4:
	// addis r31,r25,1
	r31.s64 = r25.s64 + 65536;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r31,r31,19760
	r31.s64 = r31.s64 + 19760;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826581F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265820C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265820C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82658218"))) PPC_WEAK_FUNC(sub_82658218);
PPC_FUNC_IMPL(__imp__sub_82658218) {
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
	ctx.lr = 0x82658220;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,3056(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3056);
	// addi r11,r3,848
	r11.s64 = ctx.r3.s64 + 848;
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// blt cr6,0x82658394
	if (cr6.lt) goto loc_82658394;
	// bne cr6,0x826583b4
	if (!cr6.eq) goto loc_826583B4;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r7,r3,2848
	ctx.r7.s64 = ctx.r3.s64 + 2848;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r3,5856
	ctx.r6.s64 = ctx.r3.s64 + 5856;
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r5,r3,6096
	ctx.r5.s64 = ctx.r3.s64 + 6096;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// addi r4,r3,6336
	ctx.r4.s64 = ctx.r3.s64 + 6336;
	// addi r31,r3,6576
	r31.s64 = ctx.r3.s64 + 6576;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// addi r7,r3,6816
	ctx.r7.s64 = ctx.r3.s64 + 6816;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r3,7056
	r30.s64 = ctx.r3.s64 + 7056;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r29,r10,1
	r29.s64 = ctx.r10.s64 + 1;
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// addi r29,r3,7296
	r29.s64 = ctx.r3.s64 + 7296;
	// sth r10,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r10.u16);
	// addi r28,r3,7536
	r28.s64 = ctx.r3.s64 + 7536;
	// addi r27,r3,7776
	r27.s64 = ctx.r3.s64 + 7776;
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r6,r3,8016
	ctx.r6.s64 = ctx.r3.s64 + 8016;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r3,8256
	ctx.r3.s64 = ctx.r3.s64 + 8256;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r26,r10,1
	r26.s64 = ctx.r10.s64 + 1;
	// sth r26,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r26.u16);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// stwx r31,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r31.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r30.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// stwx r29,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r29.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// stwx r28,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r28.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// stwx r27,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r27.u32);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r3,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82658394:
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r7,r3,2848
	ctx.r7.s64 = ctx.r3.s64 + 2848;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// bl 0x826554a0
	ctx.lr = 0x826583B4;
	sub_826554A0(ctx, base);
loc_826583B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826583BC"))) PPC_WEAK_FUNC(sub_826583BC);
PPC_FUNC_IMPL(__imp__sub_826583BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826583C0"))) PPC_WEAK_FUNC(sub_826583C0);
PPC_FUNC_IMPL(__imp__sub_826583C0) {
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
	ctx.lr = 0x826583C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,-16384
	ctx.r3.s64 = ctx.r3.s64 + -16384;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826583F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-27856(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82658404;
	sub_8238EC00(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// ori r6,r7,38880
	ctx.r6.u64 = ctx.r7.u64 | 38880;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// addis r28,r5,1
	r28.s64 = ctx.r5.s64 + 65536;
	// addi r28,r28,16256
	r28.s64 = r28.s64 + 16256;
	// lwz r4,36(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lbzx r3,r28,r6
	ctx.r3.u64 = PPC_LOAD_U8(r28.u32 + ctx.r6.u32);
	// lwz r26,28(r4)
	r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82658458
	if (!cr6.eq) goto loc_82658458;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82658464
	if (!cr6.eq) goto loc_82658464;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,8536(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8536);
	// bl 0x82388c60
	ctx.lr = 0x82658450;
	sub_82388C60(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8265845c
	goto loc_8265845C;
loc_82658458:
	// li r26,16
	r26.s64 = 16;
loc_8265845C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82658478
	if (cr6.eq) goto loc_82658478;
loc_82658464:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82389800
	ctx.lr = 0x82658470;
	sub_82389800(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x8265847c
	goto loc_8265847C;
loc_82658478:
	// li r29,0
	r29.s64 = 0;
loc_8265847C:
	// addis r11,r28,2
	r11.s64 = r28.s64 + 131072;
	// addi r11,r11,-32640
	r11.s64 = r11.s64 + -32640;
	// addi r10,r11,976
	ctx.r10.s64 = r11.s64 + 976;
	// lwz r9,864(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 864);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826584e8
	if (!cr6.eq) goto loc_826584E8;
	// lwz r10,1608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1608);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r31,1392
	r11.s64 = r31.s64 + 1392;
	// stw r9,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, ctx.r9.u32);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x826584b8
	if (cr6.eq) goto loc_826584B8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x826584B8;
	sub_821C3048(ctx, base);
loc_826584B8:
	// lwz r10,1352(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1352);
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r11,r31,1136
	r11.s64 = r31.s64 + 1136;
	// stw r9,1352(r31)
	PPC_STORE_U32(r31.u32 + 1352, ctx.r9.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// beq cr6,0x826584dc
	if (cr6.eq) goto loc_826584DC;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x826584DC;
	sub_821C3048(ctx, base);
loc_826584DC:
	// li r11,4
	r11.s64 = 4;
	// stw r11,1348(r31)
	PPC_STORE_U32(r31.u32 + 1348, r11.u32);
	// b 0x82658594
	goto loc_82658594;
loc_826584E8:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826584fc
	if (cr6.eq) goto loc_826584FC;
	// lbz r11,19(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 19);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x82658500
	goto loc_82658500;
loc_826584FC:
	// li r11,2
	r11.s64 = 2;
loc_82658500:
	// lwz r10,1608(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1608);
	// addi r30,r31,1392
	r30.s64 = r31.s64 + 1392;
	// stw r11,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, r11.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82658520
	if (cr6.eq) goto loc_82658520;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,228
	ctx.r3.s64 = r30.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658520;
	sub_821C3048(ctx, base);
loc_82658520:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8265853c
	if (cr6.eq) goto loc_8265853C;
	// lbz r11,19(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 19);
	// li r4,1
	ctx.r4.s64 = 1;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82658540
	if (cr6.gt) goto loc_82658540;
loc_8265853C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82658540:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658554;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82658594
	if (cr6.eq) goto loc_82658594;
	// lbz r11,18(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 18);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// stw r11,1348(r31)
	PPC_STORE_U32(r31.u32 + 1348, r11.u32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// ble cr6,0x82658574
	if (!cr6.gt) goto loc_82658574;
	// li r11,3
	r11.s64 = 3;
loc_82658574:
	// lwz r9,1352(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1352);
	// addi r10,r31,1136
	ctx.r10.s64 = r31.s64 + 1136;
	// stw r11,1352(r31)
	PPC_STORE_U32(r31.u32 + 1352, r11.u32);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// beq cr6,0x82658594
	if (cr6.eq) goto loc_82658594;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,228
	ctx.r3.s64 = ctx.r10.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658594;
	sub_821C3048(ctx, base);
loc_82658594:
	// lwz r11,1648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826585B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1136(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1136);
	// addi r3,r31,1136
	ctx.r3.s64 = r31.s64 + 1136;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826585C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262fff0
	ctx.lr = 0x826585D4;
	sub_8262FFF0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r31,2128
	ctx.r3.s64 = r31.s64 + 2128;
	// bl 0x8262fff0
	ctx.lr = 0x826585E0;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,2608
	ctx.r3.s64 = r31.s64 + 2608;
	// bl 0x8262fff0
	ctx.lr = 0x826585EC;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,1888
	ctx.r3.s64 = r31.s64 + 1888;
	// bl 0x8262fff0
	ctx.lr = 0x826585F8;
	sub_8262FFF0(ctx, base);
	// addi r30,r31,2368
	r30.s64 = r31.s64 + 2368;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262fff0
	ctx.lr = 0x82658608;
	sub_8262FFF0(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x8265860C;
	sub_82387A18(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82658644
	if (cr6.eq) goto loc_82658644;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82658644
	if (cr6.eq) goto loc_82658644;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,680(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 680);
	// b 0x82658650
	goto loc_82658650;
loc_82658644:
	// lwz r11,3776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3776);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
loc_82658650:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ble cr6,0x82658668
	if (!cr6.gt) goto loc_82658668;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// b 0x8265866c
	goto loc_8265866C;
loc_82658668:
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
loc_8265866C:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82658694
	if (cr6.eq) goto loc_82658694;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82658694
	if (cr6.lt) goto loc_82658694;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// ble cr6,0x82658698
	if (!cr6.gt) goto loc_82658698;
loc_82658694:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82658698:
	// addi r3,r31,2848
	ctx.r3.s64 = r31.s64 + 2848;
	// bl 0x8262fff0
	ctx.lr = 0x826586A0;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3088
	ctx.r3.s64 = r31.s64 + 3088;
	// bl 0x8262fff0
	ctx.lr = 0x826586AC;
	sub_8262FFF0(ctx, base);
	// lwz r11,4840(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4840);
	// li r28,10
	r28.s64 = 10;
	// addi r29,r31,4624
	r29.s64 = r31.s64 + 4624;
	// stw r28,4840(r31)
	PPC_STORE_U32(r31.u32 + 4840, r28.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x826586d0
	if (cr6.eq) goto loc_826586D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,228
	ctx.r3.s64 = r29.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x826586D0;
	sub_821C3048(ctx, base);
loc_826586D0:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3808
	ctx.r3.s64 = r31.s64 + 3808;
	// bl 0x8262fff0
	ctx.lr = 0x826586DC;
	sub_8262FFF0(ctx, base);
	// bl 0x8227d3b0
	ctx.lr = 0x826586E0;
	sub_8227D3B0(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bge cr6,0x826586f0
	if (!cr6.lt) goto loc_826586F0;
	// bl 0x8227d3b0
	ctx.lr = 0x826586EC;
	sub_8227D3B0(ctx, base);
	// b 0x826586f4
	goto loc_826586F4;
loc_826586F0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_826586F4:
	// rlwinm r11,r3,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r3,r31,3568
	ctx.r3.s64 = r31.s64 + 3568;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x8262fff0
	ctx.lr = 0x82658704;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// bl 0x8262fff0
	ctx.lr = 0x82658710;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,4288
	ctx.r3.s64 = r31.s64 + 4288;
	// bl 0x8262fff0
	ctx.lr = 0x8265871C;
	sub_8262FFF0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,3328
	ctx.r3.s64 = r31.s64 + 3328;
	// bl 0x8262fff0
	ctx.lr = 0x82658728;
	sub_8262FFF0(ctx, base);
	// lwz r11,5096(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5096);
	// addi r30,r31,4880
	r30.s64 = r31.s64 + 4880;
	// stw r28,5096(r31)
	PPC_STORE_U32(r31.u32 + 5096, r28.u32);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x82658748
	if (cr6.eq) goto loc_82658748;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,228
	ctx.r3.s64 = r30.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658748;
	sub_821C3048(ctx, base);
loc_82658748:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,5136
	ctx.r3.s64 = r31.s64 + 5136;
	// bl 0x8262fff0
	ctx.lr = 0x82658754;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,5376
	ctx.r3.s64 = r31.s64 + 5376;
	// bl 0x8262fff0
	ctx.lr = 0x82658760;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,5616
	ctx.r3.s64 = r31.s64 + 5616;
	// bl 0x8262fff0
	ctx.lr = 0x8265876C;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x8262fff0
	ctx.lr = 0x82658778;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6096
	ctx.r3.s64 = r31.s64 + 6096;
	// bl 0x8262fff0
	ctx.lr = 0x82658784;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6336
	ctx.r3.s64 = r31.s64 + 6336;
	// bl 0x8262fff0
	ctx.lr = 0x82658790;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6576
	ctx.r3.s64 = r31.s64 + 6576;
	// bl 0x8262fff0
	ctx.lr = 0x8265879C;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,6816
	ctx.r3.s64 = r31.s64 + 6816;
	// bl 0x8262fff0
	ctx.lr = 0x826587A8;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7056
	ctx.r3.s64 = r31.s64 + 7056;
	// bl 0x8262fff0
	ctx.lr = 0x826587B4;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7296
	ctx.r3.s64 = r31.s64 + 7296;
	// bl 0x8262fff0
	ctx.lr = 0x826587C0;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7536
	ctx.r3.s64 = r31.s64 + 7536;
	// bl 0x8262fff0
	ctx.lr = 0x826587CC;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,7776
	ctx.r3.s64 = r31.s64 + 7776;
	// bl 0x8262fff0
	ctx.lr = 0x826587D8;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,8016
	ctx.r3.s64 = r31.s64 + 8016;
	// bl 0x8262fff0
	ctx.lr = 0x826587E4;
	sub_8262FFF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,8256
	ctx.r3.s64 = r31.s64 + 8256;
	// bl 0x8262fff0
	ctx.lr = 0x826587F0;
	sub_8262FFF0(ctx, base);
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// lwz r10,3056(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r8,4496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4496);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// stw r8,8520(r31)
	PPC_STORE_U32(r31.u32 + 8520, ctx.r8.u32);
	// lwz r9,336(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 336);
	// stb r11,8516(r31)
	PPC_STORE_U8(r31.u32 + 8516, r11.u8);
	// stb r10,8517(r31)
	PPC_STORE_U8(r31.u32 + 8517, ctx.r10.u8);
	// lwz r28,5584(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 5584);
	// lwz r27,5824(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 5824);
	// lwz r26,5344(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 5344);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82658840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r30,r31,8500
	r30.s64 = r31.s64 + 8500;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265885C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r6,r26
	ctx.r6.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lbz r4,8500(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 8500);
	// rlwinm r11,r6,2,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x80;
	// stb r3,8501(r31)
	PPC_STORE_U8(r31.u32 + 8501, ctx.r3.u8);
	// ori r10,r5,60000
	ctx.r10.u64 = ctx.r5.u64 | 60000;
	// clrlwi r9,r4,25
	ctx.r9.u64 = ctx.r4.u32 & 0x7F;
	// xori r8,r11,128
	ctx.r8.u64 = r11.u64 ^ 128;
	// mullw r6,r25,r10
	ctx.r6.s64 = int64_t(r25.s32) * int64_t(ctx.r10.s32);
	// stw r6,8504(r31)
	PPC_STORE_U32(r31.u32 + 8504, ctx.r6.u32);
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// cntlzw r4,r27
	ctx.r4.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// lbz r3,8502(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 8502);
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// rlwinm r10,r4,2,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0x80;
	// stb r5,8500(r31)
	PPC_STORE_U8(r31.u32 + 8500, ctx.r5.u8);
	// clrlwi r9,r3,26
	ctx.r9.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r7,r11,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r8,r10,128
	ctx.r8.u64 = ctx.r10.u64 ^ 128;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// addi r11,r31,8496
	r11.s64 = r31.s64 + 8496;
	// rlwimi r6,r5,6,25,25
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r5.u32, 6) & 0x40) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r6,8502(r31)
	PPC_STORE_U8(r31.u32 + 8502, ctx.r6.u8);
	// lwz r28,6064(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 6064);
	// lwz r11,6544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6544);
	// lwz r10,6784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6784);
	// lwz r9,7024(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 7024);
	// lwz r8,7264(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 7264);
	// lwz r7,7504(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 7504);
	// lwz r5,8224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// lwz r4,7984(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 7984);
	// lwz r6,8464(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8464);
	// lwz r3,6304(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6304);
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lbz r29,8497(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 8497);
	// cntlzw r28,r28
	r28.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lwz r30,7744(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 7744);
	// rlwinm r3,r3,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r28,r28,28,30,30
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 28) & 0x2;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// xori r28,r28,2
	r28.u64 = r28.u64 ^ 2;
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r3,r28,r3
	ctx.r3.u64 = r28.u64 | ctx.r3.u64;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// rlwinm r3,r3,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// or r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 | r11.u64;
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r10,r3,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// xori r3,r11,1
	ctx.r3.u64 = r11.u64 ^ 1;
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// or r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 | ctx.r3.u64;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r3,r10,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFE;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// cntlzw r10,r8
	ctx.r10.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// or r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 | r11.u64;
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r3,r9,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFE;
	// cntlzw r9,r5
	ctx.r9.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// cntlzw r10,r7
	ctx.r10.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cntlzw r7,r4
	ctx.r7.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// cntlzw r8,r6
	ctx.r8.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// or r6,r3,r11
	ctx.r6.u64 = ctx.r3.u64 | r11.u64;
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r4,r9,28,30,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x2;
	// rlwinm r11,r7,2,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x80;
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r9,r5,1
	ctx.r9.u64 = ctx.r5.u64 ^ 1;
	// rlwinm r10,r6,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFE;
	// xori r7,r4,2
	ctx.r7.u64 = ctx.r4.u64 ^ 2;
	// xori r4,r11,128
	ctx.r4.u64 = r11.u64 ^ 128;
	// xori r6,r3,1
	ctx.r6.u64 = ctx.r3.u64 ^ 1;
	// or r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r5,r29,27
	ctx.r5.u64 = r29.u32 & 0x1F;
	// cntlzw r8,r30
	ctx.r8.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// or r9,r5,r4
	ctx.r9.u64 = ctx.r5.u64 | ctx.r4.u64;
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r3,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// xori r7,r11,1
	ctx.r7.u64 = r11.u64 ^ 1;
	// rlwinm r6,r10,5,24,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0;
	// rlwinm r5,r5,0,27,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// li r11,-1
	r11.s64 = -1;
	// stb r4,8496(r31)
	PPC_STORE_U8(r31.u32 + 8496, ctx.r4.u8);
	// stb r3,8497(r31)
	PPC_STORE_U8(r31.u32 + 8497, ctx.r3.u8);
	// stw r11,8536(r31)
	PPC_STORE_U32(r31.u32 + 8536, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826589D8"))) PPC_WEAK_FUNC(sub_826589D8);
PPC_FUNC_IMPL(__imp__sub_826589D8) {
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
	ctx.lr = 0x826589E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// ori r6,r9,55138
	ctx.r6.u64 = ctx.r9.u64 | 55138;
	// lwz r11,3296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// lwz r8,4496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4496);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r8,8520(r31)
	PPC_STORE_U32(r31.u32 + 8520, ctx.r8.u32);
	// stb r4,8516(r31)
	PPC_STORE_U8(r31.u32 + 8516, ctx.r4.u8);
	// lbzx r11,r3,r6
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r6.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82658a2c
	if (cr6.eq) goto loc_82658A2C;
	// lwz r11,2576(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2576);
	// b 0x82658a30
	goto loc_82658A30;
loc_82658A2C:
	// lwz r11,2336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2336);
loc_82658A30:
	// stw r11,8508(r31)
	PPC_STORE_U32(r31.u32 + 8508, r11.u32);
	// lis r9,2
	ctx.r9.s64 = 131072;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// ori r8,r9,55136
	ctx.r8.u64 = ctx.r9.u64 | 55136;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,2816(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2816);
	// lbzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82658a58
	if (cr6.eq) goto loc_82658A58;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_82658A58:
	// lwz r10,3056(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// addi r3,r31,4880
	ctx.r3.s64 = r31.s64 + 4880;
	// lwz r9,4880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4880);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r29,5584(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 5584);
	// lwz r28,5824(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 5824);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r27,5344(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 5344);
	// stw r11,8512(r31)
	PPC_STORE_U32(r31.u32 + 8512, r11.u32);
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// lwz r5,336(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 336);
	// stb r6,8517(r31)
	PPC_STORE_U8(r31.u32 + 8517, ctx.r6.u8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82658A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,4624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4624);
	// addi r11,r31,4624
	r11.s64 = r31.s64 + 4624;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r30,r31,8500
	r30.s64 = r31.s64 + 8500;
	// lwz r11,336(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 336);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82658AB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r3,8501(r31)
	PPC_STORE_U8(r31.u32 + 8501, ctx.r3.u8);
	// cntlzw r10,r28
	ctx.r10.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lbz r9,8502(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 8502);
	// cntlzw r8,r29
	ctx.r8.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// lbz r6,8500(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 8500);
	// rlwinm r7,r10,2,24,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x80;
	// cntlzw r5,r27
	ctx.r5.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// clrlwi r11,r9,26
	r11.u64 = ctx.r9.u32 & 0x3F;
	// xori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 ^ 128;
	// rlwinm r10,r8,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r9,r5,2,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x80;
	// lis r5,0
	ctx.r5.s64 = 0;
	// or r8,r4,r11
	ctx.r8.u64 = ctx.r4.u64 | r11.u64;
	// xori r7,r10,1
	ctx.r7.u64 = ctx.r10.u64 ^ 1;
	// clrlwi r4,r6,25
	ctx.r4.u64 = ctx.r6.u32 & 0x7F;
	// xori r10,r9,128
	ctx.r10.u64 = ctx.r9.u64 ^ 128;
	// ori r11,r5,60000
	r11.u64 = ctx.r5.u64 | 60000;
	// rlwimi r8,r7,6,25,25
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 6) & 0x40) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFBF);
	// or r6,r4,r10
	ctx.r6.u64 = ctx.r4.u64 | ctx.r10.u64;
	// mullw r7,r26,r11
	ctx.r7.s64 = int64_t(r26.s32) * int64_t(r11.s32);
	// stb r8,8502(r31)
	PPC_STORE_U8(r31.u32 + 8502, ctx.r8.u8);
	// stb r6,8500(r31)
	PPC_STORE_U8(r31.u32 + 8500, ctx.r6.u8);
	// stw r7,8504(r31)
	PPC_STORE_U32(r31.u32 + 8504, ctx.r7.u32);
	// lwz r4,6304(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 6304);
	// lwz r3,6544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6544);
	// lwz r10,6784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 6784);
	// lwz r9,7024(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 7024);
	// lwz r28,7264(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 7264);
	// lwz r8,6064(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 6064);
	// lwz r5,8464(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8464);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r8,8224(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// cntlzw r6,r4
	ctx.r6.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r30,7744(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 7744);
	// rlwinm r4,r7,28,30,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0x2;
	// lwz r29,7504(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 7504);
	// rlwinm r7,r6,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r6,7984(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 7984);
	// xori r4,r4,2
	ctx.r4.u64 = ctx.r4.u64 ^ 2;
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// or r7,r4,r7
	ctx.r7.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r4,r3,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r3,r7,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFE;
	// xori r7,r4,1
	ctx.r7.u64 = ctx.r4.u64 ^ 1;
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
	// rlwinm r10,r4,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// rlwinm r7,r3,1,24,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// xori r4,r10,1
	ctx.r4.u64 = ctx.r10.u64 ^ 1;
	// cntlzw r3,r9
	ctx.r3.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// or r10,r7,r4
	ctx.r10.u64 = ctx.r7.u64 | ctx.r4.u64;
	// rlwinm r9,r3,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// lbz r3,8497(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 8497);
	// rlwinm r7,r10,1,24,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFE;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// addi r11,r31,8496
	r11.s64 = r31.s64 + 8496;
	// cntlzw r11,r28
	r11.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// or r10,r7,r4
	ctx.r10.u64 = ctx.r7.u64 | ctx.r4.u64;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r7,r10,1,24,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFE;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// cntlzw r9,r5
	ctx.r9.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// cntlzw r10,r8
	ctx.r10.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r8,r6
	ctx.r8.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// or r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 | ctx.r4.u64;
	// rlwinm r6,r11,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r5,r10,28,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r11,r8,2,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x80;
	// rlwinm r10,r7,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFE;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
	// xori r7,r5,2
	ctx.r7.u64 = ctx.r5.u64 ^ 2;
	// xori r6,r4,1
	ctx.r6.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r5,r3,27
	ctx.r5.u64 = ctx.r3.u32 & 0x1F;
	// xori r4,r11,128
	ctx.r4.u64 = r11.u64 ^ 128;
	// or r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 | ctx.r9.u64;
	// or r9,r5,r4
	ctx.r9.u64 = ctx.r5.u64 | ctx.r4.u64;
	// cntlzw r8,r30
	ctx.r8.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r3,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// xori r7,r11,1
	ctx.r7.u64 = r11.u64 ^ 1;
	// rlwinm r6,r10,5,24,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0;
	// rlwinm r5,r5,0,27,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stb r4,8496(r31)
	PPC_STORE_U8(r31.u32 + 8496, ctx.r4.u8);
	// stb r3,8497(r31)
	PPC_STORE_U8(r31.u32 + 8497, ctx.r3.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82658C24"))) PPC_WEAK_FUNC(sub_82658C24);
PPC_FUNC_IMPL(__imp__sub_82658C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82658C28"))) PPC_WEAK_FUNC(sub_82658C28);
PPC_FUNC_IMPL(__imp__sub_82658C28) {
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
	ctx.lr = 0x82658C30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,3296(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3296);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82658c98
	if (cr6.lt) goto loc_82658C98;
	// bne cr6,0x82658db0
	if (!cr6.eq) goto loc_82658DB0;
	// lwz r11,1136(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1136);
	// addi r3,r29,1136
	ctx.r3.s64 = r29.s64 + 1136;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1608(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 1608);
	// addi r31,r29,1392
	r31.s64 = r29.s64 + 1392;
	// stw r3,1608(r29)
	PPC_STORE_U32(r29.u32 + 1608, ctx.r3.u32);
	// cmpw cr6,r9,r3
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r3.s32, xer);
	// beq cr6,0x82658c7c
	if (cr6.eq) goto loc_82658C7C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658C7C;
	sub_821C3048(ctx, base);
loc_82658C7C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658C90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82658C98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,16256
	ctx.r9.s64 = ctx.r9.s64 + 16256;
	// addis r31,r9,2
	r31.s64 = ctx.r9.s64 + 131072;
	// addi r31,r31,-32640
	r31.s64 = r31.s64 + -32640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,784(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 784);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82658CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,864(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r5,r31,976
	ctx.r5.s64 = r31.s64 + 976;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bne cr6,0x82658d20
	if (!cr6.eq) goto loc_82658D20;
	// lwz r11,1392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1392);
	// addi r31,r29,1392
	r31.s64 = r29.s64 + 1392;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1608(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 1608);
	// li r9,1
	ctx.r9.s64 = 1;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// stw r9,1608(r29)
	PPC_STORE_U32(r29.u32 + 1608, ctx.r9.u32);
	// beq cr6,0x82658db0
	if (cr6.eq) goto loc_82658DB0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658D18;
	sub_821C3048(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82658D20:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82658D2C;
	sub_8238EC00(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82658d54
	if (cr6.eq) goto loc_82658D54;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82389800
	ctx.lr = 0x82658D3C;
	sub_82389800(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82658d58
	if (cr6.eq) goto loc_82658D58;
	// lbz r11,19(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 19);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// b 0x82658d5c
	goto loc_82658D5C;
loc_82658D54:
	// li r30,0
	r30.s64 = 0;
loc_82658D58:
	// li r11,2
	r11.s64 = 2;
loc_82658D5C:
	// lwz r10,1608(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1608);
	// addi r31,r29,1392
	r31.s64 = r29.s64 + 1392;
	// stw r11,1608(r29)
	PPC_STORE_U32(r29.u32 + 1608, r11.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82658d7c
	if (cr6.eq) goto loc_82658D7C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82658D7C;
	sub_821C3048(ctx, base);
loc_82658D7C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82658d98
	if (cr6.eq) goto loc_82658D98;
	// lbz r11,19(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 19);
	// li r4,1
	ctx.r4.s64 = 1;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82658d9c
	if (cr6.gt) goto loc_82658D9C;
loc_82658D98:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82658D9C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82658DB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82658DB8"))) PPC_WEAK_FUNC(sub_82658DB8);
PPC_FUNC_IMPL(__imp__sub_82658DB8) {
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
	ctx.lr = 0x82658DC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82658DDC;
	sub_821F9FB8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lbz r8,164(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 164);
	// lwz r4,56(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// addis r31,r11,1
	r31.s64 = r11.s64 + 65536;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// beq cr6,0x82658e40
	if (cr6.eq) goto loc_82658E40;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// li r11,0
	r11.s64 = 0;
	// addi r29,r29,19760
	r29.s64 = r29.s64 + 19760;
	// stb r11,164(r30)
	PPC_STORE_U8(r30.u32 + 164, r11.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82658E20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82658E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82658E40:
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,-27616
	r30.s64 = r30.s64 + -27616;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82658E5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82658E74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82658E7C"))) PPC_WEAK_FUNC(sub_82658E7C);
PPC_FUNC_IMPL(__imp__sub_82658E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82658E80"))) PPC_WEAK_FUNC(sub_82658E80);
PPC_FUNC_IMPL(__imp__sub_82658E80) {
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
	ctx.lr = 0x82658E88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82658EA4;
	sub_821F9FB8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r29,r10,2612
	r29.s64 = ctx.r10.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r28,56(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82658EC0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82658ED0;
	sub_825ED480(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13268
	ctx.r4.s64 = ctx.r7.s64 + -13268;
	// bl 0x82722678
	ctx.lr = 0x82658EE8;
	sub_82722678(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// stb r11,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,-10236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// stb r11,27964(r6)
	PPC_STORE_U8(ctx.r6.u32 + 27964, r11.u8);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stb r11,1258(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1258, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,1120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1120, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,375(r10)
	PPC_STORE_U8(ctx.r10.u32 + 375, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,374(r10)
	PPC_STORE_U8(ctx.r10.u32 + 374, r11.u8);
	// lwz r10,-10220(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r11,377(r10)
	PPC_STORE_U8(ctx.r10.u32 + 377, r11.u8);
	// lwz r11,-10220(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10220);
	// stb r4,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r4.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82658F54"))) PPC_WEAK_FUNC(sub_82658F54);
PPC_FUNC_IMPL(__imp__sub_82658F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82658F58"))) PPC_WEAK_FUNC(sub_82658F58);
PPC_FUNC_IMPL(__imp__sub_82658F58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
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
	// bl 0x823d91d0
	ctx.lr = 0x82658F60;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r19,r8
	r19.u64 = ctx.r8.u64;
	// lis r25,-32112
	r25.s64 = -2104492032;
	// mr r18,r30
	r18.u64 = r30.u64;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r24,r10
	cr6.compare<uint32_t>(r24.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265937c
	if (!cr6.eq) goto loc_8265937C;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpwi cr6,r11,53
	cr6.compare<int32_t>(r11.s32, 53, xer);
	// beq cr6,0x82658fb8
	if (cr6.eq) goto loc_82658FB8;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// bne cr6,0x8265937c
	if (!cr6.eq) goto loc_8265937C;
loc_82658FB8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r26,r11,-18768
	r26.s64 = r11.s64 + -18768;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82658FC8;
	sub_821F9FB8(ctx, base);
	// lbz r11,27964(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 27964);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659218
	if (cr6.eq) goto loc_82659218;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x82658FEC;
	sub_825EE0E0(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stb r11,27964(r25)
	PPC_STORE_U8(r25.u32 + 27964, r11.u8);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,6136
	ctx.r4.s64 = ctx.r10.s64 + 6136;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// addi r28,r8,-22108
	r28.s64 = ctx.r8.s64 + -22108;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8265901C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82659030;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x826209d8
	ctx.lr = 0x82659040;
	sub_826209D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826590e4
	if (cr6.eq) goto loc_826590E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82659060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r9,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8261fc88
	ctx.lr = 0x826590B8;
	sub_8261FC88(ctx, base);
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82625ac0
	ctx.lr = 0x826590E0;
	sub_82625AC0(ctx, base);
	// b 0x82659114
	goto loc_82659114;
loc_826590E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82625f50
	ctx.lr = 0x82659114;
	sub_82625F50(ctx, base);
loc_82659114:
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,6124
	ctx.r3.s64 = ctx.r10.s64 + 6124;
	// stb r30,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,377(r11)
	PPC_STORE_U8(r11.u32 + 377, r30.u8);
	// bl 0x821fa230
	ctx.lr = 0x82659158;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,112(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82659168;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r30,248(r7)
	PPC_STORE_U32(ctx.r7.u32 + 248, r30.u32);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82659180;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826591a8
	if (cr6.eq) goto loc_826591A8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x82659194;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827205a8
	ctx.lr = 0x826591A8;
	sub_827205A8(ctx, base);
loc_826591A8:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r11,1
	r30.s64 = r11.s64 + 65536;
	// addi r30,r30,16256
	r30.s64 = r30.s64 + 16256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826591C4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826591D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826591f0
	if (cr6.eq) goto loc_826591F0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82659200
	goto loc_82659200;
loc_826591F0:
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826591FC;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82659200:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265920C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// b 0x82659378
	goto loc_82659378;
loc_82659218:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,18
	ctx.r4.s64 = 18;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82659230;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82659244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265937c
	if (cr6.eq) goto loc_8265937C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x82659264;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82657678
	ctx.lr = 0x8265926C;
	sub_82657678(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82659370
	if (cr6.eq) goto loc_82659370;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r10,-10236(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r9,352
	ctx.r9.s64 = 352;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r27,r3,-22108
	r27.s64 = ctx.r3.s64 + -22108;
	// lfs f0,6076(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r6,6060
	ctx.r4.s64 = ctx.r6.s64 + 6060;
	// addi r28,r5,-19728
	r28.s64 = ctx.r5.s64 + -19728;
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826592C4;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826592D8;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x826592FC;
	sub_82625F50(ctx, base);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stb r11,27964(r25)
	PPC_STORE_U8(r25.u32 + 27964, r11.u8);
	// stb r11,1120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1120, r11.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,375(r10)
	PPC_STORE_U8(ctx.r10.u32 + 375, r30.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,374(r10)
	PPC_STORE_U8(ctx.r10.u32 + 374, r30.u8);
	// lwz r10,-10220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r11,377(r10)
	PPC_STORE_U8(ctx.r10.u32 + 377, r11.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82659348;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82659354
	if (cr6.eq) goto loc_82659354;
	// bl 0x82720560
	ctx.lr = 0x82659354;
	sub_82720560(ctx, base);
loc_82659354:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x82659364;
	sub_8220F040(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// b 0x82659378
	goto loc_82659378;
loc_82659370:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
loc_82659378:
	// bl 0x821e6800
	ctx.lr = 0x8265937C;
	sub_821E6800(ctx, base);
loc_8265937C:
	// lbz r11,27964(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 27964);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826593ac
	if (!cr6.eq) goto loc_826593AC;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82635be0
	ctx.lr = 0x826593A4;
	sub_82635BE0(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9220
	return;
loc_826593AC:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_826593B8"))) PPC_WEAK_FUNC(sub_826593B8);
PPC_FUNC_IMPL(__imp__sub_826593B8) {
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
	ctx.lr = 0x826593C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x826593dc
	if (cr6.eq) goto loc_826593DC;
	// bl 0x826537d0
	ctx.lr = 0x826593D4;
	sub_826537D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826593DC:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x826593E4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826593f4
	if (cr6.lt) goto loc_826593F4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826593F4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8265941c
	if (cr6.eq) goto loc_8265941C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82659410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265941C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r10,3
	r31.s64 = ctx.r10.s64 + 196608;
	// addi r31,r31,-16384
	r31.s64 = r31.s64 + -16384;
	// addi r30,r31,976
	r30.s64 = r31.s64 + 976;
	// lwz r9,864(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r9,r30
	cr6.compare<uint32_t>(ctx.r9.u32, r30.u32, xer);
	// bne cr6,0x82659450
	if (!cr6.eq) goto loc_82659450;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82655ff8
	ctx.lr = 0x82659448;
	sub_82655FF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82659454
	goto loc_82659454;
loc_82659450:
	// li r29,0
	r29.s64 = 0;
loc_82659454:
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x8265946c
	if (!cr6.eq) goto loc_8265946C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-8672
	ctx.r3.s64 = r11.s64 + -8672;
	// b 0x82659480
	goto loc_82659480;
loc_8265946C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82659480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82659480:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82659488;
	sub_821C9790(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82282580
	ctx.lr = 0x826594A0;
	sub_82282580(ctx, base);
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82216138
	ctx.lr = 0x826594A8;
	sub_82216138(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826594B4"))) PPC_WEAK_FUNC(sub_826594B4);
PPC_FUNC_IMPL(__imp__sub_826594B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826594B8"))) PPC_WEAK_FUNC(sub_826594B8);
PPC_FUNC_IMPL(__imp__sub_826594B8) {
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
	ctx.lr = 0x826594C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r11,27960
	r31.s64 = r11.s64 + 27960;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lwz r5,-4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826594EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x823dd7f0
	ctx.lr = 0x826594F0;
	sub_823DD7F0(ctx, base);
	// lwz r11,-8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,-4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82659514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x823dd7f0
	ctx.lr = 0x82659518;
	sub_823DD7F0(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// ble cr6,0x8265952c
	if (!cr6.gt) goto loc_8265952C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265952C:
	// bge cr6,0x82659540
	if (!cr6.lt) goto loc_82659540;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// neg r3,r11
	ctx.r3.s64 = -r11.s64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82659540:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265954C"))) PPC_WEAK_FUNC(sub_8265954C);
PPC_FUNC_IMPL(__imp__sub_8265954C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82659550"))) PPC_WEAK_FUNC(sub_82659550);
PPC_FUNC_IMPL(__imp__sub_82659550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r11,27960
	r31.s64 = r11.s64 + 27960;
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lwz r5,-4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82659590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x823de058
	ctx.lr = 0x82659594;
	sub_823DE058(ctx, base);
	// lwz r3,-8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// lwz r5,-4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826595B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x823de058
	ctx.lr = 0x826595B8;
	sub_823DE058(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x826595cc
	if (!cr6.gt) goto loc_826595CC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x826595e4
	goto loc_826595E4;
loc_826595CC:
	// fcmpu cr6,f31,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x826595e0
	if (!cr6.lt) goto loc_826595E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// neg r3,r11
	ctx.r3.s64 = -r11.s64;
	// b 0x826595e4
	goto loc_826595E4;
loc_826595E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826595E4:
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

__attribute__((alias("__imp__sub_82659600"))) PPC_WEAK_FUNC(sub_82659600);
PPC_FUNC_IMPL(__imp__sub_82659600) {
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
	ctx.lr = 0x82659608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r27,r29,27960
	r27.s64 = r29.s64 + 27960;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-8(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8);
	// lwz r31,-10244(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r5,-4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + -4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265963C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x82659648;
	sub_82218310(ctx, base);
	// lwz r11,-8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -8);
	// lwz r5,-4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + -4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r31,-10244(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82659670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x8265967C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823db730
	ctx.lr = 0x82659688;
	sub_823DB730(ctx, base);
	// lwz r11,27960(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 27960);
	// mullw r3,r3,r11
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(r11.s32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82659698"))) PPC_WEAK_FUNC(sub_82659698);
PPC_FUNC_IMPL(__imp__sub_82659698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r8,r7,27956
	ctx.r8.s64 = ctx.r7.s64 + 27956;
	// rlwinm r9,r6,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r6,-32154
	ctx.r6.s64 = -2107244544;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,27956(r7)
	PPC_STORE_U32(ctx.r7.u32 + 27956, ctx.r10.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, r11.u32);
	// addi r6,r6,-27136
	ctx.r6.s64 = ctx.r6.s64 + -27136;
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// b 0x823dcf08
	sub_823DCF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826596E0"))) PPC_WEAK_FUNC(sub_826596E0);
PPC_FUNC_IMPL(__imp__sub_826596E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r8,r7,27956
	ctx.r8.s64 = ctx.r7.s64 + 27956;
	// rlwinm r9,r6,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r6,-32154
	ctx.r6.s64 = -2107244544;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,27956(r7)
	PPC_STORE_U32(ctx.r7.u32 + 27956, ctx.r10.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, r11.u32);
	// addi r6,r6,-27464
	ctx.r6.s64 = ctx.r6.s64 + -27464;
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// b 0x823dcf08
	sub_823DCF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82659728"))) PPC_WEAK_FUNC(sub_82659728);
PPC_FUNC_IMPL(__imp__sub_82659728) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// clrlwi r9,r5,24
	ctx.r9.u64 = ctx.r5.u32 & 0xFF;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// subfe r6,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r8,r7,27956
	ctx.r8.s64 = ctx.r7.s64 + 27956;
	// rlwinm r9,r6,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r6,-32154
	ctx.r6.s64 = -2107244544;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,27956(r7)
	PPC_STORE_U32(ctx.r7.u32 + 27956, ctx.r10.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r11,-4(r8)
	PPC_STORE_U32(ctx.r8.u32 + -4, r11.u32);
	// addi r6,r6,-27312
	ctx.r6.s64 = ctx.r6.s64 + -27312;
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// b 0x823dcf08
	sub_823DCF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82659770"))) PPC_WEAK_FUNC(sub_82659770);
PPC_FUNC_IMPL(__imp__sub_82659770) {
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
	// bl 0x82656c20
	ctx.lr = 0x82659788;
	sub_82656C20(ctx, base);
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

__attribute__((alias("__imp__sub_826597A0"))) PPC_WEAK_FUNC(sub_826597A0);
PPC_FUNC_IMPL(__imp__sub_826597A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826597B4"))) PPC_WEAK_FUNC(sub_826597B4);
PPC_FUNC_IMPL(__imp__sub_826597B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826597B8"))) PPC_WEAK_FUNC(sub_826597B8);
PPC_FUNC_IMPL(__imp__sub_826597B8) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r9,100
	ctx.r9.s64 = 100;
	// addi r10,r11,-4092
	ctx.r10.s64 = r11.s64 + -4092;
	// li r31,0
	r31.s64 = 0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// li r3,400
	ctx.r3.s64 = 400;
	// sth r31,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r31.u16);
	// sth r9,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r9.u16);
	// bl 0x82130528
	ctx.lr = 0x826597F4;
	sub_82130528(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r8,-2596
	ctx.r6.s64 = ctx.r8.s64 + -2596;
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// lwz r3,-27856(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82659810;
	sub_8238EC00(ctx, base);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// stb r31,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r31.u8);
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

__attribute__((alias("__imp__sub_82659834"))) PPC_WEAK_FUNC(sub_82659834);
PPC_FUNC_IMPL(__imp__sub_82659834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82659838"))) PPC_WEAK_FUNC(sub_82659838);
PPC_FUNC_IMPL(__imp__sub_82659838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,27
	r11.u64 = ctx.r9.u32 & 0x1F;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82659850"))) PPC_WEAK_FUNC(sub_82659850);
PPC_FUNC_IMPL(__imp__sub_82659850) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r9,18
	ctx.r9.s64 = 18;
	// addi r10,r11,-4092
	ctx.r10.s64 = r11.s64 + -4092;
	// li r31,0
	r31.s64 = 0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// sth r31,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r31.u16);
	// sth r9,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r9.u16);
	// bl 0x82130528
	ctx.lr = 0x8265988C;
	sub_82130528(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r8,-2544
	ctx.r6.s64 = ctx.r8.s64 + -2544;
	// stb r31,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r31.u8);
	// stb r31,17(r30)
	PPC_STORE_U8(r30.u32 + 17, r31.u8);
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// stb r31,18(r30)
	PPC_STORE_U8(r30.u32 + 18, r31.u8);
	// lwz r3,-27856(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826598B4;
	sub_8238EC00(ctx, base);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_826598D4"))) PPC_WEAK_FUNC(sub_826598D4);
PPC_FUNC_IMPL(__imp__sub_826598D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826598D8"))) PPC_WEAK_FUNC(sub_826598D8);
PPC_FUNC_IMPL(__imp__sub_826598D8) {
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
	ctx.lr = 0x826598E0;
	// stwu r1,-1248(r1)
	ea = -1248 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659918
	if (cr6.eq) goto loc_82659918;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82659900:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82659900
	if (!cr6.eq) goto loc_82659900;
loc_82659918:
	// li r3,14
	ctx.r3.s64 = 14;
	// bl 0x82130528
	ctx.lr = 0x82659920;
	sub_82130528(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r24,1
	r24.s64 = 1;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r11,2356
	r30.s64 = r11.s64 + 2356;
	// lwz r10,2352(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2352);
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82659950
	if (cr6.gt) goto loc_82659950;
	// li r11,0
	r11.s64 = 0;
loc_82659950:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// clrlwi r23,r11,24
	r23.u64 = r11.u32 & 0xFF;
	// addi r3,r10,6104
	ctx.r3.s64 = ctx.r10.s64 + 6104;
	// li r22,-1
	r22.s64 = -1;
	// bl 0x821fa230
	ctx.lr = 0x82659964;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82659974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// stb r3,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r3.u8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826599b0
	if (!cr6.eq) goto loc_826599B0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-2500
	ctx.r3.s64 = r11.s64 + -2500;
	// bl 0x821fa230
	ctx.lr = 0x82659990;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826599A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826599b4
	if (cr6.eq) goto loc_826599B4;
loc_826599B0:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_826599B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r11,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r11.u8);
	// bne cr6,0x826599d8
	if (!cr6.eq) goto loc_826599D8;
	// bl 0x82387a18
	ctx.lr = 0x826599C8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x826599dc
	if (cr6.eq) goto loc_826599DC;
loc_826599D8:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_826599DC:
	// stb r11,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r11.u8);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,72(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r4,r10,-2524
	ctx.r4.s64 = ctx.r10.s64 + -2524;
	// bl 0x82294ef8
	ctx.lr = 0x826599F4;
	sub_82294EF8(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x82659a0c
	if (!cr6.eq) goto loc_82659A0C;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// mr r21,r24
	r21.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659a10
	if (!cr6.eq) goto loc_82659A10;
loc_82659A0C:
	// li r21,0
	r21.s64 = 0;
loc_82659A10:
	// bl 0x82387a18
	ctx.lr = 0x82659A14;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659a88
	if (cr6.eq) goto loc_82659A88;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82659A28;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82659A38;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82659A40;
	sub_82272A30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82659a88
	if (cr6.eq) goto loc_82659A88;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82659A50;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82659A60;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82659A68;
	sub_82272A30(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x824818a0
	ctx.lr = 0x82659A74;
	sub_824818A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824818a0
	ctx.lr = 0x82659A84;
	sub_824818A0(ctx, base);
	// add r22,r29,r3
	r22.u64 = r29.u64 + ctx.r3.u64;
loc_82659A88:
	// mr r11,r20
	r11.u64 = r20.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,14
	ctx.r10.s64 = 14;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82659A98:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82659a98
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82659A98;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82659b8c
	if (!cr6.gt) goto loc_82659B8C;
	// mr r26,r11
	r26.u64 = r11.u64;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r27,0
	r27.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r25,r11,-28304
	r25.s64 = r11.s64 + -28304;
loc_82659ACC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,-10020(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10020);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r4,r9,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// beq cr6,0x82659b00
	if (cr6.eq) goto loc_82659B00;
	// bl 0x826bf4b0
	ctx.lr = 0x82659AF0;
	sub_826BF4B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659b00
	if (!cr6.eq) goto loc_82659B00;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_82659B00:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659b7c
	if (!cr6.eq) goto loc_82659B7C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// and r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82659b7c
	if (cr6.eq) goto loc_82659B7C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r10,6
	cr6.compare<int32_t>(ctx.r10.s32, 6, xer);
	// beq cr6,0x82659b68
	if (cr6.eq) goto loc_82659B68;
	// cmpwi cr6,r10,7
	cr6.compare<int32_t>(ctx.r10.s32, 7, xer);
	// beq cr6,0x82659b68
	if (cr6.eq) goto loc_82659B68;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659b5c
	if (!cr6.eq) goto loc_82659B5C;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82659b5c
	if (cr6.lt) goto loc_82659B5C;
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// ble cr6,0x82659b60
	if (!cr6.gt) goto loc_82659B60;
loc_82659B5C:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_82659B60:
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// b 0x82659b6c
	goto loc_82659B6C;
loc_82659B68:
	// li r11,0
	r11.s64 = 0;
loc_82659B6C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659b7c
	if (cr6.eq) goto loc_82659B7C;
	// stbx r24,r10,r20
	PPC_STORE_U8(ctx.r10.u32 + r20.u32, r24.u8);
loc_82659B7C:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r27,r27,160
	r27.s64 = r27.s64 + 160;
	// bne 0x82659acc
	if (!cr0.eq) goto loc_82659ACC;
loc_82659B8C:
	// lbz r11,17(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659bc8
	if (cr6.eq) goto loc_82659BC8;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659bc8
	if (!cr6.eq) goto loc_82659BC8;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,17
	ctx.r8.s64 = 17;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82659BC8:
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659bf8
	if (cr6.eq) goto loc_82659BF8;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,18
	ctx.r8.s64 = 18;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82659BF8:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659c10
	if (cr6.eq) goto loc_82659C10;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659da8
	if (!cr6.eq) goto loc_82659DA8;
loc_82659C10:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r6,r20,1
	ctx.r6.s64 = r20.s64 + 1;
loc_82659C18:
	// lbz r11,-1(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + -1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659c44
	if (cr6.eq) goto loc_82659C44;
	// lhz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// sth r5,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r5.u16);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
loc_82659C44:
	// lbz r11,0(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659c74
	if (cr6.eq) goto loc_82659C74;
	// lhz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// sth r4,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r4.u16);
	// stwx r5,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r5.u32);
loc_82659C74:
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addi r6,r6,2
	ctx.r6.s64 = ctx.r6.s64 + 2;
	// cmpwi cr6,r10,14
	cr6.compare<int32_t>(ctx.r10.s32, 14, xer);
	// blt cr6,0x82659c18
	if (cr6.lt) goto loc_82659C18;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659d5c
	if (cr6.eq) goto loc_82659D5C;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659d5c
	if (!cr6.eq) goto loc_82659D5C;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659d5c
	if (!cr6.eq) goto loc_82659D5C;
	// cmpwi cr6,r22,8
	cr6.compare<int32_t>(r22.s32, 8, xer);
	// bgt cr6,0x82659d5c
	if (cr6.gt) goto loc_82659D5C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82659CBC;
	sub_8238EC00(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r9,80
	ctx.r9.s64 = 80;
	// li r30,0
	r30.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,-12648(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12648);
	// subf r8,r11,r3
	ctx.r8.s64 = ctx.r3.s64 - r11.s64;
	// divw r7,r8,r9
	ctx.r7.s32 = ctx.r8.s32 / ctx.r9.s32;
	// clrlwi r29,r7,24
	r29.u64 = ctx.r7.u32 & 0xFF;
loc_82659CDC:
	// lwz r11,-6148(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -6148);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// addi r4,r11,11984
	ctx.r4.s64 = r11.s64 + 11984;
	// bl 0x826558c0
	ctx.lr = 0x82659CF0;
	sub_826558C0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82250ed8
	ctx.lr = 0x82659CFC;
	sub_82250ED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82659d28
	if (cr6.eq) goto loc_82659D28;
	// lbz r10,1123(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1123);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82659d1c
	if (!cr6.eq) goto loc_82659D1C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82659d20
	goto loc_82659D20;
loc_82659D1C:
	// lbz r11,1122(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1122);
loc_82659D20:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82659d38
	if (cr6.gt) goto loc_82659D38;
loc_82659D28:
	// addi r30,r30,1056
	r30.s64 = r30.s64 + 1056;
	// cmpwi cr6,r30,21120
	cr6.compare<int32_t>(r30.s32, 21120, xer);
	// blt cr6,0x82659cdc
	if (cr6.lt) goto loc_82659CDC;
	// b 0x82659d5c
	goto loc_82659D5C;
loc_82659D38:
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,16
	ctx.r8.s64 = 16;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82659D5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r4,18(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204310
	ctx.lr = 0x82659D70;
	sub_82204310(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82659da8
	if (cr6.eq) goto loc_82659DA8;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82659da8
	if (!cr6.eq) goto loc_82659DA8;
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,15
	ctx.r8.s64 = 15;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_82659DA8:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130588
	ctx.lr = 0x82659DB0;
	sub_82130588(ctx, base);
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82659DB8"))) PPC_WEAK_FUNC(sub_82659DB8);
PPC_FUNC_IMPL(__imp__sub_82659DB8) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-4092
	ctx.r9.s64 = r11.s64 + -4092;
	// li r8,20
	ctx.r8.s64 = 20;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r3,80
	ctx.r3.s64 = 80;
	// sth r10,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r10.u16);
	// sth r8,10(r31)
	PPC_STORE_U16(r31.u32 + 10, ctx.r8.u16);
	// bl 0x82130528
	ctx.lr = 0x82659DF0;
	sub_82130528(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// addi r5,r7,-2480
	ctx.r5.s64 = ctx.r7.s64 + -2480;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// lwz r3,-27856(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82659E0C;
	sub_8238EC00(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82659E28"))) PPC_WEAK_FUNC(sub_82659E28);
PPC_FUNC_IMPL(__imp__sub_82659E28) {
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
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r9,64
	ctx.r9.s64 = 64;
	// addi r10,r11,-4092
	ctx.r10.s64 = r11.s64 + -4092;
	// li r31,0
	r31.s64 = 0;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// li r3,256
	ctx.r3.s64 = 256;
	// sth r31,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r31.u16);
	// sth r9,10(r30)
	PPC_STORE_U16(r30.u32 + 10, ctx.r9.u16);
	// bl 0x82130528
	ctx.lr = 0x82659E64;
	sub_82130528(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r8,-2428
	ctx.r6.s64 = ctx.r8.s64 + -2428;
	// stw r6,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r6.u32);
	// lwz r3,-27856(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82659E80;
	sub_8238EC00(ctx, base);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// stb r31,12(r30)
	PPC_STORE_U8(r30.u32 + 12, r31.u8);
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

__attribute__((alias("__imp__sub_82659EA4"))) PPC_WEAK_FUNC(sub_82659EA4);
PPC_FUNC_IMPL(__imp__sub_82659EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82659EA8"))) PPC_WEAK_FUNC(sub_82659EA8);
PPC_FUNC_IMPL(__imp__sub_82659EA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,29
	r11.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r11,r11,0,31,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82659EC4"))) PPC_WEAK_FUNC(sub_82659EC4);
PPC_FUNC_IMPL(__imp__sub_82659EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82659EC8"))) PPC_WEAK_FUNC(sub_82659EC8);
PPC_FUNC_IMPL(__imp__sub_82659EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82659ED0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r11,-12776
	ctx.r4.s64 = r11.s64 + -12776;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r10,-7660
	r30.s64 = ctx.r10.s64 + -7660;
	// addi r27,r9,-22108
	r27.s64 = ctx.r9.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82659F0C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82659F20;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82659f38
	if (cr6.eq) goto loc_82659F38;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,27964(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27964);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82659fc8
	if (!cr6.eq) goto loc_82659FC8;
loc_82659F38:
	// addi r11,r29,-56
	r11.s64 = r29.s64 + -56;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x8265a088
	if (cr6.gt) goto loc_8265A088;
	// lis r12,-32154
	r12.s64 = -2107244544;
	// addi r12,r12,-24740
	r12.s64 = r12.s64 + -24740;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82659F7C;
	case 1:
		goto loc_8265A088;
	case 2:
		goto loc_8265A400;
	case 3:
		goto loc_8265A088;
	case 4:
		goto loc_8265A088;
	case 5:
		goto loc_8265A088;
	case 6:
		goto loc_82659FD4;
	case 7:
		goto loc_82659FC8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-24708(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24708);
	// lwz r19,-24440(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24440);
	// lwz r19,-23552(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23552);
	// lwz r19,-24440(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24440);
	// lwz r19,-24440(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24440);
	// lwz r19,-24440(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24440);
	// lwz r19,-24620(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24620);
	// lwz r19,-24632(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -24632);
loc_82659F7C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82659F8C;
	sub_826537D0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r30,r11,3408
	r30.u64 = r11.u64 | 3408;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82224a08
	ctx.lr = 0x82659FA8;
	sub_82224A08(ctx, base);
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82224a18
	ctx.lr = 0x82659FB4;
	sub_82224A18(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r10,1216(r31)
	PPC_STORE_U8(r31.u32 + 1216, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_82659FC8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_82659FD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82659FDC;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82659FEC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82659FF4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a02c
	if (cr6.eq) goto loc_8265A02C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8265A008;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8265A018;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8265A020;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265a0a0
	if (!cr6.eq) goto loc_8265A0A0;
loc_8265A02C:
	// lbz r11,5008(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5008);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a0a0
	if (cr6.eq) goto loc_8265A0A0;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,6612
	ctx.r3.s64 = r11.s64 + 6612;
	// bl 0x821fa230
	ctx.lr = 0x8265A044;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265A058;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265A070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265A088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265A088:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8265A098;
	sub_826537D0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8265A0A0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x8265A0AC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265A0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265a314
	if (cr6.eq) goto loc_8265A314;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8265A0D0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8265A0E0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8265A0E8;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265a314
	if (cr6.eq) goto loc_8265A314;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265A100;
	sub_821E6800(ctx, base);
	// lis r27,-32120
	r27.s64 = -2105016320;
	// lwz r3,-27856(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265A10C;
	sub_8238EC00(ctx, base);
	// lwz r28,864(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8265A124;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265A13C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823895f8
	ctx.lr = 0x8265A14C;
	sub_823895F8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,-10236(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,44(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 44);
	// ori r29,r7,16256
	r29.u64 = ctx.r7.u64 | 16256;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r5,48(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r5,r29
	ctx.r3.u64 = ctx.r5.u64 + r29.u64;
	// add r24,r11,r8
	r24.u64 = r11.u64 + ctx.r8.u64;
	// lwz r23,864(r31)
	r23.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// bl 0x82641cb0
	ctx.lr = 0x8265A184;
	sub_82641CB0(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r28,0(r23)
	r28.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r26,0(r22)
	r26.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8265A198;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265A1B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,788(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 788);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265A1C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,16(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 16);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpwi cr6,r8,110
	cr6.compare<int32_t>(ctx.r8.s32, 110, xer);
	// bgt cr6,0x82659fc8
	if (cr6.gt) goto loc_82659FC8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x8265A1E4;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r26,56(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// sth r28,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r28.u16);
	// sth r28,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r28.u16);
	// bl 0x82631f88
	ctx.lr = 0x8265A204;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8265a278
	if (!cr6.gt) goto loc_8265A278;
loc_8265A20C:
	// lwz r3,-27856(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265A214;
	sub_8238EC00(ctx, base);
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265A238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82389800
	ctx.lr = 0x8265A244;
	sub_82389800(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lhz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 16);
	// extsh r23,r7
	r23.s64 = ctx.r7.s16;
	// bl 0x8262e420
	ctx.lr = 0x8265A25C;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r23,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r23.u32);
	// bl 0x82631f88
	ctx.lr = 0x8265A270;
	sub_82631F88(ctx, base);
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265a20c
	if (cr6.lt) goto loc_8265A20C;
loc_8265A278:
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265A28C;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265A2A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r29
	ctx.r3.u64 = ctx.r8.u64 + r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265A2B4;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8265A2C8;
	sub_82203240(ctx, base);
	// lhz r7,16(r24)
	ctx.r7.u64 = PPC_LOAD_U16(r24.u32 + 16);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,688(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 688);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// extsh r11,r7
	r11.s64 = ctx.r7.s16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265A2F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r7,94(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8265a308
	if (cr6.eq) goto loc_8265A308;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x8265A308;
	sub_82130588(ctx, base);
loc_8265A308:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8265A314:
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r10,r31,952
	ctx.r10.s64 = r31.s64 + 952;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265a38c
	if (!cr6.eq) goto loc_8265A38C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265A330;
	sub_821E6800(ctx, base);
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,25288
	ctx.r4.s64 = ctx.r10.s64 + 25288;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8265A34C;
	sub_821C2FB0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// lwz r6,28000(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28000);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// lwz r5,27996(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 27996);
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// bl 0x826350b8
	ctx.lr = 0x8265A380;
	sub_826350B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8265A38C:
	// addi r10,r31,976
	ctx.r10.s64 = r31.s64 + 976;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265a088
	if (!cr6.eq) goto loc_8265A088;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265A3A4;
	sub_821E6800(ctx, base);
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,25288
	ctx.r4.s64 = ctx.r10.s64 + 25288;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c2fb0
	ctx.lr = 0x8265A3C0;
	sub_821C2FB0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// lwz r6,28000(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28000);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// lwz r5,27996(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 27996);
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// bl 0x826350b8
	ctx.lr = 0x8265A3F4;
	sub_826350B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8265A400:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x8265A40C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265A41C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265a088
	if (cr6.eq) goto loc_8265A088;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r10,r31,952
	ctx.r10.s64 = r31.s64 + 952;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265a088
	if (!cr6.eq) goto loc_8265A088;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265A444;
	sub_821E6800(ctx, base);
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,25288
	ctx.r4.s64 = ctx.r10.s64 + 25288;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821c2fb0
	ctx.lr = 0x8265A460;
	sub_821C2FB0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// lwz r6,28000(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28000);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// lwz r5,27996(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 27996);
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// bl 0x826350b8
	ctx.lr = 0x8265A494;
	sub_826350B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8265A4A0"))) PPC_WEAK_FUNC(sub_8265A4A0);
PPC_FUNC_IMPL(__imp__sub_8265A4A0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x8265A4A8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265A4BC;
	sub_8238EC00(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r22,r9,1
	r22.s64 = ctx.r9.s64 + 65536;
	// addi r22,r22,16256
	r22.s64 = r22.s64 + 16256;
	// addis r17,r22,2
	r17.s64 = r22.s64 + 131072;
	// addi r17,r17,-27616
	r17.s64 = r17.s64 + -27616;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265A4E4;
	sub_82654AC8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r18,0
	r18.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8265a518
	if (!cr6.eq) goto loc_8265A518;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265A4FC;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265a518
	if (!cr6.eq) goto loc_8265A518;
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265a51c
	if (cr6.eq) goto loc_8265A51C;
loc_8265A518:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265A51C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r23,r10,32896
	r23.u64 = ctx.r10.u64 | 32896;
	// beq cr6,0x8265a54c
	if (cr6.eq) goto loc_8265A54C;
	// lwzx r11,r22,r23
	r11.u64 = PPC_LOAD_U32(r22.u32 + r23.u32);
	// add r3,r22,r23
	ctx.r3.u64 = r22.u64 + r23.u64;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265A544;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// b 0x8265a550
	goto loc_8265A550;
loc_8265A54C:
	// mr r21,r18
	r21.u64 = r18.u64;
loc_8265A550:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r30,848
	r31.s64 = r30.s64 + 848;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r3,r11,2356
	ctx.r3.s64 = r11.s64 + 2356;
	// lwz r9,2352(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2352);
	// lwz r29,680(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x8265a580
	if (cr6.gt) goto loc_8265A580;
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265A580:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r27,72(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// addi r4,r10,-2524
	ctx.r4.s64 = ctx.r10.s64 + -2524;
	// bl 0x82294ef8
	ctx.lr = 0x8265A594;
	sub_82294EF8(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// bne cr6,0x8265a5ac
	if (!cr6.eq) goto loc_8265A5AC;
	// lbz r11,962(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 962);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8265a5b0
	if (!cr6.eq) goto loc_8265A5B0;
loc_8265A5AC:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265A5B0:
	// clrlwi r19,r11,24
	r19.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bge cr6,0x8265a5c0
	if (!cr6.lt) goto loc_8265A5C0;
	// bl 0x8227d3b0
	ctx.lr = 0x8265A5C0;
	sub_8227D3B0(ctx, base);
loc_8265A5C0:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8265a5f4
	if (cr6.eq) goto loc_8265A5F4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8265A5E0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8265a5e0
	if (!cr6.eq) goto loc_8265A5E0;
loc_8265A5F4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r24,r18
	r24.u64 = r18.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lbz r6,962(r17)
	ctx.r6.u64 = PPC_LOAD_U8(r17.u32 + 962);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265aba4
	if (cr6.eq) goto loc_8265ABA4;
	// lbz r11,961(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 961);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a810
	if (cr6.eq) goto loc_8265A810;
	// clrlwi r25,r19,24
	r25.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8265a6b4
	if (!cr6.eq) goto loc_8265A6B4;
	// bl 0x8227d3b0
	ctx.lr = 0x8265A634;
	sub_8227D3B0(ctx, base);
	// add r11,r22,r23
	r11.u64 = r22.u64 + r23.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r10,r11,976
	ctx.r10.s64 = r11.s64 + 976;
	// lwz r9,864(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 864);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265a66c
	if (!cr6.eq) goto loc_8265A66C;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265A654;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265a66c
	if (!cr6.eq) goto loc_8265A66C;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// ble cr6,0x8265a66c
	if (!cr6.gt) goto loc_8265A66C;
	// li r29,8
	r29.s64 = 8;
loc_8265A66C:
	// lwz r11,1088(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1088);
	// srawi r10,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	ctx.r10.s64 = r29.s32 >> 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// addi r3,r30,1088
	ctx.r3.s64 = r30.s64 + 1088;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,28076
	ctx.r4.s64 = ctx.r9.s64 + 28076;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addze r5,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r5.s64 = temp.s64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265A694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r7,r30,3568
	ctx.r7.s64 = r30.s64 + 3568;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r9,r6,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
loc_8265A6B4:
	// lbz r11,961(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 961);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a6d0
	if (cr6.eq) goto loc_8265A6D0;
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265a6d4
	if (cr6.eq) goto loc_8265A6D4;
loc_8265A6D0:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265A6D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a71c
	if (cr6.eq) goto loc_8265A71C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8265a71c
	if (!cr6.eq) goto loc_8265A71C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265a71c
	if (!cr6.eq) goto loc_8265A71C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656a88
	ctx.lr = 0x8265A6FC;
	sub_82656A88(ctx, base);
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r30,3328
	ctx.r8.s64 = r30.s64 + 3328;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// rotlwi r9,r7,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A71C:
	// addi r29,r30,3996
	r29.s64 = r30.s64 + 3996;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826b6228
	ctx.lr = 0x8265A728;
	sub_826B6228(ctx, base);
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265a754
	if (cr6.eq) goto loc_8265A754;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r8,r30,4528
	ctx.r8.s64 = r30.s64 + 4528;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A754:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x8265a77c
	if (!cr6.eq) goto loc_8265A77C;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r8,r30,4536
	ctx.r8.s64 = r30.s64 + 4536;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A77C:
	// li r28,2
	r28.s64 = 2;
	// addi r27,r30,4600
	r27.s64 = r30.s64 + 4600;
	// li r26,-1
	r26.s64 = -1;
loc_8265A788:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8265a798
	if (cr6.eq) goto loc_8265A798;
	// cmpwi cr6,r28,6
	cr6.compare<int32_t>(r28.s32, 6, xer);
	// beq cr6,0x8265a7f0
	if (cr6.eq) goto loc_8265A7F0;
loc_8265A798:
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// addi r16,r1,88
	r16.s64 = ctx.r1.s64 + 88;
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r18.u32);
	// addi r15,r28,-2
	r15.s64 = r28.s64 + -2;
	// bl 0x82387b90
	ctx.lr = 0x8265A7AC;
	sub_82387B90(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// bl 0x8238aec0
	ctx.lr = 0x8265A7B8;
	sub_8238AEC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8265a7e0
	if (cr6.lt) goto loc_8265A7E0;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
loc_8265A7E0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bne cr6,0x8265a788
	if (!cr6.eq) goto loc_8265A788;
loc_8265A7F0:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,3808
	ctx.r8.s64 = r30.s64 + 3808;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A810:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265A818;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265a848
	if (!cr6.eq) goto loc_8265A848;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265A82C;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265a848
	if (!cr6.eq) goto loc_8265A848;
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265a84c
	if (cr6.eq) goto loc_8265A84C;
loc_8265A848:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265A84C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265aa04
	if (cr6.eq) goto loc_8265AA04;
	// add r29,r22,r23
	r29.u64 = r22.u64 + r23.u64;
	// addi r11,r29,976
	r11.s64 = r29.s64 + 976;
	// lwz r10,864(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 864);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8265a874
	if (!cr6.eq) goto loc_8265A874;
	// li r24,2
	r24.s64 = 2;
	// b 0x8265a8a8
	goto loc_8265A8A8;
loc_8265A874:
	// li r11,-1
	r11.s64 = -1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823895f8
	ctx.lr = 0x8265A88C;
	sub_823895F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265a8a8
	if (cr6.eq) goto loc_8265A8A8;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82388c48
	ctx.lr = 0x8265A8A4;
	sub_82388C48(ctx, base);
	// lwz r24,4(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_8265A8A8:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8238eb20
	ctx.lr = 0x8265A8B0;
	sub_8238EB20(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x8265a968
	if (!cr6.eq) goto loc_8265A968;
	// cmpwi cr6,r24,13
	cr6.compare<int32_t>(r24.s32, 13, xer);
	// beq cr6,0x8265a8e0
	if (cr6.eq) goto loc_8265A8E0;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,4624
	ctx.r8.s64 = r30.s64 + 4624;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A8E0:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,4880
	ctx.r8.s64 = r30.s64 + 4880;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r30,5136
	ctx.r7.s64 = r30.s64 + 5136;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// bl 0x8238eab8
	ctx.lr = 0x8265A924;
	sub_8238EAB8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8265a950
	if (cr6.eq) goto loc_8265A950;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,5376
	ctx.r8.s64 = r30.s64 + 5376;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A950:
	// cmpwi cr6,r24,11
	cr6.compare<int32_t>(r24.s32, 11, xer);
	// beq cr6,0x8265a9fc
	if (cr6.eq) goto loc_8265A9FC;
	// cmpwi cr6,r24,12
	cr6.compare<int32_t>(r24.s32, 12, xer);
	// beq cr6,0x8265a9fc
	if (cr6.eq) goto loc_8265A9FC;
	// addi r8,r30,5616
	ctx.r8.s64 = r30.s64 + 5616;
	// b 0x8265a9e0
	goto loc_8265A9E0;
loc_8265A968:
	// cmpwi cr6,r24,2
	cr6.compare<int32_t>(r24.s32, 2, xer);
	// bne cr6,0x8265a9b8
	if (!cr6.eq) goto loc_8265A9B8;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1392
	ctx.r8.s64 = r30.s64 + 1392;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r30,3088
	ctx.r7.s64 = r30.s64 + 3088;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// clrlwi r5,r19,24
	ctx.r5.u64 = r19.u32 & 0xFF;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rotlwi r9,r3,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// stwx r7,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r7.u32);
	// b 0x8265a9c8
	goto loc_8265A9C8;
loc_8265A9B8:
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// bne cr6,0x8265a9fc
	if (!cr6.eq) goto loc_8265A9FC;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_8265A9C8:
	// bne cr6,0x8265a9fc
	if (!cr6.eq) goto loc_8265A9FC;
	// lwz r11,864(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 864);
	// addi r10,r29,976
	ctx.r10.s64 = r29.s64 + 976;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8265a9fc
	if (cr6.eq) goto loc_8265A9FC;
	// addi r8,r30,4288
	ctx.r8.s64 = r30.s64 + 4288;
loc_8265A9E0:
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265A9FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82658218
	ctx.lr = 0x8265AA04;
	sub_82658218(ctx, base);
loc_8265AA04:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265AA0C;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265aa44
	if (cr6.eq) goto loc_8265AA44;
	// lbz r11,961(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 961);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265aa34
	if (cr6.eq) goto loc_8265AA34;
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265aa38
	if (cr6.eq) goto loc_8265AA38;
loc_8265AA34:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265AA38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265ab9c
	if (cr6.eq) goto loc_8265AB9C;
loc_8265AA44:
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265AA4C;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265aa7c
	if (!cr6.eq) goto loc_8265AA7C;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265AA60;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265aa7c
	if (!cr6.eq) goto loc_8265AA7C;
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265aa80
	if (cr6.eq) goto loc_8265AA80;
loc_8265AA7C:
	// mr r11,r18
	r11.u64 = r18.u64;
loc_8265AA80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265ab5c
	if (!cr6.eq) goto loc_8265AB5C;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265AA94;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265ab5c
	if (!cr6.eq) goto loc_8265AB5C;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265ab5c
	if (!cr6.eq) goto loc_8265AB5C;
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// addi r29,r11,-4744
	r29.s64 = r11.s64 + -4744;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265AAC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265AAC8:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x8265aaec
	if (cr6.eq) goto loc_8265AAEC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8265aac8
	if (cr6.eq) goto loc_8265AAC8;
loc_8265AAEC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8265ab3c
	if (cr6.eq) goto loc_8265AB3C;
	// lwz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// addi r29,r11,-4680
	r29.s64 = r11.s64 + -4680;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265AB10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265AB10:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x8265ab34
	if (cr6.eq) goto loc_8265AB34;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8265ab10
	if (cr6.eq) goto loc_8265AB10;
loc_8265AB34:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8265ab5c
	if (!cr6.eq) goto loc_8265AB5C;
loc_8265AB3C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,4048
	ctx.r8.s64 = r30.s64 + 4048;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265AB5C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1888
	ctx.r8.s64 = r30.s64 + 1888;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r30,2608
	ctx.r7.s64 = r30.s64 + 2608;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r6.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
loc_8265AB9C:
	// addi r8,r30,2368
	ctx.r8.s64 = r30.s64 + 2368;
	// b 0x8265ad14
	goto loc_8265AD14;
loc_8265ABA4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r3,r11,-2380
	ctx.r3.s64 = r11.s64 + -2380;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8265ABBC;
	sub_82130000(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823895f8
	ctx.lr = 0x8265ABCC;
	sub_823895F8(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82388c48
	ctx.lr = 0x8265ABD8;
	sub_82388C48(ctx, base);
	// lbz r9,8532(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 8532);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265ac34
	if (cr6.eq) goto loc_8265AC34;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8265ac10
	if (!cr6.eq) goto loc_8265AC10;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1392
	ctx.r8.s64 = r30.s64 + 1392;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265AC10:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1648
	ctx.r8.s64 = r30.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// b 0x8265ad10
	goto loc_8265AD10;
loc_8265AC34:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1136
	ctx.r8.s64 = r30.s64 + 1136;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x8265ac80
	if (!cr6.eq) goto loc_8265AC80;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,3088
	ctx.r8.s64 = r30.s64 + 3088;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265AC80:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1648
	ctx.r8.s64 = r30.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x8265accc
	if (!cr6.eq) goto loc_8265ACCC;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1392
	ctx.r8.s64 = r30.s64 + 1392;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8265ACCC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82658218
	ctx.lr = 0x8265ACD4;
	sub_82658218(ctx, base);
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r30,2128
	ctx.r8.s64 = r30.s64 + 2128;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// rotlwi r11,r6,2
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// addi r7,r30,1888
	ctx.r7.s64 = r30.s64 + 1888;
	// sth r5,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r5.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rotlwi r11,r3,2
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
loc_8265AD10:
	// addi r8,r30,2608
	ctx.r8.s64 = r30.s64 + 2608;
loc_8265AD14:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r3,r30,928
	ctx.r3.s64 = r30.s64 + 928;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lbz r11,960(r17)
	r11.u64 = PPC_LOAD_U8(r17.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,928(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 928);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// beq cr6,0x8265ad94
	if (cr6.eq) goto loc_8265AD94;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,28244
	ctx.r4.s64 = ctx.r10.s64 + 28244;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265AD60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,992(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,28220
	ctx.r4.s64 = ctx.r8.s64 + 28220;
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// li r5,6
	ctx.r5.s64 = 6;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265AD84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,28268
	ctx.r4.s64 = ctx.r10.s64 + 28268;
	// b 0x8265add8
	goto loc_8265ADD8;
loc_8265AD94:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r10,-28096
	ctx.r4.s64 = ctx.r10.s64 + -28096;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265ADA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,992(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-28076
	ctx.r4.s64 = ctx.r8.s64 + -28076;
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// li r5,5
	ctx.r5.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265ADCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r10,28024
	ctx.r4.s64 = ctx.r10.s64 + 28024;
loc_8265ADD8:
	// lwz r9,976(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 976);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r30,976
	ctx.r3.s64 = r30.s64 + 976;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265ADF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265AE04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8265AE0C"))) PPC_WEAK_FUNC(sub_8265AE0C);
PPC_FUNC_IMPL(__imp__sub_8265AE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265AE10"))) PPC_WEAK_FUNC(sub_8265AE10);
PPC_FUNC_IMPL(__imp__sub_8265AE10) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265AE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8265ae50
	if (!cr6.eq) goto loc_8265AE50;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265a4a0
	ctx.lr = 0x8265AE4C;
	sub_8265A4A0(ctx, base);
	// b 0x8265aea8
	goto loc_8265AEA8;
loc_8265AE50:
	// addi r30,r31,3060
	r30.s64 = r31.s64 + 3060;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265AE64:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265ae64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265AE64;
	// addi r3,r31,2848
	ctx.r3.s64 = r31.s64 + 2848;
	// lwz r4,8544(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8544);
	// bl 0x8262fff0
	ctx.lr = 0x8265AE84;
	sub_8262FFF0(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265AE94:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265ae94
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265AE94;
loc_8265AEA8:
	// lwz r11,3056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// stw r11,8544(r31)
	PPC_STORE_U32(r31.u32 + 8544, r11.u32);
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

__attribute__((alias("__imp__sub_8265AEC8"))) PPC_WEAK_FUNC(sub_8265AEC8);
PPC_FUNC_IMPL(__imp__sub_8265AEC8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,3056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8265af64
	if (cr6.eq) goto loc_8265AF64;
	// lbz r10,8540(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8540);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265af64
	if (!cr6.eq) goto loc_8265AF64;
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32154
	ctx.r10.s64 = -2107244544;
	// stb r11,8540(r31)
	PPC_STORE_U8(r31.u32 + 8540, r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-20976
	ctx.r4.s64 = ctx.r10.s64 + -20976;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8265AF18;
	sub_821C2FB0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r9,-2344
	ctx.r6.s64 = ctx.r9.s64 + -2344;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r8,-2364
	ctx.r5.s64 = ctx.r8.s64 + -2364;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,8560
	ctx.r3.s64 = r31.s64 + 8560;
	// bl 0x82634ec8
	ctx.lr = 0x8265AF50;
	sub_82634EC8(ctx, base);
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
loc_8265AF64:
	// stw r11,8544(r31)
	PPC_STORE_U32(r31.u32 + 8544, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265a4a0
	ctx.lr = 0x8265AF70;
	sub_8265A4A0(ctx, base);
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

__attribute__((alias("__imp__sub_8265AF84"))) PPC_WEAK_FUNC(sub_8265AF84);
PPC_FUNC_IMPL(__imp__sub_8265AF84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265AF88"))) PPC_WEAK_FUNC(sub_8265AF88);
PPC_FUNC_IMPL(__imp__sub_8265AF88) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265AFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8265aff0
	if (!cr6.eq) goto loc_8265AFF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826583c0
	ctx.lr = 0x8265AFC0;
	sub_826583C0(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265AFD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82658c28
	ctx.lr = 0x8265AFDC;
	sub_82658C28(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265AFF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265AFF0:
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

__attribute__((alias("__imp__sub_8265B004"))) PPC_WEAK_FUNC(sub_8265B004);
PPC_FUNC_IMPL(__imp__sub_8265B004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B008"))) PPC_WEAK_FUNC(sub_8265B008);
PPC_FUNC_IMPL(__imp__sub_8265B008) {
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
	ctx.lr = 0x8265B010;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x82653be8
	ctx.lr = 0x8265B030;
	sub_82653BE8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,496
	r30.s64 = r31.s64 + 496;
	// addi r10,r11,-2316
	ctx.r10.s64 = r11.s64 + -2316;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633a10
	ctx.lr = 0x8265B050;
	sub_82633A10(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// addi r8,r9,4916
	ctx.r8.s64 = ctx.r9.s64 + 4916;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r8,496(r31)
	PPC_STORE_U32(r31.u32 + 496, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82634738
	ctx.lr = 0x8265B070;
	sub_82634738(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lis r6,-32215
	ctx.r6.s64 = -2111242240;
	// addi r5,r7,-4044
	ctx.r5.s64 = ctx.r7.s64 + -4044;
	// addi r4,r6,-26040
	ctx.r4.s64 = ctx.r6.s64 + -26040;
	// stw r5,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r5.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r28,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r28.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821c2f90
	ctx.lr = 0x8265B094;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265B0A4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265b0a4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265B0A4;
	// addi r10,r31,908
	ctx.r10.s64 = r31.s64 + 908;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265B0C8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265b0c8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265B0C8;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r29,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r29.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8265B11C"))) PPC_WEAK_FUNC(sub_8265B11C);
PPC_FUNC_IMPL(__imp__sub_8265B11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B120"))) PPC_WEAK_FUNC(sub_8265B120);
PPC_FUNC_IMPL(__imp__sub_8265B120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// addi r3,r3,496
	ctx.r3.s64 = ctx.r3.s64 + 496;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8265B134"))) PPC_WEAK_FUNC(sub_8265B134);
PPC_FUNC_IMPL(__imp__sub_8265B134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B138"))) PPC_WEAK_FUNC(sub_8265B138);
PPC_FUNC_IMPL(__imp__sub_8265B138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,496(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// addi r3,r3,496
	ctx.r3.s64 = ctx.r3.s64 + 496;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8265B14C"))) PPC_WEAK_FUNC(sub_8265B14C);
PPC_FUNC_IMPL(__imp__sub_8265B14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B150"))) PPC_WEAK_FUNC(sub_8265B150);
PPC_FUNC_IMPL(__imp__sub_8265B150) {
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
	// addi r31,r30,672
	r31.s64 = r30.s64 + 672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8265B174;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265b184
	if (cr6.lt) goto loc_8265B184;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265B184:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8265b1c8
	if (cr6.lt) goto loc_8265B1C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,864(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// bl 0x82631f88
	ctx.lr = 0x8265B198;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265b1a8
	if (cr6.lt) goto loc_8265B1A8;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265B1A8:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265B1C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8265b1cc
	goto loc_8265B1CC;
loc_8265B1C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8265B1CC:
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

__attribute__((alias("__imp__sub_8265B1E4"))) PPC_WEAK_FUNC(sub_8265B1E4);
PPC_FUNC_IMPL(__imp__sub_8265B1E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B1E8"))) PPC_WEAK_FUNC(sub_8265B1E8);
PPC_FUNC_IMPL(__imp__sub_8265B1E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r31,928
	r30.s64 = r31.s64 + 928;
	// addi r4,r9,-684
	ctx.r4.s64 = ctx.r9.s64 + -684;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r8,r11,28572
	ctx.r8.s64 = r11.s64 + 28572;
	// addi r5,r10,-704
	ctx.r5.s64 = ctx.r10.s64 + -704;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,2
	ctx.r7.s64 = 2;
	// bl 0x8265b008
	ctx.lr = 0x8265B22C;
	sub_8265B008(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r7,r8,-1508
	ctx.r7.s64 = ctx.r8.s64 + -1508;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x8265B240;
	sub_82659E28(ctx, base);
	// addi r3,r31,952
	ctx.r3.s64 = r31.s64 + 952;
	// bl 0x826597b8
	ctx.lr = 0x8265B248;
	sub_826597B8(ctx, base);
	// addi r3,r31,976
	ctx.r3.s64 = r31.s64 + 976;
	// bl 0x82659db8
	ctx.lr = 0x8265B250;
	sub_82659DB8(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x82659e28
	ctx.lr = 0x8265B258;
	sub_82659E28(ctx, base);
	// addi r3,r31,1016
	ctx.r3.s64 = r31.s64 + 1016;
	// bl 0x826597b8
	ctx.lr = 0x8265B260;
	sub_826597B8(ctx, base);
	// addi r3,r31,1040
	ctx.r3.s64 = r31.s64 + 1040;
	// bl 0x82659db8
	ctx.lr = 0x8265B268;
	sub_82659DB8(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r10,r4,-4144
	ctx.r10.s64 = ctx.r4.s64 + -4144;
	// lfs f13,-28964(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -28964);
	ctx.f13.f64 = double(temp.f32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f13,1228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1228, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f0,1220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1220, temp.u32);
	// addi r7,r3,18928
	ctx.r7.s64 = ctx.r3.s64 + 18928;
	// stfs f0,1224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1224, temp.u32);
	// stw r30,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r30.u32);
	// lfs f13,21528(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21528);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, r30.u32);
	// addi r3,r31,1424
	ctx.r3.s64 = r31.s64 + 1424;
	// stb r30,1216(r31)
	PPC_STORE_U8(r31.u32 + 1216, r30.u8);
	// stw r30,1364(r31)
	PPC_STORE_U32(r31.u32 + 1364, r30.u32);
	// stw r9,1368(r31)
	PPC_STORE_U32(r31.u32 + 1368, ctx.r9.u32);
	// stw r8,1372(r31)
	PPC_STORE_U32(r31.u32 + 1372, ctx.r8.u32);
	// stw r10,1360(r31)
	PPC_STORE_U32(r31.u32 + 1360, ctx.r10.u32);
	// stw r30,1380(r31)
	PPC_STORE_U32(r31.u32 + 1380, r30.u32);
	// stw r7,1376(r31)
	PPC_STORE_U32(r31.u32 + 1376, ctx.r7.u32);
	// stfs f13,1408(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1408, temp.u32);
	// stfs f0,1412(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1412, temp.u32);
	// bl 0x82634b60
	ctx.lr = 0x8265B2DC;
	sub_82634B60(ctx, base);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// bl 0x82634b60
	ctx.lr = 0x8265B2E4;
	sub_82634B60(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r5,-32155
	ctx.r5.s64 = -2107310080;
	// addi r4,r6,-3372
	ctx.r4.s64 = ctx.r6.s64 + -3372;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r4,3216(r31)
	PPC_STORE_U32(r31.u32 + 3216, ctx.r4.u32);
	// addi r4,r5,22568
	ctx.r4.s64 = ctx.r5.s64 + 22568;
	// stb r30,5008(r31)
	PPC_STORE_U8(r31.u32 + 5008, r30.u8);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821c2f90
	ctx.lr = 0x8265B308;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265B318:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265b318
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265B318;
	// addi r10,r31,888
	ctx.r10.s64 = r31.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265B33C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265b33c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265B33C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8265B36C"))) PPC_WEAK_FUNC(sub_8265B36C);
PPC_FUNC_IMPL(__imp__sub_8265B36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B370"))) PPC_WEAK_FUNC(sub_8265B370);
PPC_FUNC_IMPL(__imp__sub_8265B370) {
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
	// bl 0x826440a8
	ctx.lr = 0x8265B390;
	sub_826440A8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265b3a8
	if (cr6.eq) goto loc_8265B3A8;
	// bl 0x82130588
	ctx.lr = 0x8265B3A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265B3A8:
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

__attribute__((alias("__imp__sub_8265B3C0"))) PPC_WEAK_FUNC(sub_8265B3C0);
PPC_FUNC_IMPL(__imp__sub_8265B3C0) {
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
	// bl 0x82656c20
	ctx.lr = 0x8265B3E0;
	sub_82656C20(ctx, base);
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// lbz r10,13(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// stb r10,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r10.u8);
	// lbz r9,14(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 14);
	// stb r9,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r9.u8);
	// lbz r8,15(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 15);
	// stb r8,15(r31)
	PPC_STORE_U8(r31.u32 + 15, ctx.r8.u8);
	// lbz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// stb r7,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r7.u8);
	// lwz r6,20(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8265B42C"))) PPC_WEAK_FUNC(sub_8265B42C);
PPC_FUNC_IMPL(__imp__sub_8265B42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B430"))) PPC_WEAK_FUNC(sub_8265B430);
PPC_FUNC_IMPL(__imp__sub_8265B430) {
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
	ctx.lr = 0x8265B438;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r31,952
	ctx.r4.s64 = r31.s64 + 952;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x8265b484
	if (!cr6.eq) goto loc_8265B484;
	// addi r30,r31,1016
	r30.s64 = r31.s64 + 1016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8265b3c0
	ctx.lr = 0x8265B45C;
	sub_8265B3C0(ctx, base);
	// stw r30,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r30.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8265B468;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265b478
	if (cr6.lt) goto loc_8265B478;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265B478:
	// stw r11,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265B484:
	// addi r29,r31,976
	r29.s64 = r31.s64 + 976;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x8265b4ac
	if (!cr6.eq) goto loc_8265B4AC;
	// addi r30,r31,1040
	r30.s64 = r31.s64 + 1040;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82656c20
	ctx.lr = 0x8265B4A0;
	sub_82656C20(ctx, base);
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r11,1052(r31)
	PPC_STORE_U32(r31.u32 + 1052, r11.u32);
	// b 0x8265b4bc
	goto loc_8265B4BC;
loc_8265B4AC:
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// addi r4,r31,928
	ctx.r4.s64 = r31.s64 + 928;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8265b3c0
	ctx.lr = 0x8265B4BC;
	sub_8265B3C0(ctx, base);
loc_8265B4BC:
	// stw r30,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, r30.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8265B4C8;
	sub_82203240(ctx, base);
	// stw r3,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265B4D4"))) PPC_WEAK_FUNC(sub_8265B4D4);
PPC_FUNC_IMPL(__imp__sub_8265B4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265B4D8"))) PPC_WEAK_FUNC(sub_8265B4D8);
PPC_FUNC_IMPL(__imp__sub_8265B4D8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8265B4E0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,548
	ctx.r4.s64 = ctx.r9.s64 + 548;
	// addi r7,r11,28124
	ctx.r7.s64 = r11.s64 + 28124;
	// addi r5,r10,528
	ctx.r5.s64 = ctx.r10.s64 + 528;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r6,30
	ctx.r6.s64 = 30;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826540c0
	ctx.lr = 0x8265B510;
	sub_826540C0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r4,r8,-268
	ctx.r4.s64 = ctx.r8.s64 + -268;
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// addi r8,r7,7428
	ctx.r8.s64 = ctx.r7.s64 + 7428;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r7,r6,-28096
	ctx.r7.s64 = ctx.r6.s64 + -28096;
	// stw r8,928(r31)
	PPC_STORE_U32(r31.u32 + 928, ctx.r8.u32);
	// li r27,5
	r27.s64 = 5;
	// stw r30,940(r31)
	PPC_STORE_U32(r31.u32 + 940, r30.u32);
	// addi r5,r5,27980
	ctx.r5.s64 = ctx.r5.s64 + 27980;
	// stw r7,932(r31)
	PPC_STORE_U32(r31.u32 + 932, ctx.r7.u32);
	// lis r3,-32129
	ctx.r3.s64 = -2105606144;
	// stw r27,936(r31)
	PPC_STORE_U32(r31.u32 + 936, r27.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r5,948(r31)
	PPC_STORE_U32(r31.u32 + 948, ctx.r5.u32);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r8,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r8.u32);
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// stw r4,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r4.u32);
	// addi r7,r3,-28056
	ctx.r7.s64 = ctx.r3.s64 + -28056;
	// stw r30,956(r31)
	PPC_STORE_U32(r31.u32 + 956, r30.u32);
	// li r11,3
	r11.s64 = 3;
	// stw r8,960(r31)
	PPC_STORE_U32(r31.u32 + 960, ctx.r8.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// stw r7,964(r31)
	PPC_STORE_U32(r31.u32 + 964, ctx.r7.u32);
	// addi r4,r6,28024
	ctx.r4.s64 = ctx.r6.s64 + 28024;
	// stw r11,968(r31)
	PPC_STORE_U32(r31.u32 + 968, r11.u32);
	// addi r3,r9,-28076
	ctx.r3.s64 = ctx.r9.s64 + -28076;
	// stw r30,972(r31)
	PPC_STORE_U32(r31.u32 + 972, r30.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r4,980(r31)
	PPC_STORE_U32(r31.u32 + 980, ctx.r4.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stw r8,976(r31)
	PPC_STORE_U32(r31.u32 + 976, ctx.r8.u32);
	// addi r7,r5,28012
	ctx.r7.s64 = ctx.r5.s64 + 28012;
	// stw r10,984(r31)
	PPC_STORE_U32(r31.u32 + 984, ctx.r10.u32);
	// stw r30,988(r31)
	PPC_STORE_U32(r31.u32 + 988, r30.u32);
	// addi r6,r9,28036
	ctx.r6.s64 = ctx.r9.s64 + 28036;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// stw r8,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r8.u32);
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// stw r27,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r27.u32);
	// addi r24,r31,928
	r24.s64 = r31.s64 + 928;
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// addi r23,r31,944
	r23.s64 = r31.s64 + 944;
	// stw r7,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, ctx.r7.u32);
	// addi r22,r31,960
	r22.s64 = r31.s64 + 960;
	// stw r8,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r8.u32);
	// addi r21,r31,976
	r21.s64 = r31.s64 + 976;
	// stw r11,1016(r31)
	PPC_STORE_U32(r31.u32 + 1016, r11.u32);
	// addi r20,r31,992
	r20.s64 = r31.s64 + 992;
	// stw r30,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r30.u32);
	// addi r19,r31,1008
	r19.s64 = r31.s64 + 1008;
	// stw r4,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, ctx.r4.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r8,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, ctx.r8.u32);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stw r10,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r10.u32);
	// addi r4,r3,27920
	ctx.r4.s64 = ctx.r3.s64 + 27920;
	// stw r30,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r30.u32);
	// stw r6,1044(r31)
	PPC_STORE_U32(r31.u32 + 1044, ctx.r6.u32);
	// addi r6,r5,28056
	ctx.r6.s64 = ctx.r5.s64 + 28056;
	// stw r8,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r8.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// stw r27,1048(r31)
	PPC_STORE_U32(r31.u32 + 1048, r27.u32);
	// stw r30,1052(r31)
	PPC_STORE_U32(r31.u32 + 1052, r30.u32);
	// stw r8,1056(r31)
	PPC_STORE_U32(r31.u32 + 1056, ctx.r8.u32);
	// lis r3,-32126
	ctx.r3.s64 = -2105409536;
	// stw r6,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, ctx.r6.u32);
	// addi r7,r7,28076
	ctx.r7.s64 = ctx.r7.s64 + 28076;
	// stw r27,1064(r31)
	PPC_STORE_U32(r31.u32 + 1064, r27.u32);
	// stw r30,1068(r31)
	PPC_STORE_U32(r31.u32 + 1068, r30.u32);
	// addi r6,r5,28108
	ctx.r6.s64 = ctx.r5.s64 + 28108;
	// stw r4,1076(r31)
	PPC_STORE_U32(r31.u32 + 1076, ctx.r4.u32);
	// addi r28,r3,28120
	r28.s64 = ctx.r3.s64 + 28120;
	// stw r8,1072(r31)
	PPC_STORE_U32(r31.u32 + 1072, ctx.r8.u32);
	// addi r26,r31,1136
	r26.s64 = r31.s64 + 1136;
	// stw r9,1080(r31)
	PPC_STORE_U32(r31.u32 + 1080, ctx.r9.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// stw r30,1084(r31)
	PPC_STORE_U32(r31.u32 + 1084, r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,1088(r31)
	PPC_STORE_U32(r31.u32 + 1088, ctx.r8.u32);
	// addi r4,r4,-296
	ctx.r4.s64 = ctx.r4.s64 + -296;
	// stw r7,1092(r31)
	PPC_STORE_U32(r31.u32 + 1092, ctx.r7.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r9,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, ctx.r9.u32);
	// addi r29,r31,1024
	r29.s64 = r31.s64 + 1024;
	// stw r30,1100(r31)
	PPC_STORE_U32(r31.u32 + 1100, r30.u32);
	// addi r18,r31,1072
	r18.s64 = r31.s64 + 1072;
	// stw r11,1112(r31)
	PPC_STORE_U32(r31.u32 + 1112, r11.u32);
	// addi r11,r31,1104
	r11.s64 = r31.s64 + 1104;
	// stw r8,1104(r31)
	PPC_STORE_U32(r31.u32 + 1104, ctx.r8.u32);
	// addi r11,r31,1120
	r11.s64 = r31.s64 + 1120;
	// stw r6,1108(r31)
	PPC_STORE_U32(r31.u32 + 1108, ctx.r6.u32);
	// addi r17,r31,1088
	r17.s64 = r31.s64 + 1088;
	// stw r30,1116(r31)
	PPC_STORE_U32(r31.u32 + 1116, r30.u32);
	// stw r8,1120(r31)
	PPC_STORE_U32(r31.u32 + 1120, ctx.r8.u32);
	// stw r28,1124(r31)
	PPC_STORE_U32(r31.u32 + 1124, r28.u32);
	// stw r10,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, ctx.r10.u32);
	// stw r30,1132(r31)
	PPC_STORE_U32(r31.u32 + 1132, r30.u32);
	// bl 0x82633d40
	ctx.lr = 0x8265B6B0;
	sub_82633D40(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r30,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r30.u32);
	// addi r3,r26,228
	ctx.r3.s64 = r26.s64 + 228;
	// addi r16,r11,-29700
	r16.s64 = r11.s64 + -29700;
	// stw r30,1348(r31)
	PPC_STORE_U32(r31.u32 + 1348, r30.u32);
	// stw r30,1352(r31)
	PPC_STORE_U32(r31.u32 + 1352, r30.u32);
	// stw r16,1136(r31)
	PPC_STORE_U32(r31.u32 + 1136, r16.u32);
	// stw r30,1356(r31)
	PPC_STORE_U32(r31.u32 + 1356, r30.u32);
	// stb r30,1360(r31)
	PPC_STORE_U8(r31.u32 + 1360, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8265B6D8;
	sub_821C2F70(ctx, base);
	// lis r15,-32126
	r15.s64 = -2105409536;
	// lis r14,-32126
	r14.s64 = -2105409536;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r25,r31,1392
	r25.s64 = r31.s64 + 1392;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,24600(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24600);
	// addi r4,r10,-312
	ctx.r4.s64 = ctx.r10.s64 + -312;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,1384(r31)
	PPC_STORE_U32(r31.u32 + 1384, r11.u32);
	// lwz r11,24596(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 24596);
	// stw r11,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8265B708;
	sub_82633D40(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// stw r16,1392(r31)
	PPC_STORE_U32(r31.u32 + 1392, r16.u32);
	// addi r3,r25,228
	ctx.r3.s64 = r25.s64 + 228;
	// stw r30,1600(r31)
	PPC_STORE_U32(r31.u32 + 1600, r30.u32);
	// stw r27,1604(r31)
	PPC_STORE_U32(r31.u32 + 1604, r27.u32);
	// stw r28,1608(r31)
	PPC_STORE_U32(r31.u32 + 1608, r28.u32);
	// stw r30,1612(r31)
	PPC_STORE_U32(r31.u32 + 1612, r30.u32);
	// stb r30,1616(r31)
	PPC_STORE_U8(r31.u32 + 1616, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8265B72C;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24600);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r31,1648
	ctx.r3.s64 = r31.s64 + 1648;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// stw r11,1640(r31)
	PPC_STORE_U32(r31.u32 + 1640, r11.u32);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// lwz r11,24596(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 24596);
	// stw r11,1644(r31)
	PPC_STORE_U32(r31.u32 + 1644, r11.u32);
	// bl 0x826349f0
	ctx.lr = 0x8265B754;
	sub_826349F0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r31,1888
	ctx.r3.s64 = r31.s64 + 1888;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,6484
	ctx.r4.s64 = ctx.r8.s64 + 6484;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265B76C;
	sub_826349F0(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r3,r31,2128
	ctx.r3.s64 = r31.s64 + 2128;
	// addi r24,r7,6472
	r24.s64 = ctx.r7.s64 + 6472;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265B788;
	sub_826349F0(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r3,r31,2368
	ctx.r3.s64 = r31.s64 + 2368;
	// bl 0x826349f0
	ctx.lr = 0x8265B79C;
	sub_826349F0(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r3,r31,2608
	ctx.r3.s64 = r31.s64 + 2608;
	// addi r4,r5,6496
	ctx.r4.s64 = ctx.r5.s64 + 6496;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265B7B4;
	sub_826349F0(ctx, base);
	// addi r22,r31,2848
	r22.s64 = r31.s64 + 2848;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r4,6452
	ctx.r4.s64 = ctx.r4.s64 + 6452;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265B7D0;
	sub_826349F0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,3088
	ctx.r3.s64 = r31.s64 + 3088;
	// addi r4,r11,2036
	ctx.r4.s64 = r11.s64 + 2036;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265B7E8;
	sub_826349F0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-344
	ctx.r4.s64 = ctx.r10.s64 + -344;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// addi r3,r31,3328
	ctx.r3.s64 = r31.s64 + 3328;
	// bl 0x826349f0
	ctx.lr = 0x8265B800;
	sub_826349F0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-360
	ctx.r4.s64 = ctx.r9.s64 + -360;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// addi r3,r31,3568
	ctx.r3.s64 = r31.s64 + 3568;
	// bl 0x826349f0
	ctx.lr = 0x8265B818;
	sub_826349F0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-376
	ctx.r4.s64 = ctx.r8.s64 + -376;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r3,r31,3808
	ctx.r3.s64 = r31.s64 + 3808;
	// bl 0x82634908
	ctx.lr = 0x8265B830;
	sub_82634908(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r5,r31,1104
	ctx.r5.s64 = r31.s64 + 1104;
	// addi r24,r7,-388
	r24.s64 = ctx.r7.s64 + -388;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// bl 0x826349f0
	ctx.lr = 0x8265B84C;
	sub_826349F0(ctx, base);
	// addi r5,r31,1120
	ctx.r5.s64 = r31.s64 + 1120;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,4288
	ctx.r3.s64 = r31.s64 + 4288;
	// bl 0x826349f0
	ctx.lr = 0x8265B860;
	sub_826349F0(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r24,r6,5568
	r24.s64 = ctx.r6.s64 + 5568;
	// addi r21,r31,4528
	r21.s64 = r31.s64 + 4528;
	// stw r24,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r24.u32);
	// addi r4,r5,-5396
	ctx.r4.s64 = ctx.r5.s64 + -5396;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x826311f8
	ctx.lr = 0x8265B880;
	sub_826311F8(ctx, base);
	// stw r24,4536(r31)
	PPC_STORE_U32(r31.u32 + 4536, r24.u32);
	// addi r20,r31,4536
	r20.s64 = r31.s64 + 4536;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r4,r4,-396
	ctx.r4.s64 = ctx.r4.s64 + -396;
	// bl 0x826311f8
	ctx.lr = 0x8265B898;
	sub_826311F8(ctx, base);
	// stw r24,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r24.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r19,r31,4544
	r19.s64 = r31.s64 + 4544;
	// addi r4,r11,6180
	ctx.r4.s64 = r11.s64 + 6180;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x826311f8
	ctx.lr = 0x8265B8B0;
	sub_826311F8(ctx, base);
	// stw r24,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r24.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r18,r31,4552
	r18.s64 = r31.s64 + 4552;
	// addi r4,r10,6164
	ctx.r4.s64 = ctx.r10.s64 + 6164;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826311f8
	ctx.lr = 0x8265B8C8;
	sub_826311F8(ctx, base);
	// stw r24,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r24.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r17,r31,4560
	r17.s64 = r31.s64 + 4560;
	// addi r4,r9,-408
	ctx.r4.s64 = ctx.r9.s64 + -408;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826311f8
	ctx.lr = 0x8265B8E0;
	sub_826311F8(ctx, base);
	// stw r24,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, r24.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,4568
	ctx.r3.s64 = r31.s64 + 4568;
	// addi r4,r8,-420
	ctx.r4.s64 = ctx.r8.s64 + -420;
	// bl 0x826311f8
	ctx.lr = 0x8265B8F4;
	sub_826311F8(ctx, base);
	// stw r24,4576(r31)
	PPC_STORE_U32(r31.u32 + 4576, r24.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r31,4576
	ctx.r3.s64 = r31.s64 + 4576;
	// addi r4,r7,-432
	ctx.r4.s64 = ctx.r7.s64 + -432;
	// bl 0x826311f8
	ctx.lr = 0x8265B908;
	sub_826311F8(ctx, base);
	// stw r24,4584(r31)
	PPC_STORE_U32(r31.u32 + 4584, r24.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r31,4584
	ctx.r3.s64 = r31.s64 + 4584;
	// addi r4,r6,-444
	ctx.r4.s64 = ctx.r6.s64 + -444;
	// bl 0x826311f8
	ctx.lr = 0x8265B91C;
	sub_826311F8(ctx, base);
	// addi r24,r31,4624
	r24.s64 = r31.s64 + 4624;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,6396
	ctx.r4.s64 = ctx.r4.s64 + 6396;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82633d40
	ctx.lr = 0x8265B934;
	sub_82633D40(ctx, base);
	// li r11,99
	r11.s64 = 99;
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r16,4624(r31)
	PPC_STORE_U32(r31.u32 + 4624, r16.u32);
	// stw r30,4832(r31)
	PPC_STORE_U32(r31.u32 + 4832, r30.u32);
	// addi r3,r24,228
	ctx.r3.s64 = r24.s64 + 228;
	// stw r11,4836(r31)
	PPC_STORE_U32(r31.u32 + 4836, r11.u32);
	// stw r10,4840(r31)
	PPC_STORE_U32(r31.u32 + 4840, ctx.r10.u32);
	// stw r30,4844(r31)
	PPC_STORE_U32(r31.u32 + 4844, r30.u32);
	// stb r30,4848(r31)
	PPC_STORE_U8(r31.u32 + 4848, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8265B95C;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24600);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r23,r31,4880
	r23.s64 = r31.s64 + 4880;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,6360
	ctx.r4.s64 = ctx.r9.s64 + 6360;
	// stw r11,4872(r31)
	PPC_STORE_U32(r31.u32 + 4872, r11.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r11,24596(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 24596);
	// stw r11,4876(r31)
	PPC_STORE_U32(r31.u32 + 4876, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8265B984;
	sub_82633D40(ctx, base);
	// li r8,99
	ctx.r8.s64 = 99;
	// li r7,10
	ctx.r7.s64 = 10;
	// stw r16,4880(r31)
	PPC_STORE_U32(r31.u32 + 4880, r16.u32);
	// stw r27,5088(r31)
	PPC_STORE_U32(r31.u32 + 5088, r27.u32);
	// addi r3,r23,228
	ctx.r3.s64 = r23.s64 + 228;
	// stw r8,5092(r31)
	PPC_STORE_U32(r31.u32 + 5092, ctx.r8.u32);
	// stw r7,5096(r31)
	PPC_STORE_U32(r31.u32 + 5096, ctx.r7.u32);
	// stw r30,5100(r31)
	PPC_STORE_U32(r31.u32 + 5100, r30.u32);
	// stb r30,5104(r31)
	PPC_STORE_U8(r31.u32 + 5104, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8265B9AC;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24600);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r6,6428
	ctx.r4.s64 = ctx.r6.s64 + 6428;
	// addi r3,r31,5136
	ctx.r3.s64 = r31.s64 + 5136;
	// stw r11,5128(r31)
	PPC_STORE_U32(r31.u32 + 5128, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,24596(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 24596);
	// stw r11,5132(r31)
	PPC_STORE_U32(r31.u32 + 5132, r11.u32);
	// bl 0x826349f0
	ctx.lr = 0x8265B9D4;
	sub_826349F0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r31,5376
	ctx.r3.s64 = r31.s64 + 5376;
	// addi r4,r4,-460
	ctx.r4.s64 = ctx.r4.s64 + -460;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x826349f0
	ctx.lr = 0x8265B9EC;
	sub_826349F0(ctx, base);
	// addi r30,r31,5616
	r30.s64 = r31.s64 + 5616;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r3,6412
	ctx.r4.s64 = ctx.r3.s64 + 6412;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826349f0
	ctx.lr = 0x8265BA08;
	sub_826349F0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-480
	ctx.r4.s64 = r11.s64 + -480;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x826349f0
	ctx.lr = 0x8265BA20;
	sub_826349F0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,-496
	ctx.r4.s64 = ctx.r10.s64 + -496;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,6096
	ctx.r3.s64 = r31.s64 + 6096;
	// bl 0x826349f0
	ctx.lr = 0x8265BA38;
	sub_826349F0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r9,-516
	ctx.r4.s64 = ctx.r9.s64 + -516;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,6336
	ctx.r3.s64 = r31.s64 + 6336;
	// bl 0x826349f0
	ctx.lr = 0x8265BA50;
	sub_826349F0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r8,-536
	ctx.r4.s64 = ctx.r8.s64 + -536;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,6576
	ctx.r3.s64 = r31.s64 + 6576;
	// bl 0x826349f0
	ctx.lr = 0x8265BA68;
	sub_826349F0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r7,-560
	ctx.r4.s64 = ctx.r7.s64 + -560;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,6816
	ctx.r3.s64 = r31.s64 + 6816;
	// bl 0x826349f0
	ctx.lr = 0x8265BA80;
	sub_826349F0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r6,-580
	ctx.r4.s64 = ctx.r6.s64 + -580;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,7056
	ctx.r3.s64 = r31.s64 + 7056;
	// bl 0x826349f0
	ctx.lr = 0x8265BA98;
	sub_826349F0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r4,-596
	ctx.r4.s64 = ctx.r4.s64 + -596;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,7296
	ctx.r3.s64 = r31.s64 + 7296;
	// bl 0x826349f0
	ctx.lr = 0x8265BAB0;
	sub_826349F0(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r3,-616
	ctx.r4.s64 = ctx.r3.s64 + -616;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,7536
	ctx.r3.s64 = r31.s64 + 7536;
	// bl 0x826349f0
	ctx.lr = 0x8265BAC8;
	sub_826349F0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-636
	ctx.r4.s64 = r11.s64 + -636;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,7776
	ctx.r3.s64 = r31.s64 + 7776;
	// bl 0x826349f0
	ctx.lr = 0x8265BAE0;
	sub_826349F0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,-652
	ctx.r4.s64 = ctx.r10.s64 + -652;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r3,r31,8016
	ctx.r3.s64 = r31.s64 + 8016;
	// bl 0x826349f0
	ctx.lr = 0x8265BAF8;
	sub_826349F0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-664
	ctx.r4.s64 = ctx.r9.s64 + -664;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r31,8256
	ctx.r3.s64 = r31.s64 + 8256;
	// bl 0x826349f0
	ctx.lr = 0x8265BB10;
	sub_826349F0(ctx, base);
	// lbz r6,8497(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 8497);
	// li r8,255
	ctx.r8.s64 = 255;
	// ori r5,r6,224
	ctx.r5.u64 = ctx.r6.u64 | 224;
	// addi r11,r31,8496
	r11.s64 = r31.s64 + 8496;
	// stb r8,8496(r31)
	PPC_STORE_U8(r31.u32 + 8496, ctx.r8.u8);
	// stb r5,8497(r31)
	PPC_STORE_U8(r31.u32 + 8497, ctx.r5.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// lbz r4,8502(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 8502);
	// addi r3,r31,8560
	ctx.r3.s64 = r31.s64 + 8560;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lbz r11,8500(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8500);
	// ori r9,r4,192
	ctx.r9.u64 = ctx.r4.u64 | 192;
	// stb r28,8501(r31)
	PPC_STORE_U8(r31.u32 + 8501, r28.u8);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r9,8502(r31)
	PPC_STORE_U8(r31.u32 + 8502, ctx.r9.u8);
	// stw r28,8504(r31)
	PPC_STORE_U32(r31.u32 + 8504, r28.u32);
	// stb r10,8500(r31)
	PPC_STORE_U8(r31.u32 + 8500, ctx.r10.u8);
	// stw r28,8508(r31)
	PPC_STORE_U32(r31.u32 + 8508, r28.u32);
	// stw r28,8512(r31)
	PPC_STORE_U32(r31.u32 + 8512, r28.u32);
	// stb r28,8516(r31)
	PPC_STORE_U8(r31.u32 + 8516, r28.u8);
	// stb r28,8517(r31)
	PPC_STORE_U8(r31.u32 + 8517, r28.u8);
	// stw r28,8520(r31)
	PPC_STORE_U32(r31.u32 + 8520, r28.u32);
	// stb r7,8524(r31)
	PPC_STORE_U8(r31.u32 + 8524, ctx.r7.u8);
	// stw r27,8528(r31)
	PPC_STORE_U32(r31.u32 + 8528, r27.u32);
	// stb r28,8532(r31)
	PPC_STORE_U8(r31.u32 + 8532, r28.u8);
	// stb r28,8540(r31)
	PPC_STORE_U8(r31.u32 + 8540, r28.u8);
	// stw r28,8544(r31)
	PPC_STORE_U32(r31.u32 + 8544, r28.u32);
	// bl 0x82634b60
	ctx.lr = 0x8265BB80;
	sub_82634B60(ctx, base);
	// li r8,20
	ctx.r8.s64 = 20;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r8,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-4116
	ctx.r4.s64 = ctx.r7.s64 + -4116;
	// bl 0x8263b860
	ctx.lr = 0x8265BB98;
	sub_8263B860(ctx, base);
	// stw r17,4612(r31)
	PPC_STORE_U32(r31.u32 + 4612, r17.u32);
	// addi r11,r31,4584
	r11.s64 = r31.s64 + 4584;
	// stw r21,4592(r31)
	PPC_STORE_U32(r31.u32 + 4592, r21.u32);
	// stw r20,4596(r31)
	PPC_STORE_U32(r31.u32 + 4596, r20.u32);
	// addi r6,r31,672
	ctx.r6.s64 = r31.s64 + 672;
	// stw r11,4600(r31)
	PPC_STORE_U32(r31.u32 + 4600, r11.u32);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// addi r11,r31,4576
	r11.s64 = r31.s64 + 4576;
	// stw r19,4616(r31)
	PPC_STORE_U32(r31.u32 + 4616, r19.u32);
	// stw r18,4620(r31)
	PPC_STORE_U32(r31.u32 + 4620, r18.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,4604(r31)
	PPC_STORE_U32(r31.u32 + 4604, r11.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// addi r11,r31,4568
	r11.s64 = r31.s64 + 4568;
	// stw r11,4608(r31)
	PPC_STORE_U32(r31.u32 + 4608, r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r31,1648
	r11.s64 = r31.s64 + 1648;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,1888
	r11.s64 = r31.s64 + 1888;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r31,2128
	r11.s64 = r31.s64 + 2128;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// addi r11,r31,2608
	r11.s64 = r31.s64 + 2608;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// stwx r22,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r22.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// addi r11,r31,3088
	r11.s64 = r31.s64 + 3088;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r7,2848(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2848);
	// lwz r6,548(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 548);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265BCD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,432(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r5,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r5.u32);
	// bl 0x8262fff0
	ctx.lr = 0x8265BCE8;
	sub_8262FFF0(ctx, base);
	// lwz r4,3296(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 3296);
	// lwz r11,3056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3056);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// cntlzw r10,r4
	ctx.r10.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r9,4496(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4496);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r8,4880(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4880);
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
	// stw r9,8520(r31)
	PPC_STORE_U32(r31.u32 + 8520, ctx.r9.u32);
	// lwz r10,336(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// stb r4,8516(r31)
	PPC_STORE_U8(r31.u32 + 8516, ctx.r4.u8);
	// stb r11,8517(r31)
	PPC_STORE_U8(r31.u32 + 8517, r11.u8);
	// lwz r29,5584(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 5584);
	// lwz r27,5824(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 5824);
	// lwz r26,5344(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 5344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265BD38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4624(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4624);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r30,r31,8500
	r30.s64 = r31.s64 + 8500;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r8,336(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 336);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265BD54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r7,r27
	ctx.r7.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// lbz r6,8502(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 8502);
	// cntlzw r5,r29
	ctx.r5.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// rlwinm r4,r7,2,24,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x80;
	// lbz r11,8500(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8500);
	// clrlwi r10,r6,26
	ctx.r10.u64 = ctx.r6.u32 & 0x3F;
	// stb r3,8501(r31)
	PPC_STORE_U8(r31.u32 + 8501, ctx.r3.u8);
	// xori r9,r4,128
	ctx.r9.u64 = ctx.r4.u64 ^ 128;
	// rlwinm r8,r5,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// or r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 | ctx.r9.u64;
	// xori r6,r8,1
	ctx.r6.u64 = ctx.r8.u64 ^ 1;
	// lis r5,0
	ctx.r5.s64 = 0;
	// rlwimi r7,r6,6,25,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x40) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFBF);
	// ori r4,r5,60000
	ctx.r4.u64 = ctx.r5.u64 | 60000;
	// stb r7,8502(r31)
	PPC_STORE_U8(r31.u32 + 8502, ctx.r7.u8);
	// cntlzw r7,r26
	ctx.r7.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// mullw r8,r25,r4
	ctx.r8.s64 = int64_t(r25.s32) * int64_t(ctx.r4.s32);
	// stw r8,8504(r31)
	PPC_STORE_U32(r31.u32 + 8504, ctx.r8.u32);
	// rlwinm r5,r7,2,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x80;
	// clrlwi r6,r11,25
	ctx.r6.u64 = r11.u32 & 0x7F;
	// xori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 ^ 128;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// stb r3,8500(r31)
	PPC_STORE_U8(r31.u32 + 8500, ctx.r3.u8);
	// lwz r9,7264(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 7264);
	// lwz r8,6304(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 6304);
	// lwz r11,6544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 6544);
	// lwz r10,7024(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 7024);
	// lwz r6,6064(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 6064);
	// cntlzw r4,r8
	ctx.r4.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r7,6784(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 6784);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lwz r3,7504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 7504);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lwz r27,8464(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 8464);
	// rlwinm r8,r5,28,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0x2;
	// lwz r6,7984(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 7984);
	// rlwinm r5,r4,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lwz r30,8224(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// xori r8,r8,2
	ctx.r8.u64 = ctx.r8.u64 ^ 2;
	// lbz r29,8497(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 8497);
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// lwz r4,7744(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 7744);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// or r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 | ctx.r5.u64;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// cntlzw r11,r7
	r11.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r8,r8,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFE;
	// rlwinm r7,r11,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// or r5,r8,r5
	ctx.r5.u64 = ctx.r8.u64 | ctx.r5.u64;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// rlwinm r8,r5,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFE;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// or r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 | r11.u64;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// rlwinm r10,r5,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFE;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | r11.u64;
	// rlwinm r7,r9,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rlwinm r5,r8,1,24,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFE;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// cntlzw r10,r27
	ctx.r10.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// cntlzw r9,r6
	ctx.r9.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// or r7,r5,r11
	ctx.r7.u64 = ctx.r5.u64 | r11.u64;
	// rlwinm r6,r3,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// rlwinm r3,r9,2,24,24
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0x80;
	// cntlzw r8,r30
	ctx.r8.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r10,r7,1,24,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFE;
	// xori r9,r6,1
	ctx.r9.u64 = ctx.r6.u64 ^ 1;
	// xori r7,r5,1
	ctx.r7.u64 = ctx.r5.u64 ^ 1;
	// xori r6,r3,128
	ctx.r6.u64 = ctx.r3.u64 ^ 128;
	// rlwinm r11,r8,28,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 28) & 0x2;
	// clrlwi r5,r29,27
	ctx.r5.u64 = r29.u32 & 0x1F;
	// cntlzw r8,r4
	ctx.r8.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// or r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 | ctx.r9.u64;
	// xori r4,r11,2
	ctx.r4.u64 = r11.u64 ^ 2;
	// or r10,r5,r6
	ctx.r10.u64 = ctx.r5.u64 | ctx.r6.u64;
	// or r9,r4,r7
	ctx.r9.u64 = ctx.r4.u64 | ctx.r7.u64;
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r8,r3,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// xori r7,r11,1
	ctx.r7.u64 = r11.u64 ^ 1;
	// rlwinm r6,r6,0,27,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// rlwinm r5,r9,5,24,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xE0;
	// or r4,r8,r7
	ctx.r4.u64 = ctx.r8.u64 | ctx.r7.u64;
	// or r3,r5,r6
	ctx.r3.u64 = ctx.r5.u64 | ctx.r6.u64;
	// stb r4,8496(r31)
	PPC_STORE_U8(r31.u32 + 8496, ctx.r4.u8);
	// stb r3,8497(r31)
	PPC_STORE_U8(r31.u32 + 8497, ctx.r3.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r28,8533(r31)
	PPC_STORE_U8(r31.u32 + 8533, r28.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8265BECC"))) PPC_WEAK_FUNC(sub_8265BECC);
PPC_FUNC_IMPL(__imp__sub_8265BECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265BED0"))) PPC_WEAK_FUNC(sub_8265BED0);
PPC_FUNC_IMPL(__imp__sub_8265BED0) {
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
	// bl 0x82647e40
	ctx.lr = 0x8265BEF0;
	sub_82647E40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265bf08
	if (cr6.eq) goto loc_8265BF08;
	// bl 0x82130588
	ctx.lr = 0x8265BF04;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265BF08:
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

