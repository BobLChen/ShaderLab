Shader "Particles/Blend" 
{

	Properties 
	{
		_MainTex ("Particle Texture", 2D) = "white" {}
		_InvFade ("Soft Particles Factor", Range(0.01,3.0)) = 1.0
		_Intensity ("_Intensity", Range(0.01, 3.0)) = 1.2
		_Intensito ("_Intensito", Range(0.01, 3.0)) = 2.2
	}

	Category 
	{

		Tags { "Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent" }
		Blend DstColor One
		ColorMask RGB
		Cull Off 
		ZWrite Off 
		
		SubShader 
		{
			Pass 
			{
				CGPROGRAM

				#pragma vertex vert
				#pragma fragment frag
				#pragma multi_compile TEST1 TEST2
				#pragma multi_compile TEST3 TEST4 TEST5
				#pragma multi_compile TEST6 TEST7 TEST8 TEST9
				#pragma target gles30 opengl gles20 ios mac vulkan hlsl

				#include "TestCgInclude.cginc"

				struct PSInput
				{
				    float4 pos      : SV_Position;
				    float3 normal   : NORMAL;
				    float3 lightVec : TEXCOORD0;
				    float3 halfway  : TEXCOORD1;
				};

				cbuffer PerObjectBuffer : register(b0)
				{
				    float3 diffColor;
				    float3 specColor;
				    float  shininess;
				};

				float3 CalcBrdf(float3 diffColor, float3 specColor, float shininess, float3 lightVec, float3 halfway, float3 normal)
				{
					return diffColor * specColor + shininess * lightVec + halfway * normal;
				}

				float4 vert() : SV_Position
				{
					return float4(1, 2, 3, 4);
				}
				
				float4 frag(PSInput input) : SV_Target
				{
				    float4 color;
				    color.rgb = CalcBrdf(diffColor, specColor, shininess, input.lightVec, input.halfway, input.normal);
				    color.a = TestCGIncludeFunc(1.0);
				    return color;
				}

				ENDCG
			}
		}
	}
}
