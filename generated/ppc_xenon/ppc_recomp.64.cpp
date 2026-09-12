#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823A8170"))) PPC_WEAK_FUNC(sub_823A8170);
PPC_FUNC_IMPL(__imp__sub_823A8170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823A8178;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// addi r5,r10,23356
	ctx.r5.s64 = ctx.r10.s64 + 23356;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823A81A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// clrlwi r28,r3,31
	r28.u64 = ctx.r3.u32 & 0x1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23336
	ctx.r5.s64 = ctx.r7.s64 + 23336;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A81C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,24(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r8,23320
	ctx.r5.s64 = ctx.r8.s64 + 23320;
	// and r28,r9,r28
	r28.u64 = ctx.r9.u64 & r28.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823A81F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r8,24(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,23300
	ctx.r5.s64 = ctx.r9.s64 + 23300;
	// and r28,r11,r10
	r28.u64 = r11.u64 & ctx.r10.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823A8224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,23276
	ctx.r5.s64 = ctx.r9.s64 + 23276;
	// and r28,r11,r10
	r28.u64 = r11.u64 & ctx.r10.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823A8254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r8,24(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,23256
	ctx.r5.s64 = ctx.r9.s64 + 23256;
	// and r28,r11,r10
	r28.u64 = r11.u64 & ctx.r10.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823A8284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFF;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// and r28,r6,r5
	r28.u64 = ctx.r6.u64 & ctx.r5.u64;
	// addi r5,r4,23236
	ctx.r5.s64 = ctx.r4.s64 + 23236;
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A82B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23212
	ctx.r5.s64 = ctx.r7.s64 + 23212;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A82E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23188
	ctx.r5.s64 = ctx.r7.s64 + 23188;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8314;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23164
	ctx.r5.s64 = ctx.r7.s64 + 23164;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23140
	ctx.r5.s64 = ctx.r7.s64 + 23140;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8374;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23112
	ctx.r5.s64 = ctx.r7.s64 + 23112;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A83A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23084
	ctx.r5.s64 = ctx.r7.s64 + 23084;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A83D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23068
	ctx.r5.s64 = ctx.r7.s64 + 23068;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23052
	ctx.r5.s64 = ctx.r7.s64 + 23052;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23032
	ctx.r5.s64 = ctx.r7.s64 + 23032;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,23008
	ctx.r5.s64 = ctx.r7.s64 + 23008;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22984
	ctx.r5.s64 = ctx.r7.s64 + 22984;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A84C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22956
	ctx.r5.s64 = ctx.r7.s64 + 22956;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A84F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22928
	ctx.r5.s64 = ctx.r7.s64 + 22928;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r5,r7,22916
	ctx.r5.s64 = ctx.r7.s64 + 22916;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8554;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22904
	ctx.r5.s64 = ctx.r7.s64 + 22904;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22888
	ctx.r5.s64 = ctx.r7.s64 + 22888;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A85B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22872
	ctx.r5.s64 = ctx.r7.s64 + 22872;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A85E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22852
	ctx.r5.s64 = ctx.r7.s64 + 22852;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22832
	ctx.r5.s64 = ctx.r7.s64 + 22832;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22816
	ctx.r5.s64 = ctx.r7.s64 + 22816;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22796
	ctx.r5.s64 = ctx.r7.s64 + 22796;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A86A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22776
	ctx.r5.s64 = ctx.r7.s64 + 22776;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A86D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22752
	ctx.r5.s64 = ctx.r7.s64 + 22752;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22740
	ctx.r5.s64 = ctx.r7.s64 + 22740;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22728
	ctx.r5.s64 = ctx.r7.s64 + 22728;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8764;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22716
	ctx.r5.s64 = ctx.r7.s64 + 22716;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22700
	ctx.r5.s64 = ctx.r7.s64 + 22700;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A87C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22684
	ctx.r5.s64 = ctx.r7.s64 + 22684;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A87F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22672
	ctx.r5.s64 = ctx.r7.s64 + 22672;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22656
	ctx.r5.s64 = ctx.r7.s64 + 22656;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8854;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22640
	ctx.r5.s64 = ctx.r7.s64 + 22640;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22620
	ctx.r5.s64 = ctx.r7.s64 + 22620;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A88B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22596
	ctx.r5.s64 = ctx.r7.s64 + 22596;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A88E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22572
	ctx.r5.s64 = ctx.r7.s64 + 22572;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,21896
	ctx.r5.s64 = ctx.r7.s64 + 21896;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22112
	ctx.r5.s64 = ctx.r7.s64 + 22112;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22556
	ctx.r5.s64 = ctx.r7.s64 + 22556;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A89A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22092
	ctx.r5.s64 = ctx.r7.s64 + 22092;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A89D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,21988
	ctx.r5.s64 = ctx.r7.s64 + 21988;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8A04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22008
	ctx.r5.s64 = ctx.r7.s64 + 22008;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8A34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r5,r7,21904
	ctx.r5.s64 = ctx.r7.s64 + 21904;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8A64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22028
	ctx.r5.s64 = ctx.r7.s64 + 22028;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,21924
	ctx.r5.s64 = ctx.r7.s64 + 21924;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22068
	ctx.r5.s64 = ctx.r7.s64 + 22068;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8AF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,21964
	ctx.r5.s64 = ctx.r7.s64 + 21964;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r5,r7,22048
	ctx.r5.s64 = ctx.r7.s64 + 22048;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,21944
	ctx.r5.s64 = ctx.r7.s64 + 21944;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// and r28,r10,r9
	r28.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22536
	ctx.r5.s64 = ctx.r7.s64 + 22536;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22516
	ctx.r5.s64 = ctx.r7.s64 + 22516;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,22492
	ctx.r5.s64 = ctx.r7.s64 + 22492;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8C14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r28,r9,r8
	r28.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22476
	ctx.r5.s64 = ctx.r7.s64 + 22476;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A8C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// and r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823A8C58"))) PPC_WEAK_FUNC(sub_823A8C58);
PPC_FUNC_IMPL(__imp__sub_823A8C58) {
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
	ctx.lr = 0x823A8C60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r29,-32129
	r29.s64 = -2105606144;
	// clrlwi r28,r5,24
	r28.u64 = ctx.r5.u32 & 0xFF;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,-23204(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -23204);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq cr6,0x823a8cac
	if (cr6.eq) goto loc_823A8CAC;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,23384
	ctx.r4.s64 = r11.s64 + 23384;
	// bl 0x823d90b0
	ctx.lr = 0x823A8C9C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823a8cc4
	if (!cr6.eq) goto loc_823A8CC4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x823a8cd4
	if (!cr6.eq) goto loc_823A8CD4;
loc_823A8CAC:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,23372
	ctx.r4.s64 = r11.s64 + 23372;
	// bl 0x823d90b0
	ctx.lr = 0x823A8CBC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823a8cd4
	if (cr6.eq) goto loc_823A8CD4;
loc_823A8CC4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,-23204(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -23204);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823A8CD4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x823b7d68
	ctx.lr = 0x823A8CF8;
	sub_823B7D68(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823A8D00"))) PPC_WEAK_FUNC(sub_823A8D00);
PPC_FUNC_IMPL(__imp__sub_823A8D00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// ori r5,r8,26215
	ctx.r5.u64 = ctx.r8.u64 | 26215;
	// addi r4,r7,-23200
	ctx.r4.s64 = ctx.r7.s64 + -23200;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r5,r6,r5
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// addi r5,r7,-11512
	ctx.r5.s64 = ctx.r7.s64 + -11512;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8D64"))) PPC_WEAK_FUNC(sub_823A8D64);
PPC_FUNC_IMPL(__imp__sub_823A8D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8D68"))) PPC_WEAK_FUNC(sub_823A8D68);
PPC_FUNC_IMPL(__imp__sub_823A8D68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// ori r5,r8,26215
	ctx.r5.u64 = ctx.r8.u64 | 26215;
	// addi r4,r7,-23180
	ctx.r4.s64 = ctx.r7.s64 + -23180;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r5,r6,r5
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// addi r5,r7,-11512
	ctx.r5.s64 = ctx.r7.s64 + -11512;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8DCC"))) PPC_WEAK_FUNC(sub_823A8DCC);
PPC_FUNC_IMPL(__imp__sub_823A8DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8DD0"))) PPC_WEAK_FUNC(sub_823A8DD0);
PPC_FUNC_IMPL(__imp__sub_823A8DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// addi r6,r8,-11512
	ctx.r6.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r4,-23160(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23160);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8E04"))) PPC_WEAK_FUNC(sub_823A8E04);
PPC_FUNC_IMPL(__imp__sub_823A8E04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8E08"))) PPC_WEAK_FUNC(sub_823A8E08);
PPC_FUNC_IMPL(__imp__sub_823A8E08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// addi r6,r8,-11512
	ctx.r6.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r4,-23156(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23156);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8E3C"))) PPC_WEAK_FUNC(sub_823A8E3C);
PPC_FUNC_IMPL(__imp__sub_823A8E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8E40"))) PPC_WEAK_FUNC(sub_823A8E40);
PPC_FUNC_IMPL(__imp__sub_823A8E40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r6,r9,-23152
	ctx.r6.s64 = ctx.r9.s64 + -23152;
	// addi r8,r8,-11512
	ctx.r8.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r5,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// addze r9,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8E90"))) PPC_WEAK_FUNC(sub_823A8E90);
PPC_FUNC_IMPL(__imp__sub_823A8E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// addi r6,r8,-11512
	ctx.r6.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// lwz r4,-23144(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23144);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8EC4"))) PPC_WEAK_FUNC(sub_823A8EC4);
PPC_FUNC_IMPL(__imp__sub_823A8EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8EC8"))) PPC_WEAK_FUNC(sub_823A8EC8);
PPC_FUNC_IMPL(__imp__sub_823A8EC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823a8ee4
	if (cr6.eq) goto loc_823A8EE4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_823A8EE4:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r10,-23140
	ctx.r9.s64 = ctx.r10.s64 + -23140;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8F18"))) PPC_WEAK_FUNC(sub_823A8F18);
PPC_FUNC_IMPL(__imp__sub_823A8F18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823a8f34
	if (cr6.eq) goto loc_823A8F34;
	// li r5,1
	ctx.r5.s64 = 1;
loc_823A8F34:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lwz r4,-23132(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23132);
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823A8F4C"))) PPC_WEAK_FUNC(sub_823A8F4C);
PPC_FUNC_IMPL(__imp__sub_823A8F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8F50"))) PPC_WEAK_FUNC(sub_823A8F50);
PPC_FUNC_IMPL(__imp__sub_823A8F50) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,22448
	ctx.r10.s64 = r11.s64 + 22448;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8248
	ctx.lr = 0x823A8F7C;
	sub_823B8248(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823a8f94
	if (cr6.eq) goto loc_823A8F94;
	// bl 0x82130588
	ctx.lr = 0x823A8F90;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823A8F94:
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

__attribute__((alias("__imp__sub_823A8FAC"))) PPC_WEAK_FUNC(sub_823A8FAC);
PPC_FUNC_IMPL(__imp__sub_823A8FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A8FB0"))) PPC_WEAK_FUNC(sub_823A8FB0);
PPC_FUNC_IMPL(__imp__sub_823A8FB0) {
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
	ctx.lr = 0x823A8FB8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r29,r11,-26992
	r29.s64 = r11.s64 + -26992;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r4,128
	ctx.r4.s64 = 128;
	// beq cr6,0x823a8ff4
	if (cr6.eq) goto loc_823A8FF4;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r5,r11,23492
	ctx.r5.s64 = r11.s64 + 23492;
	// b 0x823a8ff8
	goto loc_823A8FF8;
loc_823A8FF4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
loc_823A8FF8:
	// bl 0x82137a08
	ctx.lr = 0x823A8FFC;
	sub_82137A08(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r30,r11,3664
	r30.s64 = r11.s64 + 3664;
	// addi r27,r10,30576
	r27.s64 = ctx.r10.s64 + 30576;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca778
	ctx.lr = 0x823A901C;
	sub_821CA778(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823a90a8
	if (cr6.eq) goto loc_823A90A8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82507720
	ctx.lr = 0x823A903C;
	sub_82507720(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823a90a8
	if (cr6.eq) goto loc_823A90A8;
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,776(r31)
	PPC_STORE_U32(r31.u32 + 776, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x823A9068;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823a9080
	if (cr6.eq) goto loc_823A9080;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82137248
	ctx.lr = 0x823A9078;
	sub_82137248(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// b 0x823a9084
	goto loc_823A9084;
loc_823A9080:
	// li r8,0
	ctx.r8.s64 = 0;
loc_823A9084:
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// addi r10,r31,780
	ctx.r10.s64 = r31.s64 + 780;
	// li r3,1
	ctx.r3.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
loc_823A90A8:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r6,r11,23472
	ctx.r6.s64 = r11.s64 + 23472;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823A90C4;
	sub_82137A08(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r10,23436
	ctx.r4.s64 = ctx.r10.s64 + 23436;
	// bl 0x821ca540
	ctx.lr = 0x823A90D4;
	sub_821CA540(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca778
	ctx.lr = 0x823A90E4;
	sub_821CA778(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823a9178
	if (cr6.eq) goto loc_823A9178;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82507720
	ctx.lr = 0x823A9104;
	sub_82507720(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823a9178
	if (cr6.eq) goto loc_823A9178;
	// lwz r11,776(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,776(r31)
	PPC_STORE_U32(r31.u32 + 776, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// bl 0x82130528
	ctx.lr = 0x823A9130;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823a9144
	if (cr6.eq) goto loc_823A9144;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82137248
	ctx.lr = 0x823A9140;
	sub_82137248(ctx, base);
	// b 0x823a9148
	goto loc_823A9148;
loc_823A9144:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823A9148:
	// lwz r11,1548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1548);
	// addi r10,r31,780
	ctx.r10.s64 = r31.s64 + 780;
	// li r30,1
	r30.s64 = 1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,1548(r31)
	PPC_STORE_U32(r31.u32 + 1548, r11.u32);
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823A916C;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
loc_823A9178:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,23396
	ctx.r3.s64 = r11.s64 + 23396;
	// bl 0x82130000
	ctx.lr = 0x823A9188;
	sub_82130000(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x821c9a90
	ctx.lr = 0x823A9194;
	sub_821C9A90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823A91A0"))) PPC_WEAK_FUNC(sub_823A91A0);
PPC_FUNC_IMPL(__imp__sub_823A91A0) {
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
	// bl 0x823b8540
	ctx.lr = 0x823A91B8;
	sub_823B8540(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,24004
	ctx.r10.s64 = r11.s64 + 24004;
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

__attribute__((alias("__imp__sub_823A91DC"))) PPC_WEAK_FUNC(sub_823A91DC);
PPC_FUNC_IMPL(__imp__sub_823A91DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823A91E0"))) PPC_WEAK_FUNC(sub_823A91E0);
PPC_FUNC_IMPL(__imp__sub_823A91E0) {
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
	ctx.lr = 0x823A91E8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x823b7c68
	ctx.lr = 0x823A9208;
	sub_823B7C68(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r5,r10,29068
	ctx.r5.s64 = ctx.r10.s64 + 29068;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// beq cr6,0x823a97b0
	if (cr6.eq) goto loc_823A97B0;
	// bctrl 
	ctx.lr = 0x823A923C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// clrlwi r29,r3,31
	r29.u64 = ctx.r3.u32 & 0x1;
	// addi r5,r7,29052
	ctx.r5.s64 = ctx.r7.s64 + 29052;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// and r29,r9,r29
	r29.u64 = ctx.r9.u64 & r29.u64;
	// addi r5,r8,29036
	ctx.r5.s64 = ctx.r8.s64 + 29036;
	// lwz r7,24(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823A9290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
	// lwz r8,24(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// and r29,r3,r10
	r29.u64 = ctx.r3.u64 & ctx.r10.u64;
	// addi r5,r9,29016
	ctx.r5.s64 = ctx.r9.s64 + 29016;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823A92C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r3,r29,24
	ctx.r3.u64 = r29.u32 & 0xFF;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// and r29,r6,r3
	r29.u64 = ctx.r6.u64 & ctx.r3.u64;
	// lwz r10,24(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r5,r11,28996
	ctx.r5.s64 = r11.s64 + 28996;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823A92F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// addi r5,r6,28976
	ctx.r5.s64 = ctx.r6.s64 + 28976;
	// lwz r11,24(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// and r29,r8,r7
	r29.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28956
	ctx.r5.s64 = ctx.r7.s64 + 28956;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9358;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28940
	ctx.r5.s64 = ctx.r7.s64 + 28940;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28920
	ctx.r5.s64 = ctx.r7.s64 + 28920;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A93B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23648
	ctx.r5.s64 = ctx.r7.s64 + 23648;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A93E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23708
	ctx.r5.s64 = ctx.r7.s64 + 23708;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// addi r26,r11,-23012
	r26.s64 = r11.s64 + -23012;
	// and r27,r10,r9
	r27.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r29,r26,-20
	r29.s64 = r26.s64 + -20;
loc_823A9430:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823A9450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,-20
	r11.s64 = r26.s64 + -20;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r7,r11,20
	ctx.r7.s64 = r11.s64 + 20;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// blt cr6,0x823a9430
	if (cr6.lt) goto loc_823A9430;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_823A9474:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823A9494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r7,r26,20
	ctx.r7.s64 = r26.s64 + 20;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// blt cr6,0x823a9474
	if (cr6.lt) goto loc_823A9474;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r5,r10,28900
	ctx.r5.s64 = ctx.r10.s64 + 28900;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823A94D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r29,r7,r6
	r29.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// addi r5,r5,28884
	ctx.r5.s64 = ctx.r5.s64 + 28884;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,21896
	ctx.r5.s64 = ctx.r7.s64 + 21896;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23500
	ctx.r5.s64 = ctx.r7.s64 + 23500;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22112
	ctx.r5.s64 = ctx.r7.s64 + 22112;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28868
	ctx.r5.s64 = ctx.r7.s64 + 28868;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A95C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23688
	ctx.r5.s64 = ctx.r7.s64 + 23688;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A95F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,23668
	ctx.r5.s64 = ctx.r7.s64 + 23668;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22536
	ctx.r5.s64 = ctx.r7.s64 + 22536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22516
	ctx.r5.s64 = ctx.r7.s64 + 22516;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28856
	ctx.r5.s64 = ctx.r7.s64 + 28856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A96B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28844
	ctx.r5.s64 = ctx.r7.s64 + 28844;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A96E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28828
	ctx.r5.s64 = ctx.r7.s64 + 28828;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// and r29,r10,r9
	r29.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r5,r7,28812
	ctx.r5.s64 = ctx.r7.s64 + 28812;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28804
	ctx.r5.s64 = ctx.r7.s64 + 28804;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28788
	ctx.r5.s64 = ctx.r7.s64 + 28788;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A97A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r5,r7,28768
	ctx.r5.s64 = ctx.r7.s64 + 28768;
	// b 0x823ab824
	goto loc_823AB824;
loc_823A97B0:
	// bctrl 
	ctx.lr = 0x823A97B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// clrlwi r29,r3,31
	r29.u64 = ctx.r3.u32 & 0x1;
	// addi r5,r7,29052
	ctx.r5.s64 = ctx.r7.s64 + 29052;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A97DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// and r29,r9,r29
	r29.u64 = ctx.r9.u64 & r29.u64;
	// addi r5,r8,29036
	ctx.r5.s64 = ctx.r8.s64 + 29036;
	// lwz r7,24(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823A9808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// and r29,r5,r4
	r29.u64 = ctx.r5.u64 & ctx.r4.u64;
	// lwz r11,24(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// addi r5,r3,28748
	ctx.r5.s64 = ctx.r3.s64 + 28748;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28724
	ctx.r5.s64 = ctx.r7.s64 + 28724;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28700
	ctx.r5.s64 = ctx.r7.s64 + 28700;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28676
	ctx.r5.s64 = ctx.r7.s64 + 28676;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A98C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r10,r9
	r29.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r7,28652
	ctx.r5.s64 = ctx.r7.s64 + 28652;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A98F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28628
	ctx.r5.s64 = ctx.r7.s64 + 28628;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28608
	ctx.r5.s64 = ctx.r7.s64 + 28608;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28584
	ctx.r5.s64 = ctx.r7.s64 + 28584;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28560
	ctx.r5.s64 = ctx.r7.s64 + 28560;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A99B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28536
	ctx.r5.s64 = ctx.r7.s64 + 28536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A99E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28512
	ctx.r5.s64 = ctx.r7.s64 + 28512;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28488
	ctx.r5.s64 = ctx.r7.s64 + 28488;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9A48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28804
	ctx.r5.s64 = ctx.r7.s64 + 28804;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9A78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28788
	ctx.r5.s64 = ctx.r7.s64 + 28788;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9AA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28476
	ctx.r5.s64 = ctx.r7.s64 + 28476;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9AD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28452
	ctx.r5.s64 = ctx.r7.s64 + 28452;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9B08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28428
	ctx.r5.s64 = ctx.r7.s64 + 28428;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r10,r9
	r29.u64 = ctx.r10.u64 & ctx.r9.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// addi r5,r7,28404
	ctx.r5.s64 = ctx.r7.s64 + 28404;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9B68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28380
	ctx.r5.s64 = ctx.r7.s64 + 28380;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28856
	ctx.r5.s64 = ctx.r7.s64 + 28856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28844
	ctx.r5.s64 = ctx.r7.s64 + 28844;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28828
	ctx.r5.s64 = ctx.r7.s64 + 28828;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28812
	ctx.r5.s64 = ctx.r7.s64 + 28812;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9C58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28768
	ctx.r5.s64 = ctx.r7.s64 + 28768;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// and r29,r10,r9
	r29.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r5,r7,28368
	ctx.r5.s64 = ctx.r7.s64 + 28368;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,22492
	ctx.r5.s64 = ctx.r7.s64 + 22492;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9CE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,28332
	ctx.r5.s64 = ctx.r7.s64 + 28332;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9D20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28296
	ctx.r5.s64 = ctx.r7.s64 + 28296;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28260
	ctx.r5.s64 = ctx.r7.s64 + 28260;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28224
	ctx.r5.s64 = ctx.r7.s64 + 28224;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28188
	ctx.r5.s64 = ctx.r7.s64 + 28188;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r6,28156
	ctx.r5.s64 = ctx.r6.s64 + 28156;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r9,r7
	r27.u64 = ctx.r9.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823A9E10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// and r27,r3,r11
	r27.u64 = ctx.r3.u64 & r11.u64;
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,28120
	ctx.r5.s64 = ctx.r10.s64 + 28120;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823A9E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r27,r7,r6
	r27.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r5,28088
	ctx.r5.s64 = ctx.r5.s64 + 28088;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28052
	ctx.r5.s64 = ctx.r7.s64 + 28052;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9EA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28016
	ctx.r5.s64 = ctx.r7.s64 + 28016;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9ED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27980
	ctx.r5.s64 = ctx.r7.s64 + 27980;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27944
	ctx.r5.s64 = ctx.r7.s64 + 27944;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9F30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,27908
	ctx.r5.s64 = ctx.r7.s64 + 27908;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9F60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27872
	ctx.r5.s64 = ctx.r7.s64 + 27872;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9F90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27836
	ctx.r5.s64 = ctx.r7.s64 + 27836;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9FC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27800
	ctx.r5.s64 = ctx.r7.s64 + 27800;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823A9FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27764
	ctx.r5.s64 = ctx.r7.s64 + 27764;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,27728
	ctx.r5.s64 = ctx.r7.s64 + 27728;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r9,27692
	ctx.r5.s64 = ctx.r9.s64 + 27692;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r8,r7
	r27.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,27656
	ctx.r5.s64 = ctx.r7.s64 + 27656;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA0B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27620
	ctx.r5.s64 = ctx.r7.s64 + 27620;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA0E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27584
	ctx.r5.s64 = ctx.r7.s64 + 27584;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27548
	ctx.r5.s64 = ctx.r7.s64 + 27548;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27512
	ctx.r5.s64 = ctx.r7.s64 + 27512;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27476
	ctx.r5.s64 = ctx.r7.s64 + 27476;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA1A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27444
	ctx.r5.s64 = ctx.r7.s64 + 27444;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,27408
	ctx.r5.s64 = ctx.r7.s64 + 27408;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA200;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27376
	ctx.r5.s64 = ctx.r7.s64 + 27376;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27340
	ctx.r5.s64 = ctx.r7.s64 + 27340;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA260;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27308
	ctx.r5.s64 = ctx.r7.s64 + 27308;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27272
	ctx.r5.s64 = ctx.r7.s64 + 27272;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA2C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27240
	ctx.r5.s64 = ctx.r7.s64 + 27240;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r6,27204
	ctx.r5.s64 = ctx.r6.s64 + 27204;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r9,r7
	r27.u64 = ctx.r9.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823AA320;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// and r27,r3,r11
	r27.u64 = ctx.r3.u64 & r11.u64;
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,27168
	ctx.r5.s64 = ctx.r10.s64 + 27168;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823AA350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r27,r7,r6
	r27.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r5,27132
	ctx.r5.s64 = ctx.r5.s64 + 27132;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27096
	ctx.r5.s64 = ctx.r7.s64 + 27096;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA3B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27060
	ctx.r5.s64 = ctx.r7.s64 + 27060;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA3E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,27024
	ctx.r5.s64 = ctx.r7.s64 + 27024;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26988
	ctx.r5.s64 = ctx.r7.s64 + 26988;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,26952
	ctx.r5.s64 = ctx.r7.s64 + 26952;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26916
	ctx.r5.s64 = ctx.r7.s64 + 26916;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26880
	ctx.r5.s64 = ctx.r7.s64 + 26880;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA4D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,26844
	ctx.r5.s64 = ctx.r7.s64 + 26844;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26808
	ctx.r5.s64 = ctx.r7.s64 + 26808;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26772
	ctx.r5.s64 = ctx.r7.s64 + 26772;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r9,26736
	ctx.r5.s64 = ctx.r9.s64 + 26736;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r8,r7
	r27.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA590;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,26700
	ctx.r5.s64 = ctx.r7.s64 + 26700;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26664
	ctx.r5.s64 = ctx.r7.s64 + 26664;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,26628
	ctx.r5.s64 = ctx.r7.s64 + 26628;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA620;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26592
	ctx.r5.s64 = ctx.r7.s64 + 26592;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26556
	ctx.r5.s64 = ctx.r7.s64 + 26556;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26520
	ctx.r5.s64 = ctx.r7.s64 + 26520;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA6B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26484
	ctx.r5.s64 = ctx.r7.s64 + 26484;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,26452
	ctx.r5.s64 = ctx.r7.s64 + 26452;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26416
	ctx.r5.s64 = ctx.r7.s64 + 26416;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26384
	ctx.r5.s64 = ctx.r7.s64 + 26384;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26348
	ctx.r5.s64 = ctx.r7.s64 + 26348;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA7A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26316
	ctx.r5.s64 = ctx.r7.s64 + 26316;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26280
	ctx.r5.s64 = ctx.r7.s64 + 26280;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA800;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r6,26248
	ctx.r5.s64 = ctx.r6.s64 + 26248;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r9,r7
	r27.u64 = ctx.r9.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823AA830;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// and r27,r3,r11
	r27.u64 = ctx.r3.u64 & r11.u64;
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,26212
	ctx.r5.s64 = ctx.r10.s64 + 26212;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823AA860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r27,r7,r6
	r27.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r5,26180
	ctx.r5.s64 = ctx.r5.s64 + 26180;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26144
	ctx.r5.s64 = ctx.r7.s64 + 26144;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA8C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26112
	ctx.r5.s64 = ctx.r7.s64 + 26112;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA8F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26076
	ctx.r5.s64 = ctx.r7.s64 + 26076;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,26044
	ctx.r5.s64 = ctx.r7.s64 + 26044;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,26008
	ctx.r5.s64 = ctx.r7.s64 + 26008;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25976
	ctx.r5.s64 = ctx.r7.s64 + 25976;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25940
	ctx.r5.s64 = ctx.r7.s64 + 25940;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AA9E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25908
	ctx.r5.s64 = ctx.r7.s64 + 25908;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAA10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25872
	ctx.r5.s64 = ctx.r7.s64 + 25872;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAA40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25840
	ctx.r5.s64 = ctx.r7.s64 + 25840;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAA70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r9,25804
	ctx.r5.s64 = ctx.r9.s64 + 25804;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r8,r7
	r27.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAAA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,25768
	ctx.r5.s64 = ctx.r7.s64 + 25768;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAAD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25732
	ctx.r5.s64 = ctx.r7.s64 + 25732;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAB00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25696
	ctx.r5.s64 = ctx.r7.s64 + 25696;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAB30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25660
	ctx.r5.s64 = ctx.r7.s64 + 25660;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAB60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25624
	ctx.r5.s64 = ctx.r7.s64 + 25624;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAB90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25588
	ctx.r5.s64 = ctx.r7.s64 + 25588;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AABC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25552
	ctx.r5.s64 = ctx.r7.s64 + 25552;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AABF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,25516
	ctx.r5.s64 = ctx.r7.s64 + 25516;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAC20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25484
	ctx.r5.s64 = ctx.r7.s64 + 25484;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25448
	ctx.r5.s64 = ctx.r7.s64 + 25448;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAC80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25416
	ctx.r5.s64 = ctx.r7.s64 + 25416;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AACB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25380
	ctx.r5.s64 = ctx.r7.s64 + 25380;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AACE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25348
	ctx.r5.s64 = ctx.r7.s64 + 25348;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAD10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r6,25312
	ctx.r5.s64 = ctx.r6.s64 + 25312;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r9,r7
	r27.u64 = ctx.r9.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823AAD40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// and r27,r3,r11
	r27.u64 = ctx.r3.u64 & r11.u64;
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,25280
	ctx.r5.s64 = ctx.r10.s64 + 25280;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823AAD70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r27,r7,r6
	r27.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r5,25244
	ctx.r5.s64 = ctx.r5.s64 + 25244;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AADA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25212
	ctx.r5.s64 = ctx.r7.s64 + 25212;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AADD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25176
	ctx.r5.s64 = ctx.r7.s64 + 25176;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAE00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25144
	ctx.r5.s64 = ctx.r7.s64 + 25144;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAE30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25108
	ctx.r5.s64 = ctx.r7.s64 + 25108;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAE60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,25076
	ctx.r5.s64 = ctx.r7.s64 + 25076;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAE90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25040
	ctx.r5.s64 = ctx.r7.s64 + 25040;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAEC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,25008
	ctx.r5.s64 = ctx.r7.s64 + 25008;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAEF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24972
	ctx.r5.s64 = ctx.r7.s64 + 24972;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24936
	ctx.r5.s64 = ctx.r7.s64 + 24936;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAF50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,24900
	ctx.r5.s64 = ctx.r7.s64 + 24900;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAF80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r9,24864
	ctx.r5.s64 = ctx.r9.s64 + 24864;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r8,r7
	r27.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,24828
	ctx.r5.s64 = ctx.r7.s64 + 24828;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AAFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24792
	ctx.r5.s64 = ctx.r7.s64 + 24792;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24756
	ctx.r5.s64 = ctx.r7.s64 + 24756;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24720
	ctx.r5.s64 = ctx.r7.s64 + 24720;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24684
	ctx.r5.s64 = ctx.r7.s64 + 24684;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24648
	ctx.r5.s64 = ctx.r7.s64 + 24648;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24612
	ctx.r5.s64 = ctx.r7.s64 + 24612;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB100;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,24576
	ctx.r5.s64 = ctx.r7.s64 + 24576;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24540
	ctx.r5.s64 = ctx.r7.s64 + 24540;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24508
	ctx.r5.s64 = ctx.r7.s64 + 24508;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24472
	ctx.r5.s64 = ctx.r7.s64 + 24472;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB1C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24440
	ctx.r5.s64 = ctx.r7.s64 + 24440;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24404
	ctx.r5.s64 = ctx.r7.s64 + 24404;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r6,24372
	ctx.r5.s64 = ctx.r6.s64 + 24372;
	// lwz r8,24(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r9,r7
	r27.u64 = ctx.r9.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823AB250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// and r27,r3,r11
	r27.u64 = ctx.r3.u64 & r11.u64;
	// lwz r9,24(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,24336
	ctx.r5.s64 = ctx.r10.s64 + 24336;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823AB280;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r27,24
	ctx.r6.u64 = r27.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r27,r7,r6
	r27.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r5,24304
	ctx.r5.s64 = ctx.r5.s64 + 24304;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24268
	ctx.r5.s64 = ctx.r7.s64 + 24268;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB2E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24236
	ctx.r5.s64 = ctx.r7.s64 + 24236;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24200
	ctx.r5.s64 = ctx.r7.s64 + 24200;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24168
	ctx.r5.s64 = ctx.r7.s64 + 24168;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,24132
	ctx.r5.s64 = ctx.r7.s64 + 24132;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB3A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24100
	ctx.r5.s64 = ctx.r7.s64 + 24100;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB3D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,24064
	ctx.r5.s64 = ctx.r7.s64 + 24064;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,24032
	ctx.r5.s64 = ctx.r7.s64 + 24032;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,29016
	ctx.r5.s64 = ctx.r7.s64 + 29016;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28996
	ctx.r5.s64 = ctx.r7.s64 + 28996;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB490;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// addi r5,r9,28976
	ctx.r5.s64 = ctx.r9.s64 + 28976;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// and r27,r8,r7
	r27.u64 = ctx.r8.u64 & ctx.r7.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB4C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r7,28956
	ctx.r5.s64 = ctx.r7.s64 + 28956;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28940
	ctx.r5.s64 = ctx.r7.s64 + 28940;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB520;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,28920
	ctx.r5.s64 = ctx.r7.s64 + 28920;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23648
	ctx.r5.s64 = ctx.r7.s64 + 23648;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r27,24
	ctx.r8.u64 = r27.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r27,r9,r8
	r27.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23708
	ctx.r5.s64 = ctx.r7.s64 + 23708;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// clrlwi r9,r27,24
	ctx.r9.u64 = r27.u32 & 0xFF;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// addi r25,r11,-23012
	r25.s64 = r11.s64 + -23012;
	// and r26,r10,r9
	r26.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r27,r25,-20
	r27.s64 = r25.s64 + -20;
loc_823AB5C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823AB5E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r25,-20
	r11.s64 = r25.s64 + -20;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r7,r11,20
	ctx.r7.s64 = r11.s64 + 20;
	// and r26,r9,r8
	r26.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmpw cr6,r27,r7
	cr6.compare<int32_t>(r27.s32, ctx.r7.s32, xer);
	// blt cr6,0x823ab5c8
	if (cr6.lt) goto loc_823AB5C8;
	// mr r27,r25
	r27.u64 = r25.u64;
loc_823AB60C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823AB62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r7,r25,20
	ctx.r7.s64 = r25.s64 + 20;
	// and r26,r9,r8
	r26.u64 = ctx.r9.u64 & ctx.r8.u64;
	// cmpw cr6,r27,r7
	cr6.compare<int32_t>(r27.s32, ctx.r7.s32, xer);
	// blt cr6,0x823ab60c
	if (cr6.lt) goto loc_823AB60C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,28900
	ctx.r5.s64 = ctx.r10.s64 + 28900;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823AB66C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r6,r26,24
	ctx.r6.u64 = r26.u32 & 0xFF;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// and r29,r7,r6
	r29.u64 = ctx.r7.u64 & ctx.r6.u64;
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// addi r5,r5,28884
	ctx.r5.s64 = ctx.r5.s64 + 28884;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,21896
	ctx.r5.s64 = ctx.r7.s64 + 21896;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB6CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23500
	ctx.r5.s64 = ctx.r7.s64 + 23500;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB6FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22112
	ctx.r5.s64 = ctx.r7.s64 + 22112;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB72C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,28868
	ctx.r5.s64 = ctx.r7.s64 + 28868;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,23688
	ctx.r5.s64 = ctx.r7.s64 + 23688;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB78C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// addi r5,r7,23668
	ctx.r5.s64 = ctx.r7.s64 + 23668;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB7BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22536
	ctx.r5.s64 = ctx.r7.s64 + 22536;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB7EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// addi r5,r7,22516
	ctx.r5.s64 = ctx.r7.s64 + 22516;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r5,r7,22476
	ctx.r5.s64 = ctx.r7.s64 + 22476;
loc_823AB824:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r29,24
	ctx.r8.u64 = r29.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// and r29,r9,r8
	r29.u64 = ctx.r9.u64 & ctx.r8.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823AB84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// and r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 & ctx.r9.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823AB860"))) PPC_WEAK_FUNC(sub_823AB860);
PPC_FUNC_IMPL(__imp__sub_823AB860) {
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
	ctx.lr = 0x823AB868;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r9,26214
	ctx.r9.s64 = 1717960704;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// ori r30,r9,26215
	r30.u64 = ctx.r9.u64 | 26215;
	// addi r29,r10,-23052
	r29.s64 = ctx.r10.s64 + -23052;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r27,r5,24
	r27.u64 = ctx.r5.u32 & 0xFF;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// mulhw r7,r8,r30
	ctx.r7.s64 = (int64_t(ctx.r8.s32) * int64_t(r30.s32)) >> 32;
	// srawi r10,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r3,r29
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + r29.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// beq cr6,0x823ab8e4
	if (cr6.eq) goto loc_823AB8E4;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,23384
	ctx.r4.s64 = r11.s64 + 23384;
	// bl 0x823d90b0
	ctx.lr = 0x823AB8D4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823ab8fc
	if (!cr6.eq) goto loc_823AB8FC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x823ab92c
	if (!cr6.eq) goto loc_823AB92C;
loc_823AB8E4:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,23372
	ctx.r4.s64 = r11.s64 + 23372;
	// bl 0x823d90b0
	ctx.lr = 0x823AB8F4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ab92c
	if (cr6.eq) goto loc_823AB92C;
loc_823AB8FC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulhw r10,r11,r30
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(r30.s32)) >> 32;
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r7,r11
	ctx.r6.s64 = r11.s64 - ctx.r7.s64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r28,r5,r29
	r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + r29.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
loc_823AB92C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x823b7d68
	ctx.lr = 0x823AB950;
	sub_823B7D68(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823AB958"))) PPC_WEAK_FUNC(sub_823AB958);
PPC_FUNC_IMPL(__imp__sub_823AB958) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// ori r5,r8,26215
	ctx.r5.u64 = ctx.r8.u64 | 26215;
	// addi r4,r7,-23032
	ctx.r4.s64 = ctx.r7.s64 + -23032;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r5,r6,r5
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// addi r5,r7,-11512
	ctx.r5.s64 = ctx.r7.s64 + -11512;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823AB9BC"))) PPC_WEAK_FUNC(sub_823AB9BC);
PPC_FUNC_IMPL(__imp__sub_823AB9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AB9C0"))) PPC_WEAK_FUNC(sub_823AB9C0);
PPC_FUNC_IMPL(__imp__sub_823AB9C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// ori r5,r8,26215
	ctx.r5.u64 = ctx.r8.u64 | 26215;
	// addi r4,r7,-23012
	ctx.r4.s64 = ctx.r7.s64 + -23012;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// mulhw r5,r6,r5
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// addi r5,r7,-11512
	ctx.r5.s64 = ctx.r7.s64 + -11512;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABA24"))) PPC_WEAK_FUNC(sub_823ABA24);
PPC_FUNC_IMPL(__imp__sub_823ABA24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABA28"))) PPC_WEAK_FUNC(sub_823ABA28);
PPC_FUNC_IMPL(__imp__sub_823ABA28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r6,r9,-22992
	ctx.r6.s64 = ctx.r9.s64 + -22992;
	// addi r8,r8,-11512
	ctx.r8.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r5,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 2;
	// addze r9,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABA78"))) PPC_WEAK_FUNC(sub_823ABA78);
PPC_FUNC_IMPL(__imp__sub_823ABA78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r6,r9,-22976
	ctx.r6.s64 = ctx.r9.s64 + -22976;
	// addi r8,r8,-11512
	ctx.r8.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r5,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 2;
	// addze r9,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABAC8"))) PPC_WEAK_FUNC(sub_823ABAC8);
PPC_FUNC_IMPL(__imp__sub_823ABAC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r6,r9,-22960
	ctx.r6.s64 = ctx.r9.s64 + -22960;
	// addi r8,r8,-11512
	ctx.r8.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r5,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// addze r9,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABB18"))) PPC_WEAK_FUNC(sub_823ABB18);
PPC_FUNC_IMPL(__imp__sub_823ABB18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// addi r6,r9,-22952
	ctx.r6.s64 = ctx.r9.s64 + -22952;
	// addi r8,r8,-11512
	ctx.r8.s64 = ctx.r8.s64 + -11512;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// srawi r5,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 1;
	// addze r9,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r4,r5,r7
	ctx.r4.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABB68"))) PPC_WEAK_FUNC(sub_823ABB68);
PPC_FUNC_IMPL(__imp__sub_823ABB68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823abb84
	if (cr6.eq) goto loc_823ABB84;
	// li r5,1
	ctx.r5.s64 = 1;
loc_823ABB84:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r10,-22944
	ctx.r9.s64 = ctx.r10.s64 + -22944;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r4,r8
	r11.s64 = ctx.r8.s64 - ctx.r4.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABBB8"))) PPC_WEAK_FUNC(sub_823ABBB8);
PPC_FUNC_IMPL(__imp__sub_823ABBB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,-11512
	ctx.r10.s64 = r11.s64 + -11512;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823abbd4
	if (cr6.eq) goto loc_823ABBD4;
	// li r5,1
	ctx.r5.s64 = 1;
loc_823ABBD4:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lwz r4,-22936(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22936);
	// b 0x823b7d68
	sub_823B7D68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823ABBEC"))) PPC_WEAK_FUNC(sub_823ABBEC);
PPC_FUNC_IMPL(__imp__sub_823ABBEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABBF0"))) PPC_WEAK_FUNC(sub_823ABBF0);
PPC_FUNC_IMPL(__imp__sub_823ABBF0) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,24004
	ctx.r10.s64 = r11.s64 + 24004;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b8248
	ctx.lr = 0x823ABC1C;
	sub_823B8248(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823abc34
	if (cr6.eq) goto loc_823ABC34;
	// bl 0x82130588
	ctx.lr = 0x823ABC30;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823ABC34:
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

__attribute__((alias("__imp__sub_823ABC4C"))) PPC_WEAK_FUNC(sub_823ABC4C);
PPC_FUNC_IMPL(__imp__sub_823ABC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABC50"))) PPC_WEAK_FUNC(sub_823ABC50);
PPC_FUNC_IMPL(__imp__sub_823ABC50) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,49(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 49);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC58"))) PPC_WEAK_FUNC(sub_823ABC58);
PPC_FUNC_IMPL(__imp__sub_823ABC58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC60"))) PPC_WEAK_FUNC(sub_823ABC60);
PPC_FUNC_IMPL(__imp__sub_823ABC60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC68"))) PPC_WEAK_FUNC(sub_823ABC68);
PPC_FUNC_IMPL(__imp__sub_823ABC68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,64(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC78"))) PPC_WEAK_FUNC(sub_823ABC78);
PPC_FUNC_IMPL(__imp__sub_823ABC78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC80"))) PPC_WEAK_FUNC(sub_823ABC80);
PPC_FUNC_IMPL(__imp__sub_823ABC80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC88"))) PPC_WEAK_FUNC(sub_823ABC88);
PPC_FUNC_IMPL(__imp__sub_823ABC88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC90"))) PPC_WEAK_FUNC(sub_823ABC90);
PPC_FUNC_IMPL(__imp__sub_823ABC90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABC98"))) PPC_WEAK_FUNC(sub_823ABC98);
PPC_FUNC_IMPL(__imp__sub_823ABC98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCA0"))) PPC_WEAK_FUNC(sub_823ABCA0);
PPC_FUNC_IMPL(__imp__sub_823ABCA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCB4"))) PPC_WEAK_FUNC(sub_823ABCB4);
PPC_FUNC_IMPL(__imp__sub_823ABCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABCB8"))) PPC_WEAK_FUNC(sub_823ABCB8);
PPC_FUNC_IMPL(__imp__sub_823ABCB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCCC"))) PPC_WEAK_FUNC(sub_823ABCCC);
PPC_FUNC_IMPL(__imp__sub_823ABCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABCD0"))) PPC_WEAK_FUNC(sub_823ABCD0);
PPC_FUNC_IMPL(__imp__sub_823ABCD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCDC"))) PPC_WEAK_FUNC(sub_823ABCDC);
PPC_FUNC_IMPL(__imp__sub_823ABCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABCE0"))) PPC_WEAK_FUNC(sub_823ABCE0);
PPC_FUNC_IMPL(__imp__sub_823ABCE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,28,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCEC"))) PPC_WEAK_FUNC(sub_823ABCEC);
PPC_FUNC_IMPL(__imp__sub_823ABCEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABCF0"))) PPC_WEAK_FUNC(sub_823ABCF0);
PPC_FUNC_IMPL(__imp__sub_823ABCF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,5,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABCFC"))) PPC_WEAK_FUNC(sub_823ABCFC);
PPC_FUNC_IMPL(__imp__sub_823ABCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD00"))) PPC_WEAK_FUNC(sub_823ABD00);
PPC_FUNC_IMPL(__imp__sub_823ABD00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,7,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD0C"))) PPC_WEAK_FUNC(sub_823ABD0C);
PPC_FUNC_IMPL(__imp__sub_823ABD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD10"))) PPC_WEAK_FUNC(sub_823ABD10);
PPC_FUNC_IMPL(__imp__sub_823ABD10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,9,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 9) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD1C"))) PPC_WEAK_FUNC(sub_823ABD1C);
PPC_FUNC_IMPL(__imp__sub_823ABD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD20"))) PPC_WEAK_FUNC(sub_823ABD20);
PPC_FUNC_IMPL(__imp__sub_823ABD20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD2C"))) PPC_WEAK_FUNC(sub_823ABD2C);
PPC_FUNC_IMPL(__imp__sub_823ABD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD30"))) PPC_WEAK_FUNC(sub_823ABD30);
PPC_FUNC_IMPL(__imp__sub_823ABD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,2,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD3C"))) PPC_WEAK_FUNC(sub_823ABD3C);
PPC_FUNC_IMPL(__imp__sub_823ABD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD40"))) PPC_WEAK_FUNC(sub_823ABD40);
PPC_FUNC_IMPL(__imp__sub_823ABD40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,20,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD4C"))) PPC_WEAK_FUNC(sub_823ABD4C);
PPC_FUNC_IMPL(__imp__sub_823ABD4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD50"))) PPC_WEAK_FUNC(sub_823ABD50);
PPC_FUNC_IMPL(__imp__sub_823ABD50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD5C"))) PPC_WEAK_FUNC(sub_823ABD5C);
PPC_FUNC_IMPL(__imp__sub_823ABD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD60"))) PPC_WEAK_FUNC(sub_823ABD60);
PPC_FUNC_IMPL(__imp__sub_823ABD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,24,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD6C"))) PPC_WEAK_FUNC(sub_823ABD6C);
PPC_FUNC_IMPL(__imp__sub_823ABD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD70"))) PPC_WEAK_FUNC(sub_823ABD70);
PPC_FUNC_IMPL(__imp__sub_823ABD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD88"))) PPC_WEAK_FUNC(sub_823ABD88);
PPC_FUNC_IMPL(__imp__sub_823ABD88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,19,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 19) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABD94"))) PPC_WEAK_FUNC(sub_823ABD94);
PPC_FUNC_IMPL(__imp__sub_823ABD94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABD98"))) PPC_WEAK_FUNC(sub_823ABD98);
PPC_FUNC_IMPL(__imp__sub_823ABD98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,17,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 17) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDA4"))) PPC_WEAK_FUNC(sub_823ABDA4);
PPC_FUNC_IMPL(__imp__sub_823ABDA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDA8"))) PPC_WEAK_FUNC(sub_823ABDA8);
PPC_FUNC_IMPL(__imp__sub_823ABDA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,15,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDB4"))) PPC_WEAK_FUNC(sub_823ABDB4);
PPC_FUNC_IMPL(__imp__sub_823ABDB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDB8"))) PPC_WEAK_FUNC(sub_823ABDB8);
PPC_FUNC_IMPL(__imp__sub_823ABDB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,14,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDC4"))) PPC_WEAK_FUNC(sub_823ABDC4);
PPC_FUNC_IMPL(__imp__sub_823ABDC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDC8"))) PPC_WEAK_FUNC(sub_823ABDC8);
PPC_FUNC_IMPL(__imp__sub_823ABDC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,4,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDD4"))) PPC_WEAK_FUNC(sub_823ABDD4);
PPC_FUNC_IMPL(__imp__sub_823ABDD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDD8"))) PPC_WEAK_FUNC(sub_823ABDD8);
PPC_FUNC_IMPL(__imp__sub_823ABDD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,3,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDE4"))) PPC_WEAK_FUNC(sub_823ABDE4);
PPC_FUNC_IMPL(__imp__sub_823ABDE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDE8"))) PPC_WEAK_FUNC(sub_823ABDE8);
PPC_FUNC_IMPL(__imp__sub_823ABDE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,10,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABDF4"))) PPC_WEAK_FUNC(sub_823ABDF4);
PPC_FUNC_IMPL(__imp__sub_823ABDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABDF8"))) PPC_WEAK_FUNC(sub_823ABDF8);
PPC_FUNC_IMPL(__imp__sub_823ABDF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,23,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE04"))) PPC_WEAK_FUNC(sub_823ABE04);
PPC_FUNC_IMPL(__imp__sub_823ABE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE08"))) PPC_WEAK_FUNC(sub_823ABE08);
PPC_FUNC_IMPL(__imp__sub_823ABE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE14"))) PPC_WEAK_FUNC(sub_823ABE14);
PPC_FUNC_IMPL(__imp__sub_823ABE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE18"))) PPC_WEAK_FUNC(sub_823ABE18);
PPC_FUNC_IMPL(__imp__sub_823ABE18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,31,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE24"))) PPC_WEAK_FUNC(sub_823ABE24);
PPC_FUNC_IMPL(__imp__sub_823ABE24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE28"))) PPC_WEAK_FUNC(sub_823ABE28);
PPC_FUNC_IMPL(__imp__sub_823ABE28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE34"))) PPC_WEAK_FUNC(sub_823ABE34);
PPC_FUNC_IMPL(__imp__sub_823ABE34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE38"))) PPC_WEAK_FUNC(sub_823ABE38);
PPC_FUNC_IMPL(__imp__sub_823ABE38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-19
	r11.s64 = r11.s64 + -19;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE4C"))) PPC_WEAK_FUNC(sub_823ABE4C);
PPC_FUNC_IMPL(__imp__sub_823ABE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE50"))) PPC_WEAK_FUNC(sub_823ABE50);
PPC_FUNC_IMPL(__imp__sub_823ABE50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-20
	r11.s64 = r11.s64 + -20;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE64"))) PPC_WEAK_FUNC(sub_823ABE64);
PPC_FUNC_IMPL(__imp__sub_823ABE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABE68"))) PPC_WEAK_FUNC(sub_823ABE68);
PPC_FUNC_IMPL(__imp__sub_823ABE68) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,73(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 73);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE70"))) PPC_WEAK_FUNC(sub_823ABE70);
PPC_FUNC_IMPL(__imp__sub_823ABE70) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,74(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 74);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE78"))) PPC_WEAK_FUNC(sub_823ABE78);
PPC_FUNC_IMPL(__imp__sub_823ABE78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,148(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE80"))) PPC_WEAK_FUNC(sub_823ABE80);
PPC_FUNC_IMPL(__imp__sub_823ABE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE88"))) PPC_WEAK_FUNC(sub_823ABE88);
PPC_FUNC_IMPL(__imp__sub_823ABE88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE90"))) PPC_WEAK_FUNC(sub_823ABE90);
PPC_FUNC_IMPL(__imp__sub_823ABE90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABE98"))) PPC_WEAK_FUNC(sub_823ABE98);
PPC_FUNC_IMPL(__imp__sub_823ABE98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABEA0"))) PPC_WEAK_FUNC(sub_823ABEA0);
PPC_FUNC_IMPL(__imp__sub_823ABEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABEA8"))) PPC_WEAK_FUNC(sub_823ABEA8);
PPC_FUNC_IMPL(__imp__sub_823ABEA8) {
	PPC_FUNC_PROLOGUE();
	// fabs f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABEB0"))) PPC_WEAK_FUNC(sub_823ABEB0);
PPC_FUNC_IMPL(__imp__sub_823ABEB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// fsubs f0,f1,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fsel f1,f0,f2,f1
	ctx.f1.f64 = f0.f64 >= 0.0 ? ctx.f2.f64 : ctx.f1.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABEBC"))) PPC_WEAK_FUNC(sub_823ABEBC);
PPC_FUNC_IMPL(__imp__sub_823ABEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABEC0"))) PPC_WEAK_FUNC(sub_823ABEC0);
PPC_FUNC_IMPL(__imp__sub_823ABEC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	// fsubs f0,f1,f2
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fsel f1,f0,f1,f2
	ctx.f1.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f2.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABECC"))) PPC_WEAK_FUNC(sub_823ABECC);
PPC_FUNC_IMPL(__imp__sub_823ABECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABED0"))) PPC_WEAK_FUNC(sub_823ABED0);
PPC_FUNC_IMPL(__imp__sub_823ABED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABED8"))) PPC_WEAK_FUNC(sub_823ABED8);
PPC_FUNC_IMPL(__imp__sub_823ABED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABEE0"))) PPC_WEAK_FUNC(sub_823ABEE0);
PPC_FUNC_IMPL(__imp__sub_823ABEE0) {
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
	// bl 0x823b7570
	ctx.lr = 0x823ABEF8;
	sub_823B7570(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,29392
	ctx.r9.s64 = ctx.r10.s64 + 29392;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ABF3C"))) PPC_WEAK_FUNC(sub_823ABF3C);
PPC_FUNC_IMPL(__imp__sub_823ABF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABF40"))) PPC_WEAK_FUNC(sub_823ABF40);
PPC_FUNC_IMPL(__imp__sub_823ABF40) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,29392
	ctx.r10.s64 = r11.s64 + 29392;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823b7a18
	ctx.lr = 0x823ABF6C;
	sub_823B7A18(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823abf84
	if (cr6.eq) goto loc_823ABF84;
	// bl 0x82130588
	ctx.lr = 0x823ABF80;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823ABF84:
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

__attribute__((alias("__imp__sub_823ABF9C"))) PPC_WEAK_FUNC(sub_823ABF9C);
PPC_FUNC_IMPL(__imp__sub_823ABF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFA0"))) PPC_WEAK_FUNC(sub_823ABFA0);
PPC_FUNC_IMPL(__imp__sub_823ABFA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,7(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 7);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFAC"))) PPC_WEAK_FUNC(sub_823ABFAC);
PPC_FUNC_IMPL(__imp__sub_823ABFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFB0"))) PPC_WEAK_FUNC(sub_823ABFB0);
PPC_FUNC_IMPL(__imp__sub_823ABFB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFBC"))) PPC_WEAK_FUNC(sub_823ABFBC);
PPC_FUNC_IMPL(__imp__sub_823ABFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFC0"))) PPC_WEAK_FUNC(sub_823ABFC0);
PPC_FUNC_IMPL(__imp__sub_823ABFC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r3,9(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 9);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFCC"))) PPC_WEAK_FUNC(sub_823ABFCC);
PPC_FUNC_IMPL(__imp__sub_823ABFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFD0"))) PPC_WEAK_FUNC(sub_823ABFD0);
PPC_FUNC_IMPL(__imp__sub_823ABFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,92(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFDC"))) PPC_WEAK_FUNC(sub_823ABFDC);
PPC_FUNC_IMPL(__imp__sub_823ABFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFE0"))) PPC_WEAK_FUNC(sub_823ABFE0);
PPC_FUNC_IMPL(__imp__sub_823ABFE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 136);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFEC"))) PPC_WEAK_FUNC(sub_823ABFEC);
PPC_FUNC_IMPL(__imp__sub_823ABFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ABFF0"))) PPC_WEAK_FUNC(sub_823ABFF0);
PPC_FUNC_IMPL(__imp__sub_823ABFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 140);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823ABFFC"))) PPC_WEAK_FUNC(sub_823ABFFC);
PPC_FUNC_IMPL(__imp__sub_823ABFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC000"))) PPC_WEAK_FUNC(sub_823AC000);
PPC_FUNC_IMPL(__imp__sub_823AC000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 144);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC00C"))) PPC_WEAK_FUNC(sub_823AC00C);
PPC_FUNC_IMPL(__imp__sub_823AC00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC010"))) PPC_WEAK_FUNC(sub_823AC010);
PPC_FUNC_IMPL(__imp__sub_823AC010) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac034
	if (cr6.eq) goto loc_823AC034;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC034:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC03C"))) PPC_WEAK_FUNC(sub_823AC03C);
PPC_FUNC_IMPL(__imp__sub_823AC03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC040"))) PPC_WEAK_FUNC(sub_823AC040);
PPC_FUNC_IMPL(__imp__sub_823AC040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac064
	if (cr6.eq) goto loc_823AC064;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC064:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC06C"))) PPC_WEAK_FUNC(sub_823AC06C);
PPC_FUNC_IMPL(__imp__sub_823AC06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC070"))) PPC_WEAK_FUNC(sub_823AC070);
PPC_FUNC_IMPL(__imp__sub_823AC070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,20,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac094
	if (cr6.eq) goto loc_823AC094;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC094:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC09C"))) PPC_WEAK_FUNC(sub_823AC09C);
PPC_FUNC_IMPL(__imp__sub_823AC09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC0A0"))) PPC_WEAK_FUNC(sub_823AC0A0);
PPC_FUNC_IMPL(__imp__sub_823AC0A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// rlwinm r3,r9,10,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 10) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC0B4"))) PPC_WEAK_FUNC(sub_823AC0B4);
PPC_FUNC_IMPL(__imp__sub_823AC0B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC0B8"))) PPC_WEAK_FUNC(sub_823AC0B8);
PPC_FUNC_IMPL(__imp__sub_823AC0B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ac0e4
	if (cr6.eq) goto loc_823AC0E4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,31492(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31492);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_823AC0E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC0EC"))) PPC_WEAK_FUNC(sub_823AC0EC);
PPC_FUNC_IMPL(__imp__sub_823AC0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC0F0"))) PPC_WEAK_FUNC(sub_823AC0F0);
PPC_FUNC_IMPL(__imp__sub_823AC0F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ac11c
	if (cr6.eq) goto loc_823AC11C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_823AC11C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC124"))) PPC_WEAK_FUNC(sub_823AC124);
PPC_FUNC_IMPL(__imp__sub_823AC124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC128"))) PPC_WEAK_FUNC(sub_823AC128);
PPC_FUNC_IMPL(__imp__sub_823AC128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r3,r10,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC138"))) PPC_WEAK_FUNC(sub_823AC138);
PPC_FUNC_IMPL(__imp__sub_823AC138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ac15c
	if (!cr6.eq) goto loc_823AC15C;
	// rlwinm r11,r11,12,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC15C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC164"))) PPC_WEAK_FUNC(sub_823AC164);
PPC_FUNC_IMPL(__imp__sub_823AC164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC168"))) PPC_WEAK_FUNC(sub_823AC168);
PPC_FUNC_IMPL(__imp__sub_823AC168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac198
	if (cr6.eq) goto loc_823AC198;
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac198
	if (cr6.eq) goto loc_823AC198;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC198:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC1A0"))) PPC_WEAK_FUNC(sub_823AC1A0);
PPC_FUNC_IMPL(__imp__sub_823AC1A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac1d0
	if (cr6.eq) goto loc_823AC1D0;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac1d0
	if (cr6.eq) goto loc_823AC1D0;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC1D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC1D8"))) PPC_WEAK_FUNC(sub_823AC1D8);
PPC_FUNC_IMPL(__imp__sub_823AC1D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac208
	if (cr6.eq) goto loc_823AC208;
	// rlwinm r10,r11,20,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac208
	if (cr6.eq) goto loc_823AC208;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC208:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC210"))) PPC_WEAK_FUNC(sub_823AC210);
PPC_FUNC_IMPL(__imp__sub_823AC210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,18,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ac234
	if (cr6.eq) goto loc_823AC234;
	// rlwinm r11,r11,10,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC234:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC23C"))) PPC_WEAK_FUNC(sub_823AC23C);
PPC_FUNC_IMPL(__imp__sub_823AC23C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC240"))) PPC_WEAK_FUNC(sub_823AC240);
PPC_FUNC_IMPL(__imp__sub_823AC240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,28,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ac278
	if (cr6.eq) goto loc_823AC278;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823ac278
	if (!cr6.gt) goto loc_823AC278;
	// lbz r11,49(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 49);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC278:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC280"))) PPC_WEAK_FUNC(sub_823AC280);
PPC_FUNC_IMPL(__imp__sub_823AC280) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,-19948(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19948);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC2B0"))) PPC_WEAK_FUNC(sub_823AC2B0);
PPC_FUNC_IMPL(__imp__sub_823AC2B0) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x823a7158
	ctx.lr = 0x823AC2C4;
	sub_823A7158(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x823ac2dc
	if (!cr6.gt) goto loc_823AC2DC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823AC2DC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC2EC"))) PPC_WEAK_FUNC(sub_823AC2EC);
PPC_FUNC_IMPL(__imp__sub_823AC2EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC2F0"))) PPC_WEAK_FUNC(sub_823AC2F0);
PPC_FUNC_IMPL(__imp__sub_823AC2F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,14,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ac314
	if (!cr6.eq) goto loc_823AC314;
	// rlwinm r11,r11,16,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x1;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823AC314:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC31C"))) PPC_WEAK_FUNC(sub_823AC31C);
PPC_FUNC_IMPL(__imp__sub_823AC31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC320"))) PPC_WEAK_FUNC(sub_823AC320);
PPC_FUNC_IMPL(__imp__sub_823AC320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// rlwinm r3,r9,9,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 9) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC334"))) PPC_WEAK_FUNC(sub_823AC334);
PPC_FUNC_IMPL(__imp__sub_823AC334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC338"))) PPC_WEAK_FUNC(sub_823AC338);
PPC_FUNC_IMPL(__imp__sub_823AC338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// rlwinm r3,r9,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC34C"))) PPC_WEAK_FUNC(sub_823AC34C);
PPC_FUNC_IMPL(__imp__sub_823AC34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC350"))) PPC_WEAK_FUNC(sub_823AC350);
PPC_FUNC_IMPL(__imp__sub_823AC350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// rlwinm r3,r9,24,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC364"))) PPC_WEAK_FUNC(sub_823AC364);
PPC_FUNC_IMPL(__imp__sub_823AC364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC368"))) PPC_WEAK_FUNC(sub_823AC368);
PPC_FUNC_IMPL(__imp__sub_823AC368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// not r9,r10
	ctx.r9.u64 = ~ctx.r10.u64;
	// rlwinm r3,r9,28,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC37C"))) PPC_WEAK_FUNC(sub_823AC37C);
PPC_FUNC_IMPL(__imp__sub_823AC37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC380"))) PPC_WEAK_FUNC(sub_823AC380);
PPC_FUNC_IMPL(__imp__sub_823AC380) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x823a7228
	ctx.lr = 0x823AC394;
	sub_823A7228(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x823ac3ac
	if (cr6.lt) goto loc_823AC3AC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823AC3AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC3BC"))) PPC_WEAK_FUNC(sub_823AC3BC);
PPC_FUNC_IMPL(__imp__sub_823AC3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC3C0"))) PPC_WEAK_FUNC(sub_823AC3C0);
PPC_FUNC_IMPL(__imp__sub_823AC3C0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,92(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823ac3e8
	if (!cr6.gt) goto loc_823AC3E8;
	// lfs f13,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_823AC3E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC3F0"))) PPC_WEAK_FUNC(sub_823AC3F0);
PPC_FUNC_IMPL(__imp__sub_823AC3F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,25,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ac440
	if (!cr6.eq) goto loc_823AC440;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,-11620(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11620);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823ac440
	if (!cr6.lt) goto loc_823AC440;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bltlr cr6
	if (cr6.lt) return;
loc_823AC440:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC448"))) PPC_WEAK_FUNC(sub_823AC448);
PPC_FUNC_IMPL(__imp__sub_823AC448) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,29432
	ctx.r10.s64 = r11.s64 + 29432;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x823AC478;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ac490
	if (cr6.eq) goto loc_823AC490;
	// bl 0x82130588
	ctx.lr = 0x823AC48C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823AC490:
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

__attribute__((alias("__imp__sub_823AC4A8"))) PPC_WEAK_FUNC(sub_823AC4A8);
PPC_FUNC_IMPL(__imp__sub_823AC4A8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fabs f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823ac4dc
	if (cr6.gt) goto loc_823AC4DC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-31384(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// blr 
	return;
loc_823AC4DC:
	// fneg f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f10.f64 = double(temp.f32);
	// fsel f7,f9,f12,f13
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fmadds f6,f8,f0,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f11.f64));
	// fsel f5,f1,f7,f10
	ctx.f5.f64 = ctx.f1.f64 >= 0.0 ? ctx.f7.f64 : ctx.f10.f64;
	// fmuls f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f6.f64));
	// fadds f3,f4,f13
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f13.f64));
	// fmuls f1,f3,f0
	ctx.f1.f64 = double(float(ctx.f3.f64 * f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC51C"))) PPC_WEAK_FUNC(sub_823AC51C);
PPC_FUNC_IMPL(__imp__sub_823AC51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC520"))) PPC_WEAK_FUNC(sub_823AC520);
PPC_FUNC_IMPL(__imp__sub_823AC520) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b7890
	ctx.lr = 0x823AC548;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AC554;
	sub_823A5E30(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,23320
	ctx.r4.s64 = ctx.r10.s64 + 23320;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AC568;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823AC584;
	sub_823A5C10(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,132(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 132);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823AC594;
	sub_823A3558(ctx, base);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// lfs f0,128(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r6)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r6.u32 + 56, temp.u32);
	// stfs f0,60(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 60, temp.u32);
	// stb r7,45(r31)
	PPC_STORE_U8(r31.u32 + 45, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_823AC5CC"))) PPC_WEAK_FUNC(sub_823AC5CC);
PPC_FUNC_IMPL(__imp__sub_823AC5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC5D0"))) PPC_WEAK_FUNC(sub_823AC5D0);
PPC_FUNC_IMPL(__imp__sub_823AC5D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x823AC5D8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,132(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 132);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a3558
	ctx.lr = 0x823AC5F4;
	sub_823A3558(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r9,r11,13,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ac620
	if (!cr6.eq) goto loc_823AC620;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ac620
	if (!cr6.eq) goto loc_823AC620;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f31,-3164(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3164);
	f31.f64 = double(temp.f32);
	// b 0x823ac628
	goto loc_823AC628;
loc_823AC620:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823AC628:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ac66c
	if (cr6.eq) goto loc_823AC66C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AC640;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AC64C;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23188
	ctx.r4.s64 = r11.s64 + 23188;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AC660;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23212
	ctx.r4.s64 = ctx.r10.s64 + 23212;
	// b 0x823ac6e4
	goto loc_823AC6E4;
loc_823AC66C:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// bl 0x823b7890
	ctx.lr = 0x823AC680;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AC68C;
	sub_823A5E30(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-11572
	ctx.r9.s64 = ctx.r10.s64 + -11572;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// beq cr6,0x823ac6d0
	if (cr6.eq) goto loc_823AC6D0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r29,r11,23256
	r29.s64 = r11.s64 + 23256;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AC6B8;
	sub_823B87D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AC6C8;
	sub_823B87D8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// b 0x823ac6f4
	goto loc_823AC6F4;
loc_823AC6D0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23236
	ctx.r4.s64 = r11.s64 + 23236;
	// bl 0x823b87d8
	ctx.lr = 0x823AC6DC;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23256
	ctx.r4.s64 = ctx.r10.s64 + 23256;
loc_823AC6E4:
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AC6F0;
	sub_823B87D8(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
loc_823AC6F4:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e50
	ctx.lr = 0x823AC708;
	sub_823A5E50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6f38
	ctx.lr = 0x823AC71C;
	sub_823A6F38(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stfs f31,148(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 148, temp.u32);
	// lfs f1,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6fc0
	ctx.lr = 0x823AC734;
	sub_823A6FC0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a4b38
	ctx.lr = 0x823AC744;
	sub_823A4B38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823AC750"))) PPC_WEAK_FUNC(sub_823AC750);
PPC_FUNC_IMPL(__imp__sub_823AC750) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d8
	ctx.lr = 0x823AC764;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823AC778;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// bl 0x823a6fc0
	ctx.lr = 0x823AC784;
	sub_823A6FC0(ctx, base);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,96(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lfs f0,29424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29424);
	f0.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,29420(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29420);
	ctx.f13.f64 = double(temp.f32);
	// lfs f28,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f28.f64 = double(temp.f32);
	// addi r5,r6,-11612
	ctx.r5.s64 = ctx.r6.s64 + -11612;
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fsel f9,f10,f10,f28
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f28.f64;
	// fsubs f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fsel f30,f8,f31,f9
	f30.f64 = ctx.f8.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// beq cr6,0x823ac7d8
	if (cr6.eq) goto loc_823AC7D8;
	// fmr f30,f31
	f30.f64 = f31.f64;
loc_823AC7D8:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x823a4b38
	ctx.lr = 0x823AC7E4;
	sub_823A4B38(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,32680(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	f0.f64 = double(temp.f32);
	// lfs f13,29416(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29416);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f30,f0,f31
	f0.f64 = double(float(-(f30.f64 * f0.f64 - f31.f64)));
	// stfs f0,52(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// fcmpu cr6,f29,f13
	cr6.compare(f29.f64, ctx.f13.f64);
	// blt cr6,0x823ac81c
	if (cr6.lt) goto loc_823AC81C;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f0,29412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29412);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// ble cr6,0x823ac820
	if (!cr6.gt) goto loc_823AC820;
loc_823AC81C:
	// li r10,1
	ctx.r10.s64 = 1;
loc_823AC820:
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f12,f28
	cr6.compare(ctx.f12.f64, f28.f64);
	// beq cr6,0x823ac84c
	if (cr6.eq) goto loc_823AC84C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,56(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// b 0x823ac85c
	goto loc_823AC85C;
loc_823AC84C:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f0,128(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,56(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
loc_823AC85C:
	// stfs f0,60(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ac878
	if (cr6.eq) goto loc_823AC878;
	// stfs f28,152(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
loc_823AC878:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba24
	ctx.lr = 0x823AC884;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AC894"))) PPC_WEAK_FUNC(sub_823AC894);
PPC_FUNC_IMPL(__imp__sub_823AC894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AC898"))) PPC_WEAK_FUNC(sub_823AC898);
PPC_FUNC_IMPL(__imp__sub_823AC898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823AC8A0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AC8B8;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AC8C4;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ac8f0
	if (!cr6.eq) goto loc_823AC8F0;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ac8f0
	if (!cr6.eq) goto loc_823AC8F0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f31,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823ac8f8
	goto loc_823AC8F8;
loc_823AC8F0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823AC8F8:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ac924
	if (cr6.eq) goto loc_823AC924;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23188
	ctx.r4.s64 = r11.s64 + 23188;
	// bl 0x823b87d8
	ctx.lr = 0x823AC918;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23212
	ctx.r4.s64 = ctx.r10.s64 + 23212;
	// b 0x823ac938
	goto loc_823AC938;
loc_823AC924:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23140
	ctx.r4.s64 = r11.s64 + 23140;
	// bl 0x823b87d8
	ctx.lr = 0x823AC930;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23164
	ctx.r4.s64 = ctx.r10.s64 + 23164;
loc_823AC938:
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AC944;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e50
	ctx.lr = 0x823AC95C;
	sub_823A5E50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6f38
	ctx.lr = 0x823AC96C;
	sub_823A6F38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823AC978"))) PPC_WEAK_FUNC(sub_823AC978);
PPC_FUNC_IMPL(__imp__sub_823AC978) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x823AC990;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823AC9A4;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6fc0
	ctx.lr = 0x823AC9AC;
	sub_823A6FC0(ctx, base);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f30,29424(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29424);
	f30.f64 = double(temp.f32);
	// lfs f0,96(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r30,r11,-11612
	r30.s64 = r11.s64 + -11612;
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// lfs f29,29420(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29420);
	f29.f64 = double(temp.f32);
	// lfs f28,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmuls f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64));
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsel f11,f12,f12,f28
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f28.f64;
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f1,f10,f31,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// beq cr6,0x823aca00
	if (cr6.eq) goto loc_823ACA00;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
loc_823ACA00:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a4b38
	ctx.lr = 0x823ACA08;
	sub_823A4B38(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// fmuls f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64));
	// fsel f11,f12,f12,f28
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f28.f64;
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f0,f10,f31,f11
	f0.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : ctx.f11.f64;
	// beq cr6,0x823aca34
	if (cr6.eq) goto loc_823ACA34;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_823ACA34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f13,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f13,f31
	f0.f64 = double(float(-(f0.f64 * ctx.f13.f64 - f31.f64)));
	// stfs f0,52(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lfs f13,128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,124(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,56(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 56, temp.u32);
	// stfs f13,60(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 60, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x823ACA68;
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

__attribute__((alias("__imp__sub_823ACA7C"))) PPC_WEAK_FUNC(sub_823ACA7C);
PPC_FUNC_IMPL(__imp__sub_823ACA7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ACA80"))) PPC_WEAK_FUNC(sub_823ACA80);
PPC_FUNC_IMPL(__imp__sub_823ACA80) {
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
	ctx.lr = 0x823ACA88;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823ACAA0;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ACAAC;
	sub_823A5E30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r8,r9,13,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823acaec
	if (!cr6.eq) goto loc_823ACAEC;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,12,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823acaec
	if (!cr6.eq) goto loc_823ACAEC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f31,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823acaf4
	goto loc_823ACAF4;
loc_823ACAEC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823ACAF4:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,11,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823acb38
	if (cr6.eq) goto loc_823ACB38;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r29,r11,22832
	r29.s64 = r11.s64 + 22832;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823ACB20;
	sub_823B87D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823ACB30;
	sub_823B87D8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// b 0x823acb5c
	goto loc_823ACB5C;
loc_823ACB38:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23256
	ctx.r4.s64 = r11.s64 + 23256;
	// bl 0x823b87d8
	ctx.lr = 0x823ACB44;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,22916
	ctx.r4.s64 = ctx.r10.s64 + 22916;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823ACB58;
	sub_823B87D8(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
loc_823ACB5C:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e50
	ctx.lr = 0x823ACB70;
	sub_823A5E50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6f38
	ctx.lr = 0x823ACB84;
	sub_823A6F38(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 148, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823ACB98"))) PPC_WEAK_FUNC(sub_823ACB98);
PPC_FUNC_IMPL(__imp__sub_823ACB98) {
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
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823ACBB8;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6fc0
	ctx.lr = 0x823ACBC0;
	sub_823A6FC0(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fsel f1,f10,f13,f11
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// bl 0x823a4b38
	ctx.lr = 0x823ACBEC;
	sub_823A4B38(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ACC00"))) PPC_WEAK_FUNC(sub_823ACC00);
PPC_FUNC_IMPL(__imp__sub_823ACC00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823ACC28;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ACC34;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acc60
	if (!cr6.eq) goto loc_823ACC60;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acc60
	if (!cr6.eq) goto loc_823ACC60;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f31,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823acc68
	goto loc_823ACC68;
loc_823ACC60:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823ACC68:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823acc88
	if (cr6.eq) goto loc_823ACC88;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22816
	ctx.r4.s64 = r11.s64 + 22816;
	// b 0x823acc90
	goto loc_823ACC90;
loc_823ACC88:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22904
	ctx.r4.s64 = r11.s64 + 22904;
loc_823ACC90:
	// bl 0x823b87d8
	ctx.lr = 0x823ACC94;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823ACCAC;
	sub_823A5C10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823ACCBC;
	sub_823A6EE0(ctx, base);
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

__attribute__((alias("__imp__sub_823ACCD8"))) PPC_WEAK_FUNC(sub_823ACCD8);
PPC_FUNC_IMPL(__imp__sub_823ACCD8) {
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
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823ACCF8;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6e58
	ctx.lr = 0x823ACD00;
	sub_823A6E58(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// lfs f13,29424(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29424);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r6,-11612
	ctx.r5.s64 = ctx.r6.s64 + -11612;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f12,29420(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29420);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsel f7,f8,f8,f11
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : ctx.f11.f64;
	// fsubs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 - f0.f64));
	// fsel f13,f6,f0,f7
	ctx.f13.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : ctx.f7.f64;
	// beq cr6,0x823acd60
	if (cr6.eq) goto loc_823ACD60;
	// lfs f13,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f0,f0,f13,f0
	f0.f64 = double(float(-(f0.f64 * ctx.f13.f64 - f0.f64)));
	// b 0x823acd68
	goto loc_823ACD68;
loc_823ACD60:
	// lfs f12,32680(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f0,f13,f12,f0
	f0.f64 = double(float(-(ctx.f13.f64 * ctx.f12.f64 - f0.f64)));
loc_823ACD68:
	// stfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ACD80"))) PPC_WEAK_FUNC(sub_823ACD80);
PPC_FUNC_IMPL(__imp__sub_823ACD80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823ACDA8;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ACDB4;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acde0
	if (!cr6.eq) goto loc_823ACDE0;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acde0
	if (!cr6.eq) goto loc_823ACDE0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f31,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823acde8
	goto loc_823ACDE8;
loc_823ACDE0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823ACDE8:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ace08
	if (cr6.eq) goto loc_823ACE08;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23276
	ctx.r4.s64 = r11.s64 + 23276;
	// b 0x823ace10
	goto loc_823ACE10;
loc_823ACE08:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22888
	ctx.r4.s64 = r11.s64 + 22888;
loc_823ACE10:
	// bl 0x823b87d8
	ctx.lr = 0x823ACE14;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823ACE2C;
	sub_823A5C10(ctx, base);
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

__attribute__((alias("__imp__sub_823ACE48"))) PPC_WEAK_FUNC(sub_823ACE48);
PPC_FUNC_IMPL(__imp__sub_823ACE48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823ACE70;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ACE7C;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acea8
	if (!cr6.eq) goto loc_823ACEA8;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acea8
	if (!cr6.eq) goto loc_823ACEA8;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f31,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823aceb0
	goto loc_823ACEB0;
loc_823ACEA8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823ACEB0:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823aced0
	if (cr6.eq) goto loc_823ACED0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23276
	ctx.r4.s64 = r11.s64 + 23276;
	// b 0x823aced8
	goto loc_823ACED8;
loc_823ACED0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22872
	ctx.r4.s64 = r11.s64 + 22872;
loc_823ACED8:
	// bl 0x823b87d8
	ctx.lr = 0x823ACEDC;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823ACEF4;
	sub_823A5C10(ctx, base);
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

__attribute__((alias("__imp__sub_823ACF10"))) PPC_WEAK_FUNC(sub_823ACF10);
PPC_FUNC_IMPL(__imp__sub_823ACF10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823ACF38;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ACF44;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acf70
	if (!cr6.eq) goto loc_823ACF70;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823acf70
	if (!cr6.eq) goto loc_823ACF70;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f31,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f31.f64 = double(temp.f32);
	// b 0x823acf78
	goto loc_823ACF78;
loc_823ACF70:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823ACF78:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823acf98
	if (cr6.eq) goto loc_823ACF98;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22752
	ctx.r4.s64 = r11.s64 + 22752;
	// b 0x823acfa0
	goto loc_823ACFA0;
loc_823ACF98:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22852
	ctx.r4.s64 = r11.s64 + 22852;
loc_823ACFA0:
	// bl 0x823b87d8
	ctx.lr = 0x823ACFA4;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823ACFBC;
	sub_823A5C10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823ACFCC;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_823ACFF8"))) PPC_WEAK_FUNC(sub_823ACFF8);
PPC_FUNC_IMPL(__imp__sub_823ACFF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r10,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AD00C"))) PPC_WEAK_FUNC(sub_823AD00C);
PPC_FUNC_IMPL(__imp__sub_823AD00C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD010"))) PPC_WEAK_FUNC(sub_823AD010);
PPC_FUNC_IMPL(__imp__sub_823AD010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823AD028;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x823a6e58
	ctx.lr = 0x823AD030;
	sub_823A6E58(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AD040"))) PPC_WEAK_FUNC(sub_823AD040);
PPC_FUNC_IMPL(__imp__sub_823AD040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,11,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ad094
	if (cr6.eq) goto loc_823AD094;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD07C;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD088;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23276
	ctx.r4.s64 = r11.s64 + 23276;
	// b 0x823ad0bc
	goto loc_823AD0BC;
loc_823AD094:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// bl 0x823b7890
	ctx.lr = 0x823AD0A8;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AD0B4;
	sub_823A5E30(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23300
	ctx.r4.s64 = ctx.r10.s64 + 23300;
loc_823AD0BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD0C8;
	sub_823B87D8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a5c10
	ctx.lr = 0x823AD0EC;
	sub_823A5C10(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6ee0
	ctx.lr = 0x823AD0F8;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 148, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AD11C"))) PPC_WEAK_FUNC(sub_823AD11C);
PPC_FUNC_IMPL(__imp__sub_823AD11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD120"))) PPC_WEAK_FUNC(sub_823AD120);
PPC_FUNC_IMPL(__imp__sub_823AD120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ad168
	if (!cr6.eq) goto loc_823AD168;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ad168
	if (!cr6.eq) goto loc_823AD168;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f31,-11316(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11316);
	f31.f64 = double(temp.f32);
	// b 0x823ad170
	goto loc_823AD170;
loc_823AD168:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823AD170:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ad1b0
	if (cr6.eq) goto loc_823AD1B0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823ad18c
	if (cr6.eq) goto loc_823AD18C;
	// bl 0x82224ac8
	ctx.lr = 0x823AD18C;
	sub_82224AC8(ctx, base);
loc_823AD18C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD198;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD1A4;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23276
	ctx.r4.s64 = r11.s64 + 23276;
	// b 0x823ad1e4
	goto loc_823AD1E4;
loc_823AD1B0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823ad1bc
	if (cr6.eq) goto loc_823AD1BC;
	// bl 0x82224ac8
	ctx.lr = 0x823AD1BC;
	sub_82224AC8(ctx, base);
loc_823AD1BC:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// bl 0x823b7890
	ctx.lr = 0x823AD1D0;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AD1DC;
	sub_823A5E30(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23300
	ctx.r4.s64 = ctx.r10.s64 + 23300;
loc_823AD1E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD1F0;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823AD208;
	sub_823A5C10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6ee0
	ctx.lr = 0x823AD21C;
	sub_823A6EE0(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 148, temp.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,152(r9)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 152, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AD248"))) PPC_WEAK_FUNC(sub_823AD248);
PPC_FUNC_IMPL(__imp__sub_823AD248) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r31,32(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r4,r11,29436
	ctx.r4.s64 = r11.s64 + 29436;
	// bl 0x823b7890
	ctx.lr = 0x823AD268;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AD274;
	sub_823A5E30(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823AD288"))) PPC_WEAK_FUNC(sub_823AD288);
PPC_FUNC_IMPL(__imp__sub_823AD288) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f13,31492(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31492);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f12,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f10,f11,f12,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsel f8,f9,f0,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? f0.f64 : ctx.f10.f64;
	// fadds f1,f8,f0
	ctx.f1.f64 = double(float(ctx.f8.f64 + f0.f64));
	// bl 0x823a6e58
	ctx.lr = 0x823AD2D0;
	sub_823A6E58(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lfs f7,128(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,124(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 124);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,56(r8)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r8.u32 + 56, temp.u32);
	// stfs f7,60(r8)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r8.u32 + 60, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823AD2FC"))) PPC_WEAK_FUNC(sub_823AD2FC);
PPC_FUNC_IMPL(__imp__sub_823AD2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD300"))) PPC_WEAK_FUNC(sub_823AD300);
PPC_FUNC_IMPL(__imp__sub_823AD300) {
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
	ctx.lr = 0x823AD308;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,11,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ad360
	if (cr6.eq) goto loc_823AD360;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD334;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD340;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22928
	ctx.r4.s64 = r11.s64 + 22928;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD354;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,22956
	ctx.r4.s64 = ctx.r10.s64 + 22956;
	// b 0x823ad3c0
	goto loc_823AD3C0;
loc_823AD360:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-11572
	ctx.r10.s64 = r11.s64 + -11572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ad3ac
	if (cr6.eq) goto loc_823AD3AC;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r29,r11,23008
	r29.s64 = r11.s64 + 23008;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AD38C;
	sub_823B87D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AD39C;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// b 0x823ad3d8
	goto loc_823AD3D8;
loc_823AD3AC:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,22984
	ctx.r4.s64 = r11.s64 + 22984;
	// bl 0x823b87d8
	ctx.lr = 0x823AD3B8;
	sub_823B87D8(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,23008
	ctx.r4.s64 = ctx.r10.s64 + 23008;
loc_823AD3C0:
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b87d8
	ctx.lr = 0x823AD3CC;
	sub_823B87D8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
loc_823AD3D8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a6b20
	ctx.lr = 0x823AD3E8;
	sub_823A6B20(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a6f38
	ctx.lr = 0x823AD3FC;
	sub_823A6F38(ctx, base);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lfs f13,29424(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29424);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r7,-11612
	ctx.r6.s64 = ctx.r7.s64 + -11612;
	// lfs f11,96(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lfs f12,29420(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29420);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fsel f8,f9,f9,f31
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f31.f64;
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f1,f7,f0,f8
	ctx.f1.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f8.f64;
	// beq cr6,0x823ad448
	if (cr6.eq) goto loc_823AD448;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_823AD448:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a4b38
	ctx.lr = 0x823AD450;
	sub_823A4B38(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823AD45C"))) PPC_WEAK_FUNC(sub_823AD45C);
PPC_FUNC_IMPL(__imp__sub_823AD45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD460"))) PPC_WEAK_FUNC(sub_823AD460);
PPC_FUNC_IMPL(__imp__sub_823AD460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lfs f1,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ac4a8
	ctx.lr = 0x823AD478;
	sub_823AC4A8(ctx, base);
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// bl 0x823a6fc0
	ctx.lr = 0x823AD480;
	sub_823A6FC0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AD490"))) PPC_WEAK_FUNC(sub_823AD490);
PPC_FUNC_IMPL(__imp__sub_823AD490) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD4B8;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD4C4;
	sub_823A5E30(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,13,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 13) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ad4f0
	if (!cr6.eq) goto loc_823AD4F0;
	// rlwinm r10,r11,12,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ad4f0
	if (!cr6.eq) goto loc_823AD4F0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f31,-11316(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11316);
	f31.f64 = double(temp.f32);
	// b 0x823ad4f8
	goto loc_823AD4F8;
loc_823AD4F0:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f31.f64 = double(temp.f32);
loc_823AD4F8:
	// rlwinm r11,r11,11,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x1;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ad518
	if (cr6.eq) goto loc_823AD518;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23032
	ctx.r4.s64 = r11.s64 + 23032;
	// b 0x823ad520
	goto loc_823AD520;
loc_823AD518:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r4,r11,23068
	ctx.r4.s64 = r11.s64 + 23068;
loc_823AD520:
	// bl 0x823b87d8
	ctx.lr = 0x823AD524;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5c10
	ctx.lr = 0x823AD53C;
	sub_823A5C10(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23052
	ctx.r4.s64 = r11.s64 + 23052;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD550;
	sub_823B87D8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6d40
	ctx.lr = 0x823AD568;
	sub_823A6D40(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a6ee0
	ctx.lr = 0x823AD578;
	sub_823A6EE0(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f1,-31384(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a7078
	ctx.lr = 0x823AD588;
	sub_823A7078(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r6,r7,0,29,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_823AD5B4"))) PPC_WEAK_FUNC(sub_823AD5B4);
PPC_FUNC_IMPL(__imp__sub_823AD5B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD5B8"))) PPC_WEAK_FUNC(sub_823AD5B8);
PPC_FUNC_IMPL(__imp__sub_823AD5B8) {
	PPC_FUNC_PROLOGUE();
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f13,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x823a6fc0
	ctx.lr = 0x823AD5F4;
	sub_823A6FC0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f11,92(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// bge cr6,0x823ad618
	if (!cr6.lt) goto loc_823AD618;
	// rlwinm r9,r10,0,29,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
loc_823AD618:
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823AD630"))) PPC_WEAK_FUNC(sub_823AD630);
PPC_FUNC_IMPL(__imp__sub_823AD630) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD654;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD660;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22728
	ctx.r4.s64 = r11.s64 + 22728;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD674;
	sub_823B87D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823AD690;
	sub_823A5C10(ctx, base);
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r8,800
	ctx.r8.s64 = 800;
	// addi r7,r9,-22880
	ctx.r7.s64 = ctx.r9.s64 + -22880;
	// li r6,144
	ctx.r6.s64 = 144;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823AD6D0;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823AD6F8"))) PPC_WEAK_FUNC(sub_823AD6F8);
PPC_FUNC_IMPL(__imp__sub_823AD6F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD71C;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD728;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22716
	ctx.r4.s64 = r11.s64 + 22716;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD73C;
	sub_823B87D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823AD758;
	sub_823A5C10(ctx, base);
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r8,800
	ctx.r8.s64 = 800;
	// addi r7,r9,-22880
	ctx.r7.s64 = ctx.r9.s64 + -22880;
	// li r6,144
	ctx.r6.s64 = 144;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823AD798;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823AD7C0"))) PPC_WEAK_FUNC(sub_823AD7C0);
PPC_FUNC_IMPL(__imp__sub_823AD7C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD7E4;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD7F0;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22684
	ctx.r4.s64 = r11.s64 + 22684;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD804;
	sub_823B87D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823AD820;
	sub_823A5C10(ctx, base);
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,272
	ctx.r7.s64 = 272;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,48(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lfs f0,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// rlwinm r10,r11,14,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x1;
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,128(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lvx128 v61,r9,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823ad880
	if (cr6.eq) goto loc_823AD880;
	// li r10,800
	ctx.r10.s64 = 800;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823AD880:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r9,144
	ctx.r9.s64 = 144;
	// addi r8,r11,-22880
	ctx.r8.s64 = r11.s64 + -22880;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,40(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r11,28(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ad930
	if (cr6.eq) goto loc_823AD930;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x823ad930
	if (cr6.eq) goto loc_823AD930;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-2288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -2288);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,112(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x823ad930
	if (!cr6.eq) goto loc_823AD930;
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ad930
	if (cr6.eq) goto loc_823AD930;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v59,v63
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v56,v58,v63
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v55,r11,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v54,v55,v63
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmrghw128 v53,v57,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v52,v54,v53
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v51,v53,v52
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823AD930:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f13,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,29460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29460);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fsel f1,f10,f11,f0
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// bl 0x823a6ee0
	ctx.lr = 0x823AD95C;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823AD984"))) PPC_WEAK_FUNC(sub_823AD984);
PPC_FUNC_IMPL(__imp__sub_823AD984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823AD988"))) PPC_WEAK_FUNC(sub_823AD988);
PPC_FUNC_IMPL(__imp__sub_823AD988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e10
	ctx.lr = 0x823AD9AC;
	sub_823A5E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823AD9B8;
	sub_823A5E30(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22700
	ctx.r4.s64 = r11.s64 + 22700;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AD9CC;
	sub_823B87D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823AD9E8;
	sub_823A5C10(ctx, base);
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r8,800
	ctx.r8.s64 = 800;
	// addi r7,r9,-22880
	ctx.r7.s64 = ctx.r9.s64 + -22880;
	// li r6,144
	ctx.r6.s64 = 144;
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f1,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a6ee0
	ctx.lr = 0x823ADA28;
	sub_823A6EE0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r8,r9,4
	ctx.r8.u64 = ctx.r9.u64 | 4;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_823ADA50"))) PPC_WEAK_FUNC(sub_823ADA50);
PPC_FUNC_IMPL(__imp__sub_823ADA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,17572
	ctx.r9.s64 = r11.s64 + 17572;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823adae0
	if (!cr6.eq) goto loc_823ADAE0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823adae0
	if (cr6.eq) goto loc_823ADAE0;
	// lbz r11,128(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823adae0
	if (!cr6.eq) goto loc_823ADAE0;
	// bl 0x823a73f0
	ctx.lr = 0x823ADAA4;
	sub_823A73F0(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4b00
	ctx.lr = 0x823ADAB0;
	sub_823A4B00(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ADAC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823adae0
	if (cr6.eq) goto loc_823ADAE0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc238
	ctx.lr = 0x823ADAE0;
	sub_823CC238(ctx, base);
loc_823ADAE0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// ori r9,r10,4
	ctx.r9.u64 = ctx.r10.u64 | 4;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 148, temp.u32);
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

__attribute__((alias("__imp__sub_823ADB10"))) PPC_WEAK_FUNC(sub_823ADB10);
PPC_FUNC_IMPL(__imp__sub_823ADB10) {
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
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,7,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823adb48
	if (!cr6.eq) goto loc_823ADB48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb7b0
	ctx.lr = 0x823ADB48;
	sub_823BB7B0(ctx, base);
loc_823ADB48:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f0,148(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 148, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ADB7C"))) PPC_WEAK_FUNC(sub_823ADB7C);
PPC_FUNC_IMPL(__imp__sub_823ADB7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823ADB80"))) PPC_WEAK_FUNC(sub_823ADB80);
PPC_FUNC_IMPL(__imp__sub_823ADB80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,17572
	ctx.r10.s64 = r11.s64 + 17572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823adc04
	if (!cr6.eq) goto loc_823ADC04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lbz r11,128(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823adbec
	if (cr6.eq) goto loc_823ADBEC;
	// bl 0x823a76f8
	ctx.lr = 0x823ADBBC;
	sub_823A76F8(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ADBD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823adbec
	if (cr6.eq) goto loc_823ADBEC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc238
	ctx.lr = 0x823ADBEC;
	sub_823CC238(ctx, base);
loc_823ADBEC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823adc04
	if (cr6.eq) goto loc_823ADC04;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,170(r11)
	PPC_STORE_U8(r11.u32 + 170, ctx.r10.u8);
loc_823ADC04:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ADC18"))) PPC_WEAK_FUNC(sub_823ADC18);
PPC_FUNC_IMPL(__imp__sub_823ADC18) {
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
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,7,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823adc84
	if (!cr6.eq) goto loc_823ADC84;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb7b0
	ctx.lr = 0x823ADC50;
	sub_823BB7B0(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// ori r8,r9,64
	ctx.r8.u64 = ctx.r9.u64 | 64;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f0,148(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 148, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823ADC84:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 148, temp.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ADCA8"))) PPC_WEAK_FUNC(sub_823ADCA8);
PPC_FUNC_IMPL(__imp__sub_823ADCA8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,17572
	ctx.r10.s64 = r11.s64 + 17572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823add2c
	if (!cr6.eq) goto loc_823ADD2C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lbz r11,128(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823add14
	if (cr6.eq) goto loc_823ADD14;
	// bl 0x823a76f8
	ctx.lr = 0x823ADCE4;
	sub_823A76F8(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ADCF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823add14
	if (cr6.eq) goto loc_823ADD14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cc238
	ctx.lr = 0x823ADD14;
	sub_823CC238(ctx, base);
loc_823ADD14:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823add2c
	if (cr6.eq) goto loc_823ADD2C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,170(r11)
	PPC_STORE_U8(r11.u32 + 170, ctx.r10.u8);
loc_823ADD2C:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823add5c
	if (cr6.eq) goto loc_823ADD5C;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823add5c
	if (cr6.eq) goto loc_823ADD5C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823ADD5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823ADD5C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r10,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stw r9,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r9.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r7,r8,0,30,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r7,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r7.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ADD90"))) PPC_WEAK_FUNC(sub_823ADD90);
PPC_FUNC_IMPL(__imp__sub_823ADD90) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ADDB0;
	sub_823A5E30(ctx, base);
	// addi r4,r31,96
	ctx.r4.s64 = r31.s64 + 96;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r31,32(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a8ec8
	ctx.lr = 0x823ADDC0;
	sub_823A8EC8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823ADDDC;
	sub_823A5C10(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_823ADDF0"))) PPC_WEAK_FUNC(sub_823ADDF0);
PPC_FUNC_IMPL(__imp__sub_823ADDF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r26{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823a5e30
	ctx.lr = 0x823ADE18;
	sub_823A5E30(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a86e8
	ctx.lr = 0x823ADE20;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ade44
	if (cr6.eq) goto loc_823ADE44;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a88d8
	ctx.lr = 0x823ADE34;
	sub_822A88D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ade48
	if (!cr6.eq) goto loc_823ADE48;
loc_823ADE44:
	// li r5,0
	ctx.r5.s64 = 0;
loc_823ADE48:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x823adf64
	if (cr6.gt) goto loc_823ADF64;
	// lis r12,-32197
	r12.s64 = -2110062592;
	// addi r12,r12,-8592
	r12.s64 = r12.s64 + -8592;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823ADEC0;
	case 1:
		goto loc_823ADED0;
	case 2:
		goto loc_823ADEE0;
	case 3:
		goto loc_823ADEF0;
	case 4:
		goto loc_823ADF00;
	case 5:
		goto loc_823ADF10;
	case 6:
		goto loc_823ADF20;
	case 7:
		goto loc_823ADF30;
	case 8:
		goto loc_823ADF80;
	case 9:
		goto loc_823ADF90;
	case 10:
		goto loc_823ADFA0;
	case 11:
		goto loc_823ADFB0;
	case 12:
		goto loc_823ADFD0;
	case 13:
		goto loc_823ADFC0;
	case 14:
		goto loc_823ADF64;
	case 15:
		goto loc_823ADFE0;
	case 16:
		goto loc_823ADF64;
	case 17:
		goto loc_823ADFF0;
	case 18:
		goto loc_823AE000;
	case 19:
		goto loc_823AE010;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-8512(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8512);
	// lwz r17,-8496(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8496);
	// lwz r17,-8480(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8480);
	// lwz r17,-8464(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8464);
	// lwz r17,-8448(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8448);
	// lwz r17,-8432(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8432);
	// lwz r17,-8416(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8416);
	// lwz r17,-8400(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8400);
	// lwz r17,-8320(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8320);
	// lwz r17,-8304(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8304);
	// lwz r17,-8288(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8288);
	// lwz r17,-8272(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8272);
	// lwz r17,-8240(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8240);
	// lwz r17,-8256(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8256);
	// lwz r17,-8348(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8348);
	// lwz r17,-8224(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8224);
	// lwz r17,-8348(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8348);
	// lwz r17,-8208(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8208);
	// lwz r17,-8192(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8192);
	// lwz r17,-8176(r26)
	r17.u64 = PPC_LOAD_U32(r26.u32 + -8176);
loc_823ADEC0:
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8c58
	ctx.lr = 0x823ADECC;
	sub_823A8C58(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADED0:
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8d00
	ctx.lr = 0x823ADEDC;
	sub_823A8D00(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADEE0:
	// addi r4,r31,76
	ctx.r4.s64 = r31.s64 + 76;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8d68
	ctx.lr = 0x823ADEEC;
	sub_823A8D68(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADEF0:
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8dd0
	ctx.lr = 0x823ADEFC;
	sub_823A8DD0(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADF00:
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8e08
	ctx.lr = 0x823ADF0C;
	sub_823A8E08(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADF10:
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8e40
	ctx.lr = 0x823ADF1C;
	sub_823A8E40(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADF20:
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8e90
	ctx.lr = 0x823ADF2C;
	sub_823A8E90(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823ADF30:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22536
	ctx.r4.s64 = r11.s64 + 22536;
loc_823ADF3C:
	// bl 0x823b87d8
	ctx.lr = 0x823ADF40;
	sub_823B87D8(ctx, base);
loc_823ADF40:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823adf64
	if (cr6.eq) goto loc_823ADF64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823a5c10
	ctx.lr = 0x823ADF64;
	sub_823A5C10(ctx, base);
loc_823ADF64:
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
loc_823ADF80:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22516
	ctx.r4.s64 = r11.s64 + 22516;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADF90:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22068
	ctx.r4.s64 = r11.s64 + 22068;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFA0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,21964
	ctx.r4.s64 = r11.s64 + 21964;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFB0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23512
	ctx.r4.s64 = r11.s64 + 23512;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFC0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,23556
	ctx.r4.s64 = r11.s64 + 23556;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFD0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,21924
	ctx.r4.s64 = r11.s64 + 21924;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFE0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29052
	ctx.r4.s64 = r11.s64 + 29052;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823ADFF0:
	// addi r4,r31,100
	ctx.r4.s64 = r31.s64 + 100;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823a8f18
	ctx.lr = 0x823ADFFC;
	sub_823A8F18(ctx, base);
	// b 0x823adf40
	goto loc_823ADF40;
loc_823AE000:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,22556
	ctx.r4.s64 = r11.s64 + 22556;
	// b 0x823adf3c
	goto loc_823ADF3C;
loc_823AE010:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,22476
	ctx.r4.s64 = ctx.r9.s64 + 22476;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stw r10,300(r11)
	PPC_STORE_U32(r11.u32 + 300, ctx.r10.u32);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AE034;
	sub_823B87D8(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f31,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a5c98
	ctx.lr = 0x823AE054;
	sub_823A5C98(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r4,r7,29544
	ctx.r4.s64 = ctx.r7.s64 + 29544;
	// addi r3,r6,29464
	ctx.r3.s64 = ctx.r6.s64 + 29464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r31,32(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823bf2f0
	ctx.lr = 0x823AE070;
	sub_823BF2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823a7ca8
	ctx.lr = 0x823AE084;
	sub_823A7CA8(ctx, base);
	// b 0x823adf64
	goto loc_823ADF64;
}

__attribute__((alias("__imp__sub_823AE088"))) PPC_WEAK_FUNC(sub_823AE088);
PPC_FUNC_IMPL(__imp__sub_823AE088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a7e30
	ctx.lr = 0x823AE0B8;
	sub_823A7E30(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,29436
	ctx.r4.s64 = ctx.r10.s64 + 29436;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b7890
	ctx.lr = 0x823AE0CC;
	sub_823B7890(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823a5e30
	ctx.lr = 0x823AE0D8;
	sub_823A5E30(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-10000(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10000);
	// lwz r8,300(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x823ae120
	if (!cr6.eq) goto loc_823AE120;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r10,300(r11)
	PPC_STORE_U32(r11.u32 + 300, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,23320
	ctx.r4.s64 = ctx.r9.s64 + 23320;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x823b87d8
	ctx.lr = 0x823AE108;
	sub_823B87D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x823a5c10
	ctx.lr = 0x823AE120;
	sub_823A5C10(ctx, base);
loc_823AE120:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x822a9090
	ctx.lr = 0x823AE128;
	sub_822A9090(ctx, base);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r11,20
	r11.s64 = 20;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,148(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 148, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823AE158"))) PPC_WEAK_FUNC(sub_823AE158);
PPC_FUNC_IMPL(__imp__sub_823AE158) {
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
	ctx.lr = 0x823AE160;
	// stwu r1,-2560(r1)
	ea = -2560 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32197
	r11.s64 = -2110062592;
	// addi r10,r11,-16480
	ctx.r10.s64 = r11.s64 + -16480;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE17C;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1312
	ctx.r3.s64 = ctx.r1.s64 + 1312;
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30972
	ctx.r4.s64 = ctx.r9.s64 + 30972;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE198;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE1A4;
	sub_823BA7F8(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r3,1320(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1320);
	// addi r30,r8,29432
	r30.s64 = ctx.r8.s64 + 29432;
	// stw r30,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, r30.u32);
	// bl 0x82130588
	ctx.lr = 0x823AE1B8;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16464
	ctx.r6.s64 = ctx.r7.s64 + -16464;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE1CC;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30952
	ctx.r4.s64 = ctx.r5.s64 + 30952;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE1E8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE1F4;
	sub_823BA7F8(ctx, base);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// lwz r3,168(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x82130588
	ctx.lr = 0x823AE200;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16448
	r11.s64 = ctx.r4.s64 + -16448;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE214;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2208
	ctx.r3.s64 = ctx.r1.s64 + 2208;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30932
	ctx.r4.s64 = ctx.r10.s64 + 30932;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE230;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE23C;
	sub_823BA7F8(ctx, base);
	// stw r30,2208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2208, r30.u32);
	// lwz r3,2216(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2216);
	// bl 0x82130588
	ctx.lr = 0x823AE248;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-17328
	ctx.r8.s64 = ctx.r9.s64 + -17328;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE25C;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30912
	ctx.r4.s64 = ctx.r7.s64 + 30912;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE278;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE284;
	sub_823BA7F8(ctx, base);
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// lwz r3,232(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// bl 0x82130588
	ctx.lr = 0x823AE290;
	sub_82130588(ctx, base);
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,15712
	ctx.r5.s64 = ctx.r6.s64 + 15712;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE2A4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1376
	ctx.r3.s64 = ctx.r1.s64 + 1376;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r4,30892
	ctx.r4.s64 = ctx.r4.s64 + 30892;
	// bl 0x823b9e00
	ctx.lr = 0x823AE2C0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE2CC;
	sub_823BA7F8(ctx, base);
	// stw r30,1376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1376, r30.u32);
	// lwz r3,1384(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1384);
	// bl 0x82130588
	ctx.lr = 0x823AE2D8;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16840
	ctx.r10.s64 = r11.s64 + -16840;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE2EC;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30872
	ctx.r4.s64 = ctx.r9.s64 + 30872;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE308;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE314;
	sub_823BA7F8(ctx, base);
	// stw r30,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r30.u32);
	// lwz r3,296(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	// bl 0x82130588
	ctx.lr = 0x823AE320;
	sub_82130588(ctx, base);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,14928
	ctx.r7.s64 = ctx.r8.s64 + 14928;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE334;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1952
	ctx.r3.s64 = ctx.r1.s64 + 1952;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30856
	ctx.r4.s64 = ctx.r6.s64 + 30856;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE350;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE35C;
	sub_823BA7F8(ctx, base);
	// stw r30,1952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1952, r30.u32);
	// lwz r3,1960(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1960);
	// bl 0x82130588
	ctx.lr = 0x823AE368;
	sub_82130588(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,14976
	ctx.r4.s64 = ctx.r5.s64 + 14976;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE37C;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30840
	ctx.r4.s64 = r11.s64 + 30840;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE398;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE3A4;
	sub_823BA7F8(ctx, base);
	// stw r30,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r30.u32);
	// lwz r3,360(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 360);
	// bl 0x82130588
	ctx.lr = 0x823AE3B0;
	sub_82130588(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,15048
	ctx.r9.s64 = ctx.r10.s64 + 15048;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE3C4;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1440
	ctx.r3.s64 = ctx.r1.s64 + 1440;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30820
	ctx.r4.s64 = ctx.r8.s64 + 30820;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE3E0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE3EC;
	sub_823BA7F8(ctx, base);
	// stw r30,1440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1440, r30.u32);
	// lwz r3,1448(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1448);
	// bl 0x82130588
	ctx.lr = 0x823AE3F8;
	sub_82130588(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,15120
	ctx.r6.s64 = ctx.r7.s64 + 15120;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE40C;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30800
	ctx.r4.s64 = ctx.r5.s64 + 30800;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE428;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE434;
	sub_823BA7F8(ctx, base);
	// stw r30,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r30.u32);
	// lwz r3,424(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	// bl 0x82130588
	ctx.lr = 0x823AE440;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,15192
	r11.s64 = ctx.r4.s64 + 15192;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE454;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2464
	ctx.r3.s64 = ctx.r1.s64 + 2464;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30780
	ctx.r4.s64 = ctx.r10.s64 + 30780;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE470;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE47C;
	sub_823BA7F8(ctx, base);
	// stw r30,2464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2464, r30.u32);
	// lwz r3,2472(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2472);
	// bl 0x82130588
	ctx.lr = 0x823AE488;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16416
	ctx.r8.s64 = ctx.r9.s64 + -16416;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE49C;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30752
	ctx.r4.s64 = ctx.r7.s64 + 30752;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AE4B8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE4C4;
	sub_823BA7F8(ctx, base);
	// stw r30,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r30.u32);
	// lwz r3,488(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 488);
	// bl 0x82130588
	ctx.lr = 0x823AE4D0;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16400
	ctx.r5.s64 = ctx.r6.s64 + -16400;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE4E4;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1504
	ctx.r3.s64 = ctx.r1.s64 + 1504;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30724
	ctx.r4.s64 = ctx.r4.s64 + 30724;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AE500;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE50C;
	sub_823BA7F8(ctx, base);
	// stw r30,1504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1504, r30.u32);
	// lwz r3,1512(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1512);
	// bl 0x82130588
	ctx.lr = 0x823AE518;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16384
	ctx.r10.s64 = r11.s64 + -16384;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE52C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,30696
	ctx.r4.s64 = ctx.r9.s64 + 30696;
	// bl 0x823b9c20
	ctx.lr = 0x823AE548;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE554;
	sub_823BA7F8(ctx, base);
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, r30.u32);
	// lwz r3,552(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	// bl 0x82130588
	ctx.lr = 0x823AE560;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16792
	ctx.r7.s64 = ctx.r8.s64 + -16792;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE574;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30676
	ctx.r4.s64 = ctx.r6.s64 + 30676;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE590;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE59C;
	sub_823BA7F8(ctx, base);
	// stw r30,2016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2016, r30.u32);
	// lwz r3,2024(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2024);
	// bl 0x82130588
	ctx.lr = 0x823AE5A8;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16784
	ctx.r4.s64 = ctx.r5.s64 + -16784;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE5BC;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30656
	ctx.r4.s64 = r11.s64 + 30656;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE5D8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE5E4;
	sub_823BA7F8(ctx, base);
	// stw r30,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r30.u32);
	// lwz r3,616(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 616);
	// bl 0x82130588
	ctx.lr = 0x823AE5F0;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-17248
	ctx.r9.s64 = ctx.r10.s64 + -17248;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE604;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1568
	ctx.r3.s64 = ctx.r1.s64 + 1568;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30640
	ctx.r4.s64 = ctx.r8.s64 + 30640;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE620;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE62C;
	sub_823BA7F8(ctx, base);
	// stw r30,1568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1568, r30.u32);
	// lwz r3,1576(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1576);
	// bl 0x82130588
	ctx.lr = 0x823AE638;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-17224
	ctx.r6.s64 = ctx.r7.s64 + -17224;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE64C;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30624
	ctx.r4.s64 = ctx.r5.s64 + 30624;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE668;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE674;
	sub_823BA7F8(ctx, base);
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// lwz r3,680(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 680);
	// bl 0x82130588
	ctx.lr = 0x823AE680;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-17088
	r11.s64 = ctx.r4.s64 + -17088;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE694;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2272
	ctx.r3.s64 = ctx.r1.s64 + 2272;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30612
	ctx.r4.s64 = ctx.r10.s64 + 30612;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE6B0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE6BC;
	sub_823BA7F8(ctx, base);
	// stw r30,2272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2272, r30.u32);
	// lwz r3,2280(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2280);
	// bl 0x82130588
	ctx.lr = 0x823AE6C8;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-17136
	ctx.r8.s64 = ctx.r9.s64 + -17136;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE6DC;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,736
	ctx.r3.s64 = ctx.r1.s64 + 736;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30604
	ctx.r4.s64 = ctx.r7.s64 + 30604;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE6F8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE704;
	sub_823BA7F8(ctx, base);
	// stw r30,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r30.u32);
	// lwz r3,744(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 744);
	// bl 0x82130588
	ctx.lr = 0x823AE710;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-17120
	ctx.r5.s64 = ctx.r6.s64 + -17120;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE724;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1632
	ctx.r3.s64 = ctx.r1.s64 + 1632;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30592
	ctx.r4.s64 = ctx.r4.s64 + 30592;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE740;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE74C;
	sub_823BA7F8(ctx, base);
	// stw r30,1632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1632, r30.u32);
	// lwz r3,1640(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1640);
	// bl 0x82130588
	ctx.lr = 0x823AE758;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-17104
	ctx.r10.s64 = r11.s64 + -17104;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE76C;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30568
	ctx.r4.s64 = ctx.r9.s64 + 30568;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE788;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE794;
	sub_823BA7F8(ctx, base);
	// stw r30,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, r30.u32);
	// lwz r3,808(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 808);
	// bl 0x82130588
	ctx.lr = 0x823AE7A0;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17072
	ctx.r7.s64 = ctx.r8.s64 + -17072;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE7B4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r6,30560
	ctx.r4.s64 = ctx.r6.s64 + 30560;
	// bl 0x823b9e00
	ctx.lr = 0x823AE7D0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE7DC;
	sub_823BA7F8(ctx, base);
	// stw r30,2080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2080, r30.u32);
	// lwz r3,2088(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2088);
	// bl 0x82130588
	ctx.lr = 0x823AE7E8;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17056
	ctx.r4.s64 = ctx.r5.s64 + -17056;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE7FC;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30548
	ctx.r4.s64 = r11.s64 + 30548;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE818;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE824;
	sub_823BA7F8(ctx, base);
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, r30.u32);
	// lwz r3,872(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 872);
	// bl 0x82130588
	ctx.lr = 0x823AE830;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-17184
	ctx.r9.s64 = ctx.r10.s64 + -17184;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE844;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1696
	ctx.r3.s64 = ctx.r1.s64 + 1696;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30536
	ctx.r4.s64 = ctx.r8.s64 + 30536;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE860;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE86C;
	sub_823BA7F8(ctx, base);
	// stw r30,1696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1696, r30.u32);
	// lwz r3,1704(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1704);
	// bl 0x82130588
	ctx.lr = 0x823AE878;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-17168
	ctx.r6.s64 = ctx.r7.s64 + -17168;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE88C;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30524
	ctx.r4.s64 = ctx.r5.s64 + 30524;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE8A8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE8B4;
	sub_823BA7F8(ctx, base);
	// stw r30,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, r30.u32);
	// lwz r3,936(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 936);
	// bl 0x82130588
	ctx.lr = 0x823AE8C0;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-17200
	r11.s64 = ctx.r4.s64 + -17200;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE8D4;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2400
	ctx.r3.s64 = ctx.r1.s64 + 2400;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30512
	ctx.r4.s64 = ctx.r10.s64 + 30512;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE8F0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE8FC;
	sub_823BA7F8(ctx, base);
	// stw r30,2400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2400, r30.u32);
	// lwz r3,2408(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2408);
	// bl 0x82130588
	ctx.lr = 0x823AE908;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16856
	ctx.r8.s64 = ctx.r9.s64 + -16856;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE91C;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,992
	ctx.r3.s64 = ctx.r1.s64 + 992;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30488
	ctx.r4.s64 = ctx.r7.s64 + 30488;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE938;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE944;
	sub_823BA7F8(ctx, base);
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, r30.u32);
	// lwz r3,1000(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1000);
	// bl 0x82130588
	ctx.lr = 0x823AE950;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16888
	ctx.r5.s64 = ctx.r6.s64 + -16888;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE964;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1760
	ctx.r3.s64 = ctx.r1.s64 + 1760;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30468
	ctx.r4.s64 = ctx.r4.s64 + 30468;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE980;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE98C;
	sub_823BA7F8(ctx, base);
	// stw r30,1760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1760, r30.u32);
	// lwz r3,1768(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1768);
	// bl 0x82130588
	ctx.lr = 0x823AE998;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16872
	ctx.r10.s64 = r11.s64 + -16872;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE9AC;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1056
	ctx.r3.s64 = ctx.r1.s64 + 1056;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30448
	ctx.r4.s64 = ctx.r9.s64 + 30448;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AE9C8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AE9D4;
	sub_823BA7F8(ctx, base);
	// stw r30,1056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1056, r30.u32);
	// lwz r3,1064(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1064);
	// bl 0x82130588
	ctx.lr = 0x823AE9E0;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17040
	ctx.r7.s64 = ctx.r8.s64 + -17040;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AE9F4;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2144
	ctx.r3.s64 = ctx.r1.s64 + 2144;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30436
	ctx.r4.s64 = ctx.r6.s64 + 30436;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEA10;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEA1C;
	sub_823BA7F8(ctx, base);
	// stw r30,2144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2144, r30.u32);
	// lwz r3,2152(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2152);
	// bl 0x82130588
	ctx.lr = 0x823AEA28;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17016
	ctx.r4.s64 = ctx.r5.s64 + -17016;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEA3C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r3,30416
	ctx.r4.s64 = ctx.r3.s64 + 30416;
	// addi r3,r1,1120
	ctx.r3.s64 = ctx.r1.s64 + 1120;
	// bl 0x823b9e00
	ctx.lr = 0x823AEA58;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEA64;
	sub_823BA7F8(ctx, base);
	// stw r30,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, r30.u32);
	// lwz r3,1128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1128);
	// bl 0x82130588
	ctx.lr = 0x823AEA70;
	sub_82130588(ctx, base);
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,4928
	ctx.r10.s64 = r11.s64 + 4928;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEA84;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1824
	ctx.r3.s64 = ctx.r1.s64 + 1824;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30396
	ctx.r4.s64 = ctx.r9.s64 + 30396;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEAA0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEAAC;
	sub_823BA7F8(ctx, base);
	// stw r30,1824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1824, r30.u32);
	// lwz r3,1832(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1832);
	// bl 0x82130588
	ctx.lr = 0x823AEAB8;
	sub_82130588(ctx, base);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,4944
	ctx.r7.s64 = ctx.r8.s64 + 4944;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEACC;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1184
	ctx.r3.s64 = ctx.r1.s64 + 1184;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30376
	ctx.r4.s64 = ctx.r6.s64 + 30376;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEAE8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEAF4;
	sub_823BA7F8(ctx, base);
	// stw r30,1184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1184, r30.u32);
	// lwz r3,1192(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1192);
	// bl 0x82130588
	ctx.lr = 0x823AEB00;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17000
	ctx.r4.s64 = ctx.r5.s64 + -17000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEB14;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2336
	ctx.r3.s64 = ctx.r1.s64 + 2336;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30348
	ctx.r4.s64 = r11.s64 + 30348;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEB30;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEB3C;
	sub_823BA7F8(ctx, base);
	// stw r30,2336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2336, r30.u32);
	// lwz r3,2344(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2344);
	// bl 0x82130588
	ctx.lr = 0x823AEB48;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16984
	ctx.r9.s64 = ctx.r10.s64 + -16984;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEB5C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30320
	ctx.r4.s64 = ctx.r8.s64 + 30320;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEB78;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEB84;
	sub_823BA7F8(ctx, base);
	// stw r30,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, r30.u32);
	// lwz r3,1256(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1256);
	// bl 0x82130588
	ctx.lr = 0x823AEB90;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16968
	ctx.r6.s64 = ctx.r7.s64 + -16968;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEBA4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r3,r1,1888
	ctx.r3.s64 = ctx.r1.s64 + 1888;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30300
	ctx.r4.s64 = ctx.r5.s64 + 30300;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEBC0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEBCC;
	sub_823BA7F8(ctx, base);
	// stw r30,1888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1888, r30.u32);
	// lwz r3,1896(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1896);
	// bl 0x82130588
	ctx.lr = 0x823AEBD8;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16936
	r11.s64 = ctx.r4.s64 + -16936;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEBEC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30284
	ctx.r4.s64 = ctx.r10.s64 + 30284;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEC08;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEC14;
	sub_823BA7F8(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x823AEC20;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16952
	ctx.r8.s64 = ctx.r9.s64 + -16952;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEC34;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30272
	ctx.r4.s64 = ctx.r7.s64 + 30272;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEC50;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEC5C;
	sub_823BA7F8(ctx, base);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x823AEC68;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16920
	ctx.r5.s64 = ctx.r6.s64 + -16920;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEC7C;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30260
	ctx.r4.s64 = ctx.r4.s64 + 30260;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEC98;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AECA4;
	sub_823BA7F8(ctx, base);
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// lwz r3,200(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// bl 0x82130588
	ctx.lr = 0x823AECB0;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16904
	ctx.r10.s64 = r11.s64 + -16904;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AECC4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,30244
	ctx.r4.s64 = ctx.r9.s64 + 30244;
	// bl 0x823b9e00
	ctx.lr = 0x823AECE0;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AECEC;
	sub_823BA7F8(ctx, base);
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// lwz r3,264(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// bl 0x82130588
	ctx.lr = 0x823AECF8;
	sub_82130588(ctx, base);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,4880
	ctx.r7.s64 = ctx.r8.s64 + 4880;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AED0C;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,30220
	ctx.r4.s64 = ctx.r6.s64 + 30220;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AED28;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AED34;
	sub_823BA7F8(ctx, base);
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// lwz r3,328(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	// bl 0x82130588
	ctx.lr = 0x823AED40;
	sub_82130588(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,4896
	ctx.r4.s64 = ctx.r5.s64 + 4896;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AED54;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30196
	ctx.r4.s64 = r11.s64 + 30196;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AED70;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AED7C;
	sub_823BA7F8(ctx, base);
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r30.u32);
	// lwz r3,392(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 392);
	// bl 0x82130588
	ctx.lr = 0x823AED88;
	sub_82130588(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,4912
	ctx.r9.s64 = ctx.r10.s64 + 4912;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AED9C;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30176
	ctx.r4.s64 = ctx.r8.s64 + 30176;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEDB8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEDC4;
	sub_823BA7F8(ctx, base);
	// stw r30,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, r30.u32);
	// lwz r3,456(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 456);
	// bl 0x82130588
	ctx.lr = 0x823AEDD0;
	sub_82130588(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-16816
	ctx.r6.s64 = ctx.r7.s64 + -16816;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEDE4;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30156
	ctx.r4.s64 = ctx.r5.s64 + 30156;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEE00;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEE0C;
	sub_823BA7F8(ctx, base);
	// stw r30,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, r30.u32);
	// lwz r3,520(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 520);
	// bl 0x82130588
	ctx.lr = 0x823AEE18;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,4872
	r11.s64 = ctx.r4.s64 + 4872;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEE2C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30140
	ctx.r4.s64 = ctx.r10.s64 + 30140;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AEE48;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEE54;
	sub_823BA7F8(ctx, base);
	// stw r30,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, r30.u32);
	// lwz r3,584(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// bl 0x82130588
	ctx.lr = 0x823AEE60;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-17280
	ctx.r8.s64 = ctx.r9.s64 + -17280;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEE74;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,30124
	ctx.r4.s64 = ctx.r7.s64 + 30124;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AEE90;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEE9C;
	sub_823BA7F8(ctx, base);
	// stw r30,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, r30.u32);
	// lwz r3,648(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 648);
	// bl 0x82130588
	ctx.lr = 0x823AEEA8;
	sub_82130588(ctx, base);
	// lis r6,-32222
	ctx.r6.s64 = -2111700992;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-12384
	ctx.r5.s64 = ctx.r6.s64 + -12384;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEEBC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// addi r3,r1,704
	ctx.r3.s64 = ctx.r1.s64 + 704;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,30112
	ctx.r4.s64 = ctx.r4.s64 + 30112;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AEED8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEEE4;
	sub_823BA7F8(ctx, base);
	// stw r30,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r30.u32);
	// lwz r3,712(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 712);
	// bl 0x82130588
	ctx.lr = 0x823AEEF0;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-17320
	ctx.r10.s64 = r11.s64 + -17320;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEF04;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,30092
	ctx.r4.s64 = ctx.r9.s64 + 30092;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AEF20;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEF2C;
	sub_823BA7F8(ctx, base);
	// stw r30,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, r30.u32);
	// lwz r3,776(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 776);
	// bl 0x82130588
	ctx.lr = 0x823AEF38;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-17312
	ctx.r7.s64 = ctx.r8.s64 + -17312;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEF4C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,832
	ctx.r3.s64 = ctx.r1.s64 + 832;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r6,30076
	ctx.r4.s64 = ctx.r6.s64 + 30076;
	// bl 0x823b9c20
	ctx.lr = 0x823AEF68;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEF74;
	sub_823BA7F8(ctx, base);
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// lwz r3,840(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 840);
	// bl 0x82130588
	ctx.lr = 0x823AEF80;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-17272
	ctx.r4.s64 = ctx.r5.s64 + -17272;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEF94;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,30056
	ctx.r4.s64 = r11.s64 + 30056;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AEFB0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AEFBC;
	sub_823BA7F8(ctx, base);
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, r30.u32);
	// lwz r3,904(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 904);
	// bl 0x82130588
	ctx.lr = 0x823AEFC8;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-17264
	ctx.r9.s64 = ctx.r10.s64 + -17264;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AEFDC;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,30032
	ctx.r4.s64 = ctx.r8.s64 + 30032;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AEFF8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF004;
	sub_823BA7F8(ctx, base);
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, r30.u32);
	// lwz r3,968(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 968);
	// bl 0x82130588
	ctx.lr = 0x823AF010;
	sub_82130588(ctx, base);
	// lis r7,-32235
	ctx.r7.s64 = -2112552960;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,-27520
	ctx.r6.s64 = ctx.r7.s64 + -27520;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF024;
	sub_82130000(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1024
	ctx.r3.s64 = ctx.r1.s64 + 1024;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,30016
	ctx.r4.s64 = ctx.r5.s64 + 30016;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF040;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF04C;
	sub_823BA7F8(ctx, base);
	// stw r30,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, r30.u32);
	// lwz r3,1032(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1032);
	// bl 0x82130588
	ctx.lr = 0x823AF058;
	sub_82130588(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-17256
	r11.s64 = ctx.r4.s64 + -17256;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF06C;
	sub_82130000(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1088
	ctx.r3.s64 = ctx.r1.s64 + 1088;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,30000
	ctx.r4.s64 = ctx.r10.s64 + 30000;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF088;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF094;
	sub_823BA7F8(ctx, base);
	// stw r30,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, r30.u32);
	// lwz r3,1096(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1096);
	// bl 0x82130588
	ctx.lr = 0x823AF0A0;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-16776
	ctx.r8.s64 = ctx.r9.s64 + -16776;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF0B4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29988
	ctx.r4.s64 = ctx.r7.s64 + 29988;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF0D0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF0DC;
	sub_823BA7F8(ctx, base);
	// stw r30,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r30.u32);
	// lwz r3,1160(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1160);
	// bl 0x82130588
	ctx.lr = 0x823AF0E8;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-16768
	ctx.r5.s64 = ctx.r6.s64 + -16768;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF0FC;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1216
	ctx.r3.s64 = ctx.r1.s64 + 1216;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29976
	ctx.r4.s64 = ctx.r4.s64 + 29976;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF118;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF124;
	sub_823BA7F8(ctx, base);
	// stw r30,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, r30.u32);
	// lwz r3,1224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1224);
	// bl 0x82130588
	ctx.lr = 0x823AF130;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16760
	ctx.r10.s64 = r11.s64 + -16760;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF144;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,29964
	ctx.r4.s64 = ctx.r9.s64 + 29964;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF160;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF16C;
	sub_823BA7F8(ctx, base);
	// stw r30,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, r30.u32);
	// lwz r3,1288(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1288);
	// bl 0x82130588
	ctx.lr = 0x823AF178;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16432
	ctx.r7.s64 = ctx.r8.s64 + -16432;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF18C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r3,r1,1344
	ctx.r3.s64 = ctx.r1.s64 + 1344;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,29936
	ctx.r4.s64 = ctx.r6.s64 + 29936;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF1A8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF1B4;
	sub_823BA7F8(ctx, base);
	// stw r30,1344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1344, r30.u32);
	// lwz r3,1352(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1352);
	// bl 0x82130588
	ctx.lr = 0x823AF1C0;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16752
	ctx.r4.s64 = ctx.r5.s64 + -16752;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF1D4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r3,29920
	ctx.r4.s64 = ctx.r3.s64 + 29920;
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// bl 0x823b9c20
	ctx.lr = 0x823AF1F0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF1FC;
	sub_823BA7F8(ctx, base);
	// stw r30,1408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1408, r30.u32);
	// lwz r3,1416(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1416);
	// bl 0x82130588
	ctx.lr = 0x823AF208;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16744
	ctx.r10.s64 = r11.s64 + -16744;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF21C;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1472
	ctx.r3.s64 = ctx.r1.s64 + 1472;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,29892
	ctx.r4.s64 = ctx.r9.s64 + 29892;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF238;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF244;
	sub_823BA7F8(ctx, base);
	// stw r30,1472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1472, r30.u32);
	// lwz r3,1480(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1480);
	// bl 0x82130588
	ctx.lr = 0x823AF250;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16736
	ctx.r7.s64 = ctx.r8.s64 + -16736;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF264;
	sub_82130000(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1536
	ctx.r3.s64 = ctx.r1.s64 + 1536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,29868
	ctx.r4.s64 = ctx.r6.s64 + 29868;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF280;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF28C;
	sub_823BA7F8(ctx, base);
	// stw r30,1536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1536, r30.u32);
	// lwz r3,1544(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1544);
	// bl 0x82130588
	ctx.lr = 0x823AF298;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16688
	ctx.r4.s64 = ctx.r5.s64 + -16688;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF2AC;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1600
	ctx.r3.s64 = ctx.r1.s64 + 1600;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,29852
	ctx.r4.s64 = r11.s64 + 29852;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF2C8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF2D4;
	sub_823BA7F8(ctx, base);
	// stw r30,1600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1600, r30.u32);
	// lwz r3,1608(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1608);
	// bl 0x82130588
	ctx.lr = 0x823AF2E0;
	sub_82130588(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16680
	ctx.r9.s64 = ctx.r10.s64 + -16680;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF2F4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r1,1664
	ctx.r3.s64 = ctx.r1.s64 + 1664;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,29844
	ctx.r4.s64 = ctx.r8.s64 + 29844;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF310;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF31C;
	sub_823BA7F8(ctx, base);
	// stw r30,1664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1664, r30.u32);
	// lwz r3,1672(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1672);
	// bl 0x82130588
	ctx.lr = 0x823AF328;
	sub_82130588(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r6,r7,13720
	ctx.r6.s64 = ctx.r7.s64 + 13720;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF33C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r3,r1,1728
	ctx.r3.s64 = ctx.r1.s64 + 1728;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,29816
	ctx.r4.s64 = ctx.r5.s64 + 29816;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF358;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF364;
	sub_823BA7F8(ctx, base);
	// stw r30,1728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1728, r30.u32);
	// lwz r3,1736(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1736);
	// bl 0x82130588
	ctx.lr = 0x823AF370;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,13744
	r11.s64 = ctx.r4.s64 + 13744;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF384;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,29788
	ctx.r4.s64 = ctx.r10.s64 + 29788;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF3A0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF3AC;
	sub_823BA7F8(ctx, base);
	// stw r30,1792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1792, r30.u32);
	// lwz r3,1800(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1800);
	// bl 0x82130588
	ctx.lr = 0x823AF3B8;
	sub_82130588(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,13768
	ctx.r8.s64 = ctx.r9.s64 + 13768;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF3CC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// addi r3,r1,1856
	ctx.r3.s64 = ctx.r1.s64 + 1856;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29760
	ctx.r4.s64 = ctx.r7.s64 + 29760;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF3E8;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF3F4;
	sub_823BA7F8(ctx, base);
	// stw r30,1856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1856, r30.u32);
	// lwz r3,1864(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1864);
	// bl 0x82130588
	ctx.lr = 0x823AF400;
	sub_82130588(ctx, base);
	// lis r6,-32198
	ctx.r6.s64 = -2110128128;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,13792
	ctx.r5.s64 = ctx.r6.s64 + 13792;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF414;
	sub_82130000(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,1920
	ctx.r3.s64 = ctx.r1.s64 + 1920;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29732
	ctx.r4.s64 = ctx.r4.s64 + 29732;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF430;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF43C;
	sub_823BA7F8(ctx, base);
	// stw r30,1920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1920, r30.u32);
	// lwz r3,1928(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1928);
	// bl 0x82130588
	ctx.lr = 0x823AF448;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16728
	ctx.r10.s64 = r11.s64 + -16728;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF45C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r3,r1,1984
	ctx.r3.s64 = ctx.r1.s64 + 1984;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r4,r9,29728
	ctx.r4.s64 = ctx.r9.s64 + 29728;
	// bl 0x823b9cc0
	ctx.lr = 0x823AF478;
	sub_823B9CC0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF484;
	sub_823BA7F8(ctx, base);
	// stw r30,1984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1984, r30.u32);
	// lwz r3,1992(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1992);
	// bl 0x82130588
	ctx.lr = 0x823AF490;
	sub_82130588(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r7,r8,-16720
	ctx.r7.s64 = ctx.r8.s64 + -16720;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF4A4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r3,r1,2048
	ctx.r3.s64 = ctx.r1.s64 + 2048;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r6,29724
	ctx.r4.s64 = ctx.r6.s64 + 29724;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9d60
	ctx.lr = 0x823AF4C0;
	sub_823B9D60(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF4CC;
	sub_823BA7F8(ctx, base);
	// stw r30,2048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2048, r30.u32);
	// lwz r3,2056(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2056);
	// bl 0x82130588
	ctx.lr = 0x823AF4D8;
	sub_82130588(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r5,-16704
	ctx.r4.s64 = ctx.r5.s64 + -16704;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF4EC;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,2112
	ctx.r3.s64 = ctx.r1.s64 + 2112;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,29720
	ctx.r4.s64 = r11.s64 + 29720;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9d60
	ctx.lr = 0x823AF508;
	sub_823B9D60(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF514;
	sub_823BA7F8(ctx, base);
	// stw r30,2112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2112, r30.u32);
	// lwz r3,2120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2120);
	// bl 0x82130588
	ctx.lr = 0x823AF520;
	sub_82130588(ctx, base);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r9,r10,29016
	ctx.r9.s64 = ctx.r10.s64 + 29016;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF534;
	sub_82130000(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2176
	ctx.r3.s64 = ctx.r1.s64 + 2176;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r8,29700
	ctx.r4.s64 = ctx.r8.s64 + 29700;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF550;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF55C;
	sub_823BA7F8(ctx, base);
	// stw r30,2176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2176, r30.u32);
	// lwz r3,2184(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2184);
	// bl 0x82130588
	ctx.lr = 0x823AF568;
	sub_82130588(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r6,r7,29224
	ctx.r6.s64 = ctx.r7.s64 + 29224;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF57C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// addi r3,r1,2240
	ctx.r3.s64 = ctx.r1.s64 + 2240;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r5,29672
	ctx.r4.s64 = ctx.r5.s64 + 29672;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF598;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF5A4;
	sub_823BA7F8(ctx, base);
	// stw r30,2240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2240, r30.u32);
	// lwz r3,2248(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2248);
	// bl 0x82130588
	ctx.lr = 0x823AF5B0;
	sub_82130588(ctx, base);
	// lis r4,-32198
	ctx.r4.s64 = -2110128128;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r11,r4,29544
	r11.s64 = ctx.r4.s64 + 29544;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF5C4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r1,2304
	ctx.r3.s64 = ctx.r1.s64 + 2304;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r10,29656
	ctx.r4.s64 = ctx.r10.s64 + 29656;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF5E0;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF5EC;
	sub_823BA7F8(ctx, base);
	// stw r30,2304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2304, r30.u32);
	// lwz r3,2312(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2312);
	// bl 0x82130588
	ctx.lr = 0x823AF5F8;
	sub_82130588(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r8,r9,-17304
	ctx.r8.s64 = ctx.r9.s64 + -17304;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF60C;
	sub_82130000(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2368
	ctx.r3.s64 = ctx.r1.s64 + 2368;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r7,29632
	ctx.r4.s64 = ctx.r7.s64 + 29632;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF628;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF634;
	sub_823BA7F8(ctx, base);
	// stw r30,2368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2368, r30.u32);
	// lwz r3,2376(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2376);
	// bl 0x82130588
	ctx.lr = 0x823AF640;
	sub_82130588(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r6,-17288
	ctx.r5.s64 = ctx.r6.s64 + -17288;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF654;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// addi r3,r1,2432
	ctx.r3.s64 = ctx.r1.s64 + 2432;
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r4,29604
	ctx.r4.s64 = ctx.r4.s64 + 29604;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9c20
	ctx.lr = 0x823AF670;
	sub_823B9C20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF67C;
	sub_823BA7F8(ctx, base);
	// stw r30,2432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2432, r30.u32);
	// lwz r3,2440(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2440);
	// bl 0x82130588
	ctx.lr = 0x823AF688;
	sub_82130588(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-17152
	ctx.r10.s64 = r11.s64 + -17152;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF69C;
	sub_82130000(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,2496
	ctx.r3.s64 = ctx.r1.s64 + 2496;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r9,29588
	ctx.r4.s64 = ctx.r9.s64 + 29588;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b9e00
	ctx.lr = 0x823AF6B8;
	sub_823B9E00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ba7f8
	ctx.lr = 0x823AF6C4;
	sub_823BA7F8(ctx, base);
	// stw r30,2496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2496, r30.u32);
	// lwz r3,2504(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2504);
	// bl 0x82130588
	ctx.lr = 0x823AF6D0;
	sub_82130588(ctx, base);
	// addi r1,r1,2560
	ctx.r1.s64 = ctx.r1.s64 + 2560;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823AF6D8"))) PPC_WEAK_FUNC(sub_823AF6D8);
PPC_FUNC_IMPL(__imp__sub_823AF6D8) {
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
	ctx.lr = 0x823AF6E0;
	// stwu r1,-1504(r1)
	ea = -1504 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,32604
	ctx.r4.s64 = r11.s64 + 32604;
	// bl 0x823b9960
	ctx.lr = 0x823AF6F4;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32588
	ctx.r4.s64 = ctx.r10.s64 + 32588;
	// stw r15,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r15.u32);
	// bl 0x823b9960
	ctx.lr = 0x823AF70C;
	sub_823B9960(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,32564
	ctx.r4.s64 = ctx.r9.s64 + 32564;
	// bl 0x823b9960
	ctx.lr = 0x823AF720;
	sub_823B9960(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,32556
	ctx.r4.s64 = ctx.r8.s64 + 32556;
	// bl 0x823b9960
	ctx.lr = 0x823AF734;
	sub_823B9960(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,32544
	ctx.r4.s64 = ctx.r7.s64 + 32544;
	// bl 0x823b9960
	ctx.lr = 0x823AF748;
	sub_823B9960(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,32536
	ctx.r4.s64 = ctx.r6.s64 + 32536;
	// bl 0x823b9960
	ctx.lr = 0x823AF75C;
	sub_823B9960(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,32528
	ctx.r4.s64 = ctx.r5.s64 + 32528;
	// bl 0x823b9960
	ctx.lr = 0x823AF770;
	sub_823B9960(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,32520
	ctx.r4.s64 = ctx.r4.s64 + 32520;
	// bl 0x823b9960
	ctx.lr = 0x823AF784;
	sub_823B9960(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,32504
	ctx.r4.s64 = r11.s64 + 32504;
	// bl 0x823b9960
	ctx.lr = 0x823AF798;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32488
	ctx.r4.s64 = ctx.r10.s64 + 32488;
	// bl 0x823b9960
	ctx.lr = 0x823AF7AC;
	sub_823B9960(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,32472
	ctx.r4.s64 = ctx.r9.s64 + 32472;
	// bl 0x823b9960
	ctx.lr = 0x823AF7C0;
	sub_823B9960(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,32460
	ctx.r4.s64 = ctx.r8.s64 + 32460;
	// bl 0x823b9960
	ctx.lr = 0x823AF7D4;
	sub_823B9960(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,32444
	ctx.r4.s64 = ctx.r7.s64 + 32444;
	// bl 0x823b9960
	ctx.lr = 0x823AF7E8;
	sub_823B9960(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,32424
	ctx.r4.s64 = ctx.r6.s64 + 32424;
	// bl 0x823b9960
	ctx.lr = 0x823AF7FC;
	sub_823B9960(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,32404
	ctx.r4.s64 = ctx.r5.s64 + 32404;
	// stw r14,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r14.u32);
	// bl 0x823b9960
	ctx.lr = 0x823AF814;
	sub_823B9960(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,32384
	ctx.r4.s64 = ctx.r4.s64 + 32384;
	// bl 0x823b9960
	ctx.lr = 0x823AF828;
	sub_823B9960(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,32360
	ctx.r4.s64 = r11.s64 + 32360;
	// bl 0x823b9960
	ctx.lr = 0x823AF83C;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32344
	ctx.r4.s64 = ctx.r10.s64 + 32344;
	// bl 0x823b9960
	ctx.lr = 0x823AF850;
	sub_823B9960(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,32320
	ctx.r4.s64 = ctx.r9.s64 + 32320;
	// bl 0x823b9960
	ctx.lr = 0x823AF864;
	sub_823B9960(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,32300
	ctx.r4.s64 = ctx.r8.s64 + 32300;
	// bl 0x823b9960
	ctx.lr = 0x823AF878;
	sub_823B9960(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,32276
	ctx.r4.s64 = ctx.r7.s64 + 32276;
	// bl 0x823b9960
	ctx.lr = 0x823AF88C;
	sub_823B9960(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r3,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,32252
	ctx.r4.s64 = ctx.r6.s64 + 32252;
	// bl 0x823b9960
	ctx.lr = 0x823AF8A0;
	sub_823B9960(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,32228
	ctx.r4.s64 = ctx.r5.s64 + 32228;
	// bl 0x823b9960
	ctx.lr = 0x823AF8B4;
	sub_823B9960(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,32204
	ctx.r4.s64 = ctx.r4.s64 + 32204;
	// bl 0x823b9960
	ctx.lr = 0x823AF8C8;
	sub_823B9960(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,32184
	ctx.r4.s64 = r11.s64 + 32184;
	// bl 0x823b9960
	ctx.lr = 0x823AF8DC;
	sub_823B9960(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,32156
	ctx.r4.s64 = ctx.r10.s64 + 32156;
	// bl 0x823b9960
	ctx.lr = 0x823AF8F0;
	sub_823B9960(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,32148
	ctx.r4.s64 = ctx.r9.s64 + 32148;
	// bl 0x823b9960
	ctx.lr = 0x823AF904;
	sub_823B9960(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r3,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,32140
	ctx.r4.s64 = ctx.r8.s64 + 32140;
	// bl 0x823b9960
	ctx.lr = 0x823AF918;
	sub_823B9960(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,32132
	ctx.r4.s64 = ctx.r7.s64 + 32132;
	// bl 0x823b9960
	ctx.lr = 0x823AF92C;
	sub_823B9960(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r4,r6,32116
	ctx.r4.s64 = ctx.r6.s64 + 32116;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b9960
	ctx.lr = 0x823AF940;
	sub_823B9960(ctx, base);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// addi r4,r5,-11868
	ctx.r4.s64 = ctx.r5.s64 + -11868;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823af988
	if (cr6.eq) goto loc_823AF988;
	// lis r11,-32198
	r11.s64 = -2110128128;
	// stw r30,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, r30.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r10,r11,23968
	ctx.r10.s64 = r11.s64 + 23968;
	// stw r10,684(r1)
	PPC_STORE_U32(ctx.r1.u32 + 684, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF974;
	sub_82130000(ctx, base);
	// stw r3,680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 680, ctx.r3.u32);
	// addi r4,r1,680
	ctx.r4.s64 = ctx.r1.s64 + 680;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8660
	ctx.lr = 0x823AF984;
	sub_823B8660(ctx, base);
	// b 0x823afa64
	goto loc_823AFA64;
loc_823AF988:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16984
	ctx.r10.s64 = r11.s64 + -16984;
	// stw r10,1300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1300, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF9A0;
	sub_82130000(ctx, base);
	// stw r3,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,1296
	r14.s64 = ctx.r1.s64 + 1296;
	// bl 0x823b99d0
	ctx.lr = 0x823AF9B0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AF9BC;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AF9C8;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,1304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1304, r30.u32);
	// addi r8,r9,-17000
	ctx.r8.s64 = ctx.r9.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,1308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1308, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AF9E0;
	sub_82130000(ctx, base);
	// stw r3,1304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1304, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,1304
	r14.s64 = ctx.r1.s64 + 1304;
	// bl 0x823b99d0
	ctx.lr = 0x823AF9F0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AF9FC;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFA08;
	sub_823B86A0(ctx, base);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,1312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1312, r30.u32);
	// addi r5,r7,8
	ctx.r5.s64 = ctx.r7.s64 + 8;
	// stw r30,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r30.u32);
	// addi r4,r6,-15072
	ctx.r4.s64 = ctx.r6.s64 + -15072;
	// stw r5,1316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1316, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFA30;
	sub_82130000(ctx, base);
	// stw r3,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,200
	r15.s64 = ctx.r1.s64 + 200;
	// addi r14,r1,1312
	r14.s64 = ctx.r1.s64 + 1312;
	// bl 0x823b99d0
	ctx.lr = 0x823AFA44;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823b9430
	ctx.lr = 0x823AFA50;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86b8
	ctx.lr = 0x823AFA60;
	sub_823B86B8(ctx, base);
	// lwz r14,88(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_823AFA64:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16368
	ctx.r10.s64 = r11.s64 + -16368;
	// stw r10,780(r1)
	PPC_STORE_U32(ctx.r1.u32 + 780, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFA7C;
	sub_82130000(ctx, base);
	// stw r3,776(r1)
	PPC_STORE_U32(ctx.r1.u32 + 776, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,776
	r15.s64 = ctx.r1.s64 + 776;
	// bl 0x823b99d0
	ctx.lr = 0x823AFA8C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFA98;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823b86a0
	ctx.lr = 0x823AFAA4;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-16320
	ctx.r8.s64 = ctx.r9.s64 + -16320;
	// stw r8,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFABC;
	sub_82130000(ctx, base);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,216
	r15.s64 = ctx.r1.s64 + 216;
	// bl 0x823b99d0
	ctx.lr = 0x823AFACC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFAD8;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x823b86a0
	ctx.lr = 0x823AFAE4;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,1064(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1064, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-16272
	ctx.r6.s64 = ctx.r7.s64 + -16272;
	// stw r6,1068(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1068, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFAFC;
	sub_82130000(ctx, base);
	// stw r3,1064(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1064, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1064
	r15.s64 = ctx.r1.s64 + 1064;
	// bl 0x823b99d0
	ctx.lr = 0x823AFB0C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFB18;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,124(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x823b86a0
	ctx.lr = 0x823AFB24;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-16224
	ctx.r4.s64 = ctx.r5.s64 + -16224;
	// stw r4,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFB3C;
	sub_82130000(ctx, base);
	// stw r3,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,232
	r15.s64 = ctx.r1.s64 + 232;
	// bl 0x823b99d0
	ctx.lr = 0x823AFB4C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFB58;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,156(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x823b86a0
	ctx.lr = 0x823AFB64;
	sub_823B86A0(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// stw r30,1328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1328, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// addi r15,r1,1328
	r15.s64 = ctx.r1.s64 + 1328;
	// stw r10,1332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1332, ctx.r10.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823AFB80;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFB8C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFB98;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-16024
	ctx.r8.s64 = ctx.r9.s64 + -16024;
	// stw r8,796(r1)
	PPC_STORE_U32(ctx.r1.u32 + 796, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFBB0;
	sub_82130000(ctx, base);
	// stw r3,792(r1)
	PPC_STORE_U32(ctx.r1.u32 + 792, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,792
	r15.s64 = ctx.r1.s64 + 792;
	// bl 0x823b99d0
	ctx.lr = 0x823AFBC0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFBCC;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,160(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// bl 0x823b86a0
	ctx.lr = 0x823AFBD8;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-15968
	ctx.r6.s64 = ctx.r7.s64 + -15968;
	// stw r6,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFBF0;
	sub_82130000(ctx, base);
	// stw r3,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,248
	r15.s64 = ctx.r1.s64 + 248;
	// bl 0x823b99d0
	ctx.lr = 0x823AFC00;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFC0C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,108(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823b86a0
	ctx.lr = 0x823AFC18;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,1208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1208, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-15912
	ctx.r4.s64 = ctx.r5.s64 + -15912;
	// stw r4,1212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1212, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFC30;
	sub_82130000(ctx, base);
	// stw r3,1208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1208, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1208
	r15.s64 = ctx.r1.s64 + 1208;
	// bl 0x823b99d0
	ctx.lr = 0x823AFC40;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFC4C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,104(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x823b86a0
	ctx.lr = 0x823AFC58;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15856
	ctx.r10.s64 = r11.s64 + -15856;
	// stw r10,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFC70;
	sub_82130000(ctx, base);
	// stw r3,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,264
	r15.s64 = ctx.r1.s64 + 264;
	// bl 0x823b99d0
	ctx.lr = 0x823AFC80;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFC8C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFC98;
	sub_823B86A0(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r30,1336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1336, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// addi r15,r1,1336
	r15.s64 = ctx.r1.s64 + 1336;
	// stw r8,1340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1340, ctx.r8.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823AFCB4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFCC0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFCCC;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-12224
	ctx.r6.s64 = ctx.r7.s64 + -12224;
	// stw r6,812(r1)
	PPC_STORE_U32(ctx.r1.u32 + 812, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFCE4;
	sub_82130000(ctx, base);
	// stw r3,808(r1)
	PPC_STORE_U32(ctx.r1.u32 + 808, ctx.r3.u32);
	// addi r4,r1,808
	ctx.r4.s64 = ctx.r1.s64 + 808;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b8660
	ctx.lr = 0x823AFCF4;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-11640
	ctx.r4.s64 = ctx.r5.s64 + -11640;
	// stw r4,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFD08;
	sub_82130000(ctx, base);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// ld r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x823b8658
	ctx.lr = 0x823AFD18;
	sub_823B8658(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// addi r11,r3,-16984
	r11.s64 = ctx.r3.s64 + -16984;
	// stw r30,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r11,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFD30;
	sub_82130000(ctx, base);
	// stw r3,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,280
	r15.s64 = ctx.r1.s64 + 280;
	// bl 0x823b99d0
	ctx.lr = 0x823AFD40;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFD4C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFD58;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, r30.u32);
	// addi r9,r10,-17000
	ctx.r9.s64 = ctx.r10.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,1084(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1084, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFD70;
	sub_82130000(ctx, base);
	// stw r3,1080(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1080, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1080
	r15.s64 = ctx.r1.s64 + 1080;
	// bl 0x823b99d0
	ctx.lr = 0x823AFD80;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFD8C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFD98;
	sub_823B86A0(ctx, base);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// stw r30,1320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1320, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,8
	ctx.r7.s64 = ctx.r8.s64 + 8;
	// addi r15,r1,1320
	r15.s64 = ctx.r1.s64 + 1320;
	// stw r7,1324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1324, ctx.r7.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823AFDB4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFDC0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFDCC;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-12000
	ctx.r5.s64 = ctx.r6.s64 + -12000;
	// stw r5,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFDE4;
	sub_82130000(ctx, base);
	// stw r3,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r3.u32);
	// addi r4,r1,296
	ctx.r4.s64 = ctx.r1.s64 + 296;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b8660
	ctx.lr = 0x823AFDF4;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-11704
	r11.s64 = ctx.r4.s64 + -11704;
	// stw r11,828(r1)
	PPC_STORE_U32(ctx.r1.u32 + 828, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFE0C;
	sub_82130000(ctx, base);
	// stw r3,824(r1)
	PPC_STORE_U32(ctx.r1.u32 + 824, ctx.r3.u32);
	// addi r4,r1,824
	ctx.r4.s64 = ctx.r1.s64 + 824;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b8678
	ctx.lr = 0x823AFE1C;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-11640
	ctx.r9.s64 = ctx.r10.s64 + -11640;
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFE30;
	sub_82130000(ctx, base);
	// stw r3,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// ld r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x823b8658
	ctx.lr = 0x823AFE40;
	sub_823B8658(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r11,r11,-11592
	r11.s64 = r11.s64 + -11592;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// addi r8,r10,32104
	ctx.r8.s64 = ctx.r10.s64 + 32104;
	// addi r10,r9,17572
	ctx.r10.s64 = ctx.r9.s64 + 17572;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823afec0
	if (cr6.eq) goto loc_823AFEC0;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823afec0
	if (!cr6.eq) goto loc_823AFEC0;
	// lis r11,-32196
	r11.s64 = -2109997056;
	// stw r30,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r11,-22472
	ctx.r10.s64 = r11.s64 + -22472;
	// stw r10,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFE94;
	sub_82130000(ctx, base);
	// stw r3,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,312
	r15.s64 = ctx.r1.s64 + 312;
	// bl 0x823b99d0
	ctx.lr = 0x823AFEA4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFEB0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// lwz r5,152(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x823b86e0
	ctx.lr = 0x823AFEC0;
	sub_823B86E0(ctx, base);
loc_823AFEC0:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16984
	ctx.r10.s64 = r11.s64 + -16984;
	// stw r10,1284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1284, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFED8;
	sub_82130000(ctx, base);
	// stw r3,1280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1280, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1280
	r15.s64 = ctx.r1.s64 + 1280;
	// bl 0x823b99d0
	ctx.lr = 0x823AFEE8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFEF4;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFF00;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r30.u32);
	// addi r8,r9,-17000
	ctx.r8.s64 = ctx.r9.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFF18;
	sub_82130000(ctx, base);
	// stw r3,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,328
	r15.s64 = ctx.r1.s64 + 328;
	// bl 0x823b99d0
	ctx.lr = 0x823AFF28;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFF34;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFF40;
	sub_823B86A0(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// stw r30,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, r30.u32);
	// addi r6,r7,13632
	ctx.r6.s64 = ctx.r7.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r6,844(r1)
	PPC_STORE_U32(ctx.r1.u32 + 844, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFF58;
	sub_82130000(ctx, base);
	// stw r3,840(r1)
	PPC_STORE_U32(ctx.r1.u32 + 840, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,840
	r15.s64 = ctx.r1.s64 + 840;
	// bl 0x823b99d0
	ctx.lr = 0x823AFF68;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFF74;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFF80;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-16200
	ctx.r4.s64 = ctx.r5.s64 + -16200;
	// stw r4,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFF98;
	sub_82130000(ctx, base);
	// stw r3,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,344
	r15.s64 = ctx.r1.s64 + 344;
	// bl 0x823b99d0
	ctx.lr = 0x823AFFA8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFFB4;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823AFFC0;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1096, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16144
	ctx.r10.s64 = r11.s64 + -16144;
	// stw r10,1100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1100, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823AFFD8;
	sub_82130000(ctx, base);
	// stw r3,1096(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1096, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1096
	r15.s64 = ctx.r1.s64 + 1096;
	// bl 0x823b99d0
	ctx.lr = 0x823AFFE8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823AFFF4;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0000;
	sub_823B86A0(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// addi r8,r9,-22472
	ctx.r8.s64 = ctx.r9.s64 + -22472;
	// stw r30,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r8,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0018;
	sub_82130000(ctx, base);
	// stw r3,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r11,32092
	r15.s64 = r11.s64 + 32092;
	// addi r14,r1,360
	r14.s64 = ctx.r1.s64 + 360;
	// stw r15,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r15.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823B0034;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0040;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0050;
	sub_823B86E0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-16088
	ctx.r6.s64 = ctx.r7.s64 + -16088;
	// stw r6,860(r1)
	PPC_STORE_U32(ctx.r1.u32 + 860, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0068;
	sub_82130000(ctx, base);
	// stw r3,856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 856, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,856
	r15.s64 = ctx.r1.s64 + 856;
	// bl 0x823b99d0
	ctx.lr = 0x823B0078;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0084;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0090;
	sub_823B86A0(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// stw r30,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, r30.u32);
	// addi r4,r5,-22472
	ctx.r4.s64 = ctx.r5.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B00A8;
	sub_82130000(ctx, base);
	// stw r3,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r11,32028
	r15.s64 = r11.s64 + 32028;
	// addi r14,r1,376
	r14.s64 = ctx.r1.s64 + 376;
	// stw r15,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r15.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823B00C4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B00D0;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B00E0;
	sub_823B86E0(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// stw r11,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, r11.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130000
	ctx.lr = 0x823B00F8;
	sub_82130000(ctx, base);
	// stw r3,1224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1224, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r10,31896
	r15.s64 = ctx.r10.s64 + 31896;
	// addi r14,r1,1224
	r14.s64 = ctx.r1.s64 + 1224;
	// bl 0x823b99d0
	ctx.lr = 0x823B0110;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B011C;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B012C;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-16072
	ctx.r8.s64 = ctx.r9.s64 + -16072;
	// stw r8,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0144;
	sub_82130000(ctx, base);
	// stw r3,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,392
	r15.s64 = ctx.r1.s64 + 392;
	// bl 0x823b99d0
	ctx.lr = 0x823B0154;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0160;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B016C;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-14896
	ctx.r6.s64 = ctx.r7.s64 + -14896;
	// stw r6,876(r1)
	PPC_STORE_U32(ctx.r1.u32 + 876, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0184;
	sub_82130000(ctx, base);
	// stw r3,872(r1)
	PPC_STORE_U32(ctx.r1.u32 + 872, ctx.r3.u32);
	// addi r4,r1,872
	ctx.r4.s64 = ctx.r1.s64 + 872;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0194;
	sub_823B8660(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-14512
	ctx.r4.s64 = ctx.r5.s64 + -14512;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B01A8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B01B8;
	sub_823B8658(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b029c
	if (!cr6.eq) goto loc_823B029C;
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b021c
	if (cr6.eq) goto loc_823B021C;
	// lis r11,-32196
	r11.s64 = -2109997056;
	// stw r30,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r11,-22472
	ctx.r10.s64 = r11.s64 + -22472;
	// stw r10,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B01F0;
	sub_82130000(ctx, base);
	// stw r3,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,408
	r15.s64 = ctx.r1.s64 + 408;
	// bl 0x823b99d0
	ctx.lr = 0x823B0200;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B020C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,152(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x823b86e0
	ctx.lr = 0x823B021C;
	sub_823B86E0(ctx, base);
loc_823B021C:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1112, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,-16984
	ctx.r10.s64 = r11.s64 + -16984;
	// stw r10,1116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1116, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0234;
	sub_82130000(ctx, base);
	// stw r3,1112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1112, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1112
	r15.s64 = ctx.r1.s64 + 1112;
	// bl 0x823b99d0
	ctx.lr = 0x823B0244;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0250;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B025C;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, r30.u32);
	// addi r8,r9,-17000
	ctx.r8.s64 = ctx.r9.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,428(r1)
	PPC_STORE_U32(ctx.r1.u32 + 428, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0274;
	sub_82130000(ctx, base);
	// stw r3,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,424
	r15.s64 = ctx.r1.s64 + 424;
	// bl 0x823b99d0
	ctx.lr = 0x823B0284;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0290;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B029C;
	sub_823B86A0(ctx, base);
loc_823B029C:
	// lis r11,-32198
	r11.s64 = -2110128128;
	// stw r30,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,4872
	ctx.r10.s64 = r11.s64 + 4872;
	// stw r10,892(r1)
	PPC_STORE_U32(ctx.r1.u32 + 892, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B02B4;
	sub_82130000(ctx, base);
	// stw r3,888(r1)
	PPC_STORE_U32(ctx.r1.u32 + 888, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,888
	r15.s64 = ctx.r1.s64 + 888;
	// bl 0x823b99d0
	ctx.lr = 0x823B02C4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B02D0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,144(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// bl 0x823b86a0
	ctx.lr = 0x823B02DC;
	sub_823B86A0(ctx, base);
	// lis r9,-32198
	ctx.r9.s64 = -2110128128;
	// stw r30,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, r30.u32);
	// addi r8,r9,13632
	ctx.r8.s64 = ctx.r9.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B02F4;
	sub_82130000(ctx, base);
	// stw r3,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,440
	r15.s64 = ctx.r1.s64 + 440;
	// bl 0x823b99d0
	ctx.lr = 0x823B0304;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0310;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B031C;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-15808
	ctx.r6.s64 = ctx.r7.s64 + -15808;
	// stw r6,1268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1268, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0334;
	sub_82130000(ctx, base);
	// stw r3,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1264
	r15.s64 = ctx.r1.s64 + 1264;
	// bl 0x823b99d0
	ctx.lr = 0x823B0344;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0350;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B035C;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, r30.u32);
	// addi r4,r5,-17120
	ctx.r4.s64 = ctx.r5.s64 + -17120;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r4,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0374;
	sub_82130000(ctx, base);
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,456
	r15.s64 = ctx.r1.s64 + 456;
	// bl 0x823b99d0
	ctx.lr = 0x823B0384;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0390;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B039C;
	sub_823B86A0(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// stw r30,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, r30.u32);
	// addi r11,r3,-17072
	r11.s64 = ctx.r3.s64 + -17072;
	// stw r11,908(r1)
	PPC_STORE_U32(ctx.r1.u32 + 908, r11.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130000
	ctx.lr = 0x823B03B4;
	sub_82130000(ctx, base);
	// stw r3,904(r1)
	PPC_STORE_U32(ctx.r1.u32 + 904, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,904
	r15.s64 = ctx.r1.s64 + 904;
	// bl 0x823b99d0
	ctx.lr = 0x823B03C4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B03D0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwz r5,164(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// bl 0x823b86a0
	ctx.lr = 0x823B03DC;
	sub_823B86A0(ctx, base);
	// lis r10,-32196
	ctx.r10.s64 = -2109997056;
	// addi r9,r10,-22472
	ctx.r9.s64 = ctx.r10.s64 + -22472;
	// stw r30,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r9,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B03F4;
	sub_82130000(ctx, base);
	// stw r3,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r8,31864
	r15.s64 = ctx.r8.s64 + 31864;
	// addi r14,r1,472
	r14.s64 = ctx.r1.s64 + 472;
	// bl 0x823b99d0
	ctx.lr = 0x823B040C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0418;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0428;
	sub_823B86E0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,1128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1128, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-16200
	ctx.r6.s64 = ctx.r7.s64 + -16200;
	// stw r6,1132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1132, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0440;
	sub_82130000(ctx, base);
	// stw r3,1128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1128, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1128
	r15.s64 = ctx.r1.s64 + 1128;
	// bl 0x823b99d0
	ctx.lr = 0x823B0450;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B045C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0468;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-16144
	ctx.r4.s64 = ctx.r5.s64 + -16144;
	// stw r4,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0480;
	sub_82130000(ctx, base);
	// stw r3,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,488
	r15.s64 = ctx.r1.s64 + 488;
	// bl 0x823b99d0
	ctx.lr = 0x823B0490;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B049C;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B04A8;
	sub_823B86A0(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// stw r11,924(r1)
	PPC_STORE_U32(ctx.r1.u32 + 924, r11.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130000
	ctx.lr = 0x823B04C0;
	sub_82130000(ctx, base);
	// stw r3,920(r1)
	PPC_STORE_U32(ctx.r1.u32 + 920, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,920
	r15.s64 = ctx.r1.s64 + 920;
	// bl 0x823b99d0
	ctx.lr = 0x823B04D0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B04DC;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// lwz r5,120(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x823b86e0
	ctx.lr = 0x823B04EC;
	sub_823B86E0(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r9,r10,-11632
	ctx.r9.s64 = ctx.r10.s64 + -11632;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b054c
	if (!cr6.eq) goto loc_823B054C;
	// lis r11,-32196
	r11.s64 = -2109997056;
	// stw r30,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r11,-22472
	ctx.r10.s64 = r11.s64 + -22472;
	// stw r10,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0518;
	sub_82130000(ctx, base);
	// stw r3,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r9,31800
	r15.s64 = ctx.r9.s64 + 31800;
	// addi r14,r1,504
	r14.s64 = ctx.r1.s64 + 504;
	// bl 0x823b99d0
	ctx.lr = 0x823B0530;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B053C;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// lwz r6,140(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// bl 0x823b86e0
	ctx.lr = 0x823B054C;
	sub_823B86E0(ctx, base);
loc_823B054C:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1240, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15744
	ctx.r10.s64 = r11.s64 + -15744;
	// stw r10,1244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1244, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0564;
	sub_82130000(ctx, base);
	// stw r3,1240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1240, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,1240
	r15.s64 = ctx.r1.s64 + 1240;
	// bl 0x823b99d0
	ctx.lr = 0x823B0574;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0580;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B058C;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-16072
	ctx.r8.s64 = ctx.r9.s64 + -16072;
	// stw r8,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B05A4;
	sub_82130000(ctx, base);
	// stw r3,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r1,520
	r15.s64 = ctx.r1.s64 + 520;
	// bl 0x823b99d0
	ctx.lr = 0x823B05B4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B05C0;
	sub_823B9430(ctx, base);
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B05CC;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-10704
	ctx.r6.s64 = ctx.r7.s64 + -10704;
	// stw r6,940(r1)
	PPC_STORE_U32(ctx.r1.u32 + 940, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B05E4;
	sub_82130000(ctx, base);
	// stw r3,936(r1)
	PPC_STORE_U32(ctx.r1.u32 + 936, ctx.r3.u32);
	// lwz r15,160(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// addi r4,r1,936
	ctx.r4.s64 = ctx.r1.s64 + 936;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B05F8;
	sub_823B8660(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B060C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B061C;
	sub_823B8658(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// addi r11,r3,-15696
	r11.s64 = ctx.r3.s64 + -15696;
	// stw r30,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,540(r1)
	PPC_STORE_U32(ctx.r1.u32 + 540, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0634;
	sub_82130000(ctx, base);
	// stw r3,536(r1)
	PPC_STORE_U32(ctx.r1.u32 + 536, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,536
	r14.s64 = ctx.r1.s64 + 536;
	// bl 0x823b99d0
	ctx.lr = 0x823B0644;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0650;
	sub_823B9430(ctx, base);
	// lwz r15,112(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0660;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,1144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1144, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-10504
	ctx.r9.s64 = ctx.r10.s64 + -10504;
	// stw r9,1148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1148, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0678;
	sub_82130000(ctx, base);
	// stw r3,1144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1144, ctx.r3.u32);
	// lwz r14,108(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,1144
	ctx.r4.s64 = ctx.r1.s64 + 1144;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B068C;
	sub_823B8660(ctx, base);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// addi r7,r8,0
	ctx.r7.s64 = ctx.r8.s64 + 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B06A0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B06B0;
	sub_823B8658(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// addi r5,r6,-15696
	ctx.r5.s64 = ctx.r6.s64 + -15696;
	// stw r30,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,556(r1)
	PPC_STORE_U32(ctx.r1.u32 + 556, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B06C8;
	sub_82130000(ctx, base);
	// stw r3,552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 552, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,552
	r14.s64 = ctx.r1.s64 + 552;
	// bl 0x823b99d0
	ctx.lr = 0x823B06D8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x823b9430
	ctx.lr = 0x823B06E4;
	sub_823B9430(ctx, base);
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B06F0;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-10304
	r11.s64 = ctx.r4.s64 + -10304;
	// stw r11,956(r1)
	PPC_STORE_U32(ctx.r1.u32 + 956, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0708;
	sub_82130000(ctx, base);
	// stw r3,952(r1)
	PPC_STORE_U32(ctx.r1.u32 + 952, ctx.r3.u32);
	// lwz r14,88(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r4,r1,952
	ctx.r4.s64 = ctx.r1.s64 + 952;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B071C;
	sub_823B8660(ctx, base);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0730;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0740;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,-15696
	ctx.r7.s64 = ctx.r8.s64 + -15696;
	// stw r30,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0758;
	sub_82130000(ctx, base);
	// stw r3,568(r1)
	PPC_STORE_U32(ctx.r1.u32 + 568, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,568
	r14.s64 = ctx.r1.s64 + 568;
	// bl 0x823b99d0
	ctx.lr = 0x823B0768;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x823b9430
	ctx.lr = 0x823B0774;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0780;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,1272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1272, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-9848
	ctx.r5.s64 = ctx.r6.s64 + -9848;
	// stw r5,1276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1276, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0798;
	sub_82130000(ctx, base);
	// stw r3,1272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1272, ctx.r3.u32);
	// lwz r14,104(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r4,r1,1272
	ctx.r4.s64 = ctx.r1.s64 + 1272;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B07AC;
	sub_823B8660(ctx, base);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,0
	r11.s64 = ctx.r4.s64 + 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B07C0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B07D0;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,-15696
	ctx.r9.s64 = ctx.r10.s64 + -15696;
	// stw r30,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B07E8;
	sub_82130000(ctx, base);
	// stw r3,584(r1)
	PPC_STORE_U32(ctx.r1.u32 + 584, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,584
	r14.s64 = ctx.r1.s64 + 584;
	// bl 0x823b99d0
	ctx.lr = 0x823B07F8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x823b9430
	ctx.lr = 0x823B0804;
	sub_823B9430(ctx, base);
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0810;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 968, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-9648
	ctx.r7.s64 = ctx.r8.s64 + -9648;
	// stw r7,972(r1)
	PPC_STORE_U32(ctx.r1.u32 + 972, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0828;
	sub_82130000(ctx, base);
	// stw r3,968(r1)
	PPC_STORE_U32(ctx.r1.u32 + 968, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r4,r1,968
	ctx.r4.s64 = ctx.r1.s64 + 968;
	// bl 0x823b8660
	ctx.lr = 0x823B0838;
	sub_823B8660(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-9456
	ctx.r5.s64 = ctx.r6.s64 + -9456;
	// stw r5,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0850;
	sub_82130000(ctx, base);
	// stw r3,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r3.u32);
	// addi r4,r1,600
	ctx.r4.s64 = ctx.r1.s64 + 600;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B0860;
	sub_823B8678(ctx, base);
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823b08c4
	if (cr6.eq) goto loc_823B08C4;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823b08c4
	if (!cr6.eq) goto loc_823B08C4;
	// lis r11,-32196
	r11.s64 = -2109997056;
	// stw r30,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r10,r11,-22472
	ctx.r10.s64 = r11.s64 + -22472;
	// stw r10,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0898;
	sub_82130000(ctx, base);
	// stw r3,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r9,31784
	r15.s64 = ctx.r9.s64 + 31784;
	// addi r14,r1,1160
	r14.s64 = ctx.r1.s64 + 1160;
	// bl 0x823b99d0
	ctx.lr = 0x823B08B0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x823b9430
	ctx.lr = 0x823B08BC;
	sub_823B9430(ctx, base);
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// b 0x823b0944
	goto loc_823B0944;
loc_823B08C4:
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15632
	ctx.r10.s64 = r11.s64 + -15632;
	// stw r10,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B08DC;
	sub_82130000(ctx, base);
	// stw r3,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,616
	r14.s64 = ctx.r1.s64 + 616;
	// bl 0x823b99d0
	ctx.lr = 0x823B08EC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B08F8;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// lwz r5,168(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x823b86a0
	ctx.lr = 0x823B0904;
	sub_823B86A0(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// stw r30,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, r30.u32);
	// addi r8,r9,-22472
	ctx.r8.s64 = ctx.r9.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r8,988(r1)
	PPC_STORE_U32(ctx.r1.u32 + 988, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B091C;
	sub_82130000(ctx, base);
	// stw r3,984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 984, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r7,31740
	r15.s64 = ctx.r7.s64 + 31740;
	// addi r14,r1,984
	r14.s64 = ctx.r1.s64 + 984;
	// bl 0x823b99d0
	ctx.lr = 0x823B0934;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x823b9430
	ctx.lr = 0x823B0940;
	sub_823B9430(ctx, base);
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_823B0944:
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0950;
	sub_823B86E0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-9344
	ctx.r10.s64 = r11.s64 + -9344;
	// stw r10,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0968;
	sub_82130000(ctx, base);
	// stw r3,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r3.u32);
	// lwz r15,168(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// addi r4,r1,632
	ctx.r4.s64 = ctx.r1.s64 + 632;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B097C;
	sub_823B8678(ctx, base);
	// lis r9,-32237
	ctx.r9.s64 = -2112684032;
	// stw r30,1344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1344, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// addi r14,r1,1344
	r14.s64 = ctx.r1.s64 + 1344;
	// stw r8,1348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1348, ctx.r8.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823B0998;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B09A4;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B09B0;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-10304
	ctx.r6.s64 = ctx.r7.s64 + -10304;
	// stw r6,1260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1260, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B09C8;
	sub_82130000(ctx, base);
	// stw r3,1256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1256, ctx.r3.u32);
	// lwz r15,156(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// addi r4,r1,1256
	ctx.r4.s64 = ctx.r1.s64 + 1256;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B09DC;
	sub_823B8660(ctx, base);
	// lis r5,-32237
	ctx.r5.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,0
	ctx.r4.s64 = ctx.r5.s64 + 0;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B09F0;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0A00;
	sub_823B8658(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// addi r11,r3,-15696
	r11.s64 = ctx.r3.s64 + -15696;
	// stw r30,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0A18;
	sub_82130000(ctx, base);
	// stw r3,648(r1)
	PPC_STORE_U32(ctx.r1.u32 + 648, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,648
	r14.s64 = ctx.r1.s64 + 648;
	// bl 0x823b99d0
	ctx.lr = 0x823B0A28;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0A34;
	sub_823B9430(ctx, base);
	// lwz r15,148(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0A44;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-10704
	ctx.r9.s64 = ctx.r10.s64 + -10704;
	// stw r9,1004(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1004, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0A5C;
	sub_82130000(ctx, base);
	// stw r3,1000(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1000, ctx.r3.u32);
	// lwz r14,116(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r4,r1,1000
	ctx.r4.s64 = ctx.r1.s64 + 1000;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0A70;
	sub_823B8660(ctx, base);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,0
	ctx.r7.s64 = ctx.r8.s64 + 0;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0A84;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0A94;
	sub_823B8658(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-15696
	ctx.r5.s64 = ctx.r6.s64 + -15696;
	// stw r5,668(r1)
	PPC_STORE_U32(ctx.r1.u32 + 668, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0AAC;
	sub_82130000(ctx, base);
	// stw r3,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,664
	r14.s64 = ctx.r1.s64 + 664;
	// bl 0x823b99d0
	ctx.lr = 0x823B0ABC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823b9430
	ctx.lr = 0x823B0AC8;
	sub_823B9430(ctx, base);
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0AD4;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,1176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1176, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-10504
	r11.s64 = ctx.r4.s64 + -10504;
	// stw r11,1180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1180, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0AEC;
	sub_82130000(ctx, base);
	// stw r3,1176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1176, ctx.r3.u32);
	// lwz r14,96(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r4,r1,1176
	ctx.r4.s64 = ctx.r1.s64 + 1176;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0B00;
	sub_823B8660(ctx, base);
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,0
	ctx.r9.s64 = ctx.r10.s64 + 0;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0B14;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0B24;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,-15696
	ctx.r7.s64 = ctx.r8.s64 + -15696;
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0B3C;
	sub_82130000(ctx, base);
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,176
	r14.s64 = ctx.r1.s64 + 176;
	// bl 0x823b99d0
	ctx.lr = 0x823B0B4C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x823b9430
	ctx.lr = 0x823B0B58;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0B64;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-9848
	ctx.r5.s64 = ctx.r6.s64 + -9848;
	// stw r5,1020(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1020, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0B7C;
	sub_82130000(ctx, base);
	// stw r3,1016(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1016, ctx.r3.u32);
	// lwz r14,124(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r4,r1,1016
	ctx.r4.s64 = ctx.r1.s64 + 1016;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0B90;
	sub_823B8660(ctx, base);
	// lis r4,-32237
	ctx.r4.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,0
	r11.s64 = ctx.r4.s64 + 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0BA4;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0BB4;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,-15696
	ctx.r9.s64 = ctx.r10.s64 + -15696;
	// stw r30,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0BCC;
	sub_82130000(ctx, base);
	// stw r3,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r1,696
	r14.s64 = ctx.r1.s64 + 696;
	// bl 0x823b99d0
	ctx.lr = 0x823B0BDC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x823b9430
	ctx.lr = 0x823B0BE8;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0BF4;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,1288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1288, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-9648
	ctx.r7.s64 = ctx.r8.s64 + -9648;
	// stw r7,1292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1292, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0C0C;
	sub_82130000(ctx, base);
	// stw r3,1288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1288, ctx.r3.u32);
	// addi r4,r1,1288
	ctx.r4.s64 = ctx.r1.s64 + 1288;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0C1C;
	sub_823B8660(ctx, base);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,0
	ctx.r5.s64 = ctx.r6.s64 + 0;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0C30;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0C40;
	sub_823B8658(ctx, base);
	// lis r4,-32196
	ctx.r4.s64 = -2109997056;
	// addi r11,r4,-22472
	r11.s64 = ctx.r4.s64 + -22472;
	// stw r30,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, r30.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0C58;
	sub_82130000(ctx, base);
	// stw r3,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r11,r1,712
	r11.s64 = ctx.r1.s64 + 712;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r14,r10,31684
	r14.s64 = ctx.r10.s64 + 31684;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// bl 0x823b99d0
	ctx.lr = 0x823B0C74;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// rotlwi r3,r15,0
	ctx.r3.u64 = __builtin_rotateleft32(r15.u32, 0);
	// bl 0x823b9430
	ctx.lr = 0x823B0C80;
	sub_823B9430(ctx, base);
	// lwz r15,100(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// lwz r4,120(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0C94;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,1032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1032, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-9192
	ctx.r8.s64 = ctx.r9.s64 + -9192;
	// stw r8,1036(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1036, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0CAC;
	sub_82130000(ctx, base);
	// stw r3,1032(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1032, ctx.r3.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// addi r4,r1,1032
	ctx.r4.s64 = ctx.r1.s64 + 1032;
	// bl 0x823b8660
	ctx.lr = 0x823B0CBC;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-9048
	ctx.r6.s64 = ctx.r7.s64 + -9048;
	// stw r6,732(r1)
	PPC_STORE_U32(ctx.r1.u32 + 732, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0CD4;
	sub_82130000(ctx, base);
	// stw r3,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, ctx.r3.u32);
	// addi r4,r1,728
	ctx.r4.s64 = ctx.r1.s64 + 728;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B0CE4;
	sub_823B8678(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// stw r30,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, r30.u32);
	// addi r4,r5,-22472
	ctx.r4.s64 = ctx.r5.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,1196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1196, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0CFC;
	sub_82130000(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r3,1192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1192, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r15,r11,31600
	r15.s64 = r11.s64 + 31600;
	// addi r14,r1,1192
	r14.s64 = ctx.r1.s64 + 1192;
	// bl 0x823b99d0
	ctx.lr = 0x823B0D14;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823b9430
	ctx.lr = 0x823B0D20;
	sub_823B9430(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0D30;
	sub_823B86E0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-14184
	ctx.r9.s64 = ctx.r10.s64 + -14184;
	// stw r9,748(r1)
	PPC_STORE_U32(ctx.r1.u32 + 748, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0D48;
	sub_82130000(ctx, base);
	// stw r3,744(r1)
	PPC_STORE_U32(ctx.r1.u32 + 744, ctx.r3.u32);
	// addi r4,r1,744
	ctx.r4.s64 = ctx.r1.s64 + 744;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0D58;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-13960
	ctx.r7.s64 = ctx.r8.s64 + -13960;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0D6C;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0D7C;
	sub_823B8658(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// addi r5,r6,-16984
	ctx.r5.s64 = ctx.r6.s64 + -16984;
	// stw r30,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,1052(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1052, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0D94;
	sub_82130000(ctx, base);
	// stw r3,1048(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1048, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,1048
	r18.s64 = ctx.r1.s64 + 1048;
	// bl 0x823b99d0
	ctx.lr = 0x823B0DA4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0DB0;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0DBC;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, r30.u32);
	// addi r11,r4,-17000
	r11.s64 = ctx.r4.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r11,764(r1)
	PPC_STORE_U32(ctx.r1.u32 + 764, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0DD4;
	sub_82130000(ctx, base);
	// stw r3,760(r1)
	PPC_STORE_U32(ctx.r1.u32 + 760, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,760
	r18.s64 = ctx.r1.s64 + 760;
	// bl 0x823b99d0
	ctx.lr = 0x823B0DE4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0DF0;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0DFC;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-15584
	ctx.r9.s64 = ctx.r10.s64 + -15584;
	// stw r9,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0E14;
	sub_82130000(ctx, base);
	// stw r3,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,184
	r18.s64 = ctx.r1.s64 + 184;
	// bl 0x823b99d0
	ctx.lr = 0x823B0E24;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0E30;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0E3C;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-16072
	ctx.r7.s64 = ctx.r8.s64 + -16072;
	// stw r7,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0E54;
	sub_82130000(ctx, base);
	// stw r3,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,192
	r18.s64 = ctx.r1.s64 + 192;
	// bl 0x823b99d0
	ctx.lr = 0x823B0E64;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0E70;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0E7C;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-13696
	ctx.r5.s64 = ctx.r6.s64 + -13696;
	// stw r5,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0E94;
	sub_82130000(ctx, base);
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B0EA4;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-13416
	r11.s64 = ctx.r4.s64 + -13416;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0EB8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B0EC8;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r10,-16984
	ctx.r9.s64 = ctx.r10.s64 + -16984;
	// stw r9,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0EE0;
	sub_82130000(ctx, base);
	// stw r3,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,224
	r18.s64 = ctx.r1.s64 + 224;
	// bl 0x823b99d0
	ctx.lr = 0x823B0EF0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0EFC;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0F08;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// addi r7,r8,-17000
	ctx.r7.s64 = ctx.r8.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0F20;
	sub_82130000(ctx, base);
	// stw r3,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,240
	r18.s64 = ctx.r1.s64 + 240;
	// bl 0x823b99d0
	ctx.lr = 0x823B0F30;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0F3C;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0F48;
	sub_823B86A0(ctx, base);
	// lis r6,-32196
	ctx.r6.s64 = -2109997056;
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// addi r5,r6,-22472
	ctx.r5.s64 = ctx.r6.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r5,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0F60;
	sub_82130000(ctx, base);
	// stw r3,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r4,31572
	r18.s64 = ctx.r4.s64 + 31572;
	// addi r17,r1,256
	r17.s64 = ctx.r1.s64 + 256;
	// bl 0x823b99d0
	ctx.lr = 0x823B0F78;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0F84;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B0F94;
	sub_823B86E0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// addi r10,r11,-16072
	ctx.r10.s64 = r11.s64 + -16072;
	// stw r30,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0FAC;
	sub_82130000(ctx, base);
	// stw r3,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,272
	r18.s64 = ctx.r1.s64 + 272;
	// bl 0x823b99d0
	ctx.lr = 0x823B0FBC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B0FC8;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B0FD4;
	sub_823B86A0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-13312
	ctx.r8.s64 = ctx.r9.s64 + -13312;
	// stw r8,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B0FEC;
	sub_82130000(ctx, base);
	// stw r3,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// lwz r18,164(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B1000;
	sub_823B8660(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-13096
	ctx.r6.s64 = ctx.r7.s64 + -13096;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1014;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B1024;
	sub_823B8658(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// addi r4,r5,-16984
	ctx.r4.s64 = ctx.r5.s64 + -16984;
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r4,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B103C;
	sub_82130000(ctx, base);
	// stw r3,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r17,r1,304
	r17.s64 = ctx.r1.s64 + 304;
	// bl 0x823b99d0
	ctx.lr = 0x823B104C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1058;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1064;
	sub_823B86A0(ctx, base);
	// lis r3,-32197
	ctx.r3.s64 = -2110062592;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// addi r11,r3,-17000
	r11.s64 = ctx.r3.s64 + -17000;
	// stw r11,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r11.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130000
	ctx.lr = 0x823B107C;
	sub_82130000(ctx, base);
	// stw r3,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r17,r1,320
	r17.s64 = ctx.r1.s64 + 320;
	// bl 0x823b99d0
	ctx.lr = 0x823B108C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1098;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B10A4;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-15560
	ctx.r9.s64 = ctx.r10.s64 + -15560;
	// stw r9,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B10BC;
	sub_82130000(ctx, base);
	// stw r3,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r17,r1,336
	r17.s64 = ctx.r1.s64 + 336;
	// bl 0x823b99d0
	ctx.lr = 0x823B10CC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B10D8;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B10E4;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-16072
	ctx.r7.s64 = ctx.r8.s64 + -16072;
	// stw r7,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B10FC;
	sub_82130000(ctx, base);
	// stw r3,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r17,r1,352
	r17.s64 = ctx.r1.s64 + 352;
	// bl 0x823b99d0
	ctx.lr = 0x823B110C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1118;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1124;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-12000
	ctx.r5.s64 = ctx.r6.s64 + -12000;
	// stw r5,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B113C;
	sub_82130000(ctx, base);
	// stw r3,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B114C;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-14512
	r11.s64 = ctx.r4.s64 + -14512;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1160;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B1170;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,-16984
	ctx.r9.s64 = ctx.r10.s64 + -16984;
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1188;
	sub_82130000(ctx, base);
	// stw r3,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,384
	r18.s64 = ctx.r1.s64 + 384;
	// bl 0x823b99d0
	ctx.lr = 0x823B1198;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B11A4;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B11B0;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, r30.u32);
	// addi r7,r8,-17000
	ctx.r7.s64 = ctx.r8.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B11C8;
	sub_82130000(ctx, base);
	// stw r3,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,400
	r18.s64 = ctx.r1.s64 + 400;
	// bl 0x823b99d0
	ctx.lr = 0x823B11D8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B11E4;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B11F0;
	sub_823B86A0(ctx, base);
	// lis r6,-32196
	ctx.r6.s64 = -2109997056;
	// stw r30,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r30.u32);
	// addi r5,r6,-22472
	ctx.r5.s64 = ctx.r6.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r5,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1208;
	sub_82130000(ctx, base);
	// stw r3,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r4,31488
	r18.s64 = ctx.r4.s64 + 31488;
	// addi r17,r1,416
	r17.s64 = ctx.r1.s64 + 416;
	// bl 0x823b99d0
	ctx.lr = 0x823B1220;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B122C;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B123C;
	sub_823B86E0(ctx, base);
	// lis r3,-32196
	ctx.r3.s64 = -2109997056;
	// stw r30,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, r30.u32);
	// addi r11,r3,-22472
	r11.s64 = ctx.r3.s64 + -22472;
	// stw r11,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, r11.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x82130000
	ctx.lr = 0x823B1254;
	sub_82130000(ctx, base);
	// stw r3,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r10,31400
	r18.s64 = ctx.r10.s64 + 31400;
	// addi r17,r1,432
	r17.s64 = ctx.r1.s64 + 432;
	// bl 0x823b99d0
	ctx.lr = 0x823B126C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1278;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B1288;
	sub_823B86E0(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// stw r30,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, r30.u32);
	// addi r8,r9,-22472
	ctx.r8.s64 = ctx.r9.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r8,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B12A0;
	sub_82130000(ctx, base);
	// stw r3,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r7,31360
	r18.s64 = ctx.r7.s64 + 31360;
	// addi r17,r1,448
	r17.s64 = ctx.r1.s64 + 448;
	// bl 0x823b99d0
	ctx.lr = 0x823B12B8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B12C4;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B12D4;
	sub_823B86E0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-16072
	ctx.r5.s64 = ctx.r6.s64 + -16072;
	// stw r5,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B12EC;
	sub_82130000(ctx, base);
	// stw r3,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,464
	r18.s64 = ctx.r1.s64 + 464;
	// bl 0x823b99d0
	ctx.lr = 0x823B12FC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1308;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1314;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-12928
	r11.s64 = ctx.r4.s64 + -12928;
	// stw r11,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B132C;
	sub_82130000(ctx, base);
	// stw r3,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r3.u32);
	// addi r4,r1,480
	ctx.r4.s64 = ctx.r1.s64 + 480;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B133C;
	sub_823B8660(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-14512
	ctx.r9.s64 = ctx.r10.s64 + -14512;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1350;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B1360;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,-16984
	ctx.r7.s64 = ctx.r8.s64 + -16984;
	// stw r30,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1378;
	sub_82130000(ctx, base);
	// stw r3,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,496
	r18.s64 = ctx.r1.s64 + 496;
	// bl 0x823b99d0
	ctx.lr = 0x823B1388;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1394;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B13A0;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, r30.u32);
	// addi r5,r6,-17000
	ctx.r5.s64 = ctx.r6.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B13B8;
	sub_82130000(ctx, base);
	// stw r3,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,512
	r18.s64 = ctx.r1.s64 + 512;
	// bl 0x823b99d0
	ctx.lr = 0x823B13C8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B13D4;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B13E0;
	sub_823B86A0(ctx, base);
	// lis r4,-32196
	ctx.r4.s64 = -2109997056;
	// stw r30,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, r30.u32);
	// addi r11,r4,-22472
	r11.s64 = ctx.r4.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,532(r1)
	PPC_STORE_U32(ctx.r1.u32 + 532, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B13F8;
	sub_82130000(ctx, base);
	// stw r3,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r10,31320
	r18.s64 = ctx.r10.s64 + 31320;
	// addi r17,r1,528
	r17.s64 = ctx.r1.s64 + 528;
	// bl 0x823b99d0
	ctx.lr = 0x823B1410;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B141C;
	sub_823B9430(ctx, base);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B142C;
	sub_823B86E0(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-15536
	ctx.r8.s64 = ctx.r9.s64 + -15536;
	// stw r8,548(r1)
	PPC_STORE_U32(ctx.r1.u32 + 548, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1444;
	sub_82130000(ctx, base);
	// stw r3,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,544
	r18.s64 = ctx.r1.s64 + 544;
	// bl 0x823b99d0
	ctx.lr = 0x823B1454;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1460;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B146C;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-16072
	ctx.r6.s64 = ctx.r7.s64 + -16072;
	// stw r6,564(r1)
	PPC_STORE_U32(ctx.r1.u32 + 564, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1484;
	sub_82130000(ctx, base);
	// stw r3,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r18,r1,560
	r18.s64 = ctx.r1.s64 + 560;
	// bl 0x823b99d0
	ctx.lr = 0x823B1494;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B14A0;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B14AC;
	sub_823B86A0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-12728
	ctx.r4.s64 = ctx.r5.s64 + -12728;
	// stw r4,580(r1)
	PPC_STORE_U32(ctx.r1.u32 + 580, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B14C4;
	sub_82130000(ctx, base);
	// stw r3,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r3.u32);
	// addi r4,r1,576
	ctx.r4.s64 = ctx.r1.s64 + 576;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B14D4;
	sub_823B8660(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14512
	ctx.r10.s64 = r11.s64 + -14512;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B14E8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B14F8;
	sub_823B8658(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// addi r8,r9,-16984
	ctx.r8.s64 = ctx.r9.s64 + -16984;
	// stw r30,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1510;
	sub_82130000(ctx, base);
	// stw r3,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,592
	r24.s64 = ctx.r1.s64 + 592;
	// bl 0x823b99d0
	ctx.lr = 0x823B1520;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B152C;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1538;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r30.u32);
	// addi r6,r7,-17000
	ctx.r6.s64 = ctx.r7.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r6,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1550;
	sub_82130000(ctx, base);
	// stw r3,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,608
	r24.s64 = ctx.r1.s64 + 608;
	// bl 0x823b99d0
	ctx.lr = 0x823B1560;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B156C;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1578;
	sub_823B86A0(ctx, base);
	// lis r5,-32196
	ctx.r5.s64 = -2109997056;
	// stw r30,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, r30.u32);
	// addi r4,r5,-22472
	ctx.r4.s64 = ctx.r5.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r4,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1590;
	sub_82130000(ctx, base);
	// stw r3,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r11,31280
	r24.s64 = r11.s64 + 31280;
	// addi r18,r1,624
	r18.s64 = ctx.r1.s64 + 624;
	// bl 0x823b99d0
	ctx.lr = 0x823B15A8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B15B4;
	sub_823B9430(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B15C4;
	sub_823B86E0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-15536
	ctx.r9.s64 = ctx.r10.s64 + -15536;
	// stw r9,644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 644, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B15DC;
	sub_82130000(ctx, base);
	// stw r3,640(r1)
	PPC_STORE_U32(ctx.r1.u32 + 640, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,640
	r25.s64 = ctx.r1.s64 + 640;
	// bl 0x823b99d0
	ctx.lr = 0x823B15EC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B15F8;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1604;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-16072
	ctx.r7.s64 = ctx.r8.s64 + -16072;
	// stw r7,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B161C;
	sub_82130000(ctx, base);
	// stw r3,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,656
	r25.s64 = ctx.r1.s64 + 656;
	// bl 0x823b99d0
	ctx.lr = 0x823B162C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1638;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1644;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-12528
	ctx.r5.s64 = ctx.r6.s64 + -12528;
	// stw r5,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B165C;
	sub_82130000(ctx, base);
	// stw r3,672(r1)
	PPC_STORE_U32(ctx.r1.u32 + 672, ctx.r3.u32);
	// addi r4,r1,672
	ctx.r4.s64 = ctx.r1.s64 + 672;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B166C;
	sub_823B8660(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-12296
	r11.s64 = ctx.r4.s64 + -12296;
	// stw r11,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1684;
	sub_82130000(ctx, base);
	// stw r3,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, ctx.r3.u32);
	// addi r4,r1,688
	ctx.r4.s64 = ctx.r1.s64 + 688;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B1694;
	sub_823B8678(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-12272
	ctx.r9.s64 = ctx.r10.s64 + -12272;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B16A8;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B16B8;
	sub_823B8658(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,-16984
	ctx.r7.s64 = ctx.r8.s64 + -16984;
	// stw r30,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B16D0;
	sub_82130000(ctx, base);
	// stw r3,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,704
	r25.s64 = ctx.r1.s64 + 704;
	// bl 0x823b99d0
	ctx.lr = 0x823B16E0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B16EC;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B16F8;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, r30.u32);
	// addi r5,r6,-17000
	ctx.r5.s64 = ctx.r6.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1710;
	sub_82130000(ctx, base);
	// stw r3,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,720
	r25.s64 = ctx.r1.s64 + 720;
	// bl 0x823b99d0
	ctx.lr = 0x823B1720;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B172C;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1738;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-15512
	r11.s64 = ctx.r4.s64 + -15512;
	// stw r11,740(r1)
	PPC_STORE_U32(ctx.r1.u32 + 740, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1750;
	sub_82130000(ctx, base);
	// stw r3,736(r1)
	PPC_STORE_U32(ctx.r1.u32 + 736, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,736
	r25.s64 = ctx.r1.s64 + 736;
	// bl 0x823b99d0
	ctx.lr = 0x823B1760;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B176C;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1778;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-16072
	ctx.r9.s64 = ctx.r10.s64 + -16072;
	// stw r9,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1790;
	sub_82130000(ctx, base);
	// stw r3,752(r1)
	PPC_STORE_U32(ctx.r1.u32 + 752, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,752
	r25.s64 = ctx.r1.s64 + 752;
	// bl 0x823b99d0
	ctx.lr = 0x823B17A0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B17AC;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B17B8;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-11520
	ctx.r7.s64 = ctx.r8.s64 + -11520;
	// stw r7,772(r1)
	PPC_STORE_U32(ctx.r1.u32 + 772, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B17D0;
	sub_82130000(ctx, base);
	// stw r3,768(r1)
	PPC_STORE_U32(ctx.r1.u32 + 768, ctx.r3.u32);
	// lwz r25,140(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B17E4;
	sub_823B8660(ctx, base);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// stw r30,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,0
	ctx.r5.s64 = ctx.r6.s64 + 0;
	// stw r5,788(r1)
	PPC_STORE_U32(ctx.r1.u32 + 788, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B17FC;
	sub_82130000(ctx, base);
	// stw r3,784(r1)
	PPC_STORE_U32(ctx.r1.u32 + 784, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r4,r1,784
	ctx.r4.s64 = ctx.r1.s64 + 784;
	// bl 0x823b8678
	ctx.lr = 0x823B180C;
	sub_823B8678(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-11168
	r11.s64 = ctx.r4.s64 + -11168;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1820;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B1830;
	sub_823B8658(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// addi r9,r10,-16984
	ctx.r9.s64 = ctx.r10.s64 + -16984;
	// stw r30,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,804(r1)
	PPC_STORE_U32(ctx.r1.u32 + 804, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1848;
	sub_82130000(ctx, base);
	// stw r3,800(r1)
	PPC_STORE_U32(ctx.r1.u32 + 800, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,800
	r24.s64 = ctx.r1.s64 + 800;
	// bl 0x823b99d0
	ctx.lr = 0x823B1858;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1864;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1870;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// addi r7,r8,-17000
	ctx.r7.s64 = ctx.r8.s64 + -17000;
	// stw r30,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,820(r1)
	PPC_STORE_U32(ctx.r1.u32 + 820, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1888;
	sub_82130000(ctx, base);
	// stw r3,816(r1)
	PPC_STORE_U32(ctx.r1.u32 + 816, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,816
	r24.s64 = ctx.r1.s64 + 816;
	// bl 0x823b99d0
	ctx.lr = 0x823B1898;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B18A4;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B18B0;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-15488
	ctx.r5.s64 = ctx.r6.s64 + -15488;
	// stw r5,836(r1)
	PPC_STORE_U32(ctx.r1.u32 + 836, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B18C8;
	sub_82130000(ctx, base);
	// stw r3,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,832
	r24.s64 = ctx.r1.s64 + 832;
	// bl 0x823b99d0
	ctx.lr = 0x823B18D8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B18E4;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B18F0;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-16072
	r11.s64 = ctx.r4.s64 + -16072;
	// stw r11,852(r1)
	PPC_STORE_U32(ctx.r1.u32 + 852, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1908;
	sub_82130000(ctx, base);
	// stw r3,848(r1)
	PPC_STORE_U32(ctx.r1.u32 + 848, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r24,r1,848
	r24.s64 = ctx.r1.s64 + 848;
	// bl 0x823b99d0
	ctx.lr = 0x823B1918;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1924;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1930;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-11120
	ctx.r9.s64 = ctx.r10.s64 + -11120;
	// stw r9,868(r1)
	PPC_STORE_U32(ctx.r1.u32 + 868, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1948;
	sub_82130000(ctx, base);
	// stw r3,864(r1)
	PPC_STORE_U32(ctx.r1.u32 + 864, ctx.r3.u32);
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B1958;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-12296
	ctx.r7.s64 = ctx.r8.s64 + -12296;
	// stw r7,884(r1)
	PPC_STORE_U32(ctx.r1.u32 + 884, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1970;
	sub_82130000(ctx, base);
	// stw r3,880(r1)
	PPC_STORE_U32(ctx.r1.u32 + 880, ctx.r3.u32);
	// addi r4,r1,880
	ctx.r4.s64 = ctx.r1.s64 + 880;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B1980;
	sub_823B8678(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-10824
	ctx.r5.s64 = ctx.r6.s64 + -10824;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1994;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B19A4;
	sub_823B8658(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// addi r11,r4,-16984
	r11.s64 = ctx.r4.s64 + -16984;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r30,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, r30.u32);
	// stw r11,900(r1)
	PPC_STORE_U32(ctx.r1.u32 + 900, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B19BC;
	sub_82130000(ctx, base);
	// stw r3,896(r1)
	PPC_STORE_U32(ctx.r1.u32 + 896, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,896
	r25.s64 = ctx.r1.s64 + 896;
	// bl 0x823b99d0
	ctx.lr = 0x823B19CC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B19D8;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B19E4;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, r30.u32);
	// addi r9,r10,-17000
	ctx.r9.s64 = ctx.r10.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,916(r1)
	PPC_STORE_U32(ctx.r1.u32 + 916, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B19FC;
	sub_82130000(ctx, base);
	// stw r3,912(r1)
	PPC_STORE_U32(ctx.r1.u32 + 912, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,912
	r25.s64 = ctx.r1.s64 + 912;
	// bl 0x823b99d0
	ctx.lr = 0x823B1A0C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1A18;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1A24;
	sub_823B86A0(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-15424
	ctx.r7.s64 = ctx.r8.s64 + -15424;
	// stw r7,932(r1)
	PPC_STORE_U32(ctx.r1.u32 + 932, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1A3C;
	sub_82130000(ctx, base);
	// stw r3,928(r1)
	PPC_STORE_U32(ctx.r1.u32 + 928, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,928
	r25.s64 = ctx.r1.s64 + 928;
	// bl 0x823b99d0
	ctx.lr = 0x823B1A4C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1A58;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1A64;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-15376
	ctx.r5.s64 = ctx.r6.s64 + -15376;
	// stw r5,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1A7C;
	sub_82130000(ctx, base);
	// stw r3,944(r1)
	PPC_STORE_U32(ctx.r1.u32 + 944, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,944
	r25.s64 = ctx.r1.s64 + 944;
	// bl 0x823b99d0
	ctx.lr = 0x823B1A8C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1A98;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1AA4;
	sub_823B86A0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-16072
	r11.s64 = ctx.r4.s64 + -16072;
	// stw r11,964(r1)
	PPC_STORE_U32(ctx.r1.u32 + 964, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1ABC;
	sub_82130000(ctx, base);
	// stw r3,960(r1)
	PPC_STORE_U32(ctx.r1.u32 + 960, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,960
	r25.s64 = ctx.r1.s64 + 960;
	// bl 0x823b99d0
	ctx.lr = 0x823B1ACC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1AD8;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1AE4;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-8720
	ctx.r9.s64 = ctx.r10.s64 + -8720;
	// stw r9,980(r1)
	PPC_STORE_U32(ctx.r1.u32 + 980, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1AFC;
	sub_82130000(ctx, base);
	// stw r3,976(r1)
	PPC_STORE_U32(ctx.r1.u32 + 976, ctx.r3.u32);
	// addi r4,r1,976
	ctx.r4.s64 = ctx.r1.s64 + 976;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B1B0C;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-8056
	ctx.r7.s64 = ctx.r8.s64 + -8056;
	// stw r7,996(r1)
	PPC_STORE_U32(ctx.r1.u32 + 996, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1B24;
	sub_82130000(ctx, base);
	// stw r3,992(r1)
	PPC_STORE_U32(ctx.r1.u32 + 992, ctx.r3.u32);
	// addi r4,r1,992
	ctx.r4.s64 = ctx.r1.s64 + 992;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B1B34;
	sub_823B8678(ctx, base);
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,0
	ctx.r5.s64 = ctx.r6.s64 + 0;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1B48;
	sub_82130000(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x823b8658
	ctx.lr = 0x823B1B58;
	sub_823B8658(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r4,-16984
	r11.s64 = ctx.r4.s64 + -16984;
	// stw r11,1012(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1012, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1B70;
	sub_82130000(ctx, base);
	// stw r3,1008(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1008, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1008
	r25.s64 = ctx.r1.s64 + 1008;
	// bl 0x823b99d0
	ctx.lr = 0x823B1B80;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1B8C;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1B98;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, r30.u32);
	// addi r9,r10,-17000
	ctx.r9.s64 = ctx.r10.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,1028(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1028, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1BB0;
	sub_82130000(ctx, base);
	// stw r3,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1024
	r25.s64 = ctx.r1.s64 + 1024;
	// bl 0x823b99d0
	ctx.lr = 0x823B1BC0;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1BCC;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1BD8;
	sub_823B86A0(ctx, base);
	// lis r8,-32196
	ctx.r8.s64 = -2109997056;
	// stw r30,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, r30.u32);
	// addi r7,r8,-22472
	ctx.r7.s64 = ctx.r8.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r7,1044(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1044, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1BF0;
	sub_82130000(ctx, base);
	// stw r3,1040(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1040, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r6,31112
	r25.s64 = ctx.r6.s64 + 31112;
	// addi r24,r1,1040
	r24.s64 = ctx.r1.s64 + 1040;
	// bl 0x823b99d0
	ctx.lr = 0x823B1C08;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1C14;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B1C24;
	sub_823B86E0(ctx, base);
	// lis r5,-32197
	ctx.r5.s64 = -2110062592;
	// stw r30,1056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1056, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-8816
	ctx.r4.s64 = ctx.r5.s64 + -8816;
	// stw r4,1060(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1060, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1C3C;
	sub_82130000(ctx, base);
	// stw r3,1056(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1056, ctx.r3.u32);
	// addi r4,r1,1056
	ctx.r4.s64 = ctx.r1.s64 + 1056;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B1C4C;
	sub_823B8660(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-8056
	ctx.r10.s64 = r11.s64 + -8056;
	// stw r10,1076(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1076, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1C64;
	sub_82130000(ctx, base);
	// stw r3,1072(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1072, ctx.r3.u32);
	// addi r4,r1,1072
	ctx.r4.s64 = ctx.r1.s64 + 1072;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b8678
	ctx.lr = 0x823B1C74;
	sub_823B8678(ctx, base);
	// lis r9,-32197
	ctx.r9.s64 = -2110062592;
	// stw r30,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, r30.u32);
	// addi r8,r9,-16984
	ctx.r8.s64 = ctx.r9.s64 + -16984;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,1092(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1092, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1C8C;
	sub_82130000(ctx, base);
	// stw r3,1088(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1088, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1088
	r25.s64 = ctx.r1.s64 + 1088;
	// bl 0x823b99d0
	ctx.lr = 0x823B1C9C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1CA8;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1CB4;
	sub_823B86A0(ctx, base);
	// lis r7,-32197
	ctx.r7.s64 = -2110062592;
	// stw r30,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, r30.u32);
	// addi r6,r7,-17000
	ctx.r6.s64 = ctx.r7.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r6,1108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1108, ctx.r6.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1CCC;
	sub_82130000(ctx, base);
	// stw r3,1104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1104, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1104
	r25.s64 = ctx.r1.s64 + 1104;
	// bl 0x823b99d0
	ctx.lr = 0x823B1CDC;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1CE8;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1CF4;
	sub_823B86A0(ctx, base);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// stw r30,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, r30.u32);
	// addi r4,r5,13632
	ctx.r4.s64 = ctx.r5.s64 + 13632;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r4,1124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1124, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1D0C;
	sub_82130000(ctx, base);
	// stw r3,1120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1120, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1120
	r25.s64 = ctx.r1.s64 + 1120;
	// bl 0x823b99d0
	ctx.lr = 0x823B1D1C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1D28;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1D34;
	sub_823B86A0(ctx, base);
	// lis r11,-32197
	r11.s64 = -2110062592;
	// stw r30,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16088
	ctx.r10.s64 = r11.s64 + -16088;
	// stw r10,1140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1140, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1D4C;
	sub_82130000(ctx, base);
	// stw r3,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1136
	r25.s64 = ctx.r1.s64 + 1136;
	// bl 0x823b99d0
	ctx.lr = 0x823B1D5C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1D68;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1D74;
	sub_823B86A0(ctx, base);
	// lis r9,-32196
	ctx.r9.s64 = -2109997056;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r30,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r30.u32);
	// addi r8,r9,-22472
	ctx.r8.s64 = ctx.r9.s64 + -22472;
	// stw r8,1156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1156, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1D8C;
	sub_82130000(ctx, base);
	// stw r3,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r7,31016
	r25.s64 = ctx.r7.s64 + 31016;
	// addi r24,r1,1152
	r24.s64 = ctx.r1.s64 + 1152;
	// bl 0x823b99d0
	ctx.lr = 0x823B1DA4;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1DB0;
	sub_823B9430(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B1DC0;
	sub_823B86E0(ctx, base);
	// lis r6,-32196
	ctx.r6.s64 = -2109997056;
	// stw r30,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, r30.u32);
	// addi r5,r6,-22472
	ctx.r5.s64 = ctx.r6.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r5,1172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1172, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1DD8;
	sub_82130000(ctx, base);
	// stw r3,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r26,r1,1168
	r26.s64 = ctx.r1.s64 + 1168;
	// bl 0x823b99d0
	ctx.lr = 0x823B1DE8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1DF4;
	sub_823B9430(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x823b86e0
	ctx.lr = 0x823B1E04;
	sub_823B86E0(ctx, base);
	// lis r4,-32197
	ctx.r4.s64 = -2110062592;
	// stw r30,1184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1184, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-16072
	r11.s64 = ctx.r4.s64 + -16072;
	// stw r11,1188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1188, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1E1C;
	sub_82130000(ctx, base);
	// stw r3,1184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1184, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r26,r1,1184
	r26.s64 = ctx.r1.s64 + 1184;
	// bl 0x823b99d0
	ctx.lr = 0x823B1E2C;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1E38;
	sub_823B9430(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1E44;
	sub_823B86A0(ctx, base);
	// lis r10,-32197
	ctx.r10.s64 = -2110062592;
	// stw r30,1200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1200, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-14896
	ctx.r9.s64 = ctx.r10.s64 + -14896;
	// stw r9,1204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1204, ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1E5C;
	sub_82130000(ctx, base);
	// stw r3,1200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1200, ctx.r3.u32);
	// lwz r26,144(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// addi r4,r1,1200
	ctx.r4.s64 = ctx.r1.s64 + 1200;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b8660
	ctx.lr = 0x823B1E70;
	sub_823B8660(ctx, base);
	// lis r8,-32197
	ctx.r8.s64 = -2110062592;
	// stw r30,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, r30.u32);
	// addi r7,r8,-16984
	ctx.r7.s64 = ctx.r8.s64 + -16984;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r7,1220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1220, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1E88;
	sub_82130000(ctx, base);
	// stw r3,1216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1216, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r1,1216
	r25.s64 = ctx.r1.s64 + 1216;
	// bl 0x823b99d0
	ctx.lr = 0x823B1E98;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1EA4;
	sub_823B9430(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1EB0;
	sub_823B86A0(ctx, base);
	// lis r6,-32197
	ctx.r6.s64 = -2110062592;
	// stw r30,1232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1232, r30.u32);
	// addi r5,r6,-17000
	ctx.r5.s64 = ctx.r6.s64 + -17000;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r5,1236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1236, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1EC8;
	sub_82130000(ctx, base);
	// stw r3,1232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1232, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r1,1232
	r27.s64 = ctx.r1.s64 + 1232;
	// bl 0x823b99d0
	ctx.lr = 0x823B1ED8;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1EE4;
	sub_823B9430(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823b86a0
	ctx.lr = 0x823B1EF0;
	sub_823B86A0(ctx, base);
	// lis r4,-32196
	ctx.r4.s64 = -2109997056;
	// stw r30,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, r30.u32);
	// addi r11,r4,-22472
	r11.s64 = ctx.r4.s64 + -22472;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r11,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823B1F08;
	sub_82130000(ctx, base);
	// stw r3,1248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1248, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,30992
	r31.s64 = ctx.r10.s64 + 30992;
	// addi r30,r1,1248
	r30.s64 = ctx.r1.s64 + 1248;
	// bl 0x823b99d0
	ctx.lr = 0x823B1F20;
	sub_823B99D0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823b9430
	ctx.lr = 0x823B1F2C;
	sub_823B9430(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x823b86e0
	ctx.lr = 0x823B1F3C;
	sub_823B86E0(ctx, base);
	// addi r1,r1,1504
	ctx.r1.s64 = ctx.r1.s64 + 1504;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_823B1F44"))) PPC_WEAK_FUNC(sub_823B1F44);
PPC_FUNC_IMPL(__imp__sub_823B1F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1F48"))) PPC_WEAK_FUNC(sub_823B1F48);
PPC_FUNC_IMPL(__imp__sub_823B1F48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F50"))) PPC_WEAK_FUNC(sub_823B1F50);
PPC_FUNC_IMPL(__imp__sub_823B1F50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,22,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F5C"))) PPC_WEAK_FUNC(sub_823B1F5C);
PPC_FUNC_IMPL(__imp__sub_823B1F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1F60"))) PPC_WEAK_FUNC(sub_823B1F60);
PPC_FUNC_IMPL(__imp__sub_823B1F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,6,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F6C"))) PPC_WEAK_FUNC(sub_823B1F6C);
PPC_FUNC_IMPL(__imp__sub_823B1F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1F70"))) PPC_WEAK_FUNC(sub_823B1F70);
PPC_FUNC_IMPL(__imp__sub_823B1F70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F7C"))) PPC_WEAK_FUNC(sub_823B1F7C);
PPC_FUNC_IMPL(__imp__sub_823B1F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1F80"))) PPC_WEAK_FUNC(sub_823B1F80);
PPC_FUNC_IMPL(__imp__sub_823B1F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,21,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F8C"))) PPC_WEAK_FUNC(sub_823B1F8C);
PPC_FUNC_IMPL(__imp__sub_823B1F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1F90"))) PPC_WEAK_FUNC(sub_823B1F90);
PPC_FUNC_IMPL(__imp__sub_823B1F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1F9C"))) PPC_WEAK_FUNC(sub_823B1F9C);
PPC_FUNC_IMPL(__imp__sub_823B1F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1FA0"))) PPC_WEAK_FUNC(sub_823B1FA0);
PPC_FUNC_IMPL(__imp__sub_823B1FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1FB4"))) PPC_WEAK_FUNC(sub_823B1FB4);
PPC_FUNC_IMPL(__imp__sub_823B1FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1FB8"))) PPC_WEAK_FUNC(sub_823B1FB8);
PPC_FUNC_IMPL(__imp__sub_823B1FB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1FCC"))) PPC_WEAK_FUNC(sub_823B1FCC);
PPC_FUNC_IMPL(__imp__sub_823B1FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1FD0"))) PPC_WEAK_FUNC(sub_823B1FD0);
PPC_FUNC_IMPL(__imp__sub_823B1FD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1FE4"))) PPC_WEAK_FUNC(sub_823B1FE4);
PPC_FUNC_IMPL(__imp__sub_823B1FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B1FE8"))) PPC_WEAK_FUNC(sub_823B1FE8);
PPC_FUNC_IMPL(__imp__sub_823B1FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B1FFC"))) PPC_WEAK_FUNC(sub_823B1FFC);
PPC_FUNC_IMPL(__imp__sub_823B1FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2000"))) PPC_WEAK_FUNC(sub_823B2000);
PPC_FUNC_IMPL(__imp__sub_823B2000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-5
	r11.s64 = r11.s64 + -5;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B2014"))) PPC_WEAK_FUNC(sub_823B2014);
PPC_FUNC_IMPL(__imp__sub_823B2014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2018"))) PPC_WEAK_FUNC(sub_823B2018);
PPC_FUNC_IMPL(__imp__sub_823B2018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-6
	r11.s64 = r11.s64 + -6;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B202C"))) PPC_WEAK_FUNC(sub_823B202C);
PPC_FUNC_IMPL(__imp__sub_823B202C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2030"))) PPC_WEAK_FUNC(sub_823B2030);
PPC_FUNC_IMPL(__imp__sub_823B2030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-7
	r11.s64 = r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B2044"))) PPC_WEAK_FUNC(sub_823B2044);
PPC_FUNC_IMPL(__imp__sub_823B2044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2048"))) PPC_WEAK_FUNC(sub_823B2048);
PPC_FUNC_IMPL(__imp__sub_823B2048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B205C"))) PPC_WEAK_FUNC(sub_823B205C);
PPC_FUNC_IMPL(__imp__sub_823B205C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2060"))) PPC_WEAK_FUNC(sub_823B2060);
PPC_FUNC_IMPL(__imp__sub_823B2060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-9
	r11.s64 = r11.s64 + -9;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B2074"))) PPC_WEAK_FUNC(sub_823B2074);
PPC_FUNC_IMPL(__imp__sub_823B2074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2078"))) PPC_WEAK_FUNC(sub_823B2078);
PPC_FUNC_IMPL(__imp__sub_823B2078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-10
	r11.s64 = r11.s64 + -10;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B208C"))) PPC_WEAK_FUNC(sub_823B208C);
PPC_FUNC_IMPL(__imp__sub_823B208C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B2090"))) PPC_WEAK_FUNC(sub_823B2090);
PPC_FUNC_IMPL(__imp__sub_823B2090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-11
	r11.s64 = r11.s64 + -11;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B20A4"))) PPC_WEAK_FUNC(sub_823B20A4);
PPC_FUNC_IMPL(__imp__sub_823B20A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B20A8"))) PPC_WEAK_FUNC(sub_823B20A8);
PPC_FUNC_IMPL(__imp__sub_823B20A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-13
	r11.s64 = r11.s64 + -13;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B20BC"))) PPC_WEAK_FUNC(sub_823B20BC);
PPC_FUNC_IMPL(__imp__sub_823B20BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B20C0"))) PPC_WEAK_FUNC(sub_823B20C0);
PPC_FUNC_IMPL(__imp__sub_823B20C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-17
	r11.s64 = r11.s64 + -17;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B20D4"))) PPC_WEAK_FUNC(sub_823B20D4);
PPC_FUNC_IMPL(__imp__sub_823B20D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823B20D8"))) PPC_WEAK_FUNC(sub_823B20D8);
PPC_FUNC_IMPL(__imp__sub_823B20D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-18
	r11.s64 = r11.s64 + -18;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823B20EC"))) PPC_WEAK_FUNC(sub_823B20EC);
PPC_FUNC_IMPL(__imp__sub_823B20EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

