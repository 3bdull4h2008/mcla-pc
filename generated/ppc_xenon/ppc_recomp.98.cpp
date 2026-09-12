#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824E70FC"))) PPC_WEAK_FUNC(sub_824E70FC);
PPC_FUNC_IMPL(__imp__sub_824E70FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7100"))) PPC_WEAK_FUNC(sub_824E7100);
PPC_FUNC_IMPL(__imp__sub_824E7100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E710C"))) PPC_WEAK_FUNC(sub_824E710C);
PPC_FUNC_IMPL(__imp__sub_824E710C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7110"))) PPC_WEAK_FUNC(sub_824E7110);
PPC_FUNC_IMPL(__imp__sub_824E7110) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7118"))) PPC_WEAK_FUNC(sub_824E7118);
PPC_FUNC_IMPL(__imp__sub_824E7118) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,76
	ctx.r3.s64 = ctx.r3.s64 + 76;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7120"))) PPC_WEAK_FUNC(sub_824E7120);
PPC_FUNC_IMPL(__imp__sub_824E7120) {
	PPC_FUNC_PROLOGUE();
	// addi r4,r4,48
	ctx.r4.s64 = ctx.r4.s64 + 48;
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// b 0x824f0550
	sub_824F0550(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E712C"))) PPC_WEAK_FUNC(sub_824E712C);
PPC_FUNC_IMPL(__imp__sub_824E712C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7130"))) PPC_WEAK_FUNC(sub_824E7130);
PPC_FUNC_IMPL(__imp__sub_824E7130) {
	PPC_FUNC_PROLOGUE();
	// addi r4,r4,48
	ctx.r4.s64 = ctx.r4.s64 + 48;
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// b 0x824f0570
	sub_824F0570(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E713C"))) PPC_WEAK_FUNC(sub_824E713C);
PPC_FUNC_IMPL(__imp__sub_824E713C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7140"))) PPC_WEAK_FUNC(sub_824E7140);
PPC_FUNC_IMPL(__imp__sub_824E7140) {
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
	ctx.lr = 0x824E7148;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stb r28,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r28.u8);
	// bl 0x824575f8
	ctx.lr = 0x824E7164;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e71bc
	if (cr6.eq) goto loc_824E71BC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824579e0
	ctx.lr = 0x824E7178;
	sub_824579E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e7198
	if (!cr6.eq) goto loc_824E7198;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f0
	ctx.lr = 0x824E7190;
	sub_824575F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e71b0
	if (cr6.eq) goto loc_824E71B0;
loc_824E7198:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,26104
	ctx.r5.s64 = r11.s64 + 26104;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x824E71B0;
	sub_82137A08(ctx, base);
loc_824E71B0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E71BC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E71C8"))) PPC_WEAK_FUNC(sub_824E71C8);
PPC_FUNC_IMPL(__imp__sub_824E71C8) {
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
	ctx.lr = 0x824E71D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824f99c0
	ctx.lr = 0x824E71DC;
	sub_824F99C0(ctx, base);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E71E8;
	sub_824F0498(ctx, base);
	// addi r29,r31,56
	r29.s64 = r31.s64 + 56;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9438
	ctx.lr = 0x824E71F4;
	sub_824F9438(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9788
	ctx.lr = 0x824E71FC;
	sub_824F9788(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E7204;
	sub_824F0498(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E720C;
	sub_824F9230(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824E7224;
	sub_8244D150(ctx, base);
	// lbz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E723C"))) PPC_WEAK_FUNC(sub_824E723C);
PPC_FUNC_IMPL(__imp__sub_824E723C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7240"))) PPC_WEAK_FUNC(sub_824E7240);
PPC_FUNC_IMPL(__imp__sub_824E7240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, r11.u8);
	// b 0x824e7140
	sub_824E7140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E724C"))) PPC_WEAK_FUNC(sub_824E724C);
PPC_FUNC_IMPL(__imp__sub_824E724C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7250"))) PPC_WEAK_FUNC(sub_824E7250);
PPC_FUNC_IMPL(__imp__sub_824E7250) {
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
	ctx.lr = 0x824E7258;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x824f9788
	ctx.lr = 0x824E7270;
	sub_824F9788(ctx, base);
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E727C;
	sub_824F0498(ctx, base);
	// addi r27,r31,56
	r27.s64 = r31.s64 + 56;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E7288;
	sub_824F9230(ctx, base);
	// li r25,-1
	r25.s64 = -1;
	// addi r29,r31,76
	r29.s64 = r31.s64 + 76;
	// stw r25,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r25.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x824E72A4;
	sub_8244D150(ctx, base);
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// bl 0x824575f8
	ctx.lr = 0x824E72B8;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9970
	ctx.lr = 0x824E72C8;
	sub_824F9970(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f05b0
	ctx.lr = 0x824E72E0;
	sub_824F05B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f93b8
	ctx.lr = 0x824E72F8;
	sub_824F93B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// stb r26,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r26.u8);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7140
	ctx.lr = 0x824E7318;
	sub_824E7140(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7374
	if (cr6.eq) goto loc_824E7374;
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// bl 0x824e6d08
	ctx.lr = 0x824E733C;
	sub_824E6D08(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lbz r8,92(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r7,r9,24
	ctx.r7.u64 = ctx.r9.u32 & 0xFF;
	// rlwimi r8,r7,6,25,25
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 6) & 0x40) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r8,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r8.u8);
	// bl 0x824e6d08
	ctx.lr = 0x824E7358;
	sub_824E6D08(ctx, base);
	// lbz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r5,r4,5,26,26
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0x20) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r5,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r5.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_824E7374:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f9788
	ctx.lr = 0x824E737C;
	sub_824F9788(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f0498
	ctx.lr = 0x824E7384;
	sub_824F0498(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824f9230
	ctx.lr = 0x824E738C;
	sub_824F9230(ctx, base);
	// stw r25,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r25.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d150
	ctx.lr = 0x824E73A0;
	sub_8244D150(ctx, base);
	// lbz r11,92(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 92);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824E73B8"))) PPC_WEAK_FUNC(sub_824E73B8);
PPC_FUNC_IMPL(__imp__sub_824E73B8) {
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
	ctx.lr = 0x824E73C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x8252a660
	ctx.lr = 0x824E73E4;
	sub_8252A660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f97c8
	ctx.lr = 0x824E7408;
	sub_824F97C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f94e0
	ctx.lr = 0x824E7438;
	sub_824F94E0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e74bc
	if (cr6.eq) goto loc_824E74BC;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618750
	ctx.lr = 0x824E7460;
	sub_82618750(ctx, base);
	// subf r5,r28,r29
	ctx.r5.s64 = r29.s64 - r28.s64;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618640
	ctx.lr = 0x824E7470;
	sub_82618640(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82619080
	ctx.lr = 0x824E7480;
	sub_82619080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74b8
	if (cr6.eq) goto loc_824E74B8;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8226b338
	ctx.lr = 0x824E749C;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e74b8
	if (cr6.eq) goto loc_824E74B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186a0
	ctx.lr = 0x824E74B0;
	sub_826186A0(ctx, base);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// b 0x824e74bc
	goto loc_824E74BC;
loc_824E74B8:
	// li r28,0
	r28.s64 = 0;
loc_824E74BC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e74c8
	if (cr6.eq) goto loc_824E74C8;
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
loc_824E74C8:
	// subfic r11,r28,0
	xer.ca = r28.u32 <= 0;
	r11.s64 = 0 - r28.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E74DC"))) PPC_WEAK_FUNC(sub_824E74DC);
PPC_FUNC_IMPL(__imp__sub_824E74DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E74E0"))) PPC_WEAK_FUNC(sub_824E74E0);
PPC_FUNC_IMPL(__imp__sub_824E74E0) {
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
	ctx.lr = 0x824E74E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x824f04c8
	ctx.lr = 0x824E750C;
	sub_824F04C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r5,r11,r29
	ctx.r5.s64 = r29.s64 - r11.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f9888
	ctx.lr = 0x824E7530;
	sub_824F9888(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	// add r4,r11,r30
	ctx.r4.u64 = r11.u64 + r30.u64;
	// bl 0x824f95d0
	ctx.lr = 0x824E7560;
	sub_824F95D0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e75e4
	if (cr6.eq) goto loc_824E75E4;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618750
	ctx.lr = 0x824E7588;
	sub_82618750(ctx, base);
	// subf r5,r28,r29
	ctx.r5.s64 = r29.s64 - r28.s64;
	// add r4,r28,r30
	ctx.r4.u64 = r28.u64 + r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824E7598;
	sub_826185E0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618fa0
	ctx.lr = 0x824E75A8;
	sub_82618FA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e0
	if (cr6.eq) goto loc_824E75E0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82275750
	ctx.lr = 0x824E75C4;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e75e0
	if (cr6.eq) goto loc_824E75E0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824E75D8;
	sub_826186B0(ctx, base);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
	// b 0x824e75e4
	goto loc_824E75E4;
loc_824E75E0:
	// li r28,0
	r28.s64 = 0;
loc_824E75E4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e75f0
	if (cr6.eq) goto loc_824E75F0;
	// stw r28,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r28.u32);
loc_824E75F0:
	// subfic r11,r28,0
	xer.ca = r28.u32 <= 0;
	r11.s64 = 0 - r28.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r10,31
	ctx.r3.u64 = ctx.r10.u32 & 0x1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E7604"))) PPC_WEAK_FUNC(sub_824E7604);
PPC_FUNC_IMPL(__imp__sub_824E7604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7608"))) PPC_WEAK_FUNC(sub_824E7608);
PPC_FUNC_IMPL(__imp__sub_824E7608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30340
	ctx.r10.s64 = r11.s64 + 30340;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7618"))) PPC_WEAK_FUNC(sub_824E7618);
PPC_FUNC_IMPL(__imp__sub_824E7618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30404
	ctx.r10.s64 = r11.s64 + 30404;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7628"))) PPC_WEAK_FUNC(sub_824E7628);
PPC_FUNC_IMPL(__imp__sub_824E7628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30180
	ctx.r10.s64 = r11.s64 + 30180;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7638"))) PPC_WEAK_FUNC(sub_824E7638);
PPC_FUNC_IMPL(__imp__sub_824E7638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30212
	ctx.r10.s64 = r11.s64 + 30212;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7648"))) PPC_WEAK_FUNC(sub_824E7648);
PPC_FUNC_IMPL(__imp__sub_824E7648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30244
	ctx.r10.s64 = r11.s64 + 30244;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7658"))) PPC_WEAK_FUNC(sub_824E7658);
PPC_FUNC_IMPL(__imp__sub_824E7658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30308
	ctx.r10.s64 = r11.s64 + 30308;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7668"))) PPC_WEAK_FUNC(sub_824E7668);
PPC_FUNC_IMPL(__imp__sub_824E7668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,30148
	ctx.r10.s64 = r11.s64 + 30148;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E7678"))) PPC_WEAK_FUNC(sub_824E7678);
PPC_FUNC_IMPL(__imp__sub_824E7678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e7698
	if (cr6.lt) goto loc_824E7698;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bge cr6,0x824e7698
	if (!cr6.lt) goto loc_824E7698;
	// mulli r11,r4,104
	r11.s64 = ctx.r4.s64 * 104;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
loc_824E7698:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E76A0"))) PPC_WEAK_FUNC(sub_824E76A0);
PPC_FUNC_IMPL(__imp__sub_824E76A0) {
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
	ctx.lr = 0x824E76A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7718
	if (!cr6.eq) goto loc_824E7718;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x824501e0
	ctx.lr = 0x824E76CC;
	sub_824501E0(ctx, base);
	// stw r3,432(r31)
	PPC_STORE_U32(r31.u32 + 432, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,3032
	r30.s64 = r31.s64 + 3032;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r11,26236
	ctx.r4.s64 = r11.s64 + 26236;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b98
	ctx.lr = 0x824E76FC;
	sub_824E6B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7718
	if (cr6.eq) goto loc_824E7718;
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E7718:
	// lwz r3,432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e772c
	if (cr6.eq) goto loc_824E772C;
	// bl 0x8275cc90
	ctx.lr = 0x824E7728;
	sub_8275CC90(ctx, base);
	// stw r28,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r28.u32);
loc_824E772C:
	// lwz r11,3032(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3032);
	// addi r3,r31,3032
	ctx.r3.s64 = r31.s64 + 3032;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E7740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E774C"))) PPC_WEAK_FUNC(sub_824E774C);
PPC_FUNC_IMPL(__imp__sub_824E774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7750"))) PPC_WEAK_FUNC(sub_824E7750);
PPC_FUNC_IMPL(__imp__sub_824E7750) {
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
	ctx.lr = 0x824E7758;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// li r25,0
	r25.s64 = 0;
	// bl 0x821f8730
	ctx.lr = 0x824E777C;
	sub_821F8730(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,7,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r11,472
	r31.s64 = r11.s64 + 472;
	// lwz r10,472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x824e780c
	if (!cr6.eq) goto loc_824E780C;
	// addi r4,r29,436
	ctx.r4.s64 = r29.s64 + 436;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E77A8;
	sub_821C8FE0(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x823da950
	ctx.lr = 0x824E77B8;
	sub_823DA950(ctx, base);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x824ea350
	ctx.lr = 0x824E77C8;
	sub_824EA350(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824e77d4
	if (!cr6.eq) goto loc_824E77D4;
	// addi r30,r31,628
	r30.s64 = r31.s64 + 628;
loc_824E77D4:
	// stw r30,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E77E8;
	sub_821CE080(ctx, base);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// bl 0x824e6a10
	ctx.lr = 0x824E77F4;
	sub_824E6A10(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821c9030
	ctx.lr = 0x824E7800;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_824E780C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e783c
	if (cr6.eq) goto loc_824E783C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E7820;
	sub_821CE080(ctx, base);
	// stw r25,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r25.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7834;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824E783C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824E7848"))) PPC_WEAK_FUNC(sub_824E7848);
PPC_FUNC_IMPL(__imp__sub_824E7848) {
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
	ctx.lr = 0x824E7850;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x821f8730
	ctx.lr = 0x824E7864;
	sub_821F8730(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E7870;
	sub_824E8E58(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e7890
	if (!cr6.gt) goto loc_824E7890;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e9240
	ctx.lr = 0x824E7888;
	sub_824E9240(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824e7894
	goto loc_824E7894;
loc_824E7890:
	// li r31,1
	r31.s64 = 1;
loc_824E7894:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7920
	if (cr6.eq) goto loc_824E7920;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824E78B4:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824e78b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824E78B4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8244ee40
	ctx.lr = 0x824E78D4;
	sub_8244EE40(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// ori r4,r4,32769
	ctx.r4.u64 = ctx.r4.u64 | 32769;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824574c8
	ctx.lr = 0x824E78F0;
	sub_824574C8(ctx, base);
	// cmplwi cr6,r3,997
	cr6.compare<uint32_t>(ctx.r3.u32, 997, xer);
	// bne cr6,0x824e7904
	if (!cr6.eq) goto loc_824E7904;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82135db8
	ctx.lr = 0x824E7904;
	sub_82135DB8(ctx, base);
loc_824E7904:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x8244eee0
	ctx.lr = 0x824E790C;
	sub_8244EEE0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82450030
	ctx.lr = 0x824E7914;
	sub_82450030(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x824e7924
	if (!cr6.eq) goto loc_824E7924;
loc_824E7920:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E7924:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E792C"))) PPC_WEAK_FUNC(sub_824E792C);
PPC_FUNC_IMPL(__imp__sub_824E792C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7930"))) PPC_WEAK_FUNC(sub_824E7930);
PPC_FUNC_IMPL(__imp__sub_824E7930) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824e7974
	if (!cr6.eq) goto loc_824E7974;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7968
	if (cr6.eq) goto loc_824E7968;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824e79ac
	if (!cr6.eq) goto loc_824E79AC;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7968:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7974:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824e7994
	if (!cr6.eq) goto loc_824E7994;
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824e79ac
	goto loc_824E79AC;
loc_824E7994:
	// stw r5,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r5.u32);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r11,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r11.u32);
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r6,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r6.u32);
loc_824E79AC:
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

__attribute__((alias("__imp__sub_824E79C4"))) PPC_WEAK_FUNC(sub_824E79C4);
PPC_FUNC_IMPL(__imp__sub_824E79C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E79C8"))) PPC_WEAK_FUNC(sub_824E79C8);
PPC_FUNC_IMPL(__imp__sub_824E79C8) {
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
	// addi r9,r11,26136
	ctx.r9.s64 = r11.s64 + 26136;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824e79fc
	if (cr6.eq) goto loc_824E79FC;
	// bl 0x82130588
	ctx.lr = 0x824E79F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E79FC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824E7A10"))) PPC_WEAK_FUNC(sub_824E7A10);
PPC_FUNC_IMPL(__imp__sub_824E7A10) {
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
	// bl 0x824e6b58
	ctx.lr = 0x824E7A30;
	sub_824E6B58(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7a48
	if (cr6.eq) goto loc_824E7A48;
	// bl 0x82130588
	ctx.lr = 0x824E7A44;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E7A48:
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

__attribute__((alias("__imp__sub_824E7A60"))) PPC_WEAK_FUNC(sub_824E7A60);
PPC_FUNC_IMPL(__imp__sub_824E7A60) {
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
	ctx.lr = 0x824E7A68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r25
	r29.u64 = r25.u64;
	// li r28,1
	r28.s64 = 1;
	// li r26,-1
	r26.s64 = -1;
	// li r27,2
	r27.s64 = 2;
loc_824E7A84:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r31,r11,472
	r31.s64 = r11.s64 + 472;
	// lwz r11,472(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7b08
	if (!cr6.eq) goto loc_824E7B08;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addi r6,r31,108
	ctx.r6.s64 = r31.s64 + 108;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// bl 0x824e7848
	ctx.lr = 0x824E7AB4;
	sub_824E7848(ctx, base);
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r4,r11,436
	ctx.r4.s64 = r11.s64 + 436;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824E7AC8;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r24,624(r31)
	r24.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// beq cr6,0x824e7af0
	if (cr6.eq) goto loc_824E7AF0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7AE8;
	sub_821CE0A0(ctx, base);
	// stw r25,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r25.u32);
	// b 0x824e7afc
	goto loc_824E7AFC;
loc_824E7AF0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7AF8;
	sub_821CE0A0(ctx, base);
	// stw r26,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r26.u32);
loc_824E7AFC:
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824E7B08;
	sub_821C9030(ctx, base);
loc_824E7B08:
	// addi r29,r29,640
	r29.s64 = r29.s64 + 640;
	// cmpwi cr6,r29,2560
	cr6.compare<int32_t>(r29.s32, 2560, xer);
	// blt cr6,0x824e7a84
	if (cr6.lt) goto loc_824E7A84;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824E7B1C"))) PPC_WEAK_FUNC(sub_824E7B1C);
PPC_FUNC_IMPL(__imp__sub_824E7B1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7B20"))) PPC_WEAK_FUNC(sub_824E7B20);
PPC_FUNC_IMPL(__imp__sub_824E7B20) {
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
	ctx.lr = 0x824E7B28;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// li r26,0
	r26.s64 = 0;
	// bl 0x824e70e0
	ctx.lr = 0x824E7B4C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7b8c
	if (cr6.eq) goto loc_824E7B8C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7008
	ctx.lr = 0x824E7B60;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7b8c
	if (cr6.eq) goto loc_824E7B8C;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7750
	ctx.lr = 0x824E7B84;
	sub_824E7750(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_824E7B8C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e7bbc
	if (cr6.eq) goto loc_824E7BBC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824E7BA0;
	sub_821CE080(ctx, base);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7BB4;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824E7BBC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E7BC8"))) PPC_WEAK_FUNC(sub_824E7BC8);
PPC_FUNC_IMPL(__imp__sub_824E7BC8) {
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
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,30144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30144);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824e7c28
	if (!cr6.eq) goto loc_824E7C28;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// stw r11,30144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30144, r11.u32);
	// addi r31,r9,30120
	r31.s64 = ctx.r9.s64 + 30120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824fa970
	ctx.lr = 0x824E7C04;
	sub_824FA970(ctx, base);
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// addi r3,r8,-19424
	ctx.r3.s64 = ctx.r8.s64 + -19424;
	// bl 0x823d9a98
	ctx.lr = 0x824E7C10;
	sub_823D9A98(ctx, base);
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
loc_824E7C28:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,30120
	ctx.r3.s64 = r11.s64 + 30120;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824E7C44"))) PPC_WEAK_FUNC(sub_824E7C44);
PPC_FUNC_IMPL(__imp__sub_824E7C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7C48"))) PPC_WEAK_FUNC(sub_824E7C48);
PPC_FUNC_IMPL(__imp__sub_824E7C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7c70
	if (cr6.eq) goto loc_824E7C70;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
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
loc_824E7C70:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7c90
	if (cr6.eq) goto loc_824E7C90;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824e7c94
	if (!cr6.eq) goto loc_824E7C94;
loc_824E7C90:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824E7C94:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7cb0
	if (cr6.eq) goto loc_824E7CB0;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824E7CB0:
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

__attribute__((alias("__imp__sub_824E7CC4"))) PPC_WEAK_FUNC(sub_824E7CC4);
PPC_FUNC_IMPL(__imp__sub_824E7CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7CC8"))) PPC_WEAK_FUNC(sub_824E7CC8);
PPC_FUNC_IMPL(__imp__sub_824E7CC8) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7d08
	if (cr6.eq) goto loc_824E7D08;
loc_824E7CE8:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824e7cfc
	if (cr6.eq) goto loc_824E7CFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824E7CFC;
	sub_825D7AA0(ctx, base);
loc_824E7CFC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7ce8
	if (!cr6.eq) goto loc_824E7CE8;
loc_824E7D08:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824E7D1C"))) PPC_WEAK_FUNC(sub_824E7D1C);
PPC_FUNC_IMPL(__imp__sub_824E7D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7D20"))) PPC_WEAK_FUNC(sub_824E7D20);
PPC_FUNC_IMPL(__imp__sub_824E7D20) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7da0
	if (cr6.eq) goto loc_824E7DA0;
loc_824E7D44:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// beq cr6,0x824e7d94
	if (cr6.eq) goto loc_824E7D94;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7D64;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7d94
	if (cr6.eq) goto loc_824E7D94;
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x824e7d94
	if (!cr6.eq) goto loc_824E7D94;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7d88
	if (cr6.eq) goto loc_824E7D88;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82278948
	ctx.lr = 0x824E7D88;
	sub_82278948(ctx, base);
loc_824E7D88:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824E7D94;
	sub_825D7AA0(ctx, base);
loc_824E7D94:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e7d44
	if (!cr6.eq) goto loc_824E7D44;
loc_824E7DA0:
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

__attribute__((alias("__imp__sub_824E7DB8"))) PPC_WEAK_FUNC(sub_824E7DB8);
PPC_FUNC_IMPL(__imp__sub_824E7DB8) {
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
	ctx.lr = 0x824E7DC0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
	// stb r4,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r4.u8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r3.u64);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// std r6,108(r1)
	PPC_STORE_U64(ctx.r1.u32 + 108, ctx.r6.u64);
	// beq cr6,0x824e7edc
	if (cr6.eq) goto loc_824E7EDC;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_824E7E20:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7e44
	if (cr6.eq) goto loc_824E7E44;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824E7E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824e7e54
	goto loc_824E7E54;
loc_824E7E44:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824E7E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824E7E54:
	// lbz r11,116(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7ec0
	if (cr6.eq) goto loc_824E7EC0;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e7e7c
	if (cr6.eq) goto loc_824E7E7C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x824e7ed0
	goto loc_824E7ED0;
loc_824E7E7C:
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// rlwinm r10,r9,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7e9c
	if (cr6.eq) goto loc_824E7E9C;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824e7ea0
	if (!cr6.eq) goto loc_824E7EA0;
loc_824E7E9C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824E7EA0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7ed0
	if (cr6.eq) goto loc_824E7ED0;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// b 0x824e7ed0
	goto loc_824E7ED0;
loc_824E7EC0:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r9.u8);
loc_824E7ED0:
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824e7e20
	if (!cr6.eq) goto loc_824E7E20;
loc_824E7EDC:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E7EF0"))) PPC_WEAK_FUNC(sub_824E7EF0);
PPC_FUNC_IMPL(__imp__sub_824E7EF0) {
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
	ctx.lr = 0x824E7EF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e7f7c
	if (cr6.eq) goto loc_824E7F7C;
	// lwz r11,3032(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3032);
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824E7F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 432);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e7f3c
	if (cr6.eq) goto loc_824E7F3C;
	// bl 0x8275cc90
	ctx.lr = 0x824E7F38;
	sub_8275CC90(ctx, base);
	// stw r28,432(r29)
	PPC_STORE_U32(r29.u32 + 432, r28.u32);
loc_824E7F3C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7d20
	ctx.lr = 0x824E7F44;
	sub_824E7D20(ctx, base);
	// addi r31,r29,116
	r31.s64 = r29.s64 + 116;
	// li r30,4
	r30.s64 = 4;
loc_824E7F4C:
	// addi r3,r31,-100
	ctx.r3.s64 = r31.s64 + -100;
	// bl 0x824e6f20
	ctx.lr = 0x824E7F54;
	sub_824E6F20(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stw r28,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r28.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bne 0x824e7f4c
	if (!cr0.eq) goto loc_824E7F4C;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r10.u8);
loc_824E7F7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E7F84"))) PPC_WEAK_FUNC(sub_824E7F84);
PPC_FUNC_IMPL(__imp__sub_824E7F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7F88"))) PPC_WEAK_FUNC(sub_824E7F88);
PPC_FUNC_IMPL(__imp__sub_824E7F88) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x821ce0a0
	ctx.lr = 0x824E7FB4;
	sub_821CE0A0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e7fd0
	if (!cr6.eq) goto loc_824E7FD0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e7930
	ctx.lr = 0x824E7FD0;
	sub_824E7930(ctx, base);
loc_824E7FD0:
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

__attribute__((alias("__imp__sub_824E7FE8"))) PPC_WEAK_FUNC(sub_824E7FE8);
PPC_FUNC_IMPL(__imp__sub_824E7FE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82279e20
	sub_82279E20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E7FEC"))) PPC_WEAK_FUNC(sub_824E7FEC);
PPC_FUNC_IMPL(__imp__sub_824E7FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E7FF0"))) PPC_WEAK_FUNC(sub_824E7FF0);
PPC_FUNC_IMPL(__imp__sub_824E7FF0) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824E7FF8;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mulli r11,r31,104
	r11.s64 = r31.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// bl 0x824e6cd8
	ctx.lr = 0x824E8018;
	sub_824E6CD8(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6d08
	ctx.lr = 0x824E8024;
	sub_824E6D08(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6d08
	ctx.lr = 0x824E8030;
	sub_824E6D08(ctx, base);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E803C;
	sub_824E70E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x824E8048;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r22,r30,24
	r22.u64 = r30.u32 & 0xFF;
	// clrlwi r23,r19,24
	r23.u64 = r19.u32 & 0xFF;
	// clrlwi r26,r18,24
	r26.u64 = r18.u32 & 0xFF;
	// subf r10,r23,r22
	ctx.r10.s64 = r22.s64 - r23.s64;
	// subf r9,r26,r11
	ctx.r9.s64 = r11.s64 - r26.s64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// xori r30,r6,1
	r30.u64 = ctx.r6.u64 ^ 1;
	// xori r24,r5,1
	r24.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r25,r17,24
	r25.u64 = r17.u32 & 0xFF;
	// bl 0x824e7100
	ctx.lr = 0x824E8084;
	sub_824E7100(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// subf r10,r25,r4
	ctx.r10.s64 = ctx.r4.s64 - r25.s64;
	// rlwinm r20,r11,28,31,31
	r20.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r21,r8,1
	r21.u64 = ctx.r8.u64 ^ 1;
	// bl 0x824f9438
	ctx.lr = 0x824E80A8;
	sub_824F9438(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f93b8
	ctx.lr = 0x824E80B4;
	sub_824F93B8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824e80c8
	if (!cr6.eq) goto loc_824E80C8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f9230
	ctx.lr = 0x824E80C8;
	sub_824F9230(ctx, base);
loc_824E80C8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// bl 0x824e7110
	ctx.lr = 0x824E80D4;
	sub_824E7110(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824f9388
	ctx.lr = 0x824E80DC;
	sub_824F9388(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E80F0;
	sub_823DA950(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e71c8
	ctx.lr = 0x824E80F8;
	sub_824E71C8(ctx, base);
	// clrlwi r27,r30,24
	r27.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8134
	if (!cr6.eq) goto loc_824E8134;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8188
	if (cr6.eq) goto loc_824E8188;
loc_824E8134:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7250
	ctx.lr = 0x824E8140;
	sub_824E7250(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e817c
	if (!cr6.eq) goto loc_824E817C;
	// bl 0x824e6f20
	ctx.lr = 0x824E8154;
	sub_824E6F20(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,1088
	ctx.r4.s64 = ctx.r1.s64 + 1088;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8164;
	sub_823DA950(ctx, base);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x824f9230
	ctx.lr = 0x824E816C;
	sub_824F9230(ctx, base);
	// lbz r11,204(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 204);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r10,204(r1)
	PPC_STORE_U8(ctx.r1.u32 + 204, ctx.r10.u8);
	// b 0x824e8188
	goto loc_824E8188;
loc_824E817C:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8188;
	sub_823DA950(ctx, base);
loc_824E8188:
	// li r16,0
	r16.s64 = 0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r15,r16
	r15.u64 = r16.u64;
	// stb r16,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r16.u8);
	// stb r16,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r16.u8);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stb r16,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r16.u8);
	// addi r30,r11,26136
	r30.s64 = r11.s64 + 26136;
	// stb r16,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r16.u8);
	// bne cr6,0x824e81dc
	if (!cr6.eq) goto loc_824E81DC;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e81d4
	if (!cr6.eq) goto loc_824E81D4;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e81d4
	if (!cr6.eq) goto loc_824E81D4;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e828c
	if (cr6.eq) goto loc_824E828C;
loc_824E81D4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e81f4
	if (cr6.eq) goto loc_824E81F4;
loc_824E81DC:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e81ec
	if (cr6.eq) goto loc_824E81EC;
	// li r15,1
	r15.s64 = 1;
	// b 0x824e81f4
	goto loc_824E81F4;
loc_824E81EC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r11.u8);
loc_824E81F4:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8218
	if (cr6.eq) goto loc_824E8218;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e8214
	if (cr6.eq) goto loc_824E8214;
	// li r11,1
	r11.s64 = 1;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x824e8218
	goto loc_824E8218;
loc_824E8214:
	// li r16,1
	r16.s64 = 1;
loc_824E8218:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e823c
	if (cr6.eq) goto loc_824E823C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824e8238
	if (cr6.eq) goto loc_824E8238;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// b 0x824e823c
	goto loc_824E823C;
loc_824E8238:
	// stb r11,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r11.u8);
loc_824E823C:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e828c
	if (cr6.eq) goto loc_824E828C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E8264;
	sub_823DA950(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r1,976
	ctx.r10.s64 = ctx.r1.s64 + 976;
	// addi r9,r11,26172
	ctx.r9.s64 = r11.s64 + 26172;
	// stw r10,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r10.u32);
	// addi r5,r1,976
	ctx.r5.s64 = ctx.r1.s64 + 976;
	// stw r9,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8288;
	sub_824E7DB8(ctx, base);
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
loc_824E828C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e7118
	ctx.lr = 0x824E82B0;
	sub_824E7118(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// bl 0x824e7118
	ctx.lr = 0x824E82BC;
	sub_824E7118(ctx, base);
loc_824E82BC:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x824e82e0
	if (cr6.eq) goto loc_824E82E0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e82bc
	if (cr6.eq) goto loc_824E82BC;
loc_824E82E0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e82f4
	if (cr6.eq) goto loc_824E82F4;
	// mr r15,r19
	r15.u64 = r19.u64;
	// stb r18,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r18.u8);
	// stb r17,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r17.u8);
loc_824E82F4:
	// clrlwi r10,r16,24
	ctx.r10.u64 = r16.u32 & 0xFF;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r31,r11,26160
	r31.s64 = r11.s64 + 26160;
	// beq cr6,0x824e8354
	if (cr6.eq) goto loc_824E8354;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E831C;
	sub_823DA950(ctx, base);
	// lbz r8,708(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 708);
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r31,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r31.u32);
	// rlwimi r8,r11,4,20,24
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xF80) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF07F);
	// stw r10,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r10.u32);
	// stw r9,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r9.u32);
	// addi r5,r1,592
	ctx.r5.s64 = ctx.r1.s64 + 592;
	// stb r8,708(r1)
	PPC_STORE_U8(ctx.r1.u32 + 708, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8350;
	sub_824E7DB8(ctx, base);
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
loc_824E8354:
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e83ac
	if (cr6.eq) goto loc_824E83AC;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8374;
	sub_823DA950(ctx, base);
	// lbz r8,324(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 324);
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// li r9,5
	ctx.r9.s64 = 5;
	// stw r31,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r31.u32);
	// rlwimi r8,r11,4,20,24
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xF80) | (ctx.r8.u64 & 0xFFFFFFFFFFFFF07F);
	// stw r10,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r10.u32);
	// stw r9,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r9.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stb r8,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E83A8;
	sub_824E7DB8(ctx, base);
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
loc_824E83AC:
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8400
	if (cr6.eq) goto loc_824E8400;
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E83CC;
	sub_823DA950(ctx, base);
	// lbz r9,580(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 580);
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// stw r31,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, r11.u32);
	// stw r10,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r10.u32);
	// addi r5,r1,464
	ctx.r5.s64 = ctx.r1.s64 + 464;
	// stb r8,580(r1)
	PPC_STORE_U8(ctx.r1.u32 + 580, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E83FC;
	sub_824E7DB8(ctx, base);
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
loc_824E8400:
	// clrlwi r11,r15,24
	r11.u64 = r15.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8454
	if (cr6.eq) goto loc_824E8454;
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8420;
	sub_823DA950(ctx, base);
	// lbz r9,836(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 836);
	// addi r11,r1,720
	r11.s64 = ctx.r1.s64 + 720;
	// stw r31,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, r11.u32);
	// stw r10,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r10.u32);
	// addi r5,r1,720
	ctx.r5.s64 = ctx.r1.s64 + 720;
	// stb r8,836(r1)
	PPC_STORE_U8(ctx.r1.u32 + 836, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8450;
	sub_824E7DB8(ctx, base);
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
loc_824E8454:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e84a8
	if (cr6.eq) goto loc_824E84A8;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E8474;
	sub_823DA950(ctx, base);
	// lbz r9,452(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 452);
	// addi r11,r1,336
	r11.s64 = ctx.r1.s64 + 336;
	// stw r31,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r31.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r11.u32);
	// stw r10,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stb r8,452(r1)
	PPC_STORE_U8(ctx.r1.u32 + 452, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E84A4;
	sub_824E7DB8(ctx, base);
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
loc_824E84A8:
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e84f8
	if (cr6.eq) goto loc_824E84F8;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// stw r30,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824E84C8;
	sub_823DA950(ctx, base);
	// lbz r9,964(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 964);
	// addi r11,r1,848
	r11.s64 = ctx.r1.s64 + 848;
	// stw r31,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r31.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// clrlwi r8,r9,25
	ctx.r8.u64 = ctx.r9.u32 & 0x7F;
	// stw r11,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, r11.u32);
	// stw r10,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r10.u32);
	// addi r5,r1,848
	ctx.r5.s64 = ctx.r1.s64 + 848;
	// stb r8,964(r1)
	PPC_STORE_U8(ctx.r1.u32 + 964, ctx.r8.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E84F8;
	sub_824E7DB8(ctx, base);
loc_824E84F8:
	// lbz r11,100(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 100);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stb r10,100(r29)
	PPC_STORE_U8(r29.u32 + 100, ctx.r10.u8);
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824E8510"))) PPC_WEAK_FUNC(sub_824E8510);
PPC_FUNC_IMPL(__imp__sub_824E8510) {
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
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r10,104
	r11.s64 = ctx.r10.s64 * 104;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// bl 0x8244a9c0
	ctx.lr = 0x824E8544;
	sub_8244A9C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824e864c
	if (!cr6.eq) goto loc_824E864C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7110
	ctx.lr = 0x824E8554;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x824E8558;
	sub_824F92F0(ctx, base);
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// cmpld cr6,r3,r11
	cr6.compare<uint64_t>(ctx.r3.u64, r11.u64, xer);
	// bne cr6,0x824e864c
	if (!cr6.eq) goto loc_824E864C;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x824e6400
	ctx.lr = 0x824E856C;
	sub_824E6400(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E857C;
	sub_823DA950(ctx, base);
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824e85fc
	if (cr6.eq) goto loc_824E85FC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f9438
	ctx.lr = 0x824E8590;
	sub_824F9438(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// bl 0x824f92a0
	ctx.lr = 0x824E859C;
	sub_824F92A0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E85B8;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// addi r7,r9,26196
	ctx.r7.s64 = ctx.r9.s64 + 26196;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// stw r8,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r8.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stw r7,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r7.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E85DC;
	sub_823DA950(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,432
	r11.s64 = ctx.r1.s64 + 432;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// ld r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// ld r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// std r9,8(r11)
	PPC_STORE_U64(r11.u32 + 8, ctx.r9.u64);
	// b 0x824e8640
	goto loc_824E8640;
loc_824E85FC:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r10,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E8618;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,448
	ctx.r8.s64 = ctx.r1.s64 + 448;
	// addi r7,r9,26208
	ctx.r7.s64 = ctx.r9.s64 + 26208;
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// stw r8,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r8.u32);
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// stw r7,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r7.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824E863C;
	sub_823DA950(ctx, base);
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
loc_824E8640:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E864C;
	sub_824E7DB8(ctx, base);
loc_824E864C:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
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

__attribute__((alias("__imp__sub_824E8664"))) PPC_WEAK_FUNC(sub_824E8664);
PPC_FUNC_IMPL(__imp__sub_824E8664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8668"))) PPC_WEAK_FUNC(sub_824E8668);
PPC_FUNC_IMPL(__imp__sub_824E8668) {
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
	ctx.lr = 0x824E8670;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mulli r11,r4,104
	r11.s64 = ctx.r4.s64 * 104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r10,r11,26136
	ctx.r10.s64 = r11.s64 + 26136;
	// beq cr6,0x824e86fc
	if (cr6.eq) goto loc_824E86FC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E86AC;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r9,26196
	ctx.r7.s64 = ctx.r9.s64 + 26196;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E86D0;
	sub_823DA950(ctx, base);
	// ld r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// ld r11,8(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 8);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r6,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r6.u64);
	// std r11,8(r10)
	PPC_STORE_U64(ctx.r10.u32 + 8, r11.u64);
	// bl 0x824e7db8
	ctx.lr = 0x824E86F4;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
loc_824E86FC:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stw r10,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r10.u32);
	// bl 0x823da950
	ctx.lr = 0x824E8708;
	sub_823DA950(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// addi r7,r9,26208
	ctx.r7.s64 = ctx.r9.s64 + 26208;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// stw r8,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r8.u32);
	// li r5,60
	ctx.r5.s64 = 60;
	// stw r7,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r7.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824E872C;
	sub_823DA950(ctx, base);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E873C;
	sub_824E7DB8(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E8744"))) PPC_WEAK_FUNC(sub_824E8744);
PPC_FUNC_IMPL(__imp__sub_824E8744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8748"))) PPC_WEAK_FUNC(sub_824E8748);
PPC_FUNC_IMPL(__imp__sub_824E8748) {
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
	// addi r10,r11,26268
	ctx.r10.s64 = r11.s64 + 26268;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824e7bc8
	ctx.lr = 0x824E8774;
	sub_824E7BC8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824fa710
	ctx.lr = 0x824E877C;
	sub_824FA710(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-1028
	ctx.r7.s64 = ctx.r9.s64 + -1028;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824e87a0
	if (cr6.eq) goto loc_824E87A0;
	// bl 0x82130588
	ctx.lr = 0x824E879C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E87A0:
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

__attribute__((alias("__imp__sub_824E87B8"))) PPC_WEAK_FUNC(sub_824E87B8);
PPC_FUNC_IMPL(__imp__sub_824E87B8) {
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
	// bl 0x824e7ef0
	ctx.lr = 0x824E87D0;
	sub_824E7EF0(ctx, base);
	// addi r3,r31,3032
	ctx.r3.s64 = r31.s64 + 3032;
	// bl 0x824e6b58
	ctx.lr = 0x824E87D8;
	sub_824E6B58(ctx, base);
	// addi r3,r31,436
	ctx.r3.s64 = r31.s64 + 436;
	// bl 0x82130000
	ctx.lr = 0x824E87E0;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7d20
	ctx.lr = 0x824E87E8;
	sub_824E7D20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e7cc8
	ctx.lr = 0x824E87F0;
	sub_824E7CC8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824E8804"))) PPC_WEAK_FUNC(sub_824E8804);
PPC_FUNC_IMPL(__imp__sub_824E8804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8808"))) PPC_WEAK_FUNC(sub_824E8808);
PPC_FUNC_IMPL(__imp__sub_824E8808) {
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
	ctx.lr = 0x824E8810;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r31,r28
	r31.u64 = r28.u64;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e8894
	if (!cr6.eq) goto loc_824E8894;
	// bl 0x824e76a0
	ctx.lr = 0x824E8834;
	sub_824E76A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8894
	if (cr6.eq) goto loc_824E8894;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r31,r29,116
	r31.s64 = r29.s64 + 116;
loc_824E8848:
	// addi r3,r31,-100
	ctx.r3.s64 = r31.s64 + -100;
	// bl 0x824e6f20
	ctx.lr = 0x824E8850;
	sub_824E6F20(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stw r28,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, r28.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// bl 0x824e7ff0
	ctx.lr = 0x824E886C;
	sub_824E7FF0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x824e8848
	if (cr6.lt) goto loc_824E8848;
	// lbz r11,3088(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E8894:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E88A0"))) PPC_WEAK_FUNC(sub_824E88A0);
PPC_FUNC_IMPL(__imp__sub_824E88A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824E88A8;
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,432(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 432);
	// bl 0x827bd054
	ctx.lr = 0x824E88C4;
	__imp__XNotifyGetNext(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r18,r11,26136
	r18.s64 = r11.s64 + 26136;
	// beq cr6,0x824e8b78
	if (cr6.eq) goto loc_824E8B78;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// lis r9,512
	ctx.r9.s64 = 33554432;
	// lis r8,-32747
	ctx.r8.s64 = -2146107392;
	// lis r7,512
	ctx.r7.s64 = 33554432;
	// lis r6,1024
	ctx.r6.s64 = 67108864;
	// ori r23,r10,2
	r23.u64 = ctx.r10.u64 | 2;
	// ori r20,r9,1
	r20.u64 = ctx.r9.u64 | 1;
	// ori r17,r8,4101
	r17.u64 = ctx.r8.u64 | 4101;
	// li r25,1
	r25.s64 = 1;
	// ori r21,r7,7
	r21.u64 = ctx.r7.u64 | 7;
	// addi r24,r11,26148
	r24.s64 = r11.s64 + 26148;
	// lis r19,1024
	r19.s64 = 67108864;
	// ori r22,r6,3
	r22.u64 = ctx.r6.u64 | 3;
loc_824E890C:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r23
	cr6.compare<uint32_t>(r11.u32, r23.u32, xer);
	// bgt cr6,0x824e8ae4
	if (cr6.gt) goto loc_824E8AE4;
	// beq cr6,0x824e8ac4
	if (cr6.eq) goto loc_824E8AC4;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x824e89ec
	if (cr6.eq) goto loc_824E89EC;
	// cmplwi cr6,r11,14
	cr6.compare<uint32_t>(r11.u32, 14, xer);
	// beq cr6,0x824e8974
	if (cr6.eq) goto loc_824E8974;
	// cmplw cr6,r11,r20
	cr6.compare<uint32_t>(r11.u32, r20.u32, xer);
	// bne cr6,0x824e8b5c
	if (!cr6.eq) goto loc_824E8B5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r17
	cr6.compare<uint32_t>(r11.u32, r17.u32, xer);
	// bne cr6,0x824e8b5c
	if (!cr6.eq) goto loc_824E8B5C;
	// lbz r11,116(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 116);
	// lbz r10,220(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 220);
	// lbz r9,324(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 324);
	// ori r8,r11,136
	ctx.r8.u64 = r11.u64 | 136;
	// lbz r7,428(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 428);
	// ori r6,r10,136
	ctx.r6.u64 = ctx.r10.u64 | 136;
	// ori r5,r9,136
	ctx.r5.u64 = ctx.r9.u64 | 136;
	// stb r8,116(r28)
	PPC_STORE_U8(r28.u32 + 116, ctx.r8.u8);
	// ori r4,r7,136
	ctx.r4.u64 = ctx.r7.u64 | 136;
	// stb r6,220(r28)
	PPC_STORE_U8(r28.u32 + 220, ctx.r6.u8);
	// stb r5,324(r28)
	PPC_STORE_U8(r28.u32 + 324, ctx.r5.u8);
	// stb r4,428(r28)
	PPC_STORE_U8(r28.u32 + 428, ctx.r4.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8974:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8994
	if (cr6.eq) goto loc_824E8994;
	// lbz r9,116(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 116);
	// addi r11,r28,16
	r11.s64 = r28.s64 + 16;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,116(r28)
	PPC_STORE_U8(r28.u32 + 116, ctx.r8.u8);
loc_824E8994:
	// rlwinm r11,r10,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e89b0
	if (cr6.eq) goto loc_824E89B0;
	// lbz r9,220(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 220);
	// addi r11,r28,120
	r11.s64 = r28.s64 + 120;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,220(r28)
	PPC_STORE_U8(r28.u32 + 220, ctx.r8.u8);
loc_824E89B0:
	// rlwinm r11,r10,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e89cc
	if (cr6.eq) goto loc_824E89CC;
	// lbz r9,324(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 324);
	// addi r11,r28,224
	r11.s64 = r28.s64 + 224;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stb r8,324(r28)
	PPC_STORE_U8(r28.u32 + 324, ctx.r8.u8);
loc_824E89CC:
	// rlwinm r11,r10,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8b5c
	if (cr6.eq) goto loc_824E8B5C;
	// lbz r10,428(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 428);
	// addi r11,r28,328
	r11.s64 = r28.s64 + 328;
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,428(r28)
	PPC_STORE_U8(r28.u32 + 428, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E89EC:
	// li r27,0
	r27.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r25
	r29.u64 = r25.u64;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
loc_824E8A00:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// and r10,r29,r11
	ctx.r10.u64 = r29.u64 & r11.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8a3c
	if (cr6.eq) goto loc_824E8A3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E8A18;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8a3c
	if (cr6.eq) goto loc_824E8A3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x824E8A2C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e8a3c
	if (!cr6.eq) goto loc_824E8A3C;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_824E8A3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824575f8
	ctx.lr = 0x824E8A44;
	sub_824575F8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824e8a50
	if (cr6.eq) goto loc_824E8A50;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_824E8A50:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,104
	r30.s64 = r30.s64 + 104;
	// rotlwi r29,r29,1
	r29.u64 = __builtin_rotateleft32(r29.u32, 1);
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x824e8a00
	if (cr6.lt) goto loc_824E8A00;
	// addi r31,r28,112
	r31.s64 = r28.s64 + 112;
	// li r30,4
	r30.s64 = 4;
loc_824E8A6C:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8a88
	if (cr6.eq) goto loc_824E8A88;
	// bl 0x821c9788
	ctx.lr = 0x824E8A80;
	sub_821C9788(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x824e8ab4
	goto loc_824E8AB4;
loc_824E8A88:
	// rlwimi r11,r25,7,0,24
	r11.u64 = (__builtin_rotateleft32(r25.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x821c9788
	ctx.lr = 0x824E8A94;
	sub_821C9788(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8ab4
	if (cr6.eq) goto loc_824E8AB4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x824e8ab4
	if (!cr6.eq) goto loc_824E8AB4;
	// addi r11,r3,1500
	r11.s64 = ctx.r3.s64 + 1500;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_824E8AB4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bne 0x824e8a6c
	if (!cr0.eq) goto loc_824E8A6C;
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8AC4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lbz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 116);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,116(r11)
	PPC_STORE_U8(r11.u32 + 116, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8AE4:
	// cmplw cr6,r11,r21
	cr6.compare<uint32_t>(r11.u32, r21.u32, xer);
	// beq cr6,0x824e8b1c
	if (cr6.eq) goto loc_824E8B1C;
	// cmplw cr6,r11,r19
	cr6.compare<uint32_t>(r11.u32, r19.u32, xer);
	// ble cr6,0x824e8b5c
	if (!cr6.gt) goto loc_824E8B5C;
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// bgt cr6,0x824e8b5c
	if (cr6.gt) goto loc_824E8B5C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lbz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 116);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,116(r11)
	PPC_STORE_U8(r11.u32 + 116, ctx.r9.u8);
	// b 0x824e8b5c
	goto loc_824E8B5C;
loc_824E8B1C:
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,96
	ctx.r5.s64 = 96;
	// mulli r11,r11,104
	r11.s64 = r11.s64 * 104;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x823da950
	ctx.lr = 0x824E8B3C;
	sub_823DA950(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8B58;
	sub_824E7DB8(ctx, base);
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
loc_824E8B5C:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,432(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 432);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd054
	ctx.lr = 0x824E8B70;
	__imp__XNotifyGetNext(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824e890c
	if (!cr6.eq) goto loc_824E890C;
loc_824E8B78:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r29,0
	r29.s64 = 0;
	// addi r31,r28,116
	r31.s64 = r28.s64 + 116;
	// addi r27,r11,26184
	r27.s64 = r11.s64 + 26184;
loc_824E8B88:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8bc0
	if (cr6.eq) goto loc_824E8BC0;
	// bl 0x821c9788
	ctx.lr = 0x824E8B9C;
	sub_821C9788(ctx, base);
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// subf. r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x824e8bc0
	if (cr0.lt) goto loc_824E8BC0;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
	// bl 0x824e7ff0
	ctx.lr = 0x824E8BC0;
	sub_824E7FF0(ctx, base);
loc_824E8BC0:
	// addi r30,r31,-100
	r30.s64 = r31.s64 + -100;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x824E8BCC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e8c7c
	if (cr6.eq) goto loc_824E8C7C;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c28
	if (cr6.eq) goto loc_824E8C28;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stw r18,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r18.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// rlwinm r11,r11,0,26,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// li r5,96
	ctx.r5.s64 = 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x823da950
	ctx.lr = 0x824E8C08;
	sub_823DA950(ctx, base);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stw r27,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r27.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stw r10,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7db8
	ctx.lr = 0x824E8C24;
	sub_824E7DB8(ctx, base);
	// stw r18,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r18.u32);
loc_824E8C28:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c50
	if (cr6.eq) goto loc_824E8C50;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r11,r11,0,27,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// bl 0x824e8510
	ctx.lr = 0x824E8C50;
	sub_824E8510(ctx, base);
loc_824E8C50:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824e8c7c
	if (cr6.eq) goto loc_824E8C7C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e7ff0
	ctx.lr = 0x824E8C6C;
	sub_824E7FF0(ctx, base);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r10.u8);
loc_824E8C7C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x824e8b88
	if (cr6.lt) goto loc_824E8B88;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_824E8C94"))) PPC_WEAK_FUNC(sub_824E8C94);
PPC_FUNC_IMPL(__imp__sub_824E8C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8C98"))) PPC_WEAK_FUNC(sub_824E8C98);
PPC_FUNC_IMPL(__imp__sub_824E8C98) {
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
	ctx.lr = 0x824E8CA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r29,16
	r31.s64 = r29.s64 + 16;
	// li r28,3
	r28.s64 = 3;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// stw r30,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r30.u32);
loc_824E8CC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824E8CCC;
	sub_824E71C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6f20
	ctx.lr = 0x824E8CD4;
	sub_824E6F20(ctx, base);
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// clrlwi r10,r11,29
	ctx.r10.u64 = r11.u32 & 0x7;
	// stb r10,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r10.u8);
	// addi r31,r31,104
	r31.s64 = r31.s64 + 104;
	// bge 0x824e8cc4
	if (!cr0.lt) goto loc_824E8CC4;
	// addi r3,r29,436
	ctx.r3.s64 = r29.s64 + 436;
	// bl 0x821c8ed8
	ctx.lr = 0x824E8CF8;
	sub_821C8ED8(ctx, base);
	// addi r31,r29,472
	r31.s64 = r29.s64 + 472;
	// li r28,3
	r28.s64 = 3;
	// li r26,2
	r26.s64 = 2;
	// li r27,-1
	r27.s64 = -1;
loc_824E8D08:
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824e71c8
	ctx.lr = 0x824E8D14;
	sub_824E71C8(ctx, base);
	// stw r27,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r27.u32);
	// addi r3,r31,108
	ctx.r3.s64 = r31.s64 + 108;
	// bl 0x824e8de8
	ctx.lr = 0x824E8D20;
	sub_824E8DE8(ctx, base);
	// stw r30,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r30.u32);
	// stw r30,628(r31)
	PPC_STORE_U32(r31.u32 + 628, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r30,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r30.u32);
	// addi r31,r31,640
	r31.s64 = r31.s64 + 640;
	// bge 0x824e8d08
	if (!cr0.lt) goto loc_824E8D08;
	// addi r3,r29,3032
	ctx.r3.s64 = r29.s64 + 3032;
	// bl 0x824e6928
	ctx.lr = 0x824E8D40;
	sub_824E6928(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,3084(r29)
	PPC_STORE_U32(r29.u32 + 3084, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r10,r11,26220
	ctx.r10.s64 = r11.s64 + 26220;
	// stw r10,3032(r29)
	PPC_STORE_U32(r29.u32 + 3032, ctx.r10.u32);
	// lbz r9,3088(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 3088);
	// clrlwi r8,r9,26
	ctx.r8.u64 = ctx.r9.u32 & 0x3F;
	// stw r30,432(r29)
	PPC_STORE_U32(r29.u32 + 432, r30.u32);
	// stb r8,3088(r29)
	PPC_STORE_U8(r29.u32 + 3088, ctx.r8.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E8D6C"))) PPC_WEAK_FUNC(sub_824E8D6C);
PPC_FUNC_IMPL(__imp__sub_824E8D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8D70"))) PPC_WEAK_FUNC(sub_824E8D70);
PPC_FUNC_IMPL(__imp__sub_824E8D70) {
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
	// bl 0x824e88a0
	ctx.lr = 0x824E8D8C;
	sub_824E88A0(ctx, base);
	// bl 0x825019b0
	ctx.lr = 0x824E8D90;
	sub_825019B0(ctx, base);
	// lbz r11,3088(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 3088);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r9,r11,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x824e8dd0
	if (cr6.eq) goto loc_824E8DD0;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,3088(r30)
	PPC_STORE_U8(r30.u32 + 3088, r11.u8);
	// bne cr6,0x824e8dd0
	if (!cr6.eq) goto loc_824E8DD0;
	// li r31,0
	r31.s64 = 0;
loc_824E8DB8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e7ff0
	ctx.lr = 0x824E8DC4;
	sub_824E7FF0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x824e8db8
	if (cr6.lt) goto loc_824E8DB8;
loc_824E8DD0:
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

__attribute__((alias("__imp__sub_824E8DE8"))) PPC_WEAK_FUNC(sub_824E8DE8);
PPC_FUNC_IMPL(__imp__sub_824E8DE8) {
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
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,512(r31)
	PPC_STORE_U8(r31.u32 + 512, ctx.r10.u8);
	// bl 0x8244d150
	ctx.lr = 0x824E8E14;
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

__attribute__((alias("__imp__sub_824E8E2C"))) PPC_WEAK_FUNC(sub_824E8E2C);
PPC_FUNC_IMPL(__imp__sub_824E8E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E30"))) PPC_WEAK_FUNC(sub_824E8E30);
PPC_FUNC_IMPL(__imp__sub_824E8E30) {
	PPC_FUNC_PROLOGUE();
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8244d150
	sub_8244D150(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824E8E3C"))) PPC_WEAK_FUNC(sub_824E8E3C);
PPC_FUNC_IMPL(__imp__sub_824E8E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E40"))) PPC_WEAK_FUNC(sub_824E8E40);
PPC_FUNC_IMPL(__imp__sub_824E8E40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// std r11,4(r3)
	PPC_STORE_U64(ctx.r3.u32 + 4, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8E54"))) PPC_WEAK_FUNC(sub_824E8E54);
PPC_FUNC_IMPL(__imp__sub_824E8E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8E58"))) PPC_WEAK_FUNC(sub_824E8E58);
PPC_FUNC_IMPL(__imp__sub_824E8E58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8e68
	if (cr6.eq) goto loc_824E8E68;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// blr 
	return;
loc_824E8E68:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8E70"))) PPC_WEAK_FUNC(sub_824E8E70);
PPC_FUNC_IMPL(__imp__sub_824E8E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	// rlwinm r11,r3,4,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xF;
	// li r3,-1
	ctx.r3.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-29032
	r12.s64 = r12.s64 + -29032;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E8EB8;
	case 1:
		goto loc_824E8EB8;
	case 2:
		goto loc_824E8EC0;
	case 3:
		goto loc_824E8EC0;
	case 4:
		goto loc_824E8EC4;
	case 5:
		goto loc_824E8EB8;
	case 6:
		goto loc_824E8EC4;
	case 7:
		goto loc_824E8EC0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
	// lwz r18,-28988(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28988);
	// lwz r18,-29000(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -29000);
	// lwz r18,-28988(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28988);
	// lwz r18,-28992(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28992);
loc_824E8EB8:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_824E8EC0:
	// li r3,8
	ctx.r3.s64 = 8;
loc_824E8EC4:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8EC8"))) PPC_WEAK_FUNC(sub_824E8EC8);
PPC_FUNC_IMPL(__imp__sub_824E8EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,-1
	ctx.r3.s64 = -1;
	// rlwinm r11,r11,4,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28940
	r12.s64 = r12.s64 + -28940;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E8F14;
	case 1:
		goto loc_824E8F14;
	case 2:
		goto loc_824E8F1C;
	case 3:
		goto loc_824E8F1C;
	case 4:
		goto loc_824E8F20;
	case 5:
		goto loc_824E8F14;
	case 6:
		goto loc_824E8F20;
	case 7:
		goto loc_824E8F1C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
	// lwz r18,-28896(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28896);
	// lwz r18,-28908(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28908);
	// lwz r18,-28896(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28896);
	// lwz r18,-28900(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28900);
loc_824E8F14:
	// li r3,4
	ctx.r3.s64 = 4;
	// blr 
	return;
loc_824E8F1C:
	// li r3,8
	ctx.r3.s64 = 8;
loc_824E8F20:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8F24"))) PPC_WEAK_FUNC(sub_824E8F24);
PPC_FUNC_IMPL(__imp__sub_824E8F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8F28"))) PPC_WEAK_FUNC(sub_824E8F28);
PPC_FUNC_IMPL(__imp__sub_824E8F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e8f7c
	if (cr6.lt) goto loc_824E8F7C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f40
	if (cr6.eq) goto loc_824E8F40;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e8f44
	goto loc_824E8F44;
loc_824E8F40:
	// li r11,0
	r11.s64 = 0;
loc_824E8F44:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e8f7c
	if (!cr6.lt) goto loc_824E8F7C;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f5c
	if (cr6.eq) goto loc_824E8F5C;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e8f60
	goto loc_824E8F60;
loc_824E8F5C:
	// li r11,0
	r11.s64 = 0;
loc_824E8F60:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e8f80
	if (cr6.eq) goto loc_824E8F80;
loc_824E8F7C:
	// li r11,0
	r11.s64 = 0;
loc_824E8F80:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8F88"))) PPC_WEAK_FUNC(sub_824E8F88);
PPC_FUNC_IMPL(__imp__sub_824E8F88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e8f98
	if (cr6.eq) goto loc_824E8F98;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e8f9c
	goto loc_824E8F9C;
loc_824E8F98:
	// li r11,0
	r11.s64 = 0;
loc_824E8F9C:
	// li r10,1
	ctx.r10.s64 = 1;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// sld r11,r10,r11
	r11.u64 = r11.u8 & 0x40 ? 0 : (ctx.r10.u64 << (r11.u8 & 0x7F));
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// beq cr6,0x824e8fbc
	if (cr6.eq) goto loc_824E8FBC;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e8fc0
	goto loc_824E8FC0;
loc_824E8FBC:
	// li r11,0
	r11.s64 = 0;
loc_824E8FC0:
	// and r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e8fd4
	if (!cr6.eq) goto loc_824E8FD4;
	// li r11,0
	r11.s64 = 0;
loc_824E8FD4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E8FDC"))) PPC_WEAK_FUNC(sub_824E8FDC);
PPC_FUNC_IMPL(__imp__sub_824E8FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E8FE0"))) PPC_WEAK_FUNC(sub_824E8FE0);
PPC_FUNC_IMPL(__imp__sub_824E8FE0) {
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
	ctx.lr = 0x824E8FE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x824e9030
	if (cr6.lt) goto loc_824E9030;
	// addi r29,r30,512
	r29.s64 = r30.s64 + 512;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x824e9030
	if (!cr6.lt) goto loc_824E9030;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9014;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x824e902c
	if (cr6.lt) goto loc_824E902C;
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824e9030
	if (cr6.lt) goto loc_824E9030;
loc_824E902C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E9030:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E9038"))) PPC_WEAK_FUNC(sub_824E9038);
PPC_FUNC_IMPL(__imp__sub_824E9038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 + 12;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824e9054
	if (cr6.eq) goto loc_824E9054;
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// b 0x824e9058
	goto loc_824E9058;
loc_824E9054:
	// li r5,0
	ctx.r5.s64 = 0;
loc_824E9058:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x824e910c
	if (cr6.eq) {
		// ERROR 824E910C
		return;
	}
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x824e90fc
	if (cr6.lt) {
		// ERROR 824E90FC
		return;
	}
	// addi r7,r8,512
	ctx.r7.s64 = ctx.r8.s64 + 512;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// bge cr6,0x824e90fc
	if (!cr6.lt) {
		// ERROR 824E90FC
		return;
	}
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// li r11,-1
	r11.s64 = -1;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e90e0
	if (cr6.gt) goto loc_824E90E0;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28492
	r12.s64 = r12.s64 + -28492;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E90D4;
	case 1:
		goto loc_824E90D4;
	case 2:
		goto loc_824E90DC;
	case 3:
		goto loc_824E90DC;
	case 4:
		goto loc_824E90E0;
	case 5:
		goto loc_824E90D4;
	case 6:
		goto loc_824E90E0;
	case 7:
		goto loc_824E90DC;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
	// lwz r18,-28448(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28448);
	// lwz r18,-28460(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28460);
	// lwz r18,-28448(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28448);
	// lwz r18,-28452(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28452);
loc_824E90D4:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e90e0
	goto loc_824E90E0;
loc_824E90DC:
	// li r11,8
	r11.s64 = 8;
loc_824E90E0:
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
}

__attribute__((alias("__imp__sub_824E9114"))) PPC_WEAK_FUNC(sub_824E9114);
PPC_FUNC_IMPL(__imp__sub_824E9114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9118"))) PPC_WEAK_FUNC(sub_824E9118);
PPC_FUNC_IMPL(__imp__sub_824E9118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824e9234
	if (cr6.eq) {
		sub_824E9234(ctx, base);
		return;
	}
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// addi r9,r7,12
	ctx.r9.s64 = ctx.r7.s64 + 12;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r8,r10,4,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r8,7
	cr6.compare<uint32_t>(ctx.r8.u32, 7, xer);
	// bgt cr6,0x824e9198
	if (cr6.gt) goto loc_824E9198;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-28308
	r12.s64 = r12.s64 + -28308;
	// rlwinm r0,r8,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r8.u64) {
	case 0:
		goto loc_824E918C;
	case 1:
		goto loc_824E918C;
	case 2:
		goto loc_824E9194;
	case 3:
		goto loc_824E9194;
	case 4:
		goto loc_824E9198;
	case 5:
		goto loc_824E918C;
	case 6:
		goto loc_824E9198;
	case 7:
		goto loc_824E9194;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
	// lwz r18,-28264(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28264);
	// lwz r18,-28276(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28276);
	// lwz r18,-28264(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28264);
	// lwz r18,-28268(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28268);
loc_824E918C:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e9198
	goto loc_824E9198;
loc_824E9194:
	// li r11,8
	r11.s64 = 8;
loc_824E9198:
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
}

__attribute__((alias("__imp__sub_824E91DC"))) PPC_WEAK_FUNC(sub_824E91DC);
PPC_FUNC_IMPL(__imp__sub_824E91DC) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r14{};
	PPCRegister r18{};
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// lwz r18,-28152(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28152);
	// lwz r18,-28164(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28164);
	// lwz r18,-28152(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28152);
	// lwz r18,-28156(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -28156);
	// li r11,4
	r11.s64 = 4;
	// b 0x824e9208
	// ERROR 824E9208
	return;
}

__attribute__((alias("__imp__sub_824E9204"))) PPC_WEAK_FUNC(sub_824E9204);
PPC_FUNC_IMPL(__imp__sub_824E9204) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,8
	r11.s64 = 8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// blt cr6,0x824e9220
	if (cr6.lt) goto loc_824E9220;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x824e9224
	if (cr6.lt) goto loc_824E9224;
loc_824E9220:
	// li r11,0
	r11.s64 = 0;
loc_824E9224:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// bne 0x824e9140
	if (!cr0.eq) {
		// ERROR 824E9140
		return;
	}
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E9234"))) PPC_WEAK_FUNC(sub_824E9234);
PPC_FUNC_IMPL(__imp__sub_824E9234) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E923C"))) PPC_WEAK_FUNC(sub_824E923C);
PPC_FUNC_IMPL(__imp__sub_824E923C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9240"))) PPC_WEAK_FUNC(sub_824E9240);
PPC_FUNC_IMPL(__imp__sub_824E9240) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824E9248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x824e9398
	if (cr6.lt) goto loc_824E9398;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// bge cr6,0x824e9398
	if (!cr6.lt) goto loc_824E9398;
	// addi r30,r29,12
	r30.s64 = r29.s64 + 12;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9280
	if (cr6.eq) goto loc_824E9280;
	// lwz r26,0(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e9284
	goto loc_824E9284;
loc_824E9280:
	// li r26,0
	r26.s64 = 0;
loc_824E9284:
	// li r28,0
	r28.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x824e9394
	if (!cr6.gt) goto loc_824E9394;
loc_824E9294:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x824e92e4
	if (cr6.lt) goto loc_824E92E4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e92ac
	if (cr6.eq) goto loc_824E92AC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e92b0
	goto loc_824E92B0;
loc_824E92AC:
	// li r11,0
	r11.s64 = 0;
loc_824E92B0:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x824e92e4
	if (!cr6.lt) goto loc_824E92E4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e92c8
	if (cr6.eq) goto loc_824E92C8;
	// ld r11,4(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 4);
	// b 0x824e92cc
	goto loc_824E92CC;
loc_824E92C8:
	// li r11,0
	r11.s64 = 0;
loc_824E92CC:
	// extsw r10,r28
	ctx.r10.s64 = r28.s32;
	// sld r9,r25,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (r25.u64 << (ctx.r10.u8 & 0x7F));
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x824e92e8
	if (cr6.eq) goto loc_824E92E8;
loc_824E92E4:
	// li r11,0
	r11.s64 = 0;
loc_824E92E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9304
	if (cr6.eq) goto loc_824E9304;
	// clrlwi r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9398
	if (!cr6.eq) goto loc_824E9398;
	// b 0x824e9348
	goto loc_824E9348;
loc_824E9304:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r31,0,0,3
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xF0000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9328
	if (!cr6.eq) goto loc_824E9328;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82457550
	ctx.lr = 0x824E9324;
	sub_82457550(ctx, base);
	// b 0x824e9348
	goto loc_824E9348;
loc_824E9328:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r22,r30,4
	r22.s64 = r30.s64 + 4;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9334;
	sub_824E8EC8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// bl 0x824575e8
	ctx.lr = 0x824E9348;
	sub_824575E8(ctx, base);
loc_824E9348:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x824e9388
	if (cr6.lt) goto loc_824E9388;
	// addi r31,r29,512
	r31.s64 = r29.s64 + 512;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bge cr6,0x824e9388
	if (!cr6.lt) goto loc_824E9388;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E936C;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x824e9384
	if (cr6.lt) goto loc_824E9384;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x824e9388
	if (cr6.lt) goto loc_824E9388;
loc_824E9384:
	// li r11,0
	r11.s64 = 0;
loc_824E9388:
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// blt cr6,0x824e9294
	if (cr6.lt) goto loc_824E9294;
loc_824E9394:
	// mr r24,r25
	r24.u64 = r25.u64;
loc_824E9398:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E93A4"))) PPC_WEAK_FUNC(sub_824E93A4);
PPC_FUNC_IMPL(__imp__sub_824E93A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E93A8"))) PPC_WEAK_FUNC(sub_824E93A8);
PPC_FUNC_IMPL(__imp__sub_824E93A8) {
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
	ctx.lr = 0x824E93B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e943c
	if (cr6.lt) goto loc_824E943C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824e93d4
	if (cr6.eq) goto loc_824E93D4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824e93d8
	goto loc_824E93D8;
loc_824E93D4:
	// li r11,0
	r11.s64 = 0;
loc_824E93D8:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e943c
	if (!cr6.lt) goto loc_824E943C;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// ble cr6,0x824e9438
	if (!cr6.gt) goto loc_824E9438;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
loc_824E93F0:
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x824e942c
	if (cr6.lt) goto loc_824E942C;
	// addi r29,r30,512
	r29.s64 = r30.s64 + 512;
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// bge cr6,0x824e942c
	if (!cr6.lt) goto loc_824E942C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8ec8
	ctx.lr = 0x824E9410;
	sub_824E8EC8(ctx, base);
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x824e9428
	if (cr6.lt) goto loc_824E9428;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x824e942c
	if (cr6.lt) goto loc_824E942C;
loc_824E9428:
	// li r11,0
	r11.s64 = 0;
loc_824E942C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// mr r31,r11
	r31.u64 = r11.u64;
	// bne 0x824e93f0
	if (!cr0.eq) goto loc_824E93F0;
loc_824E9438:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824E943C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E9444"))) PPC_WEAK_FUNC(sub_824E9444);
PPC_FUNC_IMPL(__imp__sub_824E9444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9448"))) PPC_WEAK_FUNC(sub_824E9448);
PPC_FUNC_IMPL(__imp__sub_824E9448) {
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
	ctx.lr = 0x824E9450;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E9460;
	sub_824E9038(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bge cr6,0x824e94e0
	if (!cr6.lt) goto loc_824E94E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824e94b4
	if (cr6.eq) goto loc_824E94B4;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,64
	cr6.compare<int32_t>(r30.s32, 64, xer);
	// bge cr6,0x824e94e0
	if (!cr6.lt) goto loc_824E94E0;
loc_824E9480:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e70
	ctx.lr = 0x824E9488;
	sub_824E8E70(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824e94e0
	if (!cr6.gt) goto loc_824E94E0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824e94bc
	if (!cr6.gt) goto loc_824E94BC;
	// addi r4,r30,-1
	ctx.r4.s64 = r30.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E94A4;
	sub_824E93A8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e8fe0
	ctx.lr = 0x824E94B0;
	sub_824E8FE0(ctx, base);
	// b 0x824e94c0
	goto loc_824E94C0;
loc_824E94B4:
	// li r30,0
	r30.s64 = 0;
	// b 0x824e9480
	goto loc_824E9480;
loc_824E94BC:
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
loc_824E94C0:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e94e0
	if (cr6.eq) goto loc_824E94E0;
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824E94E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824E94EC"))) PPC_WEAK_FUNC(sub_824E94EC);
PPC_FUNC_IMPL(__imp__sub_824E94EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E94F0"))) PPC_WEAK_FUNC(sub_824E94F0);
PPC_FUNC_IMPL(__imp__sub_824E94F0) {
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
	// bl 0x824e93a8
	ctx.lr = 0x824E9500;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e951c
	if (cr6.eq) goto loc_824E951C;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E951C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E9530"))) PPC_WEAK_FUNC(sub_824E9530);
PPC_FUNC_IMPL(__imp__sub_824E9530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824E9538;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// li r27,0
	r27.s64 = 0;
	// bl 0x824e93a8
	ctx.lr = 0x824E9554;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e95ec
	if (cr6.eq) goto loc_824E95EC;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e95b4
	if (cr6.gt) goto loc_824E95B4;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-27256
	r12.s64 = r12.s64 + -27256;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E95A8;
	case 1:
		goto loc_824E95A8;
	case 2:
		goto loc_824E95B0;
	case 3:
		goto loc_824E95B0;
	case 4:
		goto loc_824E95B4;
	case 5:
		goto loc_824E95A8;
	case 6:
		goto loc_824E95B4;
	case 7:
		goto loc_824E95B0;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
	// lwz r18,-27212(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27212);
	// lwz r18,-27224(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27224);
	// lwz r18,-27212(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27212);
	// lwz r18,-27216(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -27216);
loc_824E95A8:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e95b4
	goto loc_824E95B4;
loc_824E95B0:
	// li r11,8
	r11.s64 = 8;
loc_824E95B4:
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// bne cr6,0x824e95ec
	if (!cr6.eq) goto loc_824E95EC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x8244d5c0
	ctx.lr = 0x824E95CC;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// ld r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U64(r31.u32 + 4);
	// sld r10,r3,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (ctx.r3.u64 << (r11.u8 & 0x7F));
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// std r8,4(r31)
	PPC_STORE_U64(r31.u32 + 4, ctx.r8.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824E95EC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824E95F8"))) PPC_WEAK_FUNC(sub_824E95F8);
PPC_FUNC_IMPL(__imp__sub_824E95F8) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x824e9658
	if (cr6.lt) goto loc_824E9658;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e961c
	if (cr6.eq) goto loc_824E961C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e9620
	goto loc_824E9620;
loc_824E961C:
	// li r11,0
	r11.s64 = 0;
loc_824E9620:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824e9658
	if (!cr6.lt) goto loc_824E9658;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9638
	if (cr6.eq) goto loc_824E9638;
	// ld r11,4(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 4);
	// b 0x824e963c
	goto loc_824E963C;
loc_824E9638:
	// li r11,0
	r11.s64 = 0;
loc_824E963C:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e965c
	if (cr6.eq) goto loc_824E965C;
loc_824E9658:
	// li r11,0
	r11.s64 = 0;
loc_824E965C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9678
	if (!cr6.eq) goto loc_824E9678;
	// bl 0x824e93a8
	ctx.lr = 0x824E966C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x824e967c
	if (!cr6.eq) goto loc_824E967C;
loc_824E9678:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824E967C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E968C"))) PPC_WEAK_FUNC(sub_824E968C);
PPC_FUNC_IMPL(__imp__sub_824E968C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9690"))) PPC_WEAK_FUNC(sub_824E9690);
PPC_FUNC_IMPL(__imp__sub_824E9690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824E9698;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824e93a8
	ctx.lr = 0x824E96AC;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9730
	if (cr6.eq) goto loc_824E9730;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// rlwinm r10,r10,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e970c
	if (cr6.gt) goto loc_824E970C;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26912
	r12.s64 = r12.s64 + -26912;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E9700;
	case 1:
		goto loc_824E9700;
	case 2:
		goto loc_824E9708;
	case 3:
		goto loc_824E9708;
	case 4:
		goto loc_824E970C;
	case 5:
		goto loc_824E9700;
	case 6:
		goto loc_824E970C;
	case 7:
		goto loc_824E9708;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
	// lwz r18,-26868(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26868);
	// lwz r18,-26880(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26880);
	// lwz r18,-26868(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26868);
	// lwz r18,-26872(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26872);
loc_824E9700:
	// li r11,4
	r11.s64 = 4;
	// b 0x824e970c
	goto loc_824E970C;
loc_824E9708:
	// li r11,8
	r11.s64 = 8;
loc_824E970C:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bgt cr6,0x824e9730
	if (cr6.gt) goto loc_824E9730;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824E9724;
	sub_8244D5C0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824E9730:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824E973C"))) PPC_WEAK_FUNC(sub_824E973C);
PPC_FUNC_IMPL(__imp__sub_824E973C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9740"))) PPC_WEAK_FUNC(sub_824E9740);
PPC_FUNC_IMPL(__imp__sub_824E9740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x824e93a8
	ctx.lr = 0x824E9750;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e97cc
	if (cr6.eq) goto loc_824E97CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r3,-1
	ctx.r3.s64 = -1;
	// rlwinm r11,r11,4,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e97d0
	if (cr6.gt) goto loc_824E97D0;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26748
	r12.s64 = r12.s64 + -26748;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E97A4;
	case 1:
		goto loc_824E97A4;
	case 2:
		goto loc_824E97B8;
	case 3:
		goto loc_824E97B8;
	case 4:
		goto loc_824E97D0;
	case 5:
		goto loc_824E97A4;
	case 6:
		goto loc_824E97D0;
	case 7:
		goto loc_824E97B8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
	// lwz r18,-26672(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26672);
	// lwz r18,-26716(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26716);
	// lwz r18,-26672(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26672);
	// lwz r18,-26696(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26696);
loc_824E97A4:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E97B8:
	// li r3,8
	ctx.r3.s64 = 8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E97CC:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824E97D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824E97E0"))) PPC_WEAK_FUNC(sub_824E97E0);
PPC_FUNC_IMPL(__imp__sub_824E97E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E97E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e9808
	if (cr6.eq) goto loc_824E9808;
	// lwz r23,0(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824e980c
	goto loc_824E980C;
loc_824E9808:
	// li r23,0
	r23.s64 = 0;
loc_824E980C:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x824e993c
	if (!cr6.gt) goto loc_824E993C;
	// li r26,0
	r26.s64 = 0;
	// li r24,1
	r24.s64 = 1;
	// li r22,-1
	r22.s64 = -1;
loc_824E9824:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824e9870
	if (cr6.lt) goto loc_824E9870;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e983c
	if (cr6.eq) goto loc_824E983C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824e9840
	goto loc_824E9840;
loc_824E983C:
	// li r11,0
	r11.s64 = 0;
loc_824E9840:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824e9870
	if (!cr6.lt) goto loc_824E9870;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824e9858
	if (cr6.eq) goto loc_824E9858;
	// ld r11,4(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 4);
	// b 0x824e985c
	goto loc_824E985C;
loc_824E9858:
	// li r11,0
	r11.s64 = 0;
loc_824E985C:
	// sld r10,r24,r26
	ctx.r10.u64 = r26.u8 & 0x40 ? 0 : (r24.u64 << (r26.u8 & 0x7F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// beq cr6,0x824e9874
	if (cr6.eq) goto loc_824E9874;
loc_824E9870:
	// li r11,0
	r11.s64 = 0;
loc_824E9874:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e992c
	if (!cr6.eq) goto loc_824E992C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E988C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e989c
	if (cr6.eq) goto loc_824E989C;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e98a0
	goto loc_824E98A0;
loc_824E989C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
loc_824E98A0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9038
	ctx.lr = 0x824E98A8;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824e992c
	if (cr6.lt) goto loc_824E992C;
	// rlwinm r11,r4,4,28,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xF;
	// li r31,-1
	r31.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e9908
	if (cr6.gt) goto loc_824E9908;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-26404
	r12.s64 = r12.s64 + -26404;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E98FC;
	case 1:
		goto loc_824E98FC;
	case 2:
		goto loc_824E9904;
	case 3:
		goto loc_824E9904;
	case 4:
		goto loc_824E9908;
	case 5:
		goto loc_824E98FC;
	case 6:
		goto loc_824E9908;
	case 7:
		goto loc_824E9904;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
	// lwz r18,-26360(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26360);
	// lwz r18,-26372(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26372);
	// lwz r18,-26360(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26360);
	// lwz r18,-26364(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -26364);
loc_824E98FC:
	// li r31,4
	r31.s64 = 4;
	// b 0x824e9908
	goto loc_824E9908;
loc_824E9904:
	// li r31,8
	r31.s64 = 8;
loc_824E9908:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9914;
	sub_824E95F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824e9530
	ctx.lr = 0x824E9928;
	sub_824E9530(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_824E992C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// blt cr6,0x824e9824
	if (cr6.lt) goto loc_824E9824;
loc_824E993C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E9948"))) PPC_WEAK_FUNC(sub_824E9948);
PPC_FUNC_IMPL(__imp__sub_824E9948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	// bl 0x823d91e0
	ctx.lr = 0x824E9950;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// li r23,0
	r23.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E9970;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824E9980;
	sub_82618640(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9990
	if (cr6.eq) goto loc_824E9990;
	// lwz r24,0(r27)
	r24.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// b 0x824e9994
	goto loc_824E9994;
loc_824E9990:
	// li r24,0
	r24.s64 = 0;
loc_824E9994:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9118
	ctx.lr = 0x824E999C;
	sub_824E9118(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E99B0;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e99ec
	if (cr6.eq) goto loc_824E99EC;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E99DC;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E99E8;
	sub_826188B8(ctx, base);
	// mr r31,r26
	r31.u64 = r26.u64;
loc_824E99EC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c04
	if (cr6.eq) goto loc_824E9C04;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x824E9A08;
	sub_824E6390(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c04
	if (cr6.eq) goto loc_824E9C04;
	// mr r23,r26
	r23.u64 = r26.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x824e9c04
	if (!cr6.gt) goto loc_824E9C04;
	// li r25,-1
	r25.s64 = -1;
loc_824E9A28:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824e9a78
	if (cr6.lt) goto loc_824E9A78;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9a40
	if (cr6.eq) goto loc_824E9A40;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// b 0x824e9a44
	goto loc_824E9A44;
loc_824E9A40:
	// li r11,0
	r11.s64 = 0;
loc_824E9A44:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824e9a78
	if (!cr6.lt) goto loc_824E9A78;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824e9a5c
	if (cr6.eq) goto loc_824E9A5C;
	// ld r11,4(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 4);
	// b 0x824e9a60
	goto loc_824E9A60;
loc_824E9A5C:
	// li r11,0
	r11.s64 = 0;
loc_824E9A60:
	// extsw r10,r29
	ctx.r10.s64 = r29.s32;
	// sld r9,r26,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x40 ? 0 : (r26.u64 << (ctx.r10.u8 & 0x7F));
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & r11.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpldi cr6,r8,0
	cr6.compare<uint64_t>(ctx.r8.u64, 0, xer);
	// beq cr6,0x824e9a7c
	if (cr6.eq) goto loc_824E9A7C;
loc_824E9A78:
	// li r11,0
	r11.s64 = 0;
loc_824E9A7C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x824e93a8
	ctx.lr = 0x824E9A8C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9a9c
	if (cr6.eq) goto loc_824E9A9C;
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824e9aa0
	goto loc_824E9AA0;
loc_824E9A9C:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824E9AA0:
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// bl 0x826186c0
	ctx.lr = 0x824E9AB0;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9ae8
	if (cr6.eq) goto loc_824E9AE8;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82618390
	ctx.lr = 0x824E9AD8;
	sub_82618390(ctx, base);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826188b8
	ctx.lr = 0x824E9AE4;
	sub_826188B8(ctx, base);
	// mr r31,r26
	r31.u64 = r26.u64;
loc_824E9AE8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618f70
	ctx.lr = 0x824E9B00;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824e9bf0
	if (!cr6.eq) goto loc_824E9BF0;
	// rlwinm r11,r30,4,28,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824e9be4
	if (cr6.gt) goto loc_824E9BE4;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-25792
	r12.s64 = r12.s64 + -25792;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824E9B60;
	case 1:
		goto loc_824E9B60;
	case 2:
		goto loc_824E9B84;
	case 3:
		goto loc_824E9BC8;
	case 4:
		goto loc_824E9BE4;
	case 5:
		goto loc_824E9BA8;
	case 6:
		goto loc_824E9BE4;
	case 7:
		goto loc_824E9B84;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-25760(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25760);
	// lwz r18,-25760(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25760);
	// lwz r18,-25724(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25724);
	// lwz r18,-25656(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25656);
	// lwz r18,-25628(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25628);
	// lwz r18,-25688(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25688);
	// lwz r18,-25628(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25628);
	// lwz r18,-25724(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25724);
loc_824E9B60:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9B6C;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824e6390
	ctx.lr = 0x824E9B80;
	sub_824E6390(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9B84:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9B90;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82618d38
	ctx.lr = 0x824E9BA4;
	sub_82618D38(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9BA8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9BB4;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82618df0
	ctx.lr = 0x824E9BC4;
	sub_82618DF0(ctx, base);
	// b 0x824e9be4
	goto loc_824E9BE4;
loc_824E9BC8:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824E9BD4;
	sub_824E95F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfd f1,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82618e98
	ctx.lr = 0x824E9BE4;
	sub_82618E98(ctx, base);
loc_824E9BE4:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c00
	if (cr6.eq) goto loc_824E9C00;
loc_824E9BF0:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r24
	cr6.compare<int32_t>(r29.s32, r24.s32, xer);
	// blt cr6,0x824e9a28
	if (cr6.lt) goto loc_824E9A28;
	// b 0x824e9c04
	goto loc_824E9C04;
loc_824E9C00:
	// li r23,0
	r23.s64 = 0;
loc_824E9C04:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824e9c38
	if (cr6.eq) goto loc_824E9C38;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9c30
	if (cr6.eq) goto loc_824E9C30;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824E9C20;
	sub_826186A0(ctx, base);
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
loc_824E9C30:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r3.u32);
loc_824E9C38:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824E9C44"))) PPC_WEAK_FUNC(sub_824E9C44);
PPC_FUNC_IMPL(__imp__sub_824E9C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9C48"))) PPC_WEAK_FUNC(sub_824E9C48);
PPC_FUNC_IMPL(__imp__sub_824E9C48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824E9C50;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x824E9C70;
	sub_82618750(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826185e0
	ctx.lr = 0x824E9C80;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9c90
	if (cr6.eq) goto loc_824E9C90;
	// li r11,0
	r11.s64 = 0;
	// std r11,4(r29)
	PPC_STORE_U64(r29.u32 + 4, r11.u64);
loc_824E9C90:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9CA0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e74
	if (cr6.eq) goto loc_824E9E74;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x824e9e74
	if (cr6.gt) goto loc_824E9E74;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9CC8;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e74
	if (cr6.eq) goto loc_824E9E74;
	// lwz r28,84(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r28,64
	cr6.compare<uint32_t>(r28.u32, 64, xer);
	// bgt cr6,0x824e9e74
	if (cr6.gt) goto loc_824E9E74;
	// li r27,1
	r27.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x824e9e74
	if (!cr6.gt) goto loc_824E9E74;
loc_824E9CF0:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9D00;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618f10
	ctx.lr = 0x824E9D18;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e8e58
	ctx.lr = 0x824E9D2C;
	sub_824E8E58(ctx, base);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x824e9d4c
	if (cr6.lt) goto loc_824E9D4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9448
	ctx.lr = 0x824E9D44;
	sub_824E9448(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x824e9e70
	if (!cr6.eq) goto loc_824E9E70;
loc_824E9D4C:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824e9e60
	if (!cr6.eq) goto loc_824E9E60;
	// rlwinm r10,r31,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xF;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,7
	cr6.compare<uint32_t>(ctx.r10.u32, 7, xer);
	// bgt cr6,0x824e9e54
	if (cr6.gt) goto loc_824E9E54;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-25216
	r12.s64 = r12.s64 + -25216;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_824E9DA0;
	case 1:
		goto loc_824E9DA0;
	case 2:
		goto loc_824E9DC8;
	case 3:
		goto loc_824E9E10;
	case 4:
		goto loc_824E9E54;
	case 5:
		goto loc_824E9DEC;
	case 6:
		goto loc_824E9E54;
	case 7:
		goto loc_824E9DC8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-25184(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25184);
	// lwz r18,-25184(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25184);
	// lwz r18,-25144(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25144);
	// lwz r18,-25072(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25072);
	// lwz r18,-25004(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25004);
	// lwz r18,-25108(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25108);
	// lwz r18,-25004(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25004);
	// lwz r18,-25144(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -25144);
loc_824E9DA0:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82257568
	ctx.lr = 0x824E9DB0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// b 0x824e9e30
	goto loc_824E9E30;
loc_824E9DC8:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618c90
	ctx.lr = 0x824E9DD8;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// b 0x824e9e2c
	goto loc_824E9E2C;
loc_824E9DEC:
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618db0
	ctx.lr = 0x824E9DF8;
	sub_82618DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// b 0x824e9e30
	goto loc_824E9E30;
loc_824E9E10:
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82618e20
	ctx.lr = 0x824E9E1C;
	sub_82618E20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e4c
	if (cr6.eq) goto loc_824E9E4C;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
loc_824E9E2C:
	// li r6,8
	ctx.r6.s64 = 8;
loc_824E9E30:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e9530
	ctx.lr = 0x824E9E3C;
	sub_824E9530(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824e9e50
	if (!cr6.eq) goto loc_824E9E50;
loc_824E9E4C:
	// li r11,0
	r11.s64 = 0;
loc_824E9E50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_824E9E54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9e70
	if (cr6.eq) goto loc_824E9E70;
loc_824E9E60:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// blt cr6,0x824e9cf0
	if (cr6.lt) goto loc_824E9CF0;
	// b 0x824e9e74
	goto loc_824E9E74;
loc_824E9E70:
	// li r27,0
	r27.s64 = 0;
loc_824E9E74:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824e9ea8
	if (cr6.eq) goto loc_824E9EA8;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824e9ea0
	if (cr6.eq) goto loc_824E9EA0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x826186b0
	ctx.lr = 0x824E9E90;
	sub_826186B0(ctx, base);
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_824E9EA0:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
loc_824E9EA8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824E9EB4"))) PPC_WEAK_FUNC(sub_824E9EB4);
PPC_FUNC_IMPL(__imp__sub_824E9EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9EB8"))) PPC_WEAK_FUNC(sub_824E9EB8);
PPC_FUNC_IMPL(__imp__sub_824E9EB8) {
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
	// bl 0x824e93a8
	ctx.lr = 0x824E9EC8;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9efc
	if (cr6.eq) goto loc_824E9EFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824E9EFC:
	// li r11,0
	r11.s64 = 0;
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

__attribute__((alias("__imp__sub_824E9F14"))) PPC_WEAK_FUNC(sub_824E9F14);
PPC_FUNC_IMPL(__imp__sub_824E9F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824E9F18"))) PPC_WEAK_FUNC(sub_824E9F18);
PPC_FUNC_IMPL(__imp__sub_824E9F18) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824E9F20;
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
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x824e9f88
	if (cr6.lt) goto loc_824E9F88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9f4c
	if (cr6.eq) goto loc_824E9F4C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x824e9f50
	goto loc_824E9F50;
loc_824E9F4C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F50:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x824e9f88
	if (!cr6.lt) goto loc_824E9F88;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824e9f68
	if (cr6.eq) goto loc_824E9F68;
	// ld r11,4(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 4);
	// b 0x824e9f6c
	goto loc_824E9F6C;
loc_824E9F68:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F6C:
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824e9f8c
	if (cr6.eq) goto loc_824E9F8C;
loc_824E9F88:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9F8C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea0a8
	if (!cr6.eq) goto loc_824EA0A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824E9FA4;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824e9fc8
	if (cr6.eq) goto loc_824E9FC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// subf r9,r28,r10
	ctx.r9.s64 = ctx.r10.s64 - r28.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// b 0x824e9fcc
	goto loc_824E9FCC;
loc_824E9FC8:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824E9FCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea0a8
	if (cr6.eq) goto loc_824EA0A8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x824e93a8
	ctx.lr = 0x824E9FE8;
	sub_824E93A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r8,4,28,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xF;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stb r10,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r10.u8);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bgt cr6,0x824ea0a8
	if (cr6.gt) goto loc_824EA0A8;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-24544
	r12.s64 = r12.s64 + -24544;
	// rlwinm r0,r9,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r9.u64) {
	case 0:
		goto loc_824EA03C;
	case 1:
		goto loc_824EA050;
	case 2:
		goto loc_824EA078;
	case 3:
		goto loc_824EA0A8;
	case 4:
		goto loc_824EA064;
	case 5:
		goto loc_824EA0A8;
	case 6:
		goto loc_824EA08C;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-24516(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24516);
	// lwz r18,-24496(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24496);
	// lwz r18,-24456(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24456);
	// lwz r18,-24408(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24408);
	// lwz r18,-24476(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24476);
	// lwz r18,-24408(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24408);
	// lwz r18,-24436(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -24436);
loc_824EA03C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA050:
	// ld r11,4(r11)
	r11.u64 = PPC_LOAD_U64(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r11,16(r30)
	PPC_STORE_U64(r30.u32 + 16, r11.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA064:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,16(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA078:
	// lfd f0,4(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfd f0,16(r30)
	PPC_STORE_U64(r30.u32 + 16, f0.u64);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA08C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA0A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA0B4"))) PPC_WEAK_FUNC(sub_824EA0B4);
PPC_FUNC_IMPL(__imp__sub_824EA0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA0B8"))) PPC_WEAK_FUNC(sub_824EA0B8);
PPC_FUNC_IMPL(__imp__sub_824EA0B8) {
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
	ctx.lr = 0x824EA0C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x824ea128
	if (cr6.lt) goto loc_824EA128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ea0ec
	if (cr6.eq) goto loc_824EA0EC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ea0f0
	goto loc_824EA0F0;
loc_824EA0EC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA0F0:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x824ea128
	if (!cr6.lt) goto loc_824EA128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ea108
	if (cr6.eq) goto loc_824EA108;
	// ld r11,4(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 4);
	// b 0x824ea10c
	goto loc_824EA10C;
loc_824EA108:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA10C:
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// li r9,1
	ctx.r9.s64 = 1;
	// sld r8,r9,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r9.u64 << (ctx.r10.u8 & 0x7F));
	// and r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 & r11.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// beq cr6,0x824ea12c
	if (cr6.eq) goto loc_824EA12C;
loc_824EA128:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA12C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea1a4
	if (!cr6.eq) goto loc_824EA1A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824EA144;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea164
	if (cr6.eq) goto loc_824EA164;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xF0000000;
	// subf r9,r28,r10
	ctx.r9.s64 = ctx.r10.s64 - r28.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x824ea168
	goto loc_824EA168;
loc_824EA164:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EA168:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea1a4
	if (cr6.eq) goto loc_824EA1A4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,1
	r31.s64 = 1;
	// bl 0x824e93a8
	ctx.lr = 0x824EA184;
	sub_824E93A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA1A4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA1B0"))) PPC_WEAK_FUNC(sub_824EA1B0);
PPC_FUNC_IMPL(__imp__sub_824EA1B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r18{};
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
	ctx.lr = 0x824EA1B8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r25,0
	r25.s64 = 0;
	// lbz r11,512(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 512);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ea1e4
	if (cr6.eq) goto loc_824EA1E4;
	// bl 0x824e97e0
	ctx.lr = 0x824EA1DC;
	sub_824E97E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_824EA1E4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea1f4
	if (cr6.eq) goto loc_824EA1F4;
	// lwz r23,0(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824ea1f8
	goto loc_824EA1F8;
loc_824EA1F4:
	// li r23,0
	r23.s64 = 0;
loc_824EA1F8:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x824ea340
	if (!cr6.gt) goto loc_824EA340;
	// li r26,0
	r26.s64 = 0;
	// li r22,-1
	r22.s64 = -1;
	// li r24,1
	r24.s64 = 1;
loc_824EA210:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e93a8
	ctx.lr = 0x824EA21C;
	sub_824E93A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea22c
	if (cr6.eq) goto loc_824EA22C;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x824ea230
	goto loc_824EA230;
loc_824EA22C:
	// mr r31,r22
	r31.u64 = r22.u64;
loc_824EA230:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9038
	ctx.lr = 0x824EA23C;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x824ea254
	if (!cr6.lt) goto loc_824EA254;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824e9448
	ctx.lr = 0x824EA250;
	sub_824E9448(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_824EA254:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x824ea2a0
	if (cr6.lt) goto loc_824EA2A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea26c
	if (cr6.eq) goto loc_824EA26C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x824ea270
	goto loc_824EA270;
loc_824EA26C:
	// li r11,0
	r11.s64 = 0;
loc_824EA270:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x824ea2a0
	if (!cr6.lt) goto loc_824EA2A0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ea288
	if (cr6.eq) goto loc_824EA288;
	// ld r11,4(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 4);
	// b 0x824ea28c
	goto loc_824EA28C;
loc_824EA288:
	// li r11,0
	r11.s64 = 0;
loc_824EA28C:
	// sld r10,r24,r26
	ctx.r10.u64 = r26.u8 & 0x40 ? 0 : (r24.u64 << (r26.u8 & 0x7F));
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmpldi cr6,r9,0
	cr6.compare<uint64_t>(ctx.r9.u64, 0, xer);
	// beq cr6,0x824ea2a4
	if (cr6.eq) goto loc_824EA2A4;
loc_824EA2A0:
	// li r11,0
	r11.s64 = 0;
loc_824EA2A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea330
	if (!cr6.eq) goto loc_824EA330;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824ea330
	if (cr6.lt) goto loc_824EA330;
	// rlwinm r11,r31,4,28,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xF;
	// li r31,-1
	r31.s64 = -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824ea30c
	if (cr6.gt) goto loc_824EA30C;
	// lis r12,-32177
	r12.s64 = -2108751872;
	// addi r12,r12,-23840
	r12.s64 = r12.s64 + -23840;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824EA300;
	case 1:
		goto loc_824EA300;
	case 2:
		goto loc_824EA308;
	case 3:
		goto loc_824EA308;
	case 4:
		goto loc_824EA30C;
	case 5:
		goto loc_824EA300;
	case 6:
		goto loc_824EA30C;
	case 7:
		goto loc_824EA308;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
	// lwz r18,-23796(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23796);
	// lwz r18,-23808(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23808);
	// lwz r18,-23796(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23796);
	// lwz r18,-23800(r14)
	r18.u64 = PPC_LOAD_U32(r14.u32 + -23800);
loc_824EA300:
	// li r31,4
	r31.s64 = 4;
	// b 0x824ea30c
	goto loc_824EA30C;
loc_824EA308:
	// li r31,8
	r31.s64 = 8;
loc_824EA30C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e95f8
	ctx.lr = 0x824EA318;
	sub_824E95F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x824e9530
	ctx.lr = 0x824EA32C;
	sub_824E9530(ctx, base);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
loc_824EA330:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r29,r23
	cr6.compare<int32_t>(r29.s32, r23.s32, xer);
	// blt cr6,0x824ea210
	if (cr6.lt) goto loc_824EA210;
loc_824EA340:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EA34C"))) PPC_WEAK_FUNC(sub_824EA34C);
PPC_FUNC_IMPL(__imp__sub_824EA34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA350"))) PPC_WEAK_FUNC(sub_824EA350);
PPC_FUNC_IMPL(__imp__sub_824EA350) {
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
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x824ea39c
	if (cr6.eq) goto loc_824EA39C;
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ea390
	if (!cr6.eq) goto loc_824EA390;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824EA390;
	sub_8244D150(ctx, base);
loc_824EA390:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ea1b0
	ctx.lr = 0x824EA39C;
	sub_824EA1B0(ctx, base);
loc_824EA39C:
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

__attribute__((alias("__imp__sub_824EA3B8"))) PPC_WEAK_FUNC(sub_824EA3B8);
PPC_FUNC_IMPL(__imp__sub_824EA3B8) {
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
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// lbz r11,512(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 512);
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,512(r31)
	PPC_STORE_U8(r31.u32 + 512, r11.u8);
	// beq cr6,0x824ea40c
	if (cr6.eq) goto loc_824EA40C;
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ea400
	if (!cr6.eq) goto loc_824EA400;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8244d150
	ctx.lr = 0x824EA400;
	sub_8244D150(ctx, base);
loc_824EA400:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ea1b0
	ctx.lr = 0x824EA40C;
	sub_824EA1B0(ctx, base);
loc_824EA40C:
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

__attribute__((alias("__imp__sub_824EA428"))) PPC_WEAK_FUNC(sub_824EA428);
PPC_FUNC_IMPL(__imp__sub_824EA428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA438"))) PPC_WEAK_FUNC(sub_824EA438);
PPC_FUNC_IMPL(__imp__sub_824EA438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r3,21380(r9)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + 21380);
	// lbz r8,30436(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 30436);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplw cr6,r7,r8
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r3,30436(r11)
	PPC_STORE_U8(r11.u32 + 30436, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA45C"))) PPC_WEAK_FUNC(sub_824EA45C);
PPC_FUNC_IMPL(__imp__sub_824EA45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA460"))) PPC_WEAK_FUNC(sub_824EA460);
PPC_FUNC_IMPL(__imp__sub_824EA460) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwimi r10,r3,7,0,24
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r3.u32, 7) & 0xFFFFFF80) | (ctx.r10.u64 & 0xFFFFFFFF0000007F);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA488"))) PPC_WEAK_FUNC(sub_824EA488);
PPC_FUNC_IMPL(__imp__sub_824EA488) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea4bc
	if (cr6.eq) goto loc_824EA4BC;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA4BC:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ea4e4
	if (!cr6.eq) goto loc_824EA4E4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824EA4CC;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82131c28
	ctx.lr = 0x824EA4D8;
	sub_82131C28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ea4e8
	if (cr6.eq) goto loc_824EA4E8;
loc_824EA4E4:
	// li r11,0
	r11.s64 = 0;
loc_824EA4E8:
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

__attribute__((alias("__imp__sub_824EA500"))) PPC_WEAK_FUNC(sub_824EA500);
PPC_FUNC_IMPL(__imp__sub_824EA500) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea534
	if (cr6.eq) goto loc_824EA534;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA534:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ea55c
	if (!cr6.eq) goto loc_824EA55C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x824f92f0
	ctx.lr = 0x824EA544;
	sub_824F92F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82131c38
	ctx.lr = 0x824EA550;
	sub_82131C38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ea560
	if (cr6.eq) goto loc_824EA560;
loc_824EA55C:
	// li r11,0
	r11.s64 = 0;
loc_824EA560:
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

__attribute__((alias("__imp__sub_824EA578"))) PPC_WEAK_FUNC(sub_824EA578);
PPC_FUNC_IMPL(__imp__sub_824EA578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r11,r8,0,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lbz r11,21380(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 21380);
	// lbz r9,30436(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 30436);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// cmplw cr6,r7,r9
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, xer);
	// beq cr6,0x824ea5a8
	if (cr6.eq) goto loc_824EA5A8;
	// stb r11,30436(r10)
	PPC_STORE_U8(ctx.r10.u32 + 30436, r11.u8);
loc_824EA5A8:
	// clrlwi r11,r8,25
	r11.u64 = ctx.r8.u32 & 0x7F;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA5B4"))) PPC_WEAK_FUNC(sub_824EA5B4);
PPC_FUNC_IMPL(__imp__sub_824EA5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA5B8"))) PPC_WEAK_FUNC(sub_824EA5B8);
PPC_FUNC_IMPL(__imp__sub_824EA5B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32724
	ctx.r10.s64 = r11.s64 + 32724;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA5C8"))) PPC_WEAK_FUNC(sub_824EA5C8);
PPC_FUNC_IMPL(__imp__sub_824EA5C8) {
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
	// addi r10,r11,26932
	ctx.r10.s64 = r11.s64 + 26932;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// addi r11,r31,52
	r11.s64 = r31.s64 + 52;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x824ea61c
	if (cr6.eq) goto loc_824EA61C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EA61C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EA61C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82530228
	ctx.lr = 0x824EA624;
	sub_82530228(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EA638"))) PPC_WEAK_FUNC(sub_824EA638);
PPC_FUNC_IMPL(__imp__sub_824EA638) {
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
	// bl 0x824ea5c8
	ctx.lr = 0x824EA658;
	sub_824EA5C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ea670
	if (cr6.eq) goto loc_824EA670;
	// bl 0x82130588
	ctx.lr = 0x824EA66C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EA670:
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

__attribute__((alias("__imp__sub_824EA688"))) PPC_WEAK_FUNC(sub_824EA688);
PPC_FUNC_IMPL(__imp__sub_824EA688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32716
	ctx.r10.s64 = r11.s64 + -32716;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA698"))) PPC_WEAK_FUNC(sub_824EA698);
PPC_FUNC_IMPL(__imp__sub_824EA698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32692
	ctx.r10.s64 = r11.s64 + 32692;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA6A8"))) PPC_WEAK_FUNC(sub_824EA6A8);
PPC_FUNC_IMPL(__imp__sub_824EA6A8) {
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
	ctx.lr = 0x824EA6B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EA6D4;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r10,212(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r11,26968
	ctx.r9.s64 = r11.s64 + 26968;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r29,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r29.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// sth r27,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r27.u16);
	// stw r7,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EA710"))) PPC_WEAK_FUNC(sub_824EA710);
PPC_FUNC_IMPL(__imp__sub_824EA710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,32596
	ctx.r10.s64 = r11.s64 + 32596;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA720"))) PPC_WEAK_FUNC(sub_824EA720);
PPC_FUNC_IMPL(__imp__sub_824EA720) {
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
	// addi r10,r11,26968
	ctx.r10.s64 = r11.s64 + 26968;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// addi r11,r31,56
	r11.s64 = r31.s64 + 56;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beq cr6,0x824ea774
	if (cr6.eq) goto loc_824EA774;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EA774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EA774:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82530228
	ctx.lr = 0x824EA77C;
	sub_82530228(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EA790"))) PPC_WEAK_FUNC(sub_824EA790);
PPC_FUNC_IMPL(__imp__sub_824EA790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32684
	ctx.r10.s64 = r11.s64 + -32684;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA7A0"))) PPC_WEAK_FUNC(sub_824EA7A0);
PPC_FUNC_IMPL(__imp__sub_824EA7A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r10,r11,-32748
	ctx.r10.s64 = r11.s64 + -32748;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA7B0"))) PPC_WEAK_FUNC(sub_824EA7B0);
PPC_FUNC_IMPL(__imp__sub_824EA7B0) {
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
	// bne cr6,0x824ea7f8
	if (!cr6.eq) goto loc_824EA7F8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwimi r11,r10,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821c90c0
	ctx.lr = 0x824EA7E8;
	sub_821C90C0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9168
	ctx.lr = 0x824EA7F0;
	sub_821C9168(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821c9158
	ctx.lr = 0x824EA7F8;
	sub_821C9158(ctx, base);
loc_824EA7F8:
	// lbz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// rlwinm r8,r8,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r8,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r8.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EA834"))) PPC_WEAK_FUNC(sub_824EA834);
PPC_FUNC_IMPL(__imp__sub_824EA834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA838"))) PPC_WEAK_FUNC(sub_824EA838);
PPC_FUNC_IMPL(__imp__sub_824EA838) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ea84c
	if (cr6.eq) goto loc_824EA84C;
	// b 0x823eaef8
	sub_823EAEF8(ctx, base);
	return;
loc_824EA84C:
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA854"))) PPC_WEAK_FUNC(sub_824EA854);
PPC_FUNC_IMPL(__imp__sub_824EA854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA858"))) PPC_WEAK_FUNC(sub_824EA858);
PPC_FUNC_IMPL(__imp__sub_824EA858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,1336(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1336);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,1336(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1336, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA86C"))) PPC_WEAK_FUNC(sub_824EA86C);
PPC_FUNC_IMPL(__imp__sub_824EA86C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA870"))) PPC_WEAK_FUNC(sub_824EA870);
PPC_FUNC_IMPL(__imp__sub_824EA870) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,1336(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1336);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EA87C"))) PPC_WEAK_FUNC(sub_824EA87C);
PPC_FUNC_IMPL(__imp__sub_824EA87C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA880"))) PPC_WEAK_FUNC(sub_824EA880);
PPC_FUNC_IMPL(__imp__sub_824EA880) {
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
	ctx.lr = 0x824EA888;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA8A4;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,192(r11)
	PPC_STORE_U32(r11.u32 + 192, ctx.r10.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r8,r9,1000
	ctx.r8.s64 = ctx.r9.s64 * 1000;
	// stw r8,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r8.u32);
	// bl 0x821c9030
	ctx.lr = 0x824EA8C8;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EA8D0"))) PPC_WEAK_FUNC(sub_824EA8D0);
PPC_FUNC_IMPL(__imp__sub_824EA8D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x824EA8D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,1292
	r30.s64 = r31.s64 + 1292;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA8F4;
	sub_821C8FE0(ctx, base);
	// addi r31,r31,196
	r31.s64 = r31.s64 + 196;
	// li r28,16
	r28.s64 = 16;
loc_824EA8FC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EA908;
	sub_821C8FE0(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824EA918:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824ea918
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824EA918;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EA934;
	sub_821C9030(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,68
	r31.s64 = r31.s64 + 68;
	// bne 0x824ea8fc
	if (!cr0.eq) goto loc_824EA8FC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EA948;
	sub_821C9030(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA950"))) PPC_WEAK_FUNC(sub_824EA950);
PPC_FUNC_IMPL(__imp__sub_824EA950) {
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
	ctx.lr = 0x824EA958;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82533f20
	ctx.lr = 0x824EA970;
	sub_82533F20(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EA97C;
	sub_82533FC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r29,-3
	ctx.r4.s64 = r29.s64 + -3;
	// addi r3,r30,3
	ctx.r3.s64 = r30.s64 + 3;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x821d2e28
	ctx.lr = 0x824EA990;
	sub_821D2E28(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ea9c0
	if (cr6.eq) goto loc_824EA9C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533f58
	ctx.lr = 0x824EA9A4;
	sub_82533F58(ctx, base);
	// rlwinm r5,r3,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82533e98
	ctx.lr = 0x824EA9B4;
	sub_82533E98(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EA9C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EA9CC"))) PPC_WEAK_FUNC(sub_824EA9CC);
PPC_FUNC_IMPL(__imp__sub_824EA9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EA9D0"))) PPC_WEAK_FUNC(sub_824EA9D0);
PPC_FUNC_IMPL(__imp__sub_824EA9D0) {
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
	ctx.lr = 0x824EA9D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EA9F4;
	sub_82533EF0(ctx, base);
	// add r29,r3,r31
	r29.u64 = ctx.r3.u64 + r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ble cr6,0x824eaaf8
	if (!cr6.gt) goto loc_824EAAF8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaa4c
	if (cr6.eq) goto loc_824EAA4C;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824f8db8
	ctx.lr = 0x824EAA28;
	sub_824F8DB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaaf4
	if (!cr6.eq) goto loc_824EAAF4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824eaaf8
	if (!cr6.eq) goto loc_824EAAF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAA4C:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaa90
	if (cr6.eq) goto loc_824EAA90;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82533c68
	ctx.lr = 0x824EAA6C;
	sub_82533C68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaaf4
	if (!cr6.eq) goto loc_824EAAF4;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824eaaf8
	if (!cr6.eq) goto loc_824EAAF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAA90:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EAAB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eab00
	if (cr6.eq) goto loc_824EAB00;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// bl 0x8244d5c0
	ctx.lr = 0x824EAAE8;
	sub_8244D5C0(ctx, base);
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
loc_824EAAF4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824EAAF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824EAB00:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EAB0C"))) PPC_WEAK_FUNC(sub_824EAB0C);
PPC_FUNC_IMPL(__imp__sub_824EAB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAB10"))) PPC_WEAK_FUNC(sub_824EAB10);
PPC_FUNC_IMPL(__imp__sub_824EAB10) {
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
	ctx.lr = 0x824EAB18;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r5,20(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r11,12(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// srw. r30,r11,r5
	r30.u64 = ctx.r5.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r5.u8 & 0x3F));
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x824eab94
	if (cr0.eq) goto loc_824EAB94;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r31,148
	r31.s64 = 148;
loc_824EAB3C:
	// lwz r7,0(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// blt cr6,0x824eab7c
	if (cr6.lt) goto loc_824EAB7C;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// mulli r11,r11,148
	r11.s64 = r11.s64 * 148;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bge cr6,0x824eab7c
	if (!cr6.lt) goto loc_824EAB7C;
	// subf r10,r7,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r7.s64;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// slw r11,r8,r5
	r11.u64 = ctx.r5.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r5.u8 & 0x3F));
	// divw r10,r10,r31
	ctx.r10.s32 = ctx.r10.s32 / r31.s32;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// cmplw cr6,r29,r7
	cr6.compare<uint32_t>(r29.u32, ctx.r7.u32, xer);
	// blt cr6,0x824eab90
	if (cr6.lt) goto loc_824EAB90;
loc_824EAB7C:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// blt cr6,0x824eab3c
	if (cr6.lt) goto loc_824EAB3C;
	// b 0x823d924c
	return;
loc_824EAB90:
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
loc_824EAB94:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EAB98"))) PPC_WEAK_FUNC(sub_824EAB98);
PPC_FUNC_IMPL(__imp__sub_824EAB98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eabdc
	if (!cr6.eq) goto loc_824EABDC;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eabd0
	if (cr6.eq) goto loc_824EABD0;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eac14
	if (!cr6.eq) goto loc_824EAC14;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABD0:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABDC:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eabfc
	if (!cr6.eq) goto loc_824EABFC;
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eac14
	goto loc_824EAC14;
loc_824EABFC:
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r11,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r11.u32);
	// lwz r10,8(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
	// stw r6,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r6.u32);
loc_824EAC14:
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

__attribute__((alias("__imp__sub_824EAC2C"))) PPC_WEAK_FUNC(sub_824EAC2C);
PPC_FUNC_IMPL(__imp__sub_824EAC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAC30"))) PPC_WEAK_FUNC(sub_824EAC30);
PPC_FUNC_IMPL(__imp__sub_824EAC30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eac74
	if (!cr6.eq) goto loc_824EAC74;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eac68
	if (cr6.eq) goto loc_824EAC68;
	// stw r6,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,132(r6)
	PPC_STORE_U32(ctx.r6.u32 + 132, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eacac
	if (!cr6.eq) goto loc_824EACAC;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC68:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC74:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eac94
	if (!cr6.eq) goto loc_824EAC94;
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eacac
	goto loc_824EACAC;
loc_824EAC94:
	// stw r5,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, ctx.r5.u32);
	// lwz r11,132(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// stw r11,132(r6)
	PPC_STORE_U32(ctx.r6.u32 + 132, r11.u32);
	// lwz r10,132(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 132);
	// stw r6,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r6.u32);
	// stw r6,132(r5)
	PPC_STORE_U32(ctx.r5.u32 + 132, ctx.r6.u32);
loc_824EACAC:
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

__attribute__((alias("__imp__sub_824EACC4"))) PPC_WEAK_FUNC(sub_824EACC4);
PPC_FUNC_IMPL(__imp__sub_824EACC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EACC8"))) PPC_WEAK_FUNC(sub_824EACC8);
PPC_FUNC_IMPL(__imp__sub_824EACC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824ead0c
	if (!cr6.eq) goto loc_824EAD0C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ead00
	if (cr6.eq) goto loc_824EAD00;
	// stw r6,124(r11)
	PPC_STORE_U32(r11.u32 + 124, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824ead44
	if (!cr6.eq) goto loc_824EAD44;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD00:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD0C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824ead2c
	if (!cr6.eq) goto loc_824EAD2C;
	// stw r11,124(r6)
	PPC_STORE_U32(ctx.r6.u32 + 124, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824ead44
	goto loc_824EAD44;
loc_824EAD2C:
	// stw r5,124(r6)
	PPC_STORE_U32(ctx.r6.u32 + 124, ctx.r5.u32);
	// lwz r11,128(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// stw r11,128(r6)
	PPC_STORE_U32(ctx.r6.u32 + 128, r11.u32);
	// lwz r10,128(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// stw r6,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, ctx.r6.u32);
	// stw r6,128(r5)
	PPC_STORE_U32(ctx.r5.u32 + 128, ctx.r6.u32);
loc_824EAD44:
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

__attribute__((alias("__imp__sub_824EAD5C"))) PPC_WEAK_FUNC(sub_824EAD5C);
PPC_FUNC_IMPL(__imp__sub_824EAD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAD60"))) PPC_WEAK_FUNC(sub_824EAD60);
PPC_FUNC_IMPL(__imp__sub_824EAD60) {
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
	// bl 0x82530228
	ctx.lr = 0x824EAD80;
	sub_82530228(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ead98
	if (cr6.eq) goto loc_824EAD98;
	// bl 0x82130588
	ctx.lr = 0x824EAD94;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EAD98:
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

__attribute__((alias("__imp__sub_824EADB0"))) PPC_WEAK_FUNC(sub_824EADB0);
PPC_FUNC_IMPL(__imp__sub_824EADB0) {
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
	// bl 0x825337a8
	ctx.lr = 0x824EADD0;
	sub_825337A8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eade8
	if (cr6.eq) goto loc_824EADE8;
	// bl 0x82130588
	ctx.lr = 0x824EADE4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824EADE8:
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

__attribute__((alias("__imp__sub_824EAE00"))) PPC_WEAK_FUNC(sub_824EAE00);
PPC_FUNC_IMPL(__imp__sub_824EAE00) {
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
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eae34
	if (!cr6.eq) goto loc_824EAE34;
	// bl 0x8218f5b0
	ctx.lr = 0x824EAE28;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824eae38
	if (cr6.eq) goto loc_824EAE38;
loc_824EAE34:
	// li r11,0
	r11.s64 = 0;
loc_824EAE38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eae50
	if (cr6.eq) goto loc_824EAE50;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
loc_824EAE50:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EAE64"))) PPC_WEAK_FUNC(sub_824EAE64);
PPC_FUNC_IMPL(__imp__sub_824EAE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EAE68"))) PPC_WEAK_FUNC(sub_824EAE68);
PPC_FUNC_IMPL(__imp__sub_824EAE68) {
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
	// bl 0x825303e8
	ctx.lr = 0x824EAE88;
	sub_825303E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaec8
	if (!cr6.eq) goto loc_824EAEC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825305b0
	ctx.lr = 0x824EAE9C;
	sub_825305B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eaec4
	if (cr6.eq) goto loc_824EAEC4;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eaec8
	if (cr6.eq) goto loc_824EAEC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82531b80
	ctx.lr = 0x824EAEBC;
	sub_82531B80(ctx, base);
	// cmplwi cr6,r3,20
	cr6.compare<uint32_t>(ctx.r3.u32, 20, xer);
	// ble cr6,0x824eaec8
	if (!cr6.gt) goto loc_824EAEC8;
loc_824EAEC4:
	// li r30,1
	r30.s64 = 1;
loc_824EAEC8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eaee8
	if (!cr6.eq) goto loc_824EAEE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b728
	ctx.lr = 0x824EAEDC;
	sub_8263B728(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824eaeec
	if (cr6.eq) goto loc_824EAEEC;
loc_824EAEE8:
	// li r11,1
	r11.s64 = 1;
loc_824EAEEC:
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

__attribute__((alias("__imp__sub_824EAF08"))) PPC_WEAK_FUNC(sub_824EAF08);
PPC_FUNC_IMPL(__imp__sub_824EAF08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x824EAF10;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EAF30;
	sub_82533FC0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82533fc8
	ctx.lr = 0x824EAF50;
	sub_82533FC8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eaf6c
	if (cr6.eq) goto loc_824EAF6C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534248
	ctx.lr = 0x824EAF60;
	sub_82534248(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EAF6C;
	sub_8244D5C0(ctx, base);
loc_824EAF6C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82534318
	ctx.lr = 0x824EAF74;
	sub_82534318(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82533e98
	ctx.lr = 0x824EAF84;
	sub_82533E98(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EAF98;
	sub_824EA9D0(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EAFA0"))) PPC_WEAK_FUNC(sub_824EAFA0);
PPC_FUNC_IMPL(__imp__sub_824EAFA0) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EAFC8;
	sub_821C8FE0(ctx, base);
	// clrlwi r11,r30,16
	r11.u64 = r30.u32 & 0xFFFF;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824eb01c
	if (cr6.lt) goto loc_824EB01C;
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bge cr6,0x824eb01c
	if (!cr6.lt) goto loc_824EB01C;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// srw r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r11.u32 >> (ctx.r10.u8 & 0x3F));
	// lwz r7,108(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r5,r7,r11
	ctx.r5.u64 = ctx.r7.u64 & r11.u64;
	// mulli r10,r5,148
	ctx.r10.s64 = ctx.r5.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb01c
	if (cr6.eq) goto loc_824EB01C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EB014;
	sub_82656BF8(ctx, base);
	// cmpw cr6,r3,r30
	cr6.compare<int32_t>(ctx.r3.s32, r30.s32, xer);
	// beq cr6,0x824eb020
	if (cr6.eq) goto loc_824EB020;
loc_824EB01C:
	// li r31,0
	r31.s64 = 0;
loc_824EB020:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EB028;
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

__attribute__((alias("__imp__sub_824EB044"))) PPC_WEAK_FUNC(sub_824EB044);
PPC_FUNC_IMPL(__imp__sub_824EB044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB048"))) PPC_WEAK_FUNC(sub_824EB048);
PPC_FUNC_IMPL(__imp__sub_824EB048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb098
	if (!cr6.eq) goto loc_824EB098;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb084
	if (cr6.eq) goto loc_824EB084;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB084:
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
loc_824EB098:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb0d4
	if (!cr6.eq) goto loc_824EB0D4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb0f8
	if (cr6.eq) goto loc_824EB0F8;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB0D4:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
loc_824EB0F8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB108"))) PPC_WEAK_FUNC(sub_824EB108);
PPC_FUNC_IMPL(__imp__sub_824EB108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb158
	if (!cr6.eq) goto loc_824EB158;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb144
	if (cr6.eq) goto loc_824EB144;
	// stw r11,132(r10)
	PPC_STORE_U32(ctx.r10.u32 + 132, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB144:
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
loc_824EB158:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb194
	if (!cr6.eq) goto loc_824EB194;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,132(r4)
	PPC_STORE_U32(ctx.r4.u32 + 132, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb1b8
	if (cr6.eq) goto loc_824EB1B8;
	// stw r11,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB194:
	// lwz r10,132(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,128(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// stw r9,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r9.u32);
	// lwz r8,128(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// lwz r7,132(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 132);
	// stw r7,132(r8)
	PPC_STORE_U32(ctx.r8.u32 + 132, ctx.r7.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// stw r11,132(r4)
	PPC_STORE_U32(ctx.r4.u32 + 132, r11.u32);
loc_824EB1B8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB1C8"))) PPC_WEAK_FUNC(sub_824EB1C8);
PPC_FUNC_IMPL(__imp__sub_824EB1C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb1f0
	if (cr6.eq) goto loc_824EB1F0;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
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
loc_824EB1F0:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb210
	if (cr6.eq) goto loc_824EB210;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824eb214
	if (!cr6.eq) goto loc_824EB214;
loc_824EB210:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824EB214:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb230
	if (cr6.eq) goto loc_824EB230;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_824EB230:
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

__attribute__((alias("__imp__sub_824EB244"))) PPC_WEAK_FUNC(sub_824EB244);
PPC_FUNC_IMPL(__imp__sub_824EB244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB248"))) PPC_WEAK_FUNC(sub_824EB248);
PPC_FUNC_IMPL(__imp__sub_824EB248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb298
	if (!cr6.eq) goto loc_824EB298;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb284
	if (cr6.eq) goto loc_824EB284;
	// stw r11,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB284:
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
loc_824EB298:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb2d4
	if (!cr6.eq) goto loc_824EB2D4;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb2f8
	if (cr6.eq) goto loc_824EB2F8;
	// stw r11,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB2D4:
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,20(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// lwz r8,20(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
loc_824EB2F8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB308"))) PPC_WEAK_FUNC(sub_824EB308);
PPC_FUNC_IMPL(__imp__sub_824EB308) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb358
	if (!cr6.eq) goto loc_824EB358;
	// lwz r10,124(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// li r11,0
	r11.s64 = 0;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r11,124(r4)
	PPC_STORE_U32(ctx.r4.u32 + 124, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb344
	if (cr6.eq) goto loc_824EB344;
	// stw r11,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB344:
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
loc_824EB358:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x824eb394
	if (!cr6.eq) goto loc_824EB394;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb3b8
	if (cr6.eq) goto loc_824EB3B8;
	// stw r11,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
loc_824EB394:
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,124(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	// stw r9,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, ctx.r9.u32);
	// lwz r8,124(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 124);
	// lwz r7,128(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// stw r7,128(r8)
	PPC_STORE_U32(ctx.r8.u32 + 128, ctx.r7.u32);
	// stw r11,124(r4)
	PPC_STORE_U32(ctx.r4.u32 + 124, r11.u32);
	// stw r11,128(r4)
	PPC_STORE_U32(ctx.r4.u32 + 128, r11.u32);
loc_824EB3B8:
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB3C8"))) PPC_WEAK_FUNC(sub_824EB3C8);
PPC_FUNC_IMPL(__imp__sub_824EB3C8) {
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
	ctx.lr = 0x824EB3D0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r22,r24
	r22.u64 = r24.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r11,r21
	ctx.r10.u64 = r11.u64 + r21.u64;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// srw r30,r9,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// andc r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r8.u64;
	// srw r23,r10,r7
	r23.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x824eb5a0
	if (!cr6.gt) goto loc_824EB5A0;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bgt cr6,0x824eb6c8
	if (cr6.gt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824eb6c8
	if (cr6.lt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB458;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824eb6c8
	if (cr6.eq) goto loc_824EB6C8;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r22,1
	r22.s64 = 1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eb494
	if (cr6.eq) goto loc_824EB494;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8244d5c0
	ctx.lr = 0x824EB47C;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EB494:
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mr r26,r30
	r26.u64 = r30.u64;
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// bge cr6,0x824eb6c8
	if (!cr6.lt) goto loc_824EB6C8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// rlwinm r28,r30,2,0,29
	r28.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,27004
	r25.s64 = r11.s64 + 27004;
loc_824EB4B0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r24,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, r24.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mulli r30,r10,148
	r30.s64 = ctx.r10.s64 * 148;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824EB4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x824eb504
	if (cr6.lt) goto loc_824EB504;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	ctx.lr = 0x824EB4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r3,r28,r9
	PPC_STORE_U32(r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_824EB504:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eb598
	if (cr6.eq) goto loc_824EB598;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r27,r24
	r27.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824eb574
	if (!cr6.gt) goto loc_824EB574;
	// mr r29,r24
	r29.u64 = r24.u64;
loc_824EB528:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// add. r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// beq 0x824eb560
	if (cr0.eq) goto loc_824EB560;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82531aa8
	ctx.lr = 0x824EB540;
	sub_82531AA8(ctx, base);
	// stw r25,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r25.u32);
	// stw r24,128(r30)
	PPC_STORE_U32(r30.u32 + 128, r24.u32);
	// stw r24,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r24.u32);
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r24,136(r30)
	PPC_STORE_U32(r30.u32 + 136, r24.u32);
	// stw r24,140(r30)
	PPC_STORE_U32(r30.u32 + 140, r24.u32);
	// stb r10,144(r30)
	PPC_STORE_U8(r30.u32 + 144, ctx.r10.u8);
loc_824EB560:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,148
	r29.s64 = r29.s64 + 148;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824eb528
	if (cr6.lt) goto loc_824EB528;
loc_824EB574:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r26,r23
	cr6.compare<uint32_t>(r26.u32, r23.u32, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// blt cr6,0x824eb4b0
	if (cr6.lt) goto loc_824EB4B0;
	// b 0x824eb6c8
	goto loc_824EB6C8;
loc_824EB598:
	// mr r22,r24
	r22.u64 = r24.u64;
	// b 0x824eb6c8
	goto loc_824EB6C8;
loc_824EB5A0:
	// bge cr6,0x824eb6c4
	if (!cr6.lt) goto loc_824EB6C4;
	// cmplw cr6,r23,r30
	cr6.compare<uint32_t>(r23.u32, r30.u32, xer);
	// bge cr6,0x824eb630
	if (!cr6.lt) goto loc_824EB630;
	// rlwinm r28,r23,2,0,29
	r28.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r27,r23,r30
	r27.s64 = r30.s64 - r23.s64;
loc_824EB5B4:
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb5f8
	if (cr6.eq) goto loc_824EB5F8;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_824EB5C4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EB5E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,148
	r30.s64 = r30.s64 + 148;
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// blt cr6,0x824eb5c4
	if (cr6.lt) goto loc_824EB5C4;
loc_824EB5F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r4,r28,r11
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EB614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// bne 0x824eb5b4
	if (!cr0.eq) goto loc_824EB5B4;
loc_824EB630:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x824eb6b0
	if (cr6.eq) goto loc_824EB6B0;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824eb6c8
	if (cr6.lt) goto loc_824EB6C8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB678;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eb6c8
	if (cr6.eq) goto loc_824EB6C8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d5c0
	ctx.lr = 0x824EB690;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// b 0x824eb6c4
	goto loc_824EB6C4;
loc_824EB6B0:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB6C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
loc_824EB6C4:
	// li r22,1
	r22.s64 = 1;
loc_824EB6C8:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb6e4
	if (cr6.eq) goto loc_824EB6E4;
	// stw r21,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r21.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_824EB6E4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x824eb6f8
	if (!cr6.gt) goto loc_824EB6F8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_824EB6F8:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824EB704"))) PPC_WEAK_FUNC(sub_824EB704);
PPC_FUNC_IMPL(__imp__sub_824EB704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB708"))) PPC_WEAK_FUNC(sub_824EB708);
PPC_FUNC_IMPL(__imp__sub_824EB708) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824eb74c
	if (!cr6.eq) goto loc_824EB74C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb740
	if (cr6.eq) goto loc_824EB740;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, r11.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// bne cr6,0x824eb784
	if (!cr6.eq) goto loc_824EB784;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB740:
	// stw r6,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB74C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x824eb76c
	if (!cr6.eq) goto loc_824EB76C;
	// stw r11,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, r11.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r6,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r6.u32);
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// b 0x824eb784
	goto loc_824EB784;
loc_824EB76C:
	// stw r5,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r5.u32);
	// lwz r11,24(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// stw r11,24(r6)
	PPC_STORE_U32(ctx.r6.u32 + 24, r11.u32);
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// stw r6,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r6.u32);
	// stw r6,24(r5)
	PPC_STORE_U32(ctx.r5.u32 + 24, ctx.r6.u32);
loc_824EB784:
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

__attribute__((alias("__imp__sub_824EB79C"))) PPC_WEAK_FUNC(sub_824EB79C);
PPC_FUNC_IMPL(__imp__sub_824EB79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB7A0"))) PPC_WEAK_FUNC(sub_824EB7A0);
PPC_FUNC_IMPL(__imp__sub_824EB7A0) {
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
	ctx.lr = 0x824EB7A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb7f0
	if (cr6.eq) goto loc_824EB7F0;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eb7f0
	if (cr6.eq) goto loc_824EB7F0;
loc_824EB7CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB7E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824eb7cc
	if (!cr6.eq) goto loc_824EB7CC;
loc_824EB7F0:
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// ori r8,r29,1
	ctx.r8.u64 = r29.u64 | 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb840
	if (cr6.eq) goto loc_824EB840;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// mulli r9,r10,1000
	ctx.r9.s64 = ctx.r10.s64 * 1000;
	// cmpwi cr6,r11,1000
	cr6.compare<int32_t>(r11.s32, 1000, xer);
	// ble cr6,0x824eb818
	if (!cr6.gt) goto loc_824EB818;
	// li r11,1000
	r11.s64 = 1000;
loc_824EB818:
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x824eb850
	if (!cr6.gt) goto loc_824EB850;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EB840:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// mulli r10,r11,1000
	ctx.r10.s64 = r11.s64 * 1000;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_824EB850:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EB858"))) PPC_WEAK_FUNC(sub_824EB858);
PPC_FUNC_IMPL(__imp__sub_824EB858) {
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
	ctx.lr = 0x824EB860;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,40(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb8b8
	if (cr6.eq) goto loc_824EB8B8;
	// lwz r31,32(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb8b8
	if (cr6.eq) goto loc_824EB8B8;
loc_824EB88C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EB8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eb88c
	if (!cr6.eq) goto loc_824EB88C;
loc_824EB8B8:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb8d4
	if (cr6.eq) goto loc_824EB8D4;
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mulli r10,r30,1000
	ctx.r10.s64 = r30.s64 * 1000;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r9.u32);
loc_824EB8D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824EB8DC"))) PPC_WEAK_FUNC(sub_824EB8DC);
PPC_FUNC_IMPL(__imp__sub_824EB8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB8E0"))) PPC_WEAK_FUNC(sub_824EB8E0);
PPC_FUNC_IMPL(__imp__sub_824EB8E0) {
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
	ctx.lr = 0x824EB8E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eb93c
	if (cr6.eq) goto loc_824EB93C;
	// lwz r31,32(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb93c
	if (cr6.eq) goto loc_824EB93C;
loc_824EB910:
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
	ctx.lr = 0x824EB930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eb910
	if (!cr6.eq) goto loc_824EB910;
loc_824EB93C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EB944"))) PPC_WEAK_FUNC(sub_824EB944);
PPC_FUNC_IMPL(__imp__sub_824EB944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EB948"))) PPC_WEAK_FUNC(sub_824EB948);
PPC_FUNC_IMPL(__imp__sub_824EB948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r4,27
	ctx.r10.u64 = ctx.r4.u32 & 0x1F;
	// addi r9,r11,333
	ctx.r9.s64 = r11.s64 + 333;
	// li r8,1
	ctx.r8.s64 = 1;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r7,r8,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// lwzx r6,r11,r3
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// or r5,r7,r6
	ctx.r5.u64 = ctx.r7.u64 | ctx.r6.u64;
	// stwx r5,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EB970"))) PPC_WEAK_FUNC(sub_824EB970);
PPC_FUNC_IMPL(__imp__sub_824EB970) {
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
	ctx.lr = 0x824EB978;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EB994;
	sub_821C8FE0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x824eafa0
	ctx.lr = 0x824EB9A4;
	sub_824EAFA0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eb9ec
	if (cr6.eq) goto loc_824EB9EC;
	// bl 0x8218f5b0
	ctx.lr = 0x824EB9B4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x824eb9ec
	if (cr6.eq) goto loc_824EB9EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825303e0
	ctx.lr = 0x824EB9C4;
	sub_825303E0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824EB9D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824eb9d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824EB9D4;
	// li r29,1
	r29.s64 = 1;
loc_824EB9EC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EB9F4;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EBA00"))) PPC_WEAK_FUNC(sub_824EBA00);
PPC_FUNC_IMPL(__imp__sub_824EBA00) {
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
	ctx.lr = 0x824EBA08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBA24;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,216
	ctx.r3.s64 = r11.s64 + 216;
	// bl 0x824eb048
	ctx.lr = 0x824EBA38;
	sub_824EB048(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBA40;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EBA48"))) PPC_WEAK_FUNC(sub_824EBA48);
PPC_FUNC_IMPL(__imp__sub_824EBA48) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBA70;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EBA7C;
	sub_824EAFA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824eba90
	if (cr6.eq) goto loc_824EBA90;
	// bl 0x821f6c70
	ctx.lr = 0x824EBA88;
	sub_821F6C70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824eba98
	goto loc_824EBA98;
loc_824EBA90:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,30468
	r31.s64 = r11.s64 + 30468;
loc_824EBA98:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBAA0;
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

__attribute__((alias("__imp__sub_824EBABC"))) PPC_WEAK_FUNC(sub_824EBABC);
PPC_FUNC_IMPL(__imp__sub_824EBABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EBAC0"))) PPC_WEAK_FUNC(sub_824EBAC0);
PPC_FUNC_IMPL(__imp__sub_824EBAC0) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBAE8;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EBAF4;
	sub_824EAFA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ebb08
	if (cr6.eq) goto loc_824EBB08;
	// bl 0x82618698
	ctx.lr = 0x824EBB00;
	sub_82618698(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824ebb0c
	goto loc_824EBB0C;
loc_824EBB08:
	// li r31,-1
	r31.s64 = -1;
loc_824EBB0C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBB14;
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

__attribute__((alias("__imp__sub_824EBB30"))) PPC_WEAK_FUNC(sub_824EBB30);
PPC_FUNC_IMPL(__imp__sub_824EBB30) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBB58;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EBB64;
	sub_824EAFA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ebba0
	if (cr6.eq) goto loc_824EBBA0;
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ebb8c
	if (!cr6.eq) goto loc_824EBB8C;
	// bl 0x8218f5b0
	ctx.lr = 0x824EBB80;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ebb90
	if (cr6.eq) goto loc_824EBB90;
loc_824EBB8C:
	// li r11,0
	r11.s64 = 0;
loc_824EBB90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ebba4
	if (!cr6.eq) goto loc_824EBBA4;
loc_824EBBA0:
	// li r31,0
	r31.s64 = 0;
loc_824EBBA4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBBAC;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824EBBC8"))) PPC_WEAK_FUNC(sub_824EBBC8);
PPC_FUNC_IMPL(__imp__sub_824EBBC8) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBBF0;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EBBFC;
	sub_824EAFA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ebc14
	if (cr6.eq) goto loc_824EBC14;
	// bl 0x8218f5b0
	ctx.lr = 0x824EBC08;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// li r31,0
	r31.s64 = 0;
	// bne cr6,0x824ebc18
	if (!cr6.eq) goto loc_824EBC18;
loc_824EBC14:
	// li r31,1
	r31.s64 = 1;
loc_824EBC18:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBC20;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824EBC3C"))) PPC_WEAK_FUNC(sub_824EBC3C);
PPC_FUNC_IMPL(__imp__sub_824EBC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EBC40"))) PPC_WEAK_FUNC(sub_824EBC40);
PPC_FUNC_IMPL(__imp__sub_824EBC40) {
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
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBC68;
	sub_821C8FE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EBC74;
	sub_824EAFA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ebca0
	if (cr6.eq) goto loc_824EBCA0;
	// bl 0x8218f5b0
	ctx.lr = 0x824EBC80;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ebc90
	if (cr6.lt) goto loc_824EBC90;
	// li r11,0
	r11.s64 = 0;
loc_824EBC90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ebca4
	if (!cr6.eq) goto loc_824EBCA4;
loc_824EBCA0:
	// li r31,0
	r31.s64 = 0;
loc_824EBCA4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBCAC;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_824EBCC8"))) PPC_WEAK_FUNC(sub_824EBCC8);
PPC_FUNC_IMPL(__imp__sub_824EBCC8) {
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
	// addi r4,r30,124
	ctx.r4.s64 = r30.s64 + 124;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EBCF0;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ebd28
	if (cr6.eq) goto loc_824EBD28;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x824eb248
	ctx.lr = 0x824EBD14;
	sub_824EB248(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_824EBD28:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EBD30;
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

__attribute__((alias("__imp__sub_824EBD48"))) PPC_WEAK_FUNC(sub_824EBD48);
PPC_FUNC_IMPL(__imp__sub_824EBD48) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ebd88
	if (cr6.eq) goto loc_824EBD88;
loc_824EBD68:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ebd7c
	if (cr6.eq) goto loc_824EBD7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EBD7C;
	sub_824EB108(ctx, base);
loc_824EBD7C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ebd68
	if (!cr6.eq) goto loc_824EBD68;
loc_824EBD88:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EBD9C"))) PPC_WEAK_FUNC(sub_824EBD9C);
PPC_FUNC_IMPL(__imp__sub_824EBD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EBDA0"))) PPC_WEAK_FUNC(sub_824EBDA0);
PPC_FUNC_IMPL(__imp__sub_824EBDA0) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ebde0
	if (cr6.eq) goto loc_824EBDE0;
loc_824EBDC0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ebdd4
	if (cr6.eq) goto loc_824EBDD4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EBDD4;
	sub_824EB308(ctx, base);
loc_824EBDD4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ebdc0
	if (!cr6.eq) goto loc_824EBDC0;
loc_824EBDE0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EBDF4"))) PPC_WEAK_FUNC(sub_824EBDF4);
PPC_FUNC_IMPL(__imp__sub_824EBDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EBDF8"))) PPC_WEAK_FUNC(sub_824EBDF8);
PPC_FUNC_IMPL(__imp__sub_824EBDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ebe30
	if (cr6.eq) goto loc_824EBE30;
	// lwz r11,104(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ebe28
	if (cr6.eq) goto loc_824EBE28;
loc_824EBE18:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ebe18
	if (!cr6.eq) goto loc_824EBE18;
loc_824EBE28:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_824EBE30:
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_824EBE3C:
	// lwz r10,100(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,108(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824ebe3c
	if (!cr6.eq) goto loc_824EBE3C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EBE60"))) PPC_WEAK_FUNC(sub_824EBE60);
PPC_FUNC_IMPL(__imp__sub_824EBE60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// addi r11,r4,100
	r11.s64 = ctx.r4.s64 + 100;
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// lwz r7,104(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// or r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 | ctx.r7.u64;
	// stw r6,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r6.u32);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ebe90
	if (cr6.eq) goto loc_824EBE90;
	// stw r4,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r4.u32);
loc_824EBE90:
	// lwz r10,108(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x824ebeb4
	if (!cr6.eq) goto loc_824EBEB4;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r4,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r4.u32);
	// stw r11,108(r4)
	PPC_STORE_U32(ctx.r4.u32 + 108, r11.u32);
	// blr 
	return;
loc_824EBEB4:
	// lwz r10,108(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x824ebed4
	if (!cr6.eq) goto loc_824EBED4;
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// stw r4,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r4.u32);
	// stw r11,108(r4)
	PPC_STORE_U32(ctx.r4.u32 + 108, r11.u32);
	// blr 
	return;
loc_824EBED4:
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
	// stw r4,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r4.u32);
	// stw r11,108(r4)
	PPC_STORE_U32(ctx.r4.u32 + 108, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EBEF0"))) PPC_WEAK_FUNC(sub_824EBEF0);
PPC_FUNC_IMPL(__imp__sub_824EBEF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,104(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,104(r4)
	PPC_STORE_U32(ctx.r4.u32 + 104, ctx.r9.u32);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r8,r10,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ebf18
	if (cr6.eq) goto loc_824EBF18;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r4,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r4.u32);
loc_824EBF18:
	// lwz r10,108(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x824ebf34
	if (!cr6.eq) goto loc_824EBF34;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x824ebf60
	goto loc_824EBF60;
loc_824EBF34:
	// lwz r10,108(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// bne cr6,0x824ebf5c
	if (!cr6.eq) goto loc_824EBF5C;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
	// b 0x824ebf60
	goto loc_824EBF60;
loc_824EBF5C:
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
loc_824EBF60:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// or r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 | ctx.r4.u64;
	// stw r8,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r8.u32);
	// stw r11,108(r4)
	PPC_STORE_U32(ctx.r4.u32 + 108, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EBF78"))) PPC_WEAK_FUNC(sub_824EBF78);
PPC_FUNC_IMPL(__imp__sub_824EBF78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824EBFA0"))) PPC_WEAK_FUNC(sub_824EBFA0);
PPC_FUNC_IMPL(__imp__sub_824EBFA0) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ebfe0
	if (cr6.eq) goto loc_824EBFE0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x824eb248
	ctx.lr = 0x824EBFCC;
	sub_824EB248(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_824EBFE0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824EBFF4"))) PPC_WEAK_FUNC(sub_824EBFF4);
PPC_FUNC_IMPL(__imp__sub_824EBFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EBFF8"))) PPC_WEAK_FUNC(sub_824EBFF8);
PPC_FUNC_IMPL(__imp__sub_824EBFF8) {
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
	ctx.lr = 0x824EC000;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r26,0
	r26.s64 = 0;
	// lwz r25,52(r29)
	r25.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824ec0b4
	if (cr6.eq) goto loc_824EC0B4;
loc_824EC020:
	// lwz r11,52(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec0b4
	if (cr6.eq) goto loc_824EC0B4;
	// lwz r31,44(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// addi r30,r29,44
	r30.s64 = r29.s64 + 44;
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x824ec0b4
	if (cr6.eq) goto loc_824EC0B4;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ec058
	if (cr6.eq) goto loc_824EC058;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EC058;
	sub_824EB248(ctx, base);
loc_824EC058:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824eb708
	ctx.lr = 0x824EC06C;
	sub_824EB708(ctx, base);
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// beq cr6,0x824ec098
	if (cr6.eq) goto loc_824EC098;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824EC094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824ec0a8
	goto loc_824EC0A8;
loc_824EC098:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824EC0A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EC0A8:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmplw cr6,r26,r25
	cr6.compare<uint32_t>(r26.u32, r25.u32, xer);
	// blt cr6,0x824ec020
	if (cr6.lt) goto loc_824EC020;
loc_824EC0B4:
	// lwz r11,56(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 56);
loc_824EC0B8:
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824ec0b8
	if (cr0.eq) goto loc_824EC0B8;
	// stw r11,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824EC0CC"))) PPC_WEAK_FUNC(sub_824EC0CC);
PPC_FUNC_IMPL(__imp__sub_824EC0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EC0D0"))) PPC_WEAK_FUNC(sub_824EC0D0);
PPC_FUNC_IMPL(__imp__sub_824EC0D0) {
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
	ctx.lr = 0x824EC0D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EC0F4;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r4,r11,216
	ctx.r4.s64 = r11.s64 + 216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eab98
	ctx.lr = 0x824EC110;
	sub_824EAB98(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EC118;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EC120"))) PPC_WEAK_FUNC(sub_824EC120);
PPC_FUNC_IMPL(__imp__sub_824EC120) {
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
	ctx.lr = 0x824EC128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,124
	ctx.r4.s64 = r31.s64 + 124;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EC144;
	sub_821C8FE0(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r30,r31,184
	r30.s64 = r31.s64 + 184;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r30,44
	ctx.r4.s64 = r30.s64 + 44;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eb708
	ctx.lr = 0x824EC164;
	sub_824EB708(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r11.u32);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// stw r10,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x824EC180;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EC188"))) PPC_WEAK_FUNC(sub_824EC188);
PPC_FUNC_IMPL(__imp__sub_824EC188) {
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
	ctx.lr = 0x824EC190;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ec1d0
	if (cr6.eq) goto loc_824EC1D0;
	// lwz r11,104(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec1c8
	if (cr6.eq) goto loc_824EC1C8;
loc_824EC1B8:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ec1b8
	if (!cr6.eq) goto loc_824EC1B8;
loc_824EC1C8:
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// b 0x824ec1d4
	goto loc_824EC1D4;
loc_824EC1D0:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_824EC1D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e6310
	ctx.lr = 0x824EC1DC;
	sub_824E6310(ctx, base);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824ec20c
	if (cr6.eq) goto loc_824EC20C;
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,116(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824EC20C:
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EC218"))) PPC_WEAK_FUNC(sub_824EC218);
PPC_FUNC_IMPL(__imp__sub_824EC218) {
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
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ec24c
	if (cr6.eq) goto loc_824EC24C;
	// bl 0x824ebdf8
	ctx.lr = 0x824EC244;
	sub_824EBDF8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// b 0x824ec2a8
	goto loc_824EC2A8;
loc_824EC24C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ec26c
	if (cr6.eq) goto loc_824EC26C;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824ec270
	if (!cr6.eq) goto loc_824EC270;
loc_824EC26C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824EC270:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ec2a8
	if (cr6.eq) goto loc_824EC2A8;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,104(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec2a4
	if (cr6.eq) goto loc_824EC2A4;
loc_824EC294:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ec294
	if (!cr6.eq) goto loc_824EC294;
loc_824EC2A4:
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_824EC2A8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec2c4
	if (cr6.eq) goto loc_824EC2C4;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,116(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_824EC2C4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// stw r8,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_824EC2FC"))) PPC_WEAK_FUNC(sub_824EC2FC);
PPC_FUNC_IMPL(__imp__sub_824EC2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EC300"))) PPC_WEAK_FUNC(sub_824EC300);
PPC_FUNC_IMPL(__imp__sub_824EC300) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x824ec5f4
	if (cr6.eq) goto loc_824EC5F4;
loc_824EC328:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ec5f4
	if (!cr6.eq) goto loc_824EC5F4;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x824ec4a4
	if (!cr6.eq) goto loc_824EC4A4;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r4,r10,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ec3a4
	if (cr6.eq) goto loc_824EC3A4;
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x824ec39c
	if (!cr6.eq) goto loc_824EC39C;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r10.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r8.u32);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824ebe60
	ctx.lr = 0x824EC390;
	sub_824EBE60(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r4,r7,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
loc_824EC39C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824ec3ac
	if (!cr6.eq) goto loc_824EC3AC;
loc_824EC3A4:
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x824ec5e8
	goto loc_824EC5E8;
loc_824EC3AC:
	// lwz r10,104(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ec3c8
	if (cr6.eq) goto loc_824EC3C8;
	// lwz r11,100(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824ec3ec
	if (!cr6.eq) goto loc_824EC3EC;
loc_824EC3C8:
	// lwz r11,100(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ec494
	if (cr6.eq) goto loc_824EC494;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ec494
	if (cr6.eq) goto loc_824EC494;
loc_824EC3EC:
	// lwz r9,100(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// addi r11,r4,100
	r11.s64 = ctx.r4.s64 + 100;
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ec414
	if (cr6.eq) goto loc_824EC414;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r8,100(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ec440
	if (!cr6.eq) goto loc_824EC440;
loc_824EC414:
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bl 0x824ebef0
	ctx.lr = 0x824EC434;
	sub_824EBEF0(ctx, base);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r4,100(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	// rlwinm r4,r4,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
loc_824EC440:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r11,r4,100
	r11.s64 = ctx.r4.s64 + 100;
	// lwz r9,100(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,100(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// rlwimi r7,r9,0,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// stw r7,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r7.u32);
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r6,100(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r5,r6,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r5,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r5.u32);
	// lwz r4,100(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// rlwinm r11,r4,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r9.u32);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824ebe60
	ctx.lr = 0x824EC48C;
	sub_824EBE60(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ec5e8
	goto loc_824EC5E8;
loc_824EC494:
	// lwz r11,100(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r10.u32);
	// b 0x824ec5e4
	goto loc_824EC5E4;
loc_824EC4A4:
	// lwz r4,104(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ec4f8
	if (cr6.eq) goto loc_824EC4F8;
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x824ec4f0
	if (!cr6.eq) goto loc_824EC4F0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r10.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r8.u32);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824ebef0
	ctx.lr = 0x824EC4E8;
	sub_824EBEF0(ctx, base);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r4,104(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 104);
loc_824EC4F0:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824ec500
	if (!cr6.eq) goto loc_824EC500;
loc_824EC4F8:
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x824ec5e8
	goto loc_824EC5E8;
loc_824EC500:
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// addi r11,r4,100
	r11.s64 = ctx.r4.s64 + 100;
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ec528
	if (cr6.eq) goto loc_824EC528;
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r8,100(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ec544
	if (!cr6.eq) goto loc_824EC544;
loc_824EC528:
	// lwz r9,104(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ec5d8
	if (cr6.eq) goto loc_824EC5D8;
	// lwz r9,100(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ec5d8
	if (cr6.eq) goto loc_824EC5D8;
loc_824EC544:
	// lwz r9,104(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ec560
	if (cr6.eq) goto loc_824EC560;
	// lwz r9,100(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ec58c
	if (!cr6.eq) goto loc_824EC58C;
loc_824EC560:
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bl 0x824ebe60
	ctx.lr = 0x824EC584;
	sub_824EBE60(ctx, base);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r4,104(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 104);
loc_824EC58C:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// lwz r9,100(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwimi r8,r10,0,0,30
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFFFE) | (ctx.r8.u64 & 0xFFFFFFFF00000001);
	// stw r8,100(r4)
	PPC_STORE_U32(ctx.r4.u32 + 100, ctx.r8.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r6.u32);
	// lwz r11,104(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// lwz r5,100(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r4,r5,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r4,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r4.u32);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824ebef0
	ctx.lr = 0x824EC5D0;
	sub_824EBEF0(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ec5e8
	goto loc_824EC5E8;
loc_824EC5D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_824EC5E4:
	// lwz r31,108(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 108);
loc_824EC5E8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824ec328
	if (!cr6.eq) goto loc_824EC328;
loc_824EC5F4:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_824EC618"))) PPC_WEAK_FUNC(sub_824EC618);
PPC_FUNC_IMPL(__imp__sub_824EC618) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x824ec8d4
	if (cr6.eq) goto loc_824EC8D4;
loc_824EC640:
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,100(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// clrlwi r11,r10,31
	r11.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824ec8d4
	if (!cr6.eq) goto loc_824EC8D4;
	// lwz r11,108(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// lwz r9,104(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x824ec7ac
	if (!cr6.eq) goto loc_824EC7AC;
	// lwz r11,100(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec6c4
	if (cr6.eq) goto loc_824EC6C4;
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x824ec6c4
	if (!cr6.eq) goto loc_824EC6C4;
	// rotlwi r10,r4,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// lwz r4,100(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 | 1;
	// stw r3,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r31,108(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// b 0x824ec8c8
	goto loc_824EC8C8;
loc_824EC6C4:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824ec6dc
	if (!cr6.eq) goto loc_824EC6DC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824ebe60
	ctx.lr = 0x824EC6DC;
	sub_824EBE60(ctx, base);
loc_824EC6DC:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r9.u32);
	// lwz r8,108(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r6.u32);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r4,100(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r3,r4,0,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r3,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r3.u32);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ec730
	if (cr6.eq) goto loc_824EC730;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
loc_824EC730:
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r9,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x824ec75c
	if (!cr6.eq) goto loc_824EC75C;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
	// b 0x824ec8c4
	goto loc_824EC8C4;
loc_824EC75C:
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r8,100(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// rlwinm r7,r8,0,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bne cr6,0x824ec794
	if (!cr6.eq) goto loc_824EC794;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r6,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r6.u32);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
	// b 0x824ec8c4
	goto loc_824EC8C4;
loc_824EC794:
	// stw r10,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, ctx.r10.u32);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
	// b 0x824ec8c4
	goto loc_824EC8C4;
loc_824EC7AC:
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ec808
	if (cr6.eq) goto loc_824EC808;
	// addi r11,r11,100
	r11.s64 = r11.s64 + 100;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x824ec808
	if (!cr6.eq) goto loc_824EC808;
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// lwz r4,100(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 | 1;
	// stw r3,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r3.u32);
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r31,108(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// b 0x824ec8c8
	goto loc_824EC8C8;
loc_824EC808:
	// lwz r11,104(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824ec820
	if (!cr6.eq) goto loc_824EC820;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824ebef0
	ctx.lr = 0x824EC820;
	sub_824EBEF0(ctx, base);
loc_824EC820:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r9.u32);
	// lwz r8,108(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r6.u32);
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r11,108(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// addi r10,r11,100
	ctx.r10.s64 = r11.s64 + 100;
	// lwz r4,100(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r10,r3,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFE;
	// clrlwi r8,r4,31
	ctx.r8.u64 = ctx.r4.u32 & 0x1;
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stw r7,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r7.u32);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ec87c
	if (cr6.eq) goto loc_824EC87C;
	// stw r11,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r11.u32);
loc_824EC87C:
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r9,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, ctx.r9.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x824ec898
	if (!cr6.eq) goto loc_824EC898;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x824ec8c0
	goto loc_824EC8C0;
loc_824EC898:
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x824ec8b0
	if (!cr6.eq) goto loc_824EC8B0;
	// stw r10,104(r9)
	PPC_STORE_U32(ctx.r9.u32 + 104, ctx.r10.u32);
	// b 0x824ec8c0
	goto loc_824EC8C0;
loc_824EC8B0:
	// lwz r8,100(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stw r6,100(r9)
	PPC_STORE_U32(ctx.r9.u32 + 100, ctx.r6.u32);
loc_824EC8C0:
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
loc_824EC8C4:
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
loc_824EC8C8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824ec640
	if (!cr6.eq) goto loc_824EC640;
loc_824EC8D4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_824EC8FC"))) PPC_WEAK_FUNC(sub_824EC8FC);
PPC_FUNC_IMPL(__imp__sub_824EC8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EC900"))) PPC_WEAK_FUNC(sub_824EC900);
PPC_FUNC_IMPL(__imp__sub_824EC900) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r11,r31,100
	r11.s64 = r31.s64 + 100;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
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
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// bl 0x824e6310
	ctx.lr = 0x824EC958;
	sub_824E6310(ctx, base);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// stw r30,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r30.u32);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824EC974:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x824ec974
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824EC974;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
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

__attribute__((alias("__imp__sub_824EC9A0"))) PPC_WEAK_FUNC(sub_824EC9A0);
PPC_FUNC_IMPL(__imp__sub_824EC9A0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EC9C8;
	sub_821C8FE0(ctx, base);
	// addi r4,r31,156
	ctx.r4.s64 = r31.s64 + 156;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eb708
	ctx.lr = 0x824EC9DC;
	sub_824EB708(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EC9E4;
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

__attribute__((alias("__imp__sub_824EC9FC"))) PPC_WEAK_FUNC(sub_824EC9FC);
PPC_FUNC_IMPL(__imp__sub_824EC9FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ECA00"))) PPC_WEAK_FUNC(sub_824ECA00);
PPC_FUNC_IMPL(__imp__sub_824ECA00) {
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
	ctx.lr = 0x824ECA08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mulli r11,r28,68
	r11.s64 = r28.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r11,184
	r29.s64 = r11.s64 + 184;
	// lwz r11,188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lbz r11,64(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 64);
	// bge cr6,0x824ecaac
	if (!cr6.lt) goto loc_824ECAAC;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ecac4
	if (!cr6.eq) goto loc_824ECAC4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ECA5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eca90
	if (cr6.eq) goto loc_824ECA90;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x825301e0
	ctx.lr = 0x824ECA78;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,26980
	ctx.r10.s64 = r11.s64 + 26980;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x824ec9a0
	ctx.lr = 0x824ECA90;
	sub_824EC9A0(ctx, base);
loc_824ECA90:
	// lbz r11,64(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 64);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,64(r29)
	PPC_STORE_U8(r29.u32 + 64, ctx.r10.u8);
	// rlwinm r3,r9,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824ECAAC:
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,64(r29)
	PPC_STORE_U8(r29.u32 + 64, ctx.r10.u8);
	// rlwinm r3,r9,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824ECAC4:
	// lbz r11,64(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 64);
	// rlwinm r3,r11,25,7,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824ECAD4"))) PPC_WEAK_FUNC(sub_824ECAD4);
PPC_FUNC_IMPL(__imp__sub_824ECAD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ECAD8"))) PPC_WEAK_FUNC(sub_824ECAD8);
PPC_FUNC_IMPL(__imp__sub_824ECAD8) {
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
	ctx.lr = 0x824ECAE0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// bl 0x821c8fe0
	ctx.lr = 0x824ECAF4;
	sub_821C8FE0(ctx, base);
	// addi r31,r31,72
	r31.s64 = r31.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824ec188
	ctx.lr = 0x824ECB04;
	sub_824EC188(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824ECB0C;
	sub_824E6310(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// bl 0x824e6310
	ctx.lr = 0x824ECB20;
	sub_824E6310(ctx, base);
	// lwz r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r8,136(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ld r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// stw r10,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r10.u32);
	// stw r8,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// bl 0x824e6310
	ctx.lr = 0x824ECB40;
	sub_824E6310(ctx, base);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// ld r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r5,152(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// beq cr6,0x824eccd4
	if (cr6.eq) goto loc_824ECCD4;
loc_824ECB64:
	// lwz r31,64(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ecbcc
	if (cr6.eq) goto loc_824ECBCC;
loc_824ECB78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82532898
	ctx.lr = 0x824ECB80;
	sub_82532898(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ecb90
	if (cr6.eq) goto loc_824ECB90;
	// lwz r31,128(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// b 0x824ecbc4
	goto loc_824ECBC4;
loc_824ECB90:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecbac
	if (cr6.eq) goto loc_824ECBAC;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ecbb0
	if (!cr6.eq) goto loc_824ECBB0;
loc_824ECBAC:
	// li r11,0
	r11.s64 = 0;
loc_824ECBB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecbcc
	if (cr6.eq) goto loc_824ECBCC;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_824ECBC4:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ecb78
	if (!cr6.eq) goto loc_824ECB78;
loc_824ECBCC:
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecc34
	if (cr6.eq) goto loc_824ECC34;
	// addi r30,r29,76
	r30.s64 = r29.s64 + 76;
loc_824ECBDC:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ecbf4
	if (cr6.eq) goto loc_824ECBF4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824ECBF4;
	sub_825D7AA0(ctx, base);
loc_824ECBF4:
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ECC10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824ECC28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,84(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ecbdc
	if (!cr6.eq) goto loc_824ECBDC;
loc_824ECC34:
	// lwz r11,96(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecc9c
	if (cr6.eq) goto loc_824ECC9C;
	// addi r30,r29,88
	r30.s64 = r29.s64 + 88;
loc_824ECC44:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ecc5c
	if (cr6.eq) goto loc_824ECC5C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824ECC5C;
	sub_825D7AA0(ctx, base);
loc_824ECC5C:
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ECC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824ECC90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,96(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ecc44
	if (!cr6.eq) goto loc_824ECC44;
loc_824ECC9C:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824ec218
	ctx.lr = 0x824ECCA8;
	sub_824EC218(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824ECCB0;
	sub_824E6310(ctx, base);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// ld r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r8,152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// bne cr6,0x824ecb64
	if (!cr6.eq) goto loc_824ECB64;
loc_824ECCD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824ECCDC;
	sub_821C9030(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824ECCE4"))) PPC_WEAK_FUNC(sub_824ECCE4);
PPC_FUNC_IMPL(__imp__sub_824ECCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ECCE8"))) PPC_WEAK_FUNC(sub_824ECCE8);
PPC_FUNC_IMPL(__imp__sub_824ECCE8) {
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
	ctx.lr = 0x824ECCF0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x824ecad8
	ctx.lr = 0x824ECCFC;
	sub_824ECAD8(ctx, base);
	// addi r31,r29,72
	r31.s64 = r29.s64 + 72;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824ec188
	ctx.lr = 0x824ECD0C;
	sub_824EC188(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824e6310
	ctx.lr = 0x824ECD14;
	sub_824E6310(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r31.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// bl 0x824e6310
	ctx.lr = 0x824ECD28;
	sub_824E6310(ctx, base);
	// lwz r10,156(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r8,152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// ld r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// stw r8,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r8.u32);
	// std r9,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r9.u64);
	// bl 0x824e6310
	ctx.lr = 0x824ECD48;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r7,124(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// ld r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lwz r5,168(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// stw r7,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// std r6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// beq cr6,0x824ece08
	if (cr6.eq) goto loc_824ECE08;
loc_824ECD6C:
	// lwz r31,64(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// addi r30,r11,64
	r30.s64 = r11.s64 + 64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ecdd0
	if (cr6.eq) goto loc_824ECDD0;
loc_824ECD7C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82532958
	ctx.lr = 0x824ECD84;
	sub_82532958(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ecd94
	if (cr6.eq) goto loc_824ECD94;
	// lwz r31,128(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// b 0x824ecdc8
	goto loc_824ECDC8;
loc_824ECD94:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecdb0
	if (cr6.eq) goto loc_824ECDB0;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ecdb4
	if (!cr6.eq) goto loc_824ECDB4;
loc_824ECDB0:
	// li r11,0
	r11.s64 = 0;
loc_824ECDB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecdd0
	if (cr6.eq) goto loc_824ECDD0;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_824ECDC8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ecd7c
	if (!cr6.eq) goto loc_824ECD7C;
loc_824ECDD0:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ec218
	ctx.lr = 0x824ECDDC;
	sub_824EC218(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824ECDE4;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// ld r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lwz r8,168(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// stw r10,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r10.u32);
	// std r9,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// bne cr6,0x824ecd6c
	if (!cr6.eq) goto loc_824ECD6C;
loc_824ECE08:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ECE28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ece78
	if (cr6.eq) goto loc_824ECE78;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x825301e0
	ctx.lr = 0x824ECE44;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r29,1292
	ctx.r4.s64 = r29.s64 + 1292;
	// addi r10,r11,26992
	ctx.r10.s64 = r11.s64 + 26992;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c8fe0
	ctx.lr = 0x824ECE5C;
	sub_821C8FE0(ctx, base);
	// addi r4,r29,156
	ctx.r4.s64 = r29.s64 + 156;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824eb708
	ctx.lr = 0x824ECE70;
	sub_824EB708(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824ECE78;
	sub_821C9030(ctx, base);
loc_824ECE78:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824ECE80"))) PPC_WEAK_FUNC(sub_824ECE80);
PPC_FUNC_IMPL(__imp__sub_824ECE80) {
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
	ctx.lr = 0x824ECE88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x824e6310
	ctx.lr = 0x824ECE9C;
	sub_824E6310(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r29,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r29.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// beq cr6,0x824ecec8
	if (cr6.eq) goto loc_824ECEC8;
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r10,116(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// b 0x824ececc
	goto loc_824ECECC;
loc_824ECEC8:
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
loc_824ECECC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824ec218
	ctx.lr = 0x824ECED8;
	sub_824EC218(ctx, base);
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ecf50
	if (cr6.eq) goto loc_824ECF50;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ecf50
	if (cr6.eq) goto loc_824ECF50;
	// lwz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ecf28
	if (cr6.eq) goto loc_824ECF28;
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ecf54
	if (cr6.eq) goto loc_824ECF54;
loc_824ECF14:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r10,104(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ecf14
	if (!cr6.eq) goto loc_824ECF14;
	// b 0x824ecf54
	goto loc_824ECF54;
loc_824ECF28:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ecf54
	if (cr6.eq) goto loc_824ECF54;
loc_824ECF38:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824ecf38
	if (!cr6.eq) goto loc_824ECF38;
	// b 0x824ecf54
	goto loc_824ECF54;
loc_824ECF50:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824ECF54:
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ecf68
	if (cr6.eq) goto loc_824ECF68;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// b 0x824ecf70
	goto loc_824ECF70;
loc_824ECF68:
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// rlwinm r4,r10,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
loc_824ECF70:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ecf80
	if (cr6.eq) goto loc_824ECF80;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r10,108(r4)
	PPC_STORE_U32(ctx.r4.u32 + 108, ctx.r10.u32);
loc_824ECF80:
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ecf94
	if (!cr6.eq) goto loc_824ECF94;
	// stw r4,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r4.u32);
	// b 0x824ecfb8
	goto loc_824ECFB8;
loc_824ECF94:
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x824ecfa8
	if (!cr6.eq) goto loc_824ECFA8;
	// stw r4,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, ctx.r4.u32);
	// b 0x824ecfb8
	goto loc_824ECFB8;
loc_824ECFA8:
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 | ctx.r4.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
loc_824ECFB8:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x824ed05c
	if (cr6.eq) goto loc_824ED05C;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x824ecfd4
	if (!cr6.eq) goto loc_824ECFD4;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x824ecffc
	goto loc_824ECFFC;
loc_824ECFD4:
	// lwz r10,108(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bne cr6,0x824ecfec
	if (!cr6.eq) goto loc_824ECFEC;
	// stw r11,104(r10)
	PPC_STORE_U32(ctx.r10.u32 + 104, r11.u32);
	// b 0x824ecffc
	goto loc_824ECFFC;
loc_824ECFEC:
	// lwz r9,100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,100(r10)
	PPC_STORE_U32(ctx.r10.u32 + 100, ctx.r7.u32);
loc_824ECFFC:
	// lwz r9,108(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r10,r11,100
	ctx.r10.s64 = r11.s64 + 100;
	// stw r9,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r9.u32);
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// stw r8,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r8.u32);
	// lwz r7,100(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// lwz r6,100(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwimi r7,r6,0,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// stw r7,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r7.u32);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r3,100(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwimi r10,r5,0,0,30
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0xFFFFFFFE) | (ctx.r10.u64 & 0xFFFFFFFF00000001);
	// stw r10,100(r11)
	PPC_STORE_U32(r11.u32 + 100, ctx.r10.u32);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ed044
	if (cr6.eq) goto loc_824ED044;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
loc_824ED044:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ed05c
	if (cr6.eq) goto loc_824ED05C;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,108(r10)
	PPC_STORE_U32(ctx.r10.u32 + 108, r11.u32);
loc_824ED05C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ed07c
	if (cr6.eq) goto loc_824ED07C;
	// lwz r11,100(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ed07c
	if (!cr6.eq) goto loc_824ED07C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824ec300
	ctx.lr = 0x824ED07C;
	sub_824EC300(ctx, base);
loc_824ED07C:
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r8.u32);
	// stw r8,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r8.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r7,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824ED0B0"))) PPC_WEAK_FUNC(sub_824ED0B0);
PPC_FUNC_IMPL(__imp__sub_824ED0B0) {
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
	ctx.lr = 0x824ED0B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r31,0(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ed0e8
	if (!cr6.eq) goto loc_824ED0E8;
	// stw r30,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r30.u32);
	// mr r28,r30
	r28.u64 = r30.u64;
	// b 0x824ed164
	goto loc_824ED164;
loc_824ED0E8:
	// addi r29,r31,112
	r29.s64 = r31.s64 + 112;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824e62a0
	ctx.lr = 0x824ED0F8;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ed118
	if (cr6.eq) goto loc_824ED118;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ed158
	if (!cr6.eq) goto loc_824ED158;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// b 0x824ed150
	goto loc_824ED150;
loc_824ED118:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e62a0
	ctx.lr = 0x824ED124;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ed164
	if (cr6.eq) goto loc_824ED164;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ed158
	if (!cr6.eq) goto loc_824ED158;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// or r8,r9,r30
	ctx.r8.u64 = ctx.r9.u64 | r30.u64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
loc_824ED150:
	// stw r31,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r31.u32);
	// mr r28,r30
	r28.u64 = r30.u64;
loc_824ED158:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ed0e8
	if (!cr6.eq) goto loc_824ED0E8;
loc_824ED164:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ed1a0
	if (cr6.eq) goto loc_824ED1A0;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,100(r30)
	PPC_STORE_U32(r30.u32 + 100, ctx.r10.u32);
	// bl 0x824ec618
	ctx.lr = 0x824ED184;
	sub_824EC618(ctx, base);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r9,112(r30)
	PPC_STORE_U32(r30.u32 + 112, ctx.r9.u32);
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stw r8,116(r30)
	PPC_STORE_U32(r30.u32 + 116, ctx.r8.u32);
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,4(r26)
	PPC_STORE_U32(r26.u32 + 4, ctx.r7.u32);
loc_824ED1A0:
	// addi r11,r28,0
	r11.s64 = r28.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r31,r9,1
	r31.u64 = ctx.r9.u64 ^ 1;
	// bl 0x824e6310
	ctx.lr = 0x824ED1B8;
	sub_824E6310(ctx, base);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ed1cc
	if (cr6.eq) goto loc_824ED1CC;
	// ld r10,112(r28)
	ctx.r10.u64 = PPC_LOAD_U64(r28.u32 + 112);
	// mr r11,r28
	r11.u64 = r28.u64;
	// b 0x824ed1d4
	goto loc_824ED1D4;
loc_824ED1CC:
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r11,0
	r11.s64 = 0;
loc_824ED1D4:
	// std r10,0(r25)
	PPC_STORE_U64(r25.u32 + 0, ctx.r10.u64);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,8(r25)
	PPC_STORE_U32(r25.u32 + 8, r11.u32);
	// stw r26,12(r25)
	PPC_STORE_U32(r25.u32 + 12, r26.u32);
	// stb r31,16(r25)
	PPC_STORE_U8(r25.u32 + 16, r31.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824ED1F0"))) PPC_WEAK_FUNC(sub_824ED1F0);
PPC_FUNC_IMPL(__imp__sub_824ED1F0) {
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
	ctx.lr = 0x824ED1F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r29,r24
	r29.u64 = r24.u64;
	// mr r28,r24
	r28.u64 = r24.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ed25c
	if (cr6.eq) goto loc_824ED25C;
loc_824ED224:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x824e62a0
	ctx.lr = 0x824ED230;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ed248
	if (cr6.eq) goto loc_824ED248;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r31,r11,0,0,30
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x824ed250
	goto loc_824ED250;
loc_824ED248:
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r31,104(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 104);
loc_824ED250:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ed224
	if (!cr6.eq) goto loc_824ED224;
loc_824ED25C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x824ed268
	if (cr6.eq) goto loc_824ED268;
	// stw r28,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r28.u32);
loc_824ED268:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6310
	ctx.lr = 0x824ED270;
	sub_824E6310(ctx, base);
	// stw r27,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r27.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r24,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r24.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824ed2a0
	if (cr6.eq) goto loc_824ED2A0;
	// lwz r11,112(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 112);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r10,116(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 116);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824ED2A0:
	// stw r24,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824ED2AC"))) PPC_WEAK_FUNC(sub_824ED2AC);
PPC_FUNC_IMPL(__imp__sub_824ED2AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ED2B0"))) PPC_WEAK_FUNC(sub_824ED2B0);
PPC_FUNC_IMPL(__imp__sub_824ED2B0) {
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
	ctx.lr = 0x824ED2B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r31,0
	r31.s64 = 0;
	// addi r9,r11,27012
	ctx.r9.s64 = r11.s64 + 27012;
	// li r29,1
	r29.s64 = 1;
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r10,r30,20
	ctx.r10.s64 = r30.s64 + 20;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
	// stw r31,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r31.u32);
	// stw r31,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r31.u32);
	// stw r31,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r31.u32);
	// stw r31,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r31.u32);
	// stw r29,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r29.u32);
	// stw r31,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r31.u32);
	// stw r31,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r31.u32);
loc_824ED304:
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r7,r9,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r9.u32);
	// stw r8,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r8.u32);
	// cmplwi cr6,r7,4
	cr6.compare<uint32_t>(ctx.r7.u32, 4, xer);
	// blt cr6,0x824ed304
	if (cr6.lt) goto loc_824ED304;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// addi r11,r30,84
	r11.s64 = r30.s64 + 84;
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// stw r31,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r31.u32);
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// stw r31,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r31.u32);
	// stw r31,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r31.u32);
	// stw r31,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r31.u32);
	// stw r31,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r31.u32);
	// stw r31,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r31.u32);
	// stw r31,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r31.u32);
	// stw r31,84(r30)
	PPC_STORE_U32(r30.u32 + 84, r31.u32);
	// stw r31,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r31.u32);
	// stw r31,92(r30)
	PPC_STORE_U32(r30.u32 + 92, r31.u32);
	// stw r31,96(r30)
	PPC_STORE_U32(r30.u32 + 96, r31.u32);
	// stw r29,100(r30)
	PPC_STORE_U32(r30.u32 + 100, r29.u32);
	// stw r31,104(r30)
	PPC_STORE_U32(r30.u32 + 104, r31.u32);
	// stw r31,108(r30)
	PPC_STORE_U32(r30.u32 + 108, r31.u32);
loc_824ED370:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// rotlwi r7,r10,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmplwi cr6,r7,4
	cr6.compare<uint32_t>(ctx.r7.u32, 4, xer);
	// blt cr6,0x824ed370
	if (cr6.lt) goto loc_824ED370;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r3,r30,124
	ctx.r3.s64 = r30.s64 + 124;
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// stw r31,112(r30)
	PPC_STORE_U32(r30.u32 + 112, r31.u32);
	// stw r31,116(r30)
	PPC_STORE_U32(r30.u32 + 116, r31.u32);
	// stw r31,120(r30)
	PPC_STORE_U32(r30.u32 + 120, r31.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x824ED3B0;
	sub_821C8ED8(ctx, base);
	// stw r31,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r31.u32);
	// stw r31,160(r30)
	PPC_STORE_U32(r30.u32 + 160, r31.u32);
	// stw r31,164(r30)
	PPC_STORE_U32(r30.u32 + 164, r31.u32);
	// bl 0x821c9788
	ctx.lr = 0x824ED3C0;
	sub_821C9788(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,168
	ctx.r3.s64 = r30.s64 + 168;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821ce460
	ctx.lr = 0x824ED3D0;
	sub_821CE460(ctx, base);
	// addi r5,r30,184
	ctx.r5.s64 = r30.s64 + 184;
	// li r4,4
	ctx.r4.s64 = 4;
	// addi r11,r5,20
	r11.s64 = ctx.r5.s64 + 20;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r6,250
	ctx.r6.s64 = 250;
	// li r7,20
	ctx.r7.s64 = 20;
	// li r8,1000
	ctx.r8.s64 = 1000;
	// li r9,5000
	ctx.r9.s64 = 5000;
loc_824ED3F0:
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r31,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r31.u32);
	// addi r5,r5,272
	ctx.r5.s64 = ctx.r5.s64 + 272;
	// stw r31,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, r31.u32);
	// stw r6,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r6.u32);
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stb r29,8(r11)
	PPC_STORE_U8(r11.u32 + 8, r29.u8);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// stw r31,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r31.u32);
	// stw r31,28(r11)
	PPC_STORE_U32(r11.u32 + 28, r31.u32);
	// stw r31,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r31.u32);
	// lbz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 44);
	// clrlwi r3,r3,25
	ctx.r3.u64 = ctx.r3.u32 & 0x7F;
	// stb r3,44(r11)
	PPC_STORE_U8(r11.u32 + 44, ctx.r3.u8);
	// stw r29,36(r11)
	PPC_STORE_U32(r11.u32 + 36, r29.u32);
	// stw r31,40(r11)
	PPC_STORE_U32(r11.u32 + 40, r31.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r31,52(r11)
	PPC_STORE_U32(r11.u32 + 52, r31.u32);
	// stw r31,56(r11)
	PPC_STORE_U32(r11.u32 + 56, r31.u32);
	// stw r6,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r6.u32);
	// stw r7,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r7.u32);
	// stw r8,68(r11)
	PPC_STORE_U32(r11.u32 + 68, ctx.r8.u32);
	// stw r9,72(r11)
	PPC_STORE_U32(r11.u32 + 72, ctx.r9.u32);
	// stb r29,76(r11)
	PPC_STORE_U8(r11.u32 + 76, r29.u8);
	// stw r31,80(r11)
	PPC_STORE_U32(r11.u32 + 80, r31.u32);
	// stw r31,84(r11)
	PPC_STORE_U32(r11.u32 + 84, r31.u32);
	// stw r31,88(r11)
	PPC_STORE_U32(r11.u32 + 88, r31.u32);
	// stw r31,92(r11)
	PPC_STORE_U32(r11.u32 + 92, r31.u32);
	// stw r31,96(r11)
	PPC_STORE_U32(r11.u32 + 96, r31.u32);
	// stw r31,100(r11)
	PPC_STORE_U32(r11.u32 + 100, r31.u32);
	// lbz r3,112(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// clrlwi r3,r3,25
	ctx.r3.u64 = ctx.r3.u32 & 0x7F;
	// stb r3,112(r11)
	PPC_STORE_U8(r11.u32 + 112, ctx.r3.u8);
	// stw r29,104(r11)
	PPC_STORE_U32(r11.u32 + 104, r29.u32);
	// stw r31,108(r11)
	PPC_STORE_U32(r11.u32 + 108, r31.u32);
	// stw r10,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r10.u32);
	// stw r31,120(r11)
	PPC_STORE_U32(r11.u32 + 120, r31.u32);
	// stw r31,124(r11)
	PPC_STORE_U32(r11.u32 + 124, r31.u32);
	// stw r6,128(r11)
	PPC_STORE_U32(r11.u32 + 128, ctx.r6.u32);
	// stw r7,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r7.u32);
	// stw r8,136(r11)
	PPC_STORE_U32(r11.u32 + 136, ctx.r8.u32);
	// stw r9,140(r11)
	PPC_STORE_U32(r11.u32 + 140, ctx.r9.u32);
	// stb r29,144(r11)
	PPC_STORE_U8(r11.u32 + 144, r29.u8);
	// stw r31,148(r11)
	PPC_STORE_U32(r11.u32 + 148, r31.u32);
	// stw r31,152(r11)
	PPC_STORE_U32(r11.u32 + 152, r31.u32);
	// stw r31,156(r11)
	PPC_STORE_U32(r11.u32 + 156, r31.u32);
	// stw r31,160(r11)
	PPC_STORE_U32(r11.u32 + 160, r31.u32);
	// stw r31,164(r11)
	PPC_STORE_U32(r11.u32 + 164, r31.u32);
	// stw r31,168(r11)
	PPC_STORE_U32(r11.u32 + 168, r31.u32);
	// lbz r3,180(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 180);
	// clrlwi r3,r3,25
	ctx.r3.u64 = ctx.r3.u32 & 0x7F;
	// stb r3,180(r11)
	PPC_STORE_U8(r11.u32 + 180, ctx.r3.u8);
	// stw r29,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r29.u32);
	// stw r31,176(r11)
	PPC_STORE_U32(r11.u32 + 176, r31.u32);
	// stw r10,184(r11)
	PPC_STORE_U32(r11.u32 + 184, ctx.r10.u32);
	// stw r31,188(r11)
	PPC_STORE_U32(r11.u32 + 188, r31.u32);
	// stw r31,192(r11)
	PPC_STORE_U32(r11.u32 + 192, r31.u32);
	// stw r6,196(r11)
	PPC_STORE_U32(r11.u32 + 196, ctx.r6.u32);
	// stw r7,200(r11)
	PPC_STORE_U32(r11.u32 + 200, ctx.r7.u32);
	// stw r8,204(r11)
	PPC_STORE_U32(r11.u32 + 204, ctx.r8.u32);
	// stw r9,208(r11)
	PPC_STORE_U32(r11.u32 + 208, ctx.r9.u32);
	// stb r29,212(r11)
	PPC_STORE_U8(r11.u32 + 212, r29.u8);
	// stw r31,216(r11)
	PPC_STORE_U32(r11.u32 + 216, r31.u32);
	// stw r31,220(r11)
	PPC_STORE_U32(r11.u32 + 220, r31.u32);
	// stw r31,224(r11)
	PPC_STORE_U32(r11.u32 + 224, r31.u32);
	// stw r31,228(r11)
	PPC_STORE_U32(r11.u32 + 228, r31.u32);
	// stw r31,232(r11)
	PPC_STORE_U32(r11.u32 + 232, r31.u32);
	// stw r31,236(r11)
	PPC_STORE_U32(r11.u32 + 236, r31.u32);
	// lbz r3,248(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 248);
	// clrlwi r3,r3,25
	ctx.r3.u64 = ctx.r3.u32 & 0x7F;
	// stw r29,240(r11)
	PPC_STORE_U32(r11.u32 + 240, r29.u32);
	// stw r31,244(r11)
	PPC_STORE_U32(r11.u32 + 244, r31.u32);
	// stb r3,248(r11)
	PPC_STORE_U8(r11.u32 + 248, ctx.r3.u8);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// bne 0x824ed3f0
	if (!cr0.eq) goto loc_824ED3F0;
	// lbz r10,1288(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 1288);
	// li r11,-1
	r11.s64 = -1;
	// stw r31,1272(r30)
	PPC_STORE_U32(r30.u32 + 1272, r31.u32);
	// addi r3,r30,1292
	ctx.r3.s64 = r30.s64 + 1292;
	// rlwimi r10,r29,7,0,25
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 7) & 0xFFFFFFC0) | (ctx.r10.u64 & 0xFFFFFFFF0000003F);
	// stw r11,1280(r30)
	PPC_STORE_U32(r30.u32 + 1280, r11.u32);
	// stw r11,1284(r30)
	PPC_STORE_U32(r30.u32 + 1284, r11.u32);
	// addi r11,r30,1272
	r11.s64 = r30.s64 + 1272;
	// stw r31,1276(r30)
	PPC_STORE_U32(r30.u32 + 1276, r31.u32);
	// stb r10,1288(r30)
	PPC_STORE_U8(r30.u32 + 1288, ctx.r10.u8);
	// bl 0x821c8ed8
	ctx.lr = 0x824ED55C;
	sub_821C8ED8(ctx, base);
	// stw r31,1324(r30)
	PPC_STORE_U32(r30.u32 + 1324, r31.u32);
	// sth r31,1328(r30)
	PPC_STORE_U16(r30.u32 + 1328, r31.u16);
	// addi r11,r30,1332
	r11.s64 = r30.s64 + 1332;
	// stw r31,1332(r30)
	PPC_STORE_U32(r30.u32 + 1332, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r9,1336(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 1336);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// stb r8,1336(r30)
	PPC_STORE_U8(r30.u32 + 1336, ctx.r8.u8);
	// stw r31,1332(r30)
	PPC_STORE_U32(r30.u32 + 1332, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824ED588"))) PPC_WEAK_FUNC(sub_824ED588);
PPC_FUNC_IMPL(__imp__sub_824ED588) {
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
	ctx.lr = 0x824ED590;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// lwz r11,8(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ed688
	if (cr6.eq) goto loc_824ED688;
loc_824ED5B8:
	// cmplwi cr6,r28,9
	cr6.compare<uint32_t>(r28.u32, 9, xer);
	// blt cr6,0x824ed688
	if (cr6.lt) goto loc_824ED688;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82534318
	ctx.lr = 0x824ED5CC;
	sub_82534318(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// bgt cr6,0x824ed688
	if (cr6.gt) goto loc_824ED688;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x825340d0
	ctx.lr = 0x824ED5E0;
	sub_825340D0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x824eca00
	ctx.lr = 0x824ED5F0;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ed634
	if (!cr6.eq) goto loc_824ED634;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824ED60C;
	sub_8244D5C0(ctx, base);
	// mulli r11,r27,68
	r11.s64 = r27.s64 * 68;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb858
	ctx.lr = 0x824ED628;
	sub_824EB858(ctx, base);
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
	// subf r28,r31,r28
	r28.s64 = r28.s64 - r31.s64;
	// add r26,r31,r26
	r26.u64 = r31.u64 + r26.u64;
loc_824ED634:
	// lwz r4,0(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ed648
	if (cr6.eq) goto loc_824ED648;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824ED648;
	sub_825D7AA0(ctx, base);
loc_824ED648:
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED664;
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
	ctx.lr = 0x824ED67C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,8(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ed5b8
	if (!cr6.eq) goto loc_824ED5B8;
loc_824ED688:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824ED694"))) PPC_WEAK_FUNC(sub_824ED694);
PPC_FUNC_IMPL(__imp__sub_824ED694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ED698"))) PPC_WEAK_FUNC(sub_824ED698);
PPC_FUNC_IMPL(__imp__sub_824ED698) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824ED6C0;
	sub_821C8FE0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ece80
	ctx.lr = 0x824ED6D0;
	sub_824ECE80(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x824eb308
	ctx.lr = 0x824ED6DC;
	sub_824EB308(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// stw r11,132(r30)
	PPC_STORE_U32(r30.u32 + 132, r11.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824eacc8
	ctx.lr = 0x824ED6F8;
	sub_824EACC8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824ED700;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_824ED718"))) PPC_WEAK_FUNC(sub_824ED718);
PPC_FUNC_IMPL(__imp__sub_824ED718) {
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
	ctx.lr = 0x824ED720;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r24,0
	r24.s64 = 0;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,52
	ctx.r4.s64 = 52;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ed830
	if (cr6.eq) goto loc_824ED830;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82534420
	ctx.lr = 0x824ED76C;
	sub_82534420(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824ED794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824ed818
	if (cr6.eq) goto loc_824ED818;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82534480
	ctx.lr = 0x824ED7A8;
	sub_82534480(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824ED7B8;
	sub_8244D5C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82534348
	ctx.lr = 0x824ED7C0;
	sub_82534348(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825301e0
	ctx.lr = 0x824ED7D8;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r10,r11,26932
	ctx.r10.s64 = r11.s64 + 26932;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
	// lwz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// stw r8,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r8.u32);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r27,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r27.u32);
	// sth r29,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r29.u16);
	// bl 0x824ec9a0
	ctx.lr = 0x824ED80C;
	sub_824EC9A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824ED818:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED830;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824ED830:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824ED83C"))) PPC_WEAK_FUNC(sub_824ED83C);
PPC_FUNC_IMPL(__imp__sub_824ED83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ED840"))) PPC_WEAK_FUNC(sub_824ED840);
PPC_FUNC_IMPL(__imp__sub_824ED840) {
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
	ctx.lr = 0x824ED848;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r24,0
	r24.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,56
	ctx.r4.s64 = 56;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ed920
	if (cr6.eq) goto loc_824ED920;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED8B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ed908
	if (cr6.eq) goto loc_824ED908;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824ED8C8;
	sub_8244D5C0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea6a8
	ctx.lr = 0x824ED8F0;
	sub_824EA6A8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ec9a0
	ctx.lr = 0x824ED8FC;
	sub_824EC9A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824ED908:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824ED920:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824ED92C"))) PPC_WEAK_FUNC(sub_824ED92C);
PPC_FUNC_IMPL(__imp__sub_824ED92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824ED930"))) PPC_WEAK_FUNC(sub_824ED930);
PPC_FUNC_IMPL(__imp__sub_824ED930) {
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
	ctx.lr = 0x824ED938;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// li r24,0
	r24.s64 = 0;
	// mr r22,r24
	r22.u64 = r24.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r11,r21
	ctx.r10.u64 = r11.u64 + r21.u64;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// srw r30,r9,r7
	r30.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r7.u8 & 0x3F));
	// andc r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r8.u64;
	// srw r23,r10,r7
	r23.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x824edadc
	if (!cr6.gt) goto loc_824EDADC;
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// bgt cr6,0x824edc84
	if (cr6.gt) goto loc_824EDC84;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824edc84
	if (cr6.lt) goto loc_824EDC84;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED9C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824edc84
	if (cr6.eq) goto loc_824EDC84;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r22,1
	r22.s64 = 1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ed9fc
	if (cr6.eq) goto loc_824ED9FC;
	// rlwinm r5,r30,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8244d5c0
	ctx.lr = 0x824ED9E4;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824ED9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824ED9FC:
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mr r27,r30
	r27.u64 = r30.u64;
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// bge cr6,0x824edc84
	if (!cr6.lt) goto loc_824EDC84;
	// rlwinm r29,r30,2,0,29
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_824EDA10:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r24,r29,r11
	PPC_STORE_U32(r29.u32 + r11.u32, r24.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mulli r30,r10,136
	r30.s64 = ctx.r10.s64 * 136;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824EDA34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// blt cr6,0x824eda64
	if (cr6.lt) goto loc_824EDA64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	ctx.lr = 0x824EDA5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stwx r3,r29,r9
	PPC_STORE_U32(r29.u32 + ctx.r9.u32, ctx.r3.u32);
loc_824EDA64:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824edad4
	if (cr6.eq) goto loc_824EDAD4;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r28,r24
	r28.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824edab0
	if (!cr6.gt) goto loc_824EDAB0;
	// mr r30,r24
	r30.u64 = r24.u64;
loc_824EDA88:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// add. r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x824eda9c
	if (cr0.eq) goto loc_824EDA9C;
	// bl 0x824ec900
	ctx.lr = 0x824EDA9C;
	sub_824EC900(ctx, base);
loc_824EDA9C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,136
	r30.s64 = r30.s64 + 136;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x824eda88
	if (cr6.lt) goto loc_824EDA88;
loc_824EDAB0:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r27,r23
	cr6.compare<uint32_t>(r27.u32, r23.u32, xer);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// blt cr6,0x824eda10
	if (cr6.lt) goto loc_824EDA10;
	// b 0x824edc84
	goto loc_824EDC84;
loc_824EDAD4:
	// mr r22,r24
	r22.u64 = r24.u64;
	// b 0x824edc84
	goto loc_824EDC84;
loc_824EDADC:
	// bge cr6,0x824edc80
	if (!cr6.lt) goto loc_824EDC80;
	// cmplw cr6,r23,r30
	cr6.compare<uint32_t>(r23.u32, r30.u32, xer);
	// bge cr6,0x824edbec
	if (!cr6.lt) goto loc_824EDBEC;
	// rlwinm r27,r23,2,0,29
	r27.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r25,r23,r30
	r25.s64 = r30.s64 - r23.s64;
loc_824EDAF0:
	// mr r26,r24
	r26.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edbb4
	if (cr6.eq) goto loc_824EDBB4;
	// mr r28,r24
	r28.u64 = r24.u64;
loc_824EDB00:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r27,r11
	r11.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// add r29,r11,r28
	r29.u64 = r11.u64 + r28.u64;
	// addi r30,r29,88
	r30.s64 = r29.s64 + 88;
	// stw r24,132(r29)
	PPC_STORE_U32(r29.u32 + 132, r24.u32);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824edb40
	if (cr6.eq) goto loc_824EDB40;
loc_824EDB20:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824edb34
	if (cr6.eq) goto loc_824EDB34;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824EDB34;
	sub_825D7AA0(ctx, base);
loc_824EDB34:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824edb20
	if (!cr6.eq) goto loc_824EDB20;
loc_824EDB40:
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// addi r30,r29,76
	r30.s64 = r29.s64 + 76;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edb70
	if (cr6.eq) goto loc_824EDB70;
loc_824EDB50:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824edb64
	if (cr6.eq) goto loc_824EDB64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825d7aa0
	ctx.lr = 0x824EDB64;
	sub_825D7AA0(ctx, base);
loc_824EDB64:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824edb50
	if (!cr6.eq) goto loc_824EDB50;
loc_824EDB70:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r30,r29,64
	r30.s64 = r29.s64 + 64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edba0
	if (cr6.eq) goto loc_824EDBA0;
loc_824EDB80:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824edb94
	if (cr6.eq) goto loc_824EDB94;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EDB94;
	sub_824EB108(ctx, base);
loc_824EDB94:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824edb80
	if (!cr6.eq) goto loc_824EDB80;
loc_824EDBA0:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,136
	r28.s64 = r28.s64 + 136;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x824edb00
	if (cr6.lt) goto loc_824EDB00;
loc_824EDBB4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r4,r27,r11
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EDBD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// bne 0x824edaf0
	if (!cr0.eq) goto loc_824EDAF0;
loc_824EDBEC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x824edc6c
	if (cr6.eq) goto loc_824EDC6C;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r29,r23,2,0,29
	r29.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EDC0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// blt cr6,0x824edc84
	if (cr6.lt) goto loc_824EDC84;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EDC34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824edc84
	if (cr6.eq) goto loc_824EDC84;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8244d5c0
	ctx.lr = 0x824EDC4C;
	sub_8244D5C0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EDC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// b 0x824edc80
	goto loc_824EDC80;
loc_824EDC6C:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EDC7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r24,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r24.u32);
loc_824EDC80:
	// li r22,1
	r22.s64 = 1;
loc_824EDC84:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edca0
	if (cr6.eq) goto loc_824EDCA0;
	// stw r21,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r21.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_824EDCA0:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// ble cr6,0x824edcb4
	if (!cr6.gt) goto loc_824EDCB4;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_824EDCB4:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824EDCC0"))) PPC_WEAK_FUNC(sub_824EDCC0);
PPC_FUNC_IMPL(__imp__sub_824EDCC0) {
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
	ctx.lr = 0x824EDCC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x824ed1f0
	ctx.lr = 0x824EDCE0;
	sub_824ED1F0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EDCE8;
	sub_824E6310(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r28,0
	r28.s64 = 0;
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// beq cr6,0x824edd20
	if (cr6.eq) goto loc_824EDD20;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e62a0
	ctx.lr = 0x824EDD0C;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824edd20
	if (!cr6.eq) goto loc_824EDD20;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// b 0x824edd34
	goto loc_824EDD34;
loc_824EDD20:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EDD28;
	sub_824E6310(ctx, base);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
loc_824EDD34:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDD60"))) PPC_WEAK_FUNC(sub_824EDD60);
PPC_FUNC_IMPL(__imp__sub_824EDD60) {
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
	ctx.lr = 0x824EDD68;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EDD80;
	sub_821C8FE0(ctx, base);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824edde8
	if (!cr6.eq) goto loc_824EDDE8;
	// lwz r29,28(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// addi r4,r29,1
	ctx.r4.s64 = r29.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ed930
	ctx.lr = 0x824EDDA0;
	sub_824ED930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eddc0
	if (!cr6.eq) goto loc_824EDDC0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDDB4;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_824EDDC0:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// srw r8,r29,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r29.u32 >> (r11.u8 & 0x3F));
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r5,r7,r29
	ctx.r5.u64 = ctx.r7.u64 & r29.u64;
	// mulli r10,r5,136
	ctx.r10.s64 = ctx.r5.s64 * 136;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// b 0x824ede00
	goto loc_824EDE00;
loc_824EDDE8:
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// extsw r30,r4
	r30.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ede00
	if (cr6.eq) goto loc_824EDE00;
	// bl 0x824eb308
	ctx.lr = 0x824EDE00;
	sub_824EB308(ctx, base);
loc_824EDE00:
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// bl 0x824ed0b0
	ctx.lr = 0x824EDE20;
	sub_824ED0B0(ctx, base);
	// addi r4,r31,60
	ctx.r4.s64 = r31.s64 + 60;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eacc8
	ctx.lr = 0x824EDE34;
	sub_824EACC8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDE3C;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDE48"))) PPC_WEAK_FUNC(sub_824EDE48);
PPC_FUNC_IMPL(__imp__sub_824EDE48) {
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
	ctx.lr = 0x824EDE50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r28,1292
	ctx.r4.s64 = r28.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EDE68;
	sub_821C8FE0(ctx, base);
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eded0
	if (!cr6.eq) goto loc_824EDED0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EDE80;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ede90
	if (cr6.lt) goto loc_824EDE90;
	// li r11,0
	r11.s64 = 0;
loc_824EDE90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eded0
	if (!cr6.eq) goto loc_824EDED0;
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824edec0
	if (!cr6.eq) goto loc_824EDEC0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EDEB4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824edec4
	if (cr6.eq) goto loc_824EDEC4;
loc_824EDEC0:
	// li r11,0
	r11.s64 = 0;
loc_824EDEC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824edf40
	if (cr6.eq) goto loc_824EDF40;
loc_824EDED0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EDED8;
	sub_821F6C70(ctx, base);
	// addi r31,r28,72
	r31.s64 = r28.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824edcc0
	ctx.lr = 0x824EDEF0;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EDEF8;
	sub_824E6310(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// lwz r29,104(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r3,r29,64
	ctx.r3.s64 = r29.s64 + 64;
	// bl 0x824eb108
	ctx.lr = 0x824EDF14;
	sub_824EB108(ctx, base);
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824edf2c
	if (!cr6.eq) goto loc_824EDF2C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824ed698
	ctx.lr = 0x824EDF2C;
	sub_824ED698(ctx, base);
loc_824EDF2C:
	// lbz r11,144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 144);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,144(r30)
	PPC_STORE_U8(r30.u32 + 144, ctx.r10.u8);
	// bl 0x82533130
	ctx.lr = 0x824EDF40;
	sub_82533130(ctx, base);
loc_824EDF40:
	// addi r4,r28,112
	ctx.r4.s64 = r28.s64 + 112;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824eac30
	ctx.lr = 0x824EDF54;
	sub_824EAC30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDF5C;
	sub_821C9030(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDF64"))) PPC_WEAK_FUNC(sub_824EDF64);
PPC_FUNC_IMPL(__imp__sub_824EDF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EDF68"))) PPC_WEAK_FUNC(sub_824EDF68);
PPC_FUNC_IMPL(__imp__sub_824EDF68) {
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
	ctx.lr = 0x824EDF70;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EDF8C;
	sub_821C8FE0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r28,15
	cr6.compare<uint32_t>(r28.u32, 15, xer);
	// bgt cr6,0x824edfd4
	if (cr6.gt) goto loc_824EDFD4;
	// addi r31,r31,72
	r31.s64 = r31.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EDFB0;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EDFB8;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// beq cr6,0x824edfd4
	if (cr6.eq) goto loc_824EDFD4;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
loc_824EDFD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EDFDC;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EDFE8"))) PPC_WEAK_FUNC(sub_824EDFE8);
PPC_FUNC_IMPL(__imp__sub_824EDFE8) {
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
	ctx.lr = 0x824EDFF0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE018;
	sub_821C8FE0(ctx, base);
	// li r23,0
	r23.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r23
	r29.u64 = r23.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EE02C;
	sub_824EAFA0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ee058
	if (!cr6.eq) goto loc_824EE058;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE04C;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ee05c
	if (cr6.eq) goto loc_824EE05C;
loc_824EE058:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824EE05C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee08c
	if (!cr6.eq) goto loc_824EE08C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE070;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ee080
	if (cr6.lt) goto loc_824EE080;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_824EE080:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
loc_824EE08C:
	// clrlwi r24,r25,31
	r24.u64 = r25.u32 & 0x1;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x824ee0b8
	if (!cr6.eq) goto loc_824EE0B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EE0A0;
	sub_82618698(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EE0AC;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee15c
	if (!cr6.eq) goto loc_824EE15C;
loc_824EE0B8:
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EE0D0;
	sub_82533190(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee10c
	if (!cr6.eq) goto loc_824EE10C;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824ee10c
	if (cr6.eq) goto loc_824EE10C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ecad8
	ctx.lr = 0x824EE0F0;
	sub_824ECAD8(ctx, base);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EE108;
	sub_82533190(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_824EE10C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// rlwinm r11,r25,0,7,7
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 0) & 0x1000000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee15c
	if (cr6.eq) goto loc_824EE15C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EE12C;
	sub_821F6C70(ctx, base);
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EE144;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EE14C;
	sub_824E6310(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r23,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r23.u32);
	// stw r23,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r23.u32);
loc_824EE15C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee178
	if (!cr6.eq) goto loc_824EE178;
	// clrlwi r11,r25,31
	r11.u64 = r25.u32 & 0x1;
	// mr r31,r23
	r31.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee17c
	if (!cr6.eq) goto loc_824EE17C;
loc_824EE178:
	// li r31,1
	r31.s64 = 1;
loc_824EE17C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EE184;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_824EE190"))) PPC_WEAK_FUNC(sub_824EE190);
PPC_FUNC_IMPL(__imp__sub_824EE190) {
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
	ctx.lr = 0x824EE198;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE1B4;
	sub_821C8FE0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EE1C4;
	sub_824EDF68(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ee1e8
	if (cr6.eq) goto loc_824EE1E8;
	// bl 0x82656bf8
	ctx.lr = 0x824EE1D0;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EE1DC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824EE1E8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EE1F4;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EE200"))) PPC_WEAK_FUNC(sub_824EE200);
PPC_FUNC_IMPL(__imp__sub_824EE200) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824EE208;
	// stwu r1,-1328(r1)
	ea = -1328 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r14,r4
	r14.u64 = ctx.r4.u64;
	// addi r4,r25,1292
	ctx.r4.s64 = r25.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE22C;
	sub_821C8FE0(ctx, base);
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// blt cr6,0x824ee5b8
	if (cr6.lt) goto loc_824EE5B8;
	// cmplwi cr6,r30,1024
	cr6.compare<uint32_t>(r30.u32, 1024, xer);
	// bgt cr6,0x824ee5b8
	if (cr6.gt) goto loc_824EE5B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EE248;
	sub_82533EF0(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bgt cr6,0x824ee5b8
	if (cr6.gt) goto loc_824EE5B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EE258;
	sub_82533EF0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r27,r28,r30
	r27.s64 = r30.s64 - r28.s64;
	// bl 0x82533f58
	ctx.lr = 0x824EE268;
	sub_82533F58(ctx, base);
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee294
	if (cr6.eq) goto loc_824EE294;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ea950
	ctx.lr = 0x824EE288;
	sub_824EA950(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ee5b8
	if (cr6.eq) goto loc_824EE5B8;
loc_824EE294:
	// addi r30,r25,72
	r30.s64 = r25.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EE2AC;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EE2B4;
	sub_824E6310(ctx, base);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// li r16,0
	r16.s64 = 0;
	// lwz r17,136(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r16,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r16.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r16,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r16.u32);
	// stw r16,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r16.u32);
	// std r16,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, r16.u64);
	// beq cr6,0x824ee300
	if (cr6.eq) goto loc_824EE300;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EE2E8;
	sub_82533FC0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// bl 0x82533f20
	ctx.lr = 0x824EE2F8;
	sub_82533F20(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_824EE300:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824ee318
	if (cr6.eq) goto loc_824EE318;
	// add r11,r28,r31
	r11.u64 = r28.u64 + r31.u64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_824EE318:
	// li r20,2
	r20.s64 = 2;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r18,r1,84
	r18.s64 = ctx.r1.s64 + 84;
	// mr r15,r20
	r15.u64 = r20.u64;
	// li r19,1
	r19.s64 = 1;
	// addi r21,r11,26944
	r21.s64 = r11.s64 + 26944;
loc_824EE330:
	// lwz r31,-4(r18)
	r31.u64 = PPC_LOAD_U32(r18.u32 + -4);
	// lwz r22,0(r18)
	r22.u64 = PPC_LOAD_U32(r18.u32 + 0);
	// cmplw cr6,r31,r22
	cr6.compare<uint32_t>(r31.u32, r22.u32, xer);
	// bge cr6,0x824ee5ac
	if (!cr6.lt) goto loc_824EE5AC;
loc_824EE340:
	// subf r30,r31,r22
	r30.s64 = r22.s64 - r31.s64;
	// cmplwi cr6,r30,9
	cr6.compare<uint32_t>(r30.u32, 9, xer);
	// blt cr6,0x824ee5ac
	if (cr6.lt) goto loc_824EE5AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE354;
	sub_82534318(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplw cr6,r24,r30
	cr6.compare<uint32_t>(r24.u32, r30.u32, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// cmplwi cr6,r24,9
	cr6.compare<uint32_t>(r24.u32, 9, xer);
	// blt cr6,0x824ee5ac
	if (cr6.lt) goto loc_824EE5AC;
	// cmplwi cr6,r24,1021
	cr6.compare<uint32_t>(r24.u32, 1021, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE378;
	sub_825340D0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,15
	cr6.compare<uint32_t>(r28.u32, 15, xer);
	// bgt cr6,0x824ee5ac
	if (cr6.gt) goto loc_824EE5AC;
	// mulli r11,r28,68
	r11.s64 = r28.s64 * 68;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb8e0
	ctx.lr = 0x824EE3A0;
	sub_824EB8E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340a0
	ctx.lr = 0x824EE3A8;
	sub_825340A0(ctx, base);
	// rlwinm r11,r3,0,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee550
	if (!cr6.eq) goto loc_824EE550;
	// cmplwi cr6,r17,0
	cr6.compare<uint32_t>(r17.u32, 0, xer);
	// beq cr6,0x824ee3cc
	if (cr6.eq) goto loc_824EE3CC;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r11,r17
	r27.u64 = PPC_LOAD_U32(r11.u32 + r17.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x824ee45c
	if (!cr6.eq) goto loc_824EE45C;
loc_824EE3CC:
	// rlwinm r11,r28,27,5,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r10,r28,27
	ctx.r10.u64 = r28.u32 & 0x1F;
	// addi r9,r11,333
	ctx.r9.s64 = r11.s64 + 333;
	// slw r8,r19,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (r19.u32 << (ctx.r10.u8 & 0x3F));
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r25
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r25.u32);
	// and r5,r8,r6
	ctx.r5.u64 = ctx.r8.u64 & ctx.r6.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825341a0
	ctx.lr = 0x824EE3F8;
	sub_825341A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE40C;
	sub_82534068(ctx, base);
	// cmplwi cr6,r3,6
	cr6.compare<uint32_t>(ctx.r3.u32, 6, xer);
	// blt cr6,0x824ee5a0
	if (cr6.lt) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE41C;
	sub_82534248(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE424;
	sub_82534318(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825344c8
	ctx.lr = 0x824EE430;
	sub_825344C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE444;
	sub_825340D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x824ed718
	ctx.lr = 0x824EE458;
	sub_824ED718(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE45C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EE464;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534210
	ctx.lr = 0x824EE474;
	sub_82534210(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee538
	if (cr6.eq) goto loc_824EE538;
	// lwz r3,12(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,168
	ctx.r4.s64 = 168;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ee52c
	if (cr6.eq) goto loc_824EE52C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE4B4;
	sub_82534068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ee4cc
	if (cr6.eq) goto loc_824EE4CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE4C4;
	sub_82534248(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x824ee4d0
	goto loc_824EE4D0;
loc_824EE4CC:
	// mr r26,r16
	r26.u64 = r16.u64;
loc_824EE4D0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE4D8;
	sub_82534068(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EE4E4;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,12(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EE4F8;
	sub_825301E0(ctx, base);
	// stw r29,164(r30)
	PPC_STORE_U32(r30.u32 + 164, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r20,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r20.u32);
	// stw r21,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r21.u32);
	// beq cr6,0x824ee51c
	if (cr6.eq) goto loc_824EE51C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE51C;
	sub_8244D5C0(ctx, base);
loc_824EE51C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ec9a0
	ctx.lr = 0x824EE528;
	sub_824EC9A0(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE52C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EE534;
	sub_824ECCE8(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE538:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x825337f0
	ctx.lr = 0x824EE54C;
	sub_825337F0(ctx, base);
	// b 0x824ee5a0
	goto loc_824EE5A0;
loc_824EE550:
	// cmplwi cr6,r24,9
	cr6.compare<uint32_t>(r24.u32, 9, xer);
	// ble cr6,0x824ee5a0
	if (!cr6.gt) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534068
	ctx.lr = 0x824EE560;
	sub_82534068(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,1012
	cr6.compare<uint32_t>(r30.u32, 1012, xer);
	// bgt cr6,0x824ee5a0
	if (cr6.gt) goto loc_824EE5A0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ee5a0
	if (cr6.eq) goto loc_824EE5A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE57C;
	sub_82534248(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825340d0
	ctx.lr = 0x824EE588;
	sub_825340D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x824ed840
	ctx.lr = 0x824EE5A0;
	sub_824ED840(ctx, base);
loc_824EE5A0:
	// add r31,r24,r31
	r31.u64 = r24.u64 + r31.u64;
	// cmplw cr6,r31,r22
	cr6.compare<uint32_t>(r31.u32, r22.u32, xer);
	// blt cr6,0x824ee340
	if (cr6.lt) goto loc_824EE340;
loc_824EE5AC:
	// addic. r15,r15,-1
	xer.ca = r15.u32 > 0;
	r15.s64 = r15.s64 + -1;
	cr0.compare<int32_t>(r15.s32, 0, xer);
	// addi r18,r18,8
	r18.s64 = r18.s64 + 8;
	// bne 0x824ee330
	if (!cr0.eq) goto loc_824EE330;
loc_824EE5B8:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EE5C0;
	sub_821C9030(ctx, base);
	// addi r1,r1,1328
	ctx.r1.s64 = ctx.r1.s64 + 1328;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824EE5C8"))) PPC_WEAK_FUNC(sub_824EE5C8);
PPC_FUNC_IMPL(__imp__sub_824EE5C8) {
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
	ctx.lr = 0x824EE5D0;
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r29,1006
	cr6.compare<uint32_t>(r29.u32, 1006, xer);
	// bgt cr6,0x824ee724
	if (cr6.gt) goto loc_824EE724;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EE600;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ee724
	if (!cr6.eq) goto loc_824EE724;
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824edcc0
	ctx.lr = 0x824EE624;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EE62C;
	sub_824E6310(ctx, base);
	// lwz r22,88(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// beq cr6,0x824ee730
	if (cr6.eq) goto loc_824EE730;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ee724
	if (cr6.eq) goto loc_824EE724;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r29,9
	ctx.r4.s64 = r29.s64 + 9;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824ee70c
	if (cr6.eq) goto loc_824EE70C;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// ori r9,r27,8
	ctx.r9.u64 = r27.u64 | 8;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// stw r26,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r26.u32);
	// bl 0x82533fc8
	ctx.lr = 0x824EE6C8;
	sub_82533FC8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE6D0;
	sub_82534248(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE6DC;
	sub_8244D5C0(ctx, base);
	// rlwinm r10,r27,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x10;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r22,88
	ctx.r4.s64 = r22.s64 + 88;
	// bne cr6,0x824ee6fc
	if (!cr6.eq) goto loc_824EE6FC;
	// addi r4,r22,76
	ctx.r4.s64 = r22.s64 + 76;
loc_824EE6FC:
	// bl 0x824e7930
	ctx.lr = 0x824EE700;
	sub_824E7930(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
loc_824EE70C:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EE724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824EE724:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
loc_824EE730:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82533fc0
	ctx.lr = 0x824EE738;
	sub_82533FC0(ctx, base);
	// ori r9,r27,8
	ctx.r9.u64 = r27.u64 | 8;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82533fc8
	ctx.lr = 0x824EE758;
	sub_82533FC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82534248
	ctx.lr = 0x824EE760;
	sub_82534248(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EE76C;
	sub_8244D5C0(ctx, base);
	// rlwinm r11,r27,0,27,27
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee78c
	if (cr6.eq) goto loc_824EE78C;
	// mr r31,r26
	r31.u64 = r26.u64;
	// bl 0x82534318
	ctx.lr = 0x824EE784;
	sub_82534318(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x824ee798
	goto loc_824EE798;
loc_824EE78C:
	// bl 0x82534318
	ctx.lr = 0x824EE790;
	sub_82534318(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r26
	r28.u64 = r26.u64;
loc_824EE798:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82533e98
	ctx.lr = 0x824EE7A8;
	sub_82533E98(ctx, base);
	// mulli r11,r24,68
	r11.s64 = r24.s64 * 68;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb858
	ctx.lr = 0x824EE7C4;
	sub_824EB858(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EE7D8;
	sub_824EA9D0(ctx, base);
	// subf r11,r26,r3
	r11.s64 = ctx.r3.s64 - r26.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EE7EC"))) PPC_WEAK_FUNC(sub_824EE7EC);
PPC_FUNC_IMPL(__imp__sub_824EE7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EE7F0"))) PPC_WEAK_FUNC(sub_824EE7F0);
PPC_FUNC_IMPL(__imp__sub_824EE7F0) {
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
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee87c
	if (cr6.eq) goto loc_824EE87C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EE820;
	sub_824E6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824f8f38
	ctx.lr = 0x824EE838;
	sub_824F8F38(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824ee8e8
	if (!cr6.gt) goto loc_824EE8E8;
loc_824EE840:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee200
	ctx.lr = 0x824EE858;
	sub_824EE200(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824f8f38
	ctx.lr = 0x824EE870;
	sub_824F8F38(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x824ee840
	if (cr6.gt) goto loc_824EE840;
	// b 0x824ee8e8
	goto loc_824EE8E8;
loc_824EE87C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee8e8
	if (cr6.eq) goto loc_824EE8E8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EE890;
	sub_824E6310(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82533dc0
	ctx.lr = 0x824EE8A8;
	sub_82533DC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824ee8e8
	if (!cr6.gt) goto loc_824EE8E8;
loc_824EE8B0:
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee200
	ctx.lr = 0x824EE8C8;
	sub_824EE200(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82533dc0
	ctx.lr = 0x824EE8E0;
	sub_82533DC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x824ee8b0
	if (cr6.gt) goto loc_824EE8B0;
loc_824EE8E8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
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

__attribute__((alias("__imp__sub_824EE904"))) PPC_WEAK_FUNC(sub_824EE904);
PPC_FUNC_IMPL(__imp__sub_824EE904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EE908"))) PPC_WEAK_FUNC(sub_824EE908);
PPC_FUNC_IMPL(__imp__sub_824EE908) {
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
	ctx.lr = 0x824EE910;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x821c9788
	ctx.lr = 0x824EE91C;
	sub_821C9788(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r27,0
	r27.s64 = 0;
	// addi r25,r26,156
	r25.s64 = r26.s64 + 156;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r24,r26,1292
	r24.s64 = r26.s64 + 1292;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// li r22,2
	r22.s64 = 2;
	// stw r3,30444(r11)
	PPC_STORE_U32(r11.u32 + 30444, ctx.r3.u32);
	// li r23,-1
	r23.s64 = -1;
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
loc_824EE944:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EE950;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee964
	if (cr6.eq) goto loc_824EE964;
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x824ee968
	goto loc_824EE968;
loc_824EE964:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EE968:
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ee97c
	if (cr6.eq) goto loc_824EE97C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EE97C;
	sub_824EB248(ctx, base);
loc_824EE97C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea88
	if (cr6.eq) goto loc_824EEA88;
loc_824EE984:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ee9b0
	if (cr6.eq) goto loc_824EE9B0;
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// bne cr6,0x824ee9b8
	if (!cr6.eq) goto loc_824EE9B8;
	// b 0x824ee9b4
	goto loc_824EE9B4;
loc_824EE9B0:
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
loc_824EE9B4:
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
loc_824EE9B8:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824EE9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x824eea18
	if (!cr6.eq) goto loc_824EEA18;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824eafa0
	ctx.lr = 0x824EE9F0;
	sub_824EAFA0(ctx, base);
	// lwz r31,140(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea54
	if (cr6.eq) goto loc_824EEA54;
	// stw r27,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EEA10;
	sub_821CE0A0(ctx, base);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// b 0x824eea54
	goto loc_824EEA54;
loc_824EEA18:
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x824eea54
	if (!cr6.eq) goto loc_824EEA54;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824eafa0
	ctx.lr = 0x824EEA30;
	sub_824EAFA0(ctx, base);
	// lwz r31,140(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824eea54
	if (cr6.eq) goto loc_824EEA54;
	// stw r27,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r27.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EEA50;
	sub_821CE0A0(ctx, base);
	// stw r23,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r23.u32);
loc_824EEA54:
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eea68
	if (cr6.eq) goto loc_824EEA68;
	// lwz r31,0(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// b 0x824eea6c
	goto loc_824EEA6C;
loc_824EEA68:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEA6C:
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eea80
	if (cr6.eq) goto loc_824EEA80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EEA80;
	sub_824EB248(ctx, base);
loc_824EEA80:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ee984
	if (!cr6.eq) goto loc_824EE984;
loc_824EEA88:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEA90;
	sub_821C9030(ctx, base);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eeaa8
	if (!cr6.eq) goto loc_824EEAA8;
	// mr r28,r27
	r28.u64 = r27.u64;
loc_824EEAA8:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eeab8
	if (cr6.eq) goto loc_824EEAB8;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824eb248
	ctx.lr = 0x824EEAB8;
	sub_824EB248(ctx, base);
loc_824EEAB8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824eec10
	if (cr6.eq) goto loc_824EEC10;
loc_824EEAC0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EEAD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824eeba4
	if (!cr6.eq) goto loc_824EEBA4;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r30,r11,32
	r30.s64 = r11.s64 + 32;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x821c8fe0
	ctx.lr = 0x824EEAF4;
	sub_821C8FE0(ctx, base);
	// mr r31,r27
	r31.u64 = r27.u64;
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824eeb94
	if (cr6.gt) goto loc_824EEB94;
	// addi r31,r26,72
	r31.s64 = r26.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824ed1f0
	ctx.lr = 0x824EEB18;
	sub_824ED1F0(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824e6310
	ctx.lr = 0x824EEB20;
	sub_824E6310(ctx, base);
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// stw r31,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r31.u32);
	// stw r27,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eeb54
	if (cr6.eq) goto loc_824EEB54;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e62a0
	ctx.lr = 0x824EEB40;
	sub_824E62A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eeb54
	if (!cr6.eq) goto loc_824EEB54;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// b 0x824eeb68
	goto loc_824EEB68;
loc_824EEB54:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824e6310
	ctx.lr = 0x824EEB5C;
	sub_824E6310(ctx, base);
	// stw r31,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r31.u32);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stw r27,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r27.u32);
loc_824EEB68:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x824e6310
	ctx.lr = 0x824EEB74;
	sub_824E6310(ctx, base);
	// stw r31,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r31.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r27,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r27.u32);
	// beq cr6,0x824eeb90
	if (cr6.eq) goto loc_824EEB90;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// b 0x824eeb94
	goto loc_824EEB94;
loc_824EEB90:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEB94:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EEB9C;
	sub_821C9030(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eebd4
	if (!cr6.eq) goto loc_824EEBD4;
loc_824EEBA4:
	// addi r4,r26,124
	ctx.r4.s64 = r26.s64 + 124;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEBB0;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824ebff8
	ctx.lr = 0x824EEBCC;
	sub_824EBFF8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EEBD4;
	sub_821C9030(ctx, base);
loc_824EEBD4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82530158
	ctx.lr = 0x824EEBDC;
	sub_82530158(ctx, base);
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eebf4
	if (!cr6.eq) goto loc_824EEBF4;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_824EEBF4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824eec04
	if (cr6.eq) goto loc_824EEC04;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824eb248
	ctx.lr = 0x824EEC04;
	sub_824EB248(ctx, base);
loc_824EEC04:
	// mr r28,r31
	r28.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824eeac0
	if (!cr6.eq) goto loc_824EEAC0;
loc_824EEC10:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// bne 0x824ee944
	if (!cr0.eq) goto loc_824EE944;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824fecd0
	ctx.lr = 0x824EEC20;
	sub_824FECD0(ctx, base);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EEC28"))) PPC_WEAK_FUNC(sub_824EEC28);
PPC_FUNC_IMPL(__imp__sub_824EEC28) {
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
	ctx.lr = 0x824EEC30;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r27,1292
	ctx.r4.s64 = r27.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEC4C;
	sub_821C8FE0(ctx, base);
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// li r28,0
	r28.s64 = 0;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// mr r26,r28
	r26.u64 = r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824eec78
	if (!cr6.eq) goto loc_824EEC78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EEC6C;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824eec7c
	if (cr6.eq) goto loc_824EEC7C;
loc_824EEC78:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EEC7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eed28
	if (cr6.eq) goto loc_824EED28;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824eec98
	if (!cr6.eq) goto loc_824EEC98;
	// stw r28,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r28.u32);
	// b 0x824eeca4
	goto loc_824EECA4;
loc_824EEC98:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EECA4:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824eedf8
	if (!cr6.eq) goto loc_824EEDF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae00
	ctx.lr = 0x824EECB8;
	sub_824EAE00(ctx, base);
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x824eecdc
	if (cr6.eq) goto loc_824EECDC;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x824eecdc
	if (cr6.eq) goto loc_824EECDC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae68
	ctx.lr = 0x824EECD0;
	sub_824EAE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eece0
	if (cr6.eq) goto loc_824EECE0;
loc_824EECDC:
	// li r26,1
	r26.s64 = 1;
loc_824EECE0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EECE8;
	sub_821F6C70(ctx, base);
	// addi r30,r27,72
	r30.s64 = r27.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EED00;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e6310
	ctx.lr = 0x824EED08;
	sub_824E6310(ctx, base);
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,136(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82618698
	ctx.lr = 0x824EED1C;
	sub_82618698(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// b 0x824eedf8
	goto loc_824EEDF8;
loc_824EED28:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EED30;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824eed40
	if (cr6.lt) goto loc_824EED40;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824EED40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eede4
	if (cr6.eq) goto loc_824EEDE4;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x824eed5c
	if (!cr6.eq) goto loc_824EED5C;
	// stw r28,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r28.u32);
	// b 0x824eed68
	goto loc_824EED68;
loc_824EED5C:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EED68:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824eedf8
	if (!cr6.eq) goto loc_824EEDF8;
	// lwz r30,140(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eed9c
	if (cr6.eq) goto loc_824EED9C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EED90;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// stw r28,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r28.u32);
loc_824EED9C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821f6c70
	ctx.lr = 0x824EEDA4;
	sub_821F6C70(ctx, base);
	// addi r30,r27,72
	r30.s64 = r27.s64 + 72;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824edcc0
	ctx.lr = 0x824EEDBC;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EEDC4;
	sub_824E6310(ctx, base);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,136(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82618698
	ctx.lr = 0x824EEDD8;
	sub_82618698(ctx, base);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// b 0x824eedf4
	goto loc_824EEDF4;
loc_824EEDE4:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824eedf8
	if (cr6.eq) goto loc_824EEDF8;
loc_824EEDF4:
	// li r26,1
	r26.s64 = 1;
loc_824EEDF8:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eee88
	if (cr6.eq) goto loc_824EEE88;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EEE24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eee74
	if (cr6.eq) goto loc_824EEE74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EEE38;
	sub_82618698(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EEE44;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r4,12(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EEE58;
	sub_825301E0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,26956
	ctx.r10.s64 = r11.s64 + 26956;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x824ec9a0
	ctx.lr = 0x824EEE70;
	sub_824EC9A0(ctx, base);
	// b 0x824eee7c
	goto loc_824EEE7C;
loc_824EEE74:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EEE7C;
	sub_824ECCE8(ctx, base);
loc_824EEE7C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824ede48
	ctx.lr = 0x824EEE88;
	sub_824EDE48(ctx, base);
loc_824EEE88:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEE90;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EEE9C"))) PPC_WEAK_FUNC(sub_824EEE9C);
PPC_FUNC_IMPL(__imp__sub_824EEE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EEEA0"))) PPC_WEAK_FUNC(sub_824EEEA0);
PPC_FUNC_IMPL(__imp__sub_824EEEA0) {
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
	ctx.lr = 0x824EEEA8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lbz r11,1336(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef214
	if (cr6.eq) goto loc_824EF214;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eeee4
	if (cr6.eq) goto loc_824EEEE4;
	// addi r3,r28,1272
	ctx.r3.s64 = r28.s64 + 1272;
	// bl 0x824ea7b0
	ctx.lr = 0x824EEED4;
	sub_824EA7B0(ctx, base);
	// lbz r11,1336(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r10,1336(r28)
	PPC_STORE_U8(r28.u32 + 1336, ctx.r10.u8);
loc_824EEEE4:
	// addi r26,r28,124
	r26.s64 = r28.s64 + 124;
	// addi r24,r28,1292
	r24.s64 = r28.s64 + 1292;
	// addi r29,r28,236
	r29.s64 = r28.s64 + 236;
	// li r27,16
	r27.s64 = 16;
	// li r25,0
	r25.s64 = 0;
	// li r30,-1
	r30.s64 = -1;
loc_824EEEFC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF08;
	sub_821C8FE0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eef68
	if (cr6.eq) goto loc_824EEF68;
loc_824EEF14:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r31,-8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF24;
	sub_821C8FE0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eef54
	if (cr6.eq) goto loc_824EEF54;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mulli r11,r11,68
	r11.s64 = r11.s64 * 68;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r3,r11,228
	ctx.r3.s64 = r11.s64 + 228;
	// bl 0x824eb248
	ctx.lr = 0x824EEF48;
	sub_824EB248(ctx, base);
	// stw r25,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r25.u32);
	// stw r25,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r25.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_824EEF54:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EEF5C;
	sub_821C9030(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eef14
	if (!cr6.eq) goto loc_824EEF14;
loc_824EEF68:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EEF70;
	sub_821C9030(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEF7C;
	sub_821C8FE0(ctx, base);
	// stw r30,-52(r29)
	PPC_STORE_U32(r29.u32 + -52, r30.u32);
	// addi r3,r29,-20
	ctx.r3.s64 = r29.s64 + -20;
	// bl 0x825307d0
	ctx.lr = 0x824EEF88;
	sub_825307D0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c9030
	ctx.lr = 0x824EEF90;
	sub_821C9030(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824eeefc
	if (!cr0.eq) goto loc_824EEEFC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEFA8;
	sub_821C8FE0(ctx, base);
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef070
	if (cr6.eq) goto loc_824EF070;
	// addi r29,r28,60
	r29.s64 = r28.s64 + 60;
loc_824EEFB8:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,72(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824eefec
	if (cr6.eq) goto loc_824EEFEC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824ef064
	if (!cr6.gt) goto loc_824EF064;
loc_824EEFD0:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EEFE0;
	sub_824EEC28(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x824eefd0
	if (!cr0.eq) goto loc_824EEFD0;
	// b 0x824ef064
	goto loc_824EF064;
loc_824EEFEC:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c8fe0
	ctx.lr = 0x824EEFF8;
	sub_821C8FE0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r28,72
	ctx.r4.s64 = r28.s64 + 72;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ece80
	ctx.lr = 0x824EF008;
	sub_824ECE80(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF014;
	sub_824EB308(ctx, base);
	// stw r25,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r25.u32);
	// lwz r10,52(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// addi r11,r28,48
	r11.s64 = r28.s64 + 48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef048
	if (cr6.eq) goto loc_824EF048;
	// stw r31,124(r10)
	PPC_STORE_U32(ctx.r10.u32 + 124, r31.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// bne cr6,0x824ef050
	if (!cr6.eq) goto loc_824EF050;
	// b 0x824ef04c
	goto loc_824EF04C;
loc_824EF048:
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
loc_824EF04C:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
loc_824EF050:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// bl 0x821c9030
	ctx.lr = 0x824EF064;
	sub_821C9030(ctx, base);
loc_824EF064:
	// lwz r11,68(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824eefb8
	if (!cr6.eq) goto loc_824EEFB8;
loc_824EF070:
	// lwz r11,120(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r31,r28,112
	r31.s64 = r28.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0a0
	if (cr6.eq) goto loc_824EF0A0;
loc_824EF080:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef094
	if (cr6.eq) goto loc_824EF094;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EF094;
	sub_824EB108(ctx, base);
loc_824EF094:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef080
	if (!cr6.eq) goto loc_824EF080;
loc_824EF0A0:
	// lwz r11,56(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r31,r28,48
	r31.s64 = r28.s64 + 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0d0
	if (cr6.eq) goto loc_824EF0D0;
loc_824EF0B0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef0c4
	if (cr6.eq) goto loc_824EF0C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF0C4;
	sub_824EB308(ctx, base);
loc_824EF0C4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef0b0
	if (!cr6.eq) goto loc_824EF0B0;
loc_824EF0D0:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r31,r28,20
	r31.s64 = r28.s64 + 20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef0f0
	if (cr6.eq) goto loc_824EF0F0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ed930
	ctx.lr = 0x824EF0EC;
	sub_824ED930(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_824EF0F0:
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// addi r31,r28,84
	r31.s64 = r28.s64 + 84;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef110
	if (cr6.eq) goto loc_824EF110;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb3c8
	ctx.lr = 0x824EF10C;
	sub_824EB3C8(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_824EF110:
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// addi r31,r28,156
	r31.s64 = r28.s64 + 156;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef128
	if (cr6.eq) goto loc_824EF128;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x824ef12c
	goto loc_824EF12C;
loc_824EF128:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824EF12C:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef140
	if (cr6.eq) goto loc_824EF140;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EF140;
	sub_824EB248(ctx, base);
loc_824EF140:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ef188
	if (cr6.eq) goto loc_824EF188;
loc_824EF14C:
	// bl 0x82530158
	ctx.lr = 0x824EF150;
	sub_82530158(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef164
	if (cr6.eq) goto loc_824EF164;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x824ef168
	goto loc_824EF168;
loc_824EF164:
	// mr r30,r25
	r30.u64 = r25.u64;
loc_824EF168:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef17c
	if (cr6.eq) goto loc_824EF17C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EF17C;
	sub_824EB248(ctx, base);
loc_824EF17C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824ef14c
	if (!cr6.eq) goto loc_824EF14C;
loc_824EF188:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef1c0
	if (cr6.eq) goto loc_824EF1C0;
loc_824EF194:
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EF1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,16(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ef194
	if (!cr6.eq) goto loc_824EF194;
loc_824EF1C0:
	// bl 0x824fa8a8
	ctx.lr = 0x824EF1C4;
	sub_824FA8A8(ctx, base);
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,27016
	ctx.r4.s64 = r11.s64 + 27016;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824EF1E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r25,1332(r28)
	PPC_STORE_U32(r28.u32 + 1332, r25.u32);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lbz r7,1336(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 1336);
	// rlwimi r7,r8,6,0,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0xFFFFFFC0) | (ctx.r7.u64 & 0xFFFFFFFF0000003F);
	// stw r25,1324(r28)
	PPC_STORE_U32(r28.u32 + 1324, r25.u32);
	// stw r25,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r25.u32);
	// stw r25,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r25.u32);
	// stw r25,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r25.u32);
	// sth r25,1328(r28)
	PPC_STORE_U16(r28.u32 + 1328, r25.u16);
	// stb r7,1336(r28)
	PPC_STORE_U8(r28.u32 + 1336, ctx.r7.u8);
	// bl 0x821c9030
	ctx.lr = 0x824EF214;
	sub_821C9030(ctx, base);
loc_824EF214:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824EF21C"))) PPC_WEAK_FUNC(sub_824EF21C);
PPC_FUNC_IMPL(__imp__sub_824EF21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EF220"))) PPC_WEAK_FUNC(sub_824EF220);
PPC_FUNC_IMPL(__imp__sub_824EF220) {
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
	ctx.lr = 0x824EF228;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF244;
	sub_821C8FE0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x824ef280
	if (cr6.lt) goto loc_824EF280;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eafa0
	ctx.lr = 0x824EF258;
	sub_824EAFA0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef280
	if (cr6.eq) goto loc_824EF280;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF270;
	sub_824EEC28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef284
	if (!cr6.eq) goto loc_824EF284;
loc_824EF280:
	// li r31,0
	r31.s64 = 0;
loc_824EF284:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF28C;
	sub_821C9030(ctx, base);
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824EF298"))) PPC_WEAK_FUNC(sub_824EF298);
PPC_FUNC_IMPL(__imp__sub_824EF298) {
	PPC_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x824ee5c8
	sub_824EE5C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824EF2A0"))) PPC_WEAK_FUNC(sub_824EF2A0);
PPC_FUNC_IMPL(__imp__sub_824EF2A0) {
	PPC_FUNC_PROLOGUE();
	// li r8,16
	ctx.r8.s64 = 16;
	// b 0x824ee5c8
	sub_824EE5C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824EF2A8"))) PPC_WEAK_FUNC(sub_824EF2A8);
PPC_FUNC_IMPL(__imp__sub_824EF2A8) {
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
	ctx.lr = 0x824EF2B0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// addi r4,r26,1292
	ctx.r4.s64 = r26.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF2D4;
	sub_821C8FE0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// lwz r31,16(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef35c
	if (cr6.eq) goto loc_824EF35C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,16(r26)
	PPC_STORE_U32(r26.u32 + 16, r11.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82533ef0
	ctx.lr = 0x824EF2F4;
	sub_82533EF0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplw cr6,r25,r30
	cr6.compare<uint32_t>(r25.u32, r30.u32, xer);
	// bgt cr6,0x824ef32c
	if (cr6.gt) goto loc_824EF32C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82533ef0
	ctx.lr = 0x824EF308;
	sub_82533EF0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EF318;
	sub_8244D5C0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r20)
	PPC_STORE_U32(r20.u32 + 4, ctx.r10.u32);
	// b 0x824ef330
	goto loc_824EF330;
loc_824EF32C:
	// li r25,0
	r25.s64 = 0;
loc_824EF330:
	// lwz r3,12(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EF348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF350;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
loc_824EF35C:
	// cmplwi cr6,r30,12
	cr6.compare<uint32_t>(r30.u32, 12, xer);
	// ble cr6,0x824ef60c
	if (!cr6.gt) goto loc_824EF60C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82533fc0
	ctx.lr = 0x824EF36C;
	sub_82533FC0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r21,68(r26)
	r21.u64 = PPC_LOAD_U32(r26.u32 + 68);
	// subf r11,r29,r22
	r11.s64 = r22.s64 - r29.s64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// add r28,r11,r30
	r28.u64 = r11.u64 + r30.u64;
	// beq cr6,0x824ef60c
	if (cr6.eq) goto loc_824EF60C;
loc_824EF384:
	// addi r21,r21,-1
	r21.s64 = r21.s64 + -1;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x824ef60c
	if (!cr6.eq) goto loc_824EF60C;
	// lwz r4,60(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 60);
	// addi r31,r26,60
	r31.s64 = r26.s64 + 60;
	// extsw r27,r4
	r27.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef3ac
	if (cr6.eq) goto loc_824EF3AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb308
	ctx.lr = 0x824EF3AC;
	sub_824EB308(ctx, base);
loc_824EF3AC:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eacc8
	ctx.lr = 0x824EF3C0;
	sub_824EACC8(ctx, base);
	// lwz r11,132(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef3d4
	if (cr6.eq) goto loc_824EF3D4;
	// subf. r11,r11,r24
	r11.s64 = r24.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x824ef604
	if (!cr0.gt) goto loc_824EF604;
loc_824EF3D4:
	// lwz r11,1324(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 1324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef3ec
	if (cr6.eq) goto loc_824EF3EC;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// b 0x824ef3f0
	goto loc_824EF3F0;
loc_824EF3EC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824EF3F0:
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// stw r10,132(r27)
	PPC_STORE_U32(r27.u32 + 132, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef58c
	if (cr6.eq) goto loc_824EF58C;
	// mr r23,r11
	r23.u64 = r11.u64;
loc_824EF404:
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmplwi cr6,r28,9
	cr6.compare<uint32_t>(r28.u32, 9, xer);
	// blt cr6,0x824ef58c
	if (cr6.lt) goto loc_824EF58C;
	// lwz r4,64(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 64);
	// addi r30,r27,64
	r30.s64 = r27.s64 + 64;
	// extsw r31,r4
	r31.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef42c
	if (cr6.eq) goto loc_824EF42C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb108
	ctx.lr = 0x824EF42C;
	sub_824EB108(ctx, base);
loc_824EF42C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef458
	if (cr6.eq) goto loc_824EF458;
	// stw r31,128(r11)
	PPC_STORE_U32(r11.u32 + 128, r31.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// bne cr6,0x824ef460
	if (!cr6.eq) goto loc_824EF460;
	// b 0x824ef45c
	goto loc_824EF45C;
loc_824EF458:
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
loc_824EF45C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
loc_824EF460:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// bl 0x8218f5b0
	ctx.lr = 0x824EF474;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x824ef488
	if (!cr6.eq) goto loc_824EF488;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EF484;
	sub_824ECCE8(ctx, base);
	// b 0x824ef584
	goto loc_824EF584;
loc_824EF488:
	// lbz r11,144(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef4c0
	if (cr6.eq) goto loc_824EF4C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eae68
	ctx.lr = 0x824EF4A0;
	sub_824EAE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef4c0
	if (cr6.eq) goto loc_824EF4C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF4BC;
	sub_824EEC28(ctx, base);
	// b 0x824ef584
	goto loc_824EF584;
loc_824EF4C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618698
	ctx.lr = 0x824EF4C8;
	sub_82618698(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824eca00
	ctx.lr = 0x824EF4D8;
	sub_824ECA00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef548
	if (cr6.eq) goto loc_824EF548;
	// bl 0x82530b28
	ctx.lr = 0x824EF4EC;
	sub_82530B28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x824EF4F4;
	sub_8218F5B0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824ef504
	if (cr6.lt) goto loc_824EF504;
	// li r11,0
	r11.s64 = 0;
loc_824EF504:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef548
	if (!cr6.eq) goto loc_824EF548;
	// bl 0x825303e8
	ctx.lr = 0x824EF518;
	sub_825303E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef53c
	if (!cr6.eq) goto loc_824EF53C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825303f8
	ctx.lr = 0x824EF530;
	sub_825303F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef584
	if (cr6.eq) goto loc_824EF584;
loc_824EF53C:
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x824ef54c
	goto loc_824EF54C;
loc_824EF548:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_824EF54C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82532508
	ctx.lr = 0x824EF558;
	sub_82532508(ctx, base);
	// mulli r11,r30,68
	r11.s64 = r30.s64 * 68;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r27,112
	ctx.r4.s64 = r27.s64 + 112;
	// addi r3,r11,184
	ctx.r3.s64 = r11.s64 + 184;
	// bl 0x824eb858
	ctx.lr = 0x824EF578;
	sub_824EB858(ctx, base);
	// add r29,r31,r29
	r29.u64 = r31.u64 + r29.u64;
	// subf r28,r31,r28
	r28.s64 = r28.s64 - r31.s64;
	// add r25,r31,r25
	r25.u64 = r31.u64 + r25.u64;
loc_824EF584:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bne cr6,0x824ef404
	if (!cr6.eq) goto loc_824EF404;
loc_824EF58C:
	// addi r31,r27,112
	r31.s64 = r27.s64 + 112;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r27,76
	ctx.r5.s64 = r27.s64 + 76;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ed588
	ctx.lr = 0x824EF5A8;
	sub_824ED588(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// add r30,r11,r25
	r30.u64 = r11.u64 + r25.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// subf r28,r11,r28
	r28.s64 = r28.s64 - r11.s64;
	// bl 0x82533e98
	ctx.lr = 0x824EF5C8;
	sub_82533E98(ctx, base);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r27,88
	ctx.r5.s64 = r27.s64 + 88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824ed588
	ctx.lr = 0x824EF5E0;
	sub_824ED588(ctx, base);
	// add. r25,r3,r30
	r25.u64 = ctx.r3.u64 + r30.u64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// subf r28,r3,r28
	r28.s64 = r28.s64 - ctx.r3.s64;
	// beq 0x824ef604
	if (cr0.eq) goto loc_824EF604;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r25,r25,3
	r25.s64 = r25.s64 + 3;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r20)
	PPC_STORE_U32(r20.u32 + 4, ctx.r10.u32);
loc_824EF604:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x824ef384
	if (!cr6.eq) goto loc_824EF384;
loc_824EF60C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EF614;
	sub_821C9030(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824EF620"))) PPC_WEAK_FUNC(sub_824EF620);
PPC_FUNC_IMPL(__imp__sub_824EF620) {
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
	ctx.lr = 0x824EF628;
	// stwu r1,-2304(r1)
	ea = -2304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef64c
	if (!cr6.eq) goto loc_824EF64C;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef8b4
	if (cr6.eq) goto loc_824EF8B4;
loc_824EF64C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6310
	ctx.lr = 0x824EF654;
	sub_824E6310(ctx, base);
	// li r7,1024
	ctx.r7.s64 = 1024;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef2a8
	ctx.lr = 0x824EF66C;
	sub_824EF2A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef8b4
	if (cr6.eq) goto loc_824EF8B4;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r25,0
	r25.s64 = 0;
	// li r23,1
	r23.s64 = 1;
	// addi r24,r11,26944
	r24.s64 = r11.s64 + 26944;
loc_824EF688:
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r29,r1,160
	r29.s64 = ctx.r1.s64 + 160;
	// bl 0x82533ef0
	ctx.lr = 0x824EF694;
	sub_82533EF0(ctx, base);
	// lbz r11,1336(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1336);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// subf r27,r26,r31
	r27.s64 = r31.s64 - r26.s64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r31,r1,160
	r31.s64 = ctx.r1.s64 + 160;
	// bl 0x82533f20
	ctx.lr = 0x824EF6B8;
	sub_82533F20(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82533fc0
	ctx.lr = 0x824EF6C4;
	sub_82533FC0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1021
	ctx.r4.s64 = 1021;
	// addi r3,r1,1187
	ctx.r3.s64 = ctx.r1.s64 + 1187;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,1024
	ctx.r7.s64 = 1024;
	// bl 0x821d2af8
	ctx.lr = 0x824EF6DC;
	sub_821D2AF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ef70c
	if (cr6.eq) goto loc_824EF70C;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// bge cr6,0x824ef70c
	if (!cr6.lt) goto loc_824EF70C;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82533f58
	ctx.lr = 0x824EF6F8;
	sub_82533F58(ctx, base);
	// ori r5,r3,1
	ctx.r5.u64 = ctx.r3.u64 | 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,1184
	ctx.r3.s64 = ctx.r1.s64 + 1184;
	// bl 0x82533e98
	ctx.lr = 0x824EF708;
	sub_82533E98(ctx, base);
	// addi r31,r1,1184
	r31.s64 = ctx.r1.s64 + 1184;
loc_824EF70C:
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533f88
	ctx.lr = 0x824EF720;
	sub_82533F88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ef74c
	if (cr6.eq) goto loc_824EF74C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533ef0
	ctx.lr = 0x824EF734;
	sub_82533EF0(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,1184
	ctx.r10.s64 = ctx.r1.s64 + 1184;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// add r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 + ctx.r10.u64;
	// add r4,r26,r11
	ctx.r4.u64 = r26.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824EF74C;
	sub_8244D5C0(ctx, base);
loc_824EF74C:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ea9d0
	ctx.lr = 0x824EF760;
	sub_824EA9D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824ef890
	if (cr6.eq) goto loc_824EF890;
	// addi r28,r30,1292
	r28.s64 = r30.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF778;
	sub_821C8FE0(ctx, base);
	// addi r31,r30,72
	r31.s64 = r30.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x824edcc0
	ctx.lr = 0x824EF790;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824e6310
	ctx.lr = 0x824EF798;
	sub_824E6310(ctx, base);
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r25,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r25.u32);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
	// lwz r29,64(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824ef888
	if (cr6.eq) goto loc_824EF888;
loc_824EF7C4:
	// lbz r11,144(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 144);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ef7e8
	if (cr6.eq) goto loc_824EF7E8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EF7E4;
	sub_824EEC28(ctx, base);
	// b 0x824ef87c
	goto loc_824EF87C;
loc_824EF7E8:
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,168
	ctx.r4.s64 = 168;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824EF808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824ef874
	if (cr6.eq) goto loc_824EF874;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82618698
	ctx.lr = 0x824EF81C;
	sub_82618698(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EF828;
	sub_82656BF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825301e0
	ctx.lr = 0x824EF83C;
	sub_825301E0(ctx, base);
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
	// stw r23,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r23.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r25,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r25.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF854;
	sub_821C8FE0(ctx, base);
	// addi r4,r30,156
	ctx.r4.s64 = r30.s64 + 156;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824eb708
	ctx.lr = 0x824EF868;
	sub_824EB708(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x824EF870;
	sub_821C9030(ctx, base);
	// b 0x824ef87c
	goto loc_824EF87C;
loc_824EF874:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ecce8
	ctx.lr = 0x824EF87C;
	sub_824ECCE8(ctx, base);
loc_824EF87C:
	// lwz r29,128(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 128);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824ef7c4
	if (!cr6.eq) goto loc_824EF7C4;
loc_824EF888:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EF890;
	sub_821C9030(ctx, base);
loc_824EF890:
	// li r7,1024
	ctx.r7.s64 = 1024;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef2a8
	ctx.lr = 0x824EF8A8;
	sub_824EF2A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824ef688
	if (!cr6.eq) goto loc_824EF688;
loc_824EF8B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,2304
	ctx.r1.s64 = ctx.r1.s64 + 2304;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_824EF8C0"))) PPC_WEAK_FUNC(sub_824EF8C0);
PPC_FUNC_IMPL(__imp__sub_824EF8C0) {
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
	ctx.lr = 0x824EF8C8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r31,1292
	ctx.r4.s64 = r31.s64 + 1292;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EF8E4;
	sub_821C8FE0(ctx, base);
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ef984
	if (!cr6.eq) goto loc_824EF984;
	// lwz r28,92(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r30,r31,84
	r30.s64 = r31.s64 + 84;
	// addi r4,r28,1
	ctx.r4.s64 = r28.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eb3c8
	ctx.lr = 0x824EF908;
	sub_824EB3C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r31,156
	ctx.r4.s64 = r31.s64 + 156;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// srw r9,r28,r11
	ctx.r9.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 >> (r11.u8 & 0x3F));
	// lwz r8,24(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// and r6,r8,r28
	ctx.r6.u64 = ctx.r8.u64 & r28.u64;
	// mulli r11,r6,148
	r11.s64 = ctx.r6.s64 * 148;
	// lwzx r10,r7,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,144(r3)
	PPC_STORE_U8(ctx.r3.u32 + 144, ctx.r10.u8);
	// bl 0x825303a8
	ctx.lr = 0x824EF950;
	sub_825303A8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// srw r8,r28,r11
	ctx.r8.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 >> (r11.u8 & 0x3F));
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// and r5,r7,r28
	ctx.r5.u64 = ctx.r7.u64 & r28.u64;
	// mulli r10,r5,148
	ctx.r10.s64 = ctx.r5.s64 * 148;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// b 0x824ef99c
	goto loc_824EF99C;
loc_824EF984:
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// extsw r29,r4
	r29.s64 = ctx.r4.s32;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ef99c
	if (cr6.eq) goto loc_824EF99C;
	// bl 0x824eb108
	ctx.lr = 0x824EF99C;
	sub_824EB108(ctx, base);
loc_824EF99C:
	// lis r11,23772
	r11.s64 = 1557921792;
	// lwz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r10,172(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ori r8,r11,64167
	ctx.r8.u64 = r11.u64 | 64167;
	// addi r3,r31,84
	ctx.r3.s64 = r31.s64 + 84;
	// mulld r11,r9,r8
	r11.s64 = ctx.r9.s64 * ctx.r8.s64;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r31,168
	r11.s64 = r31.s64 + 168;
	// rldicl r6,r30,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r30.u64, 32) & 0xFFFFFFFF;
	// stw r30,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r30.u32);
	// stw r6,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r6.u32);
	// bl 0x824eab10
	ctx.lr = 0x824EF9D0;
	sub_824EAB10(ctx, base);
	// rlwinm r5,r30,16,1,15
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 16) & 0x7FFF0000;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// or r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 | ctx.r5.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825330f0
	ctx.lr = 0x824EF9E8;
	sub_825330F0(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efa44
	if (cr6.eq) goto loc_824EFA44;
	// addi r30,r31,72
	r30.s64 = r31.s64 + 72;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824edcc0
	ctx.lr = 0x824EFA0C;
	sub_824EDCC0(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x824e6310
	ctx.lr = 0x824EFA14;
	sub_824E6310(ctx, base);
	// lwz r28,120(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r11,0
	r11.s64 = 0;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// bne cr6,0x824efa70
	if (!cr6.eq) goto loc_824EFA70;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824edd60
	ctx.lr = 0x824EFA38;
	sub_824EDD60(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x824efa70
	if (!cr6.eq) goto loc_824EFA70;
loc_824EFA44:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ede48
	ctx.lr = 0x824EFA58;
	sub_824EDE48(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r29,0
	r29.s64 = 0;
	// bl 0x821c9030
	ctx.lr = 0x824EFA64;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_824EFA70:
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r28,64
	r30.s64 = r28.s64 + 64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stwx r29,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r29.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824eac30
	ctx.lr = 0x824EFA90;
	sub_824EAC30(ctx, base);
	// mulli r11,r26,68
	r11.s64 = r26.s64 * 68;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,196
	ctx.r4.s64 = r11.s64 + 196;
	// bl 0x82530720
	ctx.lr = 0x824EFAA4;
	sub_82530720(ctx, base);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r30,64(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 64);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// bl 0x824eb1c8
	ctx.lr = 0x824EFAC4;
	sub_824EB1C8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efb14
	if (cr6.eq) goto loc_824EFB14;
loc_824EFACC:
	// cmplw cr6,r29,r30
	cr6.compare<uint32_t>(r29.u32, r30.u32, xer);
	// beq cr6,0x824efaf4
	if (cr6.eq) goto loc_824EFAF4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618698
	ctx.lr = 0x824EFADC;
	sub_82618698(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x824efaf4
	if (!cr6.eq) goto loc_824EFAF4;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFAF4;
	sub_824EEC28(ctx, base);
loc_824EFAF4:
	// ld r11,88(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// bl 0x824eb1c8
	ctx.lr = 0x824EFB08;
	sub_824EB1C8(ctx, base);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efacc
	if (!cr6.eq) goto loc_824EFACC;
loc_824EFB14:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c9030
	ctx.lr = 0x824EFB1C;
	sub_821C9030(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824EFB28"))) PPC_WEAK_FUNC(sub_824EFB28);
PPC_FUNC_IMPL(__imp__sub_824EFB28) {
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
	ctx.lr = 0x824EFB30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,27012
	ctx.r10.s64 = r11.s64 + 27012;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bl 0x824eeea0
	ctx.lr = 0x824EFB48;
	sub_824EEEA0(ctx, base);
	// addi r3,r29,1292
	ctx.r3.s64 = r29.s64 + 1292;
	// bl 0x82130000
	ctx.lr = 0x824EFB50;
	sub_82130000(ctx, base);
	// addi r11,r29,1272
	r11.s64 = r29.s64 + 1272;
	// li r28,15
	r28.s64 = 15;
	// addi r30,r11,40
	r30.s64 = r11.s64 + 40;
loc_824EFB5C:
	// addi r30,r30,-68
	r30.s64 = r30.s64 + -68;
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efb90
	if (cr6.eq) goto loc_824EFB90;
loc_824EFB70:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efb84
	if (cr6.eq) goto loc_824EFB84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb248
	ctx.lr = 0x824EFB84;
	sub_824EB248(ctx, base);
loc_824EFB84:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efb70
	if (!cr6.eq) goto loc_824EFB70;
loc_824EFB90:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r31,r30,-8
	r31.s64 = r30.s64 + -8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824efbc0
	if (cr6.eq) goto loc_824EFBC0;
loc_824EFBA0:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824efbb4
	if (cr6.eq) goto loc_824EFBB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824eb048
	ctx.lr = 0x824EFBB4;
	sub_824EB048(ctx, base);
loc_824EFBB4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efba0
	if (!cr6.eq) goto loc_824EFBA0;
loc_824EFBC0:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bge 0x824efb5c
	if (!cr0.lt) goto loc_824EFB5C;
	// addi r3,r29,156
	ctx.r3.s64 = r29.s64 + 156;
	// bl 0x824fecd0
	ctx.lr = 0x824EFBD0;
	sub_824FECD0(ctx, base);
	// addi r3,r29,124
	ctx.r3.s64 = r29.s64 + 124;
	// bl 0x82130000
	ctx.lr = 0x824EFBD8;
	sub_82130000(ctx, base);
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// bl 0x824ebd48
	ctx.lr = 0x824EFBE0;
	sub_824EBD48(ctx, base);
	// addi r3,r29,60
	ctx.r3.s64 = r29.s64 + 60;
	// bl 0x824ebda0
	ctx.lr = 0x824EFBE8;
	sub_824EBDA0(ctx, base);
	// addi r3,r29,48
	ctx.r3.s64 = r29.s64 + 48;
	// bl 0x824ebda0
	ctx.lr = 0x824EFBF0;
	sub_824EBDA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824EFBF8"))) PPC_WEAK_FUNC(sub_824EFBF8);
PPC_FUNC_IMPL(__imp__sub_824EFBF8) {
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
	ctx.lr = 0x824EFC00;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EFC28;
	sub_821C8FE0(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r31,r24
	r31.u64 = r24.u64;
	// beq cr6,0x824efc48
	if (cr6.eq) goto loc_824EFC48;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824EFC44;
	sub_821CE080(ctx, base);
	// stw r24,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r24.u32);
loc_824EFC48:
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824efd20
	if (cr6.gt) goto loc_824EFD20;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EFC60;
	sub_824EDF68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824efc88
	if (!cr6.eq) goto loc_824EFC88;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef8c0
	ctx.lr = 0x824EFC7C;
	sub_824EF8C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efd20
	if (cr6.eq) goto loc_824EFD20;
loc_824EFC88:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82533190
	ctx.lr = 0x824EFCA0;
	sub_82533190(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824efce0
	if (!cr6.eq) goto loc_824EFCE0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efd20
	if (cr6.eq) goto loc_824EFD20;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efd20
	if (!cr6.eq) goto loc_824EFD20;
	// li r11,1
	r11.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFCD8;
	sub_824EEC28(ctx, base);
	// mr r31,r24
	r31.u64 = r24.u64;
	// b 0x824efd20
	goto loc_824EFD20;
loc_824EFCE0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efd10
	if (cr6.eq) goto loc_824EFD10;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efcfc
	if (!cr6.eq) goto loc_824EFCFC;
	// stw r27,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r27.u32);
	// b 0x824efd10
	goto loc_824EFD10;
loc_824EFCFC:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFD0C;
	sub_821CE0A0(ctx, base);
	// stw r24,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r24.u32);
loc_824EFD10:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r24,1
	r24.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EFD20:
	// clrlwi r30,r24,24
	r30.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efd54
	if (!cr6.eq) goto loc_824EFD54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efd4c
	if (cr6.eq) goto loc_824EFD4C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFD44;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_824EFD4C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efd74
	if (cr6.eq) goto loc_824EFD74;
loc_824EFD54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EFD5C;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EFD68;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_824EFD74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EFD80;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824EFD8C"))) PPC_WEAK_FUNC(sub_824EFD8C);
PPC_FUNC_IMPL(__imp__sub_824EFD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824EFD90"))) PPC_WEAK_FUNC(sub_824EFD90);
PPC_FUNC_IMPL(__imp__sub_824EFD90) {
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
	ctx.lr = 0x824EFD98;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r30,1292
	ctx.r4.s64 = r30.s64 + 1292;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x824EFDBC;
	sub_821C8FE0(ctx, base);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// mr r31,r25
	r31.u64 = r25.u64;
	// beq cr6,0x824efddc
	if (cr6.eq) goto loc_824EFDDC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce080
	ctx.lr = 0x824EFDD8;
	sub_821CE080(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
loc_824EFDDC:
	// cmplwi cr6,r29,15
	cr6.compare<uint32_t>(r29.u32, 15, xer);
	// bgt cr6,0x824efea4
	if (cr6.gt) goto loc_824EFEA4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824edf68
	ctx.lr = 0x824EFDF4;
	sub_824EDF68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824efe64
	if (!cr6.eq) goto loc_824EFE64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ef8c0
	ctx.lr = 0x824EFE10;
	sub_824EF8C0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824efea4
	if (cr6.eq) goto loc_824EFEA4;
	// clrlwi r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// bl 0x825333c0
	ctx.lr = 0x824EFE2C;
	sub_825333C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824efe64
	if (!cr6.eq) goto loc_824EFE64;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efea4
	if (!cr6.eq) goto loc_824EFEA4;
	// li r11,1
	r11.s64 = 1;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824eec28
	ctx.lr = 0x824EFE5C;
	sub_824EEC28(ctx, base);
	// mr r31,r25
	r31.u64 = r25.u64;
	// b 0x824efea4
	goto loc_824EFEA4;
loc_824EFE64:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efe94
	if (cr6.eq) goto loc_824EFE94;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824efe80
	if (!cr6.eq) goto loc_824EFE80;
	// stw r27,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r27.u32);
	// b 0x824efe94
	goto loc_824EFE94;
loc_824EFE80:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFE90;
	sub_821CE0A0(ctx, base);
	// stw r25,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r25.u32);
loc_824EFE94:
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r25,1
	r25.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_824EFEA4:
	// clrlwi r30,r25,24
	r30.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824efed8
	if (!cr6.eq) goto loc_824EFED8;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824efed0
	if (cr6.eq) goto loc_824EFED0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824EFEC8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
loc_824EFED0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824efef8
	if (cr6.eq) goto loc_824EFEF8;
loc_824EFED8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82656bf8
	ctx.lr = 0x824EFEE0;
	sub_82656BF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x824EFEEC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_824EFEF8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r31,-1
	r31.s64 = -1;
	// bl 0x821c9030
	ctx.lr = 0x824EFF04;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824EFF10"))) PPC_WEAK_FUNC(sub_824EFF10);
PPC_FUNC_IMPL(__imp__sub_824EFF10) {
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
	ctx.lr = 0x824EFF18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,1336(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1336);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824f001c
	if (cr6.eq) goto loc_824F001C;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824effd4
	if (cr6.eq) goto loc_824EFFD4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lwz r9,1284(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1284);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x824effc4
	if (!cr6.eq) goto loc_824EFFC4;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,30476(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30476);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eff74
	if (cr6.eq) goto loc_824EFF74;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// stw r11,30440(r9)
	PPC_STORE_U32(ctx.r9.u32 + 30440, r11.u32);
loc_824EFF74:
	// stw r30,30476(r10)
	PPC_STORE_U32(ctx.r10.u32 + 30476, r30.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee7f0
	ctx.lr = 0x824EFF84;
	sub_824EE7F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824eff9c
	if (cr6.eq) goto loc_824EFF9C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef620
	ctx.lr = 0x824EFF9C;
	sub_824EF620(ctx, base);
loc_824EFF9C:
	// addi r29,r31,184
	r29.s64 = r31.s64 + 184;
	// li r31,16
	r31.s64 = 16;
loc_824EFFA4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb7a0
	ctx.lr = 0x824EFFB0;
	sub_824EB7A0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824effa4
	if (!cr0.eq) goto loc_824EFFA4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EFFC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFCC;
	sub_824EE908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824EFFD4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee7f0
	ctx.lr = 0x824EFFE0;
	sub_824EE7F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFE8;
	sub_824EE908(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ef620
	ctx.lr = 0x824EFFF4;
	sub_824EF620(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ee908
	ctx.lr = 0x824EFFFC;
	sub_824EE908(ctx, base);
	// addi r29,r31,184
	r29.s64 = r31.s64 + 184;
	// li r31,16
	r31.s64 = 16;
loc_824F0004:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824eb7a0
	ctx.lr = 0x824F0010;
	sub_824EB7A0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,68
	r29.s64 = r29.s64 + 68;
	// bne 0x824f0004
	if (!cr0.eq) goto loc_824F0004;
loc_824F001C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

