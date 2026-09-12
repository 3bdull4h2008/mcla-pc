#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_824ADEC8"))) PPC_WEAK_FUNC(sub_824ADEC8);
PPC_FUNC_IMPL(__imp__sub_824ADEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	// lbz r11,18(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 18);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32181
	r12.s64 = -2109014016;
	// addi r12,r12,-8468
	r12.s64 = r12.s64 + -8468;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824ADF1C;
	case 1:
		goto loc_824ADF20;
	case 2:
		goto loc_824ADF0C;
	case 3:
		goto loc_824ADF10;
	case 4:
		goto loc_824ADF14;
	case 5:
		goto loc_824ADF18;
	case 6:
		goto loc_824ADF24;
	case 7:
		goto loc_824ADF28;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-8420(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8420);
	// lwz r18,-8416(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8416);
	// lwz r18,-8436(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8436);
	// lwz r18,-8432(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8432);
	// lwz r18,-8428(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8428);
	// lwz r18,-8424(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8424);
	// lwz r18,-8412(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8412);
	// lwz r18,-8408(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8408);
loc_824ADF0C:
	// b 0x824acff0
	sub_824ACFF0(ctx, base);
	return;
loc_824ADF10:
	// b 0x824ad040
	sub_824AD040(ctx, base);
	return;
loc_824ADF14:
	// b 0x824ad090
	sub_824AD090(ctx, base);
	return;
loc_824ADF18:
	// b 0x824ad0e0
	sub_824AD0E0(ctx, base);
	return;
loc_824ADF1C:
	// b 0x824ace88
	sub_824ACE88(ctx, base);
	return;
loc_824ADF20:
	// b 0x824ace38
	sub_824ACE38(ctx, base);
	return;
loc_824ADF24:
	// b 0x824ad278
	sub_824AD278(ctx, base);
	return;
loc_824ADF28:
	// b 0x824ac918
	sub_824AC918(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824ADF2C"))) PPC_WEAK_FUNC(sub_824ADF2C);
PPC_FUNC_IMPL(__imp__sub_824ADF2C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824ADF30"))) PPC_WEAK_FUNC(sub_824ADF30);
PPC_FUNC_IMPL(__imp__sub_824ADF30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824adf68
	if (cr6.eq) goto loc_824ADF68;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824adf60
	if (cr6.eq) goto loc_824ADF60;
loc_824ADF50:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824adf50
	if (!cr6.eq) goto loc_824ADF50;
loc_824ADF60:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
loc_824ADF68:
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_824ADF74:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824adf74
	if (!cr6.eq) goto loc_824ADF74;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824ADF98"))) PPC_WEAK_FUNC(sub_824ADF98);
PPC_FUNC_IMPL(__imp__sub_824ADF98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r10,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824adfc0
	if (cr6.eq) goto loc_824ADFC0;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r4,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r4.u32);
loc_824ADFC0:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bne cr6,0x824adfdc
	if (!cr6.eq) goto loc_824ADFDC;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x824ae008
	goto loc_824AE008;
loc_824ADFDC:
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// bne cr6,0x824ae004
	if (!cr6.eq) goto loc_824AE004;
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// b 0x824ae008
	goto loc_824AE008;
loc_824AE004:
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
loc_824AE008:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// or r8,r9,r4
	ctx.r8.u64 = ctx.r9.u64 | ctx.r4.u64;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r11,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AE020"))) PPC_WEAK_FUNC(sub_824AE020);
PPC_FUNC_IMPL(__imp__sub_824AE020) {
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
	// beq cr6,0x824ae314
	if (cr6.eq) goto loc_824AE314;
loc_824AE048:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae314
	if (!cr6.eq) goto loc_824AE314;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x824ae1c4
	if (!cr6.eq) goto loc_824AE1C4;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r10,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ae0c4
	if (cr6.eq) goto loc_824AE0C4;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x824ae0bc
	if (!cr6.eq) goto loc_824AE0BC;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821fabd0
	ctx.lr = 0x824AE0B0;
	sub_821FABD0(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r7,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
loc_824AE0BC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824ae0cc
	if (!cr6.eq) goto loc_824AE0CC;
loc_824AE0C4:
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x824ae308
	goto loc_824AE308;
loc_824AE0CC:
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae0e8
	if (cr6.eq) goto loc_824AE0E8;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824ae10c
	if (!cr6.eq) goto loc_824AE10C;
loc_824AE0E8:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae1b4
	if (cr6.eq) goto loc_824AE1B4;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ae1b4
	if (cr6.eq) goto loc_824AE1B4;
loc_824AE10C:
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ae134
	if (cr6.eq) goto loc_824AE134;
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ae160
	if (!cr6.eq) goto loc_824AE160;
loc_824AE134:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bl 0x824adf98
	ctx.lr = 0x824AE154;
	sub_824ADF98(ctx, base);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r4,r4,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
loc_824AE160:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// rlwimi r7,r9,0,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// stw r7,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r7.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r5,r6,0,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r11,r4,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821fabd0
	ctx.lr = 0x824AE1AC;
	sub_821FABD0(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ae308
	goto loc_824AE308;
loc_824AE1B4:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// b 0x824ae304
	goto loc_824AE304;
loc_824AE1C4:
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ae218
	if (cr6.eq) goto loc_824AE218;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// bne cr6,0x824ae210
	if (!cr6.eq) goto loc_824AE210;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// ori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 | 1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824adf98
	ctx.lr = 0x824AE208;
	sub_824ADF98(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_824AE210:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824ae220
	if (!cr6.eq) goto loc_824AE220;
loc_824AE218:
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x824ae308
	goto loc_824AE308;
loc_824AE220:
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae248
	if (cr6.eq) goto loc_824AE248;
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824ae264
	if (!cr6.eq) goto loc_824AE264;
loc_824AE248:
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae2f8
	if (cr6.eq) goto loc_824AE2F8;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ae2f8
	if (cr6.eq) goto loc_824AE2F8;
loc_824AE264:
	// lwz r9,8(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae280
	if (cr6.eq) goto loc_824AE280;
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824ae2ac
	if (!cr6.eq) goto loc_824AE2AC;
loc_824AE280:
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 | 1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// bl 0x821fabd0
	ctx.lr = 0x824AE2A4;
	sub_821FABD0(ctx, base);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
loc_824AE2AC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwimi r8,r10,0,0,30
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFFFFE) | (ctx.r8.u64 & 0xFFFFFFFF00000001);
	// stw r8,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r8.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r6,r7,0,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r5,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r4,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r4.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824adf98
	ctx.lr = 0x824AE2F0;
	sub_824ADF98(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x824ae308
	goto loc_824AE308;
loc_824AE2F8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_824AE304:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
loc_824AE308:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x824ae048
	if (!cr6.eq) goto loc_824AE048;
loc_824AE314:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_824AE338"))) PPC_WEAK_FUNC(sub_824AE338);
PPC_FUNC_IMPL(__imp__sub_824AE338) {
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
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ae36c
	if (cr6.eq) goto loc_824AE36C;
	// bl 0x824adf30
	ctx.lr = 0x824AE364;
	sub_824ADF30(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// b 0x824ae3c8
	goto loc_824AE3C8;
loc_824AE36C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae38c
	if (cr6.eq) goto loc_824AE38C;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x824ae390
	if (!cr6.eq) goto loc_824AE390;
loc_824AE38C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_824AE390:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae3c8
	if (cr6.eq) goto loc_824AE3C8;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae3c4
	if (cr6.eq) goto loc_824AE3C4;
loc_824AE3B4:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ae3b4
	if (!cr6.eq) goto loc_824AE3B4;
loc_824AE3C4:
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_824AE3C8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae3dc
	if (cr6.eq) goto loc_824AE3DC;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_824AE3DC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_824AE40C"))) PPC_WEAK_FUNC(sub_824AE40C);
PPC_FUNC_IMPL(__imp__sub_824AE40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AE410"))) PPC_WEAK_FUNC(sub_824AE410);
PPC_FUNC_IMPL(__imp__sub_824AE410) {
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
	ctx.lr = 0x824AE418;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r30,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// beq cr6,0x824ae450
	if (cr6.eq) goto loc_824AE450;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x824ae454
	goto loc_824AE454;
loc_824AE450:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_824AE454:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824ae338
	ctx.lr = 0x824AE460;
	sub_824AE338(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae4d8
	if (cr6.eq) goto loc_824AE4D8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae4d8
	if (cr6.eq) goto loc_824AE4D8;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824ae4b0
	if (cr6.eq) goto loc_824AE4B0;
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae4dc
	if (cr6.eq) goto loc_824AE4DC;
loc_824AE49C:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae49c
	if (!cr6.eq) goto loc_824AE49C;
	// b 0x824ae4dc
	goto loc_824AE4DC;
loc_824AE4B0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae4dc
	if (cr6.eq) goto loc_824AE4DC;
loc_824AE4C0:
	// rlwinm r11,r10,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824ae4c0
	if (!cr6.eq) goto loc_824AE4C0;
	// b 0x824ae4dc
	goto loc_824AE4DC;
loc_824AE4D8:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824AE4DC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae4f0
	if (cr6.eq) goto loc_824AE4F0;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// b 0x824ae4f8
	goto loc_824AE4F8;
loc_824AE4F0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r4,r10,0,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
loc_824AE4F8:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ae508
	if (cr6.eq) goto loc_824AE508;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r10.u32);
loc_824AE508:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae51c
	if (!cr6.eq) goto loc_824AE51C;
	// stw r4,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r4.u32);
	// b 0x824ae540
	goto loc_824AE540;
loc_824AE51C:
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x824ae530
	if (!cr6.eq) goto loc_824AE530;
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// b 0x824ae540
	goto loc_824AE540;
loc_824AE530:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 | ctx.r4.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_824AE540:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x824ae5e4
	if (cr6.eq) goto loc_824AE5E4;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x824ae55c
	if (!cr6.eq) goto loc_824AE55C;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x824ae584
	goto loc_824AE584;
loc_824AE55C:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bne cr6,0x824ae574
	if (!cr6.eq) goto loc_824AE574;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// b 0x824ae584
	goto loc_824AE584;
loc_824AE574:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_824AE584:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwimi r7,r6,0,0,30
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0xFFFFFFFE) | (ctx.r7.u64 & 0xFFFFFFFF00000001);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwimi r10,r5,0,0,30
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r5.u32, 0) & 0xFFFFFFFE) | (ctx.r10.u64 & 0xFFFFFFFF00000001);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ae5cc
	if (cr6.eq) goto loc_824AE5CC;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
loc_824AE5CC:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r10,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ae5e4
	if (cr6.eq) goto loc_824AE5E4;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
loc_824AE5E4:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824ae604
	if (cr6.eq) goto loc_824AE604;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae604
	if (!cr6.eq) goto loc_824AE604;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824ae020
	ctx.lr = 0x824AE604;
	sub_824AE020(ctx, base);
loc_824AE604:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// rlwinm r8,r9,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// stw r7,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AE638"))) PPC_WEAK_FUNC(sub_824AE638);
PPC_FUNC_IMPL(__imp__sub_824AE638) {
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
	ctx.lr = 0x824AE640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ae670
	if (!cr6.eq) goto loc_824AE670;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x824ae6cc
	goto loc_824AE6CC;
loc_824AE670:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x824ae694
	if (!cr6.gt) goto loc_824AE694;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae6c0
	if (!cr6.eq) goto loc_824AE6C0;
	// stw r31,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r31.u32);
	// b 0x824ae6b8
	goto loc_824AE6B8;
loc_824AE694:
	// bge cr6,0x824ae6cc
	if (!cr6.lt) goto loc_824AE6CC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae6c0
	if (!cr6.eq) goto loc_824AE6C0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// or r7,r8,r31
	ctx.r7.u64 = ctx.r8.u64 | r31.u64;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
loc_824AE6B8:
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// mr r30,r31
	r30.u64 = r31.u64;
loc_824AE6C0:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ae670
	if (!cr6.eq) goto loc_824AE670;
loc_824AE6CC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ae700
	if (cr6.eq) goto loc_824AE700;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bl 0x821fc130
	ctx.lr = 0x824AE6EC;
	sub_821FC130(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r8.u32);
loc_824AE700:
	// addi r11,r30,0
	r11.s64 = r30.s64 + 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r9,r8,1
	ctx.r9.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x824ae728
	if (cr6.eq) goto loc_824AE728;
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r11,r30
	r11.u64 = r30.u64;
	// b 0x824ae72c
	goto loc_824AE72C;
loc_824AE728:
	// li r11,0
	r11.s64 = 0;
loc_824AE72C:
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// stw r29,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r29.u32);
	// stb r9,12(r27)
	PPC_STORE_U8(r27.u32 + 12, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824AE748"))) PPC_WEAK_FUNC(sub_824AE748);
PPC_FUNC_IMPL(__imp__sub_824AE748) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae790
	if (cr6.eq) goto loc_824AE790;
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
loc_824AE764:
	// lwz r5,16(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r5,r8
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, xer);
	// bge cr6,0x824ae77c
	if (!cr6.lt) goto loc_824AE77C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x824ae784
	goto loc_824AE784;
loc_824AE77C:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_824AE784:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ae764
	if (!cr6.eq) goto loc_824AE764;
loc_824AE790:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824ae79c
	if (cr6.eq) goto loc_824AE79C;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_824AE79C:
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// beq cr6,0x824ae7c0
	if (cr6.eq) goto loc_824AE7C0;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_824AE7C0:
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AE7C8"))) PPC_WEAK_FUNC(sub_824AE7C8);
PPC_FUNC_IMPL(__imp__sub_824AE7C8) {
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
	ctx.lr = 0x824AE7D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// bl 0x824ae748
	ctx.lr = 0x824AE7E8;
	sub_824AE748(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae80c
	if (cr6.eq) goto loc_824AE80C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x824ae80c
	if (cr6.lt) goto loc_824AE80C;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// b 0x824ae820
	goto loc_824AE820;
loc_824AE80C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
loc_824AE820:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r9,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r9.u32);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AE844"))) PPC_WEAK_FUNC(sub_824AE844);
PPC_FUNC_IMPL(__imp__sub_824AE844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AE848"))) PPC_WEAK_FUNC(sub_824AE848);
PPC_FUNC_IMPL(__imp__sub_824AE848) {
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
	ctx.lr = 0x824AE850;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r31,r28
	r31.u64 = r28.u64;
	// bl 0x824ae7c8
	ctx.lr = 0x824AE878;
	sub_824AE7C8(ctx, base);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824ae8dc
	if (cr6.eq) goto loc_824AE8DC;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_824AE888:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824ae8dc
	if (!cr6.eq) goto loc_824AE8DC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824ae8ac
	if (cr6.eq) goto loc_824AE8AC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824ae410
	ctx.lr = 0x824AE8A8;
	sub_824AE410(ctx, base);
	// b 0x824ae8bc
	goto loc_824AE8BC;
loc_824AE8AC:
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
loc_824AE8BC:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bne cr6,0x824ae888
	if (!cr6.eq) goto loc_824AE888;
loc_824AE8DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824AE8E8"))) PPC_WEAK_FUNC(sub_824AE8E8);
PPC_FUNC_IMPL(__imp__sub_824AE8E8) {
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
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r9,28
	ctx.r9.s64 = 28;
	// addi r8,r11,5308
	ctx.r8.s64 = r11.s64 + 5308;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824AE924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x824ae958
	if (!cr6.eq) goto loc_824AE958;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae958
	if (cr6.eq) goto loc_824AE958;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,19132
	ctx.r3.s64 = r11.s64 + 19132;
	// bl 0x824ae848
	ctx.lr = 0x824AE950;
	sub_824AE848(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_824AE958:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x824AE960;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_824AE974"))) PPC_WEAK_FUNC(sub_824AE974);
PPC_FUNC_IMPL(__imp__sub_824AE974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AE978"))) PPC_WEAK_FUNC(sub_824AE978);
PPC_FUNC_IMPL(__imp__sub_824AE978) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lbz r11,16(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824aea34
	if (cr6.eq) goto loc_824AEA34;
loc_824AE98C:
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824aea34
	if (cr6.eq) goto loc_824AEA34;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ae9d0
	if (cr6.eq) goto loc_824AE9D0;
loc_824AE9A8:
	// lwz r6,16(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// bge cr6,0x824ae9c0
	if (!cr6.lt) goto loc_824AE9C0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// b 0x824ae9c8
	goto loc_824AE9C8;
loc_824AE9C0:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_824AE9C8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ae9a8
	if (!cr6.eq) goto loc_824AE9A8;
loc_824AE9D0:
	// stw r9,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r7,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, ctx.r7.u32);
	// beq cr6,0x824ae9fc
	if (cr6.eq) goto loc_824AE9FC;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// stw r10,-28(r1)
	PPC_STORE_U32(ctx.r1.u32 + -28, ctx.r10.u32);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// stw r11,-32(r1)
	PPC_STORE_U32(ctx.r1.u32 + -32, r11.u32);
	// blt cr6,0x824aea00
	if (cr6.lt) goto loc_824AEA00;
	// addi r11,r1,-32
	r11.s64 = ctx.r1.s64 + -32;
	// b 0x824aea10
	goto loc_824AEA10;
loc_824AE9FC:
	// stw r7,-28(r1)
	PPC_STORE_U32(ctx.r1.u32 + -28, ctx.r7.u32);
loc_824AEA00:
	// stw r9,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r9.u32);
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// stw r7,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, ctx.r7.u32);
	// stw r7,-12(r1)
	PPC_STORE_U32(ctx.r1.u32 + -12, ctx.r7.u32);
loc_824AEA10:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824aea34
	if (cr6.eq) goto loc_824AEA34;
	// addic. r11,r8,1
	xer.ca = ctx.r8.u32 > 4294967294;
	r11.s64 = ctx.r8.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// bne 0x824ae98c
	if (!cr0.eq) goto loc_824AE98C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// b 0x824ae98c
	goto loc_824AE98C;
loc_824AEA34:
	// lwz r3,12(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// addic. r11,r3,1
	xer.ca = ctx.r3.u32 > 4294967294;
	r11.s64 = ctx.r3.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, r11.u32);
	// bnelr 
	if (!cr0.eq) return;
	// li r11,1
	r11.s64 = 1;
	// stw r7,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r7.u32);
	// stb r11,16(r9)
	PPC_STORE_U8(ctx.r9.u32 + 16, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AEA54"))) PPC_WEAK_FUNC(sub_824AEA54);
PPC_FUNC_IMPL(__imp__sub_824AEA54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEA58"))) PPC_WEAK_FUNC(sub_824AEA58);
PPC_FUNC_IMPL(__imp__sub_824AEA58) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824ae978
	ctx.lr = 0x824AEA74;
	sub_824AE978(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ae638
	ctx.lr = 0x824AEA90;
	sub_824AE638(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_824AEAAC"))) PPC_WEAK_FUNC(sub_824AEAAC);
PPC_FUNC_IMPL(__imp__sub_824AEAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEAB0"))) PPC_WEAK_FUNC(sub_824AEAB0);
PPC_FUNC_IMPL(__imp__sub_824AEAB0) {
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
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,5308
	ctx.r9.s64 = r11.s64 + 5308;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lbz r8,20860(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20860);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824aeb30
	if (cr6.eq) goto loc_824AEB30;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,68(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824AEB14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824aeb30
	if (!cr6.eq) goto loc_824AEB30;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,19132
	ctx.r3.s64 = r11.s64 + 19132;
	// bl 0x824aea58
	ctx.lr = 0x824AEB30;
	sub_824AEA58(ctx, base);
loc_824AEB30:
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

__attribute__((alias("__imp__sub_824AEB48"))) PPC_WEAK_FUNC(sub_824AEB48);
PPC_FUNC_IMPL(__imp__sub_824AEB48) {
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
	// bl 0x824ae8e8
	ctx.lr = 0x824AEB68;
	sub_824AE8E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824aeb80
	if (cr6.eq) goto loc_824AEB80;
	// bl 0x82130588
	ctx.lr = 0x824AEB7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824AEB80:
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

__attribute__((alias("__imp__sub_824AEB98"))) PPC_WEAK_FUNC(sub_824AEB98);
PPC_FUNC_IMPL(__imp__sub_824AEB98) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r11,5308
	ctx.r9.s64 = r11.s64 + 5308;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lbz r8,20860(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 20860);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824aec00
	if (cr6.eq) goto loc_824AEC00;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,19132
	ctx.r4.s64 = r11.s64 + 19132;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x824ae978
	ctx.lr = 0x824AEBEC;
	sub_824AE978(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ae638
	ctx.lr = 0x824AEC00;
	sub_824AE638(ctx, base);
loc_824AEC00:
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

__attribute__((alias("__imp__sub_824AEC18"))) PPC_WEAK_FUNC(sub_824AEC18);
PPC_FUNC_IMPL(__imp__sub_824AEC18) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x824AEC38;
	sub_821D2970(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,5612
	ctx.r8.s64 = ctx.r10.s64 + 5612;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
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

__attribute__((alias("__imp__sub_824AEC78"))) PPC_WEAK_FUNC(sub_824AEC78);
PPC_FUNC_IMPL(__imp__sub_824AEC78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824AEC80;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824AECB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x824AECD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824AED00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824AED0C"))) PPC_WEAK_FUNC(sub_824AED0C);
PPC_FUNC_IMPL(__imp__sub_824AED0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AED10"))) PPC_WEAK_FUNC(sub_824AED10);
PPC_FUNC_IMPL(__imp__sub_824AED10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20868(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20868);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AED1C"))) PPC_WEAK_FUNC(sub_824AED1C);
PPC_FUNC_IMPL(__imp__sub_824AED1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AED20"))) PPC_WEAK_FUNC(sub_824AED20);
PPC_FUNC_IMPL(__imp__sub_824AED20) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-25308
	ctx.r10.s64 = r11.s64 + -25308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x824AED4C;
	sub_821D2810(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824aed64
	if (cr6.eq) goto loc_824AED64;
	// bl 0x82130588
	ctx.lr = 0x824AED60;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824AED64:
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

__attribute__((alias("__imp__sub_824AED7C"))) PPC_WEAK_FUNC(sub_824AED7C);
PPC_FUNC_IMPL(__imp__sub_824AED7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AED80"))) PPC_WEAK_FUNC(sub_824AED80);
PPC_FUNC_IMPL(__imp__sub_824AED80) {
	PPC_FUNC_PROLOGUE();
	// b 0x824b4bc8
	sub_824B4BC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824AED84"))) PPC_WEAK_FUNC(sub_824AED84);
PPC_FUNC_IMPL(__imp__sub_824AED84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AED88"))) PPC_WEAK_FUNC(sub_824AED88);
PPC_FUNC_IMPL(__imp__sub_824AED88) {
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
	// bl 0x821d2970
	ctx.lr = 0x824AEDA0;
	sub_821D2970(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,5612
	ctx.r10.s64 = r11.s64 + 5612;
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

__attribute__((alias("__imp__sub_824AEDC4"))) PPC_WEAK_FUNC(sub_824AEDC4);
PPC_FUNC_IMPL(__imp__sub_824AEDC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEDC8"))) PPC_WEAK_FUNC(sub_824AEDC8);
PPC_FUNC_IMPL(__imp__sub_824AEDC8) {
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
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x824AEDE0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824aee2c
	if (cr6.eq) goto loc_824AEE2C;
	// bl 0x821d2970
	ctx.lr = 0x824AEDF0;
	sub_821D2970(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,5612
	ctx.r8.s64 = ctx.r9.s64 + 5612;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
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
loc_824AEE2C:
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

__attribute__((alias("__imp__sub_824AEE44"))) PPC_WEAK_FUNC(sub_824AEE44);
PPC_FUNC_IMPL(__imp__sub_824AEE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEE48"))) PPC_WEAK_FUNC(sub_824AEE48);
PPC_FUNC_IMPL(__imp__sub_824AEE48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824AEE58"))) PPC_WEAK_FUNC(sub_824AEE58);
PPC_FUNC_IMPL(__imp__sub_824AEE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824AEE88"))) PPC_WEAK_FUNC(sub_824AEE88);
PPC_FUNC_IMPL(__imp__sub_824AEE88) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AEE8C"))) PPC_WEAK_FUNC(sub_824AEE8C);
PPC_FUNC_IMPL(__imp__sub_824AEE8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEE90"))) PPC_WEAK_FUNC(sub_824AEE90);
PPC_FUNC_IMPL(__imp__sub_824AEE90) {
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
	ctx.lr = 0x824AEE98;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r28,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r28.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r28,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r28.u16);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x824AEECC;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824aef38
	if (cr6.eq) goto loc_824AEF38;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824b4bc8
	ctx.lr = 0x824AEF1C;
	sub_824B4BC8(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_824AEF38:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824AEF4C"))) PPC_WEAK_FUNC(sub_824AEF4C);
PPC_FUNC_IMPL(__imp__sub_824AEF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEF50"))) PPC_WEAK_FUNC(sub_824AEF50);
PPC_FUNC_IMPL(__imp__sub_824AEF50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,64
	ctx.r8.s64 = 64;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f0,228(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 228, temp.u32);
	// stw r7,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r7.u32);
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,96
	ctx.r5.s64 = 96;
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,112
	ctx.r4.s64 = 112;
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r10.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r8.u32);
	// ori r10,r11,8
	ctx.r10.u64 = r11.u64 | 8;
	// stw r10,260(r3)
	PPC_STORE_U32(ctx.r3.u32 + 260, ctx.r10.u32);
	// stfs f0,244(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 244, temp.u32);
	// stw r7,236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 236, ctx.r7.u32);
	// stvx128 v63,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824AEFCC"))) PPC_WEAK_FUNC(sub_824AEFCC);
PPC_FUNC_IMPL(__imp__sub_824AEFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AEFD0"))) PPC_WEAK_FUNC(sub_824AEFD0);
PPC_FUNC_IMPL(__imp__sub_824AEFD0) {
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
	ctx.lr = 0x824AEFD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821bee48
	ctx.lr = 0x824AEFF0;
	sub_821BEE48(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824af014
	if (cr6.eq) goto loc_824AF014;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824af014
	if (!cr6.eq) goto loc_824AF014;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r31,20868(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20868);
loc_824AF014:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d4bb0
	ctx.lr = 0x824AF01C;
	sub_821D4BB0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824AF03C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AF048"))) PPC_WEAK_FUNC(sub_824AF048);
PPC_FUNC_IMPL(__imp__sub_824AF048) {
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
	ctx.lr = 0x824AF050;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c00e8
	ctx.lr = 0x824AF060;
	sub_821C00E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824aefd0
	ctx.lr = 0x824AF074;
	sub_824AEFD0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,2828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824af098
	if (cr6.eq) goto loc_824AF098;
	// bl 0x821bbea8
	ctx.lr = 0x824AF098;
	sub_821BBEA8(ctx, base);
loc_824AF098:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c5c70
	ctx.lr = 0x824AF0A0;
	sub_821C5C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824AF0A8;
	sub_82130588(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824af0b4
	if (cr6.eq) goto loc_824AF0B4;
	// bl 0x821bbf00
	ctx.lr = 0x824AF0B4;
	sub_821BBF00(ctx, base);
loc_824AF0B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AF0C0"))) PPC_WEAK_FUNC(sub_824AF0C0);
PPC_FUNC_IMPL(__imp__sub_824AF0C0) {
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
	ctx.lr = 0x824AF0C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x824AF0E8;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824af13c
	if (cr6.eq) goto loc_824AF13C;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824af10c
	if (cr6.eq) goto loc_824AF10C;
	// bl 0x821be8d8
	ctx.lr = 0x824AF108;
	sub_821BE8D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_824AF10C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824af13c
	if (cr6.eq) goto loc_824AF13C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824af048
	ctx.lr = 0x824AF124;
	sub_824AF048(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x824AF130;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824AF13C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AF148"))) PPC_WEAK_FUNC(sub_824AF148);
PPC_FUNC_IMPL(__imp__sub_824AF148) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20868
	r31.s64 = r11.s64 + 20868;
	// lwz r11,20868(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20868);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824af248
	if (!cr6.eq) goto loc_824AF248;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824AF178;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824af18c
	if (cr6.eq) goto loc_824AF18C;
	// bl 0x821d5408
	ctx.lr = 0x824AF188;
	sub_821D5408(ctx, base);
	// b 0x824af190
	goto loc_824AF190;
loc_824AF18C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824AF190:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32181
	r11.s64 = -2109014016;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,5732
	ctx.r7.s64 = ctx.r10.s64 + 5732;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-4536
	ctx.r9.s64 = r11.s64 + -4536;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32181
	ctx.r8.s64 = -2109014016;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r8,-4664
	ctx.r10.s64 = ctx.r8.s64 + -4664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r9.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824AF1F4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824AF204;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824AF220;
	sub_821D41D0(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,20864
	ctx.r4.s64 = ctx.r6.s64 + 20864;
	// bl 0x821d4b00
	ctx.lr = 0x824AF230;
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
	ctx.lr = 0x824AF248;
	sub_821C0548(ctx, base);
loc_824AF248:
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

__attribute__((alias("__imp__sub_824AF260"))) PPC_WEAK_FUNC(sub_824AF260);
PPC_FUNC_IMPL(__imp__sub_824AF260) {
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
	ctx.lr = 0x824AF268;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,-32120
	ctx.r4.s64 = ctx.r10.s64 + -32120;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821ca540
	ctx.lr = 0x824AF290;
	sub_821CA540(ctx, base);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r8,5816
	ctx.r4.s64 = ctx.r8.s64 + 5816;
	// bl 0x821ca540
	ctx.lr = 0x824AF2A0;
	sub_821CA540(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r31,19734(r7)
	r31.u64 = PPC_LOAD_U8(ctx.r7.u32 + 19734);
	// bl 0x821c9bd0
	ctx.lr = 0x824AF2B0;
	sub_821C9BD0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824af354
	if (!cr6.eq) goto loc_824AF354;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824af2f8
	if (cr6.eq) goto loc_824AF2F8;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r10,r10,5804
	ctx.r10.s64 = ctx.r10.s64 + 5804;
loc_824AF2CC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x824af2f0
	if (cr6.eq) goto loc_824AF2F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824af2cc
	if (cr6.eq) goto loc_824AF2CC;
loc_824AF2F0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x824af354
	if (!cr6.eq) goto loc_824AF354;
loc_824AF2F8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r10,5792
	ctx.r5.s64 = ctx.r10.s64 + 5792;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,2828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// bl 0x824af0c0
	ctx.lr = 0x824AF314;
	sub_824AF0C0(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_824AF318:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824AF320;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824AF328;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824af348
	if (cr6.eq) goto loc_824AF348;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824AF348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824AF348:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824AF354:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,5784
	ctx.r5.s64 = r11.s64 + 5784;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824aee90
	ctx.lr = 0x824AF370;
	sub_824AEE90(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824af318
	if (!cr6.eq) goto loc_824AF318;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,5752
	ctx.r3.s64 = r11.s64 + 5752;
	// bl 0x82130000
	ctx.lr = 0x824AF38C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824AF398"))) PPC_WEAK_FUNC(sub_824AF398);
PPC_FUNC_IMPL(__imp__sub_824AF398) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-32120
	ctx.r4.s64 = ctx.r10.s64 + -32120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x824AF3C8;
	sub_821CA540(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,5816
	ctx.r4.s64 = ctx.r9.s64 + 5816;
	// bl 0x821ca540
	ctx.lr = 0x824AF3D8;
	sub_821CA540(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r7,5792
	ctx.r5.s64 = ctx.r7.s64 + 5792;
	// lwz r3,2828(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2828);
	// bl 0x821c0370
	ctx.lr = 0x824AF3F0;
	sub_821C0370(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r11.u16);
	// sth r11,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r11.u16);
	// bl 0x821d40e8
	ctx.lr = 0x824AF414;
	sub_821D40E8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824af43c
	if (cr6.eq) goto loc_824AF43C;
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
	ctx.lr = 0x824AF434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e45b0
	ctx.lr = 0x824AF43C;
	sub_821E45B0(ctx, base);
loc_824AF43C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824AF444;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824AF44C;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824af464
	if (!cr6.eq) goto loc_824AF464;
loc_824AF454:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c6f88
	ctx.lr = 0x824AF45C;
	sub_821C6F88(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x824af4b4
	goto loc_824AF4B4;
loc_824AF464:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824AF47C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824af454
	if (cr6.eq) goto loc_824AF454;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r11,5828
	ctx.r4.s64 = r11.s64 + 5828;
	// bl 0x823db730
	ctx.lr = 0x824AF494;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x824af4ac
	if (!cr6.eq) goto loc_824AF4AC;
	// bl 0x821c6f88
	ctx.lr = 0x824AF4A4;
	sub_821C6F88(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824af4b4
	goto loc_824AF4B4;
loc_824AF4AC:
	// bl 0x821c6f88
	ctx.lr = 0x824AF4B0;
	sub_821C6F88(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_824AF4B4:
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

__attribute__((alias("__imp__sub_824AF4CC"))) PPC_WEAK_FUNC(sub_824AF4CC);
PPC_FUNC_IMPL(__imp__sub_824AF4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AF4D0"))) PPC_WEAK_FUNC(sub_824AF4D0);
PPC_FUNC_IMPL(__imp__sub_824AF4D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x824b0de8
	sub_824B0DE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824AF4D4"))) PPC_WEAK_FUNC(sub_824AF4D4);
PPC_FUNC_IMPL(__imp__sub_824AF4D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AF4D8"))) PPC_WEAK_FUNC(sub_824AF4D8);
PPC_FUNC_IMPL(__imp__sub_824AF4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-32240
	ctx.r9.s64 = r11.s64 + -32240;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824AF51C;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824AF52C;
	sub_82496790(ctx, base);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r7,6144
	ctx.r4.s64 = ctx.r7.s64 + 6144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82496790
	ctx.lr = 0x824AF550;
	sub_82496790(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_setzero_si128());
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82496790
	ctx.lr = 0x824AF574;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824AF584;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824AF594;
	sub_82496790(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_824AF5AC"))) PPC_WEAK_FUNC(sub_824AF5AC);
PPC_FUNC_IMPL(__imp__sub_824AF5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AF5B0"))) PPC_WEAK_FUNC(sub_824AF5B0);
PPC_FUNC_IMPL(__imp__sub_824AF5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82224a40
	ctx.lr = 0x824AF5CC;
	sub_82224A40(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltisw v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v10,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v7,v0,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmulfp128 v5,v0,v57
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v2,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmaddfp v3,v0,v10,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v29,v58,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vmaddfp v28,v13,v8,v9
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v27,v13,v6,v7
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v26,v13,v4,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v2,v3
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v24,v12,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v29,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_824AF688"))) PPC_WEAK_FUNC(sub_824AF688);
PPC_FUNC_IMPL(__imp__sub_824AF688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82234fc0
	ctx.lr = 0x824AF6A4;
	sub_82234FC0(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltisw v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v10,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v7,v0,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmulfp128 v5,v0,v57
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v2,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmaddfp v3,v0,v10,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v29,v58,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vmaddfp v28,v13,v8,v9
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v27,v13,v6,v7
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v26,v13,v4,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v2,v3
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v24,v12,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v29,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_824AF760"))) PPC_WEAK_FUNC(sub_824AF760);
PPC_FUNC_IMPL(__imp__sub_824AF760) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824AF768;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r10,-32224
	ctx.r7.s64 = ctx.r10.s64 + -32224;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824af92c
	if (!cr6.gt) goto loc_824AF92C;
	// mr r29,r11
	r29.u64 = r11.u64;
	// lfs f10,-100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -100);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,-104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -104);
	ctx.f11.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// lfs f12,-108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -112);
	ctx.f13.f64 = double(temp.f32);
	// mr r30,r28
	r30.u64 = r28.u64;
	// lfs f9,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
loc_824AF7B8:
	// lfsx f0,r30,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// ble cr6,0x824af8f0
	if (!cr6.gt) goto loc_824AF8F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// ble cr6,0x824af7e8
	if (!cr6.gt) goto loc_824AF7E8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x824af7f0
	goto loc_824AF7F0;
loc_824AF7E8:
	// addi r11,r1,-128
	r11.s64 = ctx.r1.s64 + -128;
	// stw r28,-128(r1)
	PPC_STORE_U32(ctx.r1.u32 + -128, r28.u32);
loc_824AF7F0:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824af8f0
	if (cr6.eq) goto loc_824AF8F0;
	// lbzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824af8f0
	if (cr6.lt) goto loc_824AF8F0;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r9,r7,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r7,28(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x824af84c
	if (!cr6.gt) goto loc_824AF84C;
	// lwz r31,24(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824AF830:
	// lfs f8,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fcmpu cr6,f8,f1
	cr6.compare(ctx.f8.f64, ctx.f1.f64);
	// bge cr6,0x824af918
	if (!cr6.lt) goto loc_824AF918;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x824af830
	if (cr6.lt) goto loc_824AF830;
loc_824AF84C:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824AF860:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// lfs f8,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f1,f8
	ctx.f7.f64 = double(float(ctx.f1.f64 - ctx.f8.f64));
	// lfs f5,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// lfs f6,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f8,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f31.f64 = double(temp.f32);
	// lfs f30,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f30.f64 = double(temp.f32);
	// fmadds f6,f6,f7,f5
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 + ctx.f5.f64));
	// stfs f6,-96(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// fmadds f5,f4,f7,f3
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f7.f64 + ctx.f3.f64));
	// stfs f5,-92(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// fmadds f4,f2,f7,f8
	ctx.f4.f64 = double(float(ctx.f2.f64 * ctx.f7.f64 + ctx.f8.f64));
	// stfs f4,-88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// fmadds f3,f31,f7,f30
	ctx.f3.f64 = double(float(f31.f64 * ctx.f7.f64 + f30.f64));
	// stfs f3,-84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-68(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f6.f64 = double(temp.f32);
	// lfs f2,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f11,f2,f0,f11
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f12,f6,f0,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// stfs f12,-108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// fmadds f13,f7,f0,f13
	ctx.f13.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f13,-112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// fmadds f10,f8,f0,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f10.f64));
	// stfs f11,-104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// stfs f10,-100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -100, temp.u32);
loc_824AF8F0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824af7b8
	if (!cr0.eq) goto loc_824AF7B8;
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_824AF918:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824af860
	goto loc_824AF860;
loc_824AF92C:
	// vaddfp128 v58,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824AF940"))) PPC_WEAK_FUNC(sub_824AF940);
PPC_FUNC_IMPL(__imp__sub_824AF940) {
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
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x824AF948;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// addi r7,r10,-32224
	ctx.r7.s64 = ctx.r10.s64 + -32224;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r29,r27
	r29.u64 = r27.u64;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824afb40
	if (!cr6.gt) goto loc_824AFB40;
	// mr r28,r11
	r28.u64 = r11.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
loc_824AF980:
	// lfsx f0,r30,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x824afac8
	if (!cr6.gt) goto loc_824AFAC8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// ble cr6,0x824af9b0
	if (!cr6.gt) goto loc_824AF9B0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x824af9b8
	goto loc_824AF9B8;
loc_824AF9B0:
	// addi r11,r1,-128
	r11.s64 = ctx.r1.s64 + -128;
	// stw r27,-128(r1)
	PPC_STORE_U32(ctx.r1.u32 + -128, r27.u32);
loc_824AF9B8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824afac8
	if (cr6.lt) goto loc_824AFAC8;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r9,r7,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r7,28(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x824afa0c
	if (!cr6.gt) goto loc_824AFA0C;
	// lwz r31,24(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824AF9F0:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x824afb44
	if (!cr6.lt) goto loc_824AFB44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x824af9f0
	if (cr6.lt) goto loc_824AF9F0;
loc_824AFA0C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824AFA20:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// addi r7,r1,-64
	ctx.r7.s64 = ctx.r1.s64 + -64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f10,f11,f9
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f2,-96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// fmadds f12,f8,f11,f7
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f12,-92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// fmadds f10,f6,f11,f5
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f10,-88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// fmadds f9,f4,f11,f3
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f9,-84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,-68(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f2,f8,f0
	ctx.f2.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f4,-60(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,-64(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmuls f0,f7,f0
	f0.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f2,-56(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f0,-52(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v62,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v59.f32)));
	// vaddfp128 v63,v63,v58
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
loc_824AFAC8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824af980
	if (!cr0.eq) goto loc_824AF980;
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824afb40
	if (cr6.eq) goto loc_824AFB40;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// lfs f13,-104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -104);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,-100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -100);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, r11.u64);
	// lfd f11,-128(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r9,r1,-112
	ctx.r9.s64 = ctx.r1.s64 + -112;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f8,-112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -108);
	ctx.f7.f64 = double(temp.f32);
	// fdivs f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 / ctx.f9.f64));
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f5,-104(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -104, temp.u32);
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// stfs f4,-100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -100, temp.u32);
	// fmuls f3,f6,f8
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// stfs f3,-112(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -112, temp.u32);
	// fmuls f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// stfs f2,-108(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -108, temp.u32);
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824AFB40:
	// b 0x823d9244
	return;
loc_824AFB44:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824afa20
	goto loc_824AFA20;
}

__attribute__((alias("__imp__sub_824AFB58"))) PPC_WEAK_FUNC(sub_824AFB58);
PPC_FUNC_IMPL(__imp__sub_824AFB58) {
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
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824AFB60;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lhz r29,4(r3)
	r29.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r10,r11,-32224
	ctx.r10.s64 = r11.s64 + -32224;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824afd5c
	if (!cr6.gt) goto loc_824AFD5C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// subf r30,r8,r11
	r30.s64 = r11.s64 - ctx.r8.s64;
	// mr r31,r29
	r31.u64 = r29.u64;
	// li r28,0
	r28.s64 = 0;
loc_824AFB90:
	// lwzx r11,r30,r3
	r11.u64 = PPC_LOAD_U32(r30.u32 + ctx.r3.u32);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// ble cr6,0x824afbb0
	if (!cr6.gt) goto loc_824AFBB0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x824afbb8
	goto loc_824AFBB8;
loc_824AFBB0:
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// stw r28,-112(r1)
	PPC_STORE_U32(ctx.r1.u32 + -112, r28.u32);
loc_824AFBB8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824afce0
	if (cr6.lt) goto loc_824AFCE0;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r9,r8,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lhz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// ble cr6,0x824afc0c
	if (!cr6.gt) goto loc_824AFC0C;
	// lwz r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// addi r10,r7,48
	ctx.r10.s64 = ctx.r7.s64 + 48;
loc_824AFBF0:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824afccc
	if (!cr6.lt) goto loc_824AFCCC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x824afbf0
	if (cr6.lt) goto loc_824AFBF0;
loc_824AFC0C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,24(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824AFC20:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// lfs f4,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f3,f12,f13,f11
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f3,-96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// fmadds f2,f10,f13,f9
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f2,-92(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// fmadds f0,f8,f13,f7
	f0.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f0,-88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// fmadds f13,f6,f13,f5
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f13,-84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-68(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f6,f12,f4
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f4.f64));
	// fmuls f8,f9,f4
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f4.f64));
	// stfs f8,-60(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmuls f7,f10,f4
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// stfs f7,-64(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmuls f5,f11,f4
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f4.f64));
	// stfs f6,-56(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f5,-52(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v57,v61,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// vaddfp128 v63,v63,v57
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// b 0x824afce4
	goto loc_824AFCE4;
loc_824AFCCC:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// b 0x824afc20
	goto loc_824AFC20;
loc_824AFCE0:
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
loc_824AFCE4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x824afb90
	if (!cr0.eq) goto loc_824AFB90;
	// addi r11,r1,-96
	r11.s64 = ctx.r1.s64 + -96;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824afd5c
	if (cr6.eq) goto loc_824AFD5C;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// lfs f13,-88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -88);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,-84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -84);
	ctx.f12.f64 = double(temp.f32);
	// std r11,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r11.u64);
	// lfd f11,-112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r9,r1,-96
	ctx.r9.s64 = ctx.r1.s64 + -96;
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f9,-96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,-92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -92);
	ctx.f7.f64 = double(temp.f32);
	// fdivs f6,f0,f8
	ctx.f6.f64 = double(float(f0.f64 / ctx.f8.f64));
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f5,-88(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// stfs f4,-84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// fmuls f3,f6,f9
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f9.f64));
	// stfs f3,-96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// fmuls f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// stfs f2,-92(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824AFD5C:
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824AFD60"))) PPC_WEAK_FUNC(sub_824AFD60);
PPC_FUNC_IMPL(__imp__sub_824AFD60) {
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
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824AFD68;
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v63,v62,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824afee0
	if (!cr6.gt) goto loc_824AFEE0;
	// mr r29,r11
	r29.u64 = r11.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r28,0
	r28.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
loc_824AFD90:
	// lfsx f0,r30,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x824afed4
	if (!cr6.gt) goto loc_824AFED4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r11,r30,r11
	r11.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpw cr6,r10,r4
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r4.s32, xer);
	// ble cr6,0x824afdc0
	if (!cr6.gt) goto loc_824AFDC0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x824afdc8
	goto loc_824AFDC8;
loc_824AFDC0:
	// addi r11,r1,-112
	r11.s64 = ctx.r1.s64 + -112;
	// stw r28,-112(r1)
	PPC_STORE_U32(ctx.r1.u32 + -112, r28.u32);
loc_824AFDC8:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbzx r10,r11,r6
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x824afed4
	if (cr6.lt) goto loc_824AFED4;
	// lwz r9,40(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r9,r7,r9
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lhz r7,28(r9)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + 28);
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x824afe1c
	if (!cr6.gt) goto loc_824AFE1C;
	// lwz r31,24(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824AFE00:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x824afee8
	if (!cr6.lt) goto loc_824AFEE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x824afe00
	if (cr6.lt) goto loc_824AFE00;
loc_824AFE1C:
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,24(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824AFE30:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// vor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// addi r10,r1,-96
	ctx.r10.s64 = ctx.r1.s64 + -96;
	// addi r9,r1,-80
	ctx.r9.s64 = ctx.r1.s64 + -80;
	// addi r7,r1,-64
	ctx.r7.s64 = ctx.r1.s64 + -64;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f10,f11,f9
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f2,-96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -96, temp.u32);
	// fmadds f12,f8,f11,f7
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f11.f64 + ctx.f7.f64));
	// stfs f12,-92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -92, temp.u32);
	// fmadds f10,f6,f11,f5
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f10,-88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -88, temp.u32);
	// fmadds f9,f4,f11,f3
	ctx.f9.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f3.f64));
	// stfs f9,-84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -84, temp.u32);
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,-80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -80);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-76(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -76);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,-68(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -68);
	ctx.f7.f64 = double(temp.f32);
	// lfs f8,-72(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -72);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f2,f8,f0
	ctx.f2.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f4,-60(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,-64(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// fmuls f0,f7,f0
	f0.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f2,-56(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f0,-52(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v57,v61,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v58.f32)));
	// vmaxfp128 v63,v63,v57
	simde_mm_store_ps(v63.f32, simde_mm_max_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
loc_824AFED4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x824afd90
	if (!cr0.eq) goto loc_824AFD90;
loc_824AFEE0:
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
loc_824AFEE8:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824afe30
	goto loc_824AFE30;
}

__attribute__((alias("__imp__sub_824AFEFC"))) PPC_WEAK_FUNC(sub_824AFEFC);
PPC_FUNC_IMPL(__imp__sub_824AFEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AFF00"))) PPC_WEAK_FUNC(sub_824AFF00);
PPC_FUNC_IMPL(__imp__sub_824AFF00) {
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
	ctx.lr = 0x824AFF08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824aff6c
	if (cr6.eq) goto loc_824AFF6C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824aff6c
	if (cr6.eq) goto loc_824AFF6C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824AFF3C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824aff6c
	if (cr6.eq) goto loc_824AFF6C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x824AFF50;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x8247ce10
	ctx.lr = 0x824AFF64;
	sub_8247CE10(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_824AFF6C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824AFF7C"))) PPC_WEAK_FUNC(sub_824AFF7C);
PPC_FUNC_IMPL(__imp__sub_824AFF7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824AFF80"))) PPC_WEAK_FUNC(sub_824AFF80);
PPC_FUNC_IMPL(__imp__sub_824AFF80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// slw r10,r9,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r7.u8 & 0x3F));
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// and r11,r10,r7
	r11.u64 = ctx.r10.u64 & ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lbzx r11,r9,r6
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r6.u32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32181
	r12.s64 = -2109014016;
	// addi r12,r12,-24
	r12.s64 = r12.s64 + -24;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_824AFFF8;
	case 1:
		goto loc_824AFFFC;
	case 2:
		goto loc_824B0000;
	case 3:
		goto loc_824B0004;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-8(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r18,-4(r10)
	r18.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r18,0(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r18,4(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_824AFFF8:
	// b 0x824af940
	sub_824AF940(ctx, base);
	return;
loc_824AFFFC:
	// b 0x824af760
	sub_824AF760(ctx, base);
	return;
loc_824B0000:
	// b 0x824afd60
	sub_824AFD60(ctx, base);
	return;
loc_824B0004:
	// b 0x824afb58
	sub_824AFB58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B0008"))) PPC_WEAK_FUNC(sub_824B0008);
PPC_FUNC_IMPL(__imp__sub_824B0008) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B000C"))) PPC_WEAK_FUNC(sub_824B000C);
PPC_FUNC_IMPL(__imp__sub_824B000C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0010"))) PPC_WEAK_FUNC(sub_824B0010);
PPC_FUNC_IMPL(__imp__sub_824B0010) {
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
	ctx.lr = 0x824B0018;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821bee48
	ctx.lr = 0x824B0030;
	sub_821BEE48(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b0054
	if (cr6.eq) goto loc_824B0054;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824b0054
	if (!cr6.eq) goto loc_824B0054;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r31,20876(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 20876);
loc_824B0054:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d4bb0
	ctx.lr = 0x824B005C;
	sub_821D4BB0(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B007C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B0088"))) PPC_WEAK_FUNC(sub_824B0088);
PPC_FUNC_IMPL(__imp__sub_824B0088) {
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
	ctx.lr = 0x824B0090;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c00e8
	ctx.lr = 0x824B00A0;
	sub_821C00E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824b0010
	ctx.lr = 0x824B00B4;
	sub_824B0010(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,2828(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b00d8
	if (cr6.eq) goto loc_824B00D8;
	// bl 0x821bbea8
	ctx.lr = 0x824B00D8;
	sub_821BBEA8(ctx, base);
loc_824B00D8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c5c70
	ctx.lr = 0x824B00E0;
	sub_821C5C70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824B00E8;
	sub_82130588(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b00f4
	if (cr6.eq) goto loc_824B00F4;
	// bl 0x821bbf00
	ctx.lr = 0x824B00F4;
	sub_821BBF00(ctx, base);
loc_824B00F4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B0100"))) PPC_WEAK_FUNC(sub_824B0100);
PPC_FUNC_IMPL(__imp__sub_824B0100) {
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
	ctx.lr = 0x824B0108;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82619428
	ctx.lr = 0x824B0118;
	sub_82619428(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,6164
	ctx.r10.s64 = r11.s64 + 6164;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82495cf0
	ctx.lr = 0x824B012C;
	sub_82495CF0(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82495cf0
	ctx.lr = 0x824B0134;
	sub_82495CF0(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x82495cf0
	ctx.lr = 0x824B013C;
	sub_82495CF0(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82495cf0
	ctx.lr = 0x824B0144;
	sub_82495CF0(ctx, base);
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// bl 0x82495cf0
	ctx.lr = 0x824B014C;
	sub_82495CF0(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x82495cf0
	ctx.lr = 0x824B0154;
	sub_82495CF0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// stw r30,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r30.u32);
	// bl 0x824aff00
	ctx.lr = 0x824B0164;
	sub_824AFF00(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r29,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,268(r31)
	PPC_STORE_U8(r31.u32 + 268, ctx.r9.u8);
	// stb r30,269(r31)
	PPC_STORE_U8(r31.u32 + 269, r30.u8);
	// stb r30,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r30.u8);
	// stb r30,270(r31)
	PPC_STORE_U8(r31.u32 + 270, r30.u8);
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stb r30,275(r31)
	PPC_STORE_U8(r31.u32 + 275, r30.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B0194"))) PPC_WEAK_FUNC(sub_824B0194);
PPC_FUNC_IMPL(__imp__sub_824B0194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0198"))) PPC_WEAK_FUNC(sub_824B0198);
PPC_FUNC_IMPL(__imp__sub_824B0198) {
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
	// addi r3,r31,248
	ctx.r3.s64 = r31.s64 + 248;
	// addi r10,r11,6164
	ctx.r10.s64 = r11.s64 + 6164;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x824B01C0;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x82495d58
	ctx.lr = 0x824B01C8;
	sub_82495D58(ctx, base);
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// bl 0x82495d58
	ctx.lr = 0x824B01D0;
	sub_82495D58(ctx, base);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82495d58
	ctx.lr = 0x824B01D8;
	sub_82495D58(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x82495d58
	ctx.lr = 0x824B01E0;
	sub_82495D58(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82495d58
	ctx.lr = 0x824B01E8;
	sub_82495D58(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82495d58
	ctx.lr = 0x824B01F0;
	sub_82495D58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82619418
	ctx.lr = 0x824B01F8;
	sub_82619418(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B020C"))) PPC_WEAK_FUNC(sub_824B020C);
PPC_FUNC_IMPL(__imp__sub_824B020C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0210"))) PPC_WEAK_FUNC(sub_824B0210);
PPC_FUNC_IMPL(__imp__sub_824B0210) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20876);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B021C"))) PPC_WEAK_FUNC(sub_824B021C);
PPC_FUNC_IMPL(__imp__sub_824B021C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0220"))) PPC_WEAK_FUNC(sub_824B0220);
PPC_FUNC_IMPL(__imp__sub_824B0220) {
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
	// bl 0x824b0198
	ctx.lr = 0x824B0240;
	sub_824B0198(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b0258
	if (cr6.eq) goto loc_824B0258;
	// bl 0x82130588
	ctx.lr = 0x824B0254;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B0258:
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

__attribute__((alias("__imp__sub_824B0270"))) PPC_WEAK_FUNC(sub_824B0270);
PPC_FUNC_IMPL(__imp__sub_824B0270) {
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
	// bl 0x82619428
	ctx.lr = 0x824B0290;
	sub_82619428(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,6164
	ctx.r10.s64 = r11.s64 + 6164;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82496728
	ctx.lr = 0x824B02A8;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82496728
	ctx.lr = 0x824B02B4;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x82496728
	ctx.lr = 0x824B02C0;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82496728
	ctx.lr = 0x824B02CC;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// bl 0x82496728
	ctx.lr = 0x824B02D8;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x82496728
	ctx.lr = 0x824B02E4;
	sub_82496728(ctx, base);
	// addi r3,r31,248
	ctx.r3.s64 = r31.s64 + 248;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821d2aa8
	ctx.lr = 0x824B02F0;
	sub_821D2AA8(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x824aff00
	ctx.lr = 0x824B02F8;
	sub_824AFF00(ctx, base);
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

__attribute__((alias("__imp__sub_824B0314"))) PPC_WEAK_FUNC(sub_824B0314);
PPC_FUNC_IMPL(__imp__sub_824B0314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0318"))) PPC_WEAK_FUNC(sub_824B0318);
PPC_FUNC_IMPL(__imp__sub_824B0318) {
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
	// li r3,288
	ctx.r3.s64 = 288;
	// bl 0x82130528
	ctx.lr = 0x824B032C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b034c
	if (cr6.eq) goto loc_824B034C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824b0100
	ctx.lr = 0x824B033C;
	sub_824B0100(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B034C:
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

__attribute__((alias("__imp__sub_824B0360"))) PPC_WEAK_FUNC(sub_824B0360);
PPC_FUNC_IMPL(__imp__sub_824B0360) {
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
	ctx.lr = 0x824B0368;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r11,30576
	ctx.r3.s64 = r11.s64 + 30576;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x824B0388;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b03dc
	if (cr6.eq) goto loc_824B03DC;
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b03ac
	if (cr6.eq) goto loc_824B03AC;
	// bl 0x821be8d8
	ctx.lr = 0x824B03A8;
	sub_821BE8D8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_824B03AC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b03dc
	if (cr6.eq) goto loc_824B03DC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824b0088
	ctx.lr = 0x824B03C4;
	sub_824B0088(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x824B03D0;
	sub_821BE610(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_824B03DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B03E8"))) PPC_WEAK_FUNC(sub_824B03E8);
PPC_FUNC_IMPL(__imp__sub_824B03E8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20876
	r31.s64 = r11.s64 + 20876;
	// lwz r11,20876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b04e8
	if (!cr6.eq) goto loc_824B04E8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824B0418;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b042c
	if (cr6.eq) goto loc_824B042C;
	// bl 0x821d5408
	ctx.lr = 0x824B0428;
	sub_821D5408(ctx, base);
	// b 0x824b0430
	goto loc_824B0430;
loc_824B042C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824B0430:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32168
	r11.s64 = -2108162048;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,6300
	ctx.r7.s64 = ctx.r10.s64 + 6300;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,13856
	ctx.r9.s64 = r11.s64 + 13856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r4,288
	ctx.r4.s64 = 288;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32181
	ctx.r8.s64 = -2109014016;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r8,792
	ctx.r10.s64 = ctx.r8.s64 + 792;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r9.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824B0494;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824B04A4;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824B04C0;
	sub_821D41D0(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,20872
	ctx.r4.s64 = ctx.r6.s64 + 20872;
	// bl 0x821d4b00
	ctx.lr = 0x824B04D0;
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
	ctx.lr = 0x824B04E8;
	sub_821C0548(ctx, base);
loc_824B04E8:
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

__attribute__((alias("__imp__sub_824B0500"))) PPC_WEAK_FUNC(sub_824B0500);
PPC_FUNC_IMPL(__imp__sub_824B0500) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-32120
	ctx.r4.s64 = ctx.r10.s64 + -32120;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821ca540
	ctx.lr = 0x824B0538;
	sub_821CA540(ctx, base);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,6332
	ctx.r4.s64 = ctx.r8.s64 + 6332;
	// bl 0x821ca540
	ctx.lr = 0x824B0548;
	sub_821CA540(ctx, base);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,6320
	ctx.r5.s64 = ctx.r5.s64 + 6320;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x824b0360
	ctx.lr = 0x824B0564;
	sub_824B0360(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B056C;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B0574;
	sub_821C9A90(ctx, base);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x824b059c
	if (cr6.eq) goto loc_824B059C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B0598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B059C:
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

__attribute__((alias("__imp__sub_824B05B4"))) PPC_WEAK_FUNC(sub_824B05B4);
PPC_FUNC_IMPL(__imp__sub_824B05B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B05B8"))) PPC_WEAK_FUNC(sub_824B05B8);
PPC_FUNC_IMPL(__imp__sub_824B05B8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6680
	ctx.r4.s64 = r11.s64 + 6680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c82a8
	ctx.lr = 0x824B05E8;
	sub_821C82A8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824b060c
	if (!cr6.eq) goto loc_824B060C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6696
	ctx.r4.s64 = r11.s64 + 6696;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c82a8
	ctx.lr = 0x824B0604;
	sub_821C82A8(ctx, base);
	// bl 0x821c7f98
	ctx.lr = 0x824B0608;
	sub_821C7F98(ctx, base);
	// stfs f1,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 324, temp.u32);
loc_824B060C:
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

__attribute__((alias("__imp__sub_824B0624"))) PPC_WEAK_FUNC(sub_824B0624);
PPC_FUNC_IMPL(__imp__sub_824B0624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0628"))) PPC_WEAK_FUNC(sub_824B0628);
PPC_FUNC_IMPL(__imp__sub_824B0628) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// b 0x824dacd8
	sub_824DACD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B0630"))) PPC_WEAK_FUNC(sub_824B0630);
PPC_FUNC_IMPL(__imp__sub_824B0630) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// b 0x824dad30
	sub_824DAD30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B0638"))) PPC_WEAK_FUNC(sub_824B0638);
PPC_FUNC_IMPL(__imp__sub_824B0638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,300(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x824b0650
	if (!cr6.lt) goto loc_824B0650;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_824B0650:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfs f0,292(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	f0.f64 = double(temp.f32);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0674"))) PPC_WEAK_FUNC(sub_824B0674);
PPC_FUNC_IMPL(__imp__sub_824B0674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0678"))) PPC_WEAK_FUNC(sub_824B0678);
PPC_FUNC_IMPL(__imp__sub_824B0678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// stb r11,484(r4)
	PPC_STORE_U8(ctx.r4.u32 + 484, r11.u8);
	// b 0x824dae40
	sub_824DAE40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B0690"))) PPC_WEAK_FUNC(sub_824B0690);
PPC_FUNC_IMPL(__imp__sub_824B0690) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0694"))) PPC_WEAK_FUNC(sub_824B0694);
PPC_FUNC_IMPL(__imp__sub_824B0694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0698"))) PPC_WEAK_FUNC(sub_824B0698);
PPC_FUNC_IMPL(__imp__sub_824B0698) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// b 0x824daeb0
	sub_824DAEB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B06A0"))) PPC_WEAK_FUNC(sub_824B06A0);
PPC_FUNC_IMPL(__imp__sub_824B06A0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// b 0x824db160
	sub_824DB160(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B06A8"))) PPC_WEAK_FUNC(sub_824B06A8);
PPC_FUNC_IMPL(__imp__sub_824B06A8) {
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
	// bl 0x824b0270
	ctx.lr = 0x824B06C8;
	sub_824B0270(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,7100
	ctx.r10.s64 = r11.s64 + 7100;
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824db8e8
	ctx.lr = 0x824B06E0;
	sub_824DB8E8(ctx, base);
	// lbz r11,377(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 377);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// ble cr6,0x824b06f0
	if (!cr6.gt) goto loc_824B06F0;
	// li r11,2
	r11.s64 = 2;
loc_824B06F0:
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,377(r31)
	PPC_STORE_U8(r31.u32 + 377, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,368(r31)
	PPC_STORE_U32(r31.u32 + 368, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_824B0718"))) PPC_WEAK_FUNC(sub_824B0718);
PPC_FUNC_IMPL(__imp__sub_824B0718) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20880);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0724"))) PPC_WEAK_FUNC(sub_824B0724);
PPC_FUNC_IMPL(__imp__sub_824B0724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0728"))) PPC_WEAK_FUNC(sub_824B0728);
PPC_FUNC_IMPL(__imp__sub_824B0728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x824B0730;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// lhz r10,308(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 308);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b07bc
	if (cr6.eq) goto loc_824B07BC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// lfs f30,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f30.f64 = double(temp.f32);
loc_824B0764:
	// lwz r11,304(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 304);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x824b07a8
	if (!cr6.eq) goto loc_824B07A8;
	// lwz r3,76(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b07a8
	if (cr6.eq) goto loc_824B07A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B0794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// beq cr6,0x824b07d0
	if (cr6.eq) goto loc_824B07D0;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x824b07a8
	if (!cr6.gt) goto loc_824B07A8;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
loc_824B07A8:
	// lhz r11,308(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 308);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824b0764
	if (cr6.lt) goto loc_824B0764;
loc_824B07BC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_824B07D0:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B07E4"))) PPC_WEAK_FUNC(sub_824B07E4);
PPC_FUNC_IMPL(__imp__sub_824B07E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B07E8"))) PPC_WEAK_FUNC(sub_824B07E8);
PPC_FUNC_IMPL(__imp__sub_824B07E8) {
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
	ctx.lr = 0x824B07F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r27,r26
	r27.u64 = r26.u64;
	// lhz r11,308(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b0890
	if (cr6.eq) goto loc_824B0890;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_824B0814:
	// lwz r11,304(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 304);
	// lwzx r30,r11,r29
	r30.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x824b087c
	if (!cr6.eq) goto loc_824B087C;
	// lwz r31,72(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x824b087c
	if (cr6.eq) goto loc_824B087C;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824B083C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824b0864
	if (!cr6.eq) goto loc_824B0864;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b0864
	if (cr6.eq) goto loc_824B0864;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B0864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B0864:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b0878
	if (cr6.eq) goto loc_824B0878;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x824aee58
	ctx.lr = 0x824B0878;
	sub_824AEE58(ctx, base);
loc_824B0878:
	// stw r26,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r26.u32);
loc_824B087C:
	// lhz r11,308(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 308);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x824b0814
	if (cr6.lt) goto loc_824B0814;
loc_824B0890:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824B0898"))) PPC_WEAK_FUNC(sub_824B0898);
PPC_FUNC_IMPL(__imp__sub_824B0898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,308(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 308);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b0904
	if (cr6.eq) goto loc_824B0904;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
loc_824B08B4:
	// lwz r11,304(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x824b08ec
	if (!cr6.eq) goto loc_824B08EC;
	// lwz r11,140(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 140);
	// li r10,2
	ctx.r10.s64 = 2;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
loc_824B08D8:
	// stw r9,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, ctx.r9.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x824b08d8
	if (!cr0.eq) goto loc_824B08D8;
loc_824B08EC:
	// lhz r11,308(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 308);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r8,r8,288
	ctx.r8.s64 = ctx.r8.s64 + 288;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x824b08b4
	if (cr6.lt) goto loc_824B08B4;
loc_824B0904:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// stw r9,476(r4)
	PPC_STORE_U32(ctx.r4.u32 + 476, ctx.r9.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r10,624(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 624);
	// stw r8,472(r4)
	PPC_STORE_U32(ctx.r4.u32 + 472, ctx.r8.u32);
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r7,r11,r8
	ctx.r7.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// stb r9,688(r6)
	PPC_STORE_U8(ctx.r6.u32 + 688, ctx.r9.u8);
	// lwz r5,624(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 624);
	// stb r9,668(r5)
	PPC_STORE_U8(ctx.r5.u32 + 668, ctx.r9.u8);
	// lhz r3,308(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 308);
	// stb r3,495(r4)
	PPC_STORE_U8(ctx.r4.u32 + 495, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0948"))) PPC_WEAK_FUNC(sub_824B0948);
PPC_FUNC_IMPL(__imp__sub_824B0948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b0990
	if (!cr6.eq) goto loc_824B0990;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// beq cr6,0x824b09e4
	if (cr6.eq) goto loc_824B09E4;
loc_824B0990:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B09AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824B09C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,96(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824B09E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B09E4:
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

__attribute__((alias("__imp__sub_824B0A00"))) PPC_WEAK_FUNC(sub_824B0A00);
PPC_FUNC_IMPL(__imp__sub_824B0A00) {
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
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824db210
	ctx.lr = 0x824B0A1C;
	sub_824DB210(ctx, base);
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b0a48
	if (!cr6.eq) goto loc_824B0A48;
	// lbz r11,485(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 485);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b0a48
	if (cr6.eq) goto loc_824B0A48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x8247de78
	ctx.lr = 0x824B0A48;
	sub_8247DE78(ctx, base);
loc_824B0A48:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B0A5C"))) PPC_WEAK_FUNC(sub_824B0A5C);
PPC_FUNC_IMPL(__imp__sub_824B0A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0A60"))) PPC_WEAK_FUNC(sub_824B0A60);
PPC_FUNC_IMPL(__imp__sub_824B0A60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f13,400(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// addi r7,r9,2176
	ctx.r7.s64 = ctx.r9.s64 + 2176;
	// ori r11,r8,64167
	r11.u64 = ctx.r8.u64 | 64167;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r10,2176(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r31,r11
	r31.u64 = r11.u64;
	// mr r30,r11
	r30.u64 = r11.u64;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r10,r5
	ctx.r10.s64 = ctx.r10.s64 * ctx.r5.s64;
	// lfs f0,14348(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14348);
	f0.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f12.f64));
	// stfs f6,384(r4)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r4.u32 + 384, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f5,404(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 404);
	ctx.f5.f64 = double(temp.f32);
	// lwz r6,2176(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mulld r10,r6,r8
	ctx.r10.s64 = ctx.r6.s64 * ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fneg f4,f5
	ctx.f4.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f2,-32(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// frsp f13,f1
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f12,f3,f13
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fmadds f11,f12,f0,f4
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f4.f64));
	// stfs f11,388(r4)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r4.u32 + 388, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f10,408(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 408);
	ctx.f10.f64 = double(temp.f32);
	// lwz r6,2176(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mulld r10,r6,r31
	ctx.r10.s64 = ctx.r6.s64 * r31.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fneg f9,f10
	ctx.f9.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f7,-32(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f4,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// fmadds f3,f4,f0,f9
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f9.f64));
	// stfs f3,392(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 392, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lfs f2,348(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	ctx.f2.f64 = double(temp.f32);
	// lwz r6,2176(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mulld r10,r6,r30
	ctx.r10.s64 = ctx.r6.s64 * r30.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f1,352(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 352);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r4,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// lfd f12,-32(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmadds f8,f9,f0,f2
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f2.f64));
	// stfs f8,292(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0BCC"))) PPC_WEAK_FUNC(sub_824B0BCC);
PPC_FUNC_IMPL(__imp__sub_824B0BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0BD0"))) PPC_WEAK_FUNC(sub_824B0BD0);
PPC_FUNC_IMPL(__imp__sub_824B0BD0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r3,288
	ctx.r3.s64 = ctx.r3.s64 + 288;
	// stb r11,484(r31)
	PPC_STORE_U8(r31.u32 + 484, r11.u8);
	// bl 0x824db5d8
	ctx.lr = 0x824B0BF4;
	sub_824DB5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a950
	ctx.lr = 0x824B0BFC;
	sub_8247A950(ctx, base);
	// lwz r10,612(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824b0c1c
	if (!cr6.eq) goto loc_824B0C1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x8247de78
	ctx.lr = 0x824B0C1C;
	sub_8247DE78(ctx, base);
loc_824B0C1C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B0C30"))) PPC_WEAK_FUNC(sub_824B0C30);
PPC_FUNC_IMPL(__imp__sub_824B0C30) {
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
	ctx.lr = 0x824B0C38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,44(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 44);
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x824b0c88
	if (cr0.lt) goto loc_824B0C88;
	// rlwinm r31,r30,2,0,29
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_824B0C54:
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// lwzx r28,r11,r31
	r28.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b0c74
	if (cr6.eq) goto loc_824B0C74;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82495d58
	ctx.lr = 0x824B0C6C;
	sub_82495D58(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x824B0C74;
	sub_82130588(ctx, base);
loc_824B0C74:
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x824b0c54
	if (!cr0.lt) goto loc_824B0C54;
loc_824B0C88:
	// lwz r3,40(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// addi r31,r29,40
	r31.s64 = r29.s64 + 40;
	// bl 0x82130588
	ctx.lr = 0x824B0C94;
	sub_82130588(ctx, base);
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// stw r27,40(r29)
	PPC_STORE_U32(r29.u32 + 40, r27.u32);
	// sth r27,44(r29)
	PPC_STORE_U16(r29.u32 + 44, r27.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r27,46(r29)
	PPC_STORE_U16(r29.u32 + 46, r27.u16);
	// beq cr6,0x824b0cb4
	if (cr6.eq) goto loc_824B0CB4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824B0CB4;
	sub_82130588(ctx, base);
loc_824B0CB4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B0CBC"))) PPC_WEAK_FUNC(sub_824B0CBC);
PPC_FUNC_IMPL(__imp__sub_824B0CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0CC0"))) PPC_WEAK_FUNC(sub_824B0CC0);
PPC_FUNC_IMPL(__imp__sub_824B0CC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b0d0c
	if (cr6.eq) goto loc_824B0D0C;
	// lwz r11,592(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 592);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b0d0c
	if (cr6.eq) goto loc_824B0D0C;
	// lfs f0,588(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 588);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// stfs f0,8(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// stfs f0,4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B0D0C:
	// lhz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b0d40
	if (!cr6.gt) goto loc_824B0D40;
	// lwz r6,112(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// addi r10,r6,48
	ctx.r10.s64 = ctx.r6.s64 + 48;
loc_824B0D24:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b0dd4
	if (!cr6.lt) goto loc_824B0DD4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b0d24
	if (cr6.lt) goto loc_824B0D24;
loc_824B0D40:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,112(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B0D54:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,256(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b0dc4
	if (cr6.eq) goto loc_824B0DC4;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824aff80
	ctx.lr = 0x824B0DC4;
	sub_824AFF80(ctx, base);
loc_824B0DC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B0DD4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// b 0x824b0d54
	goto loc_824B0D54;
}

__attribute__((alias("__imp__sub_824B0DE8"))) PPC_WEAK_FUNC(sub_824B0DE8);
PPC_FUNC_IMPL(__imp__sub_824B0DE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x824b06a8
	sub_824B06A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B0DF4"))) PPC_WEAK_FUNC(sub_824B0DF4);
PPC_FUNC_IMPL(__imp__sub_824B0DF4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B0DF8"))) PPC_WEAK_FUNC(sub_824B0DF8);
PPC_FUNC_IMPL(__imp__sub_824B0DF8) {
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
	ctx.lr = 0x824B0E00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-32120
	ctx.r4.s64 = ctx.r10.s64 + -32120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x824B0E24;
	sub_821CA540(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,6332
	ctx.r4.s64 = ctx.r9.s64 + 6332;
	// bl 0x821ca540
	ctx.lr = 0x824B0E34;
	sub_821CA540(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r28,2828(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2828);
	// beq cr6,0x824b0e60
	if (cr6.eq) goto loc_824B0E60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B0E58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x824b0e68
	goto loc_824B0E68;
loc_824B0E60:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,20880(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20880);
loc_824B0E68:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r11,6320
	ctx.r5.s64 = r11.s64 + 6320;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c04b0
	ctx.lr = 0x824B0E84;
	sub_821C04B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B0E90;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B0E98;
	sub_821C9A90(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b0eb0
	if (!cr6.eq) goto loc_824B0EB0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824B0EB0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B0EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B0ED4"))) PPC_WEAK_FUNC(sub_824B0ED4);
PPC_FUNC_IMPL(__imp__sub_824B0ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B0ED8"))) PPC_WEAK_FUNC(sub_824B0ED8);
PPC_FUNC_IMPL(__imp__sub_824B0ED8) {
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
	ctx.lr = 0x824B0EE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,288
	r29.s64 = r31.s64 + 288;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824dad68
	ctx.lr = 0x824B0EF8;
	sub_824DAD68(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x8247edc0
	ctx.lr = 0x824B0F08;
	sub_8247EDC0(ctx, base);
	// bl 0x824c2b28
	ctx.lr = 0x824B0F0C;
	sub_824C2B28(ctx, base);
	// stb r3,492(r30)
	PPC_STORE_U8(r30.u32 + 492, ctx.r3.u8);
	// bl 0x824c2b28
	ctx.lr = 0x824B0F14;
	sub_824C2B28(ctx, base);
	// stb r3,493(r30)
	PPC_STORE_U8(r30.u32 + 493, ctx.r3.u8);
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b0f38
	if (cr6.eq) goto loc_824B0F38;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r4,r11,7236
	ctx.r4.s64 = r11.s64 + 7236;
	// bl 0x8247bc80
	ctx.lr = 0x824B0F30;
	sub_8247BC80(ctx, base);
	// extsb r10,r3
	ctx.r10.s64 = ctx.r3.s8;
	// b 0x824b0f3c
	goto loc_824B0F3C;
loc_824B0F38:
	// li r10,-1
	ctx.r10.s64 = -1;
loc_824B0F3C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stb r10,608(r30)
	PPC_STORE_U8(r30.u32 + 608, ctx.r10.u8);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lfs f13,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 348);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,2176
	r11.s64 = r11.s64 + 2176;
	// lfs f12,352(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 352);
	ctx.f12.f64 = double(temp.f32);
	// ori r9,r9,64167
	ctx.r9.u64 = ctx.r9.u64 | 64167;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r8,r6,r9
	ctx.r8.s64 = ctx.r6.s64 * ctx.r9.s64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lfs f0,14348(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14348);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r10,9
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,292(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// lwz r3,592(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// rlwinm r10,r3,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b0fd8
	if (cr6.eq) goto loc_824B0FD8;
	// lfs f0,488(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 488);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f13,580(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 580);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,488(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 488, temp.u32);
	// bl 0x824db6e8
	ctx.lr = 0x824B0FD0;
	sub_824DB6E8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824B0FD8:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 356);
	ctx.f12.f64 = double(temp.f32);
	// mulld r9,r7,r8
	ctx.r9.s64 = ctx.r7.s64 * ctx.r8.s64;
	// lfs f11,360(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 360);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// clrlwi r4,r10,9
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lfs f13,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// fmuls f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f7.f64));
	// fmadds f0,f6,f0,f12
	f0.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x824b1040
	if (!cr6.lt) goto loc_824B1040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_824B1040:
	// stfs f0,488(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 488, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824db6e8
	ctx.lr = 0x824B1050;
	sub_824DB6E8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B1058"))) PPC_WEAK_FUNC(sub_824B1058);
PPC_FUNC_IMPL(__imp__sub_824B1058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x824B1070;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,487(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 487);
	// stb r10,486(r31)
	PPC_STORE_U8(r31.u32 + 486, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1124
	if (cr6.eq) goto loc_824B1124;
	// lbz r11,372(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1124
	if (cr6.eq) goto loc_824B1124;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r9,624(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lbz r8,688(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 688);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824b1124
	if (cr6.eq) goto loc_824B1124;
	// lbz r11,374(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 374);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,486(r31)
	PPC_STORE_U8(r31.u32 + 486, ctx.r9.u8);
	// lbz r8,373(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 373);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824b1124
	if (cr6.eq) goto loc_824B1124;
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b1124
	if (cr6.eq) goto loc_824B1124;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B1104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x824b1124
	if (!cr6.eq) goto loc_824B1124;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,288
	ctx.r3.s64 = r30.s64 + 288;
	// bl 0x824db350
	ctx.lr = 0x824B1120;
	sub_824DB350(ctx, base);
	// b 0x824b13b4
	goto loc_824B13B4;
loc_824B1124:
	// lbz r11,608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 608);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// bge cr6,0x824b134c
	if (!cr6.lt) goto loc_824B134C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,340(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 340);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x824b134c
	if (!cr6.gt) goto loc_824B134C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r7,-4916(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// addi r11,r7,1216
	r11.s64 = ctx.r7.s64 + 1216;
	// lwz r10,1220(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1220);
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// clrlwi r3,r4,24
	ctx.r3.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b11a8
	if (cr6.eq) goto loc_824B11A8;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b1198
	if (cr6.eq) goto loc_824B1198;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B1194;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824b1300
	goto loc_824B1300;
loc_824B1198:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B11A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824b1300
	goto loc_824B1300;
loc_824B11A8:
	// lwz r8,1200(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 1200);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x824b1300
	if (!cr6.gt) goto loc_824B1300;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// lfs f0,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f0.f64 = double(temp.f32);
	// blt cr6,0x824b12a0
	if (cr6.lt) goto loc_824B12A0;
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// lfs f13,288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,292(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r7,696
	r11.s64 = ctx.r7.s64 + 696;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// lfs f11,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_824B11E4:
	// lfs f10,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfs f2,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// lfs f6,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f1,f11,f2
	ctx.f1.f64 = double(float(ctx.f11.f64 - ctx.f2.f64));
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f4,f13,f6
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f6,f13,f10
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// lfs f2,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// lfs f5,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f10,f11,f2
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f2.f64));
	// lfs f8,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f3,f12,f5
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f5.f64));
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f5,f12,f8
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fsubs f2,f12,f2
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f2.f64));
	// lfs f29,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f29.f64 = double(temp.f32);
	// fsubs f29,f11,f29
	f29.f64 = double(float(ctx.f11.f64 - f29.f64));
	// lfs f8,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// lfs f28,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	f28.f64 = double(temp.f32);
	// fsubs f8,f13,f8
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// fsubs f28,f13,f28
	f28.f64 = double(float(ctx.f13.f64 - f28.f64));
	// fmuls f3,f3,f3
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fmuls f5,f5,f5
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fmuls f2,f2,f2
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// fmadds f9,f7,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f9.f64));
	// fmadds f7,f1,f1,f3
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f3.f64));
	// fmadds f5,f10,f10,f5
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f5.f64));
	// fmadds f3,f29,f29,f2
	ctx.f3.f64 = double(float(f29.f64 * f29.f64 + ctx.f2.f64));
	// fmadds f2,f4,f4,f9
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f9.f64));
	// fmadds f1,f6,f6,f7
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fmadds f10,f8,f8,f5
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f9,f28,f28,f3
	ctx.f9.f64 = double(float(f28.f64 * f28.f64 + ctx.f3.f64));
	// fsubs f8,f0,f2
	ctx.f8.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f7,f8,f2,f0
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fsubs f6,f7,f1
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f1.f64));
	// fsel f5,f6,f1,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f1.f64 : ctx.f7.f64;
	// fsubs f4,f5,f10
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f10.f64));
	// fsel f3,f4,f10,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f10.f64 : ctx.f5.f64;
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// fsel f0,f2,f9,f3
	f0.f64 = ctx.f2.f64 >= 0.0 ? ctx.f9.f64 : ctx.f3.f64;
	// bne 0x824b11e4
	if (!cr0.eq) goto loc_824B11E4;
loc_824B12A0:
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x824b12fc
	if (!cr6.lt) goto loc_824B12FC;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,288(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,292(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// subf r10,r9,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r9.s64;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// lfs f11,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,696
	r11.s64 = r11.s64 + 696;
loc_824B12C4:
	// lfs f10,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// lfs f6,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f13,f6
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsubs f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f0,f1,f2,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// bne 0x824b12c4
	if (!cr0.eq) goto loc_824B12C4;
loc_824B12FC:
	// fsqrts f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(sqrt(f0.f64)));
loc_824B1300:
	// lfs f0,336(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 336);
	f0.f64 = double(temp.f32);
	// lfs f13,340(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x824b1318
	if (cr6.gt) goto loc_824B1318;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x824b1338
	goto loc_824B1338;
loc_824B1318:
	// fcmpu cr6,f1,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// blt cr6,0x824b132c
	if (cr6.lt) goto loc_824B132C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// b 0x824b1338
	goto loc_824B1338;
loc_824B132C:
	// fsubs f12,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
loc_824B1338:
	// lbz r11,608(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 608);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// addi r10,r11,109
	ctx.r10.s64 = r11.s64 + 109;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r31
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, temp.u32);
loc_824B134C:
	// lwz r11,624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// addi r7,r31,436
	ctx.r7.s64 = r31.s64 + 436;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 656);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824b0cc0
	ctx.lr = 0x824B1368;
	sub_824B0CC0(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lbz r7,492(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 492);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r8,r10,20976
	ctx.r8.s64 = ctx.r10.s64 + 20976;
	// lfs f10,504(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 504);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,288
	ctx.r3.s64 = r30.s64 + 288;
	// lfsx f9,r6,r8
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f13,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f9,f11,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + f0.f64));
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f6,500(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// bl 0x824daf28
	ctx.lr = 0x824B13B4;
	sub_824DAF28(ctx, base);
loc_824B13B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x824B13C0;
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

__attribute__((alias("__imp__sub_824B13D4"))) PPC_WEAK_FUNC(sub_824B13D4);
PPC_FUNC_IMPL(__imp__sub_824B13D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B13D8"))) PPC_WEAK_FUNC(sub_824B13D8);
PPC_FUNC_IMPL(__imp__sub_824B13D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B13E0;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x824B13E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b1414
	if (!cr6.eq) goto loc_824B1414;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824b1418
	if (cr6.eq) goto loc_824B1418;
loc_824B1414:
	// li r11,1
	r11.s64 = 1;
loc_824B1418:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b144c
	if (cr6.eq) goto loc_824B144C;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B1434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// lbz r3,668(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 668);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x824B1448;
	// b 0x823d9248
	return;
loc_824B144C:
	// lbz r11,487(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 487);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1644
	if (cr6.eq) goto loc_824B1644;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,328(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 328);
	f0.f64 = double(temp.f32);
	// lfs f27,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f27.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// bne cr6,0x824b1478
	if (!cr6.eq) goto loc_824B1478;
	// lfs f0,332(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 332);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// beq cr6,0x824b1644
	if (cr6.eq) goto loc_824B1644;
loc_824B1478:
	// addi r30,r31,500
	r30.s64 = r31.s64 + 500;
	// lfs f0,332(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 332);
	f0.f64 = double(temp.f32);
	// li r10,384
	ctx.r10.s64 = 384;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// li r8,32
	ctx.r8.s64 = 32;
	// lvlx128 v63,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r7,48
	ctx.r7.s64 = 48;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r29,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r9,2384
	ctx.r5.s64 = ctx.r9.s64 + 2384;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v57,r11,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r4,2352
	ctx.r3.s64 = ctx.r4.s64 + 2352;
	// vmrghw128 v56,v60,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v55,r11,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v60,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v55,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v52,v55,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v56,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v50,v56,v53
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v49,v54,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vand128 v48,v58,v63
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v47,v62,v48
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vmsum4fp128 v46,v47,v51
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v45,v47,v49
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v44,v47,v50
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v43,v46,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v42,v44,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v41,v42,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v41,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// lfs f29,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f29.f64 = double(temp.f32);
	// lfs f28,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f28.f64 = double(temp.f32);
	// ble cr6,0x824b160c
	if (!cr6.gt) goto loc_824B160C;
	// lbz r11,268(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b153c
	if (cr6.eq) goto loc_824B153C;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_824B153C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,508(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 508);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lwz r11,-4916(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// addi r11,r11,1216
	r11.s64 = r11.s64 + 1216;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824b15a0
	if (cr6.eq) goto loc_824B15A0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b1590
	if (cr6.eq) goto loc_824B1590;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B158C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824b15c8
	goto loc_824B15C8;
loc_824B1590:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B159C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824b15c8
	goto loc_824B15C8;
loc_824B15A0:
	// lwz r11,-26876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// lfs f0,116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	f0.f64 = double(temp.f32);
	// fsubs f13,f29,f0
	ctx.f13.f64 = double(float(f29.f64 - f0.f64));
	// lfs f12,120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f30,f12
	ctx.f11.f64 = double(float(f30.f64 - ctx.f12.f64));
	// lfs f10,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f28,f10
	ctx.f9.f64 = double(float(f28.f64 - ctx.f10.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f1,f9,f9,f7
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
loc_824B15C8:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// fmuls f0,f31,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 * f31.f64));
	// lwz r9,624(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// stfs f1,684(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 684, temp.u32);
	// ble cr6,0x824b160c
	if (!cr6.gt) goto loc_824B160C;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x824B1608;
	// b 0x823d9248
	return;
loc_824B160C:
	// lfs f0,328(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 328);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x824b1644
	if (!cr6.gt) goto loc_824B1644;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// fmuls f4,f0,f13
	ctx.f4.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x8217c328
	ctx.lr = 0x824B1638;
	sub_8217C328(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x824b1648
	if (cr6.eq) goto loc_824B1648;
loc_824B1644:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824B1648:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x824B1654;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B1658"))) PPC_WEAK_FUNC(sub_824B1658);
PPC_FUNC_IMPL(__imp__sub_824B1658) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,372(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b16e0
	if (cr6.eq) goto loc_824B16E0;
	// lbz r11,487(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 487);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b16e0
	if (cr6.eq) goto loc_824B16E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-4916(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// lbz r10,125(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 125);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b16ac
	if (cr6.eq) goto loc_824B16AC;
	// lwz r11,624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,668(r11)
	PPC_STORE_U8(r11.u32 + 668, ctx.r10.u8);
loc_824B16AC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824b13d8
	ctx.lr = 0x824B16B8;
	sub_824B13D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b16d4
	if (cr6.eq) goto loc_824B16D4;
	// lbz r11,375(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 375);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b184c
	if (!cr6.eq) goto loc_824B184C;
	// b 0x824b16e0
	goto loc_824B16E0;
loc_824B16D4:
	// lwz r11,624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,668(r11)
	PPC_STORE_U8(r11.u32 + 668, ctx.r10.u8);
loc_824B16E0:
	// lbz r11,487(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 487);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b17ac
	if (cr6.eq) goto loc_824B17AC;
	// lbz r11,372(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b17ac
	if (cr6.eq) goto loc_824B17AC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,324(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 324);
	f0.f64 = double(temp.f32);
	// lfs f10,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x824b17ac
	if (!cr6.gt) goto loc_824B17AC;
	// lbz r11,268(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1728
	if (cr6.eq) goto loc_824B1728;
	// lfs f13,500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,332(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 332);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// b 0x824b172c
	goto loc_824B172C;
loc_824B1728:
	// lfs f13,332(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 332);
	ctx.f13.f64 = double(temp.f32);
loc_824B172C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b173c
	if (cr6.eq) goto loc_824B173C;
	// lfs f12,500(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 500);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
loc_824B173C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f11,508(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 508);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lwz r9,624(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lfs f11,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lfs f9,684(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 684);
	ctx.f9.f64 = double(temp.f32);
	// fsqrts f13,f9
	ctx.f13.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x824b1788
	if (cr6.gt) goto loc_824B1788;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
	// b 0x824b17a4
	goto loc_824B17A4;
loc_824B1788:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x824b1798
	if (cr6.lt) goto loc_824B1798;
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
	// b 0x824b17a4
	goto loc_824B17A4;
loc_824B1798:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f0,f13,f12
	f0.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
loc_824B17A4:
	// fsubs f0,f11,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f11.f64 - f0.f64));
	// stfs f0,496(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
loc_824B17AC:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r3,r31,64
	ctx.r3.s64 = r31.s64 + 64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b17cc
	if (!cr6.eq) goto loc_824B17CC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824b17d0
	if (cr6.eq) goto loc_824B17D0;
loc_824B17CC:
	// li r11,1
	r11.s64 = 1;
loc_824B17D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b17ec
	if (cr6.eq) goto loc_824B17EC;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B17EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B17EC:
	// lbz r11,376(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 376);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,288
	ctx.r3.s64 = r30.s64 + 288;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1808
	if (cr6.eq) goto loc_824B1808;
	// bl 0x824db3f0
	ctx.lr = 0x824B1804;
	sub_824DB3F0(ctx, base);
	// b 0x824b180c
	goto loc_824B180C;
loc_824B1808:
	// bl 0x824db568
	ctx.lr = 0x824B180C;
	sub_824DB568(ctx, base);
loc_824B180C:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b182c
	if (!cr6.eq) goto loc_824B182C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x824b1830
	if (cr6.eq) goto loc_824B1830;
loc_824B182C:
	// li r11,1
	r11.s64 = 1;
loc_824B1830:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b184c
	if (cr6.eq) goto loc_824B184C;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B184C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B184C:
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

__attribute__((alias("__imp__sub_824B1864"))) PPC_WEAK_FUNC(sub_824B1864);
PPC_FUNC_IMPL(__imp__sub_824B1864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B1868"))) PPC_WEAK_FUNC(sub_824B1868);
PPC_FUNC_IMPL(__imp__sub_824B1868) {
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
	ctx.lr = 0x824B1870;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// addic. r30,r11,-1
	xer.ca = r11.u32 > 0;
	r30.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x824b18c0
	if (cr0.lt) goto loc_824B18C0;
	// rlwinm r31,r30,2,0,29
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
loc_824B188C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r28,r11,r31
	r28.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b18ac
	if (cr6.eq) goto loc_824B18AC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b0c30
	ctx.lr = 0x824B18A4;
	sub_824B0C30(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x824B18AC;
	sub_82130588(ctx, base);
loc_824B18AC:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x824b188c
	if (!cr0.lt) goto loc_824B188C;
loc_824B18C0:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// bl 0x82130588
	ctx.lr = 0x824B18CC;
	sub_82130588(ctx, base);
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// stw r27,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r27.u32);
	// sth r27,8(r29)
	PPC_STORE_U16(r29.u32 + 8, r27.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// sth r27,10(r29)
	PPC_STORE_U16(r29.u32 + 10, r27.u16);
	// beq cr6,0x824b18ec
	if (cr6.eq) goto loc_824B18EC;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824B18EC;
	sub_82130588(ctx, base);
loc_824B18EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x824B18F4;
	sub_821D2AA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B18FC"))) PPC_WEAK_FUNC(sub_824B18FC);
PPC_FUNC_IMPL(__imp__sub_824B18FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B1900"))) PPC_WEAK_FUNC(sub_824B1900);
PPC_FUNC_IMPL(__imp__sub_824B1900) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824B1908;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x824B1918;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x824b19a0
	if (!cr6.gt) goto loc_824B19A0;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_824B1930:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b1994
	if (cr6.eq) goto loc_824B1994;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b1990
	if (cr6.eq) goto loc_824B1990;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824b1990
	if (cr6.eq) goto loc_824B1990;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824B1964;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824b1990
	if (cr6.eq) goto loc_824B1990;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x824B1978;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x824dd1d8
	ctx.lr = 0x824B198C;
	sub_824DD1D8(ctx, base);
	// b 0x824b1994
	goto loc_824B1994;
loc_824B1990:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_824B1994:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x824b1930
	if (!cr0.eq) goto loc_824B1930;
loc_824B19A0:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824B19AC"))) PPC_WEAK_FUNC(sub_824B19AC);
PPC_FUNC_IMPL(__imp__sub_824B19AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B19B0"))) PPC_WEAK_FUNC(sub_824B19B0);
PPC_FUNC_IMPL(__imp__sub_824B19B0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824B19B8;
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
	// addi r10,r11,7244
	ctx.r10.s64 = r11.s64 + 7244;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// sth r30,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r30.u16);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// bl 0x821b5a60
	ctx.lr = 0x824B19E8;
	sub_821B5A60(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// bl 0x824b1900
	ctx.lr = 0x824B1A14;
	sub_824B1900(ctx, base);
	// li r7,32
	ctx.r7.s64 = 32;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r7,22(r31)
	PPC_STORE_U16(r31.u32 + 22, ctx.r7.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B1A2C"))) PPC_WEAK_FUNC(sub_824B1A2C);
PPC_FUNC_IMPL(__imp__sub_824B1A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B1A30"))) PPC_WEAK_FUNC(sub_824B1A30);
PPC_FUNC_IMPL(__imp__sub_824B1A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29996);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B1A3C"))) PPC_WEAK_FUNC(sub_824B1A3C);
PPC_FUNC_IMPL(__imp__sub_824B1A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B1A40"))) PPC_WEAK_FUNC(sub_824B1A40);
PPC_FUNC_IMPL(__imp__sub_824B1A40) {
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
	// bl 0x824db648
	ctx.lr = 0x824B1A60;
	sub_824DB648(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1a78
	if (cr6.eq) goto loc_824B1A78;
	// bl 0x82130588
	ctx.lr = 0x824B1A74;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B1A78:
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

__attribute__((alias("__imp__sub_824B1A90"))) PPC_WEAK_FUNC(sub_824B1A90);
PPC_FUNC_IMPL(__imp__sub_824B1A90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// bl 0x824b0100
	ctx.lr = 0x824B1AA8;
	sub_824B0100(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// addi r10,r11,7100
	ctx.r10.s64 = r11.s64 + 7100;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824b19b0
	ctx.lr = 0x824B1ABC;
	sub_824B19B0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r6,384
	ctx.r6.s64 = 384;
	// li r5,400
	ctx.r5.s64 = 400;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f12,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stb r11,372(r31)
	PPC_STORE_U8(r31.u32 + 372, r11.u8);
	// stfs f0,332(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 332, temp.u32);
	// stb r3,375(r31)
	PPC_STORE_U8(r31.u32 + 375, ctx.r3.u8);
	// stfs f0,324(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// stw r11,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r11.u32);
	// stfs f0,336(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stb r11,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r11.u8);
	// stfs f0,340(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stb r11,374(r31)
	PPC_STORE_U8(r31.u32 + 374, r11.u8);
	// stfs f12,328(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 328, temp.u32);
	// stb r11,376(r31)
	PPC_STORE_U8(r31.u32 + 376, r11.u8);
	// stfs f13,348(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 348, temp.u32);
	// stb r11,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r11.u8);
	// stfs f13,352(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// stb r11,377(r31)
	PPC_STORE_U8(r31.u32 + 377, r11.u8);
	// stfs f13,356(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// stb r11,268(r31)
	PPC_STORE_U8(r31.u32 + 268, r11.u8);
	// stfs f13,360(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 360, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,312(r31)
	PPC_STORE_U32(r31.u32 + 312, r31.u32);
	// lfs f0,31016(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stw r11,368(r31)
	PPC_STORE_U32(r31.u32 + 368, r11.u32);
	// stfs f0,260(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B1B68"))) PPC_WEAK_FUNC(sub_824B1B68);
PPC_FUNC_IMPL(__imp__sub_824B1B68) {
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
	ctx.lr = 0x824B1B70;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// bl 0x824dadc0
	ctx.lr = 0x824B1B88;
	sub_824DADC0(ctx, base);
	// addi r29,r31,248
	r29.s64 = r31.s64 + 248;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82477b78
	ctx.lr = 0x824B1B98;
	sub_82477B78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1bb0
	if (cr6.eq) goto loc_824B1BB0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2a58
	ctx.lr = 0x824B1BB0;
	sub_821D2A58(ctx, base);
loc_824B1BB0:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lhz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 308);
	// li r30,0
	r30.s64 = 0;
	// lwz r27,20796(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 20796);
	// cmpw cr6,r10,r27
	cr6.compare<int32_t>(ctx.r10.s32, r27.s32, xer);
	// ble cr6,0x824b1c00
	if (!cr6.gt) goto loc_824B1C00;
	// lhz r11,310(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 310);
	// addi r28,r31,304
	r28.s64 = r31.s64 + 304;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b1bfc
	if (!cr6.eq) goto loc_824B1BFC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r27.u16);
	// beq cr6,0x824b1bf4
	if (cr6.eq) goto loc_824B1BF4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b1900
	ctx.lr = 0x824B1BF0;
	sub_824B1900(ctx, base);
	// b 0x824b1bf8
	goto loc_824B1BF8;
loc_824B1BF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824B1BF8:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_824B1BFC:
	// sth r27,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r27.u16);
loc_824B1C00:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,31924(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31924);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x824b1c50
	if (!cr6.lt) goto loc_824B1C50;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// stb r30,374(r31)
	PPC_STORE_U8(r31.u32 + 374, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r11.u8);
	// stb r11,375(r31)
	PPC_STORE_U8(r31.u32 + 375, r11.u8);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824B1C38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14192(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x824b1c50
	if (!cr6.gt) goto loc_824B1C50;
	// stb r30,373(r31)
	PPC_STORE_U8(r31.u32 + 373, r30.u8);
	// stb r30,375(r31)
	PPC_STORE_U8(r31.u32 + 375, r30.u8);
loc_824B1C50:
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b1c90
	if (cr6.eq) goto loc_824B1C90;
	// bl 0x8247bd10
	ctx.lr = 0x824B1C60;
	sub_8247BD10(ctx, base);
	// lhz r11,308(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1c90
	if (cr6.eq) goto loc_824B1C90;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_824B1C70:
	// lwz r11,304(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x824dbb40
	ctx.lr = 0x824B1C7C;
	sub_824DBB40(ctx, base);
	// lhz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 308);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x824b1c70
	if (cr6.lt) goto loc_824B1C70;
loc_824B1C90:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bne cr6,0x824b1ccc
	if (!cr6.eq) goto loc_824B1CCC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B1CCC;
	sub_82496790(ctx, base);
loc_824B1CCC:
	// lhz r11,196(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b1cf8
	if (!cr6.eq) goto loc_824B1CF8;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r31,168
	ctx.r3.s64 = r31.s64 + 168;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B1CF8;
	sub_82496790(ctx, base);
loc_824B1CF8:
	// lhz r11,236(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b1d24
	if (!cr6.eq) goto loc_824B1D24;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B1D24;
	sub_82496790(ctx, base);
loc_824B1D24:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B1D30"))) PPC_WEAK_FUNC(sub_824B1D30);
PPC_FUNC_IMPL(__imp__sub_824B1D30) {
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
	// li r3,416
	ctx.r3.s64 = 416;
	// bl 0x82130528
	ctx.lr = 0x824B1D44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b1d64
	if (cr6.eq) goto loc_824B1D64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824b1a90
	ctx.lr = 0x824B1D54;
	sub_824B1A90(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B1D64:
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

__attribute__((alias("__imp__sub_824B1D78"))) PPC_WEAK_FUNC(sub_824B1D78);
PPC_FUNC_IMPL(__imp__sub_824B1D78) {
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
	ctx.lr = 0x824B1D80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addic. r29,r11,-1
	xer.ca = r11.u32 > 0;
	r29.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x824b1dd0
	if (cr0.lt) goto loc_824B1DD0;
	// rlwinm r31,r29,2,0,29
	r31.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
loc_824B1D9C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r28,r31,r11
	r28.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b1dbc
	if (cr6.eq) goto loc_824B1DBC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b1868
	ctx.lr = 0x824B1DB4;
	sub_824B1868(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x824B1DBC;
	sub_82130588(ctx, base);
loc_824B1DBC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r27,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r27.u32);
	// addi r31,r31,-4
	r31.s64 = r31.s64 + -4;
	// bge 0x824b1d9c
	if (!cr0.lt) goto loc_824B1D9C;
loc_824B1DD0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824B1DD8;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// lwz r31,36(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b1e0c
	if (cr6.eq) goto loc_824B1E0C;
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1e04
	if (cr6.eq) goto loc_824B1E04;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x824B1E04;
	sub_82130588(ctx, base);
loc_824B1E04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824B1E0C;
	sub_82130588(ctx, base);
loc_824B1E0C:
	// stw r27,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r27.u32);
	// lhz r11,14(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1e58
	if (cr6.eq) goto loc_824B1E58;
	// lwz r28,8(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824b1e50
	if (!cr6.gt) goto loc_824B1E50;
	// mr r31,r28
	r31.u64 = r28.u64;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_824B1E30:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1e44
	if (cr6.eq) goto loc_824B1E44;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824B1E44;
	sub_82130588(ctx, base);
loc_824B1E44:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x824b1e30
	if (!cr0.eq) goto loc_824B1E30;
loc_824B1E50:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x824B1E58;
	sub_82130588(ctx, base);
loc_824B1E58:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b1e6c
	if (cr6.eq) goto loc_824B1E6C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824B1E6C;
	sub_82130588(ctx, base);
loc_824B1E6C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B1E74"))) PPC_WEAK_FUNC(sub_824B1E74);
PPC_FUNC_IMPL(__imp__sub_824B1E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B1E78"))) PPC_WEAK_FUNC(sub_824B1E78);
PPC_FUNC_IMPL(__imp__sub_824B1E78) {
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
	ctx.lr = 0x824B1E80;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20880
	r31.s64 = r11.s64 + 20880;
	// lwz r11,20880(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b22b0
	if (!cr6.eq) goto loc_824B22B0;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824B1EA0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b1eb4
	if (cr6.eq) goto loc_824B1EB4;
	// bl 0x821d5408
	ctx.lr = 0x824B1EB0;
	sub_821D5408(ctx, base);
	// b 0x824b1eb8
	goto loc_824B1EB8;
loc_824B1EB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824B1EB8:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32168
	r11.s64 = -2108162048;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7252
	ctx.r7.s64 = ctx.r10.s64 + 7252;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,13856
	ctx.r9.s64 = r11.s64 + 13856;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,416
	ctx.r5.s64 = 416;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32181
	ctx.r8.s64 = -2109014016;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r4,r8,7472
	ctx.r4.s64 = ctx.r8.s64 + 7472;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r5,r10,19540
	ctx.r5.s64 = ctx.r10.s64 + 19540;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,19516
	ctx.r9.s64 = ctx.r3.s64 + 19516;
	// addi r4,r8,19588
	ctx.r4.s64 = ctx.r8.s64 + 19588;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,248
	ctx.r10.s64 = 248;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// li r11,344
	r11.s64 = 344;
	// addi r6,r3,19564
	ctx.r6.s64 = ctx.r3.s64 + 19564;
	// addi r5,r8,19612
	ctx.r5.s64 = ctx.r8.s64 + 19612;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r11,269
	r11.s64 = 269;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// li r9,268
	ctx.r9.s64 = 268;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,270
	ctx.r10.s64 = 270;
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,19660
	ctx.r4.s64 = ctx.r7.s64 + 19660;
	// addi r6,r3,19636
	ctx.r6.s64 = ctx.r3.s64 + 19636;
	// addi r5,r8,19684
	ctx.r5.s64 = ctx.r8.s64 + 19684;
	// li r11,332
	r11.s64 = 332;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// li r9,372
	ctx.r9.s64 = 372;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,324
	ctx.r10.s64 = 324;
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,19732
	ctx.r4.s64 = ctx.r7.s64 + 19732;
	// addi r6,r3,19708
	ctx.r6.s64 = ctx.r3.s64 + 19708;
	// addi r5,r8,19756
	ctx.r5.s64 = ctx.r8.s64 + 19756;
	// li r11,340
	r11.s64 = 340;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// li r9,336
	ctx.r9.s64 = 336;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,328
	ctx.r10.s64 = 328;
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,19816
	ctx.r4.s64 = ctx.r7.s64 + 19816;
	// addi r6,r3,19780
	ctx.r6.s64 = ctx.r3.s64 + 19780;
	// addi r5,r8,19840
	ctx.r5.s64 = ctx.r8.s64 + 19840;
	// li r11,373
	r11.s64 = 373;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// li r9,384
	ctx.r9.s64 = 384;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,374
	ctx.r10.s64 = 374;
	// addi r4,r7,19864
	ctx.r4.s64 = ctx.r7.s64 + 19864;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r11,375
	r11.s64 = 375;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r8,r3,19888
	ctx.r8.s64 = ctx.r3.s64 + 19888;
	// addi r7,r9,19912
	ctx.r7.s64 = ctx.r9.s64 + 19912;
	// lis r6,-32128
	ctx.r6.s64 = -2105540608;
	// addi r30,r10,20140
	r30.s64 = ctx.r10.s64 + 20140;
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// li r10,376
	ctx.r10.s64 = 376;
	// addi r3,r6,19936
	ctx.r3.s64 = ctx.r6.s64 + 19936;
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r9,273
	ctx.r9.s64 = 273;
	// addi r6,r5,19960
	ctx.r6.s64 = ctx.r5.s64 + 19960;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// addi r5,r4,19984
	ctx.r5.s64 = ctx.r4.s64 + 19984;
	// li r8,274
	ctx.r8.s64 = 274;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r10,275
	ctx.r10.s64 = 275;
	// addi r3,r7,20032
	ctx.r3.s64 = ctx.r7.s64 + 20032;
	// li r9,377
	ctx.r9.s64 = 377;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// addi r4,r4,20008
	ctx.r4.s64 = ctx.r4.s64 + 20008;
	// lis r28,-32128
	r28.s64 = -2105540608;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r8,348
	ctx.r8.s64 = 348;
	// li r10,352
	ctx.r10.s64 = 352;
	// addi r7,r28,20056
	ctx.r7.s64 = r28.s64 + 20056;
	// lis r6,-32128
	ctx.r6.s64 = -2105540608;
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r9,356
	ctx.r9.s64 = 356;
	// addi r4,r6,20080
	ctx.r4.s64 = ctx.r6.s64 + 20080;
	// addi r3,r5,20104
	ctx.r3.s64 = ctx.r5.s64 + 20104;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// li r8,360
	ctx.r8.s64 = 360;
	// li r10,400
	ctx.r10.s64 = 400;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// bne cr6,0x824b20c4
	if (!cr6.eq) goto loc_824B20C4;
	// bl 0x824970b0
	ctx.lr = 0x824B20C0;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B20C4:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,20176
	r28.s64 = ctx.r10.s64 + 20176;
	// li r10,48
	ctx.r10.s64 = 48;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b20e8
	if (!cr6.eq) goto loc_824B20E8;
	// bl 0x824970b0
	ctx.lr = 0x824B20E4;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B20E8:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,20212
	r30.s64 = ctx.r10.s64 + 20212;
	// li r10,88
	ctx.r10.s64 = 88;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b210c
	if (!cr6.eq) goto loc_824B210C;
	// bl 0x824970b0
	ctx.lr = 0x824B2108;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B210C:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,20248
	r28.s64 = ctx.r10.s64 + 20248;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b2130
	if (!cr6.eq) goto loc_824B2130;
	// bl 0x824970b0
	ctx.lr = 0x824B212C;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B2130:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,20284
	r30.s64 = ctx.r10.s64 + 20284;
	// li r10,168
	ctx.r10.s64 = 168;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b2154
	if (!cr6.eq) goto loc_824B2154;
	// bl 0x824970b0
	ctx.lr = 0x824B2150;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B2154:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r10,20320
	r28.s64 = ctx.r10.s64 + 20320;
	// li r10,208
	ctx.r10.s64 = 208;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b2178
	if (!cr6.eq) goto loc_824B2178;
	// bl 0x824970b0
	ctx.lr = 0x824B2174;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20464);
loc_824B2178:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// addi r30,r10,20356
	r30.s64 = ctx.r10.s64 + 20356;
	// li r10,288
	ctx.r10.s64 = 288;
	// lwz r11,29996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29996);
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b21a4
	if (!cr6.eq) goto loc_824B21A4;
	// bl 0x824db980
	ctx.lr = 0x824B21A0;
	sub_824DB980(ctx, base);
	// lwz r11,29996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 29996);
loc_824B21A4:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lis r28,-32115
	r28.s64 = -2104688640;
	// addi r29,r10,20392
	r29.s64 = ctx.r10.s64 + 20392;
	// li r10,256
	ctx.r10.s64 = 256;
	// lwz r11,19724(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 19724);
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b21d0
	if (!cr6.eq) goto loc_824B21D0;
	// bl 0x8247ce68
	ctx.lr = 0x824B21CC;
	sub_8247CE68(ctx, base);
	// lwz r11,19724(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 19724);
loc_824B21D0:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lwz r4,20876(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20876);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824b21ec
	if (!cr6.eq) goto loc_824B21EC;
	// bl 0x824b03e8
	ctx.lr = 0x824B21E8;
	sub_824B03E8(ctx, base);
	// lwz r4,20876(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20876);
loc_824B21EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824B21F8;
	sub_821D4458(ctx, base);
	// lwz r11,20876(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20876);
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
	ctx.lr = 0x824B2214;
	sub_82130528(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r3.u32);
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// sth r11,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r11.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,60(r30)
	PPC_STORE_U8(r30.u32 + 60, r11.u8);
	// addi r9,r10,1464
	ctx.r9.s64 = ctx.r10.s64 + 1464;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x824B2238;
	sub_82130000(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r8,-13244
	ctx.r4.s64 = ctx.r8.s64 + -13244;
	// bl 0x82197d98
	ctx.lr = 0x824B2254;
	sub_82197D98(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82196758
	ctx.lr = 0x824B225C;
	sub_82196758(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824B226C;
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
	ctx.lr = 0x824B2288;
	sub_821D41D0(ctx, base);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,20432
	ctx.r4.s64 = ctx.r5.s64 + 20432;
	// bl 0x821d4b00
	ctx.lr = 0x824B2298;
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
	ctx.lr = 0x824B22B0;
	sub_821C0548(ctx, base);
loc_824B22B0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B22B8"))) PPC_WEAK_FUNC(sub_824B22B8);
PPC_FUNC_IMPL(__imp__sub_824B22B8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,7100
	ctx.r10.s64 = r11.s64 + 7100;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824b07e8
	ctx.lr = 0x824B22E4;
	sub_824B07E8(ctx, base);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82130588
	ctx.lr = 0x824B22EC;
	sub_82130588(ctx, base);
	// lwz r30,256(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b2308
	if (cr6.eq) goto loc_824B2308;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824b1d78
	ctx.lr = 0x824B2300;
	sub_824B1D78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x824B2308;
	sub_82130588(ctx, base);
loc_824B2308:
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// bl 0x824db648
	ctx.lr = 0x824B2318;
	sub_824DB648(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824b0198
	ctx.lr = 0x824B2320;
	sub_824B0198(ctx, base);
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

__attribute__((alias("__imp__sub_824B2338"))) PPC_WEAK_FUNC(sub_824B2338);
PPC_FUNC_IMPL(__imp__sub_824B2338) {
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
	// bl 0x824b22b8
	ctx.lr = 0x824B2358;
	sub_824B22B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b2370
	if (cr6.eq) goto loc_824B2370;
	// bl 0x82130588
	ctx.lr = 0x824B236C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B2370:
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

__attribute__((alias("__imp__sub_824B2388"))) PPC_WEAK_FUNC(sub_824B2388);
PPC_FUNC_IMPL(__imp__sub_824B2388) {
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
	// addi r9,r11,7804
	ctx.r9.s64 = r11.s64 + 7804;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824b23bc
	if (cr6.eq) goto loc_824B23BC;
	// bl 0x82130588
	ctx.lr = 0x824B23B8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B23BC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B23D0"))) PPC_WEAK_FUNC(sub_824B23D0);
PPC_FUNC_IMPL(__imp__sub_824B23D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// addi r10,r4,64
	ctx.r10.s64 = ctx.r4.s64 + 64;
	// addi r9,r4,80
	ctx.r9.s64 = ctx.r4.s64 + 80;
	// addi r8,r4,48
	ctx.r8.s64 = ctx.r4.s64 + 48;
	// addi r5,r4,144
	ctx.r5.s64 = ctx.r4.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v56,v57
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v52,v53,v54
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r5
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v49,v50,v51
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v49,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B2458"))) PPC_WEAK_FUNC(sub_824B2458);
PPC_FUNC_IMPL(__imp__sub_824B2458) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B245C"))) PPC_WEAK_FUNC(sub_824B245C);
PPC_FUNC_IMPL(__imp__sub_824B245C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2460"))) PPC_WEAK_FUNC(sub_824B2460);
PPC_FUNC_IMPL(__imp__sub_824B2460) {
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
	// addi r10,r11,7812
	ctx.r10.s64 = r11.s64 + 7812;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// bl 0x82495cf0
	ctx.lr = 0x824B2498;
	sub_82495CF0(ctx, base);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x82495cf0
	ctx.lr = 0x824B24A0;
	sub_82495CF0(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x82495cf0
	ctx.lr = 0x824B24A8;
	sub_82495CF0(ctx, base);
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x82495cf0
	ctx.lr = 0x824B24B0;
	sub_82495CF0(ctx, base);
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x82495cf0
	ctx.lr = 0x824B24B8;
	sub_82495CF0(ctx, base);
	// addi r3,r31,220
	ctx.r3.s64 = r31.s64 + 220;
	// bl 0x82495cf0
	ctx.lr = 0x824B24C0;
	sub_82495CF0(ctx, base);
	// addi r3,r31,260
	ctx.r3.s64 = r31.s64 + 260;
	// bl 0x82495cf0
	ctx.lr = 0x824B24C8;
	sub_82495CF0(ctx, base);
	// addi r3,r31,300
	ctx.r3.s64 = r31.s64 + 300;
	// bl 0x82495cf0
	ctx.lr = 0x824B24D0;
	sub_82495CF0(ctx, base);
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// bl 0x82495cf0
	ctx.lr = 0x824B24D8;
	sub_82495CF0(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x82495cf0
	ctx.lr = 0x824B24E0;
	sub_82495CF0(ctx, base);
	// stw r30,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r30.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b2504
	if (cr6.eq) goto loc_824B2504;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B2504:
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b2528
	if (cr6.eq) goto loc_824B2528;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B2528:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
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

__attribute__((alias("__imp__sub_824B2548"))) PPC_WEAK_FUNC(sub_824B2548);
PPC_FUNC_IMPL(__imp__sub_824B2548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20888(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20888);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2554"))) PPC_WEAK_FUNC(sub_824B2554);
PPC_FUNC_IMPL(__imp__sub_824B2554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2558"))) PPC_WEAK_FUNC(sub_824B2558);
PPC_FUNC_IMPL(__imp__sub_824B2558) {
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
	// addi r3,r31,420
	ctx.r3.s64 = r31.s64 + 420;
	// bl 0x821d2aa0
	ctx.lr = 0x824B2574;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x82495d58
	ctx.lr = 0x824B257C;
	sub_82495D58(ctx, base);
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// bl 0x82495d58
	ctx.lr = 0x824B2584;
	sub_82495D58(ctx, base);
	// addi r3,r31,300
	ctx.r3.s64 = r31.s64 + 300;
	// bl 0x82495d58
	ctx.lr = 0x824B258C;
	sub_82495D58(ctx, base);
	// addi r3,r31,260
	ctx.r3.s64 = r31.s64 + 260;
	// bl 0x82495d58
	ctx.lr = 0x824B2594;
	sub_82495D58(ctx, base);
	// addi r3,r31,220
	ctx.r3.s64 = r31.s64 + 220;
	// bl 0x82495d58
	ctx.lr = 0x824B259C;
	sub_82495D58(ctx, base);
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x82495d58
	ctx.lr = 0x824B25A4;
	sub_82495D58(ctx, base);
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x82495d58
	ctx.lr = 0x824B25AC;
	sub_82495D58(ctx, base);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x82495d58
	ctx.lr = 0x824B25B4;
	sub_82495D58(ctx, base);
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x82495d58
	ctx.lr = 0x824B25BC;
	sub_82495D58(ctx, base);
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82495d58
	ctx.lr = 0x824B25C4;
	sub_82495D58(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b25e4
	if (cr6.eq) goto loc_824B25E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B25E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B25E4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b2604
	if (cr6.eq) goto loc_824B2604;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B2604:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,7804
	ctx.r10.s64 = r11.s64 + 7804;
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

__attribute__((alias("__imp__sub_824B2624"))) PPC_WEAK_FUNC(sub_824B2624);
PPC_FUNC_IMPL(__imp__sub_824B2624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2628"))) PPC_WEAK_FUNC(sub_824B2628);
PPC_FUNC_IMPL(__imp__sub_824B2628) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,7812
	ctx.r10.s64 = r11.s64 + 7812;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824c5d30
	ctx.lr = 0x824B2658;
	sub_824C5D30(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x824c5d30
	ctx.lr = 0x824B2664;
	sub_824C5D30(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82496728
	ctx.lr = 0x824B2670;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// bl 0x82496728
	ctx.lr = 0x824B267C;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bl 0x82496728
	ctx.lr = 0x824B2688;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,140
	ctx.r3.s64 = r31.s64 + 140;
	// bl 0x82496728
	ctx.lr = 0x824B2694;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,180
	ctx.r3.s64 = r31.s64 + 180;
	// bl 0x82496728
	ctx.lr = 0x824B26A0;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,220
	ctx.r3.s64 = r31.s64 + 220;
	// bl 0x82496728
	ctx.lr = 0x824B26AC;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,260
	ctx.r3.s64 = r31.s64 + 260;
	// bl 0x82496728
	ctx.lr = 0x824B26B8;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,300
	ctx.r3.s64 = r31.s64 + 300;
	// bl 0x82496728
	ctx.lr = 0x824B26C4;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// bl 0x82496728
	ctx.lr = 0x824B26D0;
	sub_82496728(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,380
	ctx.r3.s64 = r31.s64 + 380;
	// bl 0x82496728
	ctx.lr = 0x824B26DC;
	sub_82496728(ctx, base);
	// addi r3,r31,420
	ctx.r3.s64 = r31.s64 + 420;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821d2aa8
	ctx.lr = 0x824B26E8;
	sub_821D2AA8(ctx, base);
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

__attribute__((alias("__imp__sub_824B2704"))) PPC_WEAK_FUNC(sub_824B2704);
PPC_FUNC_IMPL(__imp__sub_824B2704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2708"))) PPC_WEAK_FUNC(sub_824B2708);
PPC_FUNC_IMPL(__imp__sub_824B2708) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,452(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2710"))) PPC_WEAK_FUNC(sub_824B2710);
PPC_FUNC_IMPL(__imp__sub_824B2710) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,496(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 496);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2718"))) PPC_WEAK_FUNC(sub_824B2718);
PPC_FUNC_IMPL(__imp__sub_824B2718) {
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
	// addi r30,r3,496
	r30.s64 = ctx.r3.s64 + 496;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82477b78
	ctx.lr = 0x824B273C;
	sub_82477B78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b2754
	if (cr6.eq) goto loc_824B2754;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2a58
	ctx.lr = 0x824B2754;
	sub_821D2A58(ctx, base);
loc_824B2754:
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

__attribute__((alias("__imp__sub_824B276C"))) PPC_WEAK_FUNC(sub_824B276C);
PPC_FUNC_IMPL(__imp__sub_824B276C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2770"))) PPC_WEAK_FUNC(sub_824B2770);
PPC_FUNC_IMPL(__imp__sub_824B2770) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,508(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b2788
	if (cr6.eq) goto loc_824B2788;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_824B2788:
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2790"))) PPC_WEAK_FUNC(sub_824B2790);
PPC_FUNC_IMPL(__imp__sub_824B2790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20884(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20884);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B279C"))) PPC_WEAK_FUNC(sub_824B279C);
PPC_FUNC_IMPL(__imp__sub_824B279C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B27A0"))) PPC_WEAK_FUNC(sub_824B27A0);
PPC_FUNC_IMPL(__imp__sub_824B27A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x824c5c40
	ctx.lr = 0x824B27CC;
	sub_824C5C40(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b27f0
	if (cr6.eq) goto loc_824B27F0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B27F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B27F0:
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x824c5c40
	ctx.lr = 0x824B2800;
	sub_824C5C40(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b2824
	if (cr6.eq) goto loc_824B2824;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B2824:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,412
	ctx.r3.s64 = r31.s64 + 412;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B2850;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B2860;
	sub_82496790(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B2888;
	sub_82496790(ctx, base);
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B28A8;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,172
	ctx.r3.s64 = r31.s64 + 172;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B28B8;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B28C8;
	sub_82496790(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r3,r31,252
	ctx.r3.s64 = r31.s64 + 252;
	// lfs f0,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B28F0;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,292
	ctx.r3.s64 = r31.s64 + 292;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B2900;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,332
	ctx.r3.s64 = r31.s64 + 332;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B2910;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,372
	ctx.r3.s64 = r31.s64 + 372;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B2920;
	sub_82496790(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824B2934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x824B2948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_824B2968"))) PPC_WEAK_FUNC(sub_824B2968);
PPC_FUNC_IMPL(__imp__sub_824B2968) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B2970;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,500(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12428(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12428);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x824b29dc
	if (!cr6.lt) goto loc_824B29DC;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r29,92
	ctx.r3.s64 = r29.s64 + 92;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x824B29CC;
	sub_82496790(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,412
	ctx.r3.s64 = r29.s64 + 412;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x824B29DC;
	sub_82496790(ctx, base);
loc_824B29DC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,500(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,10012(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 10012);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x824b2a70
	if (!cr6.lt) goto loc_824B2A70;
	// lhz r11,80(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 80);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b2a70
	if (cr6.eq) goto loc_824B2A70;
	// addi r30,r29,52
	r30.s64 = r29.s64 + 52;
	// li r28,16
	r28.s64 = 16;
loc_824B2A08:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82495b00
	ctx.lr = 0x824B2A14;
	sub_82495B00(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82495b00
	ctx.lr = 0x824B2A30;
	sub_82495B00(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f30,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f30.f64 = double(temp.f32);
	// bl 0x82495b00
	ctx.lr = 0x824B2A44;
	sub_82495B00(ctx, base);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stfs f30,0(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f31,28(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lhz r8,80(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 80);
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x824b2a08
	if (cr6.lt) goto loc_824B2A08;
loc_824B2A70:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B2A80"))) PPC_WEAK_FUNC(sub_824B2A80);
PPC_FUNC_IMPL(__imp__sub_824B2A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r8,r11,5
	ctx.r8.s64 = r11.s64 + 5;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r10.u32);
	// stwx r10,r6,r4
	PPC_STORE_U32(ctx.r6.u32 + ctx.r4.u32, ctx.r10.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B2AC4"))) PPC_WEAK_FUNC(sub_824B2AC4);
PPC_FUNC_IMPL(__imp__sub_824B2AC4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2AC8"))) PPC_WEAK_FUNC(sub_824B2AC8);
PPC_FUNC_IMPL(__imp__sub_824B2AC8) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B2AD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f13,500(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f0,244(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 244);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f11,244(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 244);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,500(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 500);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f9,4(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lwz r8,36(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,284(r8)
	PPC_STORE_U32(ctx.r8.u32 + 284, r11.u32);
	// lwz r7,44(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r11,284(r7)
	PPC_STORE_U32(ctx.r7.u32 + 284, r11.u32);
	// lwz r5,136(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// lwz r3,256(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b2b88
	if (cr6.eq) goto loc_824B2B88;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f0,436(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 436);
	f0.f64 = double(temp.f32);
	// stw r6,284(r11)
	PPC_STORE_U32(r11.u32 + 284, ctx.r6.u32);
	// stfs f0,256(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 256, temp.u32);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f13,440(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,260(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// lfs f12,444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// stw r6,284(r10)
	PPC_STORE_U32(ctx.r10.u32 + 284, ctx.r6.u32);
	// stfs f12,264(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
	// lfs f11,448(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,268(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 268, temp.u32);
	// lfs f10,452(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 452);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,272(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 272, temp.u32);
	// lfs f9,436(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 436);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,256(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 256, temp.u32);
	// lfs f8,440(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 440);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,260(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 260, temp.u32);
	// lfs f7,444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 444);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,264(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 264, temp.u32);
	// lfs f6,448(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 448);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,268(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 268, temp.u32);
	// lfs f5,452(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 452);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,272(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 272, temp.u32);
loc_824B2B88:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r29,r4,176
	r29.s64 = ctx.r4.s64 + 176;
	// lfs f1,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f1,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824B2BC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x824B2BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r28,r30,144
	r28.s64 = r30.s64 + 144;
	// li r11,80
	r11.s64 = 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824B2C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B2C30"))) PPC_WEAK_FUNC(sub_824B2C30);
PPC_FUNC_IMPL(__imp__sub_824B2C30) {
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
	ctx.lr = 0x824B2C38;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824b2ca4
	if (cr6.eq) goto loc_824B2CA4;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824b2ac8
	ctx.lr = 0x824B2C6C;
	sub_824B2AC8(ctx, base);
	// lfs f0,488(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 488);
	f0.f64 = double(temp.f32);
	// lfs f13,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	ctx.f11.f64 = double(temp.f32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f1,f10,f31
	ctx.f1.f64 = double(float(ctx.f10.f64 * f31.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B2CA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B2CB0"))) PPC_WEAK_FUNC(sub_824B2CB0);
PPC_FUNC_IMPL(__imp__sub_824B2CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r10,r11,5
	ctx.r10.s64 = r11.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r5
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B2CF0"))) PPC_WEAK_FUNC(sub_824B2CF0);
PPC_FUNC_IMPL(__imp__sub_824B2CF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B2CF4"))) PPC_WEAK_FUNC(sub_824B2CF4);
PPC_FUNC_IMPL(__imp__sub_824B2CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2CF8"))) PPC_WEAK_FUNC(sub_824B2CF8);
PPC_FUNC_IMPL(__imp__sub_824B2CF8) {
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
	// li r3,424
	ctx.r3.s64 = 424;
	// bl 0x82130528
	ctx.lr = 0x824B2D0C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b2d28
	if (cr6.eq) goto loc_824B2D28;
	// bl 0x824b2460
	ctx.lr = 0x824B2D18;
	sub_824B2460(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B2D28:
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

__attribute__((alias("__imp__sub_824B2D3C"))) PPC_WEAK_FUNC(sub_824B2D3C);
PPC_FUNC_IMPL(__imp__sub_824B2D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2D40"))) PPC_WEAK_FUNC(sub_824B2D40);
PPC_FUNC_IMPL(__imp__sub_824B2D40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lhz r9,280(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 280);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b2d8c
	if (!cr6.gt) goto loc_824B2D8C;
	// lwz r31,276(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824B2D70:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b2e24
	if (!cr6.lt) goto loc_824B2E24;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b2d70
	if (cr6.lt) goto loc_824B2D70;
loc_824B2D8C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,276(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B2DA0:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b2e10
	if (cr6.eq) goto loc_824B2E10;
	// li r6,4
	ctx.r6.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B2E10;
	sub_824AFF80(ctx, base);
loc_824B2E10:
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
loc_824B2E24:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824b2da0
	goto loc_824B2DA0;
}

__attribute__((alias("__imp__sub_824B2E38"))) PPC_WEAK_FUNC(sub_824B2E38);
PPC_FUNC_IMPL(__imp__sub_824B2E38) {
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
	// bl 0x824b2558
	ctx.lr = 0x824B2E58;
	sub_824B2558(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b2e70
	if (cr6.eq) goto loc_824B2E70;
	// bl 0x82130588
	ctx.lr = 0x824B2E6C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B2E70:
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

__attribute__((alias("__imp__sub_824B2E88"))) PPC_WEAK_FUNC(sub_824B2E88);
PPC_FUNC_IMPL(__imp__sub_824B2E88) {
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
	// addi r10,r11,7828
	ctx.r10.s64 = r11.s64 + 7828;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,504(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 504);
	// bl 0x82130588
	ctx.lr = 0x824B2EB8;
	sub_82130588(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x821d2aa0
	ctx.lr = 0x824B2EC0;
	sub_821D2AA0(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x824b2558
	ctx.lr = 0x824B2EC8;
	sub_824B2558(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-25308
	ctx.r8.s64 = ctx.r9.s64 + -25308;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x821d2810
	ctx.lr = 0x824B2EDC;
	sub_821D2810(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824b2ef4
	if (cr6.eq) goto loc_824B2EF4;
	// bl 0x82130588
	ctx.lr = 0x824B2EF0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B2EF4:
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

__attribute__((alias("__imp__sub_824B2F0C"))) PPC_WEAK_FUNC(sub_824B2F0C);
PPC_FUNC_IMPL(__imp__sub_824B2F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2F10"))) PPC_WEAK_FUNC(sub_824B2F10);
PPC_FUNC_IMPL(__imp__sub_824B2F10) {
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
	ctx.lr = 0x824B2F18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-32120
	ctx.r4.s64 = ctx.r10.s64 + -32120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x824B2F3C;
	sub_821CA540(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,5816
	ctx.r4.s64 = ctx.r9.s64 + 5816;
	// bl 0x821ca540
	ctx.lr = 0x824B2F4C;
	sub_821CA540(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r28,2828(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2828);
	// beq cr6,0x824b2f78
	if (cr6.eq) goto loc_824B2F78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x824b2f80
	goto loc_824B2F80;
loc_824B2F78:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,20884(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 20884);
loc_824B2F80:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r11,5792
	ctx.r5.s64 = r11.s64 + 5792;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c04b0
	ctx.lr = 0x824B2F9C;
	sub_821C04B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B2FA8;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B2FB0;
	sub_821C9A90(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b2fc8
	if (!cr6.eq) goto loc_824B2FC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_824B2FC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B2FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B2FEC"))) PPC_WEAK_FUNC(sub_824B2FEC);
PPC_FUNC_IMPL(__imp__sub_824B2FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B2FF0"))) PPC_WEAK_FUNC(sub_824B2FF0);
PPC_FUNC_IMPL(__imp__sub_824B2FF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lhz r9,320(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 320);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b303c
	if (!cr6.gt) goto loc_824B303C;
	// lwz r31,316(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824B3020:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b30d4
	if (!cr6.lt) goto loc_824B30D4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3020
	if (cr6.lt) goto loc_824B3020;
loc_824B303C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,316(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 316);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B3050:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b30c0
	if (cr6.eq) goto loc_824B30C0;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B30C0;
	sub_824AFF80(ctx, base);
loc_824B30C0:
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
loc_824B30D4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824b3050
	goto loc_824B3050;
}

__attribute__((alias("__imp__sub_824B30E8"))) PPC_WEAK_FUNC(sub_824B30E8);
PPC_FUNC_IMPL(__imp__sub_824B30E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lhz r9,360(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 360);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b3134
	if (!cr6.gt) goto loc_824B3134;
	// lwz r31,356(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 356);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824B3118:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b31cc
	if (!cr6.lt) goto loc_824B31CC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3118
	if (cr6.lt) goto loc_824B3118;
loc_824B3134:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,356(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 356);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B3148:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b31b8
	if (cr6.eq) goto loc_824B31B8;
	// li r6,6
	ctx.r6.s64 = 6;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B31B8;
	sub_824AFF80(ctx, base);
loc_824B31B8:
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
loc_824B31CC:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824b3148
	goto loc_824B3148;
}

__attribute__((alias("__imp__sub_824B31E0"))) PPC_WEAK_FUNC(sub_824B31E0);
PPC_FUNC_IMPL(__imp__sub_824B31E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lhz r9,400(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 400);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b322c
	if (!cr6.gt) goto loc_824B322C;
	// lwz r31,396(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
loc_824B3210:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b32c4
	if (!cr6.lt) goto loc_824B32C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3210
	if (cr6.lt) goto loc_824B3210;
loc_824B322C:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,396(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 396);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B3240:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b32b0
	if (cr6.eq) goto loc_824B32B0;
	// li r6,7
	ctx.r6.s64 = 7;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B32B0;
	sub_824AFF80(ctx, base);
loc_824B32B0:
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
loc_824B32C4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// b 0x824b3240
	goto loc_824B3240;
}

__attribute__((alias("__imp__sub_824B32D8"))) PPC_WEAK_FUNC(sub_824B32D8);
PPC_FUNC_IMPL(__imp__sub_824B32D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91e0
	ctx.lr = 0x824B32E0;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x824B32E8;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f29,f2
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f2.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// fmadds f27,f29,f31,f1
	f27.f64 = double(float(f29.f64 * f31.f64 + ctx.f1.f64));
	// beq cr6,0x824b38c0
	if (cr6.eq) goto loc_824B38C0;
	// addi r31,r6,16
	r31.s64 = ctx.r6.s64 + 16;
	// addi r24,r6,176
	r24.s64 = ctx.r6.s64 + 176;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824b38c0
	if (cr6.eq) goto loc_824B38C0;
	// lhz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 200);
	// lfs f28,128(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	f28.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b3374
	if (!cr6.gt) goto loc_824B3374;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_824B3358:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x824b38e8
	if (!cr6.lt) goto loc_824B38E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3358
	if (cr6.lt) goto loc_824B3358;
loc_824B3374:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,196(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B3388:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,116(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,120(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b3408
	if (cr6.eq) goto loc_824B3408;
	// addi r8,r23,436
	ctx.r8.s64 = r23.s64 + 436;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B3408;
	sub_824AFF80(ctx, base);
loc_824B3408:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// addi r29,r11,2176
	r29.s64 = r11.s64 + 2176;
	// ori r26,r9,64167
	r26.u64 = ctx.r9.u64 | 64167;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fsubs f30,f0,f31
	f30.f64 = double(float(f0.f64 - f31.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f31,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f31.f64 = double(temp.f32);
	// lfs f12,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f30,f29
	ctx.f10.f64 = double(float(f30.f64 * f29.f64));
	// stfs f10,80(r24)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r24.u32 + 80, temp.u32);
	// lwz r6,2176(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 2176);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mulld r10,r6,r26
	ctx.r10.s64 = ctx.r6.s64 * r26.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// fmuls f6,f11,f7
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// fmadds f5,f6,f31,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f13.f64));
	// fdivs f4,f0,f5
	ctx.f4.f64 = double(float(f0.f64 / ctx.f5.f64));
	// stfs f4,68(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// fcmpu cr6,f4,f12
	cr6.compare(ctx.f4.f64, ctx.f12.f64);
	// bge cr6,0x824b349c
	if (!cr6.lt) goto loc_824B349C;
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
loc_824B349C:
	// lwz r11,136(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 136);
	// lwz r10,256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x824b3504
	if (cr6.eq) goto loc_824B3504;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lfs f0,436(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 436);
	f0.f64 = double(temp.f32);
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stfs f0,256(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 256, temp.u32);
	// lfs f13,440(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,260(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// lfs f12,444(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,264(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
	// lfs f11,448(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,268(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 268, temp.u32);
	// lfs f10,452(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 452);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,272(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 272, temp.u32);
	// lfs f9,436(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 436);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,256(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 256, temp.u32);
	// lfs f8,440(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 440);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,260(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 260, temp.u32);
	// lfs f7,444(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 444);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,264(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 264, temp.u32);
	// lfs f6,448(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 448);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,268(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 268, temp.u32);
	// lfs f5,452(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 452);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,272(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 272, temp.u32);
loc_824B3504:
	// addi r31,r23,176
	r31.s64 = r23.s64 + 176;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// li r28,32
	r28.s64 = 32;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// li r27,16
	r27.s64 = 16;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r31,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824B3558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r11,r11,224
	r11.s64 = r11.s64 + 224;
	// addi r4,r5,2256
	ctx.r4.s64 = ctx.r5.s64 + 2256;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r0,r11
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B3590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// li r8,64
	ctx.r8.s64 = 64;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// addi r25,r24,16
	r25.s64 = r24.s64 + 16;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r6,224
	ctx.r6.s64 = 224;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// vaddfp128 v63,v59,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v127.f32)));
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r24,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,36(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r31,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,44(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lvx128 v56,r31,r28
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,20(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x824B360C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B3628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r10,240(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 240);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x824b365c
	if (!cr6.gt) goto loc_824B365C;
	// lwz r8,236(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// addi r9,r8,48
	ctx.r9.s64 = ctx.r8.s64 + 48;
loc_824B3640:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x824b38fc
	if (!cr6.lt) goto loc_824B38FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,48
	ctx.r9.s64 = ctx.r9.s64 + 48;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x824b3640
	if (cr6.lt) goto loc_824B3640;
loc_824B365C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,236(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 236);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B3670:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lhz r9,440(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 440);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 - f0.f64));
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824b3700
	if (!cr6.gt) goto loc_824B3700;
	// lwz r8,436(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 436);
	// addi r11,r8,48
	r11.s64 = ctx.r8.s64 + 48;
loc_824B36E4:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x824b3910
	if (!cr6.lt) goto loc_824B3910;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b36e4
	if (cr6.lt) goto loc_824B36E4;
loc_824B3700:
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,436(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 436);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B3714:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(f28.f64 - f0.f64));
	// lfs f10,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f5.f64 = double(temp.f32);
	// lfs f12,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,108(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,96(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,104(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b37b4
	if (cr6.eq) goto loc_824B37B4;
	// addi r31,r23,436
	r31.s64 = r23.s64 + 436;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B3798;
	sub_824AFF80(ctx, base);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B37B4;
	sub_824AFF80(ctx, base);
loc_824B37B4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// mulld r11,r11,r26
	r11.s64 = r11.s64 * r26.s64;
	// lfs f0,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f12,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f8,f30,f29
	ctx.f8.f64 = double(float(f30.f64 * f29.f64));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r26
	ctx.r10.s64 = ctx.r10.s64 * r26.s64;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f7,96(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// lfs f12,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f5,96(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// fmuls f1,f10,f3
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f3.f64));
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r8,416
	ctx.r8.s64 = 416;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r24,48
	r11.s64 = r24.s64 + 48;
	// fmuls f11,f9,f2
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f2.f64));
	// fmadds f10,f1,f31,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 * f31.f64 + f0.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v52,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// fmadds f9,f11,f31,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f13.f64));
	// lvx128 v0,r23,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v51,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmulfp128 v12,v53,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v50.f32)));
	// lvlx128 v49,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmaddfp v10,v0,v11,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v10,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,48(r24)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r24.u32 + 48, temp.u32);
	// lfs f7,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// stfs f7,56(r24)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r24.u32 + 56, temp.u32);
	// stfs f6,52(r24)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r24.u32 + 52, temp.u32);
	// lvx128 v9,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v9,v13,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v7,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B38C0:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x824B38E4;
	// b 0x823d9230
	return;
loc_824B38E8:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b3388
	goto loc_824B3388;
loc_824B38FC:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b3670
	goto loc_824B3670;
loc_824B3910:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b3714
	goto loc_824B3714;
}

__attribute__((alias("__imp__sub_824B3924"))) PPC_WEAK_FUNC(sub_824B3924);
PPC_FUNC_IMPL(__imp__sub_824B3924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B3928"))) PPC_WEAK_FUNC(sub_824B3928);
PPC_FUNC_IMPL(__imp__sub_824B3928) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B3930;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,144
	r28.s64 = 144;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,128(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stw r29,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r29.u32);
	// lwz r10,480(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 480);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x824b3a08
	if (!cr6.eq) goto loc_824B3A08;
	// stfs f31,228(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwz r10,256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x824b39ac
	if (cr6.eq) goto loc_824B39AC;
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lfs f0,436(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 436);
	f0.f64 = double(temp.f32);
	// stfs f0,256(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 256, temp.u32);
	// lfs f13,440(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,260(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// lfs f12,444(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,264(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
	// lfs f11,448(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,268(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 268, temp.u32);
	// lfs f10,452(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 452);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,272(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 272, temp.u32);
loc_824B39AC:
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lfs f1,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// addi r5,r30,176
	ctx.r5.s64 = r30.s64 + 176;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B39C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824B39E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,64
	ctx.r6.s64 = 64;
	// li r5,80
	ctx.r5.s64 = 80;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,260(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r3,r4,0,29,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r3,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r3.u32);
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B3A08:
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// ori r9,r11,2
	ctx.r9.u64 = r11.u64 | 2;
	// stw r9,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r9.u32);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r7,r8,0,30,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r7,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r7.u32);
	// lfs f0,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824b3a40
	if (cr6.gt) goto loc_824B3A40;
	// stfs f31,232(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// b 0x824b3a48
	goto loc_824B3A48;
loc_824B3A40:
	// fdivs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,232(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
loc_824B3A48:
	// lwz r11,592(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b3a64
	if (cr6.eq) goto loc_824B3A64;
	// lfs f0,576(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 576);
	f0.f64 = double(temp.f32);
	// fdivs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f13,232(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
loc_824B3A64:
	// lwz r11,592(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b3a7c
	if (cr6.eq) goto loc_824B3A7C;
	// lfs f0,580(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 580);
	f0.f64 = double(temp.f32);
	// stfs f0,240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
loc_824B3A7C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// li r9,176
	ctx.r9.s64 = 176;
	// lwz r11,19708(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19708);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r8,r11,5
	ctx.r8.s64 = r11.s64 + 5;
	// rlwinm r7,r8,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// stfsx f0,r7,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, temp.u32);
	// lwz r11,19708(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 19708);
	// lvx128 v63,r31,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,1(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r11,r6,5
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 5);
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stvx128 v63,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B3AC4"))) PPC_WEAK_FUNC(sub_824B3AC4);
PPC_FUNC_IMPL(__imp__sub_824B3AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B3AC8"))) PPC_WEAK_FUNC(sub_824B3AC8);
PPC_FUNC_IMPL(__imp__sub_824B3AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,260(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 260);
	// addi r11,r5,260
	r11.s64 = ctx.r5.s64 + 260;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwinm r9,r10,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stw r9,260(r5)
	PPC_STORE_U32(ctx.r5.u32 + 260, ctx.r9.u32);
	// rlwinm r7,r8,0,29,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r7,260(r5)
	PPC_STORE_U32(ctx.r5.u32 + 260, ctx.r7.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,612(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 612);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B3B14"))) PPC_WEAK_FUNC(sub_824B3B14);
PPC_FUNC_IMPL(__imp__sub_824B3B14) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B3B18"))) PPC_WEAK_FUNC(sub_824B3B18);
PPC_FUNC_IMPL(__imp__sub_824B3B18) {
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
	PPCRegister f0{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
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
	// bl 0x823d91d8
	ctx.lr = 0x824B3B20;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9cc
	ctx.lr = 0x824B3B28;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// fmr f29,f4
	f29.f64 = ctx.f4.f64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// li r11,1
	r11.s64 = 1;
	// lhz r9,80(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 80);
	// lfs f31,128(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b3b7c
	if (!cr6.gt) goto loc_824B3B7C;
	// lwz r8,76(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_824B3B60:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x824b3d88
	if (!cr6.lt) goto loc_824B3D88;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3b60
	if (cr6.lt) goto loc_824B3B60;
loc_824B3B7C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,76(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B3B90:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lhz r9,120(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 120);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,160(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fmadds f1,f10,f13,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f0,f8,f13,f7
	f0.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmadds f13,f6,f13,f5
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x824b3c20
	if (!cr6.gt) goto loc_824B3C20;
	// lwz r8,116(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// addi r11,r8,48
	r11.s64 = ctx.r8.s64 + 48;
loc_824B3C04:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x824b3d9c
	if (!cr6.lt) goto loc_824B3D9C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b3c04
	if (cr6.lt) goto loc_824B3C04;
loc_824B3C20:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,116(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_824B3C34:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// fsubs f9,f2,f25
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f2.f64 - f25.f64));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// fsubs f26,f3,f25
	f26.f64 = double(float(ctx.f3.f64 - f25.f64));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lwz r23,436(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 436);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fdivs f27,f9,f26
	f27.f64 = double(float(ctx.f9.f64 / f26.f64));
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f2,f13,f10,f8
	ctx.f2.f64 = double(float(ctx.f13.f64 * ctx.f10.f64 + ctx.f8.f64));
	// stfs f2,160(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fmadds f1,f7,f13,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f6.f64));
	// stfs f1,164(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f0,f5,f13,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f4.f64));
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fmadds f3,f12,f13,f11
	ctx.f3.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f3,172(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b3ce4
	if (cr6.eq) goto loc_824B3CE4;
	// addi r31,r22,436
	r31.s64 = r22.s64 + 436;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B3CC8;
	sub_824AFF80(ctx, base);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r6,9
	ctx.r6.s64 = 9;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B3CE4;
	sub_824AFF80(ctx, base);
loc_824B3CE4:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f11,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// addi r31,r11,2176
	r31.s64 = r11.s64 + 2176;
	// stfd f10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f10.u64);
	// ori r29,r10,64167
	r29.u64 = ctx.r10.u64 | 64167;
	// lwz r27,132(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lfs f0,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,2176(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 2176);
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r11,r8,r29
	r11.s64 = ctx.r8.s64 * r29.s64;
	// lfs f31,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f31.f64 = double(temp.f32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lfd f9,128(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// fmadds f30,f6,f31,f0
	f30.f64 = double(float(ctx.f6.f64 * f31.f64 + f0.f64));
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,12(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B3D6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,508(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 508);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f28,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f28.f64 = double(temp.f32);
	// beq cr6,0x824b3db0
	if (cr6.eq) goto loc_824B3DB0;
	// stfs f28,128(r30)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r30.u32 + 128, temp.u32);
	// b 0x824b3ea8
	goto loc_824B3EA8;
loc_824B3D88:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b3b90
	goto loc_824B3B90;
loc_824B3D9C:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b3c34
	goto loc_824B3C34;
loc_824B3DB0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmuls f12,f30,f27
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f30.f64 * f27.f64));
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	f0.f64 = double(temp.f32);
	// mulld r11,r11,r29
	r11.s64 = r11.s64 * r29.s64;
	// lfs f11,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f7.f64 = double(temp.f32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f3,144(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lfs f6,228(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 228);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f12,f29,f6
	ctx.f5.f64 = double(float(ctx.f12.f64 * f29.f64 + ctx.f6.f64));
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f4.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// std r4,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r4.u64);
	// lfd f12,144(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fmuls f11,f10,f1
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fmadds f11,f11,f31,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f31.f64 + f0.f64));
	// frsp f0,f10
	f0.f64 = double(float(ctx.f10.f64));
	// fsubs f6,f5,f0
	ctx.f6.f64 = double(float(ctx.f5.f64 - f0.f64));
	// stfs f6,228(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 228, temp.u32);
	// lfs f5,72(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 72);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,64(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,68(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 68);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f9
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f9.f64));
	// lfs f12,456(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 456);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f2,f2
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// fsubs f1,f5,f8
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f8.f64));
	// fsubs f9,f4,f7
	ctx.f9.f64 = double(float(ctx.f4.f64 - ctx.f7.f64));
	// fmadds f8,f1,f1,f10
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f10.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f10,f7
	ctx.f10.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x824b3e74
	if (cr6.lt) goto loc_824B3E74;
	// fmr f10,f12
	ctx.f10.f64 = ctx.f12.f64;
loc_824B3E74:
	// lwz r10,260(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// addi r11,r30,260
	r11.s64 = r30.s64 + 260;
	// fmadds f30,f10,f11,f0
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f0.f64));
	// rlwinm r9,r10,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// stw r9,260(r30)
	PPC_STORE_U32(r30.u32 + 260, ctx.r9.u32);
	// bne cr6,0x824b3ea8
	if (!cr6.eq) goto loc_824B3EA8;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// not r8,r10
	ctx.r8.u64 = ~ctx.r10.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rlwinm r7,r8,0,28,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// xor r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
loc_824B3EA8:
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// stfd f0,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, f0.u64);
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x824b3ee0
	if (!cr6.gt) goto loc_824B3EE0;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// subf r9,r10,r27
	ctx.r9.s64 = r27.s64 - ctx.r10.s64;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r8.u64);
	// lfd f0,144(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f30,f12
	ctx.f11.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fsel f30,f11,f12,f30
	f30.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f30.f64;
loc_824B3EE0:
	// lwz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// fctiwz f0,f30
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f30.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f30.f64));
	// stfd f0,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, f0.u64);
	// lwz r31,148(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// subf r20,r31,r11
	r20.s64 = r11.s64 - r31.s64;
	// lwz r9,88(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824B3F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// mr r27,r31
	r27.u64 = r31.u64;
	// blt cr6,0x824b3f14
	if (cr6.lt) goto loc_824B3F14;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_824B3F14:
	// lfs f0,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	f0.f64 = double(temp.f32);
	// li r31,1
	r31.s64 = 1;
	// fmuls f29,f0,f26
	f29.f64 = double(float(f0.f64 * f26.f64));
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// blt cr6,0x824b4020
	if (cr6.lt) goto loc_824B4020;
	// addi r26,r30,64
	r26.s64 = r30.s64 + 64;
	// addi r25,r22,368
	r25.s64 = r22.s64 + 368;
	// addi r24,r22,224
	r24.s64 = r22.s64 + 224;
loc_824B3F34:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B3F4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,508(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 508);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824b3f64
	if (cr6.eq) goto loc_824B3F64;
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
	// b 0x824b3f80
	goto loc_824B3F80;
loc_824B3F64:
	// extsw r11,r31
	r11.s64 = r31.s32;
	// std r11,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, r11.u64);
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 / f30.f64));
	// fmuls f31,f11,f27
	f31.f64 = double(float(ctx.f11.f64 * f27.f64));
loc_824B3F80:
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v0,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v61,r0,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// vsubfp128 v12,v61,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lvlx128 v58,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// vsubfp128 v11,v60,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v59,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// vspltw128 v9,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// fmr f3,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = f31.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// vmaddfp v2,v12,v10,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// fmr f1,f25
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f25.f64;
	// vmaddfp v1,v11,v9,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// bl 0x824b32d8
	ctx.lr = 0x824B3FE4;
	sub_824B32D8(ctx, base);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// fsubs f1,f28,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f28.f64 - f31.f64));
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lvx128 v1,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B4014;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// ble cr6,0x824b3f34
	if (!cr6.gt) goto loc_824B3F34;
loc_824B4020:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x824b407c
	if (!cr6.gt) goto loc_824B407C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// std r11,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, r11.u64);
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v57,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 / f30.f64));
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba18
	ctx.lr = 0x824B4078;
	// b 0x823d9228
	return;
loc_824B407C:
	// lwz r11,260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b4094
	if (!cr6.eq) goto loc_824B4094;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// ble cr6,0x824b40a4
	if (!cr6.gt) goto loc_824B40A4;
loc_824B4094:
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// li r10,64
	ctx.r10.s64 = 64;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B40A4:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba18
	ctx.lr = 0x824B40B0;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824B40B4"))) PPC_WEAK_FUNC(sub_824B40B4);
PPC_FUNC_IMPL(__imp__sub_824B40B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B40B8"))) PPC_WEAK_FUNC(sub_824B40B8);
PPC_FUNC_IMPL(__imp__sub_824B40B8) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B40C0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r8,r11,5
	ctx.r8.s64 = r11.s64 + 5;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r10.u32);
	// stwx r10,r6,r31
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, ctx.r10.u32);
	// lwz r5,260(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r4,r5,31,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b4124
	if (cr6.eq) goto loc_824B4124;
	// lbz r11,486(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 486);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b4124
	if (cr6.eq) goto loc_824B4124;
	// li r10,1
	ctx.r10.s64 = 1;
loc_824B4124:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// lwz r10,260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// neg r8,r11
	ctx.r8.s64 = -r11.s64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// xor r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// stw r5,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r5.u32);
	// lbz r4,508(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 508);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b4170
	if (cr6.eq) goto loc_824B4170;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x824b4170
	if (cr6.eq) goto loc_824B4170;
	// rotlwi r11,r5,0
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r10.u32);
loc_824B4170:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x824b4190
	if (cr6.lt) goto loc_824B4190;
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r10.u32);
loc_824B4190:
	// lfs f13,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f13,252(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b41cc
	if (cr6.eq) goto loc_824B41CC;
	// lfs f12,232(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f31,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + ctx.f13.f64));
	// stfs f11,128(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// fmr f10,f11
	ctx.f10.f64 = ctx.f11.f64;
	// stfs f10,252(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// blt cr6,0x824b41cc
	if (cr6.lt) goto loc_824B41CC;
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
loc_824B41CC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b42dc
	if (cr6.eq) goto loc_824B42DC;
	// lhz r9,160(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 160);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b420c
	if (!cr6.gt) goto loc_824B420C;
	// lwz r8,156(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_824B41F0:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x824b42e8
	if (!cr6.lt) goto loc_824B42E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b41f0
	if (cr6.lt) goto loc_824B41F0;
loc_824B420C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,156(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B4220:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lfs f1,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b42a0
	if (cr6.eq) goto loc_824B42A0;
	// addi r8,r30,436
	ctx.r8.s64 = r30.s64 + 436;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B42A0;
	sub_824AFF80(ctx, base);
loc_824B42A0:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stfs f0,256(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 256, temp.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lfs f13,240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f12,488(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 488);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// fmuls f1,f10,f31
	ctx.f1.f64 = double(float(ctx.f10.f64 * f31.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B42DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824B42DC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_824B42E8:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b4220
	goto loc_824B4220;
}

__attribute__((alias("__imp__sub_824B42FC"))) PPC_WEAK_FUNC(sub_824B42FC);
PPC_FUNC_IMPL(__imp__sub_824B42FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B4300"))) PPC_WEAK_FUNC(sub_824B4300);
PPC_FUNC_IMPL(__imp__sub_824B4300) {
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
	// bl 0x823d91e8
	ctx.lr = 0x824B4308;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b4518
	if (cr6.eq) goto loc_824B4518;
	// lfs f0,488(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 488);
	f0.f64 = double(temp.f32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lfs f13,240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,256(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	ctx.f11.f64 = double(temp.f32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmuls f10,f12,f31
	ctx.f10.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fmuls f1,f10,f11
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B436C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lfs f9,500(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 500);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// stfs f7,4(r9)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lwz r8,44(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lfs f6,500(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 500);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f5.f64));
	// stfs f4,4(r8)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r7,36(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// stw r24,284(r7)
	PPC_STORE_U32(ctx.r7.u32 + 284, r24.u32);
	// lwz r6,44(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// stw r24,284(r6)
	PPC_STORE_U32(ctx.r6.u32 + 284, r24.u32);
	// lwz r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwz r4,256(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 256);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x824b4414
	if (cr6.eq) goto loc_824B4414;
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lfs f0,436(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 436);
	f0.f64 = double(temp.f32);
	// stw r25,284(r11)
	PPC_STORE_U32(r11.u32 + 284, r25.u32);
	// stfs f0,256(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 256, temp.u32);
	// lwz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lfs f13,440(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,260(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// lfs f12,444(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// stw r25,284(r10)
	PPC_STORE_U32(ctx.r10.u32 + 284, r25.u32);
	// stfs f12,264(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
	// lfs f11,448(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,268(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 268, temp.u32);
	// lfs f10,452(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 452);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,272(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 272, temp.u32);
	// lfs f9,436(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 436);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,256(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 256, temp.u32);
	// lfs f8,440(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 440);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,260(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 260, temp.u32);
	// lfs f7,444(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 444);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,264(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 264, temp.u32);
	// lfs f6,448(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 448);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,268(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 268, temp.u32);
	// lfs f5,452(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 452);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,272(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 272, temp.u32);
loc_824B4414:
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r27,r30,176
	r27.s64 = r30.s64 + 176;
	// lfs f1,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B4434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,44(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lfs f1,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824B4450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r27,r31,48
	r27.s64 = r31.s64 + 48;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x824B4478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r26,r31,144
	r26.s64 = r31.s64 + 144;
	// li r11,80
	r11.s64 = 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824B44AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,260(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824b44f4
	if (cr6.eq) goto loc_824B44F4;
	// lfs f0,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	f0.f64 = double(temp.f32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lfs f3,252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f2,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,248(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	ctx.f1.f64 = double(temp.f32);
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// fmuls f4,f31,f0
	ctx.f4.f64 = double(float(f31.f64 * f0.f64));
	// bl 0x824b3b18
	ctx.lr = 0x824B44F0;
	sub_824B3B18(ctx, base);
	// b 0x824b4518
	goto loc_824B4518;
loc_824B44F4:
	// lwz r4,36(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B450C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,64
	ctx.r9.s64 = 64;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B4518:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// li r9,144
	ctx.r9.s64 = 144;
	// li r8,176
	ctx.r8.s64 = 176;
	// lwz r10,19708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r10,1(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// addi r7,r10,5
	ctx.r7.s64 = ctx.r10.s64 + 5;
	// rlwinm r6,r7,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// stfsx f0,r6,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, temp.u32);
	// lvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,19708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r5,1(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// rotlwi r10,r5,5
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 5);
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + r31.u64;
	// stvx128 v58,r4,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,260(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r10,r3,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b45a0
	if (cr6.eq) goto loc_824B45A0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x824b4580
	if (cr6.lt) goto loc_824B4580;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
loc_824B4580:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,260(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// neg r7,r10
	ctx.r7.s64 = -ctx.r10.s64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// xor r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 ^ ctx.r9.u64;
	// rlwinm r5,r6,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x2;
	// xor r4,r5,r8
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r8.u64;
	// stw r4,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r4.u32);
loc_824B45A0:
	// lwz r11,19708(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lbz r11,2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r31
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// add. r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x824b45d4
	if (!cr0.eq) goto loc_824B45D4;
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b45d8
	if (cr6.eq) goto loc_824B45D8;
loc_824B45D4:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_824B45D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r10,260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// neg r8,r11
	ctx.r8.s64 = -r11.s64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// xor r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r6,r7,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// stw r5,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824B4604"))) PPC_WEAK_FUNC(sub_824B4604);
PPC_FUNC_IMPL(__imp__sub_824B4604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B4608"))) PPC_WEAK_FUNC(sub_824B4608);
PPC_FUNC_IMPL(__imp__sub_824B4608) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,260(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 260);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,260(r4)
	PPC_STORE_U32(ctx.r4.u32 + 260, ctx.r10.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B4630"))) PPC_WEAK_FUNC(sub_824B4630);
PPC_FUNC_IMPL(__imp__sub_824B4630) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B4634"))) PPC_WEAK_FUNC(sub_824B4634);
PPC_FUNC_IMPL(__imp__sub_824B4634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B4638"))) PPC_WEAK_FUNC(sub_824B4638);
PPC_FUNC_IMPL(__imp__sub_824B4638) {
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
	ctx.lr = 0x824B4640;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r11,20888
	r28.s64 = r11.s64 + 20888;
	// lwz r11,20888(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20888);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b4900
	if (!cr6.eq) goto loc_824B4900;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824B4660;
	sub_82130528(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4674
	if (cr6.eq) goto loc_824B4674;
	// bl 0x821d5408
	ctx.lr = 0x824B4670;
	sub_821D5408(ctx, base);
	// b 0x824b4678
	goto loc_824B4678;
loc_824B4674:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B4678:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r7,r10,7948
	ctx.r7.s64 = ctx.r10.s64 + 7948;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,424
	ctx.r5.s64 = 424;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r8,-32181
	ctx.r8.s64 = -2109014016;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// addi r4,r8,11512
	ctx.r4.s64 = ctx.r8.s64 + 11512;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r31,r10,20804
	r31.s64 = ctx.r10.s64 + 20804;
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r3,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r3.u64);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,22004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22004);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b46f4
	if (!cr6.eq) goto loc_824B46F4;
	// bl 0x824c5408
	ctx.lr = 0x824B46F0;
	sub_824C5408(ctx, base);
	// lwz r11,22004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22004);
loc_824B46F4:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,20840
	r29.s64 = ctx.r10.s64 + 20840;
	// li r10,12
	ctx.r10.s64 = 12;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b4718
	if (!cr6.eq) goto loc_824B4718;
	// bl 0x824c5408
	ctx.lr = 0x824B4714;
	sub_824C5408(ctx, base);
	// lwz r11,22004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22004);
loc_824B4718:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// lis r27,-32115
	r27.s64 = -2104688640;
	// addi r31,r10,20876
	r31.s64 = ctx.r10.s64 + 20876;
	// li r10,20
	ctx.r10.s64 = 20;
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b4744
	if (!cr6.eq) goto loc_824B4744;
	// bl 0x824970b0
	ctx.lr = 0x824B4740;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B4744:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r29,r10,20912
	r29.s64 = ctx.r10.s64 + 20912;
	// li r10,60
	ctx.r10.s64 = 60;
	// stw r10,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b4768
	if (!cr6.eq) goto loc_824B4768;
	// bl 0x824970b0
	ctx.lr = 0x824B4764;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B4768:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,20948
	r30.s64 = ctx.r10.s64 + 20948;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b478c
	if (!cr6.eq) goto loc_824B478C;
	// bl 0x824970b0
	ctx.lr = 0x824B4788;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B478C:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,20984
	r31.s64 = ctx.r10.s64 + 20984;
	// li r10,140
	ctx.r10.s64 = 140;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b47b0
	if (!cr6.eq) goto loc_824B47B0;
	// bl 0x824970b0
	ctx.lr = 0x824B47AC;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B47B0:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,21020
	r30.s64 = ctx.r10.s64 + 21020;
	// li r10,180
	ctx.r10.s64 = 180;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b47d4
	if (!cr6.eq) goto loc_824B47D4;
	// bl 0x824970b0
	ctx.lr = 0x824B47D0;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B47D4:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,21056
	r31.s64 = ctx.r10.s64 + 21056;
	// li r10,220
	ctx.r10.s64 = 220;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b47f8
	if (!cr6.eq) goto loc_824B47F8;
	// bl 0x824970b0
	ctx.lr = 0x824B47F4;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B47F8:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,21092
	r30.s64 = ctx.r10.s64 + 21092;
	// li r10,260
	ctx.r10.s64 = 260;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b481c
	if (!cr6.eq) goto loc_824B481C;
	// bl 0x824970b0
	ctx.lr = 0x824B4818;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B481C:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,21128
	r31.s64 = ctx.r10.s64 + 21128;
	// li r10,300
	ctx.r10.s64 = 300;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b4840
	if (!cr6.eq) goto loc_824B4840;
	// bl 0x824970b0
	ctx.lr = 0x824B483C;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B4840:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,21164
	r30.s64 = ctx.r10.s64 + 21164;
	// li r10,340
	ctx.r10.s64 = 340;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b4864
	if (!cr6.eq) goto loc_824B4864;
	// bl 0x824970b0
	ctx.lr = 0x824B4860;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B4864:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r10,21200
	r31.s64 = ctx.r10.s64 + 21200;
	// li r10,380
	ctx.r10.s64 = 380;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824b4888
	if (!cr6.eq) goto loc_824B4888;
	// bl 0x824970b0
	ctx.lr = 0x824B4884;
	sub_824970B0(ctx, base);
	// lwz r11,20464(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20464);
loc_824B4888:
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// li r10,420
	ctx.r10.s64 = 420;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r8,r9,21236
	ctx.r8.s64 = ctx.r9.s64 + 21236;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x824B48AC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824B48BC;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824B48D8;
	sub_821D41D0(ctx, base);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r4,r5,21260
	ctx.r4.s64 = ctx.r5.s64 + 21260;
	// bl 0x821d4b00
	ctx.lr = 0x824B48E8;
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
	ctx.lr = 0x824B4900;
	sub_821C0548(ctx, base);
loc_824B4900:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B4908"))) PPC_WEAK_FUNC(sub_824B4908);
PPC_FUNC_IMPL(__imp__sub_824B4908) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x824B4910;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824aec18
	ctx.lr = 0x824B491C;
	sub_824AEC18(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// addi r10,r11,7828
	ctx.r10.s64 = r11.s64 + 7828;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824b2460
	ctx.lr = 0x824B4930;
	sub_824B2460(ctx, base);
	// addi r21,r31,456
	r21.s64 = r31.s64 + 456;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r23,0(r13)
	r23.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r22,60
	r22.s64 = 60;
	// mr r27,r21
	r27.u64 = r21.u64;
	// li r24,9
	r24.s64 = 9;
	// li r26,0
	r26.s64 = 0;
	// addi r25,r11,-26560
	r25.s64 = r11.s64 + -26560;
loc_824B4950:
	// lwzx r30,r22,r23
	r30.u64 = PPC_LOAD_U32(r22.u32 + r23.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b49e4
	if (cr6.eq) goto loc_824B49E4;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824B4968;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824b49e4
	if (cr6.eq) goto loc_824B49E4;
	// lwz r28,0(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b49e8
	if (cr6.eq) goto loc_824B49E8;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217d828
	ctx.lr = 0x824B498C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824b49c0
	if (cr6.eq) goto loc_824B49C0;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rotlwi r10,r28,0
	ctx.r10.u64 = __builtin_rotateleft32(r28.u32, 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// b 0x824b49e8
	goto loc_824B49E8;
loc_824B49C0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2378
	ctx.lr = 0x824B49D0;
	sub_821D2378(ctx, base);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r11,r26
	r11.u64 = r26.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// b 0x824b49e8
	goto loc_824B49E8;
loc_824B49E4:
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
loc_824B49E8:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bge 0x824b4950
	if (!cr0.lt) goto loc_824B4950;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r26,496(r31)
	PPC_STORE_U32(r31.u32 + 496, r26.u32);
	// addi r10,r31,52
	ctx.r10.s64 = r31.s64 + 52;
	// stb r26,508(r31)
	PPC_STORE_U8(r31.u32 + 508, r26.u8);
	// addi r9,r31,132
	ctx.r9.s64 = r31.s64 + 132;
	// addi r8,r31,172
	ctx.r8.s64 = r31.s64 + 172;
	// addi r7,r31,212
	ctx.r7.s64 = r31.s64 + 212;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r6,r31,252
	ctx.r6.s64 = r31.s64 + 252;
	// stfs f0,500(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stw r10,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r10.u32);
	// stw r9,460(r31)
	PPC_STORE_U32(r31.u32 + 460, ctx.r9.u32);
	// addi r5,r31,292
	ctx.r5.s64 = r31.s64 + 292;
	// stw r8,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r8.u32);
	// addi r4,r31,332
	ctx.r4.s64 = r31.s64 + 332;
	// stw r7,468(r31)
	PPC_STORE_U32(r31.u32 + 468, ctx.r7.u32);
	// addi r11,r31,372
	r11.s64 = r31.s64 + 372;
	// stw r6,472(r31)
	PPC_STORE_U32(r31.u32 + 472, ctx.r6.u32);
	// addi r10,r31,412
	ctx.r10.s64 = r31.s64 + 412;
	// stw r5,476(r31)
	PPC_STORE_U32(r31.u32 + 476, ctx.r5.u32);
	// addi r9,r31,92
	ctx.r9.s64 = r31.s64 + 92;
	// stw r4,480(r31)
	PPC_STORE_U32(r31.u32 + 480, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,484(r31)
	PPC_STORE_U32(r31.u32 + 484, r11.u32);
	// stw r10,488(r31)
	PPC_STORE_U32(r31.u32 + 488, ctx.r10.u32);
	// stw r9,492(r31)
	PPC_STORE_U32(r31.u32 + 492, ctx.r9.u32);
	// stw r26,504(r31)
	PPC_STORE_U32(r31.u32 + 504, r26.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824B4A68"))) PPC_WEAK_FUNC(sub_824B4A68);
PPC_FUNC_IMPL(__imp__sub_824B4A68) {
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
	ctx.lr = 0x824B4A70;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// bl 0x824aed88
	ctx.lr = 0x824B4A80;
	sub_824AED88(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r10,r11,7828
	ctx.r10.s64 = r11.s64 + 7828;
	// addi r3,r27,32
	ctx.r3.s64 = r27.s64 + 32;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// bl 0x824b2628
	ctx.lr = 0x824B4A98;
	sub_824B2628(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r21,0(r13)
	r21.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r22,60
	r22.s64 = 60;
	// addi r28,r27,456
	r28.s64 = r27.s64 + 456;
	// li r24,9
	r24.s64 = 9;
	// li r25,0
	r25.s64 = 0;
	// addi r26,r11,-26560
	r26.s64 = r11.s64 + -26560;
loc_824B4AB4:
	// lwzx r31,r22,r21
	r31.u64 = PPC_LOAD_U32(r22.u32 + r21.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b4b48
	if (cr6.eq) goto loc_824B4B48;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x824B4ACC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824b4b48
	if (cr6.eq) goto loc_824B4B48;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824b4b4c
	if (cr6.eq) goto loc_824B4B4C;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x824B4AF0;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824b4b24
	if (cr6.eq) goto loc_824B4B24;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// rotlwi r10,r29,0
	ctx.r10.u64 = __builtin_rotateleft32(r29.u32, 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x824b4b4c
	goto loc_824B4B4C;
loc_824B4B24:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2378
	ctx.lr = 0x824B4B34;
	sub_821D2378(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r11,r25
	r11.u64 = r25.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
	// b 0x824b4b4c
	goto loc_824B4B4C;
loc_824B4B48:
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
loc_824B4B4C:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bge 0x824b4ab4
	if (!cr0.lt) goto loc_824B4AB4;
	// addi r3,r27,496
	ctx.r3.s64 = r27.s64 + 496;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x821d2aa8
	ctx.lr = 0x824B4B64;
	sub_821D2AA8(ctx, base);
	// stw r25,504(r27)
	PPC_STORE_U32(r27.u32 + 504, r25.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,496(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 496);
	// bl 0x824b2968
	ctx.lr = 0x824B4B74;
	sub_824B2968(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_824B4B80"))) PPC_WEAK_FUNC(sub_824B4B80);
PPC_FUNC_IMPL(__imp__sub_824B4B80) {
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
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824B4B94;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4bb4
	if (cr6.eq) goto loc_824B4BB4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824b4908
	ctx.lr = 0x824B4BA4;
	sub_824B4908(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B4BB4:
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

__attribute__((alias("__imp__sub_824B4BC8"))) PPC_WEAK_FUNC(sub_824B4BC8);
PPC_FUNC_IMPL(__imp__sub_824B4BC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x824b4a68
	sub_824B4A68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B4BD4"))) PPC_WEAK_FUNC(sub_824B4BD4);
PPC_FUNC_IMPL(__imp__sub_824B4BD4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B4BD8"))) PPC_WEAK_FUNC(sub_824B4BD8);
PPC_FUNC_IMPL(__imp__sub_824B4BD8) {
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
	ctx.lr = 0x824B4BE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c81b0
	ctx.lr = 0x824B4BF4;
	sub_821C81B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4d3c
	if (cr6.eq) goto loc_824B4D3C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r10,7744
	ctx.r4.s64 = ctx.r10.s64 + 7744;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821c7910
	ctx.lr = 0x824B4C10;
	sub_821C7910(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,30712(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x824b4d3c
	if (!cr6.eq) goto loc_824B4D3C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,7460
	ctx.r4.s64 = r11.s64 + 7460;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c82a8
	ctx.lr = 0x824B4C34;
	sub_821C82A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824b4d3c
	if (cr6.eq) goto loc_824B4D3C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,7428
	r29.s64 = r11.s64 + 7428;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c82a8
	ctx.lr = 0x824B4C54;
	sub_821C82A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x824B4C60;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4c74
	if (cr6.eq) goto loc_824B4C74;
	// bl 0x82197a00
	ctx.lr = 0x824B4C6C;
	sub_82197A00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824b4c78
	goto loc_824B4C78;
loc_824B4C74:
	// li r31,0
	r31.s64 = 0;
loc_824B4C78:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c6a20
	ctx.lr = 0x824B4C88;
	sub_821C6A20(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r27,r11,7988
	r27.s64 = r11.s64 + 7988;
	// beq cr6,0x824b4cc0
	if (cr6.eq) goto loc_824B4CC0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c6a20
	ctx.lr = 0x824B4CA8;
	sub_821C6A20(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7e48
	ctx.lr = 0x824B4CB4;
	sub_821C7E48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c7e48
	ctx.lr = 0x824B4CC0;
	sub_821C7E48(ctx, base);
loc_824B4CC0:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r29,r11,7444
	r29.s64 = r11.s64 + 7444;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821c82a8
	ctx.lr = 0x824B4CD8;
	sub_821C82A8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x824B4CE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4cf8
	if (cr6.eq) goto loc_824B4CF8;
	// bl 0x82197a00
	ctx.lr = 0x824B4CF0;
	sub_82197A00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x824b4cfc
	goto loc_824B4CFC;
loc_824B4CF8:
	// li r31,0
	r31.s64 = 0;
loc_824B4CFC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c6a20
	ctx.lr = 0x824B4D0C;
	sub_821C6A20(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b4d3c
	if (cr6.eq) goto loc_824B4D3C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c6a20
	ctx.lr = 0x824B4D24;
	sub_821C6A20(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c7e48
	ctx.lr = 0x824B4D30;
	sub_821C7E48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c7e48
	ctx.lr = 0x824B4D3C;
	sub_821C7E48(ctx, base);
loc_824B4D3C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B4D44"))) PPC_WEAK_FUNC(sub_824B4D44);
PPC_FUNC_IMPL(__imp__sub_824B4D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B4D48"))) PPC_WEAK_FUNC(sub_824B4D48);
PPC_FUNC_IMPL(__imp__sub_824B4D48) {
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
	ctx.lr = 0x824B4D50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,20884
	r31.s64 = r11.s64 + 20884;
	// lwz r11,20884(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20884);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b4f24
	if (!cr6.eq) goto loc_824B4F24;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824B4D70;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b4d84
	if (cr6.eq) goto loc_824B4D84;
	// bl 0x821d5408
	ctx.lr = 0x824B4D80;
	sub_821D5408(ctx, base);
	// b 0x824b4d88
	goto loc_824B4D88;
loc_824B4D84:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824B4D88:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32181
	r11.s64 = -2109014016;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7996
	ctx.r7.s64 = ctx.r10.s64 + 7996;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-4536
	ctx.r9.s64 = r11.s64 + -4536;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,512
	ctx.r5.s64 = 512;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32181
	ctx.r8.s64 = -2109014016;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// addi r4,r8,19328
	ctx.r4.s64 = ctx.r8.s64 + 19328;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r3,20648
	ctx.r4.s64 = ctx.r3.s64 + 20648;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// addi r30,r10,20744
	r30.s64 = ctx.r10.s64 + 20744;
	// lwz r11,20888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20888);
	// addi r3,r9,20672
	ctx.r3.s64 = ctx.r9.s64 + 20672;
	// addi r28,r8,20696
	r28.s64 = ctx.r8.s64 + 20696;
	// addi r5,r5,20720
	ctx.r5.s64 = ctx.r5.s64 + 20720;
	// li r10,500
	ctx.r10.s64 = 500;
	// li r9,496
	ctx.r9.s64 = 496;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r7,508
	ctx.r7.s64 = 508;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stw r8,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r7,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r7.u32);
	// stw r6,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r6.u32);
	// bne cr6,0x824b4e44
	if (!cr6.eq) goto loc_824B4E44;
	// bl 0x824b4638
	ctx.lr = 0x824B4E40;
	sub_824B4638(ctx, base);
	// lwz r11,20888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20888);
loc_824B4E44:
	// lis r29,-32115
	r29.s64 = -2104688640;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// lwz r4,20868(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20868);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824b4e60
	if (!cr6.eq) goto loc_824B4E60;
	// bl 0x824af148
	ctx.lr = 0x824B4E5C;
	sub_824AF148(ctx, base);
	// lwz r4,20868(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20868);
loc_824B4E60:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824B4E6C;
	sub_821D4458(ctx, base);
	// lwz r11,20868(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20868);
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
	ctx.lr = 0x824B4E88;
	sub_82130528(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r3.u32);
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// sth r11,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r11.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,60(r30)
	PPC_STORE_U8(r30.u32 + 60, r11.u8);
	// addi r9,r10,19416
	ctx.r9.s64 = ctx.r10.s64 + 19416;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x824B4EAC;
	sub_82130000(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r8,-13244
	ctx.r4.s64 = ctx.r8.s64 + -13244;
	// bl 0x82197d98
	ctx.lr = 0x824B4EC8;
	sub_82197D98(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82196758
	ctx.lr = 0x824B4ED0;
	sub_82196758(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824B4EE0;
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
	ctx.lr = 0x824B4EFC;
	sub_821D41D0(ctx, base);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,20780
	ctx.r4.s64 = ctx.r5.s64 + 20780;
	// bl 0x821d4b00
	ctx.lr = 0x824B4F0C;
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
	ctx.lr = 0x824B4F24;
	sub_821C0548(ctx, base);
loc_824B4F24:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B4F2C"))) PPC_WEAK_FUNC(sub_824B4F2C);
PPC_FUNC_IMPL(__imp__sub_824B4F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B4F30"))) PPC_WEAK_FUNC(sub_824B4F30);
PPC_FUNC_IMPL(__imp__sub_824B4F30) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x8217fed0
	ctx.lr = 0x824B4F4C;
	sub_8217FED0(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r11,-25600(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -25600);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x824B4F6C;
	sub_8217FED0(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,11
	ctx.r3.s64 = 11;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r8.u8);
	// bl 0x8217fed0
	ctx.lr = 0x824B4F84;
	sub_8217FED0(ctx, base);
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r5.u8);
	// bl 0x8217fed0
	ctx.lr = 0x824B4F9C;
	sub_8217FED0(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217fed0
	ctx.lr = 0x824B4FA8;
	sub_8217FED0(ctx, base);
	// cntlzw r4,r3
	ctx.r4.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stb r10,18(r31)
	PPC_STORE_U8(r31.u32 + 18, ctx.r10.u8);
	// bl 0x8217fed0
	ctx.lr = 0x824B4FC0;
	sub_8217FED0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_824B4FD8"))) PPC_WEAK_FUNC(sub_824B4FD8);
PPC_FUNC_IMPL(__imp__sub_824B4FD8) {
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
	// li r3,2
	ctx.r3.s64 = 2;
	// lbz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// bl 0x82189e80
	ctx.lr = 0x824B4FF8;
	sub_82189E80(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r4,17(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// bl 0x82189e80
	ctx.lr = 0x824B5004;
	sub_82189E80(ctx, base);
	// li r3,10
	ctx.r3.s64 = 10;
	// lbz r4,18(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// bl 0x82189e80
	ctx.lr = 0x824B5010;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82189e80
	ctx.lr = 0x824B501C;
	sub_82189E80(ctx, base);
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82189e80
	ctx.lr = 0x824B5028;
	sub_82189E80(ctx, base);
	// li r3,6
	ctx.r3.s64 = 6;
	// lbz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// bl 0x8217f768
	ctx.lr = 0x824B5034;
	sub_8217F768(ctx, base);
	// li r3,11
	ctx.r3.s64 = 11;
	// lbz r4,17(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// bl 0x8217f768
	ctx.lr = 0x824B5040;
	sub_8217F768(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8217f768
	ctx.lr = 0x824B504C;
	sub_8217F768(ctx, base);
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// li r3,12
	ctx.r3.s64 = 12;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8217f768
	ctx.lr = 0x824B5060;
	sub_8217F768(ctx, base);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x824b5094
	if (!cr6.eq) goto loc_824B5094;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217fde0
	ctx.lr = 0x824B5078;
	sub_8217FDE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fd68
	ctx.lr = 0x824B5084;
	sub_8217FD68(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217fe58
	ctx.lr = 0x824B5090;
	sub_8217FE58(ctx, base);
	// b 0x824b509c
	goto loc_824B509C;
loc_824B5094:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x824B509C;
	sub_8217F768(ctx, base);
loc_824B509C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// ble cr6,0x824b50b4
	if (!cr6.gt) goto loc_824B50B4;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_824B50B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x824B50BC;
	sub_8217F768(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// lbz r4,18(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// bl 0x8217f768
	ctx.lr = 0x824B50C8;
	sub_8217F768(ctx, base);
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

__attribute__((alias("__imp__sub_824B50DC"))) PPC_WEAK_FUNC(sub_824B50DC);
PPC_FUNC_IMPL(__imp__sub_824B50DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B50E0"))) PPC_WEAK_FUNC(sub_824B50E0);
PPC_FUNC_IMPL(__imp__sub_824B50E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// addi r3,r3,372
	ctx.r3.s64 = ctx.r3.s64 + 372;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_824B50F4"))) PPC_WEAK_FUNC(sub_824B50F4);
PPC_FUNC_IMPL(__imp__sub_824B50F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B50F8"))) PPC_WEAK_FUNC(sub_824B50F8);
PPC_FUNC_IMPL(__imp__sub_824B50F8) {
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
	ctx.lr = 0x824B5100;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r30,r4,16
	r30.u64 = ctx.r4.u32 & 0xFFFF;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x824b5154
	if (!cr6.lt) goto loc_824B5154;
loc_824B511C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821d2a58
	ctx.lr = 0x824B5134;
	sub_821D2A58(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b511c
	if (cr6.lt) goto loc_824B511C;
loc_824B5154:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r10.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B516C"))) PPC_WEAK_FUNC(sub_824B516C);
PPC_FUNC_IMPL(__imp__sub_824B516C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5170"))) PPC_WEAK_FUNC(sub_824B5170);
PPC_FUNC_IMPL(__imp__sub_824B5170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20892);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B517C"))) PPC_WEAK_FUNC(sub_824B517C);
PPC_FUNC_IMPL(__imp__sub_824B517C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5180"))) PPC_WEAK_FUNC(sub_824B5180);
PPC_FUNC_IMPL(__imp__sub_824B5180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91fc
	ctx.lr = 0x824B5188;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b5208
	if (cr6.eq) goto loc_824B5208;
loc_824B519C:
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,192
	ctx.r10.s64 = r31.s64 + 192;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r31,240
	ctx.r9.s64 = r31.s64 + 240;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v56,v57
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b51ec
	if (cr6.eq) goto loc_824B51EC;
	// bl 0x8247a3e0
	ctx.lr = 0x824B51EC;
	sub_8247A3E0(ctx, base);
loc_824B51EC:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824b51fc
	if (cr6.eq) goto loc_824B51FC;
	// bl 0x8247a3e0
	ctx.lr = 0x824B51FC;
	sub_8247A3E0(ctx, base);
loc_824B51FC:
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824b519c
	if (!cr6.eq) goto loc_824B519C;
loc_824B5208:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B5210"))) PPC_WEAK_FUNC(sub_824B5210);
PPC_FUNC_IMPL(__imp__sub_824B5210) {
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
	ctx.lr = 0x824B5218;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x824B5234;
	sub_8261DBE0(ctx, base);
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8261dbe0
	ctx.lr = 0x824B5244;
	sub_8261DBE0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r11,-9432
	ctx.r9.s64 = r11.s64 + -9432;
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// addi r29,r10,30576
	r29.s64 = ctx.r10.s64 + 30576;
	// addi r4,r8,-32120
	ctx.r4.s64 = ctx.r8.s64 + -32120;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x824B5268;
	sub_821CA540(ctx, base);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r7,8368
	ctx.r4.s64 = ctx.r7.s64 + 8368;
	// bl 0x821ca540
	ctx.lr = 0x824B5278;
	sub_821CA540(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,8360
	ctx.r5.s64 = ctx.r5.s64 + 8360;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,2828(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2828);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c04b0
	ctx.lr = 0x824B529C;
	sub_821C04B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B52A8;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x824B52B0;
	sub_821C9A90(ctx, base);
	// clrlwi r4,r28,24
	ctx.r4.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824b52d8
	if (!cr6.eq) goto loc_824B52D8;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8261dca8
	ctx.lr = 0x824B52C4;
	sub_8261DCA8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x824B52CC;
	sub_8261DCA8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
loc_824B52D8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B52F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8261dca8
	ctx.lr = 0x824B52F8;
	sub_8261DCA8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x824B5300;
	sub_8261DCA8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_824B530C"))) PPC_WEAK_FUNC(sub_824B530C);
PPC_FUNC_IMPL(__imp__sub_824B530C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5310"))) PPC_WEAK_FUNC(sub_824B5310);
PPC_FUNC_IMPL(__imp__sub_824B5310) {
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
	ctx.lr = 0x824B5318;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B5334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// lfs f13,12(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,21700(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21700);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x824b5360
	if (!cr6.lt) goto loc_824B5360;
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r4,r11,23472
	ctx.r4.s64 = r11.s64 + 23472;
	// addi r3,r10,8384
	ctx.r3.s64 = ctx.r10.s64 + 8384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x824B5360;
	sub_82130000(ctx, base);
loc_824B5360:
	// lhz r11,364(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 364);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b53a4
	if (cr6.eq) goto loc_824B53A4;
	// li r30,0
	r30.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_824B5378:
	// lwz r11,360(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 360);
	// lwz r3,-4916(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -4916);
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lwzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8247fa28
	ctx.lr = 0x824B538C;
	sub_8247FA28(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lhz r11,364(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 364);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824b5378
	if (cr6.lt) goto loc_824B5378;
loc_824B53A4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B53B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_824B53C0"))) PPC_WEAK_FUNC(sub_824B53C0);
PPC_FUNC_IMPL(__imp__sub_824B53C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b541c
	if (cr6.eq) goto loc_824B541C;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// stw r8,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r8.u32);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bne cr6,0x824b53f0
	if (!cr6.eq) goto loc_824B53F0;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
loc_824B53F0:
	// lwz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824b5404
	if (cr6.eq) goto loc_824B5404;
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
loc_824B5404:
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b5418
	if (cr6.eq) goto loc_824B5418;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
loc_824B5418:
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
loc_824B541C:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b5454
	if (cr6.eq) goto loc_824B5454;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lwz r11,108(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r10,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r10.u32);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// blr 
	return;
loc_824B5454:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b5464
	if (!cr6.eq) goto loc_824B5464;
	// stw r5,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r5.u32);
loc_824B5464:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// stw r9,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r9.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// stw r5,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r5.u32);
	// lwz r11,92(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B5484"))) PPC_WEAK_FUNC(sub_824B5484);
PPC_FUNC_IMPL(__imp__sub_824B5484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5488"))) PPC_WEAK_FUNC(sub_824B5488);
PPC_FUNC_IMPL(__imp__sub_824B5488) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b5504
	if (cr6.eq) goto loc_824B5504;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b54d8
	if (cr6.eq) goto loc_824B54D8;
loc_824B54A0:
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// lwz r8,108(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// stw r6,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r6.u32);
	// bne cr6,0x824b54a0
	if (!cr6.eq) goto loc_824B54A0;
loc_824B54D8:
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r9,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r9.u32);
	// lbz r11,117(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 117);
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r10,r4
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, ctx.r9.u32);
	// lbz r11,117(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 117);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r4
	PPC_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.r9.u32);
	// blr 
	return;
loc_824B5504:
	// b 0x8247d338
	sub_8247D338(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B5508"))) PPC_WEAK_FUNC(sub_824B5508);
PPC_FUNC_IMPL(__imp__sub_824B5508) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,88(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x824b5530
	if (cr6.lt) goto loc_824B5530;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824B5530:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,88(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// beq cr6,0x824b5584
	if (cr6.eq) goto loc_824B5584;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x824b5554
	if (cr6.lt) goto loc_824B5554;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824B5554:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b55bc
	if (!cr6.eq) goto loc_824B55BC;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824b5570
	if (cr6.lt) goto loc_824B5570;
	// li r11,0
	r11.s64 = 0;
loc_824B5570:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824B557C:
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// blr 
	return;
loc_824B5584:
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824b5594
	if (cr6.lt) goto loc_824B5594;
	// li r11,0
	r11.s64 = 0;
loc_824B5594:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b557c
	if (!cr6.eq) goto loc_824B557C;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x824b55b0
	if (cr6.lt) goto loc_824B55B0;
	// li r11,0
	r11.s64 = 0;
loc_824B55B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_824B55BC:
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B55C4"))) PPC_WEAK_FUNC(sub_824B55C4);
PPC_FUNC_IMPL(__imp__sub_824B55C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B55C8"))) PPC_WEAK_FUNC(sub_824B55C8);
PPC_FUNC_IMPL(__imp__sub_824B55C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// ble cr6,0x824b5628
	if (!cr6.gt) goto loc_824B5628;
loc_824B55DC:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,88(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r8,88(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// li r9,1
	ctx.r9.s64 = 1;
	// blt cr6,0x824b55fc
	if (cr6.lt) goto loc_824B55FC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_824B55FC:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824b5628
	if (cr6.eq) goto loc_824B5628;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// cmpw cr6,r4,r5
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// stwx r10,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r10.u32);
	// addze r11,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	r11.s64 = temp.s64;
	// bgt cr6,0x824b55dc
	if (cr6.gt) goto loc_824B55DC;
loc_824B5628:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r11,r3
	PPC_STORE_U32(r11.u32 + ctx.r3.u32, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B5634"))) PPC_WEAK_FUNC(sub_824B5634);
PPC_FUNC_IMPL(__imp__sub_824B5634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5638"))) PPC_WEAK_FUNC(sub_824B5638);
PPC_FUNC_IMPL(__imp__sub_824B5638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// lhz r9,28(r5)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + 28);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b5678
	if (!cr6.gt) goto loc_824B5678;
	// lwz r6,24(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// addi r10,r6,48
	ctx.r10.s64 = ctx.r6.s64 + 48;
loc_824B565C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bge cr6,0x824b5710
	if (!cr6.lt) goto loc_824B5710;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b565c
	if (cr6.lt) goto loc_824B565C;
loc_824B5678:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824B568C:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,80(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f6,f13,f5
	f0.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b5700
	if (cr6.eq) goto loc_824B5700;
	// lwz r6,40(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x824aff80
	ctx.lr = 0x824B5700;
	sub_824AFF80(ctx, base);
loc_824B5700:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824B5710:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// b 0x824b568c
	goto loc_824B568C;
}

__attribute__((alias("__imp__sub_824B5724"))) PPC_WEAK_FUNC(sub_824B5724);
PPC_FUNC_IMPL(__imp__sub_824B5724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5728"))) PPC_WEAK_FUNC(sub_824B5728);
PPC_FUNC_IMPL(__imp__sub_824B5728) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x824B5730;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r30,76
	r28.s64 = r30.s64 + 76;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B5770;
	sub_824B5638(ctx, base);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r31,432
	ctx.r5.s64 = r31.s64 + 432;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B578C;
	sub_824B5638(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r27,r11,20976
	r27.s64 = r11.s64 + 20976;
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v11,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v11,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,481(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 481);
	// lbz r3,126(r30)
	ctx.r3.u64 = PPC_LOAD_U8(r30.u32 + 126);
	// rotlwi r11,r3,2
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// lfs f29,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f29.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lfsx f0,r11,r27
	temp.u32 = PPC_LOAD_U32(r11.u32 + r27.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b5800
	if (cr6.eq) goto loc_824B5800;
	// fsubs f0,f29,f0
	f0.f64 = double(float(f29.f64 - f0.f64));
loc_824B5800:
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// lfs f12,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f30,f11,f0,f13
	f30.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f30,12(r26)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r26.u32 + 12, temp.u32);
	// beq cr6,0x824b5898
	if (cr6.eq) goto loc_824B5898;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r31,68
	ctx.r5.s64 = r31.s64 + 68;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B583C;
	sub_824B5638(ctx, base);
	// lbz r11,125(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 125);
	// lbz r10,65(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfsx f0,r9,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r27.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b5858
	if (cr6.eq) goto loc_824B5858;
	// fsubs f0,f29,f0
	f0.f64 = double(float(f29.f64 - f0.f64));
loc_824B5858:
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f7,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fsubs f5,f7,f11
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f11.f64));
	// stfs f30,12(r26)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r26.u32 + 12, temp.u32);
	// fmadds f4,f8,f0,f13
	ctx.f4.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f13.f64));
	// stfs f4,0(r26)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// fmadds f3,f6,f0,f12
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// stfs f3,4(r26)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r26.u32 + 4, temp.u32);
	// fmadds f2,f5,f0,f11
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64 + ctx.f11.f64));
	// stfs f2,8(r26)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r26.u32 + 8, temp.u32);
loc_824B5898:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_824B58AC"))) PPC_WEAK_FUNC(sub_824B58AC);
PPC_FUNC_IMPL(__imp__sub_824B58AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B58B0"))) PPC_WEAK_FUNC(sub_824B58B0);
PPC_FUNC_IMPL(__imp__sub_824B58B0) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824B58B8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824b5974
	if (cr6.eq) goto loc_824B5974;
	// lwz r11,592(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 592);
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b5974
	if (cr6.eq) goto loc_824B5974;
	// lwz r11,584(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 584);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r6,r11,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r5,r11,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r4,r11,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,8(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,12(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_824B5974:
	// lhz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 36);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b59a8
	if (!cr6.gt) goto loc_824B59A8;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_824B598C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x824b5b7c
	if (!cr6.lt) goto loc_824B5B7C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b598c
	if (cr6.lt) goto loc_824B598C;
loc_824B59A8:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,32(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B59BC:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f12,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,96(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,100(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,104(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824b5a38
	if (cr6.eq) goto loc_824B5A38;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824aff80
	ctx.lr = 0x824B5A38;
	sub_824AFF80(ctx, base);
loc_824B5A38:
	// lbz r11,269(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 269);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b5b70
	if (cr6.eq) goto loc_824B5B70;
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x824b5a78
	if (!cr6.gt) goto loc_824B5A78;
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_824B5A5C:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x824b5b90
	if (!cr6.lt) goto loc_824B5B90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x824b5a5c
	if (cr6.lt) goto loc_824B5A5C;
loc_824B5A78:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_824B5A8C:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f12,f13,f11
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,108(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// fmadds f3,f10,f13,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f2,f8,f13,f7
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f1,f6,f13,f5
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b5b0c
	if (cr6.eq) goto loc_824B5B0C;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824aff80
	ctx.lr = 0x824B5B0C;
	sub_824AFF80(ctx, base);
loc_824B5B0C:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lbz r11,493(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 493);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// addi r8,r10,20976
	ctx.r8.s64 = ctx.r10.s64 + 20976;
	// lfs f11,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f4,f7,f12
	ctx.f4.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f5,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f3,f5,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// lfsx f2,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f8,f2,f0
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f2.f64 + f0.f64));
	// stfs f1,0(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// fmadds f0,f6,f2,f13
	f0.f64 = double(float(ctx.f6.f64 * ctx.f2.f64 + ctx.f13.f64));
	// stfs f0,4(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// fmadds f13,f4,f2,f12
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f2.f64 + ctx.f12.f64));
	// stfs f13,8(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// fmadds f12,f3,f2,f11
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f11.f64));
	// stfs f12,12(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
loc_824B5B70:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_824B5B7C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b59bc
	goto loc_824B59BC;
loc_824B5B90:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x824b5a8c
	goto loc_824B5A8C;
}

__attribute__((alias("__imp__sub_824B5BA4"))) PPC_WEAK_FUNC(sub_824B5BA4);
PPC_FUNC_IMPL(__imp__sub_824B5BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B5BA8"))) PPC_WEAK_FUNC(sub_824B5BA8);
PPC_FUNC_IMPL(__imp__sub_824B5BA8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x824B5BB0;
	// stfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f29.u64);
	// stfd f30,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// li r19,0
	r19.s64 = 0;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r19,124(r22)
	PPC_STORE_U32(r22.u32 + 124, r19.u32);
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// stw r19,128(r22)
	PPC_STORE_U32(r22.u32 + 128, r19.u32);
	// addi r31,r22,16
	r31.s64 = r22.s64 + 16;
	// lwz r11,132(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 132);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,132(r22)
	PPC_STORE_U32(r22.u32 + 132, ctx.r10.u32);
	// lfs f0,128(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 128);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r22)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r22.u32 + 116, temp.u32);
	// lwz r9,132(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 132);
	// rlwinm r8,r9,0,31,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r26,r22,176
	r26.s64 = r22.s64 + 176;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stw r8,132(r22)
	PPC_STORE_U32(r22.u32 + 132, ctx.r8.u32);
	// rlwinm r6,r7,0,30,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r6,132(r22)
	PPC_STORE_U32(r22.u32 + 132, ctx.r6.u32);
	// lhz r5,364(r27)
	ctx.r5.u64 = PPC_LOAD_U16(r27.u32 + 364);
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x824b5c3c
	if (!cr0.lt) goto loc_824B5C3C;
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
loc_824B5C3C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// addi r30,r11,2176
	r30.s64 = r11.s64 + 2176;
	// ori r29,r9,64167
	r29.u64 = ctx.r9.u64 | 64167;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r7,2176(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 2176);
	// addi r28,r27,372
	r28.s64 = r27.s64 + 372;
	// twllei r8,0
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mulld r10,r7,r29
	ctx.r10.s64 = ctx.r7.s64 * r29.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// divw r5,r6,r8
	ctx.r5.s32 = ctx.r6.s32 / ctx.r8.s32;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// mullw r4,r5,r8
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// subf r10,r4,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r4.s64;
	// rotlwi r11,r6,1
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stb r10,92(r26)
	PPC_STORE_U8(r26.u32 + 92, ctx.r10.u8);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// andc r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 & ~ctx.r7.u64;
	// twlgei r6,-1
	// bl 0x824dd2d0
	ctx.lr = 0x824B5CA4;
	sub_824DD2D0(ctx, base);
	// addi r20,r27,700
	r20.s64 = r27.s64 + 700;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x824dd218
	ctx.lr = 0x824B5CB4;
	sub_824DD218(ctx, base);
	// stb r3,127(r31)
	PPC_STORE_U8(r31.u32 + 127, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,492
	ctx.r4.s64 = r27.s64 + 492;
	// bl 0x824dd218
	ctx.lr = 0x824B5CC4;
	sub_824DD218(ctx, base);
	// stb r3,123(r31)
	PPC_STORE_U8(r31.u32 + 123, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,596
	ctx.r4.s64 = r27.s64 + 596;
	// bl 0x824dd218
	ctx.lr = 0x824B5CD4;
	sub_824DD218(ctx, base);
	// stb r3,124(r31)
	PPC_STORE_U8(r31.u32 + 124, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,388
	ctx.r4.s64 = r27.s64 + 388;
	// bl 0x824dd218
	ctx.lr = 0x824B5CE4;
	sub_824DD218(ctx, base);
	// stb r3,125(r31)
	PPC_STORE_U8(r31.u32 + 125, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,752
	ctx.r4.s64 = r27.s64 + 752;
	// bl 0x824dd218
	ctx.lr = 0x824B5CF4;
	sub_824DD218(ctx, base);
	// stb r3,129(r31)
	PPC_STORE_U8(r31.u32 + 129, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,1064
	ctx.r4.s64 = r27.s64 + 1064;
	// bl 0x824dd218
	ctx.lr = 0x824B5D04;
	sub_824DD218(ctx, base);
	// stb r3,131(r31)
	PPC_STORE_U8(r31.u32 + 131, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,804
	ctx.r4.s64 = r27.s64 + 804;
	// bl 0x824dd218
	ctx.lr = 0x824B5D14;
	sub_824DD218(ctx, base);
	// stb r3,126(r31)
	PPC_STORE_U8(r31.u32 + 126, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,856
	ctx.r4.s64 = r27.s64 + 856;
	// bl 0x824dd218
	ctx.lr = 0x824B5D24;
	sub_824DD218(ctx, base);
	// stb r3,128(r31)
	PPC_STORE_U8(r31.u32 + 128, ctx.r3.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r27,1636
	ctx.r4.s64 = r27.s64 + 1636;
	// bl 0x824dd218
	ctx.lr = 0x824B5D34;
	sub_824DD218(ctx, base);
	// stb r3,130(r31)
	PPC_STORE_U8(r31.u32 + 130, ctx.r3.u8);
	// addi r18,r27,1116
	r18.s64 = r27.s64 + 1116;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x824dd218
	ctx.lr = 0x824B5D48;
	sub_824DD218(ctx, base);
	// stb r3,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r3.u8);
	// bl 0x824c2b28
	ctx.lr = 0x824B5D50;
	sub_824C2B28(ctx, base);
	// stb r3,133(r31)
	PPC_STORE_U8(r31.u32 + 133, ctx.r3.u8);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lis r5,10381
	ctx.r5.s64 = 680329216;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulld r10,r4,r29
	ctx.r10.s64 = ctx.r4.s64 * r29.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// ori r3,r5,61643
	ctx.r3.u64 = ctx.r5.u64 | 61643;
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulhw r6,r7,r3
	ctx.r6.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r3.s32)) >> 32;
	// srawi r10,r6,4
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 4;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lbz r3,306(r27)
	ctx.r3.u64 = PPC_LOAD_U8(r27.u32 + 306);
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mulli r4,r5,101
	ctx.r4.s64 = ctx.r5.s64 * 101;
	// subf r11,r4,r7
	r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bgt cr6,0x824b5dac
	if (cr6.gt) goto loc_824B5DAC;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
loc_824B5DAC:
	// bl 0x824c2b28
	ctx.lr = 0x824B5DB0;
	sub_824C2B28(ctx, base);
	// stb r3,137(r31)
	PPC_STORE_U8(r31.u32 + 137, ctx.r3.u8);
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// rlwinm r10,r11,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824b5dc8
	if (!cr6.eq) goto loc_824B5DC8;
	// bl 0x824c2b28
	ctx.lr = 0x824B5DC8;
	sub_824C2B28(ctx, base);
loc_824B5DC8:
	// stb r3,138(r31)
	PPC_STORE_U8(r31.u32 + 138, ctx.r3.u8);
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// rlwinm r10,r11,24,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b5de4
	if (cr6.eq) goto loc_824B5DE4;
	// lbz r3,137(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 137);
	// b 0x824b5de8
	goto loc_824B5DE8;
loc_824B5DE4:
	// bl 0x824c2b28
	ctx.lr = 0x824B5DE8;
	sub_824C2B28(ctx, base);
loc_824B5DE8:
	// stb r3,139(r31)
	PPC_STORE_U8(r31.u32 + 139, ctx.r3.u8);
	// bl 0x824c2b28
	ctx.lr = 0x824B5DF0;
	sub_824C2B28(ctx, base);
	// stb r3,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r3.u8);
	// lfs f0,436(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 436);
	f0.f64 = double(temp.f32);
	// addi r25,r31,76
	r25.s64 = r31.s64 + 76;
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lfs f13,440(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 440);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// stfs f13,80(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// addi r5,r27,1272
	ctx.r5.s64 = r27.s64 + 1272;
	// lfs f12,444(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 444);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f11,448(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 448);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,88(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lfs f10,452(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 452);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,92(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lfs f30,128(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 128);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x824b5638
	ctx.lr = 0x824B5E40;
	sub_824B5638(ctx, base);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// addi r5,r27,1324
	ctx.r5.s64 = r27.s64 + 1324;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B5E5C;
	sub_824B5638(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// mulld r10,r9,r29
	ctx.r10.s64 = ctx.r9.s64 * r29.s64;
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f2,f11
	ctx.f10.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f5,96(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// lfs f31,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f31.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lfs f0,27644(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r5,r27,1480
	ctx.r5.s64 = r27.s64 + 1480;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fmuls f9,f8,f3
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f3.f64));
	// fmadds f8,f9,f31,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f13.f64));
	// stfs f8,0(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulld r10,r3,r29
	ctx.r10.s64 = ctx.r3.s64 * r29.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f7,96(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// fmuls f3,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f4.f64));
	// fmadds f2,f3,f31,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 * f31.f64 + ctx.f12.f64));
	// stfs f2,4(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mulld r10,r6,r29
	ctx.r10.s64 = ctx.r6.s64 * r29.s64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// fmuls f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmadds f9,f10,f31,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f11.f64));
	// stfs f9,8(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824b5638
	ctx.lr = 0x824B5F88;
	sub_824B5638(ctx, base);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r5,r27,1532
	ctx.r5.s64 = r27.s64 + 1532;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B5FA4;
	sub_824B5638(ctx, base);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r5,r27,1584
	ctx.r5.s64 = r27.s64 + 1584;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B5FC0;
	sub_824B5638(ctx, base);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// mulld r10,r5,r29
	ctx.r10.s64 = ctx.r5.s64 * r29.s64;
	// lfs f6,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f6.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// lfs f5,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f5.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// lfs f2,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f2,f11
	ctx.f10.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r29
	ctx.r10.s64 = ctx.r10.s64 * r29.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// lfd f9,96(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mulld r9,r10,r29
	ctx.r9.s64 = ctx.r10.s64 * r29.s64;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// rldicl r10,r11,32,32
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// li r29,64
	r29.s64 = 64;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// clrlwi r10,r11,9
	ctx.r10.u64 = r11.u32 & 0x7FFFFF;
	// addi r3,r6,2240
	ctx.r3.s64 = ctx.r6.s64 + 2240;
	// fmuls f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f1,96(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// fmadds f2,f5,f31,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f31.f64 + f0.f64));
	// stfs f2,112(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f8,f0
	ctx.f8.f64 = double(float(f0.f64));
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// addi r7,r8,2528
	ctx.r7.s64 = ctx.r8.s64 + 2528;
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r4
	ctx.r10.s64 = ctx.r10.s64 * ctx.r4.s64;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f6,f3,f8
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmadds f3,f6,f31,f12
	ctx.f3.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f12.f64));
	// stfs f3,120(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f2,f4,f5
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r6,-31648
	ctx.r10.s64 = ctx.r6.s64 + -31648;
	// addi r8,r4,-31664
	ctx.r8.s64 = ctx.r4.s64 + -31664;
	// clrlwi r3,r11,9
	ctx.r3.u64 = r11.u32 & 0x7FFFFF;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// fmadds f13,f2,f31,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f13.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f30,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f30.f64 = double(temp.f32);
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// lfd f1,96(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f1
	f0.f64 = double(ctx.f1.s64);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// frsp f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,18204(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18204);
	f0.f64 = double(temp.f32);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// vrsqrtefp128 v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// fmuls f10,f10,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmadds f9,f10,f31,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f11.f64));
	// vcmpeqfp128 v11,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// fmuls f8,f9,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f8,88(r26)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r26.u32 + 88, temp.u32);
	// stfs f8,12(r26)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r26.u32 + 12, temp.u32);
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v63,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// lfs f7,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,4(r26)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r26.u32 + 4, temp.u32);
	// stfs f6,0(r26)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// stfs f5,8(r26)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r26.u32 + 8, temp.u32);
	// stw r19,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r19.u32);
	// stw r19,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r19.u32);
	// lvx128 v126,r21,r29
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824b5638
	ctx.lr = 0x824B618C;
	sub_824B5638(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f4,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f4.f64 = double(temp.f32);
	// vsubfp128 v5,v127,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)));
	// fmuls f3,f4,f29
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f4.f64 * f29.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r30,r26,16
	r30.s64 = r26.s64 + 16;
	// li r20,16
	r20.s64 = 16;
	// lvlx128 v56,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v4,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v3,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v5,v4,v3
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vor128 v55,v2,v2
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// stvx128 v2,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r26,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,224(r21)
	r29.u64 = PPC_LOAD_U32(r21.u32 + 224);
	// lwz r3,44(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x824b6340
	if (!cr6.eq) goto loc_824B6340;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lfs f1,80(r26)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B61FC;
	sub_824B5638(ctx, base);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,176
	r11.s64 = r11.s64 + 176;
	// lfs f0,8456(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8456);
	f0.f64 = double(temp.f32);
	// li r7,48
	ctx.r7.s64 = 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lfs f0,-12080(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12080);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r5,-23776
	ctx.r4.s64 = ctx.r5.s64 + -23776;
	// lvlx128 v54,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvlx128 v53,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// lvx128 v0,r11,r20
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v0,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsubfp128 v12,v10,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v60.f32)));
	// vsubfp v0,v9,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vmsum3fp128 v52,v0,v12
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32), 0xEF));
	// vsubfp128 v63,v127,v52
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v52.f32)));
	// vcmpgefp128. v51,v62,v63
	simde_mm_store_ps(v51.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v51.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r3,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b62c4
	if (!cr6.eq) goto loc_824B62C4;
	// vmsum3fp128 v50,v0,v0
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vsubfp128 v61,v50,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128. v49,v62,v61
	simde_mm_store_ps(v49.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b62a0
	if (cr6.eq) goto loc_824B62A0;
	// vaddfp v12,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x824b62c4
	goto loc_824B62C4;
loc_824B62A0:
	// vaddfp128 v48,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vupkd3d128 v47,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v47 = vTemp;
	// vspltw128 v11,v47,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x0));
	// vrefp128 v13,v48
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v48.f32)));
	// vor128 v10,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vnmsubfp v8,v13,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v13,v8,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v63,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v0,v6,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
loc_824B62C4:
	// vaddfp128 v46,v12,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v60.f32)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f30
	cr6.compare(ctx.f11.f64, f30.f64);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f13,f13,f9
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// fsubs f0,f0,f8
	f0.f64 = double(float(f0.f64 - ctx.f8.f64));
	// beq cr6,0x824b6324
	if (cr6.eq) goto loc_824B6324;
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f12,f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f10,f0,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// fdivs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 / ctx.f11.f64));
	// fabs f7,f8
	ctx.f7.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_824B6324:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// lvlx128 v45,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v44,v45,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// lvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v42,v43,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v44.f32)));
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B6340:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r8,192
	ctx.r8.s64 = 192;
	// li r7,224
	ctx.r7.s64 = 224;
	// li r6,320
	ctx.r6.s64 = 320;
	// li r30,272
	r30.s64 = 272;
	// lwz r11,19708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19708);
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v41,r22,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stvx128 v41,r10,r22
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19708);
	// lvx128 v40,r22,r7
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r22
	ctx.r7.u64 = r11.u64 + r22.u64;
	// stvx128 v40,r7,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19708);
	// lfs f0,256(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 256);
	f0.f64 = double(temp.f32);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// stfs f0,352(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 352, temp.u32);
	// lwz r11,19708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19708);
	// lbz r8,268(r22)
	ctx.r8.u64 = PPC_LOAD_U8(r22.u32 + 268);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r22
	ctx.r6.u64 = r11.u64 + r22.u64;
	// stb r8,364(r6)
	PPC_STORE_U8(ctx.r6.u32 + 364, ctx.r8.u8);
	// lwz r11,19708(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19708);
	// lvx128 v39,r0,r26
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r22
	ctx.r10.u64 = r11.u64 + r22.u64;
	// stvx128 v39,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247d680
	ctx.lr = 0x824B6404;
	sub_8247D680(ctx, base);
	// lfs f13,136(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x824b6428
	if (!cr6.lt) goto loc_824B6428;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824c1c58
	ctx.lr = 0x824B6428;
	sub_824C1C58(ctx, base);
loc_824B6428:
	// lfs f0,248(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 248);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x824b644c
	if (!cr6.lt) goto loc_824B644C;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824c1c58
	ctx.lr = 0x824B644C;
	sub_824C1C58(ctx, base);
loc_824B644C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-144(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f30,-136(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_824B6474"))) PPC_WEAK_FUNC(sub_824B6474);
PPC_FUNC_IMPL(__imp__sub_824B6474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B6478"))) PPC_WEAK_FUNC(sub_824B6478);
PPC_FUNC_IMPL(__imp__sub_824B6478) {
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
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x824B6480;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824b6580
	if (cr6.eq) goto loc_824B6580;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r26,192
	r26.s64 = 192;
	// li r27,224
	r27.s64 = 224;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// li r28,320
	r28.s64 = 320;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// li r29,176
	r29.s64 = 176;
	// li r30,272
	r30.s64 = 272;
loc_824B64B8:
	// lfs f0,256(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	f0.f64 = double(temp.f32);
	// lwz r24,0(r4)
	r24.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824b6574
	if (cr6.gt) goto loc_824B6574;
	// lwz r11,19708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19708);
	// lvx128 v63,r4,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stvx128 v63,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19708);
	// lvx128 v62,r4,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r4
	ctx.r8.u64 = r11.u64 + ctx.r4.u64;
	// stvx128 v62,r8,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19708);
	// lfs f0,256(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 256);
	f0.f64 = double(temp.f32);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r4
	ctx.r6.u64 = r11.u64 + ctx.r4.u64;
	// stfs f0,352(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 352, temp.u32);
	// lwz r11,19708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19708);
	// lbz r9,268(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 268);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r4
	ctx.r7.u64 = r11.u64 + ctx.r4.u64;
	// stb r9,364(r7)
	PPC_STORE_U8(ctx.r7.u32 + 364, ctx.r9.u8);
	// lvx128 v61,r4,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 19708);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// stvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247d680
	ctx.lr = 0x824B6574;
	sub_8247D680(ctx, base);
loc_824B6574:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x824b64b8
	if (!cr6.eq) goto loc_824B64B8;
loc_824B6580:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_824B658C"))) PPC_WEAK_FUNC(sub_824B658C);
PPC_FUNC_IMPL(__imp__sub_824B658C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B6590"))) PPC_WEAK_FUNC(sub_824B6590);
PPC_FUNC_IMPL(__imp__sub_824B6590) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	// bl 0x823d91d8
	ctx.lr = 0x824B6598;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lwz r30,0(r21)
	r30.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824b6820
	if (cr6.eq) goto loc_824B6820;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r23,48
	r23.s64 = 48;
	// li r24,416
	r24.s64 = 416;
	// li r27,0
	r27.s64 = 0;
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r20,r11,2288
	r20.s64 = r11.s64 + 2288;
loc_824B65D4:
	// lwz r31,132(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// lwz r25,0(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r29,r30,176
	r29.s64 = r30.s64 + 176;
	// rlwinm r11,r31,29,31,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b6604
	if (cr6.eq) goto loc_824B6604;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824c1c58
	ctx.lr = 0x824B6604;
	sub_824C1C58(ctx, base);
loc_824B6604:
	// rlwinm r11,r31,28,31,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b6624
	if (cr6.eq) goto loc_824B6624;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824c1c58
	ctx.lr = 0x824B6624;
	sub_824C1C58(ctx, base);
loc_824B6624:
	// lfs f0,256(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 256);
	f0.f64 = double(temp.f32);
	// lwz r31,108(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x824b677c
	if (cr6.gt) goto loc_824B677C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b66c4
	if (cr6.eq) goto loc_824B66C4;
	// lwz r11,620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x824b66c0
	if (!cr6.eq) goto loc_824B66C0;
	// lvx128 v62,r29,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b66c4
	if (cr6.eq) goto loc_824B66C4;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwz r9,592(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r8,r9,26,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b66a0
	if (cr6.eq) goto loc_824B66A0;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v59,v61,v63
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B66A0:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82202ec0
	ctx.lr = 0x824B66B0;
	sub_82202EC0(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a188
	ctx.lr = 0x824B66BC;
	sub_8247A188(ctx, base);
	// b 0x824b66c4
	goto loc_824B66C4;
loc_824B66C0:
	// stw r27,108(r28)
	PPC_STORE_U32(r28.u32 + 108, r27.u32);
loc_824B66C4:
	// lwz r31,112(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 112);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b6768
	if (cr6.eq) goto loc_824B6768;
	// lwz r11,620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x824b6764
	if (!cr6.eq) goto loc_824B6764;
	// lvx128 v62,r29,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b6768
	if (cr6.eq) goto loc_824B6768;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lwz r9,592(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 592);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r8,r9,26,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b6734
	if (cr6.eq) goto loc_824B6734;
	// vspltisw128 v58,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vsubfp128 v57,v58,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v56,v58,v63
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B6734:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82202ec0
	ctx.lr = 0x824B6744;
	sub_82202EC0(ctx, base);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8247a188
	ctx.lr = 0x824B6750;
	sub_8247A188(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8247d680
	ctx.lr = 0x824B6760;
	sub_8247D680(ctx, base);
	// b 0x824b6814
	goto loc_824B6814;
loc_824B6764:
	// stw r27,112(r28)
	PPC_STORE_U32(r28.u32 + 112, r27.u32);
loc_824B6768:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8247d680
	ctx.lr = 0x824B6778;
	sub_8247D680(ctx, base);
	// b 0x824b6814
	goto loc_824B6814;
loc_824B677C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b67bc
	if (cr6.eq) goto loc_824B67BC;
	// lwz r11,620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x824b67b8
	if (!cr6.eq) goto loc_824B67B8;
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f13,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
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
	// bl 0x8247a020
	ctx.lr = 0x824B67B4;
	sub_8247A020(ctx, base);
	// stw r27,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r27.u32);
loc_824B67B8:
	// stw r27,108(r28)
	PPC_STORE_U32(r28.u32 + 108, r27.u32);
loc_824B67BC:
	// lwz r31,112(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 112);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b6800
	if (cr6.eq) goto loc_824B6800;
	// lwz r11,620(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 620);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// bne cr6,0x824b67fc
	if (!cr6.eq) goto loc_824B67FC;
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8247a020
	ctx.lr = 0x824B67F8;
	sub_8247A020(ctx, base);
	// stw r27,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r27.u32);
loc_824B67FC:
	// stw r27,112(r28)
	PPC_STORE_U32(r28.u32 + 112, r27.u32);
loc_824B6800:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,368(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 368);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x824b53c0
	ctx.lr = 0x824B6814;
	sub_824B53C0(ctx, base);
loc_824B6814:
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x824b65d4
	if (!cr6.eq) goto loc_824B65D4;
loc_824B6820:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_824B682C"))) PPC_WEAK_FUNC(sub_824B682C);
PPC_FUNC_IMPL(__imp__sub_824B682C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B6830"))) PPC_WEAK_FUNC(sub_824B6830);
PPC_FUNC_IMPL(__imp__sub_824B6830) {
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
	ctx.lr = 0x824B6838;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9c0
	ctx.lr = 0x824B6840;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,228(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 228);
	f0.f64 = double(temp.f32);
	// fmr f23,f1
	f23.f64 = ctx.f1.f64;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,224(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 232);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r16,512(r4)
	r16.u64 = PPC_LOAD_U32(ctx.r4.u32 + 512);
	// addi r26,r5,176
	r26.s64 = ctx.r5.s64 + 176;
	// stfs f2,708(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r25,r26,48
	r25.s64 = r26.s64 + 48;
	// lfs f0,-17424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	f0.f64 = double(temp.f32);
	// mr r15,r8
	r15.u64 = ctx.r8.u64;
	// lfs f10,280(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 280);
	ctx.f10.f64 = double(temp.f32);
	// addi r24,r5,16
	r24.s64 = ctx.r5.s64 + 16;
	// fmuls f22,f10,f10
	f22.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// stb r3,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, ctx.r3.u8);
	// fmuls f9,f23,f0
	ctx.f9.f64 = double(float(f23.f64 * f0.f64));
	// fmadds f8,f12,f12,f13
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fmuls f5,f6,f2
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f2.f64));
	// fcmpu cr6,f5,f9
	cr6.compare(ctx.f5.f64, ctx.f9.f64);
	// ble cr6,0x824b68b0
	if (!cr6.gt) goto loc_824B68B0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, r11.u8);
loc_824B68B0:
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r22,r10,2528
	r22.s64 = ctx.r10.s64 + 2528;
	// lhz r9,4(r16)
	ctx.r9.u64 = PPC_LOAD_U16(r16.u32 + 4);
	// addi r23,r11,2240
	r23.s64 = r11.s64 + 2240;
	// stb r3,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r3.u8);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r3,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r3.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r21,r11,-31648
	r21.s64 = r11.s64 + -31648;
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r20,r10,-31664
	r20.s64 = ctx.r10.s64 + -31664;
	// lvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v62,r0,r21
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v63,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b6e2c
	if (cr6.eq) goto loc_824B6E2C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f26,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f26.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f25,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f25.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f24,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f24.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f27,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f27.f64 = double(temp.f32);
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// lis r5,10381
	ctx.r5.s64 = 680329216;
	// lfs f29,14348(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	f29.f64 = double(temp.f32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f28,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f28.f64 = double(temp.f32);
	// lfs f31,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// ori r31,r6,64167
	r31.u64 = ctx.r6.u64 | 64167;
	// ori r17,r5,61643
	r17.u64 = ctx.r5.u64 | 61643;
	// lis r27,-32115
	r27.s64 = -2104688640;
	// addi r18,r11,20976
	r18.s64 = r11.s64 + 20976;
loc_824B6988:
	// lwz r11,0(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 0);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// li r29,0
	r29.s64 = 0;
	// add r5,r14,r11
	ctx.r5.u64 = r14.u64 + r11.u64;
	// addi r30,r5,64
	r30.s64 = ctx.r5.s64 + 64;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,80(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// stfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f0,68(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,64(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,72(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 * f26.f64));
	// fmadds f10,f0,f25,f11
	ctx.f10.f64 = double(float(f0.f64 * f25.f64 + ctx.f11.f64));
	// fmadds f9,f13,f24,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * f24.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f30
	cr6.compare(ctx.f9.f64, f30.f64);
	// bge cr6,0x824b6e0c
	if (!cr6.lt) goto loc_824B6E0C;
	// lbz r10,113(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// addi r19,r26,16
	r19.s64 = r26.s64 + 16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b6a88
	if (cr6.eq) goto loc_824B6A88;
	// vspltisw128 v56,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v55,r0,r25
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,708
	r11.s64 = ctx.r1.s64 + 708;
	// lvx128 v0,r0,r19
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v63,v0,v0
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// vsubfp128 v13,v56,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lvlx128 v54,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v13,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsubfp128 v53,v63,v0
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r5,48
	ctx.r10.s64 = ctx.r5.s64 + 48;
	// beq cr6,0x824b6a2c
	if (cr6.eq) goto loc_824B6A2C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824B6A2C:
	// addi r9,r5,32
	ctx.r9.s64 = ctx.r5.s64 + 32;
	// addi r8,r5,16
	ctx.r8.s64 = ctx.r5.s64 + 16;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// addi r5,r1,156
	ctx.r5.s64 = ctx.r1.s64 + 156;
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x8261a010
	ctx.lr = 0x824B6A64;
	sub_8261A010(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824b6acc
	if (!cr6.eq) goto loc_824B6ACC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	f0.f64 = double(temp.f32);
	// lvx128 v52,r0,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f13,f23,f0
	ctx.f13.f64 = double(float(f23.f64 - f0.f64));
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824b6ac8
	goto loc_824B6AC8;
loc_824B6A88:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// fmr f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f23.f64;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r10,r1,232
	ctx.r10.s64 = ctx.r1.s64 + 232;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8261b9a0
	ctx.lr = 0x824B6AB4;
	sub_8261B9A0(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x824b6acc
	if (cr6.eq) goto loc_824B6ACC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B6AC8:
	// li r29,1
	r29.s64 = 1;
loc_824B6ACC:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b6e0c
	if (cr6.eq) goto loc_824B6E0C;
	// addi r30,r24,76
	r30.s64 = r24.s64 + 76;
	// lfs f1,80(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// addi r29,r28,372
	r29.s64 = r28.s64 + 372;
	// li r11,1
	r11.s64 = 1;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r15
	ctx.r7.u64 = r15.u64;
	// stb r11,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r11.u8);
	// addi r5,r28,960
	ctx.r5.s64 = r28.s64 + 960;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B6B04;
	sub_824B5638(ctx, base);
	// lbz r10,122(r24)
	ctx.r10.u64 = PPC_LOAD_U8(r24.u32 + 122);
	// lbz r9,1009(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 1009);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfsx f13,r8,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824b6b20
	if (cr6.eq) goto loc_824B6B20;
	// fsubs f13,f31,f13
	ctx.f13.f64 = double(float(f31.f64 - ctx.f13.f64));
loc_824B6B20:
	// lfs f0,304(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	f0.f64 = double(temp.f32);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lfs f12,308(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f12.f64 = double(temp.f32);
	// mr r7,r15
	ctx.r7.u64 = r15.u64;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r5,r28,1012
	ctx.r5.s64 = r28.s64 + 1012;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lfs f1,80(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmadds f10,f11,f13,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// fnmsubs f9,f10,f28,f31
	ctx.f9.f64 = double(float(-(ctx.f10.f64 * f28.f64 - f31.f64)));
	// stfs f9,160(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x824b5638
	ctx.lr = 0x824B6B54;
	sub_824B5638(ctx, base);
	// lbz r11,121(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 121);
	// lbz r10,1061(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1061);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfsx f0,r9,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b6b70
	if (cr6.eq) goto loc_824B6B70;
	// fsubs f0,f31,f0
	f0.f64 = double(float(f31.f64 - f0.f64));
loc_824B6B70:
	// lfs f13,320(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,324(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f0,f11,f0,f13
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x824b6ce8
	if (cr6.eq) goto loc_824B6CE8;
	// lwz r11,19736(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 19736);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r30,r1,176
	r30.s64 = ctx.r1.s64 + 176;
	// lfs f12,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lfs f11,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r1,148
	ctx.r5.s64 = ctx.r1.s64 + 148;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulld r9,r3,r31
	ctx.r9.s64 = ctx.r3.s64 * r31.s64;
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f8,f0,f13
	ctx.f8.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 - ctx.f13.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rotlwi r8,r10,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rldicl r9,r10,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// mulld r8,r8,r31
	ctx.r8.s64 = ctx.r8.s64 * r31.s64;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r4,r10,9
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFF;
	// rotlwi r3,r9,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rldicl r8,r9,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r3,r31
	ctx.r10.s64 = ctx.r3.s64 * r31.s64;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// clrlwi r3,r9,9
	ctx.r3.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// clrlwi r9,r10,9
	ctx.r9.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r3,224(r1)
	PPC_STORE_U64(ctx.r1.u32 + 224, ctx.r3.u64);
	// std r8,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r8.u64);
	// lfd f4,192(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 192);
	// std r9,296(r1)
	PPC_STORE_U64(ctx.r1.u32 + 296, ctx.r9.u64);
	// lfd f5,296(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 296);
	// lfd f6,224(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f2,f6
	ctx.f2.f64 = double(ctx.f6.s64);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// fcfid f1,f5
	ctx.f1.f64 = double(ctx.f5.s64);
	// frsp f6,f2
	ctx.f6.f64 = double(float(ctx.f2.f64));
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// frsp f0,f3
	f0.f64 = double(float(ctx.f3.f64));
	// frsp f5,f1
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// fmuls f3,f8,f6
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fmuls f4,f9,f0
	ctx.f4.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f2,f7,f5
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f5.f64));
	// fmadds f0,f3,f29,f13
	f0.f64 = double(float(ctx.f3.f64 * f29.f64 + ctx.f13.f64));
	// stfs f0,180(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmadds f1,f4,f29,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * f29.f64 + ctx.f13.f64));
	// stfs f1,176(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmadds f13,f2,f29,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * f29.f64 + ctx.f13.f64));
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,244(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f7,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f7,f11,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f4,f6,f10,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f10.f64 + ctx.f5.f64));
	// fmuls f3,f4,f27
	ctx.f3.f64 = double(float(ctx.f4.f64 * f27.f64));
	// stfs f3,148(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvlx128 v50,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v50,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmulfp128 v48,v62,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v49.f32)));
	// vsubfp128 v63,v63,v48
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v48.f32)));
	// vaddfp128 v47,v62,v63
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v46,v47,v47
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v47.f32), 0xEF));
	// vrsqrtefp128 v45,v46
	simde_mm_store_ps(v45.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v46.f32))));
	// vor128 v12,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vcmpeqfp128 v11,v45,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v10,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v44,v47,v6
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B6CE8:
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// lvx128 v43,r0,r25
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// addi r10,r1,148
	ctx.r10.s64 = ctx.r1.s64 + 148;
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f12,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// vor128 v42,v43,v43
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v41,r0,r9
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v40,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v39,v40,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// lfs f10,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f7,280(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f8,f11,f13,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f6,f7,f12,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fmuls f5,f6,f27
	ctx.f5.f64 = double(float(ctx.f6.f64 * f27.f64));
	// stfs f5,148(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvlx128 v38,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v37,v38,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// vmulfp128 v36,v41,v37
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v37.f32)));
	// vsubfp128 v35,v42,v36
	simde_mm_store_ps(v35.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v36.f32)));
	// vor128 v34,v35,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// stvx128 v35,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v33,v34,v39
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v33,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,0(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f1,f2,f2
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// fmadds f0,f4,f4,f1
	f0.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f1.f64));
	// fmadds f13,f3,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + f0.f64));
	// fcmpu cr6,f13,f22
	cr6.compare(ctx.f13.f64, f22.f64);
	// bge cr6,0x824b6d90
	if (!cr6.lt) goto loc_824B6D90;
	// vspltisw128 v32,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v32,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,116(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 116);
	// ori r10,r11,2
	ctx.r10.u64 = r11.u64 | 2;
	// stw r10,116(r24)
	PPC_STORE_U32(r24.u32 + 116, ctx.r10.u32);
loc_824B6D90:
	// lwz r11,284(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 284);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b6dec
	if (cr6.eq) goto loc_824B6DEC;
	// lwz r11,19736(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 19736);
	// lbz r8,307(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 307);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r7,r31
	ctx.r9.s64 = ctx.r7.s64 * r31.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r6,r10,1
	ctx.r6.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// mulhw r4,r6,r17
	ctx.r4.s64 = (int64_t(ctx.r6.s32) * int64_t(r17.s32)) >> 32;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// srawi r9,r4,4
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 4;
	// rlwinm r10,r9,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mulli r10,r11,101
	ctx.r10.s64 = r11.s64 * 101;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bgt cr6,0x824b6dec
	if (cr6.gt) goto loc_824B6DEC;
	// stfs f31,80(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 80, temp.u32);
loc_824B6DEC:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r0,r19
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v12,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B6E0C:
	// lwz r11,152(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// addi r14,r14,96
	r14.s64 = r14.s64 + 96;
	// lhz r10,4(r16)
	ctx.r10.u64 = PPC_LOAD_U16(r16.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x824b6988
	if (cr6.lt) goto loc_824B6988;
	// lbz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
loc_824B6E2C:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba0c
	ctx.lr = 0x824B6E38;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824B6E3C"))) PPC_WEAK_FUNC(sub_824B6E3C);
PPC_FUNC_IMPL(__imp__sub_824B6E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B6E40"))) PPC_WEAK_FUNC(sub_824B6E40);
PPC_FUNC_IMPL(__imp__sub_824B6E40) {
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824B6E48;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d0
	ctx.lr = 0x824B6E50;
	// addi r12,r1,-208
	r12.s64 = ctx.r1.s64 + -208;
	// bl 0x823dd524
	ctx.lr = 0x824B6E58;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r9,19708(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 19708);
	// lbz r11,2(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r24
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r24.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x824b74c0
	if (cr6.eq) goto loc_824B74C0;
	// lbz r11,2(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r7,624(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 624);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r5,r11,5
	ctx.r5.s64 = r11.s64 + 5;
	// lfs f30,500(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 500);
	f30.f64 = double(temp.f32);
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// lwz r19,136(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + 136);
	// addi r8,r6,8464
	ctx.r8.s64 = ctx.r6.s64 + 8464;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// vupkd3d128 v63,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// rlwinm r6,r5,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// lfs f0,27644(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27644);
	f0.f64 = double(temp.f32);
	// add r5,r11,r7
	ctx.r5.u64 = r11.u64 + ctx.r7.u64;
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r4,r27,176
	ctx.r4.s64 = r27.s64 + 176;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lvx128 v123,r0,r8
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfsx f29,r6,r24
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r24.u32);
	f29.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f26,676(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 676);
	f26.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// vpermwi128 v126,v63,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// vpermwi128 v125,v63,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// addi r3,r7,-29952
	ctx.r3.s64 = ctx.r7.s64 + -29952;
	// lfs f27,15364(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 15364);
	f27.f64 = double(temp.f32);
	// lfs f28,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f28.f64 = double(temp.f32);
	// addi r18,r27,436
	r18.s64 = r27.s64 + 436;
	// lfs f31,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// vpermwi128 v124,v63,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// addi r17,r30,1168
	r17.s64 = r30.s64 + 1168;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// addi r16,r30,1220
	r16.s64 = r30.s64 + 1220;
	// addi r15,r30,1376
	r15.s64 = r30.s64 + 1376;
	// addi r14,r30,1428
	r14.s64 = r30.s64 + 1428;
	// addi r25,r30,372
	r25.s64 = r30.s64 + 372;
	// li r21,16
	r21.s64 = 16;
	// addi r20,r11,6144
	r20.s64 = r11.s64 + 6144;
	// addi r22,r8,20976
	r22.s64 = ctx.r8.s64 + 20976;
	// b 0x824b6f50
	goto loc_824B6F50;
loc_824B6F48:
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r9,19708(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 19708);
loc_824B6F50:
	// lbz r11,2(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 2);
	// addi r31,r10,16
	r31.s64 = ctx.r10.s64 + 16;
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r23,r6,r10
	r23.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// addi r29,r11,272
	r29.s64 = r11.s64 + 272;
	// dcbt r0,r23
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,224(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 224);
	// lvx128 v62,r0,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v122,r29,r21
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824B6FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r11,284(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// vmulfp128 v60,v61,v123
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v123.f32)));
	// rlwinm r6,r11,25,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,80(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824b5728
	ctx.lr = 0x824B6FE4;
	sub_824B5728(ctx, base);
	// lwz r10,236(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 236);
	// rlwinm r6,r10,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// rlwinm r5,r10,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// std r6,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r6.u64);
	// lfd f8,352(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 352);
	// std r5,304(r1)
	PPC_STORE_U64(ctx.r1.u32 + 304, ctx.r5.u64);
	// lfd f7,304(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 304);
	// std r4,360(r1)
	PPC_STORE_U64(ctx.r1.u32 + 360, ctx.r4.u64);
	// lfd f6,360(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 360);
	// rlwinm r11,r10,8,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r31,76
	r28.s64 = r31.s64 + 76;
	// std r11,368(r1)
	PPC_STORE_U64(ctx.r1.u32 + 368, r11.u64);
	// lfd f5,368(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 368);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// fcfid f2,f8
	ctx.f2.f64 = double(ctx.f8.s64);
	// lfs f10,496(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 496);
	ctx.f10.f64 = double(temp.f32);
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lfs f9,432(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 432);
	ctx.f9.f64 = double(temp.f32);
	// fcfid f8,f7
	ctx.f8.f64 = double(ctx.f7.s64);
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// fcfid f7,f6
	ctx.f7.f64 = double(ctx.f6.s64);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// frsp f5,f2
	ctx.f5.f64 = double(float(ctx.f2.f64));
	// fmuls f6,f3,f0
	ctx.f6.f64 = double(float(ctx.f3.f64 * f0.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// fmuls f0,f5,f13
	f0.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f2,f6,f27
	ctx.f2.f64 = double(float(ctx.f6.f64 * f27.f64));
	// fmuls f13,f4,f12
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f12,f3,f11
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fmuls f11,f2,f10
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// fmuls f10,f0,f27
	ctx.f10.f64 = double(float(f0.f64 * f27.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f8,f13,f27
	ctx.f8.f64 = double(float(ctx.f13.f64 * f27.f64));
	// stfs f8,84(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f7,f12,f27
	ctx.f7.f64 = double(float(ctx.f12.f64 * f27.f64));
	// fmuls f6,f11,f9
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// stfs f7,88(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f6,92(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x824b58b0
	ctx.lr = 0x824B70A4;
	sub_824B58B0(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r7,284(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r6,r7,29,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b710c
	if (cr6.eq) goto loc_824B710C;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f0,400(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 400);
	f0.f64 = double(temp.f32);
	// lfs f13,404(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 404);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f12,408(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 408);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v56,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B710C:
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lfs f1,80(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B7128;
	sub_824B5638(ctx, base);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lfs f1,80(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B7144;
	sub_824B5638(ctx, base);
	// lbz r10,137(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 137);
	// lbz r11,1217(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1217);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfsx f13,r9,r22
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r22.u32);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824b7160
	if (cr6.eq) goto loc_824B7160;
	// fsubs f13,f31,f13
	ctx.f13.f64 = double(float(f31.f64 - ctx.f13.f64));
loc_824B7160:
	// lfs f12,256(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f12.f64 = double(temp.f32);
	// lbz r10,138(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 138);
	// lfs f0,336(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfs f10,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f0,r9,r22
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r22.u32);
	f0.f64 = double(temp.f32);
	// fmadds f9,f11,f13,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// stfs f7,272(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// beq cr6,0x824b7198
	if (cr6.eq) goto loc_824B7198;
	// fsubs f0,f31,f0
	f0.f64 = double(float(f31.f64 - f0.f64));
loc_824B7198:
	// lfs f12,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// lbz r10,139(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 139);
	// lfs f13,340(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f13,r9,r22
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r22.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f11,f0,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// stfs f7,276(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// beq cr6,0x824b71d0
	if (cr6.eq) goto loc_824B71D0;
	// fsubs f13,f31,f13
	ctx.f13.f64 = double(float(f31.f64 - ctx.f13.f64));
loc_824B71D0:
	// lfs f0,264(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	f0.f64 = double(temp.f32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lfs f12,344(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	ctx.f12.f64 = double(temp.f32);
	// vor128 v62,v126,v126
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vor128 v61,v125,v125
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lfs f10,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stw r5,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r5.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// vor128 v60,v124,v124
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// fmadds f9,f11,f13,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// fmuls f8,f9,f30
	ctx.f8.f64 = double(float(ctx.f9.f64 * f30.f64));
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// stfs f7,280(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v55,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v54,v61,v63
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v53,v60,v63
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824b5638
	ctx.lr = 0x824B726C;
	sub_824B5638(ctx, base);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B7288;
	sub_824B5638(ctx, base);
	// lbz r8,136(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 136);
	// lbz r11,1425(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1425);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfsx f0,r7,r22
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r22.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b72a8
	if (cr6.eq) goto loc_824B72A8;
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// b 0x824b72ac
	goto loc_824B72AC;
loc_824B72A8:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_824B72AC:
	// lfs f12,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f11,f13,f28,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f28.f64 + ctx.f12.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// beq cr6,0x824b72c8
	if (cr6.eq) goto loc_824B72C8;
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// b 0x824b72cc
	goto loc_824B72CC;
loc_824B72C8:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_824B72CC:
	// lfs f12,292(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f11,f13,f28,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f28.f64 + ctx.f12.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// beq cr6,0x824b72e4
	if (cr6.eq) goto loc_824B72E4;
	// fsubs f0,f31,f0
	f0.f64 = double(float(f31.f64 - f0.f64));
loc_824B72E4:
	// addi r11,r1,124
	r11.s64 = ctx.r1.s64 + 124;
	// lfs f13,296(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmadds f12,f0,f28,f13
	ctx.f12.f64 = double(float(f0.f64 * f28.f64 + ctx.f13.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f11,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v49,v50,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// fadds f1,f11,f10
	ctx.f1.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// bl 0x82235e30
	ctx.lr = 0x824B7324;
	sub_82235E30(ctx, base);
	// lfs f9,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f8,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fadds f1,f8,f9
	ctx.f1.f64 = double(float(ctx.f8.f64 + ctx.f9.f64));
	// bl 0x82204cb8
	ctx.lr = 0x824B7338;
	sub_82204CB8(ctx, base);
	// lfs f7,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fadds f1,f6,f7
	ctx.f1.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// bl 0x82235ee0
	ctx.lr = 0x824B734C;
	sub_82235EE0(ctx, base);
	// lfs f5,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lfs f4,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f4.f64 = double(temp.f32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f3,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// stfs f5,320(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f4,324(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f3,328(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// lfs f1,12(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82350940
	ctx.lr = 0x824B7374;
	sub_82350940(ctx, base);
	// lwz r8,284(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 284);
	// rlwinm r7,r8,20,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 20) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x824b7410
	if (cr6.eq) goto loc_824B7410;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v48,v63,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v47,v62,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vspltw128 v46,v61,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v0,r11,r21
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v45,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v48.f32)));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v9,v45,v47
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v47.f32)));
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmulfp128 v7,v45,v46
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32)));
	// vspltw128 v6,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v5,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v4,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// vmaddfp v3,v0,v12,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v2,v0,v10,v9
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v1,v0,v8,v7
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v31,v13,v6,v3
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v30,v13,v5,v2
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v29,v13,v4,v1
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// stvx128 v31,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B7410:
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// lwz r3,1688(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1688);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b7454
	if (cr6.eq) goto loc_824B7454;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// li r6,5
	ctx.r6.s64 = 5;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lfs f11,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x824B7454;
	sub_8218AEF8(ctx, base);
loc_824B7454:
	// lbz r11,92(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 92);
	// lwz r10,360(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 360);
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x824b74b4
	if (cr6.eq) goto loc_824B74B4;
	// li r31,0
	r31.s64 = 0;
loc_824B7474:
	// lbz r11,92(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 92);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,360(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 360);
	// li r6,0
	ctx.r6.s64 = 0;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x824B74A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// blt cr6,0x824b7474
	if (cr6.lt) goto loc_824B7474;
loc_824B74B4:
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x824b6f48
	if (!cr6.eq) goto loc_824B6F48;
loc_824B74C0:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-208
	r12.s64 = ctx.r1.s64 + -208;
	// bl 0x823dd7bc
	ctx.lr = 0x824B74CC;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba1c
	ctx.lr = 0x824B74D4;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824B74D8"))) PPC_WEAK_FUNC(sub_824B74D8);
PPC_FUNC_IMPL(__imp__sub_824B74D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,368(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// b 0x824b5488
	sub_824B5488(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_824B74F4"))) PPC_WEAK_FUNC(sub_824B74F4);
PPC_FUNC_IMPL(__imp__sub_824B74F4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B74F8"))) PPC_WEAK_FUNC(sub_824B74F8);
PPC_FUNC_IMPL(__imp__sub_824B74F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r4
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_824B7504:
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r11,r7,-4
	r11.s64 = ctx.r7.s64 + -4;
loc_824B7510:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,88(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	// lwz r5,88(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x824b752c
	if (cr6.lt) goto loc_824B752C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824B752C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b7548
	if (cr6.eq) goto loc_824B7548;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// b 0x824b7510
	goto loc_824B7510;
loc_824B7548:
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// cmplw cr6,r7,r4
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r4.u32, xer);
	// bne cr6,0x824b7504
	if (!cr6.eq) goto loc_824B7504;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B755C"))) PPC_WEAK_FUNC(sub_824B755C);
PPC_FUNC_IMPL(__imp__sub_824B755C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B7560"))) PPC_WEAK_FUNC(sub_824B7560);
PPC_FUNC_IMPL(__imp__sub_824B7560) {
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
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x824b75e8
	if (!cr6.lt) goto loc_824B75E8;
loc_824B7588:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,88(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	// lwz r10,88(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x824b75b0
	if (cr6.lt) goto loc_824B75B0;
	// li r10,0
	ctx.r10.s64 = 0;
loc_824B75B0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b75c0
	if (cr6.eq) goto loc_824B75C0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_824B75C0:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwzx r10,r10,r3
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// stwx r10,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r10.u32);
	// blt cr6,0x824b7588
	if (cr6.lt) goto loc_824B7588;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
loc_824B75E8:
	// bne cr6,0x824b7604
	if (!cr6.eq) goto loc_824B7604;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r3
	ctx.r8.u64 = ctx.r10.u64 + ctx.r3.u64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// stwx r11,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, r11.u32);
loc_824B7604:
	// bl 0x824b55c8
	ctx.lr = 0x824B7608;
	sub_824B55C8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_824B761C"))) PPC_WEAK_FUNC(sub_824B761C);
PPC_FUNC_IMPL(__imp__sub_824B761C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B7620"))) PPC_WEAK_FUNC(sub_824B7620);
PPC_FUNC_IMPL(__imp__sub_824B7620) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// rotlwi r6,r30,0
	ctx.r6.u64 = __builtin_rotateleft32(r30.u32, 0);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// ori r5,r6,32
	ctx.r5.u64 = ctx.r6.u64 | 32;
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// lfs f13,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// rotlwi r4,r30,0
	ctx.r4.u64 = __builtin_rotateleft32(r30.u32, 0);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// stw r5,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r5.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// ori r11,r4,32
	r11.u64 = ctx.r4.u64 | 32;
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stw r7,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r7.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// bl 0x821b5a60
	ctx.lr = 0x824B76CC;
	sub_821B5A60(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,108(r31)
	PPC_STORE_U8(r31.u32 + 108, r30.u8);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
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

__attribute__((alias("__imp__sub_824B7700"))) PPC_WEAK_FUNC(sub_824B7700);
PPC_FUNC_IMPL(__imp__sub_824B7700) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824B7708;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82619428
	ctx.lr = 0x824B771C;
	sub_82619428(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// addi r10,r11,8492
	ctx.r10.s64 = r11.s64 + 8492;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824b7620
	ctx.lr = 0x824B7730;
	sub_824B7620(ctx, base);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x824b7620
	ctx.lr = 0x824B7738;
	sub_824B7620(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r11,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r11.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r11,274(r31)
	PPC_STORE_U8(r31.u32 + 274, r11.u8);
	// stb r11,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r11.u8);
	// stfs f31,264(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// stw r8,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r8.u32);
	// addi r3,r31,296
	ctx.r3.s64 = r31.s64 + 296;
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// addi r5,r7,9572
	ctx.r5.s64 = ctx.r7.s64 + 9572;
	// stw r30,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r30.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stw r30,292(r31)
	PPC_STORE_U32(r31.u32 + 292, r30.u32);
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r11,r31,284
	r11.s64 = r31.s64 + 284;
	// bl 0x82137a08
	ctx.lr = 0x824B7790;
	sub_82137A08(ctx, base);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,8480(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8480);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x824c1bf8
	ctx.lr = 0x824B77A8;
	sub_824C1BF8(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r4,100
	ctx.r4.s64 = 100;
	// stfs f31,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stw r30,284(r31)
	PPC_STORE_U32(r31.u32 + 284, r30.u32);
	// stw r30,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r30.u32);
	// stb r4,306(r31)
	PPC_STORE_U8(r31.u32 + 306, ctx.r4.u8);
	// stb r30,307(r31)
	PPC_STORE_U8(r31.u32 + 307, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824B77DC"))) PPC_WEAK_FUNC(sub_824B77DC);
PPC_FUNC_IMPL(__imp__sub_824B77DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B77E0"))) PPC_WEAK_FUNC(sub_824B77E0);
PPC_FUNC_IMPL(__imp__sub_824B77E0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,296
	ctx.r3.s64 = ctx.r3.s64 + 296;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B77E8"))) PPC_WEAK_FUNC(sub_824B77E8);
PPC_FUNC_IMPL(__imp__sub_824B77E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B77F0"))) PPC_WEAK_FUNC(sub_824B77F0);
PPC_FUNC_IMPL(__imp__sub_824B77F0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,292(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 292);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B77F8"))) PPC_WEAK_FUNC(sub_824B77F8);
PPC_FUNC_IMPL(__imp__sub_824B77F8) {
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
	// addi r30,r3,292
	r30.s64 = ctx.r3.s64 + 292;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82477b78
	ctx.lr = 0x824B781C;
	sub_82477B78(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b7834
	if (cr6.eq) goto loc_824B7834;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2a58
	ctx.lr = 0x824B7834;
	sub_821D2A58(ctx, base);
loc_824B7834:
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

__attribute__((alias("__imp__sub_824B784C"))) PPC_WEAK_FUNC(sub_824B784C);
PPC_FUNC_IMPL(__imp__sub_824B784C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B7850"))) PPC_WEAK_FUNC(sub_824B7850);
PPC_FUNC_IMPL(__imp__sub_824B7850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,276(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B7858"))) PPC_WEAK_FUNC(sub_824B7858);
PPC_FUNC_IMPL(__imp__sub_824B7858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,20972(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20972);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B7864"))) PPC_WEAK_FUNC(sub_824B7864);
PPC_FUNC_IMPL(__imp__sub_824B7864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824B7868"))) PPC_WEAK_FUNC(sub_824B7868);
PPC_FUNC_IMPL(__imp__sub_824B7868) {
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
	// bl 0x824c1850
	ctx.lr = 0x824B7888;
	sub_824C1850(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b78a0
	if (cr6.eq) goto loc_824B78A0;
	// bl 0x82130588
	ctx.lr = 0x824B789C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824B78A0:
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

__attribute__((alias("__imp__sub_824B78B8"))) PPC_WEAK_FUNC(sub_824B78B8);
PPC_FUNC_IMPL(__imp__sub_824B78B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 284, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B78C8"))) PPC_WEAK_FUNC(sub_824B78C8);
PPC_FUNC_IMPL(__imp__sub_824B78C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,368(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824b78dc
	if (!cr6.eq) goto loc_824B78DC;
	// blr 
	return;
loc_824B78DC:
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// stw r6,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r6.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b790c
	if (cr6.eq) goto loc_824B790C;
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
loc_824B790C:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// stw r9,28(r4)
	PPC_STORE_U32(ctx.r4.u32 + 28, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824B7930"))) PPC_WEAK_FUNC(sub_824B7930);
PPC_FUNC_IMPL(__imp__sub_824B7930) {
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824B7938;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9b8
	ctx.lr = 0x824B7940;
	// addi r12,r1,-256
	r12.s64 = ctx.r1.s64 + -256;
	// bl 0x823dd52c
	ctx.lr = 0x824B7948;
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stfs f28,900(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 900, temp.u32);
	// addi r26,r11,6144
	r26.s64 = r11.s64 + 6144;
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stw r26,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r26.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r5,r7,8464
	ctx.r5.s64 = ctx.r7.s64 + 8464;
	// lwz r24,224(r29)
	r24.u64 = PPC_LOAD_U32(r29.u32 + 224);
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// addi r30,r25,436
	r30.s64 = r25.s64 + 436;
	// lfs f31,128(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 128);
	f31.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lvx128 v124,r0,r5
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// stw r25,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, r25.u32);
	// stw r29,884(r1)
	PPC_STORE_U32(ctx.r1.u32 + 884, r29.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stw r24,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r24.u32);
	// bl 0x824b2ff0
	ctx.lr = 0x824B79D4;
	sub_824B2FF0(ctx, base);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// bl 0x824b30e8
	ctx.lr = 0x824B79EC;
	sub_824B30E8(ctx, base);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824b31e0
	ctx.lr = 0x824B7A04;
	sub_824B31E0(ctx, base);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lfs f0,500(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 500);
	f0.f64 = double(temp.f32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lwz r11,512(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 512);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// fmr f22,f0
	f22.f64 = f0.f64;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// fmr f21,f0
	f21.f64 = f0.f64;
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v60,v124
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v124.f32)));
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v56,v59,v124
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v124.f32)));
	// vmulfp128 v55,v57,v124
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v124.f32)));
	// fmr f23,f0
	ctx.fpscr.disableFlushModeUnconditional();
	f23.f64 = f0.f64;
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stfs f22,144(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f21,148(r1)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f23,152(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b7a7c
	if (cr6.eq) goto loc_824B7A7C;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824b7a80
	if (!cr6.eq) goto loc_824B7A80;
loc_824B7A7C:
	// li r11,0
	r11.s64 = 0;
loc_824B7A80:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f27,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824b7ab8
	if (cr6.eq) goto loc_824B7AB8;
	// lfs f0,276(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 276);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x824b7ab0
	if (cr6.eq) goto loc_824B7AB0;
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x824b7ab8
	if (!cr6.gt) goto loc_824B7AB8;
loc_824B7AB0:
	// li r11,1
	r11.s64 = 1;
	// b 0x824b7abc
	goto loc_824B7ABC;
loc_824B7AB8:
	// li r11,0
	r11.s64 = 0;
loc_824B7ABC:
	// lfs f0,276(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 276);
	f0.f64 = double(temp.f32);
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824b7ad4
	if (cr6.eq) goto loc_824B7AD4;
	// li r11,0
	r11.s64 = 0;
loc_824B7AD4:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,276(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 276);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r11,28,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// fmuls f20,f0,f0
	f20.f64 = double(float(f0.f64 * f0.f64));
	// stb r10,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f29,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f29.f64 = double(temp.f32);
	// beq cr6,0x824b7b04
	if (cr6.eq) goto loc_824B7B04;
	// stfs f27,208(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// b 0x824b7b08
	goto loc_824B7B08;
loc_824B7B04:
	// stfs f29,208(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
loc_824B7B08:
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b7b1c
	if (cr6.eq) goto loc_824B7B1C;
	// stfs f27,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// b 0x824b7b20
	goto loc_824B7B20;
loc_824B7B1C:
	// stfs f29,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
loc_824B7B20:
	// rlwinm r11,r11,26,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b7b34
	if (cr6.eq) goto loc_824B7B34;
	// stfs f27,216(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// b 0x824b7b38
	goto loc_824B7B38;
loc_824B7B34:
	// stfs f29,216(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
loc_824B7B38:
	// lwz r11,224(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 224);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// lwz r11,44(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x824b7b74
	if (!cr6.eq) goto loc_824B7B74;
	// addi r11,r11,176
	r11.s64 = r11.s64 + 176;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// lvx128 v125,r11,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r11,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824b7b84
	goto loc_824B7B84;
loc_824B7B74:
	// addi r11,r1,496
	r11.s64 = ctx.r1.s64 + 496;
	// addi r10,r1,464
	ctx.r10.s64 = ctx.r1.s64 + 464;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B7B84:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824b86d8
	if (cr6.eq) goto loc_824B86D8;
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lvx128 v123,r0,r9
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f24,-12080(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12080);
	f24.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f25,8456(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8456);
	f25.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lfs f26,18204(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 18204);
	f26.f64 = double(temp.f32);
	// addi r5,r11,-23776
	ctx.r5.s64 = r11.s64 + -23776;
	// addi r4,r10,-31664
	ctx.r4.s64 = ctx.r10.s64 + -31664;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stw r5,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r5.u32);
	// addi r3,r9,-31648
	ctx.r3.s64 = ctx.r9.s64 + -31648;
	// stw r4,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r4.u32);
	// addi r11,r8,2240
	r11.s64 = ctx.r8.s64 + 2240;
	// addi r10,r7,2528
	ctx.r10.s64 = ctx.r7.s64 + 2528;
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// addi r20,r27,372
	r20.s64 = r27.s64 + 372;
	// stw r11,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r11.u32);
	// li r14,192
	r14.s64 = 192;
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// li r15,224
	r15.s64 = 224;
	// li r16,320
	r16.s64 = 320;
	// li r17,272
	r17.s64 = 272;
	// lis r23,-32115
	r23.s64 = -2104688640;
	// addi r18,r6,20976
	r18.s64 = ctx.r6.s64 + 20976;
loc_824B7C08:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r29,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r29.u32);
loc_824B7C14:
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// dcbt r0,r10
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// cmplwi cr6,r11,464
	cr6.compare<uint32_t>(r11.u32, 464, xer);
	// blt cr6,0x824b7c14
	if (cr6.lt) goto loc_824B7C14;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lfs f30,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	f30.f64 = double(temp.f32);
	// addi r5,r27,752
	ctx.r5.s64 = r27.s64 + 752;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r21,r30,76
	r21.s64 = r30.s64 + 76;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// addi r28,r31,176
	r28.s64 = r31.s64 + 176;
	// bl 0x824b5638
	ctx.lr = 0x824B7C54;
	sub_824B5638(ctx, base);
	// lbz r11,145(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 145);
	// lbz r9,801(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 801);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfsx f31,r10,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r18.u32);
	f31.f64 = double(temp.f32);
	// beq cr6,0x824b7c70
	if (cr6.eq) goto loc_824B7C70;
	// fsubs f31,f29,f31
	f31.f64 = double(float(f29.f64 - f31.f64));
loc_824B7C70:
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// lvx128 v54,r0,r26
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r25,436
	ctx.r6.s64 = r25.s64 + 436;
	// lfs f1,100(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824b2d40
	ctx.lr = 0x824B7C94;
	sub_824B2D40(ctx, base);
	// lfs f0,416(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	f0.f64 = double(temp.f32);
	// lfs f13,420(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,68(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 68);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// lvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v52,v53,v124
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v124.f32)));
	// fmadds f10,f12,f31,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,136(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f12,f9,f28
	ctx.f12.f64 = double(float(ctx.f9.f64 * f28.f64));
	// fadds f13,f30,f12
	ctx.f13.f64 = double(float(f30.f64 + ctx.f12.f64));
	// stfs f13,80(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 80, temp.u32);
	// bgt cr6,0x824b7cec
	if (cr6.gt) goto loc_824B7CEC;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x824b7cec
	if (!cr6.lt) goto loc_824B7CEC;
	// fcmpu cr6,f12,f27
	cr6.compare(ctx.f12.f64, f27.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x824b7cf0
	if (cr6.gt) goto loc_824B7CF0;
loc_824B7CEC:
	// li r11,0
	r11.s64 = 0;
loc_824B7CF0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r10,116(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lfs f0,248(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 248);
	f0.f64 = double(temp.f32);
	// addi r19,r30,116
	r19.s64 = r30.s64 + 116;
	// neg r8,r11
	ctx.r8.s64 = -r11.s64;
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// xor r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// stw r5,116(r30)
	PPC_STORE_U32(r30.u32 + 116, ctx.r5.u32);
	// bgt cr6,0x824b7d38
	if (cr6.gt) goto loc_824B7D38;
	// lfs f13,80(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x824b7d38
	if (!cr6.lt) goto loc_824B7D38;
	// fcmpu cr6,f12,f27
	cr6.compare(ctx.f12.f64, f27.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x824b7d3c
	if (cr6.gt) goto loc_824B7D3C;
loc_824B7D38:
	// li r11,0
	r11.s64 = 0;
loc_824B7D3C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lfs f31,80(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	f31.f64 = double(temp.f32);
	// neg r8,r11
	ctx.r8.s64 = -r11.s64;
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// xor r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r10.u64;
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// stw r5,0(r19)
	PPC_STORE_U32(r19.u32 + 0, ctx.r5.u32);
	// bgt cr6,0x824b86cc
	if (cr6.gt) goto loc_824B86CC;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824dd3e8
	ctx.lr = 0x824B7D80;
	sub_824DD3E8(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lwz r8,284(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// rlwinm r7,r8,17,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 17) & 0x1;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v51,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b7db8
	if (cr6.eq) goto loc_824B7DB8;
	// vmulfp128 v49,v63,v123
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v123.f32)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B7DB8:
	// stfs f27,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824dd4d0
	ctx.lr = 0x824B7DD8;
	sub_824DD4D0(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lwz r8,284(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rlwinm r7,r8,22,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 22) & 0x1;
	// addi r26,r25,176
	r26.s64 = r25.s64 + 176;
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r25,368
	r25.s64 = r25.s64 + 368;
	// lvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// vmulfp128 v46,v48,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v46,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x824b7ea0
	if (!cr6.eq) goto loc_824B7EA0;
	// li r11,32
	r11.s64 = 32;
	// lvx128 v45,r0,r26
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// li r9,16
	ctx.r9.s64 = 16;
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f12,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v44,r26,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r26,r10
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v42,v45,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// lvx128 v41,r26,r9
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v40,v45,v44
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v39,v41,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// vmrglw128 v38,v41,v43
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f27,140(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vmrghw128 v37,v42,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v36,v40,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v35,v42,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmsum3fp128 v34,v63,v37
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vmsum3fp128 v33,v63,v36
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// vmsum3fp128 v32,v63,v35
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vmrghw128 v63,v34,v33
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v62,v32,v63
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v61,v63,v62
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// lfs f11,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
loc_824B7EA0:
	// addi r11,r1,900
	r11.s64 = ctx.r1.s64 + 900;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r29,r28,48
	r29.s64 = r28.s64 + 48;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// vspltw128 v0,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// vmaddfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824dd5c0
	ctx.lr = 0x824B7EE0;
	sub_824DD5C0(ctx, base);
	// lwz r9,284(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// rlwinm r8,r9,23,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 23) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824b7f7c
	if (!cr6.eq) goto loc_824B7F7C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// vspltisw128 v58,-1
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// li r7,32
	ctx.r7.s64 = 32;
	// lvlx128 v57,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vslw128 v56,v58,v58
	v56.u32[0] = v58.u32[0] << (v58.u8[0] & 0x1F);
	v56.u32[1] = v58.u32[1] << (v58.u8[4] & 0x1F);
	v56.u32[2] = v58.u32[2] << (v58.u8[8] & 0x1F);
	v56.u32[3] = v58.u32[3] << (v58.u8[12] & 0x1F);
	// lvlx128 v55,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v57,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v53,v55,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v52,r26,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v51,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vslw128 v50,v58,v58
	v50.u32[0] = v58.u32[0] << (v58.u8[0] & 0x1F);
	v50.u32[1] = v58.u32[1] << (v58.u8[4] & 0x1F);
	v50.u32[2] = v58.u32[2] << (v58.u8[8] & 0x1F);
	v50.u32[3] = v58.u32[3] << (v58.u8[12] & 0x1F);
	// vspltw128 v49,v51,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvx128 v48,r26,r7
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v59,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v54.f32)));
	// vslw128 v46,v58,v58
	v46.u32[0] = v58.u32[0] << (v58.u8[0] & 0x1F);
	v46.u32[1] = v58.u32[1] << (v58.u8[4] & 0x1F);
	v46.u32[2] = v58.u32[2] << (v58.u8[8] & 0x1F);
	v46.u32[3] = v58.u32[3] << (v58.u8[12] & 0x1F);
	// vmulfp128 v45,v52,v53
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// addi r6,r1,496
	ctx.r6.s64 = ctx.r1.s64 + 496;
	// stfs f27,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vmulfp128 v44,v48,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v49.f32)));
	// vandc128 v43,v47,v56
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v47.u8)));
	// vandc128 v42,v45,v50
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// vandc128 v41,v44,v46
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v44.u8)));
	// vaddfp128 v40,v43,v42
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v42.f32)));
	// vaddfp128 v39,v40,v41
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v39,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,504(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 504);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,496(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,500(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 500);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
loc_824B7F7C:
	// fneg f0,f28
	ctx.fpscr.disableFlushMode();
	f0.u64 = f28.u64 ^ 0x8000000000000000;
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r27,1636
	ctx.r5.s64 = r27.s64 + 1636;
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// lvx128 v38,r0,r29
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// fmadds f9,f0,f13,f29
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64 + f29.f64));
	// stfs f9,304(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// fmadds f8,f0,f12,f29
	ctx.f8.f64 = double(float(f0.f64 * ctx.f12.f64 + f29.f64));
	// stfs f8,308(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// fmadds f7,f0,f11,f29
	ctx.f7.f64 = double(float(f0.f64 * ctx.f11.f64 + f29.f64));
	// stfs f7,312(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// fmadds f6,f0,f10,f29
	ctx.f6.f64 = double(float(f0.f64 * ctx.f10.f64 + f29.f64));
	// stfs f6,316(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// lvx128 v37,r0,r11
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v36,v38,v37
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v36,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,80(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x824b5638
	ctx.lr = 0x824B7FE4;
	sub_824B5638(ctx, base);
	// lbz r10,130(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 130);
	// lbz r8,1685(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 1685);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfsx f0,r9,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b8000
	if (cr6.eq) goto loc_824B8000;
	// fsubs f0,f29,f0
	f0.f64 = double(float(f29.f64 - f0.f64));
loc_824B8000:
	// lfs f13,384(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r24,r28,16
	r24.s64 = r28.s64 + 16;
	// lfs f11,388(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	ctx.f11.f64 = double(temp.f32);
	// fnmsubs f10,f12,f28,f29
	ctx.f10.f64 = double(float(-(ctx.f12.f64 * f28.f64 - f29.f64)));
	// fsubs f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f8,88(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,12(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// lfs f6,20(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,24(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 24);
	ctx.f5.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f4,16(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// stfs f6,148(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f5,152(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f27,288(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f27,292(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// fmuls f3,f10,f8
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f8.f64));
	// stfs f4,144(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmadds f2,f9,f0,f13
	ctx.f2.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f13.f64));
	// stfs f27,296(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f27,84(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f3,88(r28)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r28.u32 + 88, temp.u32);
	// fmuls f1,f3,f28
	ctx.f1.f64 = double(float(ctx.f3.f64 * f28.f64));
	// fmuls f0,f2,f28
	f0.f64 = double(float(ctx.f2.f64 * f28.f64));
	// fmadds f13,f0,f26,f1
	ctx.f13.f64 = double(float(f0.f64 * f26.f64 + ctx.f1.f64));
	// fadds f12,f13,f7
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f7.f64));
	// stfs f12,12(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 12, temp.u32);
	// bne cr6,0x824b8154
	if (!cr6.eq) goto loc_824B8154;
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b8154
	if (!cr6.eq) goto loc_824B8154;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824dd378
	ctx.lr = 0x824B809C;
	sub_824DD378(ctx, base);
	// lwz r10,884(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 884);
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// li r8,80
	ctx.r8.s64 = 80;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// li r7,144
	ctx.r7.s64 = 144;
	// lfs f13,256(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r6,r11,19,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x1;
	// lvx128 v34,r0,r25
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v35,r26,r9
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lvx128 v33,r10,r8
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v35,v34
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v34.f32)));
	// lvx128 v32,r10,r7
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v32,v33
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v33.f32)));
	// beq cr6,0x824b80ec
	if (cr6.eq) goto loc_824B80EC;
	// vor128 v63,v62,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// b 0x824b80f4
	goto loc_824B80F4;
loc_824B80EC:
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B80F4:
	// rlwinm r11,r11,18,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824b8108
	if (cr6.eq) goto loc_824B8108;
	// vsubfp128 v62,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v63,v63,v62
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
loc_824B8108:
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r10,r28,32
	ctx.r10.s64 = r28.s64 + 32;
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// vaddfp128 v57,v59,v63
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v58,v63
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v55,v63
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B8154:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lfs f1,80(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// addi r5,r27,1064
	ctx.r5.s64 = r27.s64 + 1064;
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824b5638
	ctx.lr = 0x824B817C;
	sub_824B5638(ctx, base);
	// lbz r10,131(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 131);
	// lbz r8,1113(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 1113);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfsx f0,r9,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824b8198
	if (cr6.eq) goto loc_824B8198;
	// fsubs f0,f29,f0
	f0.f64 = double(float(f29.f64 - f0.f64));
loc_824B8198:
	// lfs f13,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f13.f64 = double(temp.f32);
	// lhz r11,284(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 284);
	// lfs f12,404(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmadds f0,f11,f0,f13
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bne cr6,0x824b81cc
	if (!cr6.eq) goto loc_824B81CC;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
loc_824B81CC:
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,352
	r11.s64 = ctx.r1.s64 + 352;
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b8224
	if (cr6.eq) goto loc_824B8224;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r11,-4916(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B8204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// addi r8,r1,352
	ctx.r8.s64 = ctx.r1.s64 + 352;
	// lvlx128 v52,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v0,v50,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B8224:
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lvx128 v49,r0,r29
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1208
	ctx.r9.s64 = 1208;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// lwz r10,-4916(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -4916);
	// addi r5,r27,1116
	ctx.r5.s64 = r27.s64 + 1116;
	// addi r4,r1,320
	ctx.r4.s64 = ctx.r1.s64 + 320;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// vor128 v48,v13,v13
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// lvlx128 v46,r10,r9
	temp.u32 = ctx.r10.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v46,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vsubfp128 v47,v49,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)));
	// vmaddfp v11,v0,v12,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor128 v45,v47,v47
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// stvx128 v47,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v44,v11,v11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vaddfp128 v43,v45,v44
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32)));
	// stvx128 v43,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,80(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824b5638
	ctx.lr = 0x824B8284;
	sub_824B5638(ctx, base);
	// lbz r8,133(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 133);
	// rotlwi r7,r8,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lbz r11,1165(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1165);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfsx f13,r7,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x824b82a0
	if (cr6.eq) goto loc_824B82A0;
	// fsubs f13,f29,f13
	ctx.f13.f64 = double(float(f29.f64 - ctx.f13.f64));
loc_824B82A0:
	// lfs f12,320(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f12.f64 = double(temp.f32);
	// lbz r10,132(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 132);
	// lfs f0,324(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfsx f0,r9,r18
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	f0.f64 = double(temp.f32);
	// fmadds f12,f11,f13,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f12.f64));
	// beq cr6,0x824b82c8
	if (cr6.eq) goto loc_824B82C8;
	// fsubs f0,f29,f0
	f0.f64 = double(float(f29.f64 - f0.f64));
loc_824B82C8:
	// lfs f13,328(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lfs f11,332(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f0,f10,f0,f13
	f0.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f13.f64));
	// beq cr6,0x824b8424
	if (cr6.eq) goto loc_824B8424;
	// stfs f24,92(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// stfs f25,88(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vor128 v42,v126,v126
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lvx128 v60,r0,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v41,v126,v126
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lwz r8,176(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// lvlx128 v39,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v38,v39,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// lvlx128 v40,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmaddfp128 v42,v125,v38,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v38.f32)), simde_mm_load_ps(v42.f32)));
	// vspltw128 v37,v40,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v41,v125,v37,v41
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v37.f32)), simde_mm_load_ps(v41.f32)));
	// vsubfp128 v12,v42,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v60.f32)));
	// vsubfp128 v0,v41,v42
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v42.f32)));
	// vmsum3fp128 v36,v0,v12
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32), 0xEF));
	// vsubfp128 v63,v127,v36
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v36.f32)));
	// vcmpgefp128. v35,v62,v63
	simde_mm_store_ps(v35.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v35.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x824b838c
	if (!cr6.eq) goto loc_824B838C;
	// vmsum3fp128 v34,v0,v0
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// vsubfp128 v61,v34,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128. v33,v62,v61
	simde_mm_store_ps(v33.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v33.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824b8368
	if (cr6.eq) goto loc_824B8368;
	// vaddfp v12,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x824b838c
	goto loc_824B838C;
loc_824B8368:
	// vaddfp128 v32,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v32.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vupkd3d128 v62,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// vspltw128 v11,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x0));
	// vrefp128 v13,v32
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v32.f32)));
	// vor128 v10,v32,v32
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v32.u8));
	// vnmsubfp v8,v13,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v13,v8,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v63,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v12,v0,v6,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)));
loc_824B838C:
	// vaddfp128 v61,v12,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v60.f32)));
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r9,188(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// fmuls f13,f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lwz r8,200(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// lwz r6,196(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lvx128 v12,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vsubfp128 v60,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lvlx128 v59,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmsum3fp128 v58,v60,v60
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v9,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vcmpeqfp128 v8,v57,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v7,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v7,v11,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v6,v0,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v63,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v4,v9,v6,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v3,v4,v5,v0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v2,v60,v3
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v1,v2,v10,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v1,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b8424
	if (cr6.eq) goto loc_824B8424;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// fmuls f0,f0,f28
	ctx.fpscr.disableFlushModeUnconditional();
	f0.f64 = double(float(f0.f64 * f28.f64));
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v56,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// b 0x824b8430
	goto loc_824B8430;
loc_824B8424:
	// addi r11,r1,900
	r11.s64 = ctx.r1.s64 + 900;
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
loc_824B8430:
	// lvx128 v0,r0,r24
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,284(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 284);
	// lvx128 v13,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stvx128 v11,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824b8478
	if (cr6.eq) goto loc_824B8478;
	// lwz r11,-4916(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -4916);
	// addi r5,r1,432
	ctx.r5.s64 = ctx.r1.s64 + 432;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824B846C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// lvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B8478:
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b861c
	if (cr6.eq) goto loc_824B861C;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824b861c
	if (cr6.eq) goto loc_824B861C;
	// rlwinm r11,r11,31,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824b861c
	if (!cr6.eq) goto loc_824B861C;
	// lfs f31,80(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	f31.f64 = double(temp.f32);
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r5,r27,1168
	ctx.r5.s64 = r27.s64 + 1168;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B84C0;
	sub_824B5638(ctx, base);
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r5,r27,1220
	ctx.r5.s64 = r27.s64 + 1220;
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x824b5638
	ctx.lr = 0x824B84DC;
	sub_824B5638(ctx, base);
	// lbz r10,137(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 137);
	// lbz r11,1217(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1217);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfsx f12,r9,r18
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x824b84f8
	if (cr6.eq) goto loc_824B84F8;
	// fsubs f12,f29,f12
	ctx.f12.f64 = double(float(f29.f64 - ctx.f12.f64));
loc_824B84F8:
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	f0.f64 = double(temp.f32);
	// lbz r10,138(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 138);
	// lfs f13,368(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfs f10,224(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f13,r9,r18
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f11,f12,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + f0.f64));
	// fmuls f8,f9,f22
	ctx.f8.f64 = double(float(ctx.f9.f64 * f22.f64));
	// fmuls f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// beq cr6,0x824b852c
	if (cr6.eq) goto loc_824B852C;
	// fsubs f13,f29,f13
	ctx.f13.f64 = double(float(f29.f64 - ctx.f13.f64));
loc_824B852C:
	// lfs f0,340(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	f0.f64 = double(temp.f32);
	// lbz r10,139(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 139);
	// lfs f12,372(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lfs f9,228(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f12,r9,r18
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r18.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f11,f13,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// fmuls f7,f8,f21
	ctx.f7.f64 = double(float(ctx.f8.f64 * f21.f64));
	// fmuls f11,f7,f9
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// beq cr6,0x824b8560
	if (cr6.eq) goto loc_824B8560;
	// fsubs f12,f29,f12
	ctx.f12.f64 = double(float(f29.f64 - ctx.f12.f64));
loc_824B8560:
	// lfs f0,344(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 344);
	f0.f64 = double(temp.f32);
	// lbz r11,92(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 92);
	// lfs f13,376(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,364(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 364);
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f8,232(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f8.f64 = double(temp.f32);
	// fmr f13,f29
	ctx.f13.f64 = f29.f64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// fmadds f7,f9,f12,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + f0.f64));
	// fmuls f6,f7,f23
	ctx.f6.f64 = double(float(ctx.f7.f64 * f23.f64));
	// fmuls f0,f6,f8
	f0.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// bge cr6,0x824b85ac
	if (!cr6.lt) goto loc_824B85AC;
	// lwz r10,360(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 360);
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824b85ac
	if (cr6.eq) goto loc_824B85AC;
	// lfs f13,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
loc_824B85AC:
	// fsubs f12,f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lwz r4,876(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 876);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fsel f11,f12,f10,f11
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f9,f10,f11,f0
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fmuls f1,f9,f13
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// bne cr6,0x824b8608
	if (!cr6.eq) goto loc_824B8608;
	// lfs f0,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f11,228(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 228);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f13,8(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 232);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f12,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,224(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 224);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f20
	cr6.compare(ctx.f3.f64, f20.f64);
	// bgt cr6,0x824b861c
	if (cr6.gt) goto loc_824B861C;
loc_824B8608:
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// fmr f2,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f28.f64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824b6830
	ctx.lr = 0x824B861C;
	sub_824B6830(ctx, base);
loc_824B861C:
	// lwz r11,19708(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 19708);
	// lvx128 v53,r31,r14
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r25,876(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 876);
	// lwz r26,184(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r24,204(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r29,192(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// stvx128 v53,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 19708);
	// lvx128 v52,r31,r15
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stvx128 v52,r8,r16
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 19708);
	// lfs f0,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 256);
	f0.f64 = double(temp.f32);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stfs f0,352(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 352, temp.u32);
	// lwz r11,19708(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 19708);
	// lbz r5,268(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 268);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stb r5,364(r3)
	PPC_STORE_U8(ctx.r3.u32 + 364, ctx.r5.u8);
	// lvx128 v51,r0,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19708(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 19708);
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// stvx128 v51,r10,r17
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824B86CC:
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824b7c08
	if (!cr6.eq) goto loc_824B7C08;
loc_824B86D8:
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// addi r12,r1,-256
	r12.s64 = ctx.r1.s64 + -256;
	// bl 0x823dd7c4
	ctx.lr = 0x824B86E4;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba04
	ctx.lr = 0x824B86EC;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_824B86F0"))) PPC_WEAK_FUNC(sub_824B86F0);
PPC_FUNC_IMPL(__imp__sub_824B86F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,284(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 284);
	// rlwinm r10,r11,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r10,284(r3)
	PPC_STORE_U32(ctx.r3.u32 + 284, ctx.r10.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

