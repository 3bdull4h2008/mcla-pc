// Samples the decoded-texture SRV the backend installs at t1
// (D3D12Backend::CreateDecodedTexture -> kTexture2DSlot == 1).
Texture2D t2D : register(t1);
SamplerState samp : register(s0);

struct PSIn {
    float4 pos : SV_Position;
    float2 uv : TEXCOORD;
};

float4 main(PSIn i) : SV_TARGET {
    return t2D.Sample(samp, i.uv);
}
