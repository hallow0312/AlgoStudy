// 텍스처를 편리하게 선언하기 위한 매크로함수
#define DeclareTexture( textureName, samplerName, semantic ) \
texture textureName : semantic; \
sampler samplerName = sampler_state \
{ \
	texture = <textureName>; \
	MipFilter = LINEAR; \
	MinFilter = LINEAR; \
	MagFilter = LINEAR; \
    AddressU = Wrap; \
    AddressV = Wrap; \
} \

// 변수 선언
float4x4 matW : MATRIX_WORLD;
float4x4 matV : MATRIX_VIEW;
float4x4 matP : MATRIX_PROJ;
float3   vLightPosition : LIGHT_POS;
float3   vViewPosition : VIEW_POS;
float4   vDiffuseColor : DIFFUSE_COLOR;
float    fSpecularPower : SPECULAR_POWER;
float    fTime : TIME;


// 텍스처 선언
DeclareTexture( BASEMAP, baseMap, BASEMAP );
DeclareTexture( SECONDMAP, secondMap, SECONDMAP );

static const float PI =3.14159265f;
static const float TWO_PI = 6.28318530f;
// 입력정점 형식
struct VS_INPUT
{
    float3 pos  : POSITION;
    float3 normal : NORMAL;
    float2 tex  : TEXCOORD0;
};

// 출력정점 형식
struct VS_OUTPUT
{
    float4 P : POSITION;
    float3 N : TEXCOORD0;
    float2 T : TEXCOORD1;
	float3 V : TEXCOORD2;
	float3 L : TEXCOORD3;
};

// 정점셰이더 함수 선언
VS_OUTPUT VS( VS_INPUT In )
{
    VS_OUTPUT Out = (VS_OUTPUT)0;
	
	float3 P = In.pos;
    float4x4 WorldView = mul(matW, matV);	// matW와 matV행렬을 곱해서 WorldView행렬생성
    P = mul(float4(P, 1), (float4x3)WorldView);  // view공간에서의 위치계산
    Out.P = mul(float4(P, 1), matP);	// 투영공간에서의 위치계산
    
	Out.T = In.tex;
	
	float3 vViewDirection  = vViewPosition - P;
	float3 vLightDirection = vLightPosition - P;
	
	Out.N = normalize( mul(In.normal, (float3x3)matW) );  // 법선벡터변환
	
	Out.V = normalize( vViewDirection );
	Out.L = normalize( vLightDirection );
	
    return Out;
}
float4 PS(VS_OUTPUT In) : COLOR
{
    float3 L = normalize(In.L);
    float3 N = normalize(In.N);
    float3 V = normalize(In.V);

    float NdotL = saturate(dot(N, L));
    float3 R = normalize(2.0f * N * NdotL - L);
    float RdotV = saturate(dot(R, V));

    // =========================
    // DX9 SAFE Kaleidoscope UV
    // =========================
    float2 uv = In.T;

    // 중심 기준
    uv = uv - 0.5f;

    // 반복 스케일
    uv *= 8.0f;

    // mirror 반복 (분기 없음)
    uv = abs(frac(uv) - 0.5f);

    // 시간 애니메이션
    uv.x += fTime * 0.2f;

    // UV 복원
    uv += 0.5f;

    // =========================
    // 텍스처
    // =========================
    float4 fvSrc = tex2D(baseMap, uv);
    float4 fvTmp = tex2D(secondMap, uv * 2.0f);

    float4 fvBaseColor = fvSrc * fvTmp;

    // =========================
    // 라이팅
    // =========================
    float4 fvAmbient = 0.3f * fvBaseColor;
    float4 fvDiffuse = vDiffuseColor * NdotL * fvBaseColor;

    float spec = pow(RdotV, fSpecularPower);
    float4 fvSpecular = float4(spec, spec, spec, spec);

    return fvAmbient + fvDiffuse + fvSpecular;
}

// MyShader 테크닉선언
technique MyShader
{
    pass P0	// 최초의 0번째 패스
    {
        // shaders
        VertexShader = compile vs_2_0 VS();
        PixelShader  = compile ps_2_0 PS();
    }
}