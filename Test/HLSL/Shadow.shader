Shader "Test/ConstantBuffer" 
{
	Properties 
	{

	}
    
	Category
	{

		Tags { "Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent" }
		
		SubShader 
		{
			Pass 
			{
				CGPROGRAM

				#pragma vertex vert
				#pragma fragment frag
				#pragma target gles30 opengl ios mac vulkan hlsl
                
                Texture2D shadowMap  : register(t0);
                Texture2D diffuseMap : register(t1);
                Texture2D normalMap  : register(t2);

                SamplerState sampleWrap  : register(s0);
                SamplerState sampleClamp : register(s1);

                #define NUM_LIGHTS 3
                #define SHADOW_DEPTH_BIAS 0.00005f

                struct LightState
                {
                    float3   position;
                    float3   direction;
                    float4   color;
                    float4   falloff;
                    float4x4 view;
                    float4x4 projection;
                };

                cbuffer SceneConstantBuffer : register(b0)
                {
                    float4x4   model;
                    float4x4   view;
                    float4x4   projection;
                    float4     ambientColor;
                    bool       sampleShadowMap;
                    LightState lights[NUM_LIGHTS];
                };

                struct PSInput
                {
                    float4 position : SV_POSITION;
                    float4 worldpos : POSITION;
                    float2 uv       : TEXCOORD0;
                    float3 normal   : NORMAL;
                    float3 tangent  : TANGENT;
                };

                float3 CalcPerPixelNormal(float2 vTexcoord, float3 vVertNormal, float3 vVertTangent)
                {
                    vVertNormal  = normalize(vVertNormal);
                    vVertTangent = normalize(vVertTangent);

                    float3 vVertBinormal = normalize(cross(vVertTangent, vVertNormal));
                    float3x3 mTangentSpaceToWorldSpace = float3x3(vVertTangent, vVertBinormal, vVertNormal);

                    float3 vBumpNormal = (float3)normalMap.Sample(sampleWrap, vTexcoord);
                    vBumpNormal = 2.0f * vBumpNormal - 1.0f;

                    return mul(vBumpNormal, mTangentSpaceToWorldSpace);
                }

                float4 CalcLightingColor(float3 vLightPos, float3 vLightDir, float4 vLightColor, float4 vFalloffs, float3 vPosWorld, float3 vPerPixelNormal)
                {
                    float3 vLightToPixelUnNormalized = vPosWorld - vLightPos;

                    float fDist = length(vLightToPixelUnNormalized);

                    float fDistFalloff = saturate((vFalloffs.x - fDist) / vFalloffs.y);

                    float3 vLightToPixelNormalized = vLightToPixelUnNormalized / fDist;

                    float fCosAngle = dot(vLightToPixelNormalized, vLightDir / length(vLightDir));
                    float fAngleFalloff = saturate((fCosAngle - vFalloffs.z) / vFalloffs.w);

                    float fNDotL = saturate(-dot(vLightToPixelNormalized, vPerPixelNormal));

                    return vLightColor * fNDotL * fDistFalloff * fAngleFalloff;
                }

                float4 CalcUnshadowedAmountPCF2x2(int lightIndex, float4 vPosWorld)
                {
                    float4 vLightSpacePos = vPosWorld;
                    vLightSpacePos = mul(vLightSpacePos, lights[lightIndex].view);
                    vLightSpacePos = mul(vLightSpacePos, lights[lightIndex].projection);

                    vLightSpacePos.xyz /= vLightSpacePos.w;

                    float2 vShadowTexCoord = 0.5f * vLightSpacePos.xy + 0.5f;
                    vShadowTexCoord.y = 1.0f - vShadowTexCoord.y;

                    float vLightSpaceDepth = vLightSpacePos.z - SHADOW_DEPTH_BIAS;

                    float2 vShadowMapDims = float2(1280.0f, 720.0f);
                    float4 vSubPixelCoords = float4(1.0f, 1.0f, 1.0f, 1.0f);
                    vSubPixelCoords.xy = frac(vShadowMapDims * vShadowTexCoord);
                    vSubPixelCoords.zw = 1.0f - vSubPixelCoords.xy;
                    float4 vBilinearWeights = vSubPixelCoords.zxzx * vSubPixelCoords.wwyy;

                    float2 vTexelUnits = 1.0f / vShadowMapDims;
                    float4 vShadowDepths;
                    vShadowDepths.x = shadowMap.Sample(sampleClamp, vShadowTexCoord);
                    vShadowDepths.y = shadowMap.Sample(sampleClamp, vShadowTexCoord + float2(vTexelUnits.x, 0.0f));
                    vShadowDepths.z = shadowMap.Sample(sampleClamp, vShadowTexCoord + float2(0.0f, vTexelUnits.y));
                    vShadowDepths.w = shadowMap.Sample(sampleClamp, vShadowTexCoord + vTexelUnits);

                    float4 vShadowTests = (vShadowDepths >= vLightSpaceDepth) ? 1.0f : 0.0f;
                    return dot(vBilinearWeights, vShadowTests);
                }

                PSInput vert(float3 position : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD0, float3 tangent : TANGENT)
                {
                    PSInput result;

                    float4 newPosition = float4(position, 1.0f);

                    normal.z *= -1.0f;
                    newPosition = mul(newPosition, model);

                    result.worldpos = newPosition;

                    newPosition = mul(newPosition, view);
                    newPosition = mul(newPosition, projection);

                    result.position = newPosition;
                    result.uv = uv;
                    result.normal = normal;
                    result.tangent = tangent;

                    return result;
                }

                float4 frag(PSInput input) : SV_TARGET
                {
                    float4 diffuseColor = diffuseMap.Sample(sampleWrap, input.uv);
                    float3 pixelNormal = CalcPerPixelNormal(input.uv, input.normal, input.tangent);
                    float4 totalLight = ambientColor;

                    for (int i = 0; i < NUM_LIGHTS; i++)
                    {
                        float4 lightPass = CalcLightingColor(lights[i].position, lights[i].direction, lights[i].color, lights[i].falloff, input.worldpos.xyz, pixelNormal);
                        if (sampleShadowMap && i == 0)
                        {
                            lightPass *= CalcUnshadowedAmountPCF2x2(i, input.worldpos);
                        }
                        totalLight += lightPass;
                    }

                    return diffuseColor * saturate(totalLight);
                }


				ENDCG
			}
		}
	}
}
