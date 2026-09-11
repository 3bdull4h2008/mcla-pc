#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_826D56F0) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826D56F8;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-2480(r1)
	ea = -2480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r3,r26,8800
	ctx.r3.s64 = r26.s64 + 8800;
	// bl 0x826ed338
	ctx.lr = 0x826D5718;
	sub_826ED338(ctx, base);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5a0c
	if (cr6.eq) goto loc_826D5A0C;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r23,0
	r23.s64 = 0;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lfs f31,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r22,r23
	r22.u64 = r23.u64;
	// li r25,1
	r25.s64 = 1;
	// addi r31,r11,23056
	r31.s64 = r11.s64 + 23056;
	// addi r30,r10,-18952
	r30.s64 = ctx.r10.s64 + -18952;
	// addi r24,r9,3816
	r24.s64 = ctx.r9.s64 + 3816;
	// addi r28,r8,3832
	r28.s64 = ctx.r8.s64 + 3832;
loc_826D5758:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r22,r11
	r11.u64 = r22.u64 + r11.u64;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d58a4
	if (cr6.eq) goto loc_826D58A4;
loc_826D576C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826e9620
	ctx.lr = 0x826D577C;
	sub_826E9620(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d579c
	if (cr6.eq) goto loc_826D579C;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D579C:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57b8
	if (cr6.eq) goto loc_826D57B8;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D57B8:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57d4
	if (cr6.eq) goto loc_826D57D4;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d57f0
	if (!cr6.eq) goto loc_826D57F0;
loc_826D57D4:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d57f8
	if (cr6.eq) goto loc_826D57F8;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d57f8
	if (cr6.eq) goto loc_826D57F8;
loc_826D57F0:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x826d57fc
	goto loc_826D57FC;
loc_826D57F8:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_826D57FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5898
	if (cr6.eq) goto loc_826D5898;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// bl 0x82687930
	ctx.lr = 0x826D5810;
	sub_82687930(ctx, base);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r1,2080
	ctx.r3.s64 = ctx.r1.s64 + 2080;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826df370
	ctx.lr = 0x826D5820;
	sub_826DF370(ctx, base);
	// stb r23,944(r1)
	PPC_STORE_U8(ctx.r1.u32 + 944, r23.u8);
	// stw r25,948(r1)
	PPC_STORE_U32(ctx.r1.u32 + 948, r25.u32);
	// addi r3,r1,960
	ctx.r3.s64 = ctx.r1.s64 + 960;
	// bl 0x82687930
	ctx.lr = 0x826D5830;
	sub_82687930(ctx, base);
	// lbz r11,1252(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1252);
	// stfs f31,1248(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 1248, temp.u32);
	// stw r28,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r28.u32);
	// rlwinm r11,r11,0,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// stb r11,1252(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1252, r11.u8);
	// bl 0x82761678
	ctx.lr = 0x826D584C;
	sub_82761678(ctx, base);
	// addi r3,r1,1488
	ctx.r3.s64 = ctx.r1.s64 + 1488;
	// bl 0x826d4fd0
	ctx.lr = 0x826D5854;
	sub_826D4FD0(ctx, base);
	// addi r4,r1,2080
	ctx.r4.s64 = ctx.r1.s64 + 2080;
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// bl 0x826e0140
	ctx.lr = 0x826D5860;
	sub_826E0140(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,944
	ctx.r3.s64 = ctx.r1.s64 + 944;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826e0438
	ctx.lr = 0x826D5870;
	sub_826E0438(ctx, base);
	// stw r30,1680(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1680, r30.u32);
	// stw r31,1552(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1552, r31.u32);
	// addi r3,r1,1280
	ctx.r3.s64 = ctx.r1.s64 + 1280;
	// stw r28,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r28.u32);
	// bl 0x82761428
	ctx.lr = 0x826D5884;
	sub_82761428(ctx, base);
	// stw r24,1264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1264, r24.u32);
	// stw r30,1152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1152, r30.u32);
	// stw r31,1024(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1024, r31.u32);
	// stw r30,2272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2272, r30.u32);
	// stw r31,2144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2144, r31.u32);
loc_826D5898:
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826d576c
	if (!cr6.eq) goto loc_826D576C;
loc_826D58A4:
	// addi r22,r22,52
	r22.s64 = r22.s64 + 52;
	// cmpwi cr6,r22,156
	cr6.compare<int32_t>(r22.s32, 156, xer);
	// blt cr6,0x826d5758
	if (cr6.lt) goto loc_826D5758;
	// mr r22,r23
	r22.u64 = r23.u64;
loc_826D58B4:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r22,r11
	r11.u64 = r22.u64 + r11.u64;
	// lwz r29,32(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d5a00
	if (cr6.eq) goto loc_826D5A00;
loc_826D58C8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r27,4(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826e9620
	ctx.lr = 0x826D58D8;
	sub_826E9620(ctx, base);
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d58f8
	if (cr6.eq) goto loc_826D58F8;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D58F8:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5914
	if (cr6.eq) goto loc_826D5914;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D5914:
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5930
	if (cr6.eq) goto loc_826D5930;
	// lbz r10,0(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d594c
	if (!cr6.eq) goto loc_826D594C;
loc_826D5930:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5954
	if (cr6.eq) goto loc_826D5954;
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5954
	if (cr6.eq) goto loc_826D5954;
loc_826D594C:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x826d5958
	goto loc_826D5958;
loc_826D5954:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_826D5958:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d59f4
	if (cr6.eq) goto loc_826D59F4;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// bl 0x82687930
	ctx.lr = 0x826D596C;
	sub_82687930(ctx, base);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826df370
	ctx.lr = 0x826D597C;
	sub_826DF370(ctx, base);
	// stb r23,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r23.u8);
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82687930
	ctx.lr = 0x826D598C;
	sub_82687930(ctx, base);
	// lbz r11,404(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 404);
	// stfs f31,400(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stw r28,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r28.u32);
	// rlwinm r11,r11,0,0,23
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF00;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// stb r11,404(r1)
	PPC_STORE_U8(ctx.r1.u32 + 404, r11.u8);
	// bl 0x82761678
	ctx.lr = 0x826D59A8;
	sub_82761678(ctx, base);
	// addi r3,r1,640
	ctx.r3.s64 = ctx.r1.s64 + 640;
	// bl 0x826d4fd0
	ctx.lr = 0x826D59B0;
	sub_826D4FD0(ctx, base);
	// addi r4,r1,1792
	ctx.r4.s64 = ctx.r1.s64 + 1792;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826e0140
	ctx.lr = 0x826D59BC;
	sub_826E0140(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826e0438
	ctx.lr = 0x826D59CC;
	sub_826E0438(ctx, base);
	// stw r30,832(r1)
	PPC_STORE_U32(ctx.r1.u32 + 832, r30.u32);
	// stw r31,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r31.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// stw r28,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r28.u32);
	// bl 0x82761428
	ctx.lr = 0x826D59E0;
	sub_82761428(ctx, base);
	// stw r24,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r24.u32);
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r30.u32);
	// stw r31,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r31.u32);
	// stw r30,1984(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1984, r30.u32);
	// stw r31,1856(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1856, r31.u32);
loc_826D59F4:
	// mr r29,r27
	r29.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826d58c8
	if (!cr6.eq) goto loc_826D58C8;
loc_826D5A00:
	// addi r22,r22,52
	r22.s64 = r22.s64 + 52;
	// cmpwi cr6,r22,156
	cr6.compare<int32_t>(r22.s32, 156, xer);
	// blt cr6,0x826d58b4
	if (cr6.lt) goto loc_826D58B4;
loc_826D5A0C:
	// addi r1,r1,2480
	ctx.r1.s64 = ctx.r1.s64 + 2480;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_826D56F0) {
	__imp__sub_826D56F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5A18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16985
	ctx.r10.u64 = r11.u64 | 16985;
	// lbzx r9,r3,r10
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d5a38
	if (cr6.eq) goto loc_826D5A38;
	// addis r3,r3,6
	ctx.r3.s64 = ctx.r3.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// b 0x826d9530
	sub_826D9530(ctx, base);
	return;
loc_826D5A38:
	// b 0x826d56f0
	sub_826D56F0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D5A18) {
	__imp__sub_826D5A18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5A3C) {
	__imp__sub_826D5A3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5A40) {
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
	ctx.lr = 0x826D5A48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826d5abc
	if (cr6.eq) goto loc_826D5ABC;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5ab0
	if (cr6.eq) goto loc_826D5AB0;
	// li r30,0
	r30.s64 = 0;
loc_826D5A6C:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d5aa4
	if (cr6.eq) goto loc_826D5AA4;
loc_826D5A80:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5A98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d5a80
	if (!cr6.eq) goto loc_826D5A80;
loc_826D5AA4:
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// cmpwi cr6,r30,156
	cr6.compare<int32_t>(r30.s32, 156, xer);
	// blt cr6,0x826d5a6c
	if (cr6.lt) goto loc_826D5A6C;
loc_826D5AB0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,8800
	ctx.r3.s64 = r29.s64 + 8800;
	// bl 0x826ed3e0
	ctx.lr = 0x826D5ABC;
	sub_826ED3E0(ctx, base);
loc_826D5ABC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D5A40) {
	__imp__sub_826D5A40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5AC4) {
	__imp__sub_826D5AC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5AC8) {
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
	ctx.lr = 0x826D5AD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5b28
	if (cr6.eq) goto loc_826D5B28;
	// li r30,0
	r30.s64 = 0;
loc_826D5AE8:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d5b1c
	if (cr6.eq) goto loc_826D5B1C;
loc_826D5AFC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d5afc
	if (!cr6.eq) goto loc_826D5AFC;
loc_826D5B1C:
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// cmpwi cr6,r30,156
	cr6.compare<int32_t>(r30.s32, 156, xer);
	// blt cr6,0x826d5ae8
	if (cr6.lt) goto loc_826D5AE8;
loc_826D5B28:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D5AC8) {
	__imp__sub_826D5AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5B30) {
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
	ctx.lr = 0x826D5B38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r29
	r28.u64 = r29.u64;
	// bl 0x82256058
	ctx.lr = 0x826D5B4C;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d5bf4
	if (cr6.eq) goto loc_826D5BF4;
	// bl 0x82256058
	ctx.lr = 0x826D5B5C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d5bf4
	if (cr6.eq) goto loc_826D5BF4;
	// bl 0x82256058
	ctx.lr = 0x826D5B68;
	sub_82256058(ctx, base);
	// lwz r11,3096(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x826d5b94
	if (cr6.eq) goto loc_826D5B94;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826d5bf4
	if (!cr6.eq) goto loc_826D5BF4;
loc_826D5B94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256138
	ctx.lr = 0x826D5B9C;
	sub_82256138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d5bf4
	if (!cr6.eq) goto loc_826D5BF4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256028
	ctx.lr = 0x826D5BB0;
	sub_82256028(ctx, base);
	// lis r11,6
	r11.s64 = 393216;
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// ori r6,r11,16980
	ctx.r6.u64 = r11.u64 | 16980;
	// cntlzw r4,r10
	ctx.r4.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// ori r5,r9,16978
	ctx.r5.u64 = ctx.r9.u64 | 16978;
	// ori r11,r8,16976
	r11.u64 = ctx.r8.u64 | 16976;
	// ori r10,r7,16977
	ctx.r10.u64 = ctx.r7.u64 | 16977;
	// li r30,1
	r30.s64 = 1;
	// stwx r3,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r3.u32);
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stbx r9,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, ctx.r9.u8);
	// stbx r29,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r29.u8);
	// stbx r30,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r30.u8);
	// b 0x826d5c2c
	goto loc_826D5C2C;
loc_826D5BF4:
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// li r30,1
	r30.s64 = 1;
	// addi r11,r11,16977
	r11.s64 = r11.s64 + 16977;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d5c10
	if (cr6.eq) goto loc_826D5C10;
	// mr r28,r30
	r28.u64 = r30.u64;
loc_826D5C10:
	// lis r10,6
	ctx.r10.s64 = 393216;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// ori r8,r10,16976
	ctx.r8.u64 = ctx.r10.u64 | 16976;
	// ori r7,r9,16978
	ctx.r7.u64 = ctx.r9.u64 | 16978;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// stbx r29,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r29.u8);
loc_826D5C2C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5c50
	if (cr6.eq) goto loc_826D5C50;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D5C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D5C50:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// addi r11,r11,16979
	r11.s64 = r11.s64 + 16979;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// beq cr6,0x826d5cc4
	if (cr6.eq) goto loc_826D5CC4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d5cd0
	if (!cr6.eq) goto loc_826D5CD0;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ori r8,r10,16985
	ctx.r8.u64 = ctx.r10.u64 | 16985;
	// clrlwi r7,r9,28
	ctx.r7.u64 = ctx.r9.u32 & 0xF;
	// ori r6,r7,112
	ctx.r6.u64 = ctx.r7.u64 | 112;
	// lbzx r5,r31,r8
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + ctx.r8.u32);
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5cb4
	if (cr6.eq) goto loc_826D5CB4;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5CAC;
	sub_826D9530(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D5CB4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5CBC;
	sub_826D56F0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D5CC4:
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x826d5cd0
	if (!cr6.eq) goto loc_826D5CD0;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
loc_826D5CD0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D5B30) {
	__imp__sub_826D5B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5CD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// li r5,15
	ctx.r5.s64 = 15;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// b 0x826e1a20
	sub_826E1A20(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D5CD8) {
	__imp__sub_826D5CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5D08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5D08) {
	__imp__sub_826D5D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5D0C) {
	__imp__sub_826D5D0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r9,20(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f12,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stb r8,-27138(r7)
	PPC_STORE_U8(ctx.r7.u32 + -27138, ctx.r8.u8);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,-22568(r8)
	PPC_STORE_U32(ctx.r8.u32 + -22568, ctx.r9.u32);
	// stfs f0,8312(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8312, temp.u32);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f13,8316(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8316, temp.u32);
	// lwz r10,-10012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f12,8304(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8304, temp.u32);
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// stfs f11,8308(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 8308, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5D10) {
	__imp__sub_826D5D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5D8C) {
	__imp__sub_826D5D8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5D90) {
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
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5e0c
	if (cr6.eq) goto loc_826D5E0C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r3,-22584(r10)
	PPC_STORE_U8(ctx.r10.u32 + -22584, ctx.r3.u8);
	// bne cr6,0x826d5e0c
	if (!cr6.eq) goto loc_826D5E0C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// ori r7,r9,16985
	ctx.r7.u64 = ctx.r9.u64 | 16985;
	// ori r6,r8,96
	ctx.r6.u64 = ctx.r8.u64 | 96;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5e04
	if (cr6.eq) goto loc_826D5E04;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5DF4;
	sub_826D9530(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D5E04:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5E0C;
	sub_826D56F0(ctx, base);
loc_826D5E0C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5D90) {
	__imp__sub_826D5D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5E1C) {
	__imp__sub_826D5E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5E20) {
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
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5e9c
	if (cr6.eq) goto loc_826D5E9C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r3,-22583(r10)
	PPC_STORE_U8(ctx.r10.u32 + -22583, ctx.r3.u8);
	// bne cr6,0x826d5e9c
	if (!cr6.eq) goto loc_826D5E9C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// ori r7,r9,16985
	ctx.r7.u64 = ctx.r9.u64 | 16985;
	// ori r6,r8,16
	ctx.r6.u64 = ctx.r8.u64 | 16;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5e94
	if (cr6.eq) goto loc_826D5E94;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5E84;
	sub_826D9530(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D5E94:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5E9C;
	sub_826D56F0(ctx, base);
loc_826D5E9C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5E20) {
	__imp__sub_826D5E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5EAC) {
	__imp__sub_826D5EAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5EB0) {
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
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5f2c
	if (cr6.eq) goto loc_826D5F2C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r3,-22582(r10)
	PPC_STORE_U8(ctx.r10.u32 + -22582, ctx.r3.u8);
	// bne cr6,0x826d5f2c
	if (!cr6.eq) goto loc_826D5F2C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// ori r7,r9,16985
	ctx.r7.u64 = ctx.r9.u64 | 16985;
	// ori r6,r8,32
	ctx.r6.u64 = ctx.r8.u64 | 32;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// lbzx r5,r11,r7
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d5f24
	if (cr6.eq) goto loc_826D5F24;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5F14;
	sub_826D9530(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D5F24:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D5F2C;
	sub_826D56F0(ctx, base);
loc_826D5F2C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5EB0) {
	__imp__sub_826D5EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5F3C) {
	__imp__sub_826D5F3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5F40) {
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
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d5fa4
	if (cr6.eq) goto loc_826D5FA4;
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r10,6
	ctx.r10.s64 = 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// ori r8,r10,16985
	ctx.r8.u64 = ctx.r10.u64 | 16985;
	// ori r7,r9,64
	ctx.r7.u64 = ctx.r9.u64 | 64;
	// stb r7,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// lbzx r6,r3,r8
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r8.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826d5fa0
	if (cr6.eq) goto loc_826D5FA0;
	// addis r3,r3,6
	ctx.r3.s64 = ctx.r3.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D5F90;
	sub_826D9530(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826D5FA0:
	// bl 0x826d56f0
	ctx.lr = 0x826D5FA4;
	sub_826D56F0(ctx, base);
loc_826D5FA4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5F40) {
	__imp__sub_826D5F40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D5FB4) {
	__imp__sub_826D5FB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D5FB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5fd0
	if (cr6.eq) goto loc_826D5FD0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d5fd4
	goto loc_826D5FD4;
loc_826D5FD0:
	// li r11,0
	r11.s64 = 0;
loc_826D5FD4:
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d5ff4
	if (cr6.eq) goto loc_826D5FF4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d5ff8
	goto loc_826D5FF8;
loc_826D5FF4:
	// li r11,0
	r11.s64 = 0;
loc_826D5FF8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d5fd4
	if (!cr6.eq) goto loc_826D5FD4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D5FB8) {
	__imp__sub_826D5FB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6008) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6034
	if (cr6.eq) goto loc_826D6034;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d6038
	goto loc_826D6038;
loc_826D6034:
	// li r31,0
	r31.s64 = 0;
loc_826D6038:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d6078
	if (cr6.eq) goto loc_826D6078;
loc_826D6040:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,172(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// bl 0x823db730
	ctx.lr = 0x826D604C;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826d6094
	if (cr6.eq) goto loc_826D6094;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6068
	if (cr6.eq) goto loc_826D6068;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d606c
	goto loc_826D606C;
loc_826D6068:
	// li r11,0
	r11.s64 = 0;
loc_826D606C:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d6040
	if (!cr6.eq) goto loc_826D6040;
loc_826D6078:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D607C:
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
loc_826D6094:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x826d607c
	goto loc_826D607C;
}

PPC_WEAK_FUNC(sub_826D6008) {
	__imp__sub_826D6008(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D609C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D609C) {
	__imp__sub_826D609C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D60A0) {
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
	ctx.lr = 0x826D60A8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r31,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r31.u32);
	// bl 0x82256058
	ctx.lr = 0x826D60B8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6284
	if (cr6.eq) goto loc_826D6284;
	// bl 0x822561c0
	ctx.lr = 0x826D60C4;
	sub_822561C0(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x826d6284
	if (cr6.eq) goto loc_826D6284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d5410
	ctx.lr = 0x826D60D8;
	sub_826D5410(ctx, base);
	// lhz r11,8(r14)
	r11.u64 = PPC_LOAD_U16(r14.u32 + 8);
	// li r18,0
	r18.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6284
	if (cr6.eq) goto loc_826D6284;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r16,0
	r16.s64 = 0;
	// lis r17,-32112
	r17.s64 = -2104492032;
	// addi r15,r9,-13640
	r15.s64 = ctx.r9.s64 + -13640;
	// addi r21,r10,-31816
	r21.s64 = ctx.r10.s64 + -31816;
	// addi r20,r11,-31424
	r20.s64 = r11.s64 + -31424;
loc_826D6108:
	// lwz r11,4(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 4);
	// add. r23,r16,r11
	r23.u64 = r16.u64 + r11.u64;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// beq 0x826d6270
	if (cr0.eq) goto loc_826D6270;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D6128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r19,1
	r19.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r24,30436(r17)
	r24.u64 = PPC_LOAD_U32(r17.u32 + 30436);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x826d6228
	if (cr6.eq) goto loc_826D6228;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82683e20
	ctx.lr = 0x826D6148;
	sub_82683E20(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x826d6228
	if (!cr6.gt) goto loc_826D6228;
loc_826D6158:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d6228
	if (!cr6.eq) goto loc_826D6228;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82683e58
	ctx.lr = 0x826D6170;
	sub_82683E58(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r27,8(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x826d621c
	if (!cr6.gt) goto loc_826D621C;
	// li r29,0
	r29.s64 = 0;
loc_826D6188:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d621c
	if (!cr6.eq) goto loc_826D621C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// bl 0x823dedd8
	ctx.lr = 0x826D61B0;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d620c
	if (cr6.eq) goto loc_826D620C;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpw cr6,r11,r18
	cr6.compare<int32_t>(r11.s32, r18.s32, xer);
	// bne cr6,0x826d620c
	if (!cr6.eq) goto loc_826D620C;
	// lhz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// li r26,1
	r26.s64 = 1;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826d61f8
	if (!cr6.gt) goto loc_826D61F8;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
loc_826D61DC:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r3
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r3.u32, xer);
	// beq cr6,0x826d61fc
	if (cr6.eq) goto loc_826D61FC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x826d61dc
	if (cr6.lt) goto loc_826D61DC;
loc_826D61F8:
	// li r11,-1
	r11.s64 = -1;
loc_826D61FC:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r30,r9,1
	r30.u64 = ctx.r9.u64 ^ 1;
loc_826D620C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r27
	cr6.compare<int32_t>(r28.s32, r27.s32, xer);
	// blt cr6,0x826d6188
	if (cr6.lt) goto loc_826D6188;
loc_826D621C:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmpw cr6,r25,r22
	cr6.compare<int32_t>(r25.s32, r22.s32, xer);
	// blt cr6,0x826d6158
	if (cr6.lt) goto loc_826D6158;
loc_826D6228:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6238
	if (cr6.eq) goto loc_826D6238;
	// mr r19,r30
	r19.u64 = r30.u64;
loc_826D6238:
	// stb r26,188(r23)
	PPC_STORE_U8(r23.u32 + 188, r26.u8);
	// lwz r11,4(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d624c
	if (cr6.eq) goto loc_826D624C;
	// li r19,0
	r19.s64 = 0;
loc_826D624C:
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6270
	if (cr6.eq) goto loc_826D6270;
	// lwz r11,260(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e1520
	ctx.lr = 0x826D626C;
	sub_826E1520(ctx, base);
	// stw r3,184(r23)
	PPC_STORE_U32(r23.u32 + 184, ctx.r3.u32);
loc_826D6270:
	// lhz r11,8(r14)
	r11.u64 = PPC_LOAD_U16(r14.u32 + 8);
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// addi r16,r16,192
	r16.s64 = r16.s64 + 192;
	// cmpw cr6,r18,r11
	cr6.compare<int32_t>(r18.s32, r11.s32, xer);
	// blt cr6,0x826d6108
	if (cr6.lt) goto loc_826D6108;
loc_826D6284:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_826D60A0) {
	__imp__sub_826D60A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D628C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D628C) {
	__imp__sub_826D628C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6290) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d62c8
	if (cr6.eq) goto loc_826D62C8;
	// mulli r10,r4,52
	ctx.r10.s64 = ctx.r4.s64 * 52;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d62c8
	if (cr6.eq) goto loc_826D62C8;
loc_826D62B0:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// beq cr6,0x826d62d0
	if (cr6.eq) goto loc_826D62D0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d62b0
	if (!cr6.eq) goto loc_826D62B0;
loc_826D62C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826D62D0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d62c8
	if (cr6.eq) goto loc_826D62C8;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D6290) {
	__imp__sub_826D6290(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D62E0) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r31,0
	r31.s64 = 0;
	// bl 0x826bde70
	ctx.lr = 0x826D6304;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6324
	if (cr6.eq) goto loc_826D6324;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_826D6324:
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

PPC_WEAK_FUNC(sub_826D62E0) {
	__imp__sub_826D62E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D633C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D633C) {
	__imp__sub_826D633C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// srawi r10,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 5;
	// clrlwi r10,r10,25
	ctx.r10.u64 = ctx.r10.u32 & 0x7F;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d635c
	if (cr6.eq) goto loc_826D635C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d6360
	goto loc_826D6360;
loc_826D635C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D6360:
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bltlr 
	if (cr0.lt) return;
loc_826D6368:
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d637c
	if (cr6.eq) goto loc_826D637C;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x826d6380
	goto loc_826D6380;
loc_826D637C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D6380:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x826d6368
	if (!cr0.lt) goto loc_826D6368;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D6340) {
	__imp__sub_826D6340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D638C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D638C) {
	__imp__sub_826D638C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6390) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d64c4
	if (cr6.eq) goto loc_826D64C4;
	// lwz r11,436(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 436);
	// mulli r11,r11,52
	r11.s64 = r11.s64 * 52;
	// add r31,r11,r3
	r31.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d63e0
	if (cr6.eq) goto loc_826D63E0;
loc_826D63C8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// beq cr6,0x826d6448
	if (cr6.eq) goto loc_826D6448;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d63c8
	if (!cr6.eq) goto loc_826D63C8;
loc_826D63E0:
	// li r11,0
	r11.s64 = 0;
loc_826D63E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r30,r4,16
	r30.s64 = ctx.r4.s64 + 16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// beq cr6,0x826d6468
	if (cr6.eq) goto loc_826D6468;
	// bl 0x826e0b98
	ctx.lr = 0x826D63FC;
	sub_826E0B98(ctx, base);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6450
	if (cr6.eq) goto loc_826D6450;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6430
	if (cr6.eq) goto loc_826D6430;
	// stw r30,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r30.u32);
loc_826D6430:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x826d64c4
	goto loc_826D64C4;
loc_826D6448:
	// li r11,1
	r11.s64 = 1;
	// b 0x826d63e4
	goto loc_826D63E4;
loc_826D6450:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x826d64c4
	goto loc_826D64C4;
loc_826D6468:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x826e0b98
	ctx.lr = 0x826D6470;
	sub_826E0B98(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r31,24
	ctx.r10.s64 = r31.s64 + 24;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d64b0
	if (cr6.eq) goto loc_826D64B0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d64a8
	if (cr6.eq) goto loc_826D64A8;
	// stw r30,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r30.u32);
loc_826D64A8:
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// b 0x826d64b4
	goto loc_826D64B4;
loc_826D64B0:
	// stw r30,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r30.u32);
loc_826D64B4:
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
loc_826D64C4:
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

PPC_WEAK_FUNC(sub_826D6390) {
	__imp__sub_826D6390(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D64DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D64DC) {
	__imp__sub_826D64DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D64E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826D64EC:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d653c
	if (cr6.eq) goto loc_826D653C;
	// lwz r9,-12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d6524
	if (cr6.eq) goto loc_826D6524;
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r6,-8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r4,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r4.u32);
	// b 0x826d6534
	goto loc_826D6534;
loc_826D6524:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r10,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, ctx.r10.u32);
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r9,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r9.u32);
loc_826D6534:
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
loc_826D653C:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r8,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r8.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d65a0
	if (cr6.eq) goto loc_826D65A0;
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d6588
	if (cr6.eq) goto loc_826D6588;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// lwz r4,24(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// b 0x826d6598
	goto loc_826D6598;
loc_826D6588:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
loc_826D6598:
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
loc_826D65A0:
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// addi r11,r11,52
	r11.s64 = r11.s64 + 52;
	// bne 0x826d64ec
	if (!cr0.eq) goto loc_826D64EC;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D64E0) {
	__imp__sub_826D64E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D65C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D65C4) {
	__imp__sub_826D65C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D65C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d661c
	if (cr6.eq) goto loc_826D661C;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6604
	if (cr6.eq) goto loc_826D6604;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r6,28(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// b 0x826d6614
	goto loc_826D6614;
loc_826D6604:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
loc_826D6614:
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// stw r9,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
loc_826D661C:
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6680
	if (cr6.eq) goto loc_826D6680;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6668
	if (cr6.eq) goto loc_826D6668;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r8,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r8.u32);
	// lwz r6,36(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// b 0x826d6678
	goto loc_826D6678;
loc_826D6668:
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_826D6678:
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// stw r9,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r9.u32);
loc_826D6680:
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r9,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D65C8) {
	__imp__sub_826D65C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826D66A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// li r31,18
	r31.s64 = 18;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_826D66C0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82519ca8
	ctx.lr = 0x826D66C8;
	sub_82519CA8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r29,r29,20
	r29.s64 = r29.s64 + 20;
	// bne 0x826d66c0
	if (!cr0.eq) goto loc_826D66C0;
	// li r11,0
	r11.s64 = 0;
	// li r31,18
	r31.s64 = 18;
	// stw r11,364(r28)
	PPC_STORE_U32(r28.u32 + 364, r11.u32);
loc_826D66E0:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82527b48
	ctx.lr = 0x826D66FC;
	sub_82527B48(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// bne 0x826d66e0
	if (!cr0.eq) goto loc_826D66E0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826D6698) {
	__imp__sub_826D6698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6710) {
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
	ctx.lr = 0x826D6718;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d67c0
	if (cr6.eq) goto loc_826D67C0;
	// li r30,0
	r30.s64 = 0;
loc_826D6730:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,32(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d6764
	if (cr6.eq) goto loc_826D6764;
loc_826D6744:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D6758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d6744
	if (!cr6.eq) goto loc_826D6744;
loc_826D6764:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d6798
	if (cr6.eq) goto loc_826D6798;
loc_826D6778:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D678C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,4(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826d6778
	if (!cr6.eq) goto loc_826D6778;
loc_826D6798:
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// cmpwi cr6,r30,156
	cr6.compare<int32_t>(r30.s32, 156, xer);
	// blt cr6,0x826d6730
	if (cr6.lt) goto loc_826D6730;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x826d64e0
	ctx.lr = 0x826D67AC;
	sub_826D64E0(ctx, base);
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16928
	ctx.r10.u64 = r11.u64 | 16928;
	// lwzx r9,r29,r10
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lwz r3,32(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// bl 0x826d65c8
	ctx.lr = 0x826D67C0;
	sub_826D65C8(ctx, base);
loc_826D67C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D6710) {
	__imp__sub_826D6710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D67C8) {
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
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// b 0x826d5d90
	sub_826D5D90(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D67C8) {
	__imp__sub_826D67C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D67EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D67EC) {
	__imp__sub_826D67EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D67F0) {
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
	// b 0x826d5d90
	sub_826D5D90(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D67F0) {
	__imp__sub_826D67F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D680C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D680C) {
	__imp__sub_826D680C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6810) {
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
	// b 0x826d5e20
	sub_826D5E20(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D6810) {
	__imp__sub_826D6810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D682C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D682C) {
	__imp__sub_826D682C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6830) {
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
	// b 0x826d5eb0
	sub_826D5EB0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D6830) {
	__imp__sub_826D6830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D684C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D684C) {
	__imp__sub_826D684C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6850) {
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
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10012(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f13,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x826d68bc
	if (!cr6.eq) goto loc_826D68BC;
loc_826D689C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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
loc_826D68BC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d689c
	if (cr6.eq) goto loc_826D689C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,27644(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x826e1418
	ctx.lr = 0x826D68E8;
	sub_826E1418(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_826D6850) {
	__imp__sub_826D6850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6904) {
	__imp__sub_826D6904(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6908) {
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
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826d5248
	ctx.lr = 0x826D694C;
	sub_826D5248(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_826D6908) {
	__imp__sub_826D6908(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6968) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f1,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826d52f0
	ctx.lr = 0x826D69A8;
	sub_826D52F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_826D6968) {
	__imp__sub_826D6968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D69C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D69C4) {
	__imp__sub_826D69C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D69C8) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,-10012(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,8(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// beq cr6,0x826d6a28
	if (cr6.eq) goto loc_826D6A28;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x82249c38
	ctx.lr = 0x826D6A1C;
	sub_82249C38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6a28
	if (cr6.eq) goto loc_826D6A28;
	// stw r31,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r31.u32);
loc_826D6A28:
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

PPC_WEAK_FUNC(sub_826D69C8) {
	__imp__sub_826D69C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6A3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6A3C) {
	__imp__sub_826D6A3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6A40) {
	PPC_FUNC_PROLOGUE();
	// b 0x826d5f40
	sub_826D5F40(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D6A40) {
	__imp__sub_826D6A40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6A44) {
	__imp__sub_826D6A44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6A48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6a5c
	if (cr6.eq) goto loc_826D6A5C;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d6a60
	goto loc_826D6A60;
loc_826D6A5C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D6A60:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6a98
	if (cr6.eq) goto loc_826D6A98;
loc_826D6A68:
	// lbz r11,108(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6a88
	if (cr6.eq) goto loc_826D6A88;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x826d6a8c
	goto loc_826D6A8C;
loc_826D6A88:
	// li r11,0
	r11.s64 = 0;
loc_826D6A8C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d6a68
	if (!cr6.eq) goto loc_826D6A68;
loc_826D6A98:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D6A48) {
	__imp__sub_826D6A48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6AA0) {
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
	ctx.lr = 0x826D6AA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x826d5568
	ctx.lr = 0x826D6AB8;
	sub_826D5568(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,52
	ctx.r3.s64 = r11.s64 + 52;
	// bl 0x826d5568
	ctx.lr = 0x826D6AC4;
	sub_826D5568(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,104
	ctx.r3.s64 = r11.s64 + 104;
	// bl 0x826d5568
	ctx.lr = 0x826D6AD0;
	sub_826D5568(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6ae0
	if (cr6.eq) goto loc_826D6AE0;
	// bl 0x82130588
	ctx.lr = 0x826D6AE0;
	sub_82130588(ctx, base);
loc_826D6AE0:
	// addis r28,r31,6
	r28.s64 = r31.s64 + 393216;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r28,16940
	r28.s64 = r28.s64 + 16940;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d6b10
	if (cr6.eq) goto loc_826D6B10;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D6B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D6B10:
	// addis r30,r31,6
	r30.s64 = r31.s64 + 393216;
	// stw r29,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r29.u32);
	// addi r30,r30,16944
	r30.s64 = r30.s64 + 16944;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d6b38
	if (cr6.eq) goto loc_826D6B38;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82472538
	ctx.lr = 0x826D6B30;
	sub_82472538(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826D6B38;
	sub_82130588(ctx, base);
loc_826D6B38:
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D6AA0) {
	__imp__sub_826D6AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6B44) {
	__imp__sub_826D6B44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826d6b58
	if (!cr6.eq) goto loc_826D6B58;
	// blr 
	return;
loc_826D6B58:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6b6c
	if (cr6.eq) goto loc_826D6B6C;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x826d6b7c
	goto loc_826D6B7C;
loc_826D6B6C:
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
loc_826D6B7C:
	// b 0x826e0c40
	sub_826E0C40(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D6B48) {
	__imp__sub_826D6B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x826d6390
	sub_826D6390(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D6B80) {
	__imp__sub_826D6B80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B90) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D6B90) {
	__imp__sub_826D6B90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6B94) {
	__imp__sub_826D6B94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6B98) {
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
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6c20
	if (cr6.eq) goto loc_826D6C20;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
loc_826D6BC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6c0c
	if (cr6.eq) goto loc_826D6C0C;
loc_826D6BD8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6c04
	if (cr6.eq) goto loc_826D6C04;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r5,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r5.u32);
loc_826D6C04:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d6bd8
	if (!cr6.eq) goto loc_826D6BD8;
loc_826D6C0C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmplw cr6,r6,r11
	cr6.compare<uint32_t>(ctx.r6.u32, r11.u32, xer);
	// blt cr6,0x826d6bc8
	if (cr6.lt) goto loc_826D6BC8;
loc_826D6C20:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826D6C28;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

PPC_WEAK_FUNC(sub_826D6B98) {
	__imp__sub_826D6B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6C4C) {
	__imp__sub_826D6C4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6C50) {
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
	ctx.lr = 0x826D6C58;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// blt cr6,0x826d6d64
	if (cr6.lt) goto loc_826D6D64;
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r11,r6
	r11.s64 = -ctx.r6.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826D6C80;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x826d6d00
	if (!cr6.gt) goto loc_826D6D00;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
loc_826D6CA0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6cf0
	if (cr6.eq) goto loc_826D6CF0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bne cr6,0x826d6cc0
	if (!cr6.eq) goto loc_826D6CC0;
	// stw r7,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r7.u32);
loc_826D6CC0:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6cd4
	if (cr6.eq) goto loc_826D6CD4;
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r5,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r5.u32);
loc_826D6CD4:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6ce8
	if (cr6.eq) goto loc_826D6CE8;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
loc_826D6CE8:
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
loc_826D6CF0:
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x826d6ca0
	if (!cr0.eq) goto loc_826D6CA0;
loc_826D6D00:
	// add r4,r6,r28
	ctx.r4.u64 = ctx.r6.u64 + r28.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8278f660
	ctx.lr = 0x826D6D0C;
	sub_8278F660(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826d6d64
	if (!cr6.gt) goto loc_826D6D64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
loc_826D6D1C:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d6d50
	if (cr6.eq) goto loc_826D6D50;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d6d48
	if (cr6.eq) goto loc_826D6D48;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
loc_826D6D48:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x826d6d54
	goto loc_826D6D54;
loc_826D6D50:
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_826D6D54:
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x826d6d1c
	if (!cr0.eq) goto loc_826D6D1C;
loc_826D6D64:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D6C50) {
	__imp__sub_826D6C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6D6C) {
	__imp__sub_826D6D6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6D70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lhz r11,4(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6dcc
	if (cr6.eq) goto loc_826D6DCC;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// twllei r11,0
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// divwu r7,r10,r11
	ctx.r7.u32 = ctx.r10.u32 / r11.u32;
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r5,r6,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r6.s64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826d6dcc
	if (cr6.eq) goto loc_826D6DCC;
loc_826D6DAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// beq cr6,0x826d6dd4
	if (cr6.eq) goto loc_826D6DD4;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r9,8
	r11.s64 = ctx.r9.s64 + 8;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826d6dac
	if (!cr6.eq) goto loc_826D6DAC;
loc_826D6DCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826D6DD4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d6e04
	if (cr6.eq) goto loc_826D6E04;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
loc_826D6E04:
	// lhz r11,6(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,6(r8)
	PPC_STORE_U16(ctx.r8.u32 + 6, ctx.r10.u16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D6D70) {
	__imp__sub_826D6D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D6E1C) {
	__imp__sub_826D6E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6E20) {
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
	ctx.lr = 0x826D6E28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r28,r29,4
	r28.s64 = r29.s64 + 4;
	// addi r10,r11,4448
	ctx.r10.s64 = r11.s64 + 4448;
	// mr r30,r28
	r30.u64 = r28.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// li r31,18
	r31.s64 = 18;
loc_826D6E48:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82519ca8
	ctx.lr = 0x826D6E50;
	sub_82519CA8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// bne 0x826d6e48
	if (!cr0.eq) goto loc_826D6E48;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r29,368
	ctx.r3.s64 = r29.s64 + 368;
	// stw r11,364(r29)
	PPC_STORE_U32(r29.u32 + 364, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x826D6E6C;
	sub_82130000(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826d4f88
	ctx.lr = 0x826D6E74;
	sub_826D4F88(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r9,r10,18692
	ctx.r9.s64 = ctx.r10.s64 + 18692;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D6E20) {
	__imp__sub_826D6E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6E88) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,368
	ctx.r4.s64 = r30.s64 + 368;
	// bl 0x821c8fe0
	ctx.lr = 0x826D6EAC;
	sub_821C8FE0(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// addi r10,r30,364
	ctx.r10.s64 = r30.s64 + 364;
	// li r9,1
	ctx.r9.s64 = 1;
loc_826D6EB8:
	// rlwinm r11,r31,29,3,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r8,r31,27
	ctx.r8.u64 = r31.u32 & 0x1F;
	// slw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r8.u8 & 0x3F));
	// lwzx r6,r11,r10
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// and r4,r6,r7
	ctx.r4.u64 = ctx.r6.u64 & ctx.r7.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cntlzw r8,r4
	ctx.r8.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// or r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d6f30
	if (cr6.eq) goto loc_826D6F30;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r31,18
	cr6.compare<uint32_t>(r31.u32, 18, xer);
	// blt cr6,0x826d6eb8
	if (cr6.lt) goto loc_826D6EB8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,18
	ctx.r4.s64 = 18;
	// addi r3,r11,4464
	ctx.r3.s64 = r11.s64 + 4464;
	// bl 0x821bd618
	ctx.lr = 0x826D6F0C;
	sub_821BD618(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x826D6F14;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_826D6F18:
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
loc_826D6F30:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x826D6F38;
	sub_821C9030(ctx, base);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// b 0x826d6f18
	goto loc_826D6F18;
}

PPC_WEAK_FUNC(sub_826D6E88) {
	__imp__sub_826D6E88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6F50) {
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
	// addi r4,r31,368
	ctx.r4.s64 = r31.s64 + 368;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x826D6F78;
	sub_821C8FE0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
loc_826D6F80:
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x826d6f9c
	if (cr6.eq) goto loc_826D6F9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmplwi cr6,r11,18
	cr6.compare<uint32_t>(r11.u32, 18, xer);
	// blt cr6,0x826d6f80
	if (cr6.lt) goto loc_826D6F80;
	// b 0x826d6fc0
	goto loc_826D6FC0;
loc_826D6F9C:
	// rlwinm r10,r11,27,5,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// addi r8,r10,91
	ctx.r8.s64 = ctx.r10.s64 + 91;
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// slw r6,r7,r9
	ctx.r6.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// andc r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 & ~ctx.r6.u64;
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
loc_826D6FC0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x826D6FC8;
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

PPC_WEAK_FUNC(sub_826D6F50) {
	__imp__sub_826D6F50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D6FE0) {
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
	// bl 0x826d6e20
	ctx.lr = 0x826D7000;
	sub_826D6E20(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7018
	if (cr6.eq) goto loc_826D7018;
	// bl 0x82130588
	ctx.lr = 0x826D7014;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D7018:
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

PPC_WEAK_FUNC(sub_826D6FE0) {
	__imp__sub_826D6FE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7030) {
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
	ctx.lr = 0x826D7038;
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7060
	if (!cr6.eq) goto loc_826D7060;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x826d4e28
	ctx.lr = 0x826D7060;
	sub_826D4E28(ctx, base);
loc_826D7060:
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
	// bne cr6,0x826d7090
	if (!cr6.eq) goto loc_826D7090;
	// bl 0x821c9438
	ctx.lr = 0x826D7084;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d4eb0
	ctx.lr = 0x826D7090;
	sub_826D4EB0(ctx, base);
loc_826D7090:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// divwu r7,r9,r11
	ctx.r7.u32 = ctx.r9.u32 / r11.u32;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r7,r8
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// beq cr6,0x826d70f8
	if (cr6.eq) goto loc_826D70F8;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d70f8
	if (cr6.eq) goto loc_826D70F8;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// stw r6,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r6.u32);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// b 0x826d70fc
	goto loc_826D70FC;
loc_826D70F8:
	// li r11,0
	r11.s64 = 0;
loc_826D70FC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r11,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r7,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D7030) {
	__imp__sub_826D7030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D7114) {
	__imp__sub_826D7114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7118) {
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
	ctx.lr = 0x826D7120;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,6
	r11.s64 = 393216;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r11,16985
	ctx.r9.u64 = r11.u64 | 16985;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// ori r7,r8,112
	ctx.r7.u64 = ctx.r8.u64 | 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbzx r6,r31,r9
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// stb r7,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826d7164
	if (cr6.eq) goto loc_826D7164;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9530
	ctx.lr = 0x826D7160;
	sub_826D9530(ctx, base);
	// b 0x826d716c
	goto loc_826D716C;
loc_826D7164:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D716C;
	sub_826D56F0(ctx, base);
loc_826D716C:
	// lis r11,6
	r11.s64 = 393216;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r11,16948
	ctx.r9.u64 = r11.u64 | 16948;
	// ori r8,r10,16949
	ctx.r8.u64 = ctx.r10.u64 | 16949;
	// clrlwi r7,r30,24
	ctx.r7.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// bne cr6,0x826d7214
	if (!cr6.eq) goto loc_826D7214;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d7208
	if (cr6.eq) goto loc_826D7208;
	// li r30,0
	r30.s64 = 0;
loc_826D71A4:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x826d7208
	if (!cr6.lt) goto loc_826D7208;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826d71f4
	if (cr6.eq) goto loc_826D71F4;
loc_826D71C4:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826d6d70
	ctx.lr = 0x826D71D4;
	sub_826D6D70(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwzx r7,r8,r30
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r30.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x826d71c4
	if (!cr6.eq) goto loc_826D71C4;
loc_826D71F4:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826d71a4
	if (!cr6.eq) goto loc_826D71A4;
loc_826D7208:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_826D7214:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D7118) {
	__imp__sub_826D7118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D721C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D721C) {
	__imp__sub_826D721C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7220) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r5,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x826d7030
	ctx.lr = 0x826D724C;
	sub_826D7030(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_826D7220) {
	__imp__sub_826D7220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D7274) {
	__imp__sub_826D7274(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7278) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x826d6d70
	ctx.lr = 0x826D729C;
	sub_826D6D70(ctx, base);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_826D7278) {
	__imp__sub_826D7278(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D72C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D72C4) {
	__imp__sub_826D72C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D72C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826D72D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,3
	r30.s64 = 3;
loc_826D72DC:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// bl 0x826d6c50
	ctx.lr = 0x826D72F0;
	sub_826D6C50(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x826d6c50
	ctx.lr = 0x826D7300;
	sub_826D6C50(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,52
	r31.s64 = r31.s64 + 52;
	// bne 0x826d72dc
	if (!cr0.eq) goto loc_826D72DC;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D72C8) {
	__imp__sub_826D72C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D7314) {
	__imp__sub_826D7314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7318) {
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
	ctx.lr = 0x826D7320;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,1440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1440);
	// beq cr6,0x826d752c
	if (cr6.eq) goto loc_826D752C;
	// srawi r10,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r10.s64 = r11.s32 >> 3;
	// addi r5,r31,1456
	ctx.r5.s64 = r31.s64 + 1456;
	// addze r30,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r30.s64 = temp.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82576948
	ctx.lr = 0x826D7354;
	sub_82576948(ctx, base);
	// mulli r11,r30,2496
	r11.s64 = r30.s64 * 2496;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D7370;
	sub_82576948(ctx, base);
	// mulli r11,r30,4992
	r11.s64 = r30.s64 * 4992;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D738C;
	sub_82576948(ctx, base);
	// mulli r11,r30,7488
	r11.s64 = r30.s64 * 7488;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D73A8;
	sub_82576948(ctx, base);
	// mulli r11,r30,9984
	r11.s64 = r30.s64 * 9984;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D73C4;
	sub_82576948(ctx, base);
	// mulli r11,r30,12480
	r11.s64 = r30.s64 * 12480;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D73E0;
	sub_82576948(ctx, base);
	// mulli r11,r30,14976
	r11.s64 = r30.s64 * 14976;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576948
	ctx.lr = 0x826D73FC;
	sub_82576948(ctx, base);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r11,r30,17472
	r11.s64 = r30.s64 * 17472;
	// lwz r7,1440(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1440);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// subf r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r5,r11,1456
	ctx.r5.s64 = r11.s64 + 1456;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r6,r8,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r8.s64;
	// bl 0x82576948
	ctx.lr = 0x826D7424;
	sub_82576948(ctx, base);
	// lwz r11,1444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1444);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// srawi r10,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r10.s64 = r11.s32 >> 3;
	// ori r29,r6,55728
	r29.u64 = ctx.r6.u64 | 55728;
	// addze r30,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r30.s64 = temp.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r5,r31,r29
	ctx.r5.u64 = r31.u64 + r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82576960
	ctx.lr = 0x826D744C;
	sub_82576960(ctx, base);
	// mulli r11,r30,2512
	r11.s64 = r30.s64 * 2512;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 + r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D7468;
	sub_82576960(ctx, base);
	// mulli r11,r30,5024
	r11.s64 = r30.s64 * 5024;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D7484;
	sub_82576960(ctx, base);
	// mulli r11,r30,7536
	r11.s64 = r30.s64 * 7536;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r7,r29
	ctx.r5.u64 = ctx.r7.u64 + r29.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D74A0;
	sub_82576960(ctx, base);
	// mulli r11,r30,10048
	r11.s64 = r30.s64 * 10048;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + r29.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D74BC;
	sub_82576960(ctx, base);
	// mulli r11,r30,12560
	r11.s64 = r30.s64 * 12560;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r4,r29
	ctx.r5.u64 = ctx.r4.u64 + r29.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D74D8;
	sub_82576960(ctx, base);
	// mulli r11,r30,15072
	r11.s64 = r30.s64 * 15072;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r3,r29
	ctx.r5.u64 = ctx.r3.u64 + r29.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82576960
	ctx.lr = 0x826D74F4;
	sub_82576960(ctx, base);
	// mulli r11,r30,17584
	r11.s64 = r30.s64 * 17584;
	// lwz r7,1444(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1444);
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// subf r8,r30,r10
	ctx.r8.s64 = ctx.r10.s64 - r30.s64;
	// li r4,7
	ctx.r4.s64 = 7;
	// add r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 + r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r6,r8,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r8.s64;
	// bl 0x82576960
	ctx.lr = 0x826D751C;
	sub_82576960(ctx, base);
	// stw r28,1440(r31)
	PPC_STORE_U32(r31.u32 + 1440, r28.u32);
	// stw r28,1444(r31)
	PPC_STORE_U32(r31.u32 + 1444, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826D752C:
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826d7574
	if (!cr6.gt) goto loc_826D7574;
	// addi r30,r31,3932
	r30.s64 = r31.s64 + 3932;
loc_826D753C:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r30,-2476
	ctx.r3.s64 = r30.s64 + -2476;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r7,-4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + -4);
	// lwz r6,-8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// lwz r5,-12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -12);
	// lwz r4,-16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// bl 0x822c6110
	ctx.lr = 0x826D7560;
	sub_822C6110(ctx, base);
	// lwz r11,1440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1440);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,2496
	r30.s64 = r30.s64 + 2496;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826d753c
	if (cr6.lt) goto loc_826D753C;
loc_826D7574:
	// lwz r11,1444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1444);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826d75c4
	if (!cr6.gt) goto loc_826D75C4;
	// addis r30,r31,2
	r30.s64 = r31.s64 + 131072;
	// addi r30,r30,-7316
	r30.s64 = r30.s64 + -7316;
loc_826D758C:
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r30,-2492
	ctx.r3.s64 = r30.s64 + -2492;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r7,-4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + -4);
	// lwz r6,-8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// lwz r5,-12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + -12);
	// lwz r4,-16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -16);
	// bl 0x82572f98
	ctx.lr = 0x826D75B0;
	sub_82572F98(ctx, base);
	// lwz r11,1444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1444);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,2512
	r30.s64 = r30.s64 + 2512;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826d758c
	if (cr6.lt) goto loc_826D758C;
loc_826D75C4:
	// stw r28,1440(r31)
	PPC_STORE_U32(r31.u32 + 1440, r28.u32);
	// stw r28,1444(r31)
	PPC_STORE_U32(r31.u32 + 1444, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D7318) {
	__imp__sub_826D7318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D75D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D75D4) {
	__imp__sub_826D75D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D75D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v63{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x826D75E0;
	// stfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f30.u64);
	// stfd f31,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-432
	r31.s64 = ctx.r1.s64 + -432;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d7634
	if (cr6.eq) goto loc_826D7634;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x826d7638
	if (cr6.eq) goto loc_826D7638;
loc_826D7634:
	// li r11,0
	r11.s64 = 0;
loc_826D7638:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7650
	if (cr6.eq) goto loc_826D7650;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826d5ac8
	ctx.lr = 0x826D764C;
	sub_826D5AC8(ctx, base);
	// b 0x826d7cc0
	goto loc_826D7CC0;
loc_826D7650:
	// addis r23,r26,6
	r23.s64 = r26.s64 + 393216;
	// addi r23,r23,16956
	r23.s64 = r23.s64 + 16956;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x826d7cc0
	if (cr6.eq) goto loc_826D7CC0;
	// lwz r3,12(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d7684
	if (cr6.eq) goto loc_826D7684;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826d7684
	if (!cr6.eq) goto loc_826D7684;
	// bl 0x826d72c8
	ctx.lr = 0x826D7684;
	sub_826D72C8(ctx, base);
loc_826D7684:
	// lwz r10,12(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r17,r11,-2928
	r17.s64 = r11.s64 + -2928;
	// beq cr6,0x826d76f8
	if (cr6.eq) goto loc_826D76F8;
	// li r29,0
	r29.s64 = 0;
loc_826D769C:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d76d0
	if (cr6.eq) goto loc_826D76D0;
loc_826D76B0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D76C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826d76b0
	if (!cr6.eq) goto loc_826D76B0;
loc_826D76D0:
	// addi r29,r29,52
	r29.s64 = r29.s64 + 52;
	// cmpwi cr6,r29,156
	cr6.compare<int32_t>(r29.s32, 156, xer);
	// blt cr6,0x826d769c
	if (cr6.lt) goto loc_826D769C;
	// lis r11,6
	r11.s64 = 393216;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// ori r10,r11,16987
	ctx.r10.u64 = r11.u64 | 16987;
	// lbzx r4,r26,r10
	ctx.r4.u64 = PPC_LOAD_U8(r26.u32 + ctx.r10.u32);
	// bl 0x826d7318
	ctx.lr = 0x826D76F0;
	sub_826D7318(ctx, base);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x8257fce0
	ctx.lr = 0x826D76F8;
	sub_8257FCE0(ctx, base);
loc_826D76F8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x826D7704;
	sub_822F10D0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r8,-30584
	ctx.r8.s64 = -2004353024;
	// li r9,60
	ctx.r9.s64 = 60;
	// ori r7,r8,34953
	ctx.r7.u64 = ctx.r8.u64 | 34953;
	// lfs f0,-26872(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26872);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,128(r31)
	PPC_STORE_U64(r31.u32 + 128, ctx.f13.u64);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// mulhw r10,r11,r7
	ctx.r10.s64 = (int64_t(r11.s32) * int64_t(ctx.r7.s32)) >> 32;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// divw r5,r11,r9
	ctx.r5.s32 = r11.s32 / ctx.r9.s32;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// srawi r11,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	r11.s64 = ctx.r4.s32 >> 5;
	// mulli r9,r5,100
	ctx.r9.s64 = ctx.r5.s64 * 100;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// mulli r11,r3,60
	r11.s64 = ctx.r3.s64 * 60;
	// subf r11,r11,r6
	r11.s64 = ctx.r6.s64 - r11.s64;
	// add r30,r9,r11
	r30.u64 = ctx.r9.u64 + r11.u64;
	// bl 0x82387a18
	ctx.lr = 0x826D7758;
	sub_82387A18(ctx, base);
	// lis r10,3
	ctx.r10.s64 = 196608;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// ori r19,r10,29488
	r19.u64 = ctx.r10.u64 | 29488;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d7780
	if (cr6.eq) goto loc_826D7780;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
	// addi r5,r31,144
	ctx.r5.s64 = r31.s64 + 144;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826d7784
	goto loc_826D7784;
loc_826D7780:
	// add r5,r26,r19
	ctx.r5.u64 = r26.u64 + r19.u64;
loc_826D7784:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r26,8536
	ctx.r3.s64 = r26.s64 + 8536;
	// bl 0x826dbaa0
	ctx.lr = 0x826D7794;
	sub_826DBAA0(ctx, base);
	// lis r11,3
	r11.s64 = 196608;
	// ori r24,r11,29296
	r24.u64 = r11.u64 | 29296;
	// add r25,r26,r24
	r25.u64 = r26.u64 + r24.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826f05c8
	ctx.lr = 0x826D77A8;
	sub_826F05C8(ctx, base);
	// lis r22,-32121
	r22.s64 = -2105081856;
	// addis r27,r26,4
	r27.s64 = r26.s64 + 262144;
	// lwz r21,0(r13)
	r21.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r20,72
	r20.s64 = 72;
	// li r29,1
	r29.s64 = 1;
	// li r28,12
	r28.s64 = 12;
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// addi r27,r27,-30304
	r27.s64 = r27.s64 + -30304;
loc_826D77C8:
	// lbzx r10,r20,r21
	ctx.r10.u64 = PPC_LOAD_U8(r20.u32 + r21.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d77dc
	if (cr6.eq) goto loc_826D77DC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x826d77e0
	goto loc_826D77E0;
loc_826D77DC:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_826D77E0:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x826d78a4
	if (!cr6.lt) goto loc_826D78A4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d7814
	if (cr6.eq) goto loc_826D7814;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x826d7838
	if (cr6.lt) goto loc_826D7838;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x826d7838
	if (!cr6.lt) goto loc_826D7838;
	// add r11,r28,r3
	r11.u64 = r28.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x826d7830
	goto loc_826D7830;
loc_826D7814:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x826d7838
	if (cr6.lt) goto loc_826D7838;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x826d7838
	if (!cr6.lt) goto loc_826D7838;
	// lwzx r11,r28,r3
	r11.u64 = PPC_LOAD_U32(r28.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_826D7830:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826d783c
	if (!cr6.eq) goto loc_826D783C;
loc_826D7838:
	// li r11,0
	r11.s64 = 0;
loc_826D783C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7894
	if (cr6.eq) goto loc_826D7894;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x826D7850;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d7890
	if (cr6.eq) goto loc_826D7890;
	// bl 0x82387a18
	ctx.lr = 0x826D7864;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7888
	if (cr6.eq) goto loc_826D7888;
	// lwz r11,1220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d7890
	if (cr6.eq) goto loc_826D7890;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7890
	if (!cr6.eq) goto loc_826D7890;
loc_826D7888:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826f05c8
	ctx.lr = 0x826D7890;
	sub_826F05C8(ctx, base);
loc_826D7890:
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
loc_826D7894:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r27,r27,5936
	r27.s64 = r27.s64 + 5936;
	// b 0x826d77c8
	goto loc_826D77C8;
loc_826D78A4:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-27138(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -27138);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d78c0
	if (!cr6.eq) goto loc_826D78C0;
	// lbz r11,8320(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 8320);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7940
	if (cr6.eq) goto loc_826D7940;
loc_826D78C0:
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r11,31088
	ctx.r10.u64 = r11.u64 | 31088;
	// lwzx r29,r26,r10
	r29.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// rlwinm r9,r29,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r8,r9
	ctx.r8.s64 = -ctx.r9.s64;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826D78DC;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// ble cr6,0x826d7918
	if (!cr6.gt) goto loc_826D7918;
	// addis r10,r26,3
	ctx.r10.s64 = r26.s64 + 196608;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// addi r10,r10,30688
	ctx.r10.s64 = ctx.r10.s64 + 30688;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_826D7900:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x826d7900
	if (!cr0.eq) goto loc_826D7900;
loc_826D7918:
	// addi r30,r26,48
	r30.s64 = r26.s64 + 48;
	// addi r5,r31,160
	ctx.r5.s64 = r31.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x8273e2f8
	ctx.lr = 0x826D792C;
	sub_8273E2F8(ctx, base);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r31,160
	ctx.r4.s64 = r31.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8273e7e8
	ctx.lr = 0x826D7940;
	sub_8273E7E8(ctx, base);
loc_826D7940:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18444
	ctx.r10.s64 = r11.s64 + 18444;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7974
	if (!cr6.eq) goto loc_826D7974;
	// bl 0x82387a18
	ctx.lr = 0x826D7958;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7974
	if (!cr6.eq) goto loc_826D7974;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lfs f30,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f30.f64 = double(temp.f32);
	// b 0x826d7990
	goto loc_826D7990;
loc_826D7974:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lfs f0,14992(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lfs f13,92(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f30,f12,f13,f0
	f30.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
loc_826D7990:
	// bl 0x82387a18
	ctx.lr = 0x826D7994;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d79a8
	if (cr6.eq) goto loc_826D79A8;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
	// b 0x826d79ac
	goto loc_826D79AC;
loc_826D79A8:
	// lfs f31,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	f31.f64 = double(temp.f32);
loc_826D79AC:
	// addis r11,r26,6
	r11.s64 = r26.s64 + 393216;
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// addi r11,r11,16952
	r11.s64 = r11.s64 + 16952;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// bne cr6,0x826d79d4
	if (!cr6.eq) goto loc_826D79D4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826d60a0
	ctx.lr = 0x826D79D4;
	sub_826D60A0(ctx, base);
loc_826D79D4:
	// addis r11,r26,6
	r11.s64 = r26.s64 + 393216;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,16964
	r11.s64 = r11.s64 + 16964;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r3,r26,8800
	ctx.r3.s64 = r26.s64 + 8800;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// bl 0x826ed250
	ctx.lr = 0x826D7A08;
	sub_826ED250(ctx, base);
	// addi r3,r26,8516
	ctx.r3.s64 = r26.s64 + 8516;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826f0240
	ctx.lr = 0x826D7A14;
	sub_826F0240(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lbz r8,-27139(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + -27139);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826d7a60
	if (cr6.eq) goto loc_826D7A60;
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16980
	ctx.r10.u64 = r11.u64 | 16980;
	// lwzx r9,r26,r10
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x826d7a60
	if (cr6.lt) goto loc_826D7A60;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r11,76(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d7a60
	if (!cr6.eq) goto loc_826D7A60;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x826d7a64
	if (cr6.eq) goto loc_826D7A64;
loc_826D7A60:
	// li r11,0
	r11.s64 = 0;
loc_826D7A64:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7bb0
	if (!cr6.eq) goto loc_826D7BB0;
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x826D7A78;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7a94
	if (!cr6.eq) goto loc_826D7A94;
	// bl 0x82387a18
	ctx.lr = 0x826D7A88;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7bb0
	if (cr6.eq) goto loc_826D7BB0;
loc_826D7A94:
	// lbzx r11,r20,r21
	r11.u64 = PPC_LOAD_U8(r20.u32 + r21.u32);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7aac
	if (cr6.eq) goto loc_826D7AAC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x826d7ab0
	goto loc_826D7AB0;
loc_826D7AAC:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_826D7AB0:
	// addic. r29,r11,-1
	xer.ca = r11.u32 > 0;
	r29.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// blt 0x826d7bd8
	if (cr0.lt) goto loc_826D7BD8;
	// mulli r11,r29,5936
	r11.s64 = r29.s64 * 5936;
	// addi r10,r29,2
	ctx.r10.s64 = r29.s64 + 2;
	// add r9,r11,r26
	ctx.r9.u64 = r11.u64 + r26.u64;
	// rlwinm r27,r10,2,0,29
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r9,r24
	r28.u64 = ctx.r9.u64 + r24.u64;
loc_826D7ACC:
	// lbzx r11,r20,r21
	r11.u64 = PPC_LOAD_U8(r20.u32 + r21.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7afc
	if (cr6.eq) goto loc_826D7AFC;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x826d7b20
	if (cr6.lt) goto loc_826D7B20;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x826d7b20
	if (!cr6.lt) goto loc_826D7B20;
	// add r11,r27,r3
	r11.u64 = r27.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x826d7b18
	goto loc_826D7B18;
loc_826D7AFC:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x826d7b20
	if (cr6.lt) goto loc_826D7B20;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x826d7b20
	if (!cr6.lt) goto loc_826D7B20;
	// lwzx r11,r27,r3
	r11.u64 = PPC_LOAD_U32(r27.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_826D7B18:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826d7b24
	if (!cr6.eq) goto loc_826D7B24;
loc_826D7B20:
	// li r11,0
	r11.s64 = 0;
loc_826D7B24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7b9c
	if (cr6.eq) goto loc_826D7B9C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x826D7B38;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d7b98
	if (cr6.eq) goto loc_826D7B98;
	// bl 0x82387a18
	ctx.lr = 0x826D7B4C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7b70
	if (cr6.eq) goto loc_826D7B70;
	// lwz r11,1220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d7b98
	if (cr6.eq) goto loc_826D7B98;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d7b98
	if (!cr6.eq) goto loc_826D7B98;
loc_826D7B70:
	// vor128 v2,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r7,r30,608
	ctx.r7.s64 = r30.s64 + 608;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// vspltisw v3,0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826f79f0
	ctx.lr = 0x826D7B98;
	sub_826F79F0(ctx, base);
loc_826D7B98:
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
loc_826D7B9C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r27,r27,-4
	r27.s64 = r27.s64 + -4;
	// addi r28,r28,-5936
	r28.s64 = r28.s64 + -5936;
	// bge 0x826d7acc
	if (!cr0.lt) goto loc_826D7ACC;
	// b 0x826d7bd8
	goto loc_826D7BD8;
loc_826D7BB0:
	// vor128 v2,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// vspltisw v3,0
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826f79f0
	ctx.lr = 0x826D7BD8;
	sub_826F79F0(ctx, base);
loc_826D7BD8:
	// addis r3,r26,6
	ctx.r3.s64 = r26.s64 + 393216;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// add r5,r26,r19
	ctx.r5.u64 = r26.u64 + r19.u64;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826d5b30
	ctx.lr = 0x826D7C04;
	sub_826D5B30(ctx, base);
	// lwz r30,4(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d7c38
	if (cr6.eq) goto loc_826D7C38;
loc_826D7C10:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7C2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826d7c10
	if (!cr6.eq) goto loc_826D7C10;
loc_826D7C38:
	// addi r28,r26,8448
	r28.s64 = r26.s64 + 8448;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826e98a8
	ctx.lr = 0x826D7C44;
	sub_826E98A8(ctx, base);
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// stfs f30,8488(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r26.u32 + 8488, temp.u32);
	// stw r26,8484(r26)
	PPC_STORE_U32(r26.u32 + 8484, r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d7cbc
	if (cr6.eq) goto loc_826D7CBC;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x82576978
	ctx.lr = 0x826D7C60;
	sub_82576978(ctx, base);
	// li r29,0
	r29.s64 = 0;
loc_826D7C64:
	// lwz r11,12(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d7cb0
	if (cr6.eq) goto loc_826D7CB0;
loc_826D7C78:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826D7CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826d7c78
	if (!cr6.eq) goto loc_826D7C78;
loc_826D7CB0:
	// addi r29,r29,52
	r29.s64 = r29.s64 + 52;
	// cmpwi cr6,r29,156
	cr6.compare<int32_t>(r29.s32, 156, xer);
	// blt cr6,0x826d7c64
	if (cr6.lt) goto loc_826D7C64;
loc_826D7CBC:
	// bl 0x826dc630
	ctx.lr = 0x826D7CC0;
	sub_826DC630(ctx, base);
loc_826D7CC0:
	// addi r1,r31,432
	ctx.r1.s64 = r31.s64 + 432;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_826D75D8) {
	__imp__sub_826D75D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D7CE0) {
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
	ctx.lr = 0x826D7CE8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x826D7CF8;
	sub_82130528(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d7d0c
	if (cr6.eq) goto loc_826D7D0C;
	// bl 0x824721d0
	ctx.lr = 0x826D7D08;
	sub_824721D0(ctx, base);
	// b 0x826d7d10
	goto loc_826D7D10;
loc_826D7D0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D7D10:
	// addis r30,r24,6
	r30.s64 = r24.s64 + 393216;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r30,r30,16944
	r30.s64 = r30.s64 + 16944;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// bl 0x824723a8
	ctx.lr = 0x826D7D28;
	sub_824723A8(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824723a8
	ctx.lr = 0x826D7D38;
	sub_824723A8(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x824723a8
	ctx.lr = 0x826D7D48;
	sub_824723A8(ctx, base);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// lwz r29,4(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lwz r25,88(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// beq cr6,0x826d7df0
	if (cr6.eq) goto loc_826D7DF0;
loc_826D7D6C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 108);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826d7de4
	if (!cr6.eq) goto loc_826D7DE4;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d7de4
	if (cr6.eq) goto loc_826D7DE4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7D9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lhz r30,20(r8)
	r30.u64 = PPC_LOAD_U16(ctx.r8.u32 + 20);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826D7DBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d7dd8
	if (cr6.eq) goto loc_826D7DD8;
	// cmpw cr6,r30,r25
	cr6.compare<int32_t>(r30.s32, r25.s32, xer);
	// ble cr6,0x826d7de4
	if (!cr6.gt) goto loc_826D7DE4;
	// mr r25,r30
	r25.u64 = r30.u64;
	// b 0x826d7de4
	goto loc_826D7DE4;
loc_826D7DD8:
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// ble cr6,0x826d7de4
	if (!cr6.gt) goto loc_826D7DE4;
	// mr r26,r30
	r26.u64 = r30.u64;
loc_826D7DE4:
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826d7d6c
	if (!cr6.eq) goto loc_826D7D6C;
loc_826D7DF0:
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x826D7DF8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d7eac
	if (cr6.eq) goto loc_826D7EAC;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r31.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r31.u32);
	// stw r31,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r31.u32);
	// stw r31,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r31.u32);
	// stw r31,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r31.u32);
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r31.u32);
	// stw r31,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r31.u32);
	// stw r31,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r31.u32);
	// stw r31,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r31.u32);
	// stw r31,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r31.u32);
	// stw r31,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r31.u32);
	// stw r31,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r31.u32);
	// stw r31,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r31.u32);
	// stw r31,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r31.u32);
	// stw r31,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r31.u32);
	// stw r31,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r31.u32);
	// stw r31,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r31.u32);
	// stw r31,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r31.u32);
	// stw r31,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r31.u32);
	// stw r31,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r31.u32);
	// stw r31,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r31.u32);
	// stw r31,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r31.u32);
	// stw r31,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r31.u32);
	// stw r31,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r31.u32);
	// stw r31,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r31.u32);
	// stw r31,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r31.u32);
	// stw r31,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r31.u32);
	// stw r31,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r31.u32);
	// stw r31,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r31.u32);
	// stw r31,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, r31.u32);
	// stw r31,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r31.u32);
	// stw r31,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r31.u32);
	// stw r31,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r31.u32);
	// stw r31,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, r31.u32);
	// stw r31,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, r31.u32);
	// stw r10,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r10.u32);
	// b 0x826d7eb0
	goto loc_826D7EB0;
loc_826D7EAC:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_826D7EB0:
	// lbz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r8,16(r24)
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + 16);
	// clrlwi r7,r9,26
	ctx.r7.u64 = ctx.r9.u32 & 0x3F;
	// lbz r6,17(r24)
	ctx.r6.u64 = PPC_LOAD_U8(r24.u32 + 17);
	// rotlwi r5,r8,7
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 7);
	// stw r11,12(r24)
	PPC_STORE_U32(r24.u32 + 12, r11.u32);
	// addi r27,r10,-6240
	r27.s64 = ctx.r10.s64 + -6240;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// rlwimi r4,r6,6,25,25
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x40) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFBF);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r4,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r4.u8);
	// bne cr6,0x826d7f80
	if (!cr6.eq) goto loc_826D7F80;
	// lis r3,5
	ctx.r3.s64 = 327680;
	// ori r3,r3,26704
	ctx.r3.u64 = ctx.r3.u64 | 26704;
	// bl 0x82130528
	ctx.lr = 0x826D7F04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d7f38
	if (cr6.eq) goto loc_826D7F38;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// li r11,98
	r11.s64 = 98;
	// li r30,97
	r30.s64 = 97;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
loc_826D7F20:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826e8d80
	ctx.lr = 0x826D7F28;
	sub_826E8D80(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,3616
	r29.s64 = r29.s64 + 3616;
	// bge 0x826d7f20
	if (!cr0.lt) goto loc_826D7F20;
	// b 0x826d7f3c
	goto loc_826D7F3C;
loc_826D7F38:
	// mr r28,r31
	r28.u64 = r31.u64;
loc_826D7F3C:
	// mr r30,r28
	r30.u64 = r28.u64;
	// li r29,98
	r29.s64 = 98;
loc_826D7F44:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7F64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,3616
	r30.s64 = r30.s64 + 3616;
	// bne 0x826d7f44
	if (!cr0.eq) goto loc_826D7F44;
	// li r5,98
	ctx.r5.s64 = 98;
	// lwz r3,12(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x826d5498
	ctx.lr = 0x826D7F80;
	sub_826D5498(ctx, base);
loc_826D7F80:
	// lis r3,2
	ctx.r3.s64 = 131072;
	// ori r3,r3,49744
	ctx.r3.u64 = ctx.r3.u64 | 49744;
	// bl 0x82130528
	ctx.lr = 0x826D7F8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d7fc0
	if (cr6.eq) goto loc_826D7FC0;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// li r11,50
	r11.s64 = 50;
	// li r30,49
	r30.s64 = 49;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
loc_826D7FA8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826e8d80
	ctx.lr = 0x826D7FB0;
	sub_826E8D80(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,3616
	r29.s64 = r29.s64 + 3616;
	// bge 0x826d7fa8
	if (!cr0.lt) goto loc_826D7FA8;
	// b 0x826d7fc4
	goto loc_826D7FC4;
loc_826D7FC0:
	// mr r28,r31
	r28.u64 = r31.u64;
loc_826D7FC4:
	// mr r30,r28
	r30.u64 = r28.u64;
	// li r29,50
	r29.s64 = 50;
loc_826D7FCC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D7FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,3616
	r30.s64 = r30.s64 + 3616;
	// bne 0x826d7fcc
	if (!cr0.eq) goto loc_826D7FCC;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// li r5,50
	ctx.r5.s64 = 50;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,52
	ctx.r3.s64 = r11.s64 + 52;
	// bl 0x826d5498
	ctx.lr = 0x826D800C;
	sub_826D5498(ctx, base);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d80a4
	if (!cr6.eq) goto loc_826D80A4;
	// lis r3,4
	ctx.r3.s64 = 262144;
	// ori r3,r3,52240
	ctx.r3.u64 = ctx.r3.u64 | 52240;
	// bl 0x82130528
	ctx.lr = 0x826D8024;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d8058
	if (cr6.eq) goto loc_826D8058;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// li r11,64
	r11.s64 = 64;
	// li r30,63
	r30.s64 = 63;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// mr r29,r28
	r29.u64 = r28.u64;
loc_826D8040:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ebdb0
	ctx.lr = 0x826D8048;
	sub_826EBDB0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4912
	r29.s64 = r29.s64 + 4912;
	// bge 0x826d8040
	if (!cr0.lt) goto loc_826D8040;
	// b 0x826d805c
	goto loc_826D805C;
loc_826D8058:
	// mr r28,r31
	r28.u64 = r31.u64;
loc_826D805C:
	// mr r30,r28
	r30.u64 = r28.u64;
	// li r29,64
	r29.s64 = 64;
loc_826D8064:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D8084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4912
	r30.s64 = r30.s64 + 4912;
	// bne 0x826d8064
	if (!cr0.eq) goto loc_826D8064;
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,104
	ctx.r3.s64 = r11.s64 + 104;
	// bl 0x826d5500
	ctx.lr = 0x826D80A4;
	sub_826D5500(ctx, base);
loc_826D80A4:
	// lwz r30,12(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// li r29,3
	r29.s64 = 3;
loc_826D80AC:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r28,r30,8
	r28.s64 = r30.s64 + 8;
	// bl 0x826d6c50
	ctx.lr = 0x826D80C0;
	sub_826D6C50(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x826d6c50
	ctx.lr = 0x826D80D0;
	sub_826D6C50(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// bne 0x826d80ac
	if (!cr0.eq) goto loc_826D80AC;
	// lwz r29,4(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d81a4
	if (cr6.eq) goto loc_826D81A4;
loc_826D80E8:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D80FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d811c
	if (!cr6.eq) goto loc_826D811C;
	// lwz r29,4(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826d80e8
	if (!cr6.eq) goto loc_826D80E8;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_826D811C:
	// li r3,400
	ctx.r3.s64 = 400;
	// bl 0x82130528
	ctx.lr = 0x826D8124;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826d8198
	if (cr6.eq) goto loc_826D8198;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,168(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D8148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r7,r8,4448
	ctx.r7.s64 = ctx.r8.s64 + 4448;
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// li r29,17
	r29.s64 = 17;
loc_826D8160:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82519b70
	ctx.lr = 0x826D8168;
	sub_82519B70(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,20
	r28.s64 = r28.s64 + 20;
	// bge 0x826d8160
	if (!cr0.lt) goto loc_826D8160;
	// stw r31,364(r30)
	PPC_STORE_U32(r30.u32 + 364, r31.u32);
	// addi r3,r30,368
	ctx.r3.s64 = r30.s64 + 368;
	// bl 0x821c8ed8
	ctx.lr = 0x826D8180;
	sub_821C8ED8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d6698
	ctx.lr = 0x826D8194;
	sub_826D6698(ctx, base);
	// mr r31,r30
	r31.u64 = r30.u64;
loc_826D8198:
	// lis r11,6
	r11.s64 = 393216;
	// ori r10,r11,16940
	ctx.r10.u64 = r11.u64 | 16940;
	// stwx r31,r24,r10
	PPC_STORE_U32(r24.u32 + ctx.r10.u32, r31.u32);
loc_826D81A4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_826D7CE0) {
	__imp__sub_826D7CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D81AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D81AC) {
	__imp__sub_826D81AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D81B0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x826D81B8;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stb r5,1207(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1207, ctx.r5.u8);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r26,r11,5008
	r26.s64 = r11.s64 + 5008;
	// addi r23,r10,30576
	r23.s64 = ctx.r10.s64 + 30576;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821ca540
	ctx.lr = 0x826D81EC;
	sub_821CA540(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r5,r11,4996
	ctx.r5.s64 = r11.s64 + 4996;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x826D8208;
	sub_821CA6A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x826d823c
	if (!cr6.eq) goto loc_826D823C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826D8220;
	sub_821C9A90(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,4960
	ctx.r3.s64 = r11.s64 + 4960;
	// bl 0x82130000
	ctx.lr = 0x826D8230;
	sub_82130000(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_826D823C:
	// lwz r18,0(r13)
	r18.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r17,28
	r17.s64 = 28;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r15,r11,-27096
	r15.s64 = r11.s64 + -27096;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r14,r17,r18
	r14.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// addi r3,r10,4936
	ctx.r3.s64 = ctx.r10.s64 + 4936;
	// stwx r15,r17,r18
	PPC_STORE_U32(r17.u32 + r18.u32, r15.u32);
	// stw r14,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r14.u32);
	// bl 0x82130000
	ctx.lr = 0x826D8268;
	sub_82130000(ctx, base);
	// lwzx r3,r17,r18
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826D827C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d1cd0
	ctx.lr = 0x826D8288;
	sub_821D1CD0(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cf7b8
	ctx.lr = 0x826D8298;
	sub_821CF7B8(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-17952
	ctx.r4.s64 = ctx.r7.s64 + -17952;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826D82AC;
	sub_821CFF40(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d0490
	ctx.lr = 0x826D82B8;
	sub_821D0490(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// beq cr6,0x826d82d8
	if (cr6.eq) goto loc_826D82D8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r11,4872
	ctx.r3.s64 = r11.s64 + 4872;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x82130000
	ctx.lr = 0x826D82D8;
	sub_82130000(ctx, base);
loc_826D82D8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// addi r24,r11,-29624
	r24.s64 = r11.s64 + -29624;
	// li r29,0
	r29.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821d0898
	ctx.lr = 0x826D82F0;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r28,r11,-29628
	r28.s64 = r11.s64 + -29628;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821cfe80
	ctx.lr = 0x826D8308;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d8530
	if (!cr6.eq) goto loc_826D8530;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r26,r11,4324
	r26.s64 = r11.s64 + 4324;
	// addi r25,r10,4052
	r25.s64 = ctx.r10.s64 + 4052;
	// addi r22,r9,4844
	r22.s64 = ctx.r9.s64 + 4844;
	// addi r21,r8,4824
	r21.s64 = ctx.r8.s64 + 4824;
	// addi r20,r7,19016
	r20.s64 = ctx.r7.s64 + 19016;
	// addi r19,r6,-6708
	r19.s64 = ctx.r6.s64 + -6708;
loc_826D8344:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826D8354;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8448
	if (cr6.eq) goto loc_826D8448;
	// li r3,272
	ctx.r3.s64 = 272;
	// bl 0x82130528
	ctx.lr = 0x826D8368;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d8508
	if (cr6.eq) goto loc_826D8508;
	// bl 0x826e4cd8
	ctx.lr = 0x826D8378;
	sub_826E4CD8(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_826D837C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d8508
	if (cr6.eq) goto loc_826D8508;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfaa8
	ctx.lr = 0x826D8394;
	sub_821CFAA8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d0898
	ctx.lr = 0x826D83A0;
	sub_821D0898(ctx, base);
	// lbz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 112);
	// lbz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// clrlwi r7,r9,26
	ctx.r7.u64 = ctx.r9.u32 & 0x3F;
	// lbz r6,17(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 17);
	// rotlwi r5,r8,7
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 7);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r29,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r29.u32);
	// or r11,r5,r7
	r11.u64 = ctx.r5.u64 | ctx.r7.u64;
	// stw r14,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r14.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// rlwimi r11,r6,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stb r11,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826D83F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821d0898
	ctx.lr = 0x826D8404;
	sub_821D0898(ctx, base);
	// clrlwi r7,r14,24
	ctx.r7.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826d8508
	if (cr6.eq) goto loc_826D8508;
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r9,r30,4
	ctx.r9.s64 = r30.s64 + 4;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d8500
	if (cr6.eq) goto loc_826D8500;
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
	// beq cr6,0x826d8440
	if (cr6.eq) goto loc_826D8440;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
loc_826D8440:
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// b 0x826d8504
	goto loc_826D8504;
loc_826D8448:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826D8458;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8484
	if (cr6.eq) goto loc_826D8484;
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x826D846C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d8508
	if (cr6.eq) goto loc_826D8508;
	// bl 0x826e4158
	ctx.lr = 0x826D847C;
	sub_826E4158(ctx, base);
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// b 0x826d837c
	goto loc_826D837C;
loc_826D8484:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cff40
	ctx.lr = 0x826D8494;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d84c4
	if (cr6.eq) goto loc_826D84C4;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfaa8
	ctx.lr = 0x826D84B0;
	sub_821CFAA8(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r30,8536
	ctx.r3.s64 = r30.s64 + 8536;
	// bl 0x826db928
	ctx.lr = 0x826D84C0;
	sub_826DB928(ctx, base);
	// b 0x826d8508
	goto loc_826D8508;
loc_826D84C4:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x826D84D0;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8508
	if (cr6.eq) goto loc_826D8508;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfaa8
	ctx.lr = 0x826D84EC;
	sub_821CFAA8(ctx, base);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r30,8536
	ctx.r3.s64 = r30.s64 + 8536;
	// bl 0x826db928
	ctx.lr = 0x826D84FC;
	sub_826DB928(ctx, base);
	// b 0x826d8508
	goto loc_826D8508;
loc_826D8500:
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
loc_826D8504:
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
loc_826D8508:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821cfe80
	ctx.lr = 0x826D8518;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r14,88(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8344
	if (cr6.eq) goto loc_826D8344;
	// lwz r25,92(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826D8530:
	// lbz r10,1207(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1207);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d8544
	if (cr6.eq) goto loc_826D8544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d7ce0
	ctx.lr = 0x826D8544;
	sub_826D7CE0(ctx, base);
loc_826D8544:
	// lwzx r3,r17,r18
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D8558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subf r9,r3,r16
	ctx.r9.s64 = r16.s64 - ctx.r3.s64;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r3,r6,4788
	ctx.r3.s64 = ctx.r6.s64 + 4788;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f31,-18280(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18280);
	f31.f64 = double(temp.f32);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x826D8590;
	sub_82130000(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// addi r4,r5,-6208
	ctx.r4.s64 = ctx.r5.s64 + -6208;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d85b0
	if (cr6.eq) goto loc_826D85B0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,832
	ctx.r5.s64 = r11.s64 + 832;
	// b 0x826d85b8
	goto loc_826D85B8;
loc_826D85B0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,812
	ctx.r5.s64 = r11.s64 + 812;
loc_826D85B8:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82137a08
	ctx.lr = 0x826D85C8;
	sub_82137A08(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// bl 0x821ca540
	ctx.lr = 0x826D85D4;
	sub_821CA540(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-19364
	ctx.r4.s64 = r11.s64 + -19364;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x8224c378
	ctx.lr = 0x826D85F0;
	sub_8224C378(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826D85F8;
	sub_821C9A90(ctx, base);
	// lwzx r3,r17,r18
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826D860C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r7,r8,-27136
	ctx.r7.s64 = ctx.r8.s64 + -27136;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8668
	if (cr6.eq) goto loc_826D8668;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82137a08
	ctx.lr = 0x826D8634;
	sub_82137A08(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// bl 0x821ca540
	ctx.lr = 0x826D8640;
	sub_821CA540(ctx, base);
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e2eb8
	ctx.lr = 0x826D865C;
	sub_826E2EB8(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826D8664;
	sub_821C9A90(ctx, base);
	// b 0x826d8678
	goto loc_826D8678;
loc_826D8668:
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e2e48
	ctx.lr = 0x826D8678;
	sub_826E2E48(ctx, base);
loc_826D8678:
	// lwzx r3,r17,r18
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D868C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// subf r8,r29,r31
	ctx.r8.s64 = r31.s64 - r29.s64;
	// addi r3,r9,4752
	ctx.r3.s64 = ctx.r9.s64 + 4752;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x826D86C0;
	sub_82130000(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826D86C8;
	sub_821C9A90(ctx, base);
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r3,r6,4720
	ctx.r3.s64 = ctx.r6.s64 + 4720;
	// bl 0x82130000
	ctx.lr = 0x826D86D4;
	sub_82130000(ctx, base);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// addi r3,r5,4684
	ctx.r3.s64 = ctx.r5.s64 + 4684;
	// bl 0x82130000
	ctx.lr = 0x826D86E0;
	sub_82130000(ctx, base);
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// addi r3,r3,16936
	ctx.r3.s64 = ctx.r3.s64 + 16936;
	// bl 0x826f88b0
	ctx.lr = 0x826D86EC;
	sub_826F88B0(ctx, base);
	// lwzx r3,r17,r18
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826D8700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// subf r10,r3,r29
	ctx.r10.s64 = r29.s64 - ctx.r3.s64;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r3,r9,4644
	ctx.r3.s64 = ctx.r9.s64 + 4644;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fmuls f1,f9,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 * f31.f64));
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x826D8730;
	sub_82130000(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r6,r7,-12992
	ctx.r6.s64 = ctx.r7.s64 + -12992;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8764
	if (cr6.eq) goto loc_826D8764;
	// addis r10,r30,6
	ctx.r10.s64 = r30.s64 + 393216;
	// addi r10,r10,17540
	ctx.r10.s64 = ctx.r10.s64 + 17540;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
loc_826D8750:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826d8750
	if (!cr6.eq) goto loc_826D8750;
loc_826D8764:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826D876C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq cr6,0x826d8798
	if (cr6.eq) goto loc_826D8798;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// sth r31,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r31.u16);
	// sth r31,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r31.u16);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stb r31,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r31.u8);
	// b 0x826d879c
	goto loc_826D879C;
loc_826D8798:
	// li r11,0
	r11.s64 = 0;
loc_826D879C:
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,6756
	ctx.r3.s64 = 6756;
	// bl 0x82130550
	ctx.lr = 0x826D87AC;
	sub_82130550(ctx, base);
	// li r11,562
	r11.s64 = 562;
	// stw r3,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r3.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
loc_826D87BC:
	// addi r9,r10,12
	ctx.r9.s64 = ctx.r10.s64 + 12;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// bne 0x826d87bc
	if (!cr0.eq) goto loc_826D87BC;
	// stw r31,6744(r3)
	PPC_STORE_U32(ctx.r3.u32 + 6744, r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,562
	ctx.r4.s64 = 562;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// bl 0x826d4e28
	ctx.lr = 0x826D87E4;
	sub_826D4E28(ctx, base);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// stw r10,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r10.u32);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// stw r9,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r9.u32);
	// lwzx r31,r17,r18
	r31.u64 = PPC_LOAD_U32(r17.u32 + r18.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826D8810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,32(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826D882C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,4596
	ctx.r3.s64 = r11.s64 + 4596;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x826D8840;
	sub_82130000(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stwx r14,r17,r18
	PPC_STORE_U32(r17.u32 + r18.u32, r14.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r9,r10,-30140
	ctx.r9.s64 = ctx.r10.s64 + -30140;
	// stw r9,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// bl 0x821be610
	ctx.lr = 0x826D8858;
	sub_821BE610(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_826D81B0) {
	__imp__sub_826D81B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D8864) {
	__imp__sub_826D8864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8868) {
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
	ctx.lr = 0x826D8870;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,28
	r27.s64 = 28;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r11,-27096
	ctx.r10.s64 = r11.s64 + -27096;
	// addi r31,r30,20
	r31.s64 = r30.s64 + 20;
	// lwzx r26,r27,r28
	r26.u64 = PPC_LOAD_U32(r27.u32 + r28.u32);
	// stwx r10,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, ctx.r10.u32);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d88a4
	if (cr6.eq) goto loc_826D88A4;
	// bl 0x82130588
	ctx.lr = 0x826D88A4;
	sub_82130588(ctx, base);
loc_826D88A4:
	// li r29,0
	r29.s64 = 0;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// bl 0x826d6b98
	ctx.lr = 0x826D88B8;
	sub_826D6B98(ctx, base);
	// lwz r31,36(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826d88d4
	if (cr6.eq) goto loc_826D88D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d6b98
	ctx.lr = 0x826D88CC;
	sub_826D6B98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826D88D4;
	sub_82130588(ctx, base);
loc_826D88D4:
	// stw r29,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r29.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d8928
	if (cr6.eq) goto loc_826D8928;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bne cr6,0x826d88f8
	if (!cr6.eq) goto loc_826D88F8;
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
loc_826D88F8:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d890c
	if (cr6.eq) goto loc_826D890C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_826D890C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d8920
	if (cr6.eq) goto loc_826D8920;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_826D8920:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
loc_826D8928:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d89b8
	if (cr6.eq) goto loc_826D89B8;
loc_826D8934:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826e3aa8
	ctx.lr = 0x826D893C;
	sub_826E3AA8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d895c
	if (cr6.eq) goto loc_826D895C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D895C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826D895C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d89ac
	if (cr6.eq) goto loc_826D89AC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bne cr6,0x826d897c
	if (!cr6.eq) goto loc_826D897C;
	// stw r29,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r29.u32);
loc_826D897C:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d8990
	if (cr6.eq) goto loc_826D8990;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_826D8990:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d89a4
	if (cr6.eq) goto loc_826D89A4;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_826D89A4:
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// stw r29,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r29.u32);
loc_826D89AC:
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d8934
	if (!cr6.eq) goto loc_826D8934;
loc_826D89B8:
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x82246108
	ctx.lr = 0x826D89C4;
	sub_82246108(ctx, base);
	// addi r3,r30,8536
	ctx.r3.s64 = r30.s64 + 8536;
	// bl 0x826db990
	ctx.lr = 0x826D89CC;
	sub_826DB990(ctx, base);
	// addis r3,r30,6
	ctx.r3.s64 = r30.s64 + 393216;
	// addi r3,r3,16936
	ctx.r3.s64 = ctx.r3.s64 + 16936;
	// bl 0x826f7c90
	ctx.lr = 0x826D89D8;
	sub_826F7C90(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d6aa0
	ctx.lr = 0x826D89E0;
	sub_826D6AA0(ctx, base);
	// stwx r26,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826D8868) {
	__imp__sub_826D8868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D89EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D89EC) {
	__imp__sub_826D89EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D89F0) {
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
	ctx.lr = 0x826D89F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r25,28
	r25.s64 = 28;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// addi r10,r11,-27096
	ctx.r10.s64 = r11.s64 + -27096;
	// stb r4,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r4.u8);
	// stb r5,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r5.u8);
	// lwzx r23,r25,r26
	r23.u64 = PPC_LOAD_U32(r25.u32 + r26.u32);
	// stwx r10,r25,r26
	PPC_STORE_U32(r25.u32 + r26.u32, ctx.r10.u32);
	// lbz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d8a38
	if (cr6.eq) goto loc_826D8A38;
	// bl 0x8278fc18
	ctx.lr = 0x826D8A34;
	sub_8278FC18(ctx, base);
	// bl 0x8278fd20
	ctx.lr = 0x826D8A38;
	sub_8278FD20(ctx, base);
loc_826D8A38:
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed200
	ctx.lr = 0x826D8A40;
	sub_826ED200(ctx, base);
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D8A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,8536
	ctx.r3.s64 = r31.s64 + 8536;
	// bl 0x826da258
	ctx.lr = 0x826D8A64;
	sub_826DA258(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x8273e7d8
	ctx.lr = 0x826D8A6C;
	sub_8273E7D8(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// mr r30,r27
	r30.u64 = r27.u64;
	// addi r29,r29,29296
	r29.s64 = r29.s64 + 29296;
loc_826D8A7C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826f4cb8
	ctx.lr = 0x826D8A8C;
	sub_826F4CB8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,5936
	r29.s64 = r29.s64 + 5936;
	// cmpwi cr6,r30,31
	cr6.compare<int32_t>(r30.s32, 31, xer);
	// blt cr6,0x826d8a7c
	if (cr6.lt) goto loc_826D8A7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,8516
	ctx.r3.s64 = r31.s64 + 8516;
	// bl 0x826efb30
	ctx.lr = 0x826D8AA8;
	sub_826EFB30(ctx, base);
	// bl 0x82796d70
	ctx.lr = 0x826D8AAC;
	sub_82796D70(ctx, base);
	// li r29,2
	r29.s64 = 2;
	// stw r3,8492(r31)
	PPC_STORE_U32(r31.u32 + 8492, ctx.r3.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826D8AB8:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r28,r30,8
	r28.s64 = r30.s64 + 8;
	// bl 0x826d6c50
	ctx.lr = 0x826D8ACC;
	sub_826D6C50(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x826d6c50
	ctx.lr = 0x826D8ADC;
	sub_826D6C50(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// bne 0x826d8ab8
	if (!cr0.eq) goto loc_826D8AB8;
	// lis r11,6
	r11.s64 = 393216;
	// stw r27,8496(r31)
	PPC_STORE_U32(r31.u32 + 8496, r27.u32);
	// stw r27,8500(r31)
	PPC_STORE_U32(r31.u32 + 8500, r27.u32);
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// ori r9,r11,16956
	ctx.r9.u64 = r11.u64 | 16956;
	// stw r27,8504(r31)
	PPC_STORE_U32(r31.u32 + 8504, r27.u32);
	// stw r27,8508(r31)
	PPC_STORE_U32(r31.u32 + 8508, r27.u32);
	// addi r11,r31,8496
	r11.s64 = r31.s64 + 8496;
	// stw r27,8512(r31)
	PPC_STORE_U32(r31.u32 + 8512, r27.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r27,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r27.u32);
	// beq cr6,0x826d8b1c
	if (cr6.eq) goto loc_826D8B1C;
	// bl 0x826ed6f0
	ctx.lr = 0x826D8B1C;
	sub_826ED6F0(ctx, base);
loc_826D8B1C:
	// stwx r23,r25,r26
	PPC_STORE_U32(r25.u32 + r26.u32, r23.u32);
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// bl 0x826d9638
	ctx.lr = 0x826D8B30;
	sub_826D9638(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r3,r11,-2928
	ctx.r3.s64 = r11.s64 + -2928;
	// bl 0x8257d068
	ctx.lr = 0x826D8B3C;
	sub_8257D068(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_826D89F0) {
	__imp__sub_826D89F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D8B44) {
	__imp__sub_826D8B44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826D8B50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e1ce8
	ctx.lr = 0x826D8B64;
	sub_826E1CE8(ctx, base);
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x82130000
	ctx.lr = 0x826D8B6C;
	sub_82130000(ctx, base);
	// lbz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r28,0
	r28.s64 = 0;
	// ori r7,r8,240
	ctx.r7.u64 = ctx.r8.u64 | 240;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stb r7,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r7.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r11,-27137(r10)
	PPC_STORE_U8(ctx.r10.u32 + -27137, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D8B94;
	sub_826D56F0(ctx, base);
	// addis r29,r31,3
	r29.s64 = r31.s64 + 196608;
	// li r30,31
	r30.s64 = 31;
	// addi r29,r29,29296
	r29.s64 = r29.s64 + 29296;
loc_826D8BA0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826f4e50
	ctx.lr = 0x826D8BA8;
	sub_826F4E50(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,5936
	r29.s64 = r29.s64 + 5936;
	// bne 0x826d8ba0
	if (!cr0.eq) goto loc_826D8BA0;
	// lis r11,6
	r11.s64 = 393216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lwz r30,8492(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8492);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// lis r6,6
	ctx.r6.s64 = 393216;
	// ori r4,r11,16952
	ctx.r4.u64 = r11.u64 | 16952;
	// ori r3,r10,16956
	ctx.r3.u64 = ctx.r10.u64 | 16956;
	// ori r11,r9,16964
	r11.u64 = ctx.r9.u64 | 16964;
	// ori r10,r8,17136
	ctx.r10.u64 = ctx.r8.u64 | 17136;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// ori r9,r7,17105
	ctx.r9.u64 = ctx.r7.u64 | 17105;
	// ori r8,r6,17106
	ctx.r8.u64 = ctx.r6.u64 | 17106;
	// stwx r28,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r28.u32);
	// li r29,2
	r29.s64 = 2;
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfsx f0,r31,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// stbx r28,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r28.u8);
	// stfsx f0,r31,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// stbx r28,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r28.u8);
loc_826D8C10:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r27,r30,8
	r27.s64 = r30.s64 + 8;
	// bl 0x826d6c50
	ctx.lr = 0x826D8C24;
	sub_826D6C50(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x826d6c50
	ctx.lr = 0x826D8C34;
	sub_826D6C50(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,52
	r30.s64 = r30.s64 + 52;
	// bne 0x826d8c10
	if (!cr0.eq) goto loc_826D8C10;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// lis r11,6
	r11.s64 = 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// ori r5,r11,16979
	ctx.r5.u64 = r11.u64 | 16979;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r4,r10,16978
	ctx.r4.u64 = ctx.r10.u64 | 16978;
	// ori r11,r9,16977
	r11.u64 = ctx.r9.u64 | 16977;
	// ori r10,r8,16976
	ctx.r10.u64 = ctx.r8.u64 | 16976;
	// ori r9,r7,16980
	ctx.r9.u64 = ctx.r7.u64 | 16980;
	// lwz r8,16(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// stbx r28,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r28.u8);
	// stbx r28,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r28.u8);
	// stbx r28,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r28.u8);
	// stbx r28,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r28.u8);
	// stwx r28,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r28.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826D8C94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,8448
	ctx.r3.s64 = r31.s64 + 8448;
	// bl 0x826e98a8
	ctx.lr = 0x826D8C9C;
	sub_826E98A8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826D8B48) {
	__imp__sub_826D8B48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D8CA4) {
	__imp__sub_826D8CA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8CA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x826d8b48
	sub_826D8B48(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D8CA8) {
	__imp__sub_826D8CA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8CBC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D8CBC) {
	__imp__sub_826D8CBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8CC0) {
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
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,26568
	ctx.r4.s64 = r11.s64 + 26568;
	// addi r3,r10,5556
	ctx.r3.s64 = ctx.r10.s64 + 5556;
	// bl 0x82554798
	ctx.lr = 0x826D8CE0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,20856
	ctx.r4.s64 = ctx.r9.s64 + 20856;
	// addi r3,r8,5528
	ctx.r3.s64 = ctx.r8.s64 + 5528;
	// bl 0x82554798
	ctx.lr = 0x826D8CF4;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,26608
	ctx.r4.s64 = ctx.r7.s64 + 26608;
	// addi r3,r6,5500
	ctx.r3.s64 = ctx.r6.s64 + 5500;
	// bl 0x82554798
	ctx.lr = 0x826D8D08;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,20880
	ctx.r4.s64 = ctx.r5.s64 + 20880;
	// addi r3,r3,5472
	ctx.r3.s64 = ctx.r3.s64 + 5472;
	// bl 0x82554798
	ctx.lr = 0x826D8D1C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,26640
	ctx.r4.s64 = r11.s64 + 26640;
	// addi r3,r10,5444
	ctx.r3.s64 = ctx.r10.s64 + 5444;
	// bl 0x82554798
	ctx.lr = 0x826D8D30;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,20904
	ctx.r4.s64 = ctx.r9.s64 + 20904;
	// addi r3,r8,5416
	ctx.r3.s64 = ctx.r8.s64 + 5416;
	// bl 0x82554798
	ctx.lr = 0x826D8D44;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,20928
	ctx.r4.s64 = ctx.r7.s64 + 20928;
	// addi r3,r6,5388
	ctx.r3.s64 = ctx.r6.s64 + 5388;
	// bl 0x82554798
	ctx.lr = 0x826D8D58;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,20960
	ctx.r4.s64 = ctx.r5.s64 + 20960;
	// addi r3,r3,5356
	ctx.r3.s64 = ctx.r3.s64 + 5356;
	// bl 0x82554798
	ctx.lr = 0x826D8D6C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,26672
	ctx.r4.s64 = r11.s64 + 26672;
	// addi r3,r10,5324
	ctx.r3.s64 = ctx.r10.s64 + 5324;
	// bl 0x82554798
	ctx.lr = 0x826D8D80;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,26704
	ctx.r4.s64 = ctx.r9.s64 + 26704;
	// addi r3,r8,5292
	ctx.r3.s64 = ctx.r8.s64 + 5292;
	// bl 0x82554798
	ctx.lr = 0x826D8D94;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,26888
	ctx.r4.s64 = ctx.r7.s64 + 26888;
	// addi r3,r6,5260
	ctx.r3.s64 = ctx.r6.s64 + 5260;
	// bl 0x82554798
	ctx.lr = 0x826D8DA8;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,26984
	ctx.r4.s64 = ctx.r5.s64 + 26984;
	// addi r3,r3,5228
	ctx.r3.s64 = ctx.r3.s64 + 5228;
	// bl 0x82554798
	ctx.lr = 0x826D8DBC;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,23768
	ctx.r4.s64 = r11.s64 + 23768;
	// addi r3,r10,5192
	ctx.r3.s64 = ctx.r10.s64 + 5192;
	// bl 0x82554798
	ctx.lr = 0x826D8DD0;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,27080
	ctx.r4.s64 = ctx.r9.s64 + 27080;
	// addi r3,r8,5164
	ctx.r3.s64 = ctx.r8.s64 + 5164;
	// bl 0x82554798
	ctx.lr = 0x826D8DE4;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,27200
	ctx.r4.s64 = ctx.r7.s64 + 27200;
	// addi r3,r6,5144
	ctx.r3.s64 = ctx.r6.s64 + 5144;
	// bl 0x82554798
	ctx.lr = 0x826D8DF8;
	sub_82554798(ctx, base);
	// lis r5,-32146
	ctx.r5.s64 = -2106720256;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,-29528
	ctx.r4.s64 = ctx.r5.s64 + -29528;
	// addi r3,r3,5120
	ctx.r3.s64 = ctx.r3.s64 + 5120;
	// bl 0x82554798
	ctx.lr = 0x826D8E0C;
	sub_82554798(ctx, base);
	// lis r11,-32147
	r11.s64 = -2106785792;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,20984
	ctx.r4.s64 = r11.s64 + 20984;
	// addi r3,r10,5096
	ctx.r3.s64 = ctx.r10.s64 + 5096;
	// bl 0x82554798
	ctx.lr = 0x826D8E20;
	sub_82554798(ctx, base);
	// lis r9,-32147
	ctx.r9.s64 = -2106785792;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,21008
	ctx.r4.s64 = ctx.r9.s64 + 21008;
	// addi r3,r8,5072
	ctx.r3.s64 = ctx.r8.s64 + 5072;
	// bl 0x82554798
	ctx.lr = 0x826D8E34;
	sub_82554798(ctx, base);
	// lis r7,-32147
	ctx.r7.s64 = -2106785792;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,21040
	ctx.r4.s64 = ctx.r7.s64 + 21040;
	// addi r3,r6,5048
	ctx.r3.s64 = ctx.r6.s64 + 5048;
	// bl 0x82554798
	ctx.lr = 0x826D8E48;
	sub_82554798(ctx, base);
	// lis r5,-32147
	ctx.r5.s64 = -2106785792;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,23824
	ctx.r4.s64 = ctx.r5.s64 + 23824;
	// addi r3,r3,5024
	ctx.r3.s64 = ctx.r3.s64 + 5024;
	// bl 0x82554798
	ctx.lr = 0x826D8E5C;
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

PPC_WEAK_FUNC(sub_826D8CC0) {
	__imp__sub_826D8CC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D8E6C) {
	__imp__sub_826D8E6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D8E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x826D8E78;
	// stfd f31,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,5588
	ctx.r10.s64 = r11.s64 + 5588;
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x8273e5c0
	ctx.lr = 0x826D8EBC;
	sub_8273E5C0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r11,r31,8448
	r11.s64 = r31.s64 + 8448;
	// stw r30,8484(r31)
	PPC_STORE_U32(r31.u32 + 8484, r30.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,9
	ctx.r10.s64 = 9;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,8488(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8488, temp.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_826D8EDC:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x826d8edc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826D8EDC;
	// li r11,-1
	r11.s64 = -1;
	// stw r30,8492(r31)
	PPC_STORE_U32(r31.u32 + 8492, r30.u32);
	// stw r30,8516(r31)
	PPC_STORE_U32(r31.u32 + 8516, r30.u32);
	// addi r3,r31,8536
	ctx.r3.s64 = r31.s64 + 8536;
	// stw r11,8524(r31)
	PPC_STORE_U32(r31.u32 + 8524, r11.u32);
	// bl 0x826dbd40
	ctx.lr = 0x826D8F00;
	sub_826DBD40(ctx, base);
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed660
	ctx.lr = 0x826D8F08;
	sub_826ED660(ctx, base);
	// addis r28,r31,3
	r28.s64 = r31.s64 + 196608;
	// li r29,30
	r29.s64 = 30;
	// addi r28,r28,29296
	r28.s64 = r28.s64 + 29296;
loc_826D8F14:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826f5cb0
	ctx.lr = 0x826D8F1C;
	sub_826F5CB0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,5936
	r28.s64 = r28.s64 + 5936;
	// bge 0x826d8f14
	if (!cr0.lt) goto loc_826D8F14;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x8273dbb0
	ctx.lr = 0x826D8F34;
	sub_8273DBB0(ctx, base);
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e06d0
	ctx.lr = 0x826D8F40;
	sub_826E06D0(ctx, base);
	// lis r11,6
	r11.s64 = 393216;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// ori r7,r11,16936
	ctx.r7.u64 = r11.u64 | 16936;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// ori r5,r10,16940
	ctx.r5.u64 = ctx.r10.u64 | 16940;
	// ori r4,r9,16944
	ctx.r4.u64 = ctx.r9.u64 | 16944;
	// ori r11,r8,16960
	r11.u64 = ctx.r8.u64 | 16960;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stwx r30,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r30.u32);
	// addi r3,r3,16992
	ctx.r3.s64 = ctx.r3.s64 + 16992;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// stfsx f0,r31,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// bl 0x826d95f8
	ctx.lr = 0x826D8F84;
	sub_826D95F8(ctx, base);
	// lis r10,6
	ctx.r10.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r6,6
	ctx.r6.s64 = 393216;
	// ori r4,r10,17088
	ctx.r4.u64 = ctx.r10.u64 | 17088;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// ori r10,r8,17094
	ctx.r10.u64 = ctx.r8.u64 | 17094;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// ori r8,r6,17096
	ctx.r8.u64 = ctx.r6.u64 | 17096;
	// lis r5,6
	ctx.r5.s64 = 393216;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// ori r3,r9,17093
	ctx.r3.u64 = ctx.r9.u64 | 17093;
	// addis r6,r31,6
	ctx.r6.s64 = r31.s64 + 393216;
	// ori r9,r7,17095
	ctx.r9.u64 = ctx.r7.u64 | 17095;
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// ori r7,r5,17103
	ctx.r7.u64 = ctx.r5.u64 | 17103;
	// addi r6,r6,17152
	ctx.r6.s64 = ctx.r6.s64 + 17152;
	// addi r11,r11,17168
	r11.s64 = r11.s64 + 17168;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// li r29,1
	r29.s64 = 1;
	// addi r4,r5,3832
	ctx.r4.s64 = ctx.r5.s64 + 3832;
	// stbx r29,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r29.u8);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stbx r29,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r29.u8);
	// stbx r29,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r29.u8);
	// stbx r29,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r29.u8);
	// stbx r29,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r29.u8);
	// stb r30,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r30.u8);
	// stb r30,1(r6)
	PPC_STORE_U8(ctx.r6.u32 + 1, r30.u8);
	// stb r30,2(r6)
	PPC_STORE_U8(ctx.r6.u32 + 2, r30.u8);
	// stb r30,3(r6)
	PPC_STORE_U8(ctx.r6.u32 + 3, r30.u8);
	// stb r30,4(r6)
	PPC_STORE_U8(ctx.r6.u32 + 4, r30.u8);
	// stb r30,5(r6)
	PPC_STORE_U8(ctx.r6.u32 + 5, r30.u8);
	// stb r30,6(r6)
	PPC_STORE_U8(ctx.r6.u32 + 6, r30.u8);
	// stb r30,7(r6)
	PPC_STORE_U8(ctx.r6.u32 + 7, r30.u8);
	// stb r30,8(r6)
	PPC_STORE_U8(ctx.r6.u32 + 8, r30.u8);
	// stb r30,9(r6)
	PPC_STORE_U8(ctx.r6.u32 + 9, r30.u8);
	// stb r30,10(r6)
	PPC_STORE_U8(ctx.r6.u32 + 10, r30.u8);
	// stb r30,11(r6)
	PPC_STORE_U8(ctx.r6.u32 + 11, r30.u8);
	// stb r30,12(r6)
	PPC_STORE_U8(ctx.r6.u32 + 12, r30.u8);
	// stb r30,13(r6)
	PPC_STORE_U8(ctx.r6.u32 + 13, r30.u8);
	// stb r30,14(r6)
	PPC_STORE_U8(ctx.r6.u32 + 14, r30.u8);
	// stb r30,15(r6)
	PPC_STORE_U8(ctx.r6.u32 + 15, r30.u8);
	// stw r4,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r4.u32);
	// bl 0x82761678
	ctx.lr = 0x826D9034;
	sub_82761678(ctx, base);
	// addis r11,r31,6
	r11.s64 = r31.s64 + 393216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r11,r11,17392
	r11.s64 = r11.s64 + 17392;
	// addi r9,r10,4424
	ctx.r9.s64 = ctx.r10.s64 + 4424;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r3,r3,17408
	ctx.r3.s64 = ctx.r3.s64 + 17408;
	// stw r30,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r30.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bl 0x8224c408
	ctx.lr = 0x826D9058;
	sub_8224C408(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// li r10,28
	ctx.r10.s64 = 28;
	// lis r5,-32111
	ctx.r5.s64 = -2104426496;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// ori r9,r8,17092
	ctx.r9.u64 = ctx.r8.u64 | 17092;
	// addi r5,r5,-27096
	ctx.r5.s64 = ctx.r5.s64 + -27096;
	// ori r8,r7,16952
	ctx.r8.u64 = ctx.r7.u64 | 16952;
	// lfs f0,32668(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32668);
	f0.f64 = double(temp.f32);
	// lis r4,6
	ctx.r4.s64 = 393216;
	// lfs f13,27632(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27632);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,6
	ctx.r3.s64 = 393216;
	// ori r4,r4,17101
	ctx.r4.u64 = ctx.r4.u64 | 17101;
	// stwx r5,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r5.u32);
	// ori r3,r3,17102
	ctx.r3.u64 = ctx.r3.u64 | 17102;
	// stbx r30,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r30.u8);
	// lis r7,6
	ctx.r7.s64 = 393216;
	// stfsx f31,r31,r8
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// lis r28,6
	r28.s64 = 393216;
	// lis r27,6
	r27.s64 = 393216;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// ori r7,r7,16956
	ctx.r7.u64 = ctx.r7.u64 | 16956;
	// ori r28,r28,16968
	r28.u64 = r28.u64 | 16968;
	// ori r27,r27,16972
	r27.u64 = r27.u64 | 16972;
	// lis r4,6
	ctx.r4.s64 = 393216;
	// addi r26,r26,-28388
	r26.s64 = r26.s64 + -28388;
	// lis r3,6
	ctx.r3.s64 = 393216;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
	// ori r4,r4,17105
	ctx.r4.u64 = ctx.r4.u64 | 17105;
	// stfsx f0,r31,r28
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r28.u32, temp.u32);
	// ori r3,r3,17106
	ctx.r3.u64 = ctx.r3.u64 | 17106;
	// stfsx f13,r31,r27
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + r27.u32, temp.u32);
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lwz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lis r7,6
	ctx.r7.s64 = 393216;
	// lis r5,6
	ctx.r5.s64 = 393216;
	// lis r28,6
	r28.s64 = 393216;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// lis r27,6
	r27.s64 = 393216;
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// lis r26,6
	r26.s64 = 393216;
	// ori r8,r8,17107
	ctx.r8.u64 = ctx.r8.u64 | 17107;
	// ori r7,r7,17110
	ctx.r7.u64 = ctx.r7.u64 | 17110;
	// ori r5,r5,16949
	ctx.r5.u64 = ctx.r5.u64 | 16949;
	// ori r28,r28,16948
	r28.u64 = r28.u64 | 16948;
	// ori r4,r27,16979
	ctx.r4.u64 = r27.u64 | 16979;
	// ori r3,r26,16978
	ctx.r3.u64 = r26.u64 | 16978;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// lis r25,6
	r25.s64 = 393216;
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// lis r24,6
	r24.s64 = 393216;
	// stbx r30,r31,r28
	PPC_STORE_U8(r31.u32 + r28.u32, r30.u8);
	// lis r23,6
	r23.s64 = 393216;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// lis r22,6
	r22.s64 = 393216;
	// stbx r30,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r30.u8);
	// lis r21,6
	r21.s64 = 393216;
	// lis r20,-32115
	r20.s64 = -2104688640;
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// ori r25,r25,17104
	r25.u64 = r25.u64 | 17104;
	// ori r8,r24,16977
	ctx.r8.u64 = r24.u64 | 16977;
	// ori r7,r23,16976
	ctx.r7.u64 = r23.u64 | 16976;
	// ori r5,r22,17108
	ctx.r5.u64 = r22.u64 | 17108;
	// ori r28,r21,17109
	r28.u64 = r21.u64 | 17109;
	// addi r3,r20,-13412
	ctx.r3.s64 = r20.s64 + -13412;
	// xori r9,r4,1
	ctx.r9.u64 = ctx.r4.u64 ^ 1;
	// stbx r30,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, r30.u8);
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// stbx r9,r31,r25
	PPC_STORE_U8(r31.u32 + r25.u32, ctx.r9.u8);
	// stbx r30,r31,r28
	PPC_STORE_U8(r31.u32 + r28.u32, r30.u8);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826d91b4
	if (!cr6.eq) goto loc_826D91B4;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r8,r9,-6188
	ctx.r8.s64 = ctx.r9.s64 + -6188;
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// beq cr6,0x826d91b8
	if (cr6.eq) goto loc_826D91B8;
loc_826D91B4:
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
loc_826D91B8:
	// lis r8,6
	ctx.r8.s64 = 393216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// ori r5,r8,16984
	ctx.r5.u64 = ctx.r8.u64 | 16984;
	// addi r4,r7,-5900
	ctx.r4.s64 = ctx.r7.s64 + -5900;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lis r7,6
	ctx.r7.s64 = 393216;
	// lis r18,-32111
	r18.s64 = -2104426496;
	// stbx r9,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, ctx.r9.u8);
	// lis r17,-32111
	r17.s64 = -2104426496;
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cntlzw r4,r9
	ctx.r4.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// lis r5,6
	ctx.r5.s64 = 393216;
	// stb r9,-27140(r8)
	PPC_STORE_U8(ctx.r8.u32 + -27140, ctx.r9.u8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r3,6
	ctx.r3.s64 = 393216;
	// lis r28,6
	r28.s64 = 393216;
	// lis r27,6
	r27.s64 = 393216;
	// lis r26,6
	r26.s64 = 393216;
	// lfs f12,27640(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// lis r25,6
	r25.s64 = 393216;
	// lfs f13,11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// lis r24,6
	r24.s64 = 393216;
	// lis r23,6
	r23.s64 = 393216;
	// lis r22,6
	r22.s64 = 393216;
	// lis r21,6
	r21.s64 = 393216;
	// lis r20,6
	r20.s64 = 393216;
	// lis r19,6
	r19.s64 = 393216;
	// ori r15,r7,16985
	r15.u64 = ctx.r7.u64 | 16985;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lis r16,-32111
	r16.s64 = -2104426496;
	// stb r8,-27138(r18)
	PPC_STORE_U8(r18.u32 + -27138, ctx.r8.u8);
	// ori r3,r3,16987
	ctx.r3.u64 = ctx.r3.u64 | 16987;
	// stb r7,-27139(r17)
	PPC_STORE_U8(r17.u32 + -27139, ctx.r7.u8);
	// ori r5,r5,16986
	ctx.r5.u64 = ctx.r5.u64 | 16986;
	// ori r28,r28,16980
	r28.u64 = r28.u64 | 16980;
	// ori r27,r27,17112
	r27.u64 = r27.u64 | 17112;
	// ori r26,r26,17116
	r26.u64 = r26.u64 | 17116;
	// ori r25,r25,17120
	r25.u64 = r25.u64 | 17120;
	// ori r24,r24,17098
	r24.u64 = r24.u64 | 17098;
	// ori r23,r23,17100
	r23.u64 = r23.u64 | 17100;
	// ori r22,r22,17099
	r22.u64 = r22.u64 | 17099;
	// ori r21,r21,17536
	r21.u64 = r21.u64 | 17536;
	// ori r20,r20,17136
	r20.u64 = r20.u64 | 17136;
	// ori r19,r19,17540
	r19.u64 = r19.u64 | 17540;
	// rlwinm r4,r4,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// xori r8,r4,1
	ctx.r8.u64 = ctx.r4.u64 ^ 1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stb r9,-27137(r16)
	PPC_STORE_U8(r16.u32 + -27137, ctx.r9.u8);
	// stbx r29,r31,r3
	PPC_STORE_U8(r31.u32 + ctx.r3.u32, r29.u8);
	// stfsx f13,r31,r27
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + r27.u32, temp.u32);
	// stfsx f0,r31,r26
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + r26.u32, temp.u32);
	// stbx r8,r31,r15
	PPC_STORE_U8(r31.u32 + r15.u32, ctx.r8.u8);
	// stfsx f12,r31,r25
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + r25.u32, temp.u32);
	// stbx r8,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, ctx.r8.u8);
	// stvx128 v63,r31,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwx r30,r31,r28
	PPC_STORE_U32(r31.u32 + r28.u32, r30.u32);
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,17(r31)
	PPC_STORE_U8(r31.u32 + 17, r30.u8);
	// stbx r30,r31,r24
	PPC_STORE_U8(r31.u32 + r24.u32, r30.u8);
	// stbx r30,r31,r23
	PPC_STORE_U8(r31.u32 + r23.u32, r30.u8);
	// stbx r30,r31,r22
	PPC_STORE_U8(r31.u32 + r22.u32, r30.u8);
	// stwx r7,r31,r21
	PPC_STORE_U32(r31.u32 + r21.u32, ctx.r7.u32);
	// stbx r30,r31,r19
	PPC_STORE_U8(r31.u32 + r19.u32, r30.u8);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stwx r6,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r6.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-152(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x823d9214
	return;
}

PPC_WEAK_FUNC(sub_826D8E70) {
	__imp__sub_826D8E70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D92E8) {
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
	ctx.lr = 0x826D92F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,6
	r11.s64 = 393216;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// addis r30,r31,6
	r30.s64 = r31.s64 + 393216;
	// ori r8,r11,17504
	ctx.r8.u64 = r11.u64 | 17504;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// ori r6,r10,17392
	ctx.r6.u64 = ctx.r10.u64 | 17392;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r30,r30,17168
	r30.s64 = r30.s64 + 17168;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// addi r3,r9,5588
	ctx.r3.s64 = ctx.r9.s64 + 5588;
	// addi r11,r7,-18952
	r11.s64 = ctx.r7.s64 + -18952;
	// addi r10,r5,-30128
	ctx.r10.s64 = ctx.r5.s64 + -30128;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r9,r4,3832
	ctx.r9.s64 = ctx.r4.s64 + 3832;
	// stwx r11,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r11.u32);
	// stwx r10,r31,r6
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, ctx.r10.u32);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// bl 0x82761428
	ctx.lr = 0x826D9348;
	sub_82761428(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addis r3,r31,6
	ctx.r3.s64 = r31.s64 + 393216;
	// addi r7,r8,3816
	ctx.r7.s64 = ctx.r8.s64 + 3816;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x826D9360;
	sub_82130000(ctx, base);
	// lis r6,6
	ctx.r6.s64 = 393216;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ori r29,r6,16704
	r29.u64 = ctx.r6.u64 | 16704;
	// addi r4,r5,-17868
	ctx.r4.s64 = ctx.r5.s64 + -17868;
	// add r30,r31,r29
	r30.u64 = r31.u64 + r29.u64;
	// addi r3,r30,156
	ctx.r3.s64 = r30.s64 + 156;
	// stwx r4,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r4.u32);
	// lhz r5,162(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 162);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826d9390
	if (cr6.eq) goto loc_826D9390;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8224a9c0
	ctx.lr = 0x826D9390;
	sub_8224A9C0(ctx, base);
loc_826D9390:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x826D9398;
	sub_821D2028(ctx, base);
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r29,30
	r29.s64 = 30;
	// add r30,r31,r11
	r30.u64 = r31.u64 + r11.u64;
loc_826D93A4:
	// addi r30,r30,-5936
	r30.s64 = r30.s64 + -5936;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826f5f78
	ctx.lr = 0x826D93B0;
	sub_826F5F78(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x826d93a4
	if (!cr0.lt) goto loc_826D93A4;
	// addi r3,r31,8800
	ctx.r3.s64 = r31.s64 + 8800;
	// bl 0x826ed4d0
	ctx.lr = 0x826D93C0;
	sub_826ED4D0(ctx, base);
	// addi r3,r31,8536
	ctx.r3.s64 = r31.s64 + 8536;
	// bl 0x826d4990
	ctx.lr = 0x826D93C8;
	sub_826D4990(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826d93dc
	if (cr6.eq) goto loc_826D93DC;
	// bl 0x82130588
	ctx.lr = 0x826D93DC;
	sub_82130588(ctx, base);
loc_826D93DC:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// bl 0x821d2028
	ctx.lr = 0x826D93F0;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D92E8) {
	__imp__sub_826D92E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D93F8) {
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
	// bl 0x826d92e8
	ctx.lr = 0x826D9418;
	sub_826D92E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d9430
	if (cr6.eq) goto loc_826D9430;
	// bl 0x82130588
	ctx.lr = 0x826D942C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826D9430:
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

PPC_WEAK_FUNC(sub_826D93F8) {
	__imp__sub_826D93F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x826D9450;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r23,1
	r23.s64 = 1;
	// addis r31,r27,6
	r31.s64 = r27.s64 + 393216;
	// li r25,64
	r25.s64 = 64;
	// addi r31,r31,16992
	r31.s64 = r31.s64 + 16992;
	// li r26,48
	r26.s64 = 48;
	// addi r24,r31,8
	r24.s64 = r31.s64 + 8;
loc_826D9470:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c90c0
	ctx.lr = 0x826D9478;
	sub_821C90C0(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r29,r24
	r29.u64 = r24.u64;
	// li r28,4
	r28.s64 = 4;
loc_826D9484:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9078
	ctx.lr = 0x826D948C;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d9508
	if (cr6.eq) goto loc_826D9508;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bgt cr6,0x826d9500
	if (cr6.gt) goto loc_826D9500;
	// lis r12,-32146
	r12.s64 = -2106720256;
	// addi r12,r12,-27464
	r12.s64 = r12.s64 + -27464;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-27448(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -27448);
	// lwz r19,-27412(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -27412);
	// lwz r19,-27440(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -27440);
	// lwz r19,-27428(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -27428);
	// li r23,0
	r23.s64 = 0;
	// b 0x826d9500
	goto loc_826D9500;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826d8b48
	ctx.lr = 0x826D94D8;
	sub_826D8B48(ctx, base);
	// b 0x826d9500
	goto loc_826D9500;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826d56f0
	ctx.lr = 0x826D94E8;
	sub_826D56F0(ctx, base);
	// b 0x826d9500
	goto loc_826D9500;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lvx128 v2,r31,r25
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r31,r26
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826d75d8
	ctx.lr = 0x826D9500;
	sub_826D75D8(ctx, base);
loc_826D9500:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821c9108
	ctx.lr = 0x826D9508;
	sub_821C9108(ctx, base);
loc_826D9508:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// bne 0x826d9484
	if (!cr0.eq) goto loc_826D9484;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d9470
	if (!cr6.eq) goto loc_826D9470;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_826D9448) {
	__imp__sub_826D9448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D952C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D952C) {
	__imp__sub_826D952C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9530) {
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
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r11,84(r31)
	PPC_STORE_U8(r31.u32 + 84, r11.u8);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x821c9108
	ctx.lr = 0x826D9554;
	sub_821C9108(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c9108
	ctx.lr = 0x826D955C;
	sub_821C9108(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x821c90c0
	ctx.lr = 0x826D9564;
	sub_821C90C0(ctx, base);
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

PPC_WEAK_FUNC(sub_826D9530) {
	__imp__sub_826D9530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9578) {
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
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9108
	ctx.lr = 0x826D9594;
	sub_821C9108(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c9108
	ctx.lr = 0x826D959C;
	sub_821C9108(ctx, base);
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

PPC_WEAK_FUNC(sub_826D9578) {
	__imp__sub_826D9578(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D95B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// b 0x821c90c0
	sub_821C90C0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826D95B0) {
	__imp__sub_826D95B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D95B8) {
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
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c9108
	ctx.lr = 0x826D95D4;
	sub_821C9108(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c9108
	ctx.lr = 0x826D95DC;
	sub_821C9108(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x821c90c0
	ctx.lr = 0x826D95E4;
	sub_821C90C0(ctx, base);
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

PPC_WEAK_FUNC(sub_826D95B8) {
	__imp__sub_826D95B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D95F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r10,0
	ctx.r10.s64 = 0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// lbz r8,84(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 84);
	// addi r7,r9,-31600
	ctx.r7.s64 = ctx.r9.s64 + -31600;
	// clrlwi r6,r8,28
	ctx.r6.u64 = ctx.r8.u32 & 0xF;
	// li r5,-1
	ctx.r5.s64 = -1;
	// stb r6,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, ctx.r6.u8);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r5.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r10.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D95F8) {
	__imp__sub_826D95F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9638) {
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
	ctx.lr = 0x826D9640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,5
	r30.s64 = 5;
loc_826D9650:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// bl 0x821c9060
	ctx.lr = 0x826D966C;
	sub_821C9060(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x826D9678;
	sub_821C9060(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r3.u32);
	// bne 0x826d9650
	if (!cr0.eq) goto loc_826D9650;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32146
	ctx.r10.s64 = -2106720256;
	// addi r7,r11,5932
	ctx.r7.s64 = r11.s64 + 5932;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r10,-27576
	ctx.r3.s64 = ctx.r10.s64 + -27576;
	// bl 0x821c9308
	ctx.lr = 0x826D96AC;
	sub_821C9308(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826D9638) {
	__imp__sub_826D9638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D96B8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826D96C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x821c9108
	ctx.lr = 0x826D96D0;
	sub_821C9108(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9108
	ctx.lr = 0x826D96D8;
	sub_821C9108(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x821c90c0
	ctx.lr = 0x826D96E0;
	sub_821C90C0(ctx, base);
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x821c9168
	ctx.lr = 0x826D96E8;
	sub_821C9168(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// mr r31,r30
	r31.u64 = r30.u64;
	// stw r11,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r11.u32);
	// li r29,5
	r29.s64 = 5;
loc_826D96F8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c9158
	ctx.lr = 0x826D9700;
	sub_821C9158(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821c9158
	ctx.lr = 0x826D9708;
	sub_821C9158(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x826d96f8
	if (!cr0.eq) goto loc_826D96F8;
	// li r11,0
	r11.s64 = 0;
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826D96B8) {
	__imp__sub_826D96B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D9724) {
	__imp__sub_826D9724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r3,r11,208
	ctx.r3.s64 = r11.s64 + 208;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9728) {
	__imp__sub_826D9728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D9734) {
	__imp__sub_826D9734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f1,492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 492);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9738) {
	__imp__sub_826D9738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D9744) {
	__imp__sub_826D9744(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9748) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d977c
	if (cr6.eq) goto loc_826D977C;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d977c
	if (cr6.eq) goto loc_826D977C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d977c
	if (cr6.eq) goto loc_826D977C;
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// blr 
	return;
loc_826D977C:
	// addi r3,r10,112
	ctx.r3.s64 = ctx.r10.s64 + 112;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9748) {
	__imp__sub_826D9748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D9784) {
	__imp__sub_826D9784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9788) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9788) {
	__imp__sub_826D9788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D97A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826d97d8
	if (cr6.eq) goto loc_826D97D8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r11,r9,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_826D97D8:
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d980c
	if (cr6.eq) goto loc_826D980C;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d980c
	if (cr6.eq) goto loc_826D980C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d980c
	if (cr6.eq) goto loc_826D980C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
loc_826D980C:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D97A8) {
	__imp__sub_826D97A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d9858
	if (cr6.eq) goto loc_826D9858;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d9858
	if (cr6.eq) goto loc_826D9858;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826d9858
	if (cr6.eq) goto loc_826D9858;
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x826d985c
	goto loc_826D985C;
loc_826D9858:
	// addi r10,r11,112
	ctx.r10.s64 = r11.s64 + 112;
loc_826D985C:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826d98cc
	if (cr6.eq) goto loc_826D98CC;
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d9898
	if (cr6.eq) goto loc_826D9898;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d9898
	if (cr6.eq) goto loc_826D9898;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826d9898
	if (cr6.eq) goto loc_826D9898;
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x826d989c
	goto loc_826D989C;
loc_826D9898:
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
loc_826D989C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lvx128 v63,r7,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// b 0x826d98dc
	goto loc_826D98DC;
loc_826D98CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfs f13,-31376(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31376);
	ctx.f13.f64 = double(temp.f32);
loc_826D98DC:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f13,4(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D98F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9818) {
	__imp__sub_826D9818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826D9904) {
	__imp__sub_826D9904(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D9908) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d993c
	if (cr6.eq) goto loc_826D993C;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d993c
	if (cr6.eq) goto loc_826D993C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d993c
	if (cr6.eq) goto loc_826D993C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826d9940
	goto loc_826D9940;
loc_826D993C:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
loc_826D9940:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d99ac
	if (cr6.eq) goto loc_826D99AC;
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d997c
	if (cr6.eq) goto loc_826D997C;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d997c
	if (cr6.eq) goto loc_826D997C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826d997c
	if (cr6.eq) goto loc_826D997C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826d9980
	goto loc_826D9980;
loc_826D997C:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
loc_826D9980:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lwz r7,12(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lvx128 v63,r7,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-12(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826D99AC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826D9908) {
	__imp__sub_826D9908(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826D99B8) {
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
	// bl 0x823d91c0
	ctx.lr = 0x826D99C0;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// addi r31,r1,-656
	r31.s64 = ctx.r1.s64 + -656;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D99F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f0,-18988(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18988);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// fmadds f31,f0,f13,f1
	f31.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f1.f64));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826D9A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,48
	ctx.r6.s64 = 48;
	// addi r5,r31,304
	ctx.r5.s64 = r31.s64 + 304;
	// lvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r31,176
	ctx.r4.s64 = r31.s64 + 176;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,188(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// bl 0x82249210
	ctx.lr = 0x826D9A44;
	sub_82249210(ctx, base);
	// lwz r29,308(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 308);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// neg r10,r29
	ctx.r10.s64 = -r29.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826D9A58;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r8,r23
	ctx.r8.s64 = -r23.s64;
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r8,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r22,r1,80
	r22.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x826D9A70;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r16,0
	r16.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r17,r1,80
	r17.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x826d9aa8
	if (!cr6.gt) goto loc_826D9AA8;
	// mr r11,r22
	r11.u64 = r22.u64;
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826d9aa8
	if (cr6.eq) goto loc_826D9AA8;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_826D9A9C:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x826d9a9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826D9A9C;
loc_826D9AA8:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x826d9ad0
	if (!cr6.gt) goto loc_826D9AD0;
	// mr r11,r17
	r11.u64 = r17.u64;
	// mr r10,r16
	ctx.r10.u64 = r16.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x826d9ad0
	if (cr6.eq) goto loc_826D9AD0;
	// mtctr r23
	ctr.u64 = r23.u64;
loc_826D9AC4:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x826d9ac4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826D9AC4;
loc_826D9AD0:
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r19,r16
	r19.u64 = r16.u64;
	// ori r21,r10,64167
	r21.u64 = ctx.r10.u64 | 64167;
	// li r18,1
	r18.s64 = 1;
	// addi r20,r11,2192
	r20.s64 = r11.s64 + 2192;
loc_826D9AE8:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x826d9c98
	if (!cr6.gt) goto loc_826D9C98;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// twllei r29,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d9b44
	if (cr6.eq) goto loc_826D9B44;
	// lwz r8,384(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 384);
	// addi r10,r11,384
	ctx.r10.s64 = r11.s64 + 384;
	// lwz r9,388(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 388);
	// mulld r10,r8,r21
	ctx.r10.s64 = ctx.r8.s64 * r21.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r7,r10,1
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,384(r11)
	PPC_STORE_U32(r11.u32 + 384, ctx.r10.u32);
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r5,r7,r29
	ctx.r5.s32 = ctx.r7.s32 / r29.s32;
	// stw r3,388(r11)
	PPC_STORE_U32(r11.u32 + 388, ctx.r3.u32);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// mullw r9,r5,r29
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(r29.s32);
	// andc r10,r29,r4
	ctx.r10.u64 = r29.u64 & ~ctx.r4.u64;
	// subf r30,r9,r7
	r30.s64 = ctx.r7.s64 - ctx.r9.s64;
	// twlgei r10,-1
	// b 0x826d9b80
	goto loc_826D9B80;
loc_826D9B44:
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r11,4(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// mulld r10,r9,r21
	ctx.r10.s64 = ctx.r9.s64 * r21.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r6,r8,r29
	ctx.r6.s32 = ctx.r8.s32 / r29.s32;
	// stw r11,4(r20)
	PPC_STORE_U32(r20.u32 + 4, r11.u32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mullw r4,r6,r29
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(r29.s32);
	// andc r3,r29,r5
	ctx.r3.u64 = r29.u64 & ~ctx.r5.u64;
	// subf r30,r4,r8
	r30.s64 = ctx.r8.s64 - ctx.r4.s64;
	// twlgei r3,-1
loc_826D9B80:
	// lbzx r11,r30,r22
	r11.u64 = PPC_LOAD_U8(r30.u32 + r22.u32);
	// add r26,r30,r22
	r26.u64 = r30.u64 + r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d9c8c
	if (!cr6.eq) goto loc_826D9C8C;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// stb r18,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r18.u8);
	// mr r24,r16
	r24.u64 = r16.u64;
	// add r10,r30,r11
	ctx.r10.u64 = r30.u64 + r11.u64;
	// mr r11,r16
	r11.u64 = r16.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// add r25,r10,r27
	r25.u64 = ctx.r10.u64 + r27.u64;
	// lwz r28,36(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + 36);
	// ble cr6,0x826d9c4c
	if (!cr6.gt) goto loc_826D9C4C;
	// addi r10,r31,304
	ctx.r10.s64 = r31.s64 + 304;
loc_826D9BBC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// beq cr6,0x826d9bdc
	if (cr6.eq) goto loc_826D9BDC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// blt cr6,0x826d9bbc
	if (cr6.lt) goto loc_826D9BBC;
	// b 0x826d9c4c
	goto loc_826D9C4C;
loc_826D9BDC:
	// stbx r18,r11,r17
	PPC_STORE_U8(r11.u32 + r17.u32, r18.u8);
	// mr r24,r18
	r24.u64 = r18.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r31,176
	ctx.r5.s64 = r31.s64 + 176;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9C00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,300(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826d9c18
	if (cr6.eq) goto loc_826D9C18;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 40, temp.u32);
	// b 0x826d9c4c
	goto loc_826D9C4C;
loc_826D9C18:
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// add r10,r30,r22
	ctx.r10.u64 = r30.u64 + r22.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823db5b0
	ctx.lr = 0x826D9C30;
	sub_823DB5B0(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9C48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,308(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 308);
loc_826D9C4C:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d9c8c
	if (!cr6.eq) goto loc_826D9C8C;
	// subf r11,r30,r29
	r11.s64 = r29.s64 - r30.s64;
	// add r10,r30,r22
	ctx.r10.u64 = r30.u64 + r22.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823db5b0
	ctx.lr = 0x826D9C70;
	sub_823DB5B0(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9C88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,308(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 308);
loc_826D9C8C:
	// addi r19,r19,1
	r19.s64 = r19.s64 + 1;
	// cmpwi cr6,r19,1
	cr6.compare<int32_t>(r19.s32, 1, xer);
	// blt cr6,0x826d9ae8
	if (cr6.lt) goto loc_826D9AE8;
loc_826D9C98:
	// mr r24,r16
	r24.u64 = r16.u64;
loc_826D9C9C:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x826d9e48
	if (!cr6.gt) goto loc_826D9E48;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// twllei r23,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826d9cf8
	if (cr6.eq) goto loc_826D9CF8;
	// lwz r8,384(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 384);
	// addi r10,r11,384
	ctx.r10.s64 = r11.s64 + 384;
	// lwz r9,388(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 388);
	// mulld r10,r8,r21
	ctx.r10.s64 = ctx.r8.s64 * r21.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r7,r10,1
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,384(r11)
	PPC_STORE_U32(r11.u32 + 384, ctx.r10.u32);
	// rldicl r3,r10,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r5,r7,r23
	ctx.r5.s32 = ctx.r7.s32 / r23.s32;
	// stw r3,388(r11)
	PPC_STORE_U32(r11.u32 + 388, ctx.r3.u32);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// mullw r9,r5,r23
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(r23.s32);
	// andc r10,r23,r4
	ctx.r10.u64 = r23.u64 & ~ctx.r4.u64;
	// subf r30,r9,r7
	r30.s64 = ctx.r7.s64 - ctx.r9.s64;
	// twlgei r10,-1
	// b 0x826d9d34
	goto loc_826D9D34;
loc_826D9CF8:
	// lwz r9,0(r20)
	ctx.r9.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lwz r11,4(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// mulld r10,r9,r21
	ctx.r10.s64 = ctx.r9.s64 * r21.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r6,r8,r23
	ctx.r6.s32 = ctx.r8.s32 / r23.s32;
	// stw r11,4(r20)
	PPC_STORE_U32(r20.u32 + 4, r11.u32);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// mullw r4,r6,r23
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(r23.s32);
	// andc r3,r23,r5
	ctx.r3.u64 = r23.u64 & ~ctx.r5.u64;
	// subf r30,r4,r8
	r30.s64 = ctx.r8.s64 - ctx.r4.s64;
	// twlgei r3,-1
loc_826D9D34:
	// lbzx r11,r30,r17
	r11.u64 = PPC_LOAD_U8(r30.u32 + r17.u32);
	// add r26,r30,r17
	r26.u64 = r30.u64 + r17.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d9e3c
	if (!cr6.eq) goto loc_826D9E3C;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r18,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r18.u8);
	// addi r10,r31,304
	ctx.r10.s64 = r31.s64 + 304;
	// addi r5,r31,176
	ctx.r5.s64 = r31.s64 + 176;
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// lwzx r28,r11,r10
	r28.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826D9D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r16
	r25.u64 = r16.u64;
	// mr r11,r16
	r11.u64 = r16.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x826d9e04
	if (!cr6.gt) goto loc_826D9E04;
	// addi r10,r27,36
	ctx.r10.s64 = r27.s64 + 36;
loc_826D9D84:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r28
	cr6.compare<uint32_t>(ctx.r9.u32, r28.u32, xer);
	// beq cr6,0x826d9da4
	if (cr6.eq) goto loc_826D9DA4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// blt cr6,0x826d9d84
	if (cr6.lt) goto loc_826D9D84;
	// b 0x826d9e04
	goto loc_826D9E04;
loc_826D9DA4:
	// lbz r9,236(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 236);
	// mr r25,r18
	r25.u64 = r18.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826d9dd0
	if (cr6.eq) goto loc_826D9DD0;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f0,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	f0.f64 = double(temp.f32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// stfs f0,40(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 40, temp.u32);
	// b 0x826d9e04
	goto loc_826D9E04;
loc_826D9DD0:
	// subf r10,r30,r23
	ctx.r10.s64 = r23.s64 - r30.s64;
	// add r11,r30,r17
	r11.u64 = r30.u64 + r17.u64;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823db5b0
	ctx.lr = 0x826D9DE8;
	sub_823DB5B0(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9E00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,308(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 308);
loc_826D9E04:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826d9e3c
	if (!cr6.eq) goto loc_826D9E3C;
	// lbz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 236);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826d9e3c
	if (cr6.eq) goto loc_826D9E3C;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lfs f1,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r29,308(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 308);
loc_826D9E3C:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// blt cr6,0x826d9c9c
	if (cr6.lt) goto loc_826D9C9C;
loc_826D9E48:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r8,r31,80
	ctx.r8.s64 = r31.s64 + 80;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// addi r7,r31,96
	ctx.r7.s64 = r31.s64 + 96;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// addi r5,r31,144
	ctx.r5.s64 = r31.s64 + 144;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r3,r15,24
	ctx.r3.u64 = r15.u32 & 0xFF;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r16,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r16.u32);
	// lfs f0,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r16,172(r31)
	PPC_STORE_U8(r31.u32 + 172, r16.u8);
	// lfs f13,-31400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	ctx.f13.f64 = double(temp.f32);
	// stw r16,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r16.u32);
	// stfs f0,168(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stb r16,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r16.u8);
	// stfs f13,164(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// beq cr6,0x826da00c
	if (cr6.eq) goto loc_826DA00C;
	// lwz r11,308(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 308);
	// mr r24,r16
	r24.u64 = r16.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826da00c
	if (!cr6.gt) goto loc_826DA00C;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r25,r27,40
	r25.s64 = r27.s64 + 40;
	// addi r30,r8,-31664
	r30.s64 = ctx.r8.s64 + -31664;
	// addi r29,r9,-31648
	r29.s64 = ctx.r9.s64 + -31648;
	// addi r28,r10,2240
	r28.s64 = ctx.r10.s64 + 2240;
	// addi r26,r11,2528
	r26.s64 = r11.s64 + 2528;
loc_826D9EE4:
	// lfs f1,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,-4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + -4);
	// stfs f1,120(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// stw r4,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r4.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826D9F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r7,r31,80
	ctx.r7.s64 = r31.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826D9F30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f12,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f8,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// lfs f6,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f11,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 - ctx.f6.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f0,f5,f5,f3
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826d9ff8
	if (!cr6.lt) goto loc_826D9FF8;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,80
	ctx.r9.s64 = r31.s64 + 80;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// addi r8,r31,128
	ctx.r8.s64 = r31.s64 + 128;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r31,96
	ctx.r7.s64 = r31.s64 + 96;
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// vmsum3fp128 v60,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stw r10,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r10.u32);
	// vrsqrtefp128 v58,v60
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 124);
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// stb r5,172(r31)
	PPC_STORE_U8(r31.u32 + 172, ctx.r5.u8);
	// vcmpeqfp128 v11,v58,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// stfs f0,168(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f13,164(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v63,v6
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826D9FF8:
	// lwz r11,308(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 308);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,24
	r25.s64 = r25.s64 + 24;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826d9ee4
	if (cr6.lt) goto loc_826D9EE4;
loc_826DA00C:
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r9,r31,144
	ctx.r9.s64 = r31.s64 + 144;
	// lbz r8,172(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 172);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	f0.f64 = double(temp.f32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r14,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,32(r14)
	PPC_STORE_U32(r14.u32 + 32, ctx.r10.u32);
	// stfs f13,36(r14)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r14.u32 + 36, temp.u32);
	// stb r8,44(r14)
	PPC_STORE_U8(r14.u32 + 44, ctx.r8.u8);
	// stfs f0,40(r14)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r14.u32 + 40, temp.u32);
	// addi r1,r31,656
	ctx.r1.s64 = r31.s64 + 656;
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_826D99B8) {
	__imp__sub_826D99B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA054) {
	__imp__sub_826DA054(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA058) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,308(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 308);
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r9,r10,20
	ctx.r9.s64 = ctx.r10.s64 + 20;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// stw r7,308(r10)
	PPC_STORE_U32(ctx.r10.u32 + 308, ctx.r7.u32);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
	// stfs f1,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// b 0x8273e160
	sub_8273E160(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA058) {
	__imp__sub_826DA058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA0A0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA0A0) {
	__imp__sub_826DA0A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA0A4) {
	__imp__sub_826DA0A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA0A8) {
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
	ctx.lr = 0x826DA0B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r10,308(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826da1a0
	if (!cr6.gt) goto loc_826DA1A0;
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
loc_826DA0D0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// beq cr6,0x826da0f4
	if (cr6.eq) goto loc_826DA0F4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826da0d0
	if (cr6.lt) goto loc_826DA0D0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826DA0F4:
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// li r28,0
	r28.s64 = 0;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x826da128
	if (cr6.eq) goto loc_826DA128;
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,-4
	ctx.r4.s64 = r11.s64 + -4;
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8273e1a8
	ctx.lr = 0x826DA128;
	sub_8273E1A8(ctx, base);
loc_826DA128:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r30,r11,3,0,28
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// addi r29,r11,20
	r29.s64 = r11.s64 + 20;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8273e1a8
	ctx.lr = 0x826DA148;
	sub_8273E1A8(ctx, base);
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// addi r10,r31,20
	ctx.r10.s64 = r31.s64 + 20;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// add r7,r30,r10
	ctx.r7.u64 = r30.u64 + ctx.r10.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,308(r31)
	PPC_STORE_U32(r31.u32 + 308, r11.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826DA174:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r10,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r10.u32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bdnz 0x826da174
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826DA174;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826da1a0
	if (cr6.eq) goto loc_826DA1A0;
	// stw r29,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r29.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8273e160
	ctx.lr = 0x826DA1A0;
	sub_8273E160(ctx, base);
loc_826DA1A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DA0A8) {
	__imp__sub_826DA0A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA1A8) {
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
	// lwz r11,308(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826da1ec
	if (!cr6.gt) goto loc_826DA1EC;
loc_826DA1C8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DA1E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,308(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 308);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x826da1c8
	if (cr6.gt) goto loc_826DA1C8;
loc_826DA1EC:
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

PPC_WEAK_FUNC(sub_826DA1A8) {
	__imp__sub_826DA1A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24788(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24788);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA200) {
	__imp__sub_826DA200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA20C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA20C) {
	__imp__sub_826DA20C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA210) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,6944
	ctx.r9.s64 = r11.s64 + 6944;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826da244
	if (cr6.eq) goto loc_826DA244;
	// bl 0x82130588
	ctx.lr = 0x826DA240;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DA244:
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

PPC_WEAK_FUNC(sub_826DA210) {
	__imp__sub_826DA210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// li r11,2
	r11.s64 = 2;
loc_826DA260:
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// bne 0x826da260
	if (!cr0.eq) goto loc_826DA260;
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA258) {
	__imp__sub_826DA258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// li r11,2
	r11.s64 = 2;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826DA284:
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// bne 0x826da284
	if (!cr0.eq) goto loc_826DA284;
	// addi r3,r3,96
	ctx.r3.s64 = ctx.r3.s64 + 96;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA278) {
	__imp__sub_826DA278(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA29C) {
	__imp__sub_826DA29C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA2A0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DA2A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826da2e4
	if (!cr6.gt) goto loc_826DA2E4;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_826DA2C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DA2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,12
	r31.s64 = r31.s64 + 12;
	// bne 0x826da2c0
	if (!cr0.eq) goto loc_826DA2C0;
loc_826DA2E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826DA2EC;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DA2A0) {
	__imp__sub_826DA2A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA2F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA2F4) {
	__imp__sub_826DA2F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA2F8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DA300;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826da33c
	if (!cr6.gt) goto loc_826DA33C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_826DA318:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DA330;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x826da318
	if (!cr0.eq) goto loc_826DA318;
loc_826DA33C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826DA344;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DA2F8) {
	__imp__sub_826DA2F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA34C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA34C) {
	__imp__sub_826DA34C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA350) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826DA364;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826da3a0
	if (cr6.eq) goto loc_826DA3A0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,6944
	ctx.r8.s64 = ctx.r9.s64 + 6944;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826DA3A0:
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

PPC_WEAK_FUNC(sub_826DA350) {
	__imp__sub_826DA350(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA3B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA3B4) {
	__imp__sub_826DA3B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA3B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826DA3DC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826da420
	if (!cr6.gt) goto loc_826DA420;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r11,r3,6
	r11.s64 = ctx.r3.s64 + 6;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,6944
	ctx.r10.s64 = ctx.r10.s64 + 6944;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_826DA3FC:
	// addic. r8,r11,-6
	xer.ca = r11.u32 > 5;
	ctx.r8.s64 = r11.s64 + -6;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x826da414
	if (cr0.eq) goto loc_826DA414;
	// stfs f0,2(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 2, temp.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r9,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r9.u16);
	// sth r9,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r9.u16);
loc_826DA414:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x826da3fc
	if (!cr0.eq) goto loc_826DA3FC;
loc_826DA420:
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

PPC_WEAK_FUNC(sub_826DA3B8) {
	__imp__sub_826DA3B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA434) {
	__imp__sub_826DA434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826da478
	if (cr6.eq) goto loc_826DA478;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_826DA454:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, temp.u32);
	// lhz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x826da454
	if (cr6.lt) goto loc_826DA454;
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
loc_826DA478:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA438) {
	__imp__sub_826DA438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA488) {
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
	ctx.lr = 0x826DA490;
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
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826da4f4
	if (cr6.eq) goto loc_826DA4F4;
	// li r31,0
	r31.s64 = 0;
loc_826DA4B0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da4e0
	if (cr6.eq) goto loc_826DA4E0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r4,172(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826da4e0
	if (cr6.eq) goto loc_826DA4E0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823db730
	ctx.lr = 0x826DA4D8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826da500
	if (cr6.eq) goto loc_826DA500;
loc_826DA4E0:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826da4b0
	if (cr6.lt) goto loc_826DA4B0;
loc_826DA4F4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826DA500:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DA488) {
	__imp__sub_826DA488(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA50C) {
	__imp__sub_826DA50C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA510) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lhz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826da55c
	if (!cr6.gt) goto loc_826DA55C;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r6,6
	ctx.r10.s64 = ctx.r6.s64 + 6;
loc_826DA528:
	// lhz r11,0(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// lhz r8,-2(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826da53c
	if (!cr6.eq) goto loc_826DA53C;
	// li r11,2400
	r11.s64 = 2400;
loc_826DA53C:
	// cmpw cr6,r4,r8
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r8.s32, xer);
	// blt cr6,0x826da54c
	if (cr6.lt) goto loc_826DA54C;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// ble cr6,0x826da568
	if (!cr6.gt) goto loc_826DA568;
loc_826DA54C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// blt cr6,0x826da528
	if (cr6.lt) goto loc_826DA528;
loc_826DA55C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826DA568:
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// lfs f1,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA510) {
	__imp__sub_826DA510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA580) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x826da61c
	if (cr6.eq) goto loc_826DA61C;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r5,r7,2192
	ctx.r5.s64 = ctx.r7.s64 + 2192;
	// ori r4,r6,64167
	ctx.r4.u64 = ctx.r6.u64 | 64167;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r6,2192(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2192);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mulld r9,r6,r4
	ctx.r9.s64 = ctx.r6.s64 * ctx.r4.s64;
	// lfs f0,14348(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2192, r11.u32);
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// lfs f12,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fmuls f0,f8,f0
	f0.f64 = double(float(ctx.f8.f64 * f0.f64));
	// ble cr6,0x826da61c
	if (!cr6.gt) goto loc_826DA61C;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_826DA5FC:
	// lfs f12,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826da624
	if (cr6.lt) goto loc_826DA624;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x826da5fc
	if (cr6.lt) goto loc_826DA5FC;
loc_826DA61C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826DA624:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA580) {
	__imp__sub_826DA580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA634) {
	__imp__sub_826DA634(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA638) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x826DA640;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r30,12(r3)
	r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// rotlwi r11,r30,2
	r11.u64 = __builtin_rotateleft32(r30.u32, 2);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826DA65C;
	sub_823DBFF4(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// lfs f12,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// fmr f13,f12
	ctx.f13.f64 = ctx.f12.f64;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// blt cr6,0x826da7b4
	if (cr6.lt) goto loc_826DA7B4;
	// addi r11,r30,-4
	r11.s64 = r30.s64 + -4;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r26,8
	ctx.r8.s64 = r26.s64 + 8;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r27,r9,r10
	r27.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// subf r29,r9,r26
	r29.s64 = r26.s64 - ctx.r9.s64;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// subf r28,r26,r10
	r28.s64 = ctx.r10.s64 - r26.s64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
loc_826DA6B0:
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r25,116(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmpw cr6,r25,r4
	cr6.compare<int32_t>(r25.s32, ctx.r4.s32, xer);
	// beq cr6,0x826da6c8
	if (cr6.eq) goto loc_826DA6C8;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_826DA6C8:
	// lbz r10,113(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da6e4
	if (cr6.eq) goto loc_826DA6E4;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826da6e4
	if (!cr6.eq) goto loc_826DA6E4;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_826DA6E4:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stfs f0,-8(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8, temp.u32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfsx f0,r27,r11
	temp.u32 = PPC_LOAD_U32(r27.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lwz r25,116(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmpw cr6,r25,r4
	cr6.compare<int32_t>(r25.s32, ctx.r4.s32, xer);
	// beq cr6,0x826da704
	if (cr6.eq) goto loc_826DA704;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_826DA704:
	// lbz r10,113(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da720
	if (cr6.eq) goto loc_826DA720;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826da720
	if (!cr6.eq) goto loc_826DA720;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_826DA720:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stfsx f0,r29,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + r11.u32, temp.u32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfsx f0,r28,r8
	temp.u32 = PPC_LOAD_U32(r28.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// lwz r25,116(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmpw cr6,r25,r4
	cr6.compare<int32_t>(r25.s32, ctx.r4.s32, xer);
	// beq cr6,0x826da740
	if (cr6.eq) goto loc_826DA740;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_826DA740:
	// lbz r10,113(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da75c
	if (cr6.eq) goto loc_826DA75C;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826da75c
	if (!cr6.eq) goto loc_826DA75C;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_826DA75C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,12(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	f0.f64 = double(temp.f32);
	// lwz r25,116(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmpw cr6,r25,r4
	cr6.compare<int32_t>(r25.s32, ctx.r4.s32, xer);
	// beq cr6,0x826da77c
	if (cr6.eq) goto loc_826DA77C;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_826DA77C:
	// lbz r10,113(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da798
	if (cr6.eq) goto loc_826DA798;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826da798
	if (!cr6.eq) goto loc_826DA798;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_826DA798:
	// stfs f0,4(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bne 0x826da6b0
	if (!cr0.eq) goto loc_826DA6B0;
loc_826DA7B4:
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bge cr6,0x826da820
	if (!cr6.lt) goto loc_826DA820;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// subf r9,r9,r30
	ctx.r9.s64 = r30.s64 - ctx.r9.s64;
	// subf r7,r10,r26
	ctx.r7.s64 = r26.s64 - ctx.r10.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_826DA7D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lwz r6,116(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// cmpw cr6,r6,r4
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, xer);
	// beq cr6,0x826da7f0
	if (cr6.eq) goto loc_826DA7F0;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_826DA7F0:
	// lbz r10,113(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826da80c
	if (cr6.eq) goto loc_826DA80C;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826da80c
	if (!cr6.eq) goto loc_826DA80C;
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_826DA80C:
	// stfsx f0,r7,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826da7d8
	if (!cr0.eq) goto loc_826DA7D8;
loc_826DA820:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r7,2192(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r9,r7,r5
	ctx.r9.s64 = ctx.r7.s64 * ctx.r5.s64;
	// lfs f0,14348(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// std r4,80(r31)
	PPC_STORE_U64(r31.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r31)
	ctx.f11.u64 = PPC_LOAD_U64(r31.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stw r9,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, ctx.r9.u32);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fmuls f0,f8,f0
	f0.f64 = double(float(ctx.f8.f64 * f0.f64));
	// ble cr6,0x826da8a4
	if (!cr6.gt) goto loc_826DA8A4;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_826DA884:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x826da8b0
	if (cr6.lt) goto loc_826DA8B0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// blt cr6,0x826da884
	if (cr6.lt) goto loc_826DA884;
loc_826DA8A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
loc_826DA8B0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826DA638) {
	__imp__sub_826DA638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA8C4) {
	__imp__sub_826DA8C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// b 0x826da580
	sub_826DA580(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA8C8) {
	__imp__sub_826DA8C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,20
	ctx.r3.s64 = ctx.r3.s64 + 20;
	// b 0x826da638
	sub_826DA638(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA8D0) {
	__imp__sub_826DA8D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8D8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,68
	ctx.r3.s64 = ctx.r3.s64 + 68;
	// b 0x826da580
	sub_826DA580(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DA8D8) {
	__imp__sub_826DA8D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24784(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24784);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA8E0) {
	__imp__sub_826DA8E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA8EC) {
	__imp__sub_826DA8EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA8F0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,6956
	ctx.r10.s64 = r11.s64 + 6956;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,14(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826da930
	if (cr6.eq) goto loc_826DA930;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x826da2a0
	ctx.lr = 0x826DA930;
	sub_826DA2A0(ctx, base);
loc_826DA930:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x826DA938;
	sub_821D2AA0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826da950
	if (cr6.eq) goto loc_826DA950;
	// bl 0x82130588
	ctx.lr = 0x826DA94C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DA950:
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

PPC_WEAK_FUNC(sub_826DA8F0) {
	__imp__sub_826DA8F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24780(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DA968) {
	__imp__sub_826DA968(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DA974) {
	__imp__sub_826DA974(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA978) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,6968
	ctx.r10.s64 = r11.s64 + 6968;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,26(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 26);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826da9ac
	if (cr6.eq) goto loc_826DA9AC;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x826DA9AC;
	sub_82130588(ctx, base);
loc_826DA9AC:
	// lhz r5,18(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826da9c4
	if (cr6.eq) goto loc_826DA9C4;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x826da2a0
	ctx.lr = 0x826DA9C4;
	sub_826DA2A0(ctx, base);
loc_826DA9C4:
	// lhz r5,10(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826da9dc
	if (cr6.eq) goto loc_826DA9DC;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x826da2f8
	ctx.lr = 0x826DA9DC;
	sub_826DA2F8(ctx, base);
loc_826DA9DC:
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

PPC_WEAK_FUNC(sub_826DA978) {
	__imp__sub_826DA978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DA9F0) {
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
	// bl 0x826da978
	ctx.lr = 0x826DAA10;
	sub_826DA978(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826daa28
	if (cr6.eq) goto loc_826DAA28;
	// bl 0x82130588
	ctx.lr = 0x826DAA24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DAA28:
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

PPC_WEAK_FUNC(sub_826DA9F0) {
	__imp__sub_826DA9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DAA40) {
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
	ctx.lr = 0x826DAA48;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r11,-24780(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,2828(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// beq cr6,0x826daa88
	if (cr6.eq) goto loc_826DAA88;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DAA84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826DAA88:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r10,5276
	ctx.r5.s64 = ctx.r10.s64 + 5276;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c04b0
	ctx.lr = 0x826DAAA8;
	sub_821C04B0(ctx, base);
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
	// lhz r30,8(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826daac4
	if (cr6.eq) goto loc_826DAAC4;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826DAAC0;
	sub_82130528(ctx, base);
	// b 0x826daac8
	goto loc_826DAAC8;
loc_826DAAC4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DAAC8:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r26,0
	r26.s64 = 0;
	// sth r30,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r30.u16);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dab78
	if (cr6.eq) goto loc_826DAB78;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r27,0
	r27.s64 = 0;
	// addi r23,r11,6976
	r23.s64 = r11.s64 + 6976;
loc_826DAAEC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// add r11,r27,r11
	r11.u64 = r27.u64 + r11.u64;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826da488
	ctx.lr = 0x826DAB04;
	sub_826DA488(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x826dab4c
	if (!cr6.lt) goto loc_826DAB4C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826d6008
	ctx.lr = 0x826DAB1C;
	sub_826D6008(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x826dab40
	if (cr6.eq) goto loc_826DAB40;
	// li r4,16
	ctx.r4.s64 = 16;
	// lhz r30,4(r24)
	r30.u64 = PPC_LOAD_U16(r24.u32 + 4);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8262e420
	ctx.lr = 0x826DAB38;
	sub_8262E420(ctx, base);
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// b 0x826dab4c
	goto loc_826DAB4C;
loc_826DAB40:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x826DAB4C;
	sub_82130000(ctx, base);
loc_826DAB4C:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpw cr6,r26,r6
	cr6.compare<int32_t>(r26.s32, ctx.r6.s32, xer);
	// blt cr6,0x826daaec
	if (cr6.lt) goto loc_826DAAEC;
loc_826DAB78:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826DAA40) {
	__imp__sub_826DAA40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DAB80) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x826DAB88;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x826da438
	ctx.lr = 0x826DABA0;
	sub_826DA438(ctx, base);
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r22,4(r29)
	r22.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// beq cr6,0x826dac54
	if (cr6.eq) goto loc_826DAC54;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r22,4
	cr6.compare<int32_t>(r22.s32, 4, xer);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// blt cr6,0x826dac10
	if (cr6.lt) goto loc_826DAC10;
	// addi r10,r22,-4
	ctx.r10.s64 = r22.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_826DABD8:
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + r11.u64;
	// stfs f0,4(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,-4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -4, temp.u32);
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f0,r4,r9
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + ctx.r9.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x826dabd8
	if (!cr0.eq) goto loc_826DABD8;
loc_826DAC10:
	// cmpw cr6,r7,r22
	cr6.compare<int32_t>(ctx.r7.s32, r22.s32, xer);
	// bge cr6,0x826dac34
	if (!cr6.lt) goto loc_826DAC34;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r22
	r11.s64 = r22.s64 - ctx.r7.s64;
loc_826DAC20:
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826dac20
	if (!cr0.eq) goto loc_826DAC20;
loc_826DAC34:
	// extsw r11,r22
	r11.s64 = r22.s32;
	// std r11,80(r31)
	PPC_STORE_U64(r31.u32 + 80, r11.u64);
	// lfd f0,80(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,16(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 16, temp.u32);
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
loc_826DAC54:
	// neg r11,r22
	r11.s64 = -r22.s64;
	// rlwinm r12,r11,0,0,27
	r12.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826DAC60;
	sub_823DBFF4(ctx, base);
	// lwz r10,0(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// stwux r10,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r1.u32 = ea;
	// addi r24,r1,80
	r24.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x826dac94
	if (!cr6.gt) goto loc_826DAC94;
	// mr r11,r24
	r11.u64 = r24.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x826dac94
	if (cr6.eq) goto loc_826DAC94;
	// mtctr r22
	ctr.u64 = r22.u64;
loc_826DAC88:
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x826dac88
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826DAC88;
loc_826DAC94:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,20(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 20, temp.u32);
	// beq cr6,0x826dace8
	if (cr6.eq) goto loc_826DACE8;
loc_826DACB4:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dacd4
	if (cr6.eq) goto loc_826DACD4;
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x826da510
	ctx.lr = 0x826DACCC;
	sub_826DA510(ctx, base);
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x826dace4
	if (!cr6.lt) goto loc_826DACE4;
loc_826DACD4:
	// lwz r30,20(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826dacb4
	if (!cr6.eq) goto loc_826DACB4;
	// b 0x826dace8
	goto loc_826DACE8;
loc_826DACE4:
	// stfs f1,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 20, temp.u32);
loc_826DACE8:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826dad74
	if (cr6.eq) goto loc_826DAD74;
	// li r23,1
	r23.s64 = 1;
loc_826DACF8:
	// lwz r28,24(r5)
	r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// li r25,0
	r25.s64 = 0;
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dad68
	if (cr6.eq) goto loc_826DAD68;
	// li r27,0
	r27.s64 = 0;
	// li r26,0
	r26.s64 = 0;
loc_826DAD14:
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwzx r30,r11,r26
	r30.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x826dad50
	if (cr6.lt) goto loc_826DAD50;
	// lbzx r11,r30,r24
	r11.u64 = PPC_LOAD_U8(r30.u32 + r24.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dad50
	if (!cr6.eq) goto loc_826DAD50;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// stbx r23,r30,r24
	PPC_STORE_U8(r30.u32 + r24.u32, r23.u8);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x826da510
	ctx.lr = 0x826DAD44;
	sub_826DA510(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f1,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_826DAD50:
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x826dad14
	if (cr6.lt) goto loc_826DAD14;
loc_826DAD68:
	// lwz r5,20(r5)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826dacf8
	if (!cr6.eq) goto loc_826DACF8;
loc_826DAD74:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dae04
	if (cr6.eq) goto loc_826DAE04;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
loc_826DAD8C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826dada0
	if (!cr6.gt) goto loc_826DADA0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_826DADA0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826dad8c
	if (!cr0.eq) goto loc_826DAD8C;
	// cmpwi cr6,r9,10
	cr6.compare<int32_t>(ctx.r9.s32, 10, xer);
	// blt cr6,0x826dae04
	if (cr6.lt) goto loc_826DAE04;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	r11.s64 = 0;
loc_826DADBC:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x826dadf0
	if (!cr6.eq) goto loc_826DADF0;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lfsx f12,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x826dadf0
	if (!cr6.gt) goto loc_826DADF0;
	// lbz r9,112(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 112);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dadf0
	if (!cr6.eq) goto loc_826DADF0;
	// stfsx f0,r10,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_826DADF0:
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x826dadbc
	if (cr6.lt) goto loc_826DADBC;
loc_826DAE04:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-6040
	ctx.r10.s64 = r11.s64 + -6040;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dafb4
	if (cr6.eq) goto loc_826DAFB4;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r22,4
	cr6.compare<int32_t>(r22.s32, 4, xer);
	// blt cr6,0x826daf58
	if (cr6.lt) goto loc_826DAF58;
	// addi r11,r22,-4
	r11.s64 = r22.s64 + -4;
	// li r8,0
	ctx.r8.s64 = 0;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_826DAE38:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dae70
	if (cr6.eq) goto loc_826DAE70;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826dae64
	if (!cr6.eq) goto loc_826DAE64;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dae70
	if (cr6.eq) goto loc_826DAE70;
loc_826DAE64:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f13,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// b 0x826dae78
	goto loc_826DAE78;
loc_826DAE70:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
loc_826DAE78:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826daeb8
	if (cr6.eq) goto loc_826DAEB8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826daea8
	if (!cr6.eq) goto loc_826DAEA8;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826daeb8
	if (cr6.eq) goto loc_826DAEB8;
loc_826DAEA8:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// b 0x826daec4
	goto loc_826DAEC4;
loc_826DAEB8:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
loc_826DAEC4:
	// addi r9,r8,12
	ctx.r9.s64 = ctx.r8.s64 + 12;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r9,-4
	r11.s64 = ctx.r9.s64 + -4;
	// lwzx r5,r11,r10
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826daf04
	if (cr6.eq) goto loc_826DAF04;
	// rotlwi r10,r5,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lbz r5,111(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 111);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826daef8
	if (!cr6.eq) goto loc_826DAEF8;
	// lbz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826daf04
	if (cr6.eq) goto loc_826DAF04;
loc_826DAEF8:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f13,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// b 0x826daf0c
	goto loc_826DAF0C;
loc_826DAF04:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_826DAF0C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826daf44
	if (cr6.eq) goto loc_826DAF44;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826daf38
	if (!cr6.eq) goto loc_826DAF38;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826daf44
	if (cr6.eq) goto loc_826DAF44;
loc_826DAF38:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f13,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, temp.u32);
	// b 0x826daf4c
	goto loc_826DAF4C;
loc_826DAF44:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, temp.u32);
loc_826DAF4C:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// bne 0x826dae38
	if (!cr0.eq) goto loc_826DAE38;
loc_826DAF58:
	// cmpw cr6,r6,r22
	cr6.compare<int32_t>(ctx.r6.s32, r22.s32, xer);
	// bge cr6,0x826dafb4
	if (!cr6.lt) goto loc_826DAFB4;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r6,r22
	ctx.r9.s64 = r22.s64 - ctx.r6.s64;
loc_826DAF68:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826dafa0
	if (cr6.eq) goto loc_826DAFA0;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lbz r8,111(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 111);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826daf94
	if (!cr6.eq) goto loc_826DAF94;
	// lbz r10,112(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dafa0
	if (cr6.eq) goto loc_826DAFA0;
loc_826DAF94:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f13,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// b 0x826dafa8
	goto loc_826DAFA8;
loc_826DAFA0:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_826DAFA8:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826daf68
	if (!cr0.eq) goto loc_826DAF68;
loc_826DAFB4:
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// stfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 16, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826daff0
	if (cr6.eq) goto loc_826DAFF0;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
loc_826DAFCC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lfs f13,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,16(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 16, temp.u32);
	// lhz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826dafcc
	if (cr6.lt) goto loc_826DAFCC;
loc_826DAFF0:
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826DAB80) {
	__imp__sub_826DAB80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DAFF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,20(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826db068
	if (cr6.eq) goto loc_826DB068;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r5,r7,2192
	ctx.r5.s64 = ctx.r7.s64 + 2192;
	// ori r8,r6,64167
	ctx.r8.u64 = ctx.r6.u64 | 64167;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,2192(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2192);
	// twllei r10,0
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mulld r9,r6,r8
	ctx.r9.s64 = ctx.r6.s64 * ctx.r8.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2192, r11.u32);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// andc r11,r10,r7
	r11.u64 = ctx.r10.u64 & ~ctx.r7.u64;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r11,-1
	// b 0x826d6290
	sub_826D6290(ctx, base);
	return;
loc_826DB068:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DAFF8) {
	__imp__sub_826DAFF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,124(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826db0e0
	if (cr6.eq) goto loc_826DB0E0;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r5,r7,2192
	ctx.r5.s64 = ctx.r7.s64 + 2192;
	// ori r8,r6,64167
	ctx.r8.u64 = ctx.r6.u64 | 64167;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r6,2192(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2192);
	// twllei r10,0
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mulld r9,r6,r8
	ctx.r9.s64 = ctx.r6.s64 * ctx.r8.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2192, r11.u32);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// andc r11,r10,r7
	r11.u64 = ctx.r10.u64 & ~ctx.r7.u64;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r11,-1
	// b 0x826d6290
	sub_826D6290(ctx, base);
	return;
loc_826DB0E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DB070) {
	__imp__sub_826DB070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB0E8) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826db12c
	if (!cr6.eq) goto loc_826DB12C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826db124
	if (cr6.eq) goto loc_826DB124;
	// bl 0x826da3b8
	ctx.lr = 0x826DB120;
	sub_826DA3B8(ctx, base);
	// b 0x826db128
	goto loc_826DB128;
loc_826DB124:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DB128:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826DB12C:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

PPC_WEAK_FUNC(sub_826DB0E8) {
	__imp__sub_826DB0E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB148) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x826DB15C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db194
	if (cr6.eq) goto loc_826DB194;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,6956
	ctx.r9.s64 = ctx.r10.s64 + 6956;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826DB194:
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

PPC_WEAK_FUNC(sub_826DB148) {
	__imp__sub_826DB148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB1A8) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x826DB1BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db208
	if (cr6.eq) goto loc_826DB208;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,6968
	ctx.r9.s64 = ctx.r10.s64 + 6968;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// sth r11,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r11.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826DB208:
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

PPC_WEAK_FUNC(sub_826DB1A8) {
	__imp__sub_826DB1A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB21C) {
	__imp__sub_826DB21C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB220) {
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
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x826DB23C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826db27c
	if (!cr6.gt) goto loc_826DB27C;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r11,r3,14
	r11.s64 = ctx.r3.s64 + 14;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,6956
	ctx.r9.s64 = ctx.r9.s64 + 6956;
loc_826DB254:
	// addic. r8,r11,-14
	xer.ca = r11.u32 > 13;
	ctx.r8.s64 = r11.s64 + -14;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x826db270
	if (cr0.eq) goto loc_826DB270;
	// stw r9,-14(r11)
	PPC_STORE_U32(r11.u32 + -14, ctx.r9.u32);
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_826DB270:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x826db254
	if (!cr0.eq) goto loc_826DB254;
loc_826DB27C:
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

PPC_WEAK_FUNC(sub_826DB220) {
	__imp__sub_826DB220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24776(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24776);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DB290) {
	__imp__sub_826DB290(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB29C) {
	__imp__sub_826DB29C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB2A0) {
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
	ctx.lr = 0x826DB2A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// addi r10,r11,7016
	ctx.r10.s64 = r11.s64 + 7016;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x826DB2C4;
	sub_821D2AA0(ctx, base);
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// bl 0x821d2aa0
	ctx.lr = 0x826DB2CC;
	sub_821D2AA0(ctx, base);
	// lhz r9,18(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826db2e0
	if (cr6.eq) goto loc_826DB2E0;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x826DB2E0;
	sub_82130588(ctx, base);
loc_826DB2E0:
	// lhz r31,10(r30)
	r31.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826db318
	if (cr6.eq) goto loc_826DB318;
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826db310
	if (!cr6.gt) goto loc_826DB310;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_826DB2FC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x826DB304;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826db2fc
	if (!cr0.eq) goto loc_826DB2FC;
loc_826DB310:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826DB318;
	sub_82130588(ctx, base);
loc_826DB318:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DB2A0) {
	__imp__sub_826DB2A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB320) {
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
	// bl 0x826db2a0
	ctx.lr = 0x826DB340;
	sub_826DB2A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826db358
	if (cr6.eq) goto loc_826DB358;
	// bl 0x82130588
	ctx.lr = 0x826DB354;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DB358:
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

PPC_WEAK_FUNC(sub_826DB320) {
	__imp__sub_826DB320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB370) {
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
	ctx.lr = 0x826DB378;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r24,r11,30576
	r24.s64 = r11.s64 + 30576;
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x821ca540
	ctx.lr = 0x826DB3A0;
	sub_821CA540(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r11,-24776(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24776);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,2828(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,4(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826DB3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r5,5276
	ctx.r5.s64 = ctx.r5.s64 + 5276;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c04b0
	ctx.lr = 0x826DB3E8;
	sub_821C04B0(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r4,r31,28
	ctx.r4.s64 = r31.s64 + 28;
	// bl 0x82389998
	ctx.lr = 0x826DB3FC;
	sub_82389998(ctx, base);
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x826DB404;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r30,0
	r30.s64 = 0;
	// beq cr6,0x826db444
	if (cr6.eq) goto loc_826DB444;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,6968
	ctx.r10.s64 = r11.s64 + 6968;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// sth r30,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r30.u16);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r30.u32);
	// sth r30,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r30.u16);
	// sth r30,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r30.u16);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r30.u32);
	// sth r30,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r30.u16);
	// sth r30,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r30.u16);
	// b 0x826db448
	goto loc_826DB448;
loc_826DB444:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DB448:
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x826daa40
	ctx.lr = 0x826DB458;
	sub_826DAA40(ctx, base);
	// lhz r29,8(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826db470
	if (cr6.eq) goto loc_826DB470;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826DB46C;
	sub_82130528(ctx, base);
	// b 0x826db474
	goto loc_826DB474;
loc_826DB470:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DB474:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// sth r29,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r29.u16);
	// ble cr6,0x826db54c
	if (!cr6.gt) goto loc_826DB54C;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r27,r30
	r27.u64 = r30.u64;
	// ori r26,r10,65535
	r26.u64 = ctx.r10.u64 | 65535;
	// addi r25,r11,7016
	r25.s64 = r11.s64 + 7016;
loc_826DB498:
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x826DB4A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db4e0
	if (cr6.eq) goto loc_826DB4E0;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// sth r30,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r30.u16);
	// sth r30,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r30.u16);
	// stw r30,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r30.u32);
	// sth r30,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r30.u16);
	// sth r30,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r30.u16);
	// stw r30,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r30.u32);
	// stw r30,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r30.u32);
	// stw r26,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r26.u32);
	// stw r30,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r30.u32);
	// stw r30,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r30.u32);
	// b 0x826db4e4
	goto loc_826DB4E4;
loc_826DB4E0:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
loc_826DB4E4:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// li r11,5
	r11.s64 = 5;
	// sth r5,16(r31)
	PPC_STORE_U16(r31.u32 + 16, ctx.r5.u16);
	// stwx r6,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r6.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_826DB50C:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x826db50c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826DB50C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r9,r27,r11
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// bl 0x826db370
	ctx.lr = 0x826DB540;
	sub_826DB370(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x826db498
	if (!cr0.eq) goto loc_826DB498;
loc_826DB54C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826DB554;
	sub_821C9A90(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_826DB370) {
	__imp__sub_826DB370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB55C) {
	__imp__sub_826DB55C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB560) {
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
	ctx.lr = 0x826DB568;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r28,r31
	r28.u64 = r31.u64;
	// lhz r11,16(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826db5d4
	if (cr6.eq) goto loc_826DB5D4;
	// mr r30,r31
	r30.u64 = r31.u64;
loc_826DB588:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826db560
	ctx.lr = 0x826DB594;
	sub_826DB560(ctx, base);
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db5b8
	if (cr6.eq) goto loc_826DB5B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DB5B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826DB5B8:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stwx r31,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, r31.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lhz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x826db588
	if (cr6.lt) goto loc_826DB588;
loc_826DB5D4:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x826DB5DC;
	sub_82130588(ctx, base);
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// addi r30,r29,4
	r30.s64 = r29.s64 + 4;
	// sth r31,16(r29)
	PPC_STORE_U16(r29.u32 + 16, r31.u16);
	// sth r31,18(r29)
	PPC_STORE_U16(r29.u32 + 18, r31.u16);
	// lhz r28,10(r29)
	r28.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// lwz r26,4(r29)
	r26.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// ble cr6,0x826db614
	if (!cr6.gt) goto loc_826DB614;
	// mr r27,r26
	r27.u64 = r26.u64;
loc_826DB600:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x826DB608;
	sub_821D2AA0(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x826db600
	if (!cr0.eq) goto loc_826DB600;
loc_826DB614:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x826DB61C;
	sub_82130588(ctx, base);
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// lwz r30,24(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826db710
	if (cr6.eq) goto loc_826DB710;
	// lhz r26,18(r30)
	r26.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// addi r27,r30,12
	r27.s64 = r30.s64 + 12;
	// lwz r25,12(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x826db670
	if (!cr6.gt) goto loc_826DB670;
	// mr r28,r25
	r28.u64 = r25.u64;
loc_826DB64C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DB664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// bne 0x826db64c
	if (!cr0.eq) goto loc_826DB64C;
loc_826DB670:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x826DB678;
	sub_82130588(ctx, base);
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// sth r31,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r31.u16);
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
	// sth r31,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r31.u16);
	// lwz r25,4(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lhz r11,10(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826db6c4
	if (!cr6.gt) goto loc_826DB6C4;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r26,r11
	r26.u64 = r11.u64;
loc_826DB6A0:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DB6B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r27,r27,16
	r27.s64 = r27.s64 + 16;
	// bne 0x826db6a0
	if (!cr0.eq) goto loc_826DB6A0;
loc_826DB6C4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x826DB6CC;
	sub_82130588(ctx, base);
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// sth r31,6(r28)
	PPC_STORE_U16(r28.u32 + 6, r31.u16);
	// sth r31,4(r28)
	PPC_STORE_U16(r28.u32 + 4, r31.u16);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x826DB6E0;
	sub_82130588(ctx, base);
	// stw r31,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r31.u32);
	// sth r31,24(r30)
	PPC_STORE_U16(r30.u32 + 24, r31.u16);
	// sth r31,26(r30)
	PPC_STORE_U16(r30.u32 + 26, r31.u16);
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db70c
	if (cr6.eq) goto loc_826DB70C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DB70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826DB70C:
	// stw r31,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r31.u32);
loc_826DB710:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826DB560) {
	__imp__sub_826DB560(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB718) {
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
	ctx.lr = 0x826DB720;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,7032
	ctx.r3.s64 = r11.s64 + 7032;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82130000
	ctx.lr = 0x826DB738;
	sub_82130000(ctx, base);
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x826DB740;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq cr6,0x826db790
	if (cr6.eq) goto loc_826DB790;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,7016
	ctx.r9.s64 = r11.s64 + 7016;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// sth r31,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r31.u16);
	// sth r31,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r31.u16);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r31.u32);
	// sth r31,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r31.u16);
	// sth r31,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r31.u16);
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r31.u32);
	// stw r31,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r31.u32);
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// stw r31,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r31.u32);
	// stw r31,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r31.u32);
	// b 0x826db794
	goto loc_826DB794;
loc_826DB790:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DB794:
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// addi r28,r30,20
	r28.s64 = r30.s64 + 20;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// bl 0x826db370
	ctx.lr = 0x826DB7C0;
	sub_826DB370(ctx, base);
	// lhz r9,34(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 34);
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lhz r30,24(r30)
	r30.u64 = PPC_LOAD_U16(r30.u32 + 24);
	// bne cr6,0x826db7f4
	if (!cr6.eq) goto loc_826DB7F4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// beq cr6,0x826db7ec
	if (cr6.eq) goto loc_826DB7EC;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826DB7E8;
	sub_82130528(ctx, base);
	// b 0x826db7f0
	goto loc_826DB7F0;
loc_826DB7EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DB7F0:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_826DB7F4:
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826da438
	ctx.lr = 0x826DB800;
	sub_826DA438(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,7024
	ctx.r3.s64 = ctx.r10.s64 + 7024;
	// bl 0x82130000
	ctx.lr = 0x826DB80C;
	sub_82130000(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DB718) {
	__imp__sub_826DB718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB814) {
	__imp__sub_826DB814(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB818) {
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
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x826DB83C;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// sth r30,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r30.u16);
	// sth r30,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r30.u16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x826DB854;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// sth r30,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r30.u16);
	// sth r30,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r30.u16);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db894
	if (cr6.eq) goto loc_826DB894;
	// bl 0x826db560
	ctx.lr = 0x826DB870;
	sub_826DB560(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826db890
	if (cr6.eq) goto loc_826DB890;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DB890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826DB890:
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_826DB894:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82608de8
	ctx.lr = 0x826DB89C;
	sub_82608DE8(ctx, base);
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

PPC_WEAK_FUNC(sub_826DB818) {
	__imp__sub_826DB818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB8B4) {
	__imp__sub_826DB8B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB8B8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r31,r30,20
	r31.s64 = r30.s64 + 20;
	// addi r10,r11,7084
	ctx.r10.s64 = r11.s64 + 7084;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lhz r9,34(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 34);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826db8f4
	if (cr6.eq) goto loc_826DB8F4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826DB8F4;
	sub_82130588(ctx, base);
loc_826DB8F4:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826db908
	if (cr6.eq) goto loc_826DB908;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826DB908;
	sub_82130588(ctx, base);
loc_826DB908:
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x82608de8
	ctx.lr = 0x826DB910;
	sub_82608DE8(ctx, base);
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

PPC_WEAK_FUNC(sub_826DB8B8) {
	__imp__sub_826DB8B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB928) {
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
	ctx.lr = 0x826DB930;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x826db96c
	if (!cr6.eq) goto loc_826DB96C;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-24136
	ctx.r4.s64 = r11.s64 + -24136;
	// lwz r5,-27856(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + -27856);
	// bl 0x823dc018
	ctx.lr = 0x826DB960;
	sub_823DC018(ctx, base);
	// addi r3,r30,96
	ctx.r3.s64 = r30.s64 + 96;
	// lwz r4,-27856(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -27856);
	// bl 0x826f8980
	ctx.lr = 0x826DB96C;
	sub_826F8980(ctx, base);
loc_826DB96C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826db718
	ctx.lr = 0x826DB984;
	sub_826DB718(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DB928) {
	__imp__sub_826DB928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB98C) {
	__imp__sub_826DB98C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB990) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DB998;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,2
	r31.s64 = 2;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_826DB9A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826db818
	ctx.lr = 0x826DB9B0;
	sub_826DB818(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,48
	r30.s64 = r30.s64 + 48;
	// bne 0x826db9a8
	if (!cr0.eq) goto loc_826DB9A8;
	// addi r3,r29,96
	ctx.r3.s64 = r29.s64 + 96;
	// bl 0x826f8af8
	ctx.lr = 0x826DB9C4;
	sub_826F8AF8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DB990) {
	__imp__sub_826DB990(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DB9CC) {
	__imp__sub_826DB9CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DB9D0) {
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
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x826f89c8
	ctx.lr = 0x826DB9EC;
	sub_826F89C8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x826bde70
	ctx.lr = 0x826DB9FC;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826dba18
	if (!cr6.eq) goto loc_826DBA18;
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
loc_826DBA18:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r3,32(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
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

PPC_WEAK_FUNC(sub_826DB9D0) {
	__imp__sub_826DB9D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBA38) {
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
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x826f89c8
	ctx.lr = 0x826DBA54;
	sub_826F89C8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x826bde70
	ctx.lr = 0x826DBA64;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826dba80
	if (!cr6.eq) goto loc_826DBA80;
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
loc_826DBA80:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r3,36(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 36);
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

PPC_WEAK_FUNC(sub_826DBA38) {
	__imp__sub_826DBA38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBA9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DBA9C) {
	__imp__sub_826DBA9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBAA0) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826DBAA8;
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r30,96
	ctx.r3.s64 = r30.s64 + 96;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x826f89c8
	ctx.lr = 0x826DBACC;
	sub_826F89C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
loc_826DBAD4:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x826dbb4c
	if (!cr6.eq) goto loc_826DBB4C;
	// lbz r11,248(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbb60
	if (!cr6.eq) goto loc_826DBB60;
loc_826DBAE8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_826DBAEC:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r6,r10,24
	ctx.r6.u64 = ctx.r10.u32 & 0xFF;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lhz r11,12(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbb84
	if (cr6.eq) goto loc_826DBB84;
	// divwu r9,r29,r11
	ctx.r9.u32 = r29.u32 / r11.u32;
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// twllei r11,0
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r5,r7,r29
	ctx.r5.s64 = r29.s64 - ctx.r7.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r8
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbb84
	if (cr6.eq) goto loc_826DBB84;
loc_826DBB30:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// beq cr6,0x826dbb68
	if (cr6.eq) goto loc_826DBB68;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbb30
	if (!cr6.eq) goto loc_826DBB30;
	// b 0x826dbb84
	goto loc_826DBB84;
loc_826DBB4C:
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// bne cr6,0x826dbae8
	if (!cr6.eq) goto loc_826DBAE8;
	// lbz r11,249(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 249);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbae8
	if (cr6.eq) goto loc_826DBAE8;
loc_826DBB60:
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x826dbaec
	goto loc_826DBAEC;
loc_826DBB68:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbb84
	if (cr6.eq) goto loc_826DBB84;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r10,20
	ctx.r3.s64 = ctx.r10.s64 + 20;
	// bl 0x826dab80
	ctx.lr = 0x826DBB84;
	sub_826DAB80(ctx, base);
loc_826DBB84:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// blt cr6,0x826dbad4
	if (cr6.lt) goto loc_826DBAD4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r27,r30,24
	r27.s64 = r30.s64 + 24;
	// li r22,2
	r22.s64 = 2;
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// ori r25,r9,16952
	r25.u64 = ctx.r9.u64 | 16952;
	// lis r23,-32130
	r23.s64 = -2105671680;
	// addi r24,r11,-14260
	r24.s64 = r11.s64 + -14260;
loc_826DBBB4:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbd24
	if (cr6.eq) goto loc_826DBD24;
	// li r28,0
	r28.s64 = 0;
loc_826DBBC8:
	// lwz r11,-4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4);
	// lwzx r11,r28,r11
	r11.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dbd04
	if (cr6.eq) goto loc_826DBD04;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r29,168(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x826dbbf0
	if (cr6.gt) goto loc_826DBBF0;
	// li r11,0
	r11.s64 = 0;
loc_826DBBF0:
	// lwz r10,4(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dbc08
	if (cr6.eq) goto loc_826DBC08;
	// li r30,4
	r30.s64 = 4;
	// b 0x826dbc14
	goto loc_826DBC14;
loc_826DBC08:
	// lwz r3,3528(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 3528);
	// bl 0x822d5278
	ctx.lr = 0x826DBC10;
	sub_822D5278(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826DBC14:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// lfsx f31,r21,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + r25.u32);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lbz r11,56(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 56);
	// beq cr6,0x826dbca0
	if (cr6.eq) goto loc_826DBCA0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbc40
	if (!cr6.eq) goto loc_826DBC40;
	// lbz r11,57(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 57);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x826dbc44
	if (cr6.eq) goto loc_826DBC44;
loc_826DBC40:
	// li r11,1
	r11.s64 = 1;
loc_826DBC44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbd04
	if (!cr6.eq) goto loc_826DBD04;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DBC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dbd04
	if (!cr6.eq) goto loc_826DBD04;
	// lbz r11,25(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbd04
	if (!cr6.eq) goto loc_826DBD04;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// ble cr6,0x826dbd04
	if (!cr6.gt) goto loc_826DBD04;
	// lfs f0,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// ble cr6,0x826dbd04
	if (!cr6.gt) goto loc_826DBD04;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82790108
	ctx.lr = 0x826DBC9C;
	sub_82790108(ctx, base);
	// b 0x826dbd24
	goto loc_826DBD24;
loc_826DBCA0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbcb8
	if (!cr6.eq) goto loc_826DBCB8;
	// lbz r11,57(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 57);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x826dbcbc
	if (cr6.eq) goto loc_826DBCBC;
loc_826DBCB8:
	// li r11,1
	r11.s64 = 1;
loc_826DBCBC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbd04
	if (!cr6.eq) goto loc_826DBD04;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DBCDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826dbd04
	if (cr6.eq) goto loc_826DBD04;
	// lbz r11,25(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 25);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbd04
	if (!cr6.eq) goto loc_826DBD04;
	// lfs f0,28(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 28);
	f0.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bgt cr6,0x826dbd1c
	if (cr6.gt) goto loc_826DBD1C;
loc_826DBD04:
	// lhz r11,0(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x826dbbc8
	if (cr6.lt) goto loc_826DBBC8;
	// b 0x826dbd24
	goto loc_826DBD24;
loc_826DBD1C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82790160
	ctx.lr = 0x826DBD24;
	sub_82790160(ctx, base);
loc_826DBD24:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// addi r27,r27,48
	r27.s64 = r27.s64 + 48;
	// bne 0x826dbbb4
	if (!cr0.eq) goto loc_826DBBB4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_826DBAA0) {
	__imp__sub_826DBAA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBD40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,7084
	ctx.r9.s64 = ctx.r10.s64 + 7084;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// stb r11,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, r11.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r9,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r9.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// sth r11,62(r3)
	PPC_STORE_U16(ctx.r3.u32 + 62, r11.u16);
	// sth r11,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, r11.u16);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stb r11,67(r3)
	PPC_STORE_U8(ctx.r3.u32 + 67, r11.u8);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// sth r11,72(r3)
	PPC_STORE_U16(ctx.r3.u32 + 72, r11.u16);
	// sth r11,74(r3)
	PPC_STORE_U16(ctx.r3.u32 + 74, r11.u16);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// sth r11,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, r11.u16);
	// sth r11,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, r11.u16);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, r11.u8);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stb r11,248(r3)
	PPC_STORE_U8(ctx.r3.u32 + 248, r11.u8);
	// stb r11,249(r3)
	PPC_STORE_U8(ctx.r3.u32 + 249, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DBD40) {
	__imp__sub_826DBD40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DBDEC) {
	__imp__sub_826DBDEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBDF0) {
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
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x826DBE04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dbe60
	if (cr6.eq) goto loc_826DBE60;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,7016
	ctx.r9.s64 = r11.s64 + 7016;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// sth r11,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r11.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826DBE60:
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

PPC_WEAK_FUNC(sub_826DBDF0) {
	__imp__sub_826DBDF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DBE74) {
	__imp__sub_826DBE74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBE78) {
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
	// addi r31,r11,-24788
	r31.s64 = r11.s64 + -24788;
	// lwz r11,-24788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dbfa8
	if (!cr6.eq) goto loc_826DBFA8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826DBEA8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dbebc
	if (cr6.eq) goto loc_826DBEBC;
	// bl 0x821d5408
	ctx.lr = 0x826DBEB8;
	sub_821D5408(ctx, base);
	// b 0x826dbec0
	goto loc_826DBEC0;
loc_826DBEBC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DBEC0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7088
	ctx.r7.s64 = ctx.r10.s64 + 7088;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32146
	ctx.r8.s64 = -2106720256;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-23728
	ctx.r4.s64 = ctx.r8.s64 + -23728;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-21848
	ctx.r7.s64 = ctx.r3.s64 + -21848;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// addi r4,r10,-21824
	ctx.r4.s64 = ctx.r10.s64 + -21824;
	// addi r3,r9,-21800
	ctx.r3.s64 = ctx.r9.s64 + -21800;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,8
	ctx.r8.s64 = 8;
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
	ctx.lr = 0x826DBF54;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826DBF64;
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
	ctx.lr = 0x826DBF80;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-21776
	ctx.r4.s64 = ctx.r8.s64 + -21776;
	// bl 0x821d4b00
	ctx.lr = 0x826DBF90;
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
	ctx.lr = 0x826DBFA8;
	sub_821C0548(ctx, base);
loc_826DBFA8:
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

PPC_WEAK_FUNC(sub_826DBE78) {
	__imp__sub_826DBE78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DBFC0) {
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
	ctx.lr = 0x826DBFC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-24776
	r31.s64 = r11.s64 + -24776;
	// lwz r11,-24776(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24776);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc0f8
	if (!cr6.eq) goto loc_826DC0F8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826DBFE8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dbffc
	if (cr6.eq) goto loc_826DBFFC;
	// bl 0x821d5408
	ctx.lr = 0x826DBFF8;
	sub_821D5408(ctx, base);
	// b 0x826dc000
	goto loc_826DC000;
loc_826DBFFC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DC000:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7104
	ctx.r7.s64 = ctx.r10.s64 + 7104;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32146
	ctx.r8.s64 = -2106720256;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-16912
	ctx.r4.s64 = ctx.r8.s64 + -16912;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,-21604
	ctx.r5.s64 = ctx.r3.s64 + -21604;
	// addi r4,r10,-21580
	ctx.r4.s64 = ctx.r10.s64 + -21580;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r9,-21556
	r30.s64 = ctx.r9.s64 + -21556;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r29,r8,-21344
	r29.s64 = ctx.r8.s64 + -21344;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,36
	ctx.r8.s64 = 36;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x826DC0A4;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826DC0B4;
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
	ctx.lr = 0x826DC0D0;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-21508
	ctx.r4.s64 = ctx.r8.s64 + -21508;
	// bl 0x821d4b00
	ctx.lr = 0x826DC0E0;
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
	ctx.lr = 0x826DC0F8;
	sub_821C0548(ctx, base);
loc_826DC0F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DBFC0) {
	__imp__sub_826DBFC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC100) {
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
	// bl 0x826db8b8
	ctx.lr = 0x826DC120;
	sub_826DB8B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dc138
	if (cr6.eq) goto loc_826DC138;
	// bl 0x82130588
	ctx.lr = 0x826DC134;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DC138:
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

PPC_WEAK_FUNC(sub_826DC100) {
	__imp__sub_826DC100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC150) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc194
	if (!cr6.eq) goto loc_826DC194;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826dc18c
	if (cr6.eq) goto loc_826DC18C;
	// bl 0x826db220
	ctx.lr = 0x826DC188;
	sub_826DB220(ctx, base);
	// b 0x826dc190
	goto loc_826DC190;
loc_826DC18C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DC190:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826DC194:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

PPC_WEAK_FUNC(sub_826DC150) {
	__imp__sub_826DC150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC1B0) {
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
	// addi r31,r11,-24784
	r31.s64 = r11.s64 + -24784;
	// lwz r11,-24784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24784);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc2f4
	if (!cr6.eq) goto loc_826DC2F4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826DC1E0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc1f4
	if (cr6.eq) goto loc_826DC1F4;
	// bl 0x821d5408
	ctx.lr = 0x826DC1F0;
	sub_821D5408(ctx, base);
	// b 0x826dc1f8
	goto loc_826DC1F8;
loc_826DC1F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DC1F8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7136
	ctx.r7.s64 = ctx.r10.s64 + 7136;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32146
	ctx.r8.s64 = -2106720256;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,-20152
	ctx.r4.s64 = ctx.r8.s64 + -20152;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-21488
	ctx.r5.s64 = ctx.r10.s64 + -21488;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,-21760
	ctx.r8.s64 = ctx.r3.s64 + -21760;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,8
	ctx.r9.s64 = 8;
	// lwz r11,-24788(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826dc284
	if (!cr6.eq) goto loc_826DC284;
	// bl 0x826dbe78
	ctx.lr = 0x826DC280;
	sub_826DBE78(ctx, base);
	// lwz r11,-24788(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24788);
loc_826DC284:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-21736
	ctx.r9.s64 = ctx.r10.s64 + -21736;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x826DC2A0;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826DC2B0;
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
	ctx.lr = 0x826DC2CC;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-21700
	ctx.r4.s64 = ctx.r6.s64 + -21700;
	// bl 0x821d4b00
	ctx.lr = 0x826DC2DC;
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
	ctx.lr = 0x826DC2F4;
	sub_821C0548(ctx, base);
loc_826DC2F4:
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

PPC_WEAK_FUNC(sub_826DC1B0) {
	__imp__sub_826DC1B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC30C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DC30C) {
	__imp__sub_826DC30C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC310) {
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
	// addi r31,r11,-24780
	r31.s64 = r11.s64 + -24780;
	// lwz r11,-24780(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24780);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc478
	if (!cr6.eq) goto loc_826DC478;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826DC340;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc354
	if (cr6.eq) goto loc_826DC354;
	// bl 0x821d5408
	ctx.lr = 0x826DC350;
	sub_821D5408(ctx, base);
	// b 0x826dc358
	goto loc_826DC358;
loc_826DC354:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DC358:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,7164
	ctx.r7.s64 = ctx.r10.s64 + 7164;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32146
	ctx.r8.s64 = -2106720256;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-20056
	ctx.r4.s64 = ctx.r8.s64 + -20056;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-21440
	ctx.r9.s64 = ctx.r3.s64 + -21440;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-24784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24784);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826dc3d4
	if (!cr6.eq) goto loc_826DC3D4;
	// bl 0x826dc1b0
	ctx.lr = 0x826DC3D0;
	sub_826DC1B0(ctx, base);
	// lwz r11,-24784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24784);
loc_826DC3D4:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r10,-21688
	ctx.r8.s64 = ctx.r10.s64 + -21688;
	// addi r7,r9,-21392
	ctx.r7.s64 = ctx.r9.s64 + -21392;
	// li r9,12
	ctx.r9.s64 = 12;
	// lwz r10,-24788(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24788);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826dc408
	if (!cr6.eq) goto loc_826DC408;
	// bl 0x826dbe78
	ctx.lr = 0x826DC404;
	sub_826DBE78(ctx, base);
	// lwz r10,-24788(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24788);
loc_826DC408:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,-21652
	ctx.r9.s64 = r11.s64 + -21652;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x826DC424;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826DC434;
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
	ctx.lr = 0x826DC450;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-21616
	ctx.r4.s64 = ctx.r6.s64 + -21616;
	// bl 0x821d4b00
	ctx.lr = 0x826DC460;
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
	ctx.lr = 0x826DC478;
	sub_821C0548(ctx, base);
loc_826DC478:
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

PPC_WEAK_FUNC(sub_826DC310) {
	__imp__sub_826DC310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC490) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r30,6
	r30.s64 = 6;
loc_826DC4AC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc4c0
	if (cr6.eq) goto loc_826DC4C0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x826DC4C0;
	sub_8213C218(ctx, base);
loc_826DC4C0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826dc4ac
	if (!cr0.eq) goto loc_826DC4AC;
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

PPC_WEAK_FUNC(sub_826DC490) {
	__imp__sub_826DC490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DC4E4) {
	__imp__sub_826DC4E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC4E8) {
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
	// bl 0x826f8b60
	ctx.lr = 0x826DC504;
	sub_826F8B60(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,7660
	ctx.r10.s64 = r11.s64 + 7660;
	// addi r11,r31,192
	r11.s64 = r31.s64 + 192;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_826DC524:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x826dc524
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826DC524;
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r30,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r30.u32);
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// stb r30,285(r31)
	PPC_STORE_U8(r31.u32 + 285, r30.u8);
	// bl 0x82130528
	ctx.lr = 0x826DC54C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc560
	if (cr6.eq) goto loc_826DC560;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82381ed0
	ctx.lr = 0x826DC55C;
	sub_82381ED0(ctx, base);
	// b 0x826dc564
	goto loc_826DC564;
loc_826DC560:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826DC564:
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r3,228(r31)
	PPC_STORE_U32(r31.u32 + 228, ctx.r3.u32);
	// lwz r11,-24772(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24772);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc594
	if (!cr6.eq) goto loc_826DC594;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r11,7628
	ctx.r4.s64 = r11.s64 + 7628;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x826DC58C;
	sub_82144A20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,-24772(r30)
	PPC_STORE_U32(r30.u32 + -24772, r11.u32);
loc_826DC594:
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

PPC_WEAK_FUNC(sub_826DC4E8) {
	__imp__sub_826DC4E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC5B0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DC5DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dc604
	if (cr6.eq) goto loc_826DC604;
	// stw r30,76(r11)
	PPC_STORE_U32(r11.u32 + 76, r30.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dc604
	if (!cr6.eq) goto loc_826DC604;
	// bl 0x821f6c50
	ctx.lr = 0x826DC604;
	sub_821F6C50(ctx, base);
loc_826DC604:
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x82381c68
	ctx.lr = 0x826DC60C;
	sub_82381C68(ctx, base);
	// stb r30,285(r31)
	PPC_STORE_U8(r31.u32 + 285, r30.u8);
	// stw r30,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r30.u32);
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

PPC_WEAK_FUNC(sub_826DC5B0) {
	__imp__sub_826DC5B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC630) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r31,r11,-24768
	r31.s64 = r11.s64 + -24768;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826f8c68
	ctx.lr = 0x826DC658;
	sub_826F8C68(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dc680
	if (cr6.eq) goto loc_826DC680;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826DC66C:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stb r9,284(r8)
	PPC_STORE_U8(ctx.r8.u32 + 284, ctx.r9.u8);
	// bne 0x826dc66c
	if (!cr0.eq) goto loc_826DC66C;
loc_826DC680:
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

PPC_WEAK_FUNC(sub_826DC630) {
	__imp__sub_826DC630(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DC694) {
	__imp__sub_826DC694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r9,284(r3)
	PPC_STORE_U8(ctx.r3.u32 + 284, ctx.r9.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,280(r3)
	PPC_STORE_U32(ctx.r3.u32 + 280, ctx.r8.u32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,260(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// stfs f0,264(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// stfs f0,268(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 268, temp.u32);
	// stfs f0,272(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 272, temp.u32);
	// stfs f0,244(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 244, temp.u32);
	// stfs f0,248(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 248, temp.u32);
	// stfs f0,252(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 252, temp.u32);
	// stfs f0,256(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// stfs f13,276(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// stfs f0,236(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 236, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DC698) {
	__imp__sub_826DC698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC6E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DC6E4) {
	__imp__sub_826DC6E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC6E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f13,244(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7612);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,260(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DC6E8) {
	__imp__sub_826DC6E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC700) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,228(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 228);
	// b 0x82383178
	sub_82383178(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DC700) {
	__imp__sub_826DC700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC708) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826DC710;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// beq cr6,0x826dc9ac
	if (cr6.eq) goto loc_826DC9AC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x826dc9ac
	if (cr6.lt) goto loc_826DC9AC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// cmplwi cr6,r28,4
	cr6.compare<uint32_t>(r28.u32, 4, xer);
	// stw r9,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r9.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bgt cr6,0x826dc9a4
	if (cr6.gt) goto loc_826DC9A4;
	// lis r12,-32146
	r12.s64 = -2106720256;
	// addi r12,r12,-14472
	r12.s64 = r12.s64 + -14472;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-13956(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -13956);
	// lwz r19,-14452(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -14452);
	// lwz r19,-14348(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -14348);
	// lwz r19,-14280(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -14280);
	// lwz r19,-14168(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -14168);
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc7a4
	if (cr6.eq) goto loc_826DC7A4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC7A4;
	sub_8213C218(ctx, base);
loc_826DC7A4:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,22(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// bl 0x825491f0
	ctx.lr = 0x826DC7BC;
	sub_825491F0(ctx, base);
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f0,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	f0.f64 = double(temp.f32);
	// lfs f13,236(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lwz r9,26(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26);
	// stfs f31,252(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f10,248(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc80c
	if (cr6.eq) goto loc_826DC80C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC80C;
	sub_8213C218(ctx, base);
loc_826DC80C:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,30(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// bl 0x825491f0
	ctx.lr = 0x826DC824;
	sub_825491F0(ctx, base);
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc850
	if (cr6.eq) goto loc_826DC850;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC850;
	sub_8213C218(ctx, base);
loc_826DC850:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,18(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// lfs f0,7588(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7588);
	f0.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f9,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f9.u32);
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// bl 0x825491f0
	ctx.lr = 0x826DC894;
	sub_825491F0(ctx, base);
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826dc8cc
	if (!cr6.eq) goto loc_826DC8CC;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f0,248(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	f0.f64 = double(temp.f32);
	// lwz r10,26(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 26);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dc9ac
	if (cr6.lt) goto loc_826DC9AC;
loc_826DC8CC:
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc8e4
	if (cr6.eq) goto loc_826DC8E4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC8E4;
	sub_8213C218(ctx, base);
loc_826DC8E4:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r9,50(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 50);
	// lwz r4,42(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 42);
	// lfs f0,7592(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7592);
	f0.f64 = double(temp.f32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r8,52(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 52);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// fsubs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fsubs f3,f7,f5
	ctx.f3.f64 = double(float(ctx.f7.f64 - ctx.f5.f64));
	// fsel f2,f3,f7,f5
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f7.f64 : ctx.f5.f64;
	// fsubs f1,f2,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fsel f0,f1,f4,f2
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f13,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f13.u32);
	// lwz r4,34(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// bl 0x825491f0
	ctx.lr = 0x826DC968;
	sub_825491F0(ctx, base);
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc990
	if (cr6.eq) goto loc_826DC990;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC990;
	sub_8213C218(ctx, base);
loc_826DC990:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dc9a4
	if (cr6.eq) goto loc_826DC9A4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DC9A4;
	sub_8213C218(ctx, base);
loc_826DC9A4:
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r28,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r28.u32);
loc_826DC9AC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DC708) {
	__imp__sub_826DC708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DC9B8) {
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
	ctx.lr = 0x826DC9C0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DC9E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// stw r28,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r28.u32);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826dca10
	if (cr6.eq) goto loc_826DCA10;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r28
	ctx.r10.u64 = r11.u64 + r28.u64;
	// b 0x826dca48
	goto loc_826DCA48;
loc_826DCA10:
	// lbz r11,500(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dca40
	if (cr6.eq) goto loc_826DCA40;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dca40
	if (cr6.eq) goto loc_826DCA40;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dca40
	if (cr6.eq) goto loc_826DCA40;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826dca44
	goto loc_826DCA44;
loc_826DCA40:
	// addi r11,r28,112
	r11.s64 = r28.s64 + 112;
loc_826DCA44:
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_826DCA48:
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r5,9572
	ctx.r5.s64 = ctx.r5.s64 + 9572;
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,128
	ctx.r4.s64 = 128;
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,166(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 166);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// stw r29,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r29.u32);
	// stb r10,166(r31)
	PPC_STORE_U8(r31.u32 + 166, ctx.r10.u8);
	// bl 0x82137a08
	ctx.lr = 0x826DCAA4;
	sub_82137A08(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82144a20
	ctx.lr = 0x826DCAB8;
	sub_82144A20(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// bne cr6,0x826dcaec
	if (!cr6.eq) goto loc_826DCAEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826DCAD0;
	sub_82145020(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,7836
	ctx.r5.s64 = r11.s64 + 7836;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x826DCAEC;
	sub_82137A08(ctx, base);
loc_826DCAEC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82144a20
	ctx.lr = 0x826DCAF8;
	sub_82144A20(ctx, base);
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826dcb30
	if (!cr6.eq) goto loc_826DCB30;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r10,7736
	ctx.r3.s64 = ctx.r10.s64 + 7736;
	// lwz r30,-20956(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -20956);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x826DCB20;
	sub_82130000(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82144a20
	ctx.lr = 0x826DCB2C;
	sub_82144A20(ctx, base);
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
loc_826DCB30:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,116(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// bl 0x82144a28
	ctx.lr = 0x826DCB40;
	sub_82144A28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dcb54
	if (cr6.eq) goto loc_826DCB54;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,54
	cr6.compare<uint32_t>(r11.u32, 54, xer);
	// beq cr6,0x826dcb64
	if (cr6.eq) goto loc_826DCB64;
loc_826DCB54:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,7708
	ctx.r4.s64 = r11.s64 + 7708;
	// bl 0x82144a20
	ctx.lr = 0x826DCB64;
	sub_82144A20(ctx, base);
loc_826DCB64:
	// lbz r11,500(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dcb94
	if (cr6.eq) goto loc_826DCB94;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcb94
	if (cr6.eq) goto loc_826DCB94;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dcb94
	if (cr6.eq) goto loc_826DCB94;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826dcb98
	goto loc_826DCB98;
loc_826DCB94:
	// addi r11,r28,112
	r11.s64 = r28.s64 + 112;
loc_826DCB98:
	// lwz r10,228(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x82381ce8
	ctx.lr = 0x826DCBB0;
	sub_82381CE8(ctx, base);
	// lwz r9,228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r8,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, ctx.r8.u32);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826dcc40
	if (cr6.eq) goto loc_826DCC40;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826dcbfc
	if (cr6.eq) goto loc_826DCBFC;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcbfc
	if (cr6.eq) goto loc_826DCBFC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dcbfc
	if (cr6.eq) goto loc_826DCBFC;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826dcc00
	goto loc_826DCC00;
loc_826DCBFC:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
loc_826DCC00:
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r11,76(r9)
	PPC_STORE_U32(ctx.r9.u32 + 76, r11.u32);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r11,-11980(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11980);
	// lwz r7,22(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// lwz r5,14(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// lwz r6,18(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 80, temp.u32);
	// stfs f0,84(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 84, temp.u32);
	// stfs f12,88(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 88, temp.u32);
loc_826DCC40:
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lwz r11,-24772(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24772);
	// lbz r11,11(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcc90
	if (cr6.eq) goto loc_826DCC90;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826DCC60;
	sub_82145020(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,-24772(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24772);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x82144a28
	ctx.lr = 0x826DCC7C;
	sub_82144A28(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,224(r31)
	PPC_STORE_U32(r31.u32 + 224, ctx.r3.u32);
	// stb r8,285(r31)
	PPC_STORE_U8(r31.u32 + 285, ctx.r8.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826DCC90:
	// li r11,1
	r11.s64 = 1;
	// stb r11,285(r31)
	PPC_STORE_U8(r31.u32 + 285, r11.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DC9B8) {
	__imp__sub_826DC9B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCCA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x826DCCA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,264(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dcdd4
	if (cr6.lt) goto loc_826DCDD4;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82794ee8
	ctx.lr = 0x826DCCCC;
	sub_82794EE8(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r30,0
	r30.s64 = 0;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r11,452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcd48
	if (cr6.eq) goto loc_826DCD48;
	// lwz r3,188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dcd48
	if (cr6.eq) goto loc_826DCD48;
	// bl 0x82245340
	ctx.lr = 0x826DCD20;
	sub_82245340(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dcd48
	if (cr6.eq) goto loc_826DCD48;
	// bl 0x822447b8
	ctx.lr = 0x826DCD2C;
	sub_822447B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,-20256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20256);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x826dcd44
	if (!cr6.lt) goto loc_826DCD44;
	// li r11,0
	r11.s64 = 0;
loc_826DCD44:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
loc_826DCD48:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826dcd6c
	if (cr6.eq) goto loc_826DCD6C;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcd6c
	if (cr6.eq) goto loc_826DCD6C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821f7208
	ctx.lr = 0x826DCD6C;
	sub_821F7208(ctx, base);
loc_826DCD6C:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// lfs f0,21600(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21600);
	f0.f64 = double(temp.f32);
	// lwz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lfs f13,412(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826dcdac
	if (!cr6.gt) goto loc_826DCDAC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// beq cr6,0x826dcda4
	if (cr6.eq) goto loc_826DCDA4;
	// lwz r4,102(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 102);
	// b 0x826dcdb4
	goto loc_826DCDB4;
loc_826DCDA4:
	// lwz r4,98(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 98);
	// b 0x826dcdb4
	goto loc_826DCDB4;
loc_826DCDAC:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lwz r4,106(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 106);
loc_826DCDB4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82549118
	ctx.lr = 0x826DCDC0;
	sub_82549118(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,264(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
loc_826DCDD4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DCCA0) {
	__imp__sub_826DCCA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DCDDC) {
	__imp__sub_826DCDDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCDE0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DCDE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826dcec4
	if (cr6.eq) goto loc_826DCEC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DCE10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dcec4
	if (!cr6.eq) goto loc_826DCEC4;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dcec4
	if (!cr6.eq) goto loc_826DCEC4;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dcec4
	if (cr6.lt) goto loc_826DCEC4;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82794ee8
	ctx.lr = 0x826DCE44;
	sub_82794EE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,0
	r29.s64 = 0;
	// lvx128 v62,r7,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lvx128 v61,r7,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f0,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// lwz r4,90(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 90);
	// bl 0x825491f0
	ctx.lr = 0x826DCEA4;
	sub_825491F0(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f2,7612(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7612);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,7616(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7616);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x826DCEB8;
	sub_82145080(ctx, base);
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,260(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
loc_826DCEC4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DCDE0) {
	__imp__sub_826DCDE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DCECC) {
	__imp__sub_826DCECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCED0) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DCED8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dcfd0
	if (cr6.eq) goto loc_826DCFD0;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826dcfd0
	if (cr6.eq) goto loc_826DCFD0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DCF0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dcfd0
	if (!cr6.eq) goto loc_826DCFD0;
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r30,r31,216
	r30.s64 = r31.s64 + 216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dcfd0
	if (!cr6.eq) goto loc_826DCFD0;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,272(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dcfd0
	if (cr6.lt) goto loc_826DCFD0;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82794ee8
	ctx.lr = 0x826DCF40;
	sub_82794EE8(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r31,96
	ctx.r7.s64 = r31.s64 + 96;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,5
	ctx.r8.s64 = 5;
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 224);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r4,10(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-12544(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12544);
	// bl 0x821f4e78
	ctx.lr = 0x826DCFB0;
	sub_821F4E78(ctx, base);
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f2,7612(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7612);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,7616(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7616);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82145080
	ctx.lr = 0x826DCFC4;
	sub_82145080(ctx, base);
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,272(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
loc_826DCFD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DCED0) {
	__imp__sub_826DCED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DCFD8) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DCFE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826dd0b0
	if (cr6.eq) goto loc_826DD0B0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dd0b0
	if (!cr6.eq) goto loc_826DD0B0;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dd0b0
	if (!cr6.eq) goto loc_826DD0B0;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dd0b0
	if (cr6.lt) goto loc_826DD0B0;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82794ee8
	ctx.lr = 0x826DD03C;
	sub_82794EE8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,0
	r29.s64 = 0;
	// lvx128 v62,r7,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lvx128 v61,r7,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f0,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// lwz r4,94(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 94);
	// bl 0x825491f0
	ctx.lr = 0x826DD09C;
	sub_825491F0(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f13,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7612(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7612);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,260(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
loc_826DD0B0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DCFD8) {
	__imp__sub_826DCFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DD0B8) {
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
	ctx.lr = 0x826DD0C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,228(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 228);
	// bl 0x82381fb0
	ctx.lr = 0x826DD0D4;
	sub_82381FB0(ctx, base);
	// lwz r11,168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826dd270
	if (cr6.eq) goto loc_826DD270;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD0F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826dd270
	if (!cr6.eq) goto loc_826DD270;
	// lfs f0,244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,268(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dd2e0
	if (cr6.lt) goto loc_826DD2E0;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r28,4(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r29,8(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
loc_826DD120:
	// cmpw cr6,r29,r31
	cr6.compare<int32_t>(r29.s32, r31.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x826dd130
	if (!cr6.lt) goto loc_826DD130;
	// li r11,0
	r11.s64 = 0;
loc_826DD130:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dd2e0
	if (!cr6.eq) goto loc_826DD2E0;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r27
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// lbz r10,165(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 165);
	// rlwinm r8,r10,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826dd1d4
	if (cr6.eq) goto loc_826DD1D4;
	// lwz r10,168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826dd188
	if (cr6.eq) goto loc_826DD188;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dd188
	if (cr6.eq) goto loc_826DD188;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dd188
	if (cr6.eq) goto loc_826DD188;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826dd18c
	goto loc_826DD18C;
loc_826DD188:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
loc_826DD18C:
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x826dd1d4
	if (!cr6.eq) goto loc_826DD1D4;
	// lwz r11,160(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r28,r10
	cr6.compare<uint32_t>(r28.u32, ctx.r10.u32, xer);
	// bne cr6,0x826dd1a8
	if (!cr6.eq) goto loc_826DD1A8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_826DD1A8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dd1d4
	if (cr6.eq) goto loc_826DD1D4;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD1C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,8
	cr6.compare<int32_t>(ctx.r3.s32, 8, xer);
	// beq cr6,0x826dd1dc
	if (cr6.eq) goto loc_826DD1DC;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// beq cr6,0x826dd1dc
	if (cr6.eq) goto loc_826DD1DC;
loc_826DD1D4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x826dd120
	goto loc_826DD120;
loc_826DD1DC:
	// li r4,99
	ctx.r4.s64 = 99;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826DD1E8;
	sub_82145020(ctx, base);
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lbz r9,115(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 115);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x826dd204
	if (!cr6.gt) goto loc_826DD204;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826dcde0
	ctx.lr = 0x826DD204;
	sub_826DCDE0(ctx, base);
loc_826DD204:
	// li r4,99
	ctx.r4.s64 = 99;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826DD210;
	sub_82145020(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,-24772(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24772);
	// lbz r9,10(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x826dd2cc
	if (!cr6.gt) goto loc_826DD2CC;
	// lwz r11,168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lfs f0,212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 212);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 216);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,7860(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7860);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x826dd2cc
	if (!cr6.lt) goto loc_826DD2CC;
	// lwz r11,448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r10,116(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bge cr6,0x826dd2cc
	if (!cr6.lt) goto loc_826DD2CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826dced0
	ctx.lr = 0x826DD26C;
	sub_826DCED0(ctx, base);
	// b 0x826dd2cc
	goto loc_826DD2CC;
loc_826DD270:
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// addi r31,r30,212
	r31.s64 = r30.s64 + 212;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dd2e0
	if (!cr6.eq) goto loc_826DD2E0;
	// lfs f0,244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 244);
	f0.f64 = double(temp.f32);
	// lfs f13,268(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826dd2e0
	if (cr6.lt) goto loc_826DD2E0;
	// li r4,99
	ctx.r4.s64 = 99;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82145020
	ctx.lr = 0x826DD29C;
	sub_82145020(ctx, base);
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lbz r9,114(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x826dd2cc
	if (!cr6.gt) goto loc_826DD2CC;
	// addi r10,r30,64
	ctx.r10.s64 = r30.s64 + 64;
	// addi r6,r30,96
	ctx.r6.s64 = r30.s64 + 96;
	// stw r10,116(r30)
	PPC_STORE_U32(r30.u32 + 116, ctx.r10.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,110(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 110);
	// bl 0x825491f0
	ctx.lr = 0x826DD2CC;
	sub_825491F0(ctx, base);
loc_826DD2CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12428(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12428);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,268(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 268, temp.u32);
loc_826DD2E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826DD0B8) {
	__imp__sub_826DD0B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DD2E8) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826DD2F0;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,236(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,46(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 46);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826dd32c
	if (!cr6.lt) goto loc_826DD32C;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x826dd330
	goto loc_826DD330;
loc_826DD32C:
	// lfs f11,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f11.f64 = double(temp.f32);
loc_826DD330:
	// lwz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// li r26,3
	r26.s64 = 3;
	// li r27,0
	r27.s64 = 0;
	// lis r28,-32244
	r28.s64 = -2113142784;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bge cr6,0x826dd3e8
	if (!cr6.lt) goto loc_826DD3E8;
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x826dd4f0
	if (cr6.eq) goto loc_826DD4F0;
	// lfs f0,252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// blt cr6,0x826dd4f0
	if (cr6.lt) goto loc_826DD4F0;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dd3a0
	if (cr6.eq) goto loc_826DD3A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DD3A0;
	sub_8213C218(ctx, base);
loc_826DD3A0:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7588(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7588);
	f0.f64 = double(temp.f32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f9,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f9.u32);
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// bl 0x825491f0
	ctx.lr = 0x826DD3E0;
	sub_825491F0(ctx, base);
	// stw r26,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r26.u32);
	// b 0x826dd4ec
	goto loc_826DD4EC;
loc_826DD3E8:
	// lwz r11,38(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 38);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f10,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f0,f10,f13
	f0.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fabs f0,f0
	f0.u64 = f0.u64 & ~0x8000000000000000;
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f11,f8
	cr6.compare(ctx.f11.f64, ctx.f8.f64);
	// blt cr6,0x826dd418
	if (cr6.lt) goto loc_826DD418;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x826dd41c
	if (!cr6.gt) goto loc_826DD41C;
loc_826DD418:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826DD41C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dd438
	if (cr6.eq) goto loc_826DD438;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826dc708
	ctx.lr = 0x826DD434;
	sub_826DC708(ctx, base);
	// b 0x826dd4f0
	goto loc_826DD4F0;
loc_826DD438:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f0,240(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 240);
	f0.f64 = double(temp.f32);
	// lfs f11,7596(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7596);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x826dd46c
	if (!cr6.gt) goto loc_826DD46C;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x826dd4f0
	if (!cr6.gt) goto loc_826DD4F0;
	// fcmpu cr6,f12,f9
	cr6.compare(ctx.f12.f64, ctx.f9.f64);
	// blt cr6,0x826dd4f0
	if (cr6.lt) goto loc_826DD4F0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826dc708
	ctx.lr = 0x826DD468;
	sub_826DC708(ctx, base);
	// b 0x826dd4f0
	goto loc_826DD4F0;
loc_826DD46C:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x826dd4f0
	if (cr6.eq) goto loc_826DD4F0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f11,-15876(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -15876);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x826dd4f0
	if (!cr6.lt) goto loc_826DD4F0;
	// fnmsubs f0,f10,f12,f12
	f0.f64 = double(float(-(ctx.f10.f64 * ctx.f12.f64 - ctx.f12.f64)));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826dd4f0
	if (!cr6.lt) goto loc_826DD4F0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x826dd4f0
	if (cr6.eq) goto loc_826DD4F0;
	// lfs f0,252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// blt cr6,0x826dd4f0
	if (cr6.lt) goto loc_826DD4F0;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dd4cc
	if (cr6.eq) goto loc_826DD4CC;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DD4CC;
	sub_8213C218(ctx, base);
loc_826DD4CC:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,30(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// bl 0x825491f0
	ctx.lr = 0x826DD4E4;
	sub_825491F0(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,280(r31)
	PPC_STORE_U32(r31.u32 + 280, ctx.r10.u32);
loc_826DD4EC:
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
loc_826DD4F0:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x826dd728
	if (cr6.gt) goto loc_826DD728;
	// lis r12,-32146
	r12.s64 = -2106720256;
	// addi r12,r12,-10988
	r12.s64 = r12.s64 + -10988;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-10576(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -10576);
	// lwz r19,-10968(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -10968);
	// lwz r19,-10456(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -10456);
	// lwz r19,-10924(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -10924);
	// lwz r19,-10784(r13)
	r19.u64 = PPC_LOAD_U32(ctx.r13.u32 + -10784);
	// lfs f0,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 248);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// lfs f0,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826dd728
	if (!cr6.gt) goto loc_826DD728;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826dc708
	ctx.lr = 0x826DD550;
	sub_826DC708(ctx, base);
	// b 0x826dd728
	goto loc_826DD728;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dd728
	if (cr6.eq) goto loc_826DD728;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lfs f0,7588(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7588);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// lwz r8,18(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// beq cr6,0x826dd5c8
	if (cr6.eq) goto loc_826DD5C8;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148c60
	ctx.lr = 0x826DD5C4;
	sub_82148C60(ctx, base);
	// b 0x826dd728
	goto loc_826DD728;
loc_826DD5C8:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82148c60
	ctx.lr = 0x826DD5DC;
	sub_82148C60(ctx, base);
	// b 0x826dd728
	goto loc_826DD728;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dd728
	if (cr6.eq) goto loc_826DD728;
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// lwz r7,42(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 42);
	// lfs f0,7592(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7592);
	f0.f64 = double(temp.f32);
	// lhz r6,52(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 52);
	// lhz r5,50(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 50);
	// extsh r10,r6
	ctx.r10.s64 = ctx.r6.s16;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fsubs f8,f13,f12
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// fsubs f3,f5,f7
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f7.f64));
	// fsel f2,f3,f5,f7
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f5.f64 : ctx.f7.f64;
	// fsubs f1,f2,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fsel f0,f1,f4,f2
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f4.f64 : ctx.f2.f64;
	// beq cr6,0x826dd698
	if (cr6.eq) goto loc_826DD698;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148c60
	ctx.lr = 0x826DD694;
	sub_82148C60(ctx, base);
	// b 0x826dd728
	goto loc_826DD728;
loc_826DD698:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82148c60
	ctx.lr = 0x826DD6AC;
	sub_82148C60(ctx, base);
	// b 0x826dd728
	goto loc_826DD728;
	// lfs f0,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// blt cr6,0x826dd728
	if (cr6.lt) goto loc_826DD728;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// stw r27,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r27.u32);
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dd6e0
	if (cr6.eq) goto loc_826DD6E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DD6E0;
	sub_8213C218(ctx, base);
loc_826DD6E0:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lfs f13,232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7588(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 7588);
	f0.f64 = double(temp.f32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f9,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f9.u32);
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// bl 0x825491f0
	ctx.lr = 0x826DD720;
	sub_825491F0(ctx, base);
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r26,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r26.u32);
loc_826DD728:
	// lfs f0,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f13,252(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-80(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826DD2E8) {
	__imp__sub_826DD2E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DD748) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DD750;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// lfs f0,212(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 212);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 216);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,7864(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7864);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// ble cr6,0x826dd818
	if (!cr6.gt) goto loc_826DD818;
	// lwz r11,448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// li r29,0
	r29.s64 = 0;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826dd818
	if (!cr6.gt) goto loc_826DD818;
	// li r30,0
	r30.s64 = 0;
loc_826DD7B0:
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD7C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r9,r30,r3
	ctx.r9.u64 = r30.u64 + ctx.r3.u64;
	// lbz r8,696(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 696);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826dd7fc
	if (cr6.eq) goto loc_826DD7FC;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD7E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// add r9,r30,r3
	ctx.r9.u64 = r30.u64 + ctx.r3.u64;
	// lfs f0,692(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 692);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826dd7fc
	if (!cr6.gt) goto loc_826DD7FC;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_826DD7FC:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x826dd7b0
	if (cr6.lt) goto loc_826DD7B0;
loc_826DD818:
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x826e5950
	ctx.lr = 0x826DD820;
	sub_826E5950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826dd860
	if (!cr6.eq) goto loc_826DD860;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f0,7600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7600);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x826dd860
	if (cr6.gt) goto loc_826DD860;
	// lwz r3,204(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826dd938
	if (cr6.eq) goto loc_826DD938;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DD850;
	sub_8213C218(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_826DD860:
	// lwz r10,220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// addi r5,r31,204
	ctx.r5.s64 = r31.s64 + 204;
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lhz r9,86(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 86);
	// lhz r8,88(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 88);
	// stfs f30,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// extsw r3,r7
	ctx.r3.s64 = ctx.r7.s32;
	// subf r9,r7,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r7.s64;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// fmadds f8,f10,f31,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f9.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f7,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f7.u32);
	// bne cr6,0x826dd8e4
	if (!cr6.eq) goto loc_826DD8E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,78(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 78);
	// bl 0x825491f0
	ctx.lr = 0x826DD8D4;
	sub_825491F0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_826DD8E4:
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x826dd930
	if (cr6.eq) goto loc_826DD930;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r7,r10,7216
	ctx.r7.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,200(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148c60
	ctx.lr = 0x826DD920;
	sub_82148C60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_826DD930:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82148c60
	ctx.lr = 0x826DD938;
	sub_82148C60(ctx, base);
loc_826DD938:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DD748) {
	__imp__sub_826DD748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DD948) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x826DD950;
	// stfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -144, f30.u64);
	// stfd f31,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,168(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826ddd14
	if (cr6.eq) goto loc_826DDD14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD984;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x826ddd14
	if (!cr6.eq) goto loc_826DDD14;
	// lwz r3,168(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + 168);
	// lwz r11,452(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 452);
	// lwz r31,432(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 432);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826ddd08
	if (cr6.eq) goto loc_826DDD08;
	// lbz r11,6(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bne cr6,0x826dd9b4
	if (!cr6.eq) goto loc_826DD9B4;
	// lwz r20,312(r31)
	r20.u64 = PPC_LOAD_U32(r31.u32 + 312);
	// b 0x826dd9c0
	goto loc_826DD9C0;
loc_826DD9B4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826ddd08
	if (!cr6.eq) goto loc_826DDD08;
	// mr r20,r31
	r20.u64 = r31.u64;
loc_826DD9C0:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x826ddd08
	if (cr6.eq) goto loc_826DDD08;
	// li r18,0
	r18.s64 = 0;
	// bl 0x82794ee8
	ctx.lr = 0x826DD9D0;
	sub_82794EE8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r3,32
	r29.s64 = ctx.r3.s64 + 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DD9E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,32
	ctx.r9.s64 = ctx.r3.s64 + 32;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f12,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f12,f8,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// blt cr6,0x826dda28
	if (cr6.lt) goto loc_826DDA28;
	// li r11,0
	r11.s64 = 0;
loc_826DDA28:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// clrlwi r19,r11,24
	r19.u64 = r11.u32 & 0xFF;
	// bl 0x822a8148
	ctx.lr = 0x826DDA34;
	sub_822A8148(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,7868(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7868);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// blt cr6,0x826dda64
	if (cr6.lt) goto loc_826DDA64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826DDA64:
	// lwz r11,168(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 168);
	// clrlwi r21,r10,24
	r21.u64 = ctx.r10.u32 & 0xFF;
	// lfs f13,212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 212);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f11,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 216);
	ctx.f10.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fmadds f9,f11,f11,f12
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f8,f10,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// blt cr6,0x826dda94
	if (cr6.lt) goto loc_826DDA94;
	// li r11,0
	r11.s64 = 0;
loc_826DDA94:
	// lwz r28,640(r20)
	r28.u64 = PPC_LOAD_U32(r20.u32 + 640);
	// clrlwi r25,r11,24
	r25.u64 = r11.u32 & 0xFF;
	// li r23,0
	r23.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ddc24
	if (cr6.eq) goto loc_826DDC24;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826ddad0
	if (cr6.eq) goto loc_826DDAD0;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826ddad4
	if (cr6.eq) goto loc_826DDAD4;
loc_826DDAD0:
	// li r11,0
	r11.s64 = 0;
loc_826DDAD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ddc24
	if (cr6.eq) goto loc_826DDC24;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82245340
	ctx.lr = 0x826DDAE8;
	sub_82245340(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ddc20
	if (cr6.eq) goto loc_826DDC20;
	// bl 0x822447b8
	ctx.lr = 0x826DDAF4;
	sub_822447B8(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x822a8148
	ctx.lr = 0x826DDB00;
	sub_822A8148(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f11,f30,f0
	ctx.f11.f64 = double(float(f30.f64 * f0.f64));
	// fmadds f9,f12,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f8,f11,f11
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f7,f10,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fcmpu cr6,f7,f8
	cr6.compare(ctx.f7.f64, ctx.f8.f64);
	// bge cr6,0x826ddb34
	if (!cr6.lt) goto loc_826DDB34;
	// li r23,1
	r23.s64 = 1;
loc_826DDB34:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DDB48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,32
	ctx.r9.s64 = ctx.r3.s64 + 32;
	// lfs f0,628(r20)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r20.u32 + 628);
	f0.f64 = double(temp.f32);
	// lfs f13,632(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,624(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 624);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bge cr6,0x826ddc24
	if (!cr6.lt) goto loc_826DDC24;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DDB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 28);
	// lwz r7,32(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r27,0
	r27.s64 = 0;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,56(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lhzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r7.u32);
	// rotlwi r10,r4,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lhz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ddc24
	if (cr6.eq) goto loc_826DDC24;
	// li r29,0
	r29.s64 = 0;
loc_826DDBC4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// beq cr6,0x826ddbe4
	if (cr6.eq) goto loc_826DDBE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x826DDBDC;
	sub_822452F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826ddbfc
	if (!cr6.eq) goto loc_826DDBFC;
loc_826DDBE4:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x826ddbc4
	if (cr6.lt) goto loc_826DDBC4;
	// b 0x826ddc24
	goto loc_826DDC24;
loc_826DDBFC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8273a178
	ctx.lr = 0x826DDC04;
	sub_8273A178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ddc18
	if (cr6.eq) goto loc_826DDC18;
	// li r26,1
	r26.s64 = 1;
	// b 0x826ddc24
	goto loc_826DDC24;
loc_826DDC18:
	// li r24,1
	r24.s64 = 1;
	// b 0x826ddc24
	goto loc_826DDC24;
loc_826DDC20:
	// li r22,1
	r22.s64 = 1;
loc_826DDC24:
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ddc34
	if (cr6.eq) goto loc_826DDC34;
	// li r18,1
	r18.s64 = 1;
loc_826DDC34:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ddc68
	if (cr6.eq) goto loc_826DDC68;
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ddc68
	if (cr6.eq) goto loc_826DDC68;
	// clrlwi r10,r26,24
	ctx.r10.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ddc64
	if (!cr6.eq) goto loc_826DDC64;
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ddc68
	if (!cr6.eq) goto loc_826DDC68;
loc_826DDC64:
	// li r18,1
	r18.s64 = 1;
loc_826DDC68:
	// clrlwi r10,r23,24
	ctx.r10.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ddc84
	if (cr6.eq) goto loc_826DDC84;
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826ddc84
	if (!cr6.eq) goto loc_826DDC84;
	// li r18,1
	r18.s64 = 1;
loc_826DDC84:
	// clrlwi r10,r22,24
	ctx.r10.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ddc9c
	if (cr6.eq) goto loc_826DDC9C;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r18,r10,1
	r18.u64 = ctx.r10.u64 ^ 1;
loc_826DDC9C:
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ddcf4
	if (cr6.eq) goto loc_826DDCF4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,256(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stfs f12,256(r17)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r17.u32 + 256, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x826ddd14
	if (cr6.lt) goto loc_826DDD14;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x822a5578
	ctx.lr = 0x826DDCD8;
	sub_822A5578(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f13,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7620(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7620);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826ddd14
	if (!cr6.lt) goto loc_826DDD14;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826dcde0
	ctx.lr = 0x826DDCF4;
	sub_826DCDE0(ctx, base);
loc_826DDCF4:
	// stfs f31,256(r17)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r17.u32 + 256, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-144(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
loc_826DDD08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,256(r17)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r17.u32 + 256, temp.u32);
loc_826DDD14:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-144(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// lfd f31,-136(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_826DD948) {
	__imp__sub_826DD948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDD24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DDD24) {
	__imp__sub_826DDD24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDD28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ddd7c
	if (cr6.eq) goto loc_826DDD7C;
	// bl 0x82794ee8
	ctx.lr = 0x826DDD4C;
	sub_82794EE8(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826DDD7C:
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

PPC_WEAK_FUNC(sub_826DDD28) {
	__imp__sub_826DDD28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDD90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826dddbc
	if (cr6.eq) goto loc_826DDDBC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// b 0x826dddf4
	goto loc_826DDDF4;
loc_826DDDBC:
	// lbz r11,500(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dddec
	if (cr6.eq) goto loc_826DDDEC;
	// lwz r11,52(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dddec
	if (cr6.eq) goto loc_826DDDEC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826dddec
	if (cr6.eq) goto loc_826DDDEC;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826dddf0
	goto loc_826DDDF0;
loc_826DDDEC:
	// addi r11,r4,112
	r11.s64 = ctx.r4.s64 + 112;
loc_826DDDF0:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_826DDDF4:
	// li r10,32
	ctx.r10.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DDD90) {
	__imp__sub_826DDD90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DDE0C) {
	__imp__sub_826DDE0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDE10) {
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
	ctx.lr = 0x826DDE18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,7660
	ctx.r10.s64 = r11.s64 + 7660;
	// lwz r30,228(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826dde4c
	if (cr6.eq) goto loc_826DDE4C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x826DDE44;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x826DDE4C;
	sub_82130588(ctx, base);
loc_826DDE4C:
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// bl 0x826dc490
	ctx.lr = 0x826DDE54;
	sub_826DC490(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826f8c58
	ctx.lr = 0x826DDE5C;
	sub_826F8C58(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dde74
	if (cr6.eq) goto loc_826DDE74;
	// bl 0x82130588
	ctx.lr = 0x826DDE70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826DDE74:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DDE10) {
	__imp__sub_826DDE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DDE7C) {
	__imp__sub_826DDE7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DDE80) {
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
	ctx.lr = 0x826DDE88;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r31,168(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826ddd90
	ctx.lr = 0x826DDEAC;
	sub_826DDD90(ctx, base);
	// lfs f0,212(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 212);
	f0.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,216(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f30,-13028(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13028);
	f30.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fmuls f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64));
	// stfs f5,232(r30)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r30.u32 + 232, temp.u32);
	// lfs f13,236(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 236);
	ctx.f13.f64 = double(temp.f32);
	// lfs f4,416(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 416);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f0,f4,f30
	f0.f64 = double(float(ctx.f4.f64 * f30.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826ddf14
	if (!cr6.lt) goto loc_826DDF14;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f31,f13,f12
	ctx.f11.f64 = double(float(f31.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f11,236(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 236, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x826ddf3c
	if (!cr6.gt) goto loc_826DDF3C;
	// b 0x826ddf38
	goto loc_826DDF38;
loc_826DDF14:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826ddf3c
	if (!cr6.gt) goto loc_826DDF3C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,236(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f11,f31,f13,f12
	ctx.f11.f64 = double(float(-(f31.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// stfs f11,236(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 236, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x826ddf3c
	if (!cr6.lt) goto loc_826DDF3C;
loc_826DDF38:
	// stfs f0,236(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 236, temp.u32);
loc_826DDF3C:
	// lwz r31,168(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826ddd90
	ctx.lr = 0x826DDF4C;
	sub_826DDD90(ctx, base);
	// lfs f0,228(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 228);
	f0.f64 = double(temp.f32);
	// lfs f10,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f13,232(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f8,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f11,232(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 232);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f6,f8,f13,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f5,f7,f12,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmuls f4,f5,f30
	ctx.f4.f64 = double(float(ctx.f5.f64 * f30.f64));
	// stfs f4,240(r30)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r30.u32 + 240, temp.u32);
	// lwz r10,70(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 70);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// blt cr6,0x826de208
	if (cr6.lt) goto loc_826DE208;
	// lhz r9,66(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 66);
	// lfs f13,412(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,62(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 62);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * f30.f64));
	// lhz r7,68(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 68);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// lhz r6,64(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 64);
	// extsh r4,r10
	ctx.r4.s64 = ctx.r10.s16;
	// lwz r3,70(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 70);
	// extsh r9,r7
	ctx.r9.s64 = ctx.r7.s16;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// subf r6,r5,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r5.s64;
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsh r4,r7
	ctx.r4.s64 = ctx.r7.s16;
	// lwz r8,74(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 74);
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// fcfid f2,f11
	ctx.f2.f64 = double(ctx.f11.s64);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// extsw r3,r6
	ctx.r3.s64 = ctx.r6.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f5,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// fsel f4,f9,f12,f0
	ctx.f4.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fcfid f12,f8
	ctx.f12.f64 = double(ctx.f8.s64);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// fcfid f11,f7
	ctx.f11.f64 = double(ctx.f7.s64);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// frsp f8,f2
	ctx.f8.f64 = double(float(ctx.f2.f64));
	// addi r29,r30,196
	r29.s64 = r30.s64 + 196;
	// fsubs f13,f5,f10
	ctx.f13.f64 = double(float(ctx.f5.f64 - ctx.f10.f64));
	// addi r28,r30,96
	r28.s64 = r30.s64 + 96;
	// fcfid f9,f6
	ctx.f9.f64 = double(ctx.f6.s64);
	// lfs f0,11360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	f0.f64 = double(temp.f32);
	// addi r31,r9,7216
	r31.s64 = ctx.r9.s64 + 7216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fsubs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// frsp f6,f12
	ctx.f6.f64 = double(float(ctx.f12.f64));
	// fsel f1,f3,f5,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f5.f64 : ctx.f4.f64;
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// frsp f5,f11
	ctx.f5.f64 = double(float(ctx.f11.f64));
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// fsubs f7,f1,f10
	ctx.f7.f64 = double(float(ctx.f1.f64 - ctx.f10.f64));
	// fmsubs f1,f6,f0,f3
	ctx.f1.f64 = double(float(ctx.f6.f64 * f0.f64 - ctx.f3.f64));
	// fdivs f2,f7,f13
	ctx.f2.f64 = double(float(ctx.f7.f64 / ctx.f13.f64));
	// fmadds f0,f5,f2,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f2.f64 + ctx.f4.f64));
	// fmadds f13,f1,f2,f3
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + ctx.f3.f64));
	// stfs f13,96(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// fctiwz f12,f0
	ctx.f12.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r12,100
	r12.s64 = 100;
	// stfiwx f12,r30,r12
	PPC_STORE_U32(r30.u32 + r12.u32, ctx.f12.u32);
	// bne cr6,0x826de09c
	if (!cr6.eq) goto loc_826DE09C;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,54(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825491f0
	ctx.lr = 0x826DE098;
	sub_825491F0(ctx, base);
	// b 0x826de118
	goto loc_826DE118;
loc_826DE09C:
	// lbz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// lwz r4,100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x826de0d0
	if (cr6.eq) goto loc_826DE0D0;
	// lbz r11,64(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x826de0d4
	goto loc_826DE0D4;
loc_826DE0D0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DE0D4:
	// bl 0x82148c60
	ctx.lr = 0x826DE0D8;
	sub_82148C60(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x826de110
	if (cr6.eq) goto loc_826DE110;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x826de114
	goto loc_826DE114;
loc_826DE110:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DE114:
	// bl 0x82148cb0
	ctx.lr = 0x826DE118;
	sub_82148CB0(ctx, base);
loc_826DE118:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-12288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12288);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,1044(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1044);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x826de21c
	if (cr6.eq) goto loc_826DE21C;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// addi r29,r30,200
	r29.s64 = r30.s64 + 200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826de16c
	if (!cr6.eq) goto loc_826DE16C;
	// lwz r11,220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 220);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,58(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// bl 0x825491f0
	ctx.lr = 0x826DE15C;
	sub_825491F0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826DE16C:
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lwz r4,100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x826de1a0
	if (cr6.eq) goto loc_826DE1A0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x826de1a4
	goto loc_826DE1A4;
loc_826DE1A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826DE1A4:
	// bl 0x82148c60
	ctx.lr = 0x826DE1A8;
	sub_82148C60(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x826de1f0
	if (cr6.eq) goto loc_826DE1F0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82148cb0
	ctx.lr = 0x826DE1E0;
	sub_82148CB0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826DE1F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82148cb0
	ctx.lr = 0x826DE1F8;
	sub_82148CB0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_826DE208:
	// lwz r3,196(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826de21c
	if (cr6.eq) goto loc_826DE21C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DE21C;
	sub_8213C218(ctx, base);
loc_826DE21C:
	// lwz r3,200(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826de230
	if (cr6.eq) goto loc_826DE230;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DE230;
	sub_8213C218(ctx, base);
loc_826DE230:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DDE80) {
	__imp__sub_826DDE80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE240) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826DE248;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x826f9258
	ctx.lr = 0x826DE264;
	sub_826F9258(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// beq cr6,0x826de46c
	if (cr6.eq) goto loc_826DE46C;
	// lfs f0,244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,244(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826de320
	if (cr6.eq) goto loc_826DE320;
	// lbz r11,284(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 284);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826de2c4
	if (!cr6.eq) goto loc_826DE2C4;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826de2c4
	if (cr6.eq) goto loc_826DE2C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DE2B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826de320
	if (cr6.eq) goto loc_826DE320;
loc_826DE2C4:
	// lwz r11,280(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 280);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826de320
	if (cr6.eq) goto loc_826DE320;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 252);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x826de320
	if (cr6.lt) goto loc_826DE320;
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r30,0
	r30.s64 = 0;
	// stfs f31,96(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// beq cr6,0x826de304
	if (cr6.eq) goto loc_826DE304;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DE304;
	sub_8213C218(ctx, base);
loc_826DE304:
	// lwz r3,196(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826de318
	if (cr6.eq) goto loc_826DE318;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826DE318;
	sub_8213C218(ctx, base);
loc_826DE318:
	// stfs f31,252(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stw r30,280(r31)
	PPC_STORE_U32(r31.u32 + 280, r30.u32);
loc_826DE320:
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826de370
	if (cr6.eq) goto loc_826DE370;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lfs f13,276(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,244(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,7872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7872);
	f0.f64 = double(temp.f32);
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x826de35c
	if (!cr6.gt) goto loc_826DE35C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826de370
	if (!cr6.eq) goto loc_826DE370;
	// bl 0x821f6c50
	ctx.lr = 0x826DE358;
	sub_821F6C50(ctx, base);
	// b 0x826de370
	goto loc_826DE370;
loc_826DE35C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826de370
	if (cr6.eq) goto loc_826DE370;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f7208
	ctx.lr = 0x826DE370;
	sub_821F7208(ctx, base);
loc_826DE370:
	// lwz r30,168(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826ddd90
	ctx.lr = 0x826DE380;
	sub_826DDD90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,212(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 212);
	f0.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,216(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f12,208(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,-13028(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13028);
	f31.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fmuls f5,f6,f31
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f5,232(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// bl 0x826ddd90
	ctx.lr = 0x826DE3C4;
	sub_826DDD90(ctx, base);
	// lfs f4,228(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 228);
	ctx.f4.f64 = double(temp.f32);
	// lfs f1,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lbz r9,284(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 284);
	// fmuls f0,f1,f4
	f0.f64 = double(float(ctx.f1.f64 * ctx.f4.f64));
	// lfs f3,232(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 232);
	ctx.f3.f64 = double(temp.f32);
	// lfs f13,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f2,224(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 224);
	ctx.f2.f64 = double(temp.f32);
	// lfs f12,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f13,f3,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f3.f64 + f0.f64));
	// fmadds f10,f12,f2,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f2.f64 + ctx.f11.f64));
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// stfs f9,240(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// lfs f8,416(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 416);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64));
	// stfs f7,236(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// bne cr6,0x826de448
	if (!cr6.eq) goto loc_826DE448;
	// lwz r3,452(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826de43c
	if (cr6.eq) goto loc_826DE43C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DE424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826de43c
	if (!cr6.eq) goto loc_826DE43C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x826dd2e8
	ctx.lr = 0x826DE43C;
	sub_826DD2E8(ctx, base);
loc_826DE43C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x826dde80
	ctx.lr = 0x826DE448;
	sub_826DDE80(ctx, base);
loc_826DE448:
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x82381f50
	ctx.lr = 0x826DE450;
	sub_82381F50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826dd748
	ctx.lr = 0x826DE458;
	sub_826DD748(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826dd948
	ctx.lr = 0x826DE464;
	sub_826DD948(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,284(r31)
	PPC_STORE_U8(r31.u32 + 284, r11.u8);
loc_826DE46C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DE240) {
	__imp__sub_826DE240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DE47C) {
	__imp__sub_826DE47C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE480) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x826de4d0
	if (cr6.eq) goto loc_826DE4D0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// addi r6,r10,7216
	ctx.r6.s64 = ctx.r10.s64 + 7216;
	// mulli r7,r9,11488
	ctx.r7.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r10,200(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 200);
	// add r4,r7,r9
	ctx.r4.u64 = ctx.r7.u64 + ctx.r9.u64;
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11444(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 11444);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// b 0x826de4d4
	goto loc_826DE4D4;
loc_826DE4D0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_826DE4D4:
	// lwz r10,172(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de4f0
	if (cr6.eq) goto loc_826DE4F0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,228(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// bl 0x82383688
	ctx.lr = 0x826DE4EC;
	sub_82383688(ctx, base);
	// b 0x826de4fc
	goto loc_826DE4FC;
loc_826DE4F0:
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213b860
	ctx.lr = 0x826DE4FC;
	sub_8213B860(ctx, base);
loc_826DE4FC:
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// stfs f0,276(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
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

PPC_WEAK_FUNC(sub_826DE480) {
	__imp__sub_826DE480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE518) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,25,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,27,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,28,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,29,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// rlwinm r6,r7,0,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826de5d4
	if (!cr6.eq) goto loc_826DE5D4;
	// xor r11,r10,r11
	r11.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de5d8
	if (cr6.eq) goto loc_826DE5D8;
loc_826DE5D4:
	// li r11,0
	r11.s64 = 0;
loc_826DE5D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DE518) {
	__imp__sub_826DE518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE5E0) {
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
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de628
	if (cr6.eq) goto loc_826DE628;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x8224f790
	ctx.lr = 0x826DE614;
	sub_8224F790(ctx, base);
	// lwz r11,788(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826de628
	if (cr6.eq) goto loc_826DE628;
	// lwz r11,476(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// stw r11,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r11.u32);
loc_826DE628:
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de658
	if (cr6.eq) goto loc_826DE658;
	// lwz r4,272(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826de658
	if (cr6.eq) goto loc_826DE658;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826d6b80
	ctx.lr = 0x826DE64C;
	sub_826D6B80(ctx, base);
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// lwz r3,448(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// bl 0x826e39e8
	ctx.lr = 0x826DE658;
	sub_826E39E8(ctx, base);
loc_826DE658:
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

PPC_WEAK_FUNC(sub_826DE5E0) {
	__imp__sub_826DE5E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE670) {
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
	ctx.lr = 0x826DE678;
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826de728
	if (!cr6.eq) goto loc_826DE728;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de728
	if (cr6.eq) goto loc_826DE728;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826de728
	if (!cr6.eq) goto loc_826DE728;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x826e39b0
	ctx.lr = 0x826DE6BC;
	sub_826E39B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826de728
	if (cr6.eq) goto loc_826DE728;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r28,108(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 108);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DE6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x826d6b48
	ctx.lr = 0x826DE6F0;
	sub_826D6B48(ctx, base);
	// stw r3,788(r31)
	PPC_STORE_U32(r31.u32 + 788, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826de720
	if (cr6.eq) goto loc_826DE720;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r11,448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 448, r11.u32);
	// lhz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 256);
	// sth r10,784(r31)
	PPC_STORE_U16(r31.u32 + 784, ctx.r10.u16);
	// lbz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stb r8,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826DE720:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x826e39e8
	ctx.lr = 0x826DE728;
	sub_826E39E8(ctx, base);
loc_826DE728:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826DE670) {
	__imp__sub_826DE670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE730) {
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
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826de7dc
	if (!cr6.eq) goto loc_826DE7DC;
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de7dc
	if (cr6.eq) goto loc_826DE7DC;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de7a0
	if (cr6.eq) goto loc_826DE7A0;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826de7a0
	if (!cr6.eq) goto loc_826DE7A0;
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// stw r11,788(r31)
	PPC_STORE_U32(r31.u32 + 788, r11.u32);
	// lbz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// ori r9,r10,64
	ctx.r9.u64 = ctx.r10.u64 | 64;
	// stb r9,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r9.u8);
	// b 0x826de7dc
	goto loc_826DE7DC;
loc_826DE7A0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,288(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// bl 0x826d62e0
	ctx.lr = 0x826DE7AC;
	sub_826D62E0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826de7dc
	if (cr6.eq) goto loc_826DE7DC;
	// lbz r11,500(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 500);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826de7dc
	if (cr6.eq) goto loc_826DE7DC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,276(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// bl 0x826d50e8
	ctx.lr = 0x826DE7D4;
	sub_826D50E8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_826DE7DC:
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

PPC_WEAK_FUNC(sub_826DE730) {
	__imp__sub_826DE730(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE7F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DE7F4) {
	__imp__sub_826DE7F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DE7F8) {
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
	ctx.lr = 0x826DE800;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826deaf0
	if (!cr6.eq) goto loc_826DEAF0;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826deaf0
	if (cr6.eq) goto loc_826DEAF0;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826deaf0
	if (!cr6.eq) goto loc_826DEAF0;
	// lwz r11,244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826de88c
	if (cr6.eq) goto loc_826DE88C;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// addi r10,r31,544
	ctx.r10.s64 = r31.s64 + 544;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826DE88C:
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826de9d4
	if (cr6.eq) goto loc_826DE9D4;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfs f1,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f1.f64 = double(temp.f32);
	// addi r30,r31,544
	r30.s64 = r31.s64 + 544;
	// addi r6,r31,576
	ctx.r6.s64 = r31.s64 + 576;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826DE8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stvx128 v58,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r3,2240
	ctx.r9.s64 = ctx.r3.s64 + 2240;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v56,v59,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v54,v55,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,-31648
	ctx.r8.s64 = ctx.r10.s64 + -31648;
	// addi r4,r5,-31664
	ctx.r4.s64 = ctx.r5.s64 + -31664;
	// vrsqrtefp128 v53,v54
	simde_mm_store_ps(v53.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v54.f32))));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v10,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r10,r30,16
	ctx.r10.s64 = r30.s64 + 16;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,-31616
	ctx.r5.s64 = ctx.r7.s64 + -31616;
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v12,v53,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v11,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vsel v0,v11,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v10,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v52,v55,v6
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v52,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v50,v63,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vpermwi128 v49,v51,135
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x78));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v48,v50,99
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x9C));
	// vpermwi128 v4,v51,99
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x9C));
	// vpermwi128 v3,v50,135
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x78));
	// vmulfp128 v5,v49,v48
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)));
	// vnmsubfp v0,v4,v3,v5
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v5.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v47,v0,v0
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// stvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v46,v47
	simde_mm_store_ps(v46.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v47.f32))));
	// vor128 v1,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vcmpeqfp128 v31,v46,v62
	simde_mm_store_ps(v31.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v30,v46,v46
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vsel v13,v30,v2,v31
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)v30.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8))));
	// vmulfp128 v29,v13,v13
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v28,v63,v13
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v27,v1,v29,v12
	simde_mm_store_ps(v27.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v26,v27,v28,v13
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v27.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v45,v0,v26
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v26.f32)));
	// stvx128 v45,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826DE9D4:
	// li r8,64
	ctx.r8.s64 = 64;
	// vspltisw128 v44,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,544
	r11.s64 = r31.s64 + 544;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r10,r11,32
	ctx.r10.s64 = r11.s64 + 32;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v43,r31,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stvx128 v43,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lvx128 v42,r31,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v41,v44,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v42.f32)));
	// stvx128 v41,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// addi r6,r8,-31648
	ctx.r6.s64 = ctx.r8.s64 + -31648;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r5,-31616
	ctx.r8.s64 = ctx.r5.s64 + -31616;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// lvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v39,v40,v40
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v40.f32), 0xEF));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v38,v39
	simde_mm_store_ps(v38.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v39.f32))));
	// vor128 v12,v39,v39
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v39.u8));
	// vcmpeqfp128 v11,v38,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v38,v38
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
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
	// vmulfp128 v37,v40,v6
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v37,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v36,v37,v37
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v35,v63,v63
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vpermwi128 v34,v36,135
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0x78));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v33,v35,99
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x9C));
	// vpermwi128 v5,v36,99
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), 0x9C));
	// vpermwi128 v4,v35,135
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0x78));
	// vmulfp128 v3,v34,v33
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v33.f32)));
	// vnmsubfp v0,v5,v4,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v32,v0,v0
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r0,r7
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v60,v32
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v32.f32))));
	// vor128 v2,v32,v32
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v32.u8));
	// vcmpeqfp128 v1,v60,v62
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v31,v60,v60
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsel v13,v31,v30,v1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v31.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v30.u8))));
	// vmulfp128 v29,v13,v13
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v28,v61,v13
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v27,v2,v29,v12
	simde_mm_store_ps(v27.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v26,v27,v28,v13
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v27.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v59,v0,v26
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v26.f32)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// ori r10,r11,4
	ctx.r10.u64 = r11.u64 | 4;
	// stb r10,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r10.u8);
loc_826DEAF0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DE7F8) {
	__imp__sub_826DE7F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEAF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r11,r3,544
	r11.s64 = ctx.r3.s64 + 544;
	// li r9,48
	ctx.r9.s64 = 48;
	// ori r7,r10,8
	ctx.r7.u64 = ctx.r10.u64 | 8;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// stb r7,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r7.u8);
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,32
	ctx.r10.s64 = r11.s64 + 32;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2240
	ctx.r4.s64 = ctx.r6.s64 + 2240;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stfs f0,580(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 580, temp.u32);
	// addi r7,r9,-31664
	ctx.r7.s64 = ctx.r9.s64 + -31664;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r5,-31648
	ctx.r8.s64 = ctx.r5.s64 + -31648;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v58,v59,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v12,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lvx128 v9,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// addi r5,r3,-31616
	ctx.r5.s64 = ctx.r3.s64 + -31616;
	// vcmpeqfp128 v11,v57,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v10,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v63,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v12,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v59,v5
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vpermwi128 v53,v55,135
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x78));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v52,v54,99
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x9C));
	// vpermwi128 v3,v55,99
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x9C));
	// vpermwi128 v2,v54,135
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x78));
	// vmulfp128 v4,v53,v52
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	// vnmsubfp v0,v3,v2,v4
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v4.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v51,v0,v0
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v50,v51
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v51.f32))));
	// vor128 v31,v51,v51
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vcmpeqfp128 v30,v50,v62
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v29,v50,v50
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
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
	// vmulfp128 v49,v0,v25
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v25.f32)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEAF8) {
	__imp__sub_826DEAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEC44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DEC44) {
	__imp__sub_826DEC44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEC48) {
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
	ctx.lr = 0x826DEC50;
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
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826ded0c
	if (!cr6.eq) goto loc_826DED0C;
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826decbc
	if (cr6.eq) goto loc_826DECBC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826de518
	ctx.lr = 0x826DEC88;
	sub_826DE518(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826decbc
	if (cr6.eq) goto loc_826DECBC;
	// lwz r4,788(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 788);
	// addi r5,r31,544
	ctx.r5.s64 = r31.s64 + 544;
	// lwz r3,448(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 448);
	// bl 0x826e3a08
	ctx.lr = 0x826DECA4;
	sub_826E3A08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,30,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r8,r11,5
	ctx.r8.s64 = r11.s64 + 5;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
loc_826DECBC:
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ded0c
	if (cr6.eq) goto loc_826DED0C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826de518
	ctx.lr = 0x826DECD8;
	sub_826DE518(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ded0c
	if (cr6.eq) goto loc_826DED0C;
	// lwz r4,788(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 788);
	// addi r5,r31,544
	ctx.r5.s64 = r31.s64 + 544;
	// lwz r3,448(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 448);
	// bl 0x826e3a48
	ctx.lr = 0x826DECF4;
	sub_826E3A48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,30,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// addi r8,r11,5
	ctx.r8.s64 = r11.s64 + 5;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
loc_826DED0C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826DEC48) {
	__imp__sub_826DEC48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DED14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DED14) {
	__imp__sub_826DED14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DED18) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826ded94
	if (!cr6.eq) goto loc_826DED94;
	// lbz r11,300(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 300);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826ded94
	if (cr6.eq) goto loc_826DED94;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// bl 0x826de518
	ctx.lr = 0x826DED54;
	sub_826DE518(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ded94
	if (cr6.eq) goto loc_826DED94;
	// lwz r11,272(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ded94
	if (cr6.eq) goto loc_826DED94;
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,500(r11)
	PPC_STORE_U8(r11.u32 + 500, ctx.r9.u8);
	// lwz r8,272(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 272);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// lwz r5,276(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 276);
	// lwz r3,448(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 448);
	// bl 0x826e3a88
	ctx.lr = 0x826DED8C;
	sub_826E3A88(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
loc_826DED94:
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

PPC_WEAK_FUNC(sub_826DED18) {
	__imp__sub_826DED18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEDA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,272(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 272);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826dedd0
	if (cr6.eq) goto loc_826DEDD0;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bne cr6,0x826dedd0
	if (!cr6.eq) goto loc_826DEDD0;
	// stw r10,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r10.u32);
loc_826DEDD0:
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x826dede0
	if (!cr6.eq) goto loc_826DEDE0;
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
loc_826DEDE0:
	// lwz r11,804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 804);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r10,804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 804, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEDA8) {
	__imp__sub_826DEDA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DEDF4) {
	__imp__sub_826DEDF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,244(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 244);
	// li r11,0
	r11.s64 = 0;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bne cr6,0x826dee18
	if (!cr6.eq) goto loc_826DEE18;
	// stw r11,244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 244, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
loc_826DEE18:
	// lwz r10,772(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 772);
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r11,772(r3)
	PPC_STORE_U32(ctx.r3.u32 + 772, r11.u32);
	// stw r11,800(r3)
	PPC_STORE_U32(ctx.r3.u32 + 800, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEDF8) {
	__imp__sub_826DEDF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEE30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x826dee40
	if (!cr6.eq) goto loc_826DEE40;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826DEE40:
	// lwz r11,280(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 280);
	// subf r10,r11,r4
	ctx.r10.s64 = ctx.r4.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEE30) {
	__imp__sub_826DEE30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DEE54) {
	__imp__sub_826DEE54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,300(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 300);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826dee94
	if (cr6.eq) goto loc_826DEE94;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,788(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 788);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,140(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_826DEE94:
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,272(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 272);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_826DEE58) {
	__imp__sub_826DEE58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEEC0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEEC0) {
	__imp__sub_826DEEC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEEC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DEEC4) {
	__imp__sub_826DEEC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEEC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,300(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 300);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826deeec
	if (cr6.eq) goto loc_826DEEEC;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addi r3,r10,8516
	ctx.r3.s64 = ctx.r10.s64 + 8516;
	// b 0x826f03f0
	sub_826F03F0(ctx, base);
	return;
loc_826DEEEC:
	// rlwinm r9,r11,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826def08
	if (cr6.eq) goto loc_826DEF08;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addi r3,r10,8516
	ctx.r3.s64 = ctx.r10.s64 + 8516;
	// b 0x826f0498
	sub_826F0498(ctx, base);
	return;
loc_826DEF08:
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826def24
	if (cr6.eq) goto loc_826DEF24;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addi r3,r10,8516
	ctx.r3.s64 = ctx.r10.s64 + 8516;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_826DEF24:
	// rlwinm r11,r11,0,27,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addi r3,r10,8516
	ctx.r3.s64 = ctx.r10.s64 + 8516;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DEEC8) {
	__imp__sub_826DEEC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEF40) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826DEF40) {
	__imp__sub_826DEF40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826DEF44) {
	__imp__sub_826DEF44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826DEF48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lbz r9,300(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 300);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826def84
	if (cr6.eq) goto loc_826DEF84;
	// mulli r11,r11,5936
	r11.s64 = r11.s64 * 5936;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,29296
	ctx.r3.s64 = ctx.r3.s64 + 29296;
	// b 0x826f6330
	sub_826F6330(ctx, base);
	return;
loc_826DEF84:
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826defac
	if (cr6.eq) goto loc_826DEFAC;
	// mulli r11,r11,5936
	r11.s64 = r11.s64 * 5936;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,29296
	ctx.r3.s64 = ctx.r3.s64 + 29296;
	// b 0x826f6460
	sub_826F6460(ctx, base);
	return;
loc_826DEFAC:
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826defd4
	if (cr6.eq) goto loc_826DEFD4;
	// mulli r11,r11,5936
	r11.s64 = r11.s64 * 5936;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,29296
	ctx.r3.s64 = ctx.r3.s64 + 29296;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_826DEFD4:
	// rlwinm r9,r9,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mulli r11,r11,5936
	r11.s64 = r11.s64 * 5936;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r3,544
	ctx.r5.s64 = ctx.r3.s64 + 544;
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,29296
	ctx.r3.s64 = ctx.r3.s64 + 29296;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826DEF48) {
	__imp__sub_826DEF48(ctx, base);
}

