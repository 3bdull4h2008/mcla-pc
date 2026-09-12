#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8263B7C8"))) PPC_WEAK_FUNC(sub_8263B7C8);
PPC_FUNC_IMPL(__imp__sub_8263B7C8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263B7F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bge cr6,0x8263b818
	if (!cr6.lt) goto loc_8263B818;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263B814;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8263b81c
	goto loc_8263B81C;
loc_8263B818:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8263B81C:
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

__attribute__((alias("__imp__sub_8263B834"))) PPC_WEAK_FUNC(sub_8263B834);
PPC_FUNC_IMPL(__imp__sub_8263B834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263B838"))) PPC_WEAK_FUNC(sub_8263B838);
PPC_FUNC_IMPL(__imp__sub_8263B838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// b 0x82218310
	sub_82218310(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263B858"))) PPC_WEAK_FUNC(sub_8263B858);
PPC_FUNC_IMPL(__imp__sub_8263B858) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263B85C"))) PPC_WEAK_FUNC(sub_8263B85C);
PPC_FUNC_IMPL(__imp__sub_8263B85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263B860"))) PPC_WEAK_FUNC(sub_8263B860);
PPC_FUNC_IMPL(__imp__sub_8263B860) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8263b8a4
	if (cr6.eq) goto loc_8263B8A4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8263B890;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,344(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 344);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263B8A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263B8A4:
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

__attribute__((alias("__imp__sub_8263B8BC"))) PPC_WEAK_FUNC(sub_8263B8BC);
PPC_FUNC_IMPL(__imp__sub_8263B8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263B8C0"))) PPC_WEAK_FUNC(sub_8263B8C0);
PPC_FUNC_IMPL(__imp__sub_8263B8C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// beq cr6,0x8263b900
	if (cr6.eq) goto loc_8263B900;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8263b8e0
	if (!cr6.lt) goto loc_8263B8E0;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_8263B8E0:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8263b918
	if (cr6.lt) goto loc_8263B918;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// b 0x8263b918
	goto loc_8263B918;
loc_8263B900:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// bge 0x8263b918
	if (!cr0.lt) goto loc_8263B918;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_8263B918:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8263b92c
	if (!cr6.eq) goto loc_8263B92C;
	// stw r10,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r10.u32);
	// b 0x8263b954
	goto loc_8263B954;
loc_8263B92C:
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x8263b954
	if (!cr6.eq) goto loc_8263B954;
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8263b954
	if (!cr6.gt) goto loc_8263B954;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
loc_8263B954:
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x8263b970
	if (cr6.lt) goto loc_8263B970;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8263b984
	goto loc_8263B984;
loc_8263B970:
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bge cr6,0x8263b988
	if (!cr6.lt) goto loc_8263B988;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8263b988
	if (!cr6.gt) goto loc_8263B988;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8263B984:
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
loc_8263B988:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,-22444
	ctx.r3.s64 = r11.s64 + -22444;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263B9A0"))) PPC_WEAK_FUNC(sub_8263B9A0);
PPC_FUNC_IMPL(__imp__sub_8263B9A0) {
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
	ctx.lr = 0x8263B9A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// lwz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// li r9,1
	ctx.r9.s64 = 1;
	// addis r7,r8,4
	ctx.r7.s64 = ctx.r8.s64 + 262144;
	// addi r7,r7,976
	ctx.r7.s64 = ctx.r7.s64 + 976;
	// cmplw cr6,r7,r29
	cr6.compare<uint32_t>(ctx.r7.u32, r29.u32, xer);
	// bne cr6,0x8263ba30
	if (!cr6.eq) goto loc_8263BA30;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r10,r11,-52
	ctx.r10.s64 = r11.s64 + -52;
	// addi r8,r11,-53
	ctx.r8.s64 = r11.s64 + -53;
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r10,r7,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// rlwinm r23,r6,27,31,31
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263ba28
	if (!cr6.eq) goto loc_8263BA28;
	// cmpwi cr6,r11,56
	cr6.compare<int32_t>(r11.s32, 56, xer);
	// beq cr6,0x8263ba28
	if (cr6.eq) goto loc_8263BA28;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8263ba2c
	if (!cr6.eq) goto loc_8263BA2C;
loc_8263BA28:
	// li r11,1
	r11.s64 = 1;
loc_8263BA2C:
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
loc_8263BA30:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bb38
	if (cr6.eq) goto loc_8263BB38;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BA50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8263baf4
	if (cr6.lt) goto loc_8263BAF4;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263BA6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,480(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 480);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BA80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8263baf4
	if (cr6.eq) goto loc_8263BAF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BA9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r11,1
	r11.s64 = 1;
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt cr6,0x8263bab4
	if (cr6.gt) goto loc_8263BAB4;
	// li r11,0
	r11.s64 = 0;
loc_8263BAB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263baec
	if (!cr6.eq) goto loc_8263BAEC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263bb30
	if (cr6.eq) goto loc_8263BB30;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8263bae0
	if (cr6.gt) goto loc_8263BAE0;
	// li r11,0
	r11.s64 = 0;
loc_8263BAE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bb30
	if (cr6.eq) goto loc_8263BB30;
loc_8263BAEC:
	// li r11,0
	r11.s64 = 0;
	// b 0x8263bb34
	goto loc_8263BB34;
loc_8263BAF4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8263bb30
	if (!cr6.lt) goto loc_8263BB30;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BB24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8263bb34
	if (!cr6.eq) goto loc_8263BB34;
loc_8263BB30:
	// li r11,1
	r11.s64 = 1;
loc_8263BB34:
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
loc_8263BB38:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263bb5c
	if (!cr6.eq) goto loc_8263BB5C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8263BB50;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_8263BB5C:
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268ea68
	ctx.lr = 0x8263BB78;
	sub_8268EA68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bbcc
	if (cr6.eq) goto loc_8263BBCC;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bba8
	if (cr6.eq) goto loc_8263BBA8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8263BB9C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_8263BBA8:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bbc0
	if (cr6.eq) goto loc_8263BBC0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8263BBC0;
	sub_821E6800(ctx, base);
loc_8263BBC0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_8263BBCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8263BBD8"))) PPC_WEAK_FUNC(sub_8263BBD8);
PPC_FUNC_IMPL(__imp__sub_8263BBD8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8263BBE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r11,0(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 0);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,52(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r5,r7,4
	ctx.r5.s64 = ctx.r7.s64 + 262144;
	// lwzx r6,r8,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	// addi r5,r5,976
	ctx.r5.s64 = ctx.r5.s64 + 976;
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bne cr6,0x8263be30
	if (!cr6.eq) goto loc_8263BE30;
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8263bc48
	if (cr6.eq) goto loc_8263BC48;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-72
	ctx.r4.s64 = r11.s64 + -72;
	// bl 0x8268da78
	ctx.lr = 0x8263BC3C;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8263bc4c
	if (!cr6.eq) goto loc_8263BC4C;
loc_8263BC48:
	// li r11,0
	r11.s64 = 0;
loc_8263BC4C:
	// lhz r9,2(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 2);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// extsh r11,r9
	r11.s64 = ctx.r9.s16;
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x8263be30
	if (cr6.gt) goto loc_8263BE30;
	// lis r27,-32126
	r27.s64 = -2105409536;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-17284
	r12.s64 = r12.s64 + -17284;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263BCCC;
	case 1:
		goto loc_8263BCEC;
	case 2:
		goto loc_8263BD6C;
	case 3:
		goto loc_8263BD0C;
	case 4:
		goto loc_8263BE30;
	case 5:
		goto loc_8263BE30;
	case 6:
		goto loc_8263BE30;
	case 7:
		goto loc_8263BE30;
	case 8:
		goto loc_8263BE30;
	case 9:
		goto loc_8263BE30;
	case 10:
		goto loc_8263BD6C;
	case 11:
		goto loc_8263BD0C;
	case 12:
		goto loc_8263BE30;
	case 13:
		goto loc_8263BE30;
	case 14:
		goto loc_8263BE30;
	case 15:
		goto loc_8263BE30;
	case 16:
		goto loc_8263BCCC;
	case 17:
		goto loc_8263BCEC;
	case 18:
		goto loc_8263BD6C;
	case 19:
		goto loc_8263BD0C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17204(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17204);
	// lwz r19,-17172(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17172);
	// lwz r19,-17044(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17044);
	// lwz r19,-17140(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17140);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-17044(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17044);
	// lwz r19,-17140(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17140);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-16848(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16848);
	// lwz r19,-17204(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17204);
	// lwz r19,-17172(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17172);
	// lwz r19,-17044(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17044);
	// lwz r19,-17140(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -17140);
loc_8263BCCC:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268dec0
	ctx.lr = 0x8263BCE0;
	sub_8268DEC0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24596(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24596);
	// b 0x8263bdbc
	goto loc_8263BDBC;
loc_8263BCEC:
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268dec0
	ctx.lr = 0x8263BD00;
	sub_8268DEC0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24600(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24600);
	// b 0x8263bdbc
	goto loc_8263BDBC;
loc_8263BD0C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263bd44
	if (cr6.eq) goto loc_8263BD44;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,484(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 484);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BD2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263bd90
	if (cr6.eq) goto loc_8263BD90;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24608(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24608);
	// b 0x8263bdc0
	goto loc_8263BDC0;
loc_8263BD44:
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8263be30
	if (cr6.eq) goto loc_8263BE30;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268dec0
	ctx.lr = 0x8263BD60;
	sub_8268DEC0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24608(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24608);
	// b 0x8263bdbc
	goto loc_8263BDBC;
loc_8263BD6C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263bd98
	if (cr6.eq) goto loc_8263BD98;
	// lwz r30,40(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263bd90
	if (cr6.eq) goto loc_8263BD90;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24604(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24604);
	// b 0x8263bdc0
	goto loc_8263BDC0;
loc_8263BD90:
	// lwz r31,24612(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 24612);
	// b 0x8263bdc0
	goto loc_8263BDC0;
loc_8263BD98:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8263be30
	if (cr6.eq) goto loc_8263BE30;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268dec0
	ctx.lr = 0x8263BDB4;
	sub_8268DEC0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r31,24604(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24604);
loc_8263BDBC:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8263BDC0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8263be30
	if (cr6.eq) goto loc_8263BE30;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263be10
	if (cr6.eq) goto loc_8263BE10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f87e8
	ctx.lr = 0x8263BDD8;
	sub_821F87E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263be10
	if (!cr6.eq) goto loc_8263BE10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e6800
	ctx.lr = 0x8263BDEC;
	sub_821E6800(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BE04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8263BE10:
	// lwz r11,24612(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24612);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8263be24
	if (!cr6.eq) goto loc_8263BE24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e6800
	ctx.lr = 0x8263BE24;
	sub_821E6800(ctx, base);
loc_8263BE24:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8263BE30:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268e958
	ctx.lr = 0x8263BE40;
	sub_8268E958(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8263BE48"))) PPC_WEAK_FUNC(sub_8263BE48);
PPC_FUNC_IMPL(__imp__sub_8263BE48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,68(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263beb0
	if (cr6.eq) goto loc_8263BEB0;
	// addi r11,r4,-51
	r11.s64 = ctx.r4.s64 + -51;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8263bf00
	if (cr6.gt) goto loc_8263BF00;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-16764
	r12.s64 = r12.s64 + -16764;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263BEE4;
	case 1:
		goto loc_8263BE94;
	case 2:
		goto loc_8263BEE4;
	case 3:
		goto loc_8263BE94;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-16668(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16668);
	// lwz r19,-16748(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16748);
	// lwz r19,-16668(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16668);
	// lwz r19,-16748(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16748);
loc_8263BE94:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8263b8c0
	ctx.lr = 0x8263BE9C;
	sub_8263B8C0(ctx, base);
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
loc_8263BEB0:
	// addi r11,r4,-47
	r11.s64 = ctx.r4.s64 + -47;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8263bf00
	if (cr6.gt) goto loc_8263BF00;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-16684
	r12.s64 = r12.s64 + -16684;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263BEE4;
	case 1:
		goto loc_8263BE94;
	case 2:
		goto loc_8263BEE4;
	case 3:
		goto loc_8263BE94;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-16668(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16668);
	// lwz r19,-16748(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16748);
	// lwz r19,-16668(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16668);
	// lwz r19,-16748(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -16748);
loc_8263BEE4:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8263b8c0
	ctx.lr = 0x8263BEEC;
	sub_8263B8C0(ctx, base);
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
loc_8263BF00:
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

__attribute__((alias("__imp__sub_8263BF14"))) PPC_WEAK_FUNC(sub_8263BF14);
PPC_FUNC_IMPL(__imp__sub_8263BF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263BF18"))) PPC_WEAK_FUNC(sub_8263BF18);
PPC_FUNC_IMPL(__imp__sub_8263BF18) {
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
	ctx.lr = 0x8263BF20;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263BF38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8263bf70
	if (!cr6.eq) goto loc_8263BF70;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,4
	ctx.r10.s64 = 262144;
	// ori r9,r10,1808
	ctx.r9.u64 = ctx.r10.u64 | 1808;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263bfbc
	if (cr6.eq) goto loc_8263BFBC;
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8263bfbc
	if (cr6.eq) goto loc_8263BFBC;
loc_8263BF70:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32138
	ctx.r10.s64 = -2106195968;
	// addi r29,r11,2612
	r29.s64 = r11.s64 + 2612;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,9352
	ctx.r8.s64 = ctx.r10.s64 + 9352;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8263BF9C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8263BFAC;
	sub_825ED480(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// bl 0x82220308
	ctx.lr = 0x8263BFBC;
	sub_82220308(ctx, base);
loc_8263BFBC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8263BFC4"))) PPC_WEAK_FUNC(sub_8263BFC4);
PPC_FUNC_IMPL(__imp__sub_8263BFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263BFC8"))) PPC_WEAK_FUNC(sub_8263BFC8);
PPC_FUNC_IMPL(__imp__sub_8263BFC8) {
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
	ctx.lr = 0x8263BFD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x8263BFDC;
	sub_82130000(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r31,0
	r31.s64 = 0;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// lbz r10,121(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 121);
	// stb r10,25137(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25137, ctx.r10.u8);
	// stb r31,121(r11)
	PPC_STORE_U8(r11.u32 + 121, r31.u8);
	// lwz r3,-8092(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// bl 0x822e5b30
	ctx.lr = 0x8263C004;
	sub_822E5B30(ctx, base);
	// stb r3,780(r30)
	PPC_STORE_U8(r30.u32 + 780, ctx.r3.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// bl 0x822e5b20
	ctx.lr = 0x8263C014;
	sub_822E5B20(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r31,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r31.u32);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stb r11,25116(r8)
	PPC_STORE_U8(ctx.r8.u32 + 25116, r11.u8);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stb r31,769(r30)
	PPC_STORE_U8(r30.u32 + 769, r31.u8);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// stb r31,729(r30)
	PPC_STORE_U8(r30.u32 + 729, r31.u8);
	// stb r31,730(r30)
	PPC_STORE_U8(r30.u32 + 730, r31.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r31,714(r30)
	PPC_STORE_U8(r30.u32 + 714, r31.u8);
	// stb r31,712(r30)
	PPC_STORE_U8(r30.u32 + 712, r31.u8);
	// stb r31,713(r30)
	PPC_STORE_U8(r30.u32 + 713, r31.u8);
	// stb r31,716(r30)
	PPC_STORE_U8(r30.u32 + 716, r31.u8);
	// stb r31,717(r30)
	PPC_STORE_U8(r30.u32 + 717, r31.u8);
	// stb r31,718(r30)
	PPC_STORE_U8(r30.u32 + 718, r31.u8);
	// stb r31,719(r30)
	PPC_STORE_U8(r30.u32 + 719, r31.u8);
	// stb r31,720(r30)
	PPC_STORE_U8(r30.u32 + 720, r31.u8);
	// stb r31,728(r30)
	PPC_STORE_U8(r30.u32 + 728, r31.u8);
	// stb r31,768(r30)
	PPC_STORE_U8(r30.u32 + 768, r31.u8);
	// stb r31,770(r30)
	PPC_STORE_U8(r30.u32 + 770, r31.u8);
	// stb r31,771(r30)
	PPC_STORE_U8(r30.u32 + 771, r31.u8);
	// stb r31,722(r30)
	PPC_STORE_U8(r30.u32 + 722, r31.u8);
	// stb r11,25132(r7)
	PPC_STORE_U8(ctx.r7.u32 + 25132, r11.u8);
	// stb r10,25133(r6)
	PPC_STORE_U8(ctx.r6.u32 + 25133, ctx.r10.u8);
	// stb r31,25135(r5)
	PPC_STORE_U8(ctx.r5.u32 + 25135, r31.u8);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,468(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 468);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263C094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,1432
	ctx.r4.s64 = ctx.r10.s64 + 1432;
	// bl 0x825ee0e0
	ctx.lr = 0x8263C0A4;
	sub_825EE0E0(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r9,1412
	r31.s64 = ctx.r9.s64 + 1412;
	// lwz r7,468(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263C0C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8263C0CC;
	sub_825EE0E0(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-3624(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x8263C0D8;
	sub_8226CE68(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r3,25044(r5)
	PPC_STORE_U32(ctx.r5.u32 + 25044, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263C0E8"))) PPC_WEAK_FUNC(sub_8263C0E8);
PPC_FUNC_IMPL(__imp__sub_8263C0E8) {
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
	// addi r3,r31,456
	ctx.r3.s64 = r31.s64 + 456;
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263C110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,1170(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r4,r11,1432
	ctx.r4.s64 = r11.s64 + 1432;
	// li r5,0
	ctx.r5.s64 = 0;
	// bne cr6,0x8263c130
	if (!cr6.eq) goto loc_8263C130;
	// li r5,1
	ctx.r5.s64 = 1;
loc_8263C130:
	// bl 0x825ee0e0
	ctx.lr = 0x8263C134;
	sub_825EE0E0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1412
	ctx.r4.s64 = r11.s64 + 1412;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263C148;
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

__attribute__((alias("__imp__sub_8263C15C"))) PPC_WEAK_FUNC(sub_8263C15C);
PPC_FUNC_IMPL(__imp__sub_8263C15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C160"))) PPC_WEAK_FUNC(sub_8263C160);
PPC_FUNC_IMPL(__imp__sub_8263C160) {
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
	// bl 0x8263b730
	ctx.lr = 0x8263C178;
	sub_8263B730(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,28
	ctx.r8.s64 = 28;
	// li r11,1
	r11.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,25133(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25133, r11.u8);
	// stb r7,715(r31)
	PPC_STORE_U8(r31.u32 + 715, ctx.r7.u8);
	// lwzx r3,r8,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263C1A8;
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

__attribute__((alias("__imp__sub_8263C1BC"))) PPC_WEAK_FUNC(sub_8263C1BC);
PPC_FUNC_IMPL(__imp__sub_8263C1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C1C0"))) PPC_WEAK_FUNC(sub_8263C1C0);
PPC_FUNC_IMPL(__imp__sub_8263C1C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c1d4
	if (cr6.eq) goto loc_8263C1D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8263C1D4:
	// lis r11,3
	r11.s64 = 196608;
	// lwz r10,428(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// ori r9,r11,8192
	ctx.r9.u64 = r11.u64 | 8192;
	// mullw r11,r5,r9
	r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r3,r11,204
	ctx.r3.s64 = r11.s64 + 204;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263C1F0"))) PPC_WEAK_FUNC(sub_8263C1F0);
PPC_FUNC_IMPL(__imp__sub_8263C1F0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r7,r11,27728
	ctx.r7.s64 = r11.s64 + 27728;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
loc_8263C210:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x8263c1c0
	ctx.lr = 0x8263C21C;
	sub_8263C1C0(ctx, base);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r7,64
	r11.s64 = ctx.r7.s64 + 64;
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x8263c210
	if (cr6.lt) goto loc_8263C210;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r7
	ctx.r3.u64 = r11.u64 + ctx.r7.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263C248"))) PPC_WEAK_FUNC(sub_8263C248);
PPC_FUNC_IMPL(__imp__sub_8263C248) {
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
	ctx.lr = 0x8263C250;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3
	r11.s64 = 196608;
	// lwz r29,428(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// ori r5,r11,8192
	ctx.r5.u64 = r11.u64 | 8192;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mullw r11,r31,r10
	r11.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r30,r11,204
	r30.s64 = r11.s64 + 204;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d9890
	ctx.lr = 0x8263C288;
	sub_823D9890(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8263C298;
	sub_823DA950(ctx, base);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// stw r27,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r27.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// bl 0x821d58d8
	ctx.lr = 0x8263C2C0;
	sub_821D58D8(ctx, base);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8263C2CC"))) PPC_WEAK_FUNC(sub_8263C2CC);
PPC_FUNC_IMPL(__imp__sub_8263C2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C2D0"))) PPC_WEAK_FUNC(sub_8263C2D0);
PPC_FUNC_IMPL(__imp__sub_8263C2D0) {
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
	ctx.lr = 0x8263C2D8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r24,r11,25048
	r24.s64 = r11.s64 + 25048;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8263C2FC;
	sub_823D9890(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r28,0
	r28.s64 = 0;
	// addi r25,r11,25144
	r25.s64 = r11.s64 + 25144;
	// lwz r11,1208(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8263c3ac
	if (!cr6.gt) goto loc_8263C3AC;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// addi r30,r25,76
	r30.s64 = r25.s64 + 76;
loc_8263C31C:
	// addi r29,r30,-76
	r29.s64 = r30.s64 + -76;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bl 0x824f2380
	ctx.lr = 0x8263C334;
	sub_824F2380(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c398
	if (cr6.eq) goto loc_8263C398;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263c398
	if (cr6.eq) goto loc_8263C398;
	// lwz r11,64(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x8263c398
	if (!cr6.eq) goto loc_8263C398;
	// lwz r11,-40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8263c398
	if (!cr6.gt) goto loc_8263C398;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8263C370;
	sub_823DA950(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bge cr6,0x8263c398
	if (!cr6.lt) goto loc_8263C398;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263c398
	if (!cr6.eq) goto loc_8263C398;
	// stwx r29,r11,r24
	PPC_STORE_U32(r11.u32 + r24.u32, r29.u32);
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
loc_8263C398:
	// lwz r11,1208(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1208);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,152
	r30.s64 = r30.s64 + 152;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x8263c31c
	if (cr6.lt) goto loc_8263C31C;
loc_8263C3AC:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r24,4
	ctx.r9.s64 = r24.s64 + 4;
loc_8263C3B8:
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8263c478
	if (!cr6.lt) goto loc_8263C478;
	// lwz r8,-4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263c3e4
	if (!cr6.eq) goto loc_8263C3E4;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// mulli r8,r8,152
	ctx.r8.s64 = ctx.r8.s64 * 152;
	// add r7,r8,r25
	ctx.r7.u64 = ctx.r8.u64 + r25.u64;
	// stw r7,-4(r9)
	PPC_STORE_U32(ctx.r9.u32 + -4, ctx.r7.u32);
loc_8263C3E4:
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8263c478
	if (!cr6.lt) goto loc_8263C478;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263c410
	if (!cr6.eq) goto loc_8263C410;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// mulli r8,r8,152
	ctx.r8.s64 = ctx.r8.s64 * 152;
	// add r7,r8,r25
	ctx.r7.u64 = ctx.r8.u64 + r25.u64;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_8263C410:
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8263c478
	if (!cr6.lt) goto loc_8263C478;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263c43c
	if (!cr6.eq) goto loc_8263C43C;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// mulli r8,r8,152
	ctx.r8.s64 = ctx.r8.s64 * 152;
	// add r7,r8,r25
	ctx.r7.u64 = ctx.r8.u64 + r25.u64;
	// stw r7,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r7.u32);
loc_8263C43C:
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8263c478
	if (!cr6.lt) goto loc_8263C478;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263c468
	if (!cr6.eq) goto loc_8263C468;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// mulli r8,r8,152
	ctx.r8.s64 = ctx.r8.s64 * 152;
	// add r7,r8,r25
	ctx.r7.u64 = ctx.r8.u64 + r25.u64;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
loc_8263C468:
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r8,r24,68
	ctx.r8.s64 = r24.s64 + 68;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8263c3b8
	if (cr6.lt) goto loc_8263C3B8;
loc_8263C478:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8263C480"))) PPC_WEAK_FUNC(sub_8263C480);
PPC_FUNC_IMPL(__imp__sub_8263C480) {
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
	ctx.lr = 0x8263C488;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r29,428(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x8268ee10
	ctx.lr = 0x8263C4B0;
	sub_8268EE10(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r10.u32);
	// addi r7,r31,1216
	ctx.r7.s64 = r31.s64 + 1216;
	// stw r9,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r9.u32);
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// stw r8,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, ctx.r8.u32);
	// bge cr6,0x8263c524
	if (!cr6.lt) goto loc_8263C524;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,25048
	ctx.r9.s64 = r11.s64 + 25048;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c524
	if (cr6.eq) goto loc_8263C524;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x8263c524
	if (!cr6.gt) goto loc_8263C524;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// lwz r4,40(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// ori r6,r10,8192
	ctx.r6.u64 = ctx.r10.u64 | 8192;
	// addi r9,r31,1200
	ctx.r9.s64 = r31.s64 + 1200;
	// mullw r11,r30,r6
	r11.s64 = int64_t(r30.s32) * int64_t(ctx.r6.s32);
	// lwz r3,25044(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 25044);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r8,r31,1196
	ctx.r8.s64 = r31.s64 + 1196;
	// addi r5,r11,204
	ctx.r5.s64 = r11.s64 + 204;
	// bl 0x824f7578
	ctx.lr = 0x8263C524;
	sub_824F7578(ctx, base);
loc_8263C524:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263C52C"))) PPC_WEAK_FUNC(sub_8263C52C);
PPC_FUNC_IMPL(__imp__sub_8263C52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C530"))) PPC_WEAK_FUNC(sub_8263C530);
PPC_FUNC_IMPL(__imp__sub_8263C530) {
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
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,28
	ctx.r4.s64 = 28;
	// bl 0x8268ee10
	ctx.lr = 0x8263C564;
	sub_8268EE10(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r10,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r10.u32);
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// stw r9,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r9.u32);
	// bge cr6,0x8263c5b0
	if (!cr6.lt) goto loc_8263C5B0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,25048
	ctx.r9.s64 = r11.s64 + 25048;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c5b0
	if (cr6.eq) goto loc_8263C5B0;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r5,32(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r6,r31,1200
	ctx.r6.s64 = r31.s64 + 1200;
	// addi r4,r9,21436
	ctx.r4.s64 = ctx.r9.s64 + 21436;
	// lwz r3,25044(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 25044);
	// bl 0x824f7260
	ctx.lr = 0x8263C5B0;
	sub_824F7260(ctx, base);
loc_8263C5B0:
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

__attribute__((alias("__imp__sub_8263C5C8"))) PPC_WEAK_FUNC(sub_8263C5C8);
PPC_FUNC_IMPL(__imp__sub_8263C5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8263C5D0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// bl 0x821be568
	ctx.lr = 0x8263C5EC;
	sub_821BE568(ctx, base);
	// lwz r3,1240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// bl 0x821bdcf8
	ctx.lr = 0x8263C5F4;
	sub_821BDCF8(ctx, base);
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,1240(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// lwz r3,1140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// bl 0x82775c60
	ctx.lr = 0x8263C610;
	sub_82775C60(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,1240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// bl 0x821bdcf8
	ctx.lr = 0x8263C61C;
	sub_821BDCF8(ctx, base);
	// subf r11,r30,r3
	r11.s64 = ctx.r3.s64 - r30.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263C634"))) PPC_WEAK_FUNC(sub_8263C634);
PPC_FUNC_IMPL(__imp__sub_8263C634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C638"))) PPC_WEAK_FUNC(sub_8263C638);
PPC_FUNC_IMPL(__imp__sub_8263C638) {
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
	ctx.lr = 0x8263C640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263C664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x821789d8
	ctx.lr = 0x8263C668;
	sub_821789D8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32131
	r27.s64 = -2105737216;
	// lis r28,-32131
	r28.s64 = -2105737216;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8263c684
	if (cr6.eq) goto loc_8263C684;
	// lwz r11,17004(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 17004);
	// b 0x8263c688
	goto loc_8263C688;
loc_8263C684:
	// lwz r11,17012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17012);
loc_8263C688:
	// lwz r10,1140(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1140);
	// lis r30,-32131
	r30.s64 = -2105737216;
	// lis r31,-32131
	r31.s64 = -2105737216;
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x8263c6cc
	if (!cr6.eq) goto loc_8263C6CC;
	// bl 0x821789d8
	ctx.lr = 0x8263C6A4;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c6b8
	if (cr6.eq) goto loc_8263C6B8;
	// lwz r11,17008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17008);
	// b 0x8263c6bc
	goto loc_8263C6BC;
loc_8263C6B8:
	// lwz r11,17016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17016);
loc_8263C6BC:
	// lwz r10,1140(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 1140);
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// beq cr6,0x8263c714
	if (cr6.eq) goto loc_8263C714;
loc_8263C6CC:
	// bl 0x821789d8
	ctx.lr = 0x8263C6D0;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c6e4
	if (cr6.eq) goto loc_8263C6E4;
	// lwz r31,17008(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 17008);
	// b 0x8263c6e8
	goto loc_8263C6E8;
loc_8263C6E4:
	// lwz r31,17016(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 17016);
loc_8263C6E8:
	// bl 0x821789d8
	ctx.lr = 0x8263C6EC;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c700
	if (cr6.eq) goto loc_8263C700;
	// lwz r4,17004(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 17004);
	// b 0x8263c704
	goto loc_8263C704;
loc_8263C700:
	// lwz r4,17012(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 17012);
loc_8263C704:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,1140(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 1140);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8218e060
	ctx.lr = 0x8263C714;
	sub_8218E060(ctx, base);
loc_8263C714:
	// lwz r3,1140(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 1140);
	// bl 0x82178b20
	ctx.lr = 0x8263C71C;
	sub_82178B20(ctx, base);
	// stw r3,1140(r29)
	PPC_STORE_U32(r29.u32 + 1140, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8263C728"))) PPC_WEAK_FUNC(sub_8263C728);
PPC_FUNC_IMPL(__imp__sub_8263C728) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r6,6
	ctx.r6.s64 = 393216;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,1448
	ctx.r8.s64 = r11.s64 + 1448;
	// ori r6,r6,16384
	ctx.r6.u64 = ctx.r6.u64 | 16384;
	// lwz r5,1148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb740
	ctx.lr = 0x8263C764;
	sub_821CB740(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r10,1444
	ctx.r5.s64 = ctx.r10.s64 + 1444;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca720
	ctx.lr = 0x8263C780;
	sub_821CA720(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r3,1240(r31)
	PPC_STORE_U32(r31.u32 + 1240, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,31296(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31296);
	f0.f64 = double(temp.f32);
	// stfs f0,1244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1244, temp.u32);
	// bl 0x821be568
	ctx.lr = 0x8263C798;
	sub_821BE568(ctx, base);
	// lwz r3,1240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// bl 0x821bdcf8
	ctx.lr = 0x8263C7A0;
	sub_821BDCF8(ctx, base);
	// li r5,85
	ctx.r5.s64 = 85;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,1240(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// lwz r3,1140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// bl 0x82775c60
	ctx.lr = 0x8263C7B4;
	sub_82775C60(ctx, base);
	// lwz r3,1240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// bl 0x821bdcf8
	ctx.lr = 0x8263C7BC;
	sub_821BDCF8(ctx, base);
	// subf r7,r30,r3
	ctx.r7.s64 = ctx.r3.s64 - r30.s64;
	// stw r7,864(r31)
	PPC_STORE_U32(r31.u32 + 864, ctx.r7.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_8263C7DC"))) PPC_WEAK_FUNC(sub_8263C7DC);
PPC_FUNC_IMPL(__imp__sub_8263C7DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263C7E0"))) PPC_WEAK_FUNC(sub_8263C7E0);
PPC_FUNC_IMPL(__imp__sub_8263C7E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8263C7E8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r29,r10,8191
	r29.u64 = ctx.r10.u64 | 8191;
	// lfs f0,1244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1244);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8263c82c
	if (!cr6.gt) goto loc_8263C82C;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bge cr6,0x8263c82c
	if (!cr6.lt) goto loc_8263C82C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263C82C:
	// lwz r11,1240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1240);
	// li r30,9
	r30.s64 = 9;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c858
	if (cr6.eq) goto loc_8263C858;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f1,1244(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1244, temp.u32);
	// bl 0x8263c5c8
	ctx.lr = 0x8263C854;
	sub_8263C5C8(ctx, base);
	// b 0x8263c85c
	goto loc_8263C85C;
loc_8263C858:
	// stw r30,592(r31)
	PPC_STORE_U32(r31.u32 + 592, r30.u32);
loc_8263C85C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c874
	if (cr6.eq) goto loc_8263C874;
	// lfs f0,1244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1244);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8263c878
	if (cr6.gt) goto loc_8263C878;
loc_8263C874:
	// stw r30,592(r31)
	PPC_STORE_U32(r31.u32 + 592, r30.u32);
loc_8263C878:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263c89c
	if (cr6.eq) goto loc_8263C89C;
	// lfs f0,1244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1244);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8263c89c
	if (!cr6.gt) goto loc_8263C89C;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8263c8a0
	if (cr6.lt) goto loc_8263C8A0;
loc_8263C89C:
	// li r11,0
	r11.s64 = 0;
loc_8263C8A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263C8B0"))) PPC_WEAK_FUNC(sub_8263C8B0);
PPC_FUNC_IMPL(__imp__sub_8263C8B0) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r6,6
	ctx.r6.s64 = 393216;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,1448
	ctx.r8.s64 = r11.s64 + 1448;
	// ori r6,r6,16384
	ctx.r6.u64 = ctx.r6.u64 | 16384;
	// lwz r5,1148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb740
	ctx.lr = 0x8263C8EC;
	sub_821CB740(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r11,-18004(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// stw r9,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r9.u32);
	// lwz r11,1148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// bne cr6,0x8263c9b0
	if (!cr6.eq) goto loc_8263C9B0;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r11,216
	cr6.compare<uint32_t>(r11.u32, 216, xer);
	// bne cr6,0x8263c9b0
	if (!cr6.eq) goto loc_8263C9B0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r4,1140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82775de0
	ctx.lr = 0x8263C92C;
	sub_82775DE0(ctx, base);
	// lwz r11,1132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r10,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r30,0(r10)
	r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263C950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// bne cr6,0x8263c984
	if (!cr6.eq) goto loc_8263C984;
	// lwz r3,1132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r11,1140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r30,2(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263C978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// beq cr6,0x8263c9a4
	if (cr6.eq) goto loc_8263C9A4;
loc_8263C984:
	// lwz r3,1132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r11,1140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263C9A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263C9A4:
	// lwz r4,1132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r3,1136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1136);
	// bl 0x8218f8d0
	ctx.lr = 0x8263C9B0;
	sub_8218F8D0(ctx, base);
loc_8263C9B0:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_8263C9C8"))) PPC_WEAK_FUNC(sub_8263C9C8);
PPC_FUNC_IMPL(__imp__sub_8263C9C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,1225(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263ca00
	if (cr6.eq) goto loc_8263CA00;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r9,r11,r4
	xer.ca = ctx.r4.u32 >= r11.u32;
	ctx.r9.s64 = ctx.r4.s64 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// b 0x8263ca1c
	goto loc_8263CA1C;
loc_8263CA00:
	// li r11,1
	r11.s64 = 1;
	// lwz r9,860(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r8,r11,r4
	ctx.r8.u64 = ctx.r4.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r4.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
loc_8263CA1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263cb38
	if (cr6.eq) goto loc_8263CB38;
	// lis r11,3
	r11.s64 = 196608;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ori r6,r11,8192
	ctx.r6.u64 = r11.u64 | 8192;
	// beq cr6,0x8263ca40
	if (cr6.eq) goto loc_8263CA40;
	// li r30,0
	r30.s64 = 0;
	// b 0x8263ca50
	goto loc_8263CA50;
loc_8263CA40:
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// mullw r10,r4,r6
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r11,204
	r30.s64 = r11.s64 + 204;
loc_8263CA50:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,1448
	ctx.r8.s64 = r11.s64 + 1448;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb740
	ctx.lr = 0x8263CA6C;
	sub_821CB740(ctx, base);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x8263cb38
	if (!cr6.eq) goto loc_8263CB38;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// cmplwi cr6,r11,216
	cr6.compare<uint32_t>(r11.u32, 216, xer);
	// bne cr6,0x8263cb38
	if (!cr6.eq) goto loc_8263CB38;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r4,1140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82775de0
	ctx.lr = 0x8263CA98;
	sub_82775DE0(ctx, base);
	// lwz r11,1132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stw r10,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r30,0(r10)
	r30.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263CABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// cmpw cr6,r3,r7
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, xer);
	// bne cr6,0x8263caf0
	if (!cr6.eq) goto loc_8263CAF0;
	// lwz r3,1132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r11,1140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r30,2(r11)
	r30.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263CAE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// beq cr6,0x8263cb10
	if (cr6.eq) goto loc_8263CB10;
loc_8263CAF0:
	// lwz r3,1132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r11,1140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263CB10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263CB10:
	// lwz r4,1132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// lwz r3,1136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1136);
	// bl 0x8218f8d0
	ctx.lr = 0x8263CB1C;
	sub_8218F8D0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8268ee10
	ctx.lr = 0x8263CB34;
	sub_8268EE10(ctx, base);
	// b 0x8263cb60
	goto loc_8263CB60;
loc_8263CB38:
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r3,r31,456
	ctx.r3.s64 = r31.s64 + 456;
	// addi r31,r10,1432
	r31.s64 = ctx.r10.s64 + 1432;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263CB54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263CB60;
	sub_825EE0E0(ctx, base);
loc_8263CB60:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_8263CB78"))) PPC_WEAK_FUNC(sub_8263CB78);
PPC_FUNC_IMPL(__imp__sub_8263CB78) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x8268d388
	ctx.lr = 0x8263CB98;
	sub_8268D388(ctx, base);
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bne cr6,0x8263cda4
	if (!cr6.eq) goto loc_8263CDA4;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8263cda4
	if (cr6.gt) goto loc_8263CDA4;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-13368
	r12.s64 = r12.s64 + -13368;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263CBD8;
	case 1:
		goto loc_8263CCD0;
	case 2:
		goto loc_8263CD80;
	case 3:
		goto loc_8263CCE4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-13352(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13352);
	// lwz r19,-13104(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13104);
	// lwz r19,-12928(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12928);
	// lwz r19,-13084(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13084);
loc_8263CBD8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r30,0
	r30.s64 = 0;
	// lbz r10,21380(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263cc14
	if (!cr6.eq) goto loc_8263CC14;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r11,493(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 493);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8263cc14
	if (!cr6.eq) goto loc_8263CC14;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263cc2c
	if (cr6.eq) goto loc_8263CC2C;
loc_8263CC14:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stb r11,25133(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25133, r11.u8);
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
loc_8263CC2C:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r11,r11,-9
	r11.s64 = r11.s64 + -9;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8263cda4
	if (cr6.gt) goto loc_8263CDA4;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-13228
	r12.s64 = r12.s64 + -13228;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263CC64;
	case 1:
		goto loc_8263CC8C;
	case 2:
		goto loc_8263CC80;
	case 3:
		goto loc_8263CC78;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-13212(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13212);
	// lwz r19,-13172(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13172);
	// lwz r19,-13184(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13184);
	// lwz r19,-13192(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -13192);
loc_8263CC64:
	// addi r3,r31,-456
	ctx.r3.s64 = r31.s64 + -456;
	// bl 0x8263c638
	ctx.lr = 0x8263CC6C;
	sub_8263C638(ctx, base);
	// li r11,12
	r11.s64 = 12;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CC78:
	// addi r3,r31,-456
	ctx.r3.s64 = r31.s64 + -456;
	// bl 0x8263c728
	ctx.lr = 0x8263CC80;
	sub_8263C728(ctx, base);
loc_8263CC80:
	// li r11,10
	r11.s64 = 10;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CC8C:
	// addi r3,r31,-456
	ctx.r3.s64 = r31.s64 + -456;
	// bl 0x8263c7e0
	ctx.lr = 0x8263CC94;
	sub_8263C7E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263cda4
	if (cr6.eq) goto loc_8263CDA4;
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// lwz r3,784(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 784);
	// bl 0x821be610
	ctx.lr = 0x8263CCAC;
	sub_821BE610(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8268ee10
	ctx.lr = 0x8263CCC4;
	sub_8268EE10(ctx, base);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r10.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CCD0:
	// addi r3,r31,-456
	ctx.r3.s64 = r31.s64 + -456;
	// bl 0x8263c8b0
	ctx.lr = 0x8263CCD8;
	sub_8263C8B0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CCE4:
	// lwz r11,732(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r11.u32);
	// lbz r9,25134(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25134);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263cda4
	if (cr6.eq) goto loc_8263CDA4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// ble cr6,0x8263cda4
	if (!cr6.gt) goto loc_8263CDA4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21380(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263cd68
	if (!cr6.eq) goto loc_8263CD68;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r11,493(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 493);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8263cd68
	if (!cr6.eq) goto loc_8263CD68;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263cd68
	if (!cr6.eq) goto loc_8263CD68;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,9
	ctx.r8.s64 = 9;
	// li r11,1
	r11.s64 = 1;
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r8.u32);
	// stb r11,25135(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25135, r11.u8);
	// stw r7,732(r31)
	PPC_STORE_U32(r31.u32 + 732, ctx.r7.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CD68:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stb r11,25133(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25133, r11.u8);
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// b 0x8263cda4
	goto loc_8263CDA4;
loc_8263CD80:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25134(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25134);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263cda4
	if (cr6.eq) goto loc_8263CDA4;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r11,1
	r11.s64 = 1;
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// stb r11,25135(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25135, r11.u8);
loc_8263CDA4:
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

__attribute__((alias("__imp__sub_8263CDBC"))) PPC_WEAK_FUNC(sub_8263CDBC);
PPC_FUNC_IMPL(__imp__sub_8263CDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263CDC0"))) PPC_WEAK_FUNC(sub_8263CDC0);
PPC_FUNC_IMPL(__imp__sub_8263CDC0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,1225(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1225);
	// lwz r31,1180(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1180);
loc_8263CDE8:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,16
	cr6.compare<int32_t>(r31.s32, 16, xer);
	// blt cr6,0x8263cdf8
	if (cr6.lt) goto loc_8263CDF8;
	// li r31,0
	r31.s64 = 0;
loc_8263CDF8:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8263ce14
	if (cr6.eq) goto loc_8263CE14;
	// lwz r11,1208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1208);
	// subfc r7,r11,r31
	xer.ca = r31.u32 >= r11.u32;
	ctx.r7.s64 = r31.s64 - r11.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r6,31
	r11.u64 = ctx.r6.u32 & 0x1;
	// b 0x8263ce2c
	goto loc_8263CE2C;
loc_8263CE14:
	// lwz r11,860(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 860);
	// slw r7,r10,r31
	ctx.r7.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// and r6,r11,r7
	ctx.r6.u64 = r11.u64 & ctx.r7.u64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
loc_8263CE2C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263ce48
	if (!cr6.eq) goto loc_8263CE48;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// blt cr6,0x8263cde8
	if (cr6.lt) goto loc_8263CDE8;
	// b 0x8263ce70
	goto loc_8263CE70;
loc_8263CE48:
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8263ce60
	if (!cr6.gt) goto loc_8263CE60;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,1460
	ctx.r3.s64 = r11.s64 + 1460;
	// bl 0x821e6800
	ctx.lr = 0x8263CE60;
	sub_821E6800(ctx, base);
loc_8263CE60:
	// stw r31,1180(r30)
	PPC_STORE_U32(r30.u32 + 1180, r31.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8263c9c8
	ctx.lr = 0x8263CE70;
	sub_8263C9C8(ctx, base);
loc_8263CE70:
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

__attribute__((alias("__imp__sub_8263CE88"))) PPC_WEAK_FUNC(sub_8263CE88);
PPC_FUNC_IMPL(__imp__sub_8263CE88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,1225(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 1225);
	// lwz r31,1180(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1180);
loc_8263CEB0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8263cebc
	if (!cr0.lt) goto loc_8263CEBC;
	// li r31,16
	r31.s64 = 16;
loc_8263CEBC:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8263ced8
	if (cr6.eq) goto loc_8263CED8;
	// lwz r11,1208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1208);
	// subfc r7,r11,r31
	xer.ca = r31.u32 >= r11.u32;
	ctx.r7.s64 = r31.s64 - r11.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r6,31
	r11.u64 = ctx.r6.u32 & 0x1;
	// b 0x8263cef0
	goto loc_8263CEF0;
loc_8263CED8:
	// lwz r11,860(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 860);
	// slw r7,r10,r31
	ctx.r7.u64 = r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r31.u8 & 0x3F));
	// and r6,r11,r7
	ctx.r6.u64 = r11.u64 & ctx.r7.u64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
loc_8263CEF0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263cf0c
	if (!cr6.eq) goto loc_8263CF0C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// blt cr6,0x8263ceb0
	if (cr6.lt) goto loc_8263CEB0;
	// b 0x8263cf34
	goto loc_8263CF34;
loc_8263CF0C:
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8263cf24
	if (!cr6.gt) goto loc_8263CF24;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,1460
	ctx.r3.s64 = r11.s64 + 1460;
	// bl 0x821e6800
	ctx.lr = 0x8263CF24;
	sub_821E6800(ctx, base);
loc_8263CF24:
	// stw r31,1180(r30)
	PPC_STORE_U32(r30.u32 + 1180, r31.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8263c9c8
	ctx.lr = 0x8263CF34;
	sub_8263C9C8(ctx, base);
loc_8263CF34:
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

__attribute__((alias("__imp__sub_8263CF4C"))) PPC_WEAK_FUNC(sub_8263CF4C);
PPC_FUNC_IMPL(__imp__sub_8263CF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263CF50"))) PPC_WEAK_FUNC(sub_8263CF50);
PPC_FUNC_IMPL(__imp__sub_8263CF50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// lwz r10,820(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 820);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r9,824(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 824);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r8,832(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 832);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263CF70"))) PPC_WEAK_FUNC(sub_8263CF70);
PPC_FUNC_IMPL(__imp__sub_8263CF70) {
	PPC_FUNC_PROLOGUE();
	// lis r3,50
	ctx.r3.s64 = 3276800;
	// ori r3,r3,204
	ctx.r3.u64 = ctx.r3.u64 | 204;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263CF7C"))) PPC_WEAK_FUNC(sub_8263CF7C);
PPC_FUNC_IMPL(__imp__sub_8263CF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263CF80"))) PPC_WEAK_FUNC(sub_8263CF80);
PPC_FUNC_IMPL(__imp__sub_8263CF80) {
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
	// bl 0x82130000
	ctx.lr = 0x8263CF98;
	sub_82130000(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lbz r4,780(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 780);
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5b20
	ctx.lr = 0x8263CFA8;
	sub_822E5B20(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lbz r11,25137(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25137);
	// lwz r10,21664(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 21664);
	// stb r11,121(r10)
	PPC_STORE_U8(ctx.r10.u32 + 121, r11.u8);
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

__attribute__((alias("__imp__sub_8263CFD0"))) PPC_WEAK_FUNC(sub_8263CFD0);
PPC_FUNC_IMPL(__imp__sub_8263CFD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,408(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	// addi r11,r3,404
	r11.s64 = ctx.r3.s64 + 404;
	// lwz r8,404(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	// li r10,0
	ctx.r10.s64 = 0;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi. r6,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi r11,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	r11.s64 = ctx.r7.s32 >> 2;
loc_8263CFFC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8263cffc
	if (cr6.lt) goto loc_8263CFFC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263D00C"))) PPC_WEAK_FUNC(sub_8263D00C);
PPC_FUNC_IMPL(__imp__sub_8263D00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263D010"))) PPC_WEAK_FUNC(sub_8263D010);
PPC_FUNC_IMPL(__imp__sub_8263D010) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10228);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263d044
	if (cr6.eq) goto loc_8263D044;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263D044;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263D044:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10228(r31)
	PPC_STORE_U32(r31.u32 + -10228, r11.u32);
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

__attribute__((alias("__imp__sub_8263D060"))) PPC_WEAK_FUNC(sub_8263D060);
PPC_FUNC_IMPL(__imp__sub_8263D060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,721(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 721);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stb r10,721(r3)
	PPC_STORE_U8(ctx.r3.u32 + 721, ctx.r10.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-14960
	ctx.r4.s64 = ctx.r9.s64 + -14960;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8263D098"))) PPC_WEAK_FUNC(sub_8263D098);
PPC_FUNC_IMPL(__imp__sub_8263D098) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263D09C"))) PPC_WEAK_FUNC(sub_8263D09C);
PPC_FUNC_IMPL(__imp__sub_8263D09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263D0A0"))) PPC_WEAK_FUNC(sub_8263D0A0);
PPC_FUNC_IMPL(__imp__sub_8263D0A0) {
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
	// bl 0x82635538
	ctx.lr = 0x8263D0B8;
	sub_82635538(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263D0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r6,1
	ctx.r6.s64 = 1;
	// stb r6,715(r31)
	PPC_STORE_U8(r31.u32 + 715, ctx.r6.u8);
	// lwz r11,2832(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2832);
	// lbz r5,10096(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 10096);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8263d108
	if (cr6.eq) goto loc_8263D108;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x8268ee10
	ctx.lr = 0x8263D108;
	sub_8268EE10(ctx, base);
loc_8263D108:
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

__attribute__((alias("__imp__sub_8263D11C"))) PPC_WEAK_FUNC(sub_8263D11C);
PPC_FUNC_IMPL(__imp__sub_8263D11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263D120"))) PPC_WEAK_FUNC(sub_8263D120);
PPC_FUNC_IMPL(__imp__sub_8263D120) {
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
	ctx.lr = 0x8263D128;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lbz r11,25134(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25134);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263d1d8
	if (!cr6.eq) goto loc_8263D1D8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r30,1
	r30.s64 = 1;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lbz r10,14584(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14584);
	// stb r10,25136(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25136, ctx.r10.u8);
	// stb r30,14584(r11)
	PPC_STORE_U8(r11.u32 + 14584, r30.u8);
	// lwz r11,21664(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21664);
	// lwz r10,316(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 316);
	// stw r10,25124(r7)
	PPC_STORE_U32(ctx.r7.u32 + 25124, ctx.r10.u32);
	// stw r30,316(r11)
	PPC_STORE_U32(r11.u32 + 316, r30.u32);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lwz r4,364(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// stw r4,25040(r6)
	PPC_STORE_U32(ctx.r6.u32 + 25040, ctx.r4.u32);
	// bl 0x822e5b10
	ctx.lr = 0x8263D188;
	sub_822E5B10(ctx, base);
	// lis r4,10240
	ctx.r4.s64 = 671088640;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e5b00
	ctx.lr = 0x8263D194;
	sub_822E5B00(ctx, base);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r3,-32119
	ctx.r3.s64 = -2104950784;
	// li r31,0
	r31.s64 = 0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,-7896(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -7896);
	// stb r31,3392(r11)
	PPC_STORE_U8(r11.u32 + 3392, r31.u8);
	// lwz r11,-18004(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -18004);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stb r31,4(r9)
	PPC_STORE_U8(ctx.r9.u32 + 4, r31.u8);
	// lwz r3,-10024(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10024);
	// bl 0x82224e58
	ctx.lr = 0x8263D1C4;
	sub_82224E58(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// stb r11,25134(r29)
	PPC_STORE_U8(r29.u32 + 25134, r11.u8);
	// stb r10,25135(r8)
	PPC_STORE_U8(ctx.r8.u32 + 25135, ctx.r10.u8);
loc_8263D1D8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263D1E0"))) PPC_WEAK_FUNC(sub_8263D1E0);
PPC_FUNC_IMPL(__imp__sub_8263D1E0) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lbz r11,25134(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25134);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263d290
	if (cr6.eq) goto loc_8263D290;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-10024(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10024);
	// bl 0x82224e48
	ctx.lr = 0x8263D214;
	sub_82224E48(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lwz r11,-18004(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18004);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stb r10,4(r5)
	PPC_STORE_U8(ctx.r5.u32 + 4, ctx.r10.u8);
	// lwz r11,-7896(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7896);
	// stb r10,3392(r11)
	PPC_STORE_U8(r11.u32 + 3392, ctx.r10.u8);
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// lwz r4,25040(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 25040);
	// bl 0x822e5b00
	ctx.lr = 0x8263D248;
	sub_822E5B00(ctx, base);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lis r3,-32120
	ctx.r3.s64 = -2105016320;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lbz r11,25136(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 25136);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lwz r10,-7572(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + -7572);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,14584(r10)
	PPC_STORE_U8(ctx.r10.u32 + 14584, r11.u8);
	// lwz r11,25124(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 25124);
	// lwz r10,21664(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 21664);
	// stw r11,316(r10)
	PPC_STORE_U32(ctx.r10.u32 + 316, r11.u32);
	// stb r9,25134(r31)
	PPC_STORE_U8(r31.u32 + 25134, ctx.r9.u8);
	// stb r8,25135(r30)
	PPC_STORE_U8(r30.u32 + 25135, ctx.r8.u8);
	// stb r7,25116(r4)
	PPC_STORE_U8(ctx.r4.u32 + 25116, ctx.r7.u8);
loc_8263D290:
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

__attribute__((alias("__imp__sub_8263D2A8"))) PPC_WEAK_FUNC(sub_8263D2A8);
PPC_FUNC_IMPL(__imp__sub_8263D2A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8263D2B0;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82180430
	ctx.lr = 0x8263D2C4;
	sub_82180430(ctx, base);
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,28
	r29.s64 = 28;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263D2E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r9,r29,r30
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263D31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,1660
	ctx.r5.s64 = ctx.r10.s64 + 1660;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D350;
	sub_82137A08(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r26,r11,9572
	r26.s64 = r11.s64 + 9572;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130000
	ctx.lr = 0x8263D364;
	sub_82130000(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263D37C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r7,r29,r30
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263D39C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,40(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D3B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263D3CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r23,r11,1644
	r23.s64 = r11.s64 + 1644;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D3EC;
	sub_82137A08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8263D3F8;
	sub_82130000(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,20(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263D448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r22,r11,1628
	r22.s64 = r11.s64 + 1628;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D480;
	sub_82137A08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8263D48C;
	sub_82130000(ctx, base);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r6.u32);
	// stb r5,194(r1)
	PPC_STORE_U8(ctx.r1.u32 + 194, ctx.r5.u8);
	// lis r27,-32120
	r27.s64 = -2105016320;
	// stw r4,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r4.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e5048
	ctx.lr = 0x8263D4BC;
	sub_822E5048(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-24876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24876);
	// stw r11,-24876(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24876, r11.u32);
	// bl 0x82183710
	ctx.lr = 0x8263D4D8;
	sub_82183710(ctx, base);
	// lis r3,56
	ctx.r3.s64 = 3670016;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// ori r3,r3,20480
	ctx.r3.u64 = ctx.r3.u64 | 20480;
	// bl 0x82183748
	ctx.lr = 0x8263D4E8;
	sub_82183748(ctx, base);
	// addi r9,r3,4095
	ctx.r9.s64 = ctx.r3.s64 + 4095;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// rlwinm r7,r9,0,0,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFF000;
	// lis r6,6184
	ctx.r6.s64 = 405274624;
	// stw r7,1144(r31)
	PPC_STORE_U32(r31.u32 + 1144, ctx.r7.u32);
	// li r5,720
	ctx.r5.s64 = 720;
	// ori r6,r6,134
	ctx.r6.u64 = ctx.r6.u64 | 134;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// li r4,1280
	ctx.r4.s64 = 1280;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,1144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1144);
	// stw r3,1132(r31)
	PPC_STORE_U32(r31.u32 + 1132, ctx.r3.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,720
	ctx.r4.s64 = 720;
	// li r3,1280
	ctx.r3.s64 = 1280;
	// bl 0x8218de38
	ctx.lr = 0x8263D544;
	sub_8218DE38(ctx, base);
	// stw r3,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, ctx.r3.u32);
	// lis r3,50
	ctx.r3.s64 = 3276800;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// ori r3,r3,204
	ctx.r3.u64 = ctx.r3.u64 | 204;
	// bl 0x82183748
	ctx.lr = 0x8263D558;
	sub_82183748(ctx, base);
	// stw r3,428(r31)
	PPC_STORE_U32(r31.u32 + 428, ctx.r3.u32);
	// lis r3,6
	ctx.r3.s64 = 393216;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// ori r3,r3,16384
	ctx.r3.u64 = ctx.r3.u64 | 16384;
	// bl 0x82183748
	ctx.lr = 0x8263D56C;
	sub_82183748(ctx, base);
	// stw r3,1148(r31)
	PPC_STORE_U32(r31.u32 + 1148, ctx.r3.u32);
	// lwz r3,-8092(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x8263D578;
	sub_822E50B8(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r27,r10,30576
	r27.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,1600
	ctx.r4.s64 = ctx.r9.s64 + 1600;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x8263D590;
	sub_821CA540(ctx, base);
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,1580
	ctx.r4.s64 = ctx.r8.s64 + 1580;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8263D5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, ctx.r3.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x8218de38
	ctx.lr = 0x8263D5D8;
	sub_8218DE38(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8263D5E4;
	sub_821C9A90(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r27,r31,608
	r27.s64 = r31.s64 + 608;
	// addi r21,r10,1568
	r21.s64 = ctx.r10.s64 + 1568;
loc_8263D5F4:
	// addi r25,r11,1
	r25.s64 = r11.s64 + 1;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x8263D60C;
	sub_82137A08(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8263D614;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263d630
	if (cr6.eq) goto loc_8263D630;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r5,1128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// bl 0x8218fad0
	ctx.lr = 0x8263D628;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8263d634
	goto loc_8263D634;
loc_8263D630:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8263D634:
	// stw r5,-4(r27)
	PPC_STORE_U32(r27.u32 + -4, ctx.r5.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x8263D644;
	sub_82182150(ctx, base);
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263D660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// mr r11,r25
	r11.u64 = r25.u64;
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// cmplwi cr6,r25,16
	cr6.compare<uint32_t>(r25.u32, 16, xer);
	// blt cr6,0x8263d5f4
	if (cr6.lt) goto loc_8263D5F4;
	// lwz r11,32(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r24)
	PPC_STORE_U32(r24.u32 + 32, r11.u32);
	// bne 0x8263d694
	if (!cr0.eq) goto loc_8263D694;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8263D68C;
	sub_8218CD10(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82130588
	ctx.lr = 0x8263D694;
	sub_82130588(ctx, base);
loc_8263D694:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8263D69C;
	sub_82130528(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r27,r11,1552
	r27.s64 = r11.s64 + 1552;
	// beq cr6,0x8263d6c0
	if (cr6.eq) goto loc_8263D6C0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r5,1128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// bl 0x8218fad0
	ctx.lr = 0x8263D6B8;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x8263d6c4
	goto loc_8263D6C4;
loc_8263D6C0:
	// li r5,0
	ctx.r5.s64 = 0;
loc_8263D6C4:
	// stw r5,1136(r31)
	PPC_STORE_U32(r31.u32 + 1136, ctx.r5.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-25232(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x8263D6D4;
	sub_82182150(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263D6EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r9,r29,r30
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263D724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D73C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,1500
	ctx.r5.s64 = ctx.r10.s64 + 1500;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D758;
	sub_82137A08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8263D764;
	sub_82130000(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263D77C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r7,r29,r30
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263D79C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,40(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D7B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263D7CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D7E4;
	sub_82137A08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82130000
	ctx.lr = 0x8263D7F0;
	sub_82130000(ctx, base);
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r11,20(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8263D828;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263D840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263D858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x8263D870;
	sub_82137A08(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8263D878"))) PPC_WEAK_FUNC(sub_8263D878);
PPC_FUNC_IMPL(__imp__sub_8263D878) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8263D880;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r23,1
	r23.s64 = 1;
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263d8b0
	if (cr6.eq) goto loc_8263D8B0;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r10,r11,r30
	xer.ca = r30.u32 >= r11.u32;
	ctx.r10.s64 = r30.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263d8c8
	goto loc_8263D8C8;
loc_8263D8B0:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r10,r23,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r23.u32 << (r30.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_8263D8C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263db24
	if (cr6.eq) goto loc_8263DB24;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c1f0
	ctx.lr = 0x8263D8E0;
	sub_8263C1F0(ctx, base);
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r9,428(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r28,0
	r28.s64 = 0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r30,55
	ctx.r7.s64 = r30.s64 + 55;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// rlwinm r5,r7,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r26,r6,25048
	r26.s64 = ctx.r6.s64 + 25048;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r25,r30,2,0,29
	r25.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,20(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// addi r29,r11,872
	r29.s64 = r11.s64 + 872;
	// stw r28,872(r11)
	PPC_STORE_U32(r11.u32 + 872, r28.u32);
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r28,876(r11)
	PPC_STORE_U32(r11.u32 + 876, r28.u32);
	// addi r27,r11,876
	r27.s64 = r11.s64 + 876;
	// stw r28,880(r11)
	PPC_STORE_U32(r11.u32 + 880, r28.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// stw r28,884(r11)
	PPC_STORE_U32(r11.u32 + 884, r28.u32);
	// stw r30,872(r11)
	PPC_STORE_U32(r11.u32 + 872, r30.u32);
	// stw r10,876(r11)
	PPC_STORE_U32(r11.u32 + 876, ctx.r10.u32);
	// stwx r4,r5,r31
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, ctx.r4.u32);
	// lwzx r11,r25,r26
	r11.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263da50
	if (cr6.eq) goto loc_8263DA50;
	// lbz r10,1248(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1248);
	// addi r9,r11,76
	ctx.r9.s64 = r11.s64 + 76;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263d9d8
	if (!cr6.eq) goto loc_8263D9D8;
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x8263d9d8
	if (!cr6.eq) goto loc_8263D9D8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263d9d8
	if (cr6.eq) goto loc_8263D9D8;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r9,16
	ctx.r8.s64 = ctx.r9.s64 + 16;
loc_8263D984:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x8263d9a4
	if (!cr0.eq) goto loc_8263D9A4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x8263d984
	if (!cr6.eq) goto loc_8263D984;
loc_8263D9A4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8263d9d8
	if (!cr6.eq) goto loc_8263D9D8;
	// lhz r11,1232(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263db30
	if (!cr6.eq) goto loc_8263DB30;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x8268ee10
	ctx.lr = 0x8263D9D0;
	sub_8268EE10(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_8263D9D8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8268ee10
	ctx.lr = 0x8263D9F0;
	sub_8268EE10(ctx, base);
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r23,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r23.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stb r28,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r28.u8);
	// stw r10,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r10.u32);
	// addi r8,r31,1200
	ctx.r8.s64 = r31.s64 + 1200;
	// lwzx r5,r25,r26
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// addi r7,r9,27576
	ctx.r7.s64 = ctx.r9.s64 + 27576;
	// addi r6,r31,1196
	ctx.r6.s64 = r31.s64 + 1196;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r4,r11,21436
	ctx.r4.s64 = r11.s64 + 21436;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,25044(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 25044);
	// bl 0x824f7468
	ctx.lr = 0x8263DA48;
	sub_824F7468(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_8263DA50:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,13
	ctx.r4.s64 = 13;
	// bl 0x8268ee10
	ctx.lr = 0x8263DA68;
	sub_8268EE10(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r23,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r10.u32);
	// bl 0x82388580
	ctx.lr = 0x8263DA7C;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8263DA90;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8263DA9C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8263DAAC;
	sub_82270170(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// addi r25,r31,1200
	r25.s64 = r31.s64 + 1200;
	// addi r30,r7,27576
	r30.s64 = ctx.r7.s64 + 27576;
	// addi r31,r31,1196
	r31.s64 = r31.s64 + 1196;
	// bl 0x824e7118
	ctx.lr = 0x8263DAC8;
	sub_824E7118(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r26,16
	ctx.r3.s64 = r26.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8263DAD4;
	sub_824E7110(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// li r11,16
	r11.s64 = 16;
	// stb r28,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r28.u8);
	// addi r4,r4,21436
	ctx.r4.s64 = ctx.r4.s64 + 21436;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// lwz r3,25044(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 25044);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r25,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r25.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// bl 0x824f7308
	ctx.lr = 0x8263DB1C;
	sub_824F7308(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_8263DB24:
	// li r28,0
	r28.s64 = 0;
	// stw r28,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r28.u32);
	// stw r28,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r28.u32);
loc_8263DB30:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8263DB38"))) PPC_WEAK_FUNC(sub_8263DB38);
PPC_FUNC_IMPL(__imp__sub_8263DB38) {
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
	ctx.lr = 0x8263DB40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x8268ee10
	ctx.lr = 0x8263DB60;
	sub_8268EE10(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,7
	ctx.r8.s64 = 7;
	// addi r3,r10,25048
	ctx.r3.s64 = ctx.r10.s64 + 25048;
	// stw r9,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r9.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r8,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8263DB84;
	sub_823D9890(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8263DB8C;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r3,-10240(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8263DBA0;
	sub_82270170(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// addi r30,r5,25144
	r30.s64 = ctx.r5.s64 + 25144;
	// addi r31,r31,1208
	r31.s64 = r31.s64 + 1208;
	// bl 0x824e7110
	ctx.lr = 0x8263DBB8;
	sub_824E7110(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r4,r10,21436
	ctx.r4.s64 = ctx.r10.s64 + 21436;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r3,25044(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 25044);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// bl 0x824f6ea0
	ctx.lr = 0x8263DBE0;
	sub_824F6EA0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263DBE8"))) PPC_WEAK_FUNC(sub_8263DBE8);
PPC_FUNC_IMPL(__imp__sub_8263DBE8) {
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
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x8268ee10
	ctx.lr = 0x8263DC14;
	sub_8268EE10(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,1224(r31)
	PPC_STORE_U8(r31.u32 + 1224, ctx.r10.u8);
	// bl 0x8263db38
	ctx.lr = 0x8263DC24;
	sub_8263DB38(ctx, base);
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

__attribute__((alias("__imp__sub_8263DC38"))) PPC_WEAK_FUNC(sub_8263DC38);
PPC_FUNC_IMPL(__imp__sub_8263DC38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,21436
	ctx.r3.s64 = r11.s64 + 21436;
	// bl 0x821fa230
	ctx.lr = 0x8263DC58;
	sub_821FA230(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lbz r9,25116(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25116);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263dce4
	if (cr6.eq) goto loc_8263DCE4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263dce4
	if (cr6.eq) goto loc_8263DCE4;
	// lbz r9,1225(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8263DC7C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263dc98
	if (cr6.eq) goto loc_8263DC98;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r8,r11,r4
	xer.ca = ctx.r4.u32 >= r11.u32;
	ctx.r8.s64 = ctx.r4.s64 - r11.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	// b 0x8263dcb0
	goto loc_8263DCB0;
loc_8263DC98:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r8,r10,r4
	ctx.r8.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r4.u8 & 0x3F));
	// and r7,r11,r8
	ctx.r7.u64 = r11.u64 & ctx.r8.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
loc_8263DCB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263dccc
	if (cr6.eq) goto loc_8263DCCC;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmpwi cr6,r4,16
	cr6.compare<int32_t>(ctx.r4.s32, 16, xer);
	// blt cr6,0x8263dc7c
	if (cr6.lt) goto loc_8263DC7C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8263DCCC:
	// bl 0x8268dcb0
	ctx.lr = 0x8263DCD0;
	sub_8268DCB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263DCE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263DCE4:
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

__attribute__((alias("__imp__sub_8263DCF8"))) PPC_WEAK_FUNC(sub_8263DCF8);
PPC_FUNC_IMPL(__imp__sub_8263DCF8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8263DD00;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r6,864(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// lwz r5,1148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// bl 0x8263c248
	ctx.lr = 0x8263DD18;
	sub_8263C248(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r5,1148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// lis r6,6
	ctx.r6.s64 = 393216;
	// addi r27,r11,1448
	r27.s64 = r11.s64 + 1448;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r6,r6,16384
	ctx.r6.u64 = ctx.r6.u64 | 16384;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821cb740
	ctx.lr = 0x8263DD40;
	sub_821CB740(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,1140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82775de0
	ctx.lr = 0x8263DD54;
	sub_82775DE0(ctx, base);
	// stw r3,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, ctx.r3.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x8218ee38
	ctx.lr = 0x8263DD68;
	sub_8218EE38(ctx, base);
	// addi r11,r29,38
	r11.s64 = r29.s64 + 38;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r28,r11,4,0,27
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r3,r28,r31
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263dd98
	if (cr6.eq) goto loc_8263DD98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263DD94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8263ddb8
	goto loc_8263DDB8;
loc_8263DD98:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263DDB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r28,r31
	PPC_STORE_U32(r28.u32 + r31.u32, ctx.r3.u32);
loc_8263DDB8:
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r4,r28,r31
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r31.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r3,604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 604);
	// bl 0x8218f8d0
	ctx.lr = 0x8263DDCC;
	sub_8218F8D0(ctx, base);
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// bne 0x8263ddec
	if (!cr0.eq) goto loc_8263DDEC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8263DDE4;
	sub_8218CD10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8263DDEC;
	sub_82130588(ctx, base);
loc_8263DDEC:
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263de10
	if (cr6.eq) goto loc_8263DE10;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r10,r11,r29
	xer.ca = r29.u32 >= r11.u32;
	ctx.r10.s64 = r29.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263de28
	goto loc_8263DE28;
loc_8263DE10:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r10,r28,r29
	ctx.r10.u64 = r29.u8 & 0x20 ? 0 : (r28.u32 << (r29.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_8263DE28:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263de70
	if (!cr6.eq) goto loc_8263DE70;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r11.u32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x8263de70
	if (!cr6.eq) goto loc_8263DE70;
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,1816
	ctx.r4.s64 = r11.s64 + 1816;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263DE70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263DE70:
	// lwz r3,-12440(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12440);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,1808
	ctx.r4.s64 = r11.s64 + 1808;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263DE94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,860(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r30,r28,r29
	r30.u64 = r29.u8 & 0x20 ? 0 : (r28.u32 << (r29.u8 & 0x3F));
	// or r7,r30,r8
	ctx.r7.u64 = r30.u64 | ctx.r8.u64;
	// stw r7,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r7.u32);
	// bl 0x82178848
	ctx.lr = 0x8263DEA8;
	sub_82178848(ctx, base);
	// lwz r11,868(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// or r10,r11,r30
	ctx.r10.u64 = r11.u64 | r30.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8263dec0
	if (!cr6.eq) goto loc_8263DEC0;
	// andc r10,r11,r30
	ctx.r10.u64 = r11.u64 & ~r30.u64;
loc_8263DEC0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r10,868(r31)
	PPC_STORE_U32(r31.u32 + 868, ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263DEE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stb r11,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r11.u8);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stb r11,1176(r31)
	PPC_STORE_U8(r31.u32 + 1176, r11.u8);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r3,r8,1792
	ctx.r3.s64 = ctx.r8.s64 + 1792;
	// addi r31,r7,-22132
	r31.s64 = ctx.r7.s64 + -22132;
	// addi r30,r6,-22108
	r30.s64 = ctx.r6.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8263DF0C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8263DF20;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,112(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8263DF34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263DF4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263DF64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r6,28
	ctx.r6.s64 = 28;
	// lwzx r3,r6,r7
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8263DF80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrldi r3,r3,32
	ctx.r3.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,16928(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16928);
	f0.f64 = double(temp.f32);
	// addi r3,r10,1720
	ctx.r3.s64 = ctx.r10.s64 + 1720;
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x8263DFB4;
	sub_82130000(ctx, base);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8263DFBC"))) PPC_WEAK_FUNC(sub_8263DFBC);
PPC_FUNC_IMPL(__imp__sub_8263DFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263DFC0"))) PPC_WEAK_FUNC(sub_8263DFC0);
PPC_FUNC_IMPL(__imp__sub_8263DFC0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8263DFC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,1824
	ctx.r3.s64 = r11.s64 + 1824;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821fa230
	ctx.lr = 0x8263DFE0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263DFF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263e1dc
	if (!cr6.eq) goto loc_8263E1DC;
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// addi r27,r31,456
	r27.s64 = r31.s64 + 456;
	// stw r30,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E018;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,1170(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263e098
	if (cr6.eq) goto loc_8263E098;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8263E03C;
	sub_8220F040(ctx, base);
	// lbz r10,1225(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263e060
	if (cr6.eq) goto loc_8263E060;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r10,r11,r30
	xer.ca = r30.u32 >= r11.u32;
	ctx.r10.s64 = r30.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263e078
	goto loc_8263E078;
loc_8263E060:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r10,r29,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r29.u32 << (r30.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_8263E078:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,1432
	ctx.r4.s64 = r11.s64 + 1432;
	// beq cr6,0x8263e138
	if (cr6.eq) goto loc_8263E138;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8263e13c
	goto loc_8263E13C;
loc_8263E098:
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e0bc
	if (cr6.eq) goto loc_8263E0BC;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r10,r11,r30
	xer.ca = r30.u32 >= r11.u32;
	ctx.r10.s64 = r30.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263e0d4
	goto loc_8263E0D4;
loc_8263E0BC:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r10,r29,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r29.u32 << (r30.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_8263E0D4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e108
	if (cr6.eq) goto loc_8263E108;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8263E0F4;
	sub_8220F040(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,1432
	ctx.r4.s64 = ctx.r10.s64 + 1432;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// b 0x8263e13c
	goto loc_8263E13C;
loc_8263E108:
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// li r4,56
	ctx.r4.s64 = 56;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bgt cr6,0x8263e128
	if (cr6.gt) goto loc_8263E128;
	// li r4,58
	ctx.r4.s64 = 58;
loc_8263E128:
	// bl 0x8220f040
	ctx.lr = 0x8263E12C;
	sub_8220F040(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r10,1432
	ctx.r4.s64 = ctx.r10.s64 + 1432;
loc_8263E138:
	// li r5,1
	ctx.r5.s64 = 1;
loc_8263E13C:
	// bl 0x825ee0e0
	ctx.lr = 0x8263E140;
	sub_825EE0E0(ctx, base);
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263e1a8
	if (!cr6.eq) goto loc_8263E1A8;
	// lwz r11,588(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8263e1a8
	if (!cr6.eq) goto loc_8263E1A8;
	// lwz r11,868(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// slw r10,r29,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r29.u32 << (r30.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r29,r7,1
	r29.u64 = ctx.r7.u64 ^ 1;
	// bl 0x82178848
	ctx.lr = 0x8263E174;
	sub_82178848(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r5,r29,24
	ctx.r5.u64 = r29.u32 & 0xFF;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// cmplw cr6,r5,r6
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// addi r29,r10,1412
	r29.s64 = ctx.r10.s64 + 1412;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// beq cr6,0x8263e1c0
	if (cr6.eq) goto loc_8263E1C0;
	// bctrl 
	ctx.lr = 0x8263E1A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8263e1c8
	goto loc_8263E1C8;
loc_8263E1A8:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r29,r10,1412
	r29.s64 = ctx.r10.s64 + 1412;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8263E1C0:
	// bctrl 
	ctx.lr = 0x8263E1C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
loc_8263E1C8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263E1D0;
	sub_825EE0E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c9c8
	ctx.lr = 0x8263E1DC;
	sub_8263C9C8(ctx, base);
loc_8263E1DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8263E1E4"))) PPC_WEAK_FUNC(sub_8263E1E4);
PPC_FUNC_IMPL(__imp__sub_8263E1E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263E1E8"))) PPC_WEAK_FUNC(sub_8263E1E8);
PPC_FUNC_IMPL(__imp__sub_8263E1E8) {
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
	ctx.lr = 0x8263E1F0;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,3
	ctx.r10.s64 = 196608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// ori r6,r10,8192
	ctx.r6.u64 = ctx.r10.u64 | 8192;
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e218
	if (cr6.eq) goto loc_8263E218;
	// li r29,0
	r29.s64 = 0;
	// b 0x8263e228
	goto loc_8263E228;
loc_8263E218:
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// mullw r10,r30,r6
	ctx.r10.s64 = int64_t(r30.s32) * int64_t(ctx.r6.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r29,r11,204
	r29.s64 = r11.s64 + 204;
loc_8263E228:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,1448
	ctx.r8.s64 = r11.s64 + 1448;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cb740
	ctx.lr = 0x8263E244;
	sub_821CB740(ctx, base);
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e264
	if (cr6.eq) goto loc_8263E264;
	// lbz r10,1186(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1186);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263e270
	if (cr6.eq) goto loc_8263E270;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263e3e4
	if (!cr6.eq) goto loc_8263E3E4;
loc_8263E264:
	// lbz r10,1185(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263e3dc
	if (!cr6.eq) goto loc_8263E3DC;
loc_8263E270:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// bne cr6,0x8263e3b0
	if (!cr6.eq) goto loc_8263E3B0;
	// lbz r11,1(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 1);
	// cmplwi cr6,r11,216
	cr6.compare<uint32_t>(r11.u32, 216, xer);
	// bne cr6,0x8263e3b0
	if (!cr6.eq) goto loc_8263E3B0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,1140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1140);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82775de0
	ctx.lr = 0x8263E29C;
	sub_82775DE0(ctx, base);
	// stw r3,1140(r31)
	PPC_STORE_U32(r31.u32 + 1140, ctx.r3.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x8218ee38
	ctx.lr = 0x8263E2B0;
	sub_8218EE38(ctx, base);
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// beq cr6,0x8263e330
	if (cr6.eq) goto loc_8263E330;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// lwz r3,612(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 612);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263e2fc
	if (cr6.eq) goto loc_8263E2FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E2E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217f540
	ctx.lr = 0x8263E2F0;
	sub_8217F540(ctx, base);
	// lwz r4,612(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 612);
	// lwz r3,604(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 604);
	// b 0x8263e390
	goto loc_8263E390;
loc_8263E2FC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263E318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,612(r30)
	PPC_STORE_U32(r30.u32 + 612, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217f540
	ctx.lr = 0x8263E324;
	sub_8217F540(ctx, base);
	// lwz r4,612(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 612);
	// lwz r3,604(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 604);
	// b 0x8263e390
	goto loc_8263E390;
loc_8263E330:
	// addi r11,r30,38
	r11.s64 = r30.s64 + 38;
	// rlwinm r29,r11,4,0,27
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263e358
	if (cr6.eq) goto loc_8263E358;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8263e378
	goto loc_8263E378;
loc_8263E358:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263E374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r3.u32);
loc_8263E378:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217f540
	ctx.lr = 0x8263E380;
	sub_8217F540(ctx, base);
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwzx r4,r29,r31
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r3,604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 604);
loc_8263E390:
	// bl 0x8218f8d0
	ctx.lr = 0x8263E394;
	sub_8218F8D0(ctx, base);
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e41c
	if (cr6.eq) goto loc_8263E41C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c8b0
	ctx.lr = 0x8263E3A8;
	sub_8263C8B0(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_8263E3B0:
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r4,1128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r3,604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 604);
	// bl 0x8218f8d0
	ctx.lr = 0x8263E3C4;
	sub_8218F8D0(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r10,1844
	ctx.r3.s64 = ctx.r10.s64 + 1844;
	// bl 0x82130000
	ctx.lr = 0x8263E3D4;
	sub_82130000(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_8263E3DC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e400
	if (cr6.eq) goto loc_8263E400;
loc_8263E3E4:
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r4,612(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// lwz r3,604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 604);
	// bl 0x8218f8d0
	ctx.lr = 0x8263E3F8;
	sub_8218F8D0(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
loc_8263E400:
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r30,38
	ctx.r10.s64 = r30.s64 + 38;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r3,604(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 604);
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x8218f8d0
	ctx.lr = 0x8263E41C;
	sub_8218F8D0(ctx, base);
loc_8263E41C:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8263E424"))) PPC_WEAK_FUNC(sub_8263E424);
PPC_FUNC_IMPL(__imp__sub_8263E424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263E428"))) PPC_WEAK_FUNC(sub_8263E428);
PPC_FUNC_IMPL(__imp__sub_8263E428) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263e474
	if (!cr6.eq) goto loc_8263E474;
	// li r11,5
	r11.s64 = 5;
	// stw r10,1188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1188, ctx.r10.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 588, r11.u32);
	// stb r9,1172(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1172, ctx.r9.u8);
	// bl 0x8263c0e8
	ctx.lr = 0x8263E460;
	sub_8263C0E8(ctx, base);
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
loc_8263E474:
	// lbz r11,1170(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e4ac
	if (cr6.eq) goto loc_8263E4AC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x8268ee10
	ctx.lr = 0x8263E498;
	sub_8268EE10(ctx, base);
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
loc_8263E4AC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r31,1180(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1180);
	// addi r3,r11,21436
	ctx.r3.s64 = r11.s64 + 21436;
	// bl 0x821fa230
	ctx.lr = 0x8263E4BC;
	sub_821FA230(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8263E4C4;
	sub_8268DCB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263E4D8;
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

__attribute__((alias("__imp__sub_8263E4EC"))) PPC_WEAK_FUNC(sub_8263E4EC);
PPC_FUNC_IMPL(__imp__sub_8263E4EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263E4F0"))) PPC_WEAK_FUNC(sub_8263E4F0);
PPC_FUNC_IMPL(__imp__sub_8263E4F0) {
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
	ctx.lr = 0x8263E4F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r27,1
	r27.s64 = 1;
	// lwz r11,1336(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1336);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e518
	if (!cr6.eq) goto loc_8263E518;
	// stb r27,1177(r31)
	PPC_STORE_U8(r31.u32 + 1177, r27.u8);
loc_8263E518:
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// addi r29,r31,456
	r29.s64 = r31.s64 + 456;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// lbz r11,1171(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1171);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// lwz r11,588(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x8263e5a4
	if (!cr6.eq) goto loc_8263E5A4;
	// lwz r11,1340(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1340);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// lwz r11,1344(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1344);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e854
	if (!cr6.eq) goto loc_8263E854;
	// li r29,0
	r29.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r29.u32);
	// stw r29,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E5A4:
	// lwz r11,1296(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1296);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e69c
	if (!cr6.eq) goto loc_8263E69C;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// stb r29,1172(r31)
	PPC_STORE_U8(r31.u32 + 1172, r29.u8);
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// stw r29,10092(r11)
	PPC_STORE_U32(r11.u32 + 10092, r29.u32);
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// stb r29,10850(r11)
	PPC_STORE_U8(r11.u32 + 10850, r29.u8);
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// stb r27,10851(r11)
	PPC_STORE_U8(r11.u32 + 10851, r27.u8);
	// lwz r3,2832(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// bl 0x821fef90
	ctx.lr = 0x8263E5DC;
	sub_821FEF90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263e604
	if (!cr6.eq) goto loc_8263E604;
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8263E600;
	sub_8268EE10(ctx, base);
	// b 0x8263e668
	goto loc_8263E668;
loc_8263E604:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,2832(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// addi r28,r11,1448
	r28.s64 = r11.s64 + 1448;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82200818
	ctx.lr = 0x8263E618;
	sub_82200818(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263e640
	if (!cr6.eq) goto loc_8263E640;
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,28
	ctx.r4.s64 = 28;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8268ee10
	ctx.lr = 0x8263E63C;
	sub_8268EE10(ctx, base);
	// b 0x8263e668
	goto loc_8263E668;
loc_8263E640:
	// stw r29,860(r31)
	PPC_STORE_U32(r31.u32 + 860, r29.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r29,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,2832(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263E664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r27,1178(r31)
	PPC_STORE_U8(r31.u32 + 1178, r27.u8);
loc_8263E668:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,21436
	ctx.r3.s64 = r11.s64 + 21436;
	// bl 0x821fa230
	ctx.lr = 0x8263E674;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268dcb0
	ctx.lr = 0x8263E67C;
	sub_8268DCB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263E690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E69C:
	// lwz r11,1256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1256);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e6fc
	if (!cr6.eq) goto loc_8263E6FC;
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// li r10,14
	ctx.r10.s64 = 14;
	// li r29,0
	r29.s64 = 0;
	// lwz r4,1180(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1180);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,856(r31)
	PPC_STORE_U32(r31.u32 + 856, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,868(r31)
	PPC_STORE_U32(r31.u32 + 868, ctx.r7.u32);
	// stw r29,1164(r31)
	PPC_STORE_U32(r31.u32 + 1164, r29.u32);
	// stw r10,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r10.u32);
	// bl 0x8263dfc0
	ctx.lr = 0x8263E6E0;
	sub_8263DFC0(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// mr r11,r27
	r11.u64 = r27.u64;
	// stb r29,1172(r31)
	PPC_STORE_U8(r31.u32 + 1172, r29.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,25116(r6)
	PPC_STORE_U8(ctx.r6.u32 + 25116, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E6FC:
	// lwz r11,1320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1320);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e76c
	if (!cr6.eq) goto loc_8263E76C;
	// lbz r11,1172(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e740
	if (cr6.eq) goto loc_8263E740;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263E734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E740:
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1160);
	// bl 0x8263dcf8
	ctx.lr = 0x8263E758;
	sub_8263DCF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E76C:
	// lwz r11,1304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e79c
	if (!cr6.eq) goto loc_8263E79C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x8268ee10
	ctx.lr = 0x8263E790;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E79C:
	// lwz r11,1308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1308);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e7d8
	if (!cr6.eq) goto loc_8263E7D8;
	// stb r27,1176(r31)
	PPC_STORE_U8(r31.u32 + 1176, r27.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263E7CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E7D8:
	// lwz r11,1312(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8263e84c
	if (cr6.eq) goto loc_8263E84C;
	// lwz r11,1324(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1324);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8263e854
	if (cr6.eq) goto loc_8263E854;
	// lwz r11,1328(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1328);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e840
	if (!cr6.eq) goto loc_8263E840;
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// beq cr6,0x8263e82c
	if (cr6.eq) goto loc_8263E82C;
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x8268ee10
	ctx.lr = 0x8263E820;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E82C:
	// li r4,37
	ctx.r4.s64 = 37;
	// bl 0x8268ee10
	ctx.lr = 0x8263E834;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8263E840:
	// lwz r11,1332(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1332);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8263e854
	if (!cr6.eq) goto loc_8263E854;
loc_8263E84C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1176(r31)
	PPC_STORE_U8(r31.u32 + 1176, r11.u8);
loc_8263E854:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8263E860"))) PPC_WEAK_FUNC(sub_8263E860);
PPC_FUNC_IMPL(__imp__sub_8263E860) {
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
	ctx.lr = 0x8263E868;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263e8e4
	if (cr6.eq) goto loc_8263E8E4;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r11.u32);
	// beq cr6,0x8263e8ac
	if (cr6.eq) goto loc_8263E8AC;
loc_8263E890:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263e1e8
	ctx.lr = 0x8263E89C;
	sub_8263E1E8(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// blt cr6,0x8263e890
	if (cr6.lt) goto loc_8263E890;
loc_8263E8AC:
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// bge cr6,0x8263e974
	if (!cr6.lt) goto loc_8263E974;
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// subfic r30,r30,16
	xer.ca = r30.u32 <= 16;
	r30.s64 = 16 - r30.s64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r11,604
	r29.s64 = r11.s64 + 604;
loc_8263E8C4:
	// lwz r4,1128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8218f8d0
	ctx.lr = 0x8263E8D0;
	sub_8218F8D0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x8263e8c4
	if (!cr0.eq) goto loc_8263E8C4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263E8E4:
	// lwz r10,428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// addi r11,r31,856
	r11.s64 = r31.s64 + 856;
	// addi r11,r31,860
	r11.s64 = r31.s64 + 860;
	// addi r11,r31,868
	r11.s64 = r31.s64 + 868;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,14
	ctx.r8.s64 = 14;
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// stb r7,856(r31)
	PPC_STORE_U8(r31.u32 + 856, ctx.r7.u8);
	// lbz r6,1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// stb r6,857(r31)
	PPC_STORE_U8(r31.u32 + 857, ctx.r6.u8);
	// lbz r5,2(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// stb r5,858(r31)
	PPC_STORE_U8(r31.u32 + 858, ctx.r5.u8);
	// lbz r4,3(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// stb r4,859(r31)
	PPC_STORE_U8(r31.u32 + 859, ctx.r4.u8);
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// stb r10,860(r31)
	PPC_STORE_U8(r31.u32 + 860, ctx.r10.u8);
	// lbz r7,5(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// stb r7,861(r31)
	PPC_STORE_U8(r31.u32 + 861, ctx.r7.u8);
	// lbz r6,6(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// stb r6,862(r31)
	PPC_STORE_U8(r31.u32 + 862, ctx.r6.u8);
	// lbz r5,7(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// stb r5,863(r31)
	PPC_STORE_U8(r31.u32 + 863, ctx.r5.u8);
	// lwz r11,428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// stb r3,868(r31)
	PPC_STORE_U8(r31.u32 + 868, ctx.r3.u8);
	// lbz r10,9(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// stb r10,869(r31)
	PPC_STORE_U8(r31.u32 + 869, ctx.r10.u8);
	// lbz r7,10(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// stb r7,870(r31)
	PPC_STORE_U8(r31.u32 + 870, ctx.r7.u8);
	// lbz r6,11(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// stb r6,871(r31)
	PPC_STORE_U8(r31.u32 + 871, ctx.r6.u8);
	// stw r9,1164(r31)
	PPC_STORE_U32(r31.u32 + 1164, ctx.r9.u32);
	// stw r8,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r8.u32);
loc_8263E974:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263E97C"))) PPC_WEAK_FUNC(sub_8263E97C);
PPC_FUNC_IMPL(__imp__sub_8263E97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263E980"))) PPC_WEAK_FUNC(sub_8263E980);
PPC_FUNC_IMPL(__imp__sub_8263E980) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,1496
	ctx.r9.s64 = r11.s64 + 1496;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8263e9b4
	if (cr6.eq) goto loc_8263E9B4;
	// bl 0x82130588
	ctx.lr = 0x8263E9B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8263E9B4:
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

__attribute__((alias("__imp__sub_8263E9C8"))) PPC_WEAK_FUNC(sub_8263E9C8);
PPC_FUNC_IMPL(__imp__sub_8263E9C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8263E9D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635af8
	ctx.lr = 0x8263E9DC;
	sub_82635AF8(ctx, base);
	// addic. r11,r31,-456
	xer.ca = r31.u32 > 455;
	r11.s64 = r31.s64 + -456;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r30,0
	r30.s64 = 0;
	// addi r4,r31,-420
	ctx.r4.s64 = r31.s64 + -420;
	// bne 0x8263e9f0
	if (!cr0.eq) goto loc_8263E9F0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_8263E9F0:
	// lis r29,-32125
	r29.s64 = -2105344000;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r6,r11,1888
	ctx.r6.s64 = r11.s64 + 1888;
	// addi r5,r10,1448
	ctx.r5.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2832);
	// bl 0x821fed20
	ctx.lr = 0x8263EA0C;
	sub_821FED20(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stb r11,25135(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25135, r11.u8);
	// stb r10,25116(r8)
	PPC_STORE_U8(ctx.r8.u32 + 25116, ctx.r10.u8);
	// lwz r3,-3624(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -3624);
	// bl 0x8226ce68
	ctx.lr = 0x8263EA30;
	sub_8226CE68(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r4,r4,1872
	ctx.r4.s64 = ctx.r4.s64 + 1872;
	// stw r3,25044(r6)
	PPC_STORE_U32(ctx.r6.u32 + 25044, ctx.r3.u32);
	// stb r30,768(r31)
	PPC_STORE_U8(r31.u32 + 768, r30.u8);
	// stw r30,756(r31)
	PPC_STORE_U32(r31.u32 + 756, r30.u32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// stb r30,769(r31)
	PPC_STORE_U8(r31.u32 + 769, r30.u8);
	// stb r30,720(r31)
	PPC_STORE_U8(r31.u32 + 720, r30.u8);
	// stw r30,764(r31)
	PPC_STORE_U32(r31.u32 + 764, r30.u32);
	// stb r30,771(r31)
	PPC_STORE_U8(r31.u32 + 771, r30.u8);
	// lwz r3,-10236(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8263EA6C;
	sub_821F9FB8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263EA88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r3,2832(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 2832);
	// addi r4,r8,-14960
	ctx.r4.s64 = ctx.r8.s64 + -14960;
	// bl 0x821feca8
	ctx.lr = 0x8263EA98;
	sub_821FECA8(ctx, base);
	// lwz r7,392(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// stw r7,696(r31)
	PPC_STORE_U32(r31.u32 + 696, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263EAA8"))) PPC_WEAK_FUNC(sub_8263EAA8);
PPC_FUNC_IMPL(__imp__sub_8263EAA8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25133(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25133);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263ead0
	if (cr6.eq) goto loc_8263EAD0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,25133(r11)
	PPC_STORE_U8(r11.u32 + 25133, ctx.r10.u8);
	// bl 0x8263d1e0
	ctx.lr = 0x8263EAD0;
	sub_8263D1E0(ctx, base);
loc_8263EAD0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25132(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25132);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263eaec
	if (cr6.eq) goto loc_8263EAEC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,25132(r11)
	PPC_STORE_U8(r11.u32 + 25132, ctx.r10.u8);
	// bl 0x8263d120
	ctx.lr = 0x8263EAEC;
	sub_8263D120(ctx, base);
loc_8263EAEC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263EAFC"))) PPC_WEAK_FUNC(sub_8263EAFC);
PPC_FUNC_IMPL(__imp__sub_8263EAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263EB00"))) PPC_WEAK_FUNC(sub_8263EB00);
PPC_FUNC_IMPL(__imp__sub_8263EB00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,1232(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1232);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8263eb3c
	if (!cr6.gt) goto loc_8263EB3C;
	// lwz r11,1228(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1228);
loc_8263EB14:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x8263eb34
	if (cr6.eq) goto loc_8263EB34;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8263eb14
	if (cr6.lt) goto loc_8263EB14;
	// b 0x8263eb3c
	goto loc_8263EB3C;
loc_8263EB34:
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_8263EB3C:
	// lhz r11,1232(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1232);
	// lwz r9,1228(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1228);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,1232(r3)
	PPC_STORE_U16(ctx.r3.u32 + 1232, ctx.r8.u16);
	// stwx r4,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263EB58"))) PPC_WEAK_FUNC(sub_8263EB58);
PPC_FUNC_IMPL(__imp__sub_8263EB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8263EB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,596(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 596);
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8263efb8
	if (cr6.gt) goto loc_8263EFB8;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-5236
	r12.s64 = r12.s64 + -5236;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263EBC0;
	case 1:
		goto loc_8263EC10;
	case 2:
		goto loc_8263ECB4;
	case 3:
		goto loc_8263ECC4;
	case 4:
		goto loc_8263EDE4;
	case 5:
		goto loc_8263EE68;
	case 6:
		goto loc_8263EF40;
	case 7:
		goto loc_8263ECD0;
	case 8:
		goto loc_8263ED70;
	case 9:
		goto loc_8263ED98;
	case 10:
		goto loc_8263EF4C;
	case 11:
		goto loc_8263ECB4;
	case 12:
		goto loc_8263EFA0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-5184(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -5184);
	// lwz r19,-5104(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -5104);
	// lwz r19,-4940(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4940);
	// lwz r19,-4924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4924);
	// lwz r19,-4636(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4636);
	// lwz r19,-4504(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4504);
	// lwz r19,-4288(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4288);
	// lwz r19,-4912(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4912);
	// lwz r19,-4752(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4752);
	// lwz r19,-4712(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4712);
	// lwz r19,-4276(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4276);
	// lwz r19,-4940(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4940);
	// lwz r19,-4192(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4192);
loc_8263EBC0:
	// lhz r11,1232(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263ec00
	if (cr6.eq) goto loc_8263EC00;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// lwz r9,1228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1228);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r11,r31,1228
	r11.s64 = r31.s64 + 1228;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,1232(r31)
	PPC_STORE_U16(r31.u32 + 1232, ctx.r7.u16);
	// rlwinm r6,r7,2,14,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x8263d878
	ctx.lr = 0x8263EBF8;
	sub_8263D878(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EC00:
	// li r11,0
	r11.s64 = 0;
	// stw r11,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EC10:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8263efb8
	if (cr6.eq) goto loc_8263EFB8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// bne cr6,0x8263ec98
	if (!cr6.eq) goto loc_8263EC98;
	// addi r30,r11,24884
	r30.s64 = r11.s64 + 24884;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268ee10
	ctx.lr = 0x8263EC40;
	sub_8268EE10(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,2028
	ctx.r4.s64 = ctx.r9.s64 + 2028;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263EC70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,1232(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 1232);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8263efb8
	if (!cr6.eq) goto loc_8263EFB8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x8268ee10
	ctx.lr = 0x8263EC90;
	sub_8268EE10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EC98:
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8268ee10
	ctx.lr = 0x8263ECA4;
	sub_8268EE10(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263ECB4:
	// li r11,0
	r11.s64 = 0;
loc_8263ECB8:
	// stw r11,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263ECC4:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,2004
	ctx.r3.s64 = r11.s64 + 2004;
	// b 0x8263efa8
	goto loc_8263EFA8;
loc_8263ECD0:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8263efb8
	if (cr6.eq) goto loc_8263EFB8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8263ed14
	if (!cr6.eq) goto loc_8263ED14;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,26
	ctx.r4.s64 = 26;
	// bl 0x8268ee10
	ctx.lr = 0x8263ECFC;
	sub_8268EE10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c2d0
	ctx.lr = 0x8263ED04;
	sub_8263C2D0(ctx, base);
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263ED14:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8263ED1C;
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
	ctx.lr = 0x8263ED30;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8263ED38;
	sub_824E70F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r4,15
	ctx.r4.s64 = 15;
	// bne cr6,0x8263ed5c
	if (!cr6.eq) goto loc_8263ED5C;
	// li r4,39
	ctx.r4.s64 = 39;
loc_8263ED5C:
	// bl 0x8268ee10
	ctx.lr = 0x8263ED60;
	sub_8268EE10(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r11,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263ED70:
	// lbz r11,1224(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1224);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8263ecb8
	if (cr6.eq) goto loc_8263ECB8;
	// stw r11,1212(r31)
	PPC_STORE_U32(r31.u32 + 1212, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c480
	ctx.lr = 0x8263ED90;
	sub_8263C480(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263ED98:
	// li r30,0
	r30.s64 = 0;
	// lwz r4,1204(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1204);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stb r30,1225(r31)
	PPC_STORE_U8(r31.u32 + 1225, r30.u8);
	// stb r30,1186(r31)
	PPC_STORE_U8(r31.u32 + 1186, r30.u8);
	// addi r3,r11,1976
	ctx.r3.s64 = r11.s64 + 1976;
	// stb r30,1224(r31)
	PPC_STORE_U8(r31.u32 + 1224, r30.u8);
	// stb r30,1227(r31)
	PPC_STORE_U8(r31.u32 + 1227, r30.u8);
	// bl 0x82130000
	ctx.lr = 0x8263EDBC;
	sub_82130000(ctx, base);
	// lhz r10,1234(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1234);
	// addi r11,r31,1228
	r11.s64 = r31.s64 + 1228;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263edd4
	if (!cr6.eq) goto loc_8263EDD4;
	// sth r30,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r30.u16);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_8263EDD4:
	// sth r30,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r30.u16);
	// stw r30,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EDE4:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8263efb8
	if (cr6.eq) goto loc_8263EFB8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8263ee0c
	if (!cr6.eq) goto loc_8263EE0C;
	// lis r11,3
	r11.s64 = 196608;
	// lwz r10,1216(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// ori r9,r11,8191
	ctx.r9.u64 = r11.u64 | 8191;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8263ee18
	if (cr6.lt) goto loc_8263EE18;
loc_8263EE0C:
	// lwz r11,1216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263ee40
	if (!cr6.eq) goto loc_8263EE40;
loc_8263EE18:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8268ee10
	ctx.lr = 0x8263EE30;
	sub_8268EE10(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EE40:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// bl 0x8268ee10
	ctx.lr = 0x8263EE58;
	sub_8268EE10(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EE68:
	// lbz r11,1224(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1224);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263ecb4
	if (cr6.eq) goto loc_8263ECB4;
	// lwz r4,1212(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1212);
	// cmplwi cr6,r4,16
	cr6.compare<uint32_t>(ctx.r4.u32, 16, xer);
	// bge cr6,0x8263ecb4
	if (!cr6.lt) goto loc_8263ECB4;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263eea0
	if (cr6.eq) goto loc_8263EEA0;
	// lbz r11,1186(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1186);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263eea0
	if (!cr6.eq) goto loc_8263EEA0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263e1e8
	ctx.lr = 0x8263EEA0;
	sub_8263E1E8(ctx, base);
loc_8263EEA0:
	// lwz r10,1212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1212);
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r4,1212(r31)
	PPC_STORE_U32(r31.u32 + 1212, ctx.r4.u32);
	// beq cr6,0x8263eed4
	if (cr6.eq) goto loc_8263EED4;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8263eed4
	if (cr6.eq) goto loc_8263EED4;
	// bge cr6,0x8263efb8
	if (!cr6.lt) goto loc_8263EFB8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263c480
	ctx.lr = 0x8263EECC;
	sub_8263C480(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EED4:
	// stw r11,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r11.u32);
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bge cr6,0x8263ef08
	if (!cr6.lt) goto loc_8263EF08;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subfic r30,r11,16
	xer.ca = r11.u32 <= 16;
	r30.s64 = 16 - r11.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// addi r29,r10,604
	r29.s64 = ctx.r10.s64 + 604;
loc_8263EEF0:
	// lwz r4,1128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8218f8d0
	ctx.lr = 0x8263EEFC;
	sub_8218F8D0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x8263eef0
	if (!cr0.eq) goto loc_8263EEF0;
loc_8263EF08:
	// li r11,1
	r11.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// stb r11,1186(r31)
	PPC_STORE_U8(r31.u32 + 1186, r11.u8);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// stw r30,596(r31)
	PPC_STORE_U32(r31.u32 + 596, r30.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r30.u32);
	// addi r3,r10,24884
	ctx.r3.s64 = ctx.r10.s64 + 24884;
	// stb r11,1227(r31)
	PPC_STORE_U8(r31.u32 + 1227, r11.u8);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// bl 0x8268ee10
	ctx.lr = 0x8263EF38;
	sub_8268EE10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EF40:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,1948
	ctx.r3.s64 = r11.s64 + 1948;
	// b 0x8263efa8
	goto loc_8263EFA8;
loc_8263EF4C:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8263efb8
	if (cr6.eq) goto loc_8263EFB8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// bne cr6,0x8263ef88
	if (!cr6.eq) goto loc_8263EF88;
	// li r4,29
	ctx.r4.s64 = 29;
	// bl 0x8268ee10
	ctx.lr = 0x8263EF78;
	sub_8268EE10(ctx, base);
	// li r10,11
	ctx.r10.s64 = 11;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EF88:
	// li r4,30
	ctx.r4.s64 = 30;
	// bl 0x8268ee10
	ctx.lr = 0x8263EF90;
	sub_8268EE10(ctx, base);
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263EFA0:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,1920
	ctx.r3.s64 = r11.s64 + 1920;
loc_8263EFA8:
	// lwz r4,1204(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1204);
	// bl 0x82130000
	ctx.lr = 0x8263EFB0;
	sub_82130000(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,596(r31)
	PPC_STORE_U32(r31.u32 + 596, ctx.r10.u32);
loc_8263EFB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263EFC0"))) PPC_WEAK_FUNC(sub_8263EFC0);
PPC_FUNC_IMPL(__imp__sub_8263EFC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8263EFC8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x826355a8
	ctx.lr = 0x8263EFDC;
	sub_826355A8(ctx, base);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cmplwi cr6,r11,12
	cr6.compare<uint32_t>(r11.u32, 12, xer);
	// bgt cr6,0x8263f25c
	if (cr6.gt) goto loc_8263F25C;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-4092
	r12.s64 = r12.s64 + -4092;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263F038;
	case 1:
		goto loc_8263F25C;
	case 2:
		goto loc_8263F25C;
	case 3:
		goto loc_8263F25C;
	case 4:
		goto loc_8263F06C;
	case 5:
		goto loc_8263F0C4;
	case 6:
		goto loc_8263F244;
	case 7:
		goto loc_8263F25C;
	case 8:
		goto loc_8263F25C;
	case 9:
		goto loc_8263F25C;
	case 10:
		goto loc_8263F25C;
	case 11:
		goto loc_8263F114;
	case 12:
		goto loc_8263F158;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-4040(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4040);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3988(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3988);
	// lwz r19,-3900(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3900);
	// lwz r19,-3516(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3516);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3492(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3492);
	// lwz r19,-3820(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3820);
	// lwz r19,-3752(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3752);
loc_8263F038:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263F058;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263F06C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21380(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263f0a4
	if (!cr6.eq) goto loc_8263F0A4;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r11,493(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 493);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8263f0a4
	if (!cr6.eq) goto loc_8263F0A4;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263f25c
	if (cr6.eq) goto loc_8263F25C;
loc_8263F0A4:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r9,7
	ctx.r9.s64 = 7;
	// stb r11,25133(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25133, r11.u8);
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263F0C4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21380(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8263f25c
	if (!cr6.eq) goto loc_8263F25C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lbz r11,493(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 493);
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8263f25c
	if (!cr6.eq) goto loc_8263F25C;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263f25c
	if (!cr6.eq) goto loc_8263F25C;
	// li r10,13
	ctx.r10.s64 = 13;
	// stw r11,736(r31)
	PPC_STORE_U32(r31.u32 + 736, r11.u32);
	// stw r10,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263F114:
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// stw r8,736(r31)
	PPC_STORE_U32(r31.u32 + 736, ctx.r8.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r7,732(r31)
	PPC_STORE_U32(r31.u32 + 732, ctx.r7.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r10,-18004(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// stb r11,25132(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25132, r11.u8);
	// stw r6,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r6.u32);
	// stw r5,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263F158:
	// lbz r11,769(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 769);
	// addi r30,r31,-456
	r30.s64 = r31.s64 + -456;
	// lwz r4,708(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263f184
	if (cr6.eq) goto loc_8263F184;
	// lwz r11,1208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1208);
	// subfc r10,r11,r4
	xer.ca = ctx.r4.u32 >= r11.u32;
	ctx.r10.s64 = ctx.r4.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263f19c
	goto loc_8263F19C;
loc_8263F184:
	// lwz r11,860(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 860);
	// slw r10,r29,r4
	ctx.r10.u64 = ctx.r4.u8 & 0x20 ? 0 : (r29.u32 << (ctx.r4.u8 & 0x3F));
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
loc_8263F19C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263f1f8
	if (cr6.eq) goto loc_8263F1F8;
	// lbz r11,729(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 729);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263f1d0
	if (!cr6.eq) goto loc_8263F1D0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8263e1e8
	ctx.lr = 0x8263F1BC;
	sub_8263E1E8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r4,708(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// addi r3,r11,2036
	ctx.r3.s64 = r11.s64 + 2036;
	// bl 0x82130000
	ctx.lr = 0x8263F1CC;
	sub_82130000(ctx, base);
	// b 0x8263f20c
	goto loc_8263F20C;
loc_8263F1D0:
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r4,152(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// lwz r3,148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// bl 0x8218f8d0
	ctx.lr = 0x8263F1E4;
	sub_8218F8D0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r4,708(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// addi r3,r11,2036
	ctx.r3.s64 = r11.s64 + 2036;
	// bl 0x82130000
	ctx.lr = 0x8263F1F4;
	sub_82130000(ctx, base);
	// b 0x8263f20c
	goto loc_8263F20C;
loc_8263F1F8:
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r3,148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// bl 0x8218f8d0
	ctx.lr = 0x8263F20C;
	sub_8218F8D0(ctx, base);
loc_8263F20C:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x8263f25c
	if (!cr6.eq) goto loc_8263F25C;
	// li r11,0
	r11.s64 = 0;
	// stb r29,729(r31)
	PPC_STORE_U8(r31.u32 + 729, r29.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,724(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 724);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// bl 0x8263dfc0
	ctx.lr = 0x8263F238;
	sub_8263DFC0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8263F244:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r3,25044(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 25044);
	// bl 0x824f3b50
	ctx.lr = 0x8263F250;
	sub_824F3B50(ctx, base);
	// addi r3,r31,-456
	ctx.r3.s64 = r31.s64 + -456;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8263eb58
	ctx.lr = 0x8263F25C;
	sub_8263EB58(ctx, base);
loc_8263F25C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263F268"))) PPC_WEAK_FUNC(sub_8263F268);
PPC_FUNC_IMPL(__imp__sub_8263F268) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x82635be0
	ctx.lr = 0x8263F288;
	sub_82635BE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263f318
	if (!cr6.eq) goto loc_8263F318;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 262144;
	// addi r9,r9,976
	ctx.r9.s64 = ctx.r9.s64 + 976;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bne cr6,0x8263f318
	if (!cr6.eq) goto loc_8263F318;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8263f318
	if (cr6.gt) goto loc_8263F318;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-3368
	r12.s64 = r12.s64 + -3368;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263F2F8;
	case 1:
		goto loc_8263F300;
	case 2:
		goto loc_8263F2E8;
	case 3:
		goto loc_8263F2F0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-3336(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3336);
	// lwz r19,-3328(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3328);
	// lwz r19,-3352(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3352);
	// lwz r19,-3344(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3344);
loc_8263F2E8:
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x8263f304
	goto loc_8263F304;
loc_8263F2F0:
	// li r4,3
	ctx.r4.s64 = 3;
	// b 0x8263f304
	goto loc_8263F304;
loc_8263F2F8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8263f304
	goto loc_8263F304;
loc_8263F300:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8263F304:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268ee10
	ctx.lr = 0x8263F314;
	sub_8268EE10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8263F318:
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

__attribute__((alias("__imp__sub_8263F330"))) PPC_WEAK_FUNC(sub_8263F330);
PPC_FUNC_IMPL(__imp__sub_8263F330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8263F338;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// addi r4,r10,21436
	ctx.r4.s64 = ctx.r10.s64 + 21436;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x8263F360;
	sub_823DB670(ctx, base);
	// addi r29,r31,36
	r29.s64 = r31.s64 + 36;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822029d8
	ctx.lr = 0x8263F36C;
	sub_822029D8(ctx, base);
	// addi r28,r31,456
	r28.s64 = r31.s64 + 456;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8263a5f8
	ctx.lr = 0x8263F378;
	sub_8263A5F8(ctx, base);
	// addi r3,r31,536
	ctx.r3.s64 = r31.s64 + 536;
	// bl 0x824e6928
	ctx.lr = 0x8263F380;
	sub_824E6928(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r11,r6,2292
	r11.s64 = ctx.r6.s64 + 2292;
	// addi r10,r5,2268
	ctx.r10.s64 = ctx.r5.s64 + 2268;
	// addi r4,r8,2256
	ctx.r4.s64 = ctx.r8.s64 + 2256;
	// stw r11,456(r31)
	PPC_STORE_U32(r31.u32 + 456, r11.u32);
	// addi r3,r7,2216
	ctx.r3.s64 = ctx.r7.s64 + 2216;
	// stw r10,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r10.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// addi r11,r31,600
	r11.s64 = r31.s64 + 600;
	// li r10,15
	ctx.r10.s64 = 15;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r9,1496
	ctx.r9.s64 = ctx.r9.s64 + 1496;
loc_8263F3C4:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bge 0x8263f3c4
	if (!cr0.lt) goto loc_8263F3C4;
	// stw r30,1200(r31)
	PPC_STORE_U32(r31.u32 + 1200, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,1204(r31)
	PPC_STORE_U32(r31.u32 + 1204, r30.u32);
	// addi r11,r31,1228
	r11.s64 = r31.s64 + 1228;
	// stw r30,1228(r31)
	PPC_STORE_U32(r31.u32 + 1228, r30.u32);
	// sth r30,1232(r31)
	PPC_STORE_U16(r31.u32 + 1232, r30.u16);
	// sth r30,1234(r31)
	PPC_STORE_U16(r31.u32 + 1234, r30.u16);
	// bl 0x82130000
	ctx.lr = 0x8263F3F8;
	sub_82130000(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fe7b0
	ctx.lr = 0x8263F400;
	sub_821FE7B0(ctx, base);
	// lis r11,50
	r11.s64 = 3276800;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r30,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r30.u32);
	// ori r8,r11,204
	ctx.r8.u64 = r11.u64 | 204;
	// stw r30,860(r31)
	PPC_STORE_U32(r31.u32 + 860, r30.u32);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// stw r30,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r30.u32);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// stw r8,432(r31)
	PPC_STORE_U32(r31.u32 + 432, ctx.r8.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r30,1132(r31)
	PPC_STORE_U32(r31.u32 + 1132, r30.u32);
	// stb r30,1168(r31)
	PPC_STORE_U8(r31.u32 + 1168, r30.u8);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// stb r30,1169(r31)
	PPC_STORE_U8(r31.u32 + 1169, r30.u8);
	// li r3,128
	ctx.r3.s64 = 128;
	// stb r30,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r30.u8);
	// stb r30,1171(r31)
	PPC_STORE_U8(r31.u32 + 1171, r30.u8);
	// stb r30,1172(r31)
	PPC_STORE_U8(r31.u32 + 1172, r30.u8);
	// stb r30,1184(r31)
	PPC_STORE_U8(r31.u32 + 1184, r30.u8);
	// stb r30,1174(r31)
	PPC_STORE_U8(r31.u32 + 1174, r30.u8);
	// stw r30,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r30.u32);
	// stb r30,1186(r31)
	PPC_STORE_U8(r31.u32 + 1186, r30.u8);
	// stb r11,25116(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25116, r11.u8);
	// stb r30,1185(r31)
	PPC_STORE_U8(r31.u32 + 1185, r30.u8);
	// stb r30,1225(r31)
	PPC_STORE_U8(r31.u32 + 1225, r30.u8);
	// stb r11,25132(r7)
	PPC_STORE_U8(ctx.r7.u32 + 25132, r11.u8);
	// stb r10,25133(r6)
	PPC_STORE_U8(ctx.r6.u32 + 25133, ctx.r10.u8);
	// stb r30,1177(r31)
	PPC_STORE_U8(r31.u32 + 1177, r30.u8);
	// bl 0x82130528
	ctx.lr = 0x8263F474;
	sub_82130528(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r3,1228(r31)
	PPC_STORE_U32(r31.u32 + 1228, ctx.r3.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// sth r5,1234(r31)
	PPC_STORE_U16(r31.u32 + 1234, ctx.r5.u16);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r30,1208(r31)
	PPC_STORE_U32(r31.u32 + 1208, r30.u32);
	// addi r5,r4,-15244
	ctx.r5.s64 = ctx.r4.s64 + -15244;
	// stw r30,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r30.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stb r30,1248(r31)
	PPC_STORE_U8(r31.u32 + 1248, r30.u8);
	// stw r30,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r30.u32);
	// stw r30,1164(r31)
	PPC_STORE_U32(r31.u32 + 1164, r30.u32);
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8263F4B4;
	sub_8268B960(ctx, base);
	// stw r3,1252(r31)
	PPC_STORE_U32(r31.u32 + 1252, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-19968
	ctx.r5.s64 = r11.s64 + -19968;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F4D0;
	sub_8268B960(ctx, base);
	// stw r3,1256(r31)
	PPC_STORE_U32(r31.u32 + 1256, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r10,-15256
	ctx.r5.s64 = ctx.r10.s64 + -15256;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F4EC;
	sub_8268B960(ctx, base);
	// stw r3,1260(r31)
	PPC_STORE_U32(r31.u32 + 1260, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-15268
	ctx.r5.s64 = ctx.r9.s64 + -15268;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F508;
	sub_8268B960(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r3,1264(r31)
	PPC_STORE_U32(r31.u32 + 1264, ctx.r3.u32);
	// li r6,10
	ctx.r6.s64 = 10;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// addi r5,r8,-15284
	ctx.r5.s64 = ctx.r8.s64 + -15284;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F524;
	sub_8268B960(ctx, base);
	// stw r3,1268(r31)
	PPC_STORE_U32(r31.u32 + 1268, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r7,-15296
	ctx.r5.s64 = ctx.r7.s64 + -15296;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F540;
	sub_8268B960(ctx, base);
	// stw r3,1272(r31)
	PPC_STORE_U32(r31.u32 + 1272, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r5,-15312
	ctx.r5.s64 = ctx.r5.s64 + -15312;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F55C;
	sub_8268B960(ctx, base);
	// stw r3,1276(r31)
	PPC_STORE_U32(r31.u32 + 1276, ctx.r3.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,-15332
	ctx.r5.s64 = ctx.r4.s64 + -15332;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F578;
	sub_8268B960(ctx, base);
	// stw r3,1280(r31)
	PPC_STORE_U32(r31.u32 + 1280, ctx.r3.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-15348
	ctx.r5.s64 = r11.s64 + -15348;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F594;
	sub_8268B960(ctx, base);
	// stw r3,1284(r31)
	PPC_STORE_U32(r31.u32 + 1284, ctx.r3.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r10,-15368
	ctx.r5.s64 = ctx.r10.s64 + -15368;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F5B0;
	sub_8268B960(ctx, base);
	// stw r3,1288(r31)
	PPC_STORE_U32(r31.u32 + 1288, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-15592
	ctx.r5.s64 = ctx.r9.s64 + -15592;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F5CC;
	sub_8268B960(ctx, base);
	// stw r3,1292(r31)
	PPC_STORE_U32(r31.u32 + 1292, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r8,2188
	ctx.r5.s64 = ctx.r8.s64 + 2188;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F5E8;
	sub_8268B960(ctx, base);
	// stw r3,1296(r31)
	PPC_STORE_U32(r31.u32 + 1296, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r7,2172
	ctx.r5.s64 = ctx.r7.s64 + 2172;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F604;
	sub_8268B960(ctx, base);
	// stw r3,1300(r31)
	PPC_STORE_U32(r31.u32 + 1300, ctx.r3.u32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r5,2152
	ctx.r5.s64 = ctx.r5.s64 + 2152;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F620;
	sub_8268B960(ctx, base);
	// stw r3,1304(r31)
	PPC_STORE_U32(r31.u32 + 1304, ctx.r3.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,2128
	ctx.r5.s64 = ctx.r4.s64 + 2128;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F63C;
	sub_8268B960(ctx, base);
	// stw r3,1308(r31)
	PPC_STORE_U32(r31.u32 + 1308, ctx.r3.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,2096
	ctx.r5.s64 = r11.s64 + 2096;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F658;
	sub_8268B960(ctx, base);
	// stw r3,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r6,10
	ctx.r6.s64 = 10;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// addi r5,r10,2080
	ctx.r5.s64 = ctx.r10.s64 + 2080;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F674;
	sub_8268B960(ctx, base);
	// stw r3,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, ctx.r3.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r9,-15732
	ctx.r5.s64 = ctx.r9.s64 + -15732;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F690;
	sub_8268B960(ctx, base);
	// stw r3,1320(r31)
	PPC_STORE_U32(r31.u32 + 1320, ctx.r3.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r8,2064
	ctx.r5.s64 = ctx.r8.s64 + 2064;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F6AC;
	sub_8268B960(ctx, base);
	// stw r3,1324(r31)
	PPC_STORE_U32(r31.u32 + 1324, ctx.r3.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r7,-15416
	ctx.r5.s64 = ctx.r7.s64 + -15416;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F6C8;
	sub_8268B960(ctx, base);
	// stw r3,1328(r31)
	PPC_STORE_U32(r31.u32 + 1328, ctx.r3.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r5,-15852
	ctx.r5.s64 = ctx.r5.s64 + -15852;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F6E4;
	sub_8268B960(ctx, base);
	// stw r3,1332(r31)
	PPC_STORE_U32(r31.u32 + 1332, ctx.r3.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r4,-15576
	ctx.r5.s64 = ctx.r4.s64 + -15576;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268b960
	ctx.lr = 0x8263F700;
	sub_8268B960(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r3,1336(r31)
	PPC_STORE_U32(r31.u32 + 1336, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,25134(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25134, r11.u8);
	// stb r30,1175(r31)
	PPC_STORE_U8(r31.u32 + 1175, r30.u8);
	// stw r30,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, r30.u32);
	// stw r30,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, r30.u32);
	// bl 0x8263d2a8
	ctx.lr = 0x8263F724;
	sub_8263D2A8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8263F730"))) PPC_WEAK_FUNC(sub_8263F730);
PPC_FUNC_IMPL(__imp__sub_8263F730) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-36
	ctx.r3.s64 = ctx.r3.s64 + -36;
	// b 0x82640130
	sub_82640130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263F738"))) PPC_WEAK_FUNC(sub_8263F738);
PPC_FUNC_IMPL(__imp__sub_8263F738) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-536
	ctx.r3.s64 = ctx.r3.s64 + -536;
	// b 0x82640130
	sub_82640130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263F740"))) PPC_WEAK_FUNC(sub_8263F740);
PPC_FUNC_IMPL(__imp__sub_8263F740) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-456
	ctx.r3.s64 = ctx.r3.s64 + -456;
	// b 0x82640130
	sub_82640130(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263F748"))) PPC_WEAK_FUNC(sub_8263F748);
PPC_FUNC_IMPL(__imp__sub_8263F748) {
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
	ctx.lr = 0x8263F750;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r7,r11,2256
	ctx.r7.s64 = r11.s64 + 2256;
	// addi r6,r10,2216
	ctx.r6.s64 = ctx.r10.s64 + 2216;
	// addi r5,r9,2292
	ctx.r5.s64 = ctx.r9.s64 + 2292;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r4,r8,2268
	ctx.r4.s64 = ctx.r8.s64 + 2268;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
	// stw r5,456(r31)
	PPC_STORE_U32(r31.u32 + 456, ctx.r5.u32);
	// addi r28,r31,456
	r28.s64 = r31.s64 + 456;
	// stw r4,536(r31)
	PPC_STORE_U32(r31.u32 + 536, ctx.r4.u32);
	// addi r27,r31,36
	r27.s64 = r31.s64 + 36;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r26,r31,536
	r26.s64 = r31.s64 + 536;
	// bl 0x82130000
	ctx.lr = 0x8263F79C;
	sub_82130000(ctx, base);
	// lwz r3,1132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1132);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263f7b0
	if (cr6.eq) goto loc_8263F7B0;
	// stw r29,1132(r31)
	PPC_STORE_U32(r31.u32 + 1132, r29.u32);
loc_8263F7B0:
	// lwz r30,1128(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1128);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263f7f0
	if (cr6.eq) goto loc_8263F7F0;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8263F7C4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8263f7ec
	if (!cr6.eq) goto loc_8263F7EC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8263f7ec
	if (cr6.eq) goto loc_8263F7EC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263F7EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263F7EC:
	// stw r29,1128(r31)
	PPC_STORE_U32(r31.u32 + 1128, r29.u32);
loc_8263F7F0:
	// lwz r3,1152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1152);
	// bl 0x82130588
	ctx.lr = 0x8263F7F8;
	sub_82130588(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r5,1252(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1252);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F80C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1256);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F81C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1260(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1260);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F82C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1264(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1264);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F83C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1268(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1268);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F84C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1272(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1272);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F85C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1276(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1276);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F86C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1280(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1280);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F87C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1284(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1284);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F88C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1288(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1288);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F89C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1292(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1292);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8AC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1296(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1296);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8BC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1300(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1300);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8CC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1304(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1304);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8DC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1308(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1308);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8EC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1312);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F8FC;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1316(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1316);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F90C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1320(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1320);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F91C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1324(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1324);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F92C;
	sub_8268B6D0(ctx, base);
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,1328(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1328);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F93C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1332(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1332);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F94C;
	sub_8268B6D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// lwz r5,1336(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1336);
	// bl 0x8268b6d0
	ctx.lr = 0x8263F95C;
	sub_8268B6D0(ctx, base);
	// lhz r11,1234(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1234);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263f970
	if (cr6.eq) goto loc_8263F970;
	// lwz r3,1228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1228);
	// bl 0x82130588
	ctx.lr = 0x8263F970;
	sub_82130588(ctx, base);
loc_8263F970:
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r11,r31,856
	r11.s64 = r31.s64 + 856;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r9,r9,1496
	ctx.r9.s64 = ctx.r9.s64 + 1496;
loc_8263F980:
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8263f980
	if (!cr0.lt) goto loc_8263F980;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e6b58
	ctx.lr = 0x8263F998;
	sub_824E6B58(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826375a0
	ctx.lr = 0x8263F9A0;
	sub_826375A0(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82202950
	ctx.lr = 0x8263F9A8;
	sub_82202950(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8263F9BC"))) PPC_WEAK_FUNC(sub_8263F9BC);
PPC_FUNC_IMPL(__imp__sub_8263F9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8263F9C0"))) PPC_WEAK_FUNC(sub_8263F9C0);
PPC_FUNC_IMPL(__imp__sub_8263F9C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,1232(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 1232);
	// addi r7,r3,1228
	ctx.r7.s64 = ctx.r3.s64 + 1228;
	// lwz r9,1228(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1228);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8263f9f8
	if (cr6.eq) goto loc_8263F9F8;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8263F9E4:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8263f9e4
	if (!cr6.eq) goto loc_8263F9E4;
loc_8263F9F8:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r7)
	PPC_STORE_U16(ctx.r7.u32 + 4, ctx.r8.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263FA10"))) PPC_WEAK_FUNC(sub_8263FA10);
PPC_FUNC_IMPL(__imp__sub_8263FA10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8263FA18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-12876
	ctx.r3.s64 = r11.s64 + -12876;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r31,r10,-22036
	r31.s64 = ctx.r10.s64 + -22036;
	// addi r29,r9,-22108
	r29.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8263FA3C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8263FA50;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,21
	cr6.compare<uint32_t>(r11.u32, 21, xer);
	// bgt cr6,0x82640124
	if (cr6.gt) goto loc_82640124;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,-1404
	r12.s64 = r12.s64 + -1404;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8263FADC;
	case 1:
		goto loc_8263FC90;
	case 2:
		goto loc_82640058;
	case 3:
		goto loc_8263FCC4;
	case 4:
		goto loc_8263FCF0;
	case 5:
		goto loc_8263FD8C;
	case 6:
		goto loc_8263FDB4;
	case 7:
		goto loc_8263FDA0;
	case 8:
		goto loc_8263FDC8;
	case 9:
		goto loc_8263FDDC;
	case 10:
		goto loc_8263FE28;
	case 11:
		goto loc_8263FE44;
	case 12:
		goto loc_8263FE58;
	case 13:
		goto loc_8263FE70;
	case 14:
		goto loc_8263FE88;
	case 15:
		goto loc_8263FF8C;
	case 16:
		goto loc_8263FFD4;
	case 17:
		goto loc_8263FF68;
	case 18:
		goto loc_8263FFA0;
	case 19:
		goto loc_8263FFC0;
	case 20:
		goto loc_82640078;
	case 21:
		goto loc_826400D0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-1316(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -1316);
	// lwz r19,-880(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -880);
	// lwz r19,88(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 88);
	// lwz r19,-828(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -828);
	// lwz r19,-784(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -784);
	// lwz r19,-628(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -628);
	// lwz r19,-588(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -588);
	// lwz r19,-608(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -608);
	// lwz r19,-568(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -568);
	// lwz r19,-548(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -548);
	// lwz r19,-472(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -472);
	// lwz r19,-444(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -444);
	// lwz r19,-424(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -424);
	// lwz r19,-400(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -400);
	// lwz r19,-376(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -376);
	// lwz r19,-116(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -116);
	// lwz r19,-44(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -44);
	// lwz r19,-152(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -152);
	// lwz r19,-96(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -96);
	// lwz r19,-64(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + -64);
	// lwz r19,120(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// lwz r19,208(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 208);
loc_8263FADC:
	// lbz r11,1226(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1226);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640124
	if (!cr6.eq) goto loc_82640124;
	// lbz r11,1176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640124
	if (!cr6.eq) goto loc_82640124;
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// lbz r10,1225(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,1180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1180);
	// beq cr6,0x8263fbbc
	if (cr6.eq) goto loc_8263FBBC;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,1160(r31)
	PPC_STORE_U32(r31.u32 + 1160, r11.u32);
	// beq cr6,0x8263fb28
	if (cr6.eq) goto loc_8263FB28;
	// lwz r10,1208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r9,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,31
	r11.u64 = ctx.r8.u32 & 0x1;
	// b 0x8263fb44
	goto loc_8263FB44;
loc_8263FB28:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,860(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r8,r10,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r11,r5,1
	r11.u64 = ctx.r5.u64 ^ 1;
loc_8263FB44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263fb74
	if (cr6.eq) goto loc_8263FB74;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2152
	ctx.r4.s64 = ctx.r10.s64 + 2152;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8263FB68;
	sub_8268B770(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FB74:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263FB98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-15712
	ctx.r4.s64 = ctx.r6.s64 + -15712;
	// lwz r3,-10224(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8263FBB0;
	sub_8268B770(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FBBC:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263fbd8
	if (cr6.eq) goto loc_8263FBD8;
	// lwz r9,1208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r8,r9,r11
	xer.ca = r11.u32 >= ctx.r9.u32;
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	// b 0x8263fbf4
	goto loc_8263FBF4;
loc_8263FBD8:
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r8,860(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// slw r7,r9,r11
	ctx.r7.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// and r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ctx.r7.u64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r11,r4,1
	r11.u64 = ctx.r4.u64 ^ 1;
loc_8263FBF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263fc2c
	if (cr6.eq) goto loc_8263FC2C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x8268ee10
	ctx.lr = 0x8263FC20;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FC2C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// li r4,10
	ctx.r4.s64 = 10;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bgt cr6,0x8263fc5c
	if (cr6.gt) goto loc_8263FC5C;
	// li r4,57
	ctx.r4.s64 = 57;
loc_8263FC5C:
	// bl 0x8220f040
	ctx.lr = 0x8263FC60;
	sub_8220F040(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15924
	ctx.r3.s64 = r11.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x8263FC6C;
	sub_821E6800(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r10,24884
	ctx.r3.s64 = ctx.r10.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x8268ee10
	ctx.lr = 0x8263FC84;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FC90:
	// lwz r11,588(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8263FCA8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8263dfc0
	ctx.lr = 0x8263FCB8;
	sub_8263DFC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FCC4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263FCE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FCF0:
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r3,r31,456
	ctx.r3.s64 = r31.s64 + 456;
	// addi r30,r10,1412
	r30.s64 = ctx.r10.s64 + 1412;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263FD0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8263FD18;
	sub_825EE0E0(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lbz r7,21380(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 21380);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8263fd78
	if (!cr6.eq) goto loc_8263FD78;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,-18004(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r11,493(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 493);
	// rlwinm r8,r11,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8263fd78
	if (!cr6.eq) goto loc_8263FD78;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263fd78
	if (!cr6.eq) goto loc_8263FD78;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r8,5
	ctx.r8.s64 = 5;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,25132(r9)
	PPC_STORE_U8(ctx.r9.u32 + 25132, r11.u8);
	// stw r8,68(r10)
	PPC_STORE_U32(ctx.r10.u32 + 68, ctx.r8.u32);
	// stw r7,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FD78:
	// li r11,7
	r11.s64 = 7;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FD8C:
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FDA0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263ce88
	ctx.lr = 0x8263FDA8;
	sub_8263CE88(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FDB4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263cdc0
	ctx.lr = 0x8263FDBC;
	sub_8263CDC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FDC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263e428
	ctx.lr = 0x8263FDD0;
	sub_8263E428(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FDDC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,25116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 25116);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8263fe04
	if (cr6.eq) goto loc_8263FE04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1160);
	// bl 0x8263dcf8
	ctx.lr = 0x8263FDF8;
	sub_8263DCF8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE04:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2188
	ctx.r4.s64 = ctx.r10.s64 + 2188;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8263FE1C;
	sub_8268B770(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE28:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r11.u8);
	// bl 0x8263dc38
	ctx.lr = 0x8263FE38;
	sub_8263DC38(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE44:
	// li r11,1
	r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,1170(r31)
	PPC_STORE_U8(r31.u32 + 1170, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE58:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,25133(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25133, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE70:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r11,1
	r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,25132(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25132, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FE88:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8263FE90;
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
	ctx.lr = 0x8263FEA4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8263FEAC;
	sub_824E70F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82640124
	if (!cr6.gt) goto loc_82640124;
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640124
	if (!cr6.eq) goto loc_82640124;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,2884
	ctx.r3.s64 = r11.s64 + 2884;
	// bl 0x821e6800
	ctx.lr = 0x8263FEDC;
	sub_821E6800(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r10,24884
	ctx.r3.s64 = ctx.r10.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8268ee10
	ctx.lr = 0x8263FEF4;
	sub_8268EE10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263db38
	ctx.lr = 0x8263FEFC;
	sub_8263DB38(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8263FF04:
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263ff24
	if (cr6.eq) goto loc_8263FF24;
	// lwz r11,1208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1208);
	// subfc r10,r11,r4
	xer.ca = ctx.r4.u32 >= r11.u32;
	ctx.r10.s64 = ctx.r4.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// b 0x8263ff38
	goto loc_8263FF38;
loc_8263FF24:
	// lwz r11,860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 860);
	// and r10,r11,r7
	ctx.r10.u64 = r11.u64 & ctx.r7.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
loc_8263FF38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263ff4c
	if (cr6.eq) goto loc_8263FF4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263eb00
	ctx.lr = 0x8263FF4C;
	sub_8263EB00(ctx, base);
loc_8263FF4C:
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// rotlwi r7,r7,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// cmpwi cr6,r4,16
	cr6.compare<int32_t>(ctx.r4.s32, 16, xer);
	// blt cr6,0x8263ff04
	if (cr6.lt) goto loc_8263FF04;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FF68:
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1180(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1180);
	// bl 0x8263c530
	ctx.lr = 0x8263FF80;
	sub_8263C530(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FF8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8263FF90:
	// bl 0x8263dbe8
	ctx.lr = 0x8263FF94;
	sub_8263DBE8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FFA0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,1448
	ctx.r4.s64 = ctx.r10.s64 + 1448;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// bl 0x82200818
	ctx.lr = 0x8263FFB4;
	sub_82200818(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FFC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263f9c0
	ctx.lr = 0x8263FFC8;
	sub_8263F9C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FFD4:
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263fff8
	if (cr6.eq) goto loc_8263FFF8;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,2848
	ctx.r3.s64 = r11.s64 + 2848;
	// bl 0x82637b28
	ctx.lr = 0x8263FFEC;
	sub_82637B28(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8263FFF8:
	// lbz r11,1225(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1225);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640030
	if (cr6.eq) goto loc_82640030;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,1225(r31)
	PPC_STORE_U8(r31.u32 + 1225, ctx.r10.u8);
	// lbz r9,25116(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 25116);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82640048
	if (!cr6.eq) goto loc_82640048;
	// bl 0x8263e428
	ctx.lr = 0x82640024;
	sub_8263E428(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640030:
	// lbz r11,1227(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1227);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,1225(r31)
	PPC_STORE_U8(r31.u32 + 1225, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263ff90
	if (cr6.eq) goto loc_8263FF90;
loc_82640048:
	// bl 0x8263e860
	ctx.lr = 0x8264004C;
	sub_8263E860(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640058:
	// lis r5,3
	ctx.r5.s64 = 196608;
	// lwz r4,1148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1148);
	// lwz r3,1152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1152);
	// ori r5,r5,8192
	ctx.r5.u64 = ctx.r5.u64 | 8192;
	// bl 0x823da950
	ctx.lr = 0x8264006C;
	sub_823DA950(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640078:
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r3,r11,24884
	ctx.r3.s64 = r11.s64 + 24884;
	// bne cr6,0x82640114
	if (!cr6.eq) goto loc_82640114;
	// li r4,40
	ctx.r4.s64 = 40;
	// bl 0x8268ee10
	ctx.lr = 0x8264009C;
	sub_8268EE10(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,21436
	ctx.r3.s64 = ctx.r10.s64 + 21436;
	// bl 0x821fa230
	ctx.lr = 0x826400A8;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268dcb0
	ctx.lr = 0x826400B0;
	sub_8268DCB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826400C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826400D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263e860
	ctx.lr = 0x826400D8;
	sub_8263E860(ctx, base);
	// lbz r11,1170(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1170);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// lbz r11,1178(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1178);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640124
	if (cr6.eq) goto loc_82640124;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stb r9,1178(r31)
	PPC_STORE_U8(r31.u32 + 1178, ctx.r9.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,25116(r10)
	PPC_STORE_U8(ctx.r10.u32 + 25116, r11.u8);
	// addi r3,r8,24884
	ctx.r3.s64 = ctx.r8.s64 + 24884;
	// li r5,3
	ctx.r5.s64 = 3;
loc_82640114:
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x8268ee10
	ctx.lr = 0x8264011C;
	sub_8268EE10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263dc38
	ctx.lr = 0x82640124;
	sub_8263DC38(ctx, base);
loc_82640124:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82640130"))) PPC_WEAK_FUNC(sub_82640130);
PPC_FUNC_IMPL(__imp__sub_82640130) {
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
	// bl 0x8263f748
	ctx.lr = 0x82640150;
	sub_8263F748(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640168
	if (cr6.eq) goto loc_82640168;
	// bl 0x82130588
	ctx.lr = 0x82640164;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82640168:
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

__attribute__((alias("__imp__sub_82640180"))) PPC_WEAK_FUNC(sub_82640180);
PPC_FUNC_IMPL(__imp__sub_82640180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27564(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27564);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264018C"))) PPC_WEAK_FUNC(sub_8264018C);
PPC_FUNC_IMPL(__imp__sub_8264018C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640190"))) PPC_WEAK_FUNC(sub_82640190);
PPC_FUNC_IMPL(__imp__sub_82640190) {
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
	ctx.lr = 0x82640198;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x826401A4;
	sub_82632F78(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r11,2612
	r30.s64 = r11.s64 + 2612;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826401BC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826401CC;
	sub_825ED480(ctx, base);
	// li r10,57
	ctx.r10.s64 = 57;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-13268
	ctx.r4.s64 = ctx.r9.s64 + -13268;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82722678
	ctx.lr = 0x826401E8;
	sub_82722678(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r5,r31,944
	ctx.r5.s64 = r31.s64 + 944;
	// addi r4,r8,-13284
	ctx.r4.s64 = ctx.r8.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x826401FC;
	sub_82722678(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82640204"))) PPC_WEAK_FUNC(sub_82640204);
PPC_FUNC_IMPL(__imp__sub_82640204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640208"))) PPC_WEAK_FUNC(sub_82640208);
PPC_FUNC_IMPL(__imp__sub_82640208) {
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
	ctx.lr = 0x82640210;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r29,672
	r30.s64 = r29.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x82640224;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826402b4
	if (!cr6.gt) goto loc_826402B4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,2800(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 2800);
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// bl 0x821eec68
	ctx.lr = 0x8264023C;
	sub_821EEC68(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x82640244;
	sub_82631F88(ctx, base);
	// lwz r11,184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82640254
	if (cr6.lt) goto loc_82640254;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82640254:
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// bl 0x821f0600
	ctx.lr = 0x82640260;
	sub_821F0600(ctx, base);
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82640294
	if (!cr6.eq) goto loc_82640294;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264028c
	if (cr6.eq) goto loc_8264028C;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82640294
	if (!cr6.eq) goto loc_82640294;
loc_8264028C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82640298
	goto loc_82640298;
loc_82640294:
	// li r11,0
	r11.s64 = 0;
loc_82640298:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826402ac
	if (!cr6.eq) goto loc_826402AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f0108
	ctx.lr = 0x826402AC;
	sub_821F0108(ctx, base);
loc_826402AC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,2804(r29)
	PPC_STORE_U8(r29.u32 + 2804, r11.u8);
loc_826402B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826402C0"))) PPC_WEAK_FUNC(sub_826402C0);
PPC_FUNC_IMPL(__imp__sub_826402C0) {
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
	ctx.lr = 0x826402C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,3
	r31.s64 = 196608;
	// lis r11,3
	r11.s64 = 196608;
	// ori r31,r31,57288
	r31.u64 = r31.u64 | 57288;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// ori r29,r11,57416
	r29.u64 = r11.u64 | 57416;
loc_826402E0:
	// bl 0x82387b90
	ctx.lr = 0x826402E4;
	sub_82387B90(ctx, base);
	// lwzx r4,r31,r3
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826402f8
	if (cr6.eq) goto loc_826402F8;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821ef690
	ctx.lr = 0x826402F8;
	sub_821EF690(ctx, base);
loc_826402F8:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x826402e0
	if (cr6.lt) goto loc_826402E0;
	// bl 0x82387b90
	ctx.lr = 0x82640308;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lwz r4,1328(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 1328);
	// bl 0x821eec68
	ctx.lr = 0x82640318;
	sub_821EEC68(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8264031C;
	sub_82387B90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r4,1325(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1325);
	// bl 0x821eea90
	ctx.lr = 0x8264032C;
	sub_821EEA90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82640334"))) PPC_WEAK_FUNC(sub_82640334);
PPC_FUNC_IMPL(__imp__sub_82640334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640338"))) PPC_WEAK_FUNC(sub_82640338);
PPC_FUNC_IMPL(__imp__sub_82640338) {
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
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82640364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// ble cr6,0x826403f4
	if (!cr6.gt) goto loc_826403F4;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r10,3952
	ctx.r4.s64 = ctx.r10.s64 + 3952;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82640388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,672
	r31.s64 = r31.s64 + 672;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826403A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x826403AC;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r30,r11
	r30.u64 = r11.u64;
	// blt cr6,0x826403c0
	if (cr6.lt) goto loc_826403C0;
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
loc_826403C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x826403C8;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x82640450
	if (cr6.lt) goto loc_82640450;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82631f88
	ctx.lr = 0x826403DC;
	sub_82631F88(ctx, base);
	// addi r4,r3,-1
	ctx.r4.s64 = ctx.r3.s64 + -1;
	// lwz r11,648(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 648);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826403F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82640450
	goto loc_82640450;
loc_826403F4:
	// addi r30,r31,496
	r30.s64 = r31.s64 + 496;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,3932
	ctx.r4.s64 = ctx.r10.s64 + 3932;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264040C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,672
	r31.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82640428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264043C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,184(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82640450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82640450:
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

__attribute__((alias("__imp__sub_82640468"))) PPC_WEAK_FUNC(sub_82640468);
PPC_FUNC_IMPL(__imp__sub_82640468) {
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
	// cmpwi cr6,r4,63
	cr6.compare<int32_t>(ctx.r4.s32, 63, xer);
	// bne cr6,0x826404b0
	if (!cr6.eq) goto loc_826404B0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82640498;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826404AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,63
	ctx.r4.s64 = 63;
loc_826404B0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x826404BC;
	sub_826309E0(ctx, base);
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

__attribute__((alias("__imp__sub_826404D4"))) PPC_WEAK_FUNC(sub_826404D4);
PPC_FUNC_IMPL(__imp__sub_826404D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826404D8"))) PPC_WEAK_FUNC(sub_826404D8);
PPC_FUNC_IMPL(__imp__sub_826404D8) {
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
	ctx.lr = 0x826404F0;
	sub_8263A5F8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,4028
	ctx.r10.s64 = r11.s64 + 4028;
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

__attribute__((alias("__imp__sub_82640514"))) PPC_WEAK_FUNC(sub_82640514);
PPC_FUNC_IMPL(__imp__sub_82640514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640518"))) PPC_WEAK_FUNC(sub_82640518);
PPC_FUNC_IMPL(__imp__sub_82640518) {
	PPC_FUNC_PROLOGUE();
	// li r3,9
	ctx.r3.s64 = 9;
	// b 0x82216138
	sub_82216138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82640520"))) PPC_WEAK_FUNC(sub_82640520);
PPC_FUNC_IMPL(__imp__sub_82640520) {
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
	ctx.lr = 0x82640528;
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
	ctx.lr = 0x82640548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82640560
	if (!cr6.eq) goto loc_82640560;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640560:
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x82640580
	if (cr6.eq) goto loc_82640580;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82640578;
	sub_826537D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640580:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8264058C"))) PPC_WEAK_FUNC(sub_8264058C);
PPC_FUNC_IMPL(__imp__sub_8264058C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640590"))) PPC_WEAK_FUNC(sub_82640590);
PPC_FUNC_IMPL(__imp__sub_82640590) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r5,1240(r31)
	PPC_STORE_U32(r31.u32 + 1240, ctx.r5.u32);
	// bl 0x8268d0d8
	ctx.lr = 0x826405B8;
	sub_8268D0D8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x826405C4;
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

__attribute__((alias("__imp__sub_826405DC"))) PPC_WEAK_FUNC(sub_826405DC);
PPC_FUNC_IMPL(__imp__sub_826405DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826405E0"))) PPC_WEAK_FUNC(sub_826405E0);
PPC_FUNC_IMPL(__imp__sub_826405E0) {
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
	// bl 0x82631f88
	ctx.lr = 0x82640600;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r30,r11
	r30.u64 = r11.u64;
	// blt cr6,0x82640614
	if (cr6.lt) goto loc_82640614;
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
loc_82640614:
	// bl 0x82387b90
	ctx.lr = 0x82640618;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238af90
	ctx.lr = 0x82640620;
	sub_8238AF90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82640634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82640650"))) PPC_WEAK_FUNC(sub_82640650);
PPC_FUNC_IMPL(__imp__sub_82640650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,-2
	cr6.compare<int32_t>(ctx.r4.s32, -2, xer);
	// beq cr6,0x8264065c
	if (cr6.eq) goto loc_8264065C;
	// b 0x826537d0
	sub_826537D0(ctx, base);
	return;
loc_8264065C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82640664"))) PPC_WEAK_FUNC(sub_82640664);
PPC_FUNC_IMPL(__imp__sub_82640664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640668"))) PPC_WEAK_FUNC(sub_82640668);
PPC_FUNC_IMPL(__imp__sub_82640668) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82640694;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826406f0
	if (cr6.eq) goto loc_826406F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x826406AC;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82558290
	ctx.lr = 0x826406C4;
	sub_82558290(ctx, base);
	// lfs f2,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x826406D0;
	sub_823DCDD8(ctx, base);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// stfs f13,180(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f0,184(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
loc_826406F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822157a0
	ctx.lr = 0x826406F8;
	sub_822157A0(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x826406FC;
	sub_82130000(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13196
	ctx.r3.s64 = r11.s64 + -13196;
	// bl 0x821e6800
	ctx.lr = 0x82640708;
	sub_821E6800(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264071C;
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

__attribute__((alias("__imp__sub_82640734"))) PPC_WEAK_FUNC(sub_82640734);
PPC_FUNC_IMPL(__imp__sub_82640734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640738"))) PPC_WEAK_FUNC(sub_82640738);
PPC_FUNC_IMPL(__imp__sub_82640738) {
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
	ctx.lr = 0x82640740;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stb r30,4386(r31)
	PPC_STORE_U8(r31.u32 + 4386, r30.u8);
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8264075C;
	sub_8238EC00(ctx, base);
	// addi r5,r31,4172
	ctx.r5.s64 = r31.s64 + 4172;
	// lwz r4,1060(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1060);
	// bl 0x82389668
	ctx.lr = 0x82640768;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82640784
	if (!cr6.eq) goto loc_82640784;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82640784:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82640790;
	sub_822A39C8(ctx, base);
	// lwz r11,1052(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1052);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8264080c
	if (cr6.lt) goto loc_8264080C;
	// beq cr6,0x826407dc
	if (cr6.eq) goto loc_826407DC;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8264083c
	if (!cr6.lt) goto loc_8264083C;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f998
	ctx.lr = 0x826407B0;
	sub_8238F998(ctx, base);
	// lbz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826407DC:
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// bl 0x8238f998
	ctx.lr = 0x826407E4;
	sub_8238F998(ctx, base);
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264080C:
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r29,1056(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// bl 0x8238f6b0
	ctx.lr = 0x82640818;
	sub_8238F6B0(ctx, base);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// lwz r11,1056(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1056);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8264083c
	if (cr6.eq) goto loc_8264083C;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264083C:
	// lwz r11,1048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1048);
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,4168(r31)
	PPC_STORE_U32(r31.u32 + 4168, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82640850"))) PPC_WEAK_FUNC(sub_82640850);
PPC_FUNC_IMPL(__imp__sub_82640850) {
	PPC_FUNC_PROLOGUE();
	// b 0x826302b8
	sub_826302B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82640854"))) PPC_WEAK_FUNC(sub_82640854);
PPC_FUNC_IMPL(__imp__sub_82640854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640858"))) PPC_WEAK_FUNC(sub_82640858);
PPC_FUNC_IMPL(__imp__sub_82640858) {
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
	// bl 0x82633f38
	ctx.lr = 0x82640868;
	sub_82633F38(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82640878;
	sub_82207190(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82640888"))) PPC_WEAK_FUNC(sub_82640888);
PPC_FUNC_IMPL(__imp__sub_82640888) {
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
	// bl 0x82634010
	ctx.lr = 0x82640898;
	sub_82634010(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x826408A8;
	sub_82207190(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826408B8"))) PPC_WEAK_FUNC(sub_826408B8);
PPC_FUNC_IMPL(__imp__sub_826408B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,256(r3)
	PPC_STORE_U32(ctx.r3.u32 + 256, ctx.r10.u32);
	// stw r9,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r9.u32);
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r8,1892(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 1892);
	// stw r8,264(r3)
	PPC_STORE_U32(ctx.r3.u32 + 264, ctx.r8.u32);
	// b 0x822165a8
	sub_822165A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826408DC"))) PPC_WEAK_FUNC(sub_826408DC);
PPC_FUNC_IMPL(__imp__sub_826408DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826408E0"))) PPC_WEAK_FUNC(sub_826408E0);
PPC_FUNC_IMPL(__imp__sub_826408E0) {
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
	// lwz r3,872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82640908
	if (cr6.eq) goto loc_82640908;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82640908;
	sub_821EC060(ctx, base);
loc_82640908:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264091c
	if (cr6.eq) goto loc_8264091C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x8264091C;
	sub_821EC060(ctx, base);
loc_8264091C:
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82640930
	if (cr6.eq) goto loc_82640930;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82640930;
	sub_821EC060(ctx, base);
loc_82640930:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
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

__attribute__((alias("__imp__sub_82640954"))) PPC_WEAK_FUNC(sub_82640954);
PPC_FUNC_IMPL(__imp__sub_82640954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640958"))) PPC_WEAK_FUNC(sub_82640958);
PPC_FUNC_IMPL(__imp__sub_82640958) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,868(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x826409cc
	if (!cr6.eq) goto loc_826409CC;
	// lwz r3,872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826409a0
	if (cr6.eq) goto loc_826409A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826409A0;
	sub_821EC060(ctx, base);
loc_826409A0:
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826409b4
	if (cr6.eq) goto loc_826409B4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826409B4;
	sub_821EC060(ctx, base);
loc_826409B4:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82640ab8
	if (cr6.eq) goto loc_82640AB8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826409C8;
	sub_821EC060(ctx, base);
	// b 0x82640ab8
	goto loc_82640AB8;
loc_826409CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x82640a40
	if (!cr6.eq) goto loc_82640A40;
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826409f0
	if (cr6.eq) goto loc_826409F0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826409F0;
	sub_821EC060(ctx, base);
loc_826409F0:
	// lwz r11,872(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// addi r5,r31,872
	ctx.r5.s64 = r31.s64 + 872;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640a14
	if (!cr6.eq) goto loc_82640A14;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 884);
	// bl 0x821ee370
	ctx.lr = 0x82640A14;
	sub_821EE370(ctx, base);
loc_82640A14:
	// lwz r11,880(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// addi r5,r31,880
	ctx.r5.s64 = r31.s64 + 880;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640a38
	if (!cr6.eq) goto loc_82640A38;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,892(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// bl 0x821ee370
	ctx.lr = 0x82640A34;
	sub_821EE370(ctx, base);
	// b 0x82640ab8
	goto loc_82640AB8;
loc_82640A38:
	// stfs f31,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// b 0x82640ab8
	goto loc_82640AB8;
loc_82640A40:
	// lwz r3,872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82640a54
	if (cr6.eq) goto loc_82640A54;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82640A54;
	sub_821EC060(ctx, base);
loc_82640A54:
	// lwz r11,876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// addi r5,r31,876
	ctx.r5.s64 = r31.s64 + 876;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640a78
	if (!cr6.eq) goto loc_82640A78;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,888(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 888);
	// bl 0x821ee370
	ctx.lr = 0x82640A78;
	sub_821EE370(ctx, base);
loc_82640A78:
	// lwz r11,880(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lfs f0,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// addi r5,r31,880
	ctx.r5.s64 = r31.s64 + 880;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640aa0
	if (!cr6.eq) goto loc_82640AA0;
	// lwz r3,-12252(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12252);
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 - f0.f64));
	// lwz r4,892(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 892);
	// bl 0x821ee370
	ctx.lr = 0x82640A9C;
	sub_821EE370(ctx, base);
	// b 0x82640ab8
	goto loc_82640AB8;
loc_82640AA0:
	// fsubs f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fsel f12,f13,f13,f30
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// fsel f11,f13,f13,f30
	ctx.f11.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// fsubs f10,f12,f31
	ctx.f10.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f9,f10,f31,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// stfs f9,20(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
loc_82640AB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82640AD8"))) PPC_WEAK_FUNC(sub_82640AD8);
PPC_FUNC_IMPL(__imp__sub_82640AD8) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82640AE0"))) PPC_WEAK_FUNC(sub_82640AE0);
PPC_FUNC_IMPL(__imp__sub_82640AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82640AE8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82256058
	ctx.lr = 0x82640B04;
	sub_82256058(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x82640b48
	if (!cr6.gt) goto loc_82640B48;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82640B24;
	sub_8238EC00(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// stw r4,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r4.u32);
	// bl 0x82389800
	ctx.lr = 0x82640B3C;
	sub_82389800(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r7,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r7.u32);
loc_82640B48:
	// lwz r11,3104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3104);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cmplwi cr6,r11,15
	cr6.compare<uint32_t>(r11.u32, 15, xer);
	// bgt cr6,0x82640d64
	if (cr6.gt) goto loc_82640D64;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,2928
	r12.s64 = r12.s64 + 2928;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82640D00;
	case 1:
		goto loc_82640BB0;
	case 2:
		goto loc_82640C10;
	case 3:
		goto loc_82640D64;
	case 4:
		goto loc_82640CE8;
	case 5:
		goto loc_82640D64;
	case 6:
		goto loc_82640D64;
	case 7:
		goto loc_82640D64;
	case 8:
		goto loc_82640D64;
	case 9:
		goto loc_82640CBC;
	case 10:
		goto loc_82640D64;
	case 11:
		goto loc_82640D58;
	case 12:
		goto loc_82640D64;
	case 13:
		goto loc_82640D64;
	case 14:
		goto loc_82640D3C;
	case 15:
		goto loc_82640D3C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,3328(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3328);
	// lwz r19,2992(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2992);
	// lwz r19,3088(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3088);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3304(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3304);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3260(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3260);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3416(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3416);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3428(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3428);
	// lwz r19,3388(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3388);
	// lwz r19,3388(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3388);
loc_82640BB0:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,5700
	ctx.r3.s64 = r11.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x82640BBC;
	sub_821FA230(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,5684
	ctx.r4.s64 = ctx.r10.s64 + 5684;
	// bl 0x8268da78
	ctx.lr = 0x82640BCC;
	sub_8268DA78(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r5,r8,32684
	ctx.r5.s64 = ctx.r8.s64 + 32684;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x82640BE8;
	sub_82137A08(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,5660
	ctx.r4.s64 = ctx.r6.s64 + 5660;
	// lwz r3,-10244(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82640C00;
	sub_822183B0(ctx, base);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// addi r4,r5,5636
	ctx.r4.s64 = ctx.r5.s64 + 5636;
	// stw r4,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r4.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640C10:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,5616
	ctx.r3.s64 = r11.s64 + 5616;
	// bl 0x821fa230
	ctx.lr = 0x82640C1C;
	sub_821FA230(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,5596
	ctx.r4.s64 = ctx.r10.s64 + 5596;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8268da78
	ctx.lr = 0x82640C30;
	sub_8268DA78(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r28,r8,32684
	r28.s64 = ctx.r8.s64 + 32684;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// bl 0x82137a08
	ctx.lr = 0x82640C54;
	sub_82137A08(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,5660
	ctx.r4.s64 = ctx.r7.s64 + 5660;
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82640C6C;
	sub_822183B0(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,5584
	ctx.r4.s64 = ctx.r6.s64 + 5584;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268da78
	ctx.lr = 0x82640C80;
	sub_8268DA78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x82640C98;
	sub_82137A08(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,5560
	ctx.r4.s64 = ctx.r10.s64 + 5560;
	// bl 0x822183b0
	ctx.lr = 0x82640CAC;
	sub_822183B0(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r9,5532
	ctx.r8.s64 = ctx.r9.s64 + 5532;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640CBC:
	// lwz r11,3140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82640cd8
	if (cr6.eq) goto loc_82640CD8;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,5516
	ctx.r10.s64 = r11.s64 + 5516;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640CD8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,5500
	ctx.r10.s64 = r11.s64 + 5500;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640CE8:
	// lwz r11,3100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3100);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r9,r10,-27892
	ctx.r9.s64 = ctx.r10.s64 + -27892;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// b 0x82640e1c
	goto loc_82640E1C;
loc_82640D00:
	// bl 0x82256058
	ctx.lr = 0x82640D04;
	sub_82256058(ctx, base);
	// bl 0x82256150
	ctx.lr = 0x82640D08;
	sub_82256150(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223de50
	ctx.lr = 0x82640D14;
	sub_8223DE50(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,5480
	ctx.r4.s64 = ctx.r10.s64 + 5480;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82640D2C;
	sub_822183B0(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r9,5452
	ctx.r8.s64 = ctx.r9.s64 + 5452;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640D3C:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82640ce8
	if (cr6.eq) goto loc_82640CE8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640D58:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
loc_82640D64:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,5412
	ctx.r3.s64 = r11.s64 + 5412;
	// bl 0x82130000
	ctx.lr = 0x82640D78;
	sub_82130000(ctx, base);
	// lwz r10,3160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3160);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82640db8
	if (cr6.eq) goto loc_82640DB8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// bl 0x8223de50
	ctx.lr = 0x82640D90;
	sub_8223DE50(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,5480
	ctx.r4.s64 = ctx.r10.s64 + 5480;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82640DA8;
	sub_822183B0(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r9,5452
	ctx.r8.s64 = ctx.r9.s64 + 5452;
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640DB8:
	// lwz r11,3100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3100);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82640de4
	if (!cr6.eq) goto loc_82640DE4;
	// lwz r10,3124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3124);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bgt cr6,0x82640de4
	if (cr6.gt) goto loc_82640DE4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r10,r11,-27892
	ctx.r10.s64 = r11.s64 + -27892;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640DE4:
	// lwz r10,3148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3148);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82640e0c
	if (cr6.eq) goto loc_82640E0C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,2052
	ctx.r9.s64 = r11.s64 + 2052;
	// addi r8,r10,5400
	ctx.r8.s64 = ctx.r10.s64 + 5400;
	// stw r9,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// b 0x82640e20
	goto loc_82640E20;
loc_82640E0C:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-27892
	ctx.r8.s64 = ctx.r10.s64 + -27892;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
loc_82640E1C:
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
loc_82640E20:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,3108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3108);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r7,r11,531
	ctx.r7.s64 = r11.s64 + 531;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r5,r7,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-10020(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10020);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-13328(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13328);
	f0.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lfsx f12,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,15360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15360);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,8504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8504);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f8,8500(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8500);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fctiwz f6,f11
	ctx.f6.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r4,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// fctiwz f5,f9
	ctx.f5.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f4,f7
	ctx.f4.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82640EA4"))) PPC_WEAK_FUNC(sub_82640EA4);
PPC_FUNC_IMPL(__imp__sub_82640EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82640EA8"))) PPC_WEAK_FUNC(sub_82640EA8);
PPC_FUNC_IMPL(__imp__sub_82640EA8) {
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
	// bl 0x8228fbf8
	ctx.lr = 0x82640EC0;
	sub_8228FBF8(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82640EC4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82640f60
	if (cr6.eq) goto loc_82640F60;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82640ae0
	ctx.lr = 0x82640EFC;
	sub_82640AE0(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82640F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// lwz r5,340(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 340);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82640F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,88(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r11.u32);
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82640F4C;
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
loc_82640F60:
	// lis r11,255
	r11.s64 = 16711680;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// stw r10,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82640F80"))) PPC_WEAK_FUNC(sub_82640F80);
PPC_FUNC_IMPL(__imp__sub_82640F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82640F98"))) PPC_WEAK_FUNC(sub_82640F98);
PPC_FUNC_IMPL(__imp__sub_82640F98) {
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
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x821eefd8
	ctx.lr = 0x82640FC8;
	sub_821EEFD8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82640fe4
	if (cr6.eq) goto loc_82640FE4;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// li r3,22
	ctx.r3.s64 = 22;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82640fe8
	if (!cr6.eq) goto loc_82640FE8;
loc_82640FE4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82640FE8:
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

__attribute__((alias("__imp__sub_82640FFC"))) PPC_WEAK_FUNC(sub_82640FFC);
PPC_FUNC_IMPL(__imp__sub_82640FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641000"))) PPC_WEAK_FUNC(sub_82641000);
PPC_FUNC_IMPL(__imp__sub_82641000) {
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
	ctx.lr = 0x82641008;
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
	ctx.lr = 0x8264101C;
	sub_82631F88(ctx, base);
	// addi r29,r30,256
	r29.s64 = r30.s64 + 256;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ble cr6,0x826410a8
	if (!cr6.gt) goto loc_826410A8;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,28964
	ctx.r4.s64 = r11.s64 + 28964;
	// bl 0x8262ffe0
	ctx.lr = 0x8264103C;
	sub_8262FFE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82641044;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82641054
	if (cr6.lt) goto loc_82641054;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82641054:
	// lwz r10,2800(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 2800);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,11
	ctx.r7.s64 = ctx.r10.s64 + 11;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lwzx r5,r6,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// bl 0x821eefd8
	ctx.lr = 0x82641078;
	sub_821EEFD8(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,432(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 432);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82641098
	if (cr6.eq) goto loc_82641098;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r10,5736
	ctx.r9.s64 = ctx.r10.s64 + 5736;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// b 0x826410b8
	goto loc_826410B8;
loc_82641098:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r10,5716
	ctx.r9.s64 = ctx.r10.s64 + 5716;
	// stw r9,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r9.u32);
	// b 0x826410b8
	goto loc_826410B8;
loc_826410A8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// bl 0x8262ffe0
	ctx.lr = 0x826410B8;
	sub_8262FFE0(ctx, base);
loc_826410B8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826410CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826410D4"))) PPC_WEAK_FUNC(sub_826410D4);
PPC_FUNC_IMPL(__imp__sub_826410D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826410D8"))) PPC_WEAK_FUNC(sub_826410D8);
PPC_FUNC_IMPL(__imp__sub_826410D8) {
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
	ctx.lr = 0x826410E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,3
	r11.s64 = 196608;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// ori r27,r11,57288
	r27.u64 = r11.u64 | 57288;
	// lis r11,3
	r11.s64 = 196608;
	// mr r29,r27
	r29.u64 = r27.u64;
	// li r31,0
	r31.s64 = 0;
	// lwz r26,-12216(r25)
	r26.u64 = PPC_LOAD_U32(r25.u32 + -12216);
	// ori r28,r11,57416
	r28.u64 = r11.u64 | 57416;
loc_82641104:
	// bl 0x82387b90
	ctx.lr = 0x82641108;
	sub_82387B90(ctx, base);
	// stwx r31,r3,r29
	PPC_STORE_U32(ctx.r3.u32 + r29.u32, r31.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x82641104
	if (cr6.lt) goto loc_82641104;
	// lhz r28,156(r26)
	r28.u64 = PPC_LOAD_U16(r26.u32 + 156);
	// mr r30,r31
	r30.u64 = r31.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x82641158
	if (!cr6.gt) goto loc_82641158;
loc_82641128:
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// bge cr6,0x82641158
	if (!cr6.lt) goto loc_82641158;
	// lwz r29,152(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 152);
	// bl 0x82387b90
	ctx.lr = 0x82641138;
	sub_82387B90(ctx, base);
	// lwzx r11,r29,r31
	r11.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// add r10,r31,r3
	ctx.r10.u64 = r31.u64 + ctx.r3.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stwx r9,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, ctx.r9.u32);
	// blt cr6,0x82641128
	if (cr6.lt) goto loc_82641128;
loc_82641158:
	// lwz r11,-12216(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12216);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82387b90
	ctx.lr = 0x82641164;
	sub_82387B90(ctx, base);
	// stw r31,1328(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1328, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82641170"))) PPC_WEAK_FUNC(sub_82641170);
PPC_FUNC_IMPL(__imp__sub_82641170) {
	PPC_FUNC_PROLOGUE();
	// b 0x82641000
	sub_82641000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82641174"))) PPC_WEAK_FUNC(sub_82641174);
PPC_FUNC_IMPL(__imp__sub_82641174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641178"))) PPC_WEAK_FUNC(sub_82641178);
PPC_FUNC_IMPL(__imp__sub_82641178) {
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
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// bl 0x82387928
	ctx.lr = 0x826411A8;
	sub_82387928(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r4,r9,6580
	ctx.r4.s64 = ctx.r9.s64 + 6580;
	// li r8,10000
	ctx.r8.s64 = 10000;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r7,1000
	ctx.r7.s64 = 1000;
	// li r6,1000
	ctx.r6.s64 = 1000;
	// li r9,1
	ctx.r9.s64 = 1;
	// bne cr6,0x826411dc
	if (!cr6.eq) goto loc_826411DC;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r10,6552
	ctx.r5.s64 = ctx.r10.s64 + 6552;
	// b 0x826411e4
	goto loc_826411E4;
loc_826411DC:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r10,6532
	ctx.r5.s64 = ctx.r10.s64 + 6532;
loc_826411E4:
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821fb938
	ctx.lr = 0x826411EC;
	sub_821FB938(ctx, base);
	// stb r30,256(r31)
	PPC_STORE_U8(r31.u32 + 256, r30.u8);
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

__attribute__((alias("__imp__sub_82641208"))) PPC_WEAK_FUNC(sub_82641208);
PPC_FUNC_IMPL(__imp__sub_82641208) {
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
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264127c
	if (cr6.eq) goto loc_8264127C;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,1072
	ctx.r4.s64 = ctx.r10.s64 + 1072;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x825ee120
	ctx.lr = 0x82641248;
	sub_825EE120(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x826412a0
	if (!cr6.eq) goto loc_826412A0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82641260;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// b 0x826412a0
	goto loc_826412A0;
loc_8264127C:
	// lbz r11,256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826412a0
	if (!cr6.eq) goto loc_826412A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,6580
	ctx.r4.s64 = ctx.r10.s64 + 6580;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8264129C;
	sub_821F9FB8(ctx, base);
	// stw r3,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r3.u32);
loc_826412A0:
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

__attribute__((alias("__imp__sub_826412B8"))) PPC_WEAK_FUNC(sub_826412B8);
PPC_FUNC_IMPL(__imp__sub_826412B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stb r11,256(r3)
	PPC_STORE_U8(ctx.r3.u32 + 256, r11.u8);
	// stw r10,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r10.u32);
	// lwz r3,-10236(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// addi r4,r8,6580
	ctx.r4.s64 = ctx.r8.s64 + 6580;
	// b 0x821f96c8
	sub_821F96C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826412DC"))) PPC_WEAK_FUNC(sub_826412DC);
PPC_FUNC_IMPL(__imp__sub_826412DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826412E0"))) PPC_WEAK_FUNC(sub_826412E0);
PPC_FUNC_IMPL(__imp__sub_826412E0) {
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
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x82641300;
	sub_8220F040(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x82641308;
	sub_82387928(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// addi r4,r9,6580
	ctx.r4.s64 = ctx.r9.s64 + 6580;
	// li r8,10000
	ctx.r8.s64 = 10000;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r7,1000
	ctx.r7.s64 = 1000;
	// li r6,1000
	ctx.r6.s64 = 1000;
	// addi r31,r11,-10236
	r31.s64 = r11.s64 + -10236;
	// li r9,0
	ctx.r9.s64 = 0;
	// bne cr6,0x82641340
	if (!cr6.eq) goto loc_82641340;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r10,6552
	ctx.r5.s64 = ctx.r10.s64 + 6552;
	// b 0x82641348
	goto loc_82641348;
loc_82641340:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r10,6532
	ctx.r5.s64 = ctx.r10.s64 + 6532;
loc_82641348:
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x821fb938
	ctx.lr = 0x82641350;
	sub_821FB938(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821fce90
	ctx.lr = 0x82641360;
	sub_821FCE90(ctx, base);
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

__attribute__((alias("__imp__sub_82641374"))) PPC_WEAK_FUNC(sub_82641374);
PPC_FUNC_IMPL(__imp__sub_82641374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641378"))) PPC_WEAK_FUNC(sub_82641378);
PPC_FUNC_IMPL(__imp__sub_82641378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,6580
	ctx.r4.s64 = ctx.r10.s64 + 6580;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// b 0x821f96c8
	sub_821F96C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8264138C"))) PPC_WEAK_FUNC(sub_8264138C);
PPC_FUNC_IMPL(__imp__sub_8264138C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641390"))) PPC_WEAK_FUNC(sub_82641390);
PPC_FUNC_IMPL(__imp__sub_82641390) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826413A8;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826413B8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x826413C0;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264142c
	if (!cr6.eq) goto loc_8264142C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826413D4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826413E4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826413EC;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8264142c
	if (!cr6.eq) goto loc_8264142C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82641400;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82641410;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272d50
	ctx.lr = 0x82641418;
	sub_82272D50(ctx, base);
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
loc_8264142C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82641434;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82641444;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8264144C;
	sub_821F8730(ctx, base);
	// bl 0x82131c30
	ctx.lr = 0x82641450;
	sub_82131C30(ctx, base);
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

__attribute__((alias("__imp__sub_82641464"))) PPC_WEAK_FUNC(sub_82641464);
PPC_FUNC_IMPL(__imp__sub_82641464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641468"))) PPC_WEAK_FUNC(sub_82641468);
PPC_FUNC_IMPL(__imp__sub_82641468) {
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
	// bctrl 
	ctx.lr = 0x8264148C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82641494;
	sub_82216138(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826414A4"))) PPC_WEAK_FUNC(sub_826414A4);
PPC_FUNC_IMPL(__imp__sub_826414A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826414A8"))) PPC_WEAK_FUNC(sub_826414A8);
PPC_FUNC_IMPL(__imp__sub_826414A8) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x826414C4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826414d4
	if (cr6.lt) goto loc_826414D4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826414D4:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82641538
	if (cr6.lt) goto loc_82641538;
	// bne cr6,0x82641540
	if (!cr6.eq) goto loc_82641540;
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826414F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641528
	if (cr6.eq) goto loc_82641528;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,23868
	ctx.r3.s64 = r11.s64 + 23868;
	// bl 0x821e6800
	ctx.lr = 0x8264150C;
	sub_821E6800(ctx, base);
	// bl 0x822156e8
	ctx.lr = 0x82641510;
	sub_822156E8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82641540
	goto loc_82641540;
loc_82641528:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15540
	ctx.r3.s64 = r11.s64 + -15540;
	// bl 0x821e6800
	ctx.lr = 0x82641534;
	sub_821E6800(ctx, base);
	// b 0x82641540
	goto loc_82641540;
loc_82641538:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640668
	ctx.lr = 0x82641540;
	sub_82640668(ctx, base);
loc_82641540:
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

__attribute__((alias("__imp__sub_82641558"))) PPC_WEAK_FUNC(sub_82641558);
PPC_FUNC_IMPL(__imp__sub_82641558) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r10,27761
	ctx.r8.u64 = ctx.r10.u64 | 27761;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// li r4,0
	ctx.r4.s64 = 0;
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// lwz r31,17268(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82641594;
	sub_821E80F8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826415f4
	if (cr6.eq) goto loc_826415F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x826415AC;
	sub_822A3998(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a6198
	ctx.lr = 0x826415BC;
	sub_822A6198(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x826415C8;
	sub_822A93A8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x826415E0;
	sub_822AFCD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x826415E8;
	sub_822A5578(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
loc_826415F4:
	// bl 0x822150d8
	ctx.lr = 0x826415F8;
	sub_822150D8(ctx, base);
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

__attribute__((alias("__imp__sub_8264160C"))) PPC_WEAK_FUNC(sub_8264160C);
PPC_FUNC_IMPL(__imp__sub_8264160C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641610"))) PPC_WEAK_FUNC(sub_82641610);
PPC_FUNC_IMPL(__imp__sub_82641610) {
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
	ctx.lr = 0x82641618;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x82641624;
	sub_82653B30(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r30,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r30.u8);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r30,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r30.u8);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x8261fb00
	ctx.lr = 0x82641658;
	sub_8261FB00(ctx, base);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r3,r31,996
	ctx.r3.s64 = r31.s64 + 996;
	// stb r30,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r30.u8);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r30,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r30.u8);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// stb r10,377(r11)
	PPC_STORE_U8(r11.u32 + 377, ctx.r10.u8);
	// bl 0x822d4cc0
	ctx.lr = 0x8264167C;
	sub_822D4CC0(ctx, base);
	// lwz r8,4176(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r9,6588
	ctx.r4.s64 = ctx.r9.s64 + 6588;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82641698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r30,4385(r31)
	PPC_STORE_U8(r31.u32 + 4385, r30.u8);
	// stb r30,4386(r31)
	PPC_STORE_U8(r31.u32 + 4386, r30.u8);
	// stw r6,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r6.u32);
	// stb r30,4387(r31)
	PPC_STORE_U8(r31.u32 + 4387, r30.u8);
	// stb r30,4384(r31)
	PPC_STORE_U8(r31.u32 + 4384, r30.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826416B8"))) PPC_WEAK_FUNC(sub_826416B8);
PPC_FUNC_IMPL(__imp__sub_826416B8) {
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
	// bl 0x82653670
	ctx.lr = 0x826416D0;
	sub_82653670(ctx, base);
	// lbz r11,4384(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4384);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826416f8
	if (!cr6.eq) goto loc_826416F8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// stb r10,4387(r31)
	PPC_STORE_U8(r31.u32 + 4387, ctx.r10.u8);
	// bl 0x82216138
	ctx.lr = 0x826416F8;
	sub_82216138(ctx, base);
loc_826416F8:
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

__attribute__((alias("__imp__sub_8264170C"))) PPC_WEAK_FUNC(sub_8264170C);
PPC_FUNC_IMPL(__imp__sub_8264170C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641710"))) PPC_WEAK_FUNC(sub_82641710);
PPC_FUNC_IMPL(__imp__sub_82641710) {
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
	ctx.lr = 0x8264172C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264173c
	if (cr6.lt) goto loc_8264173C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264173C:
	// lwz r10,1232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1232);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82641784
	if (!cr6.eq) goto loc_82641784;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82641750;
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
	ctx.lr = 0x82641764;
	sub_82270170(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// ori r31,r9,65520
	r31.u64 = ctx.r9.u64 | 65520;
	// bl 0x821f8730
	ctx.lr = 0x82641774;
	sub_821F8730(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82131c40
	ctx.lr = 0x82641784;
	sub_82131C40(ctx, base);
loc_82641784:
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

__attribute__((alias("__imp__sub_8264179C"))) PPC_WEAK_FUNC(sub_8264179C);
PPC_FUNC_IMPL(__imp__sub_8264179C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826417A0"))) PPC_WEAK_FUNC(sub_826417A0);
PPC_FUNC_IMPL(__imp__sub_826417A0) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826417C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641890
	if (cr6.eq) goto loc_82641890;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826417DC;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826417EC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826417F4;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264182c
	if (cr6.eq) goto loc_8264182C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82641808;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82641818;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82641820;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82641890
	if (!cr6.eq) goto loc_82641890;
loc_8264182C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,6612
	ctx.r3.s64 = r11.s64 + 6612;
	// bl 0x821fa230
	ctx.lr = 0x82641838;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264184C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82641864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264187C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,736(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 736);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82641890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82641890:
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

__attribute__((alias("__imp__sub_826418A8"))) PPC_WEAK_FUNC(sub_826418A8);
PPC_FUNC_IMPL(__imp__sub_826418A8) {
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
	ctx.lr = 0x826418B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x8262fe68
	ctx.lr = 0x826418BC;
	sub_8262FE68(ctx, base);
	// lhz r11,72(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82641908
	if (!cr6.gt) goto loc_82641908;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_826418D4:
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826418EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826418fc
	if (!cr6.eq) goto loc_826418FC;
	// li r28,0
	r28.s64 = 0;
loc_826418FC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826418d4
	if (!cr0.eq) goto loc_826418D4;
loc_82641908:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82641914"))) PPC_WEAK_FUNC(sub_82641914);
PPC_FUNC_IMPL(__imp__sub_82641914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641918"))) PPC_WEAK_FUNC(sub_82641918);
PPC_FUNC_IMPL(__imp__sub_82641918) {
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
	ctx.lr = 0x82641920;
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
	ctx.lr = 0x82641940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641a28
	if (cr6.eq) goto loc_82641A28;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826419a4
	if (cr6.eq) goto loc_826419A4;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264196C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826419a4
	if (cr6.eq) goto loc_826419A4;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,512(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641994;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// b 0x826419b8
	goto loc_826419B8;
loc_826419A4:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// lwz r31,436(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 436);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82641a28
	if (cr6.eq) goto loc_82641A28;
loc_826419B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641a28
	if (cr6.eq) goto loc_82641A28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826419D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641a28
	if (cr6.eq) goto loc_82641A28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641A00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82641A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82641a2c
	if (cr6.eq) goto loc_82641A2C;
loc_82641A28:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82641A2C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82641A34"))) PPC_WEAK_FUNC(sub_82641A34);
PPC_FUNC_IMPL(__imp__sub_82641A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641A38"))) PPC_WEAK_FUNC(sub_82641A38);
PPC_FUNC_IMPL(__imp__sub_82641A38) {
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
	ctx.lr = 0x82641A40;
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
	ctx.lr = 0x82641A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82641ac4
	if (cr6.eq) goto loc_82641AC4;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641ac4
	if (cr6.eq) goto loc_82641AC4;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,512(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// b 0x82641ad8
	goto loc_82641AD8;
loc_82641AC4:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r11,1
	r11.s64 = 1;
	// lwz r31,436(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 436);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
loc_82641AD8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641AF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641b48
	if (cr6.eq) goto loc_82641B48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82641B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82641b4c
	if (cr6.eq) goto loc_82641B4C;
loc_82641B48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82641B4C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82641B54"))) PPC_WEAK_FUNC(sub_82641B54);
PPC_FUNC_IMPL(__imp__sub_82641B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641B58"))) PPC_WEAK_FUNC(sub_82641B58);
PPC_FUNC_IMPL(__imp__sub_82641B58) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82641bb0
	if (cr6.eq) goto loc_82641BB0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641bb0
	if (cr6.eq) goto loc_82641BB0;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82641bc0
	if (!cr6.eq) goto loc_82641BC0;
loc_82641BB0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82641BBC;
	sub_82207190(ctx, base);
	// b 0x82641bf4
	goto loc_82641BF4;
loc_82641BC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641BD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641bf4
	if (cr6.eq) goto loc_82641BF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641BF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82641BF4:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641c08
	if (cr6.eq) goto loc_82641C08;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82207190
	ctx.lr = 0x82641C08;
	sub_82207190(ctx, base);
loc_82641C08:
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

__attribute__((alias("__imp__sub_82641C20"))) PPC_WEAK_FUNC(sub_82641C20);
PPC_FUNC_IMPL(__imp__sub_82641C20) {
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
	ctx.lr = 0x82641C28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lhz r24,72(r30)
	r24.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x82641c98
	if (!cr6.gt) goto loc_82641C98;
	// li r31,0
	r31.s64 = 0;
loc_82641C54:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,380(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 380);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82641ca4
	if (!cr6.eq) goto loc_82641CA4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r24
	cr6.compare<int32_t>(r29.s32, r24.s32, xer);
	// blt cr6,0x82641c54
	if (cr6.lt) goto loc_82641C54;
loc_82641C98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82641CA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82641CB0"))) PPC_WEAK_FUNC(sub_82641CB0);
PPC_FUNC_IMPL(__imp__sub_82641CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641CC8"))) PPC_WEAK_FUNC(sub_82641CC8);
PPC_FUNC_IMPL(__imp__sub_82641CC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641cec
	if (cr6.eq) goto loc_82641CEC;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,13136
	ctx.r10.s64 = ctx.r10.s64 + 13136;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_82641CEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641CF4"))) PPC_WEAK_FUNC(sub_82641CF4);
PPC_FUNC_IMPL(__imp__sub_82641CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82641CF8"))) PPC_WEAK_FUNC(sub_82641CF8);
PPC_FUNC_IMPL(__imp__sub_82641CF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,216(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641d18
	if (cr6.eq) goto loc_82641D18;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82641D18:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82641D20"))) PPC_WEAK_FUNC(sub_82641D20);
PPC_FUNC_IMPL(__imp__sub_82641D20) {
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
	// lwz r31,212(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82641d7c
	if (cr6.eq) goto loc_82641D7C;
loc_82641D3C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82641d70
	if (cr6.eq) goto loc_82641D70;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82641D70:
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82641d3c
	if (!cr6.eq) goto loc_82641D3C;
loc_82641D7C:
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

__attribute__((alias("__imp__sub_82641D90"))) PPC_WEAK_FUNC(sub_82641D90);
PPC_FUNC_IMPL(__imp__sub_82641D90) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,6644
	ctx.r10.s64 = r11.s64 + 6644;
	// lwz r3,872(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 872);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dc4
	if (cr6.eq) goto loc_82641DC4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DC4;
	sub_821EC060(ctx, base);
loc_82641DC4:
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dd8
	if (cr6.eq) goto loc_82641DD8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DD8;
	sub_821EC060(ctx, base);
loc_82641DD8:
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82641dec
	if (cr6.eq) goto loc_82641DEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82641DEC;
	sub_821EC060(ctx, base);
loc_82641DEC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// bl 0x82633b00
	ctx.lr = 0x82641E04;
	sub_82633B00(ctx, base);
	// addi r3,r31,464
	ctx.r3.s64 = r31.s64 + 464;
	// bl 0x82633b00
	ctx.lr = 0x82641E0C;
	sub_82633B00(ctx, base);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// bl 0x82633b00
	ctx.lr = 0x82641E14;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82641E1C;
	sub_82633B00(ctx, base);
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

__attribute__((alias("__imp__sub_82641E30"))) PPC_WEAK_FUNC(sub_82641E30);
PPC_FUNC_IMPL(__imp__sub_82641E30) {
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
	// bl 0x8221cdd0
	ctx.lr = 0x82641E48;
	sub_8221CDD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82641e64
	if (cr6.eq) goto loc_82641E64;
	// lbz r11,896(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 896);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82641e68
	if (cr6.eq) goto loc_82641E68;
loc_82641E64:
	// li r11,0
	r11.s64 = 0;
loc_82641E68:
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

__attribute__((alias("__imp__sub_82641E80"))) PPC_WEAK_FUNC(sub_82641E80);
PPC_FUNC_IMPL(__imp__sub_82641E80) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r3,r10,7412
	ctx.r3.s64 = ctx.r10.s64 + 7412;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x82641EB4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r6,r7,16324
	ctx.r6.u64 = ctx.r7.u64 | 16324;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwzx r5,r11,r6
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// lwz r3,284(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 284);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82641EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82215a60
	ctx.lr = 0x82641EF8;
	sub_82215A60(ctx, base);
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

__attribute__((alias("__imp__sub_82641F10"))) PPC_WEAK_FUNC(sub_82641F10);
PPC_FUNC_IMPL(__imp__sub_82641F10) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82641F18;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d8
	ctx.lr = 0x82641F20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82641F4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f29,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82642114
	if (cr6.eq) goto loc_82642114;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,264(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// lwz r30,-5008(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r9,1892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1892);
	// lwz r8,1888(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1888);
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// subf r6,r10,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r10.s64;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f9,f11,f30
	ctx.f9.f64 = double(float(ctx.f11.f64 - f30.f64));
	// fsubs f7,f30,f9
	ctx.f7.f64 = double(float(f30.f64 - ctx.f9.f64));
	// fsel f6,f7,f30,f9
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : ctx.f9.f64;
	// fdivs f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 / ctx.f6.f64));
	// fsel f4,f5,f5,f29
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f29.f64;
	// fsubs f3,f4,f30
	ctx.f3.f64 = double(float(ctx.f4.f64 - f30.f64));
	// fsel f1,f3,f30,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? f30.f64 : ctx.f4.f64;
	// bl 0x82630290
	ctx.lr = 0x82641FC8;
	sub_82630290(ctx, base);
	// lbz r11,2620(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2620);
	// rlwinm r3,r11,0,29,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826420f8
	if (!cr6.eq) goto loc_826420F8;
	// rlwinm r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82641ff4
	if (!cr6.eq) goto loc_82641FF4;
	// bl 0x822610b0
	ctx.lr = 0x82641FE8;
	sub_822610B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82642044
	if (!cr6.eq) goto loc_82642044;
loc_82641FF4:
	// lwz r11,1888(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1888);
	// lwz r10,1892(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1892);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82642044
	if (!cr6.eq) goto loc_82642044;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82642014;
	sub_822A39C8(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f0,36(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82642038
	if (cr6.lt) goto loc_82642038;
	// li r11,1
	r11.s64 = 1;
loc_82642038:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826420f8
	if (cr6.eq) goto loc_826420F8;
loc_82642044:
	// bl 0x823bbf80
	ctx.lr = 0x82642048;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82642114
	if (!cr6.eq) goto loc_82642114;
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82642114
	if (!cr6.eq) goto loc_82642114;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82642068;
	sub_82388598(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r30,r10,21384
	r30.s64 = ctx.r10.s64 + 21384;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8221cba0
	ctx.lr = 0x8264207C;
	sub_8221CBA0(ctx, base);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82642088;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8221cbf8
	ctx.lr = 0x82642094;
	sub_8221CBF8(ctx, base);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8260c6d8
	ctx.lr = 0x826420B0;
	sub_8260C6D8(ctx, base);
	// fmuls f31,f1,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// lfs f13,864(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 864);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14196(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14196);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// stfs f12,864(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x826420f0
	if (!cr6.lt) goto loc_826420F0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826420EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f30,864(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
loc_826420F0:
	// li r29,1
	r29.s64 = 1;
	// b 0x82642114
	goto loc_82642114;
loc_826420F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82641e80
	ctx.lr = 0x82642114;
	sub_82641E80(ctx, base);
loc_82642114:
	// lfs f0,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8264214c
	if (!cr6.lt) goto loc_8264214C;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f13,f12
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f11,868(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// ble cr6,0x82642180
	if (!cr6.gt) goto loc_82642180;
	// b 0x8264217c
	goto loc_8264217C;
loc_8264214C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82642180
	if (!cr6.gt) goto loc_82642180;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,868(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	f0.f64 = double(temp.f32);
	// fnmsubs f11,f0,f13,f12
	ctx.f11.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// stfs f11,868(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x82642180
	if (!cr6.lt) goto loc_82642180;
loc_8264217C:
	// stfs f31,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
loc_82642180:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826421a8
	if (cr6.eq) goto loc_826421A8;
	// lfs f0,868(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 868);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x826421a8
	if (cr6.eq) goto loc_826421A8;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x826421b4
	goto loc_826421B4;
loc_826421A8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-12460(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12460);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_826421B4:
	// stw r11,-12460(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12460, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640958
	ctx.lr = 0x826421C0;
	sub_82640958(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x82130000
	ctx.lr = 0x826421CC;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x826421D8;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826421DC"))) PPC_WEAK_FUNC(sub_826421DC);
PPC_FUNC_IMPL(__imp__sub_826421DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826421E0"))) PPC_WEAK_FUNC(sub_826421E0);
PPC_FUNC_IMPL(__imp__sub_826421E0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826421F0"))) PPC_WEAK_FUNC(sub_826421F0);
PPC_FUNC_IMPL(__imp__sub_826421F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r11,r11,r4
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r4.s32);
	// add r9,r11,r5
	ctx.r9.u64 = r11.u64 + ctx.r5.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8264220C"))) PPC_WEAK_FUNC(sub_8264220C);
PPC_FUNC_IMPL(__imp__sub_8264220C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642210"))) PPC_WEAK_FUNC(sub_82642210);
PPC_FUNC_IMPL(__imp__sub_82642210) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10868
	ctx.r4.s64 = ctx.r10.s64 + -10868;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642238;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82642250
	if (cr6.eq) goto loc_82642250;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82632f00
	ctx.lr = 0x82642250;
	sub_82632F00(ctx, base);
loc_82642250:
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

__attribute__((alias("__imp__sub_82642264"))) PPC_WEAK_FUNC(sub_82642264);
PPC_FUNC_IMPL(__imp__sub_82642264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642268"))) PPC_WEAK_FUNC(sub_82642268);
PPC_FUNC_IMPL(__imp__sub_82642268) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,4588
	ctx.r10.s64 = r11.s64 + 4588;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82642294;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826422ac
	if (cr6.eq) goto loc_826422AC;
	// bl 0x82130588
	ctx.lr = 0x826422A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826422AC:
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

__attribute__((alias("__imp__sub_826422C4"))) PPC_WEAK_FUNC(sub_826422C4);
PPC_FUNC_IMPL(__imp__sub_826422C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826422C8"))) PPC_WEAK_FUNC(sub_826422C8);
PPC_FUNC_IMPL(__imp__sub_826422C8) {
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
	ctx.lr = 0x826422D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,63
	cr6.compare<int32_t>(ctx.r4.s32, 63, xer);
	// beq cr6,0x826422ec
	if (cr6.eq) goto loc_826422EC;
	// bl 0x826537d0
	ctx.lr = 0x826422E4;
	sub_826537D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826422EC:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x826422F8;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826423ec
	if (!cr6.gt) goto loc_826423EC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264230C;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r9,16324
	ctx.r8.u64 = ctx.r9.u64 | 16324;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r3,164(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 164);
	// bl 0x82204ab8
	ctx.lr = 0x8264232C;
	sub_82204AB8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,-12216(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// bl 0x82203240
	ctx.lr = 0x82642340;
	sub_82203240(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ef5e0
	ctx.lr = 0x82642350;
	sub_821EF5E0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826423c8
	if (!cr6.eq) goto loc_826423C8;
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,-12216(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r27,r11,3,0,28
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82203240
	ctx.lr = 0x82642374;
	sub_82203240(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// lwz r3,-12216(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12216);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x821ef700
	ctx.lr = 0x82642390;
	sub_821EF700(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x82642398;
	sub_82641000(ctx, base);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826423AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640338
	ctx.lr = 0x826423B4;
	sub_82640338(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, ctx.r4.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826423C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x826423D0;
	sub_82641000(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r11,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, r11.u8);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826423EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826423EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826423F8"))) PPC_WEAK_FUNC(sub_826423F8);
PPC_FUNC_IMPL(__imp__sub_826423F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642424;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82642440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,2800(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r6,-23232
	ctx.r5.s64 = ctx.r6.s64 + -23232;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// lwzx r4,r10,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r6,992(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// lwz r11,-12216(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12216);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82642498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2800(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2800);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = r11.s64 + -8;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, ctx.r9.u8);
	// bl 0x82640338
	ctx.lr = 0x826424B8;
	sub_82640338(ctx, base);
	// lwz r8,992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826424CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826424ec
	if (!cr6.gt) goto loc_826424EC;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826424EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826424EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641000
	ctx.lr = 0x826424F4;
	sub_82641000(ctx, base);
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

__attribute__((alias("__imp__sub_8264250C"))) PPC_WEAK_FUNC(sub_8264250C);
PPC_FUNC_IMPL(__imp__sub_8264250C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642510"))) PPC_WEAK_FUNC(sub_82642510);
PPC_FUNC_IMPL(__imp__sub_82642510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8264253C;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82642558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lis r5,3
	ctx.r5.s64 = 196608;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// ori r4,r5,37060
	ctx.r4.u64 = ctx.r5.u64 | 37060;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10028(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10028);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stbx r10,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r10.u8);
	// lwz r8,672(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r9,524(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// stb r9,1012(r31)
	PPC_STORE_U8(r31.u32 + 1012, ctx.r9.u8);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lwz r7,648(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 648);
	// lwz r4,52(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264259C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r5,r31,1008
	ctx.r5.s64 = r31.s64 + 1008;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826425c8
	if (!cr6.eq) goto loc_826425C8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r4,r9,7528
	ctx.r4.s64 = ctx.r9.s64 + 7528;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x826425C8;
	sub_821EE720(ctx, base);
loc_826425C8:
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r11,524(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// beq cr6,0x826425f0
	if (cr6.eq) goto loc_826425F0;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3992
	ctx.r8.s64 = ctx.r10.s64 + 3992;
	// addi r3,r9,7508
	ctx.r3.s64 = ctx.r9.s64 + 7508;
	// b 0x82642600
	goto loc_82642600;
loc_826425F0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3968
	ctx.r8.s64 = ctx.r10.s64 + 3968;
	// addi r3,r9,7488
	ctx.r3.s64 = ctx.r9.s64 + 7488;
loc_82642600:
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x82642608;
	sub_82130000(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264261C;
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

__attribute__((alias("__imp__sub_82642634"))) PPC_WEAK_FUNC(sub_82642634);
PPC_FUNC_IMPL(__imp__sub_82642634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642638"))) PPC_WEAK_FUNC(sub_82642638);
PPC_FUNC_IMPL(__imp__sub_82642638) {
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
	ctx.lr = 0x82642640;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,3
	r11.s64 = 196608;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// ori r8,r11,37060
	ctx.r8.u64 = r11.u64 | 37060;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,-10028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// lwz r11,-12216(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8264267c
	if (!cr6.eq) goto loc_8264267C;
	// lbz r10,524(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// lbz r9,1012(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1012);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826426bc
	if (cr6.eq) goto loc_826426BC;
loc_8264267C:
	// lbz r29,524(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// bl 0x82387b90
	ctx.lr = 0x82642684;
	sub_82387B90(ctx, base);
	// stb r29,1325(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1325, r29.u8);
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,-31280
	ctx.r3.s64 = ctx.r3.s64 + -31280;
	// bl 0x826410d8
	ctx.lr = 0x82642698;
	sub_826410D8(ctx, base);
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
	ctx.lr = 0x826426BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826426BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x826426CC;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r7,48(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x826426fc
	if (cr6.eq) goto loc_826426FC;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x82642718
	if (!cr6.eq) goto loc_82642718;
loc_826426FC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f3,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82207ef0
	ctx.lr = 0x82642718;
	sub_82207EF0(ctx, base);
loc_82642718:
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// li r4,1
	ctx.r4.s64 = 1;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r3,284(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 284);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82642740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,1008(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1008);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82642754
	if (cr6.eq) goto loc_82642754;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x82642754;
	sub_821EC060(ctx, base);
loc_82642754:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x8264275C;
	sub_82216138(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82642764"))) PPC_WEAK_FUNC(sub_82642764);
PPC_FUNC_IMPL(__imp__sub_82642764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642768"))) PPC_WEAK_FUNC(sub_82642768);
PPC_FUNC_IMPL(__imp__sub_82642768) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82642814
	if (cr6.eq) goto loc_82642814;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// beq cr6,0x82642798
	if (cr6.eq) goto loc_82642798;
	// bl 0x826537d0
	ctx.lr = 0x82642794;
	sub_826537D0(ctx, base);
	// b 0x82642870
	goto loc_82642870;
loc_82642798:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826427A4;
	sub_821E6800(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r10,524(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 524);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x821eea90
	ctx.lr = 0x826427BC;
	sub_821EEA90(ctx, base);
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lbz r8,524(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 524);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// beq cr6,0x826427e4
	if (cr6.eq) goto loc_826427E4;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3992
	ctx.r8.s64 = ctx.r10.s64 + 3992;
	// addi r3,r9,7508
	ctx.r3.s64 = ctx.r9.s64 + 7508;
	// b 0x826427f4
	goto loc_826427F4;
loc_826427E4:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r8,r10,3968
	ctx.r8.s64 = ctx.r10.s64 + 3968;
	// addi r3,r9,7488
	ctx.r3.s64 = ctx.r9.s64 + 7488;
loc_826427F4:
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x826427FC;
	sub_82130000(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8264286c
	goto loc_8264286C;
loc_82642814:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82642820;
	sub_821E6800(ctx, base);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x82642828;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642838
	if (cr6.lt) goto loc_82642838;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642838:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r8,r9,16324
	ctx.r8.u64 = ctx.r9.u64 | 16324;
	// lwz r10,-10236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lwz r3,160(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 160);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,2800(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2800, r11.u32);
	// lwz r11,704(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 704);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264286C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264286C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82642870:
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

__attribute__((alias("__imp__sub_82642888"))) PPC_WEAK_FUNC(sub_82642888);
PPC_FUNC_IMPL(__imp__sub_82642888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x826428A4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826428b4
	if (cr6.lt) goto loc_826428B4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826428B4:
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x826429bc
	if (cr6.gt) goto loc_826429BC;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,10452
	r12.s64 = r12.s64 + 10452;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826428EC;
	case 1:
		goto loc_8264290C;
	case 2:
		goto loc_8264292C;
	case 3:
		goto loc_8264294C;
	case 4:
		goto loc_8264296C;
	case 5:
		goto loc_8264298C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,10476(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10476);
	// lwz r19,10508(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10508);
	// lwz r19,10540(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10540);
	// lwz r19,10572(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10572);
	// lwz r19,10604(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10604);
	// lwz r19,10636(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10636);
loc_826428EC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,116(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 116);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264290C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,108(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264292C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,104(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264294C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,112(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264296C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,88(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	// b 0x826429a8
	goto loc_826429A8;
loc_8264298C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r3,84(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
loc_826429A8:
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,704(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 704);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826429BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826429BC:
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

__attribute__((alias("__imp__sub_826429D4"))) PPC_WEAK_FUNC(sub_826429D4);
PPC_FUNC_IMPL(__imp__sub_826429D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826429D8"))) PPC_WEAK_FUNC(sub_826429D8);
PPC_FUNC_IMPL(__imp__sub_826429D8) {
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
	ctx.lr = 0x826429E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// ori r30,r11,16324
	r30.u64 = r11.u64 | 16324;
	// addi r31,r26,672
	r31.s64 = r26.s64 + 672;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r29,96(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// bl 0x82631f88
	ctx.lr = 0x82642A10;
	sub_82631F88(ctx, base);
	// lwz r11,856(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642a20
	if (cr6.lt) goto loc_82642A20;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642A20:
	// lwz r10,1000(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 1000);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r26,1000
	r27.s64 = r26.s64 + 1000;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,-12120(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12120);
	// mulli r5,r6,104
	ctx.r5.s64 = ctx.r6.s64 * 104;
	// lwz r10,788(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// lwzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r8,r9,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// lwz r30,96(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// bl 0x82631f88
	ctx.lr = 0x82642A6C;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r29,r11
	r29.u64 = r11.u64;
	// blt cr6,0x82642a80
	if (cr6.lt) goto loc_82642A80;
	// addi r29,r3,-1
	r29.s64 = ctx.r3.s64 + -1;
loc_82642A80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82642A88;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642a98
	if (cr6.lt) goto loc_82642A98;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642A98:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,688(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 688);
	// lwzx r5,r9,r8
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82642AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82642AD0"))) PPC_WEAK_FUNC(sub_82642AD0);
PPC_FUNC_IMPL(__imp__sub_82642AD0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r30,100(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 100);
	// bl 0x82631f88
	ctx.lr = 0x82642B0C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642b1c
	if (cr6.lt) goto loc_82642B1C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642B1C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,700(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82642B54"))) PPC_WEAK_FUNC(sub_82642B54);
PPC_FUNC_IMPL(__imp__sub_82642B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642B58"))) PPC_WEAK_FUNC(sub_82642B58);
PPC_FUNC_IMPL(__imp__sub_82642B58) {
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
	ctx.lr = 0x82642B60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r25,992
	ctx.r3.s64 = r25.s64 + 992;
	// lwz r11,992(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 992);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82642c98
	if (!cr6.gt) goto loc_82642C98;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82642B90;
	sub_8238EC00(ctx, base);
	// addi r31,r25,672
	r31.s64 = r25.s64 + 672;
	// lwz r30,864(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 864);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82642BA4;
	sub_82631F88(ctx, base);
	// lwz r4,856(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 856);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642bb4
	if (cr6.lt) goto loc_82642BB4;
	// addi r4,r3,-1
	ctx.r4.s64 = ctx.r3.s64 + -1;
loc_82642BB4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642BCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82389800
	ctx.lr = 0x82642BD8;
	sub_82389800(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lwz r28,864(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 864);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// ori r30,r9,16324
	r30.u64 = ctx.r9.u64 | 16324;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// lwz r27,92(r7)
	r27.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// bl 0x82631f88
	ctx.lr = 0x82642C04;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642c14
	if (cr6.lt) goto loc_82642C14;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642C14:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r26,0(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,788(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 788);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r6,r7,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	// lwz r30,92(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// bl 0x82631f88
	ctx.lr = 0x82642C60;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642c70
	if (cr6.lt) goto loc_82642C70;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642C70:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r25,1232
	ctx.r7.s64 = r25.s64 + 1232;
	// lhz r9,16(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 16);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,688(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 688);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82642C98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82642CA4"))) PPC_WEAK_FUNC(sub_82642CA4);
PPC_FUNC_IMPL(__imp__sub_82642CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642CA8"))) PPC_WEAK_FUNC(sub_82642CA8);
PPC_FUNC_IMPL(__imp__sub_82642CA8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r10,16324
	ctx.r9.u64 = ctx.r10.u64 | 16324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r30,80(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// bl 0x82631f88
	ctx.lr = 0x82642CE4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82642cf4
	if (cr6.lt) goto loc_82642CF4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82642CF4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,700(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642D10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82642D2C"))) PPC_WEAK_FUNC(sub_82642D2C);
PPC_FUNC_IMPL(__imp__sub_82642D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642D30"))) PPC_WEAK_FUNC(sub_82642D30);
PPC_FUNC_IMPL(__imp__sub_82642D30) {
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
	ctx.lr = 0x82642D38;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,1000(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 1000);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82642e34
	if (!cr6.gt) goto loc_82642E34;
	// lis r8,3
	ctx.r8.s64 = 196608;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r28,r27,848
	r28.s64 = r27.s64 + 848;
	// addi r31,r27,1084
	r31.s64 = r27.s64 + 1084;
	// ori r26,r8,57220
	r26.u64 = ctx.r8.u64 | 57220;
	// addi r24,r11,7596
	r24.s64 = r11.s64 + 7596;
	// addi r23,r10,7576
	r23.s64 = ctx.r10.s64 + 7576;
	// addi r25,r9,7556
	r25.s64 = ctx.r9.s64 + 7556;
loc_82642D78:
	// addi r30,r29,1
	r30.s64 = r29.s64 + 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,50
	ctx.r4.s64 = 50;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82642D90;
	sub_82137A08(ctx, base);
	// lwz r3,-80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642DA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lwz r6,-80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r11,996(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 996);
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// bl 0x82387b90
	ctx.lr = 0x82642DD0;
	sub_82387B90(ctx, base);
	// add r5,r3,r29
	ctx.r5.u64 = ctx.r3.u64 + r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbzx r4,r5,r26
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + r26.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// beq cr6,0x82642df4
	if (cr6.eq) goto loc_82642DF4;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
loc_82642DF4:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -80);
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r4,1000(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 1000);
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x82642d78
	if (cr6.lt) goto loc_82642D78;
loc_82642E34:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82642E3C"))) PPC_WEAK_FUNC(sub_82642E3C);
PPC_FUNC_IMPL(__imp__sub_82642E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82642E40"))) PPC_WEAK_FUNC(sub_82642E40);
PPC_FUNC_IMPL(__imp__sub_82642E40) {
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
	ctx.lr = 0x82642E48;
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
	ctx.lr = 0x82642E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82642e8c
	if (!cr6.eq) goto loc_82642E8C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643180
	if (cr6.eq) goto loc_82643180;
loc_82642E8C:
	// addi r30,r31,996
	r30.s64 = r31.s64 + 996;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740958
	ctx.lr = 0x82642E98;
	sub_82740958(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823b2078
	ctx.lr = 0x82642EA0;
	sub_823B2078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82642f6c
	if (cr6.eq) goto loc_82642F6C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,1044
	ctx.r3.s64 = r31.s64 + 1044;
	// lwz r4,-6752(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -6752);
	// bl 0x82740730
	ctx.lr = 0x82642EC4;
	sub_82740730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,792(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 792);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82642ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,4176(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r9,7680
	ctx.r4.s64 = ctx.r9.s64 + 7680;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82642EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82640738
	ctx.lr = 0x82642EFC;
	sub_82640738(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r3.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stw r6,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r6.u32);
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stb r29,4385(r31)
	PPC_STORE_U8(r31.u32 + 4385, r29.u8);
	// addi r4,r5,28988
	ctx.r4.s64 = ctx.r5.s64 + 28988;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8262ffe0
	ctx.lr = 0x82642F24;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642F38;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82642F54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82642F68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_82642F6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823b2090
	ctx.lr = 0x82642F74;
	sub_823B2090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643020
	if (cr6.eq) goto loc_82643020;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,7656
	ctx.r4.s64 = ctx.r10.s64 + 7656;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82642F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,4176(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r8,7640
	ctx.r4.s64 = ctx.r8.s64 + 7640;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82642FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r5,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r5.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,29228
	ctx.r4.s64 = ctx.r4.s64 + 29228;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82642FD8;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82642FEC;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264301C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_82643020:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740708
	ctx.lr = 0x82643028;
	sub_82740708(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430d4
	if (cr6.eq) goto loc_826430D4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,7616
	ctx.r4.s64 = ctx.r10.s64 + 7616;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,4176(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4176);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,4176
	ctx.r3.s64 = r31.s64 + 4176;
	// addi r4,r8,7640
	ctx.r4.s64 = ctx.r8.s64 + 7640;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264306C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r5,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, ctx.r5.u32);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r4,29228
	ctx.r4.s64 = ctx.r4.s64 + 29228;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x8264308C;
	sub_8262FFE0(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-10256
	ctx.r4.s64 = r11.s64 + -10256;
	// lwz r3,-10236(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826430A0;
	sub_821F9FB8(ctx, base);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826430BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826430D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826430fc
	goto loc_826430FC;
loc_826430D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82740720
	ctx.lr = 0x826430DC;
	sub_82740720(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430fc
	if (cr6.eq) goto loc_826430FC;
	// lbz r11,4386(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4386);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826430fc
	if (cr6.eq) goto loc_826430FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822d4cc0
	ctx.lr = 0x826430FC;
	sub_822D4CC0(ctx, base);
loc_826430FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82643104;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82643114;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8264311C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643154
	if (cr6.eq) goto loc_82643154;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82643130;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82643140;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82643148;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82643180
	if (!cr6.eq) goto loc_82643180;
loc_82643154:
	// lbz r11,4387(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4387);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82643180
	if (!cr6.eq) goto loc_82643180;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8264317C;
	sub_82289AB0(ctx, base);
	// stb r29,4387(r31)
	PPC_STORE_U8(r31.u32 + 4387, r29.u8);
loc_82643180:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643188"))) PPC_WEAK_FUNC(sub_82643188);
PPC_FUNC_IMPL(__imp__sub_82643188) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82643190;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826431B4;
	sub_821F9FB8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r28,56(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826431C8;
	sub_8238EC00(ctx, base);
	// lwz r4,4172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// bl 0x82388c48
	ctx.lr = 0x826431D0;
	sub_82388C48(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,55
	cr6.compare<int32_t>(r29.s32, 55, xer);
	// beq cr6,0x826432a0
	if (cr6.eq) goto loc_826432A0;
	// cmpwi cr6,r29,56
	cr6.compare<int32_t>(r29.s32, 56, xer);
	// beq cr6,0x82643280
	if (cr6.eq) goto loc_82643280;
	// cmpwi cr6,r29,62
	cr6.compare<int32_t>(r29.s32, 62, xer);
	// beq cr6,0x82643204
	if (cr6.eq) goto loc_82643204;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x826431FC;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643204:
	// lbz r11,4385(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4385);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826434e0
	if (cr6.eq) goto loc_826434E0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264321C;
	sub_821E6800(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r29,r10,16324
	r29.u64 = ctx.r10.u64 | 16324;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r29.u32);
	// lwz r3,24(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,196(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82643248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r6,4164(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4164);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,1048(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 1048);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwzx r11,r3,r29
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// lwz r3,24(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,696(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 696);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643280:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826432A0:
	// lbz r11,4385(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4385);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826434e0
	if (cr6.eq) goto loc_826434E0;
	// bl 0x82387b38
	ctx.lr = 0x826432B0;
	sub_82387B38(ctx, base);
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x826434ec
	if (cr6.gt) goto loc_826434EC;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,13016
	r12.s64 = r12.s64 + 13016;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826432E8;
	case 1:
		goto loc_826433FC;
	case 2:
		goto loc_82643448;
	case 3:
		goto loc_82643494;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13032(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13032);
	// lwz r19,13308(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13308);
	// lwz r19,13384(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13384);
	// lwz r19,13460(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13460);
loc_826432E8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,25
	ctx.r3.s64 = 25;
	// stb r10,4384(r30)
	PPC_STORE_U8(r30.u32 + 4384, ctx.r10.u8);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r10,797(r8)
	PPC_STORE_U8(ctx.r8.u32 + 797, ctx.r10.u8);
	// bl 0x82216138
	ctx.lr = 0x8264330C;
	sub_82216138(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r7,2
	ctx.r7.s64 = 131072;
	// lwz r4,4172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// lis r6,2
	ctx.r6.s64 = 131072;
	// ori r28,r7,44552
	r28.u64 = ctx.r7.u64 | 44552;
	// ori r29,r6,36016
	r29.u64 = ctx.r6.u64 | 36016;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stwx r4,r5,r28
	PPC_STORE_U32(ctx.r5.u32 + r28.u32, ctx.r4.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + r29.u64;
	// bl 0x826583c0
	ctx.lr = 0x8264333C;
	sub_826583C0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r10,4172(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4172);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stwx r10,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, ctx.r10.u32);
	// beq cr6,0x82643388
	if (cr6.eq) goto loc_82643388;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lbz r10,19(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 19);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r11,r8,3
	r11.s64 = ctx.r8.s64 + 196608;
	// addi r11,r11,-28128
	r11.s64 = r11.s64 + -28128;
	// lwz r7,216(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 216);
	// stw r9,216(r11)
	PPC_STORE_U32(r11.u32 + 216, ctx.r9.u32);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// beq cr6,0x82643388
	if (cr6.eq) goto loc_82643388;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82643388;
	sub_821C3048(ctx, base);
loc_82643388:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,-26912
	ctx.r3.s64 = ctx.r3.s64 + -26912;
	// bl 0x8262fff0
	ctx.lr = 0x826433A0;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,3
	ctx.r3.s64 = ctx.r10.s64 + 196608;
	// addi r3,r3,-26672
	ctx.r3.s64 = ctx.r3.s64 + -26672;
	// bl 0x8262fff0
	ctx.lr = 0x826433B8;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r9,3
	ctx.r3.s64 = ctx.r9.s64 + 196608;
	// addi r3,r3,-27632
	ctx.r3.s64 = ctx.r3.s64 + -27632;
	// bl 0x8262fff0
	ctx.lr = 0x826433D0;
	sub_8262FFF0(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r29
	ctx.r3.u64 = ctx.r8.u64 + r29.u64;
	// bl 0x82655550
	ctx.lr = 0x826433E0;
	sub_82655550(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r29
	ctx.r3.u64 = ctx.r7.u64 + r29.u64;
	// bl 0x8265d2b8
	ctx.lr = 0x826433F0;
	sub_8265D2B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826433FC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7732
	ctx.r3.s64 = r11.s64 + 7732;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x82643418;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8264342C;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264343C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643448:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7716
	ctx.r3.s64 = r11.s64 + 7716;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x82643464;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82643478;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82643488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82643494:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,7700
	ctx.r3.s64 = r11.s64 + 7700;
	// addi r31,r10,-17888
	r31.s64 = ctx.r10.s64 + -17888;
	// addi r30,r9,-22108
	r30.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x826434B0;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826434C4;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826434D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_826434E0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826434EC;
	sub_821E6800(ctx, base);
loc_826434EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826434F8"))) PPC_WEAK_FUNC(sub_826434F8);
PPC_FUNC_IMPL(__imp__sub_826434F8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8264355c
	if (!cr6.eq) goto loc_8264355C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 65536;
	// addi r4,r4,16256
	ctx.r4.s64 = ctx.r4.s64 + 16256;
	// lwz r9,68(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r3,440(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 440);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264354C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8264355C:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82643564;
	sub_82216138(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82643574"))) PPC_WEAK_FUNC(sub_82643574);
PPC_FUNC_IMPL(__imp__sub_82643574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643578"))) PPC_WEAK_FUNC(sub_82643578);
PPC_FUNC_IMPL(__imp__sub_82643578) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82643580;
	// addi r31,r1,-192
	r31.s64 = ctx.r1.s64 + -192;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r27,672
	ctx.r3.s64 = r27.s64 + 672;
	// lwz r11,672(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 672);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826435A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r3,2832(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2832);
	// lbz r8,10852(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10852);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82643768
	if (cr6.eq) goto loc_82643768;
	// lbz r11,10096(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10096);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643744
	if (cr6.eq) goto loc_82643744;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-6752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6752);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x82643664
	if (cr6.gt) goto loc_82643664;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,13808
	r12.s64 = r12.s64 + 13808;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82643650;
	case 1:
		goto loc_82643614;
	case 2:
		goto loc_82643628;
	case 3:
		goto loc_8264363C;
	case 4:
		goto loc_82643664;
	case 5:
		goto loc_82643608;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13904(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13904);
	// lwz r19,13844(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13844);
	// lwz r19,13864(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13864);
	// lwz r19,13884(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13884);
	// lwz r19,13924(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13924);
	// lwz r19,13832(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 13832);
loc_82643608:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,9416
	r29.s64 = ctx.r10.s64 + 9416;
	// b 0x8264366c
	goto loc_8264366C;
loc_82643614:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,9368
	r30.s64 = r11.s64 + 9368;
	// addi r29,r10,9064
	r29.s64 = ctx.r10.s64 + 9064;
	// b 0x82643674
	goto loc_82643674;
loc_82643628:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,9012
	r30.s64 = r11.s64 + 9012;
	// addi r29,r10,8688
	r29.s64 = ctx.r10.s64 + 8688;
	// b 0x82643674
	goto loc_82643674;
loc_8264363C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,8644
	r30.s64 = r11.s64 + 8644;
	// addi r29,r10,8352
	r29.s64 = ctx.r10.s64 + 8352;
	// b 0x82643674
	goto loc_82643674;
loc_82643650:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r30,r11,8308
	r30.s64 = r11.s64 + 8308;
	// addi r29,r10,8032
	r29.s64 = ctx.r10.s64 + 8032;
	// b 0x82643674
	goto loc_82643674;
loc_82643664:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,7808
	r29.s64 = ctx.r10.s64 + 7808;
loc_8264366C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r30,r11,7764
	r30.s64 = r11.s64 + 7764;
loc_82643674:
	// lwz r11,0(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwu r11,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r1.u32 = ea;
	// addi r26,r1,96
	r26.s64 = ctx.r1.s64 + 96;
	// stb r28,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r28.u8);
	// bl 0x823de3a8
	ctx.lr = 0x82643690;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821e4958
	ctx.lr = 0x826436A0;
	sub_821E4958(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r25,r10,7744
	r25.s64 = ctx.r10.s64 + 7744;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826436BC;
	sub_822183B0(ctx, base);
	// stb r28,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r28.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823de3a8
	ctx.lr = 0x826436C8;
	sub_823DE3A8(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821e4958
	ctx.lr = 0x826436D8;
	sub_821E4958(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r30,r9,-3200
	r30.s64 = ctx.r9.s64 + -3200;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x826436F0;
	sub_822183B0(ctx, base);
	// lis r8,-32156
	ctx.r8.s64 = -2107375616;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r8,13560
	ctx.r4.s64 = ctx.r8.s64 + 13560;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8264370C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// stb r28,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r28.u8);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r3,r27,1248
	ctx.r3.s64 = r27.s64 + 1248;
	// ld r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82634ec8
	ctx.lr = 0x8264373C;
	sub_82634EC8(ctx, base);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
loc_82643744:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
loc_82643768:
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82643770;
	sub_82216138(ctx, base);
	// addi r1,r31,192
	ctx.r1.s64 = r31.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82643778"))) PPC_WEAK_FUNC(sub_82643778);
PPC_FUNC_IMPL(__imp__sub_82643778) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633dc8
	ctx.lr = 0x82643798;
	sub_82633DC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r10,r11,9564
	ctx.r10.s64 = r11.s64 + 9564;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,27808
	ctx.r4.s64 = ctx.r9.s64 + 27808;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b68
	ctx.lr = 0x826437BC;
	sub_82633B68(ctx, base);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_826437FC"))) PPC_WEAK_FUNC(sub_826437FC);
PPC_FUNC_IMPL(__imp__sub_826437FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643800"))) PPC_WEAK_FUNC(sub_82643800);
PPC_FUNC_IMPL(__imp__sub_82643800) {
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
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82643824;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8264382C;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643844
	if (cr6.eq) goto loc_82643844;
	// bl 0x82130588
	ctx.lr = 0x82643840;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82643844:
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

__attribute__((alias("__imp__sub_8264385C"))) PPC_WEAK_FUNC(sub_8264385C);
PPC_FUNC_IMPL(__imp__sub_8264385C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643860"))) PPC_WEAK_FUNC(sub_82643860);
PPC_FUNC_IMPL(__imp__sub_82643860) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643888;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826438A4;
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

__attribute__((alias("__imp__sub_826438B8"))) PPC_WEAK_FUNC(sub_826438B8);
PPC_FUNC_IMPL(__imp__sub_826438B8) {
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
	// addi r3,r31,5700
	ctx.r3.s64 = r31.s64 + 5700;
	// bl 0x821d2028
	ctx.lr = 0x826438D8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5696
	ctx.r3.s64 = r31.s64 + 5696;
	// bl 0x821d2028
	ctx.lr = 0x826438E0;
	sub_821D2028(ctx, base);
	// addi r3,r31,5692
	ctx.r3.s64 = r31.s64 + 5692;
	// bl 0x821d2028
	ctx.lr = 0x826438E8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5688
	ctx.r3.s64 = r31.s64 + 5688;
	// bl 0x821d2028
	ctx.lr = 0x826438F0;
	sub_821D2028(ctx, base);
	// addi r3,r31,5680
	ctx.r3.s64 = r31.s64 + 5680;
	// bl 0x821d2028
	ctx.lr = 0x826438F8;
	sub_821D2028(ctx, base);
	// addi r3,r31,5676
	ctx.r3.s64 = r31.s64 + 5676;
	// bl 0x821d2028
	ctx.lr = 0x82643900;
	sub_821D2028(ctx, base);
	// addi r3,r31,5672
	ctx.r3.s64 = r31.s64 + 5672;
	// bl 0x821d2028
	ctx.lr = 0x82643908;
	sub_821D2028(ctx, base);
	// addi r3,r31,5668
	ctx.r3.s64 = r31.s64 + 5668;
	// bl 0x821d2028
	ctx.lr = 0x82643910;
	sub_821D2028(ctx, base);
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// bl 0x821d2028
	ctx.lr = 0x82643918;
	sub_821D2028(ctx, base);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// bl 0x82633b00
	ctx.lr = 0x82643920;
	sub_82633B00(ctx, base);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// bl 0x82633b00
	ctx.lr = 0x82643928;
	sub_82633B00(ctx, base);
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// bl 0x82233ba0
	ctx.lr = 0x82643930;
	sub_82233BA0(ctx, base);
	// addi r3,r31,3840
	ctx.r3.s64 = r31.s64 + 3840;
	// bl 0x82633b00
	ctx.lr = 0x82643938;
	sub_82633B00(ctx, base);
	// addi r3,r31,3648
	ctx.r3.s64 = r31.s64 + 3648;
	// bl 0x82633b00
	ctx.lr = 0x82643940;
	sub_82633B00(ctx, base);
	// addi r30,r31,2832
	r30.s64 = r31.s64 + 2832;
	// addi r3,r30,468
	ctx.r3.s64 = r30.s64 + 468;
	// bl 0x82726128
	ctx.lr = 0x8264394C;
	sub_82726128(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82643954;
	sub_82633B00(ctx, base);
	// addi r3,r31,2624
	ctx.r3.s64 = r31.s64 + 2624;
	// bl 0x82633b00
	ctx.lr = 0x8264395C;
	sub_82633B00(ctx, base);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// bl 0x82633b00
	ctx.lr = 0x82643964;
	sub_82633B00(ctx, base);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// bl 0x82633b00
	ctx.lr = 0x8264396C;
	sub_82633B00(ctx, base);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// bl 0x82633b00
	ctx.lr = 0x82643974;
	sub_82633B00(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x82633b00
	ctx.lr = 0x8264397C;
	sub_82633B00(ctx, base);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// bl 0x82633b00
	ctx.lr = 0x82643984;
	sub_82633B00(ctx, base);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82633b00
	ctx.lr = 0x8264398C;
	sub_82633B00(ctx, base);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// bl 0x82633b00
	ctx.lr = 0x82643994;
	sub_82633B00(ctx, base);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// bl 0x82633b00
	ctx.lr = 0x8264399C;
	sub_82633B00(ctx, base);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// bl 0x82633b00
	ctx.lr = 0x826439A4;
	sub_82633B00(ctx, base);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// bl 0x82633b00
	ctx.lr = 0x826439AC;
	sub_82633B00(ctx, base);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// bl 0x82633b00
	ctx.lr = 0x826439B4;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x826439BC;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826439C4;
	sub_82633B00(ctx, base);
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

__attribute__((alias("__imp__sub_826439DC"))) PPC_WEAK_FUNC(sub_826439DC);
PPC_FUNC_IMPL(__imp__sub_826439DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826439E0"))) PPC_WEAK_FUNC(sub_826439E0);
PPC_FUNC_IMPL(__imp__sub_826439E0) {
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
	ctx.lr = 0x826439E8;
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643A08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// cmpwi cr6,r29,63
	cr6.compare<int32_t>(r29.s32, 63, xer);
	// bne cr6,0x82643a54
	if (!cr6.eq) goto loc_82643A54;
	// bl 0x823bbf80
	ctx.lr = 0x82643A20;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643a54
	if (cr6.eq) goto loc_82643A54;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb498
	ctx.lr = 0x82643A38;
	sub_823BB498(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// addi r3,r11,10736
	ctx.r3.s64 = r11.s64 + 10736;
	// bl 0x82214168
	ctx.lr = 0x82643A48;
	sub_82214168(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82643A54:
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82643a90
	if (cr6.eq) goto loc_82643A90;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643A74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643a90
	if (cr6.eq) goto loc_82643A90;
	// lwz r11,216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 216);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82643a98
	if (!cr6.eq) goto loc_82643A98;
loc_82643A90:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r31,436(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 436);
loc_82643A98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643AB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82643b40
	if (cr6.eq) goto loc_82643B40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82643afc
	if (!cr6.eq) goto loc_82643AFC;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r10,436(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 436);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x82643b40
	if (!cr6.eq) goto loc_82643B40;
loc_82643AFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,276(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643B18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643B30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82643b44
	if (cr6.eq) goto loc_82643B44;
loc_82643B40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82643B44:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82643B4C"))) PPC_WEAK_FUNC(sub_82643B4C);
PPC_FUNC_IMPL(__imp__sub_82643B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643B50"))) PPC_WEAK_FUNC(sub_82643B50);
PPC_FUNC_IMPL(__imp__sub_82643B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82643B58;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lhz r31,72(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82643ba0
	if (!cr6.gt) goto loc_82643BA0;
	// li r30,0
	r30.s64 = 0;
loc_82643B78:
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82643B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82643b78
	if (!cr0.eq) goto loc_82643B78;
loc_82643BA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641d20
	ctx.lr = 0x82643BA8;
	sub_82641D20(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643BB4"))) PPC_WEAK_FUNC(sub_82643BB4);
PPC_FUNC_IMPL(__imp__sub_82643BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643BB8"))) PPC_WEAK_FUNC(sub_82643BB8);
PPC_FUNC_IMPL(__imp__sub_82643BB8) {
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
	ctx.lr = 0x82643BC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BCC;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r29,r29,14048
	r29.s64 = r29.s64 + 14048;
loc_82643BDC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BE4;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643BF4;
	sub_82641CC8(ctx, base);
	// addi r11,r31,2672
	r11.s64 = r31.s64 + 2672;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x82643c94
	if (cr6.eq) goto loc_82643C94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C08;
	sub_82641CC8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C14;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C2C;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x82643c54
	if (cr6.eq) goto loc_82643C54;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82643c84
	if (cr6.eq) goto loc_82643C84;
loc_82643C54:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82643C6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,744(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82643C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82643C84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82643C8C;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82643bdc
	if (!cr6.eq) goto loc_82643BDC;
loc_82643C94:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82643C9C"))) PPC_WEAK_FUNC(sub_82643C9C);
PPC_FUNC_IMPL(__imp__sub_82643C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643CA0"))) PPC_WEAK_FUNC(sub_82643CA0);
PPC_FUNC_IMPL(__imp__sub_82643CA0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82643CA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633dc8
	ctx.lr = 0x82643CB8;
	sub_82633DC8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,6644
	ctx.r9.s64 = r11.s64 + 6644;
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
	// addi r28,r31,272
	r28.s64 = r31.s64 + 272;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826340f0
	ctx.lr = 0x82643CE4;
	sub_826340F0(ctx, base);
	// addi r29,r31,464
	r29.s64 = r31.s64 + 464;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633930
	ctx.lr = 0x82643CF4;
	sub_82633930(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// addi r7,r8,3236
	ctx.r7.s64 = ctx.r8.s64 + 3236;
	// addi r27,r31,640
	r27.s64 = r31.s64 + 640;
	// stw r7,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r7.u32);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r6,28052
	ctx.r4.s64 = ctx.r6.s64 + 28052;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633b68
	ctx.lr = 0x82643D18;
	sub_82633B68(ctx, base);
	// stb r30,896(r31)
	PPC_STORE_U8(r31.u32 + 896, r30.u8);
	// stw r30,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r30.u32);
	// addi r11,r31,532
	r11.s64 = r31.s64 + 532;
	// lwz r10,532(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 532);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r26,r4,19856
	r26.s64 = ctx.r4.s64 + 19856;
	// addi r4,r3,10408
	ctx.r4.s64 = ctx.r3.s64 + 10408;
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lhz r11,536(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 536);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,536(r31)
	PPC_STORE_U16(r31.u32 + 536, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,532(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 532);
	// lhz r11,536(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 536);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,536(r31)
	PPC_STORE_U16(r31.u32 + 536, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// stfs f0,864(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// stfs f0,868(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// stb r30,844(r31)
	PPC_STORE_U8(r31.u32 + 844, r30.u8);
	// stw r30,872(r31)
	PPC_STORE_U32(r31.u32 + 872, r30.u32);
	// stw r30,876(r31)
	PPC_STORE_U32(r31.u32 + 876, r30.u32);
	// stw r30,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r30.u32);
	// bl 0x82144a20
	ctx.lr = 0x82643DA4;
	sub_82144A20(ctx, base);
	// stw r3,884(r31)
	PPC_STORE_U32(r31.u32 + 884, ctx.r3.u32);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r6,10372
	ctx.r4.s64 = ctx.r6.s64 + 10372;
	// bl 0x82144a20
	ctx.lr = 0x82643DB8;
	sub_82144A20(ctx, base);
	// stw r3,888(r31)
	PPC_STORE_U32(r31.u32 + 888, ctx.r3.u32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r5,10344
	ctx.r4.s64 = ctx.r5.s64 + 10344;
	// bl 0x82144a20
	ctx.lr = 0x82643DCC;
	sub_82144A20(ctx, base);
	// stw r3,892(r31)
	PPC_STORE_U32(r31.u32 + 892, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82643DDC"))) PPC_WEAK_FUNC(sub_82643DDC);
PPC_FUNC_IMPL(__imp__sub_82643DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643DE0"))) PPC_WEAK_FUNC(sub_82643DE0);
PPC_FUNC_IMPL(__imp__sub_82643DE0) {
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
	// bl 0x82641d90
	ctx.lr = 0x82643E00;
	sub_82641D90(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643e18
	if (cr6.eq) goto loc_82643E18;
	// bl 0x82130588
	ctx.lr = 0x82643E14;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82643E18:
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

__attribute__((alias("__imp__sub_82643E30"))) PPC_WEAK_FUNC(sub_82643E30);
PPC_FUNC_IMPL(__imp__sub_82643E30) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643E58;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643e70
	if (cr6.eq) goto loc_82643E70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82632f00
	ctx.lr = 0x82643E70;
	sub_82632F00(ctx, base);
loc_82643E70:
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

__attribute__((alias("__imp__sub_82643E84"))) PPC_WEAK_FUNC(sub_82643E84);
PPC_FUNC_IMPL(__imp__sub_82643E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82643E88"))) PPC_WEAK_FUNC(sub_82643E88);
PPC_FUNC_IMPL(__imp__sub_82643E88) {
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
	ctx.lr = 0x82643E90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	ctx.lr = 0x82643EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644068
	if (cr6.eq) goto loc_82644068;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82643EC4;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// lbz r10,36(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 36);
	// bne cr6,0x82643f0c
	if (!cr6.eq) goto loc_82643F0C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// addi r4,r11,29484
	ctx.r4.s64 = r11.s64 + 29484;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82643EF4;
	sub_8262FFE0(ctx, base);
	// lwz r10,640(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82643fc0
	goto loc_82643FC0;
loc_82643F0C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82643f2c
	if (!cr6.eq) goto loc_82643F2C;
	// lwz r11,640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82643fc0
	goto loc_82643FC0;
loc_82643F2C:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// bne cr6,0x82643f74
	if (!cr6.eq) goto loc_82643F74;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643f5c
	if (cr6.eq) goto loc_82643F5C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,28052
	ctx.r4.s64 = ctx.r10.s64 + 28052;
	// lwz r11,28892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28892);
	// b 0x82643f9c
	goto loc_82643F9C;
loc_82643F5C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,28052
	ctx.r4.s64 = ctx.r10.s64 + 28052;
	// lwz r11,28888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28888);
	// b 0x82643f9c
	goto loc_82643F9C;
loc_82643F74:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82643f88
	if (cr6.eq) goto loc_82643F88;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r11,28892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28892);
	// b 0x82643f90
	goto loc_82643F90;
loc_82643F88:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r11,28888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28888);
loc_82643F90:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r10,29300
	ctx.r4.s64 = ctx.r10.s64 + 29300;
loc_82643F9C:
	// stw r11,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r11.u32);
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82643FAC;
	sub_8262FFE0(ctx, base);
	// lwz r9,640(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82643FC0:
	// bctrl 
	ctx.lr = 0x82643FC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82643FD8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82644068
	if (cr6.eq) goto loc_82644068;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r11,-10292
	r29.s64 = r11.s64 + -10292;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82643FF8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82644008;
	sub_825ED480(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bne cr6,0x8264402c
	if (!cr6.eq) goto loc_8264402C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2736
	ctx.r4.s64 = ctx.r10.s64 + -2736;
	// b 0x82644034
	goto loc_82644034;
loc_8264402C:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,10448
	ctx.r4.s64 = ctx.r10.s64 + 10448;
loc_82644034:
	// bl 0x82218310
	ctx.lr = 0x82644038;
	sub_82218310(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-13276
	ctx.r4.s64 = ctx.r9.s64 + -13276;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8264404C;
	sub_827227B8(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,10436
	ctx.r4.s64 = ctx.r10.s64 + 10436;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x82644068;
	sub_82722678(ctx, base);
loc_82644068:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82632f78
	ctx.lr = 0x82644070;
	sub_82632F78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82644084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826440a0
	if (!cr6.eq) goto loc_826440A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x826440A0;
	sub_8220F040(ctx, base);
loc_826440A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826440A8"))) PPC_WEAK_FUNC(sub_826440A8);
PPC_FUNC_IMPL(__imp__sub_826440A8) {
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
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// bl 0x8221fbc8
	ctx.lr = 0x826440C8;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,1424
	ctx.r3.s64 = r31.s64 + 1424;
	// bl 0x8221fbc8
	ctx.lr = 0x826440D0;
	sub_8221FBC8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,1376
	ctx.r3.s64 = r31.s64 + 1376;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// stw r10,1376(r31)
	PPC_STORE_U32(r31.u32 + 1376, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826440E4;
	sub_821D2028(ctx, base);
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// bl 0x821d2028
	ctx.lr = 0x826440EC;
	sub_821D2028(ctx, base);
	// lhz r9,1050(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 1050);
	// addi r30,r31,1040
	r30.s64 = r31.s64 + 1040;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644104
	if (cr6.eq) goto loc_82644104;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644104;
	sub_82130588(ctx, base);
loc_82644104:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264410C;
	sub_821D2028(ctx, base);
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// addi r30,r31,1016
	r30.s64 = r31.s64 + 1016;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644124
	if (cr6.eq) goto loc_82644124;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644124;
	sub_82130588(ctx, base);
loc_82644124:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264412C;
	sub_821D2028(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644144
	if (cr6.eq) goto loc_82644144;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644144;
	sub_82130588(ctx, base);
loc_82644144:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264414C;
	sub_821D2028(ctx, base);
	// lhz r11,986(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 986);
	// addi r30,r31,976
	r30.s64 = r31.s64 + 976;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644164
	if (cr6.eq) goto loc_82644164;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644164;
	sub_82130588(ctx, base);
loc_82644164:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264416C;
	sub_821D2028(ctx, base);
	// lhz r11,962(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 962);
	// addi r30,r31,952
	r30.s64 = r31.s64 + 952;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644184
	if (cr6.eq) goto loc_82644184;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644184;
	sub_82130588(ctx, base);
loc_82644184:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8264418C;
	sub_821D2028(ctx, base);
	// lhz r11,938(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 938);
	// addi r30,r31,928
	r30.s64 = r31.s64 + 928;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826441a4
	if (cr6.eq) goto loc_826441A4;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x826441A4;
	sub_82130588(ctx, base);
loc_826441A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x826441AC;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826441B4;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826441CC"))) PPC_WEAK_FUNC(sub_826441CC);
PPC_FUNC_IMPL(__imp__sub_826441CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826441D0"))) PPC_WEAK_FUNC(sub_826441D0);
PPC_FUNC_IMPL(__imp__sub_826441D0) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r11,-25064
	ctx.r5.s64 = r11.s64 + -25064;
	// addi r4,r10,11264
	ctx.r4.s64 = ctx.r10.s64 + 11264;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644208;
	sub_82654318(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,10460
	ctx.r6.s64 = ctx.r7.s64 + 10460;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stb r5,245(r31)
	PPC_STORE_U8(r31.u32 + 245, ctx.r5.u8);
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

__attribute__((alias("__imp__sub_82644258"))) PPC_WEAK_FUNC(sub_82644258);
PPC_FUNC_IMPL(__imp__sub_82644258) {
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
	// bl 0x82653b30
	ctx.lr = 0x82644270;
	sub_82653B30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1008(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
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

__attribute__((alias("__imp__sub_82644290"))) PPC_WEAK_FUNC(sub_82644290);
PPC_FUNC_IMPL(__imp__sub_82644290) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,12896
	ctx.r4.s64 = ctx.r9.s64 + 12896;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28964
	ctx.r8.s64 = r11.s64 + 28964;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x826442D0;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r6,r8,12092
	ctx.r6.s64 = ctx.r8.s64 + 12092;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r4,r5,7460
	ctx.r4.s64 = ctx.r5.s64 + 7460;
	// lwz r11,-12216(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12216);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r10,r10,11
	ctx.r10.s64 = ctx.r10.s64 + 11;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stb r30,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, r30.u8);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x82634b60
	ctx.lr = 0x82644314;
	sub_82634B60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r30,480(r31)
	PPC_STORE_U8(r31.u32 + 480, r30.u8);
	// lis r8,-32156
	ctx.r8.s64 = -2107375616;
	// stb r9,2804(r31)
	PPC_STORE_U8(r31.u32 + 2804, ctx.r9.u8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r30,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r30.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,4464
	ctx.r4.s64 = ctx.r8.s64 + 4464;
	// bl 0x821c2f90
	ctx.lr = 0x82644338;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82644348:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82644348
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82644348;
	// addi r10,r31,888
	ctx.r10.s64 = r31.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264436C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264436c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264436C;
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

__attribute__((alias("__imp__sub_8264439C"))) PPC_WEAK_FUNC(sub_8264439C);
PPC_FUNC_IMPL(__imp__sub_8264439C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826443A0"))) PPC_WEAK_FUNC(sub_826443A0);
PPC_FUNC_IMPL(__imp__sub_826443A0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r9,13732
	ctx.r4.s64 = ctx.r9.s64 + 13732;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// addi r8,r11,28100
	ctx.r8.s64 = r11.s64 + 28100;
	// addi r5,r10,13720
	ctx.r5.s64 = ctx.r10.s64 + 13720;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x826443DC;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r8,12916
	ctx.r5.s64 = ctx.r8.s64 + 12916;
	// addi r3,r6,-23232
	ctx.r3.s64 = ctx.r6.s64 + -23232;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,9
	r11.s64 = 9;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82644430"))) PPC_WEAK_FUNC(sub_82644430);
PPC_FUNC_IMPL(__imp__sub_82644430) {
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
	ctx.lr = 0x82644438;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,14672
	ctx.r4.s64 = ctx.r9.s64 + 14672;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644468;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r7,r8,13868
	ctx.r7.s64 = ctx.r8.s64 + 13868;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,13840
	ctx.r4.s64 = ctx.r6.s64 + 13840;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264448C;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,13824
	ctx.r4.s64 = ctx.r4.s64 + 13824;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444A4;
	sub_82633D40(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,13804
	ctx.r4.s64 = ctx.r3.s64 + 13804;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444BC;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13784
	ctx.r4.s64 = r11.s64 + 13784;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444D4;
	sub_82633D40(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r26,r31,1824
	r26.s64 = r31.s64 + 1824;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13764
	ctx.r4.s64 = ctx.r10.s64 + 13764;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x826444EC;
	sub_82633D40(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r25,r31,2032
	r25.s64 = r31.s64 + 2032;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,13744
	ctx.r4.s64 = ctx.r9.s64 + 13744;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x82644504;
	sub_82633D40(ctx, base);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264451C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
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
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826445BC"))) PPC_WEAK_FUNC(sub_826445BC);
PPC_FUNC_IMPL(__imp__sub_826445BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826445C0"))) PPC_WEAK_FUNC(sub_826445C0);
PPC_FUNC_IMPL(__imp__sub_826445C0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13840
	ctx.r4.s64 = ctx.r9.s64 + 13840;
	// addi r8,r11,24348
	ctx.r8.s64 = r11.s64 + 24348;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,50
	ctx.r6.s64 = 50;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826445FC;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,14700
	ctx.r7.s64 = ctx.r8.s64 + 14700;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1004(r31)
	PPC_STORE_U16(r31.u32 + 1004, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1006(r31)
	PPC_STORE_U16(r31.u32 + 1006, r11.u16);
	// stw r11,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r11.u32);
	// sth r11,1012(r31)
	PPC_STORE_U16(r31.u32 + 1012, r11.u16);
	// sth r11,1014(r31)
	PPC_STORE_U16(r31.u32 + 1014, r11.u16);
	// stw r11,1016(r31)
	PPC_STORE_U32(r31.u32 + 1016, r11.u32);
	// sth r11,1020(r31)
	PPC_STORE_U16(r31.u32 + 1020, r11.u16);
	// sth r11,1022(r31)
	PPC_STORE_U16(r31.u32 + 1022, r11.u16);
	// stw r11,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r11.u32);
	// sth r11,1028(r31)
	PPC_STORE_U16(r31.u32 + 1028, r11.u16);
	// sth r11,1030(r31)
	PPC_STORE_U16(r31.u32 + 1030, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x82644658;
	sub_826347F0(ctx, base);
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

__attribute__((alias("__imp__sub_82644670"))) PPC_WEAK_FUNC(sub_82644670);
PPC_FUNC_IMPL(__imp__sub_82644670) {
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
	// lhz r11,1030(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1030);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644698
	if (cr6.eq) goto loc_82644698;
	// lwz r3,1024(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// bl 0x82130588
	ctx.lr = 0x82644698;
	sub_82130588(ctx, base);
loc_82644698:
	// lhz r11,1022(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1022);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446ac
	if (cr6.eq) goto loc_826446AC;
	// lwz r3,1016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1016);
	// bl 0x82130588
	ctx.lr = 0x826446AC;
	sub_82130588(ctx, base);
loc_826446AC:
	// lhz r11,1014(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1014);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446c0
	if (cr6.eq) goto loc_826446C0;
	// lwz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// bl 0x82130588
	ctx.lr = 0x826446C0;
	sub_82130588(ctx, base);
loc_826446C0:
	// lhz r11,1006(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1006);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826446d4
	if (cr6.eq) goto loc_826446D4;
	// lwz r3,1000(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x826446D4;
	sub_82130588(ctx, base);
loc_826446D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x826446DC;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_826446F0"))) PPC_WEAK_FUNC(sub_826446F0);
PPC_FUNC_IMPL(__imp__sub_826446F0) {
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
	ctx.lr = 0x826446F8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,103
	ctx.r10.s64 = 103;
	// addi r9,r11,5392
	ctx.r9.s64 = r11.s64 + 5392;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r24,r31,1008
	r24.s64 = r31.s64 + 1008;
	// addi r23,r31,1000
	r23.s64 = r31.s64 + 1000;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12440(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12440);
	// bl 0x8238e3a8
	ctx.lr = 0x8264473C;
	sub_8238E3A8(ctx, base);
	// lhz r6,1004(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 1004);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82644894
	if (cr6.eq) goto loc_82644894;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r31,1016
	r29.s64 = r31.s64 + 1016;
	// addi r28,r31,1024
	r28.s64 = r31.s64 + 1024;
	// li r30,0
	r30.s64 = 0;
	// addi r22,r11,5568
	r22.s64 = r11.s64 + 5568;
	// addi r25,r10,3998
	r25.s64 = ctx.r10.s64 + 3998;
loc_82644768:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bgt cr6,0x82644840
	if (cr6.gt) goto loc_82644840;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8264477C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82644798
	if (cr6.eq) goto loc_82644798;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x82644790;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8264479c
	goto loc_8264479C;
loc_82644798:
	// li r27,0
	r27.s64 = 0;
loc_8264479C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x826447A8;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x826447B8;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826447d4
	if (cr6.eq) goto loc_826447D4;
	// stw r22,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r22.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x826447D0;
	sub_826311F8(ctx, base);
	// b 0x826447d8
	goto loc_826447D8;
loc_826447D4:
	// li r27,0
	r27.s64 = 0;
loc_826447D8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x826447E4;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r6,r30,r10
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r11,r30,r5
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r5.u32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r30,r7
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
loc_82644840:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwzx r4,r30,r10
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82644860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r3,r30,r7
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r7.u32);
	// lwzx r4,r30,r6
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82644880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,1004(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 1004);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x82644768
	if (cr6.lt) goto loc_82644768;
loc_82644894:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8264489C"))) PPC_WEAK_FUNC(sub_8264489C);
PPC_FUNC_IMPL(__imp__sub_8264489C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826448A0"))) PPC_WEAK_FUNC(sub_826448A0);
PPC_FUNC_IMPL(__imp__sub_826448A0) {
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
	ctx.lr = 0x826448A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r11,-12120
	r31.s64 = r11.s64 + -12120;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// addi r4,r7,13824
	ctx.r4.s64 = ctx.r7.s64 + 13824;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// lhz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826448E0;
	sub_82654318(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// addi r5,r6,15508
	ctx.r5.s64 = ctx.r6.s64 + 15508;
	// addi r25,r30,992
	r25.s64 = r30.s64 + 992;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// mr r27,r29
	r27.u64 = r29.u64;
	// stw r29,992(r30)
	PPC_STORE_U32(r30.u32 + 992, r29.u32);
	// sth r29,996(r30)
	PPC_STORE_U16(r30.u32 + 996, r29.u16);
	// sth r29,998(r30)
	PPC_STORE_U16(r30.u32 + 998, r29.u16);
	// stw r29,1000(r30)
	PPC_STORE_U32(r30.u32 + 1000, r29.u32);
	// sth r29,1004(r30)
	PPC_STORE_U16(r30.u32 + 1004, r29.u16);
	// sth r29,1006(r30)
	PPC_STORE_U16(r30.u32 + 1006, r29.u16);
	// stw r29,1008(r30)
	PPC_STORE_U32(r30.u32 + 1008, r29.u32);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82644974
	if (cr6.eq) goto loc_82644974;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_82644924:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8264492C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264494c
	if (cr6.eq) goto loc_8264494C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r28,r11
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x82644944;
	sub_82633D40(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x82644950
	goto loc_82644950;
loc_8264494C:
	// mr r26,r29
	r26.u64 = r29.u64;
loc_82644950:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8262e420
	ctx.lr = 0x8264495C;
	sub_8262E420(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// addi r28,r28,104
	r28.s64 = r28.s64 + 104;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82644924
	if (cr6.lt) goto loc_82644924;
loc_82644974:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82644980"))) PPC_WEAK_FUNC(sub_82644980);
PPC_FUNC_IMPL(__imp__sub_82644980) {
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
	ctx.lr = 0x82644988;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r28,r26,848
	r28.s64 = r26.s64 + 848;
	// lwz r3,848(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 848);
	// bl 0x82130588
	ctx.lr = 0x8264499C;
	sub_82130588(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// addi r27,r26,1000
	r27.s64 = r26.s64 + 1000;
	// stw r31,848(r26)
	PPC_STORE_U32(r26.u32 + 848, r31.u32);
	// sth r31,852(r26)
	PPC_STORE_U16(r26.u32 + 852, r31.u16);
	// sth r31,854(r26)
	PPC_STORE_U16(r26.u32 + 854, r31.u16);
	// lwz r9,1000(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 1000);
	// lhz r11,1004(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 1004);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826449e4
	if (cr6.eq) goto loc_826449E4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826449D0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826449d0
	if (!cr6.eq) goto loc_826449D0;
loc_826449E4:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r24,r11,-12120
	r24.s64 = r11.s64 + -12120;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r7.u16);
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644ad4
	if (cr6.eq) goto loc_82644AD4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r29,r31
	r29.u64 = r31.u64;
	// mr r25,r31
	r25.u64 = r31.u64;
	// li r21,118
	r21.s64 = 118;
	// lis r22,-32115
	r22.s64 = -2104688640;
	// addi r20,r11,-19152
	r20.s64 = r11.s64 + -19152;
	// addi r23,r10,3924
	r23.s64 = ctx.r10.s64 + 3924;
loc_82644A2C:
	// lhz r11,996(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 996);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x82644ad4
	if (!cr6.lt) goto loc_82644AD4;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwzx r30,r25,r11
	r30.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82644abc
	if (cr6.eq) goto loc_82644ABC;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r21,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r21.u8);
	// sth r31,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r31.u16);
	// lwz r3,-12440(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -12440);
	// bl 0x8238dd80
	ctx.lr = 0x82644A60;
	sub_8238DD80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82644ab4
	if (cr6.eq) goto loc_82644AB4;
	// lwz r11,992(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 992);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82644A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x82644A94;
	sub_8262E420(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r31,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r31.u32);
	// lwz r11,992(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 992);
	// lwzx r30,r11,r29
	r30.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x8262e420
	ctx.lr = 0x82644AB0;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_82644AB4:
	// lhz r9,4(r24)
	ctx.r9.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
loc_82644ABC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// clrlwi r11,r9,16
	r11.u64 = ctx.r9.u32 & 0xFFFF;
	// addi r25,r25,104
	r25.s64 = r25.s64 + 104;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82644a2c
	if (cr6.lt) goto loc_82644A2C;
loc_82644AD4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82644ADC"))) PPC_WEAK_FUNC(sub_82644ADC);
PPC_FUNC_IMPL(__imp__sub_82644ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644AE0"))) PPC_WEAK_FUNC(sub_82644AE0);
PPC_FUNC_IMPL(__imp__sub_82644AE0) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644B1C;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r6,r8,16428
	ctx.r6.s64 = ctx.r8.s64 + 16428;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r4,r7,16392
	ctx.r4.s64 = ctx.r7.s64 + 16392;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B3C;
	sub_82633D40(ctx, base);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// addi r3,r31,1200
	ctx.r3.s64 = r31.s64 + 1200;
	// addi r4,r5,16364
	ctx.r4.s64 = ctx.r5.s64 + 16364;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B50;
	sub_82633D40(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// addi r4,r4,16336
	ctx.r4.s64 = ctx.r4.s64 + 16336;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B64;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,1616
	ctx.r3.s64 = r31.s64 + 1616;
	// addi r4,r11,16312
	ctx.r4.s64 = r11.s64 + 16312;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82644B78;
	sub_82633D40(ctx, base);
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

__attribute__((alias("__imp__sub_82644B90"))) PPC_WEAK_FUNC(sub_82644B90);
PPC_FUNC_IMPL(__imp__sub_82644B90) {
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
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644bc0
	if (cr6.eq) goto loc_82644BC0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644BC0;
	sub_82130588(ctx, base);
loc_82644BC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644BC8;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644be0
	if (cr6.eq) goto loc_82644BE0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644BE0;
	sub_82130588(ctx, base);
loc_82644BE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644BE8;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644c00
	if (cr6.eq) goto loc_82644C00;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644C00;
	sub_82130588(ctx, base);
loc_82644C00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644C08;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644c20
	if (cr6.eq) goto loc_82644C20;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644C20;
	sub_82130588(ctx, base);
loc_82644C20:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644C28;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82644C30;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82644C48"))) PPC_WEAK_FUNC(sub_82644C48);
PPC_FUNC_IMPL(__imp__sub_82644C48) {
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
	ctx.lr = 0x82644C50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82659e28
	ctx.lr = 0x82644C60;
	sub_82659E28(ctx, base);
	// lhz r11,852(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 852);
	// lwz r9,848(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 848);
	// addi r31,r30,848
	r31.s64 = r30.s64 + 848;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82644c98
	if (cr6.eq) goto loc_82644C98;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82644C84:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82644c84
	if (!cr6.eq) goto loc_82644C84;
loc_82644C98:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r29,r11,17232
	r29.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r6,-4680
	ctx.r5.s64 = ctx.r6.s64 + -4680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644CC8;
	sub_826571D8(ctx, base);
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644cf4
	if (cr6.eq) goto loc_82644CF4;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,992
	ctx.r8.s64 = r30.s64 + 992;
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
loc_82644CF4:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4744
	ctx.r5.s64 = r11.s64 + -4744;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D08;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644d34
	if (cr6.eq) goto loc_82644D34;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1408
	ctx.r8.s64 = r30.s64 + 1408;
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
loc_82644D34:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4692
	ctx.r5.s64 = r11.s64 + -4692;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D48;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644d74
	if (cr6.eq) goto loc_82644D74;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1200
	ctx.r8.s64 = r30.s64 + 1200;
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
loc_82644D74:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,-4764
	ctx.r5.s64 = r11.s64 + -4764;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826571d8
	ctx.lr = 0x82644D88;
	sub_826571D8(ctx, base);
	// lhz r9,88(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82644db4
	if (cr6.eq) goto loc_82644DB4;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r30,1616
	ctx.r8.s64 = r30.s64 + 1616;
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
loc_82644DB4:
	// lhz r10,90(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 90);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82644dc8
	if (cr6.eq) goto loc_82644DC8;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82130588
	ctx.lr = 0x82644DC8;
	sub_82130588(ctx, base);
loc_82644DC8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2028
	ctx.lr = 0x82644DD0;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82644DD8"))) PPC_WEAK_FUNC(sub_82644DD8);
PPC_FUNC_IMPL(__imp__sub_82644DD8) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x82644E18;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,17268
	ctx.r7.s64 = ctx.r8.s64 + 17268;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x82644E2C;
	sub_82659E28(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,17244
	ctx.r4.s64 = ctx.r6.s64 + 17244;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x82644E44;
	sub_82633D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// stw r11,1232(r31)
	PPC_STORE_U32(r31.u32 + 1232, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,1236(r31)
	PPC_STORE_U16(r31.u32 + 1236, r11.u16);
	// sth r11,1238(r31)
	PPC_STORE_U16(r31.u32 + 1238, r11.u16);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
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

__attribute__((alias("__imp__sub_82644E8C"))) PPC_WEAK_FUNC(sub_82644E8C);
PPC_FUNC_IMPL(__imp__sub_82644E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644E90"))) PPC_WEAK_FUNC(sub_82644E90);
PPC_FUNC_IMPL(__imp__sub_82644E90) {
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
	// lhz r11,1238(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1238);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ebc
	if (cr6.eq) goto loc_82644EBC;
	// lwz r3,1232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1232);
	// bl 0x82130588
	ctx.lr = 0x82644EBC;
	sub_82130588(ctx, base);
loc_82644EBC:
	// lhz r11,1218(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1218);
	// addi r31,r30,1024
	r31.s64 = r30.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ed4
	if (cr6.eq) goto loc_82644ED4;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82644ED4;
	sub_82130588(ctx, base);
loc_82644ED4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82644EDC;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1002);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82644ef4
	if (cr6.eq) goto loc_82644EF4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82644EF4;
	sub_82130588(ctx, base);
loc_82644EF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82644EFC;
	sub_821D2028(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82644F04;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82644F1C"))) PPC_WEAK_FUNC(sub_82644F1C);
PPC_FUNC_IMPL(__imp__sub_82644F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82644F20"))) PPC_WEAK_FUNC(sub_82644F20);
PPC_FUNC_IMPL(__imp__sub_82644F20) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82644F28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r27,r30,1232
	r27.s64 = r30.s64 + 1232;
	// lhz r11,1236(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1236);
	// lwz r9,1232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1232);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82644f68
	if (cr6.eq) goto loc_82644F68;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_82644F54:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82644f54
	if (!cr6.eq) goto loc_82644F54;
loc_82644F68:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lwz r11,1240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1240);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82645060
	if (cr6.gt) goto loc_82645060;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,18072
	r29.s64 = ctx.r10.s64 + 18072;
	// lis r12,-32156
	r12.s64 = -2107375616;
	// addi r12,r12,20392
	r12.s64 = r12.s64 + 20392;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82644FB8;
	case 1:
		goto loc_82644FDC;
	case 2:
		goto loc_82645000;
	case 3:
		goto loc_82645040;
	default:
		__builtin_unreachable();
	}
	// lwz r19,20408(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20408);
	// lwz r19,20444(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20444);
	// lwz r19,20480(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20480);
	// lwz r19,20544(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20544);
loc_82644FB8:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// addi r5,r10,-4680
	ctx.r5.s64 = ctx.r10.s64 + -4680;
	// addi r4,r9,18072
	ctx.r4.s64 = ctx.r9.s64 + 18072;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8264505c
	goto loc_8264505C;
loc_82644FDC:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// addi r4,r9,18072
	ctx.r4.s64 = ctx.r9.s64 + 18072;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x8264505c
	goto loc_8264505C;
loc_82645000:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,992(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82645038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x82645060
	if (cr6.gt) goto loc_82645060;
loc_82645040:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r30,992
	ctx.r3.s64 = r30.s64 + 992;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264505C:
	// bctrl 
	ctx.lr = 0x82645060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82645060:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82645078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82645128
	if (cr6.eq) goto loc_82645128;
	// stw r31,864(r30)
	PPC_STORE_U32(r30.u32 + 864, r31.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,24324
	ctx.r4.s64 = r11.s64 + 24324;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82645098;
	sub_8262FFE0(ctx, base);
	// addi r29,r30,672
	r29.s64 = r30.s64 + 672;
	// li r31,0
	r31.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x826450A8;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8264515c
	if (!cr6.gt) goto loc_8264515C;
	// lis r28,-32120
	r28.s64 = -2105016320;
loc_826450B4:
	// lwz r3,-27856(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826450BC;
	sub_8238EC00(ctx, base);
	// lwz r11,864(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826450E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82389800
	ctx.lr = 0x826450EC;
	sub_82389800(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lhz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 16);
	// extsh r26,r7
	r26.s64 = ctx.r7.s16;
	// bl 0x8262e420
	ctx.lr = 0x82645104;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r26,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r26.u32);
	// bl 0x82631f88
	ctx.lr = 0x82645118;
	sub_82631F88(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x826450b4
	if (cr6.lt) goto loc_826450B4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82645128:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r31,r30,256
	r31.s64 = r30.s64 + 256;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x82645140;
	sub_8262FFE0(ctx, base);
	// lwz r10,256(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645154;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,864(r30)
	PPC_STORE_U32(r30.u32 + 864, ctx.r8.u32);
loc_8264515C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82645164"))) PPC_WEAK_FUNC(sub_82645164);
PPC_FUNC_IMPL(__imp__sub_82645164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645168"))) PPC_WEAK_FUNC(sub_82645168);
PPC_FUNC_IMPL(__imp__sub_82645168) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13784
	ctx.r4.s64 = ctx.r9.s64 + 13784;
	// addi r8,r11,24348
	ctx.r8.s64 = r11.s64 + 24348;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,35
	ctx.r6.s64 = 35;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826451A4;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,18092
	ctx.r7.s64 = ctx.r8.s64 + 18092;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1000(r31)
	PPC_STORE_U16(r31.u32 + 1000, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1002(r31)
	PPC_STORE_U16(r31.u32 + 1002, r11.u16);
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x826451FC;
	sub_826347F0(ctx, base);
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

__attribute__((alias("__imp__sub_82645214"))) PPC_WEAK_FUNC(sub_82645214);
PPC_FUNC_IMPL(__imp__sub_82645214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645218"))) PPC_WEAK_FUNC(sub_82645218);
PPC_FUNC_IMPL(__imp__sub_82645218) {
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
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645240
	if (cr6.eq) goto loc_82645240;
	// lwz r3,1020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// bl 0x82130588
	ctx.lr = 0x82645240;
	sub_82130588(ctx, base);
loc_82645240:
	// lhz r11,1018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1018);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645254
	if (cr6.eq) goto loc_82645254;
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// bl 0x82130588
	ctx.lr = 0x82645254;
	sub_82130588(ctx, base);
loc_82645254:
	// lhz r11,1010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1010);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645268
	if (cr6.eq) goto loc_82645268;
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// bl 0x82130588
	ctx.lr = 0x82645268;
	sub_82130588(ctx, base);
loc_82645268:
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264527c
	if (cr6.eq) goto loc_8264527C;
	// lwz r3,996(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// bl 0x82130588
	ctx.lr = 0x8264527C;
	sub_82130588(ctx, base);
loc_8264527C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82645284;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82645298"))) PPC_WEAK_FUNC(sub_82645298);
PPC_FUNC_IMPL(__imp__sub_82645298) {
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
	ctx.lr = 0x826452A0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,107
	ctx.r10.s64 = 107;
	// addi r9,r11,3912
	ctx.r9.s64 = r11.s64 + 3912;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r22,r30,1004
	r22.s64 = r30.s64 + 1004;
	// addi r25,r30,996
	r25.s64 = r30.s64 + 996;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12440(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12440);
	// bl 0x8238e3a8
	ctx.lr = 0x826452E4;
	sub_8238E3A8(ctx, base);
	// lhz r6,1000(r30)
	ctx.r6.u64 = PPC_LOAD_U16(r30.u32 + 1000);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8264545c
	if (cr6.eq) goto loc_8264545C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r28,r30,1012
	r28.s64 = r30.s64 + 1012;
	// addi r27,r30,1020
	r27.s64 = r30.s64 + 1020;
	// li r31,0
	r31.s64 = 0;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r21,r11,5568
	r21.s64 = r11.s64 + 5568;
	// addi r24,r10,3998
	r24.s64 = ctx.r10.s64 + 3998;
loc_82645314:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bgt cr6,0x82645408
	if (cr6.gt) goto loc_82645408;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82645328;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82645344
	if (cr6.eq) goto loc_82645344;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x8264533C;
	sub_82633D40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82645348
	goto loc_82645348;
loc_82645344:
	// li r29,0
	r29.s64 = 0;
loc_82645348:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645354;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x82645364;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82645380
	if (cr6.eq) goto loc_82645380;
	// stw r21,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r21.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8264537C;
	sub_826311F8(ctx, base);
	// b 0x82645384
	goto loc_82645384;
loc_82645380:
	// li r29,0
	r29.s64 = 0;
loc_82645384:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645390;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r3,-10244(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10244);
	// lwzx r4,r31,r11
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x822175d0
	ctx.lr = 0x826453A4;
	sub_822175D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826453fc
	if (cr6.eq) goto loc_826453FC;
	// lhz r11,852(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 852);
	// addi r10,r30,848
	ctx.r10.s64 = r30.s64 + 848;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,848(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,852(r30)
	PPC_STORE_U16(r30.u32 + 852, ctx.r8.u16);
	// lwzx r6,r31,r10
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// stwx r6,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r31,r5
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r31,r7
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
loc_826453FC:
	// lwz r11,992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 992);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,992(r30)
	PPC_STORE_U32(r30.u32 + 992, r11.u32);
loc_82645408:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82645428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r6,0(r22)
	ctx.r6.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// lwzx r3,r31,r7
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwzx r4,r31,r6
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82645448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,1000(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 1000);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r26,r10
	cr6.compare<int32_t>(r26.s32, ctx.r10.s32, xer);
	// blt cr6,0x82645314
	if (cr6.lt) goto loc_82645314;
loc_8264545C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82645464"))) PPC_WEAK_FUNC(sub_82645464);
PPC_FUNC_IMPL(__imp__sub_82645464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82645468"))) PPC_WEAK_FUNC(sub_82645468);
PPC_FUNC_IMPL(__imp__sub_82645468) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13824
	ctx.r4.s64 = ctx.r9.s64 + 13824;
	// addi r8,r11,29164
	ctx.r8.s64 = r11.s64 + 29164;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x826454A4;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,18900
	ctx.r7.s64 = ctx.r8.s64 + 18900;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r11.u32);
	// sth r11,1032(r31)
	PPC_STORE_U16(r31.u32 + 1032, r11.u16);
	// sth r11,1034(r31)
	PPC_STORE_U16(r31.u32 + 1034, r11.u16);
	// stw r11,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r11.u32);
	// sth r11,1040(r31)
	PPC_STORE_U16(r31.u32 + 1040, r11.u16);
	// sth r11,1042(r31)
	PPC_STORE_U16(r31.u32 + 1042, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x82645510;
	sub_826347F0(ctx, base);
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

__attribute__((alias("__imp__sub_82645528"))) PPC_WEAK_FUNC(sub_82645528);
PPC_FUNC_IMPL(__imp__sub_82645528) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82645530;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r9,118
	ctx.r9.s64 = 118;
	// addi r8,r10,3924
	ctx.r8.s64 = ctx.r10.s64 + 3924;
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// lis r4,-32115
	ctx.r4.s64 = -2104688640;
	// lwz r11,996(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r21,r31,1012
	r21.s64 = r31.s64 + 1012;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r26,r31,1004
	r26.s64 = r31.s64 + 1004;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// lwz r3,-12440(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12440);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// bl 0x8238e3a8
	ctx.lr = 0x82645574;
	sub_8238E3A8(ctx, base);
	// lhz r3,1008(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r25,0
	r25.s64 = 0;
	// addi r19,r11,19760
	r19.s64 = r11.s64 + 19760;
	// addi r18,r10,19736
	r18.s64 = ctx.r10.s64 + 19736;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82645794
	if (cr6.eq) goto loc_82645794;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r27,r31,1028
	r27.s64 = r31.s64 + 1028;
	// li r30,0
	r30.s64 = 0;
	// addi r20,r11,5568
	r20.s64 = r11.s64 + 5568;
	// addi r23,r10,19720
	r23.s64 = ctx.r10.s64 + 19720;
	// addi r22,r9,19704
	r22.s64 = ctx.r9.s64 + 19704;
	// addi r24,r8,3998
	r24.s64 = ctx.r8.s64 + 3998;
loc_826455BC:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// bgt cr6,0x82645698
	if (cr6.gt) goto loc_82645698;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x826455D0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826455ec
	if (cr6.eq) goto loc_826455EC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x826455E4;
	sub_82633D40(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x826455f0
	goto loc_826455F0;
loc_826455EC:
	// li r28,0
	r28.s64 = 0;
loc_826455F0:
	// addi r29,r31,1020
	r29.s64 = r31.s64 + 1020;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x82645600;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r28,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r28.u32);
	// bl 0x82130528
	ctx.lr = 0x82645610;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8264562c
	if (cr6.eq) goto loc_8264562C;
	// stw r20,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r20.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x82645628;
	sub_826311F8(ctx, base);
	// b 0x82645630
	goto loc_82645630;
loc_8264562C:
	// li r28,0
	r28.s64 = 0;
loc_82645630:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x8264563C;
	sub_8262E420(ctx, base);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r6,r30,r10
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwzx r11,r30,r5
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r5.u32);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// lwz r7,188(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// lwzx r11,r30,r8
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// stwx r11,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, r11.u32);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r10.u32);
loc_82645698:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x826456A8;
	sub_823DC018(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_826456B4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826456d8
	if (cr6.eq) goto loc_826456D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826456b4
	if (cr6.eq) goto loc_826456B4;
loc_826456D8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826456fc
	if (!cr6.eq) goto loc_826456FC;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826456FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826456FC:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r5,996(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 996);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x8264570C;
	sub_823DC018(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
loc_82645718:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8264573c
	if (cr6.eq) goto loc_8264573C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82645718
	if (cr6.eq) goto loc_82645718;
loc_8264573C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82645760
	if (!cr6.eq) goto loc_82645760;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82645760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82645760:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwzx r4,r30,r10
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82645780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r25,r7
	cr6.compare<int32_t>(r25.s32, ctx.r7.s32, xer);
	// blt cr6,0x826455bc
	if (cr6.lt) goto loc_826455BC;
loc_82645794:
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x826457e4
	if (!cr6.gt) goto loc_826457E4;
	// lhz r11,1008(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1008);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x826457e4
	if (!cr6.eq) goto loc_826457E4;
	// lwz r11,1020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826457C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1020(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826457E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826457E4:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826457F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82645800"))) PPC_WEAK_FUNC(sub_82645800);
PPC_FUNC_IMPL(__imp__sub_82645800) {
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
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,13804
	ctx.r4.s64 = ctx.r9.s64 + 13804;
	// addi r8,r11,28372
	ctx.r8.s64 = r11.s64 + 28372;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264583C;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,19780
	ctx.r7.s64 = ctx.r8.s64 + 19780;
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r11,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r11.u32);
	// addi r4,r6,25024
	ctx.r4.s64 = ctx.r6.s64 + 25024;
	// sth r11,1008(r31)
	PPC_STORE_U16(r31.u32 + 1008, r11.u16);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r11,1010(r31)
	PPC_STORE_U16(r31.u32 + 1010, r11.u16);
	// stw r11,1012(r31)
	PPC_STORE_U32(r31.u32 + 1012, r11.u32);
	// sth r11,1016(r31)
	PPC_STORE_U16(r31.u32 + 1016, r11.u16);
	// sth r11,1018(r31)
	PPC_STORE_U16(r31.u32 + 1018, r11.u16);
	// stw r11,1020(r31)
	PPC_STORE_U32(r31.u32 + 1020, r11.u32);
	// sth r11,1024(r31)
	PPC_STORE_U16(r31.u32 + 1024, r11.u16);
	// sth r11,1026(r31)
	PPC_STORE_U16(r31.u32 + 1026, r11.u16);
	// stw r11,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r11.u32);
	// sth r11,1032(r31)
	PPC_STORE_U16(r31.u32 + 1032, r11.u16);
	// sth r11,1034(r31)
	PPC_STORE_U16(r31.u32 + 1034, r11.u16);
	// stw r11,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r11.u32);
	// sth r11,1040(r31)
	PPC_STORE_U16(r31.u32 + 1040, r11.u16);
	// sth r11,1042(r31)
	PPC_STORE_U16(r31.u32 + 1042, r11.u16);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,996(r31)
	PPC_STORE_U32(r31.u32 + 996, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x826458A4;
	sub_826347F0(ctx, base);
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

__attribute__((alias("__imp__sub_826458BC"))) PPC_WEAK_FUNC(sub_826458BC);
PPC_FUNC_IMPL(__imp__sub_826458BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826458C0"))) PPC_WEAK_FUNC(sub_826458C0);
PPC_FUNC_IMPL(__imp__sub_826458C0) {
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
	// lhz r11,1042(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1042);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826458e8
	if (cr6.eq) goto loc_826458E8;
	// lwz r3,1036(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1036);
	// bl 0x82130588
	ctx.lr = 0x826458E8;
	sub_82130588(ctx, base);
loc_826458E8:
	// lhz r11,1034(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1034);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826458fc
	if (cr6.eq) goto loc_826458FC;
	// lwz r3,1028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// bl 0x82130588
	ctx.lr = 0x826458FC;
	sub_82130588(ctx, base);
loc_826458FC:
	// lhz r11,1026(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1026);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645910
	if (cr6.eq) goto loc_82645910;
	// lwz r3,1020(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1020);
	// bl 0x82130588
	ctx.lr = 0x82645910;
	sub_82130588(ctx, base);
loc_82645910:
	// lhz r11,1018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1018);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645924
	if (cr6.eq) goto loc_82645924;
	// lwz r3,1012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1012);
	// bl 0x82130588
	ctx.lr = 0x82645924;
	sub_82130588(ctx, base);
loc_82645924:
	// lhz r11,1010(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1010);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82645938
	if (cr6.eq) goto loc_82645938;
	// lwz r3,1004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// bl 0x82130588
	ctx.lr = 0x82645938;
	sub_82130588(ctx, base);
loc_82645938:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x82645940;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_82645954"))) PPC_WEAK_FUNC(sub_82645954);
PPC_FUNC_IMPL(__imp__sub_82645954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

