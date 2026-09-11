#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82679790"))) PPC_WEAK_FUNC(sub_82679790);
PPC_FUNC_IMPL(__imp__sub_82679790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,132(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797A0"))) PPC_WEAK_FUNC(sub_826797A0);
PPC_FUNC_IMPL(__imp__sub_826797A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,124(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797B0"))) PPC_WEAK_FUNC(sub_826797B0);
PPC_FUNC_IMPL(__imp__sub_826797B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,120(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797C0"))) PPC_WEAK_FUNC(sub_826797C0);
PPC_FUNC_IMPL(__imp__sub_826797C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,144(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797D0"))) PPC_WEAK_FUNC(sub_826797D0);
PPC_FUNC_IMPL(__imp__sub_826797D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,148(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797E0"))) PPC_WEAK_FUNC(sub_826797E0);
PPC_FUNC_IMPL(__imp__sub_826797E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,140(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 140);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826797F0"))) PPC_WEAK_FUNC(sub_826797F0);
PPC_FUNC_IMPL(__imp__sub_826797F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,136(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679800"))) PPC_WEAK_FUNC(sub_82679800);
PPC_FUNC_IMPL(__imp__sub_82679800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82679810"))) PPC_WEAK_FUNC(sub_82679810);
PPC_FUNC_IMPL(__imp__sub_82679810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82679820"))) PPC_WEAK_FUNC(sub_82679820);
PPC_FUNC_IMPL(__imp__sub_82679820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,84(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679830"))) PPC_WEAK_FUNC(sub_82679830);
PPC_FUNC_IMPL(__imp__sub_82679830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,80(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679840"))) PPC_WEAK_FUNC(sub_82679840);
PPC_FUNC_IMPL(__imp__sub_82679840) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267984C"))) PPC_WEAK_FUNC(sub_8267984C);
PPC_FUNC_IMPL(__imp__sub_8267984C) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// li r3,6
	ctx.r3.s64 = 6;
	// slw r4,r11,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x20 ? 0 : (r11.u32 << (ctx.r4.u8 & 0x3F));
	// cmpwi cr6,r4,256
	cr6.compare<int32_t>(ctx.r4.s32, 256, xer);
	// bgt cr6,0x82679b14
	if (cr6.gt) {
		sub_82679B14(ctx, base);
		return;
	}
	// beq cr6,0x82679b04
	if (cr6.eq) {
		sub_82679B04(ctx, base);
		return;
	}
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cmplwi cr6,r11,127
	cr6.compare<uint32_t>(r11.u32, 127, xer);
	// bgt cr6,0x82679bc4
	if (cr6.gt) {
		// ERROR 82679BC4
		return;
	}
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-26492
	r12.s64 = r12.s64 + -26492;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		// ERROR: 0x82679A84
		return;
	case 1:
		// ERROR: 0x82679A94
		return;
	case 2:
		// ERROR: 0x82679BC4
		return;
	case 3:
		// ERROR: 0x82679AA4
		return;
	case 4:
		// ERROR: 0x82679BC4
		return;
	case 5:
		// ERROR: 0x82679BC4
		return;
	case 6:
		// ERROR: 0x82679BC4
		return;
	case 7:
		// ERROR: 0x82679AB4
		return;
	case 8:
		// ERROR: 0x82679BC4
		return;
	case 9:
		// ERROR: 0x82679BC4
		return;
	case 10:
		// ERROR: 0x82679BC4
		return;
	case 11:
		// ERROR: 0x82679BC4
		return;
	case 12:
		// ERROR: 0x82679BC4
		return;
	case 13:
		// ERROR: 0x82679BC4
		return;
	case 14:
		// ERROR: 0x82679BC4
		return;
	case 15:
		// ERROR: 0x82679AC4
		return;
	case 16:
		// ERROR: 0x82679BC4
		return;
	case 17:
		// ERROR: 0x82679BC4
		return;
	case 18:
		// ERROR: 0x82679BC4
		return;
	case 19:
		// ERROR: 0x82679BC4
		return;
	case 20:
		// ERROR: 0x82679BC4
		return;
	case 21:
		// ERROR: 0x82679BC4
		return;
	case 22:
		// ERROR: 0x82679BC4
		return;
	case 23:
		// ERROR: 0x82679BC4
		return;
	case 24:
		// ERROR: 0x82679BC4
		return;
	case 25:
		// ERROR: 0x82679BC4
		return;
	case 26:
		// ERROR: 0x82679BC4
		return;
	case 27:
		// ERROR: 0x82679BC4
		return;
	case 28:
		// ERROR: 0x82679BC4
		return;
	case 29:
		// ERROR: 0x82679BC4
		return;
	case 30:
		// ERROR: 0x82679BC4
		return;
	case 31:
		// ERROR: 0x82679AD4
		return;
	case 32:
		// ERROR: 0x82679BC4
		return;
	case 33:
		// ERROR: 0x82679BC4
		return;
	case 34:
		// ERROR: 0x82679BC4
		return;
	case 35:
		// ERROR: 0x82679BC4
		return;
	case 36:
		// ERROR: 0x82679BC4
		return;
	case 37:
		// ERROR: 0x82679BC4
		return;
	case 38:
		// ERROR: 0x82679BC4
		return;
	case 39:
		// ERROR: 0x82679BC4
		return;
	case 40:
		// ERROR: 0x82679BC4
		return;
	case 41:
		// ERROR: 0x82679BC4
		return;
	case 42:
		// ERROR: 0x82679BC4
		return;
	case 43:
		// ERROR: 0x82679BC4
		return;
	case 44:
		// ERROR: 0x82679BC4
		return;
	case 45:
		// ERROR: 0x82679BC4
		return;
	case 46:
		// ERROR: 0x82679BC4
		return;
	case 47:
		// ERROR: 0x82679BC4
		return;
	case 48:
		// ERROR: 0x82679BC4
		return;
	case 49:
		// ERROR: 0x82679BC4
		return;
	case 50:
		// ERROR: 0x82679BC4
		return;
	case 51:
		// ERROR: 0x82679BC4
		return;
	case 52:
		// ERROR: 0x82679BC4
		return;
	case 53:
		// ERROR: 0x82679BC4
		return;
	case 54:
		// ERROR: 0x82679BC4
		return;
	case 55:
		// ERROR: 0x82679BC4
		return;
	case 56:
		// ERROR: 0x82679BC4
		return;
	case 57:
		// ERROR: 0x82679BC4
		return;
	case 58:
		// ERROR: 0x82679BC4
		return;
	case 59:
		// ERROR: 0x82679BC4
		return;
	case 60:
		// ERROR: 0x82679BC4
		return;
	case 61:
		// ERROR: 0x82679BC4
		return;
	case 62:
		// ERROR: 0x82679BC4
		return;
	case 63:
		// ERROR: 0x82679AE4
		return;
	case 64:
		// ERROR: 0x82679BC4
		return;
	case 65:
		// ERROR: 0x82679BC4
		return;
	case 66:
		// ERROR: 0x82679BC4
		return;
	case 67:
		// ERROR: 0x82679BC4
		return;
	case 68:
		// ERROR: 0x82679BC4
		return;
	case 69:
		// ERROR: 0x82679BC4
		return;
	case 70:
		// ERROR: 0x82679BC4
		return;
	case 71:
		// ERROR: 0x82679BC4
		return;
	case 72:
		// ERROR: 0x82679BC4
		return;
	case 73:
		// ERROR: 0x82679BC4
		return;
	case 74:
		// ERROR: 0x82679BC4
		return;
	case 75:
		// ERROR: 0x82679BC4
		return;
	case 76:
		// ERROR: 0x82679BC4
		return;
	case 77:
		// ERROR: 0x82679BC4
		return;
	case 78:
		// ERROR: 0x82679BC4
		return;
	case 79:
		// ERROR: 0x82679BC4
		return;
	case 80:
		// ERROR: 0x82679BC4
		return;
	case 81:
		// ERROR: 0x82679BC4
		return;
	case 82:
		// ERROR: 0x82679BC4
		return;
	case 83:
		// ERROR: 0x82679BC4
		return;
	case 84:
		// ERROR: 0x82679BC4
		return;
	case 85:
		// ERROR: 0x82679BC4
		return;
	case 86:
		// ERROR: 0x82679BC4
		return;
	case 87:
		// ERROR: 0x82679BC4
		return;
	case 88:
		// ERROR: 0x82679BC4
		return;
	case 89:
		// ERROR: 0x82679BC4
		return;
	case 90:
		// ERROR: 0x82679BC4
		return;
	case 91:
		// ERROR: 0x82679BC4
		return;
	case 92:
		// ERROR: 0x82679BC4
		return;
	case 93:
		// ERROR: 0x82679BC4
		return;
	case 94:
		// ERROR: 0x82679BC4
		return;
	case 95:
		// ERROR: 0x82679BC4
		return;
	case 96:
		// ERROR: 0x82679BC4
		return;
	case 97:
		// ERROR: 0x82679BC4
		return;
	case 98:
		// ERROR: 0x82679BC4
		return;
	case 99:
		// ERROR: 0x82679BC4
		return;
	case 100:
		// ERROR: 0x82679BC4
		return;
	case 101:
		// ERROR: 0x82679BC4
		return;
	case 102:
		// ERROR: 0x82679BC4
		return;
	case 103:
		// ERROR: 0x82679BC4
		return;
	case 104:
		// ERROR: 0x82679BC4
		return;
	case 105:
		// ERROR: 0x82679BC4
		return;
	case 106:
		// ERROR: 0x82679BC4
		return;
	case 107:
		// ERROR: 0x82679BC4
		return;
	case 108:
		// ERROR: 0x82679BC4
		return;
	case 109:
		// ERROR: 0x82679BC4
		return;
	case 110:
		// ERROR: 0x82679BC4
		return;
	case 111:
		// ERROR: 0x82679BC4
		return;
	case 112:
		// ERROR: 0x82679BC4
		return;
	case 113:
		// ERROR: 0x82679BC4
		return;
	case 114:
		// ERROR: 0x82679BC4
		return;
	case 115:
		// ERROR: 0x82679BC4
		return;
	case 116:
		// ERROR: 0x82679BC4
		return;
	case 117:
		// ERROR: 0x82679BC4
		return;
	case 118:
		// ERROR: 0x82679BC4
		return;
	case 119:
		// ERROR: 0x82679BC4
		return;
	case 120:
		// ERROR: 0x82679BC4
		return;
	case 121:
		// ERROR: 0x82679BC4
		return;
	case 122:
		// ERROR: 0x82679BC4
		return;
	case 123:
		// ERROR: 0x82679BC4
		return;
	case 124:
		// ERROR: 0x82679BC4
		return;
	case 125:
		// ERROR: 0x82679BC4
		return;
	case 126:
		// ERROR: 0x82679BC4
		return;
	case 127:
		// ERROR: 0x82679AF4
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_82679884"))) PPC_WEAK_FUNC(sub_82679884);
PPC_FUNC_IMPL(__imp__sub_82679884) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r19{};
	// lwz r19,-25980(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25980);
	// lwz r19,-25964(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25964);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25948(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25948);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25932(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25932);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25916(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25916);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25900(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25900);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25884(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25884);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25660(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25660);
	// lwz r19,-25868(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -25868);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,28(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679A94"))) PPC_WEAK_FUNC(sub_82679A94);
PPC_FUNC_IMPL(__imp__sub_82679A94) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,32(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AA4"))) PPC_WEAK_FUNC(sub_82679AA4);
PPC_FUNC_IMPL(__imp__sub_82679AA4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AB4"))) PPC_WEAK_FUNC(sub_82679AB4);
PPC_FUNC_IMPL(__imp__sub_82679AB4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,24(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AC4"))) PPC_WEAK_FUNC(sub_82679AC4);
PPC_FUNC_IMPL(__imp__sub_82679AC4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AD4"))) PPC_WEAK_FUNC(sub_82679AD4);
PPC_FUNC_IMPL(__imp__sub_82679AD4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AE4"))) PPC_WEAK_FUNC(sub_82679AE4);
PPC_FUNC_IMPL(__imp__sub_82679AE4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679AF4"))) PPC_WEAK_FUNC(sub_82679AF4);
PPC_FUNC_IMPL(__imp__sub_82679AF4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679B04"))) PPC_WEAK_FUNC(sub_82679B04);
PPC_FUNC_IMPL(__imp__sub_82679B04) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,40(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679B14"))) PPC_WEAK_FUNC(sub_82679B14);
PPC_FUNC_IMPL(__imp__sub_82679B14) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,4096
	cr6.compare<int32_t>(ctx.r4.s32, 4096, xer);
	// bgt cr6,0x82679b78
	if (cr6.gt) goto loc_82679B78;
	// beq cr6,0x82679b68
	if (cr6.eq) goto loc_82679B68;
	// cmpwi cr6,r4,512
	cr6.compare<int32_t>(ctx.r4.s32, 512, xer);
	// beq cr6,0x82679b58
	if (cr6.eq) goto loc_82679B58;
	// cmpwi cr6,r4,1024
	cr6.compare<int32_t>(ctx.r4.s32, 1024, xer);
	// beq cr6,0x82679b48
	if (cr6.eq) goto loc_82679B48;
	// cmpwi cr6,r4,2048
	cr6.compare<int32_t>(ctx.r4.s32, 2048, xer);
	// bne cr6,0x82679bc4
	if (!cr6.eq) goto loc_82679BC4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,36(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// blr 
	return;
loc_82679B48:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,112(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// blr 
	return;
loc_82679B58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r11,31112
	ctx.r10.s64 = r11.s64 + 31112;
	// lwz r3,116(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// blr 
	return;
loc_82679B68:
	// li r11,0
	r11.s64 = 0;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679B78:
	// cmpwi cr6,r4,8192
	cr6.compare<int32_t>(ctx.r4.s32, 8192, xer);
	// beq cr6,0x82679bb4
	if (cr6.eq) goto loc_82679BB4;
	// cmpwi cr6,r4,16384
	cr6.compare<int32_t>(ctx.r4.s32, 16384, xer);
	// beq cr6,0x82679ba4
	if (cr6.eq) goto loc_82679BA4;
	// cmplwi cr6,r4,32768
	cr6.compare<uint32_t>(ctx.r4.u32, 32768, xer);
	// bne cr6,0x82679bc4
	if (!cr6.eq) goto loc_82679BC4;
	// li r11,0
	r11.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BA4:
	// li r11,0
	r11.s64 = 0;
	// li r4,16384
	ctx.r4.s64 = 16384;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BB4:
	// li r11,0
	r11.s64 = 0;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// b 0x82391ab8
	sub_82391AB8(ctx, base);
	return;
loc_82679BC4:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// addi r3,r10,3998
	ctx.r3.s64 = ctx.r10.s64 + 3998;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679BD8"))) PPC_WEAK_FUNC(sub_82679BD8);
PPC_FUNC_IMPL(__imp__sub_82679BD8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679BF4;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679c10
	if (cr6.eq) goto loc_82679C10;
	// bl 0x82387b90
	ctx.lr = 0x82679C04;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679C0C;
	sub_8238B070(ctx, base);
	// b 0x82679c1c
	goto loc_82679C1C;
loc_82679C10:
	// bl 0x82387b90
	ctx.lr = 0x82679C14;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679C1C;
	sub_8238B080(ctx, base);
loc_82679C1C:
	// addi r11,r31,5160
	r11.s64 = r31.s64 + 5160;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,592
	ctx.r5.s64 = 592;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823da950
	ctx.lr = 0x82679C30;
	sub_823DA950(ctx, base);
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

__attribute__((alias("__imp__sub_82679C44"))) PPC_WEAK_FUNC(sub_82679C44);
PPC_FUNC_IMPL(__imp__sub_82679C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679C48"))) PPC_WEAK_FUNC(sub_82679C48);
PPC_FUNC_IMPL(__imp__sub_82679C48) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679C64;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679c80
	if (cr6.eq) goto loc_82679C80;
	// bl 0x82387b90
	ctx.lr = 0x82679C74;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679C7C;
	sub_8238B070(ctx, base);
	// b 0x82679c8c
	goto loc_82679C8C;
loc_82679C80:
	// bl 0x82387b90
	ctx.lr = 0x82679C84;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679C8C;
	sub_8238B080(ctx, base);
loc_82679C8C:
	// addi r4,r31,5160
	ctx.r4.s64 = r31.s64 + 5160;
	// bl 0x823917e0
	ctx.lr = 0x82679C94;
	sub_823917E0(ctx, base);
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

__attribute__((alias("__imp__sub_82679CA8"))) PPC_WEAK_FUNC(sub_82679CA8);
PPC_FUNC_IMPL(__imp__sub_82679CA8) {
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// lwz r11,3360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3360);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82679cf4
	if (!cr6.eq) goto loc_82679CF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,2816(r31)
	PPC_STORE_U8(r31.u32 + 2816, ctx.r10.u8);
	// lwz r9,736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82679CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679CF4:
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

__attribute__((alias("__imp__sub_82679D08"))) PPC_WEAK_FUNC(sub_82679D08);
PPC_FUNC_IMPL(__imp__sub_82679D08) {
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
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679D28;
	sub_821E6800(ctx, base);
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r11,r10,23088
	r11.s64 = ctx.r10.s64 + 23088;
	// addi r6,r9,-23272
	ctx.r6.s64 = ctx.r9.s64 + -23272;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,23088(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// addi r5,r7,-23300
	ctx.r5.s64 = ctx.r7.s64 + -23300;
	// stb r4,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, ctx.r4.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// ld r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82679D68;
	sub_82634EC8(ctx, base);
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

__attribute__((alias("__imp__sub_82679D7C"))) PPC_WEAK_FUNC(sub_82679D7C);
PPC_FUNC_IMPL(__imp__sub_82679D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679D80"))) PPC_WEAK_FUNC(sub_82679D80);
PPC_FUNC_IMPL(__imp__sub_82679D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,804(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 804);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82679D90"))) PPC_WEAK_FUNC(sub_82679D90);
PPC_FUNC_IMPL(__imp__sub_82679D90) {
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
	ctx.lr = 0x82679D98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r28,r29,672
	r28.s64 = r29.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x82679DB0;
	sub_82631F88(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82679e50
	if (!cr6.gt) goto loc_82679E50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r29,2836
	r31.s64 = r29.s64 + 2836;
	// subfic r27,r29,-2836
	xer.ca = r29.u32 <= 4294964460;
	r27.s64 = -2836 - r29.s64;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
loc_82679DCC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x82679DD4;
	sub_82631F88(ctx, base);
	// lwz r11,184(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82679de4
	if (cr6.lt) goto loc_82679DE4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82679DE4:
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x82679e20
	if (!cr6.eq) goto loc_82679E20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lbz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 208);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,208(r11)
	PPC_STORE_U8(r11.u32 + 208, ctx.r9.u8);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,188(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 188);
	// lwz r3,0(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82679E1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82679e40
	goto loc_82679E40;
loc_82679E20:
	// lwz r11,848(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82679E40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82679E40:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// blt cr6,0x82679dcc
	if (cr6.lt) goto loc_82679DCC;
loc_82679E50:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82679E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82679E6C"))) PPC_WEAK_FUNC(sub_82679E6C);
PPC_FUNC_IMPL(__imp__sub_82679E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679E70"))) PPC_WEAK_FUNC(sub_82679E70);
PPC_FUNC_IMPL(__imp__sub_82679E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r11,r8,-112
	r11.s64 = ctx.r8.s64 + -112;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r6,r11,4
	ctx.r6.s64 = r11.s64 + 4;
	// rlwinm r5,r7,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82679E94"))) PPC_WEAK_FUNC(sub_82679E94);
PPC_FUNC_IMPL(__imp__sub_82679E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679E98"))) PPC_WEAK_FUNC(sub_82679E98);
PPC_FUNC_IMPL(__imp__sub_82679E98) {
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
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82679f34
	if (!cr6.eq) goto loc_82679F34;
	// lbz r11,2816(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679f34
	if (cr6.eq) goto loc_82679F34;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82679ED0;
	sub_821E6800(ctx, base);
	// lis r10,-32152
	ctx.r10.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-25432
	ctx.r4.s64 = ctx.r10.s64 + -25432;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2f90
	ctx.lr = 0x82679EE4;
	sub_821C2F90(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r9,-23216
	ctx.r6.s64 = ctx.r9.s64 + -23216;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r8,-23244
	ctx.r5.s64 = ctx.r8.s64 + -23244;
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634ec8
	ctx.lr = 0x82679F1C;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_82679F34:
	// li r3,0
	ctx.r3.s64 = 0;
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

__attribute__((alias("__imp__sub_82679F4C"))) PPC_WEAK_FUNC(sub_82679F4C);
PPC_FUNC_IMPL(__imp__sub_82679F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82679F50"))) PPC_WEAK_FUNC(sub_82679F50);
PPC_FUNC_IMPL(__imp__sub_82679F50) {
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
	ctx.lr = 0x82679F58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x82679F68;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679f84
	if (cr6.eq) goto loc_82679F84;
	// bl 0x82387b90
	ctx.lr = 0x82679F78;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x82679F80;
	sub_8238B070(ctx, base);
	// b 0x82679f90
	goto loc_82679F90;
loc_82679F84:
	// bl 0x82387b90
	ctx.lr = 0x82679F88;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x82679F90;
	sub_8238B080(ctx, base);
loc_82679F90:
	// addi r31,r29,5160
	r31.s64 = r29.s64 + 5160;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823917e0
	ctx.lr = 0x82679FA0;
	sub_823917E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82679fbc
	if (cr6.eq) goto loc_82679FBC;
	// li r5,592
	ctx.r5.s64 = 592;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x82679FBC;
	sub_823DA950(ctx, base);
loc_82679FBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ed0
	ctx.lr = 0x82679FC4;
	sub_822A4ED0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82679FD4;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82679ffc
	if (cr6.eq) goto loc_82679FFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82679FEC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,116(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x82679FFC;
	sub_822A4DE8(ctx, base);
loc_82679FFC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,5156(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 5156);
	// li r4,33
	ctx.r4.s64 = 33;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267A01C;
	sub_82641CB0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8264d070
	ctx.lr = 0x8267A024;
	sub_8264D070(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267A030;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267A034;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267A044;
	sub_8260B990(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267A04C"))) PPC_WEAK_FUNC(sub_8267A04C);
PPC_FUNC_IMPL(__imp__sub_8267A04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A050"))) PPC_WEAK_FUNC(sub_8267A050);
PPC_FUNC_IMPL(__imp__sub_8267A050) {
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
	ctx.lr = 0x8267A058;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r29,2836
	r31.s64 = r29.s64 + 2836;
	// addi r10,r11,-22524
	ctx.r10.s64 = r11.s64 + -22524;
	// li r30,32
	r30.s64 = 32;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_8267A074:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267a094
	if (cr6.eq) goto loc_8267A094;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267A094:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8267a074
	if (!cr0.eq) goto loc_8267A074;
	// addi r3,r29,3360
	ctx.r3.s64 = r29.s64 + 3360;
	// bl 0x8221fbc8
	ctx.lr = 0x8267A0A8;
	sub_8221FBC8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r29,3224
	r11.s64 = r29.s64 + 3224;
	// li r10,31
	ctx.r10.s64 = 31;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_8267A0B8:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8267a0b8
	if (!cr0.lt) goto loc_8267A0B8;
	// lhz r11,2830(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 2830);
	// addi r31,r29,2820
	r31.s64 = r29.s64 + 2820;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a0e0
	if (cr6.eq) goto loc_8267A0E0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8267A0E0;
	sub_82130588(ctx, base);
loc_8267A0E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267A0E8;
	sub_821D2028(ctx, base);
	// addi r3,r29,992
	ctx.r3.s64 = r29.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x8267A0F0;
	sub_8221FBC8(ctx, base);
	// lhz r11,886(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 886);
	// addi r31,r29,672
	r31.s64 = r29.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a108
	if (cr6.eq) goto loc_8267A108;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267A108;
	sub_82130588(ctx, base);
loc_8267A108:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a11c
	if (cr6.eq) goto loc_8267A11C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267A11C;
	sub_82130588(ctx, base);
loc_8267A11C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267A124;
	sub_82633B00(ctx, base);
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267A12C;
	sub_82633B00(ctx, base);
	// addi r3,r29,256
	ctx.r3.s64 = r29.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267A134;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267A13C;
	sub_82633B00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267A144"))) PPC_WEAK_FUNC(sub_8267A144);
PPC_FUNC_IMPL(__imp__sub_8267A144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A148"))) PPC_WEAK_FUNC(sub_8267A148);
PPC_FUNC_IMPL(__imp__sub_8267A148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,2832(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2832);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267A158"))) PPC_WEAK_FUNC(sub_8267A158);
PPC_FUNC_IMPL(__imp__sub_8267A158) {
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
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a188
	if (cr6.eq) goto loc_8267A188;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8267A188;
	sub_82130588(ctx, base);
loc_8267A188:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8267A190;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a1a8
	if (cr6.eq) goto loc_8267A1A8;
	// bl 0x82130588
	ctx.lr = 0x8267A1A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267A1A8:
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

__attribute__((alias("__imp__sub_8267A1C0"))) PPC_WEAK_FUNC(sub_8267A1C0);
PPC_FUNC_IMPL(__imp__sub_8267A1C0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x8267A1C8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// addi r27,r18,848
	r27.s64 = r18.s64 + 848;
	// lhz r11,852(r18)
	r11.u64 = PPC_LOAD_U16(r18.u32 + 852);
	// lwz r9,848(r18)
	ctx.r9.u64 = PPC_LOAD_U32(r18.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267a208
	if (cr6.eq) goto loc_8267A208;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8267A1F4:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8267a1f4
	if (!cr6.eq) goto loc_8267A1F4;
loc_8267A208:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// addi r24,r18,5752
	r24.s64 = r18.s64 + 5752;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lbz r6,5152(r18)
	ctx.r6.u64 = PPC_LOAD_U8(r18.u32 + 5152);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8267a230
	if (!cr6.eq) goto loc_8267A230;
	// addi r24,r18,5160
	r24.s64 = r18.s64 + 5160;
loc_8267A230:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r15,r11,-112
	r15.s64 = r11.s64 + -112;
	// stb r10,2816(r18)
	PPC_STORE_U8(r18.u32 + 2816, ctx.r10.u8);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// addi r28,r18,2836
	r28.s64 = r18.s64 + 2836;
	// addi r25,r15,4
	r25.s64 = r15.s64 + 4;
	// li r16,1
	r16.s64 = 1;
	// addi r17,r11,-21592
	r17.s64 = r11.s64 + -21592;
	// addi r21,r10,-21612
	r21.s64 = ctx.r10.s64 + -21612;
	// addi r20,r9,-21628
	r20.s64 = ctx.r9.s64 + -21628;
	// addi r23,r8,-21640
	r23.s64 = ctx.r8.s64 + -21640;
	// addi r22,r7,-21652
	r22.s64 = ctx.r7.s64 + -21652;
	// addi r19,r6,-21664
	r19.s64 = ctx.r6.s64 + -21664;
loc_8267A27C:
	// lwz r31,-4(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + -4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82726710
	ctx.lr = 0x8267A288;
	sub_82726710(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267a4f4
	if (!cr6.eq) goto loc_8267A4F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267A29C;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a2c0
	if (cr6.eq) goto loc_8267A2C0;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// blt cr6,0x8267a2b8
	if (cr6.lt) goto loc_8267A2B8;
	// cmplwi cr6,r31,44
	cr6.compare<uint32_t>(r31.u32, 44, xer);
	// bne cr6,0x8267a2c0
	if (!cr6.eq) goto loc_8267A2C0;
loc_8267A2B8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8267a2c4
	goto loc_8267A2C4;
loc_8267A2C0:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8267A2C4:
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A2D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r31,388(r28)
	PPC_STORE_U32(r28.u32 + 388, r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A2F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r24
	r11.u64 = r11.u64 + r24.u64;
	// sth r6,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r6.u16);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x822a4a90
	ctx.lr = 0x8267A330;
	sub_822A4A90(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8267a364
	if (cr6.eq) goto loc_8267A364;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8267a364
	if (!cr6.eq) goto loc_8267A364;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827265a0
	ctx.lr = 0x8267A350;
	sub_827265A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a364
	if (cr6.eq) goto loc_8267A364;
	// mr r26,r16
	r26.u64 = r16.u64;
	// stb r16,2816(r18)
	PPC_STORE_U8(r18.u32 + 2816, r16.u8);
loc_8267A364:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267A36C;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a398
	if (!cr6.eq) goto loc_8267A398;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8267a398
	if (!cr6.eq) goto loc_8267A398;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A398:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a3c0
	if (!cr6.eq) goto loc_8267A3C0;
	// cmpwi cr6,r29,27
	cr6.compare<int32_t>(r29.s32, 27, xer);
	// bne cr6,0x8267a3c0
	if (!cr6.eq) goto loc_8267A3C0;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A3C0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,9
	cr6.compare<int32_t>(r30.s32, 9, xer);
	// bne cr6,0x8267a3e8
	if (!cr6.eq) goto loc_8267A3E8;
	// cmpwi cr6,r29,26
	cr6.compare<int32_t>(r29.s32, 26, xer);
	// bne cr6,0x8267a3e8
	if (!cr6.eq) goto loc_8267A3E8;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A3E8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a410
	if (!cr6.eq) goto loc_8267A410;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x8267a410
	if (!cr6.eq) goto loc_8267A410;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A410:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a438
	if (!cr6.eq) goto loc_8267A438;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x8267a438
	if (!cr6.eq) goto loc_8267A438;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A438:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a460
	if (!cr6.eq) goto loc_8267A460;
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x8267a460
	if (!cr6.eq) goto loc_8267A460;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A460:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a488
	if (cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bne cr6,0x8267a488
	if (!cr6.eq) goto loc_8267A488;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bne cr6,0x8267a488
	if (!cr6.eq) goto loc_8267A488;
	// li r11,0
	r11.s64 = 0;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// b 0x8267a4a0
	goto loc_8267A4A0;
loc_8267A488:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82679678
	ctx.lr = 0x8267A498;
	sub_82679678(ctx, base);
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_8267A4A0:
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r8,r26,24
	ctx.r8.u64 = r26.u32 & 0xFF;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lbz r7,208(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 208);
	// rlwimi r7,r8,6,25,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 6) & 0x40) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r7,208(r9)
	PPC_STORE_U8(ctx.r9.u32 + 208, ctx.r7.u8);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r3,208(r5)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r5.u32 + 208);
	// rlwimi r3,r11,7,17,24
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r3.u64 & 0xFFFFFFFFFFFF807F);
	// stb r3,208(r5)
	PPC_STORE_U8(ctx.r5.u32 + 208, ctx.r3.u8);
	// beq cr6,0x8267a50c
	if (cr6.eq) goto loc_8267A50C;
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
loc_8267A4D4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
loc_8267A4E8:
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267A4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
loc_8267A4F4:
	// addi r25,r25,8
	r25.s64 = r25.s64 + 8;
	// addi r11,r15,364
	r11.s64 = r15.s64 + 364;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x8267a27c
	if (cr6.lt) goto loc_8267A27C;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9214
	return;
loc_8267A50C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8267a4d4
	if (cr6.eq) goto loc_8267A4D4;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8267a4e8
	goto loc_8267A4E8;
}

__attribute__((alias("__imp__sub_8267A52C"))) PPC_WEAK_FUNC(sub_8267A52C);
PPC_FUNC_IMPL(__imp__sub_8267A52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A530"))) PPC_WEAK_FUNC(sub_8267A530);
PPC_FUNC_IMPL(__imp__sub_8267A530) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8267A538;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-21552
	ctx.r4.s64 = ctx.r9.s64 + -21552;
	// addi r8,r11,28716
	ctx.r8.s64 = r11.s64 + 28716;
	// addi r5,r10,-21572
	ctx.r5.s64 = ctx.r10.s64 + -21572;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,32
	ctx.r6.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8264cc48
	ctx.lr = 0x8267A568;
	sub_8264CC48(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r6,r8,-22524
	ctx.r6.s64 = ctx.r8.s64 + -22524;
	// addi r5,r7,-4092
	ctx.r5.s64 = ctx.r7.s64 + -4092;
	// li r4,74
	ctx.r4.s64 = 74;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// li r26,0
	r26.s64 = 0;
	// stw r5,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r5.u32);
	// sth r4,2830(r31)
	PPC_STORE_U16(r31.u32 + 2830, ctx.r4.u16);
	// li r3,296
	ctx.r3.s64 = 296;
	// sth r26,2828(r31)
	PPC_STORE_U16(r31.u32 + 2828, r26.u16);
	// addi r11,r31,2820
	r11.s64 = r31.s64 + 2820;
	// bl 0x82130528
	ctx.lr = 0x8267A59C;
	sub_82130528(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// stw r3,2824(r31)
	PPC_STORE_U32(r31.u32 + 2824, ctx.r3.u32);
	// addi r29,r31,2968
	r29.s64 = r31.s64 + 2968;
	// addi r10,r11,-21708
	ctx.r10.s64 = r11.s64 + -21708;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r10,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
	// li r28,31
	r28.s64 = 31;
	// mr r30,r29
	r30.u64 = r29.u64;
	// stw r26,2964(r31)
	PPC_STORE_U32(r31.u32 + 2964, r26.u32);
	// addi r27,r11,5568
	r27.s64 = r11.s64 + 5568;
	// addi r23,r10,3998
	r23.s64 = ctx.r10.s64 + 3998;
loc_8267A5D0:
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267A5E0;
	sub_826311F8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x8267a5d0
	if (!cr0.lt) goto loc_8267A5D0;
	// stw r26,3352(r31)
	PPC_STORE_U32(r31.u32 + 3352, r26.u32);
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634b60
	ctx.lr = 0x8267A5F8;
	sub_82634B60(ctx, base);
	// stb r26,5152(r31)
	PPC_STORE_U8(r31.u32 + 5152, r26.u8);
	// stw r26,5156(r31)
	PPC_STORE_U32(r31.u32 + 5156, r26.u32);
	// addi r3,r31,5160
	ctx.r3.s64 = r31.s64 + 5160;
	// bl 0x82391b18
	ctx.lr = 0x8267A608;
	sub_82391B18(ctx, base);
	// addi r3,r31,5752
	ctx.r3.s64 = r31.s64 + 5752;
	// bl 0x82391b18
	ctx.lr = 0x8267A610;
	sub_82391B18(ctx, base);
	// addi r11,r31,880
	r11.s64 = r31.s64 + 880;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// addi r28,r31,2836
	r28.s64 = r31.s64 + 2836;
	// addi r7,r8,31100
	ctx.r7.s64 = ctx.r8.s64 + 31100;
	// addi r27,r31,3224
	r27.s64 = r31.s64 + 3224;
	// li r30,32
	r30.s64 = 32;
	// lhz r11,884(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r6.u16);
	// lwz r11,31100(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31100);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r11,884(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r24,r11,-23180
	r24.s64 = r11.s64 + -23180;
loc_8267A668:
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x8267A670;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8267a6a0
	if (cr6.eq) goto loc_8267A6A0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633d40
	ctx.lr = 0x8267A688;
	sub_82633D40(ctx, base);
	// lbz r10,208(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 208);
	// mr r11,r25
	r11.u64 = r25.u64;
	// stw r24,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r24.u32);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// stb r9,208(r25)
	PPC_STORE_U8(r25.u32 + 208, ctx.r9.u8);
	// b 0x8267a6a4
	goto loc_8267A6A4;
loc_8267A6A0:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8267A6A4:
	// lwz r10,128(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r10,r11,188
	ctx.r10.s64 = r11.s64 + 188;
	// stw r8,128(r28)
	PPC_STORE_U32(r28.u32 + 128, ctx.r8.u32);
	// stwx r11,r9,r28
	PPC_STORE_U32(ctx.r9.u32 + r28.u32, r11.u32);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// stwx r29,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r29.u32);
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// stw r5,128(r27)
	PPC_STORE_U32(r27.u32 + 128, ctx.r5.u32);
	// stwx r26,r10,r27
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, r26.u32);
	// bne 0x8267a668
	if (!cr0.eq) goto loc_8267A668;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8267A700"))) PPC_WEAK_FUNC(sub_8267A700);
PPC_FUNC_IMPL(__imp__sub_8267A700) {
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
	// bl 0x8267a050
	ctx.lr = 0x8267A720;
	sub_8267A050(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a738
	if (cr6.eq) goto loc_8267A738;
	// bl 0x82130588
	ctx.lr = 0x8267A734;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267A738:
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

__attribute__((alias("__imp__sub_8267A750"))) PPC_WEAK_FUNC(sub_8267A750);
PPC_FUNC_IMPL(__imp__sub_8267A750) {
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
	// bl 0x8267a1c0
	ctx.lr = 0x8267A76C;
	sub_8267A1C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ab8
	ctx.lr = 0x8267A774;
	sub_822A4AB8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8267a794
	if (cr6.eq) goto loc_8267A794;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,2784(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2784, temp.u32);
	// stfs f0,2788(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2788, temp.u32);
	// stfs f0,2792(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2792, temp.u32);
	// stfs f0,2796(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 2796, temp.u32);
loc_8267A794:
	// lwz r11,256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// addi r31,r30,256
	r31.s64 = r30.s64 + 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,5152(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 5152);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267a7d0
	if (cr6.eq) goto loc_8267A7D0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28716
	ctx.r4.s64 = r11.s64 + 28716;
	// b 0x8267a7dc
	goto loc_8267A7DC;
loc_8267A7D0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,29364
	ctx.r4.s64 = r11.s64 + 29364;
loc_8267A7DC:
	// bl 0x8262ffe0
	ctx.lr = 0x8267A7E0;
	sub_8262FFE0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A7F4;
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

__attribute__((alias("__imp__sub_8267A80C"))) PPC_WEAK_FUNC(sub_8267A80C);
PPC_FUNC_IMPL(__imp__sub_8267A80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A810"))) PPC_WEAK_FUNC(sub_8267A810);
PPC_FUNC_IMPL(__imp__sub_8267A810) {
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
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// beq cr6,0x8267a87c
	if (cr6.eq) goto loc_8267A87C;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21504
	ctx.r4.s64 = ctx.r10.s64 + -21504;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,496(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r8,-21532
	ctx.r4.s64 = ctx.r8.s64 + -21532;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267A864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387b90
	ctx.lr = 0x8267A868;
	sub_82387B90(ctx, base);
	// lwz r5,5156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 5156);
	// addi r4,r31,5752
	ctx.r4.s64 = r31.s64 + 5752;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// bl 0x8238ca70
	ctx.lr = 0x8267A878;
	sub_8238CA70(ctx, base);
	// b 0x8267a8a8
	goto loc_8267A8A8;
loc_8267A87C:
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21552
	ctx.r4.s64 = ctx.r10.s64 + -21552;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,496(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r8,-21572
	ctx.r4.s64 = ctx.r8.s64 + -21572;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267A8A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267A8A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267A8B0;
	sub_8267A750(ctx, base);
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
	ctx.lr = 0x8267A8C8;
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

__attribute__((alias("__imp__sub_8267A8DC"))) PPC_WEAK_FUNC(sub_8267A8DC);
PPC_FUNC_IMPL(__imp__sub_8267A8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267A8E0"))) PPC_WEAK_FUNC(sub_8267A8E0);
PPC_FUNC_IMPL(__imp__sub_8267A8E0) {
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
	ctx.lr = 0x8267A8E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267aa44
	if (cr6.eq) goto loc_8267AA44;
	// lbz r11,2833(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2833);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267a918
	if (cr6.eq) goto loc_8267A918;
	// li r11,0
	r11.s64 = 0;
	// stb r11,2833(r31)
	PPC_STORE_U8(r31.u32 + 2833, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8267A918:
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203240
	ctx.lr = 0x8267A924;
	sub_82203240(ctx, base);
	// addi r11,r3,806
	r11.s64 = ctx.r3.s64 + 806;
	// addi r7,r31,2784
	ctx.r7.s64 = r31.s64 + 2784;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82727010
	ctx.lr = 0x8267A944;
	sub_82727010(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267aa44
	if (cr6.eq) goto loc_8267AA44;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203240
	ctx.lr = 0x8267A958;
	sub_82203240(ctx, base);
	// addi r11,r3,806
	r11.s64 = ctx.r3.s64 + 806;
	// addi r6,r31,5160
	ctx.r6.s64 = r31.s64 + 5160;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwzx r5,r10,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x82726870
	ctx.lr = 0x8267A974;
	sub_82726870(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x8267A980;
	sub_82631F88(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8267a9bc
	if (!cr6.gt) goto loc_8267A9BC;
	// mr r29,r26
	r29.u64 = r26.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8267A994:
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267A9B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8267a994
	if (!cr0.eq) goto loc_8267A994;
loc_8267A9BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267A9C4;
	sub_8267A750(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r26,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r26.u32);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267A9DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267A9F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r27,24
	ctx.r7.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8267aa38
	if (cr6.eq) goto loc_8267AA38;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AA08;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AA18;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AA1C;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AA2C;
	sub_8260B990(ctx, base);
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8267AA38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82679d08
	ctx.lr = 0x8267AA40;
	sub_82679D08(ctx, base);
	// stb r26,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r26.u8);
loc_8267AA44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267AA4C"))) PPC_WEAK_FUNC(sub_8267AA4C);
PPC_FUNC_IMPL(__imp__sub_8267AA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267AA50"))) PPC_WEAK_FUNC(sub_8267AA50);
PPC_FUNC_IMPL(__imp__sub_8267AA50) {
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
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// lwz r11,3360(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3360);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267AA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8267aad4
	if (!cr6.eq) goto loc_8267AAD4;
	// bl 0x82387b90
	ctx.lr = 0x8267AA84;
	sub_82387B90(ctx, base);
	// lwz r11,5156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5156);
	// addi r4,r31,5160
	ctx.r4.s64 = r31.s64 + 5160;
	// extsh r5,r11
	ctx.r5.s64 = r11.s16;
	// bl 0x8238ca70
	ctx.lr = 0x8267AA94;
	sub_8238CA70(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AAA4;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AAA8;
	sub_822A5578(ctx, base);
	// lwz r9,116(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AAB8;
	sub_8260B990(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267a750
	ctx.lr = 0x8267AAC0;
	sub_8267A750(ctx, base);
	// lwz r8,672(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267AAD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267AAD4:
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

__attribute__((alias("__imp__sub_8267AAE8"))) PPC_WEAK_FUNC(sub_8267AAE8);
PPC_FUNC_IMPL(__imp__sub_8267AAE8) {
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
	// bl 0x8267a750
	ctx.lr = 0x8267AB00;
	sub_8267A750(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AB10;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AB14;
	sub_822A5578(ctx, base);
	// lwz r10,116(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AB24;
	sub_8260B990(ctx, base);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AB38;
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

__attribute__((alias("__imp__sub_8267AB4C"))) PPC_WEAK_FUNC(sub_8267AB4C);
PPC_FUNC_IMPL(__imp__sub_8267AB4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267AB50"))) PPC_WEAK_FUNC(sub_8267AB50);
PPC_FUNC_IMPL(__imp__sub_8267AB50) {
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
	ctx.lr = 0x8267AB58;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2832(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac64
	if (!cr6.eq) goto loc_8267AC64;
	// addi r11,r4,-55
	r11.s64 = ctx.r4.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8267ae40
	if (cr6.gt) goto loc_8267AE40;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-21616
	r12.s64 = r12.s64 + -21616;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267ACE0;
	case 1:
		goto loc_8267AD9C;
	case 2:
		goto loc_8267AE40;
	case 3:
		goto loc_8267AE40;
	case 4:
		goto loc_8267AE40;
	case 5:
		goto loc_8267AE40;
	case 6:
		goto loc_8267AE40;
	case 7:
		goto loc_8267AC70;
	case 8:
		goto loc_8267ABB4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-21280(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21280);
	// lwz r19,-21092(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21092);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-20928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20928);
	// lwz r19,-21392(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21392);
	// lwz r19,-21580(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -21580);
loc_8267ABB4:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac58
	if (!cr6.eq) goto loc_8267AC58;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267ABE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267ac58
	if (cr6.eq) goto loc_8267AC58;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267ABFC;
	sub_821E6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8267AC04;
	sub_82203240(ctx, base);
	// addi r9,r3,806
	ctx.r9.s64 = ctx.r3.s64 + 806;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r11,r7,r31
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r6,r11,645
	ctx.r6.s64 = r11.s64 + 645;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r3,17268(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AC38;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AC3C;
	sub_822A5578(ctx, base);
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4de8
	ctx.lr = 0x8267AC44;
	sub_822A4DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267aae8
	ctx.lr = 0x8267AC4C;
	sub_8267AAE8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AC58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267AC64;
	sub_821E6800(ctx, base);
loc_8267AC64:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AC70:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267acd4
	if (!cr6.eq) goto loc_8267ACD4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AC88;
	sub_821E6800(ctx, base);
	// lis r10,-32152
	ctx.r10.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-25216
	ctx.r4.s64 = ctx.r10.s64 + -25216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2f90
	ctx.lr = 0x8267AC9C;
	sub_821C2F90(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r9,-21444
	ctx.r6.s64 = ctx.r9.s64 + -21444;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r8,-21472
	ctx.r5.s64 = ctx.r8.s64 + -21472;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,3360
	ctx.r3.s64 = r31.s64 + 3360;
	// bl 0x82634ec8
	ctx.lr = 0x8267ACD4;
	sub_82634EC8(ctx, base);
loc_8267ACD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267ACE0:
	// lbz r11,5152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267ac58
	if (!cr6.eq) goto loc_8267AC58;
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267AD0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267ac58
	if (cr6.eq) goto loc_8267AC58;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AD24;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82679d90
	ctx.lr = 0x8267AD2C;
	sub_82679D90(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stb r29,2832(r31)
	PPC_STORE_U8(r31.u32 + 2832, r29.u8);
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r28,r10,28156
	r28.s64 = ctx.r10.s64 + 28156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8262ffe0
	ctx.lr = 0x8267AD50;
	sub_8262FFE0(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r28.u32);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AD68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8267AD78;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8267AD7C;
	sub_822A5578(ctx, base);
	// lwz r6,116(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// bl 0x8260b990
	ctx.lr = 0x8267AD8C;
	sub_8260B990(ctx, base);
	// stb r29,2833(r31)
	PPC_STORE_U8(r31.u32 + 2833, r29.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AD9C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267ADA8;
	sub_826304B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8267ADB0;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267adcc
	if (cr6.eq) goto loc_8267ADCC;
	// bl 0x82387b90
	ctx.lr = 0x8267ADC0;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b070
	ctx.lr = 0x8267ADC8;
	sub_8238B070(ctx, base);
	// b 0x8267add8
	goto loc_8267ADD8;
loc_8267ADCC:
	// bl 0x82387b90
	ctx.lr = 0x8267ADD0;
	sub_82387B90(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8238b080
	ctx.lr = 0x8267ADD8;
	sub_8238B080(ctx, base);
loc_8267ADD8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,5160
	ctx.r3.s64 = r31.s64 + 5160;
	// bl 0x82391758
	ctx.lr = 0x8267ADE4;
	sub_82391758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lbz r10,5152(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267ae14
	if (!cr6.eq) goto loc_8267AE14;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267ae14
	if (cr6.eq) goto loc_8267AE14;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AE14;
	sub_826304B0(ctx, base);
loc_8267AE14:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267AE20;
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
	ctx.lr = 0x8267AE34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8267AE40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264b668
	ctx.lr = 0x8267AE48;
	sub_8264B668(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267AE50"))) PPC_WEAK_FUNC(sub_8267AE50);
PPC_FUNC_IMPL(__imp__sub_8267AE50) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267aebc
	if (cr6.eq) goto loc_8267AEBC;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267ae8c
	if (cr6.eq) goto loc_8267AE8C;
	// bl 0x826537d0
	ctx.lr = 0x8267AE78;
	sub_826537D0(ctx, base);
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
loc_8267AE8C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267AE98;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AEA4;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267af38
	goto loc_8267AF38;
loc_8267AEBC:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8267AEC4;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267aed4
	if (cr6.lt) goto loc_8267AED4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8267AED4:
	// addi r11,r11,248
	r11.s64 = r11.s64 + 248;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267AEF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8267af2c
	if (cr6.eq) goto loc_8267AF2C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AF08;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AF14;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AF28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267af38
	goto loc_8267AF38;
loc_8267AF2C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267AF38;
	sub_821E6800(ctx, base);
loc_8267AF38:
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

__attribute__((alias("__imp__sub_8267AF50"))) PPC_WEAK_FUNC(sub_8267AF50);
PPC_FUNC_IMPL(__imp__sub_8267AF50) {
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
	// addi r11,r4,-47
	r11.s64 = ctx.r4.s64 + -47;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x8267b050
	if (cr6.gt) goto loc_8267B050;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-20600
	r12.s64 = r12.s64 + -20600;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267AFB0;
	case 1:
		goto loc_8267AFB0;
	case 2:
		goto loc_8267AFB0;
	case 3:
		goto loc_8267AFB0;
	case 4:
		goto loc_8267B050;
	case 5:
		goto loc_8267B050;
	case 6:
		goto loc_8267B050;
	case 7:
		goto loc_8267B050;
	case 8:
		goto loc_8267AFC8;
	case 9:
		goto loc_8267B00C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20560(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20560);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20400(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20400);
	// lwz r19,-20536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20536);
	// lwz r19,-20468(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20468);
loc_8267AFB0:
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
loc_8267AFC8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267AFD4;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267AFE0;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267AFF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8267B00C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267B018;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B024;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8267B050:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267B058;
	sub_826537D0(ctx, base);
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

__attribute__((alias("__imp__sub_8267B06C"))) PPC_WEAK_FUNC(sub_8267B06C);
PPC_FUNC_IMPL(__imp__sub_8267B06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B070"))) PPC_WEAK_FUNC(sub_8267B070);
PPC_FUNC_IMPL(__imp__sub_8267B070) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r5,1896(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1896, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267B080"))) PPC_WEAK_FUNC(sub_8267B080);
PPC_FUNC_IMPL(__imp__sub_8267B080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8267B09C"))) PPC_WEAK_FUNC(sub_8267B09C);
PPC_FUNC_IMPL(__imp__sub_8267B09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B0A0"))) PPC_WEAK_FUNC(sub_8267B0A0);
PPC_FUNC_IMPL(__imp__sub_8267B0A0) {
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
	// addi r11,r4,-47
	r11.s64 = ctx.r4.s64 + -47;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x8267b188
	if (cr6.gt) goto loc_8267B188;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-20264
	r12.s64 = r12.s64 + -20264;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267B12C;
	case 1:
		goto loc_8267B12C;
	case 2:
		goto loc_8267B12C;
	case 3:
		goto loc_8267B12C;
	case 4:
		goto loc_8267B188;
	case 5:
		goto loc_8267B188;
	case 6:
		goto loc_8267B188;
	case 7:
		goto loc_8267B188;
	case 8:
		goto loc_8267B100;
	case 9:
		goto loc_8267B144;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20180(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20180);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20088(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20088);
	// lwz r19,-20224(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20224);
	// lwz r19,-20156(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20156);
loc_8267B100:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267B10C;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B118;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267B12C:
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
loc_8267B144:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267B150;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267B15C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_8267B188:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267B190;
	sub_826537D0(ctx, base);
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

__attribute__((alias("__imp__sub_8267B1A4"))) PPC_WEAK_FUNC(sub_8267B1A4);
PPC_FUNC_IMPL(__imp__sub_8267B1A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B1A8"))) PPC_WEAK_FUNC(sub_8267B1A8);
PPC_FUNC_IMPL(__imp__sub_8267B1A8) {
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
	// bl 0x822150d8
	ctx.lr = 0x8267B1B8;
	sub_822150D8(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267B1BC;
	sub_82216648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267B1CC"))) PPC_WEAK_FUNC(sub_8267B1CC);
PPC_FUNC_IMPL(__imp__sub_8267B1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B1D0"))) PPC_WEAK_FUNC(sub_8267B1D0);
PPC_FUNC_IMPL(__imp__sub_8267B1D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267B1D8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-29360
	ctx.r3.s64 = r11.s64 + -29360;
	// bl 0x821fa230
	ctx.lr = 0x8267B1F0;
	sub_821FA230(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,20
	ctx.r6.s64 = 20;
	// lwz r5,1216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r3,18508(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18508);
	// bl 0x826b96c8
	ctx.lr = 0x8267B210;
	sub_826B96C8(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r28,r11,-20892
	r28.s64 = r11.s64 + -20892;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x8267B228;
	sub_8268E5B8(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8267b288
	if (cr6.lt) goto loc_8267B288;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f11,32(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 32);
loc_8267B258:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fmul f8,f0,f11
	ctx.f8.f64 = f0.f64 * ctx.f11.f64;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// fmadd f7,f8,f31,f9
	ctx.f7.f64 = ctx.f8.f64 * f31.f64 + ctx.f9.f64;
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f6.u64);
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// ble cr6,0x8267b258
	if (!cr6.gt) goto loc_8267B258;
loc_8267B288:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82217b70
	ctx.lr = 0x8267B2A4;
	sub_82217B70(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r10,-20912
	ctx.r3.s64 = ctx.r10.s64 + -20912;
	// bl 0x82218838
	ctx.lr = 0x8267B2B4;
	sub_82218838(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268e5b8
	ctx.lr = 0x8267B2C0;
	sub_8268E5B8(ctx, base);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-20932
	ctx.r3.s64 = ctx.r9.s64 + -20932;
	// bl 0x82218838
	ctx.lr = 0x8267B2D0;
	sub_82218838(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r7,1456(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1456);
	// addi r3,r31,1456
	ctx.r3.s64 = r31.s64 + 1456;
	// addi r30,r8,31444
	r30.s64 = ctx.r8.s64 + 31444;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267B2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1680(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1680);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1680
	ctx.r3.s64 = r31.s64 + 1680;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267B308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,672(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267B31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B328"))) PPC_WEAK_FUNC(sub_8267B328);
PPC_FUNC_IMPL(__imp__sub_8267B328) {
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
	// bl 0x822166e8
	ctx.lr = 0x8267B340;
	sub_822166E8(ctx, base);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8262fff0
	ctx.lr = 0x8267B34C;
	sub_8262FFF0(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8267B350;
	sub_82215A60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267b1d0
	ctx.lr = 0x8267B358;
	sub_8267B1D0(ctx, base);
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

__attribute__((alias("__imp__sub_8267B36C"))) PPC_WEAK_FUNC(sub_8267B36C);
PPC_FUNC_IMPL(__imp__sub_8267B36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B370"))) PPC_WEAK_FUNC(sub_8267B370);
PPC_FUNC_IMPL(__imp__sub_8267B370) {
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
	ctx.lr = 0x8267B378;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-19384
	ctx.r4.s64 = ctx.r9.s64 + -19384;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-19408
	ctx.r5.s64 = ctx.r10.s64 + -19408;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,3
	ctx.r7.s64 = 3;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267B3A8;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r7,r8,-20212
	ctx.r7.s64 = ctx.r8.s64 + -20212;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r26,1008
	r31.s64 = r26.s64 + 1008;
	// stw r7,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r7.u32);
	// li r30,9
	r30.s64 = 9;
	// addi r29,r11,5568
	r29.s64 = r11.s64 + 5568;
	// addi r27,r10,3998
	r27.s64 = ctx.r10.s64 + 3998;
loc_8267B3CC:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B3DC;
	sub_826311F8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bge 0x8267b3cc
	if (!cr0.lt) goto loc_8267B3CC;
	// addi r28,r26,848
	r28.s64 = r26.s64 + 848;
	// addi r31,r26,992
	r31.s64 = r26.s64 + 992;
	// addi r30,r26,1016
	r30.s64 = r26.s64 + 1016;
	// li r29,4
	r29.s64 = 4;
loc_8267B3F8:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8267B400;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267b418
	if (cr6.eq) goto loc_8267B418;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82633d40
	ctx.lr = 0x8267B414;
	sub_82633D40(ctx, base);
	// b 0x8267b41c
	goto loc_8267B41C;
loc_8267B418:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8267B41C:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r7,r30,-8
	ctx.r7.s64 = r30.s64 + -8;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r6.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,188(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// sth r3,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r3.u16);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r7.u16);
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r30.u32);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x8267b3f8
	if (!cr0.eq) goto loc_8267B3F8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,31392
	ctx.r4.s64 = r11.s64 + 31392;
	// addi r3,r26,672
	ctx.r3.s64 = r26.s64 + 672;
	// bl 0x826347f0
	ctx.lr = 0x8267B49C;
	sub_826347F0(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8267B4A8"))) PPC_WEAK_FUNC(sub_8267B4A8);
PPC_FUNC_IMPL(__imp__sub_8267B4A8) {
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
	ctx.lr = 0x8267B4B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r31,r28,992
	r31.s64 = r28.s64 + 992;
	// addi r10,r11,-20212
	ctx.r10.s64 = r11.s64 + -20212;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// li r29,0
	r29.s64 = 0;
loc_8267B4D0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267b4f4
	if (cr6.eq) goto loc_8267B4F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_8267B4F4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8267b4d0
	if (!cr0.eq) goto loc_8267B4D0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r11,r28,1088
	r11.s64 = r28.s64 + 1088;
	// li r10,9
	ctx.r10.s64 = 9;
	// addi r9,r9,5568
	ctx.r9.s64 = ctx.r9.s64 + 5568;
loc_8267B510:
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// bge 0x8267b510
	if (!cr0.lt) goto loc_8267B510;
	// lhz r11,886(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 886);
	// addi r31,r28,672
	r31.s64 = r28.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b538
	if (cr6.eq) goto loc_8267B538;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8267B538;
	sub_82130588(ctx, base);
loc_8267B538:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b54c
	if (cr6.eq) goto loc_8267B54C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8267B54C;
	sub_82130588(ctx, base);
loc_8267B54C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267B554;
	sub_82633B00(ctx, base);
	// addi r3,r28,496
	ctx.r3.s64 = r28.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8267B55C;
	sub_82633B00(ctx, base);
	// addi r3,r28,256
	ctx.r3.s64 = r28.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8267B564;
	sub_82633B00(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x8267B56C;
	sub_82633B00(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B574"))) PPC_WEAK_FUNC(sub_8267B574);
PPC_FUNC_IMPL(__imp__sub_8267B574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B578"))) PPC_WEAK_FUNC(sub_8267B578);
PPC_FUNC_IMPL(__imp__sub_8267B578) {
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
	ctx.lr = 0x8267B580;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r28,848
	r31.s64 = r28.s64 + 848;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267b5c0
	if (cr6.eq) goto loc_8267B5C0;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8267B5AC:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8267b5ac
	if (!cr6.eq) goto loc_8267B5AC;
loc_8267B5C0:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r30,r28,992
	r30.s64 = r28.s64 + 992;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// li r29,4
	r29.s64 = 4;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
loc_8267B5DC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B5F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267b61c
	if (cr6.eq) goto loc_8267B61C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r7,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r7.u32);
loc_8267B61C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8267b5dc
	if (!cr0.eq) goto loc_8267B5DC;
	// lwz r11,672(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 672);
	// addi r3,r28,672
	ctx.r3.s64 = r28.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267B65C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267B664"))) PPC_WEAK_FUNC(sub_8267B664);
PPC_FUNC_IMPL(__imp__sub_8267B664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B668"))) PPC_WEAK_FUNC(sub_8267B668);
PPC_FUNC_IMPL(__imp__sub_8267B668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,852(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 852);
	// addi r11,r3,848
	r11.s64 = ctx.r3.s64 + 848;
	// lwz r8,848(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x8267b6a0
	if (cr6.eq) goto loc_8267B6A0;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_8267B68C:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8267b68c
	if (!cr6.eq) goto loc_8267B68C;
loc_8267B6A0:
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// srawi r6,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 2;
	// li r4,8
	ctx.r4.s64 = 8;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// rotlwi r8,r8,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r10,992(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 992);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r6,996(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 996);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r8,r5,1
	ctx.r8.s64 = ctx.r5.s64 + 1;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lwz r5,1000(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1000);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
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
	// lwz r5,1004(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1004);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r3,-12640(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12640);
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

__attribute__((alias("__imp__sub_8267B748"))) PPC_WEAK_FUNC(sub_8267B748);
PPC_FUNC_IMPL(__imp__sub_8267B748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267B750;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-18532
	ctx.r4.s64 = ctx.r9.s64 + -18532;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-18552
	ctx.r5.s64 = ctx.r10.s64 + -18552;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267B780;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-19356
	ctx.r5.s64 = ctx.r8.s64 + -19356;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// bl 0x826349f0
	ctx.lr = 0x8267B7D0;
	sub_826349F0(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r8,31444
	r30.s64 = ctx.r8.s64 + 31444;
	// lwz r4,31444(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31444);
	// bl 0x82633d40
	ctx.lr = 0x8267B7EC;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r25,r7,-20868
	r25.s64 = ctx.r7.s64 + -20868;
	// addi r24,r6,5568
	r24.s64 = ctx.r6.s64 + 5568;
	// stw r25,1248(r31)
	PPC_STORE_U32(r31.u32 + 1248, r25.u32);
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r24,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B814;
	sub_826311F8(ctx, base);
	// addi r26,r31,1472
	r26.s64 = r31.s64 + 1472;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267B828;
	sub_82633D40(ctx, base);
	// stw r25,1472(r31)
	PPC_STORE_U32(r31.u32 + 1472, r25.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// stw r24,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r24.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267B840;
	sub_826311F8(ctx, base);
	// addi r24,r31,672
	r24.s64 = r31.s64 + 672;
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,31436
	ctx.r4.s64 = ctx.r4.s64 + 31436;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267B858;
	sub_826347F0(ctx, base);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267B88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267B898;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-20016
	ctx.r4.s64 = ctx.r4.s64 + -20016;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267B8AC;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267B8B8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267b8b8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267B8B8;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267B8DC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267b8dc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267B8DC;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1436
	ctx.r10.s64 = r31.s64 + 1436;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r31,1660
	ctx.r9.s64 = r31.s64 + 1660;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stwx r28,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r28.u32);
	// lwz r10,1436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1436);
	// lhz r11,1440(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1440);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1440(r31)
	PPC_STORE_U16(r31.u32 + 1440, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,1660(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1660);
	// lhz r11,1664(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1664);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1664(r31)
	PPC_STORE_U16(r31.u32 + 1664, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267B970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r9.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8267B984"))) PPC_WEAK_FUNC(sub_8267B984);
PPC_FUNC_IMPL(__imp__sub_8267B984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267B988"))) PPC_WEAK_FUNC(sub_8267B988);
PPC_FUNC_IMPL(__imp__sub_8267B988) {
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
	// bl 0x8267b4a8
	ctx.lr = 0x8267B9A8;
	sub_8267B4A8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267b9c0
	if (cr6.eq) goto loc_8267B9C0;
	// bl 0x82130588
	ctx.lr = 0x8267B9BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267B9C0:
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

__attribute__((alias("__imp__sub_8267B9D8"))) PPC_WEAK_FUNC(sub_8267B9D8);
PPC_FUNC_IMPL(__imp__sub_8267B9D8) {
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
	ctx.lr = 0x8267B9E0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267BA10;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821fd7c0
	ctx.lr = 0x8267BA24;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r11.u8);
	// stw r11,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// stw r8,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r8.u32);
	// lwz r11,228(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267bb50
	if (cr6.eq) goto loc_8267BB50;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267BA5C;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267bb50
	if (cr6.eq) goto loc_8267BB50;
	// lwz r29,1216(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267BA70;
	sub_826CD180(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8267bb08
	if (cr6.eq) goto loc_8267BB08;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267bae4
	if (cr6.eq) goto loc_8267BAE4;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x8267bab0
	if (cr6.eq) goto loc_8267BAB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r30,10
	ctx.r4.s64 = r30.s64 + 10;
	// lwz r30,-10244(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x8267BAA4;
	sub_82218310(ctx, base);
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// b 0x8267bb44
	goto loc_8267BB44;
loc_8267BAB0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267BAC4;
	sub_826B7AB0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r5,60(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-21312
	ctx.r4.s64 = ctx.r9.s64 + -21312;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x82218788
	ctx.lr = 0x8267BAE0;
	sub_82218788(ctx, base);
	// b 0x8267bb50
	goto loc_8267BB50;
loc_8267BAE4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267BAF0;
	sub_826B7940(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r30,10
	ctx.r5.s64 = r30.s64 + 10;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// b 0x8267bb4c
	goto loc_8267BB4C;
loc_8267BB08:
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r7,r11,-17856
	ctx.r7.s64 = r11.s64 + -17856;
	// addi r5,r10,10372
	ctx.r5.s64 = ctx.r10.s64 + 10372;
	// addi r6,r30,10
	ctx.r6.s64 = r30.s64 + 10;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x8267BB28;
	sub_82137A08(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r30,-10244(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x8267BB3C;
	sub_82218310(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r8,-21312
	ctx.r4.s64 = ctx.r8.s64 + -21312;
loc_8267BB44:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8267BB4C:
	// bl 0x822183b0
	ctx.lr = 0x8267BB50;
	sub_822183B0(ctx, base);
loc_8267BB50:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r10,1664(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1664);
	// addi r3,r31,1664
	ctx.r3.s64 = r31.s64 + 1664;
	// addi r30,r11,31412
	r30.s64 = r11.s64 + 31412;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267BB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1888(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1888
	ctx.r3.s64 = r31.s64 + 1888;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267BB88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BB9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267BBA4"))) PPC_WEAK_FUNC(sub_8267BBA4);
PPC_FUNC_IMPL(__imp__sub_8267BBA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267BBA8"))) PPC_WEAK_FUNC(sub_8267BBA8);
PPC_FUNC_IMPL(__imp__sub_8267BBA8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8267BBB0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,164
	ctx.r3.s64 = ctx.r1.s64 + 164;
	// bl 0x823db670
	ctx.lr = 0x8267BBE4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fd7c0
	ctx.lr = 0x8267BBF8;
	sub_821FD7C0(ctx, base);
	// lwz r11,148(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// li r29,0
	r29.s64 = 0;
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r31,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r31.u32);
	// stb r29,244(r1)
	PPC_STORE_U8(ctx.r1.u32 + 244, r29.u8);
	// stw r29,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, r29.u32);
	// stw r8,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r8.u32);
	// beq cr6,0x8267bd40
	if (cr6.eq) goto loc_8267BD40;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267BC30;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267bd40
	if (cr6.eq) goto loc_8267BD40;
	// lwz r23,1216(r24)
	r23.u64 = PPC_LOAD_U32(r24.u32 + 1216);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267BC44;
	sub_826CD180(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r24,1696
	r31.s64 = r24.s64 + 1696;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r27,r24,1728
	r27.s64 = r24.s64 + 1728;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r25,r11,-17836
	r25.s64 = r11.s64 + -17836;
	// addi r26,r10,-21312
	r26.s64 = ctx.r10.s64 + -21312;
loc_8267BC6C:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267bcec
	if (cr6.eq) goto loc_8267BCEC;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x8267bd20
	if (!cr6.eq) goto loc_8267BD20;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7ab0
	ctx.lr = 0x8267BC90;
	sub_826B7AB0(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r22,60(r30)
	r22.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// bl 0x82217820
	ctx.lr = 0x8267BCAC;
	sub_82217820(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// rlwinm r6,r22,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x82217820
	ctx.lr = 0x8267BCC4;
	sub_82217820(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x8267BCDC;
	sub_82137A08(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x8267bd14
	goto loc_8267BD14;
loc_8267BCEC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267BCF8;
	sub_826B7940(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r30,10
	ctx.r5.s64 = r30.s64 + 10;
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8267BD08;
	sub_822183B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_8267BD14:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267BD20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267BD20:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,64
	r27.s64 = r27.s64 + 64;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x8267bc6c
	if (cr6.lt) goto loc_8267BC6C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r24,1456
	ctx.r3.s64 = r24.s64 + 1456;
	// bl 0x8262fff0
	ctx.lr = 0x8267BD40;
	sub_8262FFF0(ctx, base);
loc_8267BD40:
	// lwz r11,672(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 672);
	// addi r3,r24,672
	ctx.r3.s64 = r24.s64 + 672;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267BD54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8267BD60"))) PPC_WEAK_FUNC(sub_8267BD60);
PPC_FUNC_IMPL(__imp__sub_8267BD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267BD68;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-17000
	ctx.r4.s64 = ctx.r9.s64 + -17000;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,-17016
	ctx.r5.s64 = ctx.r10.s64 + -17016;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267BD98;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-17820
	ctx.r5.s64 = ctx.r8.s64 + -17820;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r30,1
	r30.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-328
	ctx.r4.s64 = ctx.r10.s64 + -328;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826349f0
	ctx.lr = 0x8267BDE8;
	sub_826349F0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,3998
	ctx.r4.s64 = ctx.r9.s64 + 3998;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267BE00;
	sub_82633D40(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r24,r8,31412
	r24.s64 = ctx.r8.s64 + 31412;
	// lwz r4,31412(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 31412);
	// bl 0x82633d40
	ctx.lr = 0x8267BE1C;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r23,r7,-20868
	r23.s64 = ctx.r7.s64 + -20868;
	// addi r22,r6,5568
	r22.s64 = ctx.r6.s64 + 5568;
	// stw r23,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r23.u32);
	// addi r26,r31,1664
	r26.s64 = r31.s64 + 1664;
	// lwz r4,4(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// stw r22,1664(r31)
	PPC_STORE_U32(r31.u32 + 1664, r22.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267BE44;
	sub_826311F8(ctx, base);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267BE58;
	sub_82633D40(ctx, base);
	// stw r23,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r23.u32);
	// lwz r4,12(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// addi r24,r31,1888
	r24.s64 = r31.s64 + 1888;
	// stw r22,1888(r31)
	PPC_STORE_U32(r31.u32 + 1888, r22.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267BE70;
	sub_826311F8(ctx, base);
	// stw r30,1896(r31)
	PPC_STORE_U32(r31.u32 + 1896, r30.u32);
	// lis r4,-32126
	ctx.r4.s64 = -2105409536;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,31404
	ctx.r4.s64 = ctx.r4.s64 + 31404;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x826347f0
	ctx.lr = 0x8267BE88;
	sub_826347F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// stb r3,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r3.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// li r4,0
	ctx.r4.s64 = 0;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r6,1008(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BEC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,1896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// bl 0x8262fff0
	ctx.lr = 0x8267BED0;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-17960
	ctx.r4.s64 = ctx.r4.s64 + -17960;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267BEE4;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267BEF0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267bef0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267BEF0;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267BF14:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267bf14
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267BF14;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267BF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r31,1644
	r11.s64 = r31.s64 + 1644;
	// addi r11,r31,1868
	r11.s64 = r31.s64 + 1868;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r4.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r11,1648(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lhz r11,1872(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1872);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,1868(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1868);
	// sth r4,1872(r31)
	PPC_STORE_U16(r31.u32 + 1872, ctx.r4.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8267BFCC"))) PPC_WEAK_FUNC(sub_8267BFCC);
PPC_FUNC_IMPL(__imp__sub_8267BFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267BFD0"))) PPC_WEAK_FUNC(sub_8267BFD0);
PPC_FUNC_IMPL(__imp__sub_8267BFD0) {
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
	// bl 0x82646dc8
	ctx.lr = 0x8267BFF0;
	sub_82646DC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c008
	if (cr6.eq) goto loc_8267C008;
	// bl 0x82130588
	ctx.lr = 0x8267C004;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267C008:
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

__attribute__((alias("__imp__sub_8267C020"))) PPC_WEAK_FUNC(sub_8267C020);
PPC_FUNC_IMPL(__imp__sub_8267C020) {
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
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,1896(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// bl 0x8262fff0
	ctx.lr = 0x8267C048;
	sub_8262FFF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267b9d8
	ctx.lr = 0x8267C050;
	sub_8267B9D8(ctx, base);
	// lwz r11,1896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1896);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x8267c07c
	if (!cr6.eq) goto loc_8267C07C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8267c08c
	goto loc_8267C08C;
loc_8267C07C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C088;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8267C08C:
	// lwz r9,1248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C0BC;
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

__attribute__((alias("__imp__sub_8267C0D4"))) PPC_WEAK_FUNC(sub_8267C0D4);
PPC_FUNC_IMPL(__imp__sub_8267C0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C0D8"))) PPC_WEAK_FUNC(sub_8267C0D8);
PPC_FUNC_IMPL(__imp__sub_8267C0D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8267C0E0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r4,r9,-16144
	ctx.r4.s64 = ctx.r9.s64 + -16144;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r8,r10,24324
	ctx.r8.s64 = ctx.r10.s64 + 24324;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267C114;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,-16948
	ctx.r5.s64 = ctx.r8.s64 + -16948;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r27,r31,1008
	r27.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826349f0
	ctx.lr = 0x8267C164;
	sub_826349F0(ctx, base);
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267C178;
	sub_82633D40(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r25,r31,1456
	r25.s64 = r31.s64 + 1456;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-16976
	ctx.r4.s64 = ctx.r8.s64 + -16976;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82634908
	ctx.lr = 0x8267C194;
	sub_82634908(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// addi r23,r31,1696
	r23.s64 = r31.s64 + 1696;
	// addi r6,r7,-18508
	ctx.r6.s64 = ctx.r7.s64 + -18508;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r23
	r30.u64 = r23.u64;
	// stw r6,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, ctx.r6.u32);
	// li r26,3
	r26.s64 = 3;
	// addi r24,r11,5568
	r24.s64 = r11.s64 + 5568;
loc_8267C1B4:
	// stw r24,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r24.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267C1C4;
	sub_826311F8(ctx, base);
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x8267c1b4
	if (!cr0.lt) goto loc_8267C1B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,31428
	ctx.r4.s64 = r11.s64 + 31428;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267C1E8;
	sub_826347F0(ctx, base);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267C220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267C22C;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-17496
	ctx.r4.s64 = ctx.r4.s64 + -17496;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267C240;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267C250:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267c250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267C250;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267C274:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267c274
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267C274;
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r6,0(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267C2BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r31,1644
	r11.s64 = r31.s64 + 1644;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r11,r5,1
	r11.s64 = ctx.r5.s64 + 1;
	// addi r8,r31,1704
	ctx.r8.s64 = r31.s64 + 1704;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// addi r7,r31,1712
	ctx.r7.s64 = r31.s64 + 1712;
	// addi r6,r31,1720
	ctx.r6.s64 = r31.s64 + 1720;
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r9,1648(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r5.u16);
	// stwx r23,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r23.u32);
	// lwz r9,1644(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r5,1648(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// rotlwi r11,r5,2
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r10,r5,1
	ctx.r10.s64 = ctx.r5.s64 + 1;
	// sth r10,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r10.u16);
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r11,1648(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r9.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r10,1644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1644);
	// lhz r7,1648(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 1648);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// sth r5,1648(r31)
	PPC_STORE_U16(r31.u32 + 1648, ctx.r5.u16);
	// stwx r6,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r6.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r6.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8267C378"))) PPC_WEAK_FUNC(sub_8267C378);
PPC_FUNC_IMPL(__imp__sub_8267C378) {
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
	// bl 0x82646e80
	ctx.lr = 0x8267C398;
	sub_82646E80(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c3b0
	if (cr6.eq) goto loc_8267C3B0;
	// bl 0x82130588
	ctx.lr = 0x8267C3AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267C3B0:
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

__attribute__((alias("__imp__sub_8267C3C8"))) PPC_WEAK_FUNC(sub_8267C3C8);
PPC_FUNC_IMPL(__imp__sub_8267C3C8) {
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
	ctx.lr = 0x8267C3D0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267C400;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8267C414;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267c4d0
	if (cr6.eq) goto loc_8267C4D0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267C44C;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267c498
	if (cr6.eq) goto loc_8267C498;
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// ble cr6,0x8267c498
	if (!cr6.gt) goto loc_8267C498;
	// lwz r11,1008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C478;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r9,-16088
	ctx.r4.s64 = ctx.r9.s64 + -16088;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267c4dc
	goto loc_8267C4DC;
loc_8267C498:
	// lwz r11,1008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C4B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,496(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// addi r4,r9,-16124
	ctx.r4.s64 = ctx.r9.s64 + -16124;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267C4CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267c4dc
	goto loc_8267C4DC;
loc_8267C4D0:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267C4DC;
	sub_8262FFF0(ctx, base);
loc_8267C4DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267bba8
	ctx.lr = 0x8267C4E4;
	sub_8267BBA8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267C508"))) PPC_WEAK_FUNC(sub_8267C508);
PPC_FUNC_IMPL(__imp__sub_8267C508) {
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
	// bl 0x82630580
	ctx.lr = 0x8267C518;
	sub_82630580(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267C524;
	sub_82203BD0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C534"))) PPC_WEAK_FUNC(sub_8267C534);
PPC_FUNC_IMPL(__imp__sub_8267C534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C538"))) PPC_WEAK_FUNC(sub_8267C538);
PPC_FUNC_IMPL(__imp__sub_8267C538) {
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
	// cmpwi cr6,r4,17
	cr6.compare<int32_t>(ctx.r4.s32, 17, xer);
	// beq cr6,0x8267c594
	if (cr6.eq) goto loc_8267C594;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267c57c
	if (!cr6.eq) goto loc_8267C57C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C568;
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
	ctx.lr = 0x8267C57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C57C:
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
loc_8267C594:
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

__attribute__((alias("__imp__sub_8267C5AC"))) PPC_WEAK_FUNC(sub_8267C5AC);
PPC_FUNC_IMPL(__imp__sub_8267C5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C5B0"))) PPC_WEAK_FUNC(sub_8267C5B0);
PPC_FUNC_IMPL(__imp__sub_8267C5B0) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C5C8;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C5E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267C5E8;
	sub_82216788(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C5F8"))) PPC_WEAK_FUNC(sub_8267C5F8);
PPC_FUNC_IMPL(__imp__sub_8267C5F8) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267C610;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267C614;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267C618;
	sub_822150D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C628"))) PPC_WEAK_FUNC(sub_8267C628);
PPC_FUNC_IMPL(__imp__sub_8267C628) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c690
	if (cr6.eq) goto loc_8267C690;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267c664
	if (cr6.eq) goto loc_8267C664;
	// bl 0x8267c538
	ctx.lr = 0x8267C650;
	sub_8267C538(ctx, base);
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
loc_8267C664:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C670;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C67C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C690:
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

__attribute__((alias("__imp__sub_8267C6A8"))) PPC_WEAK_FUNC(sub_8267C6A8);
PPC_FUNC_IMPL(__imp__sub_8267C6A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,17292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17292);
	// lwz r4,68(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bl 0x82267e98
	ctx.lr = 0x8267C6D0;
	sub_82267E98(ctx, base);
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267C6F0;
	sub_82641CB0(ctx, base);
	// addi r8,r3,3648
	ctx.r8.s64 = ctx.r3.s64 + 3648;
	// stw r8,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8267C70C"))) PPC_WEAK_FUNC(sub_8267C70C);
PPC_FUNC_IMPL(__imp__sub_8267C70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C710"))) PPC_WEAK_FUNC(sub_8267C710);
PPC_FUNC_IMPL(__imp__sub_8267C710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,944(r3)
	PPC_STORE_U32(ctx.r3.u32 + 944, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C71C"))) PPC_WEAK_FUNC(sub_8267C71C);
PPC_FUNC_IMPL(__imp__sub_8267C71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C720"))) PPC_WEAK_FUNC(sub_8267C720);
PPC_FUNC_IMPL(__imp__sub_8267C720) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267c784
	if (cr6.eq) goto loc_8267C784;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267c784
	if (cr6.eq) goto loc_8267C784;
	// bl 0x8223fd30
	ctx.lr = 0x8267C760;
	sub_8223FD30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8267c784
	if (!cr6.lt) goto loc_8267C784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267C784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C784:
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

__attribute__((alias("__imp__sub_8267C798"))) PPC_WEAK_FUNC(sub_8267C798);
PPC_FUNC_IMPL(__imp__sub_8267C798) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C7B8;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267C7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267C7D8;
	sub_82216788(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r11,17292(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17292);
	// lwz r4,444(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 444);
	// lwz r3,440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 440);
	// bl 0x82267e98
	ctx.lr = 0x8267C7EC;
	sub_82267E98(ctx, base);
	// lwz r6,432(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 432);
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

__attribute__((alias("__imp__sub_8267C808"))) PPC_WEAK_FUNC(sub_8267C808);
PPC_FUNC_IMPL(__imp__sub_8267C808) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,17292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17292);
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82267e98
	ctx.lr = 0x8267C830;
	sub_82267E98(ctx, base);
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
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

__attribute__((alias("__imp__sub_8267C84C"))) PPC_WEAK_FUNC(sub_8267C84C);
PPC_FUNC_IMPL(__imp__sub_8267C84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C850"))) PPC_WEAK_FUNC(sub_8267C850);
PPC_FUNC_IMPL(__imp__sub_8267C850) {
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
	// cmpwi cr6,r4,9
	cr6.compare<int32_t>(ctx.r4.s32, 9, xer);
	// beq cr6,0x8267c88c
	if (cr6.eq) goto loc_8267C88C;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c8b8
	if (cr6.eq) goto loc_8267C8B8;
	// bl 0x8267c538
	ctx.lr = 0x8267C878;
	sub_8267C538(ctx, base);
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
loc_8267C88C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C898;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C8A4;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C8B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C8B8:
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

__attribute__((alias("__imp__sub_8267C8D0"))) PPC_WEAK_FUNC(sub_8267C8D0);
PPC_FUNC_IMPL(__imp__sub_8267C8D0) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x8267c918
	if (!cr6.eq) goto loc_8267C918;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267C8F8;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267C904;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267C918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267C918:
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

__attribute__((alias("__imp__sub_8267C930"))) PPC_WEAK_FUNC(sub_8267C930);
PPC_FUNC_IMPL(__imp__sub_8267C930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267C93C"))) PPC_WEAK_FUNC(sub_8267C93C);
PPC_FUNC_IMPL(__imp__sub_8267C93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C940"))) PPC_WEAK_FUNC(sub_8267C940);
PPC_FUNC_IMPL(__imp__sub_8267C940) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267C94C"))) PPC_WEAK_FUNC(sub_8267C94C);
PPC_FUNC_IMPL(__imp__sub_8267C94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C950"))) PPC_WEAK_FUNC(sub_8267C950);
PPC_FUNC_IMPL(__imp__sub_8267C950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267c95c
	if (cr6.eq) goto loc_8267C95C;
	// b 0x8267c538
	sub_8267C538(ctx, base);
	return;
loc_8267C95C:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C964"))) PPC_WEAK_FUNC(sub_8267C964);
PPC_FUNC_IMPL(__imp__sub_8267C964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C968"))) PPC_WEAK_FUNC(sub_8267C968);
PPC_FUNC_IMPL(__imp__sub_8267C968) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267C980;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267C984;
	sub_82216648(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C994"))) PPC_WEAK_FUNC(sub_8267C994);
PPC_FUNC_IMPL(__imp__sub_8267C994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C998"))) PPC_WEAK_FUNC(sub_8267C998);
PPC_FUNC_IMPL(__imp__sub_8267C998) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267C9B0;
	sub_821E6800(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x8267C9B4;
	sub_82216788(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267C9C4"))) PPC_WEAK_FUNC(sub_8267C9C4);
PPC_FUNC_IMPL(__imp__sub_8267C9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267C9C8"))) PPC_WEAK_FUNC(sub_8267C9C8);
PPC_FUNC_IMPL(__imp__sub_8267C9C8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267c9fc
	if (cr6.eq) goto loc_8267C9FC;
	// bl 0x8267c538
	ctx.lr = 0x8267C9E8;
	sub_8267C538(ctx, base);
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
loc_8267C9FC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CA08;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CA14;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CA28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267CA40"))) PPC_WEAK_FUNC(sub_8267CA40);
PPC_FUNC_IMPL(__imp__sub_8267CA40) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CA6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// addi r3,r9,-15764
	ctx.r3.s64 = ctx.r9.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267CA78;
	sub_821E6800(ctx, base);
	// lwz r3,-12640(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267CA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267CA94;
	sub_82216788(ctx, base);
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

__attribute__((alias("__imp__sub_8267CAA8"))) PPC_WEAK_FUNC(sub_8267CAA8);
PPC_FUNC_IMPL(__imp__sub_8267CAA8) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267CAC0;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267CAC4;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267CAC8;
	sub_822150D8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267CAE4;
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

__attribute__((alias("__imp__sub_8267CAF4"))) PPC_WEAK_FUNC(sub_8267CAF4);
PPC_FUNC_IMPL(__imp__sub_8267CAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CAF8"))) PPC_WEAK_FUNC(sub_8267CAF8);
PPC_FUNC_IMPL(__imp__sub_8267CAF8) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CB24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267cb60
	if (cr6.eq) goto loc_8267CB60;
	// lfs f0,944(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 944);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,944(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8267cb60
	if (!cr6.lt) goto loc_8267CB60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CB60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267CB60:
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

__attribute__((alias("__imp__sub_8267CB78"))) PPC_WEAK_FUNC(sub_8267CB78);
PPC_FUNC_IMPL(__imp__sub_8267CB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,15004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15004);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CB88"))) PPC_WEAK_FUNC(sub_8267CB88);
PPC_FUNC_IMPL(__imp__sub_8267CB88) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8267CB90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r31,-14
	r11.s64 = r31.s64 + -14;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,45
	cr6.compare<uint32_t>(r11.u32, 45, xer);
	// bgt cr6,0x8267ccf4
	if (cr6.gt) goto loc_8267CCF4;
	// lis r12,-32152
	r12.s64 = -2107113472;
	// addi r12,r12,-13372
	r12.s64 = r12.s64 + -13372;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8267CCB4;
	case 1:
		goto loc_8267CCF4;
	case 2:
		goto loc_8267CCF4;
	case 3:
		goto loc_8267CC7C;
	case 4:
		goto loc_8267CCF4;
	case 5:
		goto loc_8267CCF4;
	case 6:
		goto loc_8267CCF4;
	case 7:
		goto loc_8267CCF4;
	case 8:
		goto loc_8267CCF4;
	case 9:
		goto loc_8267CCF4;
	case 10:
		goto loc_8267CCF4;
	case 11:
		goto loc_8267CCF4;
	case 12:
		goto loc_8267CCF4;
	case 13:
		goto loc_8267CCF4;
	case 14:
		goto loc_8267CCF4;
	case 15:
		goto loc_8267CCF4;
	case 16:
		goto loc_8267CCF4;
	case 17:
		goto loc_8267CCF4;
	case 18:
		goto loc_8267CCF4;
	case 19:
		goto loc_8267CCF4;
	case 20:
		goto loc_8267CCF4;
	case 21:
		goto loc_8267CCF4;
	case 22:
		goto loc_8267CCF4;
	case 23:
		goto loc_8267CCF4;
	case 24:
		goto loc_8267CCF4;
	case 25:
		goto loc_8267CCF4;
	case 26:
		goto loc_8267CCF4;
	case 27:
		goto loc_8267CCF4;
	case 28:
		goto loc_8267CCF4;
	case 29:
		goto loc_8267CCF4;
	case 30:
		goto loc_8267CCF4;
	case 31:
		goto loc_8267CCF4;
	case 32:
		goto loc_8267CCF4;
	case 33:
		goto loc_8267CCF4;
	case 34:
		goto loc_8267CCF4;
	case 35:
		goto loc_8267CCF4;
	case 36:
		goto loc_8267CCF4;
	case 37:
		goto loc_8267CCF4;
	case 38:
		goto loc_8267CCF4;
	case 39:
		goto loc_8267CCF4;
	case 40:
		goto loc_8267CCF4;
	case 41:
		goto loc_8267CC7C;
	case 42:
		goto loc_8267CCF4;
	case 43:
		goto loc_8267CCF4;
	case 44:
		goto loc_8267CCF4;
	case 45:
		goto loc_8267CC7C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-13132(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13132);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13068(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13068);
	// lwz r19,-13188(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + -13188);
loc_8267CC7C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CC88;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CC94;
	sub_826304B0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CCA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267CCB4:
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
	ctx.lr = 0x8267CCCC;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,276(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267CCF4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8267c538
	ctx.lr = 0x8267CD04;
	sub_8267C538(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267CD0C"))) PPC_WEAK_FUNC(sub_8267CD0C);
PPC_FUNC_IMPL(__imp__sub_8267CD0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CD10"))) PPC_WEAK_FUNC(sub_8267CD10);
PPC_FUNC_IMPL(__imp__sub_8267CD10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31376);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CD20"))) PPC_WEAK_FUNC(sub_8267CD20);
PPC_FUNC_IMPL(__imp__sub_8267CD20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 944, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8267CD30"))) PPC_WEAK_FUNC(sub_8267CD30);
PPC_FUNC_IMPL(__imp__sub_8267CD30) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267cd6c
	if (cr6.eq) goto loc_8267CD6C;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267cd6c
	if (cr6.eq) goto loc_8267CD6C;
	// bl 0x8267c538
	ctx.lr = 0x8267CD58;
	sub_8267C538(ctx, base);
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
loc_8267CD6C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CD78;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267CD84;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CD98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267CDB0"))) PPC_WEAK_FUNC(sub_8267CDB0);
PPC_FUNC_IMPL(__imp__sub_8267CDB0) {
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
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r10,-15664
	ctx.r4.s64 = ctx.r10.s64 + -15664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CDDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-15700
	ctx.r4.s64 = ctx.r8.s64 + -15700;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267CDF8;
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

__attribute__((alias("__imp__sub_8267CE0C"))) PPC_WEAK_FUNC(sub_8267CE0C);
PPC_FUNC_IMPL(__imp__sub_8267CE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CE10"))) PPC_WEAK_FUNC(sub_8267CE10);
PPC_FUNC_IMPL(__imp__sub_8267CE10) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267CE3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267ce8c
	if (cr6.eq) goto loc_8267CE8C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,944(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 944);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8267ce8c
	if (!cr6.gt) goto loc_8267CE8C;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8267ce8c
	if (!cr6.lt) goto loc_8267CE8C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-14972
	ctx.r3.s64 = r11.s64 + -14972;
	// bl 0x82215db8
	ctx.lr = 0x8267CE78;
	sub_82215DB8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267CE8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267CE8C:
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

__attribute__((alias("__imp__sub_8267CEA4"))) PPC_WEAK_FUNC(sub_8267CEA4);
PPC_FUNC_IMPL(__imp__sub_8267CEA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CEA8"))) PPC_WEAK_FUNC(sub_8267CEA8);
PPC_FUNC_IMPL(__imp__sub_8267CEA8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267cee4
	if (cr6.eq) goto loc_8267CEE4;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267cee4
	if (cr6.eq) goto loc_8267CEE4;
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
loc_8267CEE4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267CEF0;
	sub_821E6800(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f2,-6172(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6172);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,-17424(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17424);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x82207ef0
	ctx.lr = 0x8267CF08;
	sub_82207EF0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
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

__attribute__((alias("__imp__sub_8267CF2C"))) PPC_WEAK_FUNC(sub_8267CF2C);
PPC_FUNC_IMPL(__imp__sub_8267CF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CF30"))) PPC_WEAK_FUNC(sub_8267CF30);
PPC_FUNC_IMPL(__imp__sub_8267CF30) {
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
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// bl 0x822a39c0
	ctx.lr = 0x8267CF58;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267cf90
	if (cr6.eq) goto loc_8267CF90;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8267CF7C;
	sub_822A39C8(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// b 0x8267cf94
	goto loc_8267CF94;
loc_8267CF90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8267CF94:
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

__attribute__((alias("__imp__sub_8267CFAC"))) PPC_WEAK_FUNC(sub_8267CFAC);
PPC_FUNC_IMPL(__imp__sub_8267CFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267CFB0"))) PPC_WEAK_FUNC(sub_8267CFB0);
PPC_FUNC_IMPL(__imp__sub_8267CFB0) {
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
	// bl 0x82387a18
	ctx.lr = 0x8267CFD0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d004
	if (!cr6.eq) goto loc_8267D004;
	// bl 0x8267cf30
	ctx.lr = 0x8267CFE0;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d004
	if (!cr6.eq) goto loc_8267D004;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8267CFF8;
	sub_82630318(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267D004;
	sub_82203BD0(ctx, base);
loc_8267D004:
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

__attribute__((alias("__imp__sub_8267D01C"))) PPC_WEAK_FUNC(sub_8267D01C);
PPC_FUNC_IMPL(__imp__sub_8267D01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267D020"))) PPC_WEAK_FUNC(sub_8267D020);
PPC_FUNC_IMPL(__imp__sub_8267D020) {
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
	ctx.lr = 0x8267D028;
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
	// bl 0x8267cf30
	ctx.lr = 0x8267D03C;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267d054
	if (cr6.eq) goto loc_8267D054;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8267D054:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631e20
	ctx.lr = 0x8267D064;
	sub_82631E20(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267D06C"))) PPC_WEAK_FUNC(sub_8267D06C);
PPC_FUNC_IMPL(__imp__sub_8267D06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267D070"))) PPC_WEAK_FUNC(sub_8267D070);
PPC_FUNC_IMPL(__imp__sub_8267D070) {
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
	ctx.lr = 0x8267D078;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r10,-12168
	ctx.r3.s64 = ctx.r10.s64 + -12168;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x8267D0A4;
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
	ctx.lr = 0x8267D0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x8267D0BC;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8267d0f0
	if (!cr6.eq) goto loc_8267D0F0;
	// bl 0x8267cf30
	ctx.lr = 0x8267D0CC;
	sub_8267CF30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267d0f0
	if (!cr6.eq) goto loc_8267D0F0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82630318
	ctx.lr = 0x8267D0E4;
	sub_82630318(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203bd0
	ctx.lr = 0x8267D0F0;
	sub_82203BD0(ctx, base);
loc_8267D0F0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267D0F8"))) PPC_WEAK_FUNC(sub_8267D0F8);
PPC_FUNC_IMPL(__imp__sub_8267D0F8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d12c
	if (cr6.eq) goto loc_8267D12C;
	// bl 0x8267c538
	ctx.lr = 0x8267D118;
	sub_8267C538(ctx, base);
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
loc_8267D12C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D138;
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
	ctx.lr = 0x8267D14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D168;
	sub_82691650(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8262ce00
	ctx.lr = 0x8267D170;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D188"))) PPC_WEAK_FUNC(sub_8267D188);
PPC_FUNC_IMPL(__imp__sub_8267D188) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267d1f4
	if (cr6.eq) goto loc_8267D1F4;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// bne cr6,0x8267d220
	if (!cr6.eq) goto loc_8267D220;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D1B8;
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
	ctx.lr = 0x8267D1CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D1E8;
	sub_82691650(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8262ce00
	ctx.lr = 0x8267D1F0;
	sub_8262CE00(ctx, base);
	// b 0x8267d220
	goto loc_8267D220;
loc_8267D1F4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D200;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267D20C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267D220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267D220:
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

__attribute__((alias("__imp__sub_8267D238"))) PPC_WEAK_FUNC(sub_8267D238);
PPC_FUNC_IMPL(__imp__sub_8267D238) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d26c
	if (cr6.eq) goto loc_8267D26C;
	// bl 0x8267c538
	ctx.lr = 0x8267D258;
	sub_8267C538(ctx, base);
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
loc_8267D26C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D278;
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
	ctx.lr = 0x8267D28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D2A8;
	sub_82691650(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x8262ce00
	ctx.lr = 0x8267D2B0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D2C8"))) PPC_WEAK_FUNC(sub_8267D2C8);
PPC_FUNC_IMPL(__imp__sub_8267D2C8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d2fc
	if (cr6.eq) goto loc_8267D2FC;
	// bl 0x8267c538
	ctx.lr = 0x8267D2E8;
	sub_8267C538(ctx, base);
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
loc_8267D2FC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D308;
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
	ctx.lr = 0x8267D31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D338;
	sub_82691650(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8262ce00
	ctx.lr = 0x8267D340;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D358"))) PPC_WEAK_FUNC(sub_8267D358);
PPC_FUNC_IMPL(__imp__sub_8267D358) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d38c
	if (cr6.eq) goto loc_8267D38C;
	// bl 0x8267c538
	ctx.lr = 0x8267D378;
	sub_8267C538(ctx, base);
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
loc_8267D38C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D398;
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
	ctx.lr = 0x8267D3AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D3C8;
	sub_82691650(ctx, base);
	// li r4,33
	ctx.r4.s64 = 33;
	// bl 0x8262ce00
	ctx.lr = 0x8267D3D0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D3E8"))) PPC_WEAK_FUNC(sub_8267D3E8);
PPC_FUNC_IMPL(__imp__sub_8267D3E8) {
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
	ctx.lr = 0x8267D3F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8267D41C;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,59
	cr6.compare<int32_t>(r29.s32, 59, xer);
	// beq cr6,0x8267d440
	if (cr6.eq) goto loc_8267D440;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267c538
	ctx.lr = 0x8267D438;
	sub_8267C538(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8267D440:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D44C;
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
	ctx.lr = 0x8267D460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,8532(r28)
	PPC_STORE_U8(r28.u32 + 8532, ctx.r8.u8);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x8267d480
	if (!cr6.eq) goto loc_8267D480;
	// li r31,0
	r31.s64 = 0;
loc_8267D480:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-12776
	ctx.r4.s64 = ctx.r10.s64 + -12776;
	// bl 0x82691650
	ctx.lr = 0x8267D490;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267D4A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82204450
	ctx.lr = 0x8267D4A8;
	sub_82204450(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8267D4B4"))) PPC_WEAK_FUNC(sub_8267D4B4);
PPC_FUNC_IMPL(__imp__sub_8267D4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267D4B8"))) PPC_WEAK_FUNC(sub_8267D4B8);
PPC_FUNC_IMPL(__imp__sub_8267D4B8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// bne cr6,0x8267d524
	if (!cr6.eq) goto loc_8267D524;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D4E8;
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
	ctx.lr = 0x8267D4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D518;
	sub_82691650(ctx, base);
	// li r4,35
	ctx.r4.s64 = 35;
	// bl 0x8262ce00
	ctx.lr = 0x8267D520;
	sub_8262CE00(ctx, base);
	// li r4,59
	ctx.r4.s64 = 59;
loc_8267D524:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267c538
	ctx.lr = 0x8267D530;
	sub_8267C538(ctx, base);
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

__attribute__((alias("__imp__sub_8267D548"))) PPC_WEAK_FUNC(sub_8267D548);
PPC_FUNC_IMPL(__imp__sub_8267D548) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d57c
	if (cr6.eq) goto loc_8267D57C;
	// bl 0x8267c538
	ctx.lr = 0x8267D568;
	sub_8267C538(ctx, base);
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
loc_8267D57C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D588;
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
	ctx.lr = 0x8267D59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D5B8;
	sub_82691650(ctx, base);
	// li r4,36
	ctx.r4.s64 = 36;
	// bl 0x8262ce00
	ctx.lr = 0x8267D5C0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D5D8"))) PPC_WEAK_FUNC(sub_8267D5D8);
PPC_FUNC_IMPL(__imp__sub_8267D5D8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d60c
	if (cr6.eq) goto loc_8267D60C;
	// bl 0x8267c538
	ctx.lr = 0x8267D5F8;
	sub_8267C538(ctx, base);
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
loc_8267D60C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D618;
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
	ctx.lr = 0x8267D62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D648;
	sub_82691650(ctx, base);
	// li r4,37
	ctx.r4.s64 = 37;
	// bl 0x8262ce00
	ctx.lr = 0x8267D650;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D668"))) PPC_WEAK_FUNC(sub_8267D668);
PPC_FUNC_IMPL(__imp__sub_8267D668) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d69c
	if (cr6.eq) goto loc_8267D69C;
	// bl 0x8267c538
	ctx.lr = 0x8267D688;
	sub_8267C538(ctx, base);
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
loc_8267D69C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D6A8;
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
	ctx.lr = 0x8267D6BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D6D8;
	sub_82691650(ctx, base);
	// li r4,38
	ctx.r4.s64 = 38;
	// bl 0x8262ce00
	ctx.lr = 0x8267D6E0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D6F8"))) PPC_WEAK_FUNC(sub_8267D6F8);
PPC_FUNC_IMPL(__imp__sub_8267D6F8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d72c
	if (cr6.eq) goto loc_8267D72C;
	// bl 0x8267c538
	ctx.lr = 0x8267D718;
	sub_8267C538(ctx, base);
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
loc_8267D72C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D738;
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
	ctx.lr = 0x8267D74C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D768;
	sub_82691650(ctx, base);
	// li r4,39
	ctx.r4.s64 = 39;
	// bl 0x8262ce00
	ctx.lr = 0x8267D770;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D788"))) PPC_WEAK_FUNC(sub_8267D788);
PPC_FUNC_IMPL(__imp__sub_8267D788) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d7bc
	if (cr6.eq) goto loc_8267D7BC;
	// bl 0x8267c538
	ctx.lr = 0x8267D7A8;
	sub_8267C538(ctx, base);
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
loc_8267D7BC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D7C8;
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
	ctx.lr = 0x8267D7DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D7F8;
	sub_82691650(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x8262ce00
	ctx.lr = 0x8267D800;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D818"))) PPC_WEAK_FUNC(sub_8267D818);
PPC_FUNC_IMPL(__imp__sub_8267D818) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d84c
	if (cr6.eq) goto loc_8267D84C;
	// bl 0x8267c538
	ctx.lr = 0x8267D838;
	sub_8267C538(ctx, base);
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
loc_8267D84C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D858;
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
	ctx.lr = 0x8267D86C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D888;
	sub_82691650(ctx, base);
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x8262ce00
	ctx.lr = 0x8267D890;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D8A8"))) PPC_WEAK_FUNC(sub_8267D8A8);
PPC_FUNC_IMPL(__imp__sub_8267D8A8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d8dc
	if (cr6.eq) goto loc_8267D8DC;
	// bl 0x8267c538
	ctx.lr = 0x8267D8C8;
	sub_8267C538(ctx, base);
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
loc_8267D8DC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D8E8;
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
	ctx.lr = 0x8267D8FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D918;
	sub_82691650(ctx, base);
	// li r4,21
	ctx.r4.s64 = 21;
	// bl 0x8262ce00
	ctx.lr = 0x8267D920;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D938"))) PPC_WEAK_FUNC(sub_8267D938);
PPC_FUNC_IMPL(__imp__sub_8267D938) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d96c
	if (cr6.eq) goto loc_8267D96C;
	// bl 0x8267c538
	ctx.lr = 0x8267D958;
	sub_8267C538(ctx, base);
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
loc_8267D96C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267D978;
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
	ctx.lr = 0x8267D98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267D9A8;
	sub_82691650(ctx, base);
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x8262ce00
	ctx.lr = 0x8267D9B0;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267D9C8"))) PPC_WEAK_FUNC(sub_8267D9C8);
PPC_FUNC_IMPL(__imp__sub_8267D9C8) {
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
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267d9fc
	if (cr6.eq) goto loc_8267D9FC;
	// bl 0x8267c538
	ctx.lr = 0x8267D9E8;
	sub_8267C538(ctx, base);
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
loc_8267D9FC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267DA08;
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
	ctx.lr = 0x8267DA1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267DA38;
	sub_82691650(ctx, base);
	// li r4,27
	ctx.r4.s64 = 27;
	// bl 0x8262ce00
	ctx.lr = 0x8267DA40;
	sub_8262CE00(ctx, base);
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

__attribute__((alias("__imp__sub_8267DA58"))) PPC_WEAK_FUNC(sub_8267DA58);
PPC_FUNC_IMPL(__imp__sub_8267DA58) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267dae8
	if (cr6.eq) goto loc_8267DAE8;
	// cmpwi cr6,r4,59
	cr6.compare<int32_t>(ctx.r4.s32, 59, xer);
	// beq cr6,0x8267da94
	if (cr6.eq) goto loc_8267DA94;
	// bl 0x8267c538
	ctx.lr = 0x8267DA80;
	sub_8267C538(ctx, base);
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
loc_8267DA94:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267DAA0;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267DAAC;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DAC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-18792
	ctx.r4.s64 = ctx.r7.s64 + -18792;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8267DADC;
	sub_82691650(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8262ce00
	ctx.lr = 0x8267DAE4;
	sub_8262CE00(ctx, base);
	// b 0x8267db14
	goto loc_8267DB14;
loc_8267DAE8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267DAF4;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267DB00;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DB14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DB14:
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

__attribute__((alias("__imp__sub_8267DB2C"))) PPC_WEAK_FUNC(sub_8267DB2C);
PPC_FUNC_IMPL(__imp__sub_8267DB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DB30"))) PPC_WEAK_FUNC(sub_8267DB30);
PPC_FUNC_IMPL(__imp__sub_8267DB30) {
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
	// bl 0x82216788
	ctx.lr = 0x8267DB44;
	sub_82216788(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267DB50;
	sub_821E6800(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DB70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// li r8,1
	ctx.r8.s64 = 1;
	// lbz r7,176(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm r5,r7,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// rlwimi r6,r8,7,0,24
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 7) & 0xFFFFFF80) | (ctx.r6.u64 & 0xFFFFFFFF0000007F);
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// stb r6,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, ctx.r6.u8);
	// beq cr6,0x8267dba4
	if (cr6.eq) goto loc_8267DBA4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DBA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DBA4:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DBC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267DBD4;
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

__attribute__((alias("__imp__sub_8267DBE8"))) PPC_WEAK_FUNC(sub_8267DBE8);
PPC_FUNC_IMPL(__imp__sub_8267DBE8) {
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
	// bl 0x82216648
	ctx.lr = 0x8267DBFC;
	sub_82216648(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DC1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lbz r9,176(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// rlwinm r8,r9,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r7,r9,25
	ctx.r7.u64 = ctx.r9.u32 & 0x7F;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stb r7,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, ctx.r7.u8);
	// beq cr6,0x8267dc48
	if (cr6.eq) goto loc_8267DC48;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DC48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DC48:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267DC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// addi r3,r7,-15732
	ctx.r3.s64 = ctx.r7.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267DC84;
	sub_821E6800(ctx, base);
	// bl 0x822162b0
	ctx.lr = 0x8267DC88;
	sub_822162B0(ctx, base);
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

__attribute__((alias("__imp__sub_8267DC9C"))) PPC_WEAK_FUNC(sub_8267DC9C);
PPC_FUNC_IMPL(__imp__sub_8267DC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DCA0"))) PPC_WEAK_FUNC(sub_8267DCA0);
PPC_FUNC_IMPL(__imp__sub_8267DCA0) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267DCC0;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267DCDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267DCE0;
	sub_82216788(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// ori r31,r7,16256
	r31.u64 = ctx.r7.u64 | 16256;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DD00;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3648
	ctx.r3.s64 = ctx.r3.s64 + 3648;
	// li r5,1
	ctx.r5.s64 = 1;
	// lbz r4,176(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rlwinm r10,r4,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 25) & 0x1FFFFFF;
	// rlwimi r11,r5,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// stb r11,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, r11.u8);
	// beq cr6,0x8267dd34
	if (cr6.eq) goto loc_8267DD34;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DD34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DD34:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DD48;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3648
	ctx.r3.s64 = ctx.r3.s64 + 3648;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DD5C;
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

__attribute__((alias("__imp__sub_8267DD74"))) PPC_WEAK_FUNC(sub_8267DD74);
PPC_FUNC_IMPL(__imp__sub_8267DD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DD78"))) PPC_WEAK_FUNC(sub_8267DD78);
PPC_FUNC_IMPL(__imp__sub_8267DD78) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267DD98;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267DD9C;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267DDA0;
	sub_822150D8(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DDC0;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3648
	ctx.r3.s64 = ctx.r3.s64 + 3648;
	// lbz r8,176(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// rlwinm r7,r8,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r6,r8,25
	ctx.r6.u64 = ctx.r8.u32 & 0x7F;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stb r6,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, ctx.r6.u8);
	// beq cr6,0x8267ddec
	if (cr6.eq) goto loc_8267DDEC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DDEC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DE00;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3648
	ctx.r3.s64 = ctx.r3.s64 + 3648;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DE14;
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

__attribute__((alias("__imp__sub_8267DE2C"))) PPC_WEAK_FUNC(sub_8267DE2C);
PPC_FUNC_IMPL(__imp__sub_8267DE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DE30"))) PPC_WEAK_FUNC(sub_8267DE30);
PPC_FUNC_IMPL(__imp__sub_8267DE30) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15764
	ctx.r3.s64 = r11.s64 + -15764;
	// bl 0x821e6800
	ctx.lr = 0x8267DE50;
	sub_821E6800(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12640(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8267DE6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82216788
	ctx.lr = 0x8267DE70;
	sub_82216788(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// ori r31,r7,16256
	r31.u64 = ctx.r7.u64 | 16256;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DE90;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3840
	ctx.r3.s64 = ctx.r3.s64 + 3840;
	// li r5,1
	ctx.r5.s64 = 1;
	// lbz r4,176(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// rlwinm r10,r4,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 25) & 0x1FFFFFF;
	// rlwimi r11,r5,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// stb r11,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, r11.u8);
	// beq cr6,0x8267dec4
	if (cr6.eq) goto loc_8267DEC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DEC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DEC4:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DED8;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3840
	ctx.r3.s64 = ctx.r3.s64 + 3840;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DEEC;
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

__attribute__((alias("__imp__sub_8267DF04"))) PPC_WEAK_FUNC(sub_8267DF04);
PPC_FUNC_IMPL(__imp__sub_8267DF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DF08"))) PPC_WEAK_FUNC(sub_8267DF08);
PPC_FUNC_IMPL(__imp__sub_8267DF08) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-15732
	ctx.r3.s64 = r11.s64 + -15732;
	// bl 0x821e6800
	ctx.lr = 0x8267DF28;
	sub_821E6800(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8267DF2C;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8267DF30;
	sub_822150D8(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DF50;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3840
	ctx.r3.s64 = ctx.r3.s64 + 3840;
	// lbz r8,176(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 176);
	// rlwinm r7,r8,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// clrlwi r6,r8,25
	ctx.r6.u64 = ctx.r8.u32 & 0x7F;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stb r6,176(r3)
	PPC_STORE_U8(ctx.r3.u32 + 176, ctx.r6.u8);
	// beq cr6,0x8267df7c
	if (cr6.eq) goto loc_8267DF7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267DF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267DF7C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8267DF90;
	sub_82641CB0(ctx, base);
	// addi r3,r3,3840
	ctx.r3.s64 = ctx.r3.s64 + 3840;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267DFA4;
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

__attribute__((alias("__imp__sub_8267DFBC"))) PPC_WEAK_FUNC(sub_8267DFBC);
PPC_FUNC_IMPL(__imp__sub_8267DFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267DFC0"))) PPC_WEAK_FUNC(sub_8267DFC0);
PPC_FUNC_IMPL(__imp__sub_8267DFC0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,28532
	r30.s64 = r11.s64 + 28532;
	// addi r4,r9,-14792
	ctx.r4.s64 = ctx.r9.s64 + -14792;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-14820
	ctx.r5.s64 = ctx.r10.s64 + -14820;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E004;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-15620
	ctx.r7.s64 = ctx.r8.s64 + -15620;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E050"))) PPC_WEAK_FUNC(sub_8267E050);
PPC_FUNC_IMPL(__imp__sub_8267E050) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-13932
	ctx.r4.s64 = ctx.r9.s64 + -13932;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,-13956
	ctx.r5.s64 = ctx.r10.s64 + -13956;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E08C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-14756
	ctx.r7.s64 = ctx.r8.s64 + -14756;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E0B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E0D0"))) PPC_WEAK_FUNC(sub_8267E0D0);
PPC_FUNC_IMPL(__imp__sub_8267E0D0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-13072
	ctx.r4.s64 = ctx.r9.s64 + -13072;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,-13100
	ctx.r5.s64 = ctx.r10.s64 + -13100;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E10C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-13900
	ctx.r7.s64 = ctx.r8.s64 + -13900;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E150"))) PPC_WEAK_FUNC(sub_8267E150);
PPC_FUNC_IMPL(__imp__sub_8267E150) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-12204
	ctx.r4.s64 = ctx.r9.s64 + -12204;
	// addi r8,r11,28436
	ctx.r8.s64 = r11.s64 + 28436;
	// addi r5,r10,-12236
	ctx.r5.s64 = ctx.r10.s64 + -12236;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E18C;
	sub_8228F920(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r8,-13036
	ctx.r7.s64 = ctx.r8.s64 + -13036;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r6,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267E1C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E1D8"))) PPC_WEAK_FUNC(sub_8267E1D8);
PPC_FUNC_IMPL(__imp__sub_8267E1D8) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-11340
	ctx.r4.s64 = ctx.r9.s64 + -11340;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-11364
	ctx.r5.s64 = ctx.r10.s64 + -11364;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E214;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-12164
	ctx.r7.s64 = ctx.r8.s64 + -12164;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E258"))) PPC_WEAK_FUNC(sub_8267E258);
PPC_FUNC_IMPL(__imp__sub_8267E258) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-10476
	ctx.r4.s64 = ctx.r9.s64 + -10476;
	// addi r8,r11,29468
	ctx.r8.s64 = r11.s64 + 29468;
	// addi r5,r10,-10508
	ctx.r5.s64 = ctx.r10.s64 + -10508;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E294;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-11308
	ctx.r7.s64 = ctx.r8.s64 + -11308;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E2C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E2D8"))) PPC_WEAK_FUNC(sub_8267E2D8);
PPC_FUNC_IMPL(__imp__sub_8267E2D8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,29356
	r30.s64 = r11.s64 + 29356;
	// addi r4,r9,-9612
	ctx.r4.s64 = ctx.r9.s64 + -9612;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-9636
	ctx.r5.s64 = ctx.r10.s64 + -9636;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E31C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-10436
	ctx.r7.s64 = ctx.r8.s64 + -10436;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E368"))) PPC_WEAK_FUNC(sub_8267E368);
PPC_FUNC_IMPL(__imp__sub_8267E368) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,29356
	r30.s64 = r11.s64 + 29356;
	// addi r4,r9,-8760
	ctx.r4.s64 = ctx.r9.s64 + -8760;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-8780
	ctx.r5.s64 = ctx.r10.s64 + -8780;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E3AC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-9580
	ctx.r7.s64 = ctx.r8.s64 + -9580;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E3D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E3F8"))) PPC_WEAK_FUNC(sub_8267E3F8);
PPC_FUNC_IMPL(__imp__sub_8267E3F8) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r30,r11,28724
	r30.s64 = r11.s64 + 28724;
	// addi r4,r9,-7908
	ctx.r4.s64 = ctx.r9.s64 + -7908;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// addi r5,r10,-7932
	ctx.r5.s64 = ctx.r10.s64 + -7932;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E43C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-8732
	ctx.r7.s64 = ctx.r8.s64 + -8732;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
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

__attribute__((alias("__imp__sub_8267E488"))) PPC_WEAK_FUNC(sub_8267E488);
PPC_FUNC_IMPL(__imp__sub_8267E488) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-7048
	ctx.r5.s64 = r11.s64 + -7048;
	// addi r4,r10,-7076
	ctx.r4.s64 = ctx.r10.s64 + -7076;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E4C0;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-7876
	ctx.r7.s64 = ctx.r8.s64 + -7876;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29108
	ctx.r9.s64 = ctx.r10.s64 + 29108;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267E51C"))) PPC_WEAK_FUNC(sub_8267E51C);
PPC_FUNC_IMPL(__imp__sub_8267E51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267E520"))) PPC_WEAK_FUNC(sub_8267E520);
PPC_FUNC_IMPL(__imp__sub_8267E520) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-6180
	ctx.r4.s64 = ctx.r9.s64 + -6180;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-6212
	ctx.r5.s64 = ctx.r10.s64 + -6212;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E55C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-7012
	ctx.r7.s64 = ctx.r8.s64 + -7012;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E5A0"))) PPC_WEAK_FUNC(sub_8267E5A0);
PPC_FUNC_IMPL(__imp__sub_8267E5A0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-5312
	ctx.r4.s64 = ctx.r9.s64 + -5312;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-5340
	ctx.r5.s64 = ctx.r10.s64 + -5340;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E5DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-6140
	ctx.r7.s64 = ctx.r8.s64 + -6140;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E620"))) PPC_WEAK_FUNC(sub_8267E620);
PPC_FUNC_IMPL(__imp__sub_8267E620) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-4448
	ctx.r4.s64 = ctx.r9.s64 + -4448;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-4476
	ctx.r5.s64 = ctx.r10.s64 + -4476;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E65C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-5276
	ctx.r7.s64 = ctx.r8.s64 + -5276;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E688;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E6A0"))) PPC_WEAK_FUNC(sub_8267E6A0);
PPC_FUNC_IMPL(__imp__sub_8267E6A0) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,-3576
	ctx.r5.s64 = r11.s64 + -3576;
	// addi r4,r10,-3612
	ctx.r4.s64 = ctx.r10.s64 + -3612;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E6D8;
	sub_8228F920(ctx, base);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r8,r9,-4412
	ctx.r8.s64 = ctx.r9.s64 + -4412;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r7,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r7.u8);
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267E704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E71C"))) PPC_WEAK_FUNC(sub_8267E71C);
PPC_FUNC_IMPL(__imp__sub_8267E71C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267E720"))) PPC_WEAK_FUNC(sub_8267E720);
PPC_FUNC_IMPL(__imp__sub_8267E720) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-2712
	ctx.r4.s64 = ctx.r9.s64 + -2712;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-2732
	ctx.r5.s64 = ctx.r10.s64 + -2732;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E75C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-3532
	ctx.r7.s64 = ctx.r8.s64 + -3532;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E7A0"))) PPC_WEAK_FUNC(sub_8267E7A0);
PPC_FUNC_IMPL(__imp__sub_8267E7A0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-1864
	ctx.r4.s64 = ctx.r9.s64 + -1864;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-1884
	ctx.r5.s64 = ctx.r10.s64 + -1884;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E7DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-2684
	ctx.r7.s64 = ctx.r8.s64 + -2684;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E820"))) PPC_WEAK_FUNC(sub_8267E820);
PPC_FUNC_IMPL(__imp__sub_8267E820) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-1016
	ctx.r4.s64 = ctx.r9.s64 + -1016;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-1036
	ctx.r5.s64 = ctx.r10.s64 + -1036;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E85C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-1836
	ctx.r7.s64 = ctx.r8.s64 + -1836;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E8A0"))) PPC_WEAK_FUNC(sub_8267E8A0);
PPC_FUNC_IMPL(__imp__sub_8267E8A0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-168
	ctx.r4.s64 = ctx.r9.s64 + -168;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,-188
	ctx.r5.s64 = ctx.r10.s64 + -188;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E8DC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-988
	ctx.r7.s64 = ctx.r8.s64 + -988;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E920"))) PPC_WEAK_FUNC(sub_8267E920);
PPC_FUNC_IMPL(__imp__sub_8267E920) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,688
	ctx.r4.s64 = ctx.r9.s64 + 688;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,660
	ctx.r5.s64 = ctx.r10.s64 + 660;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E95C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,-140
	ctx.r7.s64 = ctx.r8.s64 + -140;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267E988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267E9A0"))) PPC_WEAK_FUNC(sub_8267E9A0);
PPC_FUNC_IMPL(__imp__sub_8267E9A0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,1552
	ctx.r4.s64 = ctx.r9.s64 + 1552;
	// addi r8,r11,28532
	ctx.r8.s64 = r11.s64 + 28532;
	// addi r5,r10,1524
	ctx.r5.s64 = ctx.r10.s64 + 1524;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267E9DC;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,724
	ctx.r6.s64 = ctx.r7.s64 + 724;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267EA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EA2C"))) PPC_WEAK_FUNC(sub_8267EA2C);
PPC_FUNC_IMPL(__imp__sub_8267EA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EA30"))) PPC_WEAK_FUNC(sub_8267EA30);
PPC_FUNC_IMPL(__imp__sub_8267EA30) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,2416
	ctx.r4.s64 = ctx.r9.s64 + 2416;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,2388
	ctx.r5.s64 = ctx.r10.s64 + 2388;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EA6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,1588
	ctx.r7.s64 = ctx.r8.s64 + 1588;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EA98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EAB0"))) PPC_WEAK_FUNC(sub_8267EAB0);
PPC_FUNC_IMPL(__imp__sub_8267EAB0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,3280
	ctx.r4.s64 = ctx.r9.s64 + 3280;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,3252
	ctx.r5.s64 = ctx.r10.s64 + 3252;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EAEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,2452
	ctx.r7.s64 = ctx.r8.s64 + 2452;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EB18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EB30"))) PPC_WEAK_FUNC(sub_8267EB30);
PPC_FUNC_IMPL(__imp__sub_8267EB30) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,4140
	ctx.r4.s64 = ctx.r9.s64 + 4140;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,4116
	ctx.r5.s64 = ctx.r10.s64 + 4116;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EB6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,3316
	ctx.r7.s64 = ctx.r8.s64 + 3316;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EB98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EBB0"))) PPC_WEAK_FUNC(sub_8267EBB0);
PPC_FUNC_IMPL(__imp__sub_8267EBB0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,4992
	ctx.r4.s64 = ctx.r9.s64 + 4992;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,4972
	ctx.r5.s64 = ctx.r10.s64 + 4972;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EBEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,4172
	ctx.r7.s64 = ctx.r8.s64 + 4172;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EC18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EC30"))) PPC_WEAK_FUNC(sub_8267EC30);
PPC_FUNC_IMPL(__imp__sub_8267EC30) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,5844
	ctx.r4.s64 = ctx.r9.s64 + 5844;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,5820
	ctx.r5.s64 = ctx.r10.s64 + 5820;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EC6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,5020
	ctx.r7.s64 = ctx.r8.s64 + 5020;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EC98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267ECB0"))) PPC_WEAK_FUNC(sub_8267ECB0);
PPC_FUNC_IMPL(__imp__sub_8267ECB0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,6700
	ctx.r4.s64 = ctx.r9.s64 + 6700;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,6676
	ctx.r5.s64 = ctx.r10.s64 + 6676;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267ECEC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,5876
	ctx.r7.s64 = ctx.r8.s64 + 5876;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267ED18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267ED30"))) PPC_WEAK_FUNC(sub_8267ED30);
PPC_FUNC_IMPL(__imp__sub_8267ED30) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,7556
	ctx.r4.s64 = ctx.r9.s64 + 7556;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,7532
	ctx.r5.s64 = ctx.r10.s64 + 7532;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267ED6C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,6732
	ctx.r7.s64 = ctx.r8.s64 + 6732;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267ED98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EDBC"))) PPC_WEAK_FUNC(sub_8267EDBC);
PPC_FUNC_IMPL(__imp__sub_8267EDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EDC0"))) PPC_WEAK_FUNC(sub_8267EDC0);
PPC_FUNC_IMPL(__imp__sub_8267EDC0) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,8416
	ctx.r4.s64 = ctx.r9.s64 + 8416;
	// addi r8,r11,28348
	ctx.r8.s64 = r11.s64 + 28348;
	// addi r5,r10,8388
	ctx.r5.s64 = ctx.r10.s64 + 8388;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EDFC;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,7588
	ctx.r7.s64 = ctx.r8.s64 + 7588;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EE28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EE4C"))) PPC_WEAK_FUNC(sub_8267EE4C);
PPC_FUNC_IMPL(__imp__sub_8267EE4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EE50"))) PPC_WEAK_FUNC(sub_8267EE50);
PPC_FUNC_IMPL(__imp__sub_8267EE50) {
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
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,9284
	ctx.r4.s64 = ctx.r9.s64 + 9284;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,9252
	ctx.r5.s64 = ctx.r10.s64 + 9252;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EE8C;
	sub_8228F920(ctx, base);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,8452
	ctx.r7.s64 = ctx.r8.s64 + 8452;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,29356
	ctx.r9.s64 = ctx.r10.s64 + 29356;
	// stw r9,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8267EEDC"))) PPC_WEAK_FUNC(sub_8267EEDC);
PPC_FUNC_IMPL(__imp__sub_8267EEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EEE0"))) PPC_WEAK_FUNC(sub_8267EEE0);
PPC_FUNC_IMPL(__imp__sub_8267EEE0) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,10160
	ctx.r4.s64 = ctx.r9.s64 + 10160;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,10124
	ctx.r5.s64 = ctx.r10.s64 + 10124;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EF1C;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,9324
	ctx.r6.s64 = ctx.r7.s64 + 9324;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267EF54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EF6C"))) PPC_WEAK_FUNC(sub_8267EF6C);
PPC_FUNC_IMPL(__imp__sub_8267EF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267EF70"))) PPC_WEAK_FUNC(sub_8267EF70);
PPC_FUNC_IMPL(__imp__sub_8267EF70) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r11,11028
	ctx.r5.s64 = r11.s64 + 11028;
	// addi r4,r10,11004
	ctx.r4.s64 = ctx.r10.s64 + 11004;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267EFA8;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r7,r8,10204
	ctx.r7.s64 = ctx.r8.s64 + 10204;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r6,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r6.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267EFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267EFF8"))) PPC_WEAK_FUNC(sub_8267EFF8);
PPC_FUNC_IMPL(__imp__sub_8267EFF8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,11888
	ctx.r4.s64 = ctx.r9.s64 + 11888;
	// addi r8,r11,28412
	ctx.r8.s64 = r11.s64 + 28412;
	// addi r5,r10,11860
	ctx.r5.s64 = ctx.r10.s64 + 11860;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267F034;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,11060
	ctx.r6.s64 = ctx.r7.s64 + 11060;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F06C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267F084"))) PPC_WEAK_FUNC(sub_8267F084);
PPC_FUNC_IMPL(__imp__sub_8267F084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F088"))) PPC_WEAK_FUNC(sub_8267F088);
PPC_FUNC_IMPL(__imp__sub_8267F088) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,-15664
	ctx.r4.s64 = ctx.r9.s64 + -15664;
	// addi r8,r11,28428
	ctx.r8.s64 = r11.s64 + 28428;
	// addi r5,r10,-15700
	ctx.r5.s64 = ctx.r10.s64 + -15700;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8267F0C4;
	sub_8228F920(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r6,r7,11924
	ctx.r6.s64 = ctx.r7.s64 + 11924;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stb r5,244(r31)
	PPC_STORE_U8(r31.u32 + 244, ctx.r5.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// stfs f0,944(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F0FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267F114"))) PPC_WEAK_FUNC(sub_8267F114);
PPC_FUNC_IMPL(__imp__sub_8267F114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F118"))) PPC_WEAK_FUNC(sub_8267F118);
PPC_FUNC_IMPL(__imp__sub_8267F118) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267f148
	if (cr6.eq) goto loc_8267F148;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267f170
	if (cr6.eq) goto loc_8267F170;
	// bl 0x826537d0
	ctx.lr = 0x8267F144;
	sub_826537D0(ctx, base);
	// b 0x8267f2c4
	goto loc_8267F2C4;
loc_8267F148:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8267F154;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267f164
	if (cr6.lt) goto loc_8267F164;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8267F164:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8267f254
	if (cr6.lt) goto loc_8267F254;
	// beq cr6,0x8267f1a0
	if (cr6.eq) goto loc_8267F1A0;
loc_8267F170:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267F17C;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F188;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F1A0:
	// lwz r11,1200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// addi r3,r31,1200
	ctx.r3.s64 = r31.s64 + 1200;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F1B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267f2b4
	if (cr6.eq) goto loc_8267F2B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F1CC;
	sub_821E6800(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x8267F1D0;
	sub_82387B90(ctx, base);
	// lwz r10,1340(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x8267f200
	if (!cr6.gt) goto loc_8267F200;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F1E8;
	sub_826304B0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F200:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r4,r11,23088
	ctx.r4.s64 = r11.s64 + 23088;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r10,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r10.u8);
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x823da950
	ctx.lr = 0x8267F21C;
	sub_823DA950(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// addi r9,r9,3998
	ctx.r9.s64 = ctx.r9.s64 + 3998;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r5,-32245
	ctx.r5.s64 = -2113208320;
	// addi r6,r7,13148
	ctx.r6.s64 = ctx.r7.s64 + 13148;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r8,r8,5928
	ctx.r8.s64 = ctx.r8.s64 + 5928;
	// addi r5,r5,13116
	ctx.r5.s64 = ctx.r5.s64 + 13116;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82634db0
	ctx.lr = 0x8267F250;
	sub_82634DB0(ctx, base);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F254:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8267F25C;
	sub_82203240(ctx, base);
	// mulli r11,r3,208
	r11.s64 = ctx.r3.s64 * 208;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// lwz r11,992(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 992);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8267f2b4
	if (cr6.eq) goto loc_8267F2B4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F290;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F29C;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F2B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267f2c0
	goto loc_8267F2C0;
loc_8267F2B4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267F2C0;
	sub_821E6800(ctx, base);
loc_8267F2C0:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8267F2C4:
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

__attribute__((alias("__imp__sub_8267F2DC"))) PPC_WEAK_FUNC(sub_8267F2DC);
PPC_FUNC_IMPL(__imp__sub_8267F2DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F2E0"))) PPC_WEAK_FUNC(sub_8267F2E0);
PPC_FUNC_IMPL(__imp__sub_8267F2E0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8267F2E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,1504
	ctx.r3.s64 = r31.s64 + 1504;
	// lwz r30,1216(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267F308;
	sub_826B7AB0(ctx, base);
	// lwz r9,1564(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1564);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,-28964(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28964);
	f0.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// beq cr6,0x8267f35c
	if (cr6.eq) goto loc_8267F35C;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// beq cr6,0x8267f350
	if (cr6.eq) goto loc_8267F350;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// bne cr6,0x8267f368
	if (!cr6.eq) goto loc_8267F368;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,19404(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 19404);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8267f364
	goto loc_8267F364;
loc_8267F350:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,31932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31932);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8267f364
	goto loc_8267F364;
loc_8267F35C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-26928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26928);
	ctx.f13.f64 = double(temp.f32);
loc_8267F364:
	// fmuls f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8267F368:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r11,20
	r11.s64 = 20;
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r11,r10,r11
	r11.s32 = ctx.r10.s32 / r11.s32;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// li r6,-20
	ctx.r6.s64 = -20;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,5
	ctx.r7.s64 = 5;
	// extsw r5,r11
	ctx.r5.s64 = r11.s32;
	// lfs f0,18892(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18892);
	f0.f64 = double(temp.f32);
	// addi r10,r31,1248
	ctx.r10.s64 = r31.s64 + 1248;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// divw r9,r4,r6
	ctx.r9.s32 = ctx.r4.s32 / ctx.r6.s32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// divw r6,r8,r7
	ctx.r6.s32 = ctx.r8.s32 / ctx.r7.s32;
	// divw r9,r6,r7
	ctx.r9.s32 = ctx.r6.s32 / ctx.r7.s32;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r9,r8
	r30.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// subf r5,r9,r11
	ctx.r5.s64 = r11.s64 - ctx.r9.s64;
	// add r29,r9,r11
	r29.u64 = ctx.r9.u64 + r11.u64;
	// stw r5,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, ctx.r5.u32);
	// lwz r4,1464(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1464);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// stw r11,1464(r31)
	PPC_STORE_U32(r31.u32 + 1464, r11.u32);
	// beq cr6,0x8267f414
	if (cr6.eq) goto loc_8267F414;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,228
	ctx.r3.s64 = ctx.r10.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8267F414;
	sub_821C3048(ctx, base);
loc_8267F414:
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r29,1460(r31)
	PPC_STORE_U32(r31.u32 + 1460, r29.u32);
	// stw r30,1468(r31)
	PPC_STORE_U32(r31.u32 + 1468, r30.u32);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267F430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F438"))) PPC_WEAK_FUNC(sub_8267F438);
PPC_FUNC_IMPL(__imp__sub_8267F438) {
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
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267F458;
	sub_8262FFF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8267f2e0
	ctx.lr = 0x8267F460;
	sub_8267F2E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267F468;
	sub_82653B30(ctx, base);
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

__attribute__((alias("__imp__sub_8267F47C"))) PPC_WEAK_FUNC(sub_8267F47C);
PPC_FUNC_IMPL(__imp__sub_8267F47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F480"))) PPC_WEAK_FUNC(sub_8267F480);
PPC_FUNC_IMPL(__imp__sub_8267F480) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267f4d0
	if (cr6.eq) goto loc_8267F4D0;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8267f4bc
	if (cr6.eq) goto loc_8267F4BC;
	// bl 0x826537d0
	ctx.lr = 0x8267F4A8;
	sub_826537D0(ctx, base);
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
loc_8267F4BC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8267F4C8;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8267f4e0
	goto loc_8267F4E0;
loc_8267F4D0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267F4DC;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
loc_8267F4E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8267F4E8;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8267F514"))) PPC_WEAK_FUNC(sub_8267F514);
PPC_FUNC_IMPL(__imp__sub_8267F514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F518"))) PPC_WEAK_FUNC(sub_8267F518);
PPC_FUNC_IMPL(__imp__sub_8267F518) {
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
	// bl 0x826535f8
	ctx.lr = 0x8267F530;
	sub_826535F8(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267f590
	if (cr6.eq) goto loc_8267F590;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14556
	ctx.r4.s64 = ctx.r10.s64 + -14556;
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// lwz r5,508(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// bl 0x825ee0e0
	ctx.lr = 0x8267F554;
	sub_825EE0E0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r4,r8,13184
	ctx.r4.s64 = ctx.r8.s64 + 13184;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8267F568;
	sub_82218310(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r7,13172
	ctx.r4.s64 = ctx.r7.s64 + 13172;
	// bl 0x825ee2d8
	ctx.lr = 0x8267F57C;
	sub_825EE2D8(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r6,-10268
	ctx.r4.s64 = ctx.r6.s64 + -10268;
	// bl 0x825ee0e0
	ctx.lr = 0x8267F590;
	sub_825EE0E0(ctx, base);
loc_8267F590:
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

__attribute__((alias("__imp__sub_8267F5A4"))) PPC_WEAK_FUNC(sub_8267F5A4);
PPC_FUNC_IMPL(__imp__sub_8267F5A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F5A8"))) PPC_WEAK_FUNC(sub_8267F5A8);
PPC_FUNC_IMPL(__imp__sub_8267F5A8) {
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
	ctx.lr = 0x8267F5B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267F5D4;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r30.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r29,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r29.u32);
	// addi r9,r10,-29700
	ctx.r9.s64 = ctx.r10.s64 + -29700;
	// stw r28,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r28.u32);
	// stw r11,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r11.u32);
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,224(r31)
	PPC_STORE_U8(r31.u32 + 224, r11.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8267F600;
	sub_821C2F70(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,13196
	ctx.r4.s64 = ctx.r6.s64 + 13196;
	// lwz r11,24600(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24600);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r11.u32);
	// lwz r11,24596(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24596);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r5,224(r31)
	PPC_STORE_U8(r31.u32 + 224, ctx.r5.u8);
	// stw r11,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267F638"))) PPC_WEAK_FUNC(sub_8267F638);
PPC_FUNC_IMPL(__imp__sub_8267F638) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8267F640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,14700
	ctx.r4.s64 = ctx.r9.s64 + 14700;
	// addi r8,r11,28484
	ctx.r8.s64 = r11.s64 + 28484;
	// addi r5,r10,14680
	ctx.r5.s64 = ctx.r10.s64 + 14680;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267F670;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
	// addi r7,r8,13876
	ctx.r7.s64 = ctx.r8.s64 + 13876;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r29
	r28.u64 = r29.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
loc_8267F690:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267F6A0;
	sub_82633D40(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,208
	r28.s64 = r28.s64 + 208;
	// bge 0x8267f690
	if (!cr0.lt) goto loc_8267F690;
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// bl 0x82634b60
	ctx.lr = 0x8267F6B4;
	sub_82634B60(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,13860
	ctx.r4.s64 = r11.s64 + 13860;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267F6D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1200(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,13848
	ctx.r4.s64 = ctx.r8.s64 + 13848;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267F6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8267F738"))) PPC_WEAK_FUNC(sub_8267F738);
PPC_FUNC_IMPL(__imp__sub_8267F738) {
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
	// bl 0x82646c40
	ctx.lr = 0x8267F758;
	sub_82646C40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267f770
	if (cr6.eq) goto loc_8267F770;
	// bl 0x82130588
	ctx.lr = 0x8267F76C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267F770:
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

__attribute__((alias("__imp__sub_8267F788"))) PPC_WEAK_FUNC(sub_8267F788);
PPC_FUNC_IMPL(__imp__sub_8267F788) {
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
	ctx.lr = 0x8267F790;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,15548
	ctx.r4.s64 = ctx.r9.s64 + 15548;
	// addi r8,r11,24324
	ctx.r8.s64 = r11.s64 + 24324;
	// addi r5,r10,15528
	ctx.r5.s64 = ctx.r10.s64 + 15528;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267F7C0;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,14724
	ctx.r5.s64 = ctx.r8.s64 + 14724;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r30,r31,1008
	r30.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// li r6,1
	ctx.r6.s64 = 1;
	// bl 0x826349f0
	ctx.lr = 0x8267F810;
	sub_826349F0(ctx, base);
	// addi r29,r31,1248
	r29.s64 = r31.s64 + 1248;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8267f5a8
	ctx.lr = 0x8267F828;
	sub_8267F5A8(ctx, base);
	// addi r3,r31,1504
	ctx.r3.s64 = r31.s64 + 1504;
	// bl 0x826b6ba0
	ctx.lr = 0x8267F830;
	sub_826B6BA0(ctx, base);
	// lwz r8,1008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267F848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267F854;
	sub_8262FFF0(ctx, base);
	// lis r6,-32152
	ctx.r6.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,-3360
	ctx.r4.s64 = ctx.r6.s64 + -3360;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267F868;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267F878:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267f878
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267F878;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267F89C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267f89c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267F89C;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F8EC"))) PPC_WEAK_FUNC(sub_8267F8EC);
PPC_FUNC_IMPL(__imp__sub_8267F8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F8F0"))) PPC_WEAK_FUNC(sub_8267F8F0);
PPC_FUNC_IMPL(__imp__sub_8267F8F0) {
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
	// bl 0x82646c98
	ctx.lr = 0x8267F910;
	sub_82646C98(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267f928
	if (cr6.eq) goto loc_8267F928;
	// bl 0x82130588
	ctx.lr = 0x8267F924;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8267F928:
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

__attribute__((alias("__imp__sub_8267F940"))) PPC_WEAK_FUNC(sub_8267F940);
PPC_FUNC_IMPL(__imp__sub_8267F940) {
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
	ctx.lr = 0x8267F948;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,15568
	ctx.r4.s64 = ctx.r9.s64 + 15568;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x8267F974;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8267F988;
	sub_821FD7C0(ctx, base);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r31,0
	r31.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r31.u8);
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// beq cr6,0x8267f9d0
	if (cr6.eq) goto loc_8267F9D0;
	// bl 0x822031a8
	ctx.lr = 0x8267F9B4;
	sub_822031A8(ctx, base);
	// bl 0x826be6d0
	ctx.lr = 0x8267F9B8;
	sub_826BE6D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8267f9c4
	if (!cr6.gt) goto loc_8267F9C4;
	// li r31,1
	r31.s64 = 1;
loc_8267F9C4:
	// clrlwi r3,r31,24
	ctx.r3.u64 = r31.u32 & 0xFF;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_8267F9D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267F9DC"))) PPC_WEAK_FUNC(sub_8267F9DC);
PPC_FUNC_IMPL(__imp__sub_8267F9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267F9E0"))) PPC_WEAK_FUNC(sub_8267F9E0);
PPC_FUNC_IMPL(__imp__sub_8267F9E0) {
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
	ctx.lr = 0x8267F9E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267F9F4;
	sub_82653B30(ctx, base);
	// lwz r11,992(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FA0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// lwz r29,1200(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1200);
	// bl 0x8267f940
	ctx.lr = 0x8267FA1C;
	sub_8267F940(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,76(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267FA30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267FA38"))) PPC_WEAK_FUNC(sub_8267FA38);
PPC_FUNC_IMPL(__imp__sub_8267FA38) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8267FA40;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x823d9890
	ctx.lr = 0x8267FA60;
	sub_823D9890(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x8267FA88;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821fd7c0
	ctx.lr = 0x8267FA9C;
	sub_821FD7C0(ctx, base);
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r30,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, r30.u8);
	// stw r30,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r30.u32);
	// stw r29,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r29.u32);
	// stw r8,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r8.u32);
	// beq cr6,0x8267fb2c
	if (cr6.eq) goto loc_8267FB2C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r11,92
	ctx.r4.s64 = r11.s64 + 92;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267FAD0;
	sub_826BE498(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267fb2c
	if (cr6.eq) goto loc_8267FB2C;
	// lwz r29,1216(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826cd180
	ctx.lr = 0x8267FAE4;
	sub_826CD180(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x8267fb10
	if (cr6.eq) goto loc_8267FB10;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x8267fb1c
	if (!cr6.eq) goto loc_8267FB1C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f1,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826b7ab0
	ctx.lr = 0x8267FB0C;
	sub_826B7AB0(ctx, base);
	// b 0x8267fb1c
	goto loc_8267FB1C;
loc_8267FB10:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b7940
	ctx.lr = 0x8267FB1C;
	sub_826B7940(ctx, base);
loc_8267FB1C:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r30,10
	ctx.r4.s64 = r30.s64 + 10;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x8267FB2C;
	sub_823DB670(ctx, base);
loc_8267FB2C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-21312
	ctx.r4.s64 = ctx.r10.s64 + -21312;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8267FB44;
	sub_822183B0(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lwz r8,1456(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1456);
	// addi r3,r31,1456
	ctx.r3.s64 = r31.s64 + 1456;
	// addi r30,r9,-32520
	r30.s64 = ctx.r9.s64 + -32520;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8267FB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1680(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1680);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r3,r31,1680
	ctx.r3.s64 = r31.s64 + 1680;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8267FB7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,672(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r11,184(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8267FB90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8267FB98"))) PPC_WEAK_FUNC(sub_8267FB98);
PPC_FUNC_IMPL(__imp__sub_8267FB98) {
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
	ctx.lr = 0x8267FBA0;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,-17848
	ctx.r4.s64 = ctx.r9.s64 + -17848;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823db670
	ctx.lr = 0x8267FBD0;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x8267FBE4;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267fc98
	if (cr6.eq) goto loc_8267FC98;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r31,r11,92
	r31.s64 = r11.s64 + 92;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10020(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// bl 0x826be498
	ctx.lr = 0x8267FC20;
	sub_826BE498(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8267fc7c
	if (cr6.eq) goto loc_8267FC7C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8267fc7c
	if (cr6.eq) goto loc_8267FC7C;
	// addi r31,r29,1008
	r31.s64 = r29.s64 + 1008;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267FC44;
	sub_8262FFF0(ctx, base);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// ble cr6,0x8267fc6c
	if (!cr6.gt) goto loc_8267FC6C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC6C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC7C:
	// lwz r11,1008(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 1008);
	// addi r3,r29,1008
	ctx.r3.s64 = r29.s64 + 1008;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267FC94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8267fca4
	goto loc_8267FCA4;
loc_8267FC98:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r29,1008
	ctx.r3.s64 = r29.s64 + 1008;
	// bl 0x8262fff0
	ctx.lr = 0x8267FCA4;
	sub_8262FFF0(ctx, base);
loc_8267FCA4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8267fa38
	ctx.lr = 0x8267FCAC;
	sub_8267FA38(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82653b30
	ctx.lr = 0x8267FCB4;
	sub_82653B30(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8267FCBC"))) PPC_WEAK_FUNC(sub_8267FCBC);
PPC_FUNC_IMPL(__imp__sub_8267FCBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8267FCC0"))) PPC_WEAK_FUNC(sub_8267FCC0);
PPC_FUNC_IMPL(__imp__sub_8267FCC0) {
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
	// bl 0x82653670
	ctx.lr = 0x8267FCDC;
	sub_82653670(ctx, base);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8267FCE4;
	sub_82631F88(ctx, base);
	// lwz r31,856(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8267fcf4
	if (cr6.lt) goto loc_8267FCF4;
	// addi r31,r3,-1
	r31.s64 = ctx.r3.s64 + -1;
loc_8267FCF4:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,2476
	ctx.r4.s64 = ctx.r10.s64 + 2476;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8267FD0C;
	sub_821FD980(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// stw r31,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r31.u32);
	// bl 0x823dc018
	ctx.lr = 0x8267FD28;
	sub_823DC018(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,156(r30)
	PPC_STORE_U32(r30.u32 + 156, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8267FD48"))) PPC_WEAK_FUNC(sub_8267FD48);
PPC_FUNC_IMPL(__imp__sub_8267FD48) {
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
	// bl 0x82653670
	ctx.lr = 0x8267FD64;
	sub_82653670(ctx, base);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8267fd98
	if (cr6.eq) goto loc_8267FD98;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-10268
	ctx.r4.s64 = r11.s64 + -10268;
	// bl 0x825ee0e0
	ctx.lr = 0x8267FD80;
	sub_825EE0E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// addi r4,r9,13172
	ctx.r4.s64 = ctx.r9.s64 + 13172;
	// bl 0x825ee2d8
	ctx.lr = 0x8267FD98;
	sub_825EE2D8(ctx, base);
loc_8267FD98:
	// lwz r11,1248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1248);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r3,r31,1248
	ctx.r3.s64 = r31.s64 + 1248;
	// lwz r31,-24180(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267FDB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r8,9720
	ctx.r4.s64 = ctx.r8.s64 + 9720;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fd980
	ctx.lr = 0x8267FDCC;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r7,32684
	ctx.r4.s64 = ctx.r7.s64 + 32684;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x8267FDE8;
	sub_823DC018(ctx, base);
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r6,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8267FE08"))) PPC_WEAK_FUNC(sub_8267FE08);
PPC_FUNC_IMPL(__imp__sub_8267FE08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8267FE10;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32245
	ctx.r9.s64 = -2113208320;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32245
	ctx.r10.s64 = -2113208320;
	// addi r4,r9,16412
	ctx.r4.s64 = ctx.r9.s64 + 16412;
	// addi r8,r11,28484
	ctx.r8.s64 = r11.s64 + 28484;
	// addi r5,r10,16392
	ctx.r5.s64 = ctx.r10.s64 + 16392;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8267FE40;
	sub_82654318(ctx, base);
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32129
	ctx.r6.s64 = -2105606144;
	// addi r5,r8,15588
	ctx.r5.s64 = ctx.r8.s64 + 15588;
	// addi r3,r6,-28140
	ctx.r3.s64 = ctx.r6.s64 + -28140;
	// addi r4,r7,7428
	ctx.r4.s64 = ctx.r7.s64 + 7428;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// li r11,4
	r11.s64 = 4;
	// stw r3,996(r31)
	PPC_STORE_U32(r31.u32 + 996, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r4,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r4.u32);
	// stw r11,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r10,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, ctx.r10.u32);
	// addi r29,r31,1008
	r29.s64 = r31.s64 + 1008;
	// addi r5,r31,992
	ctx.r5.s64 = r31.s64 + 992;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-328
	ctx.r4.s64 = ctx.r9.s64 + -328;
	// bl 0x826349f0
	ctx.lr = 0x8267FE90;
	sub_826349F0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r28,r31,1248
	r28.s64 = r31.s64 + 1248;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r8,-32520
	r30.s64 = ctx.r8.s64 + -32520;
	// lwz r4,-32520(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32520);
	// bl 0x82633d40
	ctx.lr = 0x8267FEAC;
	sub_82633D40(ctx, base);
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r25,r7,-20868
	r25.s64 = ctx.r7.s64 + -20868;
	// addi r24,r6,5568
	r24.s64 = ctx.r6.s64 + 5568;
	// stw r25,1248(r31)
	PPC_STORE_U32(r31.u32 + 1248, r25.u32);
	// addi r27,r31,1456
	r27.s64 = r31.s64 + 1456;
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r24,1456(r31)
	PPC_STORE_U32(r31.u32 + 1456, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267FED4;
	sub_826311F8(ctx, base);
	// addi r26,r31,1472
	r26.s64 = r31.s64 + 1472;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8267FEE8;
	sub_82633D40(ctx, base);
	// stw r25,1472(r31)
	PPC_STORE_U32(r31.u32 + 1472, r25.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r25,r31,1680
	r25.s64 = r31.s64 + 1680;
	// stw r24,1680(r31)
	PPC_STORE_U32(r31.u32 + 1680, r24.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826311f8
	ctx.lr = 0x8267FF00;
	sub_826311F8(ctx, base);
	// addi r24,r31,672
	r24.s64 = r31.s64 + 672;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r4,-32536
	ctx.r4.s64 = ctx.r4.s64 + -32536;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826347f0
	ctx.lr = 0x8267FF18;
	sub_826347F0(ctx, base);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r30,r31,848
	r30.s64 = r31.s64 + 848;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r7,1008(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267FF4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262fff0
	ctx.lr = 0x8267FF58;
	sub_8262FFF0(ctx, base);
	// lis r4,-32152
	ctx.r4.s64 = -2107113472;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-1480
	ctx.r4.s64 = ctx.r4.s64 + -1480;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8267FF6C;
	sub_821C2F90(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r11,5
	r11.s64 = 5;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_8267FF78:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267ff78
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267FF78;
	// addi r10,r31,1220
	ctx.r10.s64 = r31.s64 + 1220;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8267FF9C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8267ff9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8267FF9C;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r10,r31,1436
	ctx.r10.s64 = r31.s64 + 1436;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r31,1660
	ctx.r9.s64 = r31.s64 + 1660;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stwx r28,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, r28.u32);
	// lwz r10,1436(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1436);
	// lhz r11,1440(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1440);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1440(r31)
	PPC_STORE_U16(r31.u32 + 1440, ctx.r6.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r8.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,1660(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1660);
	// lhz r11,1664(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1664);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,1664(r31)
	PPC_STORE_U16(r31.u32 + 1664, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82680030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r9,876(r31)
	PPC_STORE_U8(r31.u32 + 876, ctx.r9.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82680044"))) PPC_WEAK_FUNC(sub_82680044);
PPC_FUNC_IMPL(__imp__sub_82680044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680048"))) PPC_WEAK_FUNC(sub_82680048);
PPC_FUNC_IMPL(__imp__sub_82680048) {
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
	// bl 0x82646d30
	ctx.lr = 0x82680068;
	sub_82646D30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680080
	if (cr6.eq) goto loc_82680080;
	// bl 0x82130588
	ctx.lr = 0x8268007C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82680080:
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

__attribute__((alias("__imp__sub_82680098"))) PPC_WEAK_FUNC(sub_82680098);
PPC_FUNC_IMPL(__imp__sub_82680098) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826800A0;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lfs f13,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 / ctx.f13.f64));
	// bl 0x823dba38
	ctx.lr = 0x826800C4;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,0,r29
	PPC_STORE_U32(r29.u32, ctx.f11.u32);
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f1,f10,f9
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// bl 0x823dba38
	ctx.lr = 0x826800E0;
	sub_823DBA38(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,0,r28
	PPC_STORE_U32(r28.u32, ctx.f7.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// stw r6,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r6.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82680114"))) PPC_WEAK_FUNC(sub_82680114);
PPC_FUNC_IMPL(__imp__sub_82680114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680118"))) PPC_WEAK_FUNC(sub_82680118);
PPC_FUNC_IMPL(__imp__sub_82680118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8268012C"))) PPC_WEAK_FUNC(sub_8268012C);
PPC_FUNC_IMPL(__imp__sub_8268012C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680130"))) PPC_WEAK_FUNC(sub_82680130);
PPC_FUNC_IMPL(__imp__sub_82680130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82680160
	if (cr6.eq) goto loc_82680160;
	// b 0x82682970
	sub_82682970(ctx, base);
	return;
loc_82680160:
	// b 0x82682bf8
	sub_82682BF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82680164"))) PPC_WEAK_FUNC(sub_82680164);
PPC_FUNC_IMPL(__imp__sub_82680164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680168"))) PPC_WEAK_FUNC(sub_82680168);
PPC_FUNC_IMPL(__imp__sub_82680168) {
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
	// lis r11,-32245
	r11.s64 = -2113208320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,16736
	ctx.r9.s64 = r11.s64 + 16736;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x826801A0;
	sub_822E5148(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,29608(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29608, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x826801B4;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826801cc
	if (cr6.eq) goto loc_826801CC;
	// bl 0x82130588
	ctx.lr = 0x826801C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826801CC:
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

__attribute__((alias("__imp__sub_826801E4"))) PPC_WEAK_FUNC(sub_826801E4);
PPC_FUNC_IMPL(__imp__sub_826801E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826801E8"))) PPC_WEAK_FUNC(sub_826801E8);
PPC_FUNC_IMPL(__imp__sub_826801E8) {
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
	ctx.lr = 0x826801F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8268022c
	if (!cr6.gt) goto loc_8268022C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_82680208:
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
	ctx.lr = 0x82680220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
	// bne 0x82680208
	if (!cr0.eq) goto loc_82680208;
loc_8268022C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82680234;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8268023C"))) PPC_WEAK_FUNC(sub_8268023C);
PPC_FUNC_IMPL(__imp__sub_8268023C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680240"))) PPC_WEAK_FUNC(sub_82680240);
PPC_FUNC_IMPL(__imp__sub_82680240) {
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
	// bl 0x822e6b38
	ctx.lr = 0x82680260;
	sub_822E6B38(ctx, base);
	// lis r11,-32245
	r11.s64 = -2113208320;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,16736
	ctx.r9.s64 = r11.s64 + 16736;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x82680290;
	sub_822E5138(ctx, base);
	// lis r6,-32245
	ctx.r6.s64 = -2113208320;
	// li r11,0
	r11.s64 = 0;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r5,r6,16760
	ctx.r5.s64 = ctx.r6.s64 + 16760;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lis r4,16383
	ctx.r4.s64 = 1073676288;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// ori r3,r4,65535
	ctx.r3.u64 = ctx.r4.u64 | 65535;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// srawi r8,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826802e8
	if (!cr6.gt) goto loc_826802E8;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_826802E8:
	// bl 0x82130528
	ctx.lr = 0x826802EC;
	sub_82130528(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x82680300;
	sub_823D9890(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,29604(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29604, r31.u32);
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

__attribute__((alias("__imp__sub_82680324"))) PPC_WEAK_FUNC(sub_82680324);
PPC_FUNC_IMPL(__imp__sub_82680324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82680328"))) PPC_WEAK_FUNC(sub_82680328);
PPC_FUNC_IMPL(__imp__sub_82680328) {
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
	ctx.lr = 0x82680330;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826803e4
	if (cr6.eq) goto loc_826803E4;
	// lhz r28,4(r11)
	r28.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// bl 0x82387a18
	ctx.lr = 0x8268034C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82680380
	if (cr6.eq) goto loc_82680380;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x82680364;
	sub_82293F60(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826803b0
	goto loc_826803B0;
loc_82680380:
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2192
	ctx.r6.s64 = ctx.r8.s64 + 2192;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// lwz r4,2192(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// clrlwi r29,r11,1
	r29.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
loc_826803B0:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x826803e4
	if (!cr6.gt) goto loc_826803E4;
	// li r30,0
	r30.s64 = 0;
loc_826803C0:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// add r4,r31,r29
	ctx.r4.u64 = r31.u64 + r29.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82683b28
	ctx.lr = 0x826803D4;
	sub_82683B28(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,160
	r30.s64 = r30.s64 + 160;
	// cmpw cr6,r31,r28
	cr6.compare<int32_t>(r31.s32, r28.s32, xer);
	// blt cr6,0x826803c0
	if (cr6.lt) goto loc_826803C0;
loc_826803E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826803EC"))) PPC_WEAK_FUNC(sub_826803EC);
PPC_FUNC_IMPL(__imp__sub_826803EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826803F0"))) PPC_WEAK_FUNC(sub_826803F0);
PPC_FUNC_IMPL(__imp__sub_826803F0) {
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
	ctx.lr = 0x826803F8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r4,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r4.u32);
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826804e4
	if (cr6.eq) goto loc_826804E4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826804e4
	if (!cr6.gt) goto loc_826804E4;
	// clrlwi r27,r5,24
	r27.u64 = ctx.r5.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82680424:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r26,36(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,44(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 44);
	f0.f64 = double(temp.f32);
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 / f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x82680444;
	sub_823DBA38(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,44(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f1,f11,f10
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fctiwz f9,f12
	ctx.f9.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r25,84(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823dba38
	ctx.lr = 0x82680464;
	sub_823DBA38(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// lwz r10,52(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// lwz r9,48(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 48);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// subf r7,r9,r25
	ctx.r7.s64 = r25.s64 - ctx.r9.s64;
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subf r5,r10,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r10.s64;
	// srawi r4,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 1;
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// mullw r10,r4,r8
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r8.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826804c0
	if (cr0.lt) goto loc_826804C0;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x826804c0
	if (!cr6.lt) goto loc_826804C0;
	// lwz r10,24(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// lwz r7,24(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stwx r31,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, r31.u32);
loc_826804C0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x826804d8
	if (!cr6.eq) goto loc_826804D8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683c10
	ctx.lr = 0x826804D8;
	sub_82683C10(ctx, base);
loc_826804D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,160
	r29.s64 = r29.s64 + 160;
	// bne 0x82680424
	if (!cr0.eq) goto loc_82680424;
loc_826804E4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826804EC"))) PPC_WEAK_FUNC(sub_826804EC);
PPC_FUNC_IMPL(__imp__sub_826804EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826804F0"))) PPC_WEAK_FUNC(sub_826804F0);
PPC_FUNC_IMPL(__imp__sub_826804F0) {
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
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82680564
	if (cr6.eq) goto loc_82680564;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// li r5,0
	ctx.r5.s64 = 0;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,68(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// bl 0x8232b540
	ctx.lr = 0x82680544;
	sub_8232B540(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82680564
	if (cr6.eq) goto loc_82680564;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683828
	ctx.lr = 0x82680558;
	sub_82683828(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82683a28
	ctx.lr = 0x82680564;
	sub_82683A28(ctx, base);
loc_82680564:
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

__attribute__((alias("__imp__sub_8268057C"))) PPC_WEAK_FUNC(sub_8268057C);
PPC_FUNC_IMPL(__imp__sub_8268057C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

