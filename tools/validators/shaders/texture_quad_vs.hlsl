// Textured-quad vertex stage for tools/validators/texture_import_validator.cpp.
// Matches D3D12Backend::CreateTestRootSignature (SRV table t0..t3, root CBV b0,
// static sampler s0). 2D textures bind at t1 (kTexture2DSlot == 1).
//
// uv is DERIVED from position, so the input layout is POSITION-only and a bad
// attribute binding cannot skew it. The -0.5/texelsize term is what makes the
// mapping pixel-exact: a full-viewport clip-space quad maps screen pixel centre
// p to ndc 2(p+1)/W-1, which without the correction lands uv on a texel BOUNDARY
// and makes the backend's MIN_MAG_MIP_LINEAR sampler blend two texels 50/50.
// With it, uv hits the texel centre and linear returns the texel unchanged.
Texture2D t2D : register(t1);

struct VSIn {
    float3 pos : POSITION;
};

struct VSOut {
    float4 pos : SV_Position;
    float2 uv : TEXCOORD;
};

VSOut main(VSIn i) {
    VSOut o;
    o.pos = float4(i.pos, 1.0f);
    uint w, h, levels, samples;
    t2D.GetDimensions(w, h, levels, samples);
    // A null SRV in slot t1 reports 0x0; clamp so the no-texture control
    // degrades to a defined uv instead of a divide-by-zero NaN.
    w = max(w, 1u);
    h = max(h, 1u);
    o.uv = i.pos.xy * float2(0.5f, -0.5f) + 0.5f -
           float2(0.5f, 0.5f) / float2((float)w, (float)h);
    return o;
}
