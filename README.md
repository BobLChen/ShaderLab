# ShaderLab

A C++ library that convert unity shaderlab to json form webgl or other rendering engine.

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
double click bin/do.cmd

### Source Code
```
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

### Json data
```
{
	"fallbackName": "",
	"properties": {
		"props": [{
			"description": "Particle Texture",
			"name": "_MainTex",
			"texture": {
				"dimension": "2D",
				"name": "white"
			},
			"type": "Texture",
			"value": {
				"w": 0.0,
				"x": 0.0,
				"y": 0.0,
				"z": 0.0
			}
		}, {
			"description": "Soft Particles Factor",
			"name": "_InvFade",
			"texture": {
				"dimension": "UnKnown",
				"name": ""
			},
			"type": "Range",
			"value": {
				"w": 0.0,
				"x": 1.0,
				"y": 0.0099999997764825821,
				"z": 3.0
			}
		}, {
			"description": "_Intensity",
			"name": "_Intensity",
			"texture": {
				"dimension": "UnKnown",
				"name": ""
			},
			"type": "Range",
			"value": {
				"w": 0.0,
				"x": 1.2000000476837158,
				"y": 0.0099999997764825821,
				"z": 3.0
			}
		}, {
			"description": "_Intensito",
			"name": "_Intensito",
			"texture": {
				"dimension": "UnKnown",
				"name": ""
			},
			"type": "Range",
			"value": {
				"w": 0.0,
				"x": 2.2000000476837158,
				"y": 0.0099999997764825821,
				"z": 3.0
			}
		}]
	},
	"shaderName": "Particles/Blend",
	"subShaders": [{
		"lod": 0,
		"passes": [{
			"programs": [{
				"subPrograms": [{
					"bindChannels": [{
						"dest": "POSITION",
						"src": "xlat_attrib_POSITION",
						"stride": 4
					}, {
						"dest": "COLOR",
						"src": "xlat_attrib_COLOR",
						"stride": 4
					}, {
						"dest": "TEXCOORD0",
						"src": "xlat_attrib_TEXCOORD0",
						"stride": 2
					}, {
						"dest": "TANGENT",
						"src": "xlat_attrib_TANGENT",
						"stride": 3
					}],
					"keywords": ["SHADOW"],
					"matrixParams": [{
						"array": -1,
						"cols": 4,
						"index": -1,
						"name": "_matrix_mvp",
						"rows": 4
					}],
					"name": "gles30",
					"source": "\n#version 300 es\nuniform highp mat4 _matrix_mvp;\nuniform highp float _val0;\nuniform highp vec2 _val1;\nuniform highp vec3 _val2;\nuniform highp vec4 _val3[10];\nin highp vec4 xlat_attrib_POSITION;\nin highp vec4 xlat_attrib_COLOR;\nin highp vec2 xlat_attrib_TEXCOORD0;\nin highp vec3 xlat_attrib_TANGENT;\nout highp vec4 xlv_COLOR;\nout highp vec2 xlv_TEXCOORD0;\nout highp vec4 xlv_TEXCOORD1;\nout highp vec3 xlv_TANGENT;\nvoid main ()\n{\n  highp vec4 tmpvar_1;\n  highp vec4 tmpvar_2;\n  highp vec4 tmpvar_3;\n  tmpvar_3.w = 2.0;\n  tmpvar_3.xyz = _val2;\n  tmpvar_1 = (((xlat_attrib_COLOR * _val0) * (\n    (_val1.x * _val1.y)\n   * tmpvar_3)) * _val3[0]);\n  tmpvar_1 = (tmpvar_1 * (_val0 * 12.0));\n  gl_Position = (_matrix_mvp * xlat_attrib_POSITION);\n  xlv_COLOR = tmpvar_1;\n  xlv_TEXCOORD0 = xlat_attrib_TEXCOORD0;\n  xlv_TEXCOORD1 = tmpvar_2;\n  xlv_TANGENT = xlat_attrib_TANGENT;\n}\n\n\n",
					"vectorParams": [{
						"array": -1,
						"dimension": 1,
						"index": -1,
						"name": "_val0",
						"type": "Float"
					}, {
						"array": -1,
						"dimension": 2,
						"index": -1,
						"name": "_val1",
						"type": "Float"
					}, {
						"array": -1,
						"dimension": 3,
						"index": -1,
						"name": "_val2",
						"type": "Float"
					}, {
						"array": 10,
						"dimension": 4,
						"index": -1,
						"name": "_val3",
						"type": "Float"
					}]
				}],
				"type": "vp"
			}, {
				"subPrograms": [{
					"keywords": ["SHADOW"],
					"name": "gles30",
					"source": "\n#version 300 es\nlayout(location=0) out mediump vec4 _gles3FragData[4];\nuniform sampler2D _MainTex;\nuniform lowp samplerCube _MainTex1;\nuniform lowp sampler3D _MainTex2;\nuniform mediump float _Intensity;\nuniform highp float _Intensito;\nin highp vec4 xlv_COLOR;\nin highp vec2 xlv_TEXCOORD0;\nin highp vec4 xlv_TEXCOORD1;\nvoid main ()\n{\n  lowp vec4 tmpvar_1;\n  highp float tmpvar_2;\n  tmpvar_2 = (_Intensito * 10.0);\n  highp vec3 tmpvar_3;\n  tmpvar_3.z = 1.0;\n  tmpvar_3.xy = xlv_TEXCOORD0;\n  tmpvar_1 = (((xlv_COLOR * texture (_MainTex, xlv_TEXCOORD0)) * (tmpvar_2 * _Intensity)) * (texture (_MainTex1, tmpvar_3) * texture (_MainTex2, xlv_TEXCOORD1.xyz)));\n  _gles3FragData[0] = tmpvar_1;\n}\n\n\n",
					"textureParams": [{
						"dimension": "2D",
						"index": -1,
						"name": "_MainTex",
						"sampler": 0
					}, {
						"dimension": "Cube",
						"index": -1,
						"name": "_MainTex1",
						"sampler": 1
					}, {
						"dimension": "3D",
						"index": -1,
						"name": "_MainTex2",
						"sampler": 2
					}],
					"vectorParams": [{
						"array": -1,
						"dimension": 1,
						"index": -1,
						"name": "_Intensity",
						"type": "Float"
					}, {
						"array": -1,
						"dimension": 1,
						"index": -1,
						"name": "_Intensito",
						"type": "Float"
					}]
				}],
				"type": "fp"
			}],
			"state": {
				"alphaToMask": {
					"ref": "",
					"val": 0.0
				},
				"blendOp": {
					"ref": "",
					"val": 0.0
				},
				"blendOpAlpha": {
					"ref": "",
					"val": 0.0
				},
				"colMask": {
					"ref": "",
					"val": 14.0
				},
				"culling": {
					"ref": "",
					"val": 0.0
				},
				"destBlend": {
					"ref": "",
					"val": 1.0
				},
				"destBlendAlpha": {
					"ref": "",
					"val": 1.0
				},
				"fogColor": {
					"w": 0.0,
					"x": 0.0,
					"y": 0.0,
					"z": 0.0
				},
				"fogDensity": {
					"ref": "",
					"val": 0.0
				},
				"fogEnd": {
					"ref": "",
					"val": 0.0
				},
				"fogMode": "Linear",
				"fogStart": {
					"ref": "",
					"val": 0.0
				},
				"gpuProgramID": -1,
				"lod": 0,
				"name": "",
				"offsetFactor": {
					"ref": "",
					"val": 0.0
				},
				"offsetUnits": {
					"ref": "",
					"val": 0.0
				},
				"srcBlend": {
					"ref": "",
					"val": 2.0
				},
				"srcBlendAlpha": {
					"ref": "",
					"val": 2.0
				},
				"stencilOp": {
					"comp": 8.0,
					"fail": 0.0,
					"pass": 0.0,
					"zFail": 0.0
				},
				"stencilOpBack": {
					"comp": 8.0,
					"fail": 0.0,
					"pass": 0.0,
					"zFail": 0.0
				},
				"stencilOpFront": {
					"comp": 8.0,
					"fail": 0.0,
					"pass": 0.0,
					"zFail": 0.0
				},
				"stencilReadMask": {
					"ref": "",
					"val": 255.0
				},
				"stencilRef": {
					"ref": "",
					"val": 0.0
				},
				"stencilWriteMask": {
					"ref": "",
					"val": 255.0
				},
				"tags": {
					"IgnoreProjector": "True",
					"Queue": "Transparent",
					"RenderType": "Transparent"
				},
				"zTest": {
					"ref": "",
					"val": 4.0
				},
				"zWrite": {
					"ref": "",
					"val": 0.0
				}
			},
			"type": "Pass"
		}],
		"tags": {
			"IgnoreProjector": "True",
			"Queue": "Transparent",
			"RenderType": "Transparent"
		}
	}]
}
```
