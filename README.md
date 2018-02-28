# ShaderLab

A C++ library that takes unity shaderlab,compile shaderlab and parse compiled shader to get all infomation.

## Requirement
cmake 3.0

## Build
```
cd ShaderLab
mkdir build
cd build
cmake ..
make
```

## example
Souce code
```hlsl
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
```

Compiled code
```glsl
Shader "Particles/Blend" {
Properties {
	_MainTex ("Particle Texture", 2D) = "white" {}
	_InvFade ("Soft Particles Factor", Range(0.01,3.0)) = 1.0
	_Intensity ("_Intensity", Range(0.01, 3.0)) = 1.2
	_Intensito ("_Intensito", Range(0.01, 3.0)) = 2.2
}



Category {

	Tags { "Queue"="Transparent" "IgnoreProjector"="True" "RenderType"="Transparent" }
	Blend DstColor One
	ColorMask RGB
	Cull Off 
	ZWrite Off 
	Fog { Color (0,0,0,0) }

	SubShader {
		Pass {
		
			Program "vp" {
SubProgram "gles30" {
Keywords { "SHADOW" }
Bind "xlat_attrib_POSITION" POSITION 4
Bind "xlat_attrib_COLOR" COLOR 4
Bind "xlat_attrib_TEXCOORD0" TEXCOORD0 2
Bind "xlat_attrib_TANGENT" TANGENT 3
Matrix -1 [_matrix_mvp] 4 4 -1
Float -1 [_val0] -1
Vector -1 [_val1] 2 -1
Vector -1 [_val2] 3 -1
Vector -1 [_val3] 4 10
"
#version 300 es
uniform highp mat4 _matrix_mvp;
uniform highp float _val0;
uniform highp vec2 _val1;
uniform highp vec3 _val2;
uniform highp vec4 _val3[10];
in highp vec4 xlat_attrib_POSITION;
in highp vec4 xlat_attrib_COLOR;
in highp vec2 xlat_attrib_TEXCOORD0;
in highp vec3 xlat_attrib_TANGENT;
out highp vec4 xlv_COLOR;
out highp vec2 xlv_TEXCOORD0;
out highp vec4 xlv_TEXCOORD1;
out highp vec3 xlv_TANGENT;
void main ()
{
  highp vec4 tmpvar_1;
  highp vec4 tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 2.0;
  tmpvar_3.xyz = _val2;
  tmpvar_1 = (((xlat_attrib_COLOR * _val0) * (
    (_val1.x * _val1.y)
   * tmpvar_3)) * _val3[0]);
  tmpvar_1 = (tmpvar_1 * (_val0 * 12.0));
  gl_Position = (_matrix_mvp * xlat_attrib_POSITION);
  xlv_COLOR = tmpvar_1;
  xlv_TEXCOORD0 = xlat_attrib_TEXCOORD0;
  xlv_TEXCOORD1 = tmpvar_2;
  xlv_TANGENT = xlat_attrib_TANGENT;
}


"
}

}
Program "fp" {
SubProgram "gles30" {
Keywords { "SHADOW" }
Float -1 [_Intensity] -1
Float -1 [_Intensito] -1
SetTexture -1 [_MainTex] 2D 0
SetTexture -1 [_MainTex1] CUBE 1
SetTexture -1 [_MainTex2] 3D 2
"
#version 300 es
layout(location=0) out mediump vec4 _gles3FragData[4];
uniform sampler2D _MainTex;
uniform lowp samplerCube _MainTex1;
uniform lowp sampler3D _MainTex2;
uniform mediump float _Intensity;
uniform highp float _Intensito;
in highp vec4 xlv_COLOR;
in highp vec2 xlv_TEXCOORD0;
in highp vec4 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tmpvar_1;
  highp float tmpvar_2;
  tmpvar_2 = (_Intensito * 10.0);
  highp vec3 tmpvar_3;
  tmpvar_3.z = 1.0;
  tmpvar_3.xy = xlv_TEXCOORD0;
  tmpvar_1 = (((xlv_COLOR * texture (_MainTex, xlv_TEXCOORD0)) * (tmpvar_2 * _Intensity)) * (texture (_MainTex1, tmpvar_3) * texture (_MainTex2, xlv_TEXCOORD1.xyz)));
  _gles3FragData[0] = tmpvar_1;
}


"
}

}
 
		}
	}
}
}

```
