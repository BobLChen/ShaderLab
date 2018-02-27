Shader "Particles/Blend" {
Properties {
	_MainTex ("Particle Texture", 2D) = "white" {}
	_InvFade ("Soft Particles Factor", Range(0.01,3.0)) = 1.0
	_Intensity ("_Intensity", Range(0.01, 3.0)) = 1.2
	_Intensito ("_Intensito", Range(0.01, 3.0)) = 2.2
}

CGINCLUDE

float test_cg_include(float v)
{
	return v * 10;
}

ENDCG

Category {

	Tags { "Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent" }
	Blend DstColor One
	ColorMask RGB
	Cull Off 
	ZWrite Off 
	Fog { Color (0,0,0,0) }

	SubShader {
		Pass {
		
			CGPROGRAM

			#include "TestCgInclude.cginc"

			#pragma vertex vert
			#pragma fragment frag
			#pragma multi_compile SHADOW
			#pragma target gles30

			sampler2D _MainTex;
			samplerCUBE _MainTex1;
			sampler3D _MainTex2;

			fixed4 _TintColor;
			
			struct appdata_t {
				float4 vertex   : POSITION;
				float4 color    : COLOR;
				float2 texcoord : TEXCOORD0;
				float4 indices  : SKIN_INDICES;
				float3 weights  : SKIN_WEIGHTS;
				float3 tangents : TANGENT;
			};

			struct v2f {
				float4 vertex   : POSITION;
				float4 color    : COLOR;
				float2 texcoord : TEXCOORD0;
				float4 projPos  : TEXCOORD1;
				float3 tangents : TANGENT;
			};
			
			float4 _MainTex_ST;
			float4x4 _matrix_mvp;
			float  _val0;
			float2 _val1;
			float3 _val2;
			float4[10] _val3;
			
			v2f vert (appdata_t v)
			{
				v2f o;
				o.vertex = mul(_matrix_mvp, v.vertex);
				o.color = v.color * _val0 * _val1.x * _val1.y * float4(_val2, 2.0) * _val3[0];
				o.texcoord = v.texcoord;
				o.tangents = v.tangents;
				o.color = o.color * test_cg_include_file(_val0);
				return o;
			}

			float _InvFade;
			half _Intensity;
			float _Intensito;
			
			fixed4 frag (v2f i) : COLOR
			{
				return i.color * tex2D(_MainTex, i.texcoord) * test_cg_include(_Intensito) * _Intensity * texCUBE(_MainTex1, float3(i.texcoord, 1.0)) * tex3D(_MainTex2, i.projPos);
			}
			ENDCG 
		}
	}
}
}
