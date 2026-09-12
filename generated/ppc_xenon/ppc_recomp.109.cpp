#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82554784"))) PPC_WEAK_FUNC(sub_82554784);
PPC_FUNC_IMPL(__imp__sub_82554784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82554788"))) PPC_WEAK_FUNC(sub_82554788);
PPC_FUNC_IMPL(__imp__sub_82554788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-23584
	ctx.r3.s64 = r11.s64 + -23584;
	// b 0x82554500
	sub_82554500(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82554798"))) PPC_WEAK_FUNC(sub_82554798);
PPC_FUNC_IMPL(__imp__sub_82554798) {
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
	// bl 0x82557f78
	ctx.lr = 0x825547B8;
	sub_82557F78(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-23584
	ctx.r3.s64 = r11.s64 + -23584;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825578c8
	ctx.lr = 0x825547CC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825547e8
	if (!cr6.eq) goto loc_825547E8;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-13448
	ctx.r3.s64 = r11.s64 + -13448;
	// bl 0x821bd618
	ctx.lr = 0x825547E8;
	sub_821BD618(ctx, base);
loc_825547E8:
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

__attribute__((alias("__imp__sub_82554800"))) PPC_WEAK_FUNC(sub_82554800);
PPC_FUNC_IMPL(__imp__sub_82554800) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82554808;
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x82554824
	if (cr6.eq) goto loc_82554824;
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
loc_82554824:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82554878
	if (!cr6.eq) goto loc_82554878;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r11,-23620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23620);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82554850
	if (cr6.eq) goto loc_82554850;
	// stw r31,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r31.u32);
loc_82554850:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13236
	ctx.r4.s64 = r11.s64 + -13236;
	// bl 0x82554590
	ctx.lr = 0x82554860;
	sub_82554590(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825549f4
	if (cr6.eq) goto loc_825549F4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r11.u32);
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x823d9248
	return;
loc_82554878:
	// bl 0x825578b8
	ctx.lr = 0x8255487C;
	sub_825578B8(ctx, base);
	// lhz r11,22(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 22);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x825548dc
	if (cr6.eq) goto loc_825548DC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// beq cr6,0x825548dc
	if (cr6.eq) goto loc_825548DC;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r11,-23620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23620);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825548b4
	if (cr6.eq) goto loc_825548B4;
	// stw r31,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r31.u32);
loc_825548B4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13264
	ctx.r4.s64 = r11.s64 + -13264;
	// bl 0x82554590
	ctx.lr = 0x825548C4;
	sub_82554590(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825549f4
	if (cr6.eq) goto loc_825549F4;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r11.u32);
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x823d9248
	return;
loc_825548DC:
	// li r28,0
	r28.s64 = 0;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// lhz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// blt cr6,0x82554958
	if (cr6.lt) goto loc_82554958;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,512
	ctx.r4.s64 = 512;
	// addi r5,r11,-13344
	ctx.r5.s64 = r11.s64 + -13344;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82554914;
	sub_82137A08(ctx, base);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r11,-23620(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23620);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82554934
	if (cr6.eq) goto loc_82554934;
	// stw r31,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r31.u32);
loc_82554934:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82554590
	ctx.lr = 0x82554940;
	sub_82554590(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825549f4
	if (cr6.eq) goto loc_825549F4;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-23620(r30)
	PPC_STORE_U32(r30.u32 + -23620, r11.u32);
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x823d9248
	return;
loc_82554958:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// subf r8,r11,r7
	ctx.r8.s64 = ctx.r7.s64 - r11.s64;
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r8,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r8.u32);
	// ble cr6,0x82554990
	if (!cr6.gt) goto loc_82554990;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82554978:
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stwx r9,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82554978
	if (!cr0.eq) goto loc_82554978;
loc_82554990:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x825549b4
	if (cr6.eq) goto loc_825549B4;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823da950
	ctx.lr = 0x825549B4;
	sub_823DA950(ctx, base);
loc_825549B4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
	// stwx r28,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r28.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
loc_825549F4:
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825549FC"))) PPC_WEAK_FUNC(sub_825549FC);
PPC_FUNC_IMPL(__imp__sub_825549FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82554A00"))) PPC_WEAK_FUNC(sub_82554A00);
PPC_FUNC_IMPL(__imp__sub_82554A00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,64(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82554a50
	if (!cr6.eq) goto loc_82554A50;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// addi r9,r10,-23592
	ctx.r9.s64 = ctx.r10.s64 + -23592;
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x82554a50
	if (!cr6.gt) goto loc_82554A50;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_82554A28:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82554a40
	if (!cr6.eq) goto loc_82554A40;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// beq cr6,0x82554a58
	if (cr6.eq) goto loc_82554A58;
loc_82554A40:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x82554a28
	if (cr6.lt) goto loc_82554A28;
loc_82554A50:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82554A58:
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r4,64(r7)
	PPC_STORE_U32(ctx.r7.u32 + 64, ctx.r4.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r3,1
	ctx.r3.s64 = 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r8,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, ctx.r8.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82554A88"))) PPC_WEAK_FUNC(sub_82554A88);
PPC_FUNC_IMPL(__imp__sub_82554A88) {
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
	ctx.lr = 0x82554A90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82554b58
	if (cr6.eq) goto loc_82554B58;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,-23608
	r30.s64 = r11.s64 + -23608;
	// mr r28,r29
	r28.u64 = r29.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82554b24
	if (cr6.eq) goto loc_82554B24;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82554AD0:
	// lwzx r3,r31,r8
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x82554b10
	if (!cr6.eq) goto loc_82554B10;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82554b10
	if (cr6.eq) goto loc_82554B10;
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bne cr6,0x82554b10
	if (!cr6.eq) goto loc_82554B10;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82554B08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82554B10:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x82554ad0
	if (cr6.lt) goto loc_82554AD0;
loc_82554B24:
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82554b58
	if (!cr6.gt) goto loc_82554B58;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_82554B38:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82554b64
	if (cr6.eq) goto loc_82554B64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82554b38
	if (cr6.lt) goto loc_82554B38;
loc_82554B58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82554B64:
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwzx r3,r31,r8
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// bl 0x82554a00
	ctx.lr = 0x82554B74;
	sub_82554A00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82554b58
	if (cr6.eq) goto loc_82554B58;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r29,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r29.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r29,52(r10)
	PPC_STORE_U32(ctx.r10.u32 + 52, r29.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r29,56(r9)
	PPC_STORE_U32(ctx.r9.u32 + 56, r29.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r8,r31,r11
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r29,60(r8)
	PPC_STORE_U32(ctx.r8.u32 + 60, r29.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82554BD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825578b8
	ctx.lr = 0x82554BDC;
	sub_825578B8(ctx, base);
	// bl 0x825575d0
	ctx.lr = 0x82554BE0;
	sub_825575D0(ctx, base);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,-23624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23624);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-23624(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23624, r11.u32);
	// lwzx r8,r31,r10
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// lwz r3,-23624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23624);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82554C08"))) PPC_WEAK_FUNC(sub_82554C08);
PPC_FUNC_IMPL(__imp__sub_82554C08) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-23620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23620);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x82554c54
	if (!cr6.eq) goto loc_82554C54;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-13208
	ctx.r9.s64 = r11.s64 + -13208;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r9,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82554C54:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x825578b8
	ctx.lr = 0x82554C5C;
	sub_825578B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82554c68
	if (cr6.eq) goto loc_82554C68;
	// bl 0x825579a0
	ctx.lr = 0x82554C68;
	sub_825579A0(ctx, base);
loc_82554C68:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r9,r11,-23592
	ctx.r9.s64 = r11.s64 + -23592;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82554cb4
	if (cr6.eq) goto loc_82554CB4;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_82554C88:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplw cr6,r5,r31
	cr6.compare<uint32_t>(ctx.r5.u32, r31.u32, xer);
	// bne cr6,0x82554ca0
	if (!cr6.eq) goto loc_82554CA0;
	// stwx r6,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r6.u32);
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
loc_82554CA0:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// clrlwi r10,r8,16
	ctx.r10.u64 = ctx.r8.u32 & 0xFFFF;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// blt cr6,0x82554c88
	if (cr6.lt) goto loc_82554C88;
loc_82554CB4:
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// stw r6,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r6.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82554CD4"))) PPC_WEAK_FUNC(sub_82554CD4);
PPC_FUNC_IMPL(__imp__sub_82554CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82554CD8"))) PPC_WEAK_FUNC(sub_82554CD8);
PPC_FUNC_IMPL(__imp__sub_82554CD8) {
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
	ctx.lr = 0x82554CE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r11,-23608
	r31.s64 = r11.s64 + -23608;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82554d40
	if (cr6.eq) goto loc_82554D40;
	// li r30,0
	r30.s64 = 0;
loc_82554D04:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r10
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// bne cr6,0x82554d2c
	if (!cr6.eq) goto loc_82554D2C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82554D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
loc_82554D2C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82554d04
	if (cr6.lt) goto loc_82554D04;
loc_82554D40:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82554D48"))) PPC_WEAK_FUNC(sub_82554D48);
PPC_FUNC_IMPL(__imp__sub_82554D48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82554d90
	if (cr6.eq) goto loc_82554D90;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-23608
	r11.s64 = r11.s64 + -23608;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82554d90
	if (!cr6.gt) goto loc_82554D90;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82554D70:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplw cr6,r6,r3
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r3.u32, xer);
	// beq cr6,0x82554d98
	if (cr6.eq) goto loc_82554D98;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82554d70
	if (cr6.lt) goto loc_82554D70;
loc_82554D90:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82554D98:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82554DA4"))) PPC_WEAK_FUNC(sub_82554DA4);
PPC_FUNC_IMPL(__imp__sub_82554DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82554DA8"))) PPC_WEAK_FUNC(sub_82554DA8);
PPC_FUNC_IMPL(__imp__sub_82554DA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4344(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4344);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82554DC0"))) PPC_WEAK_FUNC(sub_82554DC0);
PPC_FUNC_IMPL(__imp__sub_82554DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,3998
	ctx.r9.s64 = ctx.r10.s64 + 3998;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82554DD4"))) PPC_WEAK_FUNC(sub_82554DD4);
PPC_FUNC_IMPL(__imp__sub_82554DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82554DD8"))) PPC_WEAK_FUNC(sub_82554DD8);
PPC_FUNC_IMPL(__imp__sub_82554DD8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-13564
	ctx.r9.s64 = r11.s64 + -13564;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82554e0c
	if (cr6.eq) goto loc_82554E0C;
	// bl 0x82130588
	ctx.lr = 0x82554E08;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82554E0C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82554E20"))) PPC_WEAK_FUNC(sub_82554E20);
PPC_FUNC_IMPL(__imp__sub_82554E20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82554E28;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x825566dc
	if (cr6.eq) goto loc_825566DC;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x825566dc
	if (cr6.eq) goto loc_825566DC;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r28,16(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r25,r11,-23628
	r25.s64 = r11.s64 + -23628;
	// lwz r24,8(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// stw r31,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r31.u32);
	// bl 0x825578b8
	ctx.lr = 0x82554E68;
	sub_825578B8(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r26,0
	r26.s64 = 0;
	// lwz r27,8(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r21,-23564(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + -23564);
	// stw r26,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r26.u32);
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x825566d0
	if (cr6.eq) goto loc_825566D0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r20,-1
	r20.s64 = -1;
	// addi r19,r11,-13020
	r19.s64 = r11.s64 + -13020;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r23,r10,32684
	r23.s64 = ctx.r10.s64 + 32684;
loc_82554EA4:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r22)
	PPC_STORE_U32(r22.u32 + 0, r11.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// lbzx r11,r27,r28
	r11.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplwi cr6,r10,74
	cr6.compare<uint32_t>(ctx.r10.u32, 74, xer);
	// bgt cr6,0x82556680
	if (cr6.gt) goto loc_82556680;
	// lis r12,-32171
	r12.s64 = -2108358656;
	// addi r12,r12,20204
	r12.s64 = r12.s64 + 20204;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82555018;
	case 1:
		goto loc_82555044;
	case 2:
		goto loc_82555070;
	case 3:
		goto loc_8255509C;
	case 4:
		goto loc_825550E4;
	case 5:
		goto loc_82555134;
	case 6:
		goto loc_82555158;
	case 7:
		goto loc_82555178;
	case 8:
		goto loc_825551AC;
	case 9:
		goto loc_8255521C;
	case 10:
		goto loc_825551E4;
	case 11:
		goto loc_8255528C;
	case 12:
		goto loc_82555254;
	case 13:
		goto loc_825552C4;
	case 14:
		goto loc_825552F0;
	case 15:
		goto loc_8255531C;
	case 16:
		goto loc_82555348;
	case 17:
		goto loc_8255537C;
	case 18:
		goto loc_825553D4;
	case 19:
		goto loc_825553F4;
	case 20:
		goto loc_8255542C;
	case 21:
		goto loc_8255549C;
	case 22:
		goto loc_82555464;
	case 23:
		goto loc_8255550C;
	case 24:
		goto loc_825554D4;
	case 25:
		goto loc_82555544;
	case 26:
		goto loc_825555FC;
	case 27:
		goto loc_825556B4;
	case 28:
		goto loc_8255576C;
	case 29:
		goto loc_8255585C;
	case 30:
		goto loc_825558E4;
	case 31:
		goto loc_82555910;
	case 32:
		goto loc_8255593C;
	case 33:
		goto loc_82555968;
	case 34:
		goto loc_825559A8;
	case 35:
		goto loc_82555A0C;
	case 36:
		goto loc_82555A70;
	case 37:
		goto loc_82555AA0;
	case 38:
		goto loc_82555AC4;
	case 39:
		goto loc_82555B2C;
	case 40:
		goto loc_82555B78;
	case 41:
		goto loc_82555B78;
	case 42:
		goto loc_82555BE0;
	case 43:
		goto loc_82555C14;
	case 44:
		goto loc_82555C24;
	case 45:
		goto loc_82555CF4;
	case 46:
		goto loc_82555D60;
	case 47:
		goto loc_82555E34;
	case 48:
		goto loc_82555EF8;
	case 49:
		goto loc_82555F48;
	case 50:
		goto loc_82555F8C;
	case 51:
		goto loc_82555FC8;
	case 52:
		goto loc_82556034;
	case 53:
		goto loc_8255609C;
	case 54:
		goto loc_8255609C;
	case 55:
		goto loc_8255609C;
	case 56:
		goto loc_8255609C;
	case 57:
		goto loc_8255609C;
	case 58:
		goto loc_8255609C;
	case 59:
		goto loc_8255609C;
	case 60:
		goto loc_8255609C;
	case 61:
		goto loc_825560D8;
	case 62:
		goto loc_82556124;
	case 63:
		goto loc_82556164;
	case 64:
		goto loc_825561A4;
	case 65:
		goto loc_82556220;
	case 66:
		goto loc_825562D4;
	case 67:
		goto loc_82556310;
	case 68:
		goto loc_82556338;
	case 69:
		goto loc_82556448;
	case 70:
		goto loc_825564C8;
	case 71:
		goto loc_8255655C;
	case 72:
		goto loc_82556600;
	case 73:
		goto loc_82556630;
	case 74:
		goto loc_825563A8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,20504(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20504);
	// lwz r18,20548(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20548);
	// lwz r18,20592(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20592);
	// lwz r18,20636(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20636);
	// lwz r18,20708(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20708);
	// lwz r18,20788(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20788);
	// lwz r18,20824(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20824);
	// lwz r18,20856(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20856);
	// lwz r18,20908(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20908);
	// lwz r18,21020(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21020);
	// lwz r18,20964(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 20964);
	// lwz r18,21132(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21132);
	// lwz r18,21076(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21076);
	// lwz r18,21188(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21188);
	// lwz r18,21232(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21232);
	// lwz r18,21276(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21276);
	// lwz r18,21320(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21320);
	// lwz r18,21372(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21372);
	// lwz r18,21460(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21460);
	// lwz r18,21492(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21492);
	// lwz r18,21548(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21548);
	// lwz r18,21660(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21660);
	// lwz r18,21604(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21604);
	// lwz r18,21772(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21772);
	// lwz r18,21716(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21716);
	// lwz r18,21828(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 21828);
	// lwz r18,22012(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22012);
	// lwz r18,22196(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22196);
	// lwz r18,22380(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22380);
	// lwz r18,22620(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22620);
	// lwz r18,22756(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22756);
	// lwz r18,22800(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22800);
	// lwz r18,22844(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22844);
	// lwz r18,22888(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22888);
	// lwz r18,22952(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 22952);
	// lwz r18,23052(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23052);
	// lwz r18,23152(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23152);
	// lwz r18,23200(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23200);
	// lwz r18,23236(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23236);
	// lwz r18,23340(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23340);
	// lwz r18,23416(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23416);
	// lwz r18,23416(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23416);
	// lwz r18,23520(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23520);
	// lwz r18,23572(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23572);
	// lwz r18,23588(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23588);
	// lwz r18,23796(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23796);
	// lwz r18,23904(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 23904);
	// lwz r18,24116(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24116);
	// lwz r18,24312(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24312);
	// lwz r18,24392(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24392);
	// lwz r18,24460(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24460);
	// lwz r18,24520(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24520);
	// lwz r18,24628(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24628);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24732(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24732);
	// lwz r18,24792(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24792);
	// lwz r18,24868(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24868);
	// lwz r18,24932(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24932);
	// lwz r18,24996(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 24996);
	// lwz r18,25120(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25120);
	// lwz r18,25300(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25300);
	// lwz r18,25360(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25360);
	// lwz r18,25400(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25400);
	// lwz r18,25672(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25672);
	// lwz r18,25800(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25800);
	// lwz r18,25948(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25948);
	// lwz r18,26112(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 26112);
	// lwz r18,26160(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 26160);
	// lwz r18,25512(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + 25512);
loc_82555018:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555044:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555070:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255509C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// lwz r8,-4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// twllei r10,0
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r7,r8,r10
	ctx.r7.s32 = ctx.r8.s32 / ctx.r10.s32;
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// andc r5,r10,r6
	ctx.r5.u64 = ctx.r10.u64 & ~ctx.r6.u64;
	// twlgei r5,-1
	// b 0x825566c4
	goto loc_825566C4;
loc_825550E4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// twllei r11,0
	// divw r7,r8,r11
	ctx.r7.s32 = ctx.r8.s32 / r11.s32;
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// subf r4,r6,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r6.s64;
	// andc r3,r11,r5
	ctx.r3.u64 = r11.u64 & ~ctx.r5.u64;
	// stw r4,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r4.u32);
	// twlgei r3,-1
	// b 0x825566c4
	goto loc_825566C4;
loc_82555134:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555158:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555178:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r6,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825551AC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stw r5,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r5.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825551E4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bge cr6,0x82555214
	if (!cr6.lt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82555214:
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255521C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bgt cr6,0x82555214
	if (cr6.gt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555254:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// ble cr6,0x82555214
	if (!cr6.gt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255528C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x82555214
	if (cr6.lt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825552C4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825552F0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255531C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555348:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255537C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 / f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f11.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fnmsubs f7,f8,f0,f13
	ctx.f7.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f7,-4(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825553D4:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825553F4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x82555214
	if (cr6.eq) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255542C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x82555214
	if (!cr6.eq) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555464:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82555214
	if (!cr6.lt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255549C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82555214
	if (cr6.gt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825554D4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82555214
	if (!cr6.gt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255550C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82555214
	if (cr6.lt) goto loc_82555214;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555544:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r6,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// addi r9,r7,-1
	ctx.r9.s64 = ctx.r7.s64 + -1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f12,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// lfsx f11,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// lfsx f9,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// lfsx f8,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// fadds f6,f8,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 + ctx.f12.f64));
	// stfsx f6,r10,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// fadds f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfsx f7,r4,r5
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, temp.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f10,r10,r3
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825555FC:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f13,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f11,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// lfsx f10,r30,r11
	temp.u32 = PPC_LOAD_U32(r30.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// lfsx f9,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsubs f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsubs f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// stfsx f6,r6,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f7,r9,r10
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f8,r7,r8
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825556B4:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f13,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lfsx f12,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r7,-1
	ctx.r6.s64 = ctx.r7.s64 + -1;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfsx f9,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// lfsx f8,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f6,f8,f12
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfsx f6,r5,r11
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r5.u32 + r11.u32, temp.u32);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f7,r9,r10
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f10,r7,r8
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255576C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f11,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f13,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// lfsx f0,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lfsx f10,r5,r11
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	ctx.f10.f64 = double(temp.f32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// lfsx f12,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// beq cr6,0x825557e4
	if (cr6.eq) goto loc_825557E4;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f9,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f0,f9,f0
	f0.f64 = double(float(ctx.f9.f64 / f0.f64));
	// b 0x825557e8
	goto loc_825557E8;
loc_825557E4:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_825557E8:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f31.f64);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// beq cr6,0x82555810
	if (cr6.eq) goto loc_82555810;
	// fdivs f0,f12,f13
	f0.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// b 0x82555814
	goto loc_82555814;
loc_82555810:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_82555814:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fcmpu cr6,f11,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f11.f64, f31.f64);
	// stfsx f0,r9,r10
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// beq cr6,0x8255583c
	if (cr6.eq) goto loc_8255583C;
	// fdivs f0,f10,f11
	f0.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// b 0x82555840
	goto loc_82555840;
loc_8255583C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_82555840:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255585C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lfsx f13,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfsx f11,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfsx f10,r8,r11
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// lwz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stfsx f12,r4,r5
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, temp.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f9,r10,r3
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825558E4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// and r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 & ctx.r9.u64;
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555910:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255593C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// stw r8,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555968:
	// addi r11,r28,4
	r11.s64 = r28.s64 + 4;
	// add r10,r27,r11
	ctx.r10.u64 = r27.u64 + r11.u64;
	// add r9,r27,r11
	ctx.r9.u64 = r27.u64 + r11.u64;
	// add r8,r27,r11
	ctx.r8.u64 = r27.u64 + r11.u64;
	// add r7,r27,r11
	ctx.r7.u64 = r27.u64 + r11.u64;
	// lbz r6,-1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r5,-2(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2);
	// rotlwi r4,r6,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// lbz r3,-3(r8)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + -3);
	// lbz r11,-4(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + -4);
	// or r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 | ctx.r3.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r28,r7,r11
	r28.u64 = ctx.r7.u64 | r11.u64;
	// b 0x825566c4
	goto loc_825566C4;
loc_825559A8:
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r9,r27,r28
	ctx.r9.u64 = r27.u64 + r28.u64;
	// add r7,r27,r28
	ctx.r7.u64 = r27.u64 + r28.u64;
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// add r6,r27,r28
	ctx.r6.u64 = r27.u64 + r28.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lbz r5,-1(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1);
	// lbz r9,-3(r7)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + -3);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r4,-2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + -2);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbz r7,-4(r6)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + -4);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// or r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// rlwinm r11,r4,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// lwzx r10,r3,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x825566c4
	if (!cr6.eq) goto loc_825566C4;
	// mr r28,r11
	r28.u64 = r11.u64;
	// b 0x825566c4
	goto loc_825566C4;
loc_82555A0C:
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r9,r27,r28
	ctx.r9.u64 = r27.u64 + r28.u64;
	// add r7,r27,r28
	ctx.r7.u64 = r27.u64 + r28.u64;
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// add r6,r27,r28
	ctx.r6.u64 = r27.u64 + r28.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lbz r5,-1(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + -1);
	// lbz r9,-3(r7)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + -3);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r4,-2(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + -2);
	// rotlwi r8,r5,8
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 8);
	// lbz r7,-4(r6)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r6.u32 + -4);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// or r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 | ctx.r4.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// rlwinm r11,r4,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// lwzx r10,r3,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// mr r28,r11
	r28.u64 = r11.u64;
	// b 0x825566c4
	goto loc_825566C4;
loc_82555A70:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,-4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555AA0:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r12,-4
	r12.s64 = -4;
	// stfiwx f13,r11,r12
	PPC_STORE_U32(r11.u32 + r12.u32, ctx.f13.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555AC4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// lfsx f0,r8,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r11,r10
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r10
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555B2C:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r28,r28,2
	r28.s64 = r28.s64 + 2;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// add r10,r27,r28
	ctx.r10.u64 = r27.u64 + r28.u64;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r6,-1(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r5,-2(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + -2);
	// rotlwi r4,r6,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// or r10,r11,r5
	ctx.r10.u64 = r11.u64 | ctx.r5.u64;
	// stwx r10,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555B78:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// add r10,r27,r28
	ctx.r10.u64 = r27.u64 + r28.u64;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// add r7,r27,r28
	ctx.r7.u64 = r27.u64 + r28.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r27,r28
	ctx.r6.u64 = r27.u64 + r28.u64;
	// lbz r4,-1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lbz r3,-2(r8)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + -2);
	// rotlwi r11,r4,8
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// lbz r10,-3(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + -3);
	// or r7,r11,r3
	ctx.r7.u64 = r11.u64 | ctx.r3.u64;
	// lbz r8,-4(r6)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + -4);
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r6,r10
	ctx.r4.u64 = ctx.r6.u64 | ctx.r10.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r3,r8
	r11.u64 = ctx.r3.u64 | ctx.r8.u64;
	// stwx r11,r5,r9
	PPC_STORE_U32(ctx.r5.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555BE0:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555C14:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555C24:
	// addi r11,r27,-1
	r11.s64 = r27.s64 + -1;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// lbzx r30,r11,r10
	r30.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r28,r10,4
	r28.s64 = ctx.r10.s64 + 4;
	// add r9,r27,r28
	ctx.r9.u64 = r27.u64 + r28.u64;
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// lbzx r29,r11,r10
	r29.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// add r7,r27,r28
	ctx.r7.u64 = r27.u64 + r28.u64;
	// lbzx r6,r11,r28
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// lbz r5,-2(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + -2);
	// rotlwi r4,r6,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// lbz r3,-3(r8)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r8.u32 + -3);
	// or r11,r4,r5
	r11.u64 = ctx.r4.u64 | ctx.r5.u64;
	// lbz r10,-4(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + -4);
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 | ctx.r3.u64;
	// rlwinm r7,r8,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r11,r7,r10
	r11.u64 = ctx.r7.u64 | ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556704
	if (cr6.eq) goto loc_82556704;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82555c98
	if (cr6.eq) goto loc_82555C98;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// b 0x82555c9c
	goto loc_82555C9C;
loc_82555C98:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82555C9C:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r30,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r30.u32);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r26.u32);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r7,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82555CCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x825566e8
	if (!cr6.eq) goto loc_825566E8;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82553988
	ctx.lr = 0x82555CE0;
	sub_82553988(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subf r10,r30,r29
	ctx.r10.s64 = r29.s64 - r30.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555CF4:
	// addi r11,r28,4
	r11.s64 = r28.s64 + 4;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r8,r27,r11
	ctx.r8.u64 = r27.u64 + r11.u64;
	// add r7,r27,r11
	ctx.r7.u64 = r27.u64 + r11.u64;
	// add r6,r27,r11
	ctx.r6.u64 = r27.u64 + r11.u64;
	// add r5,r27,r11
	ctx.r5.u64 = r27.u64 + r11.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// lbz r4,-1(r8)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// lbz r3,-2(r7)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + -2);
	// rotlwi r9,r4,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 8);
	// lbz r8,-3(r6)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r6.u32 + -3);
	// lbz r7,-4(r5)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r5.u32 + -4);
	// or r6,r9,r3
	ctx.r6.u64 = ctx.r9.u64 | ctx.r3.u64;
	// rlwinm r5,r6,8,0,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// or r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 | ctx.r8.u64;
	// rlwinm r3,r4,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r9,r3,r7
	ctx.r9.u64 = ctx.r3.u64 | ctx.r7.u64;
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555D60:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r10,r27,-1
	ctx.r10.s64 = r27.s64 + -1;
	// addi r28,r11,2
	r28.s64 = r11.s64 + 2;
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lbzx r6,r10,r28
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + r28.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbz r5,-2(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + -2);
	// rotlwi r4,r6,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// or r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 | ctx.r5.u64;
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stwx r10,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r10.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// subf r8,r7,r11
	ctx.r8.s64 = r11.s64 - ctx.r7.s64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r4,r8,-2
	ctx.r4.s64 = ctx.r8.s64 + -2;
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555df8
	if (!cr6.lt) goto loc_82555DF8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_82555DD8:
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r26,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r26.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x82555dd8
	if (cr6.lt) goto loc_82555DD8;
loc_82555DF8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x825566c4
	if (cr6.lt) goto loc_825566C4;
loc_82555E14:
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,4308
	ctx.r4.s64 = r11.s64 + 4308;
	// bl 0x82554590
	ctx.lr = 0x82555E24;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82555E34:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r7,r27,r11
	ctx.r7.u64 = r27.u64 + r11.u64;
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lbzx r11,r27,r11
	r11.u64 = PPC_LOAD_U8(r27.u32 + r11.u32);
	// lbz r9,-1(r7)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r7.u32 + -1);
	// subf r8,r11,r8
	ctx.r8.s64 = ctx.r8.s64 - r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r3,r9,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwzx r5,r6,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r5,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r5.u32);
	// lwzx r28,r4,r7
	r28.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r7.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// beq cr6,0x82555ed4
	if (cr6.eq) goto loc_82555ED4;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_82555EA8:
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// bne 0x82555ea8
	if (!cr0.eq) goto loc_82555EA8;
loc_82555ED4:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x825566c4
	if (!cr6.eq) goto loc_825566C4;
	// li r11,2
	r11.s64 = 2;
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82555EF8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x82553a88
	ctx.lr = 0x82555F1C;
	sub_82553A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556724
	if (cr6.eq) goto loc_82556724;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555F48:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r7
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// bl 0x82553a88
	ctx.lr = 0x82555F68;
	sub_82553A88(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82556744
	if (cr6.eq) goto loc_82556744;
	// addi r11,r8,-1
	r11.s64 = ctx.r8.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r7
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555F8C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r4,-4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// bl 0x82553a88
	ctx.lr = 0x82555FB0;
	sub_82553A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556744
	if (cr6.eq) goto loc_82556744;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82555FC8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r6,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lwzx r11,r5,r8
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825566c4
	if (!cr6.gt) goto loc_825566C4;
loc_82556008:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// stwx r6,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r6.u32);
	// bne 0x82556008
	if (!cr0.eq) goto loc_82556008;
	// b 0x825566c4
	goto loc_825566C4;
loc_82556034:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x825566c4
	if (!cr6.gt) goto loc_825566C4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_82556070:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne 0x82556070
	if (!cr0.eq) goto loc_82556070;
	// b 0x825566c4
	goto loc_825566C4;
loc_8255609C:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// addi r7,r11,-54
	ctx.r7.s64 = r11.s64 + -54;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// stwx r6,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825560D8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556124:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556164:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r9,r9,r21
	ctx.r9.u64 = ctx.r9.u64 + r21.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825561A4:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r7,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lwzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82556764
	if (cr6.lt) goto loc_82556764;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// bge cr6,0x82556764
	if (!cr6.lt) goto loc_82556764;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// mullw r10,r10,r6
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r6.s32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r7
	ctx.r9.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556220:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// add r7,r27,r11
	ctx.r7.u64 = r27.u64 + r11.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r10,-1(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + -1);
	// lwzx r7,r6,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// rotlwi r9,r10,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r28,r9,r11
	r28.u64 = ctx.r9.u64 + r11.u64;
	// ble cr6,0x825566c4
	if (!cr6.gt) goto loc_825566C4;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
loc_82556260:
	// lbz r9,-3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -3);
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// lbz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + -4);
	// rotlwi r4,r9,8
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r9.u32, 8);
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rotlwi r9,r6,8
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 8);
	// or r6,r4,r5
	ctx.r6.u64 = ctx.r4.u64 | ctx.r5.u64;
	// lbz r5,-5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + -5);
	// or r4,r9,r3
	ctx.r4.u64 = ctx.r9.u64 | ctx.r3.u64;
	// lbz r3,-1(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// rlwinm r9,r6,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,-6(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + -6);
	// rlwinm r4,r4,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r30,-2(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// or r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 | ctx.r5.u64;
	// or r5,r4,r3
	ctx.r5.u64 = ctx.r4.u64 | ctx.r3.u64;
	// rlwinm r4,r9,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// rlwinm r3,r5,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0xFFFFFF00;
	// or r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 | ctx.r6.u64;
	// or r9,r3,r30
	ctx.r9.u64 = ctx.r3.u64 | r30.u64;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// beq cr6,0x825562cc
	if (cr6.eq) goto loc_825562CC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x82556260
	if (cr6.lt) goto loc_82556260;
	// b 0x825566c4
	goto loc_825566C4;
loc_825562CC:
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// b 0x825566c4
	goto loc_825566C4;
loc_825562D4:
	// addi r11,r28,1
	r11.s64 = r28.s64 + 1;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r8,r27,r11
	ctx.r8.u64 = r27.u64 + r11.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// lbz r7,-1(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r6,r27,r11
	ctx.r6.u64 = r27.u64 + r11.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// add r28,r7,r11
	r28.u64 = ctx.r7.u64 + r11.u64;
	// stwx r6,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556310:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556338:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwzx r11,r8,r10
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825563a0
	if (cr6.eq) goto loc_825563A0;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbz r8,-1(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// beq cr6,0x825563a0
	if (cr6.eq) goto loc_825563A0;
loc_82556380:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x825563a0
	if (cr0.eq) goto loc_825563A0;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556380
	if (!cr6.eq) goto loc_82556380;
loc_825563A0:
	// stb r26,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, r26.u8);
	// b 0x825566c4
	goto loc_825566C4;
loc_825563A8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lwzx r9,r5,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x825563f8
	if (!cr6.gt) goto loc_825563F8;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_825563F8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82556438
	if (!cr6.gt) goto loc_82556438;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
loc_82556410:
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// lwzx r4,r5,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne 0x82556410
	if (!cr0.eq) goto loc_82556410;
loc_82556438:
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// stb r26,-1(r11)
	PPC_STORE_U8(r11.u32 + -1, r26.u8);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556448:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r10
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82137a08
	ctx.lr = 0x82556480;
	sub_82137A08(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lbz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// add r7,r27,r28
	ctx.r7.u64 = r27.u64 + r28.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lbz r10,-1(r7)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r7.u32 + -1);
	// beq cr6,0x825564c0
	if (cr6.eq) goto loc_825564C0;
loc_8255649C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x825564c0
	if (cr0.eq) goto loc_825564C0;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8255649c
	if (!cr6.eq) goto loc_8255649C;
loc_825564C0:
	// stb r26,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r26.u8);
	// b 0x825566c4
	goto loc_825566C4;
loc_825564C8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lwzx r10,r7,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825566c4
	if (cr6.eq) goto loc_825566C4;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// add r8,r27,r28
	ctx.r8.u64 = r27.u64 + r28.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lbz r8,-1(r8)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + -1);
	// beq cr6,0x82556528
	if (cr6.eq) goto loc_82556528;
loc_82556510:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82556528
	if (cr0.eq) goto loc_82556528;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82556510
	if (!cr6.eq) goto loc_82556510;
loc_82556528:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82556554
	if (cr6.eq) goto loc_82556554;
loc_82556534:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82556554
	if (cr0.eq) goto loc_82556554;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82556534
	if (!cr6.eq) goto loc_82556534;
loc_82556554:
	// stb r26,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r26.u8);
	// b 0x825566c4
	goto loc_825566C4;
loc_8255655C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r10
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82137a08
	ctx.lr = 0x82556594;
	sub_82137A08(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lbz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// add r6,r27,r28
	ctx.r6.u64 = r27.u64 + r28.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lbz r10,-1(r6)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r6.u32 + -1);
	// beq cr6,0x825565c8
	if (cr6.eq) goto loc_825565C8;
loc_825565B0:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x825565c8
	if (cr0.eq) goto loc_825565C8;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825565b0
	if (!cr6.eq) goto loc_825565B0;
loc_825565C8:
	// lbz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825565f8
	if (cr6.eq) goto loc_825565F8;
loc_825565D4:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x825565f8
	if (cr0.eq) goto loc_825565F8;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825565d4
	if (!cr6.eq) goto loc_825565D4;
loc_825565F8:
	// stb r26,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r26.u8);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556600:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r28.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
	// stwx r20,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r20.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r7.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556630:
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// beq cr6,0x82556784
	if (cr6.eq) goto loc_82556784;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// lwz r7,72(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// stwx r9,r6,r11
	PPC_STORE_U32(ctx.r6.u32 + r11.u32, ctx.r9.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_82556680:
	// cmplwi cr6,r11,80
	cr6.compare<uint32_t>(r11.u32, 80, xer);
	// blt cr6,0x825566b8
	if (cr6.lt) goto loc_825566B8;
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82555e14
	if (!cr6.lt) goto loc_82555E14;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,-96
	ctx.r7.s64 = r11.s64 + -96;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r6.u32);
	// b 0x825566c4
	goto loc_825566C4;
loc_825566B8:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82554590
	ctx.lr = 0x825566C4;
	sub_82554590(ctx, base);
loc_825566C4:
	// lwz r11,0(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82554ea4
	if (!cr6.eq) goto loc_82554EA4;
loc_825566D0:
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
loc_825566DC:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_825566E8:
	// addi r11,r28,-7
	r11.s64 = r28.s64 + -7;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82556704:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13044
	ctx.r4.s64 = r11.s64 + -13044;
	// bl 0x82554590
	ctx.lr = 0x82556714;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82556724:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13084
	ctx.r4.s64 = r11.s64 + -13084;
	// bl 0x82554590
	ctx.lr = 0x82556734;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82556744:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13124
	ctx.r4.s64 = r11.s64 + -13124;
	// bl 0x82554590
	ctx.lr = 0x82556754;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82556764:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13140
	ctx.r4.s64 = r11.s64 + -13140;
	// bl 0x82554590
	ctx.lr = 0x82556774;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
loc_82556784:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-13160
	ctx.r4.s64 = r11.s64 + -13160;
	// bl 0x82554590
	ctx.lr = 0x82556794;
	sub_82554590(ctx, base);
	// stw r24,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r24.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_825567A4"))) PPC_WEAK_FUNC(sub_825567A4);
PPC_FUNC_IMPL(__imp__sub_825567A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825567A8"))) PPC_WEAK_FUNC(sub_825567A8);
PPC_FUNC_IMPL(__imp__sub_825567A8) {
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
	ctx.lr = 0x825567B0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r24,r11,-23608
	r24.s64 = r11.s64 + -23608;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,6(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825567f8
	if (!cr6.eq) goto loc_825567F8;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// sth r23,6(r24)
	PPC_STORE_U16(r24.u32 + 6, r23.u16);
	// beq cr6,0x825567f0
	if (cr6.eq) goto loc_825567F0;
	// rlwinm r3,r23,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x825567E8;
	sub_82130528(ctx, base);
	// stw r3,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r3.u32);
	// b 0x825567f8
	goto loc_825567F8;
loc_825567F0:
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
loc_825567F8:
	// rlwinm r31,r23,1,0,30
	r31.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r23,4(r24)
	PPC_STORE_U16(r24.u32 + 4, r23.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82556828
	if (cr6.eq) goto loc_82556828;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82556818;
	sub_82130528(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r11,r11,-23592
	r11.s64 = r11.s64 + -23592;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// b 0x82556838
	goto loc_82556838;
loc_82556828:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r11,r11,-23592
	r11.s64 = r11.s64 + -23592;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_82556838:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// sth r31,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r31.u16);
	// ble cr6,0x825568cc
	if (!cr6.gt) goto loc_825568CC;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r28,r30
	r28.u64 = r30.u64;
	// mr r29,r23
	r29.u64 = r23.u64;
	// li r27,-1
	r27.s64 = -1;
	// addi r26,r10,-13176
	r26.s64 = ctx.r10.s64 + -13176;
	// addi r25,r11,-13564
	r25.s64 = r11.s64 + -13564;
loc_82556860:
	// li r3,100
	ctx.r3.s64 = 100;
	// bl 0x82130528
	ctx.lr = 0x82556868;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825568b4
	if (cr6.eq) goto loc_825568B4;
	// li r5,76
	ctx.r5.s64 = 76;
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r26.u32);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// bl 0x823d9890
	ctx.lr = 0x8255689C;
	sub_823D9890(ctx, base);
	// stw r27,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r27.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// b 0x825568b8
	goto loc_825568B8;
loc_825568B4:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_825568B8:
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r11,r28,r10
	PPC_STORE_U32(r28.u32 + ctx.r10.u32, r11.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82556860
	if (!cr0.eq) goto loc_82556860;
loc_825568CC:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// beq cr6,0x825568e0
	if (cr6.eq) goto loc_825568E0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x825546f8
	ctx.lr = 0x825568E0;
	sub_825546F8(ctx, base);
loc_825568E0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_825568E8"))) PPC_WEAK_FUNC(sub_825568E8);
PPC_FUNC_IMPL(__imp__sub_825568E8) {
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
	ctx.lr = 0x825568F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r3,-23584(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23584);
	// bl 0x82130588
	ctx.lr = 0x82556900;
	sub_82130588(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r10,-23608
	r30.s64 = ctx.r10.s64 + -23608;
	// stw r11,-23584(r31)
	PPC_STORE_U32(r31.u32 + -23584, r11.u32);
	// li r29,0
	r29.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556960
	if (cr6.eq) goto loc_82556960;
	// li r31,0
	r31.s64 = 0;
loc_82556924:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255694c
	if (cr6.eq) goto loc_8255694C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82556948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
loc_8255694C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82556924
	if (cr6.lt) goto loc_82556924;
loc_82556960:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r29,0
	r29.s64 = 0;
	// addi r31,r11,-23592
	r31.s64 = r11.s64 + -23592;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825569a0
	if (cr6.eq) goto loc_825569A0;
	// li r28,0
	r28.s64 = 0;
loc_8255697C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8255698C;
	sub_82130588(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8255697c
	if (cr6.lt) goto loc_8255697C;
loc_825569A0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x825569A8;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// bl 0x82130588
	ctx.lr = 0x825569C8;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825569E8"))) PPC_WEAK_FUNC(sub_825569E8);
PPC_FUNC_IMPL(__imp__sub_825569E8) {
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
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82556a10
	if (!cr6.eq) goto loc_82556A10;
	// li r11,512
	r11.s64 = 512;
loc_82556A10:
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,4340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82556A30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82556a68
	if (!cr6.eq) goto loc_82556A68;
	// lwz r11,-23620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23620);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556ab0
	if (cr6.eq) goto loc_82556AB0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82556A68:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r31,-23620(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -23620);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// beq cr6,0x82556ab0
	if (cr6.eq) goto loc_82556AB0;
	// li r5,48
	ctx.r5.s64 = 48;
loc_82556A80:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82554d48
	ctx.lr = 0x82556A88;
	sub_82554D48(ctx, base);
	// lwzx r11,r3,r5
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82556aa4
	if (!cr6.eq) goto loc_82556AA4;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82554d48
	ctx.lr = 0x82556A9C;
	sub_82554D48(ctx, base);
	// lwzx r11,r5,r31
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// stwx r11,r3,r5
	PPC_STORE_U32(ctx.r3.u32 + ctx.r5.u32, r11.u32);
loc_82556AA4:
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpwi cr6,r5,64
	cr6.compare<int32_t>(ctx.r5.s32, 64, xer);
	// blt cr6,0x82556a80
	if (cr6.lt) goto loc_82556A80;
loc_82556AB0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82556AC4"))) PPC_WEAK_FUNC(sub_82556AC4);
PPC_FUNC_IMPL(__imp__sub_82556AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82556AC8"))) PPC_WEAK_FUNC(sub_82556AC8);
PPC_FUNC_IMPL(__imp__sub_82556AC8) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x82556af0
	if (!cr6.eq) goto loc_82556AF0;
	// li r6,512
	ctx.r6.s64 = 512;
loc_82556AF0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4340(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82556B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82556b4c
	if (!cr6.eq) goto loc_82556B4C;
	// lwz r11,-23620(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23620);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82556b94
	if (cr6.eq) goto loc_82556B94;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82556B4C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r31,-23620(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -23620);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// beq cr6,0x82556b94
	if (cr6.eq) goto loc_82556B94;
	// li r5,48
	ctx.r5.s64 = 48;
loc_82556B64:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82554d48
	ctx.lr = 0x82556B6C;
	sub_82554D48(ctx, base);
	// lwzx r11,r3,r5
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r5.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82556b88
	if (!cr6.eq) goto loc_82556B88;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82554d48
	ctx.lr = 0x82556B80;
	sub_82554D48(ctx, base);
	// lwzx r11,r5,r31
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + r31.u32);
	// stwx r11,r3,r5
	PPC_STORE_U32(ctx.r3.u32 + ctx.r5.u32, r11.u32);
loc_82556B88:
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// cmpwi cr6,r5,64
	cr6.compare<int32_t>(ctx.r5.s32, 64, xer);
	// blt cr6,0x82556b64
	if (cr6.lt) goto loc_82556B64;
loc_82556B94:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82556BA8"))) PPC_WEAK_FUNC(sub_82556BA8);
PPC_FUNC_IMPL(__imp__sub_82556BA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82556BB0;
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
	// bl 0x82557f10
	ctx.lr = 0x82556BC4;
	sub_82557F10(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82554a88
	ctx.lr = 0x82556BD8;
	sub_82554A88(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82556bf0
	if (cr6.eq) goto loc_82556BF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825578b8
	ctx.lr = 0x82556BEC;
	sub_825578B8(ctx, base);
	// bl 0x825579a0
	ctx.lr = 0x82556BF0;
	sub_825579A0(ctx, base);
loc_82556BF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82556BFC"))) PPC_WEAK_FUNC(sub_82556BFC);
PPC_FUNC_IMPL(__imp__sub_82556BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82556C00"))) PPC_WEAK_FUNC(sub_82556C00);
PPC_FUNC_IMPL(__imp__sub_82556C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82556C14"))) PPC_WEAK_FUNC(sub_82556C14);
PPC_FUNC_IMPL(__imp__sub_82556C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82556C18"))) PPC_WEAK_FUNC(sub_82556C18);
PPC_FUNC_IMPL(__imp__sub_82556C18) {
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
	ctx.lr = 0x82556C20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12504
	r30.s64 = r11.s64 + -12504;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556C34;
	sub_82557F78(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lis r10,-32171
	ctx.r10.s64 = -2108358656;
	// addi r31,r11,-23584
	r31.s64 = r11.s64 + -23584;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r10,15520
	ctx.r5.s64 = ctx.r10.s64 + 15520;
	// bl 0x825578c8
	ctx.lr = 0x82556C50;
	sub_825578C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r29,r11,-13448
	r29.s64 = r11.s64 + -13448;
	// bne cr6,0x82556c70
	if (!cr6.eq) goto loc_82556C70;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556C70;
	sub_821BD618(ctx, base);
loc_82556C70:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12512
	r30.s64 = r11.s64 + -12512;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556C80;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15544
	ctx.r5.s64 = r11.s64 + 15544;
	// bl 0x825578c8
	ctx.lr = 0x82556C94;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556cac
	if (!cr6.eq) goto loc_82556CAC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556CAC;
	sub_821BD618(ctx, base);
loc_82556CAC:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12524
	r30.s64 = r11.s64 + -12524;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556CBC;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15568
	ctx.r5.s64 = r11.s64 + 15568;
	// bl 0x825578c8
	ctx.lr = 0x82556CD0;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556ce8
	if (!cr6.eq) goto loc_82556CE8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556CE8;
	sub_821BD618(ctx, base);
loc_82556CE8:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12536
	r30.s64 = r11.s64 + -12536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556CF8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15592
	ctx.r5.s64 = r11.s64 + 15592;
	// bl 0x825578c8
	ctx.lr = 0x82556D0C;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556d24
	if (!cr6.eq) goto loc_82556D24;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556D24;
	sub_821BD618(ctx, base);
loc_82556D24:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12548
	r30.s64 = r11.s64 + -12548;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556D34;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15616
	ctx.r5.s64 = r11.s64 + 15616;
	// bl 0x825578c8
	ctx.lr = 0x82556D48;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556d60
	if (!cr6.eq) goto loc_82556D60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556D60;
	sub_821BD618(ctx, base);
loc_82556D60:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12568
	r30.s64 = r11.s64 + -12568;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556D70;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15640
	ctx.r5.s64 = r11.s64 + 15640;
	// bl 0x825578c8
	ctx.lr = 0x82556D84;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556d9c
	if (!cr6.eq) goto loc_82556D9C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556D9C;
	sub_821BD618(ctx, base);
loc_82556D9C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12576
	r30.s64 = r11.s64 + -12576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556DAC;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15664
	ctx.r5.s64 = r11.s64 + 15664;
	// bl 0x825578c8
	ctx.lr = 0x82556DC0;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556dd8
	if (!cr6.eq) goto loc_82556DD8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556DD8;
	sub_821BD618(ctx, base);
loc_82556DD8:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12592
	r30.s64 = r11.s64 + -12592;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556DE8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15824
	ctx.r5.s64 = r11.s64 + 15824;
	// bl 0x825578c8
	ctx.lr = 0x82556DFC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556e14
	if (!cr6.eq) goto loc_82556E14;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556E14;
	sub_821BD618(ctx, base);
loc_82556E14:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12608
	r30.s64 = r11.s64 + -12608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556E24;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,15984
	ctx.r5.s64 = r11.s64 + 15984;
	// bl 0x825578c8
	ctx.lr = 0x82556E38;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556e50
	if (!cr6.eq) goto loc_82556E50;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556E50;
	sub_821BD618(ctx, base);
loc_82556E50:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12620
	r30.s64 = r11.s64 + -12620;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556E60;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,19880
	ctx.r5.s64 = r11.s64 + 19880;
	// bl 0x825578c8
	ctx.lr = 0x82556E74;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556e8c
	if (!cr6.eq) goto loc_82556E8C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556E8C;
	sub_821BD618(ctx, base);
loc_82556E8C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12632
	r30.s64 = r11.s64 + -12632;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556E9C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16448
	ctx.r5.s64 = r11.s64 + 16448;
	// bl 0x825578c8
	ctx.lr = 0x82556EB0;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556ec8
	if (!cr6.eq) goto loc_82556EC8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556EC8;
	sub_821BD618(ctx, base);
loc_82556EC8:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12644
	r30.s64 = r11.s64 + -12644;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556ED8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16480
	ctx.r5.s64 = r11.s64 + 16480;
	// bl 0x825578c8
	ctx.lr = 0x82556EEC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556f04
	if (!cr6.eq) goto loc_82556F04;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556F04;
	sub_821BD618(ctx, base);
loc_82556F04:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12656
	r30.s64 = r11.s64 + -12656;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556F14;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16512
	ctx.r5.s64 = r11.s64 + 16512;
	// bl 0x825578c8
	ctx.lr = 0x82556F28;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556f40
	if (!cr6.eq) goto loc_82556F40;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556F40;
	sub_821BD618(ctx, base);
loc_82556F40:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12668
	r30.s64 = r11.s64 + -12668;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556F50;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16544
	ctx.r5.s64 = r11.s64 + 16544;
	// bl 0x825578c8
	ctx.lr = 0x82556F64;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556f7c
	if (!cr6.eq) goto loc_82556F7C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556F7C;
	sub_821BD618(ctx, base);
loc_82556F7C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12676
	r30.s64 = r11.s64 + -12676;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556F8C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16576
	ctx.r5.s64 = r11.s64 + 16576;
	// bl 0x825578c8
	ctx.lr = 0x82556FA0;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556fb8
	if (!cr6.eq) goto loc_82556FB8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556FB8;
	sub_821BD618(ctx, base);
loc_82556FB8:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12688
	r30.s64 = r11.s64 + -12688;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82556FC8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16592
	ctx.r5.s64 = r11.s64 + 16592;
	// bl 0x825578c8
	ctx.lr = 0x82556FDC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82556ff4
	if (!cr6.eq) goto loc_82556FF4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82556FF4;
	sub_821BD618(ctx, base);
loc_82556FF4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12700
	r30.s64 = r11.s64 + -12700;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557004;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16672
	ctx.r5.s64 = r11.s64 + 16672;
	// bl 0x825578c8
	ctx.lr = 0x82557018;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557030
	if (!cr6.eq) goto loc_82557030;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557030;
	sub_821BD618(ctx, base);
loc_82557030:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12704
	r30.s64 = r11.s64 + -12704;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557040;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16680
	ctx.r5.s64 = r11.s64 + 16680;
	// bl 0x825578c8
	ctx.lr = 0x82557054;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255706c
	if (!cr6.eq) goto loc_8255706C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255706C;
	sub_821BD618(ctx, base);
loc_8255706C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12708
	r30.s64 = r11.s64 + -12708;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255707C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16760
	ctx.r5.s64 = r11.s64 + 16760;
	// bl 0x825578c8
	ctx.lr = 0x82557090;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825570a8
	if (!cr6.eq) goto loc_825570A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825570A8;
	sub_821BD618(ctx, base);
loc_825570A8:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12716
	r30.s64 = r11.s64 + -12716;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825570B8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16840
	ctx.r5.s64 = r11.s64 + 16840;
	// bl 0x825578c8
	ctx.lr = 0x825570CC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825570e4
	if (!cr6.eq) goto loc_825570E4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825570E4;
	sub_821BD618(ctx, base);
loc_825570E4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12720
	r30.s64 = r11.s64 + -12720;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825570F4;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16864
	ctx.r5.s64 = r11.s64 + 16864;
	// bl 0x825578c8
	ctx.lr = 0x82557108;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557120
	if (!cr6.eq) goto loc_82557120;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557120;
	sub_821BD618(ctx, base);
loc_82557120:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12724
	r30.s64 = r11.s64 + -12724;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557130;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,16936
	ctx.r5.s64 = r11.s64 + 16936;
	// bl 0x825578c8
	ctx.lr = 0x82557144;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255715c
	if (!cr6.eq) goto loc_8255715C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255715C;
	sub_821BD618(ctx, base);
loc_8255715C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12732
	r30.s64 = r11.s64 + -12732;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255716C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17000
	ctx.r5.s64 = r11.s64 + 17000;
	// bl 0x825578c8
	ctx.lr = 0x82557180;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557198
	if (!cr6.eq) goto loc_82557198;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557198;
	sub_821BD618(ctx, base);
loc_82557198:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12740
	r30.s64 = r11.s64 + -12740;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825571A8;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17048
	ctx.r5.s64 = r11.s64 + 17048;
	// bl 0x825578c8
	ctx.lr = 0x825571BC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825571d4
	if (!cr6.eq) goto loc_825571D4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825571D4;
	sub_821BD618(ctx, base);
loc_825571D4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12748
	r30.s64 = r11.s64 + -12748;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825571E4;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17088
	ctx.r5.s64 = r11.s64 + 17088;
	// bl 0x825578c8
	ctx.lr = 0x825571F8;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557210
	if (!cr6.eq) goto loc_82557210;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557210;
	sub_821BD618(ctx, base);
loc_82557210:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12756
	r30.s64 = r11.s64 + -12756;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557220;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17160
	ctx.r5.s64 = r11.s64 + 17160;
	// bl 0x825578c8
	ctx.lr = 0x82557234;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255724c
	if (!cr6.eq) goto loc_8255724C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255724C;
	sub_821BD618(ctx, base);
loc_8255724C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12768
	r30.s64 = r11.s64 + -12768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255725C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17256
	ctx.r5.s64 = r11.s64 + 17256;
	// bl 0x825578c8
	ctx.lr = 0x82557270;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557288
	if (!cr6.eq) goto loc_82557288;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557288;
	sub_821BD618(ctx, base);
loc_82557288:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12780
	r30.s64 = r11.s64 + -12780;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557298;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17224
	ctx.r5.s64 = r11.s64 + 17224;
	// bl 0x825578c8
	ctx.lr = 0x825572AC;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825572c4
	if (!cr6.eq) goto loc_825572C4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825572C4;
	sub_821BD618(ctx, base);
loc_825572C4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12800
	r30.s64 = r11.s64 + -12800;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825572D4;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,27112
	ctx.r5.s64 = r11.s64 + 27112;
	// bl 0x825578c8
	ctx.lr = 0x825572E8;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557300
	if (!cr6.eq) goto loc_82557300;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557300;
	sub_821BD618(ctx, base);
loc_82557300:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12828
	r30.s64 = r11.s64 + -12828;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557310;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,27336
	ctx.r5.s64 = r11.s64 + 27336;
	// bl 0x825578c8
	ctx.lr = 0x82557324;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255733c
	if (!cr6.eq) goto loc_8255733C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255733C;
	sub_821BD618(ctx, base);
loc_8255733C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12836
	r30.s64 = r11.s64 + -12836;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255734C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17288
	ctx.r5.s64 = r11.s64 + 17288;
	// bl 0x825578c8
	ctx.lr = 0x82557360;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557378
	if (!cr6.eq) goto loc_82557378;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557378;
	sub_821BD618(ctx, base);
loc_82557378:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12844
	r30.s64 = r11.s64 + -12844;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557388;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17360
	ctx.r5.s64 = r11.s64 + 17360;
	// bl 0x825578c8
	ctx.lr = 0x8255739C;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825573b4
	if (!cr6.eq) goto loc_825573B4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825573B4;
	sub_821BD618(ctx, base);
loc_825573B4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12852
	r30.s64 = r11.s64 + -12852;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825573C4;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17432
	ctx.r5.s64 = r11.s64 + 17432;
	// bl 0x825578c8
	ctx.lr = 0x825573D8;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825573f0
	if (!cr6.eq) goto loc_825573F0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825573F0;
	sub_821BD618(ctx, base);
loc_825573F0:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12864
	r30.s64 = r11.s64 + -12864;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557400;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17512
	ctx.r5.s64 = r11.s64 + 17512;
	// bl 0x825578c8
	ctx.lr = 0x82557414;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255742c
	if (!cr6.eq) goto loc_8255742C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255742C;
	sub_821BD618(ctx, base);
loc_8255742C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12884
	r30.s64 = r11.s64 + -12884;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255743C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,27648
	ctx.r5.s64 = r11.s64 + 27648;
	// bl 0x825578c8
	ctx.lr = 0x82557450;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557468
	if (!cr6.eq) goto loc_82557468;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557468;
	sub_821BD618(ctx, base);
loc_82557468:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12912
	r30.s64 = r11.s64 + -12912;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557478;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,19904
	ctx.r5.s64 = r11.s64 + 19904;
	// bl 0x825578c8
	ctx.lr = 0x8255748C;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825574a4
	if (!cr6.eq) goto loc_825574A4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825574A4;
	sub_821BD618(ctx, base);
loc_825574A4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12944
	r30.s64 = r11.s64 + -12944;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825574B4;
	sub_82557F78(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,0
	ctx.r5.s64 = r11.s64 + 0;
	// bl 0x825578c8
	ctx.lr = 0x825574C8;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825574e0
	if (!cr6.eq) goto loc_825574E0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x825574E0;
	sub_821BD618(ctx, base);
loc_825574E0:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-12972
	r30.s64 = r11.s64 + -12972;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x825574F0;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,19904
	ctx.r5.s64 = r11.s64 + 19904;
	// bl 0x825578c8
	ctx.lr = 0x82557504;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255751c
	if (!cr6.eq) goto loc_8255751C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x8255751C;
	sub_821BD618(ctx, base);
loc_8255751C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-13004
	r30.s64 = r11.s64 + -13004;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82557f78
	ctx.lr = 0x8255752C;
	sub_82557F78(ctx, base);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,17552
	ctx.r5.s64 = r11.s64 + 17552;
	// bl 0x825578c8
	ctx.lr = 0x82557540;
	sub_825578C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82557558
	if (!cr6.eq) goto loc_82557558;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821bd618
	ctx.lr = 0x82557558;
	sub_821BD618(ctx, base);
loc_82557558:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82557560"))) PPC_WEAK_FUNC(sub_82557560);
PPC_FUNC_IMPL(__imp__sub_82557560) {
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
	ctx.lr = 0x82557568;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lis r11,16383
	r11.s64 = 1073676288;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// ori r31,r11,65535
	r31.u64 = r11.u64 | 65535;
	// li r29,-1
	r29.s64 = -1;
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// stw r3,-23560(r30)
	PPC_STORE_U32(r30.u32 + -23560, ctx.r3.u32);
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82557594
	if (!cr6.gt) goto loc_82557594;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82557594:
	// bl 0x82130528
	ctx.lr = 0x82557598;
	sub_82130528(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r11,-23560(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23560);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// stw r3,-23564(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23564, ctx.r3.u32);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x825575b4
	if (!cr6.gt) goto loc_825575B4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_825575B4:
	// bl 0x82130528
	ctx.lr = 0x825575B8;
	sub_82130528(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stw r3,-23568(r11)
	PPC_STORE_U32(r11.u32 + -23568, ctx.r3.u32);
	// stw r28,-23556(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23556, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825575D0"))) PPC_WEAK_FUNC(sub_825575D0);
PPC_FUNC_IMPL(__imp__sub_825575D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// sth r9,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, ctx.r9.u16);
	// lwz r11,-23552(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23552);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-23552(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23552, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825575F0"))) PPC_WEAK_FUNC(sub_825575F0);
PPC_FUNC_IMPL(__imp__sub_825575F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x821ca2f8
	sub_821CA2F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82557614"))) PPC_WEAK_FUNC(sub_82557614);
PPC_FUNC_IMPL(__imp__sub_82557614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82557618"))) PPC_WEAK_FUNC(sub_82557618);
PPC_FUNC_IMPL(__imp__sub_82557618) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8255762c
	if (!cr6.eq) goto loc_8255762C;
loc_82557624:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8255762C:
	// divwu r11,r4,r9
	r11.u32 = ctx.r4.u32 / ctx.r9.u32;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// twllei r9,0
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// subf r11,r8,r4
	r11.s64 = ctx.r4.s64 - ctx.r8.s64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r6,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x82557688
	if (cr6.eq) goto loc_82557688;
loc_82557654:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82557624
	if (cr6.eq) goto loc_82557624;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// twllei r9,0
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// divwu r8,r11,r9
	ctx.r8.u32 = r11.u32 / ctx.r9.u32;
	// mullw r6,r8,r9
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r8,r5,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// bne cr6,0x82557654
	if (!cr6.eq) goto loc_82557654;
loc_82557688:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82557624
	if (cr6.eq) goto loc_82557624;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825576A0"))) PPC_WEAK_FUNC(sub_825576A0);
PPC_FUNC_IMPL(__imp__sub_825576A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// divwu r10,r4,r8
	ctx.r10.u32 = ctx.r4.u32 / ctx.r8.u32;
	// twllei r8,0
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// subf r10,r9,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r9.s64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8255770c
	if (cr6.eq) goto loc_8255770C;
loc_825576D0:
	// lwzx r9,r6,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// beq cr6,0x82557714
	if (cr6.eq) goto loc_82557714;
	// rlwinm r9,r7,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// twllei r8,0
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// add r3,r7,r10
	ctx.r3.u64 = ctx.r7.u64 + ctx.r10.u64;
	// divwu r10,r3,r8
	ctx.r10.u32 = ctx.r3.u32 / ctx.r8.u32;
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// subf r10,r9,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r5,r9,r5
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x825576d0
	if (!cr6.eq) goto loc_825576D0;
loc_8255770C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82557714:
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r9,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82557744"))) PPC_WEAK_FUNC(sub_82557744);
PPC_FUNC_IMPL(__imp__sub_82557744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82557748"))) PPC_WEAK_FUNC(sub_82557748);
PPC_FUNC_IMPL(__imp__sub_82557748) {
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
	ctx.lr = 0x82557750;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r26,r11,-23548
	r26.s64 = r11.s64 + -23548;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// lwz r11,-23544(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23544);
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825577b0
	if (!cr6.eq) goto loc_825577B0;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r9,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r9.u32);
	// stw r11,-23544(r10)
	PPC_STORE_U32(ctx.r10.u32 + -23544, r11.u32);
	// lis r11,-32132
	r11.s64 = -2105802752;
	// addi r3,r11,-14496
	ctx.r3.s64 = r11.s64 + -14496;
	// bl 0x823d9a98
	ctx.lr = 0x825577B0;
	sub_823D9A98(ctx, base);
loc_825577B0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82557f78
	ctx.lr = 0x825577B8;
	sub_82557F78(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x825577C8;
	sub_82130528(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2a58
	ctx.lr = 0x825577D8;
	sub_821D2A58(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// sth r10,24(r31)
	PPC_STORE_U16(r31.u32 + 24, ctx.r10.u16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r30,r11,-23552
	r30.s64 = r11.s64 + -23552;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,-23552(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23552);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// bl 0x823da950
	ctx.lr = 0x82557804;
	sub_823DA950(ctx, base);
	// lwz r27,252(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82557854
	if (cr6.eq) goto loc_82557854;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82557560
	ctx.lr = 0x8255781C;
	sub_82557560(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-23564(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23564);
	// bl 0x823da950
	ctx.lr = 0x82557834;
	sub_823DA950(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-23568(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23568);
	// bl 0x823da950
	ctx.lr = 0x82557848;
	sub_823DA950(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d2a58
	ctx.lr = 0x82557854;
	sub_821D2A58(ctx, base);
loc_82557854:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82557884
	if (cr6.eq) goto loc_82557884;
	// lwz r11,-4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82557884
	if (cr6.eq) goto loc_82557884;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// beq cr6,0x82557884
	if (cr6.eq) goto loc_82557884;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lwz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-12480
	ctx.r3.s64 = r11.s64 + -12480;
	// bl 0x821bd618
	ctx.lr = 0x82557884;
	sub_821BD618(ctx, base);
loc_82557884:
	// sth r24,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r24.u16);
	// rlwinm r3,r24,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FFFC;
	// bl 0x82130528
	ctx.lr = 0x82557890;
	sub_82130528(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// rlwinm r5,r24,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x823da950
	ctx.lr = 0x825578A0;
	sub_823DA950(ctx, base);
	// lwz r10,244(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r10,22(r31)
	PPC_STORE_U16(r31.u32 + 22, ctx.r10.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_825578B4"))) PPC_WEAK_FUNC(sub_825578B4);
PPC_FUNC_IMPL(__imp__sub_825578B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825578B8"))) PPC_WEAK_FUNC(sub_825578B8);
PPC_FUNC_IMPL(__imp__sub_825578B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,4404
	ctx.r3.s64 = r11.s64 + 4404;
	// b 0x82557618
	sub_82557618(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_825578C8"))) PPC_WEAK_FUNC(sub_825578C8);
PPC_FUNC_IMPL(__imp__sub_825578C8) {
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
	ctx.lr = 0x825578D0;
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x825578f4
	if (!cr6.eq) goto loc_825578F4;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82554500
	ctx.lr = 0x825578F4;
	sub_82554500(ctx, base);
loc_825578F4:
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x82557910
	if (!cr6.eq) goto loc_82557910;
loc_82557904:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82557910:
	// divwu r11,r30,r8
	r11.u32 = r30.u32 / ctx.r8.u32;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r8,0
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// subf r11,r10,r30
	r11.s64 = r30.s64 - ctx.r10.s64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// ble cr6,0x82557974
	if (!cr6.gt) goto loc_82557974;
loc_82557938:
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x82557904
	if (cr6.eq) goto loc_82557904;
	// rlwinm r10,r9,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r8,0
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// divwu r4,r5,r8
	ctx.r4.u32 = ctx.r5.u32 / ctx.r8.u32;
	// mullw r3,r4,r8
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// subf r11,r3,r5
	r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r6,r10,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// cmplwi cr6,r6,1
	cr6.compare<uint32_t>(ctx.r6.u32, 1, xer);
	// bgt cr6,0x82557938
	if (cr6.gt) goto loc_82557938;
loc_82557974:
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r30,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, r30.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_825579A0"))) PPC_WEAK_FUNC(sub_825579A0);
PPC_FUNC_IMPL(__imp__sub_825579A0) {
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
	ctx.lr = 0x825579A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,-23556
	r31.s64 = r11.s64 + -23556;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bne 0x82557a04
	if (!cr0.eq) goto loc_82557A04;
	// lis r29,-32114
	r29.s64 = -2104623104;
	// lwz r3,-23564(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -23564);
	// bl 0x82130588
	ctx.lr = 0x825579D4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r28,-32114
	r28.s64 = -2104623104;
	// stw r11,-23564(r29)
	PPC_STORE_U32(r29.u32 + -23564, r11.u32);
	// lwz r3,-23568(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -23568);
	// bl 0x82130588
	ctx.lr = 0x825579E8;
	sub_82130588(ctx, base);
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-23568(r28)
	PPC_STORE_U32(r28.u32 + -23568, r11.u32);
	// stw r10,-23560(r8)
	PPC_STORE_U32(ctx.r8.u32 + -23560, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_82557A04:
	// lhz r11,24(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// sth r9,24(r30)
	PPC_STORE_U16(r30.u32 + 24, ctx.r9.u16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82557a5c
	if (!cr6.eq) goto loc_82557A5C;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r11,4404
	ctx.r3.s64 = r11.s64 + 4404;
	// bl 0x825576a0
	ctx.lr = 0x82557A30;
	sub_825576A0(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82557A38;
	sub_82130588(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x82557A40;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82557A48;
	sub_821D2AA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82557A50;
	sub_82130588(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82557A5C:
	// lhz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82557A68"))) PPC_WEAK_FUNC(sub_82557A68);
PPC_FUNC_IMPL(__imp__sub_82557A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82557A70;
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82557f78
	ctx.lr = 0x82557A84;
	sub_82557F78(ctx, base);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r24,r11,4404
	r24.s64 = r11.s64 + 4404;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82557618
	ctx.lr = 0x82557A9C;
	sub_82557618(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82557ad0
	if (cr6.eq) goto loc_82557AD0;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lhz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 24);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// sth r8,24(r11)
	PPC_STORE_U16(r11.u32 + 24, ctx.r8.u16);
	// lwz r10,-23552(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23552);
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// stw r11,-23552(r9)
	PPC_STORE_U32(ctx.r9.u32 + -23552, r11.u32);
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// b 0x823d9234
	return;
loc_82557AD0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-23620
	ctx.r5.s64 = r11.s64 + -23620;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82557AF0;
	sub_821CA6A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82557b68
	if (cr6.eq) goto loc_82557B68;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,-12076
	ctx.r3.s64 = r11.s64 + -12076;
	// bl 0x82130000
	ctx.lr = 0x82557B0C;
	sub_82130000(ctx, base);
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x82557B1C;
	sub_821BE710(ctx, base);
	// lis r10,3666
	ctx.r10.s64 = 240254976;
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lis r9,3698
	ctx.r9.s64 = 242352128;
	// ori r8,r10,17235
	ctx.r8.u64 = ctx.r10.u64 | 17235;
	// ori r11,r9,25427
	r11.u64 = ctx.r9.u64 | 25427;
	// cmpw cr6,r6,r8
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r8.s32, xer);
	// beq cr6,0x82557b74
	if (cr6.eq) goto loc_82557B74;
	// lis r10,3698
	ctx.r10.s64 = 242352128;
	// ori r5,r10,25459
	ctx.r5.u64 = ctx.r10.u64 | 25459;
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// beq cr6,0x82557b74
	if (cr6.eq) goto loc_82557B74;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// beq cr6,0x82557b74
	if (cr6.eq) goto loc_82557B74;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,-12144
	ctx.r3.s64 = r11.s64 + -12144;
	// bl 0x82130000
	ctx.lr = 0x82557B60;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x82557B68;
	sub_821BE610(ctx, base);
loc_82557B68:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// b 0x823d9234
	return;
loc_82557B74:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bne cr6,0x82557b94
	if (!cr6.eq) goto loc_82557B94;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be710
	ctx.lr = 0x82557B94;
	sub_821BE710(ctx, base);
loc_82557B94:
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82130528
	ctx.lr = 0x82557B9C;
	sub_82130528(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// ori r31,r10,65535
	r31.u64 = ctx.r10.u64 | 65535;
	// li r29,-1
	r29.s64 = -1;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82557bc0
	if (!cr6.gt) goto loc_82557BC0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82557BC0:
	// bl 0x82130528
	ctx.lr = 0x82557BC4;
	sub_82130528(ctx, base);
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82557bdc
	if (!cr6.gt) goto loc_82557BDC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82557BDC:
	// bl 0x82130528
	ctx.lr = 0x82557BE0;
	sub_82130528(ctx, base);
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82557d30
	if (cr6.eq) goto loc_82557D30;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82130528
	ctx.lr = 0x82557BF8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x82557C0C;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x82557C14;
	sub_821BE610(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821e1610
	ctx.lr = 0x82557C1C;
	sub_821E1610(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x821e1658
	ctx.lr = 0x82557C2C;
	sub_821E1658(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82557C3C:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x82557c3c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82557C3C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,56
	ctx.r5.s64 = 56;
	// addi r4,r11,11424
	ctx.r4.s64 = r11.s64 + 11424;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821dece0
	ctx.lr = 0x82557C5C;
	sub_821DECE0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82557c70
	if (!cr6.lt) goto loc_82557C70;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-12168
	ctx.r3.s64 = r11.s64 + -12168;
	// bl 0x821bd618
	ctx.lr = 0x82557C70;
	sub_821BD618(ctx, base);
loc_82557C70:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stw r27,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r27.u32);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// bl 0x821dee40
	ctx.lr = 0x82557C94;
	sub_821DEE40(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r30,r11,-12200
	r30.s64 = r11.s64 + -12200;
	// bge cr6,0x82557cb4
	if (!cr6.lt) goto loc_82557CB4;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-12208
	ctx.r4.s64 = r11.s64 + -12208;
	// bl 0x821bd618
	ctx.lr = 0x82557CB4;
	sub_821BD618(ctx, base);
loc_82557CB4:
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// bl 0x821dee40
	ctx.lr = 0x82557CD0;
	sub_821DEE40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82557ce8
	if (!cr6.lt) goto loc_82557CE8;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-12216
	ctx.r4.s64 = r11.s64 + -12216;
	// bl 0x821bd618
	ctx.lr = 0x82557CE8;
	sub_821BD618(ctx, base);
loc_82557CE8:
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r29,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r29.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// bl 0x821dee40
	ctx.lr = 0x82557D04;
	sub_821DEE40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82557d1c
	if (!cr6.lt) goto loc_82557D1C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-12224
	ctx.r4.s64 = r11.s64 + -12224;
	// bl 0x821bd618
	ctx.lr = 0x82557D1C;
	sub_821BD618(ctx, base);
loc_82557D1C:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821e05e0
	ctx.lr = 0x82557D24;
	sub_821E05E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82557D2C;
	sub_82130588(ctx, base);
	// b 0x82557db0
	goto loc_82557DB0;
loc_82557D30:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821e1610
	ctx.lr = 0x82557D38;
	sub_821E1610(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x821be250
	ctx.lr = 0x82557D48;
	sub_821BE250(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821be250
	ctx.lr = 0x82557D5C;
	sub_821BE250(ctx, base);
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821be250
	ctx.lr = 0x82557D70;
	sub_821BE250(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821be610
	ctx.lr = 0x82557D78;
	sub_821BE610(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x821e1658
	ctx.lr = 0x82557D88;
	sub_821E1658(ctx, base);
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821e1658
	ctx.lr = 0x82557D9C;
	sub_821E1658(ctx, base);
	// lwz r8,124(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821e1658
	ctx.lr = 0x82557DB0;
	sub_821E1658(ctx, base);
loc_82557DB0:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x82557DB8;
	sub_82130000(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x82554630
	ctx.lr = 0x82557DC4;
	sub_82554630(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82557de0
	if (!cr6.eq) goto loc_82557DE0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,-12296
	ctx.r3.s64 = r11.s64 + -12296;
	// bl 0x82130000
	ctx.lr = 0x82557DE0;
	sub_82130000(ctx, base);
loc_82557DE0:
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82557e20
	if (cr6.eq) goto loc_82557E20;
loc_82557DF0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwimi r8,r9,16,16,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF) | (ctx.r8.u64 & 0xFFFFFFFFFFFF0000);
	// rlwimi r7,r9,16,0,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF0000) | (ctx.r7.u64 & 0xFFFFFFFF0000FFFF);
	// rlwinm r6,r8,24,16,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFF;
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82557df0
	if (!cr0.eq) goto loc_82557DF0;
loc_82557E20:
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82557e60
	if (cr6.eq) goto loc_82557E60;
loc_82557E30:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rlwimi r8,r9,16,16,31
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF) | (ctx.r8.u64 & 0xFFFFFFFFFFFF0000);
	// rlwimi r7,r9,16,0,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFFFF0000) | (ctx.r7.u64 & 0xFFFFFFFF0000FFFF);
	// rlwinm r6,r8,24,16,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFF;
	// rlwinm r5,r7,8,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFF0000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82557e30
	if (!cr0.eq) goto loc_82557E30;
loc_82557E60:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82557E68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82557ea8
	if (cr6.eq) goto loc_82557EA8;
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r31,128(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x82557748
	ctx.lr = 0x82557EA0;
	sub_82557748(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82557eac
	goto loc_82557EAC;
loc_82557EA8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82557EAC:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x825578c8
	ctx.lr = 0x82557EB8;
	sub_825578C8(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x82557EC0;
	sub_82130588(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x82557EC8;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82557ED0;
	sub_82130588(ctx, base);
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82557f00
	if (cr6.eq) goto loc_82557F00;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-23552
	ctx.r10.s64 = r11.s64 + -23552;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82557f00
	if (!cr6.eq) goto loc_82557F00;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r11,-12408
	ctx.r3.s64 = r11.s64 + -12408;
	// bl 0x821bd618
	ctx.lr = 0x82557F00;
	sub_821BD618(ctx, base);
loc_82557F00:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82557F0C"))) PPC_WEAK_FUNC(sub_82557F0C);
PPC_FUNC_IMPL(__imp__sub_82557F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82557F10"))) PPC_WEAK_FUNC(sub_82557F10);
PPC_FUNC_IMPL(__imp__sub_82557F10) {
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
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r6,r10,-23620
	ctx.r6.s64 = ctx.r10.s64 + -23620;
	// lwz r9,4400(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4400);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82557F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821ca8c8
	ctx.lr = 0x82557F58;
	sub_821CA8C8(ctx, base);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82557a68
	ctx.lr = 0x82557F64;
	sub_82557A68(ctx, base);
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

__attribute__((alias("__imp__sub_82557F78"))) PPC_WEAK_FUNC(sub_82557F78);
PPC_FUNC_IMPL(__imp__sub_82557F78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// li r8,0
	ctx.r8.s64 = 0;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// addi r10,r11,-34
	ctx.r10.s64 = r11.s64 + -34;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82557fa0
	if (cr6.eq) goto loc_82557FA0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82557FA0:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82558018
	if (cr6.eq) goto loc_82558018;
loc_82557FB0:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82557fc0
	if (cr6.eq) goto loc_82557FC0;
	// cmpwi cr6,r9,34
	cr6.compare<int32_t>(ctx.r9.s32, 34, xer);
	// beq cr6,0x82558018
	if (cr6.eq) goto loc_82558018;
loc_82557FC0:
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// blt cr6,0x82557fe4
	if (cr6.lt) goto loc_82557FE4;
	// cmpwi cr6,r11,90
	cr6.compare<int32_t>(r11.s32, 90, xer);
	// bgt cr6,0x82557fe4
	if (cr6.gt) goto loc_82557FE4;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// b 0x82557ff0
	goto loc_82557FF0;
loc_82557FE4:
	// cmpwi cr6,r11,92
	cr6.compare<int32_t>(r11.s32, 92, xer);
	// bne cr6,0x82557ff0
	if (!cr6.eq) goto loc_82557FF0;
	// li r10,47
	ctx.r10.s64 = 47;
loc_82557FF0:
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// rlwinm r8,r11,10,0,21
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0xFFFFFC00;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r8,r11,26,6,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x3FFFFFF;
	// xor r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 ^ r11.u64;
	// bne cr6,0x82557fb0
	if (!cr6.eq) goto loc_82557FB0;
loc_82558018:
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r10,r11,21,11,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1FFFFF;
	// xor r11,r10,r11
	r11.u64 = ctx.r10.u64 ^ r11.u64;
	// rlwinm r10,r11,15,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0xFFFF8000;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558040"))) PPC_WEAK_FUNC(sub_82558040);
PPC_FUNC_IMPL(__imp__sub_82558040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82558048;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r10,-11756
	ctx.r6.s64 = ctx.r10.s64 + -11756;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lfs f13,-13148(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// stfs f13,100(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// li r4,176
	ctx.r4.s64 = 176;
	// li r31,160
	r31.s64 = 160;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// li r30,192
	r30.s64 = 192;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r29,208
	r29.s64 = 208;
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// li r28,64
	r28.s64 = 64;
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// addi r10,r3,240
	ctx.r10.s64 = ctx.r3.s64 + 240;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f13,31308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stfs f13,116(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f13,80(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// addi r9,r3,304
	ctx.r9.s64 = ctx.r3.s64 + 304;
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f13,88(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stb r11,152(r3)
	PPC_STORE_U8(ctx.r3.u32 + 152, r11.u8);
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stfs f0,224(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stvx128 v63,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stvx128 v63,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stvx128 v63,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stvx128 v63,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82558170"))) PPC_WEAK_FUNC(sub_82558170);
PPC_FUNC_IMPL(__imp__sub_82558170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-11756
	ctx.r10.s64 = r11.s64 + -11756;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82558180"))) PPC_WEAK_FUNC(sub_82558180);
PPC_FUNC_IMPL(__imp__sub_82558180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r6,64
	ctx.r6.s64 = 64;
	// addi r11,r3,240
	r11.s64 = ctx.r3.s64 + 240;
	// li r7,16
	ctx.r7.s64 = 16;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r9,48
	ctx.r9.s64 = 48;
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// addi r10,r3,304
	ctx.r10.s64 = ctx.r3.s64 + 304;
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,224(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r5,152(r3)
	PPC_STORE_U8(ctx.r3.u32 + 152, ctx.r5.u8);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,128(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
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

__attribute__((alias("__imp__sub_82558220"))) PPC_WEAK_FUNC(sub_82558220);
PPC_FUNC_IMPL(__imp__sub_82558220) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558224"))) PPC_WEAK_FUNC(sub_82558224);
PPC_FUNC_IMPL(__imp__sub_82558224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558228"))) PPC_WEAK_FUNC(sub_82558228);
PPC_FUNC_IMPL(__imp__sub_82558228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// li r9,432
	ctx.r9.s64 = 432;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lfs f0,276(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-32032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v63,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f8,224(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// lvx128 v61,r10,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v62
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255828C"))) PPC_WEAK_FUNC(sub_8255828C);
PPC_FUNC_IMPL(__imp__sub_8255828C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558290"))) PPC_WEAK_FUNC(sub_82558290);
PPC_FUNC_IMPL(__imp__sub_82558290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,160
	r11.s64 = 160;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825582A0"))) PPC_WEAK_FUNC(sub_825582A0);
PPC_FUNC_IMPL(__imp__sub_825582A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,176
	r11.s64 = 176;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825582B0"))) PPC_WEAK_FUNC(sub_825582B0);
PPC_FUNC_IMPL(__imp__sub_825582B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x825582B8;
	// addi r11,r3,240
	r11.s64 = ctx.r3.s64 + 240;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
	// li r31,16
	r31.s64 = 16;
	// addi r8,r4,32
	ctx.r8.s64 = ctx.r4.s64 + 32;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r7,r4,48
	ctx.r7.s64 = ctx.r4.s64 + 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,304
	ctx.r10.s64 = ctx.r3.s64 + 304;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32122
	r30.s64 = -2105147392;
	// stvx128 v61,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,96
	r29.s64 = 96;
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,2384
	r30.s64 = r30.s64 + 2384;
	// stvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32122
	r28.s64 = -2105147392;
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r28,2352
	ctx.r4.s64 = r28.s64 + 2352;
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,352
	r28.s64 = 352;
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r31
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r3,r29
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v50,v51,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v49,v52,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v54,v55
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v47,v63,v50
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// vmrglw128 v46,v52,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrglw128 v45,v54,v55
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v44,v49,v48
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v43,v49,v48
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v42,v46,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum4fp128 v41,v47,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v40,v47,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmsum4fp128 v39,v47,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmrghw128 v38,v41,v47
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v40,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v37,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// stvx128 v36,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82558390"))) PPC_WEAK_FUNC(sub_82558390);
PPC_FUNC_IMPL(__imp__sub_82558390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r8,r1,28
	ctx.r8.s64 = ctx.r1.s64 + 28;
	// stfs f1,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 28, temp.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r1,28
	ctx.r9.s64 = ctx.r1.s64 + 28;
	// li r11,48
	r11.s64 = 48;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvx128 v0,r5,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r6,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v10,v13,v12,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v11,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stvx128 v10,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r5,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r6,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v9,v60,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v9,v11,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v8,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825583E0"))) PPC_WEAK_FUNC(sub_825583E0);
PPC_FUNC_IMPL(__imp__sub_825583E0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-11756
	ctx.r10.s64 = r11.s64 + -11756;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8255840C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82558424
	if (cr6.eq) goto loc_82558424;
	// bl 0x82130588
	ctx.lr = 0x82558420;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82558424:
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

__attribute__((alias("__imp__sub_8255843C"))) PPC_WEAK_FUNC(sub_8255843C);
PPC_FUNC_IMPL(__imp__sub_8255843C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558440"))) PPC_WEAK_FUNC(sub_82558440);
PPC_FUNC_IMPL(__imp__sub_82558440) {
	PPC_FUNC_PROLOGUE();
	// b 0x825582b0
	sub_825582B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82558444"))) PPC_WEAK_FUNC(sub_82558444);
PPC_FUNC_IMPL(__imp__sub_82558444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558448"))) PPC_WEAK_FUNC(sub_82558448);
PPC_FUNC_IMPL(__imp__sub_82558448) {
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
	// bl 0x825640f8
	ctx.lr = 0x82558460;
	sub_825640F8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,-11696
	ctx.r7.s64 = r11.s64 + -11696;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lfs f13,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f12,52(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_825584B4"))) PPC_WEAK_FUNC(sub_825584B4);
PPC_FUNC_IMPL(__imp__sub_825584B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825584B8"))) PPC_WEAK_FUNC(sub_825584B8);
PPC_FUNC_IMPL(__imp__sub_825584B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23488(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23488);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825584C4"))) PPC_WEAK_FUNC(sub_825584C4);
PPC_FUNC_IMPL(__imp__sub_825584C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825584C8"))) PPC_WEAK_FUNC(sub_825584C8);
PPC_FUNC_IMPL(__imp__sub_825584C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f1,24(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825584EC"))) PPC_WEAK_FUNC(sub_825584EC);
PPC_FUNC_IMPL(__imp__sub_825584EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825584F0"))) PPC_WEAK_FUNC(sub_825584F0);
PPC_FUNC_IMPL(__imp__sub_825584F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-11372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558504"))) PPC_WEAK_FUNC(sub_82558504);
PPC_FUNC_IMPL(__imp__sub_82558504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558508"))) PPC_WEAK_FUNC(sub_82558508);
PPC_FUNC_IMPL(__imp__sub_82558508) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-11372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255851C"))) PPC_WEAK_FUNC(sub_8255851C);
PPC_FUNC_IMPL(__imp__sub_8255851C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558520"))) PPC_WEAK_FUNC(sub_82558520);
PPC_FUNC_IMPL(__imp__sub_82558520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-11372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558534"))) PPC_WEAK_FUNC(sub_82558534);
PPC_FUNC_IMPL(__imp__sub_82558534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558538"))) PPC_WEAK_FUNC(sub_82558538);
PPC_FUNC_IMPL(__imp__sub_82558538) {
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
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82558568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255857C;
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

__attribute__((alias("__imp__sub_82558590"))) PPC_WEAK_FUNC(sub_82558590);
PPC_FUNC_IMPL(__imp__sub_82558590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255859C"))) PPC_WEAK_FUNC(sub_8255859C);
PPC_FUNC_IMPL(__imp__sub_8255859C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825585A0"))) PPC_WEAK_FUNC(sub_825585A0);
PPC_FUNC_IMPL(__imp__sub_825585A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-11372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11372);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825585B4"))) PPC_WEAK_FUNC(sub_825585B4);
PPC_FUNC_IMPL(__imp__sub_825585B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825585B8"))) PPC_WEAK_FUNC(sub_825585B8);
PPC_FUNC_IMPL(__imp__sub_825585B8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f1,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82558608
	if (cr6.gt) goto loc_82558608;
	// lfs f11,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f10,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f11,f13,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// fmsubs f8,f10,f13,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 - f0.f64));
	// lfs f7,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,-11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11368);
	f0.f64 = double(temp.f32);
	// fmuls f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmuls f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// fmuls f4,f5,f12
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// blr 
	return;
loc_82558608:
	// lfs f13,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f10,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f9,96(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f7,92(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f9,f10,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + f0.f64));
	// fmsubs f5,f7,f10,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 - f0.f64));
	// lfs f4,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f3,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f13,-11368(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11368);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f2,f10,f0,f11
	ctx.f2.f64 = double(float(-(ctx.f10.f64 * f0.f64 - ctx.f11.f64)));
	// fmuls f0,f2,f6
	f0.f64 = double(float(ctx.f2.f64 * ctx.f6.f64));
	// fmuls f11,f0,f5
	ctx.f11.f64 = double(float(f0.f64 * ctx.f5.f64));
	// fmuls f10,f11,f8
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmuls f9,f10,f4
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// fmuls f8,f9,f3
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f3.f64));
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fmuls f0,f7,f13
	f0.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558678"))) PPC_WEAK_FUNC(sub_82558678);
PPC_FUNC_IMPL(__imp__sub_82558678) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// addi r10,r11,-11388
	ctx.r10.s64 = r11.s64 + -11388;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82585de8
	ctx.lr = 0x825586A8;
	sub_82585DE8(ctx, base);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x82585de8
	ctx.lr = 0x825586B0;
	sub_82585DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x825586B8;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825586d0
	if (cr6.eq) goto loc_825586D0;
	// bl 0x82130588
	ctx.lr = 0x825586CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825586D0:
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

__attribute__((alias("__imp__sub_825586E8"))) PPC_WEAK_FUNC(sub_825586E8);
PPC_FUNC_IMPL(__imp__sub_825586E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82558700
	if (!cr6.gt) goto loc_82558700;
	// stfs f1,28(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
loc_82558700:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82558710"))) PPC_WEAK_FUNC(sub_82558710);
PPC_FUNC_IMPL(__imp__sub_82558710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,60(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r9,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255872C"))) PPC_WEAK_FUNC(sub_8255872C);
PPC_FUNC_IMPL(__imp__sub_8255872C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558730"))) PPC_WEAK_FUNC(sub_82558730);
PPC_FUNC_IMPL(__imp__sub_82558730) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,12880(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f10,-11356(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11356);
	ctx.f10.f64 = double(temp.f32);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// lfs f9,-11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11360);
	ctx.f9.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f11,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f5,-12084(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12084);
	ctx.f5.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f8,-11364(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -11364);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,30712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30712);
	ctx.f7.f64 = double(temp.f32);
	// li r11,10
	r11.s64 = 10;
	// lfs f6,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f6.f64 = double(temp.f32);
	// stw r9,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r9.u32);
	// lfs f4,-6176(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6176);
	ctx.f4.f64 = double(temp.f32);
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f8,20(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f7,24(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f6,28(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f5,32(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
loc_825587CC:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x825587cc
	if (!cr0.lt) goto loc_825587CC;
	// li r11,10
	r11.s64 = 10;
	// addi r10,r3,140
	ctx.r10.s64 = ctx.r3.s64 + 140;
loc_825587E4:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x825587e4
	if (!cr0.lt) goto loc_825587E4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825587F8"))) PPC_WEAK_FUNC(sub_825587F8);
PPC_FUNC_IMPL(__imp__sub_825587F8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82558800;
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f1,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f10,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f1,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f7,12(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lfs f6,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,16(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f1,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f6.f64));
	// stfs f3,16(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f2,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,20(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f2
	ctx.f13.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fmadds f12,f13,f1,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f11,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,24(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f8,f9,f1,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f8,24(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lfs f7,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmadds f4,f5,f1,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f7.f64));
	// stfs f4,4(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f3,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fmadds f13,f0,f1,f3
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f3.f64));
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f1,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f9,0(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f8,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,32(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f1,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f8.f64));
	// stfs f5,32(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f4,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,36(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f0,f2,f1,f4
	f0.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f4.f64));
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f13,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f1,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f10,40(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f9,44(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,44(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f1,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f9.f64));
	// stfs f6,44(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// lfs f5,48(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,48(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// fmadds f2,f3,f1,f5
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f1.f64 + ctx.f5.f64));
	// stfs f2,48(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lwz r11,52(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// lwz r10,52(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x82558918
	if (!cr6.gt) goto loc_82558918;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82558918:
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// li r11,96
	r11.s64 = 96;
	// lwz r10,96(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 96);
	// li r9,92
	ctx.r9.s64 = 92;
	// lwz r8,96(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// subf r4,r8,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r8.s64;
	// std r7,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r7.u64);
	// lfd f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// extsw r8,r4
	ctx.r8.s64 = ctx.r4.s32;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// li r10,88
	ctx.r10.s64 = 88;
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// li r7,84
	ctx.r7.s64 = 84;
	// lfd f13,-64(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f8,f10,f1,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f9.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r3,r11
	PPC_STORE_U32(ctx.r3.u32 + r11.u32, ctx.f7.u32);
	// lwz r4,92(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// lwz r11,92(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 92);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// lfd f6,-64(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// subf r4,r11,r4
	ctx.r4.s64 = ctx.r4.s64 - r11.s64;
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// std r11,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r11.u64);
	// lfd f4,-56(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f0,f3
	f0.f64 = double(float(ctx.f3.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fmadds f13,f0,f1,f2
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f2.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r3,r9
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.f12.u32);
	// lwz r8,88(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	// lwz r9,88(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	// extsw r4,r9
	ctx.r4.s64 = ctx.r9.s32;
	// std r4,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r4.u64);
	// lfd f11,-56(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r9.u64);
	// lfd f9,-56(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// fmadds f5,f6,f1,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f7.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfiwx f4,r3,r10
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.f4.u32);
	// lwz r8,84(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// extsw r4,r8
	ctx.r4.s64 = ctx.r8.s32;
	// std r4,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r4.u64);
	// lwz r11,84(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	// subf r10,r8,r11
	ctx.r10.s64 = r11.s64 - ctx.r8.s64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// lfd f3,-56(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// std r9,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r9.u64);
	// lfd f0,-56(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// frsp f11,f2
	ctx.f11.f64 = double(float(ctx.f2.f64));
	// fmadds f10,f12,f1,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + ctx.f11.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.f9.u32);
	// lwz r8,80(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// lwz r7,80(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// std r4,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r4.u64);
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// lfd f8,-56(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r10,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r10.u64);
	// lfd f6,-56(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// li r7,80
	ctx.r7.s64 = 80;
	// li r4,76
	ctx.r4.s64 = 76;
	// li r31,72
	r31.s64 = 72;
	// li r30,68
	r30.s64 = 68;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r6,64
	r11.s64 = ctx.r6.s64 + 64;
	// subf r9,r6,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r6.s64;
	// subf r8,r6,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r6.s64;
	// fmadds f2,f4,f1,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f3.f64));
	// fctiwz f0,f2
	f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, f0.u32);
	// lwz r7,76(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// lwz r29,76(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// extsw r28,r29
	r28.s64 = r29.s32;
	// subf r7,r29,r7
	ctx.r7.s64 = ctx.r7.s64 - r29.s64;
	// std r28,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r28.u64);
	// lfd f11,-64(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// lfd f13,-56(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f7,f10,f1,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f8.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfiwx f6,r3,r4
	PPC_STORE_U32(ctx.r3.u32 + ctx.r4.u32, ctx.f6.u32);
	// lwz r4,72(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 72);
	// extsw r29,r4
	r29.s64 = ctx.r4.s32;
	// std r29,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r29.u64);
	// lwz r7,72(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 72);
	// subf r4,r4,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r4.s64;
	// extsw r7,r4
	ctx.r7.s64 = ctx.r4.s32;
	// lfd f5,-56(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f0,f4
	f0.f64 = double(float(ctx.f4.f64));
	// lfd f3,-56(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f13,f2
	ctx.f13.f64 = double(float(ctx.f2.f64));
	// fmadds f12,f13,f1,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, ctx.f11.u32);
	// lwz r7,68(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	// extsw r31,r7
	r31.s64 = ctx.r7.s32;
	// lwz r4,68(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// std r31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r31.u64);
	// lfd f8,-64(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// subf r4,r7,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r7.s64;
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// extsw r7,r4
	ctx.r7.s64 = ctx.r4.s32;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// lfd f10,-56(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmadds f4,f7,f1,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f5.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfiwx f3,r3,r30
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, ctx.f3.u32);
loc_82558B4C:
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// extsw r31,r7
	r31.s64 = ctx.r7.s32;
	// subf r7,r7,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r7.s64;
	// std r31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r31.u64);
	// lfd f12,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// std r4,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r4.u64);
	// lfd f0,-56(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmadds f8,f11,f1,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f9.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.f7.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x82558b4c
	if (!cr0.lt) goto loc_82558B4C;
	// lwz r11,140(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 140);
	// li r10,140
	ctx.r10.s64 = 140;
	// lwz r7,140(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 140);
	// li r4,136
	ctx.r4.s64 = 136;
	// extsw r31,r11
	r31.s64 = r11.s32;
	// subf r11,r11,r7
	r11.s64 = ctx.r7.s64 - r11.s64;
	// std r31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r31.u64);
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// li r11,132
	r11.s64 = 132;
	// lfd f0,-56(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// lfd f11,-56(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// li r7,128
	ctx.r7.s64 = 128;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmadds f8,f9,f1,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f12.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r3,r10
	PPC_STORE_U32(ctx.r3.u32 + ctx.r10.u32, ctx.f7.u32);
	// lwz r31,136(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 136);
	// lwz r10,136(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 136);
	// extsw r30,r10
	r30.s64 = ctx.r10.s32;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r30.u64);
	// lfd f6,-56(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// std r10,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r10.u64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// lfd f3,-56(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f0,f2
	f0.f64 = double(float(ctx.f2.f64));
	// fmadds f13,f0,f1,f4
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f4.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r3,r4
	PPC_STORE_U32(ctx.r3.u32 + ctx.r4.u32, ctx.f12.u32);
	// lwz r4,132(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 132);
	// lwz r10,132(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
	// extsw r31,r10
	r31.s64 = ctx.r10.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r31.u64);
	// lfd f11,-56(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r10,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r10.u64);
	// lfd f9,-64(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmadds f5,f6,f1,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f7.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfiwx f4,r3,r11
	PPC_STORE_U32(ctx.r3.u32 + r11.u32, ctx.f4.u32);
	// lwz r4,128(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r10,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r10.u64);
	// lwz r11,128(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// subf r4,r4,r11
	ctx.r4.s64 = r11.s64 - ctx.r4.s64;
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// lfd f3,-56(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// std r11,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r11.u64);
	// lfd f0,-56(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f2
	ctx.f12.f64 = double(float(ctx.f2.f64));
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fmadds f10,f11,f1,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f12.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfiwx f9,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.f9.u32);
	// lwz r10,124(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 124);
	// lwz r4,124(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 124);
	// extsw r7,r10
	ctx.r7.s64 = ctx.r10.s32;
	// subf r11,r10,r4
	r11.s64 = ctx.r4.s64 - ctx.r10.s64;
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// lfd f8,-56(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// li r7,124
	ctx.r7.s64 = 124;
	// std r10,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r10.u64);
	// lfd f7,-64(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// li r4,120
	ctx.r4.s64 = 120;
	// li r31,116
	r31.s64 = 116;
	// addi r11,r6,108
	r11.s64 = ctx.r6.s64 + 108;
	// li r30,112
	r30.s64 = 112;
	// li r10,2
	ctx.r10.s64 = 2;
	// fmadds f2,f5,f1,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f3.f64));
	// fctiwz f0,f2
	f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f0,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, f0.u32);
	// lwz r28,120(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 120);
	// lwz r7,120(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 120);
	// extsw r29,r7
	r29.s64 = ctx.r7.s32;
	// subf r7,r7,r28
	ctx.r7.s64 = r28.s64 - ctx.r7.s64;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// std r29,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r29.u64);
	// std r7,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r7.u64);
	// lfd f13,-56(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfd f11,-64(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmadds f7,f8,f1,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f9.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfiwx f6,r3,r4
	PPC_STORE_U32(ctx.r3.u32 + ctx.r4.u32, ctx.f6.u32);
	// lwz r4,116(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 116);
	// lwz r7,116(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 116);
	// extsw r29,r4
	r29.s64 = ctx.r4.s32;
	// subf r4,r4,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r4.s64;
	// extsw r7,r4
	ctx.r7.s64 = ctx.r4.s32;
	// std r29,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r29.u64);
	// lfd f5,-56(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// frsp f0,f4
	f0.f64 = double(float(ctx.f4.f64));
	// lfd f3,-56(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f13,f2
	ctx.f13.f64 = double(float(ctx.f2.f64));
	// fmadds f12,f13,f1,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, ctx.f11.u32);
	// lwz r4,112(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// lwz r5,112(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	// subf r6,r5,r4
	ctx.r6.s64 = ctx.r4.s64 - ctx.r5.s64;
	// extsw r7,r5
	ctx.r7.s64 = ctx.r5.s32;
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r7,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r7.u64);
	// lfd f10,-56(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// std r5,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r5.u64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfd f7,-56(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmadds f4,f5,f1,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f8.f64));
	// fctiwz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfiwx f3,r3,r30
	PPC_STORE_U32(ctx.r3.u32 + r30.u32, ctx.f3.u32);
loc_82558DC0:
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// subf r4,r7,r6
	ctx.r4.s64 = ctx.r6.s64 - ctx.r7.s64;
	// std r5,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r5.u64);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r3.u64);
	// lfd f0,-56(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfd f12,-64(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fmadds f8,f9,f1,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f10.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.f7.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x82558dc0
	if (!cr0.lt) goto loc_82558DC0;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82558E10"))) PPC_WEAK_FUNC(sub_82558E10);
PPC_FUNC_IMPL(__imp__sub_82558E10) {
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
	ctx.lr = 0x82558E18;
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
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82558E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// addi r4,r9,-11336
	ctx.r4.s64 = ctx.r9.s64 + -11336;
	// bl 0x821d0360
	ctx.lr = 0x82558E50;
	sub_821D0360(ctx, base);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// ble cr6,0x82558e90
	if (!cr6.gt) goto loc_82558E90;
	// lbz r11,13(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 13);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,148(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// beq cr6,0x82558e80
	if (cr6.eq) goto loc_82558E80;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r4,r10,-11344
	ctx.r4.s64 = ctx.r10.s64 + -11344;
	// b 0x82558e88
	goto loc_82558E88;
loc_82558E80:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r4,r10,-11352
	ctx.r4.s64 = ctx.r10.s64 + -11352;
loc_82558E88:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82558E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82558E90:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82558EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82558EB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r30,8(r28)
	r30.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82558f18
	if (!cr6.gt) goto loc_82558F18;
	// li r29,0
	r29.s64 = 0;
loc_82558EC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82558EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// lwz r8,132(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82558EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,120(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82558F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// bne 0x82558ec8
	if (!cr0.eq) goto loc_82558EC8;
loc_82558F18:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82558F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82558F34"))) PPC_WEAK_FUNC(sub_82558F34);
PPC_FUNC_IMPL(__imp__sub_82558F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558F38"))) PPC_WEAK_FUNC(sub_82558F38);
PPC_FUNC_IMPL(__imp__sub_82558F38) {
	PPC_FUNC_PROLOGUE();
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// sth r10,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r10.u16);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// sth r10,46(r31)
	PPC_STORE_U16(r31.u32 + 46, ctx.r10.u16);
	// stfs f31,12(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f31,48(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f31,52(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f31,40(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f31,80(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// beq cr6,0x82558fb4
	if (cr6.eq) goto loc_82558FB4;
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stb r10,32(r11)
	PPC_STORE_U8(r11.u32 + 32, ctx.r10.u8);
loc_82558FB4:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82558fcc
	if (cr6.eq) goto loc_82558FCC;
	// bl 0x82568d78
	ctx.lr = 0x82558FC4;
	sub_82568D78(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// stfs f31,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
loc_82558FCC:
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

__attribute__((alias("__imp__sub_82558FE4"))) PPC_WEAK_FUNC(sub_82558FE4);
PPC_FUNC_IMPL(__imp__sub_82558FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82558FE8"))) PPC_WEAK_FUNC(sub_82558FE8);
PPC_FUNC_IMPL(__imp__sub_82558FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f12,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// lhz r11,120(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 120);
	// lfs f11,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,52(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// addi r7,r11,-2
	ctx.r7.s64 = r11.s64 + -2;
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fdivs f0,f10,f7
	f0.f64 = double(float(ctx.f10.f64 / ctx.f7.f64));
	// fsubs f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 / f0.f64));
	// fsubs f12,f1,f6
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f6.f64));
	// fmuls f5,f13,f12
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x82559060
	if (!cr6.lt) goto loc_82559060;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8255906c
	goto loc_8255906C;
loc_82559060:
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// ble cr6,0x8255906c
	if (!cr6.gt) goto loc_8255906C;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
loc_8255906C:
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r3,r3,112
	ctx.r3.s64 = ctx.r3.s64 + 112;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f2,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fnmsubs f8,f9,f0,f12
	ctx.f8.f64 = double(float(-(ctx.f9.f64 * f0.f64 - ctx.f12.f64)));
	// fmuls f1,f8,f13
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825590AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825590C0"))) PPC_WEAK_FUNC(sub_825590C0);
PPC_FUNC_IMPL(__imp__sub_825590C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f12,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// lhz r11,200(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 200);
	// lfs f11,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,52(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// addi r7,r11,-2
	ctx.r7.s64 = r11.s64 + -2;
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fdivs f0,f10,f7
	f0.f64 = double(float(ctx.f10.f64 / ctx.f7.f64));
	// fsubs f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 / f0.f64));
	// fsubs f12,f1,f6
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f6.f64));
	// fmuls f5,f13,f12
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x82559138
	if (!cr6.lt) goto loc_82559138;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82559144
	goto loc_82559144;
loc_82559138:
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// ble cr6,0x82559144
	if (!cr6.gt) goto loc_82559144;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
loc_82559144:
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lwz r10,192(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r3,r3,192
	ctx.r3.s64 = ctx.r3.s64 + 192;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f2,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fnmsubs f8,f9,f0,f12
	ctx.f8.f64 = double(float(-(ctx.f9.f64 * f0.f64 - ctx.f12.f64)));
	// fmuls f1,f8,f13
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82559184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82559198"))) PPC_WEAK_FUNC(sub_82559198);
PPC_FUNC_IMPL(__imp__sub_82559198) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,200(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825591b8
	if (cr6.eq) goto loc_825591B8;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lbz r10,-23540(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23540);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825591b8
	if (cr6.eq) goto loc_825591B8;
	// b 0x825590c0
	sub_825590C0(ctx, base);
	return;
loc_825591B8:
	// lfs f0,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f10,f0,f1
	ctx.f10.f64 = double(float(f0.f64 - ctx.f1.f64));
	// lfs f9,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 / ctx.f9.f64));
	// lfs f7,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -11368);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f11.f64 = double(temp.f32);
	// fneg f6,f10
	ctx.f6.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fmuls f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fmuls f4,f8,f1
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f1.f64));
	// fsel f3,f6,f13,f0
	ctx.f3.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// fmuls f2,f5,f12
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// fsel f1,f10,f3,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f3.f64 : ctx.f11.f64;
	// fmuls f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// fmuls f1,f0,f4
	ctx.f1.f64 = double(float(f0.f64 * ctx.f4.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82559214"))) PPC_WEAK_FUNC(sub_82559214);
PPC_FUNC_IMPL(__imp__sub_82559214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82559218"))) PPC_WEAK_FUNC(sub_82559218);
PPC_FUNC_IMPL(__imp__sub_82559218) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// addi r10,r11,-11388
	ctx.r10.s64 = r11.s64 + -11388;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82585d98
	ctx.lr = 0x82559240;
	sub_82585D98(ctx, base);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// bl 0x82585d98
	ctx.lr = 0x82559248;
	sub_82585D98(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32248
	ctx.r5.s64 = -2113404928;
	// lfd f0,-11296(r9)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + -11296);
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// fsqrts f8,f0
	ctx.f8.f64 = double(float(sqrt(f0.f64)));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f12,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-11304(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -11304);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f10,-11308(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -11308);
	ctx.f10.f64 = double(temp.f32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// lfs f9,-11312(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11312);
	ctx.f9.f64 = double(temp.f32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stfs f11,76(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f10,72(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f9,68(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// fadds f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 + f0.f64));
	// fsubs f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fmuls f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f5,92(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// fmuls f4,f6,f12
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// stfs f4,96(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x82558f38
	ctx.lr = 0x825592D0;
	sub_82558F38(ctx, base);
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

__attribute__((alias("__imp__sub_825592E8"))) PPC_WEAK_FUNC(sub_825592E8);
PPC_FUNC_IMPL(__imp__sub_825592E8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x825592F0;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,12
	r27.s64 = 12;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 120);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r9,r11,-2
	ctx.r9.s64 = r11.s64 + -2;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fdivs f30,f12,f9
	f30.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// bne cr6,0x825593ac
	if (!cr6.eq) goto loc_825593AC;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// li r3,192
	ctx.r3.s64 = 192;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// bl 0x82130528
	ctx.lr = 0x82559354;
	sub_82130528(ctx, base);
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// sth r27,122(r31)
	PPC_STORE_U16(r31.u32 + 122, r27.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82559370
	if (!cr6.eq) goto loc_82559370;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_82559370:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82559388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,122(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 122);
	// addi r30,r31,116
	r30.s64 = r31.s64 + 116;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x825593a8
	if (!cr6.eq) goto loc_825593A8;
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x825593A4;
	sub_82130528(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_825593A8:
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
loc_825593AC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82559424
	if (!cr6.gt) goto loc_82559424;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r10,56
	ctx.r10.s64 = 56;
loc_825593D8:
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,8(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,52(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x825593d8
	if (cr6.lt) goto loc_825593D8;
loc_82559424:
	// subfic r11,r8,11
	xer.ca = ctx.r8.u32 <= 11;
	r11.s64 = 11 - ctx.r8.s64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x825594b8
	if (cr6.lt) goto loc_825594B8;
	// subfic r10,r8,7
	xer.ca = ctx.r8.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r8.s64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_82559448:
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// fadds f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fadds f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 + f30.f64));
	// fadds f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 + f30.f64));
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stfs f13,16(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// stfs f31,20(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// fadds f0,f11,f30
	f0.f64 = double(float(ctx.f11.f64 + f30.f64));
	// stfs f31,24(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f12,-16(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + -16, temp.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// stfs f31,-12(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12, temp.u32);
	// stfs f31,-8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// blt cr6,0x82559448
	if (cr6.lt) goto loc_82559448;
loc_825594B8:
	// cmpwi cr6,r8,11
	cr6.compare<int32_t>(ctx.r8.s32, 11, xer);
	// bge cr6,0x825594e8
	if (!cr6.lt) goto loc_825594E8;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
loc_825594C4:
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpwi cr6,r11,176
	cr6.compare<int32_t>(r11.s32, 176, xer);
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f31,4(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// blt cr6,0x825594c4
	if (cr6.lt) goto loc_825594C4;
loc_825594E8:
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// stfs f0,176(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// stfs f31,180(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f31,184(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8255950C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,200(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 200);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82559580
	if (!cr6.eq) goto loc_82559580;
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// li r3,192
	ctx.r3.s64 = 192;
	// addi r29,r30,4
	r29.s64 = r30.s64 + 4;
	// bl 0x82130528
	ctx.lr = 0x82559528;
	sub_82130528(ctx, base);
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// sth r27,202(r31)
	PPC_STORE_U16(r31.u32 + 202, r27.u16);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82559544
	if (!cr6.eq) goto loc_82559544;
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
loc_82559544:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255955C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,202(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 202);
	// addi r30,r31,196
	r30.s64 = r31.s64 + 196;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8255957c
	if (!cr6.eq) goto loc_8255957C;
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x82559578;
	sub_82130528(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8255957C:
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
loc_82559580:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x825595f4
	if (!cr6.gt) goto loc_825595F4;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r10,100
	ctx.r10.s64 = 100;
loc_825595A8:
	// lwzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f31,8(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r5,52(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x825595a8
	if (cr6.lt) goto loc_825595A8;
loc_825595F4:
	// subfic r11,r8,11
	xer.ca = ctx.r8.u32 <= 11;
	r11.s64 = 11 - ctx.r8.s64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x82559688
	if (cr6.lt) goto loc_82559688;
	// subfic r10,r8,7
	xer.ca = ctx.r8.u32 <= 7;
	ctx.r10.s64 = 7 - ctx.r8.s64;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
loc_82559618:
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// fadds f12,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + f30.f64));
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fadds f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 + f30.f64));
	// fadds f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 + f30.f64));
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stfs f12,16(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// stfs f13,20(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// fadds f0,f10,f30
	f0.f64 = double(float(ctx.f10.f64 + f30.f64));
	// stfs f31,24(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f11,-16(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + -16, temp.u32);
	// stfs f13,-12(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -12, temp.u32);
	// stfs f31,-8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f10,0(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// blt cr6,0x82559618
	if (cr6.lt) goto loc_82559618;
loc_82559688:
	// cmpwi cr6,r8,11
	cr6.compare<int32_t>(ctx.r8.s32, 11, xer);
	// bge cr6,0x825596b8
	if (!cr6.lt) goto loc_825596B8;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
loc_82559694:
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpwi cr6,r11,176
	cr6.compare<int32_t>(r11.s32, 176, xer);
	// stfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f31,8(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// blt cr6,0x82559694
	if (cr6.lt) goto loc_82559694;
loc_825596B8:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stfs f0,176(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// stfs f13,180(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f31,184(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825596DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_825596EC"))) PPC_WEAK_FUNC(sub_825596EC);
PPC_FUNC_IMPL(__imp__sub_825596EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825596F0"))) PPC_WEAK_FUNC(sub_825596F0);
PPC_FUNC_IMPL(__imp__sub_825596F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,120(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559710
	if (cr6.eq) goto loc_82559710;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lbz r10,-23540(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23540);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82559710
	if (cr6.eq) goto loc_82559710;
	// b 0x82558fe8
	sub_82558FE8(ctx, base);
	return;
loc_82559710:
	// b 0x825585b8
	sub_825585B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82559714"))) PPC_WEAK_FUNC(sub_82559714);
PPC_FUNC_IMPL(__imp__sub_82559714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82559718"))) PPC_WEAK_FUNC(sub_82559718);
PPC_FUNC_IMPL(__imp__sub_82559718) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f31.f64 = double(temp.f32);
	// lfs f30,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x825597c8
	if (!cr6.gt) goto loc_825597C8;
	// lhz r11,120(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255976c
	if (cr6.eq) goto loc_8255976C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lbz r10,-23540(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23540);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255976c
	if (cr6.eq) goto loc_8255976C;
	// bl 0x82558fe8
	ctx.lr = 0x82559768;
	sub_82558FE8(ctx, base);
	// b 0x82559774
	goto loc_82559774;
loc_8255976C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825585b8
	ctx.lr = 0x82559774;
	sub_825585B8(ctx, base);
loc_82559774:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f12,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x825597ac
	if (!cr6.gt) goto loc_825597AC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f0,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f12,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 / ctx.f12.f64));
	// lfs f10,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
loc_825597AC:
	// fsubs f12,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f31.f64 - f30.f64));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// b 0x825597e8
	goto loc_825597E8;
loc_825597C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82559198
	ctx.lr = 0x825597D0;
	sub_82559198(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f31,f0,f13
	f0.f64 = double(float(-(f31.f64 * f0.f64 - ctx.f13.f64)));
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
loc_825597E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82559804"))) PPC_WEAK_FUNC(sub_82559804);
PPC_FUNC_IMPL(__imp__sub_82559804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82559808"))) PPC_WEAK_FUNC(sub_82559808);
PPC_FUNC_IMPL(__imp__sub_82559808) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// lhz r11,120(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 120);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559840
	if (cr6.eq) goto loc_82559840;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lbz r10,-23540(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23540);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82559840
	if (cr6.eq) goto loc_82559840;
	// bl 0x82558fe8
	ctx.lr = 0x8255983C;
	sub_82558FE8(ctx, base);
	// b 0x82559848
	goto loc_82559848;
loc_82559840:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825585b8
	ctx.lr = 0x82559848;
	sub_825585B8(ctx, base);
loc_82559848:
	// fmuls f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * f31.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-13060(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13060);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255986C"))) PPC_WEAK_FUNC(sub_8255986C);
PPC_FUNC_IMPL(__imp__sub_8255986C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82559870"))) PPC_WEAK_FUNC(sub_82559870);
PPC_FUNC_IMPL(__imp__sub_82559870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9c8
	ctx.lr = 0x82559888;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f24,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f24.f64 = double(temp.f32);
	// lfs f0,-11288(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11288);
	f0.f64 = double(temp.f32);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lfs f26,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f26.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,76(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// lfs f11,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,72(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// fmr f9,f10
	ctx.f9.f64 = ctx.f10.f64;
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fsubs f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// stfs f7,68(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// fmuls f5,f9,f9
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmuls f4,f6,f6
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmuls f3,f5,f9
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f9.f64));
	// fdivs f2,f26,f4
	ctx.f2.f64 = double(float(f26.f64 / ctx.f4.f64));
	// stfs f2,84(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// fdivs f1,f26,f3
	ctx.f1.f64 = double(float(f26.f64 / ctx.f3.f64));
	// stfs f1,88(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// beq cr6,0x82559904
	if (cr6.eq) goto loc_82559904;
	// lfs f0,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
loc_82559904:
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82559918
	if (!cr6.gt) goto loc_82559918;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825592e8
	ctx.lr = 0x82559918;
	sub_825592E8(ctx, base);
loc_82559918:
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lbz r9,-23540(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -23540);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82559a18
	if (cr6.eq) goto loc_82559A18;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82559a18
	if (!cr6.gt) goto loc_82559A18;
	// lfs f31,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f31.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f28,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f28.f64 = double(temp.f32);
	// fsubs f0,f28,f31
	f0.f64 = double(float(f28.f64 - f31.f64));
	// lfs f25,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f25.f64 = double(temp.f32);
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// ble cr6,0x82559a08
	if (!cr6.gt) goto loc_82559A08;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f27,-13060(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13060);
	f27.f64 = double(temp.f32);
loc_8255995C:
	// fadds f0,f28,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 + f31.f64));
	// lhz r11,120(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f30,f0,f25
	f30.f64 = double(float(f0.f64 * f25.f64));
	// beq cr6,0x82559990
	if (cr6.eq) goto loc_82559990;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559990
	if (cr6.eq) goto loc_82559990;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82558fe8
	ctx.lr = 0x82559988;
	sub_82558FE8(ctx, base);
	// lbz r9,-23540(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -23540);
	// b 0x8255999c
	goto loc_8255999C;
loc_82559990:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x825585b8
	ctx.lr = 0x8255999C;
	sub_825585B8(ctx, base);
loc_8255999C:
	// lhz r11,120(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 120);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825599cc
	if (cr6.eq) goto loc_825599CC;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825599cc
	if (cr6.eq) goto loc_825599CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82558fe8
	ctx.lr = 0x825599C4;
	sub_82558FE8(ctx, base);
	// lbz r9,-23540(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -23540);
	// b 0x825599d8
	goto loc_825599D8;
loc_825599CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825585b8
	ctx.lr = 0x825599D8;
	sub_825585B8(ctx, base);
loc_825599D8:
	// fmuls f0,f29,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 * f30.f64));
	// fmuls f13,f1,f31
	ctx.f13.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fmuls f12,f0,f27
	ctx.f12.f64 = double(float(f0.f64 * f27.f64));
	// fmuls f11,f13,f27
	ctx.f11.f64 = double(float(ctx.f13.f64 * f27.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x825599f8
	if (!cr6.gt) goto loc_825599F8;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// b 0x825599fc
	goto loc_825599FC;
loc_825599F8:
	// fmr f28,f30
	ctx.fpscr.disableFlushMode();
	f28.f64 = f30.f64;
loc_825599FC:
	// fsubs f0,f28,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 - f31.f64));
	// fcmpu cr6,f0,f26
	cr6.compare(f0.f64, f26.f64);
	// bgt cr6,0x8255995c
	if (cr6.gt) goto loc_8255995C;
loc_82559A08:
	// fadds f0,f28,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 + f31.f64));
	// fmuls f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 * f25.f64));
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// lbz r9,-23540(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + -23540);
loc_82559A18:
	// lhz r11,120(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 120);
	// lfs f1,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559a40
	if (cr6.eq) goto loc_82559A40;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559a40
	if (cr6.eq) goto loc_82559A40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82558fe8
	ctx.lr = 0x82559A3C;
	sub_82558FE8(ctx, base);
	// b 0x82559a48
	goto loc_82559A48;
loc_82559A40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825585b8
	ctx.lr = 0x82559A48;
	sub_825585B8(ctx, base);
loc_82559A48:
	// stfs f24,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f1,20(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba14
	ctx.lr = 0x82559A5C;
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

__attribute__((alias("__imp__sub_82559A70"))) PPC_WEAK_FUNC(sub_82559A70);
PPC_FUNC_IMPL(__imp__sub_82559A70) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82559A78;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82559ab8
	if (!cr6.gt) goto loc_82559AB8;
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82559ab8
	if (!cr6.gt) goto loc_82559AB8;
	// lfs f0,40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
loc_82559AB8:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82559af0
	if (cr6.eq) goto loc_82559AF0;
	// lhz r11,44(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82559af0
	if (!cr6.eq) goto loc_82559AF0;
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559af0
	if (cr6.eq) goto loc_82559AF0;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// sth r11,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r11.u16);
loc_82559AF0:
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lhz r8,44(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f29,-11288(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11288);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82559cc8
	if (cr6.eq) goto loc_82559CC8;
	// lfs f13,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x82559bb8
	if (!cr6.gt) goto loc_82559BB8;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82559b7c
	if (!cr6.gt) goto loc_82559B7C;
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// ble cr6,0x82559b78
	if (!cr6.gt) goto loc_82559B78;
	// lfs f0,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f10,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// lfs f12,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmuls f7,f11,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fsel f6,f7,f7,f31
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f31.f64;
	// fsel f5,f7,f7,f31
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f31.f64;
	// fsubs f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f3,f4,f0,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// fmadds f2,f3,f8,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f8.f64 + ctx.f10.f64));
	// stfs f2,24(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x82559ba0
	goto loc_82559BA0;
loc_82559B78:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
loc_82559B7C:
	// bge cr6,0x82559ba0
	if (!cr6.lt) goto loc_82559BA0;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x82559ba0
	if (!cr6.gt) goto loc_82559BA0;
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f12,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f12,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_82559BA0:
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82559bb8
	if (!cr6.lt) goto loc_82559BB8;
	// stfs f31,48(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
loc_82559BB8:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
	// lfs f0,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82559bf8
	if (!cr6.gt) goto loc_82559BF8;
	// bl 0x82561040
	ctx.lr = 0x82559BD0;
	sub_82561040(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// ble cr6,0x82559bf8
	if (!cr6.gt) goto loc_82559BF8;
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r11,9
	ctx.r8.s64 = r11.s64 + 9;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,48(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfsx f13,r7,r10
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82559BF8:
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82559c18
	if (cr6.gt) goto loc_82559C18;
	// sth r29,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r29.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x82561020
	ctx.lr = 0x82559C14;
	sub_82561020(ctx, base);
	// b 0x82559cc8
	goto loc_82559CC8;
loc_82559C18:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82559c78
	if (!cr6.gt) goto loc_82559C78;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// ble cr6,0x82559c74
	if (!cr6.gt) goto loc_82559C74;
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82559c74
	if (!cr6.gt) goto loc_82559C74;
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r8,r10,9
	ctx.r8.s64 = ctx.r10.s64 + 9;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fmadds f8,f30,f29,f9
	ctx.f8.f64 = double(float(f30.f64 * f29.f64 + ctx.f9.f64));
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// bgt cr6,0x82559cc8
	if (cr6.gt) goto loc_82559CC8;
	// b 0x82559cc4
	goto loc_82559CC4;
loc_82559C74:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
loc_82559C78:
	// bge cr6,0x82559cc8
	if (!cr6.lt) goto loc_82559CC8;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x82559cc8
	if (cr6.lt) goto loc_82559CC8;
	// fcmpu cr6,f30,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82559cc8
	if (!cr6.gt) goto loc_82559CC8;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r8,r10,9
	ctx.r8.s64 = ctx.r10.s64 + 9;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fmadds f8,f30,f29,f9
	ctx.f8.f64 = double(float(f30.f64 * f29.f64 + ctx.f9.f64));
	// fcmpu cr6,f0,f8
	cr6.compare(f0.f64, ctx.f8.f64);
	// blt cr6,0x82559cc8
	if (cr6.lt) goto loc_82559CC8;
loc_82559CC4:
	// stfs f31,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
loc_82559CC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82559718
	ctx.lr = 0x82559CD4;
	sub_82559718(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stfs f1,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r8,r10,9
	ctx.r8.s64 = ctx.r10.s64 + 9;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f30,-28872(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28872);
	f30.f64 = double(temp.f32);
	// lfsx f0,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x82559dd0
	if (cr6.eq) goto loc_82559DD0;
	// lhz r10,46(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82559dd0
	if (cr6.eq) goto loc_82559DD0;
	// lbz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82559dd0
	if (!cr6.eq) goto loc_82559DD0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lfs f0,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// addi r8,r10,9
	ctx.r8.s64 = ctx.r10.s64 + 9;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f11,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// bge cr6,0x82559d74
	if (!cr6.lt) goto loc_82559D74;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x82559d60
	if (cr6.eq) goto loc_82559D60;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82559d74
	if (!cr6.eq) goto loc_82559D74;
loc_82559D60:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// blt cr6,0x82559dd0
	if (cr6.lt) goto loc_82559DD0;
loc_82559D74:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// beq cr6,0x82559de4
	if (cr6.eq) goto loc_82559DE4;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// addi r10,r10,9
	ctx.r10.s64 = ctx.r10.s64 + 9;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bgt cr6,0x82559dbc
	if (cr6.gt) goto loc_82559DBC;
	// lfs f0,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82559de4
	if (!cr6.gt) goto loc_82559DE4;
loc_82559DBC:
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82559de4
	if (!cr6.eq) goto loc_82559DE4;
	// bl 0x82568d78
	ctx.lr = 0x82559DCC;
	sub_82568D78(ctx, base);
	// b 0x82559de4
	goto loc_82559DE4;
loc_82559DD0:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559de4
	if (cr6.eq) goto loc_82559DE4;
	// bl 0x82568d98
	ctx.lr = 0x82559DE4;
	sub_82568D98(ctx, base);
loc_82559DE4:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82559e24
	if (cr6.eq) goto loc_82559E24;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lbz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82559e24
	if (!cr6.eq) goto loc_82559E24;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lfs f3,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f2,f0,f29
	ctx.f2.f64 = double(float(f0.f64 * f29.f64));
	// bl 0x821ce490
	ctx.lr = 0x82559E20;
	sub_821CE490(ctx, base);
	// b 0x82559e6c
	goto loc_82559E6C;
loc_82559E24:
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82559e3c
	if (!cr6.eq) goto loc_82559E3C;
	// stfs f31,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// b 0x82559e6c
	goto loc_82559E6C;
loc_82559E3C:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f11,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmadds f8,f9,f0,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f12.f64));
	// fsel f7,f8,f8,f31
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f31.f64;
	// fsubs f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f11.f64));
	// fsel f5,f6,f11,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f11.f64 : ctx.f7.f64;
	// stfs f5,8(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_82559E6C:
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// lfs f12,-13060(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13060);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f10,12(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// ble cr6,0x82559ea8
	if (!cr6.gt) goto loc_82559EA8;
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// b 0x82559eac
	goto loc_82559EAC;
loc_82559EA8:
	// fmr f11,f31
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f31.f64;
loc_82559EAC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14992(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82559ee8
	if (!cr6.lt) goto loc_82559EE8;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f9,f13,f12,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f9,40(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// ble cr6,0x82559f14
	if (!cr6.gt) goto loc_82559F14;
	// b 0x82559f10
	goto loc_82559F10;
loc_82559EE8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82559f14
	if (!cr6.gt) goto loc_82559F14;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f9,f13,f12,f10
	ctx.f9.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - ctx.f10.f64)));
	// stfs f9,40(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x82559f14
	if (!cr6.lt) goto loc_82559F14;
loc_82559F10:
	// stfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
loc_82559F14:
	// lhz r11,46(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 46);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559f80
	if (cr6.eq) goto loc_82559F80;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// lwz r9,2192(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r9,r5
	ctx.r10.s64 = ctx.r9.s64 * ctx.r5.s64;
	// lfs f0,-11284(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -11284);
	f0.f64 = double(temp.f32);
	// lfs f13,27644(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27644);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// lfs f12,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmsubs f7,f8,f0,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64 - ctx.f13.f64));
	// fadds f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f12.f64));
	// stfs f6,40(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
loc_82559F80:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// beq cr6,0x82559f9c
	if (cr6.eq) goto loc_82559F9C;
	// lbz r11,32(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82559fd8
	if (cr6.eq) goto loc_82559FD8;
loc_82559F9C:
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82559fd8
	if (!cr6.gt) goto loc_82559FD8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// fneg f1,f13
	ctx.f1.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82559FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82559FD8:
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8255a004
	if (!cr6.gt) goto loc_8255A004;
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8255a004
	if (cr6.gt) goto loc_8255A004;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stb r29,32(r11)
	PPC_STORE_U8(r11.u32 + 32, r29.u8);
loc_8255A004:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255A018"))) PPC_WEAK_FUNC(sub_8255A018);
PPC_FUNC_IMPL(__imp__sub_8255A018) {
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
	// bl 0x82558040
	ctx.lr = 0x8255A030;
	sub_82558040(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-9980
	ctx.r8.s64 = ctx.r9.s64 + -9980;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r11.u32);
	// li r6,7
	ctx.r6.s64 = 7;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,372(r31)
	PPC_STORE_U32(r31.u32 + 372, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,400(r31)
	PPC_STORE_U32(r31.u32 + 400, r11.u32);
	// stw r11,404(r31)
	PPC_STORE_U32(r31.u32 + 404, r11.u32);
	// stw r11,412(r31)
	PPC_STORE_U32(r31.u32 + 412, r11.u32);
	// stw r11,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r11.u32);
	// stw r11,416(r31)
	PPC_STORE_U32(r31.u32 + 416, r11.u32);
	// stw r11,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r11.u32);
	// stw r11,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r11.u32);
	// stw r11,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r11.u32);
	// stw r11,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r11.u32);
	// stw r11,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r11.u32);
	// stw r11,444(r31)
	PPC_STORE_U32(r31.u32 + 444, r11.u32);
	// stw r11,448(r31)
	PPC_STORE_U32(r31.u32 + 448, r11.u32);
	// stw r11,452(r31)
	PPC_STORE_U32(r31.u32 + 452, r11.u32);
	// stw r11,456(r31)
	PPC_STORE_U32(r31.u32 + 456, r11.u32);
	// stw r11,460(r31)
	PPC_STORE_U32(r31.u32 + 460, r11.u32);
	// stw r11,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r11.u32);
	// stw r11,468(r31)
	PPC_STORE_U32(r31.u32 + 468, r11.u32);
	// stw r11,472(r31)
	PPC_STORE_U32(r31.u32 + 472, r11.u32);
	// stw r11,476(r31)
	PPC_STORE_U32(r31.u32 + 476, r11.u32);
	// stw r11,480(r31)
	PPC_STORE_U32(r31.u32 + 480, r11.u32);
	// stw r11,484(r31)
	PPC_STORE_U32(r31.u32 + 484, r11.u32);
	// stw r7,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r7.u32);
	// stw r11,380(r31)
	PPC_STORE_U32(r31.u32 + 380, r11.u32);
	// stb r6,384(r31)
	PPC_STORE_U8(r31.u32 + 384, ctx.r6.u8);
	// stw r11,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r11.u32);
	// stw r11,488(r31)
	PPC_STORE_U32(r31.u32 + 488, r11.u32);
	// stfs f0,496(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stfs f0,500(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stfs f0,504(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// stw r5,544(r31)
	PPC_STORE_U32(r31.u32 + 544, ctx.r5.u32);
	// stfs f0,512(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stw r4,392(r31)
	PPC_STORE_U32(r31.u32 + 392, ctx.r4.u32);
	// stfs f0,548(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// stw r11,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255A104"))) PPC_WEAK_FUNC(sub_8255A104);
PPC_FUNC_IMPL(__imp__sub_8255A104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255A108"))) PPC_WEAK_FUNC(sub_8255A108);
PPC_FUNC_IMPL(__imp__sub_8255A108) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r10,-23452(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255a198
	if (cr6.eq) goto loc_8255A198;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8255a198
	if (cr6.eq) goto loc_8255A198;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8255a198
	if (cr6.eq) goto loc_8255A198;
	// lhz r11,8(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8255a198
	if (cr6.eq) goto loc_8255A198;
	// lwz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r10,30
	ctx.r8.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x8255a198
	if (!cr6.eq) goto loc_8255A198;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// lwz r3,-2288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// bl 0x82588990
	ctx.lr = 0x8255A184;
	sub_82588990(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x825582b0
	ctx.lr = 0x8255A198;
	sub_825582B0(ctx, base);
loc_8255A198:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255A1AC"))) PPC_WEAK_FUNC(sub_8255A1AC);
PPC_FUNC_IMPL(__imp__sub_8255A1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255A1B0"))) PPC_WEAK_FUNC(sub_8255A1B0);
PPC_FUNC_IMPL(__imp__sub_8255A1B0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8255A1B8;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255a208
	if (cr6.eq) goto loc_8255A208;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255A1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,172(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8255A208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255A208:
	// lfs f0,276(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 276);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,280(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f9,272(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 272);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fnmadds f30,f9,f8,f7
	f30.f64 = double(float(-(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64)));
	// beq cr6,0x8255a300
	if (cr6.eq) goto loc_8255A300;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// fneg f31,f30
	f31.u64 = f30.u64 ^ 0x8000000000000000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8255a25c
	if (!cr6.gt) goto loc_8255A25C;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lfs f0,420(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 420);
	f0.f64 = double(temp.f32);
	// fdivs f31,f31,f0
	f31.f64 = double(float(f31.f64 / f0.f64));
loc_8255A25C:
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f31,48(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 48, temp.u32);
	// stfs f29,52(r9)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r9.u32 + 52, temp.u32);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8255a298
	if (!cr6.gt) goto loc_8255A298;
	// addi r9,r11,24
	ctx.r9.s64 = r11.s64 + 24;
loc_8255A27C:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f31,552(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 552, temp.u32);
	// lwz r7,20(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8255a27c
	if (cr6.lt) goto loc_8255A27C;
loc_8255A298:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8255a300
	if (cr6.eq) goto loc_8255A300;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255a300
	if (cr6.eq) goto loc_8255A300;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82561050
	ctx.lr = 0x8255A2B8;
	sub_82561050(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x825617e8
	ctx.lr = 0x8255A2C4;
	sub_825617E8(ctx, base);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lfs f0,76(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	f0.f64 = double(temp.f32);
	// addi r8,r11,9
	ctx.r8.s64 = r11.s64 + 9;
	// lfs f13,72(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f12,r7,r10
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsel f8,f9,f10,f0
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f6,f7,f13,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f13.f64 : ctx.f8.f64;
	// stfs f6,8(r9)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + 8, temp.u32);
loc_8255A300:
	// lwz r9,404(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8255a364
	if (cr6.eq) goto loc_8255A364;
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// fneg f0,f30
	ctx.fpscr.disableFlushMode();
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255a328
	if (!cr6.gt) goto loc_8255A328;
	// lwz r11,24(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// lfs f13,420(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 420);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_8255A328:
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// li r11,0
	r11.s64 = 0;
	// stfs f0,48(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 48, temp.u32);
	// stfs f29,52(r10)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8255a364
	if (!cr6.gt) goto loc_8255A364;
	// addi r10,r9,24
	ctx.r10.s64 = ctx.r9.s64 + 24;
loc_8255A348:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stfs f0,552(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 552, temp.u32);
	// lwz r7,20(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8255a348
	if (cr6.lt) goto loc_8255A348;
loc_8255A364:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255A378"))) PPC_WEAK_FUNC(sub_8255A378);
PPC_FUNC_IMPL(__imp__sub_8255A378) {
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
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255a3f4
	if (cr6.eq) goto loc_8255A3F4;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255a3b4
	if (cr6.eq) goto loc_8255A3B4;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x8255a3b8
	goto loc_8255A3B8;
loc_8255A3B4:
	// li r11,-1
	r11.s64 = -1;
loc_8255A3B8:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8255a3f4
	if (cr6.eq) goto loc_8255A3F4;
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a3f8
	if (cr6.eq) goto loc_8255A3F8;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255a3e4
	if (cr6.eq) goto loc_8255A3E4;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x8255a3e8
	goto loc_8255A3E8;
loc_8255A3E4:
	// li r11,-1
	r11.s64 = -1;
loc_8255A3E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// bl 0x8258b6c8
	ctx.lr = 0x8255A3F4;
	sub_8258B6C8(ctx, base);
loc_8255A3F4:
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
loc_8255A3F8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8255a414
	if (cr6.eq) goto loc_8255A414;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a414
	if (cr6.eq) goto loc_8255A414;
	// bl 0x82588338
	ctx.lr = 0x8255A414;
	sub_82588338(ctx, base);
loc_8255A414:
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

__attribute__((alias("__imp__sub_8255A42C"))) PPC_WEAK_FUNC(sub_8255A42C);
PPC_FUNC_IMPL(__imp__sub_8255A42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255A430"))) PPC_WEAK_FUNC(sub_8255A430);
PPC_FUNC_IMPL(__imp__sub_8255A430) {
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
	// lis r30,-32112
	r30.s64 = -2104492032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-2288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -2288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a478
	if (cr6.eq) goto loc_8255A478;
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x8258b448
	ctx.lr = 0x8255A460;
	sub_8258B448(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8255a478
	if (cr6.eq) goto loc_8255A478;
	// lwz r3,-2288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -2288);
	// bl 0x825882f0
	ctx.lr = 0x8255A478;
	sub_825882F0(ctx, base);
loc_8255A478:
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

__attribute__((alias("__imp__sub_8255A490"))) PPC_WEAK_FUNC(sub_8255A490);
PPC_FUNC_IMPL(__imp__sub_8255A490) {
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
	// li r3,272
	ctx.r3.s64 = 272;
	// bl 0x82130528
	ctx.lr = 0x8255A4AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a4bc
	if (cr6.eq) goto loc_8255A4BC;
	// bl 0x82559218
	ctx.lr = 0x8255A4B8;
	sub_82559218(ctx, base);
	// b 0x8255a4c0
	goto loc_8255A4C0;
loc_8255A4BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255A4C0:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r5,144(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// bl 0x82558538
	ctx.lr = 0x8255A4D4;
	sub_82558538(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255A4E8"))) PPC_WEAK_FUNC(sub_8255A4E8);
PPC_FUNC_IMPL(__imp__sub_8255A4E8) {
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
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x8255A504;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a514
	if (cr6.eq) goto loc_8255A514;
	// bl 0x82561250
	ctx.lr = 0x8255A510;
	sub_82561250(ctx, base);
	// b 0x8255a518
	goto loc_8255A518;
loc_8255A514:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255A518:
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r5,148(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// bl 0x82560e00
	ctx.lr = 0x8255A52C;
	sub_82560E00(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255A540"))) PPC_WEAK_FUNC(sub_8255A540);
PPC_FUNC_IMPL(__imp__sub_8255A540) {
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
	// li r3,608
	ctx.r3.s64 = 608;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x8255A55C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a580
	if (cr6.eq) goto loc_8255A580;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82565518
	ctx.lr = 0x8255A56C;
	sub_82565518(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8255A580:
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

__attribute__((alias("__imp__sub_8255A598"))) PPC_WEAK_FUNC(sub_8255A598);
PPC_FUNC_IMPL(__imp__sub_8255A598) {
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
	ctx.lr = 0x8255A5A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8255a690
	if (cr6.eq) goto loc_8255A690;
	// lis r11,16383
	r11.s64 = 1073676288;
	// rlwinm r28,r29,2,0,29
	r28.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8255a5d0
	if (!cr6.gt) goto loc_8255A5D0;
	// li r28,-1
	r28.s64 = -1;
loc_8255A5D0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130528
	ctx.lr = 0x8255A5D8;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8255a5f4
	if (cr6.eq) goto loc_8255A5F4;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8255A5F0;
	sub_823D9890(ctx, base);
	// b 0x8255a5f8
	goto loc_8255A5F8;
loc_8255A5F4:
	// li r30,0
	r30.s64 = 0;
loc_8255A5F8:
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// stw r29,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r29.u32);
	// stw r27,488(r31)
	PPC_STORE_U32(r31.u32 + 488, r27.u32);
	// ble cr6,0x8255a67c
	if (!cr6.gt) goto loc_8255A67C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130528
	ctx.lr = 0x8255A614;
	sub_82130528(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,388(r31)
	PPC_STORE_U32(r31.u32 + 388, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x8255A624;
	sub_823D9890(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f3,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82565290
	ctx.lr = 0x8255A644;
	sub_82565290(ctx, base);
	// lwz r8,408(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x8255a67c
	if (!cr6.gt) goto loc_8255A67C;
	// addi r10,r27,-1
	ctx.r10.s64 = r27.s64 + -1;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
loc_8255A664:
	// lwz r9,388(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// stbx r10,r9,r11
	PPC_STORE_U8(ctx.r9.u32 + r11.u32, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,408(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 408);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255a664
	if (cr6.lt) goto loc_8255A664;
loc_8255A67C:
	// lwz r11,488(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 488);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8255a690
	if (!cr6.eq) goto loc_8255A690;
	// li r11,2
	r11.s64 = 2;
	// stw r11,544(r31)
	PPC_STORE_U32(r31.u32 + 544, r11.u32);
loc_8255A690:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8255A698"))) PPC_WEAK_FUNC(sub_8255A698);
PPC_FUNC_IMPL(__imp__sub_8255A698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x8255A6A0;
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
	// lwz r11,488(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 488);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// lwz r7,56(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// addze r4,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r4.s64 = temp.s64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255A6D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x825674e0
	ctx.lr = 0x8255A6E8;
	sub_825674E0(ctx, base);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r4,r5
	PPC_STORE_U32(ctx.r4.u32 + ctx.r5.u32, r28.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255A710"))) PPC_WEAK_FUNC(sub_8255A710);
PPC_FUNC_IMPL(__imp__sub_8255A710) {
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
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8255A72C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8255a748
	if (cr6.eq) goto loc_8255A748;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
loc_8255A748:
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x8255A754;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a764
	if (cr6.eq) goto loc_8255A764;
	// bl 0x82568e70
	ctx.lr = 0x8255A760;
	sub_82568E70(ctx, base);
	// b 0x8255a768
	goto loc_8255A768;
loc_8255A764:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255A768:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r9,368(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r6,20(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,400(r31)
	PPC_STORE_U32(r31.u32 + 400, ctx.r3.u32);
	// lwz r5,152(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 152);
	// bl 0x82568d40
	ctx.lr = 0x8255A794;
	sub_82568D40(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r3,56
	ctx.r3.s64 = 56;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x8255A7A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a7b8
	if (cr6.eq) goto loc_8255A7B8;
	// bl 0x82568e70
	ctx.lr = 0x8255A7B4;
	sub_82568E70(ctx, base);
	// b 0x8255a7bc
	goto loc_8255A7BC;
loc_8255A7B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255A7BC:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r9,368(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// lwz r5,156(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 156);
	// bl 0x82568d40
	ctx.lr = 0x8255A7E8;
	sub_82568D40(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255A808"))) PPC_WEAK_FUNC(sub_8255A808);
PPC_FUNC_IMPL(__imp__sub_8255A808) {
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
	ctx.lr = 0x8255A810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8255a878
	if (cr6.eq) goto loc_8255A878;
	// lis r11,16383
	r11.s64 = 1073676288;
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8255a83c
	if (!cr6.gt) goto loc_8255A83C;
	// li r30,-1
	r30.s64 = -1;
loc_8255A83C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x8255A844;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8255a86c
	if (cr6.eq) goto loc_8255A86C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x8255A85C;
	sub_823D9890(ctx, base);
	// stw r31,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r31.u32);
	// stw r29,444(r28)
	PPC_STORE_U32(r28.u32 + 444, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8255A86C:
	// li r31,0
	r31.s64 = 0;
	// stw r29,444(r28)
	PPC_STORE_U32(r28.u32 + 444, r29.u32);
	// stw r31,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r31.u32);
loc_8255A878:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255A880"))) PPC_WEAK_FUNC(sub_8255A880);
PPC_FUNC_IMPL(__imp__sub_8255A880) {
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
	ctx.lr = 0x8255A888;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,112
	ctx.r3.s64 = 112;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82130528
	ctx.lr = 0x8255A8A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255a8bc
	if (cr6.eq) goto loc_8255A8BC;
	// bl 0x825686b8
	ctx.lr = 0x8255A8B4;
	sub_825686B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8255a8c0
	goto loc_8255A8C0;
loc_8255A8BC:
	// li r30,0
	r30.s64 = 0;
loc_8255A8C0:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82568cb8
	ctx.lr = 0x8255A8DC;
	sub_82568CB8(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8255A904"))) PPC_WEAK_FUNC(sub_8255A904);
PPC_FUNC_IMPL(__imp__sub_8255A904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255A908"))) PPC_WEAK_FUNC(sub_8255A908);
PPC_FUNC_IMPL(__imp__sub_8255A908) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,372(r3)
	PPC_STORE_U32(ctx.r3.u32 + 372, ctx.r4.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8255A91C"))) PPC_WEAK_FUNC(sub_8255A91C);
PPC_FUNC_IMPL(__imp__sub_8255A91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255A920"))) PPC_WEAK_FUNC(sub_8255A920);
PPC_FUNC_IMPL(__imp__sub_8255A920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r21{};
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
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255a950
	if (cr6.eq) goto loc_8255A950;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255a958
	if (!cr6.eq) goto loc_8255A958;
loc_8255A950:
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r10.u32);
loc_8255A958:
	// lwz r10,372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x8255a97c
	if (!cr6.eq) goto loc_8255A97C;
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stw r30,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r30.u32);
	// lwz r10,400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stw r30,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r30.u32);
	// b 0x8255a990
	goto loc_8255A990;
loc_8255A97C:
	// lwz r10,400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stw r8,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r8.u32);
loc_8255A990:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255a9b0
	if (cr6.eq) goto loc_8255A9B0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,400(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82635790
	ctx.lr = 0x8255A9B0;
	sub_82635790(ctx, base);
loc_8255A9B0:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255a9d0
	if (cr6.eq) goto loc_8255A9D0;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r4,400(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82560c98
	ctx.lr = 0x8255A9D0;
	sub_82560C98(ctx, base);
loc_8255A9D0:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// stw r30,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r30.u32);
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// stw r30,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r30.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8255ac04
	if (cr6.eq) goto loc_8255AC04;
	// lwz r11,372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 372);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8255ac04
	if (cr6.gt) goto loc_8255AC04;
	// lis r12,-32170
	r12.s64 = -2108293120;
	// addi r12,r12,-22000
	r12.s64 = r12.s64 + -22000;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8255AA24;
	case 1:
		goto loc_8255AA9C;
	case 2:
		goto loc_8255AB14;
	case 3:
		goto loc_8255AB14;
	case 4:
		goto loc_8255AB8C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-21980(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -21980);
	// lwz r18,-21860(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -21860);
	// lwz r18,-21740(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -21740);
	// lwz r18,-21740(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -21740);
	// lwz r18,-21620(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -21620);
loc_8255AA24:
	// lwz r4,412(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aa38
	if (cr6.eq) goto loc_8255AA38;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255AA38;
	sub_82568DA8(ctx, base);
loc_8255AA38:
	// lwz r4,420(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aa4c
	if (cr6.eq) goto loc_8255AA4C;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255AA4C;
	sub_82568DA8(ctx, base);
loc_8255AA4C:
	// lwz r4,416(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aa60
	if (cr6.eq) goto loc_8255AA60;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AA60;
	sub_82568DA8(ctx, base);
loc_8255AA60:
	// lwz r4,424(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aa74
	if (cr6.eq) goto loc_8255AA74;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AA74;
	sub_82568DA8(ctx, base);
loc_8255AA74:
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aa88
	if (cr6.eq) goto loc_8255AA88;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AA88;
	sub_82568DA8(ctx, base);
loc_8255AA88:
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ac04
	if (cr6.eq) goto loc_8255AC04;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// b 0x8255ac00
	goto loc_8255AC00;
loc_8255AA9C:
	// lwz r4,416(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aab0
	if (cr6.eq) goto loc_8255AAB0;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255AAB0;
	sub_82568DA8(ctx, base);
loc_8255AAB0:
	// lwz r4,424(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aac4
	if (cr6.eq) goto loc_8255AAC4;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255AAC4;
	sub_82568DA8(ctx, base);
loc_8255AAC4:
	// lwz r4,412(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aad8
	if (cr6.eq) goto loc_8255AAD8;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AAD8;
	sub_82568DA8(ctx, base);
loc_8255AAD8:
	// lwz r4,420(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aaec
	if (cr6.eq) goto loc_8255AAEC;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AAEC;
	sub_82568DA8(ctx, base);
loc_8255AAEC:
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab00
	if (cr6.eq) goto loc_8255AB00;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB00;
	sub_82568DA8(ctx, base);
loc_8255AB00:
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ac04
	if (cr6.eq) goto loc_8255AC04;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// b 0x8255ac00
	goto loc_8255AC00;
loc_8255AB14:
	// lwz r4,412(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab28
	if (cr6.eq) goto loc_8255AB28;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB28;
	sub_82568DA8(ctx, base);
loc_8255AB28:
	// lwz r4,420(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab3c
	if (cr6.eq) goto loc_8255AB3C;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB3C;
	sub_82568DA8(ctx, base);
loc_8255AB3C:
	// lwz r4,416(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab50
	if (cr6.eq) goto loc_8255AB50;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB50;
	sub_82568DA8(ctx, base);
loc_8255AB50:
	// lwz r4,424(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab64
	if (cr6.eq) goto loc_8255AB64;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB64;
	sub_82568DA8(ctx, base);
loc_8255AB64:
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ab78
	if (cr6.eq) goto loc_8255AB78;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255AB78;
	sub_82568DA8(ctx, base);
loc_8255AB78:
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ac04
	if (cr6.eq) goto loc_8255AC04;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// b 0x8255ac00
	goto loc_8255AC00;
loc_8255AB8C:
	// lwz r4,412(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255aba0
	if (cr6.eq) goto loc_8255ABA0;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255ABA0;
	sub_82568DA8(ctx, base);
loc_8255ABA0:
	// lwz r4,420(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255abb4
	if (cr6.eq) goto loc_8255ABB4;
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// bl 0x82568da8
	ctx.lr = 0x8255ABB4;
	sub_82568DA8(ctx, base);
loc_8255ABB4:
	// lwz r4,416(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255abc8
	if (cr6.eq) goto loc_8255ABC8;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255ABC8;
	sub_82568DA8(ctx, base);
loc_8255ABC8:
	// lwz r4,424(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255abdc
	if (cr6.eq) goto loc_8255ABDC;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255ABDC;
	sub_82568DA8(ctx, base);
loc_8255ABDC:
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255abf0
	if (cr6.eq) goto loc_8255ABF0;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// bl 0x82568da8
	ctx.lr = 0x8255ABF0;
	sub_82568DA8(ctx, base);
loc_8255ABF0:
	// lwz r4,432(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255ac04
	if (cr6.eq) goto loc_8255AC04;
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
loc_8255AC00:
	// bl 0x82568da8
	ctx.lr = 0x8255AC04;
	sub_82568DA8(ctx, base);
loc_8255AC04:
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

__attribute__((alias("__imp__sub_8255AC1C"))) PPC_WEAK_FUNC(sub_8255AC1C);
PPC_FUNC_IMPL(__imp__sub_8255AC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255AC20"))) PPC_WEAK_FUNC(sub_8255AC20);
PPC_FUNC_IMPL(__imp__sub_8255AC20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
loc_8255AC38:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,529(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 529);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255ac4c
	if (cr6.eq) goto loc_8255AC4C;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8255AC4C:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8255ac38
	if (!cr0.eq) goto loc_8255AC38;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AC5C"))) PPC_WEAK_FUNC(sub_8255AC5C);
PPC_FUNC_IMPL(__imp__sub_8255AC5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255AC60"))) PPC_WEAK_FUNC(sub_8255AC60);
PPC_FUNC_IMPL(__imp__sub_8255AC60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r8,24(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// blelr cr6
	if (!cr6.gt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8255acdc
	if (cr6.lt) goto loc_8255ACDC;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8255ACA0:
	// lwz r7,-8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f13,444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f11,444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 444);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 444);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f12,f11
	ctx.f8.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fadds f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// fadds f0,f7,f9
	f0.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// bne 0x8255aca0
	if (!cr0.eq) goto loc_8255ACA0;
loc_8255ACDC:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8255ad0c
	if (!cr6.lt) goto loc_8255AD0C;
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
loc_8255ACF4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f13,444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// bne 0x8255acf4
	if (!cr0.eq) goto loc_8255ACF4;
loc_8255AD0C:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f1,f0,f11
	ctx.f1.f64 = double(float(f0.f64 / ctx.f11.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AD28"))) PPC_WEAK_FUNC(sub_8255AD28);
PPC_FUNC_IMPL(__imp__sub_8255AD28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
loc_8255AD40:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,530(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 530);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255ad54
	if (cr6.eq) goto loc_8255AD54;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8255AD54:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8255ad40
	if (!cr0.eq) goto loc_8255AD40;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AD64"))) PPC_WEAK_FUNC(sub_8255AD64);
PPC_FUNC_IMPL(__imp__sub_8255AD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255AD68"))) PPC_WEAK_FUNC(sub_8255AD68);
PPC_FUNC_IMPL(__imp__sub_8255AD68) {
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
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255AD94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8255adc4
	if (cr6.eq) goto loc_8255ADC4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255adc4
	if (cr6.eq) goto loc_8255ADC4;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x8255adbc
	if (!cr6.lt) goto loc_8255ADBC;
	// bl 0x82561d20
	ctx.lr = 0x8255ADB8;
	sub_82561D20(ctx, base);
	// b 0x8255adc4
	goto loc_8255ADC4;
loc_8255ADBC:
	// ble cr6,0x8255adc4
	if (!cr6.gt) goto loc_8255ADC4;
	// bl 0x82561d90
	ctx.lr = 0x8255ADC4;
	sub_82561D90(ctx, base);
loc_8255ADC4:
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

__attribute__((alias("__imp__sub_8255ADDC"))) PPC_WEAK_FUNC(sub_8255ADDC);
PPC_FUNC_IMPL(__imp__sub_8255ADDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255ADE0"))) PPC_WEAK_FUNC(sub_8255ADE0);
PPC_FUNC_IMPL(__imp__sub_8255ADE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255adf4
	if (!cr6.eq) goto loc_8255ADF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8255ADF4:
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x8255ae08
	if (cr6.lt) goto loc_8255AE08;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8255AE08:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// neg r3,r10
	ctx.r3.s64 = -ctx.r10.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AE18"))) PPC_WEAK_FUNC(sub_8255AE18);
PPC_FUNC_IMPL(__imp__sub_8255AE18) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x825619e8
	sub_825619E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8255AE20"))) PPC_WEAK_FUNC(sub_8255AE20);
PPC_FUNC_IMPL(__imp__sub_8255AE20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82561a50
	sub_82561A50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8255AE38"))) PPC_WEAK_FUNC(sub_8255AE38);
PPC_FUNC_IMPL(__imp__sub_8255AE38) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AE3C"))) PPC_WEAK_FUNC(sub_8255AE3C);
PPC_FUNC_IMPL(__imp__sub_8255AE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255AE40"))) PPC_WEAK_FUNC(sub_8255AE40);
PPC_FUNC_IMPL(__imp__sub_8255AE40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r11,384(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 384);
	// or r9,r11,r10
	ctx.r9.u64 = r11.u64 | ctx.r10.u64;
	// bne cr6,0x8255ae5c
	if (!cr6.eq) goto loc_8255AE5C;
	// andc r9,r11,r10
	ctx.r9.u64 = r11.u64 & ~ctx.r10.u64;
loc_8255AE5C:
	// stb r9,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255AE64"))) PPC_WEAK_FUNC(sub_8255AE64);
PPC_FUNC_IMPL(__imp__sub_8255AE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255AE68"))) PPC_WEAK_FUNC(sub_8255AE68);
PPC_FUNC_IMPL(__imp__sub_8255AE68) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8255AE70;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x8255AE78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82558228
	ctx.lr = 0x8255AE84;
	sub_82558228(ctx, base);
	// lwz r29,24(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8255b280
	if (!cr6.gt) goto loc_8255B280;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmadds f11,f12,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fsqrts f1,f11
	ctx.f1.f64 = double(float(sqrt(ctx.f11.f64)));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8255aed0
	if (!cr6.gt) goto loc_8255AED0;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lfs f2,8376(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8376);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// beq cr6,0x8255aed0
	if (cr6.eq) goto loc_8255AED0;
	// bl 0x823dc480
	ctx.lr = 0x8255AECC;
	sub_823DC480(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
loc_8255AED0:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// addi r31,r11,2192
	r31.s64 = r11.s64 + 2192;
	// ori r7,r10,64167
	ctx.r7.u64 = ctx.r10.u64 | 64167;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lwz r5,2192(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 2192);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r5,r7
	ctx.r10.s64 = ctx.r5.s64 * ctx.r7.s64;
	// lfs f13,-9896(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -9896);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	ctx.f10.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r6,29952
	ctx.r4.s64 = ctx.r6.s64 + 29952;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// addi r28,r29,-1
	r28.s64 = r29.s64 + -1;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lfs f29,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 0);
	// fmr f11,f29
	ctx.f11.f64 = f29.f64;
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// addi r29,r28,1
	r29.s64 = r28.s64 + 1;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// lfs f8,548(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 548);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-31400(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -31400);
	f0.f64 = double(temp.f32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// fmadds f7,f9,f10,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f13.f64));
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmadds f28,f6,f1,f8
	f28.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f8.f64));
	// blt cr6,0x8255b050
	if (cr6.lt) goto loc_8255B050;
	// addi r10,r9,-2
	ctx.r10.s64 = ctx.r9.s64 + -2;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r4,r29,0,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r29,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 30) & 0x3FFFFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
loc_8255AF84:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,464(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255afb4
	if (cr6.eq) goto loc_8255AFB4;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255afa4
	if (!cr6.lt) goto loc_8255AFA4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8255AFA4:
	// lfs f13,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8255afb4
	if (!cr6.gt) goto loc_8255AFB4;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8255AFB4:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,464(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255afe4
	if (cr6.eq) goto loc_8255AFE4;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255afd4
	if (!cr6.lt) goto loc_8255AFD4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8255AFD4:
	// lfs f13,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8255afe4
	if (!cr6.gt) goto loc_8255AFE4;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8255AFE4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,464(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255b014
	if (cr6.eq) goto loc_8255B014;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255b004
	if (!cr6.lt) goto loc_8255B004;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8255B004:
	// lfs f13,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8255b014
	if (!cr6.gt) goto loc_8255B014;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8255B014:
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r10,464(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255b044
	if (cr6.eq) goto loc_8255B044;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255b034
	if (!cr6.lt) goto loc_8255B034;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8255B034:
	// lfs f13,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8255b044
	if (!cr6.gt) goto loc_8255B044;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8255B044:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x8255af84
	if (!cr0.eq) goto loc_8255AF84;
loc_8255B050:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x8255b0a0
	if (cr6.lt) goto loc_8255B0A0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_8255B064:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,464(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 464);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255b094
	if (cr6.eq) goto loc_8255B094;
	// lfs f13,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255b084
	if (!cr6.lt) goto loc_8255B084;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8255B084:
	// lfs f13,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8255b094
	if (!cr6.gt) goto loc_8255B094;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
loc_8255B094:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x8255b064
	if (!cr0.lt) goto loc_8255B064;
loc_8255B0A0:
	// fmr f30,f29
	ctx.fpscr.disableFlushMode();
	f30.f64 = f29.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// ble cr6,0x8255b118
	if (!cr6.gt) goto loc_8255B118;
	// clrldi r10,r6,32
	ctx.r10.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// clrldi r11,r5,32
	r11.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// mulld r10,r10,r7
	ctx.r10.s64 = ctx.r10.s64 * ctx.r7.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lfs f31,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f31.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmuls f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmadds f7,f8,f10,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + f0.f64));
	// fsubs f28,f28,f7
	f28.f64 = double(float(f28.f64 - ctx.f7.f64));
	// bl 0x821ce328
	ctx.lr = 0x8255B104;
	sub_821CE328(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x821ce328
	ctx.lr = 0x8255B118;
	sub_821CE328(ctx, base);
loc_8255B118:
	// stfs f28,548(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r30.u32 + 548, temp.u32);
	// fcmpu cr6,f28,f29
	cr6.compare(f28.f64, f29.f64);
	// bge cr6,0x8255b128
	if (!cr6.lt) goto loc_8255B128;
	// fmr f28,f29
	f28.f64 = f29.f64;
loc_8255B128:
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x8255b234
	if (cr6.lt) goto loc_8255B234;
	// addi r10,r28,1
	ctx.r10.s64 = r28.s64 + 1;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r28,r9,r28
	r28.s64 = r28.s64 - ctx.r9.s64;
loc_8255B144:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f28,460(r9)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + 460, temp.u32);
	// beq cr6,0x8255b164
	if (cr6.eq) goto loc_8255B164;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f30,452(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 452, temp.u32);
loc_8255B164:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x8255b178
	if (cr6.eq) goto loc_8255B178;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f1,456(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 456, temp.u32);
loc_8255B178:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stfs f28,460(r9)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + 460, temp.u32);
	// beq cr6,0x8255b1a0
	if (cr6.eq) goto loc_8255B1A0;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stfs f30,452(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 452, temp.u32);
loc_8255B1A0:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x8255b1b8
	if (cr6.eq) goto loc_8255B1B8;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stfs f1,456(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 456, temp.u32);
loc_8255B1B8:
	// addi r9,r11,-12
	ctx.r9.s64 = r11.s64 + -12;
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stfs f28,460(r6)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r6.u32 + 460, temp.u32);
	// beq cr6,0x8255b1e0
	if (cr6.eq) goto loc_8255B1E0;
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stfs f30,452(r6)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r6.u32 + 452, temp.u32);
loc_8255B1E0:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x8255b1f4
	if (cr6.eq) goto loc_8255B1F4;
	// lwz r7,28(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// stfs f1,456(r6)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + 456, temp.u32);
loc_8255B1F4:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stfs f28,460(r7)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r7.u32 + 460, temp.u32);
	// beq cr6,0x8255b214
	if (cr6.eq) goto loc_8255B214;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stfs f30,452(r7)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r7.u32 + 452, temp.u32);
loc_8255B214:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x8255b228
	if (cr6.eq) goto loc_8255B228;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stfs f1,456(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 456, temp.u32);
loc_8255B228:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x8255b144
	if (!cr0.eq) goto loc_8255B144;
loc_8255B234:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8255b280
	if (cr6.lt) goto loc_8255B280;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
loc_8255B240:
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// fcmpu cr6,f30,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f29.f64);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f28,460(r9)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r9.u32 + 460, temp.u32);
	// beq cr6,0x8255b260
	if (cr6.eq) goto loc_8255B260;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f30,452(r9)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r9.u32 + 452, temp.u32);
loc_8255B260:
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// beq cr6,0x8255b274
	if (cr6.eq) goto loc_8255B274;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// stfs f1,456(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 456, temp.u32);
loc_8255B274:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x8255b240
	if (!cr0.lt) goto loc_8255B240;
loc_8255B280:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x8255B28C;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255B290"))) PPC_WEAK_FUNC(sub_8255B290);
PPC_FUNC_IMPL(__imp__sub_8255B290) {
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
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8255b2ec
	if (cr6.lt) goto loc_8255B2EC;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x8255B2C0;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255b2ec
	if (!cr6.eq) goto loc_8255B2EC;
loc_8255B2CC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x8255B2E0;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255b2cc
	if (cr6.eq) goto loc_8255B2CC;
loc_8255B2EC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255B300"))) PPC_WEAK_FUNC(sub_8255B300);
PPC_FUNC_IMPL(__imp__sub_8255B300) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// li r3,124
	ctx.r3.s64 = 124;
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
	// bl 0x82130528
	ctx.lr = 0x8255B324;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b338
	if (cr6.eq) goto loc_8255B338;
	// bl 0x82565348
	ctx.lr = 0x8255B330;
	sub_82565348(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x8255b33c
	goto loc_8255B33C;
loc_8255B338:
	// li r11,0
	r11.s64 = 0;
loc_8255B33C:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r3,124
	ctx.r3.s64 = 124;
	// lfs f0,-30864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30864);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// lwz r6,136(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 112, temp.u32);
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lfs f0,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 60, temp.u32);
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 64, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x8255B384;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b394
	if (cr6.eq) goto loc_8255B394;
	// bl 0x82565348
	ctx.lr = 0x8255B390;
	sub_82565348(ctx, base);
	// b 0x8255b398
	goto loc_8255B398;
loc_8255B394:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B398:
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x8255B3A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b3b4
	if (cr6.eq) goto loc_8255B3B4;
	// bl 0x82558730
	ctx.lr = 0x8255B3B0;
	sub_82558730(ctx, base);
	// b 0x8255b3b8
	goto loc_8255B3B8;
loc_8255B3B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B3B8:
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x82130528
	ctx.lr = 0x8255B3C4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b3d4
	if (cr6.eq) goto loc_8255B3D4;
	// bl 0x825611b8
	ctx.lr = 0x8255B3D0;
	sub_825611B8(ctx, base);
	// b 0x8255b3d8
	goto loc_8255B3D8;
loc_8255B3D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B3D8:
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8255B3E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b3f4
	if (cr6.eq) goto loc_8255B3F4;
	// bl 0x82568e20
	ctx.lr = 0x8255B3F0;
	sub_82568E20(ctx, base);
	// b 0x8255b3f8
	goto loc_8255B3F8;
loc_8255B3F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B3F8:
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8255B404;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b414
	if (cr6.eq) goto loc_8255B414;
	// bl 0x82568e20
	ctx.lr = 0x8255B410;
	sub_82568E20(ctx, base);
	// b 0x8255b418
	goto loc_8255B418;
loc_8255B414:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B418:
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8255B424;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b434
	if (cr6.eq) goto loc_8255B434;
	// bl 0x82567f40
	ctx.lr = 0x8255B430;
	sub_82567F40(ctx, base);
	// b 0x8255b438
	goto loc_8255B438;
loc_8255B434:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B438:
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8255B444;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b454
	if (cr6.eq) goto loc_8255B454;
	// bl 0x82567f40
	ctx.lr = 0x8255B450;
	sub_82567F40(ctx, base);
	// b 0x8255b458
	goto loc_8255B458;
loc_8255B454:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B458:
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8255B464;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b474
	if (cr6.eq) goto loc_8255B474;
	// bl 0x8256b210
	ctx.lr = 0x8255B470;
	sub_8256B210(ctx, base);
	// b 0x8255b478
	goto loc_8255B478;
loc_8255B474:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255B478:
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8255B484;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b4a8
	if (cr6.eq) goto loc_8255B4A8;
	// bl 0x825629c8
	ctx.lr = 0x8255B490;
	sub_825629C8(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8255B4A8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255B4C4"))) PPC_WEAK_FUNC(sub_8255B4C4);
PPC_FUNC_IMPL(__imp__sub_8255B4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B4C8"))) PPC_WEAK_FUNC(sub_8255B4C8);
PPC_FUNC_IMPL(__imp__sub_8255B4C8) {
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
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x8255B4DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b4f8
	if (cr6.eq) goto loc_8255B4F8;
	// bl 0x8256b210
	ctx.lr = 0x8255B4E8;
	sub_8256B210(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B4F8:
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

__attribute__((alias("__imp__sub_8255B50C"))) PPC_WEAK_FUNC(sub_8255B50C);
PPC_FUNC_IMPL(__imp__sub_8255B50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B510"))) PPC_WEAK_FUNC(sub_8255B510);
PPC_FUNC_IMPL(__imp__sub_8255B510) {
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
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8255B524;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b540
	if (cr6.eq) goto loc_8255B540;
	// bl 0x82567f40
	ctx.lr = 0x8255B530;
	sub_82567F40(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B540:
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

__attribute__((alias("__imp__sub_8255B554"))) PPC_WEAK_FUNC(sub_8255B554);
PPC_FUNC_IMPL(__imp__sub_8255B554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B558"))) PPC_WEAK_FUNC(sub_8255B558);
PPC_FUNC_IMPL(__imp__sub_8255B558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23528);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255B564"))) PPC_WEAK_FUNC(sub_8255B564);
PPC_FUNC_IMPL(__imp__sub_8255B564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B568"))) PPC_WEAK_FUNC(sub_8255B568);
PPC_FUNC_IMPL(__imp__sub_8255B568) {
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
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x8255B57C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b598
	if (cr6.eq) goto loc_8255B598;
	// bl 0x82558730
	ctx.lr = 0x8255B588;
	sub_82558730(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B598:
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

__attribute__((alias("__imp__sub_8255B5AC"))) PPC_WEAK_FUNC(sub_8255B5AC);
PPC_FUNC_IMPL(__imp__sub_8255B5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B5B0"))) PPC_WEAK_FUNC(sub_8255B5B0);
PPC_FUNC_IMPL(__imp__sub_8255B5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23524(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23524);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255B5BC"))) PPC_WEAK_FUNC(sub_8255B5BC);
PPC_FUNC_IMPL(__imp__sub_8255B5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B5C0"))) PPC_WEAK_FUNC(sub_8255B5C0);
PPC_FUNC_IMPL(__imp__sub_8255B5C0) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8255B5D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b5f0
	if (cr6.eq) goto loc_8255B5F0;
	// bl 0x82568e20
	ctx.lr = 0x8255B5E0;
	sub_82568E20(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B5F0:
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

__attribute__((alias("__imp__sub_8255B604"))) PPC_WEAK_FUNC(sub_8255B604);
PPC_FUNC_IMPL(__imp__sub_8255B604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B608"))) PPC_WEAK_FUNC(sub_8255B608);
PPC_FUNC_IMPL(__imp__sub_8255B608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23520(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23520);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255B614"))) PPC_WEAK_FUNC(sub_8255B614);
PPC_FUNC_IMPL(__imp__sub_8255B614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B618"))) PPC_WEAK_FUNC(sub_8255B618);
PPC_FUNC_IMPL(__imp__sub_8255B618) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8255B62C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b648
	if (cr6.eq) goto loc_8255B648;
	// bl 0x825629c8
	ctx.lr = 0x8255B638;
	sub_825629C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B648:
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

__attribute__((alias("__imp__sub_8255B65C"))) PPC_WEAK_FUNC(sub_8255B65C);
PPC_FUNC_IMPL(__imp__sub_8255B65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B660"))) PPC_WEAK_FUNC(sub_8255B660);
PPC_FUNC_IMPL(__imp__sub_8255B660) {
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
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x82130528
	ctx.lr = 0x8255B674;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b690
	if (cr6.eq) goto loc_8255B690;
	// bl 0x825611b8
	ctx.lr = 0x8255B680;
	sub_825611B8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B690:
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

__attribute__((alias("__imp__sub_8255B6A4"))) PPC_WEAK_FUNC(sub_8255B6A4);
PPC_FUNC_IMPL(__imp__sub_8255B6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B6A8"))) PPC_WEAK_FUNC(sub_8255B6A8);
PPC_FUNC_IMPL(__imp__sub_8255B6A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23512(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23512);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255B6B4"))) PPC_WEAK_FUNC(sub_8255B6B4);
PPC_FUNC_IMPL(__imp__sub_8255B6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B6B8"))) PPC_WEAK_FUNC(sub_8255B6B8);
PPC_FUNC_IMPL(__imp__sub_8255B6B8) {
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
	// li r3,124
	ctx.r3.s64 = 124;
	// bl 0x82130528
	ctx.lr = 0x8255B6CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b6e8
	if (cr6.eq) goto loc_8255B6E8;
	// bl 0x82565348
	ctx.lr = 0x8255B6D8;
	sub_82565348(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255B6E8:
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

__attribute__((alias("__imp__sub_8255B6FC"))) PPC_WEAK_FUNC(sub_8255B6FC);
PPC_FUNC_IMPL(__imp__sub_8255B6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B700"))) PPC_WEAK_FUNC(sub_8255B700);
PPC_FUNC_IMPL(__imp__sub_8255B700) {
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
	ctx.lr = 0x8255B708;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// addi r9,r11,-9980
	ctx.r9.s64 = r11.s64 + -9980;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255b780
	if (cr6.eq) goto loc_8255B780;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255b740
	if (cr6.eq) goto loc_8255B740;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x8255b744
	goto loc_8255B744;
loc_8255B740:
	// li r11,-1
	r11.s64 = -1;
loc_8255B744:
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8255b780
	if (cr6.eq) goto loc_8255B780;
	// lwz r3,-2288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -2288);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b784
	if (cr6.eq) goto loc_8255B784;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255b770
	if (cr6.eq) goto loc_8255B770;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x8255b774
	goto loc_8255B774;
loc_8255B770:
	// li r11,-1
	r11.s64 = -1;
loc_8255B774:
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// bl 0x8258b6c8
	ctx.lr = 0x8255B780;
	sub_8258B6C8(ctx, base);
loc_8255B780:
	// lwz r3,-2288(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -2288);
loc_8255B784:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8255b7a0
	if (cr6.eq) goto loc_8255B7A0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b7a0
	if (cr6.eq) goto loc_8255B7A0;
	// bl 0x82588338
	ctx.lr = 0x8255B7A0;
	sub_82588338(ctx, base);
loc_8255B7A0:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b7c0
	if (cr6.eq) goto loc_8255B7C0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B7C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B7C0:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b7e0
	if (cr6.eq) goto loc_8255B7E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B7E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B7E0:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b800
	if (cr6.eq) goto loc_8255B800;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B800;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B800:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b820
	if (cr6.eq) goto loc_8255B820;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B820:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255b86c
	if (!cr6.gt) goto loc_8255B86C;
	// li r30,0
	r30.s64 = 0;
loc_8255B834:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b858
	if (cr6.eq) goto loc_8255B858;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B858:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8255b834
	if (cr6.lt) goto loc_8255B834;
loc_8255B86C:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x8255B874;
	sub_82130588(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255b8c0
	if (!cr6.gt) goto loc_8255B8C0;
	// li r30,0
	r30.s64 = 0;
loc_8255B888:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b8ac
	if (cr6.eq) goto loc_8255B8AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B8AC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8255b888
	if (cr6.lt) goto loc_8255B888;
loc_8255B8C0:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130588
	ctx.lr = 0x8255B8C8;
	sub_82130588(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255b914
	if (!cr6.gt) goto loc_8255B914;
	// li r30,0
	r30.s64 = 0;
loc_8255B8DC:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b900
	if (cr6.eq) goto loc_8255B900;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B900:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8255b8dc
	if (cr6.lt) goto loc_8255B8DC;
loc_8255B914:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82130588
	ctx.lr = 0x8255B91C;
	sub_82130588(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255b968
	if (!cr6.gt) goto loc_8255B968;
	// li r30,0
	r30.s64 = 0;
loc_8255B930:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b954
	if (cr6.eq) goto loc_8255B954;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B954:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8255b930
	if (cr6.lt) goto loc_8255B930;
loc_8255B968:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x8255B970;
	sub_82130588(ctx, base);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255b990
	if (cr6.eq) goto loc_8255B990;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255B990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255B990:
	// lwz r3,388(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 388);
	// bl 0x82130588
	ctx.lr = 0x8255B998;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82558170
	ctx.lr = 0x8255B9A0;
	sub_82558170(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255B9A8"))) PPC_WEAK_FUNC(sub_8255B9A8);
PPC_FUNC_IMPL(__imp__sub_8255B9A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255B9BC"))) PPC_WEAK_FUNC(sub_8255B9BC);
PPC_FUNC_IMPL(__imp__sub_8255B9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255B9C0"))) PPC_WEAK_FUNC(sub_8255B9C0);
PPC_FUNC_IMPL(__imp__sub_8255B9C0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8255B9C8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8255baa4
	if (!cr6.eq) goto loc_8255BAA4;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x8255B9F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255ba08
	if (cr6.eq) goto loc_8255BA08;
	// bl 0x8258f538
	ctx.lr = 0x8255BA00;
	sub_8258F538(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8255ba0c
	goto loc_8255BA0C;
loc_8255BA08:
	// li r31,0
	r31.s64 = 0;
loc_8255BA0C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8258e6b8
	ctx.lr = 0x8255BA18;
	sub_8258E6B8(ctx, base);
	// lwz r9,368(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// li r11,80
	r11.s64 = 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,112(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x825a42c8
	ctx.lr = 0x8255BA48;
	sub_825A42C8(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255BA60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,52(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8255BA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,368(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	// lfs f1,124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255BA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82595580
	ctx.lr = 0x8255BAA4;
	sub_82595580(ctx, base);
loc_8255BAA4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8255bab4
	if (cr6.eq) goto loc_8255BAB4;
	// stw r28,128(r30)
	PPC_STORE_U32(r30.u32 + 128, r28.u32);
	// b 0x8255bad4
	goto loc_8255BAD4;
loc_8255BAB4:
	// li r3,672
	ctx.r3.s64 = 672;
	// bl 0x82130528
	ctx.lr = 0x8255BABC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255bacc
	if (cr6.eq) goto loc_8255BACC;
	// bl 0x8259caa8
	ctx.lr = 0x8255BAC8;
	sub_8259CAA8(ctx, base);
	// b 0x8255bad0
	goto loc_8255BAD0;
loc_8255BACC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8255BAD0:
	// stw r3,128(r30)
	PPC_STORE_U32(r30.u32 + 128, ctx.r3.u32);
loc_8255BAD4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,128(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// bl 0x8259e648
	ctx.lr = 0x8255BAE0;
	sub_8259E648(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lwz r9,128(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,-9892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9892);
	f0.f64 = double(temp.f32);
	// stfs f0,204(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 204, temp.u32);
	// lwz r8,128(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lfs f13,23944(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 23944);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,200(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 200, temp.u32);
	// bl 0x8258e660
	ctx.lr = 0x8255BB10;
	sub_8258E660(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8255bb5c
	if (cr6.eq) goto loc_8255BB5C;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255bb5c
	if (cr6.eq) goto loc_8255BB5C;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8255bb3c
	if (cr6.eq) goto loc_8255BB3C;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8255bb40
	if (!cr6.eq) goto loc_8255BB40;
loc_8255BB3C:
	// li r11,1
	r11.s64 = 1;
loc_8255BB40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255bb5c
	if (!cr6.eq) goto loc_8255BB5C;
	// lwz r11,368(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 368);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// bl 0x825832c8
	ctx.lr = 0x8255BB5C;
	sub_825832C8(ctx, base);
loc_8255BB5C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255BB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8255BB7C"))) PPC_WEAK_FUNC(sub_8255BB7C);
PPC_FUNC_IMPL(__imp__sub_8255BB7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255BB80"))) PPC_WEAK_FUNC(sub_8255BB80);
PPC_FUNC_IMPL(__imp__sub_8255BB80) {
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
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8255BB88;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d8
	ctx.lr = 0x8255BB90;
	// addi r31,r1,-320
	r31.s64 = ctx.r1.s64 + -320;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,7700
	ctx.r6.s64 = ctx.r10.s64 + 7700;
	// addi r5,r9,24380
	ctx.r5.s64 = ctx.r9.s64 + 24380;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x823dedd8
	ctx.lr = 0x8255BBC8;
	sub_823DEDD8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// lfs f31,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f31.f64 = double(temp.f32);
	// lfs f28,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f28.f64 = double(temp.f32);
	// beq cr6,0x8255bdc0
	if (cr6.eq) goto loc_8255BDC0;
	// lwz r10,412(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 412);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8255bdc0
	if (cr6.eq) goto loc_8255BDC0;
	// lhz r4,146(r21)
	ctx.r4.u64 = PPC_LOAD_U16(r21.u32 + 146);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// blt cr6,0x8255bd28
	if (cr6.lt) goto loc_8255BD28;
	// lwz r9,132(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// lfs f0,384(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 384);
	f0.f64 = double(temp.f32);
	// lfs f13,388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r4,-3
	ctx.r8.s64 = ctx.r4.s64 + -3;
	// lfs f12,392(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 392);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r9,112
	ctx.r9.s64 = ctx.r9.s64 + 112;
	// li r5,-64
	ctx.r5.s64 = -64;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r10,128
	ctx.r10.s64 = 128;
loc_8255BC28:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsubs f7,f11,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// bge cr6,0x8255bc64
	if (!cr6.lt) goto loc_8255BC64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_8255BC64:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// lfs f11,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// bge cr6,0x8255bca0
	if (!cr6.lt) goto loc_8255BCA0;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
loc_8255BCA0:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lvx128 v61,r9,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f11,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f3,f10,f10,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// bge cr6,0x8255bcdc
	if (!cr6.lt) goto loc_8255BCDC;
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
loc_8255BCDC:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lvx128 v60,r9,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f9,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// lfs f7,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// bge cr6,0x8255bd18
	if (!cr6.lt) goto loc_8255BD18;
	// addi r7,r11,3
	ctx.r7.s64 = r11.s64 + 3;
loc_8255BD18:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,256
	ctx.r9.s64 = ctx.r9.s64 + 256;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255bc28
	if (cr6.lt) goto loc_8255BC28;
loc_8255BD28:
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x8255bd9c
	if (!cr6.lt) goto loc_8255BD9C;
	// lwz r10,412(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 412);
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r8,132(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lfs f0,384(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 384);
	f0.f64 = double(temp.f32);
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// lfs f13,388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,392(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 392);
	ctx.f12.f64 = double(temp.f32);
loc_8255BD50:
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f11,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f3,f10,f10,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// bge cr6,0x8255bd8c
	if (!cr6.lt) goto loc_8255BD8C;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_8255BD8C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// blt cr6,0x8255bd50
	if (cr6.lt) goto loc_8255BD50;
loc_8255BD9C:
	// cmpwi cr6,r7,-1
	cr6.compare<int32_t>(ctx.r7.s32, -1, xer);
	// beq cr6,0x8255bdc0
	if (cr6.eq) goto loc_8255BDC0;
	// stw r7,392(r29)
	PPC_STORE_U32(r29.u32 + 392, ctx.r7.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,0
	ctx.r3.s64 = 0;
	// fmr f3,f28
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f28.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lfs f2,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82565290
	ctx.lr = 0x8255BDC0;
	sub_82565290(ctx, base);
loc_8255BDC0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,392(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// li r28,48
	r28.s64 = 48;
	// li r26,16
	r26.s64 = 16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// lfs f29,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// ble cr6,0x8255bfcc
	if (!cr6.gt) goto loc_8255BFCC;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255bfcc
	if (!cr6.gt) goto loc_8255BFCC;
	// lis r23,-32114
	r23.s64 = -2104623104;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r24,0
	r24.s64 = 0;
	// li r22,2
	r22.s64 = 2;
	// li r19,160
	r19.s64 = 160;
	// lfs f0,-23472(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -23472);
	f0.f64 = double(temp.f32);
	// li r20,144
	r20.s64 = 144;
	// lfs f30,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f30.f64 = double(temp.f32);
loc_8255BE0C:
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// lwz r10,128(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 128);
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r8,r10
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8255bfb8
	if (cr6.eq) goto loc_8255BFB8;
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r10,r31,96
	ctx.r10.s64 = r31.s64 + 96;
	// lvx128 v58,r30,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// lwzx r27,r11,r24
	r27.u64 = PPC_LOAD_U32(r11.u32 + r24.u32);
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255be84
	if (!cr6.eq) goto loc_8255BE84;
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x8255be70
	if (!cr6.gt) goto loc_8255BE70;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255BE70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255BE70:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82582570
	ctx.lr = 0x8255BE80;
	sub_82582570(ctx, base);
	// b 0x8255bfb0
	goto loc_8255BFB0;
loc_8255BE84:
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bne cr6,0x8255bfb8
	if (!cr6.eq) goto loc_8255BFB8;
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x8255beac
	if (!cr6.gt) goto loc_8255BEAC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255BEAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255BEAC:
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8255bee8
	if (cr6.lt) goto loc_8255BEE8;
	// beq cr6,0x8255bee0
	if (cr6.eq) goto loc_8255BEE0;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8255becc
	if (cr6.lt) goto loc_8255BECC;
	// lfs f0,112(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 112);
	f0.f64 = double(temp.f32);
	// b 0x8255beec
	goto loc_8255BEEC;
loc_8255BECC:
	// lfs f0,144(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f13,128(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f0,f12,f0,f13
	f0.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// b 0x8255beec
	goto loc_8255BEEC;
loc_8255BEE0:
	// lfs f0,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	f0.f64 = double(temp.f32);
	// b 0x8255beec
	goto loc_8255BEEC;
loc_8255BEE8:
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
loc_8255BEEC:
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f13,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmuls f11,f11,f29
	ctx.f11.f64 = double(float(ctx.f11.f64 * f29.f64));
	// beq cr6,0x8255bf1c
	if (cr6.eq) goto loc_8255BF1C;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8255bf44
	goto loc_8255BF44;
loc_8255BF1C:
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// lvx128 v0,r30,r19
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r30,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvrx128 v56,r26,r11
	temp.u32 = r26.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v54,v55,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vupkhsb128 v53,v54,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v54.s16), simde_mm_load_si128((simde__m128i*)v54.s16))));
	// vcsxwfp128 v12,v53,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmaddfp v11,v12,v13,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8255BF44:
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f0,f0,f0,f13
	f0.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x8255bf64
	if (!cr6.gt) goto loc_8255BF64;
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// b 0x8255bf68
	goto loc_8255BF68;
loc_8255BF64:
	// fmr f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f28.f64;
loc_8255BF68:
	// fsubs f10,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f9,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fabs f0,f9
	f0.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fabs f8,f10
	ctx.f8.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f30
	cr6.compare(ctx.f8.f64, f30.f64);
	// bgt cr6,0x8255bf90
	if (cr6.gt) goto loc_8255BF90;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f9,f30
	cr6.compare(ctx.f9.f64, f30.f64);
	// ble cr6,0x8255bfb0
	if (!cr6.gt) goto loc_8255BFB0;
loc_8255BF90:
	// fdivs f2,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f12.f64 / ctx.f13.f64));
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fdivs f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 / f0.f64));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// fmr f3,f2
	ctx.f3.f64 = ctx.f2.f64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255BFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255BFB0:
	// stw r22,544(r29)
	PPC_STORE_U32(r29.u32 + 544, r22.u32);
	// lfs f0,-23472(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + -23472);
	f0.f64 = double(temp.f32);
loc_8255BFB8:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8255be0c
	if (cr6.lt) goto loc_8255BE0C;
loc_8255BFCC:
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8255c208
	if (cr6.eq) goto loc_8255C208;
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x8255c208
	if (!cr6.gt) goto loc_8255C208;
	// lwz r11,136(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 136);
	// lwz r10,132(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// lwz r9,408(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 408);
	// subf r8,r10,r11
	ctx.r8.s64 = r11.s64 - ctx.r10.s64;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// neg r5,r7
	ctx.r5.s64 = -ctx.r7.s64;
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r12,r5,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// bl 0x823dbff4
	ctx.lr = 0x8255C00C;
	sub_823DBFF4(ctx, base);
	// lwz r3,0(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r30,32
	r30.s64 = 32;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stwux r3,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x8255c0f8
	if (!cr6.gt) goto loc_8255C0F8;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8255C034:
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// addi r5,r31,160
	ctx.r5.s64 = r31.s64 + 160;
	// lwz r10,132(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// addi r4,r31,160
	ctx.r4.s64 = r31.s64 + 160;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwzx r10,r3,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lvx128 v52,r11,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 - f29.f64));
	// lvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f10,f11,f12,f29
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// stfs f9,164(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lvx128 v51,r0,r4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f0,r8,r27
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r27.u32, temp.u32);
	// beq cr6,0x8255c0e4
	if (cr6.eq) goto loc_8255C0E4;
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,388(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 388);
	f0.f64 = double(temp.f32);
	// lwz r11,136(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 136);
	// addi r4,r31,160
	ctx.r4.s64 = r31.s64 + 160;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f13,84(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// stfs f11,164(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lvx128 v50,r0,r4
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8255C0E4:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8255c034
	if (cr6.lt) goto loc_8255C034;
loc_8255C0F8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f31,8(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 8);
	f31.f64 = double(temp.f32);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8259ada8
	ctx.lr = 0x8255C108;
	sub_8259ADA8(ctx, base);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c194
	if (cr6.eq) goto loc_8255C194;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lhz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8255c13c
	if (cr6.lt) goto loc_8255C13C;
	// lhz r11,38(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 38);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8255c140
	if (cr6.lt) goto loc_8255C140;
loc_8255C13C:
	// li r11,0
	r11.s64 = 0;
loc_8255C140:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c16c
	if (cr6.eq) goto loc_8255C16C;
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x8255c170
	if (!cr6.eq) goto loc_8255C170;
loc_8255C16C:
	// li r11,0
	r11.s64 = 0;
loc_8255C170:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c194
	if (cr6.eq) goto loc_8255C194;
	// lfs f0,8(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8255c194
	if (cr6.eq) goto loc_8255C194;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82573b58
	ctx.lr = 0x8255C194;
	sub_82573B58(ctx, base);
loc_8255C194:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255c208
	if (!cr6.gt) goto loc_8255C208;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
loc_8255C1A8:
	// lwz r11,392(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 392);
	// addi r7,r31,160
	ctx.r7.s64 = r31.s64 + 160;
	// lwz r8,132(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 132);
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lvx128 v49,r11,r28
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r11,r26
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r11,r30
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lvx128 v45,r0,r6
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,24(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// blt cr6,0x8255c1a8
	if (cr6.lt) goto loc_8255C1A8;
loc_8255C208:
	// addi r1,r31,320
	ctx.r1.s64 = r31.s64 + 320;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba24
	ctx.lr = 0x8255C214;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8255C218"))) PPC_WEAK_FUNC(sub_8255C218);
PPC_FUNC_IMPL(__imp__sub_8255C218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91ec
	ctx.lr = 0x8255C220;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,-23482(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -23482);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255c27c
	if (cr6.eq) goto loc_8255C27C;
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c27c
	if (cr6.eq) goto loc_8255C27C;
	// lwz r10,412(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// lfs f0,392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 392);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,392(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 392);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,104(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
loc_8255C27C:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255c2ac
	if (cr6.eq) goto loc_8255C2AC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C2AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C2AC:
	// lwz r3,400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255c2c8
	if (cr6.eq) goto loc_8255C2C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C2C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C2C8:
	// lwz r3,404(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255c2e4
	if (cr6.eq) goto loc_8255C2E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C2E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C2E4:
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8255c300
	if (cr6.eq) goto loc_8255C300;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8255c304
	if (!cr6.eq) goto loc_8255C304;
loc_8255C300:
	// li r11,1
	r11.s64 = 1;
loc_8255C304:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r30,80
	r30.s64 = 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255c384
	if (!cr6.eq) goto loc_8255C384;
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lfs f31,112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	f31.f64 = double(temp.f32);
	// lvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a42c8
	ctx.lr = 0x8255C340;
	sub_825A42C8(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r29,4(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8255C364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,52(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8255C37C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x8259cc00
	ctx.lr = 0x8255C384;
	sub_8259CC00(ctx, base);
loc_8255C384:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8255c3b4
	if (cr6.eq) goto loc_8255C3B4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8255c3b8
	if (!cr6.eq) goto loc_8255C3B8;
loc_8255C3B4:
	// li r11,1
	r11.s64 = 1;
loc_8255C3B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255c3dc
	if (!cr6.eq) goto loc_8255C3DC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// bl 0x825832c8
	ctx.lr = 0x8255C3DC;
	sub_825832C8(ctx, base);
loc_8255C3DC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lfs f1,124(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// lwz r29,4(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255C404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,368(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v62,r5,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,112(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8255C42C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f4,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a42c8
	ctx.lr = 0x8255C448;
	sub_825A42C8(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8255C460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c488
	if (cr6.eq) goto loc_8255C488;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r10.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8255C488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C488:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c4b0
	if (cr6.eq) goto loc_8255C4B0;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8255C4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C4B0:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255c4d0
	if (!cr6.gt) goto loc_8255C4D0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C4D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C4D0:
	// lwz r3,436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 436);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c4ec
	if (cr6.eq) goto loc_8255C4EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C4EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C4EC:
	// lwz r3,440(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 440);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c508
	if (cr6.eq) goto loc_8255C508;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C508:
	// lwz r3,412(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c524
	if (cr6.eq) goto loc_8255C524;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C524:
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c540
	if (cr6.eq) goto loc_8255C540;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C540:
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c55c
	if (cr6.eq) goto loc_8255C55C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C55C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C55C:
	// lwz r3,424(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c578
	if (cr6.eq) goto loc_8255C578;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255C578:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f31,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8255c5c8
	if (cr6.eq) goto loc_8255C5C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// lwz r9,416(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// lfs f0,428(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	f0.f64 = double(temp.f32);
	// lfs f13,428(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 428);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fmuls f30,f12,f31
	f30.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82564758
	ctx.lr = 0x8255C5BC;
	sub_82564758(ctx, base);
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82564758
	ctx.lr = 0x8255C5C8;
	sub_82564758(ctx, base);
loc_8255C5C8:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c610
	if (cr6.eq) goto loc_8255C610;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255C5E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// lwz r9,424(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// lfs f0,428(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 428);
	f0.f64 = double(temp.f32);
	// lfs f13,428(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 428);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fmuls f31,f12,f31
	f31.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82564758
	ctx.lr = 0x8255C604;
	sub_82564758(ctx, base);
	// lwz r3,424(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82564758
	ctx.lr = 0x8255C610;
	sub_82564758(ctx, base);
loc_8255C610:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r27,0
	r27.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// ble cr6,0x8255c764
	if (!cr6.gt) goto loc_8255C764;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r1,192
	r29.s64 = ctx.r1.s64 + 192;
	// addi r26,r10,-31616
	r26.s64 = ctx.r10.s64 + -31616;
loc_8255C640:
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lvx128 v127,r0,r26
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r3,384
	r28.s64 = ctx.r3.s64 + 384;
	// lfs f30,432(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 432);
	f30.f64 = double(temp.f32);
	// bl 0x82564b38
	ctx.lr = 0x8255C654;
	sub_82564B38(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fsubs f0,f1,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f30.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v126,r0,r26
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmaddfp128 v61,v127,v59,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(v61.f32)));
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// addi r28,r3,384
	r28.s64 = ctx.r3.s64 + 384;
	// lfs f30,432(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 432);
	f30.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82564b50
	ctx.lr = 0x8255C690;
	sub_82564B50(ctx, base);
	// fneg f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r29,16
	ctx.r10.s64 = r29.s64 + 16;
	// addi r9,r27,1
	ctx.r9.s64 = r27.s64 + 1;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// addi r29,r10,16
	r29.s64 = ctx.r10.s64 + 16;
	// addi r27,r9,1
	r27.s64 = ctx.r9.s64 + 1;
	// fsubs f9,f13,f30
	ctx.f9.f64 = double(float(ctx.f13.f64 - f30.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v57,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lfs f8,416(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 416);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 + ctx.f8.f64));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f6,f11,f8
	ctx.f6.f64 = double(float(ctx.f11.f64 + ctx.f8.f64));
	// stfs f6,116(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f5,f10,f8
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f8.f64));
	// stfs f5,120(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmaddfp128 v58,v126,v55,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v55.f32)), simde_mm_load_ps(v58.f32)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f4,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// fadds f0,f4,f8
	f0.f64 = double(float(ctx.f4.f64 + ctx.f8.f64));
	// fadds f1,f2,f8
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f8.f64));
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f13,f3,f8
	ctx.f13.f64 = double(float(ctx.f3.f64 + ctx.f8.f64));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v54,r0,r6
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lfs f12,420(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 420);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// bge cr6,0x8255c750
	if (!cr6.lt) goto loc_8255C750;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lfs f31,420(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 420);
	f31.f64 = double(temp.f32);
loc_8255C750:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// blt cr6,0x8255c640
	if (cr6.lt) goto loc_8255C640;
loc_8255C764:
	// addi r30,r31,496
	r30.s64 = r31.s64 + 496;
	// addi r9,r31,512
	ctx.r9.s64 = r31.s64 + 512;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8261a938
	ctx.lr = 0x8255C788;
	sub_8261A938(ctx, base);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v53,r0,r30
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,528
	r11.s64 = r31.s64 + 528;
	// lfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v53,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,504(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 504);
	ctx.f10.f64 = double(temp.f32);
	// lfs f5,496(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 496);
	ctx.f5.f64 = double(temp.f32);
	// lfs f9,532(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 532);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,528(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 528);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 536);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,512(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	ctx.f6.f64 = double(temp.f32);
	// lfs f11,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f3,f0,f11
	ctx.f3.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f4,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// fsubs f2,f12,f10
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fsubs f13,f9,f3
	ctx.f13.f64 = double(float(ctx.f9.f64 - ctx.f3.f64));
	// fadds f0,f6,f31
	f0.f64 = double(float(ctx.f6.f64 + f31.f64));
	// stfs f0,512(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// fsubs f1,f8,f4
	ctx.f1.f64 = double(float(ctx.f8.f64 - ctx.f4.f64));
	// fsubs f12,f7,f2
	ctx.f12.f64 = double(float(ctx.f7.f64 - ctx.f2.f64));
	// fsel f10,f13,f9,f3
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? ctx.f9.f64 : ctx.f3.f64;
	// stfs f10,532(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// fsel f11,f1,f8,f4
	ctx.f11.f64 = ctx.f1.f64 >= 0.0 ? ctx.f8.f64 : ctx.f4.f64;
	// stfs f11,528(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// fsel f9,f12,f7,f2
	ctx.f9.f64 = ctx.f12.f64 >= 0.0 ? ctx.f7.f64 : ctx.f2.f64;
	// stfs f9,536(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// fmr f7,f10
	ctx.f7.f64 = ctx.f10.f64;
	// fmr f6,f11
	ctx.f6.f64 = ctx.f11.f64;
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fadds f4,f7,f31
	ctx.f4.f64 = double(float(ctx.f7.f64 + f31.f64));
	// stfs f4,532(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// fadds f5,f6,f31
	ctx.f5.f64 = double(float(ctx.f6.f64 + f31.f64));
	// stfs f5,528(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// fadds f3,f8,f31
	ctx.f3.f64 = double(float(ctx.f8.f64 + f31.f64));
	// stfs f3,536(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// bl 0x8255bb80
	ctx.lr = 0x8255C82C;
	sub_8255BB80(ctx, base);
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8255C84C"))) PPC_WEAK_FUNC(sub_8255C84C);
PPC_FUNC_IMPL(__imp__sub_8255C84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255C850"))) PPC_WEAK_FUNC(sub_8255C850);
PPC_FUNC_IMPL(__imp__sub_8255C850) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8255C858;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x8255C860;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f28,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lfs f30,132(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// lfs f29,140(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f29.f64 = double(temp.f32);
	// lfs f27,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f27.f64 = double(temp.f32);
	// bge cr6,0x8255c890
	if (!cr6.lt) goto loc_8255C890;
	// fneg f31,f0
	f31.u64 = f0.u64 ^ 0x8000000000000000;
	// b 0x8255c894
	goto loc_8255C894;
loc_8255C890:
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
loc_8255C894:
	// lwz r3,412(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c8b0
	if (cr6.eq) goto loc_8255C8B0;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x825652b8
	ctx.lr = 0x8255C8B0;
	sub_825652B8(ctx, base);
loc_8255C8B0:
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c8cc
	if (cr6.eq) goto loc_8255C8CC;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x825652b8
	ctx.lr = 0x8255C8CC;
	sub_825652B8(ctx, base);
loc_8255C8CC:
	// lfs f31,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// bgt cr6,0x8255c8dc
	if (cr6.gt) goto loc_8255C8DC;
	// fmr f31,f28
	f31.f64 = f28.f64;
loc_8255C8DC:
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c8f8
	if (cr6.eq) goto loc_8255C8F8;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x825652b8
	ctx.lr = 0x8255C8F8;
	sub_825652B8(ctx, base);
loc_8255C8F8:
	// lwz r3,424(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c914
	if (cr6.eq) goto loc_8255C914;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x825652b8
	ctx.lr = 0x8255C914;
	sub_825652B8(ctx, base);
loc_8255C914:
	// lwz r3,428(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 428);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c930
	if (cr6.eq) goto loc_8255C930;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x825652b8
	ctx.lr = 0x8255C930;
	sub_825652B8(ctx, base);
loc_8255C930:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255c94c
	if (cr6.eq) goto loc_8255C94C;
	// fmr f3,f31
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fneg f1,f30
	ctx.f1.u64 = f30.u64 ^ 0x8000000000000000;
	// bl 0x825652b8
	ctx.lr = 0x8255C94C;
	sub_825652B8(ctx, base);
loc_8255C94C:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255c960
	if (cr6.eq) goto loc_8255C960;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,32(r11)
	PPC_STORE_U8(r11.u32 + 32, ctx.r10.u8);
loc_8255C960:
	// lwz r11,368(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,132(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// bne cr6,0x8255ca68
	if (!cr6.eq) goto loc_8255CA68;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	f0.f64 = double(temp.f32);
	// lfs f13,-31652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31652);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8255c99c
	if (!cr6.lt) goto loc_8255C99C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// b 0x8255c9b0
	goto loc_8255C9B0;
loc_8255C99C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,-9888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9888);
	ctx.f13.f64 = double(temp.f32);
loc_8255C9A4:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8255c9b0
	if (!cr6.gt) goto loc_8255C9B0;
	// stfs f28,396(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
loc_8255C9B0:
	// lfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	f0.f64 = double(temp.f32);
	// li r28,1
	r28.s64 = 1;
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x8255ca08
	if (!cr6.gt) goto loc_8255CA08;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255c9f8
	if (!cr6.gt) goto loc_8255C9F8;
	// li r30,0
	r30.s64 = 0;
loc_8255C9D4:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f1,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82565320
	ctx.lr = 0x8255C9E4;
	sub_82565320(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8255c9d4
	if (cr6.lt) goto loc_8255C9D4;
loc_8255C9F8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255ca08
	if (cr6.eq) goto loc_8255CA08;
	// stb r28,32(r11)
	PPC_STORE_U8(r11.u32 + 32, r28.u8);
loc_8255CA08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32692);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// ble cr6,0x8255cb54
	if (!cr6.gt) goto loc_8255CB54;
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// ble cr6,0x8255cb54
	if (!cr6.gt) goto loc_8255CB54;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255cb54
	if (cr6.eq) goto loc_8255CB54;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x8255ca40
	if (cr6.eq) goto loc_8255CA40;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8255cb54
	if (!cr6.eq) goto loc_8255CB54;
loc_8255CA40:
	// lwz r10,400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x8255cacc
	if (!cr6.eq) goto loc_8255CACC;
	// stb r28,32(r11)
	PPC_STORE_U8(r11.u32 + 32, r28.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82561020
	ctx.lr = 0x8255CA64;
	sub_82561020(ctx, base);
	// b 0x8255cb54
	goto loc_8255CB54;
loc_8255CA68:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f0.f64 = double(temp.f32);
	// lfs f13,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8255c9a4
	if (cr6.gt) goto loc_8255C9A4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f11,224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,24920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24920);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x8255c9a4
	if (!cr6.lt) goto loc_8255C9A4;
	// lfs f0,396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bne cr6,0x8255caa8
	if (!cr6.eq) goto loc_8255CAA8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
loc_8255CAA8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14992(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,396(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// ble cr6,0x8255c9b0
	if (!cr6.gt) goto loc_8255C9B0;
	// stfs f31,396(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// b 0x8255c9b0
	goto loc_8255C9B0;
loc_8255CACC:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255cb14
	if (cr6.eq) goto loc_8255CB14;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255cb14
	if (!cr6.gt) goto loc_8255CB14;
	// li r30,24
	r30.s64 = 24;
loc_8255CAEC:
	// lwz r11,404(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82565320
	ctx.lr = 0x8255CAFC;
	sub_82565320(ctx, base);
	// lwz r10,404(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 404);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8255caec
	if (cr6.lt) goto loc_8255CAEC;
loc_8255CB14:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// li r29,0
	r29.s64 = 0;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8255cb54
	if (!cr6.gt) goto loc_8255CB54;
	// li r30,24
	r30.s64 = 24;
loc_8255CB2C:
	// lwz r11,400(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82565320
	ctx.lr = 0x8255CB3C;
	sub_82565320(ctx, base);
	// lwz r10,400(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 400);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8255cb2c
	if (cr6.lt) goto loc_8255CB2C;
loc_8255CB54:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255cba0
	if (cr6.eq) goto loc_8255CBA0;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x825584c8
	ctx.lr = 0x8255CB68;
	sub_825584C8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// ble cr6,0x8255cba0
	if (!cr6.gt) goto loc_8255CBA0;
	// lfs f0,140(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bgt cr6,0x8255cb9c
	if (cr6.gt) goto loc_8255CB9C;
	// lfs f0,144(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bgt cr6,0x8255cb9c
	if (cr6.gt) goto loc_8255CB9C;
	// lfs f0,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bgt cr6,0x8255cba0
	if (cr6.gt) goto loc_8255CBA0;
loc_8255CB9C:
	// bl 0x82558710
	ctx.lr = 0x8255CBA0;
	sub_82558710(ctx, base);
loc_8255CBA0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x8255CBAC;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255CBB0"))) PPC_WEAK_FUNC(sub_8255CBB0);
PPC_FUNC_IMPL(__imp__sub_8255CBB0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8255CBB8;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,496
	ctx.r6.s64 = 496;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// addi r5,r10,2384
	ctx.r5.s64 = ctx.r10.s64 + 2384;
	// lfs f0,532(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 532);
	f0.f64 = double(temp.f32);
	// addi r11,r31,240
	r11.s64 = r31.s64 + 240;
	// lvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r3,2256
	ctx.r6.s64 = ctx.r3.s64 + 2256;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// li r29,16
	r29.s64 = 16;
	// li r27,32
	r27.s64 = 32;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,48
	r28.s64 = 48;
	// vand128 v56,v59,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r10,r4,2352
	ctx.r10.s64 = ctx.r4.s64 + 2352;
	// lvx128 v0,r11,r29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v62,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvlx128 v45,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmrghw128 v57,v0,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vmrglw128 v55,v62,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v0,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v0.u32)));
	// vor128 v52,v62,v56
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// addi r11,r31,532
	r11.s64 = r31.s64 + 532;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// vmrglw128 v53,v58,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vmrghw128 v51,v58,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r26,r1,224
	r26.s64 = ctx.r1.s64 + 224;
	// vmrghw128 v50,v55,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r24,r1,240
	r24.s64 = ctx.r1.s64 + 240;
	// lis r25,-32114
	r25.s64 = -2104623104;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum4fp128 v48,v52,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// lvlx128 v49,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmsum4fp128 v47,v52,v51
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vmsum4fp128 v46,v52,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// li r30,0
	r30.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// vspltw128 v12,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,240
	r23.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r10,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r10.u16);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stfs f31,192(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// sth r30,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r30.u16);
	// stfs f31,196(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stb r30,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r30.u8);
	// sth r30,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r30.u16);
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// stw r30,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r6,28(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lbz r9,384(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 384);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r7,376(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// lwz r3,-23452(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -23452);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// vmrghw128 v44,v48,v52
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v47,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v13,v43,v44
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmaddfp v10,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v13,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// stvx128 v13,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v0,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v10,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x8255CD10;
	sub_82574418(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8255ce60
	if (cr6.eq) goto loc_8255CE60;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255ce90
	if (!cr6.gt) goto loc_8255CE90;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8255CD30:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f13,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f12,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r9,96
	r11.s64 = ctx.r9.s64 + 96;
	// lwz r3,84(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v42,v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v41,v63,v62
	simde_mm_store_ps(v41.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v42,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f12,f9,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f10.f64));
	// lfs f7,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f0,f11,f7,f8
	f0.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 + ctx.f8.f64));
	// stvx128 v41,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// lfs f6,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f13,f4
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f4.f64));
	// fmadds f2,f12,f6,f3
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f13,f11,f5,f2
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f5.f64 + ctx.f2.f64));
	// ble cr6,0x8255ce34
	if (!cr6.gt) goto loc_8255CE34;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bge cr6,0x8255ce34
	if (!cr6.lt) goto loc_8255CE34;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lhz r6,206(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 206);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lhz r4,210(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 210);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lhz r26,204(r1)
	r26.u64 = PPC_LOAD_U16(ctx.r1.u32 + 204);
	// lwz r25,128(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// fneg f11,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fdivs f0,f0,f12
	f0.f64 = double(float(f0.f64 / ctx.f12.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v40,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v40,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r0,r5
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r3
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r26,76(r11)
	PPC_STORE_U16(r11.u32 + 76, r26.u16);
	// stfs f0,64(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// sth r6,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r6.u16);
	// stfs f11,68(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// stb r8,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r8.u8);
	// stvx128 v38,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r4,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r4.u16);
	// stw r30,72(r11)
	PPC_STORE_U32(r11.u32 + 72, r30.u32);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stb r8,288(r9)
	PPC_STORE_U8(ctx.r9.u32 + 288, ctx.r8.u8);
	// b 0x8255ce40
	goto loc_8255CE40;
loc_8255CE34:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stb r30,288(r9)
	PPC_STORE_U8(ctx.r9.u32 + 288, r30.u8);
loc_8255CE40:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r7,r11
	cr6.compare<int32_t>(ctx.r7.s32, r11.s32, xer);
	// blt cr6,0x8255cd30
	if (cr6.lt) goto loc_8255CD30;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8255CE60:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255ce90
	if (!cr6.gt) goto loc_8255CE90;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8255CE70:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stb r30,288(r8)
	PPC_STORE_U8(ctx.r8.u32 + 288, r30.u8);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8255ce70
	if (cr6.lt) goto loc_8255CE70;
loc_8255CE90:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8255CE9C"))) PPC_WEAK_FUNC(sub_8255CE9C);
PPC_FUNC_IMPL(__imp__sub_8255CE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255CEA0"))) PPC_WEAK_FUNC(sub_8255CEA0);
PPC_FUNC_IMPL(__imp__sub_8255CEA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8255CEA8;
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8255d020
	if (cr6.lt) goto loc_8255D020;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,12(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lbz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r8,12
	cr6.compare<uint32_t>(ctx.r8.u32, 12, xer);
	// bne cr6,0x8255d020
	if (!cr6.eq) goto loc_8255D020;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255d020
	if (!cr6.gt) goto loc_8255D020;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r31,48
	r31.s64 = 48;
loc_8255CEF4:
	// lwz r11,392(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 392);
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// add r4,r28,r11
	ctx.r4.u64 = r28.u64 + r11.u64;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8255d00c
	if (cr6.eq) goto loc_8255D00C;
	// addi r11,r3,240
	r11.s64 = ctx.r3.s64 + 240;
	// lwz r6,28(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r5,132(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v62,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmsum3fp128 v58,v61,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v62,v60
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vor128 v54,v60,v60
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vmsum3fp128 v55,v57,v60
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// addi r11,r6,16
	r11.s64 = ctx.r6.s64 + 16;
	// vmrglw128 v51,v62,v61
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// rlwinm r10,r4,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// vmrghw128 v53,v57,v54
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// add r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 + ctx.r10.u64;
	// vmrglw128 v52,v57,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r11,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v47,v50,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvx128 v48,r11,r8
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v0,v59,v53
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v46,r11,r31
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v45,v49,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vspltw128 v44,v48,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vspltw128 v10,v46,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmulfp128 v9,v0,v47
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v47.f32)));
	// vmrglw128 v13,v59,v53
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmulfp128 v8,v0,v45
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v45.f32)));
	// vspltw128 v7,v50,1
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xAA));
	// vmulfp128 v6,v0,v44
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v44.f32)));
	// vspltw128 v5,v49,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xAA));
	// vspltw128 v4,v48,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xAA));
	// vmrghw128 v43,v56,v58
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vspltw128 v3,v46,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xAA));
	// vmrghw128 v12,v51,v52
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vspltw128 v2,v50,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x55));
	// vmrghw128 v42,v55,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vspltw128 v1,v49,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x55));
	// vspltw128 v31,v48,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x55));
	// vspltw128 v30,v46,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x55));
	// vmrghw128 v41,v43,v42
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmaddfp v29,v13,v7,v9
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v28,v13,v5,v8
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v27,v13,v4,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vsubfp128 v11,v63,v41
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v41.f32)));
	// vmaddfp v26,v12,v2,v29
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v29.f32)));
	// vmaddfp v25,v12,v1,v28
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v24,v12,v31,v27
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v23,v0,v10,v11
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v25,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v22,v13,v3,v23
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(v23.f32)));
	// vmaddfp v21,v12,v30,v22
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v22.f32)));
	// stvx128 v21,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,28(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r4,r7,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r5.u32);
	// stb r29,530(r4)
	PPC_STORE_U8(ctx.r4.u32 + 530, r29.u8);
loc_8255D00C:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8255cef4
	if (cr6.lt) goto loc_8255CEF4;
loc_8255D020:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255D024"))) PPC_WEAK_FUNC(sub_8255D024);
PPC_FUNC_IMPL(__imp__sub_8255D024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D028"))) PPC_WEAK_FUNC(sub_8255D028);
PPC_FUNC_IMPL(__imp__sub_8255D028) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f31{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8255D030;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-192
	r12.s64 = -192;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r22,392
	r11.s64 = r22.s64 + 392;
	// lwz r10,392(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 392);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8255d4b0
	if (cr6.lt) goto loc_8255D4B0;
	// addi r31,r30,8
	r31.s64 = r30.s64 + 8;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x8255D080;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8255d4b0
	if (!cr6.eq) goto loc_8255D4B0;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r5,r8,2272
	ctx.r5.s64 = ctx.r8.s64 + 2272;
	// addi r4,r7,8368
	ctx.r4.s64 = ctx.r7.s64 + 8368;
	// li r21,1
	r21.s64 = 1;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// li r14,16
	r14.s64 = 16;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r15,32
	r15.s64 = 32;
	// li r16,48
	r16.s64 = 48;
	// addi r20,r11,2352
	r20.s64 = r11.s64 + 2352;
	// addi r19,r10,2384
	r19.s64 = ctx.r10.s64 + 2384;
	// addi r17,r9,-23452
	r17.s64 = ctx.r9.s64 + -23452;
loc_8255D0D4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r27,r29
	r28.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// lbz r10,165(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 165);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8255d48c
	if (cr6.eq) goto loc_8255D48C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x8255D0FC;
	sub_822A7C28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255d48c
	if (cr6.eq) goto loc_8255D48C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82330c88
	ctx.lr = 0x8255D10C;
	sub_82330C88(ctx, base);
	// lwz r10,392(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 392);
	// addi r11,r22,392
	r11.s64 = r22.s64 + 392;
	// subf. r11,r10,r3
	r11.s64 = ctx.r3.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8255d48c
	if (cr0.lt) goto loc_8255D48C;
	// lwz r10,24(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8255d48c
	if (!cr6.lt) goto loc_8255D48C;
	// lwz r10,28(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 28);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,544(r22)
	ctx.r8.u64 = PPC_LOAD_U32(r22.u32 + 544);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// lwzx r18,r9,r10
	r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r31,r18,96
	r31.s64 = r18.s64 + 96;
	// bne cr6,0x8255d48c
	if (!cr6.eq) goto loc_8255D48C;
	// rotlwi r11,r28,0
	r11.u64 = __builtin_rotateleft32(r28.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v126,v63,3
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// bl 0x82330cc0
	ctx.lr = 0x8255D158;
	sub_82330CC0(ctx, base);
	// lwz r10,160(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 160);
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r11,80
	r11.s64 = 80;
	// lwz r23,0(r10)
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r29,r23
	cr6.compare<uint32_t>(r29.u32, r23.u32, xer);
	// bne cr6,0x8255d17c
	if (!cr6.eq) goto loc_8255D17C;
	// lvx128 v127,r28,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8255d188
	goto loc_8255D188;
loc_8255D17C:
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v61,r28,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v62,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
loc_8255D188:
	// addi r27,r22,256
	r27.s64 = r22.s64 + 256;
	// lhz r26,172(r28)
	r26.u64 = PPC_LOAD_U16(r28.u32 + 172);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v60,r0,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v127,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmulfp128 v126,v126,v59
	simde_mm_store_ps(v126.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v59.f32)));
	// vor128 v125,v126,v126
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vmaddcfp128 v125,v127,v125,v0
	simde_mm_store_ps(v125.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v125.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// bl 0x82489738
	ctx.lr = 0x8255D1AC;
	sub_82489738(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82342598
	ctx.lr = 0x8255D1B8;
	sub_82342598(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x8255D1C4;
	sub_822A7C28(ctx, base);
	// subf r11,r29,r23
	r11.s64 = r23.s64 - r29.s64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x825a2aa8
	ctx.lr = 0x8255D1E4;
	sub_825A2AA8(ctx, base);
	// addi r23,r29,8
	r23.s64 = r29.s64 + 8;
	// lwz r7,0(r17)
	ctx.r7.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r5,380(r22)
	ctx.r5.u64 = PPC_LOAD_U32(r22.u32 + 380);
	// lwz r8,376(r22)
	ctx.r8.u64 = PPC_LOAD_U32(r22.u32 + 376);
	// lhz r4,0(r23)
	ctx.r4.u64 = PPC_LOAD_U16(r23.u32 + 0);
	// lwz r10,112(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lbz r6,384(r22)
	ctx.r6.u64 = PPC_LOAD_U8(r22.u32 + 384);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// andc r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 & ~ctx.r5.u64;
	// and r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 & ctx.r8.u64;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// clrlwi r10,r3,30
	ctx.r10.u64 = ctx.r3.u32 & 0x3;
	// slw r9,r21,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (r21.u32 << (ctx.r10.u8 & 0x3F));
	// and r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 & ctx.r6.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// beq cr6,0x8255d250
	if (cr6.eq) goto loc_8255D250;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r21
	r11.u64 = r21.u64;
	// bne cr6,0x8255d254
	if (!cr6.eq) goto loc_8255D254;
loc_8255D250:
	// li r11,0
	r11.s64 = 0;
loc_8255D254:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255d46c
	if (cr6.eq) goto loc_8255D46C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255d46c
	if (cr6.eq) goto loc_8255D46C;
	// lvx128 v58,r0,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// vmsum3fp128 v57,v127,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v56,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vand128 v61,v55,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v54,v57,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v53,v54,v62
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgefp128. v52,v53,v61
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8255d360
	if (cr6.eq) goto loc_8255D360;
	// vspltw128 v51,v127,1
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0xAA));
	// vand128 v50,v51,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v49,v50,v62
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgefp128. v48,v49,v61
	simde_mm_store_ps(v48.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v48.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255d360
	if (cr6.eq) goto loc_8255D360;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8255d2f8
	if (!cr6.eq) goto loc_8255D2F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x8255D2DC;
	sub_822A7C28(ctx, base);
	// li r11,68
	r11.s64 = 68;
	// stfs f31,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stvx128 v125,r31,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvewx128 v126,r31,r11
	ea = (r31.u32 + r11.u32) & ~0x3;
	PPC_STORE_U32(ea, v126.u32[3 - ((ea & 0xF) >> 2)]);
	// b 0x8255d340
	goto loc_8255D340;
loc_8255D2F8:
	// addi r28,r31,68
	r28.s64 = r31.s64 + 68;
	// vand128 v47,v126,v63
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v46,v47,v62
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v45,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v44,v45,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vand128 v43,v44,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpgtfp128. v42,v46,v43
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v43.f32)));
	cr6.setFromMask(simde_mm_load_ps(v42.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255d360
	if (cr6.eq) goto loc_8255D360;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x8255D32C;
	sub_822A7C28(ctx, base);
	// stfs f31,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stvx128 v125,r31,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvewx128 v126,r0,r28
	ea = (r28.u32) & ~0x3;
	PPC_STORE_U32(ea, v126.u32[3 - ((ea & 0xF) >> 2)]);
loc_8255D340:
	// sth r25,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r25.u16);
	// sth r26,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r26.u16);
	// stb r21,80(r31)
	PPC_STORE_U8(r31.u32 + 80, r21.u8);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r24,82(r31)
	PPC_STORE_U16(r31.u32 + 82, r24.u16);
	// lvx128 v62,r0,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8255D360:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r10,84
	ctx.r10.s64 = 84;
	// lwz r9,4(r18)
	ctx.r9.u64 = PPC_LOAD_U32(r18.u32 + 4);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v126
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v126.f32)));
	// lvlx128 v41,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v41,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// vand128 v40,v61,v63
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v39,v60,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v38,v39,v62
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgtfp128. v37,v38,v40
	simde_mm_store_ps(v37.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v40.f32)));
	cr6.setFromMask(simde_mm_load_ps(v37.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r7,r8,25,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8255d41c
	if (cr6.eq) goto loc_8255D41C;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lhz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U16(r23.u32 + 0);
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,2
	cr6.compare<int32_t>(ctx.r7.s32, 2, xer);
	// bne cr6,0x8255d41c
	if (!cr6.eq) goto loc_8255D41C;
	// stb r21,530(r18)
	PPC_STORE_U8(r18.u32 + 530, r21.u8);
	// vsubfp128 v36,v60,v61
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v35,v36,1,1
	simde_mm_store_ps(v35.f32, simde_mm_blend_ps(simde_mm_load_ps(v35.f32), simde_mm_permute_ps(simde_mm_load_ps(v36.f32), 147), 1));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// stfs f31,28(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r18)
	ctx.r8.u64 = PPC_LOAD_U32(r18.u32 + 4);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lfs f0,108(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	f0.f64 = double(temp.f32);
	// stfs f0,44(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 44, temp.u32);
	// b 0x8255d48c
	goto loc_8255D48C;
loc_8255D41C:
	// li r11,0
	r11.s64 = 0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stb r11,530(r18)
	PPC_STORE_U8(r18.u32 + 530, r11.u8);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lbz r5,165(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 165);
	// clrlwi r4,r5,25
	ctx.r4.u64 = ctx.r5.u32 & 0x7F;
	// stb r4,165(r6)
	PPC_STORE_U8(ctx.r6.u32 + 165, ctx.r4.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255d48c
	if (cr6.eq) goto loc_8255D48C;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// lwz r3,160(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// bl 0x825a2e00
	ctx.lr = 0x8255D468;
	sub_825A2E00(ctx, base);
	// b 0x8255d48c
	goto loc_8255D48C;
loc_8255D46C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lbz r6,165(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 165);
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stb r5,165(r7)
	PPC_STORE_U8(ctx.r7.u32 + 165, ctx.r5.u8);
loc_8255D48C:
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x8255D4A4;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255d0d4
	if (cr6.eq) goto loc_8255D0D4;
loc_8255D4B0:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-192
	r0.s64 = -192;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8255D4D4"))) PPC_WEAK_FUNC(sub_8255D4D4);
PPC_FUNC_IMPL(__imp__sub_8255D4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D4D8"))) PPC_WEAK_FUNC(sub_8255D4D8);
PPC_FUNC_IMPL(__imp__sub_8255D4D8) {
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
	// bl 0x82558448
	ctx.lr = 0x8255D4F0;
	sub_82558448(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r9,-9880
	ctx.r6.s64 = ctx.r9.s64 + -9880;
	// lfs f0,32312(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32312);
	f0.f64 = double(temp.f32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// lfs f11,3732(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3732);
	ctx.f11.f64 = double(temp.f32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// lfs f13,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// lfs f12,31308(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31308);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// stfs f13,120(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stfs f12,116(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stw r11,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r11.u32);
	// stfs f11,124(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255D5B4"))) PPC_WEAK_FUNC(sub_8255D5B4);
PPC_FUNC_IMPL(__imp__sub_8255D5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D5B8"))) PPC_WEAK_FUNC(sub_8255D5B8);
PPC_FUNC_IMPL(__imp__sub_8255D5B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23536(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23536);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255D5C4"))) PPC_WEAK_FUNC(sub_8255D5C4);
PPC_FUNC_IMPL(__imp__sub_8255D5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D5C8"))) PPC_WEAK_FUNC(sub_8255D5C8);
PPC_FUNC_IMPL(__imp__sub_8255D5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// bl 0x823d91fc
	ctx.lr = 0x8255D5D0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r7,r1,156
	ctx.r7.s64 = ctx.r1.s64 + 156;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,64
	ctx.r9.s64 = 64;
	// lfs f0,112(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 112);
	f0.f64 = double(temp.f32);
	// addi r8,r1,156
	ctx.r8.s64 = ctx.r1.s64 + 156;
	// lfs f13,112(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r10,80
	ctx.r10.s64 = 80;
	// li r11,96
	r11.s64 = 96;
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,112(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lvx128 v0,r30,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r29,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v10,v60,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v9,v10,v13,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r8,132
	ctx.r8.s64 = 132;
	// stvx128 v9,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r30,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r29,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v8,v59,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v7,v8,v12,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v11,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stvx128 v7,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r30,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r29,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v6,v58,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v5,v6,v11,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v5,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,120(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,120(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,120(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// lfs f6,116(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,116(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,116(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lfs f2,124(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 124);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,124(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 124);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f2
	ctx.f13.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fmadds f12,f13,f31,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * f31.f64 + ctx.f2.f64));
	// stfs f12,124(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// lfs f11,128(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,128(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f8,f9,f31,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f11.f64));
	// stfs f8,128(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// lwz r7,132(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// lwz r4,132(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// extsw r11,r4
	r11.s64 = ctx.r4.s32;
	// subf r10,r4,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r4.s64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f7
	ctx.f4.f64 = double(ctx.f7.s64);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f3,f5
	ctx.f3.f64 = double(float(ctx.f5.f64));
	// fmadds f0,f3,f31,f2
	f0.f64 = double(float(ctx.f3.f64 * f31.f64 + ctx.f2.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfiwx f13,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.f13.u32);
	// bl 0x82558390
	ctx.lr = 0x8255D704;
	sub_82558390(ctx, base);
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r6,168(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 168);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,168(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255D724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,172(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r6,172(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 172);
	// lwz r5,172(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8255D744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,160(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// lwz r5,160(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// bl 0x82568128
	ctx.lr = 0x8255D758;
	sub_82568128(ctx, base);
	// lwz r6,164(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 164);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,164(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// lwz r3,164(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x82568128
	ctx.lr = 0x8255D76C;
	sub_82568128(ctx, base);
	// lwz r6,136(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x82567180
	ctx.lr = 0x8255D780;
	sub_82567180(ctx, base);
	// lwz r6,140(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,140(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// bl 0x82567180
	ctx.lr = 0x8255D794;
	sub_82567180(ctx, base);
	// lwz r6,152(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 152);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,152(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// bl 0x82569708
	ctx.lr = 0x8255D7A8;
	sub_82569708(ctx, base);
	// lwz r6,156(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 156);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,156(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x82569708
	ctx.lr = 0x8255D7BC;
	sub_82569708(ctx, base);
	// lwz r6,144(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,144(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// bl 0x825587f8
	ctx.lr = 0x8255D7D0;
	sub_825587F8(ctx, base);
	// lwz r6,148(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 148);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r5,148(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// bl 0x82561858
	ctx.lr = 0x8255D7E4;
	sub_82561858(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255D7F0"))) PPC_WEAK_FUNC(sub_8255D7F0);
PPC_FUNC_IMPL(__imp__sub_8255D7F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// bne cr6,0x8255d808
	if (!cr6.eq) goto loc_8255D808;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_8255D808:
	// li r9,32
	ctx.r9.s64 = 32;
	// lfs f12,64(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// li r8,16
	ctx.r8.s64 = 16;
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// addi r10,r3,64
	ctx.r10.s64 = ctx.r3.s64 + 64;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8255d848
	if (!cr6.eq) goto loc_8255D848;
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8255D848:
	// lfs f12,68(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x8255d858
	if (!cr6.eq) goto loc_8255D858;
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
loc_8255D858:
	// lfs f13,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8255d86c
	if (!cr6.eq) goto loc_8255D86C;
	// lfs f0,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	f0.f64 = double(temp.f32);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
loc_8255D86C:
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,80
	r11.s64 = ctx.r3.s64 + 80;
	// addi r8,r9,2384
	ctx.r8.s64 = ctx.r9.s64 + 2384;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v59,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v57,v58,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v57.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,-32
	ctx.r8.s64 = ctx.r1.s64 + -32;
	// lfs f0,-28872(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28872);
	f0.f64 = double(temp.f32);
	// stfs f0,-32(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v53,v56,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255D8C4"))) PPC_WEAK_FUNC(sub_8255D8C4);
PPC_FUNC_IMPL(__imp__sub_8255D8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D8C8"))) PPC_WEAK_FUNC(sub_8255D8C8);
PPC_FUNC_IMPL(__imp__sub_8255D8C8) {
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
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x8255D8DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255d8f8
	if (cr6.eq) goto loc_8255D8F8;
	// bl 0x8255d4d8
	ctx.lr = 0x8255D8E8;
	sub_8255D4D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255D8F8:
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

__attribute__((alias("__imp__sub_8255D90C"))) PPC_WEAK_FUNC(sub_8255D90C);
PPC_FUNC_IMPL(__imp__sub_8255D90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255D910"))) PPC_WEAK_FUNC(sub_8255D910);
PPC_FUNC_IMPL(__imp__sub_8255D910) {
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
	// bl 0x8255b700
	ctx.lr = 0x8255D930;
	sub_8255B700(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255d948
	if (cr6.eq) goto loc_8255D948;
	// bl 0x82130588
	ctx.lr = 0x8255D944;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8255D948:
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

__attribute__((alias("__imp__sub_8255D960"))) PPC_WEAK_FUNC(sub_8255D960);
PPC_FUNC_IMPL(__imp__sub_8255D960) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
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
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,7700
	ctx.r6.s64 = ctx.r10.s64 + 7700;
	// addi r5,r9,24380
	ctx.r5.s64 = ctx.r9.s64 + 24380;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x823dedd8
	ctx.lr = 0x8255D9A4;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255da34
	if (cr6.eq) goto loc_8255DA34;
	// lwz r11,392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x8255da34
	if (!cr6.gt) goto loc_8255DA34;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255da34
	if (!cr6.gt) goto loc_8255DA34;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,0
	ctx.r9.s64 = 0;
	// li r4,384
	ctx.r4.s64 = 384;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// li r7,48
	ctx.r7.s64 = 48;
	// vpermwi128 v63,v61,234
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v62,v61,186
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// vpermwi128 v61,v61,174
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
loc_8255D9F0:
	// lwz r11,392(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 392);
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r8,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lwzx r30,r30,r9
	r30.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lvx128 v60,r30,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x8255d9f0
	if (cr6.lt) goto loc_8255D9F0;
loc_8255DA34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8255bb80
	ctx.lr = 0x8255DA3C;
	sub_8255BB80(ctx, base);
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

__attribute__((alias("__imp__sub_8255DA54"))) PPC_WEAK_FUNC(sub_8255DA54);
PPC_FUNC_IMPL(__imp__sub_8255DA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255DA58"))) PPC_WEAK_FUNC(sub_8255DA58);
PPC_FUNC_IMPL(__imp__sub_8255DA58) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8255DA60;
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// addi r31,r1,-1072
	r31.s64 = ctx.r1.s64 + -1072;
	// stwu r1,-1072(r1)
	ea = -1072 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,544(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 544);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8255dad4
	if (!cr6.eq) goto loc_8255DAD4;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255e4e4
	if (!cr6.gt) goto loc_8255E4E4;
	// li r11,0
	r11.s64 = 0;
loc_8255DA94:
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// stb r4,288(r8)
	PPC_STORE_U8(ctx.r8.u32 + 288, ctx.r4.u8);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x8255da94
	if (cr6.lt) goto loc_8255DA94;
	// addi r1,r31,1072
	ctx.r1.s64 = r31.s64 + 1072;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_8255DAD4:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r26,-23452(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r26,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r26.u32);
	// beq cr6,0x8255e4e4
	if (cr6.eq) goto loc_8255E4E4;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255e4e4
	if (!cr6.gt) goto loc_8255E4E4;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// ble cr6,0x8255db28
	if (!cr6.gt) goto loc_8255DB28;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8255DB08:
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r24,96(r8)
	PPC_STORE_U32(ctx.r8.u32 + 96, r24.u32);
	// lwz r7,24(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8255db08
	if (cr6.lt) goto loc_8255DB08;
loc_8255DB28:
	// lwz r11,544(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 544);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8255e4dc
	if (!cr6.eq) goto loc_8255E4DC;
	// lwz r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x8255db7c
	if (!cr6.gt) goto loc_8255DB7C;
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r9,r31,256
	ctx.r9.s64 = r31.s64 + 256;
	// addi r7,r31,160
	ctx.r7.s64 = r31.s64 + 160;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
	// subf r7,r11,r7
	ctx.r7.s64 = ctx.r7.s64 - r11.s64;
loc_8255DB58:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r6,84(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r5,r9,96
	ctx.r5.s64 = ctx.r9.s64 + 96;
	// stwx r5,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r5.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8255db58
	if (!cr0.eq) goto loc_8255DB58;
loc_8255DB7C:
	// lwz r10,380(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// addi r11,r29,240
	r11.s64 = r29.s64 + 240;
	// li r30,16
	r30.s64 = 16;
	// lbz r7,384(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 384);
	// li r28,32
	r28.s64 = 32;
	// stb r7,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, ctx.r7.u8);
	// li r27,48
	r27.s64 = 48;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r6,496
	ctx.r6.s64 = 496;
	// lwz r25,376(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + 376);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r31,240
	ctx.r5.s64 = r31.s64 + 240;
	// addi r20,r10,2384
	r20.s64 = ctx.r10.s64 + 2384;
	// lvx128 v62,r11,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,528
	ctx.r3.s64 = 528;
	// lvx128 v60,r11,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v57,r29,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v63,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r19,r11,2352
	r19.s64 = r11.s64 + 2352;
	// vmrghw128 v56,v62,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v59,r0,r20
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v62,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vand128 v55,v57,v59
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmrglw128 v53,v63,v61
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r11,r31,192
	r11.s64 = r31.s64 + 192;
	// lwz r14,28(r9)
	r14.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// vmrglw128 v52,v58,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r23,r31,240
	r23.s64 = r31.s64 + 240;
	// lvx128 v59,r0,r19
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v50,v58,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vor128 v51,v59,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vmrghw128 v49,v53,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// addi r22,r31,208
	r22.s64 = r31.s64 + 208;
	// lvx128 v48,r29,r3
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r21,r31,224
	r21.s64 = r31.s64 + 224;
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r18,r31,144
	r18.s64 = r31.s64 + 144;
	// lfs f1,512(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 512);
	ctx.f1.f64 = double(temp.f32);
	// vmsum4fp128 v47,v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// li r16,-1
	r16.s64 = -1;
	// vmsum4fp128 v46,v51,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// vmsum4fp128 v45,v51,v49
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// addi r9,r31,160
	ctx.r9.s64 = r31.s64 + 160;
	// addi r8,r31,192
	ctx.r8.s64 = r31.s64 + 192;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// stvx128 v62,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r31,256
	ctx.r5.s64 = r31.s64 + 256;
	// stvx128 v61,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r16,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r16.u32);
	// stvx128 v48,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// vmrghw128 v44,v47,v51
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v46,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v42,v43,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v42,r0,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574840
	ctx.lr = 0x8255DC78;
	sub_82574840(ctx, base);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r23,r24
	r23.u64 = r24.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8255e480
	if (!cr6.gt) goto loc_8255E480;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r17,-24
	r17.s64 = -24;
	// li r18,8
	r18.s64 = 8;
	// lis r15,-32114
	r15.s64 = -2104623104;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f30,-31400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f30.f64 = double(temp.f32);
	// b 0x8255dcac
	goto loc_8255DCAC;
loc_8255DCA8:
	// lwz r26,112(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 112);
loc_8255DCAC:
	// lwz r11,388(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255e46c
	if (cr6.eq) goto loc_8255E46C;
	// lbzx r10,r11,r23
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r23.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255e46c
	if (cr6.eq) goto loc_8255E46C;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r21,0
	r21.s64 = 0;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8255DCE0;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// rlwinm r6,r10,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// neg r5,r6
	ctx.r5.s64 = -ctx.r6.s64;
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r5,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r22,r1,112
	r22.s64 = ctx.r1.s64 + 112;
	// bl 0x823dbff4
	ctx.lr = 0x8255DCFC;
	sub_823DBFF4(ctx, base);
	// lwz r4,28(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r3,0(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwzx r9,r24,r4
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + ctx.r4.u32);
	// stwux r3,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r1.u32 = ea;
	// addi r11,r9,16
	r11.s64 = ctx.r9.s64 + 16;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lbz r9,528(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 528);
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r11,r27
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8255dd48
	if (cr6.eq) goto loc_8255DD48;
	// rotlwi r11,r4,0
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// li r9,416
	ctx.r9.s64 = 416;
	// lwzx r8,r24,r11
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + r11.u32);
	// lvlx128 v41,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v41,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
loc_8255DD48:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255de14
	if (!cr6.gt) goto loc_8255DE14;
	// vmrghw128 v62,v61,v0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// li r11,0
	r11.s64 = 0;
	// vmrghw128 v63,v13,v60
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmrglw128 v40,v61,v0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrglw128 v39,v13,v60
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v13.u32)));
	// vmrglw128 v58,v63,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v57,v63,v62
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v61,v39,v40
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
loc_8255DD74:
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// rlwinm r9,r11,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v60,r0,r20
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v38,v63,v62
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// add r10,r9,r7
	ctx.r10.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lvx128 v59,r0,r19
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v37,v63,v62
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// lwzx r5,r24,r8
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + ctx.r8.u32);
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// lwz r8,84(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// lvx128 v36,r0,r9
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v35,v36,v60
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vor128 v34,v59,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// vmsum4fp128 v60,v34,v37
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v37.f32), 0xFF));
	// vmsum4fp128 v33,v34,v38
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// vmsum4fp128 v32,v34,v61
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmrghw128 v59,v33,v34
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v56,v60,v32
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v55,v56,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r20
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r9,r30
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v54,v60
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// lvx128 v60,r0,r19
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v52,v60,v53
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vmsum4fp128 v51,v52,v58
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// vmsum4fp128 v50,v52,v61
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// vmsum4fp128 v49,v52,v57
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v57.f32), 0xFF));
	// vmrghw128 v48,v51,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v47,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// stvx128 v46,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,388(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// lbzx r3,r23,r4
	ctx.r3.u64 = PPC_LOAD_U8(r23.u32 + ctx.r4.u32);
	// rotlwi r10,r3,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 1);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8255dd74
	if (cr6.lt) goto loc_8255DD74;
loc_8255DE14:
	// lwz r5,388(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// lfs f1,512(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 512);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,380(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 380);
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// lbz r8,384(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 384);
	// li r11,0
	r11.s64 = 0;
	// lwz r6,376(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 376);
	// lbzx r4,r23,r5
	ctx.r4.u64 = PPC_LOAD_U8(r23.u32 + ctx.r5.u32);
	// rotlwi r4,r4,1
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
loc_8255DE38:
	// addi r5,r31,640
	ctx.r5.s64 = r31.s64 + 640;
	// addi r3,r31,384
	ctx.r3.s64 = r31.s64 + 384;
	// stwx r7,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.r7.u32);
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// stwx r10,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// blt cr6,0x8255de38
	if (cr6.lt) goto loc_8255DE38;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// mr r10,r14
	ctx.r10.u64 = r14.u64;
	// stb r8,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, ctx.r8.u8);
	// addi r9,r31,384
	ctx.r9.s64 = r31.s64 + 384;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// addi r8,r31,192
	ctx.r8.s64 = r31.s64 + 192;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// stw r16,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r16.u32);
	// addi r5,r31,640
	ctx.r5.s64 = r31.s64 + 640;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82574840
	ctx.lr = 0x8255DE88;
	sub_82574840(ctx, base);
	// addi r7,r31,160
	ctx.r7.s64 = r31.s64 + 160;
	// lwz r10,388(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// addi r11,r31,320
	r11.s64 = r31.s64 + 320;
	// lwzx r9,r24,r7
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + ctx.r7.u32);
	// lbzx r8,r23,r10
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + ctx.r10.u32);
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lvx128 v62,r9,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lvx128 v63,r9,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,72(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// lvx128 v61,r9,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r4,76(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 76);
	// lfs f13,64(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lhz r3,78(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + 78);
	// lfs f9,68(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// lbz r26,80(r9)
	r26.u64 = PPC_LOAD_U8(ctx.r9.u32 + 80);
	// lhz r25,82(r9)
	r25.u64 = PPC_LOAD_U16(ctx.r9.u32 + 82);
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8255dfd8
	if (!cr6.gt) goto loc_8255DFD8;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8255DEDC:
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255dfbc
	if (cr6.eq) goto loc_8255DFBC;
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lfs f0,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	f0.f64 = double(temp.f32);
	// lwzx r9,r24,r9
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + ctx.r9.u32);
	// lwz r9,80(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f11
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f11.f64));
	// stfs f0,64(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lwzx r10,r24,r7
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + ctx.r7.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8255df54
	if (!cr6.eq) goto loc_8255DF54;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lvx128 v45,r11,r30
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r11,r28
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r11,r27
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8255df80
	goto loc_8255DF80;
loc_8255DF54:
	// lfs f12,64(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8255dfbc
	if (!cr6.lt) goto loc_8255DFBC;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lvx128 v42,r11,r30
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r11,r28
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r11,r27
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8255DF80:
	// lfs f0,64(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	f0.f64 = double(temp.f32);
	// mr r21,r11
	r21.u64 = r11.u64;
	// stfs f0,64(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 64, temp.u32);
	// lfs f12,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,68(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 68, temp.u32);
	// lwz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r9,72(r10)
	PPC_STORE_U32(ctx.r10.u32 + 72, ctx.r9.u32);
	// lhz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 76);
	// sth r9,76(r10)
	PPC_STORE_U16(ctx.r10.u32 + 76, ctx.r9.u16);
	// lhz r9,78(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 78);
	// sth r9,78(r10)
	PPC_STORE_U16(ctx.r10.u32 + 78, ctx.r9.u16);
	// lbz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 80);
	// stb r9,80(r10)
	PPC_STORE_U8(ctx.r10.u32 + 80, ctx.r9.u8);
	// lhz r11,82(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// sth r11,82(r10)
	PPC_STORE_U16(ctx.r10.u32 + 82, r11.u16);
loc_8255DFBC:
	// lwz r11,388(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// lbzx r9,r23,r11
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + r11.u32);
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// blt cr6,0x8255dedc
	if (cr6.lt) goto loc_8255DEDC;
loc_8255DFD8:
	// lwzx r11,r24,r7
	r11.u64 = PPC_LOAD_U32(r24.u32 + ctx.r7.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8255e46c
	if (cr6.eq) goto loc_8255E46C;
	// addi r10,r31,128
	ctx.r10.s64 = r31.s64 + 128;
	// lvx128 v39,r11,r28
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r24,r9
	r11.u64 = PPC_LOAD_U32(r24.u32 + ctx.r9.u32);
	// lfs f12,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lfs f11,132(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// beq cr6,0x8255e084
	if (cr6.eq) goto loc_8255E084;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8255e084
	if (cr6.eq) goto loc_8255E084;
	// lfs f8,328(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 328);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// lfs f6,324(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 324);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,320(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 320);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f6,f11,f7
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fmadds f2,f5,f10,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f3.f64));
	// fsubs f1,f31,f2
	ctx.f1.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fabs f8,f1
	ctx.f8.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr6,f8,f4
	cr6.compare(ctx.f8.f64, ctx.f4.f64);
	// ble cr6,0x8255e084
	if (!cr6.gt) goto loc_8255E084;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// stvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r5.u32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// sth r4,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r4.u16);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// sth r3,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r3.u16);
	// stb r26,80(r11)
	PPC_STORE_U8(r11.u32 + 80, r26.u8);
	// sth r25,82(r11)
	PPC_STORE_U16(r11.u32 + 82, r25.u16);
loc_8255E084:
	// lwz r10,388(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 388);
	// lbzx r9,r23,r10
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + ctx.r10.u32);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x8255e398
	if (cr6.lt) goto loc_8255E398;
	// rlwinm r9,r7,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r10,0,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// add r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r6,r10,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r5,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + r22.u64;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
loc_8255E0C4:
	// addi r9,r10,-40
	ctx.r9.s64 = ctx.r10.s64 + -40;
	// cmplw cr6,r9,r21
	cr6.compare<uint32_t>(ctx.r9.u32, r21.u32, xer);
	// beq cr6,0x8255e170
	if (cr6.eq) goto loc_8255E170;
	// lwz r8,-40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255e170
	if (cr6.eq) goto loc_8255E170;
	// lfs f13,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255e170
	if (!cr6.lt) goto loc_8255E170;
	// lfs f9,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// lfs f7,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f7,f11,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f3,f10,f6,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fabs f1,f2
	ctx.f1.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fcmpu cr6,f1,f5
	cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x8255e170
	if (!cr6.gt) goto loc_8255E170;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lvx128 v38,r10,r17
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r0,r9
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r10,r18
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lfs f9,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// stw r9,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r9.u32);
	// lhz r8,36(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 36);
	// sth r8,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r8.u16);
	// lhz r5,38(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 38);
	// sth r5,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r5.u16);
	// lbz r4,40(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// stb r4,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r4.u8);
	// lhz r3,42(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 42);
	// sth r3,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r3.u16);
loc_8255E170:
	// addi r9,r10,-136
	ctx.r9.s64 = ctx.r10.s64 + -136;
	// cmplw cr6,r9,r21
	cr6.compare<uint32_t>(ctx.r9.u32, r21.u32, xer);
	// beq cr6,0x8255e224
	if (cr6.eq) goto loc_8255E224;
	// lwz r8,-136(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -136);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255e224
	if (cr6.eq) goto loc_8255E224;
	// lfs f13,-72(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -72);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255e224
	if (!cr6.lt) goto loc_8255E224;
	// lfs f9,-96(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -96);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r10,-104
	ctx.r9.s64 = ctx.r10.s64 + -104;
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f7,-100(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-104(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -104);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f7,f11,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f3,f10,f6,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fabs f1,f2
	ctx.f1.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fcmpu cr6,f1,f5
	cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x8255e224
	if (!cr6.gt) goto loc_8255E224;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// li r8,-120
	ctx.r8.s64 = -120;
	// li r5,-88
	ctx.r5.s64 = -88;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lvx128 v35,r10,r8
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r9
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r10,r5
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-72(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -72);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lfs f9,-68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -68);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r4,-64(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -64);
	// stw r4,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r4.u32);
	// lhz r3,-60(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + -60);
	// sth r3,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r3.u16);
	// lhz r9,-58(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -58);
	// sth r9,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r9.u16);
	// lbz r8,-56(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -56);
	// stb r8,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r8.u8);
	// lhz r5,-54(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -54);
	// sth r5,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r5.u16);
loc_8255E224:
	// addi r9,r10,-232
	ctx.r9.s64 = ctx.r10.s64 + -232;
	// cmplw cr6,r9,r21
	cr6.compare<uint32_t>(ctx.r9.u32, r21.u32, xer);
	// beq cr6,0x8255e2d8
	if (cr6.eq) goto loc_8255E2D8;
	// lwz r8,-232(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -232);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255e2d8
	if (cr6.eq) goto loc_8255E2D8;
	// lfs f13,-168(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255e2d8
	if (!cr6.lt) goto loc_8255E2D8;
	// lfs f9,-192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -192);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r10,-200
	ctx.r9.s64 = ctx.r10.s64 + -200;
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f7,-196(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -196);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-200(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -200);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f7,f11,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f3,f10,f6,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fabs f1,f2
	ctx.f1.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fcmpu cr6,f1,f5
	cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x8255e2d8
	if (!cr6.gt) goto loc_8255E2D8;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// li r8,-216
	ctx.r8.s64 = -216;
	// li r5,-184
	ctx.r5.s64 = -184;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lvx128 v32,r10,r8
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-168(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -168);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lfs f9,-164(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -164);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r4,-160(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -160);
	// stw r4,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r4.u32);
	// lhz r3,-156(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + -156);
	// sth r3,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r3.u16);
	// lhz r9,-154(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -154);
	// sth r9,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r9.u16);
	// lbz r8,-152(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -152);
	// stb r8,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r8.u8);
	// lhz r5,-150(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -150);
	// sth r5,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r5.u16);
loc_8255E2D8:
	// addi r9,r10,-328
	ctx.r9.s64 = ctx.r10.s64 + -328;
	// cmplw cr6,r9,r21
	cr6.compare<uint32_t>(ctx.r9.u32, r21.u32, xer);
	// beq cr6,0x8255e38c
	if (cr6.eq) goto loc_8255E38C;
	// lwz r8,-328(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -328);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255e38c
	if (cr6.eq) goto loc_8255E38C;
	// lfs f13,-264(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -264);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255e38c
	if (!cr6.lt) goto loc_8255E38C;
	// lfs f9,-288(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -288);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r10,-296
	ctx.r9.s64 = ctx.r10.s64 + -296;
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f7,-292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -292);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-296(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -296);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f7,f11,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f3,f10,f6,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fabs f1,f2
	ctx.f1.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fcmpu cr6,f1,f5
	cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x8255e38c
	if (!cr6.gt) goto loc_8255E38C;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// li r8,-312
	ctx.r8.s64 = -312;
	// li r5,-280
	ctx.r5.s64 = -280;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r10,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-264(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -264);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lfs f9,-260(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -260);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r4,-256(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -256);
	// stw r4,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r4.u32);
	// lhz r3,-252(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + -252);
	// sth r3,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r3.u16);
	// lhz r9,-250(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -250);
	// sth r9,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r9.u16);
	// lbz r8,-248(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -248);
	// stb r8,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r8.u8);
	// lhz r5,-246(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + -246);
	// sth r5,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r5.u16);
loc_8255E38C:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r10,r10,-384
	ctx.r10.s64 = ctx.r10.s64 + -384;
	// bne 0x8255e0c4
	if (!cr0.eq) goto loc_8255E0C4;
loc_8255E398:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x8255e46c
	if (cr6.lt) goto loc_8255E46C;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r22
	ctx.r10.u64 = ctx.r10.u64 + r22.u64;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
loc_8255E3B4:
	// addi r9,r10,-40
	ctx.r9.s64 = ctx.r10.s64 + -40;
	// cmplw cr6,r9,r21
	cr6.compare<uint32_t>(ctx.r9.u32, r21.u32, xer);
	// beq cr6,0x8255e460
	if (cr6.eq) goto loc_8255E460;
	// lwz r8,-40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8255e460
	if (cr6.eq) goto loc_8255E460;
	// lfs f13,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8255e460
	if (!cr6.lt) goto loc_8255E460;
	// lfs f9,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r10,-8
	ctx.r9.s64 = ctx.r10.s64 + -8;
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// lfs f7,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-23476(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -23476);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f7,f11,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f3,f10,f6,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsubs f2,f31,f3
	ctx.f2.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fabs f1,f2
	ctx.f1.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fcmpu cr6,f1,f5
	cr6.compare(ctx.f1.f64, ctx.f5.f64);
	// ble cr6,0x8255e460
	if (!cr6.gt) goto loc_8255E460;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lvx128 v58,r10,r17
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r10,r18
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 64, temp.u32);
	// lfs f9,28(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,68(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// stw r9,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r9.u32);
	// lhz r8,36(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 36);
	// sth r8,76(r11)
	PPC_STORE_U16(r11.u32 + 76, ctx.r8.u16);
	// lhz r6,38(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 38);
	// sth r6,78(r11)
	PPC_STORE_U16(r11.u32 + 78, ctx.r6.u16);
	// lbz r5,40(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 40);
	// stb r5,80(r11)
	PPC_STORE_U8(r11.u32 + 80, ctx.r5.u8);
	// lhz r4,42(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 42);
	// sth r4,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r4.u16);
loc_8255E460:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,-96
	ctx.r10.s64 = ctx.r10.s64 + -96;
	// bge 0x8255e3b4
	if (!cr0.lt) goto loc_8255E3B4;
loc_8255E46C:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r24,r24,4
	r24.s64 = r24.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x8255dca8
	if (cr6.lt) goto loc_8255DCA8;
loc_8255E480:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255e4e4
	if (!cr6.gt) goto loc_8255E4E4;
	// li r11,0
	r11.s64 = 0;
loc_8255E494:
	// addi r9,r31,160
	ctx.r9.s64 = r31.s64 + 160;
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r7,r11,r9
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwzx r6,r11,r8
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r9,r3,1
	ctx.r9.u64 = ctx.r3.u64 ^ 1;
	// stb r9,288(r6)
	PPC_STORE_U8(ctx.r6.u32 + 288, ctx.r9.u8);
	// lwz r8,24(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255e494
	if (cr6.lt) goto loc_8255E494;
	// addi r1,r31,1072
	ctx.r1.s64 = r31.s64 + 1072;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_8255E4DC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8255cbb0
	ctx.lr = 0x8255E4E4;
	sub_8255CBB0(ctx, base);
loc_8255E4E4:
	// addi r1,r31,1072
	ctx.r1.s64 = r31.s64 + 1072;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8255E4F4"))) PPC_WEAK_FUNC(sub_8255E4F4);
PPC_FUNC_IMPL(__imp__sub_8255E4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255E4F8"))) PPC_WEAK_FUNC(sub_8255E4F8);
PPC_FUNC_IMPL(__imp__sub_8255E4F8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-9880
	ctx.r10.s64 = r11.s64 + -9880;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e538
	if (cr6.eq) goto loc_8255E538;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255E538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255E538:
	// lwz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e558
	if (cr6.eq) goto loc_8255E558;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255E558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255E558:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e568
	if (cr6.eq) goto loc_8255E568;
	// bl 0x82130588
	ctx.lr = 0x8255E568;
	sub_82130588(ctx, base);
loc_8255E568:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// bl 0x82130588
	ctx.lr = 0x8255E570;
	sub_82130588(ctx, base);
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// bl 0x82130588
	ctx.lr = 0x8255E578;
	sub_82130588(ctx, base);
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x82130588
	ctx.lr = 0x8255E580;
	sub_82130588(ctx, base);
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// bl 0x82130588
	ctx.lr = 0x8255E588;
	sub_82130588(ctx, base);
	// lwz r3,164(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// bl 0x82130588
	ctx.lr = 0x8255E590;
	sub_82130588(ctx, base);
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e5b0
	if (cr6.eq) goto loc_8255E5B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255E5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255E5B0:
	// lwz r3,172(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e5d0
	if (cr6.eq) goto loc_8255E5D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255E5D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255E5D0:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// bl 0x825640a0
	ctx.lr = 0x8255E5E0;
	sub_825640A0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255E5F4"))) PPC_WEAK_FUNC(sub_8255E5F4);
PPC_FUNC_IMPL(__imp__sub_8255E5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255E5F8"))) PPC_WEAK_FUNC(sub_8255E5F8);
PPC_FUNC_IMPL(__imp__sub_8255E5F8) {
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
	ctx.lr = 0x8255E600;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x825641a0
	ctx.lr = 0x8255E610;
	sub_825641A0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lbz r9,176(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// addi r10,r11,-9880
	ctx.r10.s64 = r11.s64 + -9880;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8255e7bc
	if (cr6.eq) goto loc_8255E7BC;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r29,r11,-28420
	r29.s64 = r11.s64 + -28420;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e65c
	if (cr6.eq) goto loc_8255E65C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E644;
	sub_8217D890(ctx, base);
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255e65c
	if (cr6.eq) goto loc_8255E65C;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
loc_8255E65C:
	// lwz r4,140(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e688
	if (cr6.eq) goto loc_8255E688;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E670;
	sub_8217D890(ctx, base);
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255e688
	if (cr6.eq) goto loc_8255E688;
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
loc_8255E688:
	// lwz r4,144(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e6a8
	if (cr6.eq) goto loc_8255E6A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E69C;
	sub_8217D890(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r10.u32);
loc_8255E6A8:
	// lwz r4,148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e6c8
	if (cr6.eq) goto loc_8255E6C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E6BC;
	sub_8217D890(ctx, base);
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r10.u32);
loc_8255E6C8:
	// lwz r4,152(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e6e8
	if (cr6.eq) goto loc_8255E6E8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E6DC;
	sub_8217D890(ctx, base);
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r10.u32);
loc_8255E6E8:
	// lwz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e708
	if (cr6.eq) goto loc_8255E708;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E6FC;
	sub_8217D890(ctx, base);
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r10.u32);
loc_8255E708:
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e728
	if (cr6.eq) goto loc_8255E728;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E71C;
	sub_8217D890(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r10.u32);
loc_8255E728:
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e748
	if (cr6.eq) goto loc_8255E748;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E73C;
	sub_8217D890(ctx, base);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r10.u32);
loc_8255E748:
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e77c
	if (cr6.eq) goto loc_8255E77C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E75C;
	sub_8217D890(ctx, base);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255e77c
	if (cr6.eq) goto loc_8255E77C;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,-13164
	ctx.r9.s64 = ctx.r10.s64 + -13164;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_8255E77C:
	// lwz r4,172(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8255e7bc
	if (cr6.eq) goto loc_8255E7BC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8255E790;
	sub_8217D890(ctx, base);
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255e7c0
	if (cr6.eq) goto loc_8255E7C0;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,-12780
	ctx.r9.s64 = ctx.r10.s64 + -12780;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8255E7BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8255E7C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255E7C8"))) PPC_WEAK_FUNC(sub_8255E7C8);
PPC_FUNC_IMPL(__imp__sub_8255E7C8) {
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
	ctx.lr = 0x8255E7D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23532
	r31.s64 = r11.s64 + -23532;
	// lwz r11,-23532(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23532);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255e910
	if (!cr6.eq) goto loc_8255E910;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255E7F0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e804
	if (cr6.eq) goto loc_8255E804;
	// bl 0x821d5408
	ctx.lr = 0x8255E800;
	sub_821D5408(ctx, base);
	// b 0x8255e808
	goto loc_8255E808;
loc_8255E804:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255E808:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9864
	ctx.r7.s64 = ctx.r10.s64 + -9864;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,80
	ctx.r5.s64 = 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-19256
	ctx.r4.s64 = ctx.r8.s64 + -19256;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r3,5284
	ctx.r4.s64 = ctx.r3.s64 + 5284;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r30,r10,5320
	r30.s64 = ctx.r10.s64 + 5320;
	// addi r29,r9,5356
	r29.s64 = ctx.r9.s64 + 5356;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r8,5392
	r11.s64 = ctx.r8.s64 + 5392;
	// addi r28,r5,5416
	r28.s64 = ctx.r5.s64 + 5416;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// li r6,68
	ctx.r6.s64 = 68;
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r6,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r6.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x8255E8BC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255E8CC;
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
	ctx.lr = 0x8255E8E8;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5440
	ctx.r4.s64 = ctx.r8.s64 + 5440;
	// bl 0x821d4b00
	ctx.lr = 0x8255E8F8;
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
	ctx.lr = 0x8255E910;
	sub_821C0548(ctx, base);
loc_8255E910:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255E918"))) PPC_WEAK_FUNC(sub_8255E918);
PPC_FUNC_IMPL(__imp__sub_8255E918) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23528
	r31.s64 = r11.s64 + -23528;
	// lwz r11,-23528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255ea38
	if (!cr6.eq) goto loc_8255EA38;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255E948;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255e95c
	if (cr6.eq) goto loc_8255E95C;
	// bl 0x821d5408
	ctx.lr = 0x8255E958;
	sub_821D5408(ctx, base);
	// b 0x8255e960
	goto loc_8255E960;
loc_8255E95C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255E960:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32170
	r11.s64 = -2108293120;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9852
	ctx.r7.s64 = ctx.r10.s64 + -9852;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19112
	ctx.r9.s64 = r11.s64 + -19112;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-19184
	ctx.r4.s64 = ctx.r8.s64 + -19184;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r8,r3,5464
	ctx.r8.s64 = ctx.r3.s64 + 5464;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r10,5488
	ctx.r7.s64 = ctx.r10.s64 + 5488;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8255E9E4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255E9F4;
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
	ctx.lr = 0x8255EA10;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5512
	ctx.r4.s64 = ctx.r8.s64 + 5512;
	// bl 0x821d4b00
	ctx.lr = 0x8255EA20;
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
	ctx.lr = 0x8255EA38;
	sub_821C0548(ctx, base);
loc_8255EA38:
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

__attribute__((alias("__imp__sub_8255EA50"))) PPC_WEAK_FUNC(sub_8255EA50);
PPC_FUNC_IMPL(__imp__sub_8255EA50) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23524
	r31.s64 = r11.s64 + -23524;
	// lwz r11,-23524(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255ec50
	if (!cr6.eq) goto loc_8255EC50;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255EA80;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255ea94
	if (cr6.eq) goto loc_8255EA94;
	// bl 0x821d5408
	ctx.lr = 0x8255EA90;
	sub_821D5408(ctx, base);
	// b 0x8255ea98
	goto loc_8255EA98;
loc_8255EA94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255EA98:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32170
	r11.s64 = -2108293120;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9840
	ctx.r7.s64 = ctx.r10.s64 + -9840;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19024
	ctx.r9.s64 = r11.s64 + -19024;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,144
	ctx.r5.s64 = 144;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-19096
	ctx.r4.s64 = ctx.r8.s64 + -19096;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,5524
	ctx.r9.s64 = ctx.r3.s64 + 5524;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,5548
	ctx.r8.s64 = ctx.r10.s64 + 5548;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,52
	ctx.r10.s64 = 52;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r6,r5,7564
	ctx.r6.s64 = ctx.r5.s64 + 7564;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,56
	ctx.r9.s64 = 56;
	// addi r5,r4,7612
	ctx.r5.s64 = ctx.r4.s64 + 7612;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,5620
	ctx.r4.s64 = ctx.r7.s64 + 5620;
	// addi r6,r8,5644
	ctx.r6.s64 = ctx.r8.s64 + 5644;
	// li r11,100
	r11.s64 = 100;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,5668
	ctx.r5.s64 = ctx.r7.s64 + 5668;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,5692
	ctx.r4.s64 = r30.s64 + 5692;
	// addi r6,r8,5716
	ctx.r6.s64 = ctx.r8.s64 + 5716;
	// li r11,12
	r11.s64 = 12;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,5740
	ctx.r5.s64 = ctx.r7.s64 + 5740;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,5764
	ctx.r4.s64 = r30.s64 + 5764;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,5788
	ctx.r6.s64 = ctx.r8.s64 + 5788;
	// li r11,24
	r11.s64 = 24;
	// li r10,28
	ctx.r10.s64 = 28;
	// addi r8,r7,5812
	ctx.r8.s64 = ctx.r7.s64 + 5812;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,5836
	ctx.r7.s64 = r30.s64 + 5836;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,40
	ctx.r9.s64 = 40;
	// li r11,44
	r11.s64 = 44;
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r9,r6,5860
	ctx.r9.s64 = ctx.r6.s64 + 5860;
	// addi r8,r11,5884
	ctx.r8.s64 = r11.s64 + 5884;
	// li r11,32
	r11.s64 = 32;
	// li r10,36
	ctx.r10.s64 = 36;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x8255EBFC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255EC0C;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8255EC28;
	sub_821D41D0(ctx, base);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,5912
	ctx.r4.s64 = ctx.r5.s64 + 5912;
	// bl 0x821d4b00
	ctx.lr = 0x8255EC38;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8255EC50;
	sub_821C0548(ctx, base);
loc_8255EC50:
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

__attribute__((alias("__imp__sub_8255EC68"))) PPC_WEAK_FUNC(sub_8255EC68);
PPC_FUNC_IMPL(__imp__sub_8255EC68) {
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
	ctx.lr = 0x8255EC70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23520
	r31.s64 = r11.s64 + -23520;
	// lwz r11,-23520(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23520);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255edd0
	if (!cr6.eq) goto loc_8255EDD0;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255EC90;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255eca4
	if (cr6.eq) goto loc_8255ECA4;
	// bl 0x821d5408
	ctx.lr = 0x8255ECA0;
	sub_821D5408(ctx, base);
	// b 0x8255eca8
	goto loc_8255ECA8;
loc_8255ECA4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255ECA8:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32170
	r11.s64 = -2108293120;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9824
	ctx.r7.s64 = ctx.r10.s64 + -9824;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-18936
	ctx.r9.s64 = r11.s64 + -18936;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-19008
	ctx.r4.s64 = ctx.r8.s64 + -19008;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r10,6004
	ctx.r4.s64 = ctx.r10.s64 + 6004;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// addi r5,r9,6028
	ctx.r5.s64 = ctx.r9.s64 + 6028;
	// addi r7,r3,5980
	ctx.r7.s64 = ctx.r3.s64 + 5980;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,8
	ctx.r8.s64 = 8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// addi r5,r11,6100
	ctx.r5.s64 = r11.s64 + 6100;
	// addi r7,r29,6052
	ctx.r7.s64 = r29.s64 + 6052;
	// addi r4,r28,6076
	ctx.r4.s64 = r28.s64 + 6076;
	// addi r6,r6,6124
	ctx.r6.s64 = ctx.r6.s64 + 6124;
	// li r11,12
	r11.s64 = 12;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// li r8,24
	ctx.r8.s64 = 24;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x8255ED7C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255ED8C;
	sub_821D4100(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8255EDA8;
	sub_821D41D0(ctx, base);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,6148
	ctx.r4.s64 = ctx.r10.s64 + 6148;
	// bl 0x821d4b00
	ctx.lr = 0x8255EDB8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x8255EDD0;
	sub_821C0548(ctx, base);
loc_8255EDD0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255EDD8"))) PPC_WEAK_FUNC(sub_8255EDD8);
PPC_FUNC_IMPL(__imp__sub_8255EDD8) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23516
	r31.s64 = r11.s64 + -23516;
	// lwz r11,-23516(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255ef08
	if (!cr6.eq) goto loc_8255EF08;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255EE08;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255ee1c
	if (cr6.eq) goto loc_8255EE1C;
	// bl 0x821d5408
	ctx.lr = 0x8255EE18;
	sub_821D5408(ctx, base);
	// b 0x8255ee20
	goto loc_8255EE20;
loc_8255EE1C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255EE20:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32182
	r11.s64 = -2109079552;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9804
	ctx.r7.s64 = ctx.r10.s64 + -9804;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-19144
	ctx.r9.s64 = r11.s64 + -19144;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-18920
	ctx.r4.s64 = ctx.r8.s64 + -18920;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,6180
	ctx.r7.s64 = ctx.r3.s64 + 6180;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// addi r4,r10,6204
	ctx.r4.s64 = ctx.r10.s64 + 6204;
	// addi r3,r9,6228
	ctx.r3.s64 = ctx.r9.s64 + 6228;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8255EEB4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255EEC4;
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
	ctx.lr = 0x8255EEE0;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,6252
	ctx.r4.s64 = ctx.r8.s64 + 6252;
	// bl 0x821d4b00
	ctx.lr = 0x8255EEF0;
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
	ctx.lr = 0x8255EF08;
	sub_821C0548(ctx, base);
loc_8255EF08:
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

__attribute__((alias("__imp__sub_8255EF20"))) PPC_WEAK_FUNC(sub_8255EF20);
PPC_FUNC_IMPL(__imp__sub_8255EF20) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23512
	r31.s64 = r11.s64 + -23512;
	// lwz r11,-23512(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23512);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f110
	if (!cr6.eq) goto loc_8255F110;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255EF50;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255ef64
	if (cr6.eq) goto loc_8255EF64;
	// bl 0x821d5408
	ctx.lr = 0x8255EF60;
	sub_821D5408(ctx, base);
	// b 0x8255ef68
	goto loc_8255EF68;
loc_8255EF64:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255EF68:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32170
	r11.s64 = -2108293120;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9788
	ctx.r7.s64 = ctx.r10.s64 + -9788;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-18776
	ctx.r9.s64 = r11.s64 + -18776;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-18848
	ctx.r4.s64 = ctx.r8.s64 + -18848;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,6292
	ctx.r8.s64 = ctx.r10.s64 + 6292;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,6268
	ctx.r9.s64 = ctx.r3.s64 + 6268;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// addi r6,r5,6316
	ctx.r6.s64 = ctx.r5.s64 + 6316;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r4,6340
	ctx.r5.s64 = ctx.r4.s64 + 6340;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r4,r7,6364
	ctx.r4.s64 = ctx.r7.s64 + 6364;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// li r11,12
	r11.s64 = 12;
	// li r10,36
	ctx.r10.s64 = 36;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,6388
	ctx.r6.s64 = ctx.r8.s64 + 6388;
	// addi r5,r7,6412
	ctx.r5.s64 = ctx.r7.s64 + 6412;
	// addi r4,r30,6436
	ctx.r4.s64 = r30.s64 + 6436;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r11,20
	r11.s64 = 20;
	// li r10,24
	ctx.r10.s64 = 24;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,6460
	ctx.r6.s64 = ctx.r8.s64 + 6460;
	// addi r5,r7,6484
	ctx.r5.s64 = ctx.r7.s64 + 6484;
	// addi r4,r30,6508
	ctx.r4.s64 = r30.s64 + 6508;
	// li r9,28
	ctx.r9.s64 = 28;
	// li r11,32
	r11.s64 = 32;
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r5,r7,6556
	ctx.r5.s64 = ctx.r7.s64 + 6556;
	// addi r4,r30,6580
	ctx.r4.s64 = r30.s64 + 6580;
	// addi r6,r8,6532
	ctx.r6.s64 = ctx.r8.s64 + 6532;
	// li r9,44
	ctx.r9.s64 = 44;
	// li r11,48
	r11.s64 = 48;
	// li r10,52
	ctx.r10.s64 = 52;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r8,r9,6604
	ctx.r8.s64 = ctx.r9.s64 + 6604;
	// li r11,56
	r11.s64 = 56;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x8255F0BC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255F0CC;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8255F0E8;
	sub_821D41D0(ctx, base);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,6632
	ctx.r4.s64 = ctx.r5.s64 + 6632;
	// bl 0x821d4b00
	ctx.lr = 0x8255F0F8;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8255F110;
	sub_821C0548(ctx, base);
loc_8255F110:
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

__attribute__((alias("__imp__sub_8255F128"))) PPC_WEAK_FUNC(sub_8255F128);
PPC_FUNC_IMPL(__imp__sub_8255F128) {
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
	ctx.lr = 0x8255F130;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23508
	r31.s64 = r11.s64 + -23508;
	// lwz r11,-23508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f400
	if (!cr6.eq) goto loc_8255F400;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255F150;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255f164
	if (cr6.eq) goto loc_8255F164;
	// bl 0x821d5408
	ctx.lr = 0x8255F160;
	sub_821D5408(ctx, base);
	// b 0x8255f168
	goto loc_8255F168;
loc_8255F164:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255F168:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9772
	ctx.r7.s64 = ctx.r10.s64 + -9772;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,124
	ctx.r5.s64 = 124;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-18760
	ctx.r4.s64 = ctx.r8.s64 + -18760;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,6696
	ctx.r9.s64 = ctx.r3.s64 + 6696;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,6720
	ctx.r8.s64 = ctx.r10.s64 + 6720;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,84
	r11.s64 = 84;
	// addi r6,r5,6744
	ctx.r6.s64 = ctx.r5.s64 + 6744;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,80
	ctx.r9.s64 = 80;
	// addi r5,r4,6768
	ctx.r5.s64 = ctx.r4.s64 + 6768;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,6792
	ctx.r4.s64 = ctx.r7.s64 + 6792;
	// addi r6,r8,6816
	ctx.r6.s64 = ctx.r8.s64 + 6816;
	// li r11,76
	r11.s64 = 76;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,88
	ctx.r10.s64 = 88;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,96
	ctx.r9.s64 = 96;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,6840
	ctx.r5.s64 = ctx.r7.s64 + 6840;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,6864
	ctx.r4.s64 = r30.s64 + 6864;
	// addi r6,r8,6888
	ctx.r6.s64 = ctx.r8.s64 + 6888;
	// li r11,100
	r11.s64 = 100;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,104
	ctx.r10.s64 = 104;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,108
	ctx.r9.s64 = 108;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,6912
	ctx.r5.s64 = ctx.r7.s64 + 6912;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,6936
	ctx.r4.s64 = r30.s64 + 6936;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,6960
	ctx.r6.s64 = ctx.r8.s64 + 6960;
	// li r11,92
	r11.s64 = 92;
	// li r10,112
	ctx.r10.s64 = 112;
	// addi r8,r7,6984
	ctx.r8.s64 = ctx.r7.s64 + 6984;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,7008
	ctx.r7.s64 = r30.s64 + 7008;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,116
	ctx.r9.s64 = 116;
	// li r11,120
	r11.s64 = 120;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// addi r9,r6,7032
	ctx.r9.s64 = ctx.r6.s64 + 7032;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r11,28
	r11.s64 = 28;
	// addi r6,r10,7056
	ctx.r6.s64 = ctx.r10.s64 + 7056;
	// addi r8,r8,7080
	ctx.r8.s64 = ctx.r8.s64 + 7080;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r7,r7,7104
	ctx.r7.s64 = ctx.r7.s64 + 7104;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r11,20
	r11.s64 = 20;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,7128
	ctx.r6.s64 = r30.s64 + 7128;
	// addi r8,r29,7152
	ctx.r8.s64 = r29.s64 + 7152;
	// addi r7,r28,7176
	ctx.r7.s64 = r28.s64 + 7176;
	// li r10,36
	ctx.r10.s64 = 36;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r11,40
	r11.s64 = 40;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,7200
	ctx.r6.s64 = r30.s64 + 7200;
	// addi r8,r29,7224
	ctx.r8.s64 = r29.s64 + 7224;
	// addi r7,r28,7248
	ctx.r7.s64 = r28.s64 + 7248;
	// li r10,68
	ctx.r10.s64 = 68;
	// li r9,56
	ctx.r9.s64 = 56;
	// li r11,44
	r11.s64 = 44;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,7272
	ctx.r6.s64 = r30.s64 + 7272;
	// addi r8,r29,7296
	ctx.r8.s64 = r29.s64 + 7296;
	// addi r7,r28,7320
	ctx.r7.s64 = r28.s64 + 7320;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,52
	ctx.r9.s64 = 52;
	// li r11,60
	r11.s64 = 60;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,7344
	ctx.r6.s64 = r30.s64 + 7344;
	// addi r8,r29,7368
	ctx.r8.s64 = r29.s64 + 7368;
	// addi r7,r28,7392
	ctx.r7.s64 = r28.s64 + 7392;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r11,8
	r11.s64 = 8;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x8255F3AC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255F3BC;
	sub_821D4100(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8255F3D8;
	sub_821D41D0(ctx, base);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r4,7416
	ctx.r4.s64 = ctx.r4.s64 + 7416;
	// bl 0x821d4b00
	ctx.lr = 0x8255F3E8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8255F400;
	sub_821C0548(ctx, base);
loc_8255F400:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8255F408"))) PPC_WEAK_FUNC(sub_8255F408);
PPC_FUNC_IMPL(__imp__sub_8255F408) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8255F410;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82558180
	ctx.lr = 0x8255F41C;
	sub_82558180(ctx, base);
	// lwz r7,368(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r11,48
	r11.s64 = 48;
	// li r10,112
	ctx.r10.s64 = 112;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,96
	ctx.r8.s64 = 96;
	// lvx128 v63,r7,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,132(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 132);
	// stw r6,372(r31)
	PPC_STORE_U32(r31.u32 + 372, ctx.r6.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,12(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8255F45C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255f478
	if (cr6.eq) goto loc_8255F478;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255F478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255F478:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255f494
	if (cr6.eq) goto loc_8255F494;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255F494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255F494:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255f4b0
	if (cr6.eq) goto loc_8255F4B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255F4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255F4B0:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255f4f0
	if (!cr6.gt) goto loc_8255F4F0;
	// li r30,0
	r30.s64 = 0;
loc_8255F4C4:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8255F4DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255f4c4
	if (cr6.lt) goto loc_8255F4C4;
loc_8255F4F0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255f530
	if (!cr6.gt) goto loc_8255F530;
	// li r30,0
	r30.s64 = 0;
loc_8255F504:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8255F51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255f504
	if (cr6.lt) goto loc_8255F504;
loc_8255F530:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255f570
	if (!cr6.gt) goto loc_8255F570;
	// li r30,0
	r30.s64 = 0;
loc_8255F544:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8255F55C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255f544
	if (cr6.lt) goto loc_8255F544;
loc_8255F570:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8255f5b0
	if (!cr6.gt) goto loc_8255F5B0;
	// li r30,0
	r30.s64 = 0;
loc_8255F584:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8255F59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x8255f584
	if (cr6.lt) goto loc_8255F584;
loc_8255F5B0:
	// li r11,160
	r11.s64 = 160;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r4,r31,176
	ctx.r4.s64 = r31.s64 + 176;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
	// stfs f0,548(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b9b28
	ctx.lr = 0x8255F5DC;
	sub_821B9B28(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8255F5F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r11,192
	r11.s64 = 192;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,208
	ctx.r10.s64 = 208;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v61,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v59,v63,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v50,r31,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v63,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v49,r31,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v61,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v55,v59,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vmrghw128 v53,v59,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v54,v58,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v52,v59,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v51,v59,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum3fp128 v48,v50,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v47,v49,v53
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v46,v50,v54
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v45,v49,v54
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v44,v50,v52
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v43,v49,v51
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmrghw128 v42,v48,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v41,v47,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v40,v44,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v39,v43,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v38,v42,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v37,v41,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stvx128 v38,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8255a1b0
	ctx.lr = 0x8255F698;
	sub_8255A1B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8255d960
	ctx.lr = 0x8255F6A0;
	sub_8255D960(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8255F6A8"))) PPC_WEAK_FUNC(sub_8255F6A8);
PPC_FUNC_IMPL(__imp__sub_8255F6A8) {
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
	// bl 0x8255e4f8
	ctx.lr = 0x8255F6C8;
	sub_8255E4F8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8255f6e0
	if (cr6.eq) goto loc_8255F6E0;
	// bl 0x82130588
	ctx.lr = 0x8255F6DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8255F6E0:
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

__attribute__((alias("__imp__sub_8255F6F8"))) PPC_WEAK_FUNC(sub_8255F6F8);
PPC_FUNC_IMPL(__imp__sub_8255F6F8) {
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
	ctx.lr = 0x8255F700;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23536
	r31.s64 = r11.s64 + -23536;
	// lwz r11,-23536(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23536);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255fa78
	if (!cr6.eq) goto loc_8255FA78;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8255F720;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255f734
	if (cr6.eq) goto loc_8255F734;
	// bl 0x821d5408
	ctx.lr = 0x8255F730;
	sub_821D5408(ctx, base);
	// b 0x8255f738
	goto loc_8255F738;
loc_8255F734:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8255F738:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9756
	ctx.r7.s64 = ctx.r10.s64 + -9756;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,192
	ctx.r5.s64 = 192;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-10040
	ctx.r4.s64 = ctx.r8.s64 + -10040;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r8,r3,4540
	ctx.r8.s64 = ctx.r3.s64 + 4540;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r5,r9,4564
	ctx.r5.s64 = ctx.r9.s64 + 4564;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// addi r30,r10,4840
	r30.s64 = ctx.r10.s64 + 4840;
	// addi r6,r4,4600
	ctx.r6.s64 = ctx.r4.s64 + 4600;
	// addi r4,r3,4636
	ctx.r4.s64 = ctx.r3.s64 + 4636;
	// li r10,112
	ctx.r10.s64 = 112;
	// addi r3,r7,4672
	ctx.r3.s64 = ctx.r7.s64 + 4672;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r8,80
	ctx.r8.s64 = 80;
	// li r10,32
	ctx.r10.s64 = 32;
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// stw r8,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r8.u32);
	// addi r7,r7,4744
	ctx.r7.s64 = ctx.r7.s64 + 4744;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r11,r11,4708
	r11.s64 = r11.s64 + 4708;
	// addi r6,r5,4768
	ctx.r6.s64 = ctx.r5.s64 + 4768;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// li r10,132
	ctx.r10.s64 = 132;
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,96
	ctx.r8.s64 = 96;
	// li r9,120
	ctx.r9.s64 = 120;
	// lis r29,-32114
	r29.s64 = -2104623104;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// addi r3,r5,4792
	ctx.r3.s64 = ctx.r5.s64 + 4792;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r7,r4,4816
	ctx.r7.s64 = ctx.r4.s64 + 4816;
	// li r8,116
	ctx.r8.s64 = 116;
	// li r10,124
	ctx.r10.s64 = 124;
	// li r9,136
	ctx.r9.s64 = 136;
	// lwz r11,-23508(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23508);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8255f854
	if (!cr6.eq) goto loc_8255F854;
	// bl 0x8255f128
	ctx.lr = 0x8255F850;
	sub_8255F128(ctx, base);
	// lwz r11,-23508(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23508);
loc_8255F854:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,4876
	r28.s64 = ctx.r10.s64 + 4876;
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8255f878
	if (!cr6.eq) goto loc_8255F878;
	// bl 0x8255f128
	ctx.lr = 0x8255F874;
	sub_8255F128(ctx, base);
	// lwz r11,-23508(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23508);
loc_8255F878:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// addi r29,r10,4912
	r29.s64 = ctx.r10.s64 + 4912;
	// li r10,144
	ctx.r10.s64 = 144;
	// lwz r11,-23524(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23524);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f8a4
	if (!cr6.eq) goto loc_8255F8A4;
	// bl 0x8255ea50
	ctx.lr = 0x8255F8A0;
	sub_8255EA50(ctx, base);
	// lwz r11,-23524(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23524);
loc_8255F8A4:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lis r28,-32114
	r28.s64 = -2104623104;
	// addi r30,r10,4948
	r30.s64 = ctx.r10.s64 + 4948;
	// li r10,148
	ctx.r10.s64 = 148;
	// lwz r11,-23512(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -23512);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f8d0
	if (!cr6.eq) goto loc_8255F8D0;
	// bl 0x8255ef20
	ctx.lr = 0x8255F8CC;
	sub_8255EF20(ctx, base);
	// lwz r11,-23512(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -23512);
loc_8255F8D0:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r27,-32114
	r27.s64 = -2104623104;
	// addi r29,r10,4984
	r29.s64 = ctx.r10.s64 + 4984;
	// li r10,152
	ctx.r10.s64 = 152;
	// lwz r11,-23520(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -23520);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f8fc
	if (!cr6.eq) goto loc_8255F8FC;
	// bl 0x8255ec68
	ctx.lr = 0x8255F8F8;
	sub_8255EC68(ctx, base);
	// lwz r11,-23520(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -23520);
loc_8255F8FC:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,5020
	r28.s64 = ctx.r10.s64 + 5020;
	// li r10,156
	ctx.r10.s64 = 156;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8255f920
	if (!cr6.eq) goto loc_8255F920;
	// bl 0x8255ec68
	ctx.lr = 0x8255F91C;
	sub_8255EC68(ctx, base);
	// lwz r11,-23520(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -23520);
loc_8255F920:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// lis r29,-32114
	r29.s64 = -2104623104;
	// addi r30,r10,5056
	r30.s64 = ctx.r10.s64 + 5056;
	// li r10,160
	ctx.r10.s64 = 160;
	// lwz r11,-23528(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23528);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f94c
	if (!cr6.eq) goto loc_8255F94C;
	// bl 0x8255e918
	ctx.lr = 0x8255F948;
	sub_8255E918(ctx, base);
	// lwz r11,-23528(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23528);
loc_8255F94C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,5092
	r28.s64 = ctx.r10.s64 + 5092;
	// li r10,164
	ctx.r10.s64 = 164;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8255f970
	if (!cr6.eq) goto loc_8255F970;
	// bl 0x8255e918
	ctx.lr = 0x8255F96C;
	sub_8255E918(ctx, base);
	// lwz r11,-23528(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23528);
loc_8255F970:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// lis r29,-32114
	r29.s64 = -2104623104;
	// addi r30,r10,5128
	r30.s64 = ctx.r10.s64 + 5128;
	// li r10,168
	ctx.r10.s64 = 168;
	// lwz r11,-23532(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23532);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f99c
	if (!cr6.eq) goto loc_8255F99C;
	// bl 0x8255e7c8
	ctx.lr = 0x8255F998;
	sub_8255E7C8(ctx, base);
	// lwz r11,-23532(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -23532);
loc_8255F99C:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r28,-32114
	r28.s64 = -2104623104;
	// addi r29,r10,5164
	r29.s64 = ctx.r10.s64 + 5164;
	// li r10,172
	ctx.r10.s64 = 172;
	// lwz r11,-23516(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -23516);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8255f9c8
	if (!cr6.eq) goto loc_8255F9C8;
	// bl 0x8255edd8
	ctx.lr = 0x8255F9C4;
	sub_8255EDD8(ctx, base);
	// lwz r11,-23516(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -23516);
loc_8255F9C8:
	// lis r30,-32114
	r30.s64 = -2104623104;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8255f9e4
	if (!cr6.eq) goto loc_8255F9E4;
	// bl 0x82564488
	ctx.lr = 0x8255F9E0;
	sub_82564488(ctx, base);
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
loc_8255F9E4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8255F9F0;
	sub_821D4458(ctx, base);
	// lwz r11,-23488(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r30,52
	ctx.r10.s64 = r30.s64 + 52;
	// rlwinm r29,r11,16,22,31
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x82130528
	ctx.lr = 0x8255FA0C;
	sub_82130528(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r3.u32);
	// sth r11,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r11.u16);
	// stb r11,60(r30)
	PPC_STORE_U8(r30.u32 + 60, r11.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82196758
	ctx.lr = 0x8255FA24;
	sub_82196758(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8255FA34;
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
	ctx.lr = 0x8255FA50;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,5200
	ctx.r4.s64 = ctx.r8.s64 + 5200;
	// bl 0x821d4b00
	ctx.lr = 0x8255FA60;
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
	ctx.lr = 0x8255FA78;
	sub_821C0548(ctx, base);
loc_8255FA78:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8255FA80"))) PPC_WEAK_FUNC(sub_8255FA80);
PPC_FUNC_IMPL(__imp__sub_8255FA80) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82560be8
	ctx.lr = 0x8255FAA4;
	sub_82560BE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// sth r30,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r30.u16);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-9404
	ctx.r8.s64 = ctx.r9.s64 + -9404;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r11.u8);
	// stb r11,57(r31)
	PPC_STORE_U8(r31.u32 + 57, r11.u8);
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

__attribute__((alias("__imp__sub_8255FAF8"))) PPC_WEAK_FUNC(sub_8255FAF8);
PPC_FUNC_IMPL(__imp__sub_8255FAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-9404
	ctx.r10.s64 = r11.s64 + -9404;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82560ba0
	sub_82560BA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8255FB08"))) PPC_WEAK_FUNC(sub_8255FB08);
PPC_FUNC_IMPL(__imp__sub_8255FB08) {
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
	// bl 0x82560bb0
	ctx.lr = 0x8255FB20;
	sub_82560BB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// sth r9,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r9.u16);
	// lfs f0,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255FB50"))) PPC_WEAK_FUNC(sub_8255FB50);
PPC_FUNC_IMPL(__imp__sub_8255FB50) {
	PPC_FUNC_PROLOGUE();
	// stw r4,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r4.u32);
	// stw r5,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255FB5C"))) PPC_WEAK_FUNC(sub_8255FB5C);
PPC_FUNC_IMPL(__imp__sub_8255FB5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FB60"))) PPC_WEAK_FUNC(sub_8255FB60);
PPC_FUNC_IMPL(__imp__sub_8255FB60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r21{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r8,1
	ctx.r8.s64 = 1;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// beq cr6,0x8255fb88
	if (cr6.eq) goto loc_8255FB88;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
loc_8255FB88:
	// fabs f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,18612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x8255fba0
	if (!cr6.lt) goto loc_8255FBA0;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_8255FBA0:
	// lwz r7,52(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f11,21600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 21600);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,224(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 224);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// bge cr6,0x8255fbc8
	if (!cr6.lt) goto loc_8255FBC8;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x8255fbc8
	if (!cr6.eq) goto loc_8255FBC8;
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
loc_8255FBC8:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r10,2
	ctx.r10.s64 = 2;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8255fbfc
	if (!cr6.eq) goto loc_8255FBFC;
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8255fbec
	if (!cr6.lt) goto loc_8255FBEC;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// b 0x8255fbfc
	goto loc_8255FBFC;
loc_8255FBEC:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8255fbfc
	if (!cr6.gt) goto loc_8255FBFC;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
loc_8255FBFC:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8255fd48
	if (cr6.gt) {
		// ERROR 8255FD48
		return;
	}
	// lis r12,-32170
	r12.s64 = -2108293120;
	// addi r12,r12,-988
	r12.s64 = r12.s64 + -988;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8255FC34;
	case 1:
		goto loc_8255FC60;
	case 2:
		goto loc_8255FC8C;
	case 3:
		goto loc_8255FCEC;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-972(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -972);
	// lwz r18,-928(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -928);
	// lwz r18,-884(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -884);
	// lwz r18,-788(r21)
	r18.u64 = PPC_LOAD_U32(r21.u32 + -788);
loc_8255FC34:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8255fc54
	if (!cr6.lt) goto loc_8255FC54;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fneg f13,f1
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// lfs f12,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FC54:
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FC60:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8255fc78
	if (!cr6.gt) goto loc_8255FC78;
	// li r11,4
	r11.s64 = 4;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// b 0x8255fd44
	// ERROR 8255FD44
	return;
loc_8255FC78:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8255fd48
	if (!cr6.lt) {
		// ERROR 8255FD48
		return;
	}
	// fneg f12,f1
	ctx.f12.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FC8C:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8255fca4
	if (!cr6.gt) goto loc_8255FCA4;
	// fmr f12,f1
	ctx.f12.f64 = ctx.f1.f64;
	// stw r8,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r8.u32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FCA4:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x8255fcbc
	if (!cr6.eq) goto loc_8255FCBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f12,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FCBC:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lfs f13,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// bge cr6,0x8255fcdc
	if (!cr6.lt) goto loc_8255FCDC;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// stw r9,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r9.u32);
	// fneg f12,f1
	ctx.f12.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FCDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fneg f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lfs f12,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8255fd48
	// ERROR 8255FD48
	return;
loc_8255FCEC:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
}

__attribute__((alias("__imp__sub_8255FD64"))) PPC_WEAK_FUNC(sub_8255FD64);
PPC_FUNC_IMPL(__imp__sub_8255FD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FD68"))) PPC_WEAK_FUNC(sub_8255FD68);
PPC_FUNC_IMPL(__imp__sub_8255FD68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8255fda4
	if (cr6.lt) goto loc_8255FDA4;
	// beq cr6,0x8255fd94
	if (cr6.eq) goto loc_8255FD94;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8255FD94:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8255FDA4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8255FDB4"))) PPC_WEAK_FUNC(sub_8255FDB4);
PPC_FUNC_IMPL(__imp__sub_8255FDB4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255FDB8"))) PPC_WEAK_FUNC(sub_8255FDB8);
PPC_FUNC_IMPL(__imp__sub_8255FDB8) {
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
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255FDDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x8255fdfc
	if (cr6.eq) goto loc_8255FDFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8255FDFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8255FDFC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255FE10"))) PPC_WEAK_FUNC(sub_8255FE10);
PPC_FUNC_IMPL(__imp__sub_8255FE10) {
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
	// bl 0x825640f8
	ctx.lr = 0x8255FE28;
	sub_825640F8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-9348
	ctx.r6.s64 = ctx.r7.s64 + -9348;
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24920(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24920);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f11,36(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8255FE7C"))) PPC_WEAK_FUNC(sub_8255FE7C);
PPC_FUNC_IMPL(__imp__sub_8255FE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FE80"))) PPC_WEAK_FUNC(sub_8255FE80);
PPC_FUNC_IMPL(__imp__sub_8255FE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23504(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23504);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8255FE8C"))) PPC_WEAK_FUNC(sub_8255FE8C);
PPC_FUNC_IMPL(__imp__sub_8255FE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FE90"))) PPC_WEAK_FUNC(sub_8255FE90);
PPC_FUNC_IMPL(__imp__sub_8255FE90) {
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
	// bl 0x825641a0
	ctx.lr = 0x8255FEA8;
	sub_825641A0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-9348
	ctx.r10.s64 = r11.s64 + -9348;
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

__attribute__((alias("__imp__sub_8255FECC"))) PPC_WEAK_FUNC(sub_8255FECC);
PPC_FUNC_IMPL(__imp__sub_8255FECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FED0"))) PPC_WEAK_FUNC(sub_8255FED0);
PPC_FUNC_IMPL(__imp__sub_8255FED0) {
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
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x8255FEE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8255ff00
	if (cr6.eq) goto loc_8255FF00;
	// bl 0x8255fe10
	ctx.lr = 0x8255FEF0;
	sub_8255FE10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8255FF00:
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

__attribute__((alias("__imp__sub_8255FF14"))) PPC_WEAK_FUNC(sub_8255FF14);
PPC_FUNC_IMPL(__imp__sub_8255FF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FF18"))) PPC_WEAK_FUNC(sub_8255FF18);
PPC_FUNC_IMPL(__imp__sub_8255FF18) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-9404
	ctx.r10.s64 = r11.s64 + -9404;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82560ba0
	ctx.lr = 0x8255FF44;
	sub_82560BA0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8255ff5c
	if (cr6.eq) goto loc_8255FF5C;
	// bl 0x82130588
	ctx.lr = 0x8255FF58;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8255FF5C:
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

__attribute__((alias("__imp__sub_8255FF74"))) PPC_WEAK_FUNC(sub_8255FF74);
PPC_FUNC_IMPL(__imp__sub_8255FF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8255FF78"))) PPC_WEAK_FUNC(sub_8255FF78);
PPC_FUNC_IMPL(__imp__sub_8255FF78) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
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
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x8255ffdc
	if (cr6.eq) goto loc_8255FFDC;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8255ffd4
	if (!cr6.lt) goto loc_8255FFD4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f0,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f30,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f30.f64 = double(temp.f32);
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / f0.f64));
	// bl 0x82227c18
	ctx.lr = 0x8255FFC8;
	sub_82227C18(ctx, base);
	// fsubs f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f31.f64));
	// fmadds f1,f1,f13,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + f31.f64));
	// b 0x8255ffe0
	goto loc_8255FFE0;
loc_8255FFD4:
	// lfs f1,28(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8255ffe0
	goto loc_8255FFE0;
loc_8255FFDC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_8255FFE0:
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

__attribute__((alias("__imp__sub_8255FFF8"))) PPC_WEAK_FUNC(sub_8255FFF8);
PPC_FUNC_IMPL(__imp__sub_8255FFF8) {
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
	ctx.lr = 0x82560000;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,21788(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21788);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// clrlwi r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8256003c
	if (cr6.eq) goto loc_8256003C;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82560040
	goto loc_82560040;
loc_8256003C:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_82560040:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// addi r28,r11,29952
	r28.s64 = r11.s64 + 29952;
	// ble cr6,0x8256008c
	if (!cr6.gt) goto loc_8256008C;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lfs f0,136(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x8256008c
	if (cr6.gt) goto loc_8256008C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,60(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82560084
	if (!cr6.lt) goto loc_82560084;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x825586e8
	ctx.lr = 0x82560084;
	sub_825586E8(ctx, base);
loc_82560084:
	// stfs f30,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
	// b 0x8256009c
	goto loc_8256009C;
loc_8256008C:
	// lfs f0,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,60(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,60(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 60, temp.u32);
loc_8256009C:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// stfs f0,136(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// lwz r11,21788(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21788);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825600c0
	if (cr6.eq) goto loc_825600C0;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x825600c4
	goto loc_825600C4;
loc_825600C0:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_825600C4:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f0,140(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r11,21772(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21772);
	// extsw r6,r11
	ctx.r6.s64 = r11.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f0,2756(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2756);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fsel f9,f10,f10,f30
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f30.f64;
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fsel f7,f8,f31,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// fmsubs f1,f7,f13,f31
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 - f31.f64));
	// bl 0x8260c5c8
	ctx.lr = 0x8256011C;
	sub_8260C5C8(ctx, base);
	// fabs f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r31,r10,21816
	r31.s64 = ctx.r10.s64 + 21816;
	// addi r4,r31,57
	ctx.r4.s64 = r31.s64 + 57;
	// fmuls f5,f6,f1
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// stfs f5,24(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r30.u32 + 24, temp.u32);
	// lfs f4,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	ctx.f4.f64 = double(temp.f32);
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,7856(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7856);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f3,f0,f13
	ctx.f3.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fsubs f2,f3,f31
	ctx.f2.f64 = double(float(ctx.f3.f64 - f31.f64));
	// fsubs f1,f5,f4
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fsel f0,f2,f31,f3
	f0.f64 = ctx.f2.f64 >= 0.0 ? f31.f64 : ctx.f3.f64;
	// fmadds f13,f0,f1,f4
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f4.f64));
	// stfs f13,132(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// lwz r11,22584(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22584);
	// rlwinm r3,r11,8,0,23
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r11,r3,r4
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82560180
	if (cr6.eq) goto loc_82560180;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82560184
	goto loc_82560184;
loc_82560180:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_82560184:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// stfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
	// addi r10,r31,19
	ctx.r10.s64 = r31.s64 + 19;
	// stfs f0,144(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// lwz r8,22584(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 22584);
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r9,19(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 19);
	// lbz r7,275(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 275);
	// xor r5,r7,r9
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// lbzx r4,r6,r10
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r10.u32);
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825601d8
	if (cr6.eq) goto loc_825601D8;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x825601d4
	if (!cr6.eq) goto loc_825601D4;
	// li r4,2
	ctx.r4.s64 = 2;
loc_825601D4:
	// bl 0x825617e8
	ctx.lr = 0x825601D8;
	sub_825617E8(ctx, base);
loc_825601D8:
	// lwz r9,22584(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 22584);
	// addi r8,r31,32
	ctx.r8.s64 = r31.s64 + 32;
	// lbz r6,288(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 288);
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r5,32(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// xor r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// lbzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// and r11,r4,r3
	r11.u64 = ctx.r4.u64 & ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82560214
	if (cr6.eq) goto loc_82560214;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// subfic r8,r9,1
	xer.ca = ctx.r9.u32 <= 1;
	ctx.r8.s64 = 1 - ctx.r9.s64;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
loc_82560214:
	// lwz r11,22584(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22584);
	// addi r8,r31,30
	ctx.r8.s64 = r31.s64 + 30;
	// lbz r7,286(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 286);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r6,30(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 30);
	// xor r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// lbzx r4,r11,r8
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// and r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82560248
	if (cr6.eq) goto loc_82560248;
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// bl 0x8255ae18
	ctx.lr = 0x82560244;
	sub_8255AE18(ctx, base);
	// b 0x82560270
	goto loc_82560270;
loc_82560248:
	// addi r8,r31,44
	ctx.r8.s64 = r31.s64 + 44;
	// lbz r7,300(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// lbz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 44);
	// xor r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// lbzx r5,r11,r8
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// and r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 & ctx.r5.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82560274
	if (cr6.eq) goto loc_82560274;
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// bl 0x8255ae20
	ctx.lr = 0x82560270;
	sub_8255AE20(ctx, base);
loc_82560270:
	// sth r3,44(r30)
	PPC_STORE_U16(r30.u32 + 44, ctx.r3.u16);
loc_82560274:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// addi r10,r31,31
	ctx.r10.s64 = r31.s64 + 31;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// sth r8,44(r30)
	PPC_STORE_U16(r30.u32 + 44, ctx.r8.u16);
	// lwz r11,22584(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 22584);
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825602a8
	if (cr6.eq) goto loc_825602A8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// b 0x825602ac
	goto loc_825602AC;
loc_825602A8:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_825602AC:
	// addi r10,r31,45
	ctx.r10.s64 = r31.s64 + 45;
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825602d4
	if (cr6.eq) goto loc_825602D4;
	// fadds f0,f31,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 + f0.f64));
	// stfs f0,32(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 32, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_825602D4:
	// fadds f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 + f0.f64));
	// stfs f0,32(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 32, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825602EC"))) PPC_WEAK_FUNC(sub_825602EC);
PPC_FUNC_IMPL(__imp__sub_825602EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825602F0"))) PPC_WEAK_FUNC(sub_825602F0);
PPC_FUNC_IMPL(__imp__sub_825602F0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x825602F8;
	// stfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f29.u64);
	// stfd f30,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,56(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 56);
	// lfs f29,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f29.f64 = double(temp.f32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r31,r11,21816
	r31.s64 = r11.s64 + 21816;
	// addi r30,r10,22584
	r30.s64 = ctx.r10.s64 + 22584;
	// beq cr6,0x8256039c
	if (cr6.eq) goto loc_8256039C;
	// lwz r9,22584(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22584);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r31,200
	ctx.r7.s64 = r31.s64 + 200;
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r10,r11,3796
	ctx.r10.s64 = r11.s64 + 3796;
	// addi r11,r8,7444
	r11.s64 = ctx.r8.s64 + 7444;
	// lbzx r6,r9,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r7.u32);
	// lfs f31,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f30,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8256036c
	if (cr6.eq) goto loc_8256036C;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8255fb60
	ctx.lr = 0x82560368;
	sub_8255FB60(ctx, base);
	// b 0x82560460
	goto loc_82560460;
loc_8256036C:
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8256038c
	if (cr6.eq) goto loc_8256038C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8255fb60
	ctx.lr = 0x82560388;
	sub_8255FB60(ctx, base);
	// b 0x82560460
	goto loc_82560460;
loc_8256038C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8255fb60
	ctx.lr = 0x82560398;
	sub_8255FB60(ctx, base);
	// b 0x82560460
	goto loc_82560460;
loc_8256039C:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r31,200
	ctx.r8.s64 = r31.s64 + 200;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r7,r9,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,7444
	r11.s64 = r11.s64 + 7444;
	// addi r10,r10,3796
	ctx.r10.s64 = ctx.r10.s64 + 3796;
	// lbzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// lfs f30,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825603d4
	if (cr6.eq) goto loc_825603D4;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x825603d8
	goto loc_825603D8;
loc_825603D4:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_825603D8:
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// stfs f0,12(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 12, temp.u32);
	// addi r10,r31,208
	ctx.r10.s64 = r31.s64 + 208;
	// stfs f0,136(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82560404
	if (cr6.eq) goto loc_82560404;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82560408
	goto loc_82560408;
loc_82560404:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_82560408:
	// stfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 16, temp.u32);
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// addi r10,r31,19
	ctx.r10.s64 = r31.s64 + 19;
	// stfs f0,140(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lbz r6,275(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 275);
	// lbz r5,19(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 19);
	// xor r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r8,r9,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// and r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 & ctx.r7.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82560460
	if (cr6.eq) goto loc_82560460;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82560458
	if (!cr6.eq) goto loc_82560458;
	// li r4,2
	ctx.r4.s64 = 2;
loc_82560458:
	// bl 0x825617e8
	ctx.lr = 0x8256045C;
	sub_825617E8(ctx, base);
	// sth r3,44(r29)
	PPC_STORE_U16(r29.u32 + 44, ctx.r3.u16);
loc_82560460:
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r31,200
	ctx.r7.s64 = r31.s64 + 200;
	// lbz r5,456(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 456);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r4,200(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 200);
	// lfs f13,60(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// addi r28,r9,29952
	r28.s64 = ctx.r9.s64 + 29952;
	// xor r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r4.u64;
	// lbzx r11,r6,r7
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r7.u32);
	// and r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 & r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825604bc
	if (cr6.eq) goto loc_825604BC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825604b4
	if (!cr6.lt) goto loc_825604B4;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x825586e8
	ctx.lr = 0x825604B4;
	sub_825586E8(ctx, base);
loc_825604B4:
	// stfs f30,60(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r29.u32 + 60, temp.u32);
	// b 0x825604c8
	goto loc_825604C8;
loc_825604BC:
	// lfs f0,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,60(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 60, temp.u32);
loc_825604C8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r31,203
	ctx.r10.s64 = r31.s64 + 203;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825604e8
	if (cr6.eq) goto loc_825604E8;
	// fmr f13,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f29.f64;
	// b 0x825604ec
	goto loc_825604EC;
loc_825604E8:
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
loc_825604EC:
	// addi r10,r31,205
	ctx.r10.s64 = r31.s64 + 205;
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82560504
	if (cr6.eq) goto loc_82560504;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x82560508
	goto loc_82560508;
loc_82560504:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_82560508:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// addi r9,r31,57
	ctx.r9.s64 = r31.s64 + 57;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,24(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 24, temp.u32);
	// lfs f13,7856(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7856);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fsel f7,f8,f31,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// fmadds f6,f7,f10,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f11.f64));
	// stfs f6,132(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r8,r11,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82560564
	if (cr6.eq) goto loc_82560564;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x82560568
	goto loc_82560568;
loc_82560564:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_82560568:
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// stfs f0,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 20, temp.u32);
	// addi r8,r31,32
	ctx.r8.s64 = r31.s64 + 32;
	// stfs f0,144(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r6,288(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 288);
	// rlwinm r7,r11,8,0,23
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// xor r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// lbzx r5,r7,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r8.u32);
	// and r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 & ctx.r5.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825605b4
	if (cr6.eq) goto loc_825605B4;
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// subfic r8,r9,1
	xer.ca = ctx.r9.u32 <= 1;
	ctx.r8.s64 = 1 - ctx.r9.s64;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_825605B4:
	// lwz r3,52(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82560628
	if (cr6.eq) goto loc_82560628;
	// rlwinm r11,r11,8,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r7,286(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 286);
	// addi r8,r31,30
	ctx.r8.s64 = r31.s64 + 30;
	// lbz r6,30(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 30);
	// xor r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// lbzx r4,r11,r8
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// and r10,r5,r4
	ctx.r10.u64 = ctx.r5.u64 & ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825605f0
	if (cr6.eq) goto loc_825605F0;
	// bl 0x8255ae18
	ctx.lr = 0x825605EC;
	sub_8255AE18(ctx, base);
	// b 0x82560614
	goto loc_82560614;
loc_825605F0:
	// addi r8,r31,44
	ctx.r8.s64 = r31.s64 + 44;
	// lbz r7,300(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// lbz r6,44(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 44);
	// xor r4,r7,r6
	ctx.r4.u64 = ctx.r7.u64 ^ ctx.r6.u64;
	// lbzx r5,r11,r8
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// and r11,r4,r5
	r11.u64 = ctx.r4.u64 & ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82560618
	if (cr6.eq) goto loc_82560618;
	// bl 0x8255ae20
	ctx.lr = 0x82560614;
	sub_8255AE20(ctx, base);
loc_82560614:
	// sth r3,44(r29)
	PPC_STORE_U16(r29.u32 + 44, ctx.r3.u16);
loc_82560618:
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// sth r9,44(r29)
	PPC_STORE_U16(r29.u32 + 44, ctx.r9.u16);
loc_82560628:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-64(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8256063C"))) PPC_WEAK_FUNC(sub_8256063C);
PPC_FUNC_IMPL(__imp__sub_8256063C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82560640"))) PPC_WEAK_FUNC(sub_82560640);
PPC_FUNC_IMPL(__imp__sub_82560640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82560648;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d0
	ctx.lr = 0x82560650;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// lbz r9,57(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// addi r11,r10,21384
	r11.s64 = ctx.r10.s64 + 21384;
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r11,-28876
	r11.s64 = r11.s64 + -28876;
	// addi r10,r10,1068
	ctx.r10.s64 = ctx.r10.s64 + 1068;
	// lfs f27,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f27.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f26,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f26.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,14192
	r11.s64 = r11.s64 + 14192;
	// addi r10,r10,7444
	ctx.r10.s64 = ctx.r10.s64 + 7444;
	// lfs f29,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f29.f64 = double(temp.f32);
	// lfs f30,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f30.f64 = double(temp.f32);
	// beq cr6,0x825606bc
	if (cr6.eq) goto loc_825606BC;
	// lbz r8,17(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x825606c8
	goto loc_825606C8;
loc_825606BC:
	// lbz r8,19(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 19);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_825606C8:
	// fcfid f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 - f27.f64));
	// fmuls f0,f11,f26
	f0.f64 = double(float(ctx.f11.f64 * f26.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x825606e8
	if (!cr6.lt) goto loc_825606E8;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x825606f4
	goto loc_825606F4;
loc_825606E8:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x825606f4
	if (!cr6.gt) goto loc_825606F4;
	// fmr f0,f30
	f0.f64 = f30.f64;
loc_825606F4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f2,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x82560704;
	sub_8260C5C8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fneg f31,f1
	ctx.fpscr.disableFlushMode();
	f31.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r29,r11,29952
	r29.s64 = r11.s64 + 29952;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lfs f28,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f28.f64 = double(temp.f32);
	// beq cr6,0x82560768
	if (cr6.eq) goto loc_82560768;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82560748
	if (cr6.eq) goto loc_82560748;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8255fb60
	ctx.lr = 0x82560744;
	sub_8255FB60(ctx, base);
	// b 0x8256085c
	goto loc_8256085C;
loc_82560748:
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82560758
	if (cr6.eq) goto loc_82560758;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	f31.f64 = f29.f64;
loc_82560758:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8255fb60
	ctx.lr = 0x82560764;
	sub_8255FB60(ctx, base);
	// b 0x8256085c
	goto loc_8256085C;
loc_82560768:
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lfs f13,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// rlwinm r7,r8,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825607ac
	if (cr6.eq) goto loc_825607AC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825607a4
	if (!cr6.lt) goto loc_825607A4;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x825586e8
	ctx.lr = 0x825607A4;
	sub_825586E8(ctx, base);
loc_825607A4:
	// stfs f28,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// b 0x825607b8
	goto loc_825607B8;
loc_825607AC:
	// lfs f0,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,60(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
loc_825607B8:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825607d0
	if (cr6.eq) goto loc_825607D0;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x825607e0
	goto loc_825607E0;
loc_825607D0:
	// fneg f0,f31
	ctx.fpscr.disableFlushMode();
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// fsel f13,f0,f0,f28
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f28.f64;
	// fsubs f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 - f30.f64));
	// fsel f0,f12,f30,f13
	f0.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
loc_825607E0:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f0,136(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82560804
	if (cr6.eq) goto loc_82560804;
	// fmr f0,f30
	f0.f64 = f30.f64;
	// b 0x82560810
	goto loc_82560810;
loc_82560804:
	// fsel f0,f31,f31,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64 >= 0.0 ? f31.f64 : f28.f64;
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// fsel f0,f13,f30,f0
	f0.f64 = ctx.f13.f64 >= 0.0 ? f30.f64 : f0.f64;
loc_82560810:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,140(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// xor r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8256085c
	if (cr6.eq) goto loc_8256085C;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82560854
	if (!cr6.eq) goto loc_82560854;
	// li r4,2
	ctx.r4.s64 = 2;
loc_82560854:
	// bl 0x825617e8
	ctx.lr = 0x82560858;
	sub_825617E8(ctx, base);
	// sth r3,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r3.u16);
loc_8256085C:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82560874
	if (cr6.eq) goto loc_82560874;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x82560878
	goto loc_82560878;
loc_82560874:
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f28.f64;
loc_82560878:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f0,144(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 144, temp.u32);
	// lbz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 - f27.f64));
	// fmuls f0,f11,f26
	f0.f64 = double(float(ctx.f11.f64 * f26.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x825608b0
	if (!cr6.lt) goto loc_825608B0;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x825608bc
	goto loc_825608BC;
loc_825608B0:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x825608bc
	if (!cr6.gt) goto loc_825608BC;
	// fmr f0,f30
	f0.f64 = f30.f64;
loc_825608BC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f31,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x825608D0;
	sub_8260C5C8(ctx, base);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lfs f1,224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8255ff78
	ctx.lr = 0x825608EC;
	sub_8255FF78(ctx, base);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// lfs f0,8(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f13,7856(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7856);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// fmsubs f9,f11,f1,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 - ctx.f10.f64));
	// fsubs f8,f12,f30
	ctx.f8.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fsel f7,f8,f30,f12
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f30.f64 : ctx.f12.f64;
	// fmadds f6,f9,f7,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 + ctx.f10.f64));
	// stfs f6,132(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r7,12(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// xor r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// and r11,r6,r8
	r11.u64 = ctx.r6.u64 & ctx.r8.u64;
	// rlwinm r5,r11,0,29,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82560944
	if (cr6.eq) goto loc_82560944;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8255ae20
	ctx.lr = 0x82560940;
	sub_8255AE20(ctx, base);
	// b 0x82560958
	goto loc_82560958;
loc_82560944:
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8256095c
	if (cr6.eq) goto loc_8256095C;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8255ae18
	ctx.lr = 0x82560958;
	sub_8255AE18(ctx, base);
loc_82560958:
	// sth r3,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r3.u16);
loc_8256095C:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// sth r9,44(r31)
	PPC_STORE_U16(r31.u32 + 44, ctx.r9.u16);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82560a28
	if (cr6.eq) goto loc_82560A28;
	// lbz r10,17(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 - f27.f64));
	// fmuls f1,f11,f26
	ctx.f1.f64 = double(float(ctx.f11.f64 * f26.f64));
	// fcmpu cr6,f1,f29
	cr6.compare(ctx.f1.f64, f29.f64);
	// bge cr6,0x825609a8
	if (!cr6.lt) goto loc_825609A8;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// b 0x825609b4
	goto loc_825609B4;
loc_825609A8:
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// ble cr6,0x825609b4
	if (!cr6.gt) goto loc_825609B4;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
loc_825609B4:
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x825609BC;
	sub_8260C5C8(ctx, base);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lbz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fsubs f9,f10,f27
	ctx.f9.f64 = double(float(ctx.f10.f64 - f27.f64));
	// fmuls f0,f9,f26
	f0.f64 = double(float(ctx.f9.f64 * f26.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x825609f4
	if (!cr6.lt) goto loc_825609F4;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82560a00
	goto loc_82560A00;
loc_825609F4:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82560a00
	if (!cr6.gt) goto loc_82560A00;
	// fmr f0,f30
	f0.f64 = f30.f64;
loc_82560A00:
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x82560A0C;
	sub_8260C5C8(ctx, base);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba1c
	ctx.lr = 0x82560A24;
	// b 0x823d924c
	return;
loc_82560A28:
	// stfs f28,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f28,36(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba1c
	ctx.lr = 0x82560A3C;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82560A40"))) PPC_WEAK_FUNC(sub_82560A40);
PPC_FUNC_IMPL(__imp__sub_82560A40) {
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
	ctx.lr = 0x82560A48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-23504
	r31.s64 = r11.s64 + -23504;
	// lwz r11,-23504(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23504);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82560b94
	if (!cr6.eq) goto loc_82560B94;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82560A68;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82560a7c
	if (cr6.eq) goto loc_82560A7C;
	// bl 0x821d5408
	ctx.lr = 0x82560A78;
	sub_821D5408(ctx, base);
	// b 0x82560a80
	goto loc_82560A80;
loc_82560A7C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82560A80:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-9332
	ctx.r7.s64 = ctx.r10.s64 + -9332;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32170
	ctx.r8.s64 = -2108293120;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-304
	ctx.r4.s64 = ctx.r8.s64 + -304;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,7740
	ctx.r5.s64 = ctx.r3.s64 + 7740;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r10,7764
	ctx.r3.s64 = ctx.r10.s64 + 7764;
	// addi r29,r9,7788
	r29.s64 = ctx.r9.s64 + 7788;
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// addi r11,r8,7812
	r11.s64 = ctx.r8.s64 + 7812;
	// li r10,28
	ctx.r10.s64 = 28;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,36
	ctx.r7.s64 = 36;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// bne cr6,0x82560b2c
	if (!cr6.eq) goto loc_82560B2C;
	// bl 0x82564488
	ctx.lr = 0x82560B28;
	sub_82564488(ctx, base);
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
loc_82560B2C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x82560B38;
	sub_821D4458(ctx, base);
	// lwz r11,-23488(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x82560B50;
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
	ctx.lr = 0x82560B6C;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,7836
	ctx.r4.s64 = ctx.r8.s64 + 7836;
	// bl 0x821d4b00
	ctx.lr = 0x82560B7C;
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
	ctx.lr = 0x82560B94;
	sub_821C0548(ctx, base);
loc_82560B94:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82560B9C"))) PPC_WEAK_FUNC(sub_82560B9C);
PPC_FUNC_IMPL(__imp__sub_82560B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82560BA0"))) PPC_WEAK_FUNC(sub_82560BA0);
PPC_FUNC_IMPL(__imp__sub_82560BA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-9036
	ctx.r10.s64 = r11.s64 + -9036;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2028
	sub_821D2028(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82560BB0"))) PPC_WEAK_FUNC(sub_82560BB0);
PPC_FUNC_IMPL(__imp__sub_82560BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// sth r11,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, r11.u16);
	// stb r11,46(r3)
	PPC_STORE_U8(ctx.r3.u32 + 46, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560BE8"))) PPC_WEAK_FUNC(sub_82560BE8);
PPC_FUNC_IMPL(__imp__sub_82560BE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// sth r4,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r4.u16);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,-9036
	ctx.r8.s64 = ctx.r9.s64 + -9036;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// sth r11,44(r3)
	PPC_STORE_U16(ctx.r3.u32 + 44, r11.u16);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r11,46(r3)
	PPC_STORE_U8(ctx.r3.u32 + 46, r11.u8);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560C38"))) PPC_WEAK_FUNC(sub_82560C38);
PPC_FUNC_IMPL(__imp__sub_82560C38) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-9036
	ctx.r10.s64 = r11.s64 + -9036;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82560C64;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82560c7c
	if (cr6.eq) goto loc_82560C7C;
	// bl 0x82130588
	ctx.lr = 0x82560C78;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82560C7C:
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

__attribute__((alias("__imp__sub_82560C94"))) PPC_WEAK_FUNC(sub_82560C94);
PPC_FUNC_IMPL(__imp__sub_82560C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82560C98"))) PPC_WEAK_FUNC(sub_82560C98);
PPC_FUNC_IMPL(__imp__sub_82560C98) {
	PPC_FUNC_PROLOGUE();
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560CA0"))) PPC_WEAK_FUNC(sub_82560CA0);
PPC_FUNC_IMPL(__imp__sub_82560CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// lfs f13,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, r11.u8);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r11,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, r11.u8);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560CE0"))) PPC_WEAK_FUNC(sub_82560CE0);
PPC_FUNC_IMPL(__imp__sub_82560CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,7876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7876);
	f0.f64 = double(temp.f32);
	// lwz r8,20(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// fmuls f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lfs f12,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,12160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12160);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// fmuls f31,f11,f13
	f31.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// ble cr6,0x82560dd8
	if (!cr6.gt) goto loc_82560DD8;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x82560d84
	if (cr6.lt) goto loc_82560D84;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// addi r11,r7,28
	r11.s64 = ctx.r7.s64 + 28;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_82560D48:
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lfs f13,420(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 420);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f10,420(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 420);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,420(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 420);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,420(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 420);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f11,f10
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// fadds f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// fadds f0,f6,f8
	f0.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// bne 0x82560d48
	if (!cr0.eq) goto loc_82560D48;
loc_82560D84:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x82560db4
	if (!cr6.lt) goto loc_82560DB4;
	// addi r10,r9,6
	ctx.r10.s64 = ctx.r9.s64 + 6;
	// subf r11,r9,r8
	r11.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
loc_82560D9C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lfs f13,420(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 420);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// bne 0x82560d9c
	if (!cr0.eq) goto loc_82560D9C;
loc_82560DB4:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f0,f0,f10
	f0.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82560dd8
	if (!cr6.gt) goto loc_82560DD8;
	// fdivs f31,f31,f0
	f31.f64 = double(float(f31.f64 / f0.f64));
loc_82560DD8:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82558520
	ctx.lr = 0x82560DE0;
	sub_82558520(ctx, base);
	// fdivs f1,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 / f31.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560DFC"))) PPC_WEAK_FUNC(sub_82560DFC);
PPC_FUNC_IMPL(__imp__sub_82560DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82560E00"))) PPC_WEAK_FUNC(sub_82560E00);
PPC_FUNC_IMPL(__imp__sub_82560E00) {
	PPC_FUNC_PROLOGUE();
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82560E08"))) PPC_WEAK_FUNC(sub_82560E08);
PPC_FUNC_IMPL(__imp__sub_82560E08) {
	PPC_FUNC_PROLOGUE();
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29232(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fsel f9,f10,f10,f13
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : ctx.f13.f64;
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fsel f0,f8,f31,f9
	f0.f64 = ctx.f8.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x82560e94
	if (!cr6.gt) goto loc_82560E94;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32692(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32692);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82560e84
	if (cr6.lt) goto loc_82560E84;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// b 0x82560e94
	goto loc_82560E94;
loc_82560E84:
	// fsubs f13,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,-8696(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8696);
	f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82560E94:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// fmr f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f13.f64;
	// lfd f2,-11296(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -11296);
	// bl 0x823dc480
	ctx.lr = 0x82560EA4;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,29952
	r11.s64 = r11.s64 + 29952;
	// fadds f11,f0,f31
	ctx.f11.f64 = double(float(f0.f64 + f31.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82560ef0
	if (!cr6.gt) goto loc_82560EF0;
	// lfs f12,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bge cr6,0x82560f1c
	if (!cr6.lt) goto loc_82560F1C;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f13,f12,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f9,72(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// ble cr6,0x82560f40
	if (!cr6.gt) goto loc_82560F40;
	// b 0x82560f3c
	goto loc_82560F3C;
loc_82560EF0:
	// lfs f12,56(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bge cr6,0x82560f1c
	if (!cr6.lt) goto loc_82560F1C;
	// lfs f10,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f13,f12,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f9,72(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// ble cr6,0x82560f40
	if (!cr6.gt) goto loc_82560F40;
	// b 0x82560f3c
	goto loc_82560F3C;
loc_82560F1C:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82560f40
	if (!cr6.gt) goto loc_82560F40;
	// lfs f10,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f9,f13,f12,f10
	ctx.f9.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - ctx.f10.f64)));
	// stfs f9,72(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x82560f40
	if (!cr6.lt) goto loc_82560F40;
loc_82560F3C:
	// stfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_82560F40:
	// lfs f13,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82560f7c
	if (!cr6.lt) goto loc_82560F7C;
	// lfs f12,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bge cr6,0x82560fa8
	if (!cr6.lt) goto loc_82560FA8;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f13,f12,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f10,148(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// ble cr6,0x82560fcc
	if (!cr6.gt) goto loc_82560FCC;
	// b 0x82560fc8
	goto loc_82560FC8;
loc_82560F7C:
	// lfs f12,56(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bge cr6,0x82560fa8
	if (!cr6.lt) goto loc_82560FA8;
	// lfs f11,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f13,f12,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f11.f64));
	// stfs f10,148(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// ble cr6,0x82560fcc
	if (!cr6.gt) goto loc_82560FCC;
	// b 0x82560fc8
	goto loc_82560FC8;
loc_82560FA8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82560fcc
	if (!cr6.gt) goto loc_82560FCC;
	// lfs f11,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f10,f13,f12,f11
	ctx.f10.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - ctx.f11.f64)));
	// stfs f10,148(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bge cr6,0x82560fcc
	if (!cr6.lt) goto loc_82560FCC;
loc_82560FC8:
	// stfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
loc_82560FCC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bgt cr6,0x82560ff4
	if (cr6.gt) goto loc_82560FF4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82560ff4
	if (!cr6.lt) goto loc_82560FF4;
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f31,148(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
loc_82560FF4:
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	f0.f64 = double(temp.f32);
	// lfs f13,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82561008
	if (!cr6.gt) goto loc_82561008;
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
loc_82561008:
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

__attribute__((alias("__imp__sub_82561020"))) PPC_WEAK_FUNC(sub_82561020);
PPC_FUNC_IMPL(__imp__sub_82561020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r4.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256103C"))) PPC_WEAK_FUNC(sub_8256103C);
PPC_FUNC_IMPL(__imp__sub_8256103C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82561040"))) PPC_WEAK_FUNC(sub_82561040);
PPC_FUNC_IMPL(__imp__sub_82561040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256104C"))) PPC_WEAK_FUNC(sub_8256104C);
PPC_FUNC_IMPL(__imp__sub_8256104C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82561050"))) PPC_WEAK_FUNC(sub_82561050);
PPC_FUNC_IMPL(__imp__sub_82561050) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8256108c
	if (!cr6.lt) goto loc_8256108C;
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
loc_8256108C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x825610b4
	if (!cr6.lt) goto loc_825610B4;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825610B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-13028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13028);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x82560ce0
	ctx.lr = 0x825610C8;
	sub_82560CE0(ctx, base);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r9,r10,-2
	ctx.r9.s64 = ctx.r10.s64 + -2;
	// cmpwi cr6,r9,4
	cr6.compare<int32_t>(ctx.r9.s32, 4, xer);
	// blt cr6,0x8256112c
	if (cr6.lt) goto loc_8256112C;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
loc_825610E8:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x825611a4
	if (cr6.gt) goto loc_825611A4;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82561170
	if (cr6.gt) goto loc_82561170;
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82561188
	if (cr6.gt) goto loc_82561188;
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x825611a0
	if (cr6.gt) goto loc_825611A0;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r9,r10,-3
	ctx.r9.s64 = ctx.r10.s64 + -3;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r3,r9
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r9.s32, xer);
	// blt cr6,0x825610e8
	if (cr6.lt) goto loc_825610E8;
loc_8256112C:
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bge cr6,0x825611a4
	if (!cr6.lt) goto loc_825611A4;
	// addi r11,r3,9
	r11.s64 = ctx.r3.s64 + 9;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
loc_82561140:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x825611a4
	if (cr6.gt) goto loc_825611A4;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// blt cr6,0x82561140
	if (cr6.lt) goto loc_82561140;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82561170:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82561188:
	// addi r3,r3,2
	ctx.r3.s64 = ctx.r3.s64 + 2;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825611A0:
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
loc_825611A4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_825611B8"))) PPC_WEAK_FUNC(sub_825611B8);
PPC_FUNC_IMPL(__imp__sub_825611B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f11,-32032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f10,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f9,-332(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -332);
	ctx.f9.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// li r9,7
	ctx.r9.s64 = 7;
	// lfs f8,27632(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27632);
	ctx.f8.f64 = double(temp.f32);
	// li r8,8
	ctx.r8.s64 = 8;
	// lfs f7,-11624(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -11624);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,31016(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31016);
	ctx.f6.f64 = double(temp.f32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lfs f12,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r8.u32);
	// lfs f5,-12084(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12084);
	ctx.f5.f64 = double(temp.f32);
	// stfs f11,40(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f9,28(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f8,4(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f7,8(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f6,12(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f12,44(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f5,56(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82561250"))) PPC_WEAK_FUNC(sub_82561250);
PPC_FUNC_IMPL(__imp__sub_82561250) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r7,-8712
	ctx.r6.s64 = ctx.r7.s64 + -8712;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f8,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f8.f64 = double(temp.f32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f8,72(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f13,32308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32308);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f0,76(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f9,32312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32312);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,-2376(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -2376);
	ctx.f10.f64 = double(temp.f32);
	// li r10,2
	ctx.r10.s64 = 2;
	// lfs f11,-28736(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -28736);
	ctx.f11.f64 = double(temp.f32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lfs f12,-18920(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18920);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// lfs f13,27632(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27632);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// addi r11,r3,84
	r11.s64 = ctx.r3.s64 + 84;
	// stfs f0,152(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// stfs f0,188(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 188, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f8,148(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f0,156(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 156, temp.u32);
	// stfs f0,192(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
loc_825612E4:
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// stfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfs f11,36(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// stfs f10,76(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 76, temp.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f9,112(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// cmpwi cr6,r10,9
	cr6.compare<int32_t>(ctx.r10.s32, 9, xer);
	// fdivs f4,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 / ctx.f5.f64));
	// stfs f4,-40(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + -40, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// blt cr6,0x825612e4
	if (cr6.lt) goto loc_825612E4;
	// li r11,1
	r11.s64 = 1;
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// stfs f8,72(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f8,148(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stb r9,32(r3)
	PPC_STORE_U8(ctx.r3.u32 + 32, ctx.r9.u8);
	// stb r9,33(r3)
	PPC_STORE_U8(ctx.r3.u32 + 33, ctx.r9.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8256134C"))) PPC_WEAK_FUNC(sub_8256134C);
PPC_FUNC_IMPL(__imp__sub_8256134C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82561350"))) PPC_WEAK_FUNC(sub_82561350);
PPC_FUNC_IMPL(__imp__sub_82561350) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-8712
	ctx.r10.s64 = r11.s64 + -8712;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8256137C;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82561394
	if (cr6.eq) goto loc_82561394;
	// bl 0x82130588
	ctx.lr = 0x82561390;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82561394:
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

__attribute__((alias("__imp__sub_825613AC"))) PPC_WEAK_FUNC(sub_825613AC);
PPC_FUNC_IMPL(__imp__sub_825613AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825613B0"))) PPC_WEAK_FUNC(sub_825613B0);
PPC_FUNC_IMPL(__imp__sub_825613B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x825613B8;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9c0
	ctx.lr = 0x825613C0;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f24,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f24.f64 = double(temp.f32);
	// stfs f24,144(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f24,192(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f24,240(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lwz r26,0(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f1,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f24,288(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f24,148(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f24,196(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f24,244(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f24,292(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// bl 0x82560ce0
	ctx.lr = 0x82561400;
	sub_82560CE0(ctx, base);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f24,100(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f1,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82560ce0
	ctx.lr = 0x8256141C;
	sub_82560CE0(ctx, base);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f1,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f1,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82560ce0
	ctx.lr = 0x82561430;
	sub_82560CE0(ctx, base);
	// rlwinm r25,r26,2,0,29
	r25.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// add r6,r25,r11
	ctx.r6.u64 = r25.u64 + r11.u64;
	// addi r27,r26,-2
	r27.s64 = r26.s64 + -2;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// lfs f27,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f27.f64 = double(temp.f32);
	// stfs f1,-4(r6)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r6.u32 + -4, temp.u32);
	// ble cr6,0x82561504
	if (!cr6.gt) goto loc_82561504;
	// addi r28,r27,-1
	r28.s64 = r27.s64 + -1;
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / f0.f64));
	// extsw r11,r28
	r11.s64 = r28.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f31,f12
	f31.f64 = double(float(ctx.f12.f64));
	// fdivs f2,f27,f31
	ctx.f2.f64 = double(float(f27.f64 / f31.f64));
	// bl 0x823dc480
	ctx.lr = 0x8256147C;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// ble cr6,0x82561504
	if (!cr6.gt) goto loc_82561504;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// addi r29,r1,108
	r29.s64 = ctx.r1.s64 + 108;
	// subfic r27,r27,1
	xer.ca = r27.u32 <= 1;
	r27.s64 = 1 - r27.s64;
loc_82561498:
	// add r11,r27,r30
	r11.u64 = r27.u64 + r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsw r9,r30
	ctx.r9.s64 = r30.s32;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,280(r1)
	PPC_STORE_U64(ctx.r1.u32 + 280, ctx.r8.u64);
	// lfd f13,280(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 280);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lfs f11,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fmuls f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// fdivs f5,f6,f31
	ctx.f5.f64 = double(float(ctx.f6.f64 / f31.f64));
	// fsubs f2,f9,f5
	ctx.f2.f64 = double(float(ctx.f9.f64 - ctx.f5.f64));
	// bl 0x823dc480
	ctx.lr = 0x825614E4;
	sub_823DC480(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// fmuls f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// stfs f2,0(r29)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// blt cr6,0x82561498
	if (cr6.lt) goto loc_82561498;
loc_82561504:
	// addi r11,r26,-1
	r11.s64 = r26.s64 + -1;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x8256161c
	if (!cr6.gt) goto loc_8256161C;
	// addi r29,r11,-2
	r29.s64 = r11.s64 + -2;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lfs f25,-11288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11288);
	f25.f64 = double(temp.f32);
	// lfs f26,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f26.f64 = double(temp.f32);
loc_82561528:
	// addi r11,r1,108
	r11.s64 = ctx.r1.s64 + 108;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f28,f0,f13
	f28.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bl 0x82558508
	ctx.lr = 0x82561544;
	sub_82558508(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x82558520
	ctx.lr = 0x82561550;
	sub_82558520(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// fsubs f12,f29,f30
	ctx.f12.f64 = double(float(f29.f64 - f30.f64));
	// fcmpu cr6,f12,f27
	cr6.compare(ctx.f12.f64, f27.f64);
	// ble cr6,0x825615ac
	if (!cr6.gt) goto loc_825615AC;
loc_82561560:
	// fadds f0,f29,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 + f30.f64));
	// lwz r28,8(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmuls f31,f0,f26
	f31.f64 = double(float(f0.f64 * f26.f64));
	// fmuls f23,f31,f25
	f23.f64 = double(float(f31.f64 * f25.f64));
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// bl 0x82559808
	ctx.lr = 0x8256157C;
	sub_82559808(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmr f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = ctx.f1.f64;
	// fmuls f1,f23,f28
	ctx.f1.f64 = double(float(f23.f64 * f28.f64));
	// bl 0x82559808
	ctx.lr = 0x8256158C;
	sub_82559808(ctx, base);
	// fcmpu cr6,f22,f1
	ctx.fpscr.disableFlushMode();
	cr6.compare(f22.f64, ctx.f1.f64);
	// bge cr6,0x8256159c
	if (!cr6.lt) goto loc_8256159C;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// b 0x825615a0
	goto loc_825615A0;
loc_8256159C:
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_825615A0:
	// fsubs f0,f29,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - f30.f64));
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bgt cr6,0x82561560
	if (cr6.gt) goto loc_82561560;
loc_825615AC:
	// fadds f0,f29,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 + f30.f64));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,152
	ctx.r10.s64 = ctx.r1.s64 + 152;
	// addi r9,r1,200
	ctx.r9.s64 = ctx.r1.s64 + 200;
	// addi r8,r1,252
	ctx.r8.s64 = ctx.r1.s64 + 252;
	// addi r7,r1,300
	ctx.r7.s64 = ctx.r1.s64 + 300;
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f27,f13
	ctx.f11.f64 = double(float(f27.f64 - ctx.f13.f64));
	// fsubs f10,f27,f12
	ctx.f10.f64 = double(float(f27.f64 - ctx.f12.f64));
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f27,f9
	ctx.f7.f64 = double(float(f27.f64 - ctx.f9.f64));
	// fsubs f6,f27,f8
	ctx.f6.f64 = double(float(f27.f64 - ctx.f8.f64));
	// fmuls f5,f0,f26
	ctx.f5.f64 = double(float(f0.f64 * f26.f64));
	// fmuls f4,f11,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f5.f64));
	// fmuls f3,f10,f5
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f5.f64));
	// fmuls f2,f7,f5
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// stfsx f2,r30,r10
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, temp.u32);
	// fmuls f1,f6,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// stfsx f1,r30,r9
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + ctx.r9.u32, temp.u32);
	// fmuls f0,f4,f28
	f0.f64 = double(float(ctx.f4.f64 * f28.f64));
	// stfsx f0,r30,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + ctx.r8.u32, temp.u32);
	// fmuls f13,f3,f28
	ctx.f13.f64 = double(float(ctx.f3.f64 * f28.f64));
	// stfsx f13,r30,r7
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, temp.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82561528
	if (!cr0.eq) goto loc_82561528;
loc_8256161C:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82558520
	ctx.lr = 0x82561624;
	sub_82558520(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r25,r11
	r11.u64 = r25.u64 + r11.u64;
	// stfs f1,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// bl 0x82558520
	ctx.lr = 0x82561638;
	sub_82558520(ctx, base);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// stfs f24,248(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f24,296(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// add r10,r25,r11
	ctx.r10.u64 = r25.u64 + r11.u64;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// stfs f1,-4(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// blt cr6,0x82561770
	if (cr6.lt) goto loc_82561770;
	// addi r11,r26,-4
	r11.s64 = r26.s64 + -4;
	// addi r10,r31,76
	ctx.r10.s64 = r31.s64 + 76;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_82561670:
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lfsx f0,r11,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	f0.f64 = double(temp.f32);
	// addi r30,r1,100
	r30.s64 = ctx.r1.s64 + 100;
	// lfsx f13,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// addi r6,r1,196
	ctx.r6.s64 = ctx.r1.s64 + 196;
	// lfsx f12,r11,r5
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,244
	ctx.r5.s64 = ctx.r1.s64 + 244;
	// lfsx f10,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,292
	ctx.r4.s64 = ctx.r1.s64 + 292;
	// lfsx f9,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lfsx f8,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r30,r1,152
	r30.s64 = ctx.r1.s64 + 152;
	// lfsx f7,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r7,r1,200
	ctx.r7.s64 = ctx.r1.s64 + 200;
	// addi r6,r1,248
	ctx.r6.s64 = ctx.r1.s64 + 248;
	// lfsx f6,r11,r5
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	ctx.f5.f64 = double(temp.f32);
	// addi r5,r1,296
	ctx.r5.s64 = ctx.r1.s64 + 296;
	// lfsx f4,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f4.f64 = double(temp.f32);
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// lfsx f3,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f3.f64 = double(temp.f32);
	// addi r3,r1,156
	ctx.r3.s64 = ctx.r1.s64 + 156;
	// lfsx f2,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f2.f64 = double(temp.f32);
	// addi r30,r1,204
	r30.s64 = ctx.r1.s64 + 204;
	// lfsx f1,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r1,252
	ctx.r7.s64 = ctx.r1.s64 + 252;
	// addi r6,r1,300
	ctx.r6.s64 = ctx.r1.s64 + 300;
	// lfsx f31,r11,r5
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	f31.f64 = double(temp.f32);
	// lfsx f30,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	f30.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f29,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	f29.f64 = double(temp.f32);
	// lfsx f28,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	f28.f64 = double(temp.f32);
	// lfsx f27,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	f27.f64 = double(temp.f32);
	// lfsx f26,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	f26.f64 = double(temp.f32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stfs f0,-40(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -40, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,36(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// stfs f11,76(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 76, temp.u32);
	// stfs f10,112(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 112, temp.u32);
	// stfs f9,-36(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + -36, temp.u32);
	// stfs f8,4(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f7,40(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// stfs f6,80(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 80, temp.u32);
	// stfs f5,116(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 116, temp.u32);
	// stfs f4,-32(r10)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r10.u32 + -32, temp.u32);
	// stfs f3,8(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stfs f2,44(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 44, temp.u32);
	// stfs f1,84(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 84, temp.u32);
	// stfs f31,120(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 120, temp.u32);
	// stfs f30,-28(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + -28, temp.u32);
	// stfs f29,12(r10)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// stfs f28,48(r10)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r10.u32 + 48, temp.u32);
	// stfs f27,88(r10)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r10.u32 + 88, temp.u32);
	// stfs f26,124(r10)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r10.u32 + 124, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x82561670
	if (!cr0.eq) goto loc_82561670;
loc_82561770:
	// cmpw cr6,r8,r26
	cr6.compare<int32_t>(ctx.r8.s32, r26.s32, xer);
	// bge cr6,0x825617d8
	if (!cr6.lt) goto loc_825617D8;
	// addi r10,r8,19
	ctx.r10.s64 = ctx.r8.s64 + 19;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r26
	ctx.r9.s64 = r26.s64 - ctx.r8.s64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
loc_8256178C:
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// lfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfsx f13,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r11,r5
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r5.u32);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f10,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stfs f0,-40(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -40, temp.u32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,36(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 36, temp.u32);
	// stfs f11,76(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 76, temp.u32);
	// stfs f10,112(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 112, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8256178c
	if (!cr0.eq) goto loc_8256178C;
loc_825617D8:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba0c
	ctx.lr = 0x825617E4;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_825617E8"))) PPC_WEAK_FUNC(sub_825617E8);
PPC_FUNC_IMPL(__imp__sub_825617E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x82561850
	if (cr6.eq) goto loc_82561850;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82561810
	if (!cr6.eq) goto loc_82561810;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r4,r9
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, xer);
	// bge cr6,0x82561850
	if (!cr6.lt) goto loc_82561850;
loc_82561810:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// ble cr6,0x8256183c
	if (!cr6.gt) goto loc_8256183C;
	// li r11,1
	r11.s64 = 1;
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// rotlwi r3,r4,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// blr 
	return;
loc_8256183C:
	// bge cr6,0x8256184c
	if (!cr6.lt) goto loc_8256184C;
	// li r11,-1
	r11.s64 = -1;
	// stfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
loc_8256184C:
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
loc_82561850:
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// blr 
	return;
}

