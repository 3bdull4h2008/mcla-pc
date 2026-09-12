#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82235490"))) PPC_WEAK_FUNC(sub_82235490);
PPC_FUNC_IMPL(__imp__sub_82235490) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-31148
	ctx.r5.s64 = r11.s64 + -31148;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,476
	ctx.r6.s64 = r31.s64 + 476;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822354CC;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-31164
	ctx.r5.s64 = ctx.r10.s64 + -31164;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,480
	ctx.r6.s64 = r31.s64 + 480;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822354EC;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-31176
	ctx.r5.s64 = ctx.r9.s64 + -31176;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,484
	ctx.r6.s64 = r31.s64 + 484;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223550C;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31192
	ctx.r5.s64 = ctx.r8.s64 + -31192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,488
	ctx.r6.s64 = r31.s64 + 488;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223552C;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-31212
	ctx.r5.s64 = ctx.r7.s64 + -31212;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,492
	ctx.r6.s64 = r31.s64 + 492;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223554C;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31232
	ctx.r5.s64 = ctx.r6.s64 + -31232;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,496
	ctx.r6.s64 = r31.s64 + 496;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223556C;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-31248
	ctx.r5.s64 = ctx.r5.s64 + -31248;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,500
	ctx.r6.s64 = r31.s64 + 500;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8223558C;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r4,-31264
	ctx.r4.s64 = ctx.r4.s64 + -31264;
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// bl 0x82235360
	ctx.lr = 0x822355A0;
	sub_82235360(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-32400
	ctx.r5.s64 = r11.s64 + -32400;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,532
	ctx.r6.s64 = r31.s64 + 532;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822355C0;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-32416
	ctx.r5.s64 = ctx.r10.s64 + -32416;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,536
	ctx.r6.s64 = r31.s64 + 536;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822355E0;
	sub_824DF200(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r6,r31,540
	ctx.r6.s64 = r31.s64 + 540;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-32436
	ctx.r5.s64 = ctx.r9.s64 + -32436;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235600;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31284
	ctx.r5.s64 = ctx.r8.s64 + -31284;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,544
	ctx.r6.s64 = r31.s64 + 544;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x82235620;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-31300
	ctx.r5.s64 = ctx.r7.s64 + -31300;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,548
	ctx.r6.s64 = r31.s64 + 548;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235640;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31312
	ctx.r5.s64 = ctx.r6.s64 + -31312;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,552
	ctx.r6.s64 = r31.s64 + 552;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235660;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-31332
	ctx.r5.s64 = ctx.r5.s64 + -31332;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,556
	ctx.r6.s64 = r31.s64 + 556;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235680;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-31352
	ctx.r5.s64 = ctx.r4.s64 + -31352;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,560
	ctx.r6.s64 = r31.s64 + 560;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822356A0;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-31372
	ctx.r5.s64 = r11.s64 + -31372;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,576
	ctx.r6.s64 = r31.s64 + 576;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822356C0;
	sub_824DF200(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-16516
	ctx.r6.s64 = ctx.r10.s64 + -16516;
	// addi r5,r9,-31392
	ctx.r5.s64 = ctx.r9.s64 + -31392;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822356E4;
	sub_824DF200(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r6,r8,-16524
	ctx.r6.s64 = ctx.r8.s64 + -16524;
	// addi r5,r7,-31412
	ctx.r5.s64 = ctx.r7.s64 + -31412;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235708;
	sub_824DF200(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r6,r6,-16520
	ctx.r6.s64 = ctx.r6.s64 + -16520;
	// addi r5,r5,-31428
	ctx.r5.s64 = ctx.r5.s64 + -31428;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8223572C;
	sub_824DF200(ctx, base);
	// lwz r4,192(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82235740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-31448
	ctx.r5.s64 = ctx.r10.s64 + -31448;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235760;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-31464
	ctx.r5.s64 = ctx.r9.s64 + -31464;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,580
	ctx.r6.s64 = r31.s64 + 580;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235780;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31484
	ctx.r5.s64 = ctx.r8.s64 + -31484;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,584
	ctx.r6.s64 = r31.s64 + 584;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822357A0;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-31512
	ctx.r5.s64 = ctx.r7.s64 + -31512;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,588
	ctx.r6.s64 = r31.s64 + 588;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822357C0;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31528
	ctx.r5.s64 = ctx.r6.s64 + -31528;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,992
	ctx.r6.s64 = r31.s64 + 992;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x822357E0;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-31540
	ctx.r5.s64 = ctx.r5.s64 + -31540;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,304
	ctx.r6.s64 = r31.s64 + 304;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x82235800;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-31556
	ctx.r5.s64 = ctx.r4.s64 + -31556;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,608
	ctx.r6.s64 = r31.s64 + 608;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235820;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-31572
	ctx.r5.s64 = r11.s64 + -31572;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,624
	ctx.r6.s64 = r31.s64 + 624;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235840;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-31588
	ctx.r5.s64 = ctx.r10.s64 + -31588;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,640
	ctx.r6.s64 = r31.s64 + 640;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82235860;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,656
	ctx.r6.s64 = r31.s64 + 656;
	// addi r5,r9,-31604
	ctx.r5.s64 = ctx.r9.s64 + -31604;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235880;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31620
	ctx.r5.s64 = ctx.r8.s64 + -31620;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,672
	ctx.r6.s64 = r31.s64 + 672;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822358A0;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-31640
	ctx.r5.s64 = ctx.r7.s64 + -31640;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,688
	ctx.r6.s64 = r31.s64 + 688;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822358C0;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31656
	ctx.r5.s64 = ctx.r6.s64 + -31656;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,704
	ctx.r6.s64 = r31.s64 + 704;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822358E0;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-31672
	ctx.r5.s64 = ctx.r5.s64 + -31672;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,720
	ctx.r6.s64 = r31.s64 + 720;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235900;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-31684
	ctx.r5.s64 = ctx.r4.s64 + -31684;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,752
	ctx.r6.s64 = r31.s64 + 752;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235920;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-31700
	ctx.r5.s64 = r11.s64 + -31700;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,736
	ctx.r6.s64 = r31.s64 + 736;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235940;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-31716
	ctx.r5.s64 = ctx.r10.s64 + -31716;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,768
	ctx.r6.s64 = r31.s64 + 768;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235960;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-31728
	ctx.r5.s64 = ctx.r9.s64 + -31728;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,784
	ctx.r6.s64 = r31.s64 + 784;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235980;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31740
	ctx.r5.s64 = ctx.r8.s64 + -31740;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,800
	ctx.r6.s64 = r31.s64 + 800;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822359A0;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-31756
	ctx.r5.s64 = ctx.r7.s64 + -31756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,816
	ctx.r6.s64 = r31.s64 + 816;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822359C0;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31776
	ctx.r5.s64 = ctx.r6.s64 + -31776;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,832
	ctx.r6.s64 = r31.s64 + 832;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822359E0;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-31800
	ctx.r5.s64 = ctx.r5.s64 + -31800;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,848
	ctx.r6.s64 = r31.s64 + 848;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235A00;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-31824
	ctx.r5.s64 = ctx.r4.s64 + -31824;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,864
	ctx.r6.s64 = r31.s64 + 864;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235A20;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-31844
	ctx.r5.s64 = r11.s64 + -31844;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,880
	ctx.r6.s64 = r31.s64 + 880;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235A40;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-31868
	ctx.r5.s64 = ctx.r10.s64 + -31868;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,896
	ctx.r6.s64 = r31.s64 + 896;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235A60;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-31892
	ctx.r5.s64 = ctx.r9.s64 + -31892;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,912
	ctx.r6.s64 = r31.s64 + 912;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235A80;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-31912
	ctx.r5.s64 = ctx.r8.s64 + -31912;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,928
	ctx.r6.s64 = r31.s64 + 928;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235AA0;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-31928
	ctx.r5.s64 = ctx.r7.s64 + -31928;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,944
	ctx.r6.s64 = r31.s64 + 944;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235AC0;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-31944
	ctx.r5.s64 = ctx.r6.s64 + -31944;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,960
	ctx.r6.s64 = r31.s64 + 960;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235AE0;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r5,-31968
	ctx.r5.s64 = ctx.r5.s64 + -31968;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,504
	ctx.r6.s64 = r31.s64 + 504;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82235B00;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-31992
	ctx.r5.s64 = ctx.r4.s64 + -31992;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,474
	ctx.r6.s64 = r31.s64 + 474;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x82235B20;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-32008
	ctx.r5.s64 = r11.s64 + -32008;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,592
	ctx.r6.s64 = r31.s64 + 592;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235B40;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-32032
	ctx.r5.s64 = ctx.r10.s64 + -32032;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,596
	ctx.r6.s64 = r31.s64 + 596;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235B60;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-32044
	ctx.r5.s64 = ctx.r9.s64 + -32044;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,976
	ctx.r6.s64 = r31.s64 + 976;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x82235B80;
	sub_824DF200(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r6,r8,-8508
	ctx.r6.s64 = ctx.r8.s64 + -8508;
	// addi r5,r7,-32060
	ctx.r5.s64 = ctx.r7.s64 + -32060;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235BA4;
	sub_824DF200(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r6,-8516
	ctx.r6.s64 = ctx.r6.s64 + -8516;
	// addi r5,r5,-32076
	ctx.r5.s64 = ctx.r5.s64 + -32076;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235BC8;
	sub_824DF200(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r4,-8512
	ctx.r6.s64 = ctx.r4.s64 + -8512;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-32088
	ctx.r5.s64 = r11.s64 + -32088;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235BEC;
	sub_824DF200(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r10,-8500
	ctx.r6.s64 = ctx.r10.s64 + -8500;
	// addi r5,r9,-32104
	ctx.r5.s64 = ctx.r9.s64 + -32104;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235C10;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-32124
	ctx.r5.s64 = ctx.r7.s64 + -32124;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1020
	ctx.r6.s64 = r31.s64 + 1020;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82235C30;
	sub_824DF200(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1024
	ctx.r6.s64 = r31.s64 + 1024;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-32148
	ctx.r5.s64 = ctx.r5.s64 + -32148;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x82235C50;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-32180
	ctx.r5.s64 = ctx.r4.s64 + -32180;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1028
	ctx.r6.s64 = r31.s64 + 1028;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x82235C70;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-32208
	ctx.r5.s64 = r11.s64 + -32208;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1032
	ctx.r6.s64 = r31.s64 + 1032;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x82235C90;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-32232
	ctx.r5.s64 = ctx.r10.s64 + -32232;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1033
	ctx.r6.s64 = r31.s64 + 1033;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x82235CB0;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-32256
	ctx.r5.s64 = ctx.r9.s64 + -32256;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,564
	ctx.r6.s64 = r31.s64 + 564;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235CD0;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-32280
	ctx.r5.s64 = ctx.r8.s64 + -32280;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,568
	ctx.r6.s64 = r31.s64 + 568;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235CF0;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-32308
	ctx.r5.s64 = ctx.r7.s64 + -32308;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,572
	ctx.r6.s64 = r31.s64 + 572;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235D10;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-32332
	ctx.r5.s64 = ctx.r6.s64 + -32332;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1008
	ctx.r6.s64 = r31.s64 + 1008;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235D30;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-32364
	ctx.r5.s64 = ctx.r5.s64 + -32364;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1012
	ctx.r6.s64 = r31.s64 + 1012;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235D50;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-32388
	ctx.r5.s64 = ctx.r4.s64 + -32388;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1016
	ctx.r6.s64 = r31.s64 + 1016;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x82235D70;
	sub_824DF200(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82235D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,56(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82235DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82235DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,340(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 340);
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82235DD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// addi r3,r31,320
	ctx.r3.s64 = r31.s64 + 320;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82235DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x82239200
	ctx.lr = 0x82235DF4;
	sub_82239200(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,260
	ctx.r3.s64 = r31.s64 + 260;
	// bl 0x82239110
	ctx.lr = 0x82235E00;
	sub_82239110(ctx, base);
	// lwz r8,208(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82235E18;
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

__attribute__((alias("__imp__sub_82235E30"))) PPC_WEAK_FUNC(sub_82235E30);
PPC_FUNC_IMPL(__imp__sub_82235E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	ctx.lr = 0x82235E4C;
	sub_82224A40(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vspltw128 v12,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vspltw128 v6,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v57,v59,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v10,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vspltw128 v8,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v63,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v5,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmulfp128 v7,v63,v57
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v4,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v31,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82235EE0"))) PPC_WEAK_FUNC(sub_82235EE0);
PPC_FUNC_IMPL(__imp__sub_82235EE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	ctx.lr = 0x82235EFC;
	sub_82234FC0(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vspltw128 v12,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vspltw128 v6,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v57,v59,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v63,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v10,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vspltw128 v8,v59,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xAA));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v63,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v5,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmulfp128 v7,v63,v57
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v4,v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x55));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v31,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82235F90"))) PPC_WEAK_FUNC(sub_82235F90);
PPC_FUNC_IMPL(__imp__sub_82235F90) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-32560
	ctx.r9.s64 = r11.s64 + -32560;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82235fc4
	if (cr6.eq) goto loc_82235FC4;
	// bl 0x82130588
	ctx.lr = 0x82235FC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82235FC4:
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

__attribute__((alias("__imp__sub_82235FD8"))) PPC_WEAK_FUNC(sub_82235FD8);
PPC_FUNC_IMPL(__imp__sub_82235FD8) {
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
	ctx.lr = 0x82235FE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r28,r29,408
	r28.s64 = r29.s64 + 408;
	// addi r10,r11,-31100
	ctx.r10.s64 = r11.s64 + -31100;
	// li r27,3
	r27.s64 = 3;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_82235FFC:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82236044
	if (cr6.eq) goto loc_82236044;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,40
	r30.s64 = 40;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// beq cr6,0x82236038
	if (cr6.eq) goto loc_82236038;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82236038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82236038:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
loc_82236044:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82235ffc
	if (!cr0.eq) goto loc_82235FFC;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,40
	r30.s64 = 40;
	// lwz r3,420(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 420);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// beq cr6,0x82236084
	if (cr6.eq) goto loc_82236084;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82236084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82236084:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// lwz r3,424(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 424);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r10,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r10.u32);
	// beq cr6,0x822360b8
	if (cr6.eq) goto loc_822360B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822360B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822360B8:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// lwz r3,428(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 428);
	// stwx r10,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822360ec
	if (cr6.eq) goto loc_822360EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822360EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822360EC:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// lwz r3,432(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82236204
	if (cr6.eq) goto loc_82236204;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// beq cr6,0x82236128
	if (cr6.eq) goto loc_82236128;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82236128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82236128:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,436(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 436);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// beq cr6,0x8223615c
	if (cr6.eq) goto loc_8223615C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223615C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223615C:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 440);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82236190
	if (cr6.eq) goto loc_82236190;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82236190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82236190:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,444(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 444);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822361c4
	if (cr6.eq) goto loc_822361C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822361C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822361C4:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,448(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 448);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822361f8
	if (cr6.eq) goto loc_822361F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822361F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822361F8:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
loc_82236204:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r29,360
	ctx.r3.s64 = r29.s64 + 360;
	// addi r31,r11,-32560
	r31.s64 = r11.s64 + -32560;
	// stw r31,376(r29)
	PPC_STORE_U32(r29.u32 + 376, r31.u32);
	// bl 0x82239498
	ctx.lr = 0x82236218;
	sub_82239498(ctx, base);
	// addi r3,r29,340
	ctx.r3.s64 = r29.s64 + 340;
	// bl 0x822397f8
	ctx.lr = 0x82236220;
	sub_822397F8(ctx, base);
	// addi r3,r29,320
	ctx.r3.s64 = r29.s64 + 320;
	// bl 0x822397f8
	ctx.lr = 0x82236228;
	sub_822397F8(ctx, base);
	// addi r3,r29,288
	ctx.r3.s64 = r29.s64 + 288;
	// bl 0x822392b0
	ctx.lr = 0x82236230;
	sub_822392B0(ctx, base);
	// stw r31,260(r29)
	PPC_STORE_U32(r29.u32 + 260, r31.u32);
	// addi r3,r29,240
	ctx.r3.s64 = r29.s64 + 240;
	// bl 0x8223a200
	ctx.lr = 0x8223623C;
	sub_8223A200(ctx, base);
	// addi r3,r29,228
	ctx.r3.s64 = r29.s64 + 228;
	// bl 0x82238f00
	ctx.lr = 0x82236244;
	sub_82238F00(ctx, base);
	// addi r3,r29,208
	ctx.r3.s64 = r29.s64 + 208;
	// bl 0x822397f8
	ctx.lr = 0x8223624C;
	sub_822397F8(ctx, base);
	// addi r3,r29,192
	ctx.r3.s64 = r29.s64 + 192;
	// bl 0x822393b8
	ctx.lr = 0x82236254;
	sub_822393B8(ctx, base);
	// stw r31,184(r29)
	PPC_STORE_U32(r29.u32 + 184, r31.u32);
	// stw r31,176(r29)
	PPC_STORE_U32(r29.u32 + 176, r31.u32);
	// addi r3,r29,112
	ctx.r3.s64 = r29.s64 + 112;
	// stw r31,144(r29)
	PPC_STORE_U32(r29.u32 + 144, r31.u32);
	// bl 0x822395b8
	ctx.lr = 0x82236268;
	sub_822395B8(ctx, base);
	// addi r3,r29,80
	ctx.r3.s64 = r29.s64 + 80;
	// bl 0x82239868
	ctx.lr = 0x82236270;
	sub_82239868(ctx, base);
	// addi r3,r29,56
	ctx.r3.s64 = r29.s64 + 56;
	// bl 0x82239868
	ctx.lr = 0x82236278;
	sub_82239868(ctx, base);
	// addi r3,r29,32
	ctx.r3.s64 = r29.s64 + 32;
	// bl 0x82239868
	ctx.lr = 0x82236280;
	sub_82239868(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0430
	ctx.lr = 0x82236288;
	sub_824E0430(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82236290"))) PPC_WEAK_FUNC(sub_82236290);
PPC_FUNC_IMPL(__imp__sub_82236290) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,388(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82236298"))) PPC_WEAK_FUNC(sub_82236298);
PPC_FUNC_IMPL(__imp__sub_82236298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13316
	ctx.r3.s64 = r11.s64 + -13316;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822362A4"))) PPC_WEAK_FUNC(sub_822362A4);
PPC_FUNC_IMPL(__imp__sub_822362A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822362A8"))) PPC_WEAK_FUNC(sub_822362A8);
PPC_FUNC_IMPL(__imp__sub_822362A8) {
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
	ctx.lr = 0x822362B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822362F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82236300
	if (!cr6.eq) goto loc_82236300;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_82236300:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82236344
	if (cr6.eq) goto loc_82236344;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82723940
	ctx.lr = 0x82236340;
	sub_82723940(ctx, base);
	// b 0x822363b4
	goto loc_822363B4;
loc_82236344:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r4,80
	ctx.r4.s64 = 80;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r3,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r3.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r29
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822363B4:
	// lwz r11,456(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 456);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822363e0
	if (!cr6.eq) goto loc_822363E0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfs f1,548(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82238d68
	ctx.lr = 0x822363D0;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822363e4
	if (cr6.eq) goto loc_822363E4;
loc_822363E0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_822363E4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822363EC"))) PPC_WEAK_FUNC(sub_822363EC);
PPC_FUNC_IMPL(__imp__sub_822363EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822363F0"))) PPC_WEAK_FUNC(sub_822363F0);
PPC_FUNC_IMPL(__imp__sub_822363F0) {
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
	// bl 0x823d91ec
	ctx.lr = 0x822363F8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// vupkd3d128 v59,v61,4
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v61.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v59 = vTemp;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f1,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x15));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x45));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x51));
	// vmulfp128 v58,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v57,v62,v60
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// vmulfp128 v56,v61,v60
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82204cb8
	ctx.lr = 0x82236480;
	sub_82204CB8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82235e30
	ctx.lr = 0x8223648C;
	sub_82235E30(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82235ee0
	ctx.lr = 0x82236498;
	sub_82235EE0(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v54,r0,r27
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vaddfp128 v53,v55,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822362a8
	ctx.lr = 0x822364D0;
	sub_822362A8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822364D8"))) PPC_WEAK_FUNC(sub_822364D8);
PPC_FUNC_IMPL(__imp__sub_822364D8) {
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
	ctx.lr = 0x822364E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addis r31,r27,1
	r31.s64 = r27.s64 + 65536;
	// addi r10,r11,-31052
	ctx.r10.s64 = r11.s64 + -31052;
	// addi r31,r31,3152
	r31.s64 = r31.s64 + 3152;
	// li r29,5
	r29.s64 = 5;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// li r28,0
	r28.s64 = 0;
loc_82236504:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82236510;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82236538
	if (!cr6.eq) goto loc_82236538;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82236538
	if (cr6.eq) goto loc_82236538;
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
	ctx.lr = 0x82236538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82236538:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82236504
	if (!cr0.eq) goto loc_82236504;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82235fd8
	ctx.lr = 0x82236550;
	sub_82235FD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82236558"))) PPC_WEAK_FUNC(sub_82236558);
PPC_FUNC_IMPL(__imp__sub_82236558) {
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
	ctx.lr = 0x82236560;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r30,r11,1040
	r30.s64 = r11.s64 + 1040;
	// lwz r31,19472(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822365a0
	if (!cr6.gt) goto loc_822365A0;
loc_82236588:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238de0
	ctx.lr = 0x82236594;
	sub_82238DE0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bne 0x82236588
	if (!cr0.eq) goto loc_82236588;
loc_822365A0:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82189e80
	ctx.lr = 0x822365AC;
	sub_82189E80(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822365B4"))) PPC_WEAK_FUNC(sub_822365B4);
PPC_FUNC_IMPL(__imp__sub_822365B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822365B8"))) PPC_WEAK_FUNC(sub_822365B8);
PPC_FUNC_IMPL(__imp__sub_822365B8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x822365C0;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823db9d8
	ctx.lr = 0x822365C8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x824e0648
	ctx.lr = 0x822365DC;
	sub_824E0648(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-31100
	ctx.r10.s64 = r11.s64 + -31100;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stb r30,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r30.u8);
	// bl 0x8223d1e8
	ctx.lr = 0x822365FC;
	sub_8223D1E8(ctx, base);
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x8223cfc8
	ctx.lr = 0x82236604;
	sub_8223CFC8(ctx, base);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x8223d048
	ctx.lr = 0x8223660C;
	sub_8223D048(ctx, base);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x8223b4a8
	ctx.lr = 0x82236614;
	sub_8223B4A8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r5,r8,-32512
	ctx.r5.s64 = ctx.r8.s64 + -32512;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r10,r6,-32484
	ctx.r10.s64 = ctx.r6.s64 + -32484;
	// stfs f31,148(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stw r5,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r5.u32);
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r9,r4,-32540
	ctx.r9.s64 = ctx.r4.s64 + -32540;
	// stfs f31,160(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f30,164(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// stfs f30,168(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
	// stfs f31,172(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stw r10,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r10.u32);
	// stfs f31,180(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stw r9,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r9.u32);
	// stfs f31,188(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// bl 0x8223c3e8
	ctx.lr = 0x82236670;
	sub_8223C3E8(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x8223c378
	ctx.lr = 0x82236678;
	sub_8223C378(ctx, base);
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x82238ea8
	ctx.lr = 0x82236680;
	sub_82238EA8(ctx, base);
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// bl 0x8223a190
	ctx.lr = 0x82236688;
	sub_8223A190(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stfs f31,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r3,r31,288
	ctx.r3.s64 = r31.s64 + 288;
	// addi r4,r5,-31132
	ctx.r4.s64 = ctx.r5.s64 + -31132;
	// lfs f0,-31108(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31108);
	f0.f64 = double(temp.f32);
	// lfs f29,15004(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15004);
	f29.f64 = double(temp.f32);
	// lfs f28,14992(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14992);
	f28.f64 = double(temp.f32);
	// stw r4,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r4.u32);
	// stfs f0,268(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 268, temp.u32);
	// stfs f29,272(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
	// stfs f28,276(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
	// bl 0x82239228
	ctx.lr = 0x822366C4;
	sub_82239228(ctx, base);
	// addi r3,r31,320
	ctx.r3.s64 = r31.s64 + 320;
	// bl 0x8223acd0
	ctx.lr = 0x822366CC;
	sub_8223ACD0(ctx, base);
	// addi r3,r31,340
	ctx.r3.s64 = r31.s64 + 340;
	// bl 0x8223ad40
	ctx.lr = 0x822366D4;
	sub_8223AD40(ctx, base);
	// addi r3,r31,360
	ctx.r3.s64 = r31.s64 + 360;
	// bl 0x8223ac70
	ctx.lr = 0x822366DC;
	sub_8223AC70(ctx, base);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stfs f31,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// addi r10,r3,-32560
	ctx.r10.s64 = ctx.r3.s64 + -32560;
	// li r27,1
	r27.s64 = 1;
	// stw r10,376(r31)
	PPC_STORE_U32(r31.u32 + 376, ctx.r10.u32);
	// stfs f30,460(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 460, temp.u32);
	// stfs f30,464(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 464, temp.u32);
	// stw r29,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r29.u32);
	// lfs f13,-30704(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30704);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f30,468(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 468, temp.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,-30708(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30708);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stfs f13,476(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f12,480(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f0,-30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -30712);
	f0.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f0,488(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// lfs f13,12428(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stfs f0,496(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stw r28,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r28.u32);
	// lfs f12,-29232(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// stw r4,504(r31)
	PPC_STORE_U32(r31.u32 + 504, ctx.r4.u32);
	// stfs f31,484(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// stw r30,420(r31)
	PPC_STORE_U32(r31.u32 + 420, r30.u32);
	// stfs f31,492(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stw r30,424(r31)
	PPC_STORE_U32(r31.u32 + 424, r30.u32);
	// stw r30,428(r31)
	PPC_STORE_U32(r31.u32 + 428, r30.u32);
	// lfs f0,14884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r30,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r30.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r30,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r30,440(r31)
	PPC_STORE_U32(r31.u32 + 440, r30.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,444(r31)
	PPC_STORE_U32(r31.u32 + 444, r30.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r30,448(r31)
	PPC_STORE_U32(r31.u32 + 448, r30.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r30,452(r31)
	PPC_STORE_U32(r31.u32 + 452, r30.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stb r30,472(r31)
	PPC_STORE_U8(r31.u32 + 472, r30.u8);
	// lis r29,-32253
	r29.s64 = -2113732608;
	// stb r30,473(r31)
	PPC_STORE_U8(r31.u32 + 473, r30.u8);
	// lis r28,-32253
	r28.s64 = -2113732608;
	// stb r27,474(r31)
	PPC_STORE_U8(r31.u32 + 474, r27.u8);
	// lfs f11,-30716(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30716);
	ctx.f11.f64 = double(temp.f32);
	// stb r30,500(r31)
	PPC_STORE_U8(r31.u32 + 500, r30.u8);
	// lfs f10,-30720(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30720);
	ctx.f10.f64 = double(temp.f32);
	// stb r27,508(r31)
	PPC_STORE_U8(r31.u32 + 508, r27.u8);
	// stfs f13,512(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stfs f12,516(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stfs f0,520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stfs f31,524(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 524, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f31,528(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stb r30,544(r31)
	PPC_STORE_U8(r31.u32 + 544, r30.u8);
	// stfs f13,532(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// lis r26,-32253
	r26.s64 = -2113732608;
	// lfs f13,11368(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// stfs f13,584(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// lis r25,-32253
	r25.s64 = -2113732608;
	// lfs f13,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f9,-12080(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12080);
	ctx.f9.f64 = double(temp.f32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lfs f8,14184(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14184);
	ctx.f8.f64 = double(temp.f32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f7,-26872(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26872);
	ctx.f7.f64 = double(temp.f32);
	// stfs f13,588(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// lfs f13,-30724(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -30724);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,536(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// stfs f11,548(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// stfs f31,540(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 540, temp.u32);
	// stfs f0,552(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 552, temp.u32);
	// stfs f10,556(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 556, temp.u32);
	// stfs f9,560(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 560, temp.u32);
	// stfs f8,576(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// stfs f7,580(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stfs f29,592(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// stfs f29,596(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// lfs f12,-30728(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -30728);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-30732(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -30732);
	ctx.f11.f64 = double(temp.f32);
	// stfs f31,620(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 620, temp.u32);
	// stfs f13,608(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 608, temp.u32);
	// stfs f12,612(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 612, temp.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stfs f11,616(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 616, temp.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stfs f13,624(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 624, temp.u32);
	// lis r29,-32253
	r29.s64 = -2113732608;
	// stfs f12,628(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 628, temp.u32);
	// lis r28,-32253
	r28.s64 = -2113732608;
	// stfs f11,632(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 632, temp.u32);
	// lis r24,-32253
	r24.s64 = -2113732608;
	// stfs f31,636(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 636, temp.u32);
	// lis r23,-32253
	r23.s64 = -2113732608;
	// stfs f13,640(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 640, temp.u32);
	// lis r22,-32253
	r22.s64 = -2113732608;
	// stfs f12,644(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// lis r21,-32253
	r21.s64 = -2113732608;
	// stfs f11,648(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// lis r20,-32253
	r20.s64 = -2113732608;
	// stfs f31,652(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 652, temp.u32);
	// lis r19,-32253
	r19.s64 = -2113732608;
	// stfs f13,656(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 656, temp.u32);
	// lis r18,-32253
	r18.s64 = -2113732608;
	// stfs f12,660(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 660, temp.u32);
	// lis r17,-32253
	r17.s64 = -2113732608;
	// stfs f11,664(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// lis r16,-32253
	r16.s64 = -2113732608;
	// stfs f31,668(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 668, temp.u32);
	// stfs f13,672(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// stfs f12,676(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 676, temp.u32);
	// stfs f11,680(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 680, temp.u32);
	// stfs f31,684(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 684, temp.u32);
	// lfs f13,-30736(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -30736);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,692(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 692, temp.u32);
	// lfs f12,-30740(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30740);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,696(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 696, temp.u32);
	// stfs f30,688(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 688, temp.u32);
	// stfs f31,700(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 700, temp.u32);
	// stfs f31,704(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// stfs f30,708(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 708, temp.u32);
	// stfs f30,712(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// stfs f31,716(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 716, temp.u32);
	// lfs f13,-30744(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30744);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30764(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -30764);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,720(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// stfs f12,724(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 724, temp.u32);
	// stfs f31,728(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
	// stfs f31,732(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
	// lfs f13,-30768(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -30768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30752(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -30752);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,740(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// stfs f12,744(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// stfs f31,736(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 736, temp.u32);
	// stfs f31,748(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 748, temp.u32);
	// stfs f13,756(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 756, temp.u32);
	// stfs f12,760(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 760, temp.u32);
	// stfs f31,752(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 752, temp.u32);
	// stfs f31,764(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 764, temp.u32);
	// stfs f12,776(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 776, temp.u32);
	// stfs f13,772(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 772, temp.u32);
	// stfs f31,768(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// stfs f31,780(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 780, temp.u32);
	// lfs f12,-30760(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30760);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-30748(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -30748);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,784(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 784, temp.u32);
	// stfs f11,788(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 788, temp.u32);
	// stfs f31,792(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// stfs f31,796(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 796, temp.u32);
	// lfs f13,-30756(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -30756);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,800(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 800, temp.u32);
	// stfs f13,804(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 804, temp.u32);
	// stfs f13,808(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 808, temp.u32);
	// stfs f31,812(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 812, temp.u32);
	// stfs f0,816(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 816, temp.u32);
	// stfs f0,820(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 820, temp.u32);
	// stfs f0,824(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 824, temp.u32);
	// lfs f0,-30772(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -30772);
	f0.f64 = double(temp.f32);
	// stfs f31,828(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 828, temp.u32);
	// stfs f0,836(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 836, temp.u32);
	// lfs f13,-30776(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -30776);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-30780(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -30780);
	f0.f64 = double(temp.f32);
	// stfs f31,832(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 832, temp.u32);
	// stfs f13,840(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 840, temp.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stfs f31,844(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 844, temp.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f0,848(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 848, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,-30784(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -30784);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f13,852(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 852, temp.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stfs f31,860(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,-30788(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -30788);
	ctx.f12.f64 = double(temp.f32);
	// addi r29,r31,1040
	r29.s64 = r31.s64 + 1040;
	// stfs f12,856(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 856, temp.u32);
	// mr r28,r27
	r28.u64 = r27.u64;
	// lfs f0,-30792(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -30792);
	f0.f64 = double(temp.f32);
	// stfs f0,864(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// lfs f13,-30796(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -30796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,868(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// stfs f31,876(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 876, temp.u32);
	// lfs f12,-30800(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + -30800);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,872(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
	// lfs f0,-30804(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + -30804);
	f0.f64 = double(temp.f32);
	// stfs f0,880(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 880, temp.u32);
	// lfs f13,-30808(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + -30808);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,884(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 884, temp.u32);
	// lfs f12,-30812(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + -30812);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,888(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 888, temp.u32);
	// stfs f31,892(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 892, temp.u32);
	// lfs f0,-30820(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + -30820);
	f0.f64 = double(temp.f32);
	// lfs f13,-30816(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + -30816);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,900(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 900, temp.u32);
	// stfs f0,904(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 904, temp.u32);
	// stfs f13,896(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 896, temp.u32);
	// stfs f31,908(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 908, temp.u32);
	// stfs f30,912(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 912, temp.u32);
	// stfs f31,916(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 916, temp.u32);
	// stfs f30,920(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 920, temp.u32);
	// stfs f31,924(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 924, temp.u32);
	// stfs f31,928(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 928, temp.u32);
	// stfs f31,932(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 932, temp.u32);
	// stfs f31,936(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 936, temp.u32);
	// stfs f31,940(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 940, temp.u32);
	// lfs f0,31308(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lfs f13,-17424(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -17424);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,948(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 948, temp.u32);
	// stfs f0,952(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 952, temp.u32);
	// stfs f13,944(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// stfs f31,956(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 956, temp.u32);
	// stfs f0,960(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f0,964(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// stfs f13,968(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 968, temp.u32);
	// stfs f31,972(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stfs f31,976(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stfs f31,980(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f31,984(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// stfs f31,988(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 988, temp.u32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stfs f0,1000(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1000, temp.u32);
	// stfs f30,996(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// stw r27,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r27.u32);
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stw r30,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r30.u32);
	// lfs f13,-32032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,1032(r31)
	PPC_STORE_U8(r31.u32 + 1032, r30.u8);
	// lfs f12,31020(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31020);
	ctx.f12.f64 = double(temp.f32);
	// stb r27,1033(r31)
	PPC_STORE_U8(r31.u32 + 1033, r27.u8);
	// stfs f28,1008(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
	// stfs f0,1012(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1012, temp.u32);
	// stfs f13,1016(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1016, temp.u32);
	// stfs f12,1020(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1020, temp.u32);
loc_82236ABC:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,192
	ctx.r5.s64 = 192;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,96
	ctx.r4.s64 = 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821305f0
	ctx.lr = 0x82236AD4;
	sub_821305F0(ctx, base);
	// stw r30,18432(r29)
	PPC_STORE_U32(r29.u32 + 18432, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,18448
	r29.s64 = r29.s64 + 18448;
	// bge 0x82236abc
	if (!cr0.lt) goto loc_82236ABC;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// mr r28,r27
	r28.u64 = r27.u64;
	// addi r29,r29,-27600
	r29.s64 = r29.s64 + -27600;
loc_82236AF0:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,192
	ctx.r5.s64 = 192;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,80
	ctx.r4.s64 = 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821305f0
	ctx.lr = 0x82236B08;
	sub_821305F0(ctx, base);
	// stw r30,15360(r29)
	PPC_STORE_U32(r29.u32 + 15360, r30.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,15376
	r29.s64 = r29.s64 + 15376;
	// bge 0x82236af0
	if (!cr0.lt) goto loc_82236AF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r11,-30832
	ctx.r7.s64 = r11.s64 + -30832;
	// addi r6,r10,-30848
	ctx.r6.s64 = ctx.r10.s64 + -30848;
	// addi r5,r9,-30868
	ctx.r5.s64 = ctx.r9.s64 + -30868;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r3,r8,-30876
	ctx.r3.s64 = ctx.r8.s64 + -30876;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// bl 0x82723808
	ctx.lr = 0x82236B48;
	sub_82723808(ctx, base);
	// stw r3,424(r31)
	PPC_STORE_U32(r31.u32 + 424, ctx.r3.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r3,r4,-30888
	ctx.r3.s64 = ctx.r4.s64 + -30888;
	// bl 0x82723808
	ctx.lr = 0x82236B58;
	sub_82723808(ctx, base);
	// stw r3,428(r31)
	PPC_STORE_U32(r31.u32 + 428, ctx.r3.u32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r3,r3,-30904
	ctx.r3.s64 = ctx.r3.s64 + -30904;
	// bl 0x82723808
	ctx.lr = 0x82236B68;
	sub_82723808(ctx, base);
	// stw r3,420(r31)
	PPC_STORE_U32(r31.u32 + 420, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r28,r11,10372
	r28.s64 = r11.s64 + 10372;
	// addi r6,r10,-30920
	ctx.r6.s64 = ctx.r10.s64 + -30920;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,-27856(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// bl 0x823dc018
	ctx.lr = 0x82236B90;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82723808
	ctx.lr = 0x82236B98;
	sub_82723808(ctx, base);
	// stw r3,432(r31)
	PPC_STORE_U32(r31.u32 + 432, ctx.r3.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r5,-27856(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r6,r9,-30936
	ctx.r6.s64 = ctx.r9.s64 + -30936;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82236BB4;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82723808
	ctx.lr = 0x82236BBC;
	sub_82723808(ctx, base);
	// stw r3,436(r31)
	PPC_STORE_U32(r31.u32 + 436, ctx.r3.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r5,-27856(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r6,r8,-30952
	ctx.r6.s64 = ctx.r8.s64 + -30952;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82236BD8;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82723808
	ctx.lr = 0x82236BE0;
	sub_82723808(ctx, base);
	// stw r3,440(r31)
	PPC_STORE_U32(r31.u32 + 440, ctx.r3.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lwz r5,-27856(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r6,r7,-30968
	ctx.r6.s64 = ctx.r7.s64 + -30968;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82236BFC;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82723808
	ctx.lr = 0x82236C04;
	sub_82723808(ctx, base);
	// stw r3,444(r31)
	PPC_STORE_U32(r31.u32 + 444, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lwz r5,-27856(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + -27856);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r6,r6,-30984
	ctx.r6.s64 = ctx.r6.s64 + -30984;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82236C20;
	sub_823DC018(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82723808
	ctx.lr = 0x82236C28;
	sub_82723808(ctx, base);
	// lis r11,16256
	r11.s64 = 1065353216;
	// stw r3,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r3.u32);
	// addi r10,r31,564
	ctx.r10.s64 = r31.s64 + 564;
	// stw r11,564(r31)
	PPC_STORE_U32(r31.u32 + 564, r11.u32);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// stw r11,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r11.u32);
	// addi r29,r31,408
	r29.s64 = r31.s64 + 408;
	// stw r11,572(r31)
	PPC_STORE_U32(r31.u32 + 572, r11.u32);
	// stb r27,1034(r31)
	PPC_STORE_U8(r31.u32 + 1034, r27.u8);
	// li r27,3
	r27.s64 = 3;
loc_82236C50:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82236c68
	if (!cr6.eq) goto loc_82236C68;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// b 0x82236c70
	goto loc_82236C70;
loc_82236C68:
	// bl 0x82723808
	ctx.lr = 0x82236C6C;
	sub_82723808(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82236C70:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82236c50
	if (!cr0.eq) goto loc_82236C50;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-30992
	ctx.r4.s64 = r11.s64 + -30992;
	// bl 0x824e06e0
	ctx.lr = 0x82236C90;
	sub_824E06E0(ctx, base);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x82236CA0;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0558
	ctx.lr = 0x82236CA8;
	sub_824E0558(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x82236CB4;
	sub_82305870(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba24
	ctx.lr = 0x82236CC4;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82236CC8"))) PPC_WEAK_FUNC(sub_82236CC8);
PPC_FUNC_IMPL(__imp__sub_82236CC8) {
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
	// bl 0x82235fd8
	ctx.lr = 0x82236CE8;
	sub_82235FD8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236d00
	if (cr6.eq) goto loc_82236D00;
	// bl 0x82130588
	ctx.lr = 0x82236CFC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82236D00:
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

__attribute__((alias("__imp__sub_82236D18"))) PPC_WEAK_FUNC(sub_82236D18);
PPC_FUNC_IMPL(__imp__sub_82236D18) {
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
	// bl 0x823d91c0
	ctx.lr = 0x82236D20;
	// stfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stb r10,351(r1)
	PPC_STORE_U8(ctx.r1.u32 + 351, ctx.r10.u8);
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stb r9,343(r1)
	PPC_STORE_U8(ctx.r1.u32 + 343, ctx.r9.u8);
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// lwz r11,388(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 388);
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// mr r15,r7
	r15.u64 = ctx.r7.u64;
	// add r21,r10,r11
	r21.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r20,r10,r11
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplw cr6,r20,r21
	cr6.compare<uint32_t>(r20.u32, r21.u32, xer);
	// beq cr6,0x82237038
	if (cr6.eq) goto loc_82237038;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r22,80
	r22.s64 = 80;
	// ori r25,r9,37936
	r25.u64 = ctx.r9.u64 | 37936;
	// lfs f30,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r23,0
	r23.s64 = 0;
	// lfs f31,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f31.f64 = double(temp.f32);
	// li r14,96
	r14.s64 = 96;
	// li r18,48
	r18.s64 = 48;
	// lis r24,-32119
	r24.s64 = -2104950784;
loc_82236D90:
	// lwz r31,8(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236dd4
	if (cr6.eq) goto loc_82236DD4;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236dd4
	if (cr6.eq) goto loc_82236DD4;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8223702c
	if (!cr6.eq) goto loc_8223702C;
	// lbz r11,1034(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1034);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
	// lbz r11,38(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223702c
	if (!cr6.eq) goto loc_8223702C;
loc_82236DD4:
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82236e18
	if (cr6.eq) goto loc_82236E18;
	// bl 0x822a91e0
	ctx.lr = 0x82236DE4;
	sub_822A91E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236e04
	if (cr6.eq) goto loc_82236E04;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x82224ac8
	ctx.lr = 0x82236DF8;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
loc_82236E04:
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x822a9260
	ctx.lr = 0x82236E0C;
	sub_822A9260(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223702c
	if (!cr6.eq) goto loc_8223702C;
loc_82236E18:
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,72
	r26.s64 = 72;
	// lbzx r11,r26,r27
	r11.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82236f64
	if (!cr6.eq) goto loc_82236F64;
	// lwz r11,-17936(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -17936);
	// mulli r11,r11,15376
	r11.s64 = r11.s64 * 15376;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// add r11,r11,r25
	r11.u64 = r11.u64 + r25.u64;
	// lwz r10,15360(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 15360);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r8,15360(r11)
	PPC_STORE_U32(r11.u32 + 15360, ctx.r8.u32);
	// rlwinm r10,r7,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// lbz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// lbz r5,38(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 38);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
	// lvx128 v63,r31,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 124);
	// stb r4,32(r11)
	PPC_STORE_U8(r11.u32 + 32, ctx.r4.u8);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r3,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r3.u32);
	// stb r23,64(r11)
	PPC_STORE_U8(r11.u32 + 64, r23.u8);
	// lbz r10,126(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 126);
	// stb r10,65(r11)
	PPC_STORE_U8(r11.u32 + 65, ctx.r10.u8);
	// lwz r30,120(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82236f00
	if (cr6.eq) goto loc_82236F00;
	// lwz r10,116(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lvx128 v62,r30,r14
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,112(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 112);
	// stb r9,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r9.u8);
	// bl 0x822a8108
	ctx.lr = 0x82236EBC;
	sub_822A8108(ctx, base);
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v61,r3,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236f64
	if (cr6.eq) goto loc_82236F64;
	// lbzx r10,r26,r27
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82236ef0
	if (cr6.eq) goto loc_82236EF0;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// lvx128 v60,r11,r18
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82236f64
	goto loc_82236F64;
loc_82236EF0:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// lvx128 v60,r11,r18
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82236f64
	goto loc_82236F64;
loc_82236F00:
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// clrlwi r3,r9,24
	ctx.r3.u64 = ctx.r9.u32 & 0xFF;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rlwinm r6,r9,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// stfs f30,60(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 60, temp.u32);
	// rlwinm r5,r9,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f4,f7,f31
	ctx.f4.f64 = double(float(ctx.f7.f64 * f31.f64));
	// stfs f4,52(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 52, temp.u32);
	// fmuls f5,f8,f31
	ctx.f5.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f5,56(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 56, temp.u32);
	// fmuls f3,f6,f31
	ctx.f3.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f3,48(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 48, temp.u32);
loc_82236F64:
	// lbz r10,343(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 343);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
	// lbz r11,125(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 125);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236f88
	if (cr6.eq) goto loc_82236F88;
	// lbz r10,351(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 351);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
loc_82236F88:
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236fa0
	if (cr6.eq) goto loc_82236FA0;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
loc_82236FA0:
	// lbz r11,153(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82236ff8
	if (!cr6.eq) goto loc_82236FF8;
	// lbz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82236fcc
	if (!cr6.eq) goto loc_82236FCC;
	// lbz r11,38(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 38);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// beq cr6,0x82236ff8
	if (cr6.eq) goto loc_82236FF8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236ff8
	if (cr6.eq) goto loc_82236FF8;
loc_82236FCC:
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// beq cr6,0x82236ff8
	if (cr6.eq) goto loc_82236FF8;
	// lbz r11,180(r19)
	r11.u64 = PPC_LOAD_U8(r19.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82236ff8
	if (cr6.eq) goto loc_82236FF8;
	// lwz r11,176(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82236ff8
	if (!cr6.eq) goto loc_82236FF8;
	// lbz r11,124(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223702c
	if (cr6.eq) goto loc_8223702C;
loc_82236FF8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82235148
	ctx.lr = 0x82237004;
	sub_82235148(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r9,r15
	ctx.r9.u64 = r15.u64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223702C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223702C:
	// lwz r20,0(r20)
	r20.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplw cr6,r20,r21
	cr6.compare<uint32_t>(r20.u32, r21.u32, xer);
	// bne cr6,0x82236d90
	if (!cr6.eq) goto loc_82236D90;
loc_82237038:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-168(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82237048"))) PPC_WEAK_FUNC(sub_82237048);
PPC_FUNC_IMPL(__imp__sub_82237048) {
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
	ctx.lr = 0x82237050;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822365b8
	ctx.lr = 0x8223705C;
	sub_822365B8(ctx, base);
	// addis r8,r31,1
	ctx.r8.s64 = r31.s64 + 65536;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r8,3172
	ctx.r8.s64 = ctx.r8.s64 + 3172;
	// addi r7,r11,-31052
	ctx.r7.s64 = r11.s64 + -31052;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lfs f13,-30580(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30580);
	ctx.f13.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// stfs f13,4(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x82237098;
	sub_823058F8(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-30604
	ctx.r4.s64 = ctx.r6.s64 + -30604;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822370BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// ori r7,r9,3152
	ctx.r7.u64 = ctx.r9.u64 | 3152;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-30628
	ctx.r4.s64 = ctx.r8.s64 + -30628;
	// stwx r3,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822370E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// ori r8,r10,3156
	ctx.r8.u64 = ctx.r10.u64 | 3156;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-30652
	ctx.r4.s64 = ctx.r9.s64 + -30652;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82237114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// ori r11,r5,3160
	r11.u64 = ctx.r5.u64 | 3160;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-30676
	ctx.r4.s64 = ctx.r4.s64 + -30676;
	// stwx r3,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82237140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// ori r6,r8,3164
	ctx.r6.u64 = ctx.r8.u64 | 3164;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-30700
	ctx.r4.s64 = ctx.r7.s64 + -30700;
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223716C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r8,r9,3168
	ctx.r8.u64 = ctx.r9.u64 | 3168;
	// stwx r3,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r3.u32);
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x82237184;
	sub_82305870(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82237190"))) PPC_WEAK_FUNC(sub_82237190);
PPC_FUNC_IMPL(__imp__sub_82237190) {
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
	// bl 0x822364d8
	ctx.lr = 0x822371B0;
	sub_822364D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822371c8
	if (cr6.eq) goto loc_822371C8;
	// bl 0x82130588
	ctx.lr = 0x822371C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822371C8:
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

__attribute__((alias("__imp__sub_822371E0"))) PPC_WEAK_FUNC(sub_822371E0);
PPC_FUNC_IMPL(__imp__sub_822371E0) {
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
	ctx.lr = 0x822371E8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lwz r8,19472(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 19472);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82237384
	if (cr6.eq) goto loc_82237384;
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,10
	ctx.r3.s64 = 10;
	// addi r11,r11,17172
	r11.s64 = r11.s64 + 17172;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stw r8,412(r10)
	PPC_STORE_U32(ctx.r10.u32 + 412, ctx.r8.u32);
	// bl 0x82189e80
	ctx.lr = 0x82237234;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82189e80
	ctx.lr = 0x82237240;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x8223724C;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82189e80
	ctx.lr = 0x82237258;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82189e80
	ctx.lr = 0x82237264;
	sub_82189E80(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82189e80
	ctx.lr = 0x82237270;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,26
	ctx.r3.s64 = 26;
	// bl 0x82189e80
	ctx.lr = 0x8223727C;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,27
	ctx.r3.s64 = 27;
	// bl 0x82189e80
	ctx.lr = 0x82237288;
	sub_82189E80(ctx, base);
	// lwz r7,432(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82237378
	if (cr6.eq) goto loc_82237378;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r29,r10,-31280
	r29.s64 = ctx.r10.s64 + -31280;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,640
	ctx.r6.s64 = r31.s64 + 640;
	// lwz r30,48(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,656(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// bl 0x82723940
	ctx.lr = 0x822372D8;
	sub_82723940(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,660(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 660);
	// li r10,1
	ctx.r10.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,608
	ctx.r6.s64 = r31.s64 + 608;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82237300;
	sub_82723940(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,664(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 664);
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,624
	ctx.r6.s64 = r31.s64 + 624;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82237328;
	sub_82723940(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,668(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 668);
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,672
	ctx.r6.s64 = r31.s64 + 672;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82237350;
	sub_82723940(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,672(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r31,656
	ctx.r6.s64 = r31.s64 + 656;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82237378;
	sub_82723940(ctx, base);
loc_82237378:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82236558
	ctx.lr = 0x82237384;
	sub_82236558(ctx, base);
loc_82237384:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82237390"))) PPC_WEAK_FUNC(sub_82237390);
PPC_FUNC_IMPL(__imp__sub_82237390) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18780
	ctx.r4.s64 = ctx.r10.s64 + -18780;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x822373B0;
	sub_821F9FB8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r9,-18692
	ctx.r4.s64 = ctx.r9.s64 + -18692;
	// bl 0x82722990
	ctx.lr = 0x822373C0;
	sub_82722990(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822373D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef808
	ctx.lr = 0x822373D8;
	sub_825EF808(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822373E8"))) PPC_WEAK_FUNC(sub_822373E8);
PPC_FUNC_IMPL(__imp__sub_822373E8) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x822373F0;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// li r23,0
	r23.s64 = 0;
	// stw r29,456(r31)
	PPC_STORE_U32(r31.u32 + 456, r29.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-17936(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// ori r7,r9,53296
	ctx.r7.u64 = ctx.r9.u64 | 53296;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// cntlzw r5,r29
	ctx.r5.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// stw r23,19472(r6)
	PPC_STORE_U32(ctx.r6.u32 + 19472, r23.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,-17936(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// mulli r11,r11,15376
	r11.s64 = r11.s64 * 15376;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r27,r5,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stwx r23,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, r23.u32);
	// lwz r28,-10236(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r3,44(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82237470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r3,696(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + 696);
	// bl 0x82240270
	ctx.lr = 0x8223747C;
	sub_82240270(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r30,r11,-31280
	r30.s64 = r11.s64 + -31280;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,336
	ctx.r6.s64 = ctx.r1.s64 + 336;
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// lvx128 v61,r30,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,368
	r11.s64 = ctx.r1.s64 + 368;
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r30,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r24,r1,336
	r24.s64 = ctx.r1.s64 + 336;
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// lwz r8,692(r21)
	ctx.r8.u64 = PPC_LOAD_U32(r21.u32 + 692);
	// lbz r28,608(r8)
	r28.u64 = PPC_LOAD_U8(ctx.r8.u32 + 608);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821f9fb8
	ctx.lr = 0x822374DC;
	sub_821F9FB8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// lwz r5,696(r21)
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + 696);
	// stw r5,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// bl 0x8217c568
	ctx.lr = 0x822374F8;
	sub_8217C568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r26,384
	ctx.r5.s64 = r26.s64 + 384;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8215e000
	ctx.lr = 0x82237508;
	sub_8215E000(ctx, base);
	// addi r4,r29,-1
	ctx.r4.s64 = r29.s64 + -1;
	// stb r22,297(r1)
	PPC_STORE_U8(ctx.r1.u32 + 297, r22.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// stw r23,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r23.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,296(r1)
	PPC_STORE_U8(ctx.r1.u32 + 296, ctx.r9.u8);
	// bl 0x82701bd8
	ctx.lr = 0x8223752C;
	sub_82701BD8(ctx, base);
	// stw r3,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82701bd8
	ctx.lr = 0x82237538;
	sub_82701BD8(ctx, base);
	// lwz r8,0(r13)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// stw r3,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lwz r11,-7900(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -7900);
	// li r6,72
	ctx.r6.s64 = 72;
	// stb r27,312(r1)
	PPC_STORE_U8(ctx.r1.u32 + 312, r27.u8);
	// li r22,1
	r22.s64 = 1;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbzx r5,r6,r8
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + ctx.r8.u32);
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// stw r29,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r29.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stb r28,324(r1)
	PPC_STORE_U8(ctx.r1.u32 + 324, r28.u8);
	// stw r4,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r4.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x82237590
	if (cr6.eq) goto loc_82237590;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822375ac
	if (!cr6.gt) goto loc_822375AC;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x822375a0
	goto loc_822375A0;
loc_82237590:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822375ac
	if (!cr6.gt) goto loc_822375AC;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_822375A0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r22
	r11.u64 = r22.u64;
	// bne cr6,0x822375b0
	if (!cr6.eq) goto loc_822375B0;
loc_822375AC:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_822375B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822375cc
	if (cr6.eq) goto loc_822375CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822375C4;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822375C8;
	sub_822A8108(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
loc_822375CC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,48
	ctx.r8.s64 = 48;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f0,-30576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30576);
	f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r24,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v1,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82238d28
	ctx.lr = 0x82237610;
	sub_82238D28(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x8223761C;
	sub_823DCDD8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r3,148(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lfs f0,26468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 26468);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 - ctx.f13.f64));
	// bl 0x82240250
	ctx.lr = 0x82237638;
	sub_82240250(ctx, base);
	// clrlwi r5,r27,24
	ctx.r5.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8223765c
	if (cr6.eq) goto loc_8223765C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82238f88
	ctx.lr = 0x8223764C;
	sub_82238F88(ctx, base);
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// b 0x82237674
	goto loc_82237674;
loc_8223765C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82237674:
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f1,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// lvx128 v62,r30,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r30,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82214d90
	ctx.lr = 0x822376BC;
	sub_82214D90(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lbz r9,-6144(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + -6144);
	// lfs f29,7444(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f30,-332(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -332);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82237700
	if (cr6.eq) goto loc_82237700;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54609
	ctx.r9.u64 = ctx.r10.u64 | 54609;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82237700
	if (cr6.eq) goto loc_82237700;
	// stfs f30,292(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// b 0x8223774c
	goto loc_8223774C;
loc_82237700:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8223771c
	if (!cr6.eq) goto loc_8223771C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x82620130
	ctx.lr = 0x82237714;
	sub_82620130(ctx, base);
	// stfs f1,292(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// b 0x8223774c
	goto loc_8223774C;
loc_8223771C:
	// lfs f0,116(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 116);
	f0.f64 = double(temp.f32);
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// lfs f13,556(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 556);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f11,560(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 560);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,141
	r11.s64 = r11.s64 + 141;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f10,r10,r31
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fadds f8,f9,f29
	ctx.f8.f64 = double(float(ctx.f9.f64 + f29.f64));
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// stfs f7,292(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
loc_8223774C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,116(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,556(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 556);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 456);
	// lfs f11,560(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 560);
	ctx.f11.f64 = double(temp.f32);
	// mr r30,r23
	r30.u64 = r23.u64;
	// addi r9,r11,141
	ctx.r9.s64 = r11.s64 + 141;
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// fmadds f10,f13,f0,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// lfsx f9,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fadds f7,f8,f29
	ctx.f7.f64 = double(float(ctx.f8.f64 + f29.f64));
	// fmuls f6,f7,f30
	ctx.f6.f64 = double(float(ctx.f7.f64 * f30.f64));
	// fmuls f5,f6,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f9.f64));
	// stfs f5,288(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
loc_8223778C:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82236d18
	ctx.lr = 0x822377B0;
	sub_82236D18(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,7
	cr6.compare<int32_t>(r30.s32, 7, xer);
	// blt cr6,0x8223778c
	if (cr6.lt) goto loc_8223778C;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822378d4
	if (cr6.eq) goto loc_822378D4;
	// stw r22,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r22.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x82238260
	ctx.lr = 0x822377D8;
	sub_82238260(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r30,r23
	r30.u64 = r23.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822377F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x822378cc
	if (!cr6.gt) goto loc_822378CC;
	// addi r28,r31,228
	r28.s64 = r31.s64 + 228;
	// li r25,5
	r25.s64 = 5;
	// li r27,3
	r27.s64 = 3;
loc_82237808:
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82237828
	if (cr6.eq) goto loc_82237828;
	// addi r10,r29,-1
	ctx.r10.s64 = r29.s64 + -1;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// beq cr6,0x82237858
	if (cr6.eq) goto loc_82237858;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223783c
	if (!cr6.eq) goto loc_8223783C;
loc_82237828:
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x8223783c
	if (!cr6.eq) goto loc_8223783C;
	// stb r25,438(r1)
	PPC_STORE_U8(ctx.r1.u32 + 438, r25.u8);
	// b 0x8223785c
	goto loc_8223785C;
loc_8223783C:
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// blt cr6,0x82237858
	if (cr6.lt) goto loc_82237858;
	// beq cr6,0x82237850
	if (cr6.eq) goto loc_82237850;
	// stb r27,438(r1)
	PPC_STORE_U8(ctx.r1.u32 + 438, r27.u8);
	// b 0x8223785c
	goto loc_8223785C;
loc_82237850:
	// stb r22,438(r1)
	PPC_STORE_U8(ctx.r1.u32 + 438, r22.u8);
	// b 0x8223785c
	goto loc_8223785C;
loc_82237858:
	// stb r23,438(r1)
	PPC_STORE_U8(ctx.r1.u32 + 438, r23.u8);
loc_8223785C:
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,544
	ctx.r3.s64 = ctx.r1.s64 + 544;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223787C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r1,480
	ctx.r5.s64 = ctx.r1.s64 + 480;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r7,r1,400
	ctx.r7.s64 = ctx.r1.s64 + 400;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822378C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82237808
	if (cr6.lt) goto loc_82237808;
loc_822378CC:
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x822378e8
	ctx.lr = 0x822378D4;
	sub_822378E8(ctx, base);
loc_822378D4:
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_822378E8"))) PPC_WEAK_FUNC(sub_822378E8);
PPC_FUNC_IMPL(__imp__sub_822378E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-30248
	ctx.r10.s64 = r11.s64 + -30248;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822378F8"))) PPC_WEAK_FUNC(sub_822378F8);
PPC_FUNC_IMPL(__imp__sub_822378F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,120(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// stb r4,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, ctx.r4.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r4,466(r11)
	PPC_STORE_U8(r11.u32 + 466, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237910"))) PPC_WEAK_FUNC(sub_82237910);
PPC_FUNC_IMPL(__imp__sub_82237910) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223791C"))) PPC_WEAK_FUNC(sub_8223791C);
PPC_FUNC_IMPL(__imp__sub_8223791C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237920"))) PPC_WEAK_FUNC(sub_82237920);
PPC_FUNC_IMPL(__imp__sub_82237920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_82237938:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lhz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// blt cr6,0x82237938
	if (cr6.lt) goto loc_82237938;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237974"))) PPC_WEAK_FUNC(sub_82237974);
PPC_FUNC_IMPL(__imp__sub_82237974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237978"))) PPC_WEAK_FUNC(sub_82237978);
PPC_FUNC_IMPL(__imp__sub_82237978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// cmplwi cr6,r4,14
	cr6.compare<uint32_t>(ctx.r4.u32, 14, xer);
	// bgt cr6,0x82237a8c
	if (cr6.gt) goto loc_82237A8C;
	// lis r12,-32221
	r12.s64 = -2111635456;
	// addi r12,r12,31148
	r12.s64 = r12.s64 + 31148;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_822379E8;
	case 1:
		goto loc_82237A44;
	case 2:
		goto loc_82237A7C;
	case 3:
		goto loc_82237A3C;
	case 4:
		goto loc_82237A3C;
	case 5:
		goto loc_82237A6C;
	case 6:
		goto loc_82237A6C;
	case 7:
		goto loc_82237A6C;
	case 8:
		goto loc_82237A6C;
	case 9:
		goto loc_82237A6C;
	case 10:
		goto loc_82237A3C;
	case 11:
		goto loc_82237A6C;
	case 12:
		goto loc_82237A84;
	case 13:
		goto loc_82237A3C;
	case 14:
		goto loc_82237A3C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,31208(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31208);
	// lwz r17,31300(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31300);
	// lwz r17,31356(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31356);
	// lwz r17,31292(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31292);
	// lwz r17,31292(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31292);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31292(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31292);
	// lwz r17,31340(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31340);
	// lwz r17,31364(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31364);
	// lwz r17,31292(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31292);
	// lwz r17,31292(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + 31292);
loc_822379E8:
	// clrlwi r10,r5,31
	ctx.r10.u64 = ctx.r5.u32 & 0x1;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a7c
	if (!cr6.eq) goto loc_82237A7C;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a3c
	if (!cr6.eq) goto loc_82237A3C;
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a3c
	if (!cr6.eq) goto loc_82237A3C;
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a3c
	if (!cr6.eq) goto loc_82237A3C;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a3c
	if (!cr6.eq) goto loc_82237A3C;
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82237a3c
	if (!cr6.eq) goto loc_82237A3C;
	// li r31,3
	r31.s64 = 3;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A3C:
	// li r31,4
	r31.s64 = 4;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A44:
	// rlwinm r10,r5,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a74
	if (!cr6.eq) goto loc_82237A74;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82237a74
	if (cr6.eq) goto loc_82237A74;
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82237a6c
	if (!cr6.eq) goto loc_82237A6C;
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
loc_82237A6C:
	// li r31,2
	r31.s64 = 2;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A74:
	// li r31,6
	r31.s64 = 6;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A7C:
	// li r31,5
	r31.s64 = 5;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A84:
	// li r31,0
	r31.s64 = 0;
	// b 0x82237a98
	goto loc_82237A98;
loc_82237A8C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-30240
	ctx.r3.s64 = r11.s64 + -30240;
	// bl 0x821bd618
	ctx.lr = 0x82237A98;
	sub_821BD618(ctx, base);
loc_82237A98:
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

__attribute__((alias("__imp__sub_82237AB0"))) PPC_WEAK_FUNC(sub_82237AB0);
PPC_FUNC_IMPL(__imp__sub_82237AB0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-30248
	ctx.r9.s64 = r11.s64 + -30248;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82237ae4
	if (cr6.eq) goto loc_82237AE4;
	// bl 0x82130588
	ctx.lr = 0x82237AE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82237AE4:
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

__attribute__((alias("__imp__sub_82237AF8"))) PPC_WEAK_FUNC(sub_82237AF8);
PPC_FUNC_IMPL(__imp__sub_82237AF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82237b24
	if (cr6.eq) goto loc_82237B24;
	// lbz r11,41(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// stb r10,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r10.u8);
	// blr 
	return;
loc_82237B24:
	// lbz r11,41(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r10,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237B38"))) PPC_WEAK_FUNC(sub_82237B38);
PPC_FUNC_IMPL(__imp__sub_82237B38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,41(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 41);
	// or r10,r11,r4
	ctx.r10.u64 = r11.u64 | ctx.r4.u64;
	// stb r10,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237B58"))) PPC_WEAK_FUNC(sub_82237B58);
PPC_FUNC_IMPL(__imp__sub_82237B58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82237b68
	if (!cr6.lt) goto loc_82237B68;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82237b74
	goto loc_82237B74;
loc_82237B68:
	// cmpwi cr6,r4,255
	cr6.compare<int32_t>(ctx.r4.s32, 255, xer);
	// ble cr6,0x82237b74
	if (!cr6.gt) goto loc_82237B74;
	// li r4,255
	ctx.r4.s64 = 255;
loc_82237B74:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x82237b84
	if (!cr6.lt) goto loc_82237B84;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82237b90
	goto loc_82237B90;
loc_82237B84:
	// cmpwi cr6,r5,255
	cr6.compare<int32_t>(ctx.r5.s32, 255, xer);
	// ble cr6,0x82237b90
	if (!cr6.gt) goto loc_82237B90;
	// li r5,255
	ctx.r5.s64 = 255;
loc_82237B90:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x82237ba0
	if (!cr6.lt) goto loc_82237BA0;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x82237bac
	goto loc_82237BAC;
loc_82237BA0:
	// cmpwi cr6,r6,255
	cr6.compare<int32_t>(ctx.r6.s32, 255, xer);
	// ble cr6,0x82237bac
	if (!cr6.gt) goto loc_82237BAC;
	// li r6,255
	ctx.r6.s64 = 255;
loc_82237BAC:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge cr6,0x82237bbc
	if (!cr6.lt) goto loc_82237BBC;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x82237bc8
	goto loc_82237BC8;
loc_82237BBC:
	// cmpwi cr6,r7,255
	cr6.compare<int32_t>(ctx.r7.s32, 255, xer);
	// ble cr6,0x82237bc8
	if (!cr6.gt) goto loc_82237BC8;
	// li r7,255
	ctx.r7.s64 = 255;
loc_82237BC8:
	// rlwinm r11,r4,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00;
	// or r10,r11,r5
	ctx.r10.u64 = r11.u64 | ctx.r5.u64;
	// rlwinm r9,r10,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r6
	ctx.r8.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwinm r6,r8,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stw r5,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237BE8"))) PPC_WEAK_FUNC(sub_82237BE8);
PPC_FUNC_IMPL(__imp__sub_82237BE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r4,531
	ctx.r10.s64 = ctx.r4.s64 + 531;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// lfs f0,15360(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15360);
	f0.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,8500(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8504(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8504);
	ctx.f12.f64 = double(temp.f32);
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82237c3c
	if (!cr6.lt) goto loc_82237C3C;
	// li r11,0
	r11.s64 = 0;
	// b 0x82237c48
	goto loc_82237C48;
loc_82237C3C:
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// ble cr6,0x82237c48
	if (!cr6.gt) goto loc_82237C48;
	// li r11,255
	r11.s64 = 255;
loc_82237C48:
	// fmuls f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82237c68
	if (!cr6.lt) goto loc_82237C68;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82237c78
	goto loc_82237C78;
loc_82237C68:
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// li r9,255
	ctx.r9.s64 = 255;
	// bgt cr6,0x82237c78
	if (cr6.gt) goto loc_82237C78;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82237C78:
	// fmuls f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x82237c98
	if (!cr6.lt) goto loc_82237C98;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82237ca4
	goto loc_82237CA4;
loc_82237C98:
	// cmpwi cr6,r10,255
	cr6.compare<int32_t>(ctx.r10.s32, 255, xer);
	// ble cr6,0x82237ca4
	if (!cr6.gt) goto loc_82237CA4;
	// li r10,255
	ctx.r10.s64 = 255;
loc_82237CA4:
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// rlwimi r8,r11,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// or r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r6,r7,8,0,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// or r5,r6,r10
	ctx.r5.u64 = ctx.r6.u64 | ctx.r10.u64;
	// stw r5,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237CC0"))) PPC_WEAK_FUNC(sub_82237CC0);
PPC_FUNC_IMPL(__imp__sub_82237CC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
loc_82237CC8:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82237cec
	if (cr6.eq) goto loc_82237CEC;
loc_82237CD4:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x82237cec
	if (cr6.eq) goto loc_82237CEC;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82237cd4
	if (!cr6.eq) goto loc_82237CD4;
loc_82237CEC:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82237d10
	if (!cr6.eq) goto loc_82237D10;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r9,7
	cr6.compare<int32_t>(ctx.r9.s32, 7, xer);
	// blt cr6,0x82237cc8
	if (cr6.lt) goto loc_82237CC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82237D10:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237D18"))) PPC_WEAK_FUNC(sub_82237D18);
PPC_FUNC_IMPL(__imp__sub_82237D18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// li r9,7
	ctx.r9.s64 = 7;
loc_82237D28:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82237d54
	if (cr6.eq) goto loc_82237D54;
loc_82237D34:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 36);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82237d48
	if (!cr6.eq) goto loc_82237D48;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82237D48:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82237d34
	if (!cr6.eq) goto loc_82237D34;
loc_82237D54:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bne 0x82237d28
	if (!cr0.eq) goto loc_82237D28;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237D64"))) PPC_WEAK_FUNC(sub_82237D64);
PPC_FUNC_IMPL(__imp__sub_82237D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237D68"))) PPC_WEAK_FUNC(sub_82237D68);
PPC_FUNC_IMPL(__imp__sub_82237D68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,120(r10)
	PPC_STORE_U32(ctx.r10.u32 + 120, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237D8C"))) PPC_WEAK_FUNC(sub_82237D8C);
PPC_FUNC_IMPL(__imp__sub_82237D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237D90"))) PPC_WEAK_FUNC(sub_82237D90);
PPC_FUNC_IMPL(__imp__sub_82237D90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,-6452(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -6452);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82237dd4
	if (cr6.eq) goto loc_82237DD4;
	// lbz r11,41(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 41);
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// stb r9,41(r10)
	PPC_STORE_U8(ctx.r10.u32 + 41, ctx.r9.u8);
	// blr 
	return;
loc_82237DD4:
	// lbz r11,41(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 41);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,41(r10)
	PPC_STORE_U8(ctx.r10.u32 + 41, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237DE8"))) PPC_WEAK_FUNC(sub_82237DE8);
PPC_FUNC_IMPL(__imp__sub_82237DE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r8,41(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// or r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stb r7,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237E14"))) PPC_WEAK_FUNC(sub_82237E14);
PPC_FUNC_IMPL(__imp__sub_82237E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237E18"))) PPC_WEAK_FUNC(sub_82237E18);
PPC_FUNC_IMPL(__imp__sub_82237E18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lbz r8,41(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// andc r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ~ctx.r9.u64;
	// stb r7,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237E44"))) PPC_WEAK_FUNC(sub_82237E44);
PPC_FUNC_IMPL(__imp__sub_82237E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237E48"))) PPC_WEAK_FUNC(sub_82237E48);
PPC_FUNC_IMPL(__imp__sub_82237E48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,38(r9)
	PPC_STORE_U8(ctx.r9.u32 + 38, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237E6C"))) PPC_WEAK_FUNC(sub_82237E6C);
PPC_FUNC_IMPL(__imp__sub_82237E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237E70"))) PPC_WEAK_FUNC(sub_82237E70);
PPC_FUNC_IMPL(__imp__sub_82237E70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stb r10,36(r9)
	PPC_STORE_U8(ctx.r9.u32 + 36, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237E94"))) PPC_WEAK_FUNC(sub_82237E94);
PPC_FUNC_IMPL(__imp__sub_82237E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237E98"))) PPC_WEAK_FUNC(sub_82237E98);
PPC_FUNC_IMPL(__imp__sub_82237E98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,-6452(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -6452);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r11,124(r10)
	PPC_STORE_U8(ctx.r10.u32 + 124, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237EC8"))) PPC_WEAK_FUNC(sub_82237EC8);
PPC_FUNC_IMPL(__imp__sub_82237EC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,125(r9)
	PPC_STORE_U8(ctx.r9.u32 + 125, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237EE8"))) PPC_WEAK_FUNC(sub_82237EE8);
PPC_FUNC_IMPL(__imp__sub_82237EE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82237b58
	sub_82237B58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82237F04"))) PPC_WEAK_FUNC(sub_82237F04);
PPC_FUNC_IMPL(__imp__sub_82237F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82237F08"))) PPC_WEAK_FUNC(sub_82237F08);
PPC_FUNC_IMPL(__imp__sub_82237F08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82237be8
	sub_82237BE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82237F18"))) PPC_WEAK_FUNC(sub_82237F18);
PPC_FUNC_IMPL(__imp__sub_82237F18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82237f38
	if (cr6.eq) goto loc_82237F38;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82237f38
	if (cr6.eq) goto loc_82237F38;
	// b 0x82237cc0
	sub_82237CC0(ctx, base);
	return;
loc_82237F38:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237F40"))) PPC_WEAK_FUNC(sub_82237F40);
PPC_FUNC_IMPL(__imp__sub_82237F40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82237f90
	if (cr6.eq) goto loc_82237F90;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
loc_82237F58:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82237f80
	if (cr6.eq) goto loc_82237F80;
loc_82237F64:
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,120(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// beq cr6,0x82237f98
	if (cr6.eq) goto loc_82237F98;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82237f64
	if (!cr6.eq) goto loc_82237F64;
loc_82237F80:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r9,7
	cr6.compare<int32_t>(ctx.r9.s32, 7, xer);
	// blt cr6,0x82237f58
	if (cr6.lt) goto loc_82237F58;
loc_82237F90:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82237F98:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82237FA0"))) PPC_WEAK_FUNC(sub_82237FA0);
PPC_FUNC_IMPL(__imp__sub_82237FA0) {
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
	ctx.lr = 0x82237FA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x82237ff4
	if (cr6.eq) goto loc_82237FF4;
loc_82237FC0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82237fe8
	if (!cr6.eq) goto loc_82237FE8;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rotlwi r11,r31,0
	r11.u64 = __builtin_rotateleft32(r31.u32, 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x82237FE8;
	sub_82130588(ctx, base);
loc_82237FE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bne cr6,0x82237fc0
	if (!cr6.eq) goto loc_82237FC0;
loc_82237FF4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82237FFC"))) PPC_WEAK_FUNC(sub_82237FFC);
PPC_FUNC_IMPL(__imp__sub_82237FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238000"))) PPC_WEAK_FUNC(sub_82238000);
PPC_FUNC_IMPL(__imp__sub_82238000) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,144
	ctx.r9.s64 = 144;
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// sth r10,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r10.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// beq cr6,0x82238054
	if (cr6.eq) goto loc_82238054;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82238050;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_82238054:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x82238064;
	sub_821F10E0(ctx, base);
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

__attribute__((alias("__imp__sub_8223807C"))) PPC_WEAK_FUNC(sub_8223807C);
PPC_FUNC_IMPL(__imp__sub_8223807C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238080"))) PPC_WEAK_FUNC(sub_82238080);
PPC_FUNC_IMPL(__imp__sub_82238080) {
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
	// li r31,0
	r31.s64 = 0;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x82237920
	ctx.lr = 0x822380A8;
	sub_82237920(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82238128
	if (cr6.eq) goto loc_82238128;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_822380BC:
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lbz r10,126(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 126);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822380e0
	if (cr6.eq) goto loc_822380E0;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// stb r31,126(r11)
	PPC_STORE_U8(r11.u32 + 126, r31.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822380e0
	if (cr6.eq) goto loc_822380E0;
	// stb r31,466(r10)
	PPC_STORE_U8(ctx.r10.u32 + 466, r31.u8);
loc_822380E0:
	// lwz r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822380bc
	if (!cr6.eq) goto loc_822380BC;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
loc_822380F8:
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// bge cr6,0x82238120
	if (!cr6.lt) goto loc_82238120;
	// lwz r8,0(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822380f8
	if (cr6.eq) goto loc_822380F8;
	// b 0x822380bc
	goto loc_822380BC;
loc_82238120:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822380bc
	if (!cr6.eq) goto loc_822380BC;
loc_82238128:
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

__attribute__((alias("__imp__sub_8223813C"))) PPC_WEAK_FUNC(sub_8223813C);
PPC_FUNC_IMPL(__imp__sub_8223813C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238140"))) PPC_WEAK_FUNC(sub_82238140);
PPC_FUNC_IMPL(__imp__sub_82238140) {
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
	ctx.lr = 0x82238148;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822381b0
	if (cr6.eq) goto loc_822381B0;
	// addi r31,r29,8
	r31.s64 = r29.s64 + 8;
	// li r30,7
	r30.s64 = 7;
loc_82238168:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x8223818c
	if (cr6.eq) goto loc_8223818C;
loc_82238174:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// beq cr6,0x8223818c
	if (cr6.eq) goto loc_8223818C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x82238174
	if (!cr6.eq) goto loc_82238174;
loc_8223818C:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x822381a4
	if (cr6.eq) goto loc_822381A4;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82237fa0
	ctx.lr = 0x822381A4;
	sub_82237FA0(ctx, base);
loc_822381A4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x82238168
	if (!cr0.eq) goto loc_82238168;
loc_822381B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822381B8"))) PPC_WEAK_FUNC(sub_822381B8);
PPC_FUNC_IMPL(__imp__sub_822381B8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// b 0x82238080
	sub_82238080(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822381C0"))) PPC_WEAK_FUNC(sub_822381C0);
PPC_FUNC_IMPL(__imp__sub_822381C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-30248
	ctx.r9.s64 = r11.s64 + -30248;
	// li r11,0
	r11.s64 = 0;
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,3
	ctx.r7.s64 = 3;
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stb r8,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r8.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r7,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r7.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,38(r3)
	PPC_STORE_U8(ctx.r3.u32 + 38, r11.u8);
	// stb r11,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, r11.u8);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stb r11,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, r11.u8);
	// stb r11,125(r3)
	PPC_STORE_U8(ctx.r3.u32 + 125, r11.u8);
	// stb r11,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, r11.u8);
	// stw r6,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238260"))) PPC_WEAK_FUNC(sub_82238260);
PPC_FUNC_IMPL(__imp__sub_82238260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-30248
	ctx.r8.s64 = r11.s64 + -30248;
	// li r11,0
	r11.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stb r7,37(r3)
	PPC_STORE_U8(ctx.r3.u32 + 37, ctx.r7.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,38(r3)
	PPC_STORE_U8(ctx.r3.u32 + 38, r11.u8);
	// stb r11,39(r3)
	PPC_STORE_U8(ctx.r3.u32 + 39, r11.u8);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stb r11,41(r3)
	PPC_STORE_U8(ctx.r3.u32 + 41, r11.u8);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stw r10,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r10.u32);
	// stw r10,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r10.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stb r11,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, r11.u8);
	// stb r11,125(r3)
	PPC_STORE_U8(ctx.r3.u32 + 125, r11.u8);
	// stb r11,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, r11.u8);
	// stw r6,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r6.u32);
	// stb r4,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822382FC"))) PPC_WEAK_FUNC(sub_822382FC);
PPC_FUNC_IMPL(__imp__sub_822382FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238300"))) PPC_WEAK_FUNC(sub_82238300);
PPC_FUNC_IMPL(__imp__sub_82238300) {
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
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x82238338
	if (cr6.eq) goto loc_82238338;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82238338
	if (cr6.eq) goto loc_82238338;
	// bl 0x82237cc0
	ctx.lr = 0x82238334;
	sub_82237CC0(ctx, base);
	// b 0x8223833c
	goto loc_8223833C;
loc_82238338:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8223833C:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238358"))) PPC_WEAK_FUNC(sub_82238358);
PPC_FUNC_IMPL(__imp__sub_82238358) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x82237f40
	ctx.lr = 0x82238374;
	sub_82237F40(ctx, base);
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r3,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223838C"))) PPC_WEAK_FUNC(sub_8223838C);
PPC_FUNC_IMPL(__imp__sub_8223838C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238390"))) PPC_WEAK_FUNC(sub_82238390);
PPC_FUNC_IMPL(__imp__sub_82238390) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// beqlr cr6
	if (cr6.eq) return;
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238404"))) PPC_WEAK_FUNC(sub_82238404);
PPC_FUNC_IMPL(__imp__sub_82238404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238408"))) PPC_WEAK_FUNC(sub_82238408);
PPC_FUNC_IMPL(__imp__sub_82238408) {
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
	ctx.lr = 0x82238410;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,-6452(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + -6452);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82238490
	if (cr6.eq) goto loc_82238490;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82238460
	if (cr6.eq) goto loc_82238460;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r30,64
	r29.s64 = r30.s64 + 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x826bde70
	ctx.lr = 0x82238448;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82238460
	if (cr6.eq) goto loc_82238460;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826cb6c0
	ctx.lr = 0x8223845C;
	sub_826CB6C0(ctx, base);
	// lwz r30,-6452(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + -6452);
loc_82238460:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238140
	ctx.lr = 0x8223846C;
	sub_82238140(ctx, base);
	// lwz r11,-6452(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -6452);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82238490
	if (cr6.eq) goto loc_82238490;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// stw r31,88(r11)
	PPC_STORE_U32(r11.u32 + 88, r31.u32);
	// sth r9,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r9.u16);
loc_82238490:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82238498"))) PPC_WEAK_FUNC(sub_82238498);
PPC_FUNC_IMPL(__imp__sub_82238498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82238140
	sub_82238140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822384B8"))) PPC_WEAK_FUNC(sub_822384B8);
PPC_FUNC_IMPL(__imp__sub_822384B8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822384BC"))) PPC_WEAK_FUNC(sub_822384BC);
PPC_FUNC_IMPL(__imp__sub_822384BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822384C0"))) PPC_WEAK_FUNC(sub_822384C0);
PPC_FUNC_IMPL(__imp__sub_822384C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-6452(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82238564
	if (cr6.eq) goto loc_82238564;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r4,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r4.u8);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,80
	ctx.r5.s64 = 80;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	ctx.f13.f64 = double(temp.f32);
	// li r4,96
	ctx.r4.s64 = 96;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82238564
	if (cr6.eq) goto loc_82238564;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6452(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6452);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r31,r11,64
	r31.s64 = r11.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bde70
	ctx.lr = 0x8223854C;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82238564
	if (!cr6.eq) goto loc_82238564;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389998
	ctx.lr = 0x82238564;
	sub_82389998(ctx, base);
loc_82238564:
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

__attribute__((alias("__imp__sub_82238578"))) PPC_WEAK_FUNC(sub_82238578);
PPC_FUNC_IMPL(__imp__sub_82238578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82238580;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,-6452(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223862c
	if (cr6.eq) goto loc_8223862C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r5,140(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x822384c0
	ctx.lr = 0x822385C4;
	sub_822384C0(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x822385d8
	if (!cr6.eq) goto loc_822385D8;
	// lbz r11,41(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 41);
	// ori r10,r11,1
	ctx.r10.u64 = r11.u64 | 1;
	// b 0x822385e0
	goto loc_822385E0;
loc_822385D8:
	// lbz r11,41(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 41);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_822385E0:
	// stb r10,41(r31)
	PPC_STORE_U8(r31.u32 + 41, ctx.r10.u8);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// stb r29,38(r31)
	PPC_STORE_U8(r31.u32 + 38, r29.u8);
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8223862c
	if (cr6.eq) goto loc_8223862C;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-6452(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -6452);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r31,r11,64
	r31.s64 = r11.s64 + 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bde70
	ctx.lr = 0x82238614;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8223862c
	if (!cr6.eq) goto loc_8223862C;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389998
	ctx.lr = 0x8223862C;
	sub_82389998(ctx, base);
loc_8223862C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82238634"))) PPC_WEAK_FUNC(sub_82238634);
PPC_FUNC_IMPL(__imp__sub_82238634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238638"))) PPC_WEAK_FUNC(sub_82238638);
PPC_FUNC_IMPL(__imp__sub_82238638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82238640;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r31,r3,8
	r31.s64 = ctx.r3.s64 + 8;
	// li r29,7
	r29.s64 = 7;
loc_8223864C:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// beq cr6,0x8223866c
	if (cr6.eq) goto loc_8223866C;
loc_82238658:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82238664;
	sub_82130588(ctx, base);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x82238658
	if (!cr6.eq) goto loc_82238658;
loc_8223866C:
	// stw r31,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r31.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stw r31,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r31.u32);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x8223864c
	if (!cr0.eq) goto loc_8223864C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82238688"))) PPC_WEAK_FUNC(sub_82238688);
PPC_FUNC_IMPL(__imp__sub_82238688) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// bne cr6,0x822386c0
	if (!cr6.eq) goto loc_822386C0;
	// lbz r6,38(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 38);
	// lbz r5,41(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 41);
	// lbz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 36);
	// bl 0x82237978
	ctx.lr = 0x822386BC;
	sub_82237978(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822386C0:
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x822386ec
	if (cr6.eq) goto loc_822386EC;
loc_822386DC:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x822386dc
	if (!cr6.eq) goto loc_822386DC;
loc_822386EC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r9,r11,-30260
	ctx.r9.s64 = r11.s64 + -30260;
	// lbzx r8,r5,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + ctx.r9.u32);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bge cr6,0x82238728
	if (!cr6.lt) goto loc_82238728;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x82238708;
	sub_82130528(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82238714
	if (cr0.eq) goto loc_82238714;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
loc_82238714:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_82238728:
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

__attribute__((alias("__imp__sub_82238740"))) PPC_WEAK_FUNC(sub_82238740);
PPC_FUNC_IMPL(__imp__sub_82238740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82238408
	sub_82238408(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223874C"))) PPC_WEAK_FUNC(sub_8223874C);
PPC_FUNC_IMPL(__imp__sub_8223874C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238750"))) PPC_WEAK_FUNC(sub_82238750);
PPC_FUNC_IMPL(__imp__sub_82238750) {
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
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f1,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
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
	// bl 0x822384c0
	ctx.lr = 0x82238794;
	sub_822384C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822387A4"))) PPC_WEAK_FUNC(sub_822387A4);
PPC_FUNC_IMPL(__imp__sub_822387A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822387A8"))) PPC_WEAK_FUNC(sub_822387A8);
PPC_FUNC_IMPL(__imp__sub_822387A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82238578
	sub_82238578(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822387BC"))) PPC_WEAK_FUNC(sub_822387BC);
PPC_FUNC_IMPL(__imp__sub_822387BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822387C0"))) PPC_WEAK_FUNC(sub_822387C0);
PPC_FUNC_IMPL(__imp__sub_822387C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82238140
	sub_82238140(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822387E4"))) PPC_WEAK_FUNC(sub_822387E4);
PPC_FUNC_IMPL(__imp__sub_822387E4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822387E8"))) PPC_WEAK_FUNC(sub_822387E8);
PPC_FUNC_IMPL(__imp__sub_822387E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82238824
	if (cr6.eq) goto loc_82238824;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// addi r10,r11,76
	ctx.r10.s64 = r11.s64 + 76;
	// lhz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r9.u16);
	// stw r8,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r8.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822381c0
	sub_822381C0(ctx, base);
	return;
loc_82238824:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223882C"))) PPC_WEAK_FUNC(sub_8223882C);
PPC_FUNC_IMPL(__imp__sub_8223882C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238830"))) PPC_WEAK_FUNC(sub_82238830);
PPC_FUNC_IMPL(__imp__sub_82238830) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82238890
	if (cr6.eq) goto loc_82238890;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// addi r10,r11,76
	ctx.r10.s64 = r11.s64 + 76;
	// lhz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r9.u16);
	// stw r8,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r8.u32);
	// beq cr6,0x8223887c
	if (cr6.eq) goto loc_8223887C;
	// bl 0x822381c0
	ctx.lr = 0x8223887C;
	sub_822381C0(ctx, base);
loc_8223887C:
	// stb r5,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, ctx.r5.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82238890:
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

__attribute__((alias("__imp__sub_822388A4"))) PPC_WEAK_FUNC(sub_822388A4);
PPC_FUNC_IMPL(__imp__sub_822388A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822388A8"))) PPC_WEAK_FUNC(sub_822388A8);
PPC_FUNC_IMPL(__imp__sub_822388A8) {
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
	ctx.lr = 0x822388B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x82238904
	if (cr6.eq) goto loc_82238904;
loc_822388CC:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplw cr6,r10,r28
	cr6.compare<uint32_t>(ctx.r10.u32, r28.u32, xer);
	// beq cr6,0x822388e4
	if (cr6.eq) goto loc_822388E4;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// bne cr6,0x822388cc
	if (!cr6.eq) goto loc_822388CC;
loc_822388E4:
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// beq cr6,0x82238904
	if (cr6.eq) goto loc_82238904;
loc_822388EC:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// beq cr6,0x82238904
	if (cr6.eq) goto loc_82238904;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x822388ec
	if (!cr6.eq) goto loc_822388EC;
loc_82238904:
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// cmplw cr6,r29,r31
	cr6.compare<uint32_t>(r29.u32, r31.u32, xer);
	// beq cr6,0x82238940
	if (cr6.eq) goto loc_82238940;
	// bl 0x82130528
	ctx.lr = 0x82238918;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addic. r10,r11,8
	xer.ca = r11.u32 > 4294967287;
	ctx.r10.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82238928
	if (cr0.eq) goto loc_82238928;
	// stw r28,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r28.u32);
loc_82238928:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// stw r29,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r29.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// b 0x82238968
	goto loc_82238968;
loc_82238940:
	// bl 0x82130528
	ctx.lr = 0x82238944;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addic. r10,r11,8
	xer.ca = r11.u32 > 4294967287;
	ctx.r10.s64 = r11.s64 + 8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82238954
	if (cr0.eq) goto loc_82238954;
	// stw r28,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r28.u32);
loc_82238954:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_82238968:
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x82130588
	ctx.lr = 0x82238980;
	sub_82130588(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82238988"))) PPC_WEAK_FUNC(sub_82238988);
PPC_FUNC_IMPL(__imp__sub_82238988) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-6452(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822389e0
	if (cr6.eq) goto loc_822389E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822389e0
	if (cr6.eq) goto loc_822389E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82238140
	ctx.lr = 0x822389C0;
	sub_82238140(ctx, base);
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-6452(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -6452);
	// bl 0x82238688
	ctx.lr = 0x822389D0;
	sub_82238688(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220a0b8
	ctx.lr = 0x822389E0;
	sub_8220A0B8(ctx, base);
loc_822389E0:
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

__attribute__((alias("__imp__sub_822389F8"))) PPC_WEAK_FUNC(sub_822389F8);
PPC_FUNC_IMPL(__imp__sub_822389F8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,-6452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82238a5c
	if (cr6.eq) goto loc_82238A5C;
	// lwz r3,88(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// addi r10,r11,76
	ctx.r10.s64 = r11.s64 + 76;
	// lhz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 82);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,82(r11)
	PPC_STORE_U16(r11.u32 + 82, ctx.r9.u16);
	// stw r8,88(r11)
	PPC_STORE_U32(r11.u32 + 88, ctx.r8.u32);
	// beq cr6,0x82238a44
	if (cr6.eq) goto loc_82238A44;
	// bl 0x822381c0
	ctx.lr = 0x82238A44;
	sub_822381C0(ctx, base);
loc_82238A44:
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82238A5C:
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238A78"))) PPC_WEAK_FUNC(sub_82238A78);
PPC_FUNC_IMPL(__imp__sub_82238A78) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82238830
	ctx.lr = 0x82238A94;
	sub_82238830(ctx, base);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238AAC"))) PPC_WEAK_FUNC(sub_82238AAC);
PPC_FUNC_IMPL(__imp__sub_82238AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238AB0"))) PPC_WEAK_FUNC(sub_82238AB0);
PPC_FUNC_IMPL(__imp__sub_82238AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82238988
	sub_82238988(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82238ABC"))) PPC_WEAK_FUNC(sub_82238ABC);
PPC_FUNC_IMPL(__imp__sub_82238ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238AC0"))) PPC_WEAK_FUNC(sub_82238AC0);
PPC_FUNC_IMPL(__imp__sub_82238AC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-6452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6452);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82238638
	sub_82238638(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82238AD4"))) PPC_WEAK_FUNC(sub_82238AD4);
PPC_FUNC_IMPL(__imp__sub_82238AD4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238AD8"))) PPC_WEAK_FUNC(sub_82238AD8);
PPC_FUNC_IMPL(__imp__sub_82238AD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,-11796
	ctx.r10.s64 = r11.s64 + -11796;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
loc_82238B08:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// std r9,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r9.u64);
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r7.u64);
	// stw r11,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r11.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x82238b08
	if (!cr0.lt) goto loc_82238B08;
	// sth r9,70(r31)
	PPC_STORE_U16(r31.u32 + 70, ctx.r9.u16);
	// li r4,229
	ctx.r4.s64 = 229;
	// sth r9,68(r31)
	PPC_STORE_U16(r31.u32 + 68, ctx.r9.u16);
	// addi r3,r31,76
	ctx.r3.s64 = r31.s64 + 76;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
	// stb r9,75(r31)
	PPC_STORE_U8(r31.u32 + 75, ctx.r9.u8);
	// bl 0x82238000
	ctx.lr = 0x82238B48;
	sub_82238000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,-6452(r11)
	PPC_STORE_U32(r11.u32 + -6452, r31.u32);
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

__attribute__((alias("__imp__sub_82238B68"))) PPC_WEAK_FUNC(sub_82238B68);
PPC_FUNC_IMPL(__imp__sub_82238B68) {
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
	// lis r11,-32220
	r11.s64 = -2111569920;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-30216
	ctx.r4.s64 = r11.s64 + -30216;
	// addi r3,r10,-29572
	ctx.r3.s64 = ctx.r10.s64 + -29572;
	// bl 0x82554798
	ctx.lr = 0x82238B88;
	sub_82554798(ctx, base);
	// lis r9,-32220
	ctx.r9.s64 = -2111569920;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-30088
	ctx.r4.s64 = ctx.r9.s64 + -30088;
	// addi r3,r8,-29604
	ctx.r3.s64 = ctx.r8.s64 + -29604;
	// bl 0x82554798
	ctx.lr = 0x82238B9C;
	sub_82554798(ctx, base);
	// lis r7,-32220
	ctx.r7.s64 = -2111569920;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-30912
	ctx.r4.s64 = ctx.r7.s64 + -30912;
	// addi r3,r6,-29636
	ctx.r3.s64 = ctx.r6.s64 + -29636;
	// bl 0x82554798
	ctx.lr = 0x82238BB0;
	sub_82554798(ctx, base);
	// lis r5,-32220
	ctx.r5.s64 = -2111569920;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-30032
	ctx.r4.s64 = ctx.r5.s64 + -30032;
	// addi r3,r3,-29664
	ctx.r3.s64 = ctx.r3.s64 + -29664;
	// bl 0x82554798
	ctx.lr = 0x82238BC4;
	sub_82554798(ctx, base);
	// lis r11,-32220
	r11.s64 = -2111569920;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-32000
	ctx.r4.s64 = r11.s64 + -32000;
	// addi r3,r10,-29692
	ctx.r3.s64 = ctx.r10.s64 + -29692;
	// bl 0x82554798
	ctx.lr = 0x82238BD8;
	sub_82554798(ctx, base);
	// lis r9,-32220
	ctx.r9.s64 = -2111569920;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-30896
	ctx.r4.s64 = ctx.r9.s64 + -30896;
	// addi r3,r8,-29720
	ctx.r3.s64 = ctx.r8.s64 + -29720;
	// bl 0x82554798
	ctx.lr = 0x82238BEC;
	sub_82554798(ctx, base);
	// lis r7,-32220
	ctx.r7.s64 = -2111569920;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-30808
	ctx.r4.s64 = ctx.r7.s64 + -30808;
	// addi r3,r6,-29756
	ctx.r3.s64 = ctx.r6.s64 + -29756;
	// bl 0x82554798
	ctx.lr = 0x82238C00;
	sub_82554798(ctx, base);
	// lis r5,-32221
	ctx.r5.s64 = -2111635456;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,32104
	ctx.r4.s64 = ctx.r5.s64 + 32104;
	// addi r3,r3,-29788
	ctx.r3.s64 = ctx.r3.s64 + -29788;
	// bl 0x82554798
	ctx.lr = 0x82238C14;
	sub_82554798(ctx, base);
	// lis r11,-32220
	r11.s64 = -2111569920;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-31912
	ctx.r4.s64 = r11.s64 + -31912;
	// addi r3,r10,-29824
	ctx.r3.s64 = ctx.r10.s64 + -29824;
	// bl 0x82554798
	ctx.lr = 0x82238C28;
	sub_82554798(ctx, base);
	// lis r9,-32220
	ctx.r9.s64 = -2111569920;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-30016
	ctx.r4.s64 = ctx.r9.s64 + -30016;
	// addi r3,r8,-29848
	ctx.r3.s64 = ctx.r8.s64 + -29848;
	// bl 0x82554798
	ctx.lr = 0x82238C3C;
	sub_82554798(ctx, base);
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,32144
	ctx.r4.s64 = ctx.r7.s64 + 32144;
	// addi r3,r6,-29876
	ctx.r3.s64 = ctx.r6.s64 + -29876;
	// bl 0x82554798
	ctx.lr = 0x82238C50;
	sub_82554798(ctx, base);
	// lis r5,-32221
	ctx.r5.s64 = -2111635456;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,32232
	ctx.r4.s64 = ctx.r5.s64 + 32232;
	// addi r3,r3,-29904
	ctx.r3.s64 = ctx.r3.s64 + -29904;
	// bl 0x82554798
	ctx.lr = 0x82238C64;
	sub_82554798(ctx, base);
	// lis r11,-32221
	r11.s64 = -2111635456;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,32280
	ctx.r4.s64 = r11.s64 + 32280;
	// addi r3,r10,-29932
	ctx.r3.s64 = ctx.r10.s64 + -29932;
	// bl 0x82554798
	ctx.lr = 0x82238C78;
	sub_82554798(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,32328
	ctx.r4.s64 = ctx.r9.s64 + 32328;
	// addi r3,r8,-29964
	ctx.r3.s64 = ctx.r8.s64 + -29964;
	// bl 0x82554798
	ctx.lr = 0x82238C8C;
	sub_82554798(ctx, base);
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,32368
	ctx.r4.s64 = ctx.r7.s64 + 32368;
	// addi r3,r6,-29992
	ctx.r3.s64 = ctx.r6.s64 + -29992;
	// bl 0x82554798
	ctx.lr = 0x82238CA0;
	sub_82554798(ctx, base);
	// lis r5,-32220
	ctx.r5.s64 = -2111569920;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-30784
	ctx.r4.s64 = ctx.r5.s64 + -30784;
	// addi r3,r3,-30024
	ctx.r3.s64 = ctx.r3.s64 + -30024;
	// bl 0x82554798
	ctx.lr = 0x82238CB4;
	sub_82554798(ctx, base);
	// lis r11,-32221
	r11.s64 = -2111635456;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,32408
	ctx.r4.s64 = r11.s64 + 32408;
	// addi r3,r10,-30052
	ctx.r3.s64 = ctx.r10.s64 + -30052;
	// bl 0x82554798
	ctx.lr = 0x82238CC8;
	sub_82554798(ctx, base);
	// lis r9,-32221
	ctx.r9.s64 = -2111635456;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,32456
	ctx.r4.s64 = ctx.r9.s64 + 32456;
	// addi r3,r8,-30084
	ctx.r3.s64 = ctx.r8.s64 + -30084;
	// bl 0x82554798
	ctx.lr = 0x82238CDC;
	sub_82554798(ctx, base);
	// lis r7,-32221
	ctx.r7.s64 = -2111635456;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,32488
	ctx.r4.s64 = ctx.r7.s64 + 32488;
	// addi r3,r6,-30108
	ctx.r3.s64 = ctx.r6.s64 + -30108;
	// bl 0x82554798
	ctx.lr = 0x82238CF0;
	sub_82554798(ctx, base);
	// lis r5,-32221
	ctx.r5.s64 = -2111635456;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,32520
	ctx.r4.s64 = ctx.r5.s64 + 32520;
	// addi r3,r3,-30144
	ctx.r3.s64 = ctx.r3.s64 + -30144;
	// bl 0x82554798
	ctx.lr = 0x82238D04;
	sub_82554798(ctx, base);
	// lis r11,-32220
	r11.s64 = -2111569920;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-31856
	ctx.r4.s64 = r11.s64 + -31856;
	// addi r3,r10,-30172
	ctx.r3.s64 = ctx.r10.s64 + -30172;
	// bl 0x82554798
	ctx.lr = 0x82238D18;
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

__attribute__((alias("__imp__sub_82238D28"))) PPC_WEAK_FUNC(sub_82238D28);
PPC_FUNC_IMPL(__imp__sub_82238D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8217bd00
	ctx.lr = 0x82238D48;
	sub_8217BD00(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82238D64"))) PPC_WEAK_FUNC(sub_82238D64);
PPC_FUNC_IMPL(__imp__sub_82238D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238D68"))) PPC_WEAK_FUNC(sub_82238D68);
PPC_FUNC_IMPL(__imp__sub_82238D68) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217bd00
	ctx.lr = 0x82238D90;
	sub_8217BD00(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// fcmpu cr6,f9,f31
	cr6.compare(ctx.f9.f64, f31.f64);
	// blt cr6,0x82238dc8
	if (cr6.lt) goto loc_82238DC8;
	// li r11,0
	r11.s64 = 0;
loc_82238DC8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_82238DE0"))) PPC_WEAK_FUNC(sub_82238DE0);
PPC_FUNC_IMPL(__imp__sub_82238DE0) {
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
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r5,r10,29952
	ctx.r5.s64 = ctx.r10.s64 + 29952;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,20(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r11,80
	ctx.r6.s64 = r11.s64 + 80;
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82238E20;
	sub_82723940(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238E30"))) PPC_WEAK_FUNC(sub_82238E30);
PPC_FUNC_IMPL(__imp__sub_82238E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-29200
	ctx.r5.s64 = ctx.r10.s64 + -29200;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82238E54"))) PPC_WEAK_FUNC(sub_82238E54);
PPC_FUNC_IMPL(__imp__sub_82238E54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238E58"))) PPC_WEAK_FUNC(sub_82238E58);
PPC_FUNC_IMPL(__imp__sub_82238E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-29176
	ctx.r5.s64 = ctx.r10.s64 + -29176;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82238E7C"))) PPC_WEAK_FUNC(sub_82238E7C);
PPC_FUNC_IMPL(__imp__sub_82238E7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238E80"))) PPC_WEAK_FUNC(sub_82238E80);
PPC_FUNC_IMPL(__imp__sub_82238E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-29152
	ctx.r5.s64 = ctx.r10.s64 + -29152;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82238EA4"))) PPC_WEAK_FUNC(sub_82238EA4);
PPC_FUNC_IMPL(__imp__sub_82238EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238EA8"))) PPC_WEAK_FUNC(sub_82238EA8);
PPC_FUNC_IMPL(__imp__sub_82238EA8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-29104
	ctx.r8.s64 = ctx.r10.s64 + -29104;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r3,r9,-29128
	ctx.r3.s64 = ctx.r9.s64 + -29128;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82723808
	ctx.lr = 0x82238EE0;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82238EFC"))) PPC_WEAK_FUNC(sub_82238EFC);
PPC_FUNC_IMPL(__imp__sub_82238EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238F00"))) PPC_WEAK_FUNC(sub_82238F00);
PPC_FUNC_IMPL(__imp__sub_82238F00) {
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
	ctx.lr = 0x82238F08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-29104
	ctx.r10.s64 = r11.s64 + -29104;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x82238f50
	if (cr6.eq) goto loc_82238F50;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82238F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82238F50:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-32560
	ctx.r8.s64 = ctx.r10.s64 + -32560;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82238F70"))) PPC_WEAK_FUNC(sub_82238F70);
PPC_FUNC_IMPL(__imp__sub_82238F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,472(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82238F84"))) PPC_WEAK_FUNC(sub_82238F84);
PPC_FUNC_IMPL(__imp__sub_82238F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82238F88"))) PPC_WEAK_FUNC(sub_82238F88);
PPC_FUNC_IMPL(__imp__sub_82238F88) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stfd f30,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2528
	ctx.r3.s64 = ctx.r5.s64 + 2528;
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r4,-31648
	ctx.r10.s64 = ctx.r4.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f31.f64 = double(temp.f32);
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f1,f10,f11,f31
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// bl 0x823dcb30
	ctx.lr = 0x8223904C;
	sub_823DCB30(ctx, base);
	// lfs f9,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// frsp f1,f1
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f9,f30
	cr6.compare(ctx.f9.f64, f30.f64);
	// bge cr6,0x82239060
	if (!cr6.lt) goto loc_82239060;
	// fmuls f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64));
loc_82239060:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82239078"))) PPC_WEAK_FUNC(sub_82239078);
PPC_FUNC_IMPL(__imp__sub_82239078) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f1,-16516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16516);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239084"))) PPC_WEAK_FUNC(sub_82239084);
PPC_FUNC_IMPL(__imp__sub_82239084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239088"))) PPC_WEAK_FUNC(sub_82239088);
PPC_FUNC_IMPL(__imp__sub_82239088) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r6,784
	ctx.r3.s64 = ctx.r6.s64 + 784;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239090"))) PPC_WEAK_FUNC(sub_82239090);
PPC_FUNC_IMPL(__imp__sub_82239090) {
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
	// lwz r11,176(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822390c8
	if (!cr6.eq) goto loc_822390C8;
	// lfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
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
loc_822390C8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x822390E0;
	sub_823DBAE8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmadds f9,f11,f12,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + f0.f64));
	// fmuls f1,f9,f10
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
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

__attribute__((alias("__imp__sub_82239110"))) PPC_WEAK_FUNC(sub_82239110);
PPC_FUNC_IMPL(__imp__sub_82239110) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-29032
	ctx.r5.s64 = r11.s64 + -29032;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,8
	ctx.r6.s64 = r31.s64 + 8;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223914C;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-29060
	ctx.r5.s64 = ctx.r10.s64 + -29060;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223916C;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-29088
	ctx.r5.s64 = ctx.r9.s64 + -29088;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8223918C;
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

__attribute__((alias("__imp__sub_822391A4"))) PPC_WEAK_FUNC(sub_822391A4);
PPC_FUNC_IMPL(__imp__sub_822391A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822391A8"))) PPC_WEAK_FUNC(sub_822391A8);
PPC_FUNC_IMPL(__imp__sub_822391A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822391bc
	if (cr6.eq) goto loc_822391BC;
	// addi r3,r6,800
	ctx.r3.s64 = ctx.r6.s64 + 800;
	// blr 
	return;
loc_822391BC:
	// lwz r11,120(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 120);
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822391C8"))) PPC_WEAK_FUNC(sub_822391C8);
PPC_FUNC_IMPL(__imp__sub_822391C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,38(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 38);
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// beq cr6,0x822391e0
	if (cr6.eq) goto loc_822391E0;
	// lwz r11,120(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// blr 
	return;
loc_822391E0:
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822391E8"))) PPC_WEAK_FUNC(sub_822391E8);
PPC_FUNC_IMPL(__imp__sub_822391E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,153(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 153);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822391FC"))) PPC_WEAK_FUNC(sub_822391FC);
PPC_FUNC_IMPL(__imp__sub_822391FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239200"))) PPC_WEAK_FUNC(sub_82239200);
PPC_FUNC_IMPL(__imp__sub_82239200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-29016
	ctx.r5.s64 = ctx.r10.s64 + -29016;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,16
	ctx.r6.s64 = r11.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82239224"))) PPC_WEAK_FUNC(sub_82239224);
PPC_FUNC_IMPL(__imp__sub_82239224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239228"))) PPC_WEAK_FUNC(sub_82239228);
PPC_FUNC_IMPL(__imp__sub_82239228) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r6,r10,-28956
	ctx.r6.s64 = ctx.r10.s64 + -28956;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lfs f0,-28964(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28964);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r5,-28976
	ctx.r3.s64 = ctx.r5.s64 + -28976;
	// lfs f12,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x82239284;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r3,r4,-28992
	ctx.r3.s64 = ctx.r4.s64 + -28992;
	// bl 0x82723808
	ctx.lr = 0x82239294;
	sub_82723808(ctx, base);
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

__attribute__((alias("__imp__sub_822392B0"))) PPC_WEAK_FUNC(sub_822392B0);
PPC_FUNC_IMPL(__imp__sub_822392B0) {
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
	ctx.lr = 0x822392B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-28956
	ctx.r10.s64 = r11.s64 + -28956;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x82239300
	if (cr6.eq) goto loc_82239300;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82239300:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r10,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r10.u32);
	// beq cr6,0x82239334
	if (cr6.eq) goto loc_82239334;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82239334:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-32560
	ctx.r8.s64 = ctx.r10.s64 + -32560;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239354"))) PPC_WEAK_FUNC(sub_82239354);
PPC_FUNC_IMPL(__imp__sub_82239354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239358"))) PPC_WEAK_FUNC(sub_82239358);
PPC_FUNC_IMPL(__imp__sub_82239358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239368"))) PPC_WEAK_FUNC(sub_82239368);
PPC_FUNC_IMPL(__imp__sub_82239368) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28940
	ctx.r5.s64 = ctx.r10.s64 + -28940;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223938C"))) PPC_WEAK_FUNC(sub_8223938C);
PPC_FUNC_IMPL(__imp__sub_8223938C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239390"))) PPC_WEAK_FUNC(sub_82239390);
PPC_FUNC_IMPL(__imp__sub_82239390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28920
	ctx.r5.s64 = ctx.r10.s64 + -28920;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822393B4"))) PPC_WEAK_FUNC(sub_822393B4);
PPC_FUNC_IMPL(__imp__sub_822393B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822393B8"))) PPC_WEAK_FUNC(sub_822393B8);
PPC_FUNC_IMPL(__imp__sub_822393B8) {
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
	ctx.lr = 0x822393C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-28892
	ctx.r10.s64 = r11.s64 + -28892;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x82239408
	if (cr6.eq) goto loc_82239408;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82239408:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-32560
	ctx.r8.s64 = ctx.r10.s64 + -32560;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239428"))) PPC_WEAK_FUNC(sub_82239428);
PPC_FUNC_IMPL(__imp__sub_82239428) {
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
	// bl 0x822393b8
	ctx.lr = 0x82239448;
	sub_822393B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82239460
	if (cr6.eq) goto loc_82239460;
	// bl 0x82130588
	ctx.lr = 0x8223945C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82239460:
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

__attribute__((alias("__imp__sub_82239478"))) PPC_WEAK_FUNC(sub_82239478);
PPC_FUNC_IMPL(__imp__sub_82239478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-16524
	ctx.r3.s64 = r11.s64 + -16524;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239484"))) PPC_WEAK_FUNC(sub_82239484);
PPC_FUNC_IMPL(__imp__sub_82239484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239488"))) PPC_WEAK_FUNC(sub_82239488);
PPC_FUNC_IMPL(__imp__sub_82239488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-16520
	ctx.r3.s64 = r11.s64 + -16520;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239494"))) PPC_WEAK_FUNC(sub_82239494);
PPC_FUNC_IMPL(__imp__sub_82239494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239498"))) PPC_WEAK_FUNC(sub_82239498);
PPC_FUNC_IMPL(__imp__sub_82239498) {
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
	ctx.lr = 0x822394A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-29232
	ctx.r10.s64 = r11.s64 + -29232;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x822394e8
	if (cr6.eq) goto loc_822394E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822394E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822394E8:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-32560
	ctx.r8.s64 = ctx.r10.s64 + -32560;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239508"))) PPC_WEAK_FUNC(sub_82239508);
PPC_FUNC_IMPL(__imp__sub_82239508) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28872
	ctx.r5.s64 = ctx.r10.s64 + -28872;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223952C"))) PPC_WEAK_FUNC(sub_8223952C);
PPC_FUNC_IMPL(__imp__sub_8223952C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239530"))) PPC_WEAK_FUNC(sub_82239530);
PPC_FUNC_IMPL(__imp__sub_82239530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,128(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// rlwinm r5,r11,8,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r4,r11,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r3,r11,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfs f0,15364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// std r4,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r4.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lfd f12,-8(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// std r3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r3.u64);
	// std r10,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r10.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lfd f10,-8(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,12(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,0(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,4(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,8(r7)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822395B0"))) PPC_WEAK_FUNC(sub_822395B0);
PPC_FUNC_IMPL(__imp__sub_822395B0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,124(r4)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r4.u32 + 124);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822395B8"))) PPC_WEAK_FUNC(sub_822395B8);
PPC_FUNC_IMPL(__imp__sub_822395B8) {
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
	ctx.lr = 0x822395C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-28844
	ctx.r10.s64 = r11.s64 + -28844;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x82239608
	if (cr6.eq) goto loc_82239608;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82239608:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-32560
	ctx.r8.s64 = ctx.r10.s64 + -32560;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239628"))) PPC_WEAK_FUNC(sub_82239628);
PPC_FUNC_IMPL(__imp__sub_82239628) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223963c
	if (cr6.eq) goto loc_8223963C;
	// addi r3,r6,800
	ctx.r3.s64 = ctx.r6.s64 + 800;
	// blr 
	return;
loc_8223963C:
	// lwz r11,120(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82239650
	if (cr6.eq) goto loc_82239650;
	// addi r3,r11,96
	ctx.r3.s64 = r11.s64 + 96;
	// blr 
	return;
loc_82239650:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-16512
	ctx.r3.s64 = r11.s64 + -16512;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223965C"))) PPC_WEAK_FUNC(sub_8223965C);
PPC_FUNC_IMPL(__imp__sub_8223965C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239660"))) PPC_WEAK_FUNC(sub_82239660);
PPC_FUNC_IMPL(__imp__sub_82239660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-28764
	ctx.r5.s64 = ctx.r10.s64 + -28764;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r11,12
	ctx.r6.s64 = r11.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x824df200
	sub_824DF200(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82239684"))) PPC_WEAK_FUNC(sub_82239684);
PPC_FUNC_IMPL(__imp__sub_82239684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239688"))) PPC_WEAK_FUNC(sub_82239688);
PPC_FUNC_IMPL(__imp__sub_82239688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,752
	r11.s64 = 752;
	// lvx128 v63,r5,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82239698"))) PPC_WEAK_FUNC(sub_82239698);
PPC_FUNC_IMPL(__imp__sub_82239698) {
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
	// bl 0x82202e38
	ctx.lr = 0x822396B4;
	sub_82202E38(ctx, base);
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

__attribute__((alias("__imp__sub_82239770"))) PPC_WEAK_FUNC(sub_82239770);
PPC_FUNC_IMPL(__imp__sub_82239770) {
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
	ctx.lr = 0x82239778;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r31,40
	r31.s64 = 40;
	// addi r10,r11,-28804
	ctx.r10.s64 = r11.s64 + -28804;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// beq cr6,0x822397c4
	if (cr6.eq) goto loc_822397C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822397C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822397C4:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// bl 0x822395b8
	ctx.lr = 0x822397D8;
	sub_822395B8(ctx, base);
	// clrlwi r10,r28,31
	ctx.r10.u64 = r28.u32 & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822397f0
	if (cr6.eq) goto loc_822397F0;
	// bl 0x82130588
	ctx.lr = 0x822397EC;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822397F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822397F8"))) PPC_WEAK_FUNC(sub_822397F8);
PPC_FUNC_IMPL(__imp__sub_822397F8) {
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
	ctx.lr = 0x82239800;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r31,40
	r31.s64 = 40;
	// addi r10,r11,-28736
	ctx.r10.s64 = r11.s64 + -28736;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// beq cr6,0x82239848
	if (cr6.eq) goto loc_82239848;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82239848:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// bl 0x82239498
	ctx.lr = 0x8223985C;
	sub_82239498(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239864"))) PPC_WEAK_FUNC(sub_82239864);
PPC_FUNC_IMPL(__imp__sub_82239864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239868"))) PPC_WEAK_FUNC(sub_82239868);
PPC_FUNC_IMPL(__imp__sub_82239868) {
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
	ctx.lr = 0x82239870;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-28700
	ctx.r10.s64 = r11.s64 + -28700;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,20(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// beq cr6,0x822398b8
	if (cr6.eq) goto loc_822398B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822398B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822398B8:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r8,r10,-28736
	ctx.r8.s64 = ctx.r10.s64 + -28736;
	// stwx r9,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r9.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stwx r7,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, ctx.r7.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822398fc
	if (cr6.eq) goto loc_822398FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822398FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822398FC:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// bl 0x82239498
	ctx.lr = 0x82239910;
	sub_82239498(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82239918"))) PPC_WEAK_FUNC(sub_82239918);
PPC_FUNC_IMPL(__imp__sub_82239918) {
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
	// bl 0x82238f00
	ctx.lr = 0x82239938;
	sub_82238F00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82239950
	if (cr6.eq) goto loc_82239950;
	// bl 0x82130588
	ctx.lr = 0x8223994C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82239950:
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

__attribute__((alias("__imp__sub_82239968"))) PPC_WEAK_FUNC(sub_82239968);
PPC_FUNC_IMPL(__imp__sub_82239968) {
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
	// bl 0x823d91f4
	ctx.lr = 0x82239970;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r10,976
	ctx.r10.s64 = 976;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v61,r4,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v60,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lbzx r10,r8,r9
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f1,148(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82239a1c
	if (cr6.eq) goto loc_82239A1C;
	// lfs f0,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r3,420(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 420);
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r9,172(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x82239A14;
	sub_82723940(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82239A1C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lfs f0,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// li r30,16
	r30.s64 = 16;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// li r29,32
	r29.s64 = 32;
	// li r28,48
	r28.s64 = 48;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r27,r10,1
	r27.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r27,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r27.u32);
	// li r8,80
	ctx.r8.s64 = 80;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r4,420(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 420);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r31
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82239ABC"))) PPC_WEAK_FUNC(sub_82239ABC);
PPC_FUNC_IMPL(__imp__sub_82239ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82239AC0"))) PPC_WEAK_FUNC(sub_82239AC0);
PPC_FUNC_IMPL(__imp__sub_82239AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// lwz r11,160(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 160);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x82239b64
	if (cr6.gt) goto loc_82239B64;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-25856
	r12.s64 = r12.s64 + -25856;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82239B1C;
	case 1:
		goto loc_82239B64;
	case 2:
		goto loc_82239B64;
	case 3:
		goto loc_82239B1C;
	case 4:
		goto loc_82239B1C;
	case 5:
		goto loc_82239B1C;
	case 6:
		goto loc_82239B1C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25828(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25828);
	// lwz r17,-25756(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25756);
	// lwz r17,-25756(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25756);
	// lwz r17,-25828(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25828);
	// lwz r17,-25828(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25828);
	// lwz r17,-25828(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25828);
	// lwz r17,-25828(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25828);
loc_82239B1C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,468(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 468);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// lfs f0,-26872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26872);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82239B34;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,-28668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28668);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// fmadds f9,f10,f13,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f9,16(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// b 0x82239b68
	goto loc_82239B68;
loc_82239B64:
	// addi r3,r6,704
	ctx.r3.s64 = ctx.r6.s64 + 704;
loc_82239B68:
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

__attribute__((alias("__imp__sub_82239B80"))) PPC_WEAK_FUNC(sub_82239B80);
PPC_FUNC_IMPL(__imp__sub_82239B80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	// lbz r11,41(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 41);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82239d18
	if (cr6.eq) goto loc_82239D18;
	// lwz r11,156(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 156);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82239d18
	if (cr6.gt) goto loc_82239D18;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-25672
	r12.s64 = r12.s64 + -25672;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82239BDC;
	case 1:
		goto loc_82239D18;
	case 2:
		goto loc_82239D18;
	case 3:
		goto loc_82239CB0;
	case 4:
		goto loc_82239BDC;
	case 5:
		goto loc_82239C4C;
	case 6:
		goto loc_82239CB0;
	case 7:
		goto loc_82239CB0;
	case 8:
		goto loc_82239CB0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25636(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25636);
	// lwz r17,-25320(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25320);
	// lwz r17,-25320(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25320);
	// lwz r17,-25424(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25424);
	// lwz r17,-25636(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25636);
	// lwz r17,-25524(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25524);
	// lwz r17,-25424(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25424);
	// lwz r17,-25424(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25424);
	// lwz r17,-25424(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25424);
loc_82239BDC:
	// lis r11,10922
	r11.s64 = 715784192;
	// lwz r9,452(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 452);
	// ori r8,r11,43691
	ctx.r8.u64 = r11.u64 | 43691;
	// mulhw r11,r9,r8
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r5,r9
	r11.s64 = ctx.r9.s64 - ctx.r5.s64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82239c40
	if (cr6.gt) goto loc_82239C40;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-25564
	r12.s64 = r12.s64 + -25564;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82239C38;
	case 1:
		goto loc_82239C38;
	case 2:
		goto loc_82239C38;
	case 3:
		goto loc_82239C40;
	case 4:
		goto loc_82239C40;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25544(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25544);
	// lwz r17,-25544(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25544);
	// lwz r17,-25544(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25544);
	// lwz r17,-25536(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25536);
	// lwz r17,-25536(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25536);
loc_82239C38:
	// addi r3,r6,720
	ctx.r3.s64 = ctx.r6.s64 + 720;
	// blr 
	return;
loc_82239C40:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-16496
	ctx.r3.s64 = r11.s64 + -16496;
	// blr 
	return;
loc_82239C4C:
	// lis r11,10922
	r11.s64 = 715784192;
	// lwz r9,452(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 452);
	// ori r8,r11,43691
	ctx.r8.u64 = r11.u64 | 43691;
	// mulhw r11,r9,r8
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r5,r9
	r11.s64 = ctx.r9.s64 - ctx.r5.s64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82239c40
	if (cr6.gt) goto loc_82239C40;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-25452
	r12.s64 = r12.s64 + -25452;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82239CA8;
	case 1:
		goto loc_82239CA8;
	case 2:
		goto loc_82239CA8;
	case 3:
		goto loc_82239C40;
	case 4:
		goto loc_82239C40;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25432(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25432);
	// lwz r17,-25432(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25432);
	// lwz r17,-25432(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25432);
	// lwz r17,-25536(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25536);
	// lwz r17,-25536(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25536);
loc_82239CA8:
	// addi r3,r6,704
	ctx.r3.s64 = ctx.r6.s64 + 704;
	// blr 
	return;
loc_82239CB0:
	// lis r10,10922
	ctx.r10.s64 = 715784192;
	// lwz r11,452(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 452);
	// ori r9,r10,43691
	ctx.r9.u64 = ctx.r10.u64 | 43691;
	// mulhw r10,r11,r9
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(ctx.r9.s32)) >> 32;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82239c40
	if (cr6.gt) goto loc_82239C40;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-25352
	r12.s64 = r12.s64 + -25352;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82239C38;
	case 1:
		goto loc_82239D0C;
	case 2:
		goto loc_82239C40;
	case 3:
		goto loc_82239CA8;
	case 4:
		goto loc_82239D0C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-25544(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25544);
	// lwz r17,-25332(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25332);
	// lwz r17,-25536(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25536);
	// lwz r17,-25432(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25432);
	// lwz r17,-25332(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25332);
loc_82239D0C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-16512
	ctx.r3.s64 = r11.s64 + -16512;
	// blr 
	return;
loc_82239D18:
	// addi r3,r6,688
	ctx.r3.s64 = ctx.r6.s64 + 688;
}

__attribute__((alias("__imp__sub_82239D20"))) PPC_WEAK_FUNC(sub_82239D20);
PPC_FUNC_IMPL(__imp__sub_82239D20) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82239D28;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82239d6c
	if (cr6.eq) goto loc_82239D6C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223a150
	if (!cr6.eq) goto loc_8223A150;
loc_82239D6C:
	// lwz r3,120(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 120);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223a150
	if (cr6.eq) goto loc_8223A150;
	// lbz r11,38(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82239d8c
	if (!cr6.eq) goto loc_82239D8C;
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// b 0x82239dc4
	goto loc_82239DC4;
loc_82239D8C:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82239dbc
	if (cr6.eq) goto loc_82239DBC;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82239db4
	if (cr6.eq) goto loc_82239DB4;
	// addi r30,r11,208
	r30.s64 = r11.s64 + 208;
	// b 0x82239dc4
	goto loc_82239DC4;
loc_82239DB4:
	// addi r30,r11,144
	r30.s64 = r11.s64 + 144;
	// b 0x82239dc4
	goto loc_82239DC4;
loc_82239DBC:
	// bl 0x822a8108
	ctx.lr = 0x82239DC0;
	sub_822A8108(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82239DC4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238f88
	ctx.lr = 0x82239DCC;
	sub_82238F88(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lfs f13,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,240(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239E00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82239e20
	if (cr6.eq) goto loc_82239E20;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10220(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x82239E18;
	sub_82620070(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// b 0x82239e24
	goto loc_82239E24;
loc_82239E20:
	// lfs f30,144(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 144);
	f30.f64 = double(temp.f32);
loc_82239E24:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f30.f64));
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x82214d90
	ctx.lr = 0x82239E78;
	sub_82214D90(ctx, base);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lfs f13,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,180(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * f30.f64));
	// stfs f31,184(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lbz r7,153(r28)
	ctx.r7.u64 = PPC_LOAD_U8(r28.u32 + 153);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stfs f31,192(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stfs f31,200(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfs f31,208(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stfs f31,212(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82239EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82239F04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82239f68
	if (cr6.eq) goto loc_82239F68;
	// lbz r11,168(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82239f68
	if (cr6.eq) goto loc_82239F68;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82238d68
	ctx.lr = 0x82239F2C;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82239f68
	if (!cr6.eq) goto loc_82239F68;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,124(r26)
	ctx.r8.u64 = PPC_LOAD_U8(r26.u32 + 124);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x82239F58;
	sub_82235280(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82239F68:
	// lwz r3,424(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,97
	ctx.r6.s64 = ctx.r1.s64 + 97;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82239F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223a150
	if (cr6.eq) goto loc_8223A150;
	// li r11,976
	r11.s64 = 976;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r7,72
	ctx.r7.s64 = 72;
	// lfs f12,228(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,124(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 124);
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lbzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// stfs f11,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f10,228(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8223a050
	if (cr6.eq) goto loc_8223A050;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a018
	if (cr6.eq) goto loc_8223A018;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223A018;
	sub_82723940(ctx, base);
loc_8223A018:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,424(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223A040;
	sub_82723940(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_8223A050:
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// li r7,80
	ctx.r7.s64 = 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a0e0
	if (cr6.eq) goto loc_8223A0E0;
	// lwz r11,-17936(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17936);
	// addi r29,r1,176
	r29.s64 = ctx.r1.s64 + 176;
	// addi r28,r1,192
	r28.s64 = ctx.r1.s64 + 192;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r27,r1,208
	r27.s64 = ctx.r1.s64 + 208;
	// addi r26,r1,224
	r26.s64 = ctx.r1.s64 + 224;
	// addi r25,r1,256
	r25.s64 = ctx.r1.s64 + 256;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r10,1
	r24.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stw r24,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r24.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r26
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r25
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A0E0:
	// lwz r11,-17936(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17936);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
	// addi r27,r1,160
	r27.s64 = ctx.r1.s64 + 160;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r26,r10,1
	r26.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r26,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r26.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,424(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r29
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r28
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r27
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A150:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8223A160"))) PPC_WEAK_FUNC(sub_8223A160);
PPC_FUNC_IMPL(__imp__sub_8223A160) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,41(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 41);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223a178
	if (cr6.eq) goto loc_8223A178;
	// addi r3,r6,944
	ctx.r3.s64 = ctx.r6.s64 + 944;
	// blr 
	return;
loc_8223A178:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// addi r3,r6,960
	ctx.r3.s64 = ctx.r6.s64 + 960;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r6,800
	ctx.r3.s64 = ctx.r6.s64 + 800;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223A190"))) PPC_WEAK_FUNC(sub_8223A190);
PPC_FUNC_IMPL(__imp__sub_8223A190) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28632
	ctx.r7.s64 = ctx.r9.s64 + -28632;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28648
	ctx.r3.s64 = ctx.r8.s64 + -28648;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223A1D4;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28664
	ctx.r3.s64 = ctx.r6.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223A1E4;
	sub_82723808(ctx, base);
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

__attribute__((alias("__imp__sub_8223A200"))) PPC_WEAK_FUNC(sub_8223A200);
PPC_FUNC_IMPL(__imp__sub_8223A200) {
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
	ctx.lr = 0x8223A208;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r31,40
	r31.s64 = 40;
	// addi r10,r11,-28804
	ctx.r10.s64 = r11.s64 + -28804;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// beq cr6,0x8223a250
	if (cr6.eq) goto loc_8223A250;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223A250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223A250:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// bl 0x822395b8
	ctx.lr = 0x8223A264;
	sub_822395B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223A26C"))) PPC_WEAK_FUNC(sub_8223A26C);
PPC_FUNC_IMPL(__imp__sub_8223A26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223A270"))) PPC_WEAK_FUNC(sub_8223A270);
PPC_FUNC_IMPL(__imp__sub_8223A270) {
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
	// bl 0x822392b0
	ctx.lr = 0x8223A290;
	sub_822392B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a2a8
	if (cr6.eq) goto loc_8223A2A8;
	// bl 0x82130588
	ctx.lr = 0x8223A2A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223A2A8:
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

__attribute__((alias("__imp__sub_8223A2C0"))) PPC_WEAK_FUNC(sub_8223A2C0);
PPC_FUNC_IMPL(__imp__sub_8223A2C0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	// bl 0x823d91dc
	ctx.lr = 0x8223A2C8;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lbz r27,36(r29)
	r27.u64 = PPC_LOAD_U8(r29.u32 + 36);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// bne cr6,0x8223a300
	if (!cr6.eq) goto loc_8223A300;
	// lwz r26,8(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// b 0x8223a304
	goto loc_8223A304;
loc_8223A300:
	// lwz r26,12(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 12);
loc_8223A304:
	// lbz r11,41(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 41);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// beq cr6,0x8223a328
	if (cr6.eq) goto loc_8223A328;
	// li r11,944
	r11.s64 = 944;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a350
	goto loc_8223A350;
loc_8223A328:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a344
	if (cr6.eq) goto loc_8223A344;
	// li r11,960
	r11.s64 = 960;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a350
	goto loc_8223A350;
loc_8223A344:
	// li r11,928
	r11.s64 = 928;
	// lvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A350:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223A368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223a388
	if (cr6.eq) goto loc_8223A388;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223A380;
	sub_82620070(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// b 0x8223a38c
	goto loc_8223A38C;
loc_8223A388:
	// lfs f31,144(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 144);
	f31.f64 = double(temp.f32);
loc_8223A38C:
	// lbz r11,41(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 41);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223a40c
	if (cr6.eq) goto loc_8223A40C;
	// lfs f1,464(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 464);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dbae8
	ctx.lr = 0x8223A3A4;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 540);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r11,-16512
	ctx.r9.s64 = r11.s64 + -16512;
	// lfs f9,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f8,536(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 536);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fabs f7,f13
	ctx.f7.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fmuls f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f7.f64));
	// fmadds f5,f8,f7,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + f0.f64));
	// fadds f4,f11,f6
	ctx.f4.f64 = double(float(ctx.f11.f64 + ctx.f6.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f3,f10,f6
	ctx.f3.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// stfs f3,116(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f2,f9,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 + ctx.f6.f64));
	// stfs f2,120(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vminfp128 v59,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_min_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// fmuls f31,f5,f31
	ctx.fpscr.disableFlushModeUnconditional();
	f31.f64 = double(float(ctx.f5.f64 * f31.f64));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A40C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,580(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 580);
	f0.f64 = double(temp.f32);
	// li r10,16
	ctx.r10.s64 = 16;
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// addi r9,r11,-31280
	ctx.r9.s64 = r11.s64 + -31280;
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r7,48
	ctx.r7.s64 = 48;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r9,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r9,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,16
	r28.s64 = 16;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8223a480
	if (!cr6.eq) goto loc_8223A480;
	// lvx128 v58,r30,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// vaddfp128 v62,v62,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A480:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lfs f1,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v57,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v56,v60,v63
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v55,v59,v63
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v54,v62,v63
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82239698
	ctx.lr = 0x8223A4C4;
	sub_82239698(ctx, base);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r27,r29,80
	r27.s64 = r29.s64 + 80;
	// lbz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U8(r29.u32 + 124);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r27
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v51,v53,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v51,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223a51c
	if (cr6.eq) goto loc_8223A51C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,27640(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223A508;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_8223A51C:
	// lbz r11,168(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a554
	if (cr6.eq) goto loc_8223A554;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223A54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223a650
	if (cr6.eq) goto loc_8223A650;
loc_8223A554:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223a5a8
	if (cr6.eq) goto loc_8223A5A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r9,172(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f1,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82723940
	ctx.lr = 0x8223A5A4;
	sub_82723940(ctx, base);
	// b 0x8223a628
	goto loc_8223A628;
loc_8223A5A8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// li r30,32
	r30.s64 = 32;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r25,48
	r25.s64 = 48;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// li r23,80
	r23.s64 = 80;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r21,r10,1
	r21.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r21,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r21.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r26,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r26.u32);
	// lvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r4
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r10,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A628:
	// lbz r11,168(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a670
	if (cr6.eq) goto loc_8223A670;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82238d68
	ctx.lr = 0x8223A644;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a670
	if (!cr6.eq) goto loc_8223A670;
loc_8223A650:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lbz r9,36(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 36);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lbz r8,124(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 124);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223A670;
	sub_82235280(ctx, base);
loc_8223A670:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8223A67C"))) PPC_WEAK_FUNC(sub_8223A67C);
PPC_FUNC_IMPL(__imp__sub_8223A67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223A680"))) PPC_WEAK_FUNC(sub_8223A680);
PPC_FUNC_IMPL(__imp__sub_8223A680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// bl 0x823d91dc
	ctx.lr = 0x8223A688;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9d0
	ctx.lr = 0x8223A690;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lbz r11,38(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 38);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lfs f31,148(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 148);
	f31.f64 = double(temp.f32);
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// li r25,0
	r25.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8223a890
	if (cr6.gt) goto loc_8223A890;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-22800
	r12.s64 = r12.s64 + -22800;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8223A708;
	case 1:
		goto loc_8223A750;
	case 2:
		goto loc_8223A780;
	case 3:
		goto loc_8223A794;
	case 4:
		goto loc_8223A7E4;
	case 5:
		goto loc_8223A82C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-22776(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22776);
	// lwz r17,-22704(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22704);
	// lwz r17,-22656(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22656);
	// lwz r17,-22636(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22636);
	// lwz r17,-22556(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22556);
	// lwz r17,-22484(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -22484);
loc_8223A708:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a728
	if (cr6.eq) goto loc_8223A728;
	// li r7,912
	ctx.r7.s64 = 912;
	// lvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a734
	goto loc_8223A734;
loc_8223A728:
	// li r7,832
	ctx.r7.s64 = 832;
	// lvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223A734:
	// lbz r7,474(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 474);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223a860
	if (cr6.eq) goto loc_8223A860;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a860
	if (!cr6.eq) goto loc_8223A860;
	// li r25,1
	r25.s64 = 1;
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A750:
	// li r11,832
	r11.s64 = 832;
	// lbz r7,474(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 474);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223a860
	if (cr6.eq) goto loc_8223A860;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a860
	if (!cr6.eq) goto loc_8223A860;
	// li r25,1
	r25.s64 = 1;
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A780:
	// li r11,848
	r11.s64 = 848;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A794:
	// lbz r11,41(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 41);
	// rlwinm r7,r11,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// beq cr6,0x8223a7b8
	if (cr6.eq) goto loc_8223A7B8;
	// li r11,944
	r11.s64 = 944;
	// lvx128 v59,r31,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A7B8:
	// rlwinm r11,r11,0,24,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a7d4
	if (cr6.eq) goto loc_8223A7D4;
	// li r11,960
	r11.s64 = 960;
	// lvx128 v58,r31,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A7D4:
	// li r11,864
	r11.s64 = 864;
	// lvx128 v57,r31,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A7E4:
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8223a818
	if (!cr6.eq) goto loc_8223A818;
	// lbz r11,474(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 474);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a814
	if (cr6.eq) goto loc_8223A814;
	// li r11,880
	r11.s64 = 880;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r25,1
	r25.s64 = 1;
	// lvx128 v56,r31,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A814:
	// li r9,1
	ctx.r9.s64 = 1;
loc_8223A818:
	// li r11,880
	r11.s64 = 880;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v56,r31,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A82C:
	// li r11,896
	r11.s64 = 896;
	// lwz r7,164(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lvx128 v55,r31,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8223a874
	if (!cr6.eq) goto loc_8223A874;
	// lbz r11,473(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 473);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a868
	if (!cr6.eq) goto loc_8223A868;
	// lbz r11,474(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 474);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a868
	if (!cr6.eq) goto loc_8223A868;
loc_8223A860:
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A868:
	// li r25,1
	r25.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8223a890
	goto loc_8223A890;
loc_8223A874:
	// lwz r11,176(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8223a890
	if (!cr6.eq) goto loc_8223A890;
	// lbz r11,508(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223a890
	if (!cr6.eq) goto loc_8223A890;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8223A890:
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r11,-5052(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5052);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223a8a8
	if (cr6.eq) goto loc_8223A8A8;
	// lbz r23,124(r26)
	r23.u64 = PPC_LOAD_U8(r26.u32 + 124);
	// b 0x8223a8b8
	goto loc_8223A8B8;
loc_8223A8A8:
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x8223a8b8
	if (!cr6.lt) goto loc_8223A8B8;
	// li r23,1
	r23.s64 = 1;
loc_8223A8B8:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = f31.f64;
	// clrlwi r5,r10,24
	ctx.r5.u64 = ctx.r10.u32 & 0xFF;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfs f28,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f28.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f30,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// fmr f29,f28
	f29.f64 = f28.f64;
	// addi r29,r10,-16512
	r29.s64 = ctx.r10.s64 + -16512;
	// stw r11,164(r28)
	PPC_STORE_U32(r28.u32 + 164, r11.u32);
	// beq cr6,0x8223a928
	if (cr6.eq) goto loc_8223A928;
	// lfs f0,512(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	f0.f64 = double(temp.f32);
	// lfs f13,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223A904;
	sub_823DBAE8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f10,f12,f30
	ctx.f10.f64 = double(float(ctx.f12.f64 + f30.f64));
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f8,124(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// b 0x8223aa2c
	goto loc_8223AA2C;
loc_8223A928:
	// lbz r10,500(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 500);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223a940
	if (!cr6.eq) goto loc_8223A940;
	// lwz r10,176(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8223a98c
	if (cr6.eq) goto loc_8223A98C;
loc_8223A940:
	// lbz r10,508(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 508);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223a98c
	if (cr6.eq) goto loc_8223A98C;
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223a98c
	if (cr6.eq) goto loc_8223A98C;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f0,460(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 460);
	f0.f64 = double(temp.f32);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fabs f29,f10
	f29.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f29,f30
	cr6.compare(f29.f64, f30.f64);
	// bge cr6,0x8223aa2c
	if (!cr6.lt) goto loc_8223AA2C;
	// fsubs f29,f30,f29
	f29.f64 = double(float(f30.f64 - f29.f64));
	// li r30,1
	r30.s64 = 1;
	// b 0x8223aa2c
	goto loc_8223AA2C;
loc_8223A98C:
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223aa2c
	if (cr6.eq) goto loc_8223AA2C;
	// lwz r11,176(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8223aa2c
	if (!cr6.eq) goto loc_8223AA2C;
	// lfs f0,512(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 512);
	f0.f64 = double(temp.f32);
	// lfs f13,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223A9B4;
	sub_823DBAE8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f2,524(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 524);
	ctx.f2.f64 = double(temp.f32);
	// fabs f26,f12
	f26.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// bl 0x823dc480
	ctx.lr = 0x8223A9C8;
	sub_823DC480(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,516(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 516);
	ctx.f10.f64 = double(temp.f32);
	// lfs f2,528(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 528);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// fmadds f9,f10,f11,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f30.f64));
	// fmuls f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 * f31.f64));
	// bl 0x823dc480
	ctx.lr = 0x8223A9E4;
	sub_823DC480(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// lfs f7,520(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 520);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f6,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f4,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f4.f64 = double(temp.f32);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f7,f8
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fadds f2,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f3.f64));
	// stfs f2,112(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f1,f5,f3
	ctx.f1.f64 = double(float(ctx.f5.f64 + ctx.f3.f64));
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f0,f4,f3
	f0.f64 = double(float(ctx.f4.f64 + ctx.f3.f64));
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vminfp128 v53,v54,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_min_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223AA2C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223aaac
	if (cr6.eq) goto loc_8223AAAC;
	// lfs f2,488(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 488);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dc480
	ctx.lr = 0x8223AA44;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,484(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 484);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f2,496(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 496);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f29,f13,f0
	f29.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dc480
	ctx.lr = 0x8223AA5C;
	sub_823DC480(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,492(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 492);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f10,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f29,f30
	ctx.f7.f64 = double(float(f29.f64 + f30.f64));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f6,f11,f12
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fmuls f31,f7,f31
	f31.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fadds f5,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 + ctx.f6.f64));
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fadds f4,f9,f6
	ctx.f4.f64 = double(float(ctx.f9.f64 + ctx.f6.f64));
	// stfs f4,116(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f3,f8,f6
	ctx.f3.f64 = double(float(ctx.f8.f64 + ctx.f6.f64));
	// stfs f3,120(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vminfp128 v51,v52,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_min_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223AAAC:
	// lbz r11,38(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 38);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223aac0
	if (!cr6.eq) goto loc_8223AAC0;
	// lfs f0,588(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 588);
	f0.f64 = double(temp.f32);
	// b 0x8223aac4
	goto loc_8223AAC4;
loc_8223AAC0:
	// lfs f0,584(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 584);
	f0.f64 = double(temp.f32);
loc_8223AAC4:
	// lwz r11,176(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// fmuls f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f31.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bne cr6,0x8223aafc
	if (!cr6.eq) goto loc_8223AAFC;
	// lwz r11,164(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 164);
	// lwz r10,504(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 504);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8223aafc
	if (!cr6.gt) goto loc_8223AAFC;
	// lbz r11,472(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 472);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223ac5c
	if (cr6.eq) goto loc_8223AC5C;
loc_8223AAFC:
	// lwz r11,-5052(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5052);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223ab4c
	if (cr6.eq) goto loc_8223AB4C;
	// lbz r10,124(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 124);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ab4c
	if (cr6.eq) goto loc_8223AB4C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,27640(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223AB34;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-5052(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5052);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_8223AB4C:
	// li r10,80
	ctx.r10.s64 = 80;
	// lbz r9,152(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 152);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v50,r26,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223ab70
	if (cr6.eq) goto loc_8223AB70;
	// stfs f28,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// b 0x8223ab7c
	goto loc_8223AB7C;
loc_8223AB70:
	// lfs f0,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_8223AB7C:
	// lbz r10,544(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 544);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223abbc
	if (!cr6.eq) goto loc_8223ABBC;
	// clrlwi r10,r23,24
	ctx.r10.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223abbc
	if (!cr6.eq) goto loc_8223ABBC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223abbc
	if (!cr6.eq) goto loc_8223ABBC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223ABBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223ABBC:
	// clrlwi r30,r25,24
	r30.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8223abe8
	if (cr6.eq) goto loc_8223ABE8;
	// lfs f0,592(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 592);
	f0.f64 = double(temp.f32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// fmuls f1,f0,f27
	ctx.f1.f64 = double(float(f0.f64 * f27.f64));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82239968
	ctx.lr = 0x8223ABE8;
	sub_82239968(ctx, base);
loc_8223ABE8:
	// addi r10,r28,16
	ctx.r10.s64 = r28.s64 + 16;
	// lwz r5,8(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r26,96
	ctx.r7.s64 = r26.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822363f0
	ctx.lr = 0x8223AC0C;
	sub_822363F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223ac5c
	if (!cr6.eq) goto loc_8223AC5C;
	// lbz r11,168(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223ac5c
	if (cr6.eq) goto loc_8223AC5C;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223ac3c
	if (!cr6.eq) goto loc_8223AC3C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// beq cr6,0x8223ac40
	if (cr6.eq) goto loc_8223AC40;
loc_8223AC3C:
	// li r8,1
	ctx.r8.s64 = 1;
loc_8223AC40:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lbz r9,36(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 36);
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223AC5C;
	sub_82235280(ctx, base);
loc_8223AC5C:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba1c
	ctx.lr = 0x8223AC68;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8223AC6C"))) PPC_WEAK_FUNC(sub_8223AC6C);
PPC_FUNC_IMPL(__imp__sub_8223AC6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223AC70"))) PPC_WEAK_FUNC(sub_8223AC70);
PPC_FUNC_IMPL(__imp__sub_8223AC70) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28588
	ctx.r7.s64 = ctx.r9.s64 + -28588;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28664
	ctx.r3.s64 = ctx.r8.s64 + -28664;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223ACB4;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223ACD0"))) PPC_WEAK_FUNC(sub_8223ACD0);
PPC_FUNC_IMPL(__imp__sub_8223ACD0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28536
	ctx.r7.s64 = ctx.r9.s64 + -28536;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28556
	ctx.r3.s64 = ctx.r8.s64 + -28556;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223AD14;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28664
	ctx.r3.s64 = ctx.r6.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223AD24;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223AD40"))) PPC_WEAK_FUNC(sub_8223AD40);
PPC_FUNC_IMPL(__imp__sub_8223AD40) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28500
	ctx.r7.s64 = ctx.r9.s64 + -28500;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28648
	ctx.r3.s64 = ctx.r8.s64 + -28648;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223AD84;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28664
	ctx.r3.s64 = ctx.r6.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223AD94;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223ADB0"))) PPC_WEAK_FUNC(sub_8223ADB0);
PPC_FUNC_IMPL(__imp__sub_8223ADB0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8223ADB8;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223adfc
	if (cr6.eq) goto loc_8223ADFC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223b084
	if (!cr6.eq) goto loc_8223B084;
loc_8223ADFC:
	// lbz r11,153(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223ae50
	if (!cr6.eq) goto loc_8223AE50;
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223ae1c
	if (cr6.gt) goto loc_8223AE1C;
	// li r11,0
	r11.s64 = 0;
loc_8223AE1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223ae50
	if (cr6.eq) goto loc_8223AE50;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223AE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8223b084
	if (!cr6.eq) goto loc_8223B084;
loc_8223AE50:
	// li r24,80
	r24.s64 = 80;
	// lbz r11,152(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 152);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r25,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x8223ae78
	if (cr6.eq) goto loc_8223AE78;
	// stfs f30,132(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_8223AE78:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r29,r30,768
	r29.s64 = r30.s64 + 768;
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223AE94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223aeb4
	if (cr6.eq) goto loc_8223AEB4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223AEAC;
	sub_82620070(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// b 0x8223aeb8
	goto loc_8223AEB8;
loc_8223AEB4:
	// lfs f31,144(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 144);
	f31.f64 = double(temp.f32);
loc_8223AEB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223AECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// li r27,16
	r27.s64 = 16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r28,32
	r28.s64 = 32;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lbz r9,168(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223af84
	if (cr6.eq) goto loc_8223AF84;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223AF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223b084
	if (cr6.eq) goto loc_8223B084;
loc_8223AF84:
	// lbz r11,124(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223afb0
	if (cr6.eq) goto loc_8223AFB0;
	// lfs f0,596(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 596);
	f0.f64 = double(temp.f32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82239968
	ctx.lr = 0x8223AFB0;
	sub_82239968(ctx, base);
loc_8223AFB0:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223b00c
	if (cr6.eq) goto loc_8223B00C;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223AFFC;
	sub_82723940(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8223B00C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// li r3,48
	ctx.r3.s64 = 48;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r30,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r30.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r6
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r29
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223B084:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8223B094"))) PPC_WEAK_FUNC(sub_8223B094);
PPC_FUNC_IMPL(__imp__sub_8223B094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223B098"))) PPC_WEAK_FUNC(sub_8223B098);
PPC_FUNC_IMPL(__imp__sub_8223B098) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91cc
	ctx.lr = 0x8223B0A0;
	// stfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f30.u64);
	// stfd f31,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223b0e8
	if (cr6.eq) goto loc_8223B0E8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223b494
	if (!cr6.eq) goto loc_8223B494;
loc_8223B0E8:
	// lbz r6,153(r26)
	ctx.r6.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8223b114
	if (!cr6.eq) goto loc_8223B114;
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223b108
	if (cr6.gt) goto loc_8223B108;
	// li r11,0
	r11.s64 = 0;
loc_8223B108:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223b494
	if (!cr6.eq) goto loc_8223B494;
loc_8223B114:
	// li r27,80
	r27.s64 = 80;
	// lbz r11,152(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 152);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r25,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x8223b13c
	if (cr6.eq) goto loc_8223B13C;
	// stfs f30,132(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
loc_8223B13C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B15C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223B174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223b194
	if (cr6.eq) goto loc_8223B194;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223B18C;
	sub_82620070(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// b 0x8223b198
	goto loc_8223B198;
loc_8223B194:
	// lfs f31,144(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 144);
	f31.f64 = double(temp.f32);
loc_8223B198:
	// lbz r11,126(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 126);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b1e4
	if (cr6.eq) goto loc_8223B1E4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B1B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223B1CC;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f10,1008(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fmadds f9,f10,f11,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f0.f64));
	// fmuls f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 * f31.f64));
loc_8223B1E4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// li r28,16
	r28.s64 = 16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r29,32
	r29.s64 = 32;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lbz r9,168(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223b2b0
	if (cr6.eq) goto loc_8223B2B0;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B2A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223b474
	if (cr6.eq) goto loc_8223B474;
loc_8223B2B0:
	// lbz r11,124(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b2dc
	if (cr6.eq) goto loc_8223B2DC;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 * f31.f64));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82239968
	ctx.lr = 0x8223B2DC;
	sub_82239968(ctx, base);
loc_8223B2DC:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,212(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223b358
	if (cr6.eq) goto loc_8223B358;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223B328;
	sub_82723940(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// addi r6,r11,-16512
	ctx.r6.s64 = r11.s64 + -16512;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223B354;
	sub_82723940(ctx, base);
	// b 0x8223b44c
	goto loc_8223B44C;
loc_8223B358:
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r24,r1,208
	r24.s64 = ctx.r1.s64 + 208;
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// addi r22,r1,112
	r22.s64 = ctx.r1.s64 + 112;
	// addi r21,r1,160
	r21.s64 = ctx.r1.s64 + 160;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r20,r1,176
	r20.s64 = ctx.r1.s64 + 176;
	// addi r19,r1,192
	r19.s64 = ctx.r1.s64 + 192;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// addi r18,r1,208
	r18.s64 = ctx.r1.s64 + 208;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r7,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r7.u32);
	// li r7,48
	ctx.r7.s64 = 48;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r8,416(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// addi r17,r9,-16512
	r17.s64 = ctx.r9.s64 + -16512;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r24
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r22
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// stw r6,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r6.u32);
	// rlwinm r11,r5,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// lvx128 v50,r0,r21
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r20
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r19
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r18
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223B44C:
	// lbz r11,168(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b494
	if (cr6.eq) goto loc_8223B494;
	// addi r4,r26,16
	ctx.r4.s64 = r26.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82238d68
	ctx.lr = 0x8223B468;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223b494
	if (!cr6.eq) goto loc_8223B494;
loc_8223B474:
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lbz r9,36(r25)
	ctx.r9.u64 = PPC_LOAD_U8(r25.u32 + 36);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// lbz r8,124(r25)
	ctx.r8.u64 = PPC_LOAD_U8(r25.u32 + 124);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223B494;
	sub_82235280(ctx, base);
loc_8223B494:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8223B4A4"))) PPC_WEAK_FUNC(sub_8223B4A4);
PPC_FUNC_IMPL(__imp__sub_8223B4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223B4A8"))) PPC_WEAK_FUNC(sub_8223B4A8);
PPC_FUNC_IMPL(__imp__sub_8223B4A8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-28448
	ctx.r8.s64 = ctx.r10.s64 + -28448;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r3,r9,-28468
	ctx.r3.s64 = ctx.r9.s64 + -28468;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82723808
	ctx.lr = 0x8223B4E0;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223B4FC"))) PPC_WEAK_FUNC(sub_8223B4FC);
PPC_FUNC_IMPL(__imp__sub_8223B4FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223B500"))) PPC_WEAK_FUNC(sub_8223B500);
PPC_FUNC_IMPL(__imp__sub_8223B500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,128(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r7,r10,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// rlwinm r6,r10,16,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r7.u64);
	// std r6,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r6.u64);
	// lfd f12,-8(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r5,r10,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lfs f0,15364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	f0.f64 = double(temp.f32);
	// std r5,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r5.u64);
	// lfd f10,-8(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
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
	// stfs f1,20(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,16(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,28(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,24(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223B588"))) PPC_WEAK_FUNC(sub_8223B588);
PPC_FUNC_IMPL(__imp__sub_8223B588) {
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
	// bl 0x822395b8
	ctx.lr = 0x8223B5A8;
	sub_822395B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b5c0
	if (cr6.eq) goto loc_8223B5C0;
	// bl 0x82130588
	ctx.lr = 0x8223B5BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223B5C0:
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

__attribute__((alias("__imp__sub_8223B5D8"))) PPC_WEAK_FUNC(sub_8223B5D8);
PPC_FUNC_IMPL(__imp__sub_8223B5D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8223B5E0;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d8
	ctx.lr = 0x8223B5E8;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-496(r1)
	ea = -496 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lbz r11,153(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 153);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b65c
	if (cr6.eq) goto loc_8223B65C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223b65c
	if (cr6.eq) goto loc_8223B65C;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82239d20
	ctx.lr = 0x8223B658;
	sub_82239D20(ctx, base);
	// b 0x8223bbb8
	goto loc_8223BBB8;
loc_8223B65C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223b680
	if (cr6.eq) goto loc_8223B680;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223bbb8
	if (!cr6.eq) goto loc_8223BBB8;
loc_8223B680:
	// lbz r11,153(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223b6d4
	if (!cr6.eq) goto loc_8223B6D4;
	// lwz r11,156(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223b6a0
	if (cr6.gt) goto loc_8223B6A0;
	// li r11,0
	r11.s64 = 0;
loc_8223B6A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b6d4
	if (cr6.eq) goto loc_8223B6D4;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B6C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8223bbb8
	if (!cr6.eq) goto loc_8223BBB8;
loc_8223B6D4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r30,120(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 120);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lbz r7,153(r27)
	ctx.r7.u64 = PPC_LOAD_U8(r27.u32 + 153);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B6FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r26,80
	r26.s64 = 80;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8223b778
	if (cr6.eq) goto loc_8223B778;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8223b73c
	if (cr6.eq) goto loc_8223B73C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8223b734
	if (cr6.eq) goto loc_8223B734;
	// addi r30,r11,208
	r30.s64 = r11.s64 + 208;
	// b 0x8223b748
	goto loc_8223B748;
loc_8223B734:
	// addi r30,r11,144
	r30.s64 = r11.s64 + 144;
	// b 0x8223b748
	goto loc_8223B748;
loc_8223B73C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8223B744;
	sub_822A8108(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8223B748:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238f88
	ctx.lr = 0x8223B750;
	sub_82238F88(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lfs f13,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223b780
	goto loc_8223B780;
loc_8223B778:
	// lfs f29,100(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 100);
	f29.f64 = double(temp.f32);
	// lvx128 v127,r25,r26
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223B780:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223b7b8
	if (cr6.eq) goto loc_8223B7B8;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223B7B0;
	sub_82620070(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// b 0x8223b7bc
	goto loc_8223B7BC;
loc_8223B7B8:
	// lfs f30,144(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 144);
	f30.f64 = double(temp.f32);
loc_8223B7BC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,-16516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16516);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f28,f0,f30
	f28.f64 = double(float(f0.f64 * f30.f64));
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,160(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f28,128(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f28,148(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f28,168(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f0,-28412(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28412);
	f0.f64 = double(temp.f32);
	// fsubs f1,f29,f0
	ctx.f1.f64 = double(float(f29.f64 - f0.f64));
	// bl 0x82214d90
	ctx.lr = 0x8223B808;
	sub_82214D90(ctx, base);
	// addi r11,r27,80
	r11.s64 = r27.s64 + 80;
	// li r29,16
	r29.s64 = 16;
	// stfs f28,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r30,32
	r30.s64 = 32;
	// stfs f28,116(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f28,120(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// lfs f0,596(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// lvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r24,r1,288
	r24.s64 = ctx.r1.s64 + 288;
	// stfs f31,196(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r21,r1,176
	r21.s64 = ctx.r1.s64 + 176;
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// stfs f31,200(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stfs f31,208(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f31,216(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,224(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8223B8CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,168(r27)
	ctx.r6.u64 = PPC_LOAD_U8(r27.u32 + 168);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8223b91c
	if (cr6.eq) goto loc_8223B91C;
	// addi r4,r27,16
	ctx.r4.s64 = r27.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82238d68
	ctx.lr = 0x8223B8EC;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223b91c
	if (!cr6.eq) goto loc_8223B91C;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223B918;
	sub_82235280(ctx, base);
	// b 0x8223bbb8
	goto loc_8223BBB8;
loc_8223B91C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223B934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,412(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r11,60(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8223B960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223bbb8
	if (cr6.eq) goto loc_8223BBB8;
	// li r11,976
	r11.s64 = 976;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f0.f64 = double(temp.f32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// li r7,72
	ctx.r7.s64 = 72;
	// lfs f12,308(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,244(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f10.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 + ctx.f10.f64));
	// lvx128 v56,r0,r23
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v55,v63,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32)));
	// lbzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// stfs f11,180(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f9,308(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// stfs f8,244(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223ba50
	if (cr6.eq) goto loc_8223BA50;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223b9f8
	if (cr6.eq) goto loc_8223B9F8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223B9F8;
	sub_82723940(ctx, base);
loc_8223B9F8:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,412(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223BA20;
	sub_82723940(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// addi r6,r11,-16512
	ctx.r6.s64 = r11.s64 + -16512;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82723940
	ctx.lr = 0x8223BA4C;
	sub_82723940(ctx, base);
	// b 0x8223bbb8
	goto loc_8223BBB8;
loc_8223BA50:
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// li r8,48
	ctx.r8.s64 = 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223bad4
	if (cr6.eq) goto loc_8223BAD4;
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// addi r28,r1,240
	r28.s64 = ctx.r1.s64 + 240;
	// addi r27,r1,320
	r27.s64 = ctx.r1.s64 + 320;
	// addi r7,r11,1040
	ctx.r7.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r10,1
	r24.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r24,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r24.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r6,420(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r27
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223BAD4:
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r28,r1,176
	r28.s64 = ctx.r1.s64 + 176;
	// addi r27,r1,256
	r27.s64 = ctx.r1.s64 + 256;
	// addi r24,r1,272
	r24.s64 = ctx.r1.s64 + 272;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// addi r22,r1,288
	r22.s64 = ctx.r1.s64 + 288;
	// addi r7,r11,1040
	ctx.r7.s64 = r11.s64 + 1040;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r21,r10,1
	r21.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r21,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r21.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r21,412(r31)
	r21.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// lis r20,-32130
	r20.s64 = -2105671680;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r20,r20,-16512
	r20.s64 = r20.s64 + -16512;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r21,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r21.u32);
	// lvx128 v49,r0,r5
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r4
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r3
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r28
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r23
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r5,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r5.u32);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r25,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r25.u32);
	// lvx128 v44,r0,r27
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r24
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r22
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223BBB8:
	// addi r1,r1,496
	ctx.r1.s64 = ctx.r1.s64 + 496;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba24
	ctx.lr = 0x8223BBCC;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8223BBD0"))) PPC_WEAK_FUNC(sub_8223BBD0);
PPC_FUNC_IMPL(__imp__sub_8223BBD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x8223BBD8;
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823db9d4
	ctx.lr = 0x8223BBE0;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-576(r1)
	ea = -576 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lbz r11,153(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223bc54
	if (cr6.eq) goto loc_8223BC54;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BC24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223bc54
	if (cr6.eq) goto loc_8223BC54;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82239d20
	ctx.lr = 0x8223BC50;
	sub_82239D20(ctx, base);
	// b 0x8223c360
	goto loc_8223C360;
loc_8223BC54:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223bc78
	if (cr6.eq) goto loc_8223BC78;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223c360
	if (!cr6.eq) goto loc_8223C360;
loc_8223BC78:
	// lbz r11,153(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223bccc
	if (!cr6.eq) goto loc_8223BCCC;
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223bc98
	if (cr6.gt) goto loc_8223BC98;
	// li r11,0
	r11.s64 = 0;
loc_8223BC98:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223bccc
	if (cr6.eq) goto loc_8223BCCC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BCC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8223c360
	if (!cr6.eq) goto loc_8223C360;
loc_8223BCCC:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r30,120(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 120);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lbz r7,153(r26)
	ctx.r7.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BCF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,80
	r28.s64 = 80;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223bd78
	if (cr6.eq) goto loc_8223BD78;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8223bd3c
	if (cr6.eq) goto loc_8223BD3C;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8223bd34
	if (cr6.eq) goto loc_8223BD34;
	// addi r30,r11,208
	r30.s64 = r11.s64 + 208;
	// b 0x8223bd48
	goto loc_8223BD48;
loc_8223BD34:
	// addi r30,r11,144
	r30.s64 = r11.s64 + 144;
	// b 0x8223bd48
	goto loc_8223BD48;
loc_8223BD3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8223BD44;
	sub_822A8108(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8223BD48:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82238f88
	ctx.lr = 0x8223BD50;
	sub_82238F88(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// fmr f28,f1
	f28.f64 = ctx.f1.f64;
	// lfs f13,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223bd80
	goto loc_8223BD80;
loc_8223BD78:
	// lfs f28,100(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 100);
	f28.f64 = double(temp.f32);
	// lvx128 v127,r25,r28
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223BD80:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BD98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223bdb8
	if (cr6.eq) goto loc_8223BDB8;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223BDB0;
	sub_82620070(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// b 0x8223bdbc
	goto loc_8223BDBC;
loc_8223BDB8:
	// lfs f29,144(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 144);
	f29.f64 = double(temp.f32);
loc_8223BDBC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,126(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 126);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x8223be08
	if (cr6.eq) goto loc_8223BE08;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BDE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223BDF8;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1008(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f11,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f30.f64));
	// fmuls f29,f9,f29
	f29.f64 = double(float(ctx.f9.f64 * f29.f64));
loc_8223BE08:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lfs f0,-16516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16516);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f27,f0,f29
	f27.f64 = double(float(f0.f64 * f29.f64));
	// stfs f31,212(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f31,216(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f31,224(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f31,240(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f31,244(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f27,208(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f27,228(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f27,248(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lfs f0,-28412(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28412);
	f0.f64 = double(temp.f32);
	// fsubs f1,f28,f0
	ctx.f1.f64 = double(float(f28.f64 - f0.f64));
	// bl 0x82214d90
	ctx.lr = 0x8223BE54;
	sub_82214D90(ctx, base);
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// li r29,16
	r29.s64 = 16;
	// stfs f27,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r30,32
	r30.s64 = 32;
	// stfs f27,116(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f27,120(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f0,596(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r24,r1,176
	r24.s64 = ctx.r1.s64 + 176;
	// stfs f31,324(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// addi r23,r1,256
	r23.s64 = ctx.r1.s64 + 256;
	// stvx128 v127,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// stvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// stfs f31,328(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stfs f31,336(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f31,344(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f31,352(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// stfs f31,356(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8223BF18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,168(r26)
	ctx.r6.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8223bf68
	if (cr6.eq) goto loc_8223BF68;
	// addi r4,r26,16
	ctx.r4.s64 = r26.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82238d68
	ctx.lr = 0x8223BF38;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223bf68
	if (!cr6.eq) goto loc_8223BF68;
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223BF64;
	sub_82235280(ctx, base);
	// b 0x8223c360
	goto loc_8223C360;
loc_8223BF68:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223BF80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223BFA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223c360
	if (cr6.eq) goto loc_8223C360;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r9,976
	ctx.r9.s64 = 976;
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,36(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lvx128 v55,r31,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v55,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8223BFDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223BFE8;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lbz r5,126(r25)
	ctx.r5.u64 = PPC_LOAD_U8(r25.u32 + 126);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f29,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f29.f64 = double(temp.f32);
	// fadds f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 + f30.f64));
	// fmuls f28,f12,f29
	f28.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fsubs f27,f30,f28
	f27.f64 = double(float(f30.f64 - f28.f64));
	// beq cr6,0x8223c058
	if (cr6.eq) goto loc_8223C058;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223C034;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1016(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1016);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f30,f10
	ctx.f9.f64 = double(float(f30.f64 - ctx.f10.f64));
	// lfs f8,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f11,f30
	ctx.f7.f64 = double(float(ctx.f11.f64 + f30.f64));
	// fmuls f6,f7,f29
	ctx.f6.f64 = double(float(ctx.f7.f64 * f29.f64));
	// fmadds f5,f6,f9,f10
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// stfs f4,140(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_8223C058:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,260(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,196(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f10,372(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	ctx.f10.f64 = double(temp.f32);
	// fadds f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// fadds f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 + f0.f64));
	// stfs f11,260(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// stfs f9,196(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stfs f8,372(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// beq cr6,0x8223c164
	if (cr6.eq) goto loc_8223C164;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223c0c8
	if (cr6.eq) goto loc_8223C0C8;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,420(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223C0C8;
	sub_82723940(ctx, base);
loc_8223C0C8:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,412(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223C0F0;
	sub_82723940(ctx, base);
	// stfs f30,288(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f30,292(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f30,296(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f28,300(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,288
	ctx.r6.s64 = ctx.r1.s64 + 288;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82723940
	ctx.lr = 0x8223C128;
	sub_82723940(ctx, base);
	// stfs f30,304(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f30,308(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f30,312(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f27,316(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82723940
	ctx.lr = 0x8223C160;
	sub_82723940(ctx, base);
	// b 0x8223c360
	goto loc_8223C360;
loc_8223C164:
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// li r8,48
	ctx.r8.s64 = 48;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223c1e8
	if (cr6.eq) goto loc_8223C1E8;
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// addi r4,r1,336
	ctx.r4.s64 = ctx.r1.s64 + 336;
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// addi r26,r1,368
	r26.s64 = ctx.r1.s64 + 368;
	// addi r25,r1,384
	r25.s64 = ctx.r1.s64 + 384;
	// addi r7,r11,1040
	ctx.r7.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r23,r10,1
	r23.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r23,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r23.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r6,420(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lvx128 v53,r0,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r3
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r26
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r25
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223C1E8:
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stfs f30,272(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// stfs f30,276(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f30,280(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f28,284(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f30,112(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f30,116(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f27,124(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// addi r26,r1,256
	r26.s64 = ctx.r1.s64 + 256;
	// addi r25,r1,128
	r25.s64 = ctx.r1.s64 + 128;
	// addi r23,r1,144
	r23.s64 = ctx.r1.s64 + 144;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// addi r22,r1,160
	r22.s64 = ctx.r1.s64 + 160;
	// addi r7,r11,1040
	ctx.r7.s64 = r11.s64 + 1040;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r21,r10,1
	r21.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r21,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, r21.u32);
	// addi r21,r1,176
	r21.s64 = ctx.r1.s64 + 176;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r6,412(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// addi r20,r1,192
	r20.s64 = ctx.r1.s64 + 192;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r19,r1,144
	r19.s64 = ctx.r1.s64 + 144;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// addi r18,r1,160
	r18.s64 = ctx.r1.s64 + 160;
	// addi r7,r1,272
	ctx.r7.s64 = ctx.r1.s64 + 272;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// lvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v47,r0,r4
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r26
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r25
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// lvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r7,r11,1040
	ctx.r7.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// stw r4,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r4.u32);
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r24,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r24.u32);
	// lvx128 v42,r0,r23
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r22
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v40,r0,r21
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r0,r20
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r6,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r6.u32);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// lvx128 v38,r0,r19
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r0,r18
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stvx128 v37,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r5
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r0,r9
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r7
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223C360:
	// addi r1,r1,576
	ctx.r1.s64 = ctx.r1.s64 + 576;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-120
	r12.s64 = ctx.r1.s64 + -120;
	// bl 0x823dba20
	ctx.lr = 0x8223C374;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8223C378"))) PPC_WEAK_FUNC(sub_8223C378);
PPC_FUNC_IMPL(__imp__sub_8223C378) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28404
	ctx.r7.s64 = ctx.r9.s64 + -28404;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-30888
	ctx.r3.s64 = ctx.r8.s64 + -30888;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223C3BC;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28664
	ctx.r3.s64 = ctx.r6.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223C3CC;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223C3E8"))) PPC_WEAK_FUNC(sub_8223C3E8);
PPC_FUNC_IMPL(__imp__sub_8223C3E8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28352
	ctx.r7.s64 = ctx.r9.s64 + -28352;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28372
	ctx.r3.s64 = ctx.r8.s64 + -28372;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223C42C;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223C448"))) PPC_WEAK_FUNC(sub_8223C448);
PPC_FUNC_IMPL(__imp__sub_8223C448) {
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
	// bl 0x823d91c4
	ctx.lr = 0x8223C450;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9d4
	ctx.lr = 0x8223C458;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223c498
	if (cr6.eq) goto loc_8223C498;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223c9a8
	if (!cr6.eq) goto loc_8223C9A8;
loc_8223C498:
	// lbz r6,153(r26)
	ctx.r6.u64 = PPC_LOAD_U8(r26.u32 + 153);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8223c4c4
	if (!cr6.eq) goto loc_8223C4C4;
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223c4b8
	if (cr6.gt) goto loc_8223C4B8;
	// li r11,0
	r11.s64 = 0;
loc_8223C4B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223c9a8
	if (!cr6.eq) goto loc_8223C9A8;
loc_8223C4C4:
	// li r27,80
	r27.s64 = 80;
	// lbz r11,152(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 152);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r24,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f27.f64 = double(temp.f32);
	// beq cr6,0x8223c4ec
	if (cr6.eq) goto loc_8223C4EC;
	// stfs f27,212(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
loc_8223C4EC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223C524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223c544
	if (cr6.eq) goto loc_8223C544;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223C53C;
	sub_82620070(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// b 0x8223c548
	goto loc_8223C548;
loc_8223C544:
	// lfs f30,144(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 144);
	f30.f64 = double(temp.f32);
loc_8223C548:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,126(r24)
	ctx.r10.u64 = PPC_LOAD_U8(r24.u32 + 126);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8223c594
	if (cr6.eq) goto loc_8223C594;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223C584;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1008(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f11,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f31.f64));
	// fmuls f30,f9,f30
	f30.f64 = double(float(ctx.f9.f64 * f30.f64));
loc_8223C594:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C5A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,80
	r11.s64 = r26.s64 + 80;
	// li r28,16
	r28.s64 = 16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r29,32
	r29.s64 = 32;
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lbz r9,168(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223c660
	if (cr6.eq) goto loc_8223C660;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223c988
	if (cr6.eq) goto loc_8223C988;
loc_8223C660:
	// lbz r11,124(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223c68c
	if (cr6.eq) goto loc_8223C68C;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 * f30.f64));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82239968
	ctx.lr = 0x8223C68C;
	sub_82239968(ctx, base);
loc_8223C68C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C6A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223C6AC;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,126(r24)
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + 126);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f29,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f29.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// fmuls f30,f12,f29
	f30.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fsubs f28,f31,f30
	f28.f64 = double(float(f31.f64 - f30.f64));
	// beq cr6,0x8223c71c
	if (cr6.eq) goto loc_8223C71C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223C6E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223C6F8;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1016(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1016);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f31,f10
	ctx.f9.f64 = double(float(f31.f64 - ctx.f10.f64));
	// lfs f8,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 + f31.f64));
	// fmuls f6,f7,f29
	ctx.f6.f64 = double(float(ctx.f7.f64 * f29.f64));
	// fmadds f5,f6,f9,f10
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// stfs f4,140(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_8223C71C:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223c7dc
	if (cr6.eq) goto loc_8223C7DC;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223C768;
	sub_82723940(ctx, base);
	// stfs f31,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f30,236(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x82723940
	ctx.lr = 0x8223C7A0;
	sub_82723940(ctx, base);
	// stfs f31,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f31,244(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f31,248(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f28,252(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lwz r9,172(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// bl 0x82723940
	ctx.lr = 0x8223C7D8;
	sub_82723940(ctx, base);
	// b 0x8223c960
	goto loc_8223C960;
loc_8223C7DC:
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// stfs f31,256(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f31,264(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f30,268(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r25,r1,192
	r25.s64 = ctx.r1.s64 + 192;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// addi r22,r1,128
	r22.s64 = ctx.r1.s64 + 128;
	// addi r21,r1,144
	r21.s64 = ctx.r1.s64 + 144;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f28,124(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r20,r1,160
	r20.s64 = ctx.r1.s64 + 160;
	// addi r19,r1,176
	r19.s64 = ctx.r1.s64 + 176;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// addi r18,r1,192
	r18.s64 = ctx.r1.s64 + 192;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// addi r16,r1,144
	r16.s64 = ctx.r1.s64 + 144;
	// addi r15,r1,192
	r15.s64 = ctx.r1.s64 + 192;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r8,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r8.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r7,416(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// addi r17,r1,112
	r17.s64 = ctx.r1.s64 + 112;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lvx128 v49,r0,r17
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// stvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r25
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r22
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r3,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r3.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r7,16(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lvx128 v48,r0,r21
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r20
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r19
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r18
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r6,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r6.u32);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lvx128 v44,r0,r16
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r5
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r4
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r15
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223C960:
	// lbz r11,168(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223c9a8
	if (cr6.eq) goto loc_8223C9A8;
	// addi r4,r26,16
	ctx.r4.s64 = r26.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82238d68
	ctx.lr = 0x8223C97C;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223c9a8
	if (!cr6.eq) goto loc_8223C9A8;
loc_8223C988:
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lbz r9,36(r24)
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + 36);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// lbz r8,124(r24)
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + 124);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223C9A8;
	sub_82235280(ctx, base);
loc_8223C9A8:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba20
	ctx.lr = 0x8223C9B4;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8223C9B8"))) PPC_WEAK_FUNC(sub_8223C9B8);
PPC_FUNC_IMPL(__imp__sub_8223C9B8) {
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
	// bl 0x823d91c4
	ctx.lr = 0x8223C9C0;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9d4
	ctx.lr = 0x8223C9C8;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ca08
	if (cr6.eq) goto loc_8223CA08;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8223cfb8
	if (!cr6.eq) goto loc_8223CFB8;
loc_8223CA08:
	// lbz r6,153(r24)
	ctx.r6.u64 = PPC_LOAD_U8(r24.u32 + 153);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8223ca34
	if (!cr6.eq) goto loc_8223CA34;
	// lwz r11,156(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 156);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x8223ca28
	if (cr6.gt) goto loc_8223CA28;
	// li r11,0
	r11.s64 = 0;
loc_8223CA28:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223cfb8
	if (!cr6.eq) goto loc_8223CFB8;
loc_8223CA34:
	// li r27,80
	r27.s64 = 80;
	// lbz r11,152(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 152);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lvx128 v63,r23,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f27,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f27.f64 = double(temp.f32);
	// beq cr6,0x8223ca5c
	if (cr6.eq) goto loc_8223CA5C;
	// stfs f27,212(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
loc_8223CA5C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CA7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223CA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223cab4
	if (cr6.eq) goto loc_8223CAB4;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x82620070
	ctx.lr = 0x8223CAAC;
	sub_82620070(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// b 0x8223cab8
	goto loc_8223CAB8;
loc_8223CAB4:
	// lfs f30,144(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 144);
	f30.f64 = double(temp.f32);
loc_8223CAB8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,126(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 126);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8223cb04
	if (cr6.eq) goto loc_8223CB04;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CAE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223CAF4;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1008(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1008);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f10,f11,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f31.f64));
	// fmuls f30,f9,f30
	f30.f64 = double(float(ctx.f9.f64 * f30.f64));
loc_8223CB04:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CB18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r24,80
	r11.s64 = r24.s64 + 80;
	// li r28,16
	r28.s64 = 16;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r29,32
	r29.s64 = 32;
	// fmuls f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 * f30.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v58,v61,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vmulfp128 v57,v60,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lbz r9,168(r24)
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + 168);
	// lvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223cbd0
	if (cr6.eq) goto loc_8223CBD0;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CBC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8223cf98
	if (cr6.eq) goto loc_8223CF98;
loc_8223CBD0:
	// lbz r11,124(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223cbfc
	if (cr6.eq) goto loc_8223CBFC;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 * f30.f64));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82239968
	ctx.lr = 0x8223CBFC;
	sub_82239968(ctx, base);
loc_8223CBFC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CC10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,468(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-28332(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28332);
	f0.f64 = double(temp.f32);
	// lfs f13,26468(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmsubs f29,f12,f0,f13
	f29.f64 = double(float(ctx.f12.f64 * f0.f64 - ctx.f13.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8223CC34;
	sub_823DBAE8(ctx, base);
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8223CC40;
	sub_823DBBC8(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,31492(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31492);
	f0.f64 = double(temp.f32);
	// lfs f28,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f28.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bge cr6,0x8223cc80
	if (!cr6.lt) goto loc_8223CC80;
	// lwz r25,16(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// fcmpu cr6,f13,f27
	cr6.compare(ctx.f13.f64, f27.f64);
	// ble cr6,0x8223cc74
	if (!cr6.gt) goto loc_8223CC74;
	// lwz r26,8(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// fadds f13,f30,f31
	ctx.f13.f64 = double(float(f30.f64 + f31.f64));
	// b 0x8223cccc
	goto loc_8223CCCC;
loc_8223CC74:
	// lwz r26,20(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// fadds f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 + f31.f64));
	// b 0x8223cccc
	goto loc_8223CCCC;
loc_8223CC80:
	// fcmpu cr6,f30,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f28.f64);
	// bge cr6,0x8223ccb0
	if (!cr6.lt) goto loc_8223CCB0;
	// fcmpu cr6,f13,f27
	cr6.compare(ctx.f13.f64, f27.f64);
	// ble cr6,0x8223cca0
	if (!cr6.gt) goto loc_8223CCA0;
	// lwz r26,20(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// fadds f30,f30,f28
	f30.f64 = double(float(f30.f64 + f28.f64));
	// lwz r25,8(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// b 0x8223ccd8
	goto loc_8223CCD8;
loc_8223CCA0:
	// lwz r26,8(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// fadds f30,f30,f28
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f30.f64 + f28.f64));
	// lwz r25,20(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// b 0x8223ccd8
	goto loc_8223CCD8;
loc_8223CCB0:
	// lwz r26,16(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// fcmpu cr6,f13,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f27.f64);
	// ble cr6,0x8223ccc4
	if (!cr6.gt) goto loc_8223CCC4;
	// lwz r25,20(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// b 0x8223ccc8
	goto loc_8223CCC8;
loc_8223CCC4:
	// lwz r25,8(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 8);
loc_8223CCC8:
	// fsubs f13,f30,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f28.f64));
loc_8223CCCC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f30,f13,f0
	f30.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8223CCD8:
	// lbz r11,126(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 126);
	// fsubs f29,f31,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(f31.f64 - f30.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223cd34
	if (cr6.eq) goto loc_8223CD34;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223CCFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1012(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f12,468(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 468);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f13,f12
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8223CD10;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f10,1016(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1016);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f31,f10
	ctx.f9.f64 = double(float(f31.f64 - ctx.f10.f64));
	// lfs f8,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f8.f64 = double(temp.f32);
	// fadds f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 + f31.f64));
	// fmuls f6,f7,f28
	ctx.f6.f64 = double(float(ctx.f7.f64 * f28.f64));
	// fmadds f5,f6,f9,f10
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmuls f4,f5,f8
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// stfs f4,140(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_8223CD34:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,196(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223cdf4
	if (cr6.eq) goto loc_8223CDF4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,172(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82723940
	ctx.lr = 0x8223CD80;
	sub_82723940(ctx, base);
	// stfs f31,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f30,236(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lwz r9,172(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82723940
	ctx.lr = 0x8223CDB8;
	sub_82723940(ctx, base);
	// stfs f31,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f31,244(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f31,248(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f29,252(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lwz r9,172(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 172);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82723940
	ctx.lr = 0x8223CDF0;
	sub_82723940(ctx, base);
	// b 0x8223cf70
	goto loc_8223CF70;
loc_8223CDF4:
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// stfs f31,256(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r30,r1,192
	r30.s64 = ctx.r1.s64 + 192;
	// stfs f29,124(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// addi r21,r1,128
	r21.s64 = ctx.r1.s64 + 128;
	// addi r20,r1,144
	r20.s64 = ctx.r1.s64 + 144;
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// stfs f31,264(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f30,268(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r19,r1,160
	r19.s64 = ctx.r1.s64 + 160;
	// addi r18,r1,176
	r18.s64 = ctx.r1.s64 + 176;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// addi r17,r1,192
	r17.s64 = ctx.r1.s64 + 192;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// addi r16,r1,144
	r16.s64 = ctx.r1.s64 + 144;
	// addi r15,r1,160
	r15.s64 = ctx.r1.s64 + 160;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r8,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r8.u32);
	// li r8,48
	ctx.r8.s64 = 48;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r7,416(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// lvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v54,r0,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v53,r0,r3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r21
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// lvx128 v49,r0,r7
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r3,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r3.u32);
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r26,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r26.u32);
	// lvx128 v48,r0,r20
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r19
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r18
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r17
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-17936(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17936);
	// mulli r11,r11,18448
	r11.s64 = r11.s64 * 18448;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// lwz r10,19472(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 19472);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r6,19472(r11)
	PPC_STORE_U32(r11.u32 + 19472, ctx.r6.u32);
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// stw r25,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r25.u32);
	// lvx128 v44,r0,r16
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r15
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r5
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r0,r4
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223CF70:
	// lbz r11,168(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 168);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223cfb8
	if (cr6.eq) goto loc_8223CFB8;
	// addi r4,r24,16
	ctx.r4.s64 = r24.s64 + 16;
	// lfs f1,548(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 548);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82238d68
	ctx.lr = 0x8223CF8C;
	sub_82238D68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223cfb8
	if (!cr6.eq) goto loc_8223CFB8;
loc_8223CF98:
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lbz r9,36(r23)
	ctx.r9.u64 = PPC_LOAD_U8(r23.u32 + 36);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// lbz r8,124(r23)
	ctx.r8.u64 = PPC_LOAD_U8(r23.u32 + 124);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82235280
	ctx.lr = 0x8223CFB8;
	sub_82235280(ctx, base);
loc_8223CFB8:
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba20
	ctx.lr = 0x8223CFC4;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8223CFC8"))) PPC_WEAK_FUNC(sub_8223CFC8);
PPC_FUNC_IMPL(__imp__sub_8223CFC8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28308
	ctx.r7.s64 = ctx.r9.s64 + -28308;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-30888
	ctx.r3.s64 = ctx.r8.s64 + -30888;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223D00C;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28328
	ctx.r3.s64 = ctx.r6.s64 + -28328;
	// bl 0x82723808
	ctx.lr = 0x8223D01C;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r3,r5,-28664
	ctx.r3.s64 = ctx.r5.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223D02C;
	sub_82723808(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223D048"))) PPC_WEAK_FUNC(sub_8223D048);
PPC_FUNC_IMPL(__imp__sub_8223D048) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28272
	ctx.r7.s64 = ctx.r9.s64 + -28272;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-30888
	ctx.r3.s64 = ctx.r8.s64 + -30888;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223D08C;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28468
	ctx.r3.s64 = ctx.r6.s64 + -28468;
	// bl 0x82723808
	ctx.lr = 0x8223D09C;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r3,r5,-28664
	ctx.r3.s64 = ctx.r5.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223D0AC;
	sub_82723808(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223D0C8"))) PPC_WEAK_FUNC(sub_8223D0C8);
PPC_FUNC_IMPL(__imp__sub_8223D0C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,126(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 126);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d0d8
	if (cr6.eq) goto loc_8223D0D8;
	// b 0x8223c9b8
	sub_8223C9B8(ctx, base);
	return;
loc_8223D0D8:
	// b 0x8223c448
	sub_8223C448(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223D0DC"))) PPC_WEAK_FUNC(sub_8223D0DC);
PPC_FUNC_IMPL(__imp__sub_8223D0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223D0E0"))) PPC_WEAK_FUNC(sub_8223D0E0);
PPC_FUNC_IMPL(__imp__sub_8223D0E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,126(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 126);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d0f0
	if (cr6.eq) goto loc_8223D0F0;
	// b 0x8223bbd0
	sub_8223BBD0(ctx, base);
	return;
loc_8223D0F0:
	// b 0x8223b5d8
	sub_8223B5D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223D0F4"))) PPC_WEAK_FUNC(sub_8223D0F4);
PPC_FUNC_IMPL(__imp__sub_8223D0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223D0F8"))) PPC_WEAK_FUNC(sub_8223D0F8);
PPC_FUNC_IMPL(__imp__sub_8223D0F8) {
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
	// bl 0x82239498
	ctx.lr = 0x8223D118;
	sub_82239498(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d130
	if (cr6.eq) goto loc_8223D130;
	// bl 0x82130588
	ctx.lr = 0x8223D12C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223D130:
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

__attribute__((alias("__imp__sub_8223D148"))) PPC_WEAK_FUNC(sub_8223D148);
PPC_FUNC_IMPL(__imp__sub_8223D148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,126(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 126);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d158
	if (cr6.eq) goto loc_8223D158;
	// b 0x8223c448
	sub_8223C448(ctx, base);
	return;
loc_8223D158:
	// b 0x8223b098
	sub_8223B098(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223D15C"))) PPC_WEAK_FUNC(sub_8223D15C);
PPC_FUNC_IMPL(__imp__sub_8223D15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223D160"))) PPC_WEAK_FUNC(sub_8223D160);
PPC_FUNC_IMPL(__imp__sub_8223D160) {
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
	ctx.lr = 0x8223D168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r31,40
	r31.s64 = 40;
	// addi r10,r11,-28736
	ctx.r10.s64 = r11.s64 + -28736;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// beq cr6,0x8223d1b4
	if (cr6.eq) goto loc_8223D1B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223D1B4:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r11.u32);
	// bl 0x82239498
	ctx.lr = 0x8223D1C8;
	sub_82239498(ctx, base);
	// clrlwi r10,r28,31
	ctx.r10.u64 = r28.u32 & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223d1e0
	if (cr6.eq) goto loc_8223D1E0;
	// bl 0x82130588
	ctx.lr = 0x8223D1DC;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8223D1E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8223D1E8"))) PPC_WEAK_FUNC(sub_8223D1E8);
PPC_FUNC_IMPL(__imp__sub_8223D1E8) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-28220
	ctx.r7.s64 = ctx.r9.s64 + -28220;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,-28556
	ctx.r3.s64 = ctx.r8.s64 + -28556;
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// bl 0x82723808
	ctx.lr = 0x8223D22C;
	sub_82723808(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r3,r6,-28240
	ctx.r3.s64 = ctx.r6.s64 + -28240;
	// bl 0x82723808
	ctx.lr = 0x8223D23C;
	sub_82723808(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r3,r5,-28664
	ctx.r3.s64 = ctx.r5.s64 + -28664;
	// bl 0x82723808
	ctx.lr = 0x8223D24C;
	sub_82723808(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8223D268"))) PPC_WEAK_FUNC(sub_8223D268);
PPC_FUNC_IMPL(__imp__sub_8223D268) {
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
	// bl 0x82239868
	ctx.lr = 0x8223D288;
	sub_82239868(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d2a0
	if (cr6.eq) goto loc_8223D2A0;
	// bl 0x82130588
	ctx.lr = 0x8223D29C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223D2A0:
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

__attribute__((alias("__imp__sub_8223D2B8"))) PPC_WEAK_FUNC(sub_8223D2B8);
PPC_FUNC_IMPL(__imp__sub_8223D2B8) {
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
	// li r11,-1
	r11.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8223D2E4;
	sub_821C2F70(ctx, base);
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

__attribute__((alias("__imp__sub_8223D2FC"))) PPC_WEAK_FUNC(sub_8223D2FC);
PPC_FUNC_IMPL(__imp__sub_8223D2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223D300"))) PPC_WEAK_FUNC(sub_8223D300);
PPC_FUNC_IMPL(__imp__sub_8223D300) {
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
	ctx.lr = 0x8223D308;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
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
	ctx.lr = 0x8223D328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r27,0
	r27.s64 = 0;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r25,r11,-28004
	r25.s64 = r11.s64 + -28004;
	// li r8,7
	ctx.r8.s64 = 7;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r31,r25
	r31.u64 = r25.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r24,r11,-14196
	r24.s64 = r11.s64 + -14196;
	// addi r30,r10,-27832
	r30.s64 = ctx.r10.s64 + -27832;
loc_8223D35C:
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x8223D368;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x8223D374;
	sub_825EF9A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8223D380;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223D390;
	sub_825ED480(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8223d3a8
	if (!cr6.eq) goto loc_8223D3A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821bd618
	ctx.lr = 0x8223D3A8;
	sub_821BD618(ctx, base);
loc_8223D3A8:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ed4a0
	ctx.lr = 0x8223D3BC;
	sub_825ED4A0(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r25,20
	r11.s64 = r25.s64 + 20;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8223d35c
	if (cr6.lt) goto loc_8223D35C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// addi r4,r11,-27856
	ctx.r4.s64 = r11.s64 + -27856;
	// bl 0x82218310
	ctx.lr = 0x8223D3E0;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x8223D3EC;
	sub_825EF9A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8223D3F8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223D408;
	sub_825ED480(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8223d420
	if (!cr6.eq) goto loc_8223D420;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821bd618
	ctx.lr = 0x8223D420;
	sub_821BD618(ctx, base);
loc_8223D420:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ed4a0
	ctx.lr = 0x8223D434;
	sub_825ED4A0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,-27876
	ctx.r4.s64 = r11.s64 + -27876;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8223D448;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8223D450"))) PPC_WEAK_FUNC(sub_8223D450);
PPC_FUNC_IMPL(__imp__sub_8223D450) {
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
	ctx.lr = 0x8223D458;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8223D470;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d5f0
	if (cr6.eq) goto loc_8223D5F0;
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
	ctx.lr = 0x8223D498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r28,56(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x822a3998
	ctx.lr = 0x8223D4AC;
	sub_822A3998(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,880(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 880);
	// lwz r29,80(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// bl 0x822a3998
	ctx.lr = 0x8223D4C4;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b13e0
	ctx.lr = 0x8223D4CC;
	sub_822B13E0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// bne cr6,0x8223d4dc
	if (!cr6.eq) goto loc_8223D4DC;
	// li r29,5
	r29.s64 = 5;
loc_8223D4DC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223d500
	if (cr6.eq) goto loc_8223D500;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223d510
	if (cr6.eq) goto loc_8223D510;
loc_8223D500:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6734(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6734);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223d518
	if (cr6.eq) goto loc_8223D518;
loc_8223D510:
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x8223d51c
	goto loc_8223D51C;
loc_8223D518:
	// li r5,4
	ctx.r5.s64 = 4;
loc_8223D51C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-27876
	ctx.r4.s64 = r11.s64 + -27876;
	// bl 0x825ee0e0
	ctx.lr = 0x8223D52C;
	sub_825EE0E0(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// beq cr6,0x8223d5ec
	if (cr6.eq) goto loc_8223D5EC;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r11,-12068
	ctx.r4.s64 = r11.s64 + -12068;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r30,r10,-17812
	r30.s64 = ctx.r10.s64 + -17812;
	// addi r26,r9,-22108
	r26.s64 = ctx.r9.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8223D564;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8223D578;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8223D588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8265eb48
	ctx.lr = 0x8223D590;
	sub_8265EB48(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8223d5ec
	if (!cr6.eq) goto loc_8223D5EC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223d5ec
	if (!cr6.eq) goto loc_8223D5EC;
	// bl 0x82207e88
	ctx.lr = 0x8223D5AC;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223d5ec
	if (!cr6.eq) goto loc_8223D5EC;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f7c90
	ctx.lr = 0x8223D5C0;
	sub_821F7C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223d5ec
	if (!cr6.eq) goto loc_8223D5EC;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8223d5ec
	if (cr6.eq) goto loc_8223D5EC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-27824
	ctx.r4.s64 = r11.s64 + -27824;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8223D5EC;
	sub_825EE0E0(ctx, base);
loc_8223D5EC:
	// stw r29,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r29.u32);
loc_8223D5F0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8223D5F8"))) PPC_WEAK_FUNC(sub_8223D5F8);
PPC_FUNC_IMPL(__imp__sub_8223D5F8) {
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
	// lwz r3,-6432(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6432);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223d62c
	if (cr6.eq) goto loc_8223D62C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223D62C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-6432(r31)
	PPC_STORE_U32(r31.u32 + -6432, r11.u32);
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

__attribute__((alias("__imp__sub_8223D648"))) PPC_WEAK_FUNC(sub_8223D648);
PPC_FUNC_IMPL(__imp__sub_8223D648) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8223D650;
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
	// lbz r11,25(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d684
	if (cr6.eq) goto loc_8223D684;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D67C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,25(r31)
	PPC_STORE_U8(r31.u32 + 25, ctx.r9.u8);
loc_8223D684:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223d774
	if (cr6.eq) goto loc_8223D774;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lis r28,-32130
	r28.s64 = -2105671680;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d708
	if (cr6.eq) goto loc_8223D708;
	// li r30,0
	r30.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8223D6C0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r5,-15876(r28)
	ctx.r5.u64 = PPC_LOAD_U8(r28.u32 + -15876);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x82720898
	ctx.lr = 0x8223D6D8;
	sub_82720898(ctx, base);
	// lbz r10,-6436(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + -6436);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223d6f4
	if (cr6.eq) goto loc_8223D6F4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r3,56(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x825ee9b8
	ctx.lr = 0x8223D6F4;
	sub_825EE9B8(ctx, base);
loc_8223D6F4:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8223d6c0
	if (cr6.lt) goto loc_8223D6C0;
loc_8223D708:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d774
	if (cr6.eq) goto loc_8223D774;
	// li r30,0
	r30.s64 = 0;
loc_8223D71C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8223D734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lhz r4,26(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8223D748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r5,-15876(r28)
	ctx.r5.u64 = PPC_LOAD_U8(r28.u32 + -15876);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r3,r4,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + r30.u32);
	// bl 0x82720898
	ctx.lr = 0x8223D760;
	sub_82720898(ctx, base);
	// lhz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// blt cr6,0x8223d71c
	if (cr6.lt) goto loc_8223D71C;
loc_8223D774:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8223D780"))) PPC_WEAK_FUNC(sub_8223D780);
PPC_FUNC_IMPL(__imp__sub_8223D780) {
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
	ctx.lr = 0x8223D788;
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
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D7AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223d838
	if (cr6.eq) goto loc_8223D838;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d7f8
	if (cr6.eq) goto loc_8223D7F8;
	// li r30,0
	r30.s64 = 0;
loc_8223D7CC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82721258
	ctx.lr = 0x8223D7E4;
	sub_82721258(ctx, base);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8223d7cc
	if (cr6.lt) goto loc_8223D7CC;
loc_8223D7F8:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d838
	if (cr6.eq) goto loc_8223D838;
	// li r30,0
	r30.s64 = 0;
loc_8223D80C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x82721258
	ctx.lr = 0x8223D824;
	sub_82721258(ctx, base);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x8223d80c
	if (cr6.lt) goto loc_8223D80C;
loc_8223D838:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8223D840"))) PPC_WEAK_FUNC(sub_8223D840);
PPC_FUNC_IMPL(__imp__sub_8223D840) {
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
	ctx.lr = 0x8223D848;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223d8ac
	if (cr6.eq) goto loc_8223D8AC;
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d8ac
	if (cr6.eq) goto loc_8223D8AC;
	// li r31,0
	r31.s64 = 0;
loc_8223D880:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8223D898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x8223d880
	if (cr6.lt) goto loc_8223D880;
loc_8223D8AC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223D8B4"))) PPC_WEAK_FUNC(sub_8223D8B4);
PPC_FUNC_IMPL(__imp__sub_8223D8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223D8B8"))) PPC_WEAK_FUNC(sub_8223D8B8);
PPC_FUNC_IMPL(__imp__sub_8223D8B8) {
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
	ctx.lr = 0x8223D8C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d938
	if (cr6.eq) goto loc_8223D938;
	// li r31,0
	r31.s64 = 0;
loc_8223D8DC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223d900
	if (cr6.eq) goto loc_8223D900;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D900;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223D900:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223d924
	if (cr6.eq) goto loc_8223D924;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223D924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223D924:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8223d8dc
	if (cr6.lt) goto loc_8223D8DC;
loc_8223D938:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223D940"))) PPC_WEAK_FUNC(sub_8223D940);
PPC_FUNC_IMPL(__imp__sub_8223D940) {
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
	ctx.lr = 0x8223D974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8223d9a8
	if (cr6.eq) goto loc_8223D9A8;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8223D98C;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223d9a8
	if (cr6.eq) goto loc_8223D9A8;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8228dc90
	ctx.lr = 0x8223D9A8;
	sub_8228DC90(ctx, base);
loc_8223D9A8:
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

__attribute__((alias("__imp__sub_8223D9C0"))) PPC_WEAK_FUNC(sub_8223D9C0);
PPC_FUNC_IMPL(__imp__sub_8223D9C0) {
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
	ctx.lr = 0x8223D9C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r10,r11,-27504
	ctx.r10.s64 = r11.s64 + -27504;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r27,1
	r27.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x8223d9f4
	if (!cr6.eq) goto loc_8223D9F4;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
loc_8223D9F4:
	// li r29,0
	r29.s64 = 0;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// clrlwi r28,r30,16
	r28.u64 = r30.u32 & 0xFFFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r29.u16);
	// sth r28,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r28.u16);
	// beq cr6,0x8223da1c
	if (cr6.eq) goto loc_8223DA1C;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8223DA18;
	sub_82130528(ctx, base);
	// b 0x8223da20
	goto loc_8223DA20;
loc_8223DA1C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8223DA20:
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r29,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r29.u16);
	// sth r28,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r28.u16);
	// beq cr6,0x8223da40
	if (cr6.eq) goto loc_8223DA40;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8223DA3C;
	sub_82130528(ctx, base);
	// b 0x8223da44
	goto loc_8223DA44;
loc_8223DA40:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8223DA44:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// stb r27,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r27.u8);
	// stb r29,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r29.u8);
	// sth r27,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r27.u16);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8223DA68"))) PPC_WEAK_FUNC(sub_8223DA68);
PPC_FUNC_IMPL(__imp__sub_8223DA68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,25(r3)
	PPC_STORE_U8(ctx.r3.u32 + 25, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223DA74"))) PPC_WEAK_FUNC(sub_8223DA74);
PPC_FUNC_IMPL(__imp__sub_8223DA74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DA78"))) PPC_WEAK_FUNC(sub_8223DA78);
PPC_FUNC_IMPL(__imp__sub_8223DA78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r9,31
	ctx.r3.u64 = ctx.r9.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223DA8C"))) PPC_WEAK_FUNC(sub_8223DA8C);
PPC_FUNC_IMPL(__imp__sub_8223DA8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DA90"))) PPC_WEAK_FUNC(sub_8223DA90);
PPC_FUNC_IMPL(__imp__sub_8223DA90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223DAA0"))) PPC_WEAK_FUNC(sub_8223DAA0);
PPC_FUNC_IMPL(__imp__sub_8223DAA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223DAB0"))) PPC_WEAK_FUNC(sub_8223DAB0);
PPC_FUNC_IMPL(__imp__sub_8223DAB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223dacc
	if (cr6.eq) goto loc_8223DACC;
	// lbz r11,24(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8223dad0
	if (!cr6.eq) goto loc_8223DAD0;
loc_8223DACC:
	// li r11,0
	r11.s64 = 0;
loc_8223DAD0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223DAD8"))) PPC_WEAK_FUNC(sub_8223DAD8);
PPC_FUNC_IMPL(__imp__sub_8223DAD8) {
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
	ctx.lr = 0x8223DAE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,36
	ctx.r3.s64 = 36;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x8223DAF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223db20
	if (cr6.eq) goto loc_8223DB20;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8223d9c0
	ctx.lr = 0x8223DB10;
	sub_8223D9C0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-6432(r11)
	PPC_STORE_U32(r11.u32 + -6432, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8223DB20:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,-6432(r11)
	PPC_STORE_U32(r11.u32 + -6432, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223DB34"))) PPC_WEAK_FUNC(sub_8223DB34);
PPC_FUNC_IMPL(__imp__sub_8223DB34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DB38"))) PPC_WEAK_FUNC(sub_8223DB38);
PPC_FUNC_IMPL(__imp__sub_8223DB38) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-27504
	ctx.r10.s64 = r11.s64 + -27504;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8223d8b8
	ctx.lr = 0x8223DB60;
	sub_8223D8B8(ctx, base);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8223db9c
	if (cr6.eq) goto loc_8223DB9C;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8223DB74;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8223db9c
	if (!cr6.eq) goto loc_8223DB9C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8223db9c
	if (cr6.eq) goto loc_8223DB9C;
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
	ctx.lr = 0x8223DB9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223DB9C:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223dbb0
	if (cr6.eq) goto loc_8223DBB0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8223DBB0;
	sub_82130588(ctx, base);
loc_8223DBB0:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223dbc4
	if (cr6.eq) goto loc_8223DBC4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8223DBC4;
	sub_82130588(ctx, base);
loc_8223DBC4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8223DBCC;
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

__attribute__((alias("__imp__sub_8223DBE4"))) PPC_WEAK_FUNC(sub_8223DBE4);
PPC_FUNC_IMPL(__imp__sub_8223DBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DBE8"))) PPC_WEAK_FUNC(sub_8223DBE8);
PPC_FUNC_IMPL(__imp__sub_8223DBE8) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8223DBF0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8223dc38
	if (cr6.eq) goto loc_8223DC38;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8223DC24:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8223dc24
	if (!cr6.eq) goto loc_8223DC24;
loc_8223DC38:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// bl 0x8223d8b8
	ctx.lr = 0x8223DC54;
	sub_8223D8B8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82387928
	ctx.lr = 0x8223DC5C;
	sub_82387928(ctx, base);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// bne cr6,0x8223dc70
	if (!cr6.eq) goto loc_8223DC70;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r25,r11,-27444
	r25.s64 = r11.s64 + -27444;
	// b 0x8223dc78
	goto loc_8223DC78;
loc_8223DC70:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r25,r11,-27456
	r25.s64 = r11.s64 + -27456;
loc_8223DC78:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,-6428
	ctx.r10.s64 = r11.s64 + -6428;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223dc90
	if (cr6.eq) goto loc_8223DC90;
	// mr r25,r11
	r25.u64 = r11.u64;
loc_8223DC90:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// mr r27,r26
	r27.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8223dd74
	if (!cr6.gt) goto loc_8223DD74;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
loc_8223DCA8:
	// li r3,1024
	ctx.r3.s64 = 1024;
	// bl 0x82130528
	ctx.lr = 0x8223DCB0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223dccc
	if (cr6.eq) goto loc_8223DCCC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r5,28(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82240e68
	ctx.lr = 0x8223DCC4;
	sub_82240E68(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8223dcd0
	goto loc_8223DCD0;
loc_8223DCCC:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8223DCD0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223DCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r3,80
	ctx.r3.s64 = 80;
	// stb r26,29(r9)
	PPC_STORE_U8(ctx.r9.u32 + 29, r26.u8);
	// lhz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// stwx r31,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, r31.u32);
	// bl 0x82130528
	ctx.lr = 0x8223DD14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223dd2c
	if (cr6.eq) goto loc_8223DD2C;
	// lwz r4,28(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x822409b0
	ctx.lr = 0x8223DD24;
	sub_822409B0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8223dd30
	goto loc_8223DD30;
loc_8223DD2C:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8223DD30:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223DD48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r7.u16);
	// stwx r31,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r31.u32);
	// lwz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r27,r5
	cr6.compare<int32_t>(r27.s32, ctx.r5.s32, xer);
	// blt cr6,0x8223dca8
	if (cr6.lt) goto loc_8223DCA8;
loc_8223DD74:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8223DD80"))) PPC_WEAK_FUNC(sub_8223DD80);
PPC_FUNC_IMPL(__imp__sub_8223DD80) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223DDB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,144
	ctx.r3.s64 = ctx.r3.s64 + 144;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8223DDD0;
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

__attribute__((alias("__imp__sub_8223DDE4"))) PPC_WEAK_FUNC(sub_8223DDE4);
PPC_FUNC_IMPL(__imp__sub_8223DDE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DDE8"))) PPC_WEAK_FUNC(sub_8223DDE8);
PPC_FUNC_IMPL(__imp__sub_8223DDE8) {
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
	// bl 0x8223db38
	ctx.lr = 0x8223DE08;
	sub_8223DB38(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223de20
	if (cr6.eq) goto loc_8223DE20;
	// bl 0x82130588
	ctx.lr = 0x8223DE1C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223DE20:
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

__attribute__((alias("__imp__sub_8223DE38"))) PPC_WEAK_FUNC(sub_8223DE38);
PPC_FUNC_IMPL(__imp__sub_8223DE38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32220
	r11.s64 = -2111569920;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8832
	ctx.r4.s64 = r11.s64 + -8832;
	// addi r3,r10,-27424
	ctx.r3.s64 = ctx.r10.s64 + -27424;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223DE4C"))) PPC_WEAK_FUNC(sub_8223DE4C);
PPC_FUNC_IMPL(__imp__sub_8223DE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223DE50"))) PPC_WEAK_FUNC(sub_8223DE50);
PPC_FUNC_IMPL(__imp__sub_8223DE50) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8223DE58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// srawi r11,r4,31
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	r11.s64 = ctx.r4.s32 >> 31;
	// lis r10,54
	ctx.r10.s64 = 3538944;
	// xor r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 ^ r11.u64;
	// ori r31,r10,61056
	r31.u64 = ctx.r10.u64 | 61056;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// li r28,1000
	r28.s64 = 1000;
	// divw. r6,r11,r31
	ctx.r6.s32 = r11.s32 / r31.s32;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x8223df28
	if (cr0.eq) goto loc_8223DF28;
	// divw. r10,r4,r28
	ctx.r10.s32 = ctx.r4.s32 / r28.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x8223de90
	if (!cr0.lt) goto loc_8223DE90;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-27064
	ctx.r5.s64 = ctx.r10.s64 + -27064;
	// b 0x8223de98
	goto loc_8223DE98;
loc_8223DE90:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
loc_8223DE98:
	// lis r10,4194
	ctx.r10.s64 = 274857984;
	// lis r9,17895
	ctx.r9.s64 = 1172766720;
	// lis r8,19088
	ctx.r8.s64 = 1250951168;
	// ori r7,r10,19923
	ctx.r7.u64 = ctx.r10.u64 | 19923;
	// mr r27,r11
	r27.u64 = r11.u64;
	// ori r4,r9,45683
	ctx.r4.u64 = ctx.r9.u64 | 45683;
	// ori r10,r8,48729
	ctx.r10.u64 = ctx.r8.u64 | 48729;
	// mulhw r9,r27,r7
	ctx.r9.s64 = (int64_t(r27.s32) * int64_t(ctx.r7.s32)) >> 32;
	// mulhw r8,r11,r4
	ctx.r8.s64 = (int64_t(r11.s32) * int64_t(ctx.r4.s32)) >> 32;
	// mulhw r7,r11,r10
	ctx.r7.s64 = (int64_t(r11.s32) * int64_t(ctx.r10.s32)) >> 32;
	// srawi r9,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 6;
	// srawi r8,r8,14
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 14;
	// srawi r7,r7,20
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 20;
	// rlwinm r30,r8,1,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r10,0
	ctx.r10.s64 = 0;
	// rlwinm r29,r7,1,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// rlwinm r4,r9,1,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + r30.u64;
	// ori r10,r10,60000
	ctx.r10.u64 = ctx.r10.u64 | 60000;
	// add r7,r7,r29
	ctx.r7.u64 = ctx.r7.u64 + r29.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// mullw r4,r8,r10
	ctx.r4.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r8,r7,r31
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(r31.s32);
	// mulli r9,r9,1000
	ctx.r9.s64 = ctx.r9.s64 * 1000;
	// subf r7,r4,r11
	ctx.r7.s64 = r11.s64 - ctx.r4.s64;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// subf r4,r9,r27
	ctx.r4.s64 = r27.s64 - ctx.r9.s64;
	// li r8,10
	ctx.r8.s64 = 10;
	// lis r31,-32253
	r31.s64 = -2113732608;
	// divw r9,r4,r8
	ctx.r9.s32 = ctx.r4.s32 / ctx.r8.s32;
	// divw r8,r7,r28
	ctx.r8.s32 = ctx.r7.s32 / r28.s32;
	// addi r4,r31,-27084
	ctx.r4.s64 = r31.s64 + -27084;
	// divw r7,r11,r10
	ctx.r7.s32 = r11.s32 / ctx.r10.s32;
	// bl 0x823dc018
	ctx.lr = 0x8223DF20;
	sub_823DC018(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8223DF28:
	// divw. r10,r4,r28
	ctx.r10.s32 = ctx.r4.s32 / r28.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge 0x8223df3c
	if (!cr0.lt) goto loc_8223DF3C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r10,-27064
	ctx.r5.s64 = ctx.r10.s64 + -27064;
	// b 0x8223df44
	goto loc_8223DF44;
loc_8223DF3C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
loc_8223DF44:
	// lis r10,4194
	ctx.r10.s64 = 274857984;
	// lis r9,17895
	ctx.r9.s64 = 1172766720;
	// ori r8,r10,19923
	ctx.r8.u64 = ctx.r10.u64 | 19923;
	// ori r7,r9,45683
	ctx.r7.u64 = ctx.r9.u64 | 45683;
	// mulhw r6,r11,r8
	ctx.r6.s64 = (int64_t(r11.s32) * int64_t(ctx.r8.s32)) >> 32;
	// mulhw r4,r11,r7
	ctx.r4.s64 = (int64_t(r11.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r9,r6,6
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 6;
	// srawi r8,r4,14
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3FFF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 14;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// rlwinm r6,r8,1,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// lis r10,0
	ctx.r10.s64 = 0;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// ori r10,r10,60000
	ctx.r10.u64 = ctx.r10.u64 | 60000;
	// mulli r4,r7,1000
	ctx.r4.s64 = ctx.r7.s64 * 1000;
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// subf r9,r4,r11
	ctx.r9.s64 = r11.s64 - ctx.r4.s64;
	// subf r7,r6,r11
	ctx.r7.s64 = r11.s64 - ctx.r6.s64;
	// li r8,10
	ctx.r8.s64 = 10;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// divw r6,r11,r10
	ctx.r6.s32 = r11.s32 / ctx.r10.s32;
	// addi r4,r4,-27104
	ctx.r4.s64 = ctx.r4.s64 + -27104;
	// divw r8,r9,r8
	ctx.r8.s32 = ctx.r9.s32 / ctx.r8.s32;
	// divw r7,r7,r28
	ctx.r7.s32 = ctx.r7.s32 / r28.s32;
	// bl 0x823dc018
	ctx.lr = 0x8223DFA8;
	sub_823DC018(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8223DFB0"))) PPC_WEAK_FUNC(sub_8223DFB0);
PPC_FUNC_IMPL(__imp__sub_8223DFB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r9,-27060
	ctx.r4.s64 = ctx.r9.s64 + -27060;
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// b 0x825ee0e0
	sub_825EE0E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223DFD0"))) PPC_WEAK_FUNC(sub_8223DFD0);
PPC_FUNC_IMPL(__imp__sub_8223DFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r11,-27040
	ctx.r4.s64 = r11.s64 + -27040;
	// b 0x825ee188
	sub_825EE188(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223DFE0"))) PPC_WEAK_FUNC(sub_8223DFE0);
PPC_FUNC_IMPL(__imp__sub_8223DFE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r9,-27024
	ctx.r4.s64 = ctx.r9.s64 + -27024;
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// b 0x825ee0e0
	sub_825EE0E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8223E000"))) PPC_WEAK_FUNC(sub_8223E000);
PPC_FUNC_IMPL(__imp__sub_8223E000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8223E008;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r9,-27060
	ctx.r4.s64 = ctx.r9.s64 + -27060;
	// bl 0x825ee0e0
	ctx.lr = 0x8223E034;
	sub_825EE0E0(ctx, base);
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bgt cr6,0x8223e070
	if (cr6.gt) goto loc_8223E070;
	// lis r12,-32220
	r12.s64 = -2111569920;
	// addi r12,r12,-8108
	r12.s64 = r12.s64 + -8108;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_8223E108;
	case 1:
		goto loc_8223E064;
	case 2:
		goto loc_8223E0D4;
	case 3:
		goto loc_8223E0A0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-7928(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -7928);
	// lwz r17,-8092(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -8092);
	// lwz r17,-7980(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -7980);
	// lwz r17,-8032(r3)
	r17.u64 = PPC_LOAD_U32(ctx.r3.u32 + -8032);
loc_8223E064:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x8223de50
	ctx.lr = 0x8223E070;
	sub_8223DE50(ctx, base);
loc_8223E070:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r31,8
	ctx.r5.s64 = r31.s64 + 8;
	// addi r4,r11,-26960
	ctx.r4.s64 = r11.s64 + -26960;
	// bl 0x825ee2d8
	ctx.lr = 0x8223E084;
	sub_825EE2D8(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r10,-26972
	ctx.r4.s64 = ctx.r10.s64 + -26972;
	// bl 0x825ee0e0
	ctx.lr = 0x8223E098;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8223E0A0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-26988
	ctx.r4.s64 = ctx.r10.s64 + -26988;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8223E0B4;
	sub_82218310(ctx, base);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
loc_8223E0B8:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8223e0b8
	if (!cr6.eq) goto loc_8223E0B8;
	// b 0x8223e070
	goto loc_8223E070;
loc_8223E0D4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-27008
	ctx.r4.s64 = ctx.r10.s64 + -27008;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8223E0E8;
	sub_82218310(ctx, base);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
loc_8223E0EC:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8223e0ec
	if (!cr6.eq) goto loc_8223E0EC;
	// b 0x8223e070
	goto loc_8223E070;
loc_8223E108:
	// li r11,0
	r11.s64 = 0;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223E118"))) PPC_WEAK_FUNC(sub_8223E118);
PPC_FUNC_IMPL(__imp__sub_8223E118) {
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
	ctx.lr = 0x8223E120;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-26604
	r29.s64 = r11.s64 + -26604;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8223E140;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223E150;
	sub_825ED480(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r10,-26620
	r29.s64 = ctx.r10.s64 + -26620;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8223E168;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223E178;
	sub_825ED480(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r9,-26640
	r29.s64 = ctx.r9.s64 + -26640;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8223E190;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223E1A0;
	sub_825ED480(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r8,-26656
	r29.s64 = ctx.r8.s64 + -26656;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8223E1B8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223E1C8;
	sub_825ED480(ctx, base);
	// li r7,4
	ctx.r7.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8223E1DC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8223E1EC;
	sub_825ED480(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223E1FC"))) PPC_WEAK_FUNC(sub_8223E1FC);
PPC_FUNC_IMPL(__imp__sub_8223E1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223E200"))) PPC_WEAK_FUNC(sub_8223E200);
PPC_FUNC_IMPL(__imp__sub_8223E200) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r5,25
	cr6.compare<int32_t>(ctx.r5.s32, 25, xer);
	// bne cr6,0x8223e20c
	if (!cr6.eq) goto loc_8223E20C;
	// li r5,-1
	ctx.r5.s64 = -1;
loc_8223E20C:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// bne cr6,0x8223e224
	if (!cr6.eq) goto loc_8223E224;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_8223E224:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223E230"))) PPC_WEAK_FUNC(sub_8223E230);
PPC_FUNC_IMPL(__imp__sub_8223E230) {
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8223E238;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826337a8
	ctx.lr = 0x8223E254;
	sub_826337A8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-25560(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -25560);
	f0.f64 = double(temp.f32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f12,-25564(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -25564);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r8,r11,-26212
	ctx.r8.s64 = r11.s64 + -26212;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f10,14880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14880);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r7,-31280
	ctx.r9.s64 = ctx.r7.s64 + -31280;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f8,-26224(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26224);
	ctx.f8.f64 = double(temp.f32);
	// lis r3,-120
	ctx.r3.s64 = -7864320;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-26228(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26228);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// ori r6,r3,34952
	ctx.r6.u64 = ctx.r3.u64 | 34952;
	// lfs f30,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// lfs f11,-26232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26232);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r31,544
	r11.s64 = r31.s64 + 544;
	// lbz r7,176(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// lfs f9,-6172(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6172);
	ctx.f9.f64 = double(temp.f32);
	// li r8,16
	ctx.r8.s64 = 16;
	// clrlwi r5,r7,26
	ctx.r5.u64 = ctx.r7.u32 & 0x3F;
	// lfs f7,30712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30712);
	ctx.f7.f64 = double(temp.f32);
	// li r27,16
	r27.s64 = 16;
	// stb r5,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r5.u8);
	// stfs f31,208(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f31,212(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// stfs f31,216(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// li r28,32
	r28.s64 = 32;
	// stfs f31,224(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// li r7,48
	ctx.r7.s64 = 48;
	// stfs f31,228(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// li r29,48
	r29.s64 = 48;
	// stfs f31,232(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// stb r10,241(r31)
	PPC_STORE_U8(r31.u32 + 241, ctx.r10.u8);
	// lbz r5,240(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// clrlwi r5,r5,27
	ctx.r5.u64 = ctx.r5.u32 & 0x1F;
	// rlwinm r5,r5,0,30,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// addi r3,r31,624
	ctx.r3.s64 = r31.s64 + 624;
	// ori r5,r5,128
	ctx.r5.u64 = ctx.r5.u64 | 128;
	// stb r5,240(r31)
	PPC_STORE_U8(r31.u32 + 240, ctx.r5.u8);
	// stw r6,384(r31)
	PPC_STORE_U32(r31.u32 + 384, ctx.r6.u32);
	// stfs f0,480(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// stfs f13,484(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// stfs f12,488(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// stfs f30,492(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stfs f31,496(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stfs f11,500(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stfs f10,504(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// stfs f31,512(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// stfs f31,516(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// stfs f9,520(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// stb r10,536(r31)
	PPC_STORE_U8(r31.u32 + 536, ctx.r10.u8);
	// stfs f8,528(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stb r10,537(r31)
	PPC_STORE_U8(r31.u32 + 537, ctx.r10.u8);
	// stfs f7,532(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stb r30,538(r31)
	PPC_STORE_U8(r31.u32 + 538, r30.u8);
	// stb r10,539(r31)
	PPC_STORE_U8(r31.u32 + 539, ctx.r10.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,608(r31)
	PPC_STORE_U8(r31.u32 + 608, r30.u8);
	// stw r30,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r30.u32);
	// bl 0x8217d5e8
	ctx.lr = 0x8223E398;
	sub_8217D5E8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14184);
	f0.f64 = double(temp.f32);
	// stfs f0,1616(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1616, temp.u32);
	// lfs f29,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f29.f64 = double(temp.f32);
	// stfs f31,1632(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1632, temp.u32);
	// stfs f31,1636(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1636, temp.u32);
	// stfs f29,1640(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 1640, temp.u32);
	// stw r30,1648(r31)
	PPC_STORE_U32(r31.u32 + 1648, r30.u32);
	// lfs f0,-26236(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -26236);
	f0.f64 = double(temp.f32);
	// stfs f31,1664(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1664, temp.u32);
	// stfs f0,1668(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1668, temp.u32);
	// stfs f30,1672(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 1672, temp.u32);
	// bl 0x8262fd60
	ctx.lr = 0x8223E3DC;
	sub_8262FD60(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r8,-26252
	ctx.r3.s64 = ctx.r8.s64 + -26252;
	// bl 0x82723808
	ctx.lr = 0x8223E3E8;
	sub_82723808(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stw r3,244(r31)
	PPC_STORE_U32(r31.u32 + 244, ctx.r3.u32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// addi r6,r10,-31664
	ctx.r6.s64 = ctx.r10.s64 + -31664;
	// addi r9,r9,-31648
	ctx.r9.s64 = ctx.r9.s64 + -31648;
	// addi r8,r8,2240
	ctx.r8.s64 = ctx.r8.s64 + 2240;
	// addi r7,r7,2528
	ctx.r7.s64 = ctx.r7.s64 + 2528;
loc_8223E414:
	// addi r10,r11,25
	ctx.r10.s64 = r11.s64 + 25;
	// addi r4,r11,97
	ctx.r4.s64 = r11.s64 + 97;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stwx r5,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, ctx.r5.u32);
	// stfs f30,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f30,4(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f30,8(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// beq cr6,0x8223e45c
	if (cr6.eq) goto loc_8223E45C;
	// addi r10,r11,27
	ctx.r10.s64 = r11.s64 + 27;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// stfs f30,0(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f30,4(r10)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f29,8(r10)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// b 0x8223e46c
	goto loc_8223E46C;
loc_8223E45C:
	// stfs f29,432(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
	// addi r10,r31,432
	ctx.r10.s64 = r31.s64 + 432;
	// stfs f29,436(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 436, temp.u32);
	// stfs f29,440(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 440, temp.u32);
loc_8223E46C:
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r11,116
	ctx.r4.s64 = r11.s64 + 116;
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
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
	// vmulfp128 v58,v61,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f30,r3,r31
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, temp.u32);
	// blt cr6,0x8223e414
	if (cr6.lt) goto loc_8223E414;
	// vspltisw128 v57,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,256
	r11.s64 = r31.s64 + 256;
	// addi r10,r31,320
	ctx.r10.s64 = r31.s64 + 320;
	// stfs f31,248(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f31,252(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// vupkd3d128 v56,v57,4
	temp.f32 = 3.0f;
	temp.s32 += v57.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v57.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v56 = vTemp;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r26,r8,-26264
	r26.s64 = ctx.r8.s64 + -26264;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// vpermwi128 v55,v56,234
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x15));
	// vpermwi128 v54,v56,186
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x45));
	// vpermwi128 v53,v56,174
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x51));
	// vpermwi128 v52,v56,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x15));
	// vpermwi128 v51,v56,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x45));
	// vpermwi128 v50,v56,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x51));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-24728(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24728);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8223E544;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,1648(r31)
	PPC_STORE_U32(r31.u32 + 1648, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8223E578;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1648(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-21728
	ctx.r4.s64 = ctx.r10.s64 + -21728;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8223E590;
	sub_8218A568(ctx, base);
	// stw r3,1652(r31)
	PPC_STORE_U32(r31.u32 + 1652, ctx.r3.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r7,1648(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-26272
	ctx.r4.s64 = ctx.r8.s64 + -26272;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8223E5AC;
	sub_8218A568(ctx, base);
	// stw r3,1656(r31)
	PPC_STORE_U32(r31.u32 + 1656, ctx.r3.u32);
	// lwz r6,1648(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-27772
	ctx.r4.s64 = ctx.r4.s64 + -27772;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x8223E5C8;
	sub_8218B688(ctx, base);
	// stw r3,1660(r31)
	PPC_STORE_U32(r31.u32 + 1660, ctx.r3.u32);
	// bl 0x82178848
	ctx.lr = 0x8223E5D0;
	sub_82178848(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8223e5e8
	if (cr6.eq) goto loc_8223E5E8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-6164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6164);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8223e5f0
	goto loc_8223E5F0;
loc_8223E5E8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-6168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6168);
	ctx.f13.f64 = double(temp.f32);
loc_8223E5F0:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-26880(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26880);
	// lfs f0,700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 700);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8223e60c
	if (cr6.eq) goto loc_8223E60C;
	// fmr f30,f0
	f30.f64 = f0.f64;
	// b 0x8223e658
	goto loc_8223E658;
loc_8223E60C:
	// lfs f0,676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 676);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8223e658
	if (cr6.eq) goto loc_8223E658;
	// lwz r9,692(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f12,672(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 672);
	ctx.f12.f64 = double(temp.f32);
	// lwz r8,688(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fmuls f4,f6,f0
	ctx.f4.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmuls f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fdivs f30,f5,f4
	f30.f64 = double(float(ctx.f5.f64 / ctx.f4.f64));
loc_8223E658:
	// fdivs f0,f30,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 / ctx.f13.f64));
	// stfs f0,1676(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1676, temp.u32);
	// lwz r11,-26880(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26880);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lwz r9,688(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 688);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f11,648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 648);
	ctx.f11.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f8.u64);
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f7,96(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f4,1680(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 1680, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-80(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8223E6CC"))) PPC_WEAK_FUNC(sub_8223E6CC);
PPC_FUNC_IMPL(__imp__sub_8223E6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223E6D0"))) PPC_WEAK_FUNC(sub_8223E6D0);
PPC_FUNC_IMPL(__imp__sub_8223E6D0) {
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
	ctx.lr = 0x8223E6D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r30,40
	r30.s64 = 40;
	// addi r10,r11,-26212
	ctx.r10.s64 = r11.s64 + -26212;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// lwzx r11,r30,r29
	r11.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r9,r30,r29
	PPC_STORE_U32(r30.u32 + r29.u32, ctx.r9.u32);
	// beq cr6,0x8223e720
	if (cr6.eq) goto loc_8223E720;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223E720;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8223E720:
	// lwzx r11,r30,r29
	r11.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// addi r3,r31,624
	ctx.r3.s64 = r31.s64 + 624;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r11,r30,r29
	PPC_STORE_U32(r30.u32 + r29.u32, r11.u32);
	// bl 0x8217cb48
	ctx.lr = 0x8223E734;
	sub_8217CB48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8223E73C;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223E744"))) PPC_WEAK_FUNC(sub_8223E744);
PPC_FUNC_IMPL(__imp__sub_8223E744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223E748"))) PPC_WEAK_FUNC(sub_8223E748);
PPC_FUNC_IMPL(__imp__sub_8223E748) {
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
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8223E750;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r11,-25196
	ctx.r5.s64 = r11.s64 + -25196;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,537
	ctx.r6.s64 = r31.s64 + 537;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8223E77C;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r10,-25212
	ctx.r5.s64 = ctx.r10.s64 + -25212;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,538
	ctx.r6.s64 = r31.s64 + 538;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8223E79C;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r9,-25236
	ctx.r5.s64 = ctx.r9.s64 + -25236;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,539
	ctx.r6.s64 = r31.s64 + 539;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8223E7BC;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r8,-25252
	ctx.r5.s64 = ctx.r8.s64 + -25252;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,528
	ctx.r6.s64 = r31.s64 + 528;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223E7DC;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r7,-25272
	ctx.r5.s64 = ctx.r7.s64 + -25272;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,496
	ctx.r6.s64 = r31.s64 + 496;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8223E7FC;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r6,-25288
	ctx.r5.s64 = ctx.r6.s64 + -25288;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,512
	ctx.r6.s64 = r31.s64 + 512;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8223E81C;
	sub_824DF200(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r5,-25312
	ctx.r5.s64 = ctx.r5.s64 + -25312;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,480
	ctx.r6.s64 = r31.s64 + 480;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8223E83C;
	sub_824DF200(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r4,-25336
	ctx.r5.s64 = ctx.r4.s64 + -25336;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,384
	ctx.r6.s64 = r31.s64 + 384;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x8223E85C;
	sub_824DF200(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r11,-25356
	ctx.r5.s64 = r11.s64 + -25356;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,241
	ctx.r6.s64 = r31.s64 + 241;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8223E87C;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-25376
	ctx.r5.s64 = ctx.r10.s64 + -25376;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,536
	ctx.r6.s64 = r31.s64 + 536;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8223E89C;
	sub_824DF200(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r9,-25392
	ctx.r5.s64 = ctx.r9.s64 + -25392;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1616
	ctx.r6.s64 = r31.s64 + 1616;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8223E8BC;
	sub_824DF200(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r8,-25408
	ctx.r5.s64 = ctx.r8.s64 + -25408;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1632
	ctx.r6.s64 = r31.s64 + 1632;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8223E8DC;
	sub_824DF200(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r7,-25432
	ctx.r5.s64 = ctx.r7.s64 + -25432;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1664
	ctx.r6.s64 = r31.s64 + 1664;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8223E8FC;
	sub_824DF200(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-25452
	ctx.r5.s64 = ctx.r6.s64 + -25452;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1672
	ctx.r6.s64 = r31.s64 + 1672;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8223E91C;
	sub_824DF200(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r28,r31,464
	r28.s64 = r31.s64 + 464;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r31,432
	r31.s64 = r31.s64 + 432;
	// addi r27,r11,-31664
	r27.s64 = r11.s64 + -31664;
	// addi r26,r10,-31648
	r26.s64 = ctx.r10.s64 + -31648;
	// addi r25,r9,2240
	r25.s64 = ctx.r9.s64 + 2240;
	// addi r24,r8,2528
	r24.s64 = ctx.r8.s64 + 2528;
	// addi r23,r7,-25476
	r23.s64 = ctx.r7.s64 + -25476;
	// addi r22,r6,-25504
	r22.s64 = ctx.r6.s64 + -25504;
	// addi r21,r5,-25532
	r21.s64 = ctx.r5.s64 + -25532;
	// addi r20,r4,-25556
	r20.s64 = ctx.r4.s64 + -25556;
loc_8223E968:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8223E978;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r28,-76
	ctx.r6.s64 = r28.s64 + -76;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8223E994;
	sub_824DF200(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8223E9A4;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,-32
	ctx.r6.s64 = r31.s64 + -32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8223E9C0;
	sub_824DF200(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8223E9D0;
	sub_823DC018(ctx, base);
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,0
	ctx.r8.s64 = 0;
	// lvx128 v13,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,1
	ctx.r7.s64 = 1;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
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
	// vmulfp128 v58,v61,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824df200
	ctx.lr = 0x8223EA30;
	sub_824DF200(ctx, base);
	// lvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v57,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lvx128 v13,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v4,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v3,v55,v62
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v2,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vsel v0,v2,v5,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v63,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v4,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v54,v57,v29
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dc018
	ctx.lr = 0x8223EA84;
	sub_823DC018(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824df200
	ctx.lr = 0x8223EAA0;
	sub_824DF200(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// blt cr6,0x8223e968
	if (cr6.lt) goto loc_8223E968;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8223EABC"))) PPC_WEAK_FUNC(sub_8223EABC);
PPC_FUNC_IMPL(__imp__sub_8223EABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8223EAC0"))) PPC_WEAK_FUNC(sub_8223EAC0);
PPC_FUNC_IMPL(__imp__sub_8223EAC0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r8,r11,62
	ctx.r8.s64 = r11.s64 + 62;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// rlwinm r30,r8,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8223EB00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223eb7c
	if (cr6.eq) goto loc_8223EB7C;
	// lbz r11,240(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223eb28
	if (cr6.eq) goto loc_8223EB28;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223eb7c
	if (cr6.eq) goto loc_8223EB7C;
loc_8223EB28:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223eb7c
	if (cr6.eq) goto loc_8223EB7C;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223eb7c
	if (cr6.eq) goto loc_8223EB7C;
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8223eb7c
	if (!cr6.eq) goto loc_8223EB7C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfsx f13,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8223eb7c
	if (!cr6.lt) goto loc_8223EB7C;
	// lfs f13,532(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 532);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r30,r31
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f13,f31,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f31.f64 + ctx.f12.f64));
	// stfsx f11,r30,r31
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + r31.u32, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x8223ec0c
	if (!cr6.gt) goto loc_8223EC0C;
	// b 0x8223ec08
	goto loc_8223EC08;
loc_8223EB7C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223EB90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223ebdc
	if (cr6.eq) goto loc_8223EBDC;
	// lbz r11,240(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ebb8
	if (cr6.eq) goto loc_8223EBB8;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ebdc
	if (cr6.eq) goto loc_8223EBDC;
loc_8223EBB8:
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ebdc
	if (cr6.eq) goto loc_8223EBDC;
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223ebdc
	if (cr6.eq) goto loc_8223EBDC;
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223ec0c
	if (cr6.eq) goto loc_8223EC0C;
loc_8223EBDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfsx f13,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8223ec0c
	if (!cr6.gt) goto loc_8223EC0C;
	// lfs f13,532(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 532);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r30,r31
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f11,f13,f31,f12
	ctx.f11.f64 = double(float(-(ctx.f13.f64 * f31.f64 - ctx.f12.f64)));
	// stfsx f11,r30,r31
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + r31.u32, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x8223ec0c
	if (!cr6.lt) goto loc_8223EC0C;
loc_8223EC08:
	// stfsx f0,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + r31.u32, temp.u32);
loc_8223EC0C:
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

__attribute__((alias("__imp__sub_8223EC28"))) PPC_WEAK_FUNC(sub_8223EC28);
PPC_FUNC_IMPL(__imp__sub_8223EC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x8223EC3C;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8217fff8
	ctx.lr = 0x8223EC48;
	sub_8217FFF8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8223ec60
	if (!cr6.lt) goto loc_8223EC60;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8223EC60:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x8223EC68;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x8223EC74;
	sub_8217F768(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8223EC80;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8223EC8C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8223EC98;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8223ECA4;
	sub_8217F768(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217fd68
	ctx.lr = 0x8223ECB0;
	sub_8217FD68(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217fe58
	ctx.lr = 0x8223ECBC;
	sub_8217FE58(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8223ECC8;
	sub_8217F768(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8223ECDC;
	sub_8217C088(ctx, base);
	// lwz r11,1648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r5,1652(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1652);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,-22084(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -22084);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8223ECF8;
	sub_82189CE0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8223ED04;
	sub_8217F768(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f12,1672(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1672);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lfs f11,1676(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1676);
	ctx.f11.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r11,-26880(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -26880);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f0,-25176(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -25176);
	f0.f64 = double(temp.f32);
	// lwz r10,22080(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 22080);
	// lfs f31,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// addi r10,r10,62
	ctx.r10.s64 = ctx.r10.s64 + 62;
	// lfs f30,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lwz r9,692(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 692);
	// lfs f13,652(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 652);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// lfd f10,128(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lfsx f1,r11,r31
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// lfs f13,27580(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27580);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f6.u64);
	// lwz r7,132(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// lfd f5,128(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// frsp f29,f4
	f29.f64 = double(float(ctx.f4.f64));
	// fmuls f3,f12,f29
	ctx.f3.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fsubs f0,f31,f2
	f0.f64 = double(float(f31.f64 - ctx.f2.f64));
	// fsel f12,f0,f31,f2
	ctx.f12.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f2.f64;
	// fmuls f11,f11,f12
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f0,-740(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -740);
	f0.f64 = double(temp.f32);
	// fmuls f27,f12,f0
	f27.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f9.u64);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r3.u64);
	// lfd f8,128(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f28,f7
	f28.f64 = double(float(ctx.f7.f64));
	// beq cr6,0x8223edfc
	if (cr6.eq) goto loc_8223EDFC;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x8223edfc
	if (cr6.eq) goto loc_8223EDFC;
	// lbz r11,241(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 241);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223edfc
	if (cr6.eq) goto loc_8223EDFC;
	// bl 0x82227ce8
	ctx.lr = 0x8223EDEC;
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
loc_8223EDFC:
	// stfs f1,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r11,1648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,1656(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1656);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8223EE24;
	sub_8218A6E0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,1668(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1668);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,1648(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1648);
	// li r11,-1
	r11.s64 = -1;
	// lfs f11,1680(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1680);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r31,1660
	ctx.r9.s64 = r31.s64 + 1660;
	// fadds f3,f11,f28
	ctx.f3.f64 = double(float(ctx.f11.f64 + f28.f64));
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f0,-25180(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -25180);
	f0.f64 = double(temp.f32);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// fmuls f0,f29,f0
	f0.f64 = double(float(f29.f64 * f0.f64));
	// stb r8,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r8.u8);
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// fsubs f1,f11,f28
	ctx.f1.f64 = double(float(ctx.f11.f64 - f28.f64));
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// lwz r3,-12280(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12280);
	// fmadds f12,f13,f29,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f29.f64 + f0.f64));
	// fctiwz f10,f12
	ctx.f10.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.f10.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f4,128(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fadds f2,f12,f27
	ctx.f2.f64 = double(float(ctx.f12.f64 + f27.f64));
	// fctiwz f0,f2
	f0.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f0,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, f0.u64);
	// lwz r11,132(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f13,128(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f11,f4
	ctx.f11.f64 = double(ctx.f4.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f4,f12
	ctx.f4.f64 = double(float(ctx.f12.f64));
	// frsp f2,f11
	ctx.f2.f64 = double(float(ctx.f11.f64));
	// bl 0x823083f8
	ctx.lr = 0x8223EEC8;
	sub_823083F8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8223EED4;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8223EEE0;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x8223EEEC;
	sub_8217F768(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x8223EEF8;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8223EF08"))) PPC_WEAK_FUNC(sub_8223EF08);
PPC_FUNC_IMPL(__imp__sub_8223EF08) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223EF30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,464(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 464);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8223EF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,608(r31)
	PPC_STORE_U8(r31.u32 + 608, ctx.r7.u8);
	// lwz r5,608(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 608);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8223EF64;
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

__attribute__((alias("__imp__sub_8223EF78"))) PPC_WEAK_FUNC(sub_8223EF78);
PPC_FUNC_IMPL(__imp__sub_8223EF78) {
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
	// bl 0x8223e6d0
	ctx.lr = 0x8223EF98;
	sub_8223E6D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223efb0
	if (cr6.eq) goto loc_8223EFB0;
	// bl 0x82130588
	ctx.lr = 0x8223EFAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8223EFB0:
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

__attribute__((alias("__imp__sub_8223EFC8"))) PPC_WEAK_FUNC(sub_8223EFC8);
PPC_FUNC_IMPL(__imp__sub_8223EFC8) {
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
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
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
	// bl 0x823d91fc
	ctx.lr = 0x8223EFD0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lvx128 v61,r4,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v60,r4,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x821713c0
	ctx.lr = 0x8223F060;
	sub_821713C0(ctx, base);
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223f098
	if (cr6.eq) goto loc_8223F098;
	// lis r10,-12851
	ctx.r10.s64 = -842203136;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// ori r9,r10,52685
	ctx.r9.u64 = ctx.r10.u64 | 52685;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beq cr6,0x8223f090
	if (cr6.eq) goto loc_8223F090;
	// lis r10,-8739
	ctx.r10.s64 = -572719104;
	// ori r9,r10,56797
	ctx.r9.u64 = ctx.r10.u64 | 56797;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x8223f098
	if (!cr6.eq) goto loc_8223F098;
loc_8223F090:
	// li r11,0
	r11.s64 = 0;
	// stw r11,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r11.u32);
loc_8223F098:
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223f0ac
	if (cr6.eq) goto loc_8223F0AC;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8223f0b4
	goto loc_8223F0B4;
loc_8223F0AC:
	// li r11,208
	r11.s64 = 208;
	// lvx128 v59,r31,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8223F0B4:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vspltisw128 v58,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r9,2384
	ctx.r6.s64 = ctx.r9.s64 + 2384;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v63,v62
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// vmrglw128 v56,v63,v62
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r3,r5,2352
	ctx.r3.s64 = ctx.r5.s64 + 2352;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v59,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v54,v61,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lwz r11,-17936(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -17936);
	// vmrglw128 v53,v61,v60
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// vor128 v52,v63,v55
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// addi r7,r10,2528
	ctx.r7.s64 = ctx.r10.s64 + 2528;
	// vmrglw128 v51,v57,v54
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// rlwinm r11,r8,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// vmrghw128 v50,v57,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r5,r9,2240
	ctx.r5.s64 = ctx.r9.s64 + 2240;
	// vmrghw128 v49,v56,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// vmsum4fp128 v48,v52,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// addi r10,r11,32
	ctx.r10.s64 = r11.s64 + 32;
	// vmsum4fp128 v47,v52,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// vmsum4fp128 v46,v52,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r8,r4,-31664
	ctx.r8.s64 = ctx.r4.s64 + -31664;
	// addi r29,r3,-31648
	r29.s64 = ctx.r3.s64 + -31648;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// addi r3,r4,-31616
	ctx.r3.s64 = ctx.r4.s64 + -31616;
	// vmrghw128 v45,v48,v52
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v47,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v63,v44,v45
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vsubfp128 v43,v58,v63
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v42,v43,v43
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v41,v42,v42
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v40,v41
	simde_mm_store_ps(v40.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v41.f32))));
	// vor128 v12,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vcmpeqfp128 v11,v40,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
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
	// vmulfp128 v39,v42,v6
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v38,v39,v39
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_load_si128((simde__m128i*)v39.u8));
	// stvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v36,v63,135
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vpermwi128 v37,v38,99
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x9C));
	// vpermwi128 v5,v38,135
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x78));
	// vpermwi128 v4,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v35,v38,135
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x78));
	// vmulfp128 v3,v36,v37
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// vpermwi128 v2,v38,99
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0x9C));
	// vnmsubfp v0,v4,v5,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v34,v0,v0
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v33,v34
	simde_mm_store_ps(v33.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v34.f32))));
	// lvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v31,v34,v34
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v34.u8));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvlx128 v32,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v32,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), 0xFF));
	// vcmpeqfp128 v30,v33,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v29,v33,v33
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_load_si128((simde__m128i*)v33.u8));
	// vsel v13,v29,v1,v30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8))));
	// vmulfp128 v28,v13,v13
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v27,v63,v13
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v26,v31,v28,v12
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v25,v26,v27,v13
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v60,v0,v25
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v25.f32)));
	// vpermwi128 v59,v60,99
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x9C));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v24,v60,135
	simde_mm_store_si128((simde__m128i*)v24.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x78));
	// vmulfp128 v23,v35,v59
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v59.f32)));
	// vnmsubfp v22,v2,v24,v23
	simde_mm_store_ps(v22.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(v23.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor128 v58,v22,v22
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v22.u8));
	// stvx128 v22,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r0,r5
	simde_mm_store_si128((simde__m128i*)v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v58,v58
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v20,v57,v57
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vcmpeqfp128 v19,v56,v63
	simde_mm_store_ps(v19.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v18,v56,v56
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v18,v21,v19
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v19.u8), simde_mm_load_si128((simde__m128i*)v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v19.u8), simde_mm_load_si128((simde__m128i*)v21.u8))));
	// vmulfp128 v17,v0,v0
	simde_mm_store_ps(v17.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v16,v62,v0
	simde_mm_store_ps(v16.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v15,v20,v17,v13
	simde_mm_store_ps(v15.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v20.f32), simde_mm_load_ps(v17.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v14,v15,v16,v0
	simde_mm_store_ps(v14.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v15.f32), simde_mm_load_ps(v16.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v58,v14
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v14.f32)));
	// stvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x8223F2A8;
	sub_8216C9C0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r4,r8,-25172
	ctx.r4.s64 = ctx.r8.s64 + -25172;
	// lfs f0,-25152(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -25152);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// bl 0x825ee188
	ctx.lr = 0x8223F2C4;
	sub_825EE188(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8223F2D0"))) PPC_WEAK_FUNC(sub_8223F2D0);
PPC_FUNC_IMPL(__imp__sub_8223F2D0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8223F2EC;
	sub_82630980(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8223F2F0;
	sub_82387B90(ctx, base);
	// lwz r11,1204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1204);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8223f30c
	if (cr6.lt) goto loc_8223F30C;
	// li r30,0
	r30.s64 = 0;
	// bne cr6,0x8223f310
	if (!cr6.eq) goto loc_8223F310;
	// li r11,1
	r11.s64 = 1;
	// b 0x8223f314
	goto loc_8223F314;
loc_8223F30C:
	// li r30,1
	r30.s64 = 1;
loc_8223F310:
	// li r11,0
	r11.s64 = 0;
loc_8223F314:
	// lbz r10,240(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwimi r10,r9,4,27,27
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 4) & 0x10) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFEF);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r7,r8,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// stb r8,240(r31)
	PPC_STORE_U8(r31.u32 + 240, ctx.r8.u8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8223f344
	if (cr6.eq) goto loc_8223F344;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223f3ac
	if (cr6.eq) goto loc_8223F3AC;
loc_8223F344:
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223f370
	if (cr6.eq) goto loc_8223F370;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// addi r4,r10,-25148
	ctx.r4.s64 = ctx.r10.s64 + -25148;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r5,r8,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// b 0x8223f3b8
	goto loc_8223F3B8;
loc_8223F370:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8223F384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8223f3ac
	if (cr6.eq) goto loc_8223F3AC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,-25148
	ctx.r4.s64 = ctx.r10.s64 + -25148;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// b 0x8223f3b8
	goto loc_8223F3B8;
loc_8223F3AC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-25148
	ctx.r4.s64 = r11.s64 + -25148;
loc_8223F3B8:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// bl 0x825ee0e0
	ctx.lr = 0x8223F3C0;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_8223F3D8"))) PPC_WEAK_FUNC(sub_8223F3D8);
PPC_FUNC_IMPL(__imp__sub_8223F3D8) {
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
	PPCRegister f31{};
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
	// bl 0x823d91dc
	ctx.lr = 0x8223F3E0;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r27,r31,624
	r27.s64 = r31.s64 + 624;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// bl 0x8217c658
	ctx.lr = 0x8223F408;
	sub_8217C658(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x8218f308
	ctx.lr = 0x8223F418;
	sub_8218F308(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,384(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 384);
	// addi r10,r31,432
	ctx.r10.s64 = r31.s64 + 432;
	// addi r11,r1,456
	r11.s64 = ctx.r1.s64 + 456;
	// rlwinm r3,r6,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r5,r6,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFF;
	// lfs f0,15364(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15364);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r6,8,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// std r5,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r5.u64);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// clrlwi r7,r6,24
	ctx.r7.u64 = ctx.r6.u32 & 0xFF;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f10,104(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// addi r9,r31,388
	ctx.r9.s64 = r31.s64 + 388;
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// li r8,2
	ctx.r8.s64 = 2;
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// li r28,-32
	r28.s64 = -32;
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// li r30,-24
	r30.s64 = -24;
	// li r3,-40
	ctx.r3.s64 = -40;
	// li r29,0
	r29.s64 = 0;
	// addi r7,r7,-31664
	ctx.r7.s64 = ctx.r7.s64 + -31664;
	// addi r6,r6,-31648
	ctx.r6.s64 = ctx.r6.s64 + -31648;
	// addi r5,r5,2240
	ctx.r5.s64 = ctx.r5.s64 + 2240;
	// addi r4,r4,2528
	ctx.r4.s64 = ctx.r4.s64 + 2528;
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,616(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,612(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,608(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,620(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 620, temp.u32);
loc_8223F4D8:
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r23,0(r9)
	r23.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r22,r23,16,24,31
	r22.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 16) & 0xFF;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r21,r23,24,24,31
	r21.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 24) & 0xFF;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r23,r23,24
	r23.u64 = r23.u32 & 0xFF;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r21,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r21.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r23,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r23.u64);
	// lfd f11,128(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// std r22,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r22.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// lvx128 v59,r10,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v58,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// fcfid f10,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(ctx.f11.s64);
	// stb r29,20(r11)
	PPC_STORE_U8(r11.u32 + 20, r29.u8);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// vcmpeqfp128 v11,v58,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// frsp f6,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f2,-8(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f4,0(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,-4(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v59,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v61,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v56,v57,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,76(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stfs f1,12(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stvx128 v56,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8223f4d8
	if (!cr0.eq) goto loc_8223F4D8;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// bl 0x821800a0
	ctx.lr = 0x8223F5AC;
	sub_821800A0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217d928
	ctx.lr = 0x8223F5B4;
	sub_8217D928(ctx, base);
	// li r11,528
	r11.s64 = 528;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lbz r9,536(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 536);
	// li r8,512
	ctx.r8.s64 = 512;
	// addi r28,r10,-31280
	r28.s64 = ctx.r10.s64 + -31280;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvlx128 v55,r31,r11
	temp.u32 = r31.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v53,r31,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,144
	r23.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r28,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// vmulfp128 v63,v63,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32)));
	// li r6,32
	ctx.r6.s64 = 32;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vmulfp128 v62,v62,v54
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v54.f32)));
	// li r30,16
	r30.s64 = 16;
	// vmulfp128 v60,v53,v54
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)));
	// li r22,496
	r22.s64 = 496;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lvx128 v61,r28,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,22080(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 22080);
	// vmulfp128 v61,v61,v54
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v54.f32)));
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// lvx128 v49,r31,r22
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// rlwinm r11,r6,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// li r6,32
	ctx.r6.s64 = 32;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// vspltw128 v52,v63,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v10,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// li r3,1
	ctx.r3.s64 = 1;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v51,v62,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v9,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v50,v61,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v4,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// li r8,1
	ctx.r8.s64 = 1;
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v11,r11,r5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// lvx128 v13,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v28,v62,2
	simde_mm_store_si128((simde__m128i*)v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v8,v0,v52
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vmulfp128 v7,v0,v51
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v51.f32)));
	// vspltw128 v26,v61,2
	simde_mm_store_si128((simde__m128i*)v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmaddfp v3,v0,v12,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v5,v0,v50
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v50.f32)));
	// lvx128 v0,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v0,v10,v8
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// vmaddfp v31,v0,v6,v7
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// vmaddfp v27,v0,v9,v3
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// addi r30,r10,1
	r30.s64 = ctx.r10.s64 + 1;
	// vmaddfp v29,v0,v4,v5
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v1,v2
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v24,v13,v28,v31
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(v31.f32)));
	// vmaddfp v22,v13,v30,v27
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v23,v13,v26,v29
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(v29.f32)));
	// stvx128 v25,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v48,v22,v49
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v23,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217fed0
	ctx.lr = 0x8223F6F4;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,1
	ctx.r3.s64 = 1;
	// std r11,276(r1)
	PPC_STORE_U64(ctx.r1.u32 + 276, r11.u64);
	// bl 0x8217f768
	ctx.lr = 0x8223F70C;
	sub_8217F768(ctx, base);
	// li r10,25
	ctx.r10.s64 = 25;
	// li r3,25
	ctx.r3.s64 = 25;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x8217fed0
	ctx.lr = 0x8223F71C;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// ld r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,25
	ctx.r3.s64 = 25;
	// std r9,284(r1)
	PPC_STORE_U64(ctx.r1.u32 + 284, ctx.r9.u64);
	// bl 0x8217f768
	ctx.lr = 0x8223F734;
	sub_8217F768(ctx, base);
	// li r8,23
	ctx.r8.s64 = 23;
	// li r3,23
	ctx.r3.s64 = 23;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x8217fed0
	ctx.lr = 0x8223F744;
	sub_8217FED0(ctx, base);
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// ld r7,96(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,23
	ctx.r3.s64 = 23;
	// std r7,292(r1)
	PPC_STORE_U64(ctx.r1.u32 + 292, ctx.r7.u64);
	// bl 0x8217f768
	ctx.lr = 0x8223F75C;
	sub_8217F768(ctx, base);
	// li r6,12
	ctx.r6.s64 = 12;
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// bl 0x8217fed0
	ctx.lr = 0x8223F76C;
	sub_8217FED0(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// li r3,12
	ctx.r3.s64 = 12;
	// stw r4,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r4.u32);
	// std r11,300(r1)
	PPC_STORE_U64(ctx.r1.u32 + 300, r11.u64);
	// lfs f0,-26276(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26276);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x8217f768
	ctx.lr = 0x8223F798;
	sub_8217F768(ctx, base);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r10,2256
	ctx.r9.s64 = ctx.r10.s64 + 2256;
	// lvx128 v47,r0,r26
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r6,-31616
	ctx.r5.s64 = ctx.r6.s64 + -31616;
	// vsubfp128 v46,v63,v47
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v46,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8223F7D0;
	sub_82202EC0(ctx, base);
	// lis r30,-32131
	r30.s64 = -2105737216;
	// li r11,1
	r11.s64 = 1;
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r11,17292(r30)
	PPC_STORE_U8(r30.u32 + 17292, r11.u8);
	// lwz r3,-26876(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8223F7EC;
	sub_8217C088(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217ce80
	ctx.lr = 0x8223F7F8;
	sub_8217CE80(ctx, base);
	// li r3,480
	ctx.r3.s64 = 480;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,17292(r30)
	PPC_STORE_U8(r30.u32 + 17292, r11.u8);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v45,r31,r3
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r3,244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f0,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82723940
	ctx.lr = 0x8223F848;
	sub_82723940(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d928
	ctx.lr = 0x8223F850;
	sub_8217D928(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8217c658
	ctx.lr = 0x8223F85C;
	sub_8217C658(ctx, base);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x82491668
	ctx.lr = 0x8223F864;
	sub_82491668(ctx, base);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8223F870"))) PPC_WEAK_FUNC(sub_8223F870);
PPC_FUNC_IMPL(__imp__sub_8223F870) {
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
	PPCRegister f31{};
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
	// bl 0x823d91f0
	ctx.lr = 0x8223F878;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r10,2048
	ctx.r10.s64 = 134217728;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,8192
	r11.s64 = 536870912;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bne cr6,0x8223f9bc
	if (!cr6.eq) goto loc_8223F9BC;
	// lbz r10,539(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 539);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223fa08
	if (cr6.eq) goto loc_8223FA08;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r11,62
	ctx.r9.s64 = r11.s64 + 62;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8223fbe0
	if (!cr6.gt) goto loc_8223FBE0;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,-22080(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -22080);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,-22084(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + -22084);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8223F904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x8223F928;
	sub_82178370(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f2,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// addi r3,r31,624
	ctx.r3.s64 = r31.s64 + 624;
	// lfs f1,1616(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1616);
	ctx.f1.f64 = double(temp.f32);
	// lfs f4,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x8223F948;
	sub_8217D460(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r31,1632
	ctx.r4.s64 = r31.s64 + 1632;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8223f3d8
	ctx.lr = 0x8223F95C;
	sub_8223F3D8(ctx, base);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stb r11,151(r1)
	PPC_STORE_U8(ctx.r1.u32 + 151, r11.u8);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stb r11,152(r1)
	PPC_STORE_U8(ctx.r1.u32 + 152, r11.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// stb r30,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, r30.u8);
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r30.u8);
	// stb r30,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r30.u8);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8223F9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8223F9BC:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x8223fa08
	if (!cr6.eq) goto loc_8223FA08;
	// lbz r10,539(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 539);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223fa08
	if (cr6.eq) goto loc_8223FA08;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r11,62
	ctx.r9.s64 = r11.s64 + 62;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8223fbe0
	if (!cr6.gt) goto loc_8223FBE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8223ec28
	ctx.lr = 0x8223F9FC;
	sub_8223EC28(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8223FA08:
	// lbz r10,537(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 537);
	// lis r28,16
	r28.s64 = 1048576;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223fa20
	if (cr6.eq) goto loc_8223FA20;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// beq cr6,0x8223fa34
	if (cr6.eq) goto loc_8223FA34;
loc_8223FA20:
	// lbz r10,538(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 538);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8223fbe0
	if (cr6.eq) goto loc_8223FBE0;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bne cr6,0x8223fbe0
	if (!cr6.eq) goto loc_8223FBE0;
loc_8223FA34:
	// lis r26,-32130
	r26.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,22080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 22080);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r9,r11,62
	ctx.r9.s64 = r11.s64 + 62;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r8,r31
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8223faa0
	if (cr6.gt) goto loc_8223FAA0;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r7,r31,544
	ctx.r7.s64 = r31.s64 + 544;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r7,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8223FAA0:
	// lis r27,-32124
	r27.s64 = -2105278464;
	// li r10,592
	ctx.r10.s64 = 592;
	// li r9,112
	ctx.r9.s64 = 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lwz r11,-26876(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// addi r30,r31,544
	r30.s64 = r31.s64 + 544;
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,64
	ctx.r4.s64 = r11.s64 + 64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-7896(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -7896);
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822e8448
	ctx.lr = 0x8223FAE0;
	sub_822E8448(ctx, base);
	// lwz r11,-26876(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -26876);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r29,r6
	cr6.compare<int32_t>(r29.s32, ctx.r6.s32, xer);
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8223fb44
	if (cr6.eq) goto loc_8223FB44;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178370
	ctx.lr = 0x8223FB44;
	sub_82178370(ctx, base);
loc_8223FB44:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-26880(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26880);
	// bl 0x82171600
	ctx.lr = 0x8223FB50;
	sub_82171600(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r3,r31,624
	ctx.r3.s64 = r31.s64 + 624;
	// lfs f1,14184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14184);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x8223FB74;
	sub_8217D460(ctx, base);
	// lwz r11,22080(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 22080);
	// addi r7,r11,62
	ctx.r7.s64 = r11.s64 + 62;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + r31.u32);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x8223fbbc
	if (cr6.eq) goto loc_8223FBBC;
	// lfs f0,7444(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x8223fbbc
	if (cr6.eq) goto loc_8223FBBC;
	// lbz r11,241(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 241);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8223fbbc
	if (cr6.eq) goto loc_8223FBBC;
	// bl 0x82227ce8
	ctx.lr = 0x8223FBA8;
	sub_82227CE8(ctx, base);
	// lfs f0,7444(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 - ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8223FBBC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8223f3d8
	ctx.lr = 0x8223FBE0;
	sub_8223F3D8(ctx, base);
loc_8223FBE0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

